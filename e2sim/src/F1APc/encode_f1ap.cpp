#include <stdlib.h>
#include <string.h>
#include <stdio.h>

extern "C" {
#include "F1AP-PDU.h"

#include "InitiatingMessage.h"
#include "Criticality.h"

#include "ProcedureCode.h"
#include "aper_encoder.h"
}

int encode_f1ap_setup_request(
    long du_id,
    uint8_t **out_buf,
    size_t *out_len
) {
    if(!out_buf || !out_len) return -1;

    *out_buf = NULL;
    *out_len = 0;

    F1AP_PDU_t *f1ap_pdu =
        (F1AP_PDU_t *)calloc(1, sizeof(F1AP_PDU_t));
    if(!f1ap_pdu) return -1;

    f1ap_pdu->present = F1AP_PDU_PR_initiatingMessage;
    f1ap_pdu->choice.initiatingMessage->procedureCode =
        ProcedureCode_id_F1Setup;
    f1ap_pdu->choice.initiatingMessage->criticality =
        Criticality_reject;
    f1ap_pdu->choice.initiatingMessage->value.present =
        InitiatingMessage__value_PR_F1SetupRequest;

    uint8_t buf[4096];
    asn_enc_rval_t enc_ret =
        aper_encode_to_buffer(
            &asn_DEF_F1AP_PDU,
            NULL,
            f1ap_pdu,
            buf,
            sizeof(buf)
        );

    if(enc_ret.encoded <= 0) {
        fprintf(stderr, "F1AP APER encode failed\n");
        ASN_STRUCT_FREE(asn_DEF_F1AP_PDU, f1ap_pdu);
        return -1;
    }

    size_t len = (enc_ret.encoded + 7) / 8;

    uint8_t *out = (uint8_t *)calloc(1, len);
    if(!out) {
        ASN_STRUCT_FREE(asn_DEF_F1AP_PDU, f1ap_pdu);
        return -1;
    }

    memcpy(out, buf, len);

    ASN_STRUCT_FREE(asn_DEF_F1AP_PDU, f1ap_pdu);

    *out_buf = out;
    *out_len = len;

    return 0;
}