/*****************************************************************************
# Copyright 2019 AT&T Intellectual Property                                  *
#                                                                            *
# Licensed under the Apache License, Version 2.0 (the "License");            *
# you may not use this file except in compliance with the License.           *
# You may obtain a copy of the License at                                    *
#                                                                            *
#      http://www.apache.org/licenses/LICENSE-2.0                            *
#                                                                            *
# Unless required by applicable law or agreed to in writing, software        *
# distributed under the License is distributed on an "AS IS" BASIS,          *
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   *
# See the License for the specific language governing permissions and        *
# limitations under the License.                                             *
#                                                                            *
******************************************************************************/

#pragma once

#include "asn/asn.hpp"
static_assert(ASN_API_VERSION_MAJOR == 5, "re-generate the ASN parser's code using 'make regen-asn' (do not use -j option)");

#include "X2AP-IEs.hpp"
#include "X2AP-Containers.hpp"
#include "X2AP-Constants.hpp"

/*
ActivatedCellList-Item-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct ActivatedCellList_Item_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
ActivatedCellList-Item::= SEQUENCE {
	ecgi								ECGI,
	iE-Extensions						ProtocolExtensionContainer { {ActivatedCellList-Item-ExtIEs} } OPTIONAL,
	...
}
*/

struct ActivatedCellList_Item : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "ActivatedCellList-Item";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct ecgi_t : ECGI
	{
		static constexpr const char* name() {return "ecgi_t";}
		using parent_t = ECGI;

	};
	ecgi_t& ref_ecgi() {return ecgi;}
	ecgi_t const& ref_ecgi() const {return ecgi;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ActivatedCellList_Item_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ActivatedCellList_Item_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(ecgi);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(ecgi);
		v(iE_Extensions);

	};
	void clear()
	{
		ecgi.clear();
		iE_Extensions.clear();

	};
	private:
	ecgi_t	ecgi;
	iE_Extensions_t	iE_Extensions;

};
/*
ActivatedCellList ::= SEQUENCE (SIZE (1..maxCellineNB)) OF ActivatedCellList-Item
*/

struct ActivatedCellList_elm : ActivatedCellList_Item
{
	static constexpr const char* name() {return "ActivatedCellList_elm";}
	using parent_t = ActivatedCellList_Item;

};
struct ActivatedCellList : asn::sequenceof<ActivatedCellList_elm>
{
	static constexpr const char* name() {return "ActivatedCellList";}
	using parent_t = asn::sequenceof<ActivatedCellList_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxCellineNB >>;

};
/*
ActivatedNRCellList-Item-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct ActivatedNRCellList_Item_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
ActivatedNRCellList-Item::= SEQUENCE {
	nrCellID						NRCGI,
	iE-Extensions						ProtocolExtensionContainer { {ActivatedNRCellList-Item-ExtIEs} } OPTIONAL,
	...
}
*/

struct ActivatedNRCellList_Item : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "ActivatedNRCellList-Item";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct nrCellID_t : NRCGI
	{
		static constexpr const char* name() {return "nrCellID_t";}
		using parent_t = NRCGI;

	};
	nrCellID_t& ref_nrCellID() {return nrCellID;}
	nrCellID_t const& ref_nrCellID() const {return nrCellID;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ActivatedNRCellList_Item_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ActivatedNRCellList_Item_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(nrCellID);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(nrCellID);
		v(iE_Extensions);

	};
	void clear()
	{
		nrCellID.clear();
		iE_Extensions.clear();

	};
	private:
	nrCellID_t	nrCellID;
	iE_Extensions_t	iE_Extensions;

};
/*
ActivatedNRCellList ::= SEQUENCE (SIZE (1.. maxCellinengNB)) OF ActivatedNRCellList-Item
*/

struct ActivatedNRCellList_elm : ActivatedNRCellList_Item
{
	static constexpr const char* name() {return "ActivatedNRCellList_elm";}
	using parent_t = ActivatedNRCellList_Item;

};
struct ActivatedNRCellList : asn::sequenceof<ActivatedNRCellList_elm>
{
	static constexpr const char* name() {return "ActivatedNRCellList";}
	using parent_t = asn::sequenceof<ActivatedNRCellList_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxCellinengNB >>;

};
/*
CellActivationFailure-IEs X2AP-PROTOCOL-IES ::= {
	{ ID id-Cause						CRITICALITY ignore	TYPE Cause						PRESENCE mandatory }|
	{ ID id-CriticalityDiagnostics		CRITICALITY ignore	TYPE CriticalityDiagnostics		PRESENCE optional },
	...
}
*/

struct CellActivationFailure_IEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_Cause() { set(id_Cause); type=1;}
		void select_id_CriticalityDiagnostics() { set(id_CriticalityDiagnostics); type=2;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_Cause)) { type = 1; return true; }
			else if(equal(id_CriticalityDiagnostics)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_Cause);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_CriticalityDiagnostics);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_Cause() { set(ignore); type=1;}
		void select_id_CriticalityDiagnostics() { set(ignore); type=2;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else if(equal(ignore)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(ignore);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Value_t : asn::typefield<true>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		Cause& select_id_Cause() { return set<Cause>(1); }
		Cause const* get_id_Cause() const { return get<Cause>(1); }
		CriticalityDiagnostics& select_id_CriticalityDiagnostics() { return set<CriticalityDiagnostics>(2); }
		CriticalityDiagnostics const* get_id_CriticalityDiagnostics() const { return get<CriticalityDiagnostics>(2); }
		bool is_unknown() const { return type == 3; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<Cause>(); break;
			case 2: var.destroy<CriticalityDiagnostics>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<Cause>(1);
			v.template operator()<CriticalityDiagnostics>(2);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_Cause()); return true;
			case 2: v(select_id_CriticalityDiagnostics()); return true;
			case 3: if(type != 3) {clear(); asn::base::set();} type = 3; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<Cause>()); return true;
			case 2: v(var.as<CriticalityDiagnostics>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(Cause)];
			char dummy2[sizeof(CriticalityDiagnostics)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_Cause() { set(mandatory); type=1;}
		void select_id_CriticalityDiagnostics() { set(optional); type=2;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			else if(equal(optional)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(optional);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
CellActivationFailure ::= SEQUENCE {
	protocolIEs		ProtocolIE-Container	{{CellActivationFailure-IEs}},
	...
}
*/

struct CellActivationFailure : asn::sequence<1, 0, true, 0>
{
	static constexpr const char* name() {return "CellActivationFailure";}
	using parent_t = asn::sequence<1, 0, true, 0>;
	struct protocolIEs_t : ProtocolIE_Container<CellActivationFailure_IEs>
	{
		static constexpr const char* name() {return "protocolIEs_t";}
		using parent_t = ProtocolIE_Container<CellActivationFailure_IEs>;

	};
	protocolIEs_t& ref_protocolIEs() {return protocolIEs;}
	protocolIEs_t const& ref_protocolIEs() const {return protocolIEs;}
	template<typename V> void decode(V& v)
	{
		v(protocolIEs);

	};
	template<typename V> void encode(V& v) const
	{
		v(protocolIEs);

	};
	void clear()
	{
		protocolIEs.clear();

	};
	private:
	protocolIEs_t	protocolIEs;

};
/*
ServedCellsToActivate-Item-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct ServedCellsToActivate_Item_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
ServedCellsToActivate-Item::= SEQUENCE {
	ecgi						ECGI,
	iE-Extensions					ProtocolExtensionContainer { {ServedCellsToActivate-Item-ExtIEs} } OPTIONAL,
	...
}
*/

struct ServedCellsToActivate_Item : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "ServedCellsToActivate-Item";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct ecgi_t : ECGI
	{
		static constexpr const char* name() {return "ecgi_t";}
		using parent_t = ECGI;

	};
	ecgi_t& ref_ecgi() {return ecgi;}
	ecgi_t const& ref_ecgi() const {return ecgi;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ServedCellsToActivate_Item_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ServedCellsToActivate_Item_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(ecgi);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(ecgi);
		v(iE_Extensions);

	};
	void clear()
	{
		ecgi.clear();
		iE_Extensions.clear();

	};
	private:
	ecgi_t	ecgi;
	iE_Extensions_t	iE_Extensions;

};
/*
ServedCellsToActivate::= SEQUENCE (SIZE (1..maxCellineNB)) OF ServedCellsToActivate-Item
*/

struct ServedCellsToActivate_elm : ServedCellsToActivate_Item
{
	static constexpr const char* name() {return "ServedCellsToActivate_elm";}
	using parent_t = ServedCellsToActivate_Item;

};
struct ServedCellsToActivate : asn::sequenceof<ServedCellsToActivate_elm>
{
	static constexpr const char* name() {return "ServedCellsToActivate";}
	using parent_t = asn::sequenceof<ServedCellsToActivate_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxCellineNB >>;

};
/*
CellActivationRequest-IEs X2AP-PROTOCOL-IES ::= {
	{ ID id-ServedCellsToActivate 	CRITICALITY reject	TYPE ServedCellsToActivate		PRESENCE mandatory},
	...
}
*/

struct CellActivationRequest_IEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_ServedCellsToActivate() { set(id_ServedCellsToActivate); type=1;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_ServedCellsToActivate)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_ServedCellsToActivate);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_ServedCellsToActivate() { set(reject); type=1;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(reject)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(reject);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Value_t : asn::typefield<true>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		ServedCellsToActivate& select_id_ServedCellsToActivate() { return set<ServedCellsToActivate>(1); }
		ServedCellsToActivate const* get_id_ServedCellsToActivate() const { return get<ServedCellsToActivate>(1); }
		bool is_unknown() const { return type == 2; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<ServedCellsToActivate>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<ServedCellsToActivate>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_ServedCellsToActivate()); return true;
			case 2: if(type != 2) {clear(); asn::base::set();} type = 2; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<ServedCellsToActivate>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(ServedCellsToActivate)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_ServedCellsToActivate() { set(mandatory); type=1;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
CellActivationRequest ::= SEQUENCE {
	protocolIEs		ProtocolIE-Container	{{CellActivationRequest-IEs}},
	...
}
*/

struct CellActivationRequest : asn::sequence<1, 0, true, 0>
{
	static constexpr const char* name() {return "CellActivationRequest";}
	using parent_t = asn::sequence<1, 0, true, 0>;
	struct protocolIEs_t : ProtocolIE_Container<CellActivationRequest_IEs>
	{
		static constexpr const char* name() {return "protocolIEs_t";}
		using parent_t = ProtocolIE_Container<CellActivationRequest_IEs>;

	};
	protocolIEs_t& ref_protocolIEs() {return protocolIEs;}
	protocolIEs_t const& ref_protocolIEs() const {return protocolIEs;}
	template<typename V> void decode(V& v)
	{
		v(protocolIEs);

	};
	template<typename V> void encode(V& v) const
	{
		v(protocolIEs);

	};
	void clear()
	{
		protocolIEs.clear();

	};
	private:
	protocolIEs_t	protocolIEs;

};
/*
CellActivationResponse-IEs X2AP-PROTOCOL-IES ::= {
	{ ID id-ActivatedCellList		CRITICALITY ignore	TYPE ActivatedCellList				PRESENCE mandatory}|
	{ ID id-CriticalityDiagnostics	CRITICALITY ignore	TYPE CriticalityDiagnostics			PRESENCE optional},
	...
}
*/

struct CellActivationResponse_IEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_ActivatedCellList() { set(id_ActivatedCellList); type=1;}
		void select_id_CriticalityDiagnostics() { set(id_CriticalityDiagnostics); type=2;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_ActivatedCellList)) { type = 1; return true; }
			else if(equal(id_CriticalityDiagnostics)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_ActivatedCellList);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_CriticalityDiagnostics);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_ActivatedCellList() { set(ignore); type=1;}
		void select_id_CriticalityDiagnostics() { set(ignore); type=2;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else if(equal(ignore)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(ignore);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Value_t : asn::typefield<true>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		ActivatedCellList& select_id_ActivatedCellList() { return set<ActivatedCellList>(1); }
		ActivatedCellList const* get_id_ActivatedCellList() const { return get<ActivatedCellList>(1); }
		CriticalityDiagnostics& select_id_CriticalityDiagnostics() { return set<CriticalityDiagnostics>(2); }
		CriticalityDiagnostics const* get_id_CriticalityDiagnostics() const { return get<CriticalityDiagnostics>(2); }
		bool is_unknown() const { return type == 3; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<ActivatedCellList>(); break;
			case 2: var.destroy<CriticalityDiagnostics>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<ActivatedCellList>(1);
			v.template operator()<CriticalityDiagnostics>(2);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_ActivatedCellList()); return true;
			case 2: v(select_id_CriticalityDiagnostics()); return true;
			case 3: if(type != 3) {clear(); asn::base::set();} type = 3; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<ActivatedCellList>()); return true;
			case 2: v(var.as<CriticalityDiagnostics>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(ActivatedCellList)];
			char dummy2[sizeof(CriticalityDiagnostics)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_ActivatedCellList() { set(mandatory); type=1;}
		void select_id_CriticalityDiagnostics() { set(optional); type=2;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			else if(equal(optional)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(optional);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
CellActivationResponse ::= SEQUENCE {
	protocolIEs		ProtocolIE-Container	{{CellActivationResponse-IEs}},
	...
}
*/

struct CellActivationResponse : asn::sequence<1, 0, true, 0>
{
	static constexpr const char* name() {return "CellActivationResponse";}
	using parent_t = asn::sequence<1, 0, true, 0>;
	struct protocolIEs_t : ProtocolIE_Container<CellActivationResponse_IEs>
	{
		static constexpr const char* name() {return "protocolIEs_t";}
		using parent_t = ProtocolIE_Container<CellActivationResponse_IEs>;

	};
	protocolIEs_t& ref_protocolIEs() {return protocolIEs;}
	protocolIEs_t const& ref_protocolIEs() const {return protocolIEs;}
	template<typename V> void decode(V& v)
	{
		v(protocolIEs);

	};
	template<typename V> void encode(V& v) const
	{
		v(protocolIEs);

	};
	void clear()
	{
		protocolIEs.clear();

	};
	private:
	protocolIEs_t	protocolIEs;

};
/*
Limited-list-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct Limited_list_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
Limited-list 	::= SEQUENCE (SIZE (1..maxCellinengNB)) OF SEQUENCE {
	nrCellID			NRCGI,
		iE-Extensions						ProtocolExtensionContainer { {Limited-list-ExtIEs} } OPTIONAL,
	...
}
*/

struct Limited_list_elm : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "Limited_list_elm";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct nrCellID_t : NRCGI
	{
		static constexpr const char* name() {return "nrCellID_t";}
		using parent_t = NRCGI;

	};
	nrCellID_t& ref_nrCellID() {return nrCellID;}
	nrCellID_t const& ref_nrCellID() const {return nrCellID;}
	struct iE_Extensions_t : ProtocolExtensionContainer<Limited_list_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<Limited_list_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(nrCellID);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(nrCellID);
		v(iE_Extensions);

	};
	void clear()
	{
		nrCellID.clear();
		iE_Extensions.clear();

	};
	private:
	nrCellID_t	nrCellID;
	iE_Extensions_t	iE_Extensions;

};
struct Limited_list : asn::sequenceof<Limited_list_elm>
{
	static constexpr const char* name() {return "Limited-list";}
	using parent_t = asn::sequenceof<Limited_list_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxCellinengNB >>;

};
/*
CellAssistanceInformation ::= CHOICE {
	limited-list				Limited-list,
	full-list				ENUMERATED {allServedNRcells, ...},
	...
}
*/

struct CellAssistanceInformation : asn::choice<2, 0, true>
{
	static constexpr const char* name() {return "CellAssistanceInformation";}
	using parent_t = asn::choice<2, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 3;}
	void set_unknown() { set_index(3);  }
	~CellAssistanceInformation() {clear();}
	struct limited_list_t : Limited_list
	{
		static constexpr const char* name() {return "limited_list_t";}
		using parent_t = Limited_list;

	};
	struct full_list_t : asn::enumerated<1, 0, true>
	{
		static constexpr const char* name() {return "full_list_t";}
		using parent_t = asn::enumerated<1, 0, true>;
		typedef enum {
			allServedNRcells
		} index_t;

	};

	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<limited_list_t>(); break;
		case 2: var.destroy<full_list_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<limited_list_t>());
		case 2: set_index(2); return v(var.build<full_list_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<limited_list_t>());
		case 2: return v(var.as<full_list_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<limited_list_t>(1);
		v.template operator()<full_list_t>(2);

	}
	limited_list_t& select_limited_list() { if(get_index() != 1) { clear(); set_index(1); return var.build<limited_list_t>();} return var.as<limited_list_t>();}
	limited_list_t const* get_limited_list() const { if(get_index() == 1) { return &var.as<limited_list_t>();} return nullptr; }
	full_list_t& select_full_list() { if(get_index() != 2) { clear(); set_index(2); return var.build<full_list_t>();} return var.as<full_list_t>();}
	full_list_t const* get_full_list() const { if(get_index() == 2) { return &var.as<full_list_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(limited_list_t)];
		char dummy2[sizeof(full_list_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
CellInformation-Item-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
{ ID id-ABSInformation						CRITICALITY ignore	EXTENSION ABSInformation							PRESENCE optional }|
{ ID id-InvokeIndication					CRITICALITY ignore	EXTENSION InvokeIndication							PRESENCE optional }|
{ ID id-IntendedULDLConfiguration			CRITICALITY ignore	EXTENSION SubframeAssignment						PRESENCE optional }|
{ ID id-ExtendedULInterferenceOverloadInfo	CRITICALITY ignore	EXTENSION ExtendedULInterferenceOverloadInfo	PRESENCE optional }|
{ ID id-CoMPInformation						CRITICALITY ignore	EXTENSION CoMPInformation							PRESENCE optional }|
{ ID id-DynamicDLTransmissionInformation	CRITICALITY ignore	EXTENSION DynamicDLTransmissionInformation		PRESENCE optional },
	...
}
*/

struct CellInformation_Item_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 7; }
		void clear() {type = 0;}
		void select_id_ABSInformation() { set(id_ABSInformation); type=1;}
		void select_id_InvokeIndication() { set(id_InvokeIndication); type=2;}
		void select_id_IntendedULDLConfiguration() { set(id_IntendedULDLConfiguration); type=3;}
		void select_id_ExtendedULInterferenceOverloadInfo() { set(id_ExtendedULInterferenceOverloadInfo); type=4;}
		void select_id_CoMPInformation() { set(id_CoMPInformation); type=5;}
		void select_id_DynamicDLTransmissionInformation() { set(id_DynamicDLTransmissionInformation); type=6;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_ABSInformation)) { type = 1; return true; }
			else if(equal(id_InvokeIndication)) { type = 2; return true; }
			else if(equal(id_IntendedULDLConfiguration)) { type = 3; return true; }
			else if(equal(id_ExtendedULInterferenceOverloadInfo)) { type = 4; return true; }
			else if(equal(id_CoMPInformation)) { type = 5; return true; }
			else if(equal(id_DynamicDLTransmissionInformation)) { type = 6; return true; }
			else { type = 7; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_ABSInformation);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_InvokeIndication);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(id_IntendedULDLConfiguration);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(id_ExtendedULInterferenceOverloadInfo);} return false;
			case 5: type = 5; if(v(ref_nested())) { return equal(id_CoMPInformation);} return false;
			case 6: type = 6; if(v(ref_nested())) { return equal(id_DynamicDLTransmissionInformation);} return false;
			case 7: type = 7; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 7; }
		void clear() {type = 0;}
		void select_id_ABSInformation() { set(ignore); type=1;}
		void select_id_InvokeIndication() { set(ignore); type=2;}
		void select_id_IntendedULDLConfiguration() { set(ignore); type=3;}
		void select_id_ExtendedULInterferenceOverloadInfo() { set(ignore); type=4;}
		void select_id_CoMPInformation() { set(ignore); type=5;}
		void select_id_DynamicDLTransmissionInformation() { set(ignore); type=6;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else if(equal(ignore)) { type = 2; return true; }
			else if(equal(ignore)) { type = 3; return true; }
			else if(equal(ignore)) { type = 4; return true; }
			else if(equal(ignore)) { type = 5; return true; }
			else if(equal(ignore)) { type = 6; return true; }
			else { type = 7; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(ignore);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(ignore);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(ignore);} return false;
			case 5: type = 5; if(v(ref_nested())) { return equal(ignore);} return false;
			case 6: type = 6; if(v(ref_nested())) { return equal(ignore);} return false;
			case 7: type = 7; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		ABSInformation& select_id_ABSInformation() { return set<ABSInformation>(1); }
		ABSInformation const* get_id_ABSInformation() const { return get<ABSInformation>(1); }
		InvokeIndication& select_id_InvokeIndication() { return set<InvokeIndication>(2); }
		InvokeIndication const* get_id_InvokeIndication() const { return get<InvokeIndication>(2); }
		SubframeAssignment& select_id_IntendedULDLConfiguration() { return set<SubframeAssignment>(3); }
		SubframeAssignment const* get_id_IntendedULDLConfiguration() const { return get<SubframeAssignment>(3); }
		ExtendedULInterferenceOverloadInfo& select_id_ExtendedULInterferenceOverloadInfo() { return set<ExtendedULInterferenceOverloadInfo>(4); }
		ExtendedULInterferenceOverloadInfo const* get_id_ExtendedULInterferenceOverloadInfo() const { return get<ExtendedULInterferenceOverloadInfo>(4); }
		CoMPInformation& select_id_CoMPInformation() { return set<CoMPInformation>(5); }
		CoMPInformation const* get_id_CoMPInformation() const { return get<CoMPInformation>(5); }
		DynamicDLTransmissionInformation& select_id_DynamicDLTransmissionInformation() { return set<DynamicDLTransmissionInformation>(6); }
		DynamicDLTransmissionInformation const* get_id_DynamicDLTransmissionInformation() const { return get<DynamicDLTransmissionInformation>(6); }
		bool is_unknown() const { return type == 7; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<ABSInformation>(); break;
			case 2: var.destroy<InvokeIndication>(); break;
			case 3: var.destroy<SubframeAssignment>(); break;
			case 4: var.destroy<ExtendedULInterferenceOverloadInfo>(); break;
			case 5: var.destroy<CoMPInformation>(); break;
			case 6: var.destroy<DynamicDLTransmissionInformation>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<ABSInformation>(1);
			v.template operator()<InvokeIndication>(2);
			v.template operator()<SubframeAssignment>(3);
			v.template operator()<ExtendedULInterferenceOverloadInfo>(4);
			v.template operator()<CoMPInformation>(5);
			v.template operator()<DynamicDLTransmissionInformation>(6);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_ABSInformation()); return true;
			case 2: v(select_id_InvokeIndication()); return true;
			case 3: v(select_id_IntendedULDLConfiguration()); return true;
			case 4: v(select_id_ExtendedULInterferenceOverloadInfo()); return true;
			case 5: v(select_id_CoMPInformation()); return true;
			case 6: v(select_id_DynamicDLTransmissionInformation()); return true;
			case 7: if(type != 7) {clear(); asn::base::set();} type = 7; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<ABSInformation>()); return true;
			case 2: v(var.as<InvokeIndication>()); return true;
			case 3: v(var.as<SubframeAssignment>()); return true;
			case 4: v(var.as<ExtendedULInterferenceOverloadInfo>()); return true;
			case 5: v(var.as<CoMPInformation>()); return true;
			case 6: v(var.as<DynamicDLTransmissionInformation>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(ABSInformation)];
			char dummy2[sizeof(CoMPInformation)];
			char dummy3[sizeof(DynamicDLTransmissionInformation)];
			char dummy4[sizeof(ExtendedULInterferenceOverloadInfo)];
			char dummy5[sizeof(InvokeIndication)];
			char dummy6[sizeof(SubframeAssignment)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 7; }
		void clear() {type = 0;}
		void select_id_ABSInformation() { set(optional); type=1;}
		void select_id_InvokeIndication() { set(optional); type=2;}
		void select_id_IntendedULDLConfiguration() { set(optional); type=3;}
		void select_id_ExtendedULInterferenceOverloadInfo() { set(optional); type=4;}
		void select_id_CoMPInformation() { set(optional); type=5;}
		void select_id_DynamicDLTransmissionInformation() { set(optional); type=6;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(optional)) { type = 1; return true; }
			else if(equal(optional)) { type = 2; return true; }
			else if(equal(optional)) { type = 3; return true; }
			else if(equal(optional)) { type = 4; return true; }
			else if(equal(optional)) { type = 5; return true; }
			else if(equal(optional)) { type = 6; return true; }
			else { type = 7; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(optional);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(optional);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(optional);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(optional);} return false;
			case 5: type = 5; if(v(ref_nested())) { return equal(optional);} return false;
			case 6: type = 6; if(v(ref_nested())) { return equal(optional);} return false;
			case 7: type = 7; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
CellInformation-Item ::= SEQUENCE {
	cell-ID							ECGI,
	ul-InterferenceOverloadIndication		UL-InterferenceOverloadIndication		OPTIONAL,
	ul-HighInterferenceIndicationInfo		UL-HighInterferenceIndicationInfo		OPTIONAL,
	relativeNarrowbandTxPower				RelativeNarrowbandTxPower				OPTIONAL,
	iE-Extensions							ProtocolExtensionContainer { {CellInformation-Item-ExtIEs} }	OPTIONAL,
	...
}
*/

struct CellInformation_Item : asn::sequence<5, 0, true, 4>
{
	static constexpr const char* name() {return "CellInformation-Item";}
	using parent_t = asn::sequence<5, 0, true, 4>;
	struct cell_ID_t : ECGI
	{
		static constexpr const char* name() {return "cell_ID_t";}
		using parent_t = ECGI;

	};
	cell_ID_t& ref_cell_ID() {return cell_ID;}
	cell_ID_t const& ref_cell_ID() const {return cell_ID;}
	struct ul_InterferenceOverloadIndication_t : UL_InterferenceOverloadIndication
	{
		static constexpr const char* name() {return "ul_InterferenceOverloadIndication_t";}
		using parent_t = UL_InterferenceOverloadIndication;
		static constexpr bool optional = true;

	};
	ul_InterferenceOverloadIndication_t& set_ul_InterferenceOverloadIndication() { ul_InterferenceOverloadIndication.setpresent(true); return ul_InterferenceOverloadIndication;}
	ul_InterferenceOverloadIndication_t const* get_ul_InterferenceOverloadIndication() const {return ul_InterferenceOverloadIndication.is_valid() ? &ul_InterferenceOverloadIndication : nullptr;}
	struct ul_HighInterferenceIndicationInfo_t : UL_HighInterferenceIndicationInfo
	{
		static constexpr const char* name() {return "ul_HighInterferenceIndicationInfo_t";}
		using parent_t = UL_HighInterferenceIndicationInfo;
		static constexpr bool optional = true;

	};
	ul_HighInterferenceIndicationInfo_t& set_ul_HighInterferenceIndicationInfo() { ul_HighInterferenceIndicationInfo.setpresent(true); return ul_HighInterferenceIndicationInfo;}
	ul_HighInterferenceIndicationInfo_t const* get_ul_HighInterferenceIndicationInfo() const {return ul_HighInterferenceIndicationInfo.is_valid() ? &ul_HighInterferenceIndicationInfo : nullptr;}
	struct relativeNarrowbandTxPower_t : RelativeNarrowbandTxPower
	{
		static constexpr const char* name() {return "relativeNarrowbandTxPower_t";}
		using parent_t = RelativeNarrowbandTxPower;
		static constexpr bool optional = true;

	};
	relativeNarrowbandTxPower_t& set_relativeNarrowbandTxPower() { relativeNarrowbandTxPower.setpresent(true); return relativeNarrowbandTxPower;}
	relativeNarrowbandTxPower_t const* get_relativeNarrowbandTxPower() const {return relativeNarrowbandTxPower.is_valid() ? &relativeNarrowbandTxPower : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<CellInformation_Item_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<CellInformation_Item_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(cell_ID);
		v(ul_InterferenceOverloadIndication);
		v(ul_HighInterferenceIndicationInfo);
		v(relativeNarrowbandTxPower);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(cell_ID);
		v(ul_InterferenceOverloadIndication);
		v(ul_HighInterferenceIndicationInfo);
		v(relativeNarrowbandTxPower);
		v(iE_Extensions);

	};
	void clear()
	{
		cell_ID.clear();
		ul_InterferenceOverloadIndication.clear();
		ul_HighInterferenceIndicationInfo.clear();
		relativeNarrowbandTxPower.clear();
		iE_Extensions.clear();

	};
	private:
	cell_ID_t	cell_ID;
	ul_InterferenceOverloadIndication_t	ul_InterferenceOverloadIndication;
	ul_HighInterferenceIndicationInfo_t	ul_HighInterferenceIndicationInfo;
	relativeNarrowbandTxPower_t	relativeNarrowbandTxPower;
	iE_Extensions_t	iE_Extensions;

};
/*
CellInformation-ItemIEs X2AP-PROTOCOL-IES ::= {
	{ ID id-CellInformation-Item	CRITICALITY ignore	TYPE CellInformation-Item 	PRESENCE mandatory	}
}
*/

struct CellInformation_ItemIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_CellInformation_Item() { set(id_CellInformation_Item); type=1;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_CellInformation_Item)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_CellInformation_Item);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_CellInformation_Item() { set(ignore); type=1;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Value_t : asn::typefield<false>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		CellInformation_Item& select_id_CellInformation_Item() { return set<CellInformation_Item>(1); }
		CellInformation_Item const* get_id_CellInformation_Item() const { return get<CellInformation_Item>(1); }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<CellInformation_Item>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<CellInformation_Item>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_CellInformation_Item()); return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<CellInformation_Item>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(CellInformation_Item)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_CellInformation_Item() { set(mandatory); type=1;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
CellInformation-List ::= SEQUENCE (SIZE (1..maxCellineNB)) OF ProtocolIE-Single-Container { {CellInformation-ItemIEs} }
*/

struct CellInformation_List_elm : ProtocolIE_Single_Container<CellInformation_ItemIEs>
{
	static constexpr const char* name() {return "CellInformation_List_elm";}
	using parent_t = ProtocolIE_Single_Container<CellInformation_ItemIEs>;

};
struct CellInformation_List : asn::sequenceof<CellInformation_List_elm>
{
	static constexpr const char* name() {return "CellInformation-List";}
	using parent_t = asn::sequenceof<CellInformation_List_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxCellineNB >>;

};
/*
CellMeasurementResult-Item-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	{ ID id-CompositeAvailableCapacityGroup	CRITICALITY ignore	EXTENSION CompositeAvailableCapacityGroup		PRESENCE optional}|
	{ ID id-ABS-Status						CRITICALITY ignore	EXTENSION ABS-Status								PRESENCE optional}|
	{ ID id-RSRPMRList						CRITICALITY ignore	EXTENSION RSRPMRList								PRESENCE optional}|
	{ ID id-CSIReportList					CRITICALITY ignore	EXTENSION CSIReportList								PRESENCE optional}|
	{ ID id-CellReportingIndicator			CRITICALITY ignore	EXTENSION CellReportingIndicator					PRESENCE optional},
	...
}
*/

struct CellMeasurementResult_Item_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 6; }
		void clear() {type = 0;}
		void select_id_CompositeAvailableCapacityGroup() { set(id_CompositeAvailableCapacityGroup); type=1;}
		void select_id_ABS_Status() { set(id_ABS_Status); type=2;}
		void select_id_RSRPMRList() { set(id_RSRPMRList); type=3;}
		void select_id_CSIReportList() { set(id_CSIReportList); type=4;}
		void select_id_CellReportingIndicator() { set(id_CellReportingIndicator); type=5;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_CompositeAvailableCapacityGroup)) { type = 1; return true; }
			else if(equal(id_ABS_Status)) { type = 2; return true; }
			else if(equal(id_RSRPMRList)) { type = 3; return true; }
			else if(equal(id_CSIReportList)) { type = 4; return true; }
			else if(equal(id_CellReportingIndicator)) { type = 5; return true; }
			else { type = 6; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_CompositeAvailableCapacityGroup);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_ABS_Status);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(id_RSRPMRList);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(id_CSIReportList);} return false;
			case 5: type = 5; if(v(ref_nested())) { return equal(id_CellReportingIndicator);} return false;
			case 6: type = 6; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 6; }
		void clear() {type = 0;}
		void select_id_CompositeAvailableCapacityGroup() { set(ignore); type=1;}
		void select_id_ABS_Status() { set(ignore); type=2;}
		void select_id_RSRPMRList() { set(ignore); type=3;}
		void select_id_CSIReportList() { set(ignore); type=4;}
		void select_id_CellReportingIndicator() { set(ignore); type=5;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else if(equal(ignore)) { type = 2; return true; }
			else if(equal(ignore)) { type = 3; return true; }
			else if(equal(ignore)) { type = 4; return true; }
			else if(equal(ignore)) { type = 5; return true; }
			else { type = 6; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(ignore);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(ignore);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(ignore);} return false;
			case 5: type = 5; if(v(ref_nested())) { return equal(ignore);} return false;
			case 6: type = 6; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		CompositeAvailableCapacityGroup& select_id_CompositeAvailableCapacityGroup() { return set<CompositeAvailableCapacityGroup>(1); }
		CompositeAvailableCapacityGroup const* get_id_CompositeAvailableCapacityGroup() const { return get<CompositeAvailableCapacityGroup>(1); }
		ABS_Status& select_id_ABS_Status() { return set<ABS_Status>(2); }
		ABS_Status const* get_id_ABS_Status() const { return get<ABS_Status>(2); }
		RSRPMRList& select_id_RSRPMRList() { return set<RSRPMRList>(3); }
		RSRPMRList const* get_id_RSRPMRList() const { return get<RSRPMRList>(3); }
		CSIReportList& select_id_CSIReportList() { return set<CSIReportList>(4); }
		CSIReportList const* get_id_CSIReportList() const { return get<CSIReportList>(4); }
		CellReportingIndicator& select_id_CellReportingIndicator() { return set<CellReportingIndicator>(5); }
		CellReportingIndicator const* get_id_CellReportingIndicator() const { return get<CellReportingIndicator>(5); }
		bool is_unknown() const { return type == 6; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<CompositeAvailableCapacityGroup>(); break;
			case 2: var.destroy<ABS_Status>(); break;
			case 3: var.destroy<RSRPMRList>(); break;
			case 4: var.destroy<CSIReportList>(); break;
			case 5: var.destroy<CellReportingIndicator>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<CompositeAvailableCapacityGroup>(1);
			v.template operator()<ABS_Status>(2);
			v.template operator()<RSRPMRList>(3);
			v.template operator()<CSIReportList>(4);
			v.template operator()<CellReportingIndicator>(5);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_CompositeAvailableCapacityGroup()); return true;
			case 2: v(select_id_ABS_Status()); return true;
			case 3: v(select_id_RSRPMRList()); return true;
			case 4: v(select_id_CSIReportList()); return true;
			case 5: v(select_id_CellReportingIndicator()); return true;
			case 6: if(type != 6) {clear(); asn::base::set();} type = 6; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<CompositeAvailableCapacityGroup>()); return true;
			case 2: v(var.as<ABS_Status>()); return true;
			case 3: v(var.as<RSRPMRList>()); return true;
			case 4: v(var.as<CSIReportList>()); return true;
			case 5: v(var.as<CellReportingIndicator>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(ABS_Status)];
			char dummy2[sizeof(CSIReportList)];
			char dummy3[sizeof(CellReportingIndicator)];
			char dummy4[sizeof(CompositeAvailableCapacityGroup)];
			char dummy5[sizeof(RSRPMRList)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 6; }
		void clear() {type = 0;}
		void select_id_CompositeAvailableCapacityGroup() { set(optional); type=1;}
		void select_id_ABS_Status() { set(optional); type=2;}
		void select_id_RSRPMRList() { set(optional); type=3;}
		void select_id_CSIReportList() { set(optional); type=4;}
		void select_id_CellReportingIndicator() { set(optional); type=5;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(optional)) { type = 1; return true; }
			else if(equal(optional)) { type = 2; return true; }
			else if(equal(optional)) { type = 3; return true; }
			else if(equal(optional)) { type = 4; return true; }
			else if(equal(optional)) { type = 5; return true; }
			else { type = 6; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(optional);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(optional);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(optional);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(optional);} return false;
			case 5: type = 5; if(v(ref_nested())) { return equal(optional);} return false;
			case 6: type = 6; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
CellMeasurementResult-Item ::= SEQUENCE {
	cell-ID						ECGI,
	hWLoadIndicator				HWLoadIndicator		OPTIONAL,
	s1TNLLoadIndicator			S1TNLLoadIndicator	OPTIONAL,
	radioResourceStatus			RadioResourceStatus	OPTIONAL,
	iE-Extensions				ProtocolExtensionContainer { {CellMeasurementResult-Item-ExtIEs} }	OPTIONAL,
	...
}
*/

struct CellMeasurementResult_Item : asn::sequence<5, 0, true, 4>
{
	static constexpr const char* name() {return "CellMeasurementResult-Item";}
	using parent_t = asn::sequence<5, 0, true, 4>;
	struct cell_ID_t : ECGI
	{
		static constexpr const char* name() {return "cell_ID_t";}
		using parent_t = ECGI;

	};
	cell_ID_t& ref_cell_ID() {return cell_ID;}
	cell_ID_t const& ref_cell_ID() const {return cell_ID;}
	struct hWLoadIndicator_t : HWLoadIndicator
	{
		static constexpr const char* name() {return "hWLoadIndicator_t";}
		using parent_t = HWLoadIndicator;
		static constexpr bool optional = true;

	};
	hWLoadIndicator_t& set_hWLoadIndicator() { hWLoadIndicator.setpresent(true); return hWLoadIndicator;}
	hWLoadIndicator_t const* get_hWLoadIndicator() const {return hWLoadIndicator.is_valid() ? &hWLoadIndicator : nullptr;}
	struct s1TNLLoadIndicator_t : S1TNLLoadIndicator
	{
		static constexpr const char* name() {return "s1TNLLoadIndicator_t";}
		using parent_t = S1TNLLoadIndicator;
		static constexpr bool optional = true;

	};
	s1TNLLoadIndicator_t& set_s1TNLLoadIndicator() { s1TNLLoadIndicator.setpresent(true); return s1TNLLoadIndicator;}
	s1TNLLoadIndicator_t const* get_s1TNLLoadIndicator() const {return s1TNLLoadIndicator.is_valid() ? &s1TNLLoadIndicator : nullptr;}
	struct radioResourceStatus_t : RadioResourceStatus
	{
		static constexpr const char* name() {return "radioResourceStatus_t";}
		using parent_t = RadioResourceStatus;
		static constexpr bool optional = true;

	};
	radioResourceStatus_t& set_radioResourceStatus() { radioResourceStatus.setpresent(true); return radioResourceStatus;}
	radioResourceStatus_t const* get_radioResourceStatus() const {return radioResourceStatus.is_valid() ? &radioResourceStatus : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<CellMeasurementResult_Item_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<CellMeasurementResult_Item_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(cell_ID);
		v(hWLoadIndicator);
		v(s1TNLLoadIndicator);
		v(radioResourceStatus);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(cell_ID);
		v(hWLoadIndicator);
		v(s1TNLLoadIndicator);
		v(radioResourceStatus);
		v(iE_Extensions);

	};
	void clear()
	{
		cell_ID.clear();
		hWLoadIndicator.clear();
		s1TNLLoadIndicator.clear();
		radioResourceStatus.clear();
		iE_Extensions.clear();

	};
	private:
	cell_ID_t	cell_ID;
	hWLoadIndicator_t	hWLoadIndicator;
	s1TNLLoadIndicator_t	s1TNLLoadIndicator;
	radioResourceStatus_t	radioResourceStatus;
	iE_Extensions_t	iE_Extensions;

};
/*
CellMeasurementResult-ItemIEs X2AP-PROTOCOL-IES ::= {
	{ ID id-CellMeasurementResult-Item	CRITICALITY ignore	TYPE CellMeasurementResult-Item	PRESENCE mandatory}
}
*/

struct CellMeasurementResult_ItemIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_CellMeasurementResult_Item() { set(id_CellMeasurementResult_Item); type=1;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_CellMeasurementResult_Item)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_CellMeasurementResult_Item);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_CellMeasurementResult_Item() { set(ignore); type=1;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Value_t : asn::typefield<false>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		CellMeasurementResult_Item& select_id_CellMeasurementResult_Item() { return set<CellMeasurementResult_Item>(1); }
		CellMeasurementResult_Item const* get_id_CellMeasurementResult_Item() const { return get<CellMeasurementResult_Item>(1); }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<CellMeasurementResult_Item>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<CellMeasurementResult_Item>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_CellMeasurementResult_Item()); return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<CellMeasurementResult_Item>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(CellMeasurementResult_Item)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_CellMeasurementResult_Item() { set(mandatory); type=1;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
CellMeasurementResult-List ::= SEQUENCE (SIZE (1..maxCellineNB)) OF ProtocolIE-Single-Container { {CellMeasurementResult-ItemIEs} }
*/

struct CellMeasurementResult_List_elm : ProtocolIE_Single_Container<CellMeasurementResult_ItemIEs>
{
	static constexpr const char* name() {return "CellMeasurementResult_List_elm";}
	using parent_t = ProtocolIE_Single_Container<CellMeasurementResult_ItemIEs>;

};
struct CellMeasurementResult_List : asn::sequenceof<CellMeasurementResult_List_elm>
{
	static constexpr const char* name() {return "CellMeasurementResult-List";}
	using parent_t = asn::sequenceof<CellMeasurementResult_List_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxCellineNB >>;

};
/*
CellToReport-Item-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct CellToReport_Item_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
CellToReport-Item ::= SEQUENCE {
	cell-ID									ECGI,
	iE-Extensions							ProtocolExtensionContainer { {CellToReport-Item-ExtIEs} } OPTIONAL,
	...
}
*/

struct CellToReport_Item : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "CellToReport-Item";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct cell_ID_t : ECGI
	{
		static constexpr const char* name() {return "cell_ID_t";}
		using parent_t = ECGI;

	};
	cell_ID_t& ref_cell_ID() {return cell_ID;}
	cell_ID_t const& ref_cell_ID() const {return cell_ID;}
	struct iE_Extensions_t : ProtocolExtensionContainer<CellToReport_Item_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<CellToReport_Item_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(cell_ID);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(cell_ID);
		v(iE_Extensions);

	};
	void clear()
	{
		cell_ID.clear();
		iE_Extensions.clear();

	};
	private:
	cell_ID_t	cell_ID;
	iE_Extensions_t	iE_Extensions;

};
/*
CellToReport-ItemIEs X2AP-PROTOCOL-IES ::= {
	{ ID id-CellToReport-Item	CRITICALITY ignore	TYPE CellToReport-Item 	PRESENCE mandatory}
}
*/

struct CellToReport_ItemIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_CellToReport_Item() { set(id_CellToReport_Item); type=1;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_CellToReport_Item)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_CellToReport_Item);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_CellToReport_Item() { set(ignore); type=1;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Value_t : asn::typefield<false>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		CellToReport_Item& select_id_CellToReport_Item() { return set<CellToReport_Item>(1); }
		CellToReport_Item const* get_id_CellToReport_Item() const { return get<CellToReport_Item>(1); }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<CellToReport_Item>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<CellToReport_Item>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_CellToReport_Item()); return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<CellToReport_Item>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(CellToReport_Item)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_CellToReport_Item() { set(mandatory); type=1;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
CellToReport-List 		::= SEQUENCE (SIZE (1..maxCellineNB)) OF ProtocolIE-Single-Container { {CellToReport-ItemIEs} }
*/

struct CellToReport_List_elm : ProtocolIE_Single_Container<CellToReport_ItemIEs>
{
	static constexpr const char* name() {return "CellToReport_List_elm";}
	using parent_t = ProtocolIE_Single_Container<CellToReport_ItemIEs>;

};
struct CellToReport_List : asn::sequenceof<CellToReport_List_elm>
{
	static constexpr const char* name() {return "CellToReport-List";}
	using parent_t = asn::sequenceof<CellToReport_List_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxCellineNB >>;

};
/*
MeasurementFailureCause-Item-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct MeasurementFailureCause_Item_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
MeasurementFailureCause-Item ::= SEQUENCE {
	measurementFailedReportCharacteristics			ReportCharacteristics,
	cause											Cause,
	iE-Extensions									ProtocolExtensionContainer { {MeasurementFailureCause-Item-ExtIEs} }	OPTIONAL,
	...
}
*/

struct MeasurementFailureCause_Item : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "MeasurementFailureCause-Item";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct measurementFailedReportCharacteristics_t : ReportCharacteristics
	{
		static constexpr const char* name() {return "measurementFailedReportCharacteristics_t";}
		using parent_t = ReportCharacteristics;

	};
	measurementFailedReportCharacteristics_t& ref_measurementFailedReportCharacteristics() {return measurementFailedReportCharacteristics;}
	measurementFailedReportCharacteristics_t const& ref_measurementFailedReportCharacteristics() const {return measurementFailedReportCharacteristics;}
	struct cause_t : Cause
	{
		static constexpr const char* name() {return "cause_t";}
		using parent_t = Cause;

	};
	cause_t& ref_cause() {return cause;}
	cause_t const& ref_cause() const {return cause;}
	struct iE_Extensions_t : ProtocolExtensionContainer<MeasurementFailureCause_Item_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<MeasurementFailureCause_Item_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(measurementFailedReportCharacteristics);
		v(cause);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(measurementFailedReportCharacteristics);
		v(cause);
		v(iE_Extensions);

	};
	void clear()
	{
		measurementFailedReportCharacteristics.clear();
		cause.clear();
		iE_Extensions.clear();

	};
	private:
	measurementFailedReportCharacteristics_t	measurementFailedReportCharacteristics;
	cause_t	cause;
	iE_Extensions_t	iE_Extensions;

};
/*
MeasurementFailureCause-ItemIEs X2AP-PROTOCOL-IES ::= {
	{ ID id-MeasurementFailureCause-Item	CRITICALITY ignore	TYPE MeasurementFailureCause-Item		PRESENCE mandatory}
}
*/

struct MeasurementFailureCause_ItemIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_MeasurementFailureCause_Item() { set(id_MeasurementFailureCause_Item); type=1;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_MeasurementFailureCause_Item)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_MeasurementFailureCause_Item);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_MeasurementFailureCause_Item() { set(ignore); type=1;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Value_t : asn::typefield<false>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		MeasurementFailureCause_Item& select_id_MeasurementFailureCause_Item() { return set<MeasurementFailureCause_Item>(1); }
		MeasurementFailureCause_Item const* get_id_MeasurementFailureCause_Item() const { return get<MeasurementFailureCause_Item>(1); }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<MeasurementFailureCause_Item>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<MeasurementFailureCause_Item>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_MeasurementFailureCause_Item()); return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<MeasurementFailureCause_Item>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(MeasurementFailureCause_Item)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_MeasurementFailureCause_Item() { set(mandatory); type=1;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
MeasurementFailureCause-List ::= SEQUENCE (SIZE (1..maxFailedMeasObjects)) OF ProtocolIE-Single-Container { {MeasurementFailureCause-ItemIEs} }
*/

struct MeasurementFailureCause_List_elm : ProtocolIE_Single_Container<MeasurementFailureCause_ItemIEs>
{
	static constexpr const char* name() {return "MeasurementFailureCause_List_elm";}
	using parent_t = ProtocolIE_Single_Container<MeasurementFailureCause_ItemIEs>;

};
struct MeasurementFailureCause_List : asn::sequenceof<MeasurementFailureCause_List_elm>
{
	static constexpr const char* name() {return "MeasurementFailureCause-List";}
	using parent_t = asn::sequenceof<MeasurementFailureCause_List_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxFailedMeasObjects >>;

};
/*
CompleteFailureCauseInformation-Item-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct CompleteFailureCauseInformation_Item_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
CompleteFailureCauseInformation-Item ::= SEQUENCE {
	cell-ID											ECGI,
	measurementFailureCause-List					MeasurementFailureCause-List,
	iE-Extensions									ProtocolExtensionContainer { {CompleteFailureCauseInformation-Item-ExtIEs} }	OPTIONAL,
	...
}
*/

struct CompleteFailureCauseInformation_Item : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "CompleteFailureCauseInformation-Item";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct cell_ID_t : ECGI
	{
		static constexpr const char* name() {return "cell_ID_t";}
		using parent_t = ECGI;

	};
	cell_ID_t& ref_cell_ID() {return cell_ID;}
	cell_ID_t const& ref_cell_ID() const {return cell_ID;}
	struct measurementFailureCause_List_t : MeasurementFailureCause_List
	{
		static constexpr const char* name() {return "measurementFailureCause_List_t";}
		using parent_t = MeasurementFailureCause_List;

	};
	measurementFailureCause_List_t& ref_measurementFailureCause_List() {return measurementFailureCause_List;}
	measurementFailureCause_List_t const& ref_measurementFailureCause_List() const {return measurementFailureCause_List;}
	struct iE_Extensions_t : ProtocolExtensionContainer<CompleteFailureCauseInformation_Item_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<CompleteFailureCauseInformation_Item_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(cell_ID);
		v(measurementFailureCause_List);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(cell_ID);
		v(measurementFailureCause_List);
		v(iE_Extensions);

	};
	void clear()
	{
		cell_ID.clear();
		measurementFailureCause_List.clear();
		iE_Extensions.clear();

	};
	private:
	cell_ID_t	cell_ID;
	measurementFailureCause_List_t	measurementFailureCause_List;
	iE_Extensions_t	iE_Extensions;

};
/*
CompleteFailureCauseInformation-ItemIEs X2AP-PROTOCOL-IES ::= {
	{ ID id-CompleteFailureCauseInformation-Item	CRITICALITY ignore	TYPE CompleteFailureCauseInformation-Item	PRESENCE mandatory}
}
*/

struct CompleteFailureCauseInformation_ItemIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_CompleteFailureCauseInformation_Item() { set(id_CompleteFailureCauseInformation_Item); type=1;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_CompleteFailureCauseInformation_Item)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_CompleteFailureCauseInformation_Item);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_CompleteFailureCauseInformation_Item() { set(ignore); type=1;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Value_t : asn::typefield<false>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		CompleteFailureCauseInformation_Item& select_id_CompleteFailureCauseInformation_Item() { return set<CompleteFailureCauseInformation_Item>(1); }
		CompleteFailureCauseInformation_Item const* get_id_CompleteFailureCauseInformation_Item() const { return get<CompleteFailureCauseInformation_Item>(1); }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<CompleteFailureCauseInformation_Item>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<CompleteFailureCauseInformation_Item>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_CompleteFailureCauseInformation_Item()); return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<CompleteFailureCauseInformation_Item>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(CompleteFailureCauseInformation_Item)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_CompleteFailureCauseInformation_Item() { set(mandatory); type=1;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
CompleteFailureCauseInformation-List ::= SEQUENCE (SIZE (1..maxCellineNB)) OF ProtocolIE-Single-Container { {CompleteFailureCauseInformation-ItemIEs} }
*/

struct CompleteFailureCauseInformation_List_elm : ProtocolIE_Single_Container<CompleteFailureCauseInformation_ItemIEs>
{
	static constexpr const char* name() {return "CompleteFailureCauseInformation_List_elm";}
	using parent_t = ProtocolIE_Single_Container<CompleteFailureCauseInformation_ItemIEs>;

};
struct CompleteFailureCauseInformation_List : asn::sequenceof<CompleteFailureCauseInformation_List_elm>
{
	static constexpr const char* name() {return "CompleteFailureCauseInformation-List";}
	using parent_t = asn::sequenceof<CompleteFailureCauseInformation_List_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxCellineNB >>;

};
/*
E-RABs-DataForwardingAddress-ItemExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct E_RABs_DataForwardingAddress_ItemExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-DataForwardingAddress-Item ::= SEQUENCE {
	e-RAB-ID						E-RAB-ID,
	dl-GTPtunnelEndpoint			GTPtunnelEndpoint,
	iE-Extensions					ProtocolExtensionContainer { {E-RABs-DataForwardingAddress-ItemExtIEs} } OPTIONAL,
	...
}
*/

struct E_RABs_DataForwardingAddress_Item : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "E-RABs-DataForwardingAddress-Item";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct e_RAB_ID_t : E_RAB_ID
	{
		static constexpr const char* name() {return "e_RAB_ID_t";}
		using parent_t = E_RAB_ID;

	};
	e_RAB_ID_t& ref_e_RAB_ID() {return e_RAB_ID;}
	e_RAB_ID_t const& ref_e_RAB_ID() const {return e_RAB_ID;}
	struct dl_GTPtunnelEndpoint_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "dl_GTPtunnelEndpoint_t";}
		using parent_t = GTPtunnelEndpoint;

	};
	dl_GTPtunnelEndpoint_t& ref_dl_GTPtunnelEndpoint() {return dl_GTPtunnelEndpoint;}
	dl_GTPtunnelEndpoint_t const& ref_dl_GTPtunnelEndpoint() const {return dl_GTPtunnelEndpoint;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABs_DataForwardingAddress_ItemExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABs_DataForwardingAddress_ItemExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(e_RAB_ID);
		v(dl_GTPtunnelEndpoint);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(e_RAB_ID);
		v(dl_GTPtunnelEndpoint);
		v(iE_Extensions);

	};
	void clear()
	{
		e_RAB_ID.clear();
		dl_GTPtunnelEndpoint.clear();
		iE_Extensions.clear();

	};
	private:
	e_RAB_ID_t	e_RAB_ID;
	dl_GTPtunnelEndpoint_t	dl_GTPtunnelEndpoint;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABs-DataForwardingAddress-ItemIEs	X2AP-PROTOCOL-IES ::= {
	{ ID id-E-RABs-DataForwardingAddress-Item	CRITICALITY ignore	TYPE E-RABs-DataForwardingAddress-Item	PRESENCE mandatory},
	...
}
*/

struct E_RABs_DataForwardingAddress_ItemIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_E_RABs_DataForwardingAddress_Item() { set(id_E_RABs_DataForwardingAddress_Item); type=1;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_E_RABs_DataForwardingAddress_Item)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_E_RABs_DataForwardingAddress_Item);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_E_RABs_DataForwardingAddress_Item() { set(ignore); type=1;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Value_t : asn::typefield<true>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		E_RABs_DataForwardingAddress_Item& select_id_E_RABs_DataForwardingAddress_Item() { return set<E_RABs_DataForwardingAddress_Item>(1); }
		E_RABs_DataForwardingAddress_Item const* get_id_E_RABs_DataForwardingAddress_Item() const { return get<E_RABs_DataForwardingAddress_Item>(1); }
		bool is_unknown() const { return type == 2; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<E_RABs_DataForwardingAddress_Item>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<E_RABs_DataForwardingAddress_Item>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_E_RABs_DataForwardingAddress_Item()); return true;
			case 2: if(type != 2) {clear(); asn::base::set();} type = 2; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<E_RABs_DataForwardingAddress_Item>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(E_RABs_DataForwardingAddress_Item)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_E_RABs_DataForwardingAddress_Item() { set(mandatory); type=1;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-DataForwardingAddress-List ::= SEQUENCE (SIZE(1..maxnoofBearers)) OF ProtocolIE-Single-Container { {E-RABs-DataForwardingAddress-ItemIEs} }
*/

struct E_RABs_DataForwardingAddress_List_elm : ProtocolIE_Single_Container<E_RABs_DataForwardingAddress_ItemIEs>
{
	static constexpr const char* name() {return "E_RABs_DataForwardingAddress_List_elm";}
	using parent_t = ProtocolIE_Single_Container<E_RABs_DataForwardingAddress_ItemIEs>;

};
struct E_RABs_DataForwardingAddress_List : asn::sequenceof<E_RABs_DataForwardingAddress_List_elm>
{
	static constexpr const char* name() {return "E-RABs-DataForwardingAddress-List";}
	using parent_t = asn::sequenceof<E_RABs_DataForwardingAddress_List_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofBearers >>;

};
/*
DataForwardingAddressIndication-IEs X2AP-PROTOCOL-IES ::= {
	{ ID id-New-eNB-UE-X2AP-ID-Extension		CRITICALITY ignore	TYPE UE-X2AP-ID-Extension						PRESENCE optional }|
	{ ID id-Old-eNB-UE-X2AP-ID					CRITICALITY ignore	TYPE UE-X2AP-ID									PRESENCE mandatory}|
	{ ID id-Old-eNB-UE-X2AP-ID-Extension		CRITICALITY ignore	TYPE UE-X2AP-ID-Extension						PRESENCE optional }|
	{ ID id-E-RABs-DataForwardingAddress-List	CRITICALITY ignore	TYPE E-RABs-DataForwardingAddress-List		PRESENCE mandatory},
	...
}
*/

struct DataForwardingAddressIndication_IEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 5; }
		void clear() {type = 0;}
		void select_id_New_eNB_UE_X2AP_ID_Extension() { set(id_New_eNB_UE_X2AP_ID_Extension); type=1;}
		void select_id_Old_eNB_UE_X2AP_ID() { set(id_Old_eNB_UE_X2AP_ID); type=2;}
		void select_id_Old_eNB_UE_X2AP_ID_Extension() { set(id_Old_eNB_UE_X2AP_ID_Extension); type=3;}
		void select_id_E_RABs_DataForwardingAddress_List() { set(id_E_RABs_DataForwardingAddress_List); type=4;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_New_eNB_UE_X2AP_ID_Extension)) { type = 1; return true; }
			else if(equal(id_Old_eNB_UE_X2AP_ID)) { type = 2; return true; }
			else if(equal(id_Old_eNB_UE_X2AP_ID_Extension)) { type = 3; return true; }
			else if(equal(id_E_RABs_DataForwardingAddress_List)) { type = 4; return true; }
			else { type = 5; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_New_eNB_UE_X2AP_ID_Extension);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_Old_eNB_UE_X2AP_ID);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(id_Old_eNB_UE_X2AP_ID_Extension);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(id_E_RABs_DataForwardingAddress_List);} return false;
			case 5: type = 5; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 5; }
		void clear() {type = 0;}
		void select_id_New_eNB_UE_X2AP_ID_Extension() { set(ignore); type=1;}
		void select_id_Old_eNB_UE_X2AP_ID() { set(ignore); type=2;}
		void select_id_Old_eNB_UE_X2AP_ID_Extension() { set(ignore); type=3;}
		void select_id_E_RABs_DataForwardingAddress_List() { set(ignore); type=4;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else if(equal(ignore)) { type = 2; return true; }
			else if(equal(ignore)) { type = 3; return true; }
			else if(equal(ignore)) { type = 4; return true; }
			else { type = 5; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(ignore);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(ignore);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(ignore);} return false;
			case 5: type = 5; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Value_t : asn::typefield<true>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		UE_X2AP_ID_Extension& select_id_New_eNB_UE_X2AP_ID_Extension() { return set<UE_X2AP_ID_Extension>(1); }
		UE_X2AP_ID_Extension const* get_id_New_eNB_UE_X2AP_ID_Extension() const { return get<UE_X2AP_ID_Extension>(1); }
		UE_X2AP_ID& select_id_Old_eNB_UE_X2AP_ID() { return set<UE_X2AP_ID>(2); }
		UE_X2AP_ID const* get_id_Old_eNB_UE_X2AP_ID() const { return get<UE_X2AP_ID>(2); }
		UE_X2AP_ID_Extension& select_id_Old_eNB_UE_X2AP_ID_Extension() { return set<UE_X2AP_ID_Extension>(3); }
		UE_X2AP_ID_Extension const* get_id_Old_eNB_UE_X2AP_ID_Extension() const { return get<UE_X2AP_ID_Extension>(3); }
		E_RABs_DataForwardingAddress_List& select_id_E_RABs_DataForwardingAddress_List() { return set<E_RABs_DataForwardingAddress_List>(4); }
		E_RABs_DataForwardingAddress_List const* get_id_E_RABs_DataForwardingAddress_List() const { return get<E_RABs_DataForwardingAddress_List>(4); }
		bool is_unknown() const { return type == 5; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<UE_X2AP_ID_Extension>(); break;
			case 2: var.destroy<UE_X2AP_ID>(); break;
			case 3: var.destroy<UE_X2AP_ID_Extension>(); break;
			case 4: var.destroy<E_RABs_DataForwardingAddress_List>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<UE_X2AP_ID_Extension>(1);
			v.template operator()<UE_X2AP_ID>(2);
			v.template operator()<UE_X2AP_ID_Extension>(3);
			v.template operator()<E_RABs_DataForwardingAddress_List>(4);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_New_eNB_UE_X2AP_ID_Extension()); return true;
			case 2: v(select_id_Old_eNB_UE_X2AP_ID()); return true;
			case 3: v(select_id_Old_eNB_UE_X2AP_ID_Extension()); return true;
			case 4: v(select_id_E_RABs_DataForwardingAddress_List()); return true;
			case 5: if(type != 5) {clear(); asn::base::set();} type = 5; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<UE_X2AP_ID_Extension>()); return true;
			case 2: v(var.as<UE_X2AP_ID>()); return true;
			case 3: v(var.as<UE_X2AP_ID_Extension>()); return true;
			case 4: v(var.as<E_RABs_DataForwardingAddress_List>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(E_RABs_DataForwardingAddress_List)];
			char dummy2[sizeof(UE_X2AP_ID)];
			char dummy3[sizeof(UE_X2AP_ID_Extension)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 5; }
		void clear() {type = 0;}
		void select_id_New_eNB_UE_X2AP_ID_Extension() { set(optional); type=1;}
		void select_id_Old_eNB_UE_X2AP_ID() { set(mandatory); type=2;}
		void select_id_Old_eNB_UE_X2AP_ID_Extension() { set(optional); type=3;}
		void select_id_E_RABs_DataForwardingAddress_List() { set(mandatory); type=4;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(optional)) { type = 1; return true; }
			else if(equal(mandatory)) { type = 2; return true; }
			else if(equal(optional)) { type = 3; return true; }
			else if(equal(mandatory)) { type = 4; return true; }
			else { type = 5; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(optional);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(optional);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 5: type = 5; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
DataForwardingAddressIndication ::= SEQUENCE {
	protocolIEs		ProtocolIE-Container	{{DataForwardingAddressIndication-IEs}},
	...
}
*/

struct DataForwardingAddressIndication : asn::sequence<1, 0, true, 0>
{
	static constexpr const char* name() {return "DataForwardingAddressIndication";}
	using parent_t = asn::sequence<1, 0, true, 0>;
	struct protocolIEs_t : ProtocolIE_Container<DataForwardingAddressIndication_IEs>
	{
		static constexpr const char* name() {return "protocolIEs_t";}
		using parent_t = ProtocolIE_Container<DataForwardingAddressIndication_IEs>;

	};
	protocolIEs_t& ref_protocolIEs() {return protocolIEs;}
	protocolIEs_t const& ref_protocolIEs() const {return protocolIEs;}
	template<typename V> void decode(V& v)
	{
		v(protocolIEs);

	};
	template<typename V> void encode(V& v) const
	{
		v(protocolIEs);

	};
	void clear()
	{
		protocolIEs.clear();

	};
	private:
	protocolIEs_t	protocolIEs;

};
/*
E-RABs-Admitted-Item-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct E_RABs_Admitted_Item_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-Admitted-Item ::= SEQUENCE {
	e-RAB-ID					E-RAB-ID,
	uL-GTP-TunnelEndpoint			GTPtunnelEndpoint	OPTIONAL,
	dL-GTP-TunnelEndpoint			GTPtunnelEndpoint	OPTIONAL,
	iE-Extensions					ProtocolExtensionContainer { {E-RABs-Admitted-Item-ExtIEs} }	OPTIONAL,
	...
}
*/

struct E_RABs_Admitted_Item : asn::sequence<4, 0, true, 3>
{
	static constexpr const char* name() {return "E-RABs-Admitted-Item";}
	using parent_t = asn::sequence<4, 0, true, 3>;
	struct e_RAB_ID_t : E_RAB_ID
	{
		static constexpr const char* name() {return "e_RAB_ID_t";}
		using parent_t = E_RAB_ID;

	};
	e_RAB_ID_t& ref_e_RAB_ID() {return e_RAB_ID;}
	e_RAB_ID_t const& ref_e_RAB_ID() const {return e_RAB_ID;}
	struct uL_GTP_TunnelEndpoint_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "uL_GTP_TunnelEndpoint_t";}
		using parent_t = GTPtunnelEndpoint;
		static constexpr bool optional = true;

	};
	uL_GTP_TunnelEndpoint_t& set_uL_GTP_TunnelEndpoint() { uL_GTP_TunnelEndpoint.setpresent(true); return uL_GTP_TunnelEndpoint;}
	uL_GTP_TunnelEndpoint_t const* get_uL_GTP_TunnelEndpoint() const {return uL_GTP_TunnelEndpoint.is_valid() ? &uL_GTP_TunnelEndpoint : nullptr;}
	struct dL_GTP_TunnelEndpoint_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "dL_GTP_TunnelEndpoint_t";}
		using parent_t = GTPtunnelEndpoint;
		static constexpr bool optional = true;

	};
	dL_GTP_TunnelEndpoint_t& set_dL_GTP_TunnelEndpoint() { dL_GTP_TunnelEndpoint.setpresent(true); return dL_GTP_TunnelEndpoint;}
	dL_GTP_TunnelEndpoint_t const* get_dL_GTP_TunnelEndpoint() const {return dL_GTP_TunnelEndpoint.is_valid() ? &dL_GTP_TunnelEndpoint : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABs_Admitted_Item_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABs_Admitted_Item_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(e_RAB_ID);
		v(uL_GTP_TunnelEndpoint);
		v(dL_GTP_TunnelEndpoint);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(e_RAB_ID);
		v(uL_GTP_TunnelEndpoint);
		v(dL_GTP_TunnelEndpoint);
		v(iE_Extensions);

	};
	void clear()
	{
		e_RAB_ID.clear();
		uL_GTP_TunnelEndpoint.clear();
		dL_GTP_TunnelEndpoint.clear();
		iE_Extensions.clear();

	};
	private:
	e_RAB_ID_t	e_RAB_ID;
	uL_GTP_TunnelEndpoint_t	uL_GTP_TunnelEndpoint;
	dL_GTP_TunnelEndpoint_t	dL_GTP_TunnelEndpoint;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABs-Admitted-ItemIEs X2AP-PROTOCOL-IES ::= {
	{ ID id-E-RABs-Admitted-Item	CRITICALITY ignore	TYPE E-RABs-Admitted-Item 	PRESENCE mandatory	}
}
*/

struct E_RABs_Admitted_ItemIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_E_RABs_Admitted_Item() { set(id_E_RABs_Admitted_Item); type=1;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_E_RABs_Admitted_Item)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_E_RABs_Admitted_Item);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_E_RABs_Admitted_Item() { set(ignore); type=1;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Value_t : asn::typefield<false>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		E_RABs_Admitted_Item& select_id_E_RABs_Admitted_Item() { return set<E_RABs_Admitted_Item>(1); }
		E_RABs_Admitted_Item const* get_id_E_RABs_Admitted_Item() const { return get<E_RABs_Admitted_Item>(1); }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<E_RABs_Admitted_Item>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<E_RABs_Admitted_Item>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_E_RABs_Admitted_Item()); return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<E_RABs_Admitted_Item>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(E_RABs_Admitted_Item)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_E_RABs_Admitted_Item() { set(mandatory); type=1;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-Admitted-List 		::= SEQUENCE (SIZE (1..maxnoofBearers)) OF ProtocolIE-Single-Container { {E-RABs-Admitted-ItemIEs} }
*/

struct E_RABs_Admitted_List_elm : ProtocolIE_Single_Container<E_RABs_Admitted_ItemIEs>
{
	static constexpr const char* name() {return "E_RABs_Admitted_List_elm";}
	using parent_t = ProtocolIE_Single_Container<E_RABs_Admitted_ItemIEs>;

};
struct E_RABs_Admitted_List : asn::sequenceof<E_RABs_Admitted_List_elm>
{
	static constexpr const char* name() {return "E-RABs-Admitted-List";}
	using parent_t = asn::sequenceof<E_RABs_Admitted_List_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofBearers >>;

};
/*
E-RABs-Admitted-ToBeAdded-Item-SCG-BearerExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct E_RABs_Admitted_ToBeAdded_Item_SCG_BearerExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-Admitted-ToBeAdded-Item-SCG-Bearer ::= SEQUENCE {
	e-RAB-ID								E-RAB-ID,
	s1-DL-GTPtunnelEndpoint					GTPtunnelEndpoint,
	dL-Forwarding-GTPtunnelEndpoint			GTPtunnelEndpoint																	OPTIONAL,
	uL-Forwarding-GTPtunnelEndpoint			GTPtunnelEndpoint																	OPTIONAL,
	iE-Extensions					ProtocolExtensionContainer { {E-RABs-Admitted-ToBeAdded-Item-SCG-BearerExtIEs} }	OPTIONAL,
	...
}
*/

struct E_RABs_Admitted_ToBeAdded_Item_SCG_Bearer : asn::sequence<5, 0, true, 3>
{
	static constexpr const char* name() {return "E-RABs-Admitted-ToBeAdded-Item-SCG-Bearer";}
	using parent_t = asn::sequence<5, 0, true, 3>;
	struct e_RAB_ID_t : E_RAB_ID
	{
		static constexpr const char* name() {return "e_RAB_ID_t";}
		using parent_t = E_RAB_ID;

	};
	e_RAB_ID_t& ref_e_RAB_ID() {return e_RAB_ID;}
	e_RAB_ID_t const& ref_e_RAB_ID() const {return e_RAB_ID;}
	struct s1_DL_GTPtunnelEndpoint_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "s1_DL_GTPtunnelEndpoint_t";}
		using parent_t = GTPtunnelEndpoint;

	};
	s1_DL_GTPtunnelEndpoint_t& ref_s1_DL_GTPtunnelEndpoint() {return s1_DL_GTPtunnelEndpoint;}
	s1_DL_GTPtunnelEndpoint_t const& ref_s1_DL_GTPtunnelEndpoint() const {return s1_DL_GTPtunnelEndpoint;}
	struct dL_Forwarding_GTPtunnelEndpoint_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "dL_Forwarding_GTPtunnelEndpoint_t";}
		using parent_t = GTPtunnelEndpoint;
		static constexpr bool optional = true;

	};
	dL_Forwarding_GTPtunnelEndpoint_t& set_dL_Forwarding_GTPtunnelEndpoint() { dL_Forwarding_GTPtunnelEndpoint.setpresent(true); return dL_Forwarding_GTPtunnelEndpoint;}
	dL_Forwarding_GTPtunnelEndpoint_t const* get_dL_Forwarding_GTPtunnelEndpoint() const {return dL_Forwarding_GTPtunnelEndpoint.is_valid() ? &dL_Forwarding_GTPtunnelEndpoint : nullptr;}
	struct uL_Forwarding_GTPtunnelEndpoint_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "uL_Forwarding_GTPtunnelEndpoint_t";}
		using parent_t = GTPtunnelEndpoint;
		static constexpr bool optional = true;

	};
	uL_Forwarding_GTPtunnelEndpoint_t& set_uL_Forwarding_GTPtunnelEndpoint() { uL_Forwarding_GTPtunnelEndpoint.setpresent(true); return uL_Forwarding_GTPtunnelEndpoint;}
	uL_Forwarding_GTPtunnelEndpoint_t const* get_uL_Forwarding_GTPtunnelEndpoint() const {return uL_Forwarding_GTPtunnelEndpoint.is_valid() ? &uL_Forwarding_GTPtunnelEndpoint : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABs_Admitted_ToBeAdded_Item_SCG_BearerExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABs_Admitted_ToBeAdded_Item_SCG_BearerExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(e_RAB_ID);
		v(s1_DL_GTPtunnelEndpoint);
		v(dL_Forwarding_GTPtunnelEndpoint);
		v(uL_Forwarding_GTPtunnelEndpoint);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(e_RAB_ID);
		v(s1_DL_GTPtunnelEndpoint);
		v(dL_Forwarding_GTPtunnelEndpoint);
		v(uL_Forwarding_GTPtunnelEndpoint);
		v(iE_Extensions);

	};
	void clear()
	{
		e_RAB_ID.clear();
		s1_DL_GTPtunnelEndpoint.clear();
		dL_Forwarding_GTPtunnelEndpoint.clear();
		uL_Forwarding_GTPtunnelEndpoint.clear();
		iE_Extensions.clear();

	};
	private:
	e_RAB_ID_t	e_RAB_ID;
	s1_DL_GTPtunnelEndpoint_t	s1_DL_GTPtunnelEndpoint;
	dL_Forwarding_GTPtunnelEndpoint_t	dL_Forwarding_GTPtunnelEndpoint;
	uL_Forwarding_GTPtunnelEndpoint_t	uL_Forwarding_GTPtunnelEndpoint;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABs-Admitted-ToBeAdded-Item-Split-BearerExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct E_RABs_Admitted_ToBeAdded_Item_Split_BearerExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-Admitted-ToBeAdded-Item-Split-Bearer ::= SEQUENCE {
	e-RAB-ID						E-RAB-ID,
	seNB-GTPtunnelEndpoint			GTPtunnelEndpoint,
	iE-Extensions					ProtocolExtensionContainer { {E-RABs-Admitted-ToBeAdded-Item-Split-BearerExtIEs} } OPTIONAL,
	...
}
*/

struct E_RABs_Admitted_ToBeAdded_Item_Split_Bearer : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "E-RABs-Admitted-ToBeAdded-Item-Split-Bearer";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct e_RAB_ID_t : E_RAB_ID
	{
		static constexpr const char* name() {return "e_RAB_ID_t";}
		using parent_t = E_RAB_ID;

	};
	e_RAB_ID_t& ref_e_RAB_ID() {return e_RAB_ID;}
	e_RAB_ID_t const& ref_e_RAB_ID() const {return e_RAB_ID;}
	struct seNB_GTPtunnelEndpoint_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "seNB_GTPtunnelEndpoint_t";}
		using parent_t = GTPtunnelEndpoint;

	};
	seNB_GTPtunnelEndpoint_t& ref_seNB_GTPtunnelEndpoint() {return seNB_GTPtunnelEndpoint;}
	seNB_GTPtunnelEndpoint_t const& ref_seNB_GTPtunnelEndpoint() const {return seNB_GTPtunnelEndpoint;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABs_Admitted_ToBeAdded_Item_Split_BearerExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABs_Admitted_ToBeAdded_Item_Split_BearerExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(e_RAB_ID);
		v(seNB_GTPtunnelEndpoint);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(e_RAB_ID);
		v(seNB_GTPtunnelEndpoint);
		v(iE_Extensions);

	};
	void clear()
	{
		e_RAB_ID.clear();
		seNB_GTPtunnelEndpoint.clear();
		iE_Extensions.clear();

	};
	private:
	e_RAB_ID_t	e_RAB_ID;
	seNB_GTPtunnelEndpoint_t	seNB_GTPtunnelEndpoint;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABs-Admitted-ToBeAdded-Item ::= CHOICE {
	sCG-Bearer		E-RABs-Admitted-ToBeAdded-Item-SCG-Bearer,
	split-Bearer	E-RABs-Admitted-ToBeAdded-Item-Split-Bearer,
	...
}
*/

struct E_RABs_Admitted_ToBeAdded_Item : asn::choice<2, 0, true>
{
	static constexpr const char* name() {return "E-RABs-Admitted-ToBeAdded-Item";}
	using parent_t = asn::choice<2, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 3;}
	void set_unknown() { set_index(3);  }
	~E_RABs_Admitted_ToBeAdded_Item() {clear();}
	struct sCG_Bearer_t : E_RABs_Admitted_ToBeAdded_Item_SCG_Bearer
	{
		static constexpr const char* name() {return "sCG_Bearer_t";}
		using parent_t = E_RABs_Admitted_ToBeAdded_Item_SCG_Bearer;

	};
	struct split_Bearer_t : E_RABs_Admitted_ToBeAdded_Item_Split_Bearer
	{
		static constexpr const char* name() {return "split_Bearer_t";}
		using parent_t = E_RABs_Admitted_ToBeAdded_Item_Split_Bearer;

	};
	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<sCG_Bearer_t>(); break;
		case 2: var.destroy<split_Bearer_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<sCG_Bearer_t>());
		case 2: set_index(2); return v(var.build<split_Bearer_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<sCG_Bearer_t>());
		case 2: return v(var.as<split_Bearer_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<sCG_Bearer_t>(1);
		v.template operator()<split_Bearer_t>(2);

	}
	sCG_Bearer_t& select_sCG_Bearer() { if(get_index() != 1) { clear(); set_index(1); return var.build<sCG_Bearer_t>();} return var.as<sCG_Bearer_t>();}
	sCG_Bearer_t const* get_sCG_Bearer() const { if(get_index() == 1) { return &var.as<sCG_Bearer_t>();} return nullptr; }
	split_Bearer_t& select_split_Bearer() { if(get_index() != 2) { clear(); set_index(2); return var.build<split_Bearer_t>();} return var.as<split_Bearer_t>();}
	split_Bearer_t const* get_split_Bearer() const { if(get_index() == 2) { return &var.as<split_Bearer_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(sCG_Bearer_t)];
		char dummy2[sizeof(split_Bearer_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
E-RABs-Admitted-ToBeAdded-ItemIEs X2AP-PROTOCOL-IES ::= {
	{ ID id-E-RABs-Admitted-ToBeAdded-Item	CRITICALITY ignore	TYPE E-RABs-Admitted-ToBeAdded-Item 		PRESENCE mandatory}
}
*/

struct E_RABs_Admitted_ToBeAdded_ItemIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_E_RABs_Admitted_ToBeAdded_Item() { set(id_E_RABs_Admitted_ToBeAdded_Item); type=1;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_E_RABs_Admitted_ToBeAdded_Item)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_E_RABs_Admitted_ToBeAdded_Item);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_E_RABs_Admitted_ToBeAdded_Item() { set(ignore); type=1;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Value_t : asn::typefield<false>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		E_RABs_Admitted_ToBeAdded_Item& select_id_E_RABs_Admitted_ToBeAdded_Item() { return set<E_RABs_Admitted_ToBeAdded_Item>(1); }
		E_RABs_Admitted_ToBeAdded_Item const* get_id_E_RABs_Admitted_ToBeAdded_Item() const { return get<E_RABs_Admitted_ToBeAdded_Item>(1); }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<E_RABs_Admitted_ToBeAdded_Item>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<E_RABs_Admitted_ToBeAdded_Item>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_E_RABs_Admitted_ToBeAdded_Item()); return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<E_RABs_Admitted_ToBeAdded_Item>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(E_RABs_Admitted_ToBeAdded_Item)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_E_RABs_Admitted_ToBeAdded_Item() { set(mandatory); type=1;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-Admitted-ToBeAdded-List ::= SEQUENCE (SIZE (1..maxnoofBearers)) OF ProtocolIE-Single-Container { {E-RABs-Admitted-ToBeAdded-ItemIEs} }
*/

struct E_RABs_Admitted_ToBeAdded_List_elm : ProtocolIE_Single_Container<E_RABs_Admitted_ToBeAdded_ItemIEs>
{
	static constexpr const char* name() {return "E_RABs_Admitted_ToBeAdded_List_elm";}
	using parent_t = ProtocolIE_Single_Container<E_RABs_Admitted_ToBeAdded_ItemIEs>;

};
struct E_RABs_Admitted_ToBeAdded_List : asn::sequenceof<E_RABs_Admitted_ToBeAdded_List_elm>
{
	static constexpr const char* name() {return "E-RABs-Admitted-ToBeAdded-List";}
	using parent_t = asn::sequenceof<E_RABs_Admitted_ToBeAdded_List_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofBearers >>;

};
/*
E-RABs-Admitted-ToBeAdded-ModAckItem-SCG-BearerExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct E_RABs_Admitted_ToBeAdded_ModAckItem_SCG_BearerExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-Admitted-ToBeAdded-ModAckItem-SCG-Bearer ::= SEQUENCE {
	e-RAB-ID								E-RAB-ID,
	s1-DL-GTPtunnelEndpoint					GTPtunnelEndpoint,
	dL-Forwarding-GTPtunnelEndpoint			GTPtunnelEndpoint																	OPTIONAL,
	uL-Forwarding-GTPtunnelEndpoint			GTPtunnelEndpoint																	OPTIONAL,
	iE-Extensions					ProtocolExtensionContainer { {E-RABs-Admitted-ToBeAdded-ModAckItem-SCG-BearerExtIEs} }	OPTIONAL,
	...
}
*/

struct E_RABs_Admitted_ToBeAdded_ModAckItem_SCG_Bearer : asn::sequence<5, 0, true, 3>
{
	static constexpr const char* name() {return "E-RABs-Admitted-ToBeAdded-ModAckItem-SCG-Bearer";}
	using parent_t = asn::sequence<5, 0, true, 3>;
	struct e_RAB_ID_t : E_RAB_ID
	{
		static constexpr const char* name() {return "e_RAB_ID_t";}
		using parent_t = E_RAB_ID;

	};
	e_RAB_ID_t& ref_e_RAB_ID() {return e_RAB_ID;}
	e_RAB_ID_t const& ref_e_RAB_ID() const {return e_RAB_ID;}
	struct s1_DL_GTPtunnelEndpoint_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "s1_DL_GTPtunnelEndpoint_t";}
		using parent_t = GTPtunnelEndpoint;

	};
	s1_DL_GTPtunnelEndpoint_t& ref_s1_DL_GTPtunnelEndpoint() {return s1_DL_GTPtunnelEndpoint;}
	s1_DL_GTPtunnelEndpoint_t const& ref_s1_DL_GTPtunnelEndpoint() const {return s1_DL_GTPtunnelEndpoint;}
	struct dL_Forwarding_GTPtunnelEndpoint_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "dL_Forwarding_GTPtunnelEndpoint_t";}
		using parent_t = GTPtunnelEndpoint;
		static constexpr bool optional = true;

	};
	dL_Forwarding_GTPtunnelEndpoint_t& set_dL_Forwarding_GTPtunnelEndpoint() { dL_Forwarding_GTPtunnelEndpoint.setpresent(true); return dL_Forwarding_GTPtunnelEndpoint;}
	dL_Forwarding_GTPtunnelEndpoint_t const* get_dL_Forwarding_GTPtunnelEndpoint() const {return dL_Forwarding_GTPtunnelEndpoint.is_valid() ? &dL_Forwarding_GTPtunnelEndpoint : nullptr;}
	struct uL_Forwarding_GTPtunnelEndpoint_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "uL_Forwarding_GTPtunnelEndpoint_t";}
		using parent_t = GTPtunnelEndpoint;
		static constexpr bool optional = true;

	};
	uL_Forwarding_GTPtunnelEndpoint_t& set_uL_Forwarding_GTPtunnelEndpoint() { uL_Forwarding_GTPtunnelEndpoint.setpresent(true); return uL_Forwarding_GTPtunnelEndpoint;}
	uL_Forwarding_GTPtunnelEndpoint_t const* get_uL_Forwarding_GTPtunnelEndpoint() const {return uL_Forwarding_GTPtunnelEndpoint.is_valid() ? &uL_Forwarding_GTPtunnelEndpoint : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABs_Admitted_ToBeAdded_ModAckItem_SCG_BearerExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABs_Admitted_ToBeAdded_ModAckItem_SCG_BearerExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(e_RAB_ID);
		v(s1_DL_GTPtunnelEndpoint);
		v(dL_Forwarding_GTPtunnelEndpoint);
		v(uL_Forwarding_GTPtunnelEndpoint);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(e_RAB_ID);
		v(s1_DL_GTPtunnelEndpoint);
		v(dL_Forwarding_GTPtunnelEndpoint);
		v(uL_Forwarding_GTPtunnelEndpoint);
		v(iE_Extensions);

	};
	void clear()
	{
		e_RAB_ID.clear();
		s1_DL_GTPtunnelEndpoint.clear();
		dL_Forwarding_GTPtunnelEndpoint.clear();
		uL_Forwarding_GTPtunnelEndpoint.clear();
		iE_Extensions.clear();

	};
	private:
	e_RAB_ID_t	e_RAB_ID;
	s1_DL_GTPtunnelEndpoint_t	s1_DL_GTPtunnelEndpoint;
	dL_Forwarding_GTPtunnelEndpoint_t	dL_Forwarding_GTPtunnelEndpoint;
	uL_Forwarding_GTPtunnelEndpoint_t	uL_Forwarding_GTPtunnelEndpoint;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABs-Admitted-ToBeAdded-ModAckItem-Split-BearerExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct E_RABs_Admitted_ToBeAdded_ModAckItem_Split_BearerExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-Admitted-ToBeAdded-ModAckItem-Split-Bearer ::= SEQUENCE {
	e-RAB-ID						E-RAB-ID,
	seNB-GTPtunnelEndpoint			GTPtunnelEndpoint,
	iE-Extensions					ProtocolExtensionContainer { {E-RABs-Admitted-ToBeAdded-ModAckItem-Split-BearerExtIEs} } OPTIONAL,
	...
}
*/

struct E_RABs_Admitted_ToBeAdded_ModAckItem_Split_Bearer : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "E-RABs-Admitted-ToBeAdded-ModAckItem-Split-Bearer";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct e_RAB_ID_t : E_RAB_ID
	{
		static constexpr const char* name() {return "e_RAB_ID_t";}
		using parent_t = E_RAB_ID;

	};
	e_RAB_ID_t& ref_e_RAB_ID() {return e_RAB_ID;}
	e_RAB_ID_t const& ref_e_RAB_ID() const {return e_RAB_ID;}
	struct seNB_GTPtunnelEndpoint_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "seNB_GTPtunnelEndpoint_t";}
		using parent_t = GTPtunnelEndpoint;

	};
	seNB_GTPtunnelEndpoint_t& ref_seNB_GTPtunnelEndpoint() {return seNB_GTPtunnelEndpoint;}
	seNB_GTPtunnelEndpoint_t const& ref_seNB_GTPtunnelEndpoint() const {return seNB_GTPtunnelEndpoint;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABs_Admitted_ToBeAdded_ModAckItem_Split_BearerExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABs_Admitted_ToBeAdded_ModAckItem_Split_BearerExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(e_RAB_ID);
		v(seNB_GTPtunnelEndpoint);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(e_RAB_ID);
		v(seNB_GTPtunnelEndpoint);
		v(iE_Extensions);

	};
	void clear()
	{
		e_RAB_ID.clear();
		seNB_GTPtunnelEndpoint.clear();
		iE_Extensions.clear();

	};
	private:
	e_RAB_ID_t	e_RAB_ID;
	seNB_GTPtunnelEndpoint_t	seNB_GTPtunnelEndpoint;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABs-Admitted-ToBeAdded-ModAckItem ::= CHOICE {
	sCG-Bearer		E-RABs-Admitted-ToBeAdded-ModAckItem-SCG-Bearer,
	split-Bearer	E-RABs-Admitted-ToBeAdded-ModAckItem-Split-Bearer,
	...
}
*/

struct E_RABs_Admitted_ToBeAdded_ModAckItem : asn::choice<2, 0, true>
{
	static constexpr const char* name() {return "E-RABs-Admitted-ToBeAdded-ModAckItem";}
	using parent_t = asn::choice<2, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 3;}
	void set_unknown() { set_index(3);  }
	~E_RABs_Admitted_ToBeAdded_ModAckItem() {clear();}
	struct sCG_Bearer_t : E_RABs_Admitted_ToBeAdded_ModAckItem_SCG_Bearer
	{
		static constexpr const char* name() {return "sCG_Bearer_t";}
		using parent_t = E_RABs_Admitted_ToBeAdded_ModAckItem_SCG_Bearer;

	};
	struct split_Bearer_t : E_RABs_Admitted_ToBeAdded_ModAckItem_Split_Bearer
	{
		static constexpr const char* name() {return "split_Bearer_t";}
		using parent_t = E_RABs_Admitted_ToBeAdded_ModAckItem_Split_Bearer;

	};
	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<sCG_Bearer_t>(); break;
		case 2: var.destroy<split_Bearer_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<sCG_Bearer_t>());
		case 2: set_index(2); return v(var.build<split_Bearer_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<sCG_Bearer_t>());
		case 2: return v(var.as<split_Bearer_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<sCG_Bearer_t>(1);
		v.template operator()<split_Bearer_t>(2);

	}
	sCG_Bearer_t& select_sCG_Bearer() { if(get_index() != 1) { clear(); set_index(1); return var.build<sCG_Bearer_t>();} return var.as<sCG_Bearer_t>();}
	sCG_Bearer_t const* get_sCG_Bearer() const { if(get_index() == 1) { return &var.as<sCG_Bearer_t>();} return nullptr; }
	split_Bearer_t& select_split_Bearer() { if(get_index() != 2) { clear(); set_index(2); return var.build<split_Bearer_t>();} return var.as<split_Bearer_t>();}
	split_Bearer_t const* get_split_Bearer() const { if(get_index() == 2) { return &var.as<split_Bearer_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(sCG_Bearer_t)];
		char dummy2[sizeof(split_Bearer_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
E-RABs-Admitted-ToBeAdded-ModAckItemIEs X2AP-PROTOCOL-IES ::= {
	{ ID id-E-RABs-Admitted-ToBeAdded-ModAckItem	CRITICALITY ignore	TYPE E-RABs-Admitted-ToBeAdded-ModAckItem		PRESENCE mandatory}
}
*/

struct E_RABs_Admitted_ToBeAdded_ModAckItemIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_E_RABs_Admitted_ToBeAdded_ModAckItem() { set(id_E_RABs_Admitted_ToBeAdded_ModAckItem); type=1;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_E_RABs_Admitted_ToBeAdded_ModAckItem)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_E_RABs_Admitted_ToBeAdded_ModAckItem);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_E_RABs_Admitted_ToBeAdded_ModAckItem() { set(ignore); type=1;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Value_t : asn::typefield<false>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		E_RABs_Admitted_ToBeAdded_ModAckItem& select_id_E_RABs_Admitted_ToBeAdded_ModAckItem() { return set<E_RABs_Admitted_ToBeAdded_ModAckItem>(1); }
		E_RABs_Admitted_ToBeAdded_ModAckItem const* get_id_E_RABs_Admitted_ToBeAdded_ModAckItem() const { return get<E_RABs_Admitted_ToBeAdded_ModAckItem>(1); }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<E_RABs_Admitted_ToBeAdded_ModAckItem>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<E_RABs_Admitted_ToBeAdded_ModAckItem>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_E_RABs_Admitted_ToBeAdded_ModAckItem()); return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<E_RABs_Admitted_ToBeAdded_ModAckItem>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(E_RABs_Admitted_ToBeAdded_ModAckItem)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_E_RABs_Admitted_ToBeAdded_ModAckItem() { set(mandatory); type=1;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-Admitted-ToBeAdded-ModAckList ::= SEQUENCE (SIZE (1..maxnoofBearers)) OF ProtocolIE-Single-Container { {E-RABs-Admitted-ToBeAdded-ModAckItemIEs} }
*/

struct E_RABs_Admitted_ToBeAdded_ModAckList_elm : ProtocolIE_Single_Container<E_RABs_Admitted_ToBeAdded_ModAckItemIEs>
{
	static constexpr const char* name() {return "E_RABs_Admitted_ToBeAdded_ModAckList_elm";}
	using parent_t = ProtocolIE_Single_Container<E_RABs_Admitted_ToBeAdded_ModAckItemIEs>;

};
struct E_RABs_Admitted_ToBeAdded_ModAckList : asn::sequenceof<E_RABs_Admitted_ToBeAdded_ModAckList_elm>
{
	static constexpr const char* name() {return "E-RABs-Admitted-ToBeAdded-ModAckList";}
	using parent_t = asn::sequenceof<E_RABs_Admitted_ToBeAdded_ModAckList_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofBearers >>;

};
/*
E-RABs-Admitted-ToBeAdded-SgNBAddReqAck-Item-SgNBPDCPpresentExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	{ ID id-uLpDCPSnLength							CRITICALITY ignore	EXTENSION PDCPSnLength					PRESENCE optional}|
	{ ID id-dLPDCPSnLength							CRITICALITY ignore	EXTENSION PDCPSnLength					PRESENCE optional},
	...
}
*/

struct E_RABs_Admitted_ToBeAdded_SgNBAddReqAck_Item_SgNBPDCPpresentExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_uLpDCPSnLength() { set(id_uLpDCPSnLength); type=1;}
		void select_id_dLPDCPSnLength() { set(id_dLPDCPSnLength); type=2;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_uLpDCPSnLength)) { type = 1; return true; }
			else if(equal(id_dLPDCPSnLength)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_uLpDCPSnLength);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_dLPDCPSnLength);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_uLpDCPSnLength() { set(ignore); type=1;}
		void select_id_dLPDCPSnLength() { set(ignore); type=2;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else if(equal(ignore)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(ignore);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		PDCPSnLength& select_id_uLpDCPSnLength() { return set<PDCPSnLength>(1); }
		PDCPSnLength const* get_id_uLpDCPSnLength() const { return get<PDCPSnLength>(1); }
		PDCPSnLength& select_id_dLPDCPSnLength() { return set<PDCPSnLength>(2); }
		PDCPSnLength const* get_id_dLPDCPSnLength() const { return get<PDCPSnLength>(2); }
		bool is_unknown() const { return type == 3; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<PDCPSnLength>(); break;
			case 2: var.destroy<PDCPSnLength>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<PDCPSnLength>(1);
			v.template operator()<PDCPSnLength>(2);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_uLpDCPSnLength()); return true;
			case 2: v(select_id_dLPDCPSnLength()); return true;
			case 3: if(type != 3) {clear(); asn::base::set();} type = 3; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<PDCPSnLength>()); return true;
			case 2: v(var.as<PDCPSnLength>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(PDCPSnLength)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_uLpDCPSnLength() { set(optional); type=1;}
		void select_id_dLPDCPSnLength() { set(optional); type=2;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(optional)) { type = 1; return true; }
			else if(equal(optional)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(optional);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(optional);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-Admitted-ToBeAdded-SgNBAddReqAck-Item-SgNBPDCPpresent ::= SEQUENCE {
	s1-DL-GTPtunnelEndpoint					GTPtunnelEndpoint,
	sgNB-UL-GTP-TEIDatPDCP					GTPtunnelEndpoint																						OPTIONAL,
-- This IE shall be present if MCG resource IE in the the EN-DC Resource Configuration IE is set to “present” --
	rlc-Mode								RLCMode																									OPTIONAL,
-- This IE shall be present if MCG resource IE in the the EN-DC Resource Configuration IE is set to “present” --
	dL-Forwarding-GTPtunnelEndpoint			GTPtunnelEndpoint																						OPTIONAL,
	uL-Forwarding-GTPtunnelEndpoint			GTPtunnelEndpoint																						OPTIONAL,
	mCG-E-RAB-Level-QoS-Parameters			E-RAB-Level-QoS-Parameters																				OPTIONAL,
-- This IE shall be present if MCG resource and SCG resource IEs in the the EN-DC Resource Configuration IE are set to “present” and the GBR QoS Information IE is present in the Requested MCG E-RAB Level QoS Parameters IE --
	uL-Configuration							ULConfiguration																							OPTIONAL,
-- This IE shall be present if MCG resource and SCG resources IEs in the the EN-DC Resource Configuration IE are set to “present” --
	iE-Extensions							ProtocolExtensionContainer { {E-RABs-Admitted-ToBeAdded-SgNBAddReqAck-Item-SgNBPDCPpresentExtIEs} }			OPTIONAL,
	...
}
*/

struct E_RABs_Admitted_ToBeAdded_SgNBAddReqAck_Item_SgNBPDCPpresent : asn::sequence<8, 0, true, 7>
{
	static constexpr const char* name() {return "E-RABs-Admitted-ToBeAdded-SgNBAddReqAck-Item-SgNBPDCPpresent";}
	using parent_t = asn::sequence<8, 0, true, 7>;
	struct s1_DL_GTPtunnelEndpoint_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "s1_DL_GTPtunnelEndpoint_t";}
		using parent_t = GTPtunnelEndpoint;

	};
	s1_DL_GTPtunnelEndpoint_t& ref_s1_DL_GTPtunnelEndpoint() {return s1_DL_GTPtunnelEndpoint;}
	s1_DL_GTPtunnelEndpoint_t const& ref_s1_DL_GTPtunnelEndpoint() const {return s1_DL_GTPtunnelEndpoint;}
	struct sgNB_UL_GTP_TEIDatPDCP_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "sgNB_UL_GTP_TEIDatPDCP_t";}
		using parent_t = GTPtunnelEndpoint;
		static constexpr bool optional = true;

	};
	sgNB_UL_GTP_TEIDatPDCP_t& set_sgNB_UL_GTP_TEIDatPDCP() { sgNB_UL_GTP_TEIDatPDCP.setpresent(true); return sgNB_UL_GTP_TEIDatPDCP;}
	sgNB_UL_GTP_TEIDatPDCP_t const* get_sgNB_UL_GTP_TEIDatPDCP() const {return sgNB_UL_GTP_TEIDatPDCP.is_valid() ? &sgNB_UL_GTP_TEIDatPDCP : nullptr;}
	struct rlc_Mode_t : RLCMode
	{
		static constexpr const char* name() {return "rlc_Mode_t";}
		using parent_t = RLCMode;
		static constexpr bool optional = true;

	};
	rlc_Mode_t& set_rlc_Mode() { rlc_Mode.setpresent(true); return rlc_Mode;}
	rlc_Mode_t const* get_rlc_Mode() const {return rlc_Mode.is_valid() ? &rlc_Mode : nullptr;}
	struct dL_Forwarding_GTPtunnelEndpoint_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "dL_Forwarding_GTPtunnelEndpoint_t";}
		using parent_t = GTPtunnelEndpoint;
		static constexpr bool optional = true;

	};
	dL_Forwarding_GTPtunnelEndpoint_t& set_dL_Forwarding_GTPtunnelEndpoint() { dL_Forwarding_GTPtunnelEndpoint.setpresent(true); return dL_Forwarding_GTPtunnelEndpoint;}
	dL_Forwarding_GTPtunnelEndpoint_t const* get_dL_Forwarding_GTPtunnelEndpoint() const {return dL_Forwarding_GTPtunnelEndpoint.is_valid() ? &dL_Forwarding_GTPtunnelEndpoint : nullptr;}
	struct uL_Forwarding_GTPtunnelEndpoint_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "uL_Forwarding_GTPtunnelEndpoint_t";}
		using parent_t = GTPtunnelEndpoint;
		static constexpr bool optional = true;

	};
	uL_Forwarding_GTPtunnelEndpoint_t& set_uL_Forwarding_GTPtunnelEndpoint() { uL_Forwarding_GTPtunnelEndpoint.setpresent(true); return uL_Forwarding_GTPtunnelEndpoint;}
	uL_Forwarding_GTPtunnelEndpoint_t const* get_uL_Forwarding_GTPtunnelEndpoint() const {return uL_Forwarding_GTPtunnelEndpoint.is_valid() ? &uL_Forwarding_GTPtunnelEndpoint : nullptr;}
	struct mCG_E_RAB_Level_QoS_Parameters_t : E_RAB_Level_QoS_Parameters
	{
		static constexpr const char* name() {return "mCG_E_RAB_Level_QoS_Parameters_t";}
		using parent_t = E_RAB_Level_QoS_Parameters;
		static constexpr bool optional = true;

	};
	mCG_E_RAB_Level_QoS_Parameters_t& set_mCG_E_RAB_Level_QoS_Parameters() { mCG_E_RAB_Level_QoS_Parameters.setpresent(true); return mCG_E_RAB_Level_QoS_Parameters;}
	mCG_E_RAB_Level_QoS_Parameters_t const* get_mCG_E_RAB_Level_QoS_Parameters() const {return mCG_E_RAB_Level_QoS_Parameters.is_valid() ? &mCG_E_RAB_Level_QoS_Parameters : nullptr;}
	struct uL_Configuration_t : ULConfiguration
	{
		static constexpr const char* name() {return "uL_Configuration_t";}
		using parent_t = ULConfiguration;
		static constexpr bool optional = true;

	};
	uL_Configuration_t& set_uL_Configuration() { uL_Configuration.setpresent(true); return uL_Configuration;}
	uL_Configuration_t const* get_uL_Configuration() const {return uL_Configuration.is_valid() ? &uL_Configuration : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABs_Admitted_ToBeAdded_SgNBAddReqAck_Item_SgNBPDCPpresentExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABs_Admitted_ToBeAdded_SgNBAddReqAck_Item_SgNBPDCPpresentExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(s1_DL_GTPtunnelEndpoint);
		v(sgNB_UL_GTP_TEIDatPDCP);
		v(rlc_Mode);
		v(dL_Forwarding_GTPtunnelEndpoint);
		v(uL_Forwarding_GTPtunnelEndpoint);
		v(mCG_E_RAB_Level_QoS_Parameters);
		v(uL_Configuration);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(s1_DL_GTPtunnelEndpoint);
		v(sgNB_UL_GTP_TEIDatPDCP);
		v(rlc_Mode);
		v(dL_Forwarding_GTPtunnelEndpoint);
		v(uL_Forwarding_GTPtunnelEndpoint);
		v(mCG_E_RAB_Level_QoS_Parameters);
		v(uL_Configuration);
		v(iE_Extensions);

	};
	void clear()
	{
		s1_DL_GTPtunnelEndpoint.clear();
		sgNB_UL_GTP_TEIDatPDCP.clear();
		rlc_Mode.clear();
		dL_Forwarding_GTPtunnelEndpoint.clear();
		uL_Forwarding_GTPtunnelEndpoint.clear();
		mCG_E_RAB_Level_QoS_Parameters.clear();
		uL_Configuration.clear();
		iE_Extensions.clear();

	};
	private:
	s1_DL_GTPtunnelEndpoint_t	s1_DL_GTPtunnelEndpoint;
	sgNB_UL_GTP_TEIDatPDCP_t	sgNB_UL_GTP_TEIDatPDCP;
	rlc_Mode_t	rlc_Mode;
	dL_Forwarding_GTPtunnelEndpoint_t	dL_Forwarding_GTPtunnelEndpoint;
	uL_Forwarding_GTPtunnelEndpoint_t	uL_Forwarding_GTPtunnelEndpoint;
	mCG_E_RAB_Level_QoS_Parameters_t	mCG_E_RAB_Level_QoS_Parameters;
	uL_Configuration_t	uL_Configuration;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABs-Admitted-ToBeAdded-SgNBAddReqAck-Item-SgNBPDCPnotpresentExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	{ ID id-lCID				CRITICALITY ignore	EXTENSION LCID			PRESENCE optional},
	...
}
*/

struct E_RABs_Admitted_ToBeAdded_SgNBAddReqAck_Item_SgNBPDCPnotpresentExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_lCID() { set(id_lCID); type=1;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_lCID)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_lCID);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_lCID() { set(ignore); type=1;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		LCID& select_id_lCID() { return set<LCID>(1); }
		LCID const* get_id_lCID() const { return get<LCID>(1); }
		bool is_unknown() const { return type == 2; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<LCID>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<LCID>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_lCID()); return true;
			case 2: if(type != 2) {clear(); asn::base::set();} type = 2; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<LCID>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(LCID)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_lCID() { set(optional); type=1;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(optional)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(optional);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-Admitted-ToBeAdded-SgNBAddReqAck-Item-SgNBPDCPnotpresent ::= SEQUENCE {
	sgNB-DL-GTP-TEIDatSCG				GTPtunnelEndpoint,
	secondary-sgNB-DL-GTP-TEIDatSCG		GTPtunnelEndpoint		OPTIONAL,
	iE-Extensions						ProtocolExtensionContainer { {E-RABs-Admitted-ToBeAdded-SgNBAddReqAck-Item-SgNBPDCPnotpresentExtIEs} } 		OPTIONAL,
	...
}
*/

struct E_RABs_Admitted_ToBeAdded_SgNBAddReqAck_Item_SgNBPDCPnotpresent : asn::sequence<3, 0, true, 2>
{
	static constexpr const char* name() {return "E-RABs-Admitted-ToBeAdded-SgNBAddReqAck-Item-SgNBPDCPnotpresent";}
	using parent_t = asn::sequence<3, 0, true, 2>;
	struct sgNB_DL_GTP_TEIDatSCG_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "sgNB_DL_GTP_TEIDatSCG_t";}
		using parent_t = GTPtunnelEndpoint;

	};
	sgNB_DL_GTP_TEIDatSCG_t& ref_sgNB_DL_GTP_TEIDatSCG() {return sgNB_DL_GTP_TEIDatSCG;}
	sgNB_DL_GTP_TEIDatSCG_t const& ref_sgNB_DL_GTP_TEIDatSCG() const {return sgNB_DL_GTP_TEIDatSCG;}
	struct secondary_sgNB_DL_GTP_TEIDatSCG_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "secondary_sgNB_DL_GTP_TEIDatSCG_t";}
		using parent_t = GTPtunnelEndpoint;
		static constexpr bool optional = true;

	};
	secondary_sgNB_DL_GTP_TEIDatSCG_t& set_secondary_sgNB_DL_GTP_TEIDatSCG() { secondary_sgNB_DL_GTP_TEIDatSCG.setpresent(true); return secondary_sgNB_DL_GTP_TEIDatSCG;}
	secondary_sgNB_DL_GTP_TEIDatSCG_t const* get_secondary_sgNB_DL_GTP_TEIDatSCG() const {return secondary_sgNB_DL_GTP_TEIDatSCG.is_valid() ? &secondary_sgNB_DL_GTP_TEIDatSCG : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABs_Admitted_ToBeAdded_SgNBAddReqAck_Item_SgNBPDCPnotpresentExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABs_Admitted_ToBeAdded_SgNBAddReqAck_Item_SgNBPDCPnotpresentExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(sgNB_DL_GTP_TEIDatSCG);
		v(secondary_sgNB_DL_GTP_TEIDatSCG);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(sgNB_DL_GTP_TEIDatSCG);
		v(secondary_sgNB_DL_GTP_TEIDatSCG);
		v(iE_Extensions);

	};
	void clear()
	{
		sgNB_DL_GTP_TEIDatSCG.clear();
		secondary_sgNB_DL_GTP_TEIDatSCG.clear();
		iE_Extensions.clear();

	};
	private:
	sgNB_DL_GTP_TEIDatSCG_t	sgNB_DL_GTP_TEIDatSCG;
	secondary_sgNB_DL_GTP_TEIDatSCG_t	secondary_sgNB_DL_GTP_TEIDatSCG;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABs-ToBeAdded-SgNBAddReqAck-ItemExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct E_RABs_ToBeAdded_SgNBAddReqAck_ItemExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-Admitted-ToBeAdded-SgNBAddReqAck-Item ::= SEQUENCE {
	e-RAB-ID								E-RAB-ID,
	en-DC-ResourceConfiguration			EN-DC-ResourceConfiguration,
	resource-configuration				CHOICE {
		sgNBPDCPpresent						E-RABs-Admitted-ToBeAdded-SgNBAddReqAck-Item-SgNBPDCPpresent,
		sgNBPDCPnotpresent					E-RABs-Admitted-ToBeAdded-SgNBAddReqAck-Item-SgNBPDCPnotpresent,
		...
	},
	iE-Extensions					ProtocolExtensionContainer { {E-RABs-ToBeAdded-SgNBAddReqAck-ItemExtIEs} }	OPTIONAL,
	...
}
*/

struct E_RABs_Admitted_ToBeAdded_SgNBAddReqAck_Item : asn::sequence<4, 0, true, 1>
{
	static constexpr const char* name() {return "E-RABs-Admitted-ToBeAdded-SgNBAddReqAck-Item";}
	using parent_t = asn::sequence<4, 0, true, 1>;
	struct e_RAB_ID_t : E_RAB_ID
	{
		static constexpr const char* name() {return "e_RAB_ID_t";}
		using parent_t = E_RAB_ID;

	};
	e_RAB_ID_t& ref_e_RAB_ID() {return e_RAB_ID;}
	e_RAB_ID_t const& ref_e_RAB_ID() const {return e_RAB_ID;}
	struct en_DC_ResourceConfiguration_t : EN_DC_ResourceConfiguration
	{
		static constexpr const char* name() {return "en_DC_ResourceConfiguration_t";}
		using parent_t = EN_DC_ResourceConfiguration;

	};
	en_DC_ResourceConfiguration_t& ref_en_DC_ResourceConfiguration() {return en_DC_ResourceConfiguration;}
	en_DC_ResourceConfiguration_t const& ref_en_DC_ResourceConfiguration() const {return en_DC_ResourceConfiguration;}
	struct resource_configuration_t : asn::choice<2, 0, true>
	{
		static constexpr const char* name() {return "resource_configuration_t";}
		using parent_t = asn::choice<2, 0, true>;
		index_type get_index() const {return index;}
		bool is_unknown() const {return index == 3;}
		void set_unknown() { set_index(3);  }
		~resource_configuration_t() {clear();}
		struct sgNBPDCPpresent_t : E_RABs_Admitted_ToBeAdded_SgNBAddReqAck_Item_SgNBPDCPpresent
		{
			static constexpr const char* name() {return "sgNBPDCPpresent_t";}
			using parent_t = E_RABs_Admitted_ToBeAdded_SgNBAddReqAck_Item_SgNBPDCPpresent;

		};
		struct sgNBPDCPnotpresent_t : E_RABs_Admitted_ToBeAdded_SgNBAddReqAck_Item_SgNBPDCPnotpresent
		{
			static constexpr const char* name() {return "sgNBPDCPnotpresent_t";}
			using parent_t = E_RABs_Admitted_ToBeAdded_SgNBAddReqAck_Item_SgNBPDCPnotpresent;

		};
		void clear()
		{
			switch(get_index())
			{
			case 1: var.destroy<sgNBPDCPpresent_t>(); break;
			case 2: var.destroy<sgNBPDCPnotpresent_t>(); break;
			}
			index = 0;
			base::clear();
		}
		template<typename V> bool decode(size_t idx, V& v)
		{
			clear();
			switch(idx)
			{
			case 1: set_index(1); return v(var.build<sgNBPDCPpresent_t>());
			case 2: set_index(2); return v(var.build<sgNBPDCPnotpresent_t>());
			}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			switch(get_index())
			{
			case 1: return v(var.as<sgNBPDCPpresent_t>());
			case 2: return v(var.as<sgNBPDCPnotpresent_t>());
			}
			return false;
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<sgNBPDCPpresent_t>(1);
			v.template operator()<sgNBPDCPnotpresent_t>(2);

		}
		sgNBPDCPpresent_t& select_sgNBPDCPpresent() { if(get_index() != 1) { clear(); set_index(1); return var.build<sgNBPDCPpresent_t>();} return var.as<sgNBPDCPpresent_t>();}
		sgNBPDCPpresent_t const* get_sgNBPDCPpresent() const { if(get_index() == 1) { return &var.as<sgNBPDCPpresent_t>();} return nullptr; }
		sgNBPDCPnotpresent_t& select_sgNBPDCPnotpresent() { if(get_index() != 2) { clear(); set_index(2); return var.build<sgNBPDCPnotpresent_t>();} return var.as<sgNBPDCPnotpresent_t>();}
		sgNBPDCPnotpresent_t const* get_sgNBPDCPnotpresent() const { if(get_index() == 2) { return &var.as<sgNBPDCPnotpresent_t>();} return nullptr; }
		private:
		void set_index(index_type i) {index = i; base::set();}
		union union_type
		{
			char dummy1[sizeof(sgNBPDCPpresent_t)];
			char dummy2[sizeof(sgNBPDCPnotpresent_t)];

		};
		asn::variant<sizeof(union_type)>	var;
		index_type	index {0};
	};
	resource_configuration_t& ref_resource_configuration() {return resource_configuration;}
	resource_configuration_t const& ref_resource_configuration() const {return resource_configuration;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABs_ToBeAdded_SgNBAddReqAck_ItemExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABs_ToBeAdded_SgNBAddReqAck_ItemExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(e_RAB_ID);
		v(en_DC_ResourceConfiguration);
		v(resource_configuration);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(e_RAB_ID);
		v(en_DC_ResourceConfiguration);
		v(resource_configuration);
		v(iE_Extensions);

	};
	void clear()
	{
		e_RAB_ID.clear();
		en_DC_ResourceConfiguration.clear();
		resource_configuration.clear();
		iE_Extensions.clear();

	};
	private:
	e_RAB_ID_t	e_RAB_ID;
	en_DC_ResourceConfiguration_t	en_DC_ResourceConfiguration;
	resource_configuration_t	resource_configuration;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABs-Admitted-ToBeAdded-SgNBAddReqAck-ItemIEs X2AP-PROTOCOL-IES ::= {
	{ ID id-E-RABs-Admitted-ToBeAdded-SgNBAddReqAck-Item	CRITICALITY ignore	TYPE E-RABs-Admitted-ToBeAdded-SgNBAddReqAck-Item 		PRESENCE mandatory}
}
*/

struct E_RABs_Admitted_ToBeAdded_SgNBAddReqAck_ItemIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_E_RABs_Admitted_ToBeAdded_SgNBAddReqAck_Item() { set(id_E_RABs_Admitted_ToBeAdded_SgNBAddReqAck_Item); type=1;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_E_RABs_Admitted_ToBeAdded_SgNBAddReqAck_Item)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_E_RABs_Admitted_ToBeAdded_SgNBAddReqAck_Item);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_E_RABs_Admitted_ToBeAdded_SgNBAddReqAck_Item() { set(ignore); type=1;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Value_t : asn::typefield<false>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		E_RABs_Admitted_ToBeAdded_SgNBAddReqAck_Item& select_id_E_RABs_Admitted_ToBeAdded_SgNBAddReqAck_Item() { return set<E_RABs_Admitted_ToBeAdded_SgNBAddReqAck_Item>(1); }
		E_RABs_Admitted_ToBeAdded_SgNBAddReqAck_Item const* get_id_E_RABs_Admitted_ToBeAdded_SgNBAddReqAck_Item() const { return get<E_RABs_Admitted_ToBeAdded_SgNBAddReqAck_Item>(1); }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<E_RABs_Admitted_ToBeAdded_SgNBAddReqAck_Item>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<E_RABs_Admitted_ToBeAdded_SgNBAddReqAck_Item>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_E_RABs_Admitted_ToBeAdded_SgNBAddReqAck_Item()); return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<E_RABs_Admitted_ToBeAdded_SgNBAddReqAck_Item>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(E_RABs_Admitted_ToBeAdded_SgNBAddReqAck_Item)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_E_RABs_Admitted_ToBeAdded_SgNBAddReqAck_Item() { set(mandatory); type=1;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-Admitted-ToBeAdded-SgNBAddReqAckList ::= SEQUENCE (SIZE (1..maxnoofBearers)) OF ProtocolIE-Single-Container { {E-RABs-Admitted-ToBeAdded-SgNBAddReqAck-ItemIEs} }
*/

struct E_RABs_Admitted_ToBeAdded_SgNBAddReqAckList_elm : ProtocolIE_Single_Container<E_RABs_Admitted_ToBeAdded_SgNBAddReqAck_ItemIEs>
{
	static constexpr const char* name() {return "E_RABs_Admitted_ToBeAdded_SgNBAddReqAckList_elm";}
	using parent_t = ProtocolIE_Single_Container<E_RABs_Admitted_ToBeAdded_SgNBAddReqAck_ItemIEs>;

};
struct E_RABs_Admitted_ToBeAdded_SgNBAddReqAckList : asn::sequenceof<E_RABs_Admitted_ToBeAdded_SgNBAddReqAckList_elm>
{
	static constexpr const char* name() {return "E-RABs-Admitted-ToBeAdded-SgNBAddReqAckList";}
	using parent_t = asn::sequenceof<E_RABs_Admitted_ToBeAdded_SgNBAddReqAckList_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofBearers >>;

};
/*
E-RABs-Admitted-ToBeAdded-SgNBModAck-Item-SgNBPDCPpresentExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	{ ID id-uLpDCPSnLength							CRITICALITY ignore	EXTENSION PDCPSnLength					PRESENCE optional}|
	{ ID id-dLPDCPSnLength							CRITICALITY ignore	EXTENSION PDCPSnLength					PRESENCE optional},
	...
}
*/

struct E_RABs_Admitted_ToBeAdded_SgNBModAck_Item_SgNBPDCPpresentExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_uLpDCPSnLength() { set(id_uLpDCPSnLength); type=1;}
		void select_id_dLPDCPSnLength() { set(id_dLPDCPSnLength); type=2;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_uLpDCPSnLength)) { type = 1; return true; }
			else if(equal(id_dLPDCPSnLength)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_uLpDCPSnLength);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_dLPDCPSnLength);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_uLpDCPSnLength() { set(ignore); type=1;}
		void select_id_dLPDCPSnLength() { set(ignore); type=2;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else if(equal(ignore)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(ignore);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		PDCPSnLength& select_id_uLpDCPSnLength() { return set<PDCPSnLength>(1); }
		PDCPSnLength const* get_id_uLpDCPSnLength() const { return get<PDCPSnLength>(1); }
		PDCPSnLength& select_id_dLPDCPSnLength() { return set<PDCPSnLength>(2); }
		PDCPSnLength const* get_id_dLPDCPSnLength() const { return get<PDCPSnLength>(2); }
		bool is_unknown() const { return type == 3; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<PDCPSnLength>(); break;
			case 2: var.destroy<PDCPSnLength>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<PDCPSnLength>(1);
			v.template operator()<PDCPSnLength>(2);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_uLpDCPSnLength()); return true;
			case 2: v(select_id_dLPDCPSnLength()); return true;
			case 3: if(type != 3) {clear(); asn::base::set();} type = 3; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<PDCPSnLength>()); return true;
			case 2: v(var.as<PDCPSnLength>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(PDCPSnLength)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_uLpDCPSnLength() { set(optional); type=1;}
		void select_id_dLPDCPSnLength() { set(optional); type=2;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(optional)) { type = 1; return true; }
			else if(equal(optional)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(optional);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(optional);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-Admitted-ToBeAdded-SgNBModAck-Item-SgNBPDCPpresent ::= SEQUENCE {
	s1-DL-GTPtunnelEndpoint					GTPtunnelEndpoint,
	sgNB-UL-GTP-TEIDatPDCP					GTPtunnelEndpoint																					OPTIONAL,
-- This IE shall be present if MCG resource IE in the the EN-DC Resource Configuration IE are set to “present” --
	rlc-Mode									RLCMode																								OPTIONAL,
-- This IE shall be present if MCG resource IE in the the EN-DC Resource Configuration IE are set to “present” --
	dL-Forwarding-GTPtunnelEndpoint			GTPtunnelEndpoint																					OPTIONAL,
	uL-Forwarding-GTPtunnelEndpoint			GTPtunnelEndpoint																					OPTIONAL,
	mCG-E-RAB-Level-QoS-Parameters			E-RAB-Level-QoS-Parameters																			OPTIONAL,
-- This IE shall be present if MCG resource and SCG resource IEs in the the EN-DC Resource Configuration IE are set to “present” and the GBR QoS Information IE is present in the Requested MCG E-RAB Level QoS Parameters IE --
	uL-Configuration						ULConfiguration																							OPTIONAL,
-- This IE shall be present if MCG resource and SCG resources IEs in the the EN-DC Resource Configuration IE are set to “present” --
	iE-Extensions					ProtocolExtensionContainer { {E-RABs-Admitted-ToBeAdded-SgNBModAck-Item-SgNBPDCPpresentExtIEs} }		OPTIONAL,
	...
}
*/

struct E_RABs_Admitted_ToBeAdded_SgNBModAck_Item_SgNBPDCPpresent : asn::sequence<8, 0, true, 7>
{
	static constexpr const char* name() {return "E-RABs-Admitted-ToBeAdded-SgNBModAck-Item-SgNBPDCPpresent";}
	using parent_t = asn::sequence<8, 0, true, 7>;
	struct s1_DL_GTPtunnelEndpoint_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "s1_DL_GTPtunnelEndpoint_t";}
		using parent_t = GTPtunnelEndpoint;

	};
	s1_DL_GTPtunnelEndpoint_t& ref_s1_DL_GTPtunnelEndpoint() {return s1_DL_GTPtunnelEndpoint;}
	s1_DL_GTPtunnelEndpoint_t const& ref_s1_DL_GTPtunnelEndpoint() const {return s1_DL_GTPtunnelEndpoint;}
	struct sgNB_UL_GTP_TEIDatPDCP_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "sgNB_UL_GTP_TEIDatPDCP_t";}
		using parent_t = GTPtunnelEndpoint;
		static constexpr bool optional = true;

	};
	sgNB_UL_GTP_TEIDatPDCP_t& set_sgNB_UL_GTP_TEIDatPDCP() { sgNB_UL_GTP_TEIDatPDCP.setpresent(true); return sgNB_UL_GTP_TEIDatPDCP;}
	sgNB_UL_GTP_TEIDatPDCP_t const* get_sgNB_UL_GTP_TEIDatPDCP() const {return sgNB_UL_GTP_TEIDatPDCP.is_valid() ? &sgNB_UL_GTP_TEIDatPDCP : nullptr;}
	struct rlc_Mode_t : RLCMode
	{
		static constexpr const char* name() {return "rlc_Mode_t";}
		using parent_t = RLCMode;
		static constexpr bool optional = true;

	};
	rlc_Mode_t& set_rlc_Mode() { rlc_Mode.setpresent(true); return rlc_Mode;}
	rlc_Mode_t const* get_rlc_Mode() const {return rlc_Mode.is_valid() ? &rlc_Mode : nullptr;}
	struct dL_Forwarding_GTPtunnelEndpoint_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "dL_Forwarding_GTPtunnelEndpoint_t";}
		using parent_t = GTPtunnelEndpoint;
		static constexpr bool optional = true;

	};
	dL_Forwarding_GTPtunnelEndpoint_t& set_dL_Forwarding_GTPtunnelEndpoint() { dL_Forwarding_GTPtunnelEndpoint.setpresent(true); return dL_Forwarding_GTPtunnelEndpoint;}
	dL_Forwarding_GTPtunnelEndpoint_t const* get_dL_Forwarding_GTPtunnelEndpoint() const {return dL_Forwarding_GTPtunnelEndpoint.is_valid() ? &dL_Forwarding_GTPtunnelEndpoint : nullptr;}
	struct uL_Forwarding_GTPtunnelEndpoint_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "uL_Forwarding_GTPtunnelEndpoint_t";}
		using parent_t = GTPtunnelEndpoint;
		static constexpr bool optional = true;

	};
	uL_Forwarding_GTPtunnelEndpoint_t& set_uL_Forwarding_GTPtunnelEndpoint() { uL_Forwarding_GTPtunnelEndpoint.setpresent(true); return uL_Forwarding_GTPtunnelEndpoint;}
	uL_Forwarding_GTPtunnelEndpoint_t const* get_uL_Forwarding_GTPtunnelEndpoint() const {return uL_Forwarding_GTPtunnelEndpoint.is_valid() ? &uL_Forwarding_GTPtunnelEndpoint : nullptr;}
	struct mCG_E_RAB_Level_QoS_Parameters_t : E_RAB_Level_QoS_Parameters
	{
		static constexpr const char* name() {return "mCG_E_RAB_Level_QoS_Parameters_t";}
		using parent_t = E_RAB_Level_QoS_Parameters;
		static constexpr bool optional = true;

	};
	mCG_E_RAB_Level_QoS_Parameters_t& set_mCG_E_RAB_Level_QoS_Parameters() { mCG_E_RAB_Level_QoS_Parameters.setpresent(true); return mCG_E_RAB_Level_QoS_Parameters;}
	mCG_E_RAB_Level_QoS_Parameters_t const* get_mCG_E_RAB_Level_QoS_Parameters() const {return mCG_E_RAB_Level_QoS_Parameters.is_valid() ? &mCG_E_RAB_Level_QoS_Parameters : nullptr;}
	struct uL_Configuration_t : ULConfiguration
	{
		static constexpr const char* name() {return "uL_Configuration_t";}
		using parent_t = ULConfiguration;
		static constexpr bool optional = true;

	};
	uL_Configuration_t& set_uL_Configuration() { uL_Configuration.setpresent(true); return uL_Configuration;}
	uL_Configuration_t const* get_uL_Configuration() const {return uL_Configuration.is_valid() ? &uL_Configuration : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABs_Admitted_ToBeAdded_SgNBModAck_Item_SgNBPDCPpresentExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABs_Admitted_ToBeAdded_SgNBModAck_Item_SgNBPDCPpresentExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(s1_DL_GTPtunnelEndpoint);
		v(sgNB_UL_GTP_TEIDatPDCP);
		v(rlc_Mode);
		v(dL_Forwarding_GTPtunnelEndpoint);
		v(uL_Forwarding_GTPtunnelEndpoint);
		v(mCG_E_RAB_Level_QoS_Parameters);
		v(uL_Configuration);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(s1_DL_GTPtunnelEndpoint);
		v(sgNB_UL_GTP_TEIDatPDCP);
		v(rlc_Mode);
		v(dL_Forwarding_GTPtunnelEndpoint);
		v(uL_Forwarding_GTPtunnelEndpoint);
		v(mCG_E_RAB_Level_QoS_Parameters);
		v(uL_Configuration);
		v(iE_Extensions);

	};
	void clear()
	{
		s1_DL_GTPtunnelEndpoint.clear();
		sgNB_UL_GTP_TEIDatPDCP.clear();
		rlc_Mode.clear();
		dL_Forwarding_GTPtunnelEndpoint.clear();
		uL_Forwarding_GTPtunnelEndpoint.clear();
		mCG_E_RAB_Level_QoS_Parameters.clear();
		uL_Configuration.clear();
		iE_Extensions.clear();

	};
	private:
	s1_DL_GTPtunnelEndpoint_t	s1_DL_GTPtunnelEndpoint;
	sgNB_UL_GTP_TEIDatPDCP_t	sgNB_UL_GTP_TEIDatPDCP;
	rlc_Mode_t	rlc_Mode;
	dL_Forwarding_GTPtunnelEndpoint_t	dL_Forwarding_GTPtunnelEndpoint;
	uL_Forwarding_GTPtunnelEndpoint_t	uL_Forwarding_GTPtunnelEndpoint;
	mCG_E_RAB_Level_QoS_Parameters_t	mCG_E_RAB_Level_QoS_Parameters;
	uL_Configuration_t	uL_Configuration;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABs-Admitted-ToBeAdded-SgNBModAck-Item-SgNBPDCPnotpresentExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	{ID id-lCID				CRITICALITY ignore	EXTENSION LCID		PRESENCE optional},
	...
}
*/

struct E_RABs_Admitted_ToBeAdded_SgNBModAck_Item_SgNBPDCPnotpresentExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_lCID() { set(id_lCID); type=1;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_lCID)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_lCID);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_lCID() { set(ignore); type=1;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		LCID& select_id_lCID() { return set<LCID>(1); }
		LCID const* get_id_lCID() const { return get<LCID>(1); }
		bool is_unknown() const { return type == 2; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<LCID>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<LCID>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_lCID()); return true;
			case 2: if(type != 2) {clear(); asn::base::set();} type = 2; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<LCID>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(LCID)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_lCID() { set(optional); type=1;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(optional)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(optional);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-Admitted-ToBeAdded-SgNBModAck-Item-SgNBPDCPnotpresent ::= SEQUENCE {
	sgNB-DL-GTP-TEIDatSCG					GTPtunnelEndpoint,
	secondary-sgNB-DL-GTP-TEIDatSCG			GTPtunnelEndpoint			OPTIONAL,
	iE-Extensions					ProtocolExtensionContainer { {E-RABs-Admitted-ToBeAdded-SgNBModAck-Item-SgNBPDCPnotpresentExtIEs} } OPTIONAL,
	...
}
*/

struct E_RABs_Admitted_ToBeAdded_SgNBModAck_Item_SgNBPDCPnotpresent : asn::sequence<3, 0, true, 2>
{
	static constexpr const char* name() {return "E-RABs-Admitted-ToBeAdded-SgNBModAck-Item-SgNBPDCPnotpresent";}
	using parent_t = asn::sequence<3, 0, true, 2>;
	struct sgNB_DL_GTP_TEIDatSCG_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "sgNB_DL_GTP_TEIDatSCG_t";}
		using parent_t = GTPtunnelEndpoint;

	};
	sgNB_DL_GTP_TEIDatSCG_t& ref_sgNB_DL_GTP_TEIDatSCG() {return sgNB_DL_GTP_TEIDatSCG;}
	sgNB_DL_GTP_TEIDatSCG_t const& ref_sgNB_DL_GTP_TEIDatSCG() const {return sgNB_DL_GTP_TEIDatSCG;}
	struct secondary_sgNB_DL_GTP_TEIDatSCG_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "secondary_sgNB_DL_GTP_TEIDatSCG_t";}
		using parent_t = GTPtunnelEndpoint;
		static constexpr bool optional = true;

	};
	secondary_sgNB_DL_GTP_TEIDatSCG_t& set_secondary_sgNB_DL_GTP_TEIDatSCG() { secondary_sgNB_DL_GTP_TEIDatSCG.setpresent(true); return secondary_sgNB_DL_GTP_TEIDatSCG;}
	secondary_sgNB_DL_GTP_TEIDatSCG_t const* get_secondary_sgNB_DL_GTP_TEIDatSCG() const {return secondary_sgNB_DL_GTP_TEIDatSCG.is_valid() ? &secondary_sgNB_DL_GTP_TEIDatSCG : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABs_Admitted_ToBeAdded_SgNBModAck_Item_SgNBPDCPnotpresentExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABs_Admitted_ToBeAdded_SgNBModAck_Item_SgNBPDCPnotpresentExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(sgNB_DL_GTP_TEIDatSCG);
		v(secondary_sgNB_DL_GTP_TEIDatSCG);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(sgNB_DL_GTP_TEIDatSCG);
		v(secondary_sgNB_DL_GTP_TEIDatSCG);
		v(iE_Extensions);

	};
	void clear()
	{
		sgNB_DL_GTP_TEIDatSCG.clear();
		secondary_sgNB_DL_GTP_TEIDatSCG.clear();
		iE_Extensions.clear();

	};
	private:
	sgNB_DL_GTP_TEIDatSCG_t	sgNB_DL_GTP_TEIDatSCG;
	secondary_sgNB_DL_GTP_TEIDatSCG_t	secondary_sgNB_DL_GTP_TEIDatSCG;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABs-Admitted-ToBeAdded-SgNBModAck-ItemExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct E_RABs_Admitted_ToBeAdded_SgNBModAck_ItemExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-Admitted-ToBeAdded-SgNBModAck-Item ::= SEQUENCE {
	e-RAB-ID								E-RAB-ID,
	en-DC-ResourceConfiguration			EN-DC-ResourceConfiguration,
	resource-configuration				CHOICE {
		sgNBPDCPpresent						E-RABs-Admitted-ToBeAdded-SgNBModAck-Item-SgNBPDCPpresent,
		sgNBPDCPnotpresent					E-RABs-Admitted-ToBeAdded-SgNBModAck-Item-SgNBPDCPnotpresent,
		...
	},
	iE-Extensions					ProtocolExtensionContainer { {E-RABs-Admitted-ToBeAdded-SgNBModAck-ItemExtIEs} }	OPTIONAL,
	...
}
*/

struct E_RABs_Admitted_ToBeAdded_SgNBModAck_Item : asn::sequence<4, 0, true, 1>
{
	static constexpr const char* name() {return "E-RABs-Admitted-ToBeAdded-SgNBModAck-Item";}
	using parent_t = asn::sequence<4, 0, true, 1>;
	struct e_RAB_ID_t : E_RAB_ID
	{
		static constexpr const char* name() {return "e_RAB_ID_t";}
		using parent_t = E_RAB_ID;

	};
	e_RAB_ID_t& ref_e_RAB_ID() {return e_RAB_ID;}
	e_RAB_ID_t const& ref_e_RAB_ID() const {return e_RAB_ID;}
	struct en_DC_ResourceConfiguration_t : EN_DC_ResourceConfiguration
	{
		static constexpr const char* name() {return "en_DC_ResourceConfiguration_t";}
		using parent_t = EN_DC_ResourceConfiguration;

	};
	en_DC_ResourceConfiguration_t& ref_en_DC_ResourceConfiguration() {return en_DC_ResourceConfiguration;}
	en_DC_ResourceConfiguration_t const& ref_en_DC_ResourceConfiguration() const {return en_DC_ResourceConfiguration;}
	struct resource_configuration_t : asn::choice<2, 0, true>
	{
		static constexpr const char* name() {return "resource_configuration_t";}
		using parent_t = asn::choice<2, 0, true>;
		index_type get_index() const {return index;}
		bool is_unknown() const {return index == 3;}
		void set_unknown() { set_index(3);  }
		~resource_configuration_t() {clear();}
		struct sgNBPDCPpresent_t : E_RABs_Admitted_ToBeAdded_SgNBModAck_Item_SgNBPDCPpresent
		{
			static constexpr const char* name() {return "sgNBPDCPpresent_t";}
			using parent_t = E_RABs_Admitted_ToBeAdded_SgNBModAck_Item_SgNBPDCPpresent;

		};
		struct sgNBPDCPnotpresent_t : E_RABs_Admitted_ToBeAdded_SgNBModAck_Item_SgNBPDCPnotpresent
		{
			static constexpr const char* name() {return "sgNBPDCPnotpresent_t";}
			using parent_t = E_RABs_Admitted_ToBeAdded_SgNBModAck_Item_SgNBPDCPnotpresent;

		};
		void clear()
		{
			switch(get_index())
			{
			case 1: var.destroy<sgNBPDCPpresent_t>(); break;
			case 2: var.destroy<sgNBPDCPnotpresent_t>(); break;
			}
			index = 0;
			base::clear();
		}
		template<typename V> bool decode(size_t idx, V& v)
		{
			clear();
			switch(idx)
			{
			case 1: set_index(1); return v(var.build<sgNBPDCPpresent_t>());
			case 2: set_index(2); return v(var.build<sgNBPDCPnotpresent_t>());
			}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			switch(get_index())
			{
			case 1: return v(var.as<sgNBPDCPpresent_t>());
			case 2: return v(var.as<sgNBPDCPnotpresent_t>());
			}
			return false;
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<sgNBPDCPpresent_t>(1);
			v.template operator()<sgNBPDCPnotpresent_t>(2);

		}
		sgNBPDCPpresent_t& select_sgNBPDCPpresent() { if(get_index() != 1) { clear(); set_index(1); return var.build<sgNBPDCPpresent_t>();} return var.as<sgNBPDCPpresent_t>();}
		sgNBPDCPpresent_t const* get_sgNBPDCPpresent() const { if(get_index() == 1) { return &var.as<sgNBPDCPpresent_t>();} return nullptr; }
		sgNBPDCPnotpresent_t& select_sgNBPDCPnotpresent() { if(get_index() != 2) { clear(); set_index(2); return var.build<sgNBPDCPnotpresent_t>();} return var.as<sgNBPDCPnotpresent_t>();}
		sgNBPDCPnotpresent_t const* get_sgNBPDCPnotpresent() const { if(get_index() == 2) { return &var.as<sgNBPDCPnotpresent_t>();} return nullptr; }
		private:
		void set_index(index_type i) {index = i; base::set();}
		union union_type
		{
			char dummy1[sizeof(sgNBPDCPpresent_t)];
			char dummy2[sizeof(sgNBPDCPnotpresent_t)];

		};
		asn::variant<sizeof(union_type)>	var;
		index_type	index {0};
	};
	resource_configuration_t& ref_resource_configuration() {return resource_configuration;}
	resource_configuration_t const& ref_resource_configuration() const {return resource_configuration;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABs_Admitted_ToBeAdded_SgNBModAck_ItemExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABs_Admitted_ToBeAdded_SgNBModAck_ItemExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(e_RAB_ID);
		v(en_DC_ResourceConfiguration);
		v(resource_configuration);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(e_RAB_ID);
		v(en_DC_ResourceConfiguration);
		v(resource_configuration);
		v(iE_Extensions);

	};
	void clear()
	{
		e_RAB_ID.clear();
		en_DC_ResourceConfiguration.clear();
		resource_configuration.clear();
		iE_Extensions.clear();

	};
	private:
	e_RAB_ID_t	e_RAB_ID;
	en_DC_ResourceConfiguration_t	en_DC_ResourceConfiguration;
	resource_configuration_t	resource_configuration;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABs-Admitted-ToBeAdded-SgNBModAck-ItemIEs X2AP-PROTOCOL-IES ::= {
	{ ID id-E-RABs-Admitted-ToBeAdded-SgNBModAck-Item 	CRITICALITY ignore	TYPE E-RABs-Admitted-ToBeAdded-SgNBModAck-Item		PRESENCE mandatory}
}
*/

struct E_RABs_Admitted_ToBeAdded_SgNBModAck_ItemIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_E_RABs_Admitted_ToBeAdded_SgNBModAck_Item() { set(id_E_RABs_Admitted_ToBeAdded_SgNBModAck_Item); type=1;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_E_RABs_Admitted_ToBeAdded_SgNBModAck_Item)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_E_RABs_Admitted_ToBeAdded_SgNBModAck_Item);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_E_RABs_Admitted_ToBeAdded_SgNBModAck_Item() { set(ignore); type=1;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Value_t : asn::typefield<false>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		E_RABs_Admitted_ToBeAdded_SgNBModAck_Item& select_id_E_RABs_Admitted_ToBeAdded_SgNBModAck_Item() { return set<E_RABs_Admitted_ToBeAdded_SgNBModAck_Item>(1); }
		E_RABs_Admitted_ToBeAdded_SgNBModAck_Item const* get_id_E_RABs_Admitted_ToBeAdded_SgNBModAck_Item() const { return get<E_RABs_Admitted_ToBeAdded_SgNBModAck_Item>(1); }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<E_RABs_Admitted_ToBeAdded_SgNBModAck_Item>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<E_RABs_Admitted_ToBeAdded_SgNBModAck_Item>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_E_RABs_Admitted_ToBeAdded_SgNBModAck_Item()); return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<E_RABs_Admitted_ToBeAdded_SgNBModAck_Item>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(E_RABs_Admitted_ToBeAdded_SgNBModAck_Item)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_E_RABs_Admitted_ToBeAdded_SgNBModAck_Item() { set(mandatory); type=1;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-Admitted-ToBeAdded-SgNBModAckList ::= SEQUENCE (SIZE (1..maxnoofBearers)) OF ProtocolIE-Single-Container { {E-RABs-Admitted-ToBeAdded-SgNBModAck-ItemIEs} }
*/

struct E_RABs_Admitted_ToBeAdded_SgNBModAckList_elm : ProtocolIE_Single_Container<E_RABs_Admitted_ToBeAdded_SgNBModAck_ItemIEs>
{
	static constexpr const char* name() {return "E_RABs_Admitted_ToBeAdded_SgNBModAckList_elm";}
	using parent_t = ProtocolIE_Single_Container<E_RABs_Admitted_ToBeAdded_SgNBModAck_ItemIEs>;

};
struct E_RABs_Admitted_ToBeAdded_SgNBModAckList : asn::sequenceof<E_RABs_Admitted_ToBeAdded_SgNBModAckList_elm>
{
	static constexpr const char* name() {return "E-RABs-Admitted-ToBeAdded-SgNBModAckList";}
	using parent_t = asn::sequenceof<E_RABs_Admitted_ToBeAdded_SgNBModAckList_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofBearers >>;

};
/*
E-RABs-Admitted-ToBeModified-ModAckItem-SCG-BearerExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct E_RABs_Admitted_ToBeModified_ModAckItem_SCG_BearerExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-Admitted-ToBeModified-ModAckItem-SCG-Bearer ::= SEQUENCE {
	e-RAB-ID						E-RAB-ID,
	s1-DL-GTPtunnelEndpoint			GTPtunnelEndpoint																	OPTIONAL,
	iE-Extensions					ProtocolExtensionContainer { {E-RABs-Admitted-ToBeModified-ModAckItem-SCG-BearerExtIEs} } OPTIONAL,
	...
}
*/

struct E_RABs_Admitted_ToBeModified_ModAckItem_SCG_Bearer : asn::sequence<3, 0, true, 2>
{
	static constexpr const char* name() {return "E-RABs-Admitted-ToBeModified-ModAckItem-SCG-Bearer";}
	using parent_t = asn::sequence<3, 0, true, 2>;
	struct e_RAB_ID_t : E_RAB_ID
	{
		static constexpr const char* name() {return "e_RAB_ID_t";}
		using parent_t = E_RAB_ID;

	};
	e_RAB_ID_t& ref_e_RAB_ID() {return e_RAB_ID;}
	e_RAB_ID_t const& ref_e_RAB_ID() const {return e_RAB_ID;}
	struct s1_DL_GTPtunnelEndpoint_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "s1_DL_GTPtunnelEndpoint_t";}
		using parent_t = GTPtunnelEndpoint;
		static constexpr bool optional = true;

	};
	s1_DL_GTPtunnelEndpoint_t& set_s1_DL_GTPtunnelEndpoint() { s1_DL_GTPtunnelEndpoint.setpresent(true); return s1_DL_GTPtunnelEndpoint;}
	s1_DL_GTPtunnelEndpoint_t const* get_s1_DL_GTPtunnelEndpoint() const {return s1_DL_GTPtunnelEndpoint.is_valid() ? &s1_DL_GTPtunnelEndpoint : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABs_Admitted_ToBeModified_ModAckItem_SCG_BearerExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABs_Admitted_ToBeModified_ModAckItem_SCG_BearerExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(e_RAB_ID);
		v(s1_DL_GTPtunnelEndpoint);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(e_RAB_ID);
		v(s1_DL_GTPtunnelEndpoint);
		v(iE_Extensions);

	};
	void clear()
	{
		e_RAB_ID.clear();
		s1_DL_GTPtunnelEndpoint.clear();
		iE_Extensions.clear();

	};
	private:
	e_RAB_ID_t	e_RAB_ID;
	s1_DL_GTPtunnelEndpoint_t	s1_DL_GTPtunnelEndpoint;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABs-Admitted-ToBeModified-ModAckItem-Split-BearerExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct E_RABs_Admitted_ToBeModified_ModAckItem_Split_BearerExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-Admitted-ToBeModified-ModAckItem-Split-Bearer ::= SEQUENCE {
	e-RAB-ID						E-RAB-ID,
	seNB-GTPtunnelEndpoint			GTPtunnelEndpoint																			OPTIONAL,
	iE-Extensions					ProtocolExtensionContainer { {E-RABs-Admitted-ToBeModified-ModAckItem-Split-BearerExtIEs} } OPTIONAL,
	...
}
*/

struct E_RABs_Admitted_ToBeModified_ModAckItem_Split_Bearer : asn::sequence<3, 0, true, 2>
{
	static constexpr const char* name() {return "E-RABs-Admitted-ToBeModified-ModAckItem-Split-Bearer";}
	using parent_t = asn::sequence<3, 0, true, 2>;
	struct e_RAB_ID_t : E_RAB_ID
	{
		static constexpr const char* name() {return "e_RAB_ID_t";}
		using parent_t = E_RAB_ID;

	};
	e_RAB_ID_t& ref_e_RAB_ID() {return e_RAB_ID;}
	e_RAB_ID_t const& ref_e_RAB_ID() const {return e_RAB_ID;}
	struct seNB_GTPtunnelEndpoint_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "seNB_GTPtunnelEndpoint_t";}
		using parent_t = GTPtunnelEndpoint;
		static constexpr bool optional = true;

	};
	seNB_GTPtunnelEndpoint_t& set_seNB_GTPtunnelEndpoint() { seNB_GTPtunnelEndpoint.setpresent(true); return seNB_GTPtunnelEndpoint;}
	seNB_GTPtunnelEndpoint_t const* get_seNB_GTPtunnelEndpoint() const {return seNB_GTPtunnelEndpoint.is_valid() ? &seNB_GTPtunnelEndpoint : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABs_Admitted_ToBeModified_ModAckItem_Split_BearerExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABs_Admitted_ToBeModified_ModAckItem_Split_BearerExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(e_RAB_ID);
		v(seNB_GTPtunnelEndpoint);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(e_RAB_ID);
		v(seNB_GTPtunnelEndpoint);
		v(iE_Extensions);

	};
	void clear()
	{
		e_RAB_ID.clear();
		seNB_GTPtunnelEndpoint.clear();
		iE_Extensions.clear();

	};
	private:
	e_RAB_ID_t	e_RAB_ID;
	seNB_GTPtunnelEndpoint_t	seNB_GTPtunnelEndpoint;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABs-Admitted-ToBeModified-ModAckItem ::= CHOICE {
	sCG-Bearer		E-RABs-Admitted-ToBeModified-ModAckItem-SCG-Bearer,
	split-Bearer	E-RABs-Admitted-ToBeModified-ModAckItem-Split-Bearer,
	...
}
*/

struct E_RABs_Admitted_ToBeModified_ModAckItem : asn::choice<2, 0, true>
{
	static constexpr const char* name() {return "E-RABs-Admitted-ToBeModified-ModAckItem";}
	using parent_t = asn::choice<2, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 3;}
	void set_unknown() { set_index(3);  }
	~E_RABs_Admitted_ToBeModified_ModAckItem() {clear();}
	struct sCG_Bearer_t : E_RABs_Admitted_ToBeModified_ModAckItem_SCG_Bearer
	{
		static constexpr const char* name() {return "sCG_Bearer_t";}
		using parent_t = E_RABs_Admitted_ToBeModified_ModAckItem_SCG_Bearer;

	};
	struct split_Bearer_t : E_RABs_Admitted_ToBeModified_ModAckItem_Split_Bearer
	{
		static constexpr const char* name() {return "split_Bearer_t";}
		using parent_t = E_RABs_Admitted_ToBeModified_ModAckItem_Split_Bearer;

	};
	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<sCG_Bearer_t>(); break;
		case 2: var.destroy<split_Bearer_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<sCG_Bearer_t>());
		case 2: set_index(2); return v(var.build<split_Bearer_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<sCG_Bearer_t>());
		case 2: return v(var.as<split_Bearer_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<sCG_Bearer_t>(1);
		v.template operator()<split_Bearer_t>(2);

	}
	sCG_Bearer_t& select_sCG_Bearer() { if(get_index() != 1) { clear(); set_index(1); return var.build<sCG_Bearer_t>();} return var.as<sCG_Bearer_t>();}
	sCG_Bearer_t const* get_sCG_Bearer() const { if(get_index() == 1) { return &var.as<sCG_Bearer_t>();} return nullptr; }
	split_Bearer_t& select_split_Bearer() { if(get_index() != 2) { clear(); set_index(2); return var.build<split_Bearer_t>();} return var.as<split_Bearer_t>();}
	split_Bearer_t const* get_split_Bearer() const { if(get_index() == 2) { return &var.as<split_Bearer_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(sCG_Bearer_t)];
		char dummy2[sizeof(split_Bearer_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
E-RABs-Admitted-ToBeModified-ModAckItemIEs X2AP-PROTOCOL-IES ::= {
	{ ID id-E-RABs-Admitted-ToBeModified-ModAckItem		CRITICALITY ignore	TYPE E-RABs-Admitted-ToBeModified-ModAckItem	PRESENCE mandatory}
}
*/

struct E_RABs_Admitted_ToBeModified_ModAckItemIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_E_RABs_Admitted_ToBeModified_ModAckItem() { set(id_E_RABs_Admitted_ToBeModified_ModAckItem); type=1;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_E_RABs_Admitted_ToBeModified_ModAckItem)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_E_RABs_Admitted_ToBeModified_ModAckItem);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_E_RABs_Admitted_ToBeModified_ModAckItem() { set(ignore); type=1;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Value_t : asn::typefield<false>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		E_RABs_Admitted_ToBeModified_ModAckItem& select_id_E_RABs_Admitted_ToBeModified_ModAckItem() { return set<E_RABs_Admitted_ToBeModified_ModAckItem>(1); }
		E_RABs_Admitted_ToBeModified_ModAckItem const* get_id_E_RABs_Admitted_ToBeModified_ModAckItem() const { return get<E_RABs_Admitted_ToBeModified_ModAckItem>(1); }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<E_RABs_Admitted_ToBeModified_ModAckItem>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<E_RABs_Admitted_ToBeModified_ModAckItem>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_E_RABs_Admitted_ToBeModified_ModAckItem()); return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<E_RABs_Admitted_ToBeModified_ModAckItem>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(E_RABs_Admitted_ToBeModified_ModAckItem)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_E_RABs_Admitted_ToBeModified_ModAckItem() { set(mandatory); type=1;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-Admitted-ToBeModified-ModAckList ::= SEQUENCE (SIZE (1..maxnoofBearers)) OF ProtocolIE-Single-Container { {E-RABs-Admitted-ToBeModified-ModAckItemIEs} }
*/

struct E_RABs_Admitted_ToBeModified_ModAckList_elm : ProtocolIE_Single_Container<E_RABs_Admitted_ToBeModified_ModAckItemIEs>
{
	static constexpr const char* name() {return "E_RABs_Admitted_ToBeModified_ModAckList_elm";}
	using parent_t = ProtocolIE_Single_Container<E_RABs_Admitted_ToBeModified_ModAckItemIEs>;

};
struct E_RABs_Admitted_ToBeModified_ModAckList : asn::sequenceof<E_RABs_Admitted_ToBeModified_ModAckList_elm>
{
	static constexpr const char* name() {return "E-RABs-Admitted-ToBeModified-ModAckList";}
	using parent_t = asn::sequenceof<E_RABs_Admitted_ToBeModified_ModAckList_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofBearers >>;

};
/*
E-RABs-Admitted-ToBeModified-SgNBModAck-Item-SgNBPDCPpresentExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	{ ID id-uLpDCPSnLength							CRITICALITY ignore	EXTENSION PDCPSnLength					PRESENCE optional}|
	{ ID id-dLPDCPSnLength							CRITICALITY ignore	EXTENSION PDCPSnLength					PRESENCE optional},
	...
}
*/

struct E_RABs_Admitted_ToBeModified_SgNBModAck_Item_SgNBPDCPpresentExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_uLpDCPSnLength() { set(id_uLpDCPSnLength); type=1;}
		void select_id_dLPDCPSnLength() { set(id_dLPDCPSnLength); type=2;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_uLpDCPSnLength)) { type = 1; return true; }
			else if(equal(id_dLPDCPSnLength)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_uLpDCPSnLength);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_dLPDCPSnLength);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_uLpDCPSnLength() { set(ignore); type=1;}
		void select_id_dLPDCPSnLength() { set(ignore); type=2;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else if(equal(ignore)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(ignore);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		PDCPSnLength& select_id_uLpDCPSnLength() { return set<PDCPSnLength>(1); }
		PDCPSnLength const* get_id_uLpDCPSnLength() const { return get<PDCPSnLength>(1); }
		PDCPSnLength& select_id_dLPDCPSnLength() { return set<PDCPSnLength>(2); }
		PDCPSnLength const* get_id_dLPDCPSnLength() const { return get<PDCPSnLength>(2); }
		bool is_unknown() const { return type == 3; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<PDCPSnLength>(); break;
			case 2: var.destroy<PDCPSnLength>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<PDCPSnLength>(1);
			v.template operator()<PDCPSnLength>(2);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_uLpDCPSnLength()); return true;
			case 2: v(select_id_dLPDCPSnLength()); return true;
			case 3: if(type != 3) {clear(); asn::base::set();} type = 3; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<PDCPSnLength>()); return true;
			case 2: v(var.as<PDCPSnLength>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(PDCPSnLength)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_uLpDCPSnLength() { set(optional); type=1;}
		void select_id_dLPDCPSnLength() { set(optional); type=2;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(optional)) { type = 1; return true; }
			else if(equal(optional)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(optional);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(optional);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-Admitted-ToBeModified-SgNBModAck-Item-SgNBPDCPpresent ::= SEQUENCE {
	s1-DL-GTPtunnelEndpoint					GTPtunnelEndpoint																						OPTIONAL,
	sgNB-UL-GTP-TEIDatPDCP					GTPtunnelEndpoint																						OPTIONAL,
	mCG-E-RAB-Level-QoS-Parameters			E-RAB-Level-QoS-Parameters																				OPTIONAL,
	uL-Configuration							ULConfiguration																							OPTIONAL,
	iE-Extensions					ProtocolExtensionContainer { {E-RABs-Admitted-ToBeModified-SgNBModAck-Item-SgNBPDCPpresentExtIEs} } 	OPTIONAL,
	...
}
*/

struct E_RABs_Admitted_ToBeModified_SgNBModAck_Item_SgNBPDCPpresent : asn::sequence<5, 0, true, 5>
{
	static constexpr const char* name() {return "E-RABs-Admitted-ToBeModified-SgNBModAck-Item-SgNBPDCPpresent";}
	using parent_t = asn::sequence<5, 0, true, 5>;
	struct s1_DL_GTPtunnelEndpoint_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "s1_DL_GTPtunnelEndpoint_t";}
		using parent_t = GTPtunnelEndpoint;
		static constexpr bool optional = true;

	};
	s1_DL_GTPtunnelEndpoint_t& set_s1_DL_GTPtunnelEndpoint() { s1_DL_GTPtunnelEndpoint.setpresent(true); return s1_DL_GTPtunnelEndpoint;}
	s1_DL_GTPtunnelEndpoint_t const* get_s1_DL_GTPtunnelEndpoint() const {return s1_DL_GTPtunnelEndpoint.is_valid() ? &s1_DL_GTPtunnelEndpoint : nullptr;}
	struct sgNB_UL_GTP_TEIDatPDCP_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "sgNB_UL_GTP_TEIDatPDCP_t";}
		using parent_t = GTPtunnelEndpoint;
		static constexpr bool optional = true;

	};
	sgNB_UL_GTP_TEIDatPDCP_t& set_sgNB_UL_GTP_TEIDatPDCP() { sgNB_UL_GTP_TEIDatPDCP.setpresent(true); return sgNB_UL_GTP_TEIDatPDCP;}
	sgNB_UL_GTP_TEIDatPDCP_t const* get_sgNB_UL_GTP_TEIDatPDCP() const {return sgNB_UL_GTP_TEIDatPDCP.is_valid() ? &sgNB_UL_GTP_TEIDatPDCP : nullptr;}
	struct mCG_E_RAB_Level_QoS_Parameters_t : E_RAB_Level_QoS_Parameters
	{
		static constexpr const char* name() {return "mCG_E_RAB_Level_QoS_Parameters_t";}
		using parent_t = E_RAB_Level_QoS_Parameters;
		static constexpr bool optional = true;

	};
	mCG_E_RAB_Level_QoS_Parameters_t& set_mCG_E_RAB_Level_QoS_Parameters() { mCG_E_RAB_Level_QoS_Parameters.setpresent(true); return mCG_E_RAB_Level_QoS_Parameters;}
	mCG_E_RAB_Level_QoS_Parameters_t const* get_mCG_E_RAB_Level_QoS_Parameters() const {return mCG_E_RAB_Level_QoS_Parameters.is_valid() ? &mCG_E_RAB_Level_QoS_Parameters : nullptr;}
	struct uL_Configuration_t : ULConfiguration
	{
		static constexpr const char* name() {return "uL_Configuration_t";}
		using parent_t = ULConfiguration;
		static constexpr bool optional = true;

	};
	uL_Configuration_t& set_uL_Configuration() { uL_Configuration.setpresent(true); return uL_Configuration;}
	uL_Configuration_t const* get_uL_Configuration() const {return uL_Configuration.is_valid() ? &uL_Configuration : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABs_Admitted_ToBeModified_SgNBModAck_Item_SgNBPDCPpresentExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABs_Admitted_ToBeModified_SgNBModAck_Item_SgNBPDCPpresentExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(s1_DL_GTPtunnelEndpoint);
		v(sgNB_UL_GTP_TEIDatPDCP);
		v(mCG_E_RAB_Level_QoS_Parameters);
		v(uL_Configuration);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(s1_DL_GTPtunnelEndpoint);
		v(sgNB_UL_GTP_TEIDatPDCP);
		v(mCG_E_RAB_Level_QoS_Parameters);
		v(uL_Configuration);
		v(iE_Extensions);

	};
	void clear()
	{
		s1_DL_GTPtunnelEndpoint.clear();
		sgNB_UL_GTP_TEIDatPDCP.clear();
		mCG_E_RAB_Level_QoS_Parameters.clear();
		uL_Configuration.clear();
		iE_Extensions.clear();

	};
	private:
	s1_DL_GTPtunnelEndpoint_t	s1_DL_GTPtunnelEndpoint;
	sgNB_UL_GTP_TEIDatPDCP_t	sgNB_UL_GTP_TEIDatPDCP;
	mCG_E_RAB_Level_QoS_Parameters_t	mCG_E_RAB_Level_QoS_Parameters;
	uL_Configuration_t	uL_Configuration;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABs-Admitted-ToBeModified-SgNBModAck-Item-SgNBPDCPnotpresentExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	{ ID id-secondarysgNBDLGTPTEIDatPDCP			CRITICALITY ignore	EXTENSION GTPtunnelEndpoint				PRESENCE optional}|
	{ ID id-RLC-Status								CRITICALITY ignore			EXTENSION RLC-Status				PRESENCE optional },
	...
}
*/

struct E_RABs_Admitted_ToBeModified_SgNBModAck_Item_SgNBPDCPnotpresentExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_secondarysgNBDLGTPTEIDatPDCP() { set(id_secondarysgNBDLGTPTEIDatPDCP); type=1;}
		void select_id_RLC_Status() { set(id_RLC_Status); type=2;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_secondarysgNBDLGTPTEIDatPDCP)) { type = 1; return true; }
			else if(equal(id_RLC_Status)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_secondarysgNBDLGTPTEIDatPDCP);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_RLC_Status);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_secondarysgNBDLGTPTEIDatPDCP() { set(ignore); type=1;}
		void select_id_RLC_Status() { set(ignore); type=2;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else if(equal(ignore)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(ignore);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		GTPtunnelEndpoint& select_id_secondarysgNBDLGTPTEIDatPDCP() { return set<GTPtunnelEndpoint>(1); }
		GTPtunnelEndpoint const* get_id_secondarysgNBDLGTPTEIDatPDCP() const { return get<GTPtunnelEndpoint>(1); }
		RLC_Status& select_id_RLC_Status() { return set<RLC_Status>(2); }
		RLC_Status const* get_id_RLC_Status() const { return get<RLC_Status>(2); }
		bool is_unknown() const { return type == 3; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<GTPtunnelEndpoint>(); break;
			case 2: var.destroy<RLC_Status>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<GTPtunnelEndpoint>(1);
			v.template operator()<RLC_Status>(2);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_secondarysgNBDLGTPTEIDatPDCP()); return true;
			case 2: v(select_id_RLC_Status()); return true;
			case 3: if(type != 3) {clear(); asn::base::set();} type = 3; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<GTPtunnelEndpoint>()); return true;
			case 2: v(var.as<RLC_Status>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(GTPtunnelEndpoint)];
			char dummy2[sizeof(RLC_Status)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_secondarysgNBDLGTPTEIDatPDCP() { set(optional); type=1;}
		void select_id_RLC_Status() { set(optional); type=2;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(optional)) { type = 1; return true; }
			else if(equal(optional)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(optional);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(optional);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-Admitted-ToBeModified-SgNBModAck-Item-SgNBPDCPnotpresent ::= SEQUENCE {
	sgNB-DL-GTP-TEIDatSCG					GTPtunnelEndpoint																								OPTIONAL,
	iE-Extensions					ProtocolExtensionContainer { {E-RABs-Admitted-ToBeModified-SgNBModAck-Item-SgNBPDCPnotpresentExtIEs} } 	OPTIONAL,
	...
}
*/

struct E_RABs_Admitted_ToBeModified_SgNBModAck_Item_SgNBPDCPnotpresent : asn::sequence<2, 0, true, 2>
{
	static constexpr const char* name() {return "E-RABs-Admitted-ToBeModified-SgNBModAck-Item-SgNBPDCPnotpresent";}
	using parent_t = asn::sequence<2, 0, true, 2>;
	struct sgNB_DL_GTP_TEIDatSCG_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "sgNB_DL_GTP_TEIDatSCG_t";}
		using parent_t = GTPtunnelEndpoint;
		static constexpr bool optional = true;

	};
	sgNB_DL_GTP_TEIDatSCG_t& set_sgNB_DL_GTP_TEIDatSCG() { sgNB_DL_GTP_TEIDatSCG.setpresent(true); return sgNB_DL_GTP_TEIDatSCG;}
	sgNB_DL_GTP_TEIDatSCG_t const* get_sgNB_DL_GTP_TEIDatSCG() const {return sgNB_DL_GTP_TEIDatSCG.is_valid() ? &sgNB_DL_GTP_TEIDatSCG : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABs_Admitted_ToBeModified_SgNBModAck_Item_SgNBPDCPnotpresentExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABs_Admitted_ToBeModified_SgNBModAck_Item_SgNBPDCPnotpresentExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(sgNB_DL_GTP_TEIDatSCG);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(sgNB_DL_GTP_TEIDatSCG);
		v(iE_Extensions);

	};
	void clear()
	{
		sgNB_DL_GTP_TEIDatSCG.clear();
		iE_Extensions.clear();

	};
	private:
	sgNB_DL_GTP_TEIDatSCG_t	sgNB_DL_GTP_TEIDatSCG;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABs-ToBeAdded-SgNBModAck-ItemExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct E_RABs_ToBeAdded_SgNBModAck_ItemExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-Admitted-ToBeModified-SgNBModAck-Item ::= SEQUENCE {
	e-RAB-ID								E-RAB-ID,
	en-DC-ResourceConfiguration			EN-DC-ResourceConfiguration,
	resource-configuration				CHOICE {
		sgNBPDCPpresent						E-RABs-Admitted-ToBeModified-SgNBModAck-Item-SgNBPDCPpresent,
		sgNBPDCPnotpresent					E-RABs-Admitted-ToBeModified-SgNBModAck-Item-SgNBPDCPnotpresent,
		...
	},
	iE-Extensions					ProtocolExtensionContainer { {E-RABs-ToBeAdded-SgNBModAck-ItemExtIEs} }	OPTIONAL,
	...
}
*/

struct E_RABs_Admitted_ToBeModified_SgNBModAck_Item : asn::sequence<4, 0, true, 1>
{
	static constexpr const char* name() {return "E-RABs-Admitted-ToBeModified-SgNBModAck-Item";}
	using parent_t = asn::sequence<4, 0, true, 1>;
	struct e_RAB_ID_t : E_RAB_ID
	{
		static constexpr const char* name() {return "e_RAB_ID_t";}
		using parent_t = E_RAB_ID;

	};
	e_RAB_ID_t& ref_e_RAB_ID() {return e_RAB_ID;}
	e_RAB_ID_t const& ref_e_RAB_ID() const {return e_RAB_ID;}
	struct en_DC_ResourceConfiguration_t : EN_DC_ResourceConfiguration
	{
		static constexpr const char* name() {return "en_DC_ResourceConfiguration_t";}
		using parent_t = EN_DC_ResourceConfiguration;

	};
	en_DC_ResourceConfiguration_t& ref_en_DC_ResourceConfiguration() {return en_DC_ResourceConfiguration;}
	en_DC_ResourceConfiguration_t const& ref_en_DC_ResourceConfiguration() const {return en_DC_ResourceConfiguration;}
	struct resource_configuration_t : asn::choice<2, 0, true>
	{
		static constexpr const char* name() {return "resource_configuration_t";}
		using parent_t = asn::choice<2, 0, true>;
		index_type get_index() const {return index;}
		bool is_unknown() const {return index == 3;}
		void set_unknown() { set_index(3);  }
		~resource_configuration_t() {clear();}
		struct sgNBPDCPpresent_t : E_RABs_Admitted_ToBeModified_SgNBModAck_Item_SgNBPDCPpresent
		{
			static constexpr const char* name() {return "sgNBPDCPpresent_t";}
			using parent_t = E_RABs_Admitted_ToBeModified_SgNBModAck_Item_SgNBPDCPpresent;

		};
		struct sgNBPDCPnotpresent_t : E_RABs_Admitted_ToBeModified_SgNBModAck_Item_SgNBPDCPnotpresent
		{
			static constexpr const char* name() {return "sgNBPDCPnotpresent_t";}
			using parent_t = E_RABs_Admitted_ToBeModified_SgNBModAck_Item_SgNBPDCPnotpresent;

		};
		void clear()
		{
			switch(get_index())
			{
			case 1: var.destroy<sgNBPDCPpresent_t>(); break;
			case 2: var.destroy<sgNBPDCPnotpresent_t>(); break;
			}
			index = 0;
			base::clear();
		}
		template<typename V> bool decode(size_t idx, V& v)
		{
			clear();
			switch(idx)
			{
			case 1: set_index(1); return v(var.build<sgNBPDCPpresent_t>());
			case 2: set_index(2); return v(var.build<sgNBPDCPnotpresent_t>());
			}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			switch(get_index())
			{
			case 1: return v(var.as<sgNBPDCPpresent_t>());
			case 2: return v(var.as<sgNBPDCPnotpresent_t>());
			}
			return false;
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<sgNBPDCPpresent_t>(1);
			v.template operator()<sgNBPDCPnotpresent_t>(2);

		}
		sgNBPDCPpresent_t& select_sgNBPDCPpresent() { if(get_index() != 1) { clear(); set_index(1); return var.build<sgNBPDCPpresent_t>();} return var.as<sgNBPDCPpresent_t>();}
		sgNBPDCPpresent_t const* get_sgNBPDCPpresent() const { if(get_index() == 1) { return &var.as<sgNBPDCPpresent_t>();} return nullptr; }
		sgNBPDCPnotpresent_t& select_sgNBPDCPnotpresent() { if(get_index() != 2) { clear(); set_index(2); return var.build<sgNBPDCPnotpresent_t>();} return var.as<sgNBPDCPnotpresent_t>();}
		sgNBPDCPnotpresent_t const* get_sgNBPDCPnotpresent() const { if(get_index() == 2) { return &var.as<sgNBPDCPnotpresent_t>();} return nullptr; }
		private:
		void set_index(index_type i) {index = i; base::set();}
		union union_type
		{
			char dummy1[sizeof(sgNBPDCPpresent_t)];
			char dummy2[sizeof(sgNBPDCPnotpresent_t)];

		};
		asn::variant<sizeof(union_type)>	var;
		index_type	index {0};
	};
	resource_configuration_t& ref_resource_configuration() {return resource_configuration;}
	resource_configuration_t const& ref_resource_configuration() const {return resource_configuration;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABs_ToBeAdded_SgNBModAck_ItemExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABs_ToBeAdded_SgNBModAck_ItemExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(e_RAB_ID);
		v(en_DC_ResourceConfiguration);
		v(resource_configuration);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(e_RAB_ID);
		v(en_DC_ResourceConfiguration);
		v(resource_configuration);
		v(iE_Extensions);

	};
	void clear()
	{
		e_RAB_ID.clear();
		en_DC_ResourceConfiguration.clear();
		resource_configuration.clear();
		iE_Extensions.clear();

	};
	private:
	e_RAB_ID_t	e_RAB_ID;
	en_DC_ResourceConfiguration_t	en_DC_ResourceConfiguration;
	resource_configuration_t	resource_configuration;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABs-Admitted-ToBeModified-SgNBModAck-ItemIEs X2AP-PROTOCOL-IES ::= {
	{ ID id-E-RABs-Admitted-ToBeModified-SgNBModAck-Item		CRITICALITY ignore	TYPE E-RABs-Admitted-ToBeModified-SgNBModAck-Item		PRESENCE mandatory}
}
*/

struct E_RABs_Admitted_ToBeModified_SgNBModAck_ItemIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_E_RABs_Admitted_ToBeModified_SgNBModAck_Item() { set(id_E_RABs_Admitted_ToBeModified_SgNBModAck_Item); type=1;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_E_RABs_Admitted_ToBeModified_SgNBModAck_Item)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_E_RABs_Admitted_ToBeModified_SgNBModAck_Item);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_E_RABs_Admitted_ToBeModified_SgNBModAck_Item() { set(ignore); type=1;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Value_t : asn::typefield<false>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		E_RABs_Admitted_ToBeModified_SgNBModAck_Item& select_id_E_RABs_Admitted_ToBeModified_SgNBModAck_Item() { return set<E_RABs_Admitted_ToBeModified_SgNBModAck_Item>(1); }
		E_RABs_Admitted_ToBeModified_SgNBModAck_Item const* get_id_E_RABs_Admitted_ToBeModified_SgNBModAck_Item() const { return get<E_RABs_Admitted_ToBeModified_SgNBModAck_Item>(1); }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<E_RABs_Admitted_ToBeModified_SgNBModAck_Item>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<E_RABs_Admitted_ToBeModified_SgNBModAck_Item>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_E_RABs_Admitted_ToBeModified_SgNBModAck_Item()); return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<E_RABs_Admitted_ToBeModified_SgNBModAck_Item>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(E_RABs_Admitted_ToBeModified_SgNBModAck_Item)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_E_RABs_Admitted_ToBeModified_SgNBModAck_Item() { set(mandatory); type=1;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-Admitted-ToBeModified-SgNBModAckList ::= SEQUENCE (SIZE (1..maxnoofBearers)) OF ProtocolIE-Single-Container { {E-RABs-Admitted-ToBeModified-SgNBModAck-ItemIEs} }
*/

struct E_RABs_Admitted_ToBeModified_SgNBModAckList_elm : ProtocolIE_Single_Container<E_RABs_Admitted_ToBeModified_SgNBModAck_ItemIEs>
{
	static constexpr const char* name() {return "E_RABs_Admitted_ToBeModified_SgNBModAckList_elm";}
	using parent_t = ProtocolIE_Single_Container<E_RABs_Admitted_ToBeModified_SgNBModAck_ItemIEs>;

};
struct E_RABs_Admitted_ToBeModified_SgNBModAckList : asn::sequenceof<E_RABs_Admitted_ToBeModified_SgNBModAckList_elm>
{
	static constexpr const char* name() {return "E-RABs-Admitted-ToBeModified-SgNBModAckList";}
	using parent_t = asn::sequenceof<E_RABs_Admitted_ToBeModified_SgNBModAckList_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofBearers >>;

};
/*
E-RABs-Admitted-ToBeReleased-ModAckItem-SCG-BearerExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct E_RABs_Admitted_ToBeReleased_ModAckItem_SCG_BearerExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-Admitted-ToBeReleased-ModAckItem-SCG-Bearer ::= SEQUENCE {
	e-RAB-ID					E-RAB-ID,
	iE-Extensions				ProtocolExtensionContainer { {E-RABs-Admitted-ToBeReleased-ModAckItem-SCG-BearerExtIEs} }	OPTIONAL,
	...
}
*/

struct E_RABs_Admitted_ToBeReleased_ModAckItem_SCG_Bearer : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "E-RABs-Admitted-ToBeReleased-ModAckItem-SCG-Bearer";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct e_RAB_ID_t : E_RAB_ID
	{
		static constexpr const char* name() {return "e_RAB_ID_t";}
		using parent_t = E_RAB_ID;

	};
	e_RAB_ID_t& ref_e_RAB_ID() {return e_RAB_ID;}
	e_RAB_ID_t const& ref_e_RAB_ID() const {return e_RAB_ID;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABs_Admitted_ToBeReleased_ModAckItem_SCG_BearerExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABs_Admitted_ToBeReleased_ModAckItem_SCG_BearerExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(e_RAB_ID);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(e_RAB_ID);
		v(iE_Extensions);

	};
	void clear()
	{
		e_RAB_ID.clear();
		iE_Extensions.clear();

	};
	private:
	e_RAB_ID_t	e_RAB_ID;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABs-Admitted-ToBeReleased-ModAckItem-Split-BearerExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct E_RABs_Admitted_ToBeReleased_ModAckItem_Split_BearerExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-Admitted-ToBeReleased-ModAckItem-Split-Bearer ::= SEQUENCE {
	e-RAB-ID					E-RAB-ID,
	iE-Extensions				ProtocolExtensionContainer { {E-RABs-Admitted-ToBeReleased-ModAckItem-Split-BearerExtIEs} } OPTIONAL,
	...
}
*/

struct E_RABs_Admitted_ToBeReleased_ModAckItem_Split_Bearer : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "E-RABs-Admitted-ToBeReleased-ModAckItem-Split-Bearer";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct e_RAB_ID_t : E_RAB_ID
	{
		static constexpr const char* name() {return "e_RAB_ID_t";}
		using parent_t = E_RAB_ID;

	};
	e_RAB_ID_t& ref_e_RAB_ID() {return e_RAB_ID;}
	e_RAB_ID_t const& ref_e_RAB_ID() const {return e_RAB_ID;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABs_Admitted_ToBeReleased_ModAckItem_Split_BearerExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABs_Admitted_ToBeReleased_ModAckItem_Split_BearerExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(e_RAB_ID);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(e_RAB_ID);
		v(iE_Extensions);

	};
	void clear()
	{
		e_RAB_ID.clear();
		iE_Extensions.clear();

	};
	private:
	e_RAB_ID_t	e_RAB_ID;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABs-Admitted-ToReleased-ModAckItem ::= CHOICE {
	sCG-Bearer		E-RABs-Admitted-ToBeReleased-ModAckItem-SCG-Bearer,
	split-Bearer	E-RABs-Admitted-ToBeReleased-ModAckItem-Split-Bearer,
	...
}
*/

struct E_RABs_Admitted_ToReleased_ModAckItem : asn::choice<2, 0, true>
{
	static constexpr const char* name() {return "E-RABs-Admitted-ToReleased-ModAckItem";}
	using parent_t = asn::choice<2, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 3;}
	void set_unknown() { set_index(3);  }
	~E_RABs_Admitted_ToReleased_ModAckItem() {clear();}
	struct sCG_Bearer_t : E_RABs_Admitted_ToBeReleased_ModAckItem_SCG_Bearer
	{
		static constexpr const char* name() {return "sCG_Bearer_t";}
		using parent_t = E_RABs_Admitted_ToBeReleased_ModAckItem_SCG_Bearer;

	};
	struct split_Bearer_t : E_RABs_Admitted_ToBeReleased_ModAckItem_Split_Bearer
	{
		static constexpr const char* name() {return "split_Bearer_t";}
		using parent_t = E_RABs_Admitted_ToBeReleased_ModAckItem_Split_Bearer;

	};
	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<sCG_Bearer_t>(); break;
		case 2: var.destroy<split_Bearer_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<sCG_Bearer_t>());
		case 2: set_index(2); return v(var.build<split_Bearer_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<sCG_Bearer_t>());
		case 2: return v(var.as<split_Bearer_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<sCG_Bearer_t>(1);
		v.template operator()<split_Bearer_t>(2);

	}
	sCG_Bearer_t& select_sCG_Bearer() { if(get_index() != 1) { clear(); set_index(1); return var.build<sCG_Bearer_t>();} return var.as<sCG_Bearer_t>();}
	sCG_Bearer_t const* get_sCG_Bearer() const { if(get_index() == 1) { return &var.as<sCG_Bearer_t>();} return nullptr; }
	split_Bearer_t& select_split_Bearer() { if(get_index() != 2) { clear(); set_index(2); return var.build<split_Bearer_t>();} return var.as<split_Bearer_t>();}
	split_Bearer_t const* get_split_Bearer() const { if(get_index() == 2) { return &var.as<split_Bearer_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(sCG_Bearer_t)];
		char dummy2[sizeof(split_Bearer_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
E-RABs-Admitted-ToBeReleased-ModAckItemIEs X2AP-PROTOCOL-IES ::= {
	{ ID id-E-RABs-Admitted-ToBeReleased-ModAckItem		CRITICALITY ignore	TYPE E-RABs-Admitted-ToReleased-ModAckItem		PRESENCE mandatory}
}
*/

struct E_RABs_Admitted_ToBeReleased_ModAckItemIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_E_RABs_Admitted_ToBeReleased_ModAckItem() { set(id_E_RABs_Admitted_ToBeReleased_ModAckItem); type=1;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_E_RABs_Admitted_ToBeReleased_ModAckItem)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_E_RABs_Admitted_ToBeReleased_ModAckItem);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_E_RABs_Admitted_ToBeReleased_ModAckItem() { set(ignore); type=1;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Value_t : asn::typefield<false>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		E_RABs_Admitted_ToReleased_ModAckItem& select_id_E_RABs_Admitted_ToBeReleased_ModAckItem() { return set<E_RABs_Admitted_ToReleased_ModAckItem>(1); }
		E_RABs_Admitted_ToReleased_ModAckItem const* get_id_E_RABs_Admitted_ToBeReleased_ModAckItem() const { return get<E_RABs_Admitted_ToReleased_ModAckItem>(1); }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<E_RABs_Admitted_ToReleased_ModAckItem>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<E_RABs_Admitted_ToReleased_ModAckItem>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_E_RABs_Admitted_ToBeReleased_ModAckItem()); return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<E_RABs_Admitted_ToReleased_ModAckItem>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(E_RABs_Admitted_ToReleased_ModAckItem)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_E_RABs_Admitted_ToBeReleased_ModAckItem() { set(mandatory); type=1;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-Admitted-ToBeReleased-ModAckList ::= SEQUENCE (SIZE (1..maxnoofBearers)) OF ProtocolIE-Single-Container { {E-RABs-Admitted-ToBeReleased-ModAckItemIEs} }
*/

struct E_RABs_Admitted_ToBeReleased_ModAckList_elm : ProtocolIE_Single_Container<E_RABs_Admitted_ToBeReleased_ModAckItemIEs>
{
	static constexpr const char* name() {return "E_RABs_Admitted_ToBeReleased_ModAckList_elm";}
	using parent_t = ProtocolIE_Single_Container<E_RABs_Admitted_ToBeReleased_ModAckItemIEs>;

};
struct E_RABs_Admitted_ToBeReleased_ModAckList : asn::sequenceof<E_RABs_Admitted_ToBeReleased_ModAckList_elm>
{
	static constexpr const char* name() {return "E-RABs-Admitted-ToBeReleased-ModAckList";}
	using parent_t = asn::sequenceof<E_RABs_Admitted_ToBeReleased_ModAckList_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofBearers >>;

};
/*
E-RABs-Admitted-ToBeReleased-SgNBModAck-Item-SgNBPDCPnotpresentExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct E_RABs_Admitted_ToBeReleased_SgNBModAck_Item_SgNBPDCPnotpresentExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-Admitted-ToBeReleased-SgNBModAck-Item-SgNBPDCPnotpresent ::= SEQUENCE {
	iE-Extensions				ProtocolExtensionContainer { {E-RABs-Admitted-ToBeReleased-SgNBModAck-Item-SgNBPDCPnotpresentExtIEs} } OPTIONAL,
	...
}
*/

struct E_RABs_Admitted_ToBeReleased_SgNBModAck_Item_SgNBPDCPnotpresent : asn::sequence<1, 0, true, 1>
{
	static constexpr const char* name() {return "E-RABs-Admitted-ToBeReleased-SgNBModAck-Item-SgNBPDCPnotpresent";}
	using parent_t = asn::sequence<1, 0, true, 1>;
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABs_Admitted_ToBeReleased_SgNBModAck_Item_SgNBPDCPnotpresentExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABs_Admitted_ToBeReleased_SgNBModAck_Item_SgNBPDCPnotpresentExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(iE_Extensions);

	};
	void clear()
	{
		iE_Extensions.clear();

	};
	private:
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABs-Admitted-ToBeReleased-SgNBModAck-Item-SgNBPDCPpresentExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct E_RABs_Admitted_ToBeReleased_SgNBModAck_Item_SgNBPDCPpresentExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-Admitted-ToBeReleased-SgNBModAck-Item-SgNBPDCPpresent ::= SEQUENCE {
	iE-Extensions				ProtocolExtensionContainer { {E-RABs-Admitted-ToBeReleased-SgNBModAck-Item-SgNBPDCPpresentExtIEs} }		OPTIONAL,
	...
}
*/

struct E_RABs_Admitted_ToBeReleased_SgNBModAck_Item_SgNBPDCPpresent : asn::sequence<1, 0, true, 1>
{
	static constexpr const char* name() {return "E-RABs-Admitted-ToBeReleased-SgNBModAck-Item-SgNBPDCPpresent";}
	using parent_t = asn::sequence<1, 0, true, 1>;
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABs_Admitted_ToBeReleased_SgNBModAck_Item_SgNBPDCPpresentExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABs_Admitted_ToBeReleased_SgNBModAck_Item_SgNBPDCPpresentExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(iE_Extensions);

	};
	void clear()
	{
		iE_Extensions.clear();

	};
	private:
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABs-ToBeReleased-SgNBModAck-ItemExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct E_RABs_ToBeReleased_SgNBModAck_ItemExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-Admitted-ToReleased-SgNBModAck-Item ::= SEQUENCE {
	e-RAB-ID							E-RAB-ID,
	en-DC-ResourceConfiguration			EN-DC-ResourceConfiguration,
	resource-configuration				CHOICE {
		sgNBPDCPpresent						E-RABs-Admitted-ToBeReleased-SgNBModAck-Item-SgNBPDCPpresent,
		sgNBPDCPnotpresent					E-RABs-Admitted-ToBeReleased-SgNBModAck-Item-SgNBPDCPnotpresent,
		...
	},
	iE-Extensions					ProtocolExtensionContainer { {E-RABs-ToBeReleased-SgNBModAck-ItemExtIEs} }	OPTIONAL,
	...
}
*/

struct E_RABs_Admitted_ToReleased_SgNBModAck_Item : asn::sequence<4, 0, true, 1>
{
	static constexpr const char* name() {return "E-RABs-Admitted-ToReleased-SgNBModAck-Item";}
	using parent_t = asn::sequence<4, 0, true, 1>;
	struct e_RAB_ID_t : E_RAB_ID
	{
		static constexpr const char* name() {return "e_RAB_ID_t";}
		using parent_t = E_RAB_ID;

	};
	e_RAB_ID_t& ref_e_RAB_ID() {return e_RAB_ID;}
	e_RAB_ID_t const& ref_e_RAB_ID() const {return e_RAB_ID;}
	struct en_DC_ResourceConfiguration_t : EN_DC_ResourceConfiguration
	{
		static constexpr const char* name() {return "en_DC_ResourceConfiguration_t";}
		using parent_t = EN_DC_ResourceConfiguration;

	};
	en_DC_ResourceConfiguration_t& ref_en_DC_ResourceConfiguration() {return en_DC_ResourceConfiguration;}
	en_DC_ResourceConfiguration_t const& ref_en_DC_ResourceConfiguration() const {return en_DC_ResourceConfiguration;}
	struct resource_configuration_t : asn::choice<2, 0, true>
	{
		static constexpr const char* name() {return "resource_configuration_t";}
		using parent_t = asn::choice<2, 0, true>;
		index_type get_index() const {return index;}
		bool is_unknown() const {return index == 3;}
		void set_unknown() { set_index(3);  }
		~resource_configuration_t() {clear();}
		struct sgNBPDCPpresent_t : E_RABs_Admitted_ToBeReleased_SgNBModAck_Item_SgNBPDCPpresent
		{
			static constexpr const char* name() {return "sgNBPDCPpresent_t";}
			using parent_t = E_RABs_Admitted_ToBeReleased_SgNBModAck_Item_SgNBPDCPpresent;

		};
		struct sgNBPDCPnotpresent_t : E_RABs_Admitted_ToBeReleased_SgNBModAck_Item_SgNBPDCPnotpresent
		{
			static constexpr const char* name() {return "sgNBPDCPnotpresent_t";}
			using parent_t = E_RABs_Admitted_ToBeReleased_SgNBModAck_Item_SgNBPDCPnotpresent;

		};
		void clear()
		{
			switch(get_index())
			{
			case 1: var.destroy<sgNBPDCPpresent_t>(); break;
			case 2: var.destroy<sgNBPDCPnotpresent_t>(); break;
			}
			index = 0;
			base::clear();
		}
		template<typename V> bool decode(size_t idx, V& v)
		{
			clear();
			switch(idx)
			{
			case 1: set_index(1); return v(var.build<sgNBPDCPpresent_t>());
			case 2: set_index(2); return v(var.build<sgNBPDCPnotpresent_t>());
			}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			switch(get_index())
			{
			case 1: return v(var.as<sgNBPDCPpresent_t>());
			case 2: return v(var.as<sgNBPDCPnotpresent_t>());
			}
			return false;
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<sgNBPDCPpresent_t>(1);
			v.template operator()<sgNBPDCPnotpresent_t>(2);

		}
		sgNBPDCPpresent_t& select_sgNBPDCPpresent() { if(get_index() != 1) { clear(); set_index(1); return var.build<sgNBPDCPpresent_t>();} return var.as<sgNBPDCPpresent_t>();}
		sgNBPDCPpresent_t const* get_sgNBPDCPpresent() const { if(get_index() == 1) { return &var.as<sgNBPDCPpresent_t>();} return nullptr; }
		sgNBPDCPnotpresent_t& select_sgNBPDCPnotpresent() { if(get_index() != 2) { clear(); set_index(2); return var.build<sgNBPDCPnotpresent_t>();} return var.as<sgNBPDCPnotpresent_t>();}
		sgNBPDCPnotpresent_t const* get_sgNBPDCPnotpresent() const { if(get_index() == 2) { return &var.as<sgNBPDCPnotpresent_t>();} return nullptr; }
		private:
		void set_index(index_type i) {index = i; base::set();}
		union union_type
		{
			char dummy1[sizeof(sgNBPDCPpresent_t)];
			char dummy2[sizeof(sgNBPDCPnotpresent_t)];

		};
		asn::variant<sizeof(union_type)>	var;
		index_type	index {0};
	};
	resource_configuration_t& ref_resource_configuration() {return resource_configuration;}
	resource_configuration_t const& ref_resource_configuration() const {return resource_configuration;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABs_ToBeReleased_SgNBModAck_ItemExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABs_ToBeReleased_SgNBModAck_ItemExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(e_RAB_ID);
		v(en_DC_ResourceConfiguration);
		v(resource_configuration);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(e_RAB_ID);
		v(en_DC_ResourceConfiguration);
		v(resource_configuration);
		v(iE_Extensions);

	};
	void clear()
	{
		e_RAB_ID.clear();
		en_DC_ResourceConfiguration.clear();
		resource_configuration.clear();
		iE_Extensions.clear();

	};
	private:
	e_RAB_ID_t	e_RAB_ID;
	en_DC_ResourceConfiguration_t	en_DC_ResourceConfiguration;
	resource_configuration_t	resource_configuration;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABs-Admitted-ToBeReleased-SgNBModAck-ItemIEs X2AP-PROTOCOL-IES ::= {
	{ ID id-E-RABs-Admitted-ToBeReleased-SgNBModAck-Item		CRITICALITY ignore	TYPE E-RABs-Admitted-ToReleased-SgNBModAck-Item		PRESENCE mandatory}
}
*/

struct E_RABs_Admitted_ToBeReleased_SgNBModAck_ItemIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_E_RABs_Admitted_ToBeReleased_SgNBModAck_Item() { set(id_E_RABs_Admitted_ToBeReleased_SgNBModAck_Item); type=1;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_E_RABs_Admitted_ToBeReleased_SgNBModAck_Item)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_E_RABs_Admitted_ToBeReleased_SgNBModAck_Item);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_E_RABs_Admitted_ToBeReleased_SgNBModAck_Item() { set(ignore); type=1;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Value_t : asn::typefield<false>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		E_RABs_Admitted_ToReleased_SgNBModAck_Item& select_id_E_RABs_Admitted_ToBeReleased_SgNBModAck_Item() { return set<E_RABs_Admitted_ToReleased_SgNBModAck_Item>(1); }
		E_RABs_Admitted_ToReleased_SgNBModAck_Item const* get_id_E_RABs_Admitted_ToBeReleased_SgNBModAck_Item() const { return get<E_RABs_Admitted_ToReleased_SgNBModAck_Item>(1); }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<E_RABs_Admitted_ToReleased_SgNBModAck_Item>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<E_RABs_Admitted_ToReleased_SgNBModAck_Item>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_E_RABs_Admitted_ToBeReleased_SgNBModAck_Item()); return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<E_RABs_Admitted_ToReleased_SgNBModAck_Item>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(E_RABs_Admitted_ToReleased_SgNBModAck_Item)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_E_RABs_Admitted_ToBeReleased_SgNBModAck_Item() { set(mandatory); type=1;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-Admitted-ToBeReleased-SgNBModAckList ::= SEQUENCE (SIZE (1..maxnoofBearers)) OF ProtocolIE-Single-Container { {E-RABs-Admitted-ToBeReleased-SgNBModAck-ItemIEs} }
*/

struct E_RABs_Admitted_ToBeReleased_SgNBModAckList_elm : ProtocolIE_Single_Container<E_RABs_Admitted_ToBeReleased_SgNBModAck_ItemIEs>
{
	static constexpr const char* name() {return "E_RABs_Admitted_ToBeReleased_SgNBModAckList_elm";}
	using parent_t = ProtocolIE_Single_Container<E_RABs_Admitted_ToBeReleased_SgNBModAck_ItemIEs>;

};
struct E_RABs_Admitted_ToBeReleased_SgNBModAckList : asn::sequenceof<E_RABs_Admitted_ToBeReleased_SgNBModAckList_elm>
{
	static constexpr const char* name() {return "E-RABs-Admitted-ToBeReleased-SgNBModAckList";}
	using parent_t = asn::sequenceof<E_RABs_Admitted_ToBeReleased_SgNBModAckList_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofBearers >>;

};
/*
E-RABs-Admitted-ToBeReleased-SgNBRelReqAck-ItemExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct E_RABs_Admitted_ToBeReleased_SgNBRelReqAck_ItemExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-Admitted-ToBeReleased-SgNBRelReqAck-Item ::= SEQUENCE {
	e-RAB-ID							E-RAB-ID,
	rlc-Mode-transferred			RLCMode,
	iE-Extensions					ProtocolExtensionContainer { {E-RABs-Admitted-ToBeReleased-SgNBRelReqAck-ItemExtIEs} }	OPTIONAL,
	...
}
*/

struct E_RABs_Admitted_ToBeReleased_SgNBRelReqAck_Item : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "E-RABs-Admitted-ToBeReleased-SgNBRelReqAck-Item";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct e_RAB_ID_t : E_RAB_ID
	{
		static constexpr const char* name() {return "e_RAB_ID_t";}
		using parent_t = E_RAB_ID;

	};
	e_RAB_ID_t& ref_e_RAB_ID() {return e_RAB_ID;}
	e_RAB_ID_t const& ref_e_RAB_ID() const {return e_RAB_ID;}
	struct rlc_Mode_transferred_t : RLCMode
	{
		static constexpr const char* name() {return "rlc_Mode_transferred_t";}
		using parent_t = RLCMode;

	};
	rlc_Mode_transferred_t& ref_rlc_Mode_transferred() {return rlc_Mode_transferred;}
	rlc_Mode_transferred_t const& ref_rlc_Mode_transferred() const {return rlc_Mode_transferred;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABs_Admitted_ToBeReleased_SgNBRelReqAck_ItemExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABs_Admitted_ToBeReleased_SgNBRelReqAck_ItemExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(e_RAB_ID);
		v(rlc_Mode_transferred);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(e_RAB_ID);
		v(rlc_Mode_transferred);
		v(iE_Extensions);

	};
	void clear()
	{
		e_RAB_ID.clear();
		rlc_Mode_transferred.clear();
		iE_Extensions.clear();

	};
	private:
	e_RAB_ID_t	e_RAB_ID;
	rlc_Mode_transferred_t	rlc_Mode_transferred;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABs-Admitted-ToBeReleased-SgNBRelReqAck-ItemIEs X2AP-PROTOCOL-IES ::= {
	{ ID id-E-RABs-Admitted-ToBeReleased-SgNBRelReqAck-Item	CRITICALITY ignore	TYPE E-RABs-Admitted-ToBeReleased-SgNBRelReqAck-Item		PRESENCE mandatory},
	...
}
*/

struct E_RABs_Admitted_ToBeReleased_SgNBRelReqAck_ItemIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_E_RABs_Admitted_ToBeReleased_SgNBRelReqAck_Item() { set(id_E_RABs_Admitted_ToBeReleased_SgNBRelReqAck_Item); type=1;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_E_RABs_Admitted_ToBeReleased_SgNBRelReqAck_Item)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_E_RABs_Admitted_ToBeReleased_SgNBRelReqAck_Item);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_E_RABs_Admitted_ToBeReleased_SgNBRelReqAck_Item() { set(ignore); type=1;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Value_t : asn::typefield<true>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		E_RABs_Admitted_ToBeReleased_SgNBRelReqAck_Item& select_id_E_RABs_Admitted_ToBeReleased_SgNBRelReqAck_Item() { return set<E_RABs_Admitted_ToBeReleased_SgNBRelReqAck_Item>(1); }
		E_RABs_Admitted_ToBeReleased_SgNBRelReqAck_Item const* get_id_E_RABs_Admitted_ToBeReleased_SgNBRelReqAck_Item() const { return get<E_RABs_Admitted_ToBeReleased_SgNBRelReqAck_Item>(1); }
		bool is_unknown() const { return type == 2; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<E_RABs_Admitted_ToBeReleased_SgNBRelReqAck_Item>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<E_RABs_Admitted_ToBeReleased_SgNBRelReqAck_Item>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_E_RABs_Admitted_ToBeReleased_SgNBRelReqAck_Item()); return true;
			case 2: if(type != 2) {clear(); asn::base::set();} type = 2; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<E_RABs_Admitted_ToBeReleased_SgNBRelReqAck_Item>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(E_RABs_Admitted_ToBeReleased_SgNBRelReqAck_Item)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_E_RABs_Admitted_ToBeReleased_SgNBRelReqAck_Item() { set(mandatory); type=1;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-Admitted-ToBeReleased-SgNBRelReqAckList ::= SEQUENCE (SIZE(1..maxnoofBearers)) OF
										ProtocolIE-Single-Container { {E-RABs-Admitted-ToBeReleased-SgNBRelReqAck-ItemIEs} }
*/

struct E_RABs_Admitted_ToBeReleased_SgNBRelReqAckList_elm : ProtocolIE_Single_Container<E_RABs_Admitted_ToBeReleased_SgNBRelReqAck_ItemIEs>
{
	static constexpr const char* name() {return "E_RABs_Admitted_ToBeReleased_SgNBRelReqAckList_elm";}
	using parent_t = ProtocolIE_Single_Container<E_RABs_Admitted_ToBeReleased_SgNBRelReqAck_ItemIEs>;

};
struct E_RABs_Admitted_ToBeReleased_SgNBRelReqAckList : asn::sequenceof<E_RABs_Admitted_ToBeReleased_SgNBRelReqAckList_elm>
{
	static constexpr const char* name() {return "E-RABs-Admitted-ToBeReleased-SgNBRelReqAckList";}
	using parent_t = asn::sequenceof<E_RABs_Admitted_ToBeReleased_SgNBRelReqAckList_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofBearers >>;

};
/*
E-RABs-AdmittedToBeModified-SgNBModConf-Item-SgNBPDCPpresentExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct E_RABs_AdmittedToBeModified_SgNBModConf_Item_SgNBPDCPpresentExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-AdmittedToBeModified-SgNBModConf-Item-SgNBPDCPpresent ::= SEQUENCE {
	iE-Extensions				ProtocolExtensionContainer { {E-RABs-AdmittedToBeModified-SgNBModConf-Item-SgNBPDCPpresentExtIEs} }		OPTIONAL,
	...
}
*/

struct E_RABs_AdmittedToBeModified_SgNBModConf_Item_SgNBPDCPpresent : asn::sequence<1, 0, true, 1>
{
	static constexpr const char* name() {return "E-RABs-AdmittedToBeModified-SgNBModConf-Item-SgNBPDCPpresent";}
	using parent_t = asn::sequence<1, 0, true, 1>;
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABs_AdmittedToBeModified_SgNBModConf_Item_SgNBPDCPpresentExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABs_AdmittedToBeModified_SgNBModConf_Item_SgNBPDCPpresentExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(iE_Extensions);

	};
	void clear()
	{
		iE_Extensions.clear();

	};
	private:
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABs-AdmittedToBeModified-SgNBModConf-Item-SgNBPDCPnotpresentExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	{ ID id-uLpDCPSnLength							CRITICALITY ignore	EXTENSION PDCPSnLength					PRESENCE optional}|
	{ ID id-dLPDCPSnLength							CRITICALITY ignore	EXTENSION PDCPSnLength					PRESENCE optional},
	...
}
*/

struct E_RABs_AdmittedToBeModified_SgNBModConf_Item_SgNBPDCPnotpresentExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_uLpDCPSnLength() { set(id_uLpDCPSnLength); type=1;}
		void select_id_dLPDCPSnLength() { set(id_dLPDCPSnLength); type=2;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_uLpDCPSnLength)) { type = 1; return true; }
			else if(equal(id_dLPDCPSnLength)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_uLpDCPSnLength);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_dLPDCPSnLength);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_uLpDCPSnLength() { set(ignore); type=1;}
		void select_id_dLPDCPSnLength() { set(ignore); type=2;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else if(equal(ignore)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(ignore);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		PDCPSnLength& select_id_uLpDCPSnLength() { return set<PDCPSnLength>(1); }
		PDCPSnLength const* get_id_uLpDCPSnLength() const { return get<PDCPSnLength>(1); }
		PDCPSnLength& select_id_dLPDCPSnLength() { return set<PDCPSnLength>(2); }
		PDCPSnLength const* get_id_dLPDCPSnLength() const { return get<PDCPSnLength>(2); }
		bool is_unknown() const { return type == 3; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<PDCPSnLength>(); break;
			case 2: var.destroy<PDCPSnLength>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<PDCPSnLength>(1);
			v.template operator()<PDCPSnLength>(2);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_uLpDCPSnLength()); return true;
			case 2: v(select_id_dLPDCPSnLength()); return true;
			case 3: if(type != 3) {clear(); asn::base::set();} type = 3; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<PDCPSnLength>()); return true;
			case 2: v(var.as<PDCPSnLength>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(PDCPSnLength)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_uLpDCPSnLength() { set(optional); type=1;}
		void select_id_dLPDCPSnLength() { set(optional); type=2;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(optional)) { type = 1; return true; }
			else if(equal(optional)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(optional);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(optional);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-AdmittedToBeModified-SgNBModConf-Item-SgNBPDCPnotpresent ::= SEQUENCE {
	secondary-meNB-UL-GTP-TEIDatPDCP				GTPtunnelEndpoint				OPTIONAL,
	iE-Extensions				ProtocolExtensionContainer { {E-RABs-AdmittedToBeModified-SgNBModConf-Item-SgNBPDCPnotpresentExtIEs} }		OPTIONAL,
	...
}
*/

struct E_RABs_AdmittedToBeModified_SgNBModConf_Item_SgNBPDCPnotpresent : asn::sequence<2, 0, true, 2>
{
	static constexpr const char* name() {return "E-RABs-AdmittedToBeModified-SgNBModConf-Item-SgNBPDCPnotpresent";}
	using parent_t = asn::sequence<2, 0, true, 2>;
	struct secondary_meNB_UL_GTP_TEIDatPDCP_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "secondary_meNB_UL_GTP_TEIDatPDCP_t";}
		using parent_t = GTPtunnelEndpoint;
		static constexpr bool optional = true;

	};
	secondary_meNB_UL_GTP_TEIDatPDCP_t& set_secondary_meNB_UL_GTP_TEIDatPDCP() { secondary_meNB_UL_GTP_TEIDatPDCP.setpresent(true); return secondary_meNB_UL_GTP_TEIDatPDCP;}
	secondary_meNB_UL_GTP_TEIDatPDCP_t const* get_secondary_meNB_UL_GTP_TEIDatPDCP() const {return secondary_meNB_UL_GTP_TEIDatPDCP.is_valid() ? &secondary_meNB_UL_GTP_TEIDatPDCP : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABs_AdmittedToBeModified_SgNBModConf_Item_SgNBPDCPnotpresentExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABs_AdmittedToBeModified_SgNBModConf_Item_SgNBPDCPnotpresentExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(secondary_meNB_UL_GTP_TEIDatPDCP);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(secondary_meNB_UL_GTP_TEIDatPDCP);
		v(iE_Extensions);

	};
	void clear()
	{
		secondary_meNB_UL_GTP_TEIDatPDCP.clear();
		iE_Extensions.clear();

	};
	private:
	secondary_meNB_UL_GTP_TEIDatPDCP_t	secondary_meNB_UL_GTP_TEIDatPDCP;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABs-AdmittedToBeModified-SgNBModConf-ItemExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct E_RABs_AdmittedToBeModified_SgNBModConf_ItemExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-AdmittedToBeModified-SgNBModConf-Item ::= SEQUENCE {
	e-RAB-ID								E-RAB-ID,
	en-DC-ResourceConfiguration			EN-DC-ResourceConfiguration,
	resource-configuration				CHOICE {
		sgNBPDCPpresent						E-RABs-AdmittedToBeModified-SgNBModConf-Item-SgNBPDCPpresent,
		sgNBPDCPnotpresent					E-RABs-AdmittedToBeModified-SgNBModConf-Item-SgNBPDCPnotpresent,
		...
	},
	iE-Extensions					ProtocolExtensionContainer { {E-RABs-AdmittedToBeModified-SgNBModConf-ItemExtIEs} }	OPTIONAL,
	...
}
*/

struct E_RABs_AdmittedToBeModified_SgNBModConf_Item : asn::sequence<4, 0, true, 1>
{
	static constexpr const char* name() {return "E-RABs-AdmittedToBeModified-SgNBModConf-Item";}
	using parent_t = asn::sequence<4, 0, true, 1>;
	struct e_RAB_ID_t : E_RAB_ID
	{
		static constexpr const char* name() {return "e_RAB_ID_t";}
		using parent_t = E_RAB_ID;

	};
	e_RAB_ID_t& ref_e_RAB_ID() {return e_RAB_ID;}
	e_RAB_ID_t const& ref_e_RAB_ID() const {return e_RAB_ID;}
	struct en_DC_ResourceConfiguration_t : EN_DC_ResourceConfiguration
	{
		static constexpr const char* name() {return "en_DC_ResourceConfiguration_t";}
		using parent_t = EN_DC_ResourceConfiguration;

	};
	en_DC_ResourceConfiguration_t& ref_en_DC_ResourceConfiguration() {return en_DC_ResourceConfiguration;}
	en_DC_ResourceConfiguration_t const& ref_en_DC_ResourceConfiguration() const {return en_DC_ResourceConfiguration;}
	struct resource_configuration_t : asn::choice<2, 0, true>
	{
		static constexpr const char* name() {return "resource_configuration_t";}
		using parent_t = asn::choice<2, 0, true>;
		index_type get_index() const {return index;}
		bool is_unknown() const {return index == 3;}
		void set_unknown() { set_index(3);  }
		~resource_configuration_t() {clear();}
		struct sgNBPDCPpresent_t : E_RABs_AdmittedToBeModified_SgNBModConf_Item_SgNBPDCPpresent
		{
			static constexpr const char* name() {return "sgNBPDCPpresent_t";}
			using parent_t = E_RABs_AdmittedToBeModified_SgNBModConf_Item_SgNBPDCPpresent;

		};
		struct sgNBPDCPnotpresent_t : E_RABs_AdmittedToBeModified_SgNBModConf_Item_SgNBPDCPnotpresent
		{
			static constexpr const char* name() {return "sgNBPDCPnotpresent_t";}
			using parent_t = E_RABs_AdmittedToBeModified_SgNBModConf_Item_SgNBPDCPnotpresent;

		};
		void clear()
		{
			switch(get_index())
			{
			case 1: var.destroy<sgNBPDCPpresent_t>(); break;
			case 2: var.destroy<sgNBPDCPnotpresent_t>(); break;
			}
			index = 0;
			base::clear();
		}
		template<typename V> bool decode(size_t idx, V& v)
		{
			clear();
			switch(idx)
			{
			case 1: set_index(1); return v(var.build<sgNBPDCPpresent_t>());
			case 2: set_index(2); return v(var.build<sgNBPDCPnotpresent_t>());
			}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			switch(get_index())
			{
			case 1: return v(var.as<sgNBPDCPpresent_t>());
			case 2: return v(var.as<sgNBPDCPnotpresent_t>());
			}
			return false;
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<sgNBPDCPpresent_t>(1);
			v.template operator()<sgNBPDCPnotpresent_t>(2);

		}
		sgNBPDCPpresent_t& select_sgNBPDCPpresent() { if(get_index() != 1) { clear(); set_index(1); return var.build<sgNBPDCPpresent_t>();} return var.as<sgNBPDCPpresent_t>();}
		sgNBPDCPpresent_t const* get_sgNBPDCPpresent() const { if(get_index() == 1) { return &var.as<sgNBPDCPpresent_t>();} return nullptr; }
		sgNBPDCPnotpresent_t& select_sgNBPDCPnotpresent() { if(get_index() != 2) { clear(); set_index(2); return var.build<sgNBPDCPnotpresent_t>();} return var.as<sgNBPDCPnotpresent_t>();}
		sgNBPDCPnotpresent_t const* get_sgNBPDCPnotpresent() const { if(get_index() == 2) { return &var.as<sgNBPDCPnotpresent_t>();} return nullptr; }
		private:
		void set_index(index_type i) {index = i; base::set();}
		union union_type
		{
			char dummy1[sizeof(sgNBPDCPpresent_t)];
			char dummy2[sizeof(sgNBPDCPnotpresent_t)];

		};
		asn::variant<sizeof(union_type)>	var;
		index_type	index {0};
	};
	resource_configuration_t& ref_resource_configuration() {return resource_configuration;}
	resource_configuration_t const& ref_resource_configuration() const {return resource_configuration;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABs_AdmittedToBeModified_SgNBModConf_ItemExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABs_AdmittedToBeModified_SgNBModConf_ItemExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(e_RAB_ID);
		v(en_DC_ResourceConfiguration);
		v(resource_configuration);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(e_RAB_ID);
		v(en_DC_ResourceConfiguration);
		v(resource_configuration);
		v(iE_Extensions);

	};
	void clear()
	{
		e_RAB_ID.clear();
		en_DC_ResourceConfiguration.clear();
		resource_configuration.clear();
		iE_Extensions.clear();

	};
	private:
	e_RAB_ID_t	e_RAB_ID;
	en_DC_ResourceConfiguration_t	en_DC_ResourceConfiguration;
	resource_configuration_t	resource_configuration;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABs-AdmittedToBeModified-SgNBModConf-ItemIEs X2AP-PROTOCOL-IES ::= {
{ ID id-E-RABs-AdmittedToBeModified-SgNBModConf-Item	 CRITICALITY ignore	TYPE E-RABs-AdmittedToBeModified-SgNBModConf-Item	 PRESENCE mandatory },
	...
}
*/

struct E_RABs_AdmittedToBeModified_SgNBModConf_ItemIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_E_RABs_AdmittedToBeModified_SgNBModConf_Item() { set(id_E_RABs_AdmittedToBeModified_SgNBModConf_Item); type=1;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_E_RABs_AdmittedToBeModified_SgNBModConf_Item)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_E_RABs_AdmittedToBeModified_SgNBModConf_Item);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_E_RABs_AdmittedToBeModified_SgNBModConf_Item() { set(ignore); type=1;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Value_t : asn::typefield<true>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		E_RABs_AdmittedToBeModified_SgNBModConf_Item& select_id_E_RABs_AdmittedToBeModified_SgNBModConf_Item() { return set<E_RABs_AdmittedToBeModified_SgNBModConf_Item>(1); }
		E_RABs_AdmittedToBeModified_SgNBModConf_Item const* get_id_E_RABs_AdmittedToBeModified_SgNBModConf_Item() const { return get<E_RABs_AdmittedToBeModified_SgNBModConf_Item>(1); }
		bool is_unknown() const { return type == 2; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<E_RABs_AdmittedToBeModified_SgNBModConf_Item>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<E_RABs_AdmittedToBeModified_SgNBModConf_Item>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_E_RABs_AdmittedToBeModified_SgNBModConf_Item()); return true;
			case 2: if(type != 2) {clear(); asn::base::set();} type = 2; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<E_RABs_AdmittedToBeModified_SgNBModConf_Item>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(E_RABs_AdmittedToBeModified_SgNBModConf_Item)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_E_RABs_AdmittedToBeModified_SgNBModConf_Item() { set(mandatory); type=1;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-AdmittedToBeModified-SgNBModConfList ::= SEQUENCE (SIZE (1..maxnoofBearers)) OF ProtocolIE-Single-Container
	{ {E-RABs-AdmittedToBeModified-SgNBModConf-ItemIEs} }
*/

struct E_RABs_AdmittedToBeModified_SgNBModConfList_elm : ProtocolIE_Single_Container<E_RABs_AdmittedToBeModified_SgNBModConf_ItemIEs>
{
	static constexpr const char* name() {return "E_RABs_AdmittedToBeModified_SgNBModConfList_elm";}
	using parent_t = ProtocolIE_Single_Container<E_RABs_AdmittedToBeModified_SgNBModConf_ItemIEs>;

};
struct E_RABs_AdmittedToBeModified_SgNBModConfList : asn::sequenceof<E_RABs_AdmittedToBeModified_SgNBModConfList_elm>
{
	static constexpr const char* name() {return "E-RABs-AdmittedToBeModified-SgNBModConfList";}
	using parent_t = asn::sequenceof<E_RABs_AdmittedToBeModified_SgNBModConfList_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofBearers >>;

};
/*
E-RABs-SubjectToCounterCheckItemExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct E_RABs_SubjectToCounterCheckItemExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-SubjectToCounterCheckItem ::= SEQUENCE {
	e-RAB-ID						E-RAB-ID,
	uL-Count						INTEGER (0..4294967295),
	dL-Count						INTEGER (0..4294967295),
	iE-Extensions					ProtocolExtensionContainer { {E-RABs-SubjectToCounterCheckItemExtIEs} } OPTIONAL,
	...
}
*/

struct E_RABs_SubjectToCounterCheckItem : asn::sequence<4, 0, true, 1>
{
	static constexpr const char* name() {return "E-RABs-SubjectToCounterCheckItem";}
	using parent_t = asn::sequence<4, 0, true, 1>;
	struct e_RAB_ID_t : E_RAB_ID
	{
		static constexpr const char* name() {return "e_RAB_ID_t";}
		using parent_t = E_RAB_ID;

	};
	e_RAB_ID_t& ref_e_RAB_ID() {return e_RAB_ID;}
	e_RAB_ID_t const& ref_e_RAB_ID() const {return e_RAB_ID;}
	struct uL_Count_t : asn::integer<>
	{
		using constraint_t = asn::constraints<false,asn::span<0, 4294967295>>;
		static constexpr const char* name() {return "uL_Count_t";}
		using parent_t = asn::integer<>;

	};

	uL_Count_t& ref_uL_Count() {return uL_Count;}
	uL_Count_t const& ref_uL_Count() const {return uL_Count;}
	struct dL_Count_t : asn::integer<>
	{
		using constraint_t = asn::constraints<false,asn::span<0, 4294967295>>;
		static constexpr const char* name() {return "dL_Count_t";}
		using parent_t = asn::integer<>;

	};

	dL_Count_t& ref_dL_Count() {return dL_Count;}
	dL_Count_t const& ref_dL_Count() const {return dL_Count;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABs_SubjectToCounterCheckItemExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABs_SubjectToCounterCheckItemExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(e_RAB_ID);
		v(uL_Count);
		v(dL_Count);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(e_RAB_ID);
		v(uL_Count);
		v(dL_Count);
		v(iE_Extensions);

	};
	void clear()
	{
		e_RAB_ID.clear();
		uL_Count.clear();
		dL_Count.clear();
		iE_Extensions.clear();

	};
	private:
	e_RAB_ID_t	e_RAB_ID;
	uL_Count_t	uL_Count;
	dL_Count_t	dL_Count;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABs-SubjectToCounterCheckItemIEs X2AP-PROTOCOL-IES ::= {
	{ ID id-E-RABs-SubjectToCounterCheckItem	CRITICALITY ignore	TYPE E-RABs-SubjectToCounterCheckItem		PRESENCE mandatory},
	...
}
*/

struct E_RABs_SubjectToCounterCheckItemIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_E_RABs_SubjectToCounterCheckItem() { set(id_E_RABs_SubjectToCounterCheckItem); type=1;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_E_RABs_SubjectToCounterCheckItem)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_E_RABs_SubjectToCounterCheckItem);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_E_RABs_SubjectToCounterCheckItem() { set(ignore); type=1;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Value_t : asn::typefield<true>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		E_RABs_SubjectToCounterCheckItem& select_id_E_RABs_SubjectToCounterCheckItem() { return set<E_RABs_SubjectToCounterCheckItem>(1); }
		E_RABs_SubjectToCounterCheckItem const* get_id_E_RABs_SubjectToCounterCheckItem() const { return get<E_RABs_SubjectToCounterCheckItem>(1); }
		bool is_unknown() const { return type == 2; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<E_RABs_SubjectToCounterCheckItem>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<E_RABs_SubjectToCounterCheckItem>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_E_RABs_SubjectToCounterCheckItem()); return true;
			case 2: if(type != 2) {clear(); asn::base::set();} type = 2; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<E_RABs_SubjectToCounterCheckItem>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(E_RABs_SubjectToCounterCheckItem)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_E_RABs_SubjectToCounterCheckItem() { set(mandatory); type=1;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-SubjectToCounterCheck-List ::= SEQUENCE (SIZE(1..maxnoofBearers)) OF ProtocolIE-Single-Container { {E-RABs-SubjectToCounterCheckItemIEs} }
*/

struct E_RABs_SubjectToCounterCheck_List_elm : ProtocolIE_Single_Container<E_RABs_SubjectToCounterCheckItemIEs>
{
	static constexpr const char* name() {return "E_RABs_SubjectToCounterCheck_List_elm";}
	using parent_t = ProtocolIE_Single_Container<E_RABs_SubjectToCounterCheckItemIEs>;

};
struct E_RABs_SubjectToCounterCheck_List : asn::sequenceof<E_RABs_SubjectToCounterCheck_List_elm>
{
	static constexpr const char* name() {return "E-RABs-SubjectToCounterCheck-List";}
	using parent_t = asn::sequenceof<E_RABs_SubjectToCounterCheck_List_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofBearers >>;

};
/*
E-RABs-SubjectToSgNBCounterCheck-ItemExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct E_RABs_SubjectToSgNBCounterCheck_ItemExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-SubjectToSgNBCounterCheck-Item ::= SEQUENCE {
	e-RAB-ID						E-RAB-ID,
	uL-Count						INTEGER (0..4294967295),
	dL-Count						INTEGER (0..4294967295),
	iE-Extensions					ProtocolExtensionContainer { {E-RABs-SubjectToSgNBCounterCheck-ItemExtIEs} } OPTIONAL,
	...
}
*/

struct E_RABs_SubjectToSgNBCounterCheck_Item : asn::sequence<4, 0, true, 1>
{
	static constexpr const char* name() {return "E-RABs-SubjectToSgNBCounterCheck-Item";}
	using parent_t = asn::sequence<4, 0, true, 1>;
	struct e_RAB_ID_t : E_RAB_ID
	{
		static constexpr const char* name() {return "e_RAB_ID_t";}
		using parent_t = E_RAB_ID;

	};
	e_RAB_ID_t& ref_e_RAB_ID() {return e_RAB_ID;}
	e_RAB_ID_t const& ref_e_RAB_ID() const {return e_RAB_ID;}
	struct uL_Count_t : asn::integer<>
	{
		using constraint_t = asn::constraints<false,asn::span<0, 4294967295>>;
		static constexpr const char* name() {return "uL_Count_t";}
		using parent_t = asn::integer<>;

	};

	uL_Count_t& ref_uL_Count() {return uL_Count;}
	uL_Count_t const& ref_uL_Count() const {return uL_Count;}
	struct dL_Count_t : asn::integer<>
	{
		using constraint_t = asn::constraints<false,asn::span<0, 4294967295>>;
		static constexpr const char* name() {return "dL_Count_t";}
		using parent_t = asn::integer<>;

	};

	dL_Count_t& ref_dL_Count() {return dL_Count;}
	dL_Count_t const& ref_dL_Count() const {return dL_Count;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABs_SubjectToSgNBCounterCheck_ItemExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABs_SubjectToSgNBCounterCheck_ItemExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(e_RAB_ID);
		v(uL_Count);
		v(dL_Count);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(e_RAB_ID);
		v(uL_Count);
		v(dL_Count);
		v(iE_Extensions);

	};
	void clear()
	{
		e_RAB_ID.clear();
		uL_Count.clear();
		dL_Count.clear();
		iE_Extensions.clear();

	};
	private:
	e_RAB_ID_t	e_RAB_ID;
	uL_Count_t	uL_Count;
	dL_Count_t	dL_Count;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABs-SubjectToSgNBCounterCheck-ItemIEs X2AP-PROTOCOL-IES ::= {
	{ ID id-E-RABs-SubjectToSgNBCounterCheck-Item		CRITICALITY ignore	TYPE E-RABs-SubjectToSgNBCounterCheck-Item		PRESENCE mandatory},
	...
}
*/

struct E_RABs_SubjectToSgNBCounterCheck_ItemIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_E_RABs_SubjectToSgNBCounterCheck_Item() { set(id_E_RABs_SubjectToSgNBCounterCheck_Item); type=1;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_E_RABs_SubjectToSgNBCounterCheck_Item)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_E_RABs_SubjectToSgNBCounterCheck_Item);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_E_RABs_SubjectToSgNBCounterCheck_Item() { set(ignore); type=1;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Value_t : asn::typefield<true>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		E_RABs_SubjectToSgNBCounterCheck_Item& select_id_E_RABs_SubjectToSgNBCounterCheck_Item() { return set<E_RABs_SubjectToSgNBCounterCheck_Item>(1); }
		E_RABs_SubjectToSgNBCounterCheck_Item const* get_id_E_RABs_SubjectToSgNBCounterCheck_Item() const { return get<E_RABs_SubjectToSgNBCounterCheck_Item>(1); }
		bool is_unknown() const { return type == 2; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<E_RABs_SubjectToSgNBCounterCheck_Item>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<E_RABs_SubjectToSgNBCounterCheck_Item>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_E_RABs_SubjectToSgNBCounterCheck_Item()); return true;
			case 2: if(type != 2) {clear(); asn::base::set();} type = 2; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<E_RABs_SubjectToSgNBCounterCheck_Item>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(E_RABs_SubjectToSgNBCounterCheck_Item)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_E_RABs_SubjectToSgNBCounterCheck_Item() { set(mandatory); type=1;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-SubjectToSgNBCounterCheck-List ::= SEQUENCE (SIZE(1..maxnoofBearers)) OF ProtocolIE-Single-Container { {E-RABs-SubjectToSgNBCounterCheck-ItemIEs} }
*/

struct E_RABs_SubjectToSgNBCounterCheck_List_elm : ProtocolIE_Single_Container<E_RABs_SubjectToSgNBCounterCheck_ItemIEs>
{
	static constexpr const char* name() {return "E_RABs_SubjectToSgNBCounterCheck_List_elm";}
	using parent_t = ProtocolIE_Single_Container<E_RABs_SubjectToSgNBCounterCheck_ItemIEs>;

};
struct E_RABs_SubjectToSgNBCounterCheck_List : asn::sequenceof<E_RABs_SubjectToSgNBCounterCheck_List_elm>
{
	static constexpr const char* name() {return "E-RABs-SubjectToSgNBCounterCheck-List";}
	using parent_t = asn::sequenceof<E_RABs_SubjectToSgNBCounterCheck_List_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofBearers >>;

};
/*
E-RABs-SubjectToStatusTransfer-ItemExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	{ ID id-ReceiveStatusOfULPDCPSDUsExtended			CRITICALITY ignore	EXTENSION ReceiveStatusOfULPDCPSDUsExtended			PRESENCE optional}|
	{ ID id-ULCOUNTValueExtended						CRITICALITY ignore	EXTENSION COUNTValueExtended								PRESENCE optional}|
	{ ID id-DLCOUNTValueExtended						CRITICALITY ignore	EXTENSION COUNTValueExtended								PRESENCE optional}|
	{ ID id-ReceiveStatusOfULPDCPSDUsPDCP-SNlength18	CRITICALITY ignore	EXTENSION ReceiveStatusOfULPDCPSDUsPDCP-SNlength18	PRESENCE optional}|
	{ ID id-ULCOUNTValuePDCP-SNlength18					CRITICALITY ignore	EXTENSION COUNTvaluePDCP-SNlength18						PRESENCE optional}|
	{ ID id-DLCOUNTValuePDCP-SNlength18					CRITICALITY ignore	EXTENSION COUNTvaluePDCP-SNlength18						PRESENCE optional},
	...
}
*/

struct E_RABs_SubjectToStatusTransfer_ItemExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 7; }
		void clear() {type = 0;}
		void select_id_ReceiveStatusOfULPDCPSDUsExtended() { set(id_ReceiveStatusOfULPDCPSDUsExtended); type=1;}
		void select_id_ULCOUNTValueExtended() { set(id_ULCOUNTValueExtended); type=2;}
		void select_id_DLCOUNTValueExtended() { set(id_DLCOUNTValueExtended); type=3;}
		void select_id_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18() { set(id_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18); type=4;}
		void select_id_ULCOUNTValuePDCP_SNlength18() { set(id_ULCOUNTValuePDCP_SNlength18); type=5;}
		void select_id_DLCOUNTValuePDCP_SNlength18() { set(id_DLCOUNTValuePDCP_SNlength18); type=6;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_ReceiveStatusOfULPDCPSDUsExtended)) { type = 1; return true; }
			else if(equal(id_ULCOUNTValueExtended)) { type = 2; return true; }
			else if(equal(id_DLCOUNTValueExtended)) { type = 3; return true; }
			else if(equal(id_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18)) { type = 4; return true; }
			else if(equal(id_ULCOUNTValuePDCP_SNlength18)) { type = 5; return true; }
			else if(equal(id_DLCOUNTValuePDCP_SNlength18)) { type = 6; return true; }
			else { type = 7; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_ReceiveStatusOfULPDCPSDUsExtended);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_ULCOUNTValueExtended);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(id_DLCOUNTValueExtended);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(id_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18);} return false;
			case 5: type = 5; if(v(ref_nested())) { return equal(id_ULCOUNTValuePDCP_SNlength18);} return false;
			case 6: type = 6; if(v(ref_nested())) { return equal(id_DLCOUNTValuePDCP_SNlength18);} return false;
			case 7: type = 7; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 7; }
		void clear() {type = 0;}
		void select_id_ReceiveStatusOfULPDCPSDUsExtended() { set(ignore); type=1;}
		void select_id_ULCOUNTValueExtended() { set(ignore); type=2;}
		void select_id_DLCOUNTValueExtended() { set(ignore); type=3;}
		void select_id_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18() { set(ignore); type=4;}
		void select_id_ULCOUNTValuePDCP_SNlength18() { set(ignore); type=5;}
		void select_id_DLCOUNTValuePDCP_SNlength18() { set(ignore); type=6;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else if(equal(ignore)) { type = 2; return true; }
			else if(equal(ignore)) { type = 3; return true; }
			else if(equal(ignore)) { type = 4; return true; }
			else if(equal(ignore)) { type = 5; return true; }
			else if(equal(ignore)) { type = 6; return true; }
			else { type = 7; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(ignore);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(ignore);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(ignore);} return false;
			case 5: type = 5; if(v(ref_nested())) { return equal(ignore);} return false;
			case 6: type = 6; if(v(ref_nested())) { return equal(ignore);} return false;
			case 7: type = 7; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		ReceiveStatusOfULPDCPSDUsExtended& select_id_ReceiveStatusOfULPDCPSDUsExtended() { return set<ReceiveStatusOfULPDCPSDUsExtended>(1); }
		ReceiveStatusOfULPDCPSDUsExtended const* get_id_ReceiveStatusOfULPDCPSDUsExtended() const { return get<ReceiveStatusOfULPDCPSDUsExtended>(1); }
		COUNTValueExtended& select_id_ULCOUNTValueExtended() { return set<COUNTValueExtended>(2); }
		COUNTValueExtended const* get_id_ULCOUNTValueExtended() const { return get<COUNTValueExtended>(2); }
		COUNTValueExtended& select_id_DLCOUNTValueExtended() { return set<COUNTValueExtended>(3); }
		COUNTValueExtended const* get_id_DLCOUNTValueExtended() const { return get<COUNTValueExtended>(3); }
		ReceiveStatusOfULPDCPSDUsPDCP_SNlength18& select_id_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18() { return set<ReceiveStatusOfULPDCPSDUsPDCP_SNlength18>(4); }
		ReceiveStatusOfULPDCPSDUsPDCP_SNlength18 const* get_id_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18() const { return get<ReceiveStatusOfULPDCPSDUsPDCP_SNlength18>(4); }
		COUNTvaluePDCP_SNlength18& select_id_ULCOUNTValuePDCP_SNlength18() { return set<COUNTvaluePDCP_SNlength18>(5); }
		COUNTvaluePDCP_SNlength18 const* get_id_ULCOUNTValuePDCP_SNlength18() const { return get<COUNTvaluePDCP_SNlength18>(5); }
		COUNTvaluePDCP_SNlength18& select_id_DLCOUNTValuePDCP_SNlength18() { return set<COUNTvaluePDCP_SNlength18>(6); }
		COUNTvaluePDCP_SNlength18 const* get_id_DLCOUNTValuePDCP_SNlength18() const { return get<COUNTvaluePDCP_SNlength18>(6); }
		bool is_unknown() const { return type == 7; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<ReceiveStatusOfULPDCPSDUsExtended>(); break;
			case 2: var.destroy<COUNTValueExtended>(); break;
			case 3: var.destroy<COUNTValueExtended>(); break;
			case 4: var.destroy<ReceiveStatusOfULPDCPSDUsPDCP_SNlength18>(); break;
			case 5: var.destroy<COUNTvaluePDCP_SNlength18>(); break;
			case 6: var.destroy<COUNTvaluePDCP_SNlength18>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<ReceiveStatusOfULPDCPSDUsExtended>(1);
			v.template operator()<COUNTValueExtended>(2);
			v.template operator()<COUNTValueExtended>(3);
			v.template operator()<ReceiveStatusOfULPDCPSDUsPDCP_SNlength18>(4);
			v.template operator()<COUNTvaluePDCP_SNlength18>(5);
			v.template operator()<COUNTvaluePDCP_SNlength18>(6);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_ReceiveStatusOfULPDCPSDUsExtended()); return true;
			case 2: v(select_id_ULCOUNTValueExtended()); return true;
			case 3: v(select_id_DLCOUNTValueExtended()); return true;
			case 4: v(select_id_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18()); return true;
			case 5: v(select_id_ULCOUNTValuePDCP_SNlength18()); return true;
			case 6: v(select_id_DLCOUNTValuePDCP_SNlength18()); return true;
			case 7: if(type != 7) {clear(); asn::base::set();} type = 7; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<ReceiveStatusOfULPDCPSDUsExtended>()); return true;
			case 2: v(var.as<COUNTValueExtended>()); return true;
			case 3: v(var.as<COUNTValueExtended>()); return true;
			case 4: v(var.as<ReceiveStatusOfULPDCPSDUsPDCP_SNlength18>()); return true;
			case 5: v(var.as<COUNTvaluePDCP_SNlength18>()); return true;
			case 6: v(var.as<COUNTvaluePDCP_SNlength18>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(COUNTValueExtended)];
			char dummy2[sizeof(COUNTvaluePDCP_SNlength18)];
			char dummy3[sizeof(ReceiveStatusOfULPDCPSDUsExtended)];
			char dummy4[sizeof(ReceiveStatusOfULPDCPSDUsPDCP_SNlength18)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 7; }
		void clear() {type = 0;}
		void select_id_ReceiveStatusOfULPDCPSDUsExtended() { set(optional); type=1;}
		void select_id_ULCOUNTValueExtended() { set(optional); type=2;}
		void select_id_DLCOUNTValueExtended() { set(optional); type=3;}
		void select_id_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18() { set(optional); type=4;}
		void select_id_ULCOUNTValuePDCP_SNlength18() { set(optional); type=5;}
		void select_id_DLCOUNTValuePDCP_SNlength18() { set(optional); type=6;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(optional)) { type = 1; return true; }
			else if(equal(optional)) { type = 2; return true; }
			else if(equal(optional)) { type = 3; return true; }
			else if(equal(optional)) { type = 4; return true; }
			else if(equal(optional)) { type = 5; return true; }
			else if(equal(optional)) { type = 6; return true; }
			else { type = 7; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(optional);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(optional);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(optional);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(optional);} return false;
			case 5: type = 5; if(v(ref_nested())) { return equal(optional);} return false;
			case 6: type = 6; if(v(ref_nested())) { return equal(optional);} return false;
			case 7: type = 7; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-SubjectToStatusTransfer-Item ::= SEQUENCE {
	e-RAB-ID								E-RAB-ID,

	receiveStatusofULPDCPSDUs				ReceiveStatusofULPDCPSDUs			OPTIONAL,
	uL-COUNTvalue					COUNTvalue,
	dL-COUNTvalue					COUNTvalue,
	iE-Extensions							ProtocolExtensionContainer { {E-RABs-SubjectToStatusTransfer-ItemExtIEs} } OPTIONAL,
	...
}
*/

struct E_RABs_SubjectToStatusTransfer_Item : asn::sequence<5, 0, true, 2>
{
	static constexpr const char* name() {return "E-RABs-SubjectToStatusTransfer-Item";}
	using parent_t = asn::sequence<5, 0, true, 2>;
	struct e_RAB_ID_t : E_RAB_ID
	{
		static constexpr const char* name() {return "e_RAB_ID_t";}
		using parent_t = E_RAB_ID;

	};
	e_RAB_ID_t& ref_e_RAB_ID() {return e_RAB_ID;}
	e_RAB_ID_t const& ref_e_RAB_ID() const {return e_RAB_ID;}
	struct receiveStatusofULPDCPSDUs_t : ReceiveStatusofULPDCPSDUs
	{
		static constexpr const char* name() {return "receiveStatusofULPDCPSDUs_t";}
		using parent_t = ReceiveStatusofULPDCPSDUs;
		static constexpr bool optional = true;

	};
	receiveStatusofULPDCPSDUs_t& set_receiveStatusofULPDCPSDUs() { receiveStatusofULPDCPSDUs.setpresent(true); return receiveStatusofULPDCPSDUs;}
	receiveStatusofULPDCPSDUs_t const* get_receiveStatusofULPDCPSDUs() const {return receiveStatusofULPDCPSDUs.is_valid() ? &receiveStatusofULPDCPSDUs : nullptr;}
	struct uL_COUNTvalue_t : COUNTvalue
	{
		static constexpr const char* name() {return "uL_COUNTvalue_t";}
		using parent_t = COUNTvalue;

	};
	uL_COUNTvalue_t& ref_uL_COUNTvalue() {return uL_COUNTvalue;}
	uL_COUNTvalue_t const& ref_uL_COUNTvalue() const {return uL_COUNTvalue;}
	struct dL_COUNTvalue_t : COUNTvalue
	{
		static constexpr const char* name() {return "dL_COUNTvalue_t";}
		using parent_t = COUNTvalue;

	};
	dL_COUNTvalue_t& ref_dL_COUNTvalue() {return dL_COUNTvalue;}
	dL_COUNTvalue_t const& ref_dL_COUNTvalue() const {return dL_COUNTvalue;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABs_SubjectToStatusTransfer_ItemExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABs_SubjectToStatusTransfer_ItemExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(e_RAB_ID);
		v(receiveStatusofULPDCPSDUs);
		v(uL_COUNTvalue);
		v(dL_COUNTvalue);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(e_RAB_ID);
		v(receiveStatusofULPDCPSDUs);
		v(uL_COUNTvalue);
		v(dL_COUNTvalue);
		v(iE_Extensions);

	};
	void clear()
	{
		e_RAB_ID.clear();
		receiveStatusofULPDCPSDUs.clear();
		uL_COUNTvalue.clear();
		dL_COUNTvalue.clear();
		iE_Extensions.clear();

	};
	private:
	e_RAB_ID_t	e_RAB_ID;
	receiveStatusofULPDCPSDUs_t	receiveStatusofULPDCPSDUs;
	uL_COUNTvalue_t	uL_COUNTvalue;
	dL_COUNTvalue_t	dL_COUNTvalue;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABs-SubjectToStatusTransfer-ItemIEs X2AP-PROTOCOL-IES ::= {
	{ ID id-E-RABs-SubjectToStatusTransfer-Item	CRITICALITY ignore	TYPE E-RABs-SubjectToStatusTransfer-Item 	PRESENCE mandatory	}
}
*/

struct E_RABs_SubjectToStatusTransfer_ItemIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_E_RABs_SubjectToStatusTransfer_Item() { set(id_E_RABs_SubjectToStatusTransfer_Item); type=1;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_E_RABs_SubjectToStatusTransfer_Item)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_E_RABs_SubjectToStatusTransfer_Item);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_E_RABs_SubjectToStatusTransfer_Item() { set(ignore); type=1;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Value_t : asn::typefield<false>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		E_RABs_SubjectToStatusTransfer_Item& select_id_E_RABs_SubjectToStatusTransfer_Item() { return set<E_RABs_SubjectToStatusTransfer_Item>(1); }
		E_RABs_SubjectToStatusTransfer_Item const* get_id_E_RABs_SubjectToStatusTransfer_Item() const { return get<E_RABs_SubjectToStatusTransfer_Item>(1); }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<E_RABs_SubjectToStatusTransfer_Item>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<E_RABs_SubjectToStatusTransfer_Item>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_E_RABs_SubjectToStatusTransfer_Item()); return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<E_RABs_SubjectToStatusTransfer_Item>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(E_RABs_SubjectToStatusTransfer_Item)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, false>
	{
		size_t get_index() const {return type;}
		void clear() {type = 0;}
		void select_id_E_RABs_SubjectToStatusTransfer_Item() { set(mandatory); type=1;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-SubjectToStatusTransfer-List	::= SEQUENCE (SIZE (1..maxnoofBearers)) OF ProtocolIE-Single-Container { {E-RABs-SubjectToStatusTransfer-ItemIEs} }
*/

struct E_RABs_SubjectToStatusTransfer_List_elm : ProtocolIE_Single_Container<E_RABs_SubjectToStatusTransfer_ItemIEs>
{
	static constexpr const char* name() {return "E_RABs_SubjectToStatusTransfer_List_elm";}
	using parent_t = ProtocolIE_Single_Container<E_RABs_SubjectToStatusTransfer_ItemIEs>;

};
struct E_RABs_SubjectToStatusTransfer_List : asn::sequenceof<E_RABs_SubjectToStatusTransfer_List_elm>
{
	static constexpr const char* name() {return "E-RABs-SubjectToStatusTransfer-List";}
	using parent_t = asn::sequenceof<E_RABs_SubjectToStatusTransfer_List_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofBearers >>;

};
/*
E-RABs-ToBeAdded-Item-SCG-BearerExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	{ ID id-Correlation-ID				CRITICALITY ignore	EXTENSION Correlation-ID		PRESENCE optional}|
	{ ID id-SIPTO-Correlation-ID		CRITICALITY ignore	EXTENSION Correlation-ID		PRESENCE optional},
	...
}
*/

struct E_RABs_ToBeAdded_Item_SCG_BearerExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_Correlation_ID() { set(id_Correlation_ID); type=1;}
		void select_id_SIPTO_Correlation_ID() { set(id_SIPTO_Correlation_ID); type=2;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_Correlation_ID)) { type = 1; return true; }
			else if(equal(id_SIPTO_Correlation_ID)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_Correlation_ID);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_SIPTO_Correlation_ID);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_Correlation_ID() { set(ignore); type=1;}
		void select_id_SIPTO_Correlation_ID() { set(ignore); type=2;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else if(equal(ignore)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(ignore);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		Correlation_ID& select_id_Correlation_ID() { return set<Correlation_ID>(1); }
		Correlation_ID const* get_id_Correlation_ID() const { return get<Correlation_ID>(1); }
		Correlation_ID& select_id_SIPTO_Correlation_ID() { return set<Correlation_ID>(2); }
		Correlation_ID const* get_id_SIPTO_Correlation_ID() const { return get<Correlation_ID>(2); }
		bool is_unknown() const { return type == 3; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<Correlation_ID>(); break;
			case 2: var.destroy<Correlation_ID>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<Correlation_ID>(1);
			v.template operator()<Correlation_ID>(2);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_Correlation_ID()); return true;
			case 2: v(select_id_SIPTO_Correlation_ID()); return true;
			case 3: if(type != 3) {clear(); asn::base::set();} type = 3; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<Correlation_ID>()); return true;
			case 2: v(var.as<Correlation_ID>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(Correlation_ID)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_Correlation_ID() { set(optional); type=1;}
		void select_id_SIPTO_Correlation_ID() { set(optional); type=2;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(optional)) { type = 1; return true; }
			else if(equal(optional)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(optional);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(optional);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-ToBeAdded-Item-SCG-Bearer ::= SEQUENCE {
	e-RAB-ID						E-RAB-ID,
	e-RAB-Level-QoS-Parameters		E-RAB-Level-QoS-Parameters,
	dL-Forwarding					DL-Forwarding																	OPTIONAL,
	s1-UL-GTPtunnelEndpoint			GTPtunnelEndpoint,
	iE-Extensions					ProtocolExtensionContainer { {E-RABs-ToBeAdded-Item-SCG-BearerExtIEs} }	OPTIONAL,
	...
}
*/

struct E_RABs_ToBeAdded_Item_SCG_Bearer : asn::sequence<5, 0, true, 2>
{
	static constexpr const char* name() {return "E-RABs-ToBeAdded-Item-SCG-Bearer";}
	using parent_t = asn::sequence<5, 0, true, 2>;
	struct e_RAB_ID_t : E_RAB_ID
	{
		static constexpr const char* name() {return "e_RAB_ID_t";}
		using parent_t = E_RAB_ID;

	};
	e_RAB_ID_t& ref_e_RAB_ID() {return e_RAB_ID;}
	e_RAB_ID_t const& ref_e_RAB_ID() const {return e_RAB_ID;}
	struct e_RAB_Level_QoS_Parameters_t : E_RAB_Level_QoS_Parameters
	{
		static constexpr const char* name() {return "e_RAB_Level_QoS_Parameters_t";}
		using parent_t = E_RAB_Level_QoS_Parameters;

	};
	e_RAB_Level_QoS_Parameters_t& ref_e_RAB_Level_QoS_Parameters() {return e_RAB_Level_QoS_Parameters;}
	e_RAB_Level_QoS_Parameters_t const& ref_e_RAB_Level_QoS_Parameters() const {return e_RAB_Level_QoS_Parameters;}
	struct dL_Forwarding_t : DL_Forwarding
	{
		static constexpr const char* name() {return "dL_Forwarding_t";}
		using parent_t = DL_Forwarding;
		static constexpr bool optional = true;

	};
	dL_Forwarding_t& set_dL_Forwarding() { dL_Forwarding.setpresent(true); return dL_Forwarding;}
	dL_Forwarding_t const* get_dL_Forwarding() const {return dL_Forwarding.is_valid() ? &dL_Forwarding : nullptr;}
	struct s1_UL_GTPtunnelEndpoint_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "s1_UL_GTPtunnelEndpoint_t";}
		using parent_t = GTPtunnelEndpoint;

	};
	s1_UL_GTPtunnelEndpoint_t& ref_s1_UL_GTPtunnelEndpoint() {return s1_UL_GTPtunnelEndpoint;}
	s1_UL_GTPtunnelEndpoint_t const& ref_s1_UL_GTPtunnelEndpoint() const {return s1_UL_GTPtunnelEndpoint;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABs_ToBeAdded_Item_SCG_BearerExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABs_ToBeAdded_Item_SCG_BearerExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(e_RAB_ID);
		v(e_RAB_Level_QoS_Parameters);
		v(dL_Forwarding);
		v(s1_UL_GTPtunnelEndpoint);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(e_RAB_ID);
		v(e_RAB_Level_QoS_Parameters);
		v(dL_Forwarding);
		v(s1_UL_GTPtunnelEndpoint);
		v(iE_Extensions);

	};
	void clear()
	{
		e_RAB_ID.clear();
		e_RAB_Level_QoS_Parameters.clear();
		dL_Forwarding.clear();
		s1_UL_GTPtunnelEndpoint.clear();
		iE_Extensions.clear();

	};
	private:
	e_RAB_ID_t	e_RAB_ID;
	e_RAB_Level_QoS_Parameters_t	e_RAB_Level_QoS_Parameters;
	dL_Forwarding_t	dL_Forwarding;
	s1_UL_GTPtunnelEndpoint_t	s1_UL_GTPtunnelEndpoint;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABs-ToBeAdded-Item-Split-BearerExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct E_RABs_ToBeAdded_Item_Split_BearerExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-ToBeAdded-Item-Split-Bearer ::= SEQUENCE {
	e-RAB-ID						E-RAB-ID,
	e-RAB-Level-QoS-Parameters		E-RAB-Level-QoS-Parameters,
	meNB-GTPtunnelEndpoint			GTPtunnelEndpoint,
	iE-Extensions					ProtocolExtensionContainer { {E-RABs-ToBeAdded-Item-Split-BearerExtIEs} } OPTIONAL,
	...
}
*/

struct E_RABs_ToBeAdded_Item_Split_Bearer : asn::sequence<4, 0, true, 1>
{
	static constexpr const char* name() {return "E-RABs-ToBeAdded-Item-Split-Bearer";}
	using parent_t = asn::sequence<4, 0, true, 1>;
	struct e_RAB_ID_t : E_RAB_ID
	{
		static constexpr const char* name() {return "e_RAB_ID_t";}
		using parent_t = E_RAB_ID;

	};
	e_RAB_ID_t& ref_e_RAB_ID() {return e_RAB_ID;}
	e_RAB_ID_t const& ref_e_RAB_ID() const {return e_RAB_ID;}
	struct e_RAB_Level_QoS_Parameters_t : E_RAB_Level_QoS_Parameters
	{
		static constexpr const char* name() {return "e_RAB_Level_QoS_Parameters_t";}
		using parent_t = E_RAB_Level_QoS_Parameters;

	};
	e_RAB_Level_QoS_Parameters_t& ref_e_RAB_Level_QoS_Parameters() {return e_RAB_Level_QoS_Parameters;}
	e_RAB_Level_QoS_Parameters_t const& ref_e_RAB_Level_QoS_Parameters() const {return e_RAB_Level_QoS_Parameters;}
	struct meNB_GTPtunnelEndpoint_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "meNB_GTPtunnelEndpoint_t";}
		using parent_t = GTPtunnelEndpoint;

	};
	meNB_GTPtunnelEndpoint_t& ref_meNB_GTPtunnelEndpoint() {return meNB_GTPtunnelEndpoint;}
	meNB_GTPtunnelEndpoint_t const& ref_meNB_GTPtunnelEndpoint() const {return meNB_GTPtunnelEndpoint;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABs_ToBeAdded_Item_Split_BearerExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABs_ToBeAdded_Item_Split_BearerExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(e_RAB_ID);
		v(e_RAB_Level_QoS_Parameters);
		v(meNB_GTPtunnelEndpoint);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(e_RAB_ID);
		v(e_RAB_Level_QoS_Parameters);
		v(meNB_GTPtunnelEndpoint);
		v(iE_Extensions);

	};
	void clear()
	{
		e_RAB_ID.clear();
		e_RAB_Level_QoS_Parameters.clear();
		meNB_GTPtunnelEndpoint.clear();
		iE_Extensions.clear();

	};
	private:
	e_RAB_ID_t	e_RAB_ID;
	e_RAB_Level_QoS_Parameters_t	e_RAB_Level_QoS_Parameters;
	meNB_GTPtunnelEndpoint_t	meNB_GTPtunnelEndpoint;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABs-ToBeAdded-Item ::= CHOICE {
	sCG-Bearer		E-RABs-ToBeAdded-Item-SCG-Bearer,
	split-Bearer	E-RABs-ToBeAdded-Item-Split-Bearer,
	...
}
*/

struct E_RABs_ToBeAdded_Item : asn::choice<2, 0, true>
{
	static constexpr const char* name() {return "E-RABs-ToBeAdded-Item";}
	using parent_t = asn::choice<2, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 3;}
	void set_unknown() { set_index(3);  }
	~E_RABs_ToBeAdded_Item() {clear();}
	struct sCG_Bearer_t : E_RABs_ToBeAdded_Item_SCG_Bearer
	{
		static constexpr const char* name() {return "sCG_Bearer_t";}
		using parent_t = E_RABs_ToBeAdded_Item_SCG_Bearer;

	};
	struct split_Bearer_t : E_RABs_ToBeAdded_Item_Split_Bearer
	{
		static constexpr const char* name() {return "split_Bearer_t";}
		using parent_t = E_RABs_ToBeAdded_Item_Split_Bearer;

	};
	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<sCG_Bearer_t>(); break;
		case 2: var.destroy<split_Bearer_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<sCG_Bearer_t>());
		case 2: set_index(2); return v(var.build<split_Bearer_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<sCG_Bearer_t>());
		case 2: return v(var.as<split_Bearer_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<sCG_Bearer_t>(1);
		v.template operator()<split_Bearer_t>(2);

	}
	sCG_Bearer_t& select_sCG_Bearer() { if(get_index() != 1) { clear(); set_index(1); return var.build<sCG_Bearer_t>();} return var.as<sCG_Bearer_t>();}
	sCG_Bearer_t const* get_sCG_Bearer() const { if(get_index() == 1) { return &var.as<sCG_Bearer_t>();} return nullptr; }
	split_Bearer_t& select_split_Bearer() { if(get_index() != 2) { clear(); set_index(2); return var.build<split_Bearer_t>();} return var.as<split_Bearer_t>();}
	split_Bearer_t const* get_split_Bearer() const { if(get_index() == 2) { return &var.as<split_Bearer_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(sCG_Bearer_t)];
		char dummy2[sizeof(split_Bearer_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
E-RABs-ToBeAdded-ItemIEs X2AP-PROTOCOL-IES ::= {
	{ ID id-E-RABs-ToBeAdded-Item	CRITICALITY reject	TYPE E-RABs-ToBeAdded-Item		PRESENCE mandatory},
	...
}
*/

struct E_RABs_ToBeAdded_ItemIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_E_RABs_ToBeAdded_Item() { set(id_E_RABs_ToBeAdded_Item); type=1;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_E_RABs_ToBeAdded_Item)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_E_RABs_ToBeAdded_Item);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_E_RABs_ToBeAdded_Item() { set(reject); type=1;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(reject)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(reject);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Value_t : asn::typefield<true>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		E_RABs_ToBeAdded_Item& select_id_E_RABs_ToBeAdded_Item() { return set<E_RABs_ToBeAdded_Item>(1); }
		E_RABs_ToBeAdded_Item const* get_id_E_RABs_ToBeAdded_Item() const { return get<E_RABs_ToBeAdded_Item>(1); }
		bool is_unknown() const { return type == 2; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<E_RABs_ToBeAdded_Item>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<E_RABs_ToBeAdded_Item>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_E_RABs_ToBeAdded_Item()); return true;
			case 2: if(type != 2) {clear(); asn::base::set();} type = 2; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<E_RABs_ToBeAdded_Item>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(E_RABs_ToBeAdded_Item)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_E_RABs_ToBeAdded_Item() { set(mandatory); type=1;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-ToBeAdded-List ::= SEQUENCE (SIZE(1..maxnoofBearers)) OF ProtocolIE-Single-Container { {E-RABs-ToBeAdded-ItemIEs} }
*/

struct E_RABs_ToBeAdded_List_elm : ProtocolIE_Single_Container<E_RABs_ToBeAdded_ItemIEs>
{
	static constexpr const char* name() {return "E_RABs_ToBeAdded_List_elm";}
	using parent_t = ProtocolIE_Single_Container<E_RABs_ToBeAdded_ItemIEs>;

};
struct E_RABs_ToBeAdded_List : asn::sequenceof<E_RABs_ToBeAdded_List_elm>
{
	static constexpr const char* name() {return "E-RABs-ToBeAdded-List";}
	using parent_t = asn::sequenceof<E_RABs_ToBeAdded_List_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofBearers >>;

};
/*
E-RABs-ToBeAdded-ModReqItem-SCG-BearerExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	{ ID id-Correlation-ID				CRITICALITY ignore	EXTENSION Correlation-ID		PRESENCE optional}|
	{ ID id-SIPTO-Correlation-ID		CRITICALITY ignore	EXTENSION Correlation-ID		PRESENCE optional},
	...
}
*/

struct E_RABs_ToBeAdded_ModReqItem_SCG_BearerExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_Correlation_ID() { set(id_Correlation_ID); type=1;}
		void select_id_SIPTO_Correlation_ID() { set(id_SIPTO_Correlation_ID); type=2;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_Correlation_ID)) { type = 1; return true; }
			else if(equal(id_SIPTO_Correlation_ID)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_Correlation_ID);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_SIPTO_Correlation_ID);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_Correlation_ID() { set(ignore); type=1;}
		void select_id_SIPTO_Correlation_ID() { set(ignore); type=2;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else if(equal(ignore)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(ignore);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		Correlation_ID& select_id_Correlation_ID() { return set<Correlation_ID>(1); }
		Correlation_ID const* get_id_Correlation_ID() const { return get<Correlation_ID>(1); }
		Correlation_ID& select_id_SIPTO_Correlation_ID() { return set<Correlation_ID>(2); }
		Correlation_ID const* get_id_SIPTO_Correlation_ID() const { return get<Correlation_ID>(2); }
		bool is_unknown() const { return type == 3; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<Correlation_ID>(); break;
			case 2: var.destroy<Correlation_ID>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<Correlation_ID>(1);
			v.template operator()<Correlation_ID>(2);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_Correlation_ID()); return true;
			case 2: v(select_id_SIPTO_Correlation_ID()); return true;
			case 3: if(type != 3) {clear(); asn::base::set();} type = 3; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<Correlation_ID>()); return true;
			case 2: v(var.as<Correlation_ID>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(Correlation_ID)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_Correlation_ID() { set(optional); type=1;}
		void select_id_SIPTO_Correlation_ID() { set(optional); type=2;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(optional)) { type = 1; return true; }
			else if(equal(optional)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(optional);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(optional);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-ToBeAdded-ModReqItem-SCG-Bearer ::= SEQUENCE {
	e-RAB-ID						E-RAB-ID,
	e-RAB-Level-QoS-Parameters		E-RAB-Level-QoS-Parameters,
	dL-Forwarding					DL-Forwarding																	OPTIONAL,
	s1-UL-GTPtunnelEndpoint			GTPtunnelEndpoint,
	iE-Extensions					ProtocolExtensionContainer { {E-RABs-ToBeAdded-ModReqItem-SCG-BearerExtIEs} } OPTIONAL,
	...
}
*/

struct E_RABs_ToBeAdded_ModReqItem_SCG_Bearer : asn::sequence<5, 0, true, 2>
{
	static constexpr const char* name() {return "E-RABs-ToBeAdded-ModReqItem-SCG-Bearer";}
	using parent_t = asn::sequence<5, 0, true, 2>;
	struct e_RAB_ID_t : E_RAB_ID
	{
		static constexpr const char* name() {return "e_RAB_ID_t";}
		using parent_t = E_RAB_ID;

	};
	e_RAB_ID_t& ref_e_RAB_ID() {return e_RAB_ID;}
	e_RAB_ID_t const& ref_e_RAB_ID() const {return e_RAB_ID;}
	struct e_RAB_Level_QoS_Parameters_t : E_RAB_Level_QoS_Parameters
	{
		static constexpr const char* name() {return "e_RAB_Level_QoS_Parameters_t";}
		using parent_t = E_RAB_Level_QoS_Parameters;

	};
	e_RAB_Level_QoS_Parameters_t& ref_e_RAB_Level_QoS_Parameters() {return e_RAB_Level_QoS_Parameters;}
	e_RAB_Level_QoS_Parameters_t const& ref_e_RAB_Level_QoS_Parameters() const {return e_RAB_Level_QoS_Parameters;}
	struct dL_Forwarding_t : DL_Forwarding
	{
		static constexpr const char* name() {return "dL_Forwarding_t";}
		using parent_t = DL_Forwarding;
		static constexpr bool optional = true;

	};
	dL_Forwarding_t& set_dL_Forwarding() { dL_Forwarding.setpresent(true); return dL_Forwarding;}
	dL_Forwarding_t const* get_dL_Forwarding() const {return dL_Forwarding.is_valid() ? &dL_Forwarding : nullptr;}
	struct s1_UL_GTPtunnelEndpoint_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "s1_UL_GTPtunnelEndpoint_t";}
		using parent_t = GTPtunnelEndpoint;

	};
	s1_UL_GTPtunnelEndpoint_t& ref_s1_UL_GTPtunnelEndpoint() {return s1_UL_GTPtunnelEndpoint;}
	s1_UL_GTPtunnelEndpoint_t const& ref_s1_UL_GTPtunnelEndpoint() const {return s1_UL_GTPtunnelEndpoint;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABs_ToBeAdded_ModReqItem_SCG_BearerExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABs_ToBeAdded_ModReqItem_SCG_BearerExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(e_RAB_ID);
		v(e_RAB_Level_QoS_Parameters);
		v(dL_Forwarding);
		v(s1_UL_GTPtunnelEndpoint);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(e_RAB_ID);
		v(e_RAB_Level_QoS_Parameters);
		v(dL_Forwarding);
		v(s1_UL_GTPtunnelEndpoint);
		v(iE_Extensions);

	};
	void clear()
	{
		e_RAB_ID.clear();
		e_RAB_Level_QoS_Parameters.clear();
		dL_Forwarding.clear();
		s1_UL_GTPtunnelEndpoint.clear();
		iE_Extensions.clear();

	};
	private:
	e_RAB_ID_t	e_RAB_ID;
	e_RAB_Level_QoS_Parameters_t	e_RAB_Level_QoS_Parameters;
	dL_Forwarding_t	dL_Forwarding;
	s1_UL_GTPtunnelEndpoint_t	s1_UL_GTPtunnelEndpoint;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABs-ToBeAdded-ModReqItem-Split-BearerExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct E_RABs_ToBeAdded_ModReqItem_Split_BearerExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-ToBeAdded-ModReqItem-Split-Bearer ::= SEQUENCE {
	e-RAB-ID						E-RAB-ID,
	e-RAB-Level-QoS-Parameters		E-RAB-Level-QoS-Parameters,
	meNB-GTPtunnelEndpoint			GTPtunnelEndpoint,
	iE-Extensions			ProtocolExtensionContainer { {E-RABs-ToBeAdded-ModReqItem-Split-BearerExtIEs} } OPTIONAL,
	...
}
*/

struct E_RABs_ToBeAdded_ModReqItem_Split_Bearer : asn::sequence<4, 0, true, 1>
{
	static constexpr const char* name() {return "E-RABs-ToBeAdded-ModReqItem-Split-Bearer";}
	using parent_t = asn::sequence<4, 0, true, 1>;
	struct e_RAB_ID_t : E_RAB_ID
	{
		static constexpr const char* name() {return "e_RAB_ID_t";}
		using parent_t = E_RAB_ID;

	};
	e_RAB_ID_t& ref_e_RAB_ID() {return e_RAB_ID;}
	e_RAB_ID_t const& ref_e_RAB_ID() const {return e_RAB_ID;}
	struct e_RAB_Level_QoS_Parameters_t : E_RAB_Level_QoS_Parameters
	{
		static constexpr const char* name() {return "e_RAB_Level_QoS_Parameters_t";}
		using parent_t = E_RAB_Level_QoS_Parameters;

	};
	e_RAB_Level_QoS_Parameters_t& ref_e_RAB_Level_QoS_Parameters() {return e_RAB_Level_QoS_Parameters;}
	e_RAB_Level_QoS_Parameters_t const& ref_e_RAB_Level_QoS_Parameters() const {return e_RAB_Level_QoS_Parameters;}
	struct meNB_GTPtunnelEndpoint_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "meNB_GTPtunnelEndpoint_t";}
		using parent_t = GTPtunnelEndpoint;

	};
	meNB_GTPtunnelEndpoint_t& ref_meNB_GTPtunnelEndpoint() {return meNB_GTPtunnelEndpoint;}
	meNB_GTPtunnelEndpoint_t const& ref_meNB_GTPtunnelEndpoint() const {return meNB_GTPtunnelEndpoint;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABs_ToBeAdded_ModReqItem_Split_BearerExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABs_ToBeAdded_ModReqItem_Split_BearerExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(e_RAB_ID);
		v(e_RAB_Level_QoS_Parameters);
		v(meNB_GTPtunnelEndpoint);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(e_RAB_ID);
		v(e_RAB_Level_QoS_Parameters);
		v(meNB_GTPtunnelEndpoint);
		v(iE_Extensions);

	};
	void clear()
	{
		e_RAB_ID.clear();
		e_RAB_Level_QoS_Parameters.clear();
		meNB_GTPtunnelEndpoint.clear();
		iE_Extensions.clear();

	};
	private:
	e_RAB_ID_t	e_RAB_ID;
	e_RAB_Level_QoS_Parameters_t	e_RAB_Level_QoS_Parameters;
	meNB_GTPtunnelEndpoint_t	meNB_GTPtunnelEndpoint;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABs-ToBeAdded-ModReqItem ::= CHOICE {
	sCG-Bearer		E-RABs-ToBeAdded-ModReqItem-SCG-Bearer,
	split-Bearer	E-RABs-ToBeAdded-ModReqItem-Split-Bearer,
	...
}
*/

struct E_RABs_ToBeAdded_ModReqItem : asn::choice<2, 0, true>
{
	static constexpr const char* name() {return "E-RABs-ToBeAdded-ModReqItem";}
	using parent_t = asn::choice<2, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 3;}
	void set_unknown() { set_index(3);  }
	~E_RABs_ToBeAdded_ModReqItem() {clear();}
	struct sCG_Bearer_t : E_RABs_ToBeAdded_ModReqItem_SCG_Bearer
	{
		static constexpr const char* name() {return "sCG_Bearer_t";}
		using parent_t = E_RABs_ToBeAdded_ModReqItem_SCG_Bearer;

	};
	struct split_Bearer_t : E_RABs_ToBeAdded_ModReqItem_Split_Bearer
	{
		static constexpr const char* name() {return "split_Bearer_t";}
		using parent_t = E_RABs_ToBeAdded_ModReqItem_Split_Bearer;

	};
	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<sCG_Bearer_t>(); break;
		case 2: var.destroy<split_Bearer_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<sCG_Bearer_t>());
		case 2: set_index(2); return v(var.build<split_Bearer_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<sCG_Bearer_t>());
		case 2: return v(var.as<split_Bearer_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<sCG_Bearer_t>(1);
		v.template operator()<split_Bearer_t>(2);

	}
	sCG_Bearer_t& select_sCG_Bearer() { if(get_index() != 1) { clear(); set_index(1); return var.build<sCG_Bearer_t>();} return var.as<sCG_Bearer_t>();}
	sCG_Bearer_t const* get_sCG_Bearer() const { if(get_index() == 1) { return &var.as<sCG_Bearer_t>();} return nullptr; }
	split_Bearer_t& select_split_Bearer() { if(get_index() != 2) { clear(); set_index(2); return var.build<split_Bearer_t>();} return var.as<split_Bearer_t>();}
	split_Bearer_t const* get_split_Bearer() const { if(get_index() == 2) { return &var.as<split_Bearer_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(sCG_Bearer_t)];
		char dummy2[sizeof(split_Bearer_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
E-RABs-ToBeAdded-ModReqItemIEs X2AP-PROTOCOL-IES ::= {
	{ ID id-E-RABs-ToBeAdded-ModReqItem	CRITICALITY ignore	TYPE E-RABs-ToBeAdded-ModReqItem	PRESENCE mandatory},
	...
}
*/

struct E_RABs_ToBeAdded_ModReqItemIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_E_RABs_ToBeAdded_ModReqItem() { set(id_E_RABs_ToBeAdded_ModReqItem); type=1;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_E_RABs_ToBeAdded_ModReqItem)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_E_RABs_ToBeAdded_ModReqItem);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_E_RABs_ToBeAdded_ModReqItem() { set(ignore); type=1;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Value_t : asn::typefield<true>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		E_RABs_ToBeAdded_ModReqItem& select_id_E_RABs_ToBeAdded_ModReqItem() { return set<E_RABs_ToBeAdded_ModReqItem>(1); }
		E_RABs_ToBeAdded_ModReqItem const* get_id_E_RABs_ToBeAdded_ModReqItem() const { return get<E_RABs_ToBeAdded_ModReqItem>(1); }
		bool is_unknown() const { return type == 2; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<E_RABs_ToBeAdded_ModReqItem>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<E_RABs_ToBeAdded_ModReqItem>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_E_RABs_ToBeAdded_ModReqItem()); return true;
			case 2: if(type != 2) {clear(); asn::base::set();} type = 2; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<E_RABs_ToBeAdded_ModReqItem>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(E_RABs_ToBeAdded_ModReqItem)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_E_RABs_ToBeAdded_ModReqItem() { set(mandatory); type=1;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-ToBeAdded-List-ModReq ::= SEQUENCE (SIZE(1..maxnoofBearers)) OF ProtocolIE-Single-Container { {E-RABs-ToBeAdded-ModReqItemIEs} }
*/

struct E_RABs_ToBeAdded_List_ModReq_elm : ProtocolIE_Single_Container<E_RABs_ToBeAdded_ModReqItemIEs>
{
	static constexpr const char* name() {return "E_RABs_ToBeAdded_List_ModReq_elm";}
	using parent_t = ProtocolIE_Single_Container<E_RABs_ToBeAdded_ModReqItemIEs>;

};
struct E_RABs_ToBeAdded_List_ModReq : asn::sequenceof<E_RABs_ToBeAdded_List_ModReq_elm>
{
	static constexpr const char* name() {return "E-RABs-ToBeAdded-List-ModReq";}
	using parent_t = asn::sequenceof<E_RABs_ToBeAdded_List_ModReq_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofBearers >>;

};
/*
E-RABs-ToBeAdded-SgNBAddReq-Item-SgNBPDCPpresentExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	{ ID id-RLCMode-transferred					CRITICALITY ignore	EXTENSION RLCMode					PRESENCE optional},
	...
}
*/

struct E_RABs_ToBeAdded_SgNBAddReq_Item_SgNBPDCPpresentExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_RLCMode_transferred() { set(id_RLCMode_transferred); type=1;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_RLCMode_transferred)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_RLCMode_transferred);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_RLCMode_transferred() { set(ignore); type=1;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		RLCMode& select_id_RLCMode_transferred() { return set<RLCMode>(1); }
		RLCMode const* get_id_RLCMode_transferred() const { return get<RLCMode>(1); }
		bool is_unknown() const { return type == 2; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<RLCMode>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<RLCMode>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_RLCMode_transferred()); return true;
			case 2: if(type != 2) {clear(); asn::base::set();} type = 2; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<RLCMode>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(RLCMode)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_RLCMode_transferred() { set(optional); type=1;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(optional)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(optional);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-ToBeAdded-SgNBAddReq-Item-SgNBPDCPpresent ::= SEQUENCE {
	full-E-RAB-Level-QoS-Parameters				E-RAB-Level-QoS-Parameters,
	max-MCG-admit-E-RAB-Level-QoS-Parameters	GBR-QosInformation															OPTIONAL,
-- This IE shall be present if MCG resource and SCG resources IEs in the the EN-DC Resource Configuration IE are set to “present” and GBR QoS Information IE is present in Full E-RAB Level QoS Parameters IE --
	dL-Forwarding								DL-Forwarding																		OPTIONAL,
	meNB-DL-GTP-TEIDatMCG						GTPtunnelEndpoint																	OPTIONAL,
-- This IE shall be present if MCG resource IE in the the EN-DC Resource Configuration IE is set to “present” --
	s1-UL-GTPtunnelEndpoint						GTPtunnelEndpoint,
	iE-Extensions					ProtocolExtensionContainer { {E-RABs-ToBeAdded-SgNBAddReq-Item-SgNBPDCPpresentExtIEs} }	OPTIONAL,
	...
}
*/

struct E_RABs_ToBeAdded_SgNBAddReq_Item_SgNBPDCPpresent : asn::sequence<6, 0, true, 4>
{
	static constexpr const char* name() {return "E-RABs-ToBeAdded-SgNBAddReq-Item-SgNBPDCPpresent";}
	using parent_t = asn::sequence<6, 0, true, 4>;
	struct full_E_RAB_Level_QoS_Parameters_t : E_RAB_Level_QoS_Parameters
	{
		static constexpr const char* name() {return "full_E_RAB_Level_QoS_Parameters_t";}
		using parent_t = E_RAB_Level_QoS_Parameters;

	};
	full_E_RAB_Level_QoS_Parameters_t& ref_full_E_RAB_Level_QoS_Parameters() {return full_E_RAB_Level_QoS_Parameters;}
	full_E_RAB_Level_QoS_Parameters_t const& ref_full_E_RAB_Level_QoS_Parameters() const {return full_E_RAB_Level_QoS_Parameters;}
	struct max_MCG_admit_E_RAB_Level_QoS_Parameters_t : GBR_QosInformation
	{
		static constexpr const char* name() {return "max_MCG_admit_E_RAB_Level_QoS_Parameters_t";}
		using parent_t = GBR_QosInformation;
		static constexpr bool optional = true;

	};
	max_MCG_admit_E_RAB_Level_QoS_Parameters_t& set_max_MCG_admit_E_RAB_Level_QoS_Parameters() { max_MCG_admit_E_RAB_Level_QoS_Parameters.setpresent(true); return max_MCG_admit_E_RAB_Level_QoS_Parameters;}
	max_MCG_admit_E_RAB_Level_QoS_Parameters_t const* get_max_MCG_admit_E_RAB_Level_QoS_Parameters() const {return max_MCG_admit_E_RAB_Level_QoS_Parameters.is_valid() ? &max_MCG_admit_E_RAB_Level_QoS_Parameters : nullptr;}
	struct dL_Forwarding_t : DL_Forwarding
	{
		static constexpr const char* name() {return "dL_Forwarding_t";}
		using parent_t = DL_Forwarding;
		static constexpr bool optional = true;

	};
	dL_Forwarding_t& set_dL_Forwarding() { dL_Forwarding.setpresent(true); return dL_Forwarding;}
	dL_Forwarding_t const* get_dL_Forwarding() const {return dL_Forwarding.is_valid() ? &dL_Forwarding : nullptr;}
	struct meNB_DL_GTP_TEIDatMCG_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "meNB_DL_GTP_TEIDatMCG_t";}
		using parent_t = GTPtunnelEndpoint;
		static constexpr bool optional = true;

	};
	meNB_DL_GTP_TEIDatMCG_t& set_meNB_DL_GTP_TEIDatMCG() { meNB_DL_GTP_TEIDatMCG.setpresent(true); return meNB_DL_GTP_TEIDatMCG;}
	meNB_DL_GTP_TEIDatMCG_t const* get_meNB_DL_GTP_TEIDatMCG() const {return meNB_DL_GTP_TEIDatMCG.is_valid() ? &meNB_DL_GTP_TEIDatMCG : nullptr;}
	struct s1_UL_GTPtunnelEndpoint_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "s1_UL_GTPtunnelEndpoint_t";}
		using parent_t = GTPtunnelEndpoint;

	};
	s1_UL_GTPtunnelEndpoint_t& ref_s1_UL_GTPtunnelEndpoint() {return s1_UL_GTPtunnelEndpoint;}
	s1_UL_GTPtunnelEndpoint_t const& ref_s1_UL_GTPtunnelEndpoint() const {return s1_UL_GTPtunnelEndpoint;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABs_ToBeAdded_SgNBAddReq_Item_SgNBPDCPpresentExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABs_ToBeAdded_SgNBAddReq_Item_SgNBPDCPpresentExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(full_E_RAB_Level_QoS_Parameters);
		v(max_MCG_admit_E_RAB_Level_QoS_Parameters);
		v(dL_Forwarding);
		v(meNB_DL_GTP_TEIDatMCG);
		v(s1_UL_GTPtunnelEndpoint);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(full_E_RAB_Level_QoS_Parameters);
		v(max_MCG_admit_E_RAB_Level_QoS_Parameters);
		v(dL_Forwarding);
		v(meNB_DL_GTP_TEIDatMCG);
		v(s1_UL_GTPtunnelEndpoint);
		v(iE_Extensions);

	};
	void clear()
	{
		full_E_RAB_Level_QoS_Parameters.clear();
		max_MCG_admit_E_RAB_Level_QoS_Parameters.clear();
		dL_Forwarding.clear();
		meNB_DL_GTP_TEIDatMCG.clear();
		s1_UL_GTPtunnelEndpoint.clear();
		iE_Extensions.clear();

	};
	private:
	full_E_RAB_Level_QoS_Parameters_t	full_E_RAB_Level_QoS_Parameters;
	max_MCG_admit_E_RAB_Level_QoS_Parameters_t	max_MCG_admit_E_RAB_Level_QoS_Parameters;
	dL_Forwarding_t	dL_Forwarding;
	meNB_DL_GTP_TEIDatMCG_t	meNB_DL_GTP_TEIDatMCG;
	s1_UL_GTPtunnelEndpoint_t	s1_UL_GTPtunnelEndpoint;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABs-ToBeAdded-SgNBAddReq-Item-SgNBPDCPnotpresentExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	{ ID id-uLpDCPSnLength							CRITICALITY ignore	EXTENSION PDCPSnLength					PRESENCE optional}|
	{ ID id-dLPDCPSnLength							CRITICALITY ignore	EXTENSION PDCPSnLength					PRESENCE optional}|
	{ ID id-duplicationActivation					CRITICALITY ignore	EXTENSION DuplicationActivation	PRESENCE optional},
	...
}
*/

struct E_RABs_ToBeAdded_SgNBAddReq_Item_SgNBPDCPnotpresentExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 4; }
		void clear() {type = 0;}
		void select_id_uLpDCPSnLength() { set(id_uLpDCPSnLength); type=1;}
		void select_id_dLPDCPSnLength() { set(id_dLPDCPSnLength); type=2;}
		void select_id_duplicationActivation() { set(id_duplicationActivation); type=3;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_uLpDCPSnLength)) { type = 1; return true; }
			else if(equal(id_dLPDCPSnLength)) { type = 2; return true; }
			else if(equal(id_duplicationActivation)) { type = 3; return true; }
			else { type = 4; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_uLpDCPSnLength);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_dLPDCPSnLength);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(id_duplicationActivation);} return false;
			case 4: type = 4; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 4; }
		void clear() {type = 0;}
		void select_id_uLpDCPSnLength() { set(ignore); type=1;}
		void select_id_dLPDCPSnLength() { set(ignore); type=2;}
		void select_id_duplicationActivation() { set(ignore); type=3;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else if(equal(ignore)) { type = 2; return true; }
			else if(equal(ignore)) { type = 3; return true; }
			else { type = 4; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(ignore);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(ignore);} return false;
			case 4: type = 4; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		PDCPSnLength& select_id_uLpDCPSnLength() { return set<PDCPSnLength>(1); }
		PDCPSnLength const* get_id_uLpDCPSnLength() const { return get<PDCPSnLength>(1); }
		PDCPSnLength& select_id_dLPDCPSnLength() { return set<PDCPSnLength>(2); }
		PDCPSnLength const* get_id_dLPDCPSnLength() const { return get<PDCPSnLength>(2); }
		DuplicationActivation& select_id_duplicationActivation() { return set<DuplicationActivation>(3); }
		DuplicationActivation const* get_id_duplicationActivation() const { return get<DuplicationActivation>(3); }
		bool is_unknown() const { return type == 4; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<PDCPSnLength>(); break;
			case 2: var.destroy<PDCPSnLength>(); break;
			case 3: var.destroy<DuplicationActivation>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<PDCPSnLength>(1);
			v.template operator()<PDCPSnLength>(2);
			v.template operator()<DuplicationActivation>(3);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_uLpDCPSnLength()); return true;
			case 2: v(select_id_dLPDCPSnLength()); return true;
			case 3: v(select_id_duplicationActivation()); return true;
			case 4: if(type != 4) {clear(); asn::base::set();} type = 4; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<PDCPSnLength>()); return true;
			case 2: v(var.as<PDCPSnLength>()); return true;
			case 3: v(var.as<DuplicationActivation>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(DuplicationActivation)];
			char dummy2[sizeof(PDCPSnLength)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 4; }
		void clear() {type = 0;}
		void select_id_uLpDCPSnLength() { set(optional); type=1;}
		void select_id_dLPDCPSnLength() { set(optional); type=2;}
		void select_id_duplicationActivation() { set(optional); type=3;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(optional)) { type = 1; return true; }
			else if(equal(optional)) { type = 2; return true; }
			else if(equal(optional)) { type = 3; return true; }
			else { type = 4; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(optional);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(optional);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(optional);} return false;
			case 4: type = 4; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-ToBeAdded-SgNBAddReq-Item-SgNBPDCPnotpresent ::= SEQUENCE {
	requested-SCG-E-RAB-Level-QoS-Parameters		E-RAB-Level-QoS-Parameters,
	meNB-UL-GTP-TEIDatPDCP							GTPtunnelEndpoint,
	secondary-meNB-UL-GTP-TEIDatPDCP				GTPtunnelEndpoint	OPTIONAL,
	rlc-Mode										RLCMode,
	uL-Configuration								ULConfiguration	OPTIONAL,
-- This IE shall be present if MCG resource and SCG resources IEs in the the EN-DC Resource Configuration IE are set to “present” --
	iE-Extensions					ProtocolExtensionContainer { {E-RABs-ToBeAdded-SgNBAddReq-Item-SgNBPDCPnotpresentExtIEs} }		 OPTIONAL,
	...
}
*/

struct E_RABs_ToBeAdded_SgNBAddReq_Item_SgNBPDCPnotpresent : asn::sequence<6, 0, true, 3>
{
	static constexpr const char* name() {return "E-RABs-ToBeAdded-SgNBAddReq-Item-SgNBPDCPnotpresent";}
	using parent_t = asn::sequence<6, 0, true, 3>;
	struct requested_SCG_E_RAB_Level_QoS_Parameters_t : E_RAB_Level_QoS_Parameters
	{
		static constexpr const char* name() {return "requested_SCG_E_RAB_Level_QoS_Parameters_t";}
		using parent_t = E_RAB_Level_QoS_Parameters;

	};
	requested_SCG_E_RAB_Level_QoS_Parameters_t& ref_requested_SCG_E_RAB_Level_QoS_Parameters() {return requested_SCG_E_RAB_Level_QoS_Parameters;}
	requested_SCG_E_RAB_Level_QoS_Parameters_t const& ref_requested_SCG_E_RAB_Level_QoS_Parameters() const {return requested_SCG_E_RAB_Level_QoS_Parameters;}
	struct meNB_UL_GTP_TEIDatPDCP_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "meNB_UL_GTP_TEIDatPDCP_t";}
		using parent_t = GTPtunnelEndpoint;

	};
	meNB_UL_GTP_TEIDatPDCP_t& ref_meNB_UL_GTP_TEIDatPDCP() {return meNB_UL_GTP_TEIDatPDCP;}
	meNB_UL_GTP_TEIDatPDCP_t const& ref_meNB_UL_GTP_TEIDatPDCP() const {return meNB_UL_GTP_TEIDatPDCP;}
	struct secondary_meNB_UL_GTP_TEIDatPDCP_t : GTPtunnelEndpoint
	{
		static constexpr const char* name() {return "secondary_meNB_UL_GTP_TEIDatPDCP_t";}
		using parent_t = GTPtunnelEndpoint;
		static constexpr bool optional = true;

	};
	secondary_meNB_UL_GTP_TEIDatPDCP_t& set_secondary_meNB_UL_GTP_TEIDatPDCP() { secondary_meNB_UL_GTP_TEIDatPDCP.setpresent(true); return secondary_meNB_UL_GTP_TEIDatPDCP;}
	secondary_meNB_UL_GTP_TEIDatPDCP_t const* get_secondary_meNB_UL_GTP_TEIDatPDCP() const {return secondary_meNB_UL_GTP_TEIDatPDCP.is_valid() ? &secondary_meNB_UL_GTP_TEIDatPDCP : nullptr;}
	struct rlc_Mode_t : RLCMode
	{
		static constexpr const char* name() {return "rlc_Mode_t";}
		using parent_t = RLCMode;

	};
	rlc_Mode_t& ref_rlc_Mode() {return rlc_Mode;}
	rlc_Mode_t const& ref_rlc_Mode() const {return rlc_Mode;}
	struct uL_Configuration_t : ULConfiguration
	{
		static constexpr const char* name() {return "uL_Configuration_t";}
		using parent_t = ULConfiguration;
		static constexpr bool optional = true;

	};
	uL_Configuration_t& set_uL_Configuration() { uL_Configuration.setpresent(true); return uL_Configuration;}
	uL_Configuration_t const* get_uL_Configuration() const {return uL_Configuration.is_valid() ? &uL_Configuration : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABs_ToBeAdded_SgNBAddReq_Item_SgNBPDCPnotpresentExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABs_ToBeAdded_SgNBAddReq_Item_SgNBPDCPnotpresentExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(requested_SCG_E_RAB_Level_QoS_Parameters);
		v(meNB_UL_GTP_TEIDatPDCP);
		v(secondary_meNB_UL_GTP_TEIDatPDCP);
		v(rlc_Mode);
		v(uL_Configuration);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(requested_SCG_E_RAB_Level_QoS_Parameters);
		v(meNB_UL_GTP_TEIDatPDCP);
		v(secondary_meNB_UL_GTP_TEIDatPDCP);
		v(rlc_Mode);
		v(uL_Configuration);
		v(iE_Extensions);

	};
	void clear()
	{
		requested_SCG_E_RAB_Level_QoS_Parameters.clear();
		meNB_UL_GTP_TEIDatPDCP.clear();
		secondary_meNB_UL_GTP_TEIDatPDCP.clear();
		rlc_Mode.clear();
		uL_Configuration.clear();
		iE_Extensions.clear();

	};
	private:
	requested_SCG_E_RAB_Level_QoS_Parameters_t	requested_SCG_E_RAB_Level_QoS_Parameters;
	meNB_UL_GTP_TEIDatPDCP_t	meNB_UL_GTP_TEIDatPDCP;
	secondary_meNB_UL_GTP_TEIDatPDCP_t	secondary_meNB_UL_GTP_TEIDatPDCP;
	rlc_Mode_t	rlc_Mode;
	uL_Configuration_t	uL_Configuration;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABs-ToBeAdded-SgNBAddReq-ItemExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct E_RABs_ToBeAdded_SgNBAddReq_ItemExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-ToBeAdded-SgNBAddReq-Item ::= SEQUENCE {
	e-RAB-ID								E-RAB-ID,
	drb-ID								DRB-ID,
	en-DC-ResourceConfiguration			EN-DC-ResourceConfiguration,
	resource-configuration				CHOICE {
		sgNBPDCPpresent						E-RABs-ToBeAdded-SgNBAddReq-Item-SgNBPDCPpresent,
		sgNBPDCPnotpresent					E-RABs-ToBeAdded-SgNBAddReq-Item-SgNBPDCPnotpresent,
		...
	},
	iE-Extensions					ProtocolExtensionContainer { {E-RABs-ToBeAdded-SgNBAddReq-ItemExtIEs} }	OPTIONAL,
	...
}
*/

struct E_RABs_ToBeAdded_SgNBAddReq_Item : asn::sequence<5, 0, true, 1>
{
	static constexpr const char* name() {return "E-RABs-ToBeAdded-SgNBAddReq-Item";}
	using parent_t = asn::sequence<5, 0, true, 1>;
	struct e_RAB_ID_t : E_RAB_ID
	{
		static constexpr const char* name() {return "e_RAB_ID_t";}
		using parent_t = E_RAB_ID;

	};
	e_RAB_ID_t& ref_e_RAB_ID() {return e_RAB_ID;}
	e_RAB_ID_t const& ref_e_RAB_ID() const {return e_RAB_ID;}
	struct drb_ID_t : DRB_ID
	{
		static constexpr const char* name() {return "drb_ID_t";}
		using parent_t = DRB_ID;

	};
	drb_ID_t& ref_drb_ID() {return drb_ID;}
	drb_ID_t const& ref_drb_ID() const {return drb_ID;}
	struct en_DC_ResourceConfiguration_t : EN_DC_ResourceConfiguration
	{
		static constexpr const char* name() {return "en_DC_ResourceConfiguration_t";}
		using parent_t = EN_DC_ResourceConfiguration;

	};
	en_DC_ResourceConfiguration_t& ref_en_DC_ResourceConfiguration() {return en_DC_ResourceConfiguration;}
	en_DC_ResourceConfiguration_t const& ref_en_DC_ResourceConfiguration() const {return en_DC_ResourceConfiguration;}
	struct resource_configuration_t : asn::choice<2, 0, true>
	{
		static constexpr const char* name() {return "resource_configuration_t";}
		using parent_t = asn::choice<2, 0, true>;
		index_type get_index() const {return index;}
		bool is_unknown() const {return index == 3;}
		void set_unknown() { set_index(3);  }
		~resource_configuration_t() {clear();}
		struct sgNBPDCPpresent_t : E_RABs_ToBeAdded_SgNBAddReq_Item_SgNBPDCPpresent
		{
			static constexpr const char* name() {return "sgNBPDCPpresent_t";}
			using parent_t = E_RABs_ToBeAdded_SgNBAddReq_Item_SgNBPDCPpresent;

		};
		struct sgNBPDCPnotpresent_t : E_RABs_ToBeAdded_SgNBAddReq_Item_SgNBPDCPnotpresent
		{
			static constexpr const char* name() {return "sgNBPDCPnotpresent_t";}
			using parent_t = E_RABs_ToBeAdded_SgNBAddReq_Item_SgNBPDCPnotpresent;

		};
		void clear()
		{
			switch(get_index())
			{
			case 1: var.destroy<sgNBPDCPpresent_t>(); break;
			case 2: var.destroy<sgNBPDCPnotpresent_t>(); break;
			}
			index = 0;
			base::clear();
		}
		template<typename V> bool decode(size_t idx, V& v)
		{
			clear();
			switch(idx)
			{
			case 1: set_index(1); return v(var.build<sgNBPDCPpresent_t>());
			case 2: set_index(2); return v(var.build<sgNBPDCPnotpresent_t>());
			}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			switch(get_index())
			{
			case 1: return v(var.as<sgNBPDCPpresent_t>());
			case 2: return v(var.as<sgNBPDCPnotpresent_t>());
			}
			return false;
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<sgNBPDCPpresent_t>(1);
			v.template operator()<sgNBPDCPnotpresent_t>(2);

		}
		sgNBPDCPpresent_t& select_sgNBPDCPpresent() { if(get_index() != 1) { clear(); set_index(1); return var.build<sgNBPDCPpresent_t>();} return var.as<sgNBPDCPpresent_t>();}
		sgNBPDCPpresent_t const* get_sgNBPDCPpresent() const { if(get_index() == 1) { return &var.as<sgNBPDCPpresent_t>();} return nullptr; }
		sgNBPDCPnotpresent_t& select_sgNBPDCPnotpresent() { if(get_index() != 2) { clear(); set_index(2); return var.build<sgNBPDCPnotpresent_t>();} return var.as<sgNBPDCPnotpresent_t>();}
		sgNBPDCPnotpresent_t const* get_sgNBPDCPnotpresent() const { if(get_index() == 2) { return &var.as<sgNBPDCPnotpresent_t>();} return nullptr; }
		private:
		void set_index(index_type i) {index = i; base::set();}
		union union_type
		{
			char dummy1[sizeof(sgNBPDCPpresent_t)];
			char dummy2[sizeof(sgNBPDCPnotpresent_t)];

		};
		asn::variant<sizeof(union_type)>	var;
		index_type	index {0};
	};
	resource_configuration_t& ref_resource_configuration() {return resource_configuration;}
	resource_configuration_t const& ref_resource_configuration() const {return resource_configuration;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABs_ToBeAdded_SgNBAddReq_ItemExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABs_ToBeAdded_SgNBAddReq_ItemExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(e_RAB_ID);
		v(drb_ID);
		v(en_DC_ResourceConfiguration);
		v(resource_configuration);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(e_RAB_ID);
		v(drb_ID);
		v(en_DC_ResourceConfiguration);
		v(resource_configuration);
		v(iE_Extensions);

	};
	void clear()
	{
		e_RAB_ID.clear();
		drb_ID.clear();
		en_DC_ResourceConfiguration.clear();
		resource_configuration.clear();
		iE_Extensions.clear();

	};
	private:
	e_RAB_ID_t	e_RAB_ID;
	drb_ID_t	drb_ID;
	en_DC_ResourceConfiguration_t	en_DC_ResourceConfiguration;
	resource_configuration_t	resource_configuration;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABs-ToBeAdded-SgNBAddReq-ItemIEs	X2AP-PROTOCOL-IES ::= {
	{ ID id-E-RABs-ToBeAdded-SgNBAddReq-Item		CRITICALITY reject	TYPE E-RABs-ToBeAdded-SgNBAddReq-Item		PRESENCE mandatory},
	...
}
*/

struct E_RABs_ToBeAdded_SgNBAddReq_ItemIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_E_RABs_ToBeAdded_SgNBAddReq_Item() { set(id_E_RABs_ToBeAdded_SgNBAddReq_Item); type=1;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_E_RABs_ToBeAdded_SgNBAddReq_Item)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_E_RABs_ToBeAdded_SgNBAddReq_Item);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_E_RABs_ToBeAdded_SgNBAddReq_Item() { set(reject); type=1;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(reject)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(reject);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Value_t : asn::typefield<true>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		E_RABs_ToBeAdded_SgNBAddReq_Item& select_id_E_RABs_ToBeAdded_SgNBAddReq_Item() { return set<E_RABs_ToBeAdded_SgNBAddReq_Item>(1); }
		E_RABs_ToBeAdded_SgNBAddReq_Item const* get_id_E_RABs_ToBeAdded_SgNBAddReq_Item() const { return get<E_RABs_ToBeAdded_SgNBAddReq_Item>(1); }
		bool is_unknown() const { return type == 2; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<E_RABs_ToBeAdded_SgNBAddReq_Item>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<E_RABs_ToBeAdded_SgNBAddReq_Item>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_E_RABs_ToBeAdded_SgNBAddReq_Item()); return true;
			case 2: if(type != 2) {clear(); asn::base::set();} type = 2; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<E_RABs_ToBeAdded_SgNBAddReq_Item>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(E_RABs_ToBeAdded_SgNBAddReq_Item)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_E_RABs_ToBeAdded_SgNBAddReq_Item() { set(mandatory); type=1;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABs-ToBeAdded-SgNBAddReqList ::= SEQUENCE (SIZE(1..maxnoofBearers)) OF ProtocolIE-Single-Container { {E-RABs-ToBeAdded-SgNBAddReq-ItemIEs} }
*/

struct E_RABs_ToBeAdded_SgNBAddReqList_elm : ProtocolIE_Single_Container<E_RABs_ToBeAdded_SgNBAddReq_ItemIEs>
{
	static constexpr const char* name() {return "E_RABs_ToBeAdded_SgNBAddReqList_elm";}
	using parent_t = ProtocolIE_Single_Container<E_RABs_ToBeAdded_SgNBAddReq_ItemIEs>;

};
struct E_RABs_ToBeAdded_SgNBAddReqList : asn::sequenceof<E_RABs_ToBeAdded_SgNBAddReqList_elm>
{
	static constexpr const char* name() {return "E-RABs-ToBeAdded-SgNBAddReqList";}
	using parent_t = asn::sequenceof<E_RABs_ToBeAdded_SgNBAddReqList_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofBearers >>;

};
/*
E-RABs-ToBeAdded-SgNBModReq-Item-SgNBPDCPpresentExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	{ ID id-RLCMode-transferred					CRITICALITY ignore	EXTENSION RLCMode					PRESENCE optional},
	...
}
*/

struct E_RABs_ToBeAdded_SgNBModReq_Item_SgNBPDCPpresentExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_RLCMode_transferred() { set(id_RLCMode_transferred); type=1;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_RLCMode_transferred)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_RLCMode_transferred);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_RLCMode_transferred() { set(ignore); type=1;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equ