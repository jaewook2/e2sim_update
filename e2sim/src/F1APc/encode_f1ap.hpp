#pragma once
#include <cstddef>
#include <cstdint>
#include <utility>

namespace encoding {

// 반환: (buf, len). 실패 시 {nullptr,0} 또는 예외/에러코드 방식 택1
int encode_f1ap_setup_request(long du_id, uint8_t** out_buf, size_t* out_len);

} // namespace encoding