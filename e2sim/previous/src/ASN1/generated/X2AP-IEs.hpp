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

#include "X2AP-Constants.hpp"
#include "X2AP-CommonDataTypes.hpp"
#include "X2AP-Containers.hpp"

/*
DL-ABS-status::= INTEGER (0..100)
*/

struct DL_ABS_status : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 100>>;
	static constexpr const char* name() {return "DL-ABS-status";}
	using parent_t = asn::integer<>;

};

/*
UsableABSInformationFDD-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct UsableABSInformationFDD_ExtIEs
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
UsableABSInformationFDD ::= SEQUENCE {
	usable-abs-pattern-info				BIT STRING (SIZE(40)),
	iE-Extensions						ProtocolExtensionContainer { {UsableABSInformationFDD-ExtIEs} } OPTIONAL,
	...
}
*/

struct UsableABSInformationFDD : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "UsableABSInformationFDD";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct usable_abs_pattern_info_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<false,asn::one<40>>;
		static constexpr const char* name() {return "usable_abs_pattern_info_t";}
		using parent_t = asn::bstring<>;

	};

	usable_abs_pattern_info_t& ref_usable_abs_pattern_info() {return usable_abs_pattern_info;}
	usable_abs_pattern_info_t const& ref_usable_abs_pattern_info() const {return usable_abs_pattern_info;}
	struct iE_Extensions_t : ProtocolExtensionContainer<UsableABSInformationFDD_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<UsableABSInformationFDD_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(usable_abs_pattern_info);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(usable_abs_pattern_info);
		v(iE_Extensions);

	};
	void clear()
	{
		usable_abs_pattern_info.clear();
		iE_Extensions.clear();

	};
	private:
	usable_abs_pattern_info_t	usable_abs_pattern_info;
	iE_Extensions_t	iE_Extensions;

};
/*
UsableABSInformationTDD-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct UsableABSInformationTDD_ExtIEs
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
UsableABSInformationTDD ::= SEQUENCE {
	usaable-abs-pattern-info			BIT STRING (SIZE(1..70, ...)),
	iE-Extensions						ProtocolExtensionContainer { {UsableABSInformationTDD-ExtIEs} } OPTIONAL,
	...
}
*/

struct UsableABSInformationTDD : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "UsableABSInformationTDD";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct usaable_abs_pattern_info_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<true,asn::span<1, 70>>;
		static constexpr const char* name() {return "usaable_abs_pattern_info_t";}
		using parent_t = asn::bstring<>;

	};

	usaable_abs_pattern_info_t& ref_usaable_abs_pattern_info() {return usaable_abs_pattern_info;}
	usaable_abs_pattern_info_t const& ref_usaable_abs_pattern_info() const {return usaable_abs_pattern_info;}
	struct iE_Extensions_t : ProtocolExtensionContainer<UsableABSInformationTDD_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<UsableABSInformationTDD_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(usaable_abs_pattern_info);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(usaable_abs_pattern_info);
		v(iE_Extensions);

	};
	void clear()
	{
		usaable_abs_pattern_info.clear();
		iE_Extensions.clear();

	};
	private:
	usaable_abs_pattern_info_t	usaable_abs_pattern_info;
	iE_Extensions_t	iE_Extensions;

};
/*
UsableABSInformation ::= CHOICE {
	fdd					UsableABSInformationFDD,
	tdd					UsableABSInformationTDD,
	...
}
*/

struct UsableABSInformation : asn::choice<2, 0, true>
{
	static constexpr const char* name() {return "UsableABSInformation";}
	using parent_t = asn::choice<2, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 3;}
	void set_unknown() { set_index(3);  }
	~UsableABSInformation() {clear();}
	struct fdd_t : UsableABSInformationFDD
	{
		static constexpr const char* name() {return "fdd_t";}
		using parent_t = UsableABSInformationFDD;

	};
	struct tdd_t : UsableABSInformationTDD
	{
		static constexpr const char* name() {return "tdd_t";}
		using parent_t = UsableABSInformationTDD;

	};
	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<fdd_t>(); break;
		case 2: var.destroy<tdd_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<fdd_t>());
		case 2: set_index(2); return v(var.build<tdd_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<fdd_t>());
		case 2: return v(var.as<tdd_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<fdd_t>(1);
		v.template operator()<tdd_t>(2);

	}
	fdd_t& select_fdd() { if(get_index() != 1) { clear(); set_index(1); return var.build<fdd_t>();} return var.as<fdd_t>();}
	fdd_t const* get_fdd() const { if(get_index() == 1) { return &var.as<fdd_t>();} return nullptr; }
	tdd_t& select_tdd() { if(get_index() != 2) { clear(); set_index(2); return var.build<tdd_t>();} return var.as<tdd_t>();}
	tdd_t const* get_tdd() const { if(get_index() == 2) { return &var.as<tdd_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(fdd_t)];
		char dummy2[sizeof(tdd_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
ABS-Status-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct ABS_Status_ExtIEs
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
ABS-Status ::= SEQUENCE {
	dL-ABS-status								DL-ABS-status,
	usableABSInformation						UsableABSInformation,
	iE-Extensions								ProtocolExtensionContainer { {ABS-Status-ExtIEs} } OPTIONAL,
	...
}
*/

struct ABS_Status : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "ABS-Status";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct dL_ABS_status_t : DL_ABS_status
	{
		static constexpr const char* name() {return "dL_ABS_status_t";}
		using parent_t = DL_ABS_status;

	};
	dL_ABS_status_t& ref_dL_ABS_status() {return dL_ABS_status;}
	dL_ABS_status_t const& ref_dL_ABS_status() const {return dL_ABS_status;}
	struct usableABSInformation_t : UsableABSInformation
	{
		static constexpr const char* name() {return "usableABSInformation_t";}
		using parent_t = UsableABSInformation;

	};
	usableABSInformation_t& ref_usableABSInformation() {return usableABSInformation;}
	usableABSInformation_t const& ref_usableABSInformation() const {return usableABSInformation;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ABS_Status_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ABS_Status_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(dL_ABS_status);
		v(usableABSInformation);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(dL_ABS_status);
		v(usableABSInformation);
		v(iE_Extensions);

	};
	void clear()
	{
		dL_ABS_status.clear();
		usableABSInformation.clear();
		iE_Extensions.clear();

	};
	private:
	dL_ABS_status_t	dL_ABS_status;
	usableABSInformation_t	usableABSInformation;
	iE_Extensions_t	iE_Extensions;

};
/*
ABSInformationFDD-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct ABSInformationFDD_ExtIEs
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
ABSInformationFDD ::= SEQUENCE {
	abs-pattern-info					BIT STRING (SIZE(40)),
	numberOfCellSpecificAntennaPorts	ENUMERATED {one, two, four, ...},
	measurement-subset					BIT STRING (SIZE(40)),
	iE-Extensions						ProtocolExtensionContainer { {ABSInformationFDD-ExtIEs} } OPTIONAL,
	...
}
*/

struct ABSInformationFDD : asn::sequence<4, 0, true, 1>
{
	static constexpr const char* name() {return "ABSInformationFDD";}
	using parent_t = asn::sequence<4, 0, true, 1>;
	struct abs_pattern_info_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<false,asn::one<40>>;
		static constexpr const char* name() {return "abs_pattern_info_t";}
		using parent_t = asn::bstring<>;

	};

	abs_pattern_info_t& ref_abs_pattern_info() {return abs_pattern_info;}
	abs_pattern_info_t const& ref_abs_pattern_info() const {return abs_pattern_info;}
	struct numberOfCellSpecificAntennaPorts_t : asn::enumerated<3, 0, true>
	{
		static constexpr const char* name() {return "numberOfCellSpecificAntennaPorts_t";}
		using parent_t = asn::enumerated<3, 0, true>;
		typedef enum {
			one
			,two
			,four
		} index_t;

	};

	numberOfCellSpecificAntennaPorts_t& ref_numberOfCellSpecificAntennaPorts() {return numberOfCellSpecificAntennaPorts;}
	numberOfCellSpecificAntennaPorts_t const& ref_numberOfCellSpecificAntennaPorts() const {return numberOfCellSpecificAntennaPorts;}
	struct measurement_subset_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<false,asn::one<40>>;
		static constexpr const char* name() {return "measurement_subset_t";}
		using parent_t = asn::bstring<>;

	};

	measurement_subset_t& ref_measurement_subset() {return measurement_subset;}
	measurement_subset_t const& ref_measurement_subset() const {return measurement_subset;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ABSInformationFDD_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ABSInformationFDD_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(abs_pattern_info);
		v(numberOfCellSpecificAntennaPorts);
		v(measurement_subset);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(abs_pattern_info);
		v(numberOfCellSpecificAntennaPorts);
		v(measurement_subset);
		v(iE_Extensions);

	};
	void clear()
	{
		abs_pattern_info.clear();
		numberOfCellSpecificAntennaPorts.clear();
		measurement_subset.clear();
		iE_Extensions.clear();

	};
	private:
	abs_pattern_info_t	abs_pattern_info;
	numberOfCellSpecificAntennaPorts_t	numberOfCellSpecificAntennaPorts;
	measurement_subset_t	measurement_subset;
	iE_Extensions_t	iE_Extensions;

};
/*
ABSInformationTDD-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct ABSInformationTDD_ExtIEs
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
ABSInformationTDD ::= SEQUENCE {
	abs-pattern-info					BIT STRING (SIZE(1..70, ...)),
	numberOfCellSpecificAntennaPorts	ENUMERATED {one, two, four, ...},
	measurement-subset					BIT STRING (SIZE(1..70, ...)),
	iE-Extensions						ProtocolExtensionContainer { {ABSInformationTDD-ExtIEs} } OPTIONAL,
	...
}
*/

struct ABSInformationTDD : asn::sequence<4, 0, true, 1>
{
	static constexpr const char* name() {return "ABSInformationTDD";}
	using parent_t = asn::sequence<4, 0, true, 1>;
	struct abs_pattern_info_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<true,asn::span<1, 70>>;
		static constexpr const char* name() {return "abs_pattern_info_t";}
		using parent_t = asn::bstring<>;

	};

	abs_pattern_info_t& ref_abs_pattern_info() {return abs_pattern_info;}
	abs_pattern_info_t const& ref_abs_pattern_info() const {return abs_pattern_info;}
	struct numberOfCellSpecificAntennaPorts_t : asn::enumerated<3, 0, true>
	{
		static constexpr const char* name() {return "numberOfCellSpecificAntennaPorts_t";}
		using parent_t = asn::enumerated<3, 0, true>;
		typedef enum {
			one
			,two
			,four
		} index_t;

	};

	numberOfCellSpecificAntennaPorts_t& ref_numberOfCellSpecificAntennaPorts() {return numberOfCellSpecificAntennaPorts;}
	numberOfCellSpecificAntennaPorts_t const& ref_numberOfCellSpecificAntennaPorts() const {return numberOfCellSpecificAntennaPorts;}
	struct measurement_subset_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<true,asn::span<1, 70>>;
		static constexpr const char* name() {return "measurement_subset_t";}
		using parent_t = asn::bstring<>;

	};

	measurement_subset_t& ref_measurement_subset() {return measurement_subset;}
	measurement_subset_t const& ref_measurement_subset() const {return measurement_subset;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ABSInformationTDD_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ABSInformationTDD_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(abs_pattern_info);
		v(numberOfCellSpecificAntennaPorts);
		v(measurement_subset);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(abs_pattern_info);
		v(numberOfCellSpecificAntennaPorts);
		v(measurement_subset);
		v(iE_Extensions);

	};
	void clear()
	{
		abs_pattern_info.clear();
		numberOfCellSpecificAntennaPorts.clear();
		measurement_subset.clear();
		iE_Extensions.clear();

	};
	private:
	abs_pattern_info_t	abs_pattern_info;
	numberOfCellSpecificAntennaPorts_t	numberOfCellSpecificAntennaPorts;
	measurement_subset_t	measurement_subset;
	iE_Extensions_t	iE_Extensions;

};
/*
ABSInformation ::= CHOICE {
	fdd					ABSInformationFDD,
	tdd					ABSInformationTDD,
	abs-inactive		NULL,
	...
}
*/

struct ABSInformation : asn::choice<3, 0, true>
{
	static constexpr const char* name() {return "ABSInformation";}
	using parent_t = asn::choice<3, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 4;}
	void set_unknown() { set_index(4);  }
	~ABSInformation() {clear();}
	struct fdd_t : ABSInformationFDD
	{
		static constexpr const char* name() {return "fdd_t";}
		using parent_t = ABSInformationFDD;

	};
	struct tdd_t : ABSInformationTDD
	{
		static constexpr const char* name() {return "tdd_t";}
		using parent_t = ABSInformationTDD;

	};
	struct abs_inactive_t : asn::nulltype
	{
		static constexpr const char* name() {return "abs_inactive_t";}
		using parent_t = asn::nulltype;

	};
	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<fdd_t>(); break;
		case 2: var.destroy<tdd_t>(); break;
		case 3: var.destroy<abs_inactive_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<fdd_t>());
		case 2: set_index(2); return v(var.build<tdd_t>());
		case 3: set_index(3); return v(var.build<abs_inactive_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<fdd_t>());
		case 2: return v(var.as<tdd_t>());
		case 3: return v(var.as<abs_inactive_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<fdd_t>(1);
		v.template operator()<tdd_t>(2);
		v.template operator()<abs_inactive_t>(3);

	}
	fdd_t& select_fdd() { if(get_index() != 1) { clear(); set_index(1); return var.build<fdd_t>();} return var.as<fdd_t>();}
	fdd_t const* get_fdd() const { if(get_index() == 1) { return &var.as<fdd_t>();} return nullptr; }
	tdd_t& select_tdd() { if(get_index() != 2) { clear(); set_index(2); return var.build<tdd_t>();} return var.as<tdd_t>();}
	tdd_t const* get_tdd() const { if(get_index() == 2) { return &var.as<tdd_t>();} return nullptr; }
	abs_inactive_t& select_abs_inactive() { if(get_index() != 3) { clear(); set_index(3); return var.build<abs_inactive_t>();} return var.as<abs_inactive_t>();}
	abs_inactive_t const* get_abs_inactive() const { if(get_index() == 3) { return &var.as<abs_inactive_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(fdd_t)];
		char dummy2[sizeof(tdd_t)];
		char dummy3[sizeof(abs_inactive_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
Key-eNodeB-Star ::= BIT STRING (SIZE(256))
*/

struct Key_eNodeB_Star : asn::bstring<>
{
	using constraint_t = asn::constraints<false,asn::one<256>>;
	static constexpr const char* name() {return "Key-eNodeB-Star";}
	using parent_t = asn::bstring<>;

};

/*
NextHopChainingCount ::= INTEGER (0..7)
*/

struct NextHopChainingCount : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 7>>;
	static constexpr const char* name() {return "NextHopChainingCount";}
	using parent_t = asn::integer<>;

};

/*
AS-SecurityInformation-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct AS_SecurityInformation_ExtIEs
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
AS-SecurityInformation ::= SEQUENCE {
	key-eNodeB-star		Key-eNodeB-Star,
	nextHopChainingCount			NextHopChainingCount,
	iE-Extensions						ProtocolExtensionContainer { {AS-SecurityInformation-ExtIEs} } OPTIONAL,
	...
}
*/

struct AS_SecurityInformation : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "AS-SecurityInformation";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct key_eNodeB_star_t : Key_eNodeB_Star
	{
		static constexpr const char* name() {return "key_eNodeB_star_t";}
		using parent_t = Key_eNodeB_Star;

	};
	key_eNodeB_star_t& ref_key_eNodeB_star() {return key_eNodeB_star;}
	key_eNodeB_star_t const& ref_key_eNodeB_star() const {return key_eNodeB_star;}
	struct nextHopChainingCount_t : NextHopChainingCount
	{
		static constexpr const char* name() {return "nextHopChainingCount_t";}
		using parent_t = NextHopChainingCount;

	};
	nextHopChainingCount_t& ref_nextHopChainingCount() {return nextHopChainingCount;}
	nextHopChainingCount_t const& ref_nextHopChainingCount() const {return nextHopChainingCount;}
	struct iE_Extensions_t : ProtocolExtensionContainer<AS_SecurityInformation_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<AS_SecurityInformation_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(key_eNodeB_star);
		v(nextHopChainingCount);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(key_eNodeB_star);
		v(nextHopChainingCount);
		v(iE_Extensions);

	};
	void clear()
	{
		key_eNodeB_star.clear();
		nextHopChainingCount.clear();
		iE_Extensions.clear();

	};
	private:
	key_eNodeB_star_t	key_eNodeB_star;
	nextHopChainingCount_t	nextHopChainingCount;
	iE_Extensions_t	iE_Extensions;

};
/*
ActivationID ::= INTEGER (0..255)
*/

struct ActivationID : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 255>>;
	static constexpr const char* name() {return "ActivationID";}
	using parent_t = asn::integer<>;

};

/*
AdditionalSpecialSubframePatterns ::= ENUMERATED {
	ssp0,
	ssp1,
	ssp2,
	ssp3,
	ssp4,
	ssp5,
	ssp6,
	ssp7,
	ssp8,
	ssp9,
	...
}
*/

struct AdditionalSpecialSubframePatterns : asn::enumerated<10, 0, true>
{
	static constexpr const char* name() {return "AdditionalSpecialSubframePatterns";}
	using parent_t = asn::enumerated<10, 0, true>;
	typedef enum {
		ssp0
		,ssp1
		,ssp2
		,ssp3
		,ssp4
		,ssp5
		,ssp6
		,ssp7
		,ssp8
		,ssp9
	} index_t;

};

/*
CyclicPrefixDL ::= ENUMERATED {
	normal,
	extended,
	...
}
*/

struct CyclicPrefixDL : asn::enumerated<2, 0, true>
{
	static constexpr const char* name() {return "CyclicPrefixDL";}
	using parent_t = asn::enumerated<2, 0, true>;
	typedef enum {
		normal
		,extended
	} index_t;

};

/*
CyclicPrefixUL ::= ENUMERATED {
	normal,
	extended,
	...
}
*/

struct CyclicPrefixUL : asn::enumerated<2, 0, true>
{
	static constexpr const char* name() {return "CyclicPrefixUL";}
	using parent_t = asn::enumerated<2, 0, true>;
	typedef enum {
		normal
		,extended
	} index_t;

};

/*
AdditionalSpecialSubframe-Info-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct AdditionalSpecialSubframe_Info_ExtIEs
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
AdditionalSpecialSubframe-Info ::=		SEQUENCE {
	additionalspecialSubframePatterns		AdditionalSpecialSubframePatterns,
	cyclicPrefixDL							CyclicPrefixDL,
	cyclicPrefixUL							CyclicPrefixUL,
	iE-Extensions							ProtocolExtensionContainer { {AdditionalSpecialSubframe-Info-ExtIEs} } OPTIONAL,
	...
}
*/

struct AdditionalSpecialSubframe_Info : asn::sequence<4, 0, true, 1>
{
	static constexpr const char* name() {return "AdditionalSpecialSubframe-Info";}
	using parent_t = asn::sequence<4, 0, true, 1>;
	struct additionalspecialSubframePatterns_t : AdditionalSpecialSubframePatterns
	{
		static constexpr const char* name() {return "additionalspecialSubframePatterns_t";}
		using parent_t = AdditionalSpecialSubframePatterns;

	};
	additionalspecialSubframePatterns_t& ref_additionalspecialSubframePatterns() {return additionalspecialSubframePatterns;}
	additionalspecialSubframePatterns_t const& ref_additionalspecialSubframePatterns() const {return additionalspecialSubframePatterns;}
	struct cyclicPrefixDL_t : CyclicPrefixDL
	{
		static constexpr const char* name() {return "cyclicPrefixDL_t";}
		using parent_t = CyclicPrefixDL;

	};
	cyclicPrefixDL_t& ref_cyclicPrefixDL() {return cyclicPrefixDL;}
	cyclicPrefixDL_t const& ref_cyclicPrefixDL() const {return cyclicPrefixDL;}
	struct cyclicPrefixUL_t : CyclicPrefixUL
	{
		static constexpr const char* name() {return "cyclicPrefixUL_t";}
		using parent_t = CyclicPrefixUL;

	};
	cyclicPrefixUL_t& ref_cyclicPrefixUL() {return cyclicPrefixUL;}
	cyclicPrefixUL_t const& ref_cyclicPrefixUL() const {return cyclicPrefixUL;}
	struct iE_Extensions_t : ProtocolExtensionContainer<AdditionalSpecialSubframe_Info_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<AdditionalSpecialSubframe_Info_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(additionalspecialSubframePatterns);
		v(cyclicPrefixDL);
		v(cyclicPrefixUL);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(additionalspecialSubframePatterns);
		v(cyclicPrefixDL);
		v(cyclicPrefixUL);
		v(iE_Extensions);

	};
	void clear()
	{
		additionalspecialSubframePatterns.clear();
		cyclicPrefixDL.clear();
		cyclicPrefixUL.clear();
		iE_Extensions.clear();

	};
	private:
	additionalspecialSubframePatterns_t	additionalspecialSubframePatterns;
	cyclicPrefixDL_t	cyclicPrefixDL;
	cyclicPrefixUL_t	cyclicPrefixUL;
	iE_Extensions_t	iE_Extensions;

};
/*
AdditionalSpecialSubframePatternsExtension ::= ENUMERATED {
	ssp10,
	...
}
*/

struct AdditionalSpecialSubframePatternsExtension : asn::enumerated<1, 0, true>
{
	static constexpr const char* name() {return "AdditionalSpecialSubframePatternsExtension";}
	using parent_t = asn::enumerated<1, 0, true>;
	typedef enum {
		ssp10
	} index_t;

};

/*
AdditionalSpecialSubframeExtension-Info-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct AdditionalSpecialSubframeExtension_Info_ExtIEs
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
AdditionalSpecialSubframeExtension-Info ::=		SEQUENCE {
	additionalspecialSubframePatternsExtension	AdditionalSpecialSubframePatternsExtension,
	cyclicPrefixDL								CyclicPrefixDL,
	cyclicPrefixUL								CyclicPrefixUL,
	iE-Extensions								ProtocolExtensionContainer { {AdditionalSpecialSubframeExtension-Info-ExtIEs} } OPTIONAL,
	...
}
*/

struct AdditionalSpecialSubframeExtension_Info : asn::sequence<4, 0, true, 1>
{
	static constexpr const char* name() {return "AdditionalSpecialSubframeExtension-Info";}
	using parent_t = asn::sequence<4, 0, true, 1>;
	struct additionalspecialSubframePatternsExtension_t : AdditionalSpecialSubframePatternsExtension
	{
		static constexpr const char* name() {return "additionalspecialSubframePatternsExtension_t";}
		using parent_t = AdditionalSpecialSubframePatternsExtension;

	};
	additionalspecialSubframePatternsExtension_t& ref_additionalspecialSubframePatternsExtension() {return additionalspecialSubframePatternsExtension;}
	additionalspecialSubframePatternsExtension_t const& ref_additionalspecialSubframePatternsExtension() const {return additionalspecialSubframePatternsExtension;}
	struct cyclicPrefixDL_t : CyclicPrefixDL
	{
		static constexpr const char* name() {return "cyclicPrefixDL_t";}
		using parent_t = CyclicPrefixDL;

	};
	cyclicPrefixDL_t& ref_cyclicPrefixDL() {return cyclicPrefixDL;}
	cyclicPrefixDL_t const& ref_cyclicPrefixDL() const {return cyclicPrefixDL;}
	struct cyclicPrefixUL_t : CyclicPrefixUL
	{
		static constexpr const char* name() {return "cyclicPrefixUL_t";}
		using parent_t = CyclicPrefixUL;

	};
	cyclicPrefixUL_t& ref_cyclicPrefixUL() {return cyclicPrefixUL;}
	cyclicPrefixUL_t const& ref_cyclicPrefixUL() const {return cyclicPrefixUL;}
	struct iE_Extensions_t : ProtocolExtensionContainer<AdditionalSpecialSubframeExtension_Info_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<AdditionalSpecialSubframeExtension_Info_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(additionalspecialSubframePatternsExtension);
		v(cyclicPrefixDL);
		v(cyclicPrefixUL);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(additionalspecialSubframePatternsExtension);
		v(cyclicPrefixDL);
		v(cyclicPrefixUL);
		v(iE_Extensions);

	};
	void clear()
	{
		additionalspecialSubframePatternsExtension.clear();
		cyclicPrefixDL.clear();
		cyclicPrefixUL.clear();
		iE_Extensions.clear();

	};
	private:
	additionalspecialSubframePatternsExtension_t	additionalspecialSubframePatternsExtension;
	cyclicPrefixDL_t	cyclicPrefixDL;
	cyclicPrefixUL_t	cyclicPrefixUL;
	iE_Extensions_t	iE_Extensions;

};
/*
AerialUEsubscriptionInformation ::= ENUMERATED {
	allowed,
	not-allowed,
	...
}
*/

struct AerialUEsubscriptionInformation : asn::enumerated<2, 0, true>
{
	static constexpr const char* name() {return "AerialUEsubscriptionInformation";}
	using parent_t = asn::enumerated<2, 0, true>;
	typedef enum {
		allowed
		,not_allowed
	} index_t;

};

/*
PriorityLevel				::= INTEGER { spare (0), highest (1), lowest (14), no-priority (15) } (0..15)
*/

struct PriorityLevel : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 15>>;
	static constexpr const char* name() {return "PriorityLevel";}
	using parent_t = asn::integer<>;
	enum {spare = 0, highest = 1, lowest = 14, no_priority = 15};

};

/*
Pre-emptionCapability ::= ENUMERATED {
	shall-not-trigger-pre-emption,
	may-trigger-pre-emption
}
*/

struct Pre_emptionCapability : asn::enumerated<2, 0, false>
{
	static constexpr const char* name() {return "Pre-emptionCapability";}
	using parent_t = asn::enumerated<2, 0, false>;
	typedef enum {
		shall_not_trigger_pre_emption
		,may_trigger_pre_emption
	} index_t;

};

/*
Pre-emptionVulnerability ::= ENUMERATED {
	not-pre-emptable,
	pre-emptable
}
*/

struct Pre_emptionVulnerability : asn::enumerated<2, 0, false>
{
	static constexpr const char* name() {return "Pre-emptionVulnerability";}
	using parent_t = asn::enumerated<2, 0, false>;
	typedef enum {
		not_pre_emptable
		,pre_emptable
	} index_t;

};

/*
AllocationAndRetentionPriority-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct AllocationAndRetentionPriority_ExtIEs
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
AllocationAndRetentionPriority ::= SEQUENCE {
	priorityLevel				PriorityLevel,
	pre-emptionCapability		Pre-emptionCapability,
	pre-emptionVulnerability	Pre-emptionVulnerability,
	iE-Extensions				ProtocolExtensionContainer { {AllocationAndRetentionPriority-ExtIEs} } OPTIONAL,
	...
}
*/

struct AllocationAndRetentionPriority : asn::sequence<4, 0, true, 1>
{
	static constexpr const char* name() {return "AllocationAndRetentionPriority";}
	using parent_t = asn::sequence<4, 0, true, 1>;
	struct priorityLevel_t : PriorityLevel
	{
		static constexpr const char* name() {return "priorityLevel_t";}
		using parent_t = PriorityLevel;

	};
	priorityLevel_t& ref_priorityLevel() {return priorityLevel;}
	priorityLevel_t const& ref_priorityLevel() const {return priorityLevel;}
	struct pre_emptionCapability_t : Pre_emptionCapability
	{
		static constexpr const char* name() {return "pre_emptionCapability_t";}
		using parent_t = Pre_emptionCapability;

	};
	pre_emptionCapability_t& ref_pre_emptionCapability() {return pre_emptionCapability;}
	pre_emptionCapability_t const& ref_pre_emptionCapability() const {return pre_emptionCapability;}
	struct pre_emptionVulnerability_t : Pre_emptionVulnerability
	{
		static constexpr const char* name() {return "pre_emptionVulnerability_t";}
		using parent_t = Pre_emptionVulnerability;

	};
	pre_emptionVulnerability_t& ref_pre_emptionVulnerability() {return pre_emptionVulnerability;}
	pre_emptionVulnerability_t const& ref_pre_emptionVulnerability() const {return pre_emptionVulnerability;}
	struct iE_Extensions_t : ProtocolExtensionContainer<AllocationAndRetentionPriority_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<AllocationAndRetentionPriority_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(priorityLevel);
		v(pre_emptionCapability);
		v(pre_emptionVulnerability);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(priorityLevel);
		v(pre_emptionCapability);
		v(pre_emptionVulnerability);
		v(iE_Extensions);

	};
	void clear()
	{
		priorityLevel.clear();
		pre_emptionCapability.clear();
		pre_emptionVulnerability.clear();
		iE_Extensions.clear();

	};
	private:
	priorityLevel_t	priorityLevel;
	pre_emptionCapability_t	pre_emptionCapability;
	pre_emptionVulnerability_t	pre_emptionVulnerability;
	iE_Extensions_t	iE_Extensions;

};
/*
PLMN-Identity ::= OCTET STRING (SIZE(3))
*/

struct PLMN_Identity : asn::ostring<>
{
	using constraint_t = asn::constraints<false,asn::one<3>>;
	static constexpr const char* name() {return "PLMN-Identity";}
	using parent_t = asn::ostring<>;

};

/*
EUTRANCellIdentifier ::= BIT STRING (SIZE (28))
*/

struct EUTRANCellIdentifier : asn::bstring<>
{
	using constraint_t = asn::constraints<false,asn::one<28>>;
	static constexpr const char* name() {return "EUTRANCellIdentifier";}
	using parent_t = asn::bstring<>;

};

/*
ECGI-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct ECGI_ExtIEs
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
ECGI ::= SEQUENCE {
	pLMN-Identity				PLMN-Identity,
	eUTRANcellIdentifier		EUTRANCellIdentifier,
	iE-Extensions				ProtocolExtensionContainer { {ECGI-ExtIEs} } OPTIONAL,
	...
}
*/

struct ECGI : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "ECGI";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct pLMN_Identity_t : PLMN_Identity
	{
		static constexpr const char* name() {return "pLMN_Identity_t";}
		using parent_t = PLMN_Identity;

	};
	pLMN_Identity_t& ref_pLMN_Identity() {return pLMN_Identity;}
	pLMN_Identity_t const& ref_pLMN_Identity() const {return pLMN_Identity;}
	struct eUTRANcellIdentifier_t : EUTRANCellIdentifier
	{
		static constexpr const char* name() {return "eUTRANcellIdentifier_t";}
		using parent_t = EUTRANCellIdentifier;

	};
	eUTRANcellIdentifier_t& ref_eUTRANcellIdentifier() {return eUTRANcellIdentifier;}
	eUTRANcellIdentifier_t const& ref_eUTRANcellIdentifier() const {return eUTRANcellIdentifier;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ECGI_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ECGI_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(pLMN_Identity);
		v(eUTRANcellIdentifier);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(pLMN_Identity);
		v(eUTRANcellIdentifier);
		v(iE_Extensions);

	};
	void clear()
	{
		pLMN_Identity.clear();
		eUTRANcellIdentifier.clear();
		iE_Extensions.clear();

	};
	private:
	pLMN_Identity_t	pLMN_Identity;
	eUTRANcellIdentifier_t	eUTRANcellIdentifier;
	iE_Extensions_t	iE_Extensions;

};
/*
CellIdListforMDT ::= SEQUENCE (SIZE(1..maxnoofCellIDforMDT)) OF ECGI
*/

struct CellIdListforMDT_elm : ECGI
{
	static constexpr const char* name() {return "CellIdListforMDT_elm";}
	using parent_t = ECGI;

};
struct CellIdListforMDT : asn::sequenceof<CellIdListforMDT_elm>
{
	static constexpr const char* name() {return "CellIdListforMDT";}
	using parent_t = asn::sequenceof<CellIdListforMDT_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofCellIDforMDT >>;

};
/*
CellBasedMDT-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct CellBasedMDT_ExtIEs
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
CellBasedMDT::= SEQUENCE {
	cellIdListforMDT	CellIdListforMDT,
	iE-Extensions		ProtocolExtensionContainer { {CellBasedMDT-ExtIEs} } OPTIONAL,
	...
}
*/

struct CellBasedMDT : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "CellBasedMDT";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct cellIdListforMDT_t : CellIdListforMDT
	{
		static constexpr const char* name() {return "cellIdListforMDT_t";}
		using parent_t = CellIdListforMDT;

	};
	cellIdListforMDT_t& ref_cellIdListforMDT() {return cellIdListforMDT;}
	cellIdListforMDT_t const& ref_cellIdListforMDT() const {return cellIdListforMDT;}
	struct iE_Extensions_t : ProtocolExtensionContainer<CellBasedMDT_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<CellBasedMDT_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(cellIdListforMDT);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(cellIdListforMDT);
		v(iE_Extensions);

	};
	void clear()
	{
		cellIdListforMDT.clear();
		iE_Extensions.clear();

	};
	private:
	cellIdListforMDT_t	cellIdListforMDT;
	iE_Extensions_t	iE_Extensions;

};
/*
TAC ::= OCTET STRING (SIZE (2))
*/

struct TAC : asn::ostring<>
{
	using constraint_t = asn::constraints<false,asn::one<2>>;
	static constexpr const char* name() {return "TAC";}
	using parent_t = asn::ostring<>;

};

/*
TAListforMDT ::= SEQUENCE (SIZE(1..maxnoofTAforMDT)) OF TAC
*/

struct TAListforMDT_elm : TAC
{
	static constexpr const char* name() {return "TAListforMDT_elm";}
	using parent_t = TAC;

};
struct TAListforMDT : asn::sequenceof<TAListforMDT_elm>
{
	static constexpr const char* name() {return "TAListforMDT";}
	using parent_t = asn::sequenceof<TAListforMDT_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofTAforMDT >>;

};
/*
TABasedMDT-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct TABasedMDT_ExtIEs
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
TABasedMDT::= SEQUENCE {
	tAListforMDT		TAListforMDT,
	iE-Extensions		ProtocolExtensionContainer { {TABasedMDT-ExtIEs} } OPTIONAL,
	...
}
*/

struct TABasedMDT : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "TABasedMDT";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct tAListforMDT_t : TAListforMDT
	{
		static constexpr const char* name() {return "tAListforMDT_t";}
		using parent_t = TAListforMDT;

	};
	tAListforMDT_t& ref_tAListforMDT() {return tAListforMDT;}
	tAListforMDT_t const& ref_tAListforMDT() const {return tAListforMDT;}
	struct iE_Extensions_t : ProtocolExtensionContainer<TABasedMDT_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<TABasedMDT_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(tAListforMDT);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(tAListforMDT);
		v(iE_Extensions);

	};
	void clear()
	{
		tAListforMDT.clear();
		iE_Extensions.clear();

	};
	private:
	tAListforMDT_t	tAListforMDT;
	iE_Extensions_t	iE_Extensions;

};
/*
TAI-Item-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct TAI_Item_ExtIEs
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
TAI-Item ::= SEQUENCE {
	tAC					TAC,
	pLMN-Identity		PLMN-Identity,
	iE-Extensions		ProtocolExtensionContainer { {TAI-Item-ExtIEs} } OPTIONAL,
	...
}
*/

struct TAI_Item : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "TAI-Item";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct tAC_t : TAC
	{
		static constexpr const char* name() {return "tAC_t";}
		using parent_t = TAC;

	};
	tAC_t& ref_tAC() {return tAC;}
	tAC_t const& ref_tAC() const {return tAC;}
	struct pLMN_Identity_t : PLMN_Identity
	{
		static constexpr const char* name() {return "pLMN_Identity_t";}
		using parent_t = PLMN_Identity;

	};
	pLMN_Identity_t& ref_pLMN_Identity() {return pLMN_Identity;}
	pLMN_Identity_t const& ref_pLMN_Identity() const {return pLMN_Identity;}
	struct iE_Extensions_t : ProtocolExtensionContainer<TAI_Item_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<TAI_Item_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(tAC);
		v(pLMN_Identity);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(tAC);
		v(pLMN_Identity);
		v(iE_Extensions);

	};
	void clear()
	{
		tAC.clear();
		pLMN_Identity.clear();
		iE_Extensions.clear();

	};
	private:
	tAC_t	tAC;
	pLMN_Identity_t	pLMN_Identity;
	iE_Extensions_t	iE_Extensions;

};
/*
TAIListforMDT ::= SEQUENCE (SIZE(1..maxnoofTAforMDT)) OF TAI-Item
*/

struct TAIListforMDT_elm : TAI_Item
{
	static constexpr const char* name() {return "TAIListforMDT_elm";}
	using parent_t = TAI_Item;

};
struct TAIListforMDT : asn::sequenceof<TAIListforMDT_elm>
{
	static constexpr const char* name() {return "TAIListforMDT";}
	using parent_t = asn::sequenceof<TAIListforMDT_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofTAforMDT >>;

};
/*
TAIBasedMDT-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct TAIBasedMDT_ExtIEs
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
TAIBasedMDT ::= SEQUENCE {
	tAIListforMDT			TAIListforMDT,
	iE-Extensions			ProtocolExtensionContainer { {TAIBasedMDT-ExtIEs} } OPTIONAL,
	...
}
*/

struct TAIBasedMDT : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "TAIBasedMDT";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct tAIListforMDT_t : TAIListforMDT
	{
		static constexpr const char* name() {return "tAIListforMDT_t";}
		using parent_t = TAIListforMDT;

	};
	tAIListforMDT_t& ref_tAIListforMDT() {return tAIListforMDT;}
	tAIListforMDT_t const& ref_tAIListforMDT() const {return tAIListforMDT;}
	struct iE_Extensions_t : ProtocolExtensionContainer<TAIBasedMDT_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<TAIBasedMDT_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(tAIListforMDT);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(tAIListforMDT);
		v(iE_Extensions);

	};
	void clear()
	{
		tAIListforMDT.clear();
		iE_Extensions.clear();

	};
	private:
	tAIListforMDT_t	tAIListforMDT;
	iE_Extensions_t	iE_Extensions;

};
/*
AreaScopeOfMDT ::= CHOICE {
	cellBased					CellBasedMDT,
	tABased						TABasedMDT,
	pLMNWide					NULL,
	...,
	tAIBased					TAIBasedMDT
}
*/

struct AreaScopeOfMDT : asn::choice<4, 1, true>
{
	static constexpr const char* name() {return "AreaScopeOfMDT";}
	using parent_t = asn::choice<4, 1, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 5;}
	void set_unknown() { set_index(5);  }
	~AreaScopeOfMDT() {clear();}
	struct cellBased_t : CellBasedMDT
	{
		static constexpr const char* name() {return "cellBased_t";}
		using parent_t = CellBasedMDT;

	};
	struct tABased_t : TABasedMDT
	{
		static constexpr const char* name() {return "tABased_t";}
		using parent_t = TABasedMDT;

	};
	struct pLMNWide_t : asn::nulltype
	{
		static constexpr const char* name() {return "pLMNWide_t";}
		using parent_t = asn::nulltype;

	};
	struct tAIBased_t : TAIBasedMDT
	{
		static constexpr const char* name() {return "tAIBased_t";}
		using parent_t = TAIBasedMDT;

	};
	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<cellBased_t>(); break;
		case 2: var.destroy<tABased_t>(); break;
		case 3: var.destroy<pLMNWide_t>(); break;
		case 4: var.destroy<tAIBased_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<cellBased_t>());
		case 2: set_index(2); return v(var.build<tABased_t>());
		case 3: set_index(3); return v(var.build<pLMNWide_t>());
		case 4: set_index(4); return v(var.build<tAIBased_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<cellBased_t>());
		case 2: return v(var.as<tABased_t>());
		case 3: return v(var.as<pLMNWide_t>());
		case 4: return v(var.as<tAIBased_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<cellBased_t>(1);
		v.template operator()<tABased_t>(2);
		v.template operator()<pLMNWide_t>(3);
		v.template operator()<tAIBased_t>(4);

	}
	cellBased_t& select_cellBased() { if(get_index() != 1) { clear(); set_index(1); return var.build<cellBased_t>();} return var.as<cellBased_t>();}
	cellBased_t const* get_cellBased() const { if(get_index() == 1) { return &var.as<cellBased_t>();} return nullptr; }
	tABased_t& select_tABased() { if(get_index() != 2) { clear(); set_index(2); return var.build<tABased_t>();} return var.as<tABased_t>();}
	tABased_t const* get_tABased() const { if(get_index() == 2) { return &var.as<tABased_t>();} return nullptr; }
	pLMNWide_t& select_pLMNWide() { if(get_index() != 3) { clear(); set_index(3); return var.build<pLMNWide_t>();} return var.as<pLMNWide_t>();}
	pLMNWide_t const* get_pLMNWide() const { if(get_index() == 3) { return &var.as<pLMNWide_t>();} return nullptr; }
	tAIBased_t& select_tAIBased() { if(get_index() != 4) { clear(); set_index(4); return var.build<tAIBased_t>();} return var.as<tAIBased_t>();}
	tAIBased_t const* get_tAIBased() const { if(get_index() == 4) { return &var.as<tAIBased_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(cellBased_t)];
		char dummy2[sizeof(tABased_t)];
		char dummy3[sizeof(pLMNWide_t)];
		char dummy4[sizeof(tAIBased_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
CellIdListforQMC ::= SEQUENCE (SIZE(1..maxnoofCellIDforQMC)) OF ECGI
*/

struct CellIdListforQMC_elm : ECGI
{
	static constexpr const char* name() {return "CellIdListforQMC_elm";}
	using parent_t = ECGI;

};
struct CellIdListforQMC : asn::sequenceof<CellIdListforQMC_elm>
{
	static constexpr const char* name() {return "CellIdListforQMC";}
	using parent_t = asn::sequenceof<CellIdListforQMC_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofCellIDforQMC >>;

};
/*
CellBasedQMC-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct CellBasedQMC_ExtIEs
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
CellBasedQMC::= SEQUENCE {
	cellIdListforQMC		CellIdListforQMC,
	iE-Extensions		ProtocolExtensionContainer { {CellBasedQMC-ExtIEs} } OPTIONAL,
	...
}
*/

struct CellBasedQMC : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "CellBasedQMC";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct cellIdListforQMC_t : CellIdListforQMC
	{
		static constexpr const char* name() {return "cellIdListforQMC_t";}
		using parent_t = CellIdListforQMC;

	};
	cellIdListforQMC_t& ref_cellIdListforQMC() {return cellIdListforQMC;}
	cellIdListforQMC_t const& ref_cellIdListforQMC() const {return cellIdListforQMC;}
	struct iE_Extensions_t : ProtocolExtensionContainer<CellBasedQMC_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<CellBasedQMC_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(cellIdListforQMC);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(cellIdListforQMC);
		v(iE_Extensions);

	};
	void clear()
	{
		cellIdListforQMC.clear();
		iE_Extensions.clear();

	};
	private:
	cellIdListforQMC_t	cellIdListforQMC;
	iE_Extensions_t	iE_Extensions;

};
/*
TAListforQMC ::= SEQUENCE (SIZE(1..maxnoofTAforQMC)) OF TAC
*/

struct TAListforQMC_elm : TAC
{
	static constexpr const char* name() {return "TAListforQMC_elm";}
	using parent_t = TAC;

};
struct TAListforQMC : asn::sequenceof<TAListforQMC_elm>
{
	static constexpr const char* name() {return "TAListforQMC";}
	using parent_t = asn::sequenceof<TAListforQMC_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofTAforQMC >>;

};
/*
TABasedQMC-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct TABasedQMC_ExtIEs
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
TABasedQMC ::= SEQUENCE {
	tAListforQMC		TAListforQMC,
	iE-Extensions		ProtocolExtensionContainer { {TABasedQMC-ExtIEs} } OPTIONAL,
	...
}
*/

struct TABasedQMC : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "TABasedQMC";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct tAListforQMC_t : TAListforQMC
	{
		static constexpr const char* name() {return "tAListforQMC_t";}
		using parent_t = TAListforQMC;

	};
	tAListforQMC_t& ref_tAListforQMC() {return tAListforQMC;}
	tAListforQMC_t const& ref_tAListforQMC() const {return tAListforQMC;}
	struct iE_Extensions_t : ProtocolExtensionContainer<TABasedQMC_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<TABasedQMC_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(tAListforQMC);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(tAListforQMC);
		v(iE_Extensions);

	};
	void clear()
	{
		tAListforQMC.clear();
		iE_Extensions.clear();

	};
	private:
	tAListforQMC_t	tAListforQMC;
	iE_Extensions_t	iE_Extensions;

};
/*
TAIListforQMC ::= SEQUENCE (SIZE(1..maxnoofTAforQMC)) OF TAI-Item
*/

struct TAIListforQMC_elm : TAI_Item
{
	static constexpr const char* name() {return "TAIListforQMC_elm";}
	using parent_t = TAI_Item;

};
struct TAIListforQMC : asn::sequenceof<TAIListforQMC_elm>
{
	static constexpr const char* name() {return "TAIListforQMC";}
	using parent_t = asn::sequenceof<TAIListforQMC_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofTAforQMC >>;

};
/*
TAIBasedQMC-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct TAIBasedQMC_ExtIEs
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
TAIBasedQMC ::= SEQUENCE {
	tAIListforQMC		TAIListforQMC,
	iE-Extensions		ProtocolExtensionContainer { {TAIBasedQMC-ExtIEs} } OPTIONAL,
	...
}
*/

struct TAIBasedQMC : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "TAIBasedQMC";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct tAIListforQMC_t : TAIListforQMC
	{
		static constexpr const char* name() {return "tAIListforQMC_t";}
		using parent_t = TAIListforQMC;

	};
	tAIListforQMC_t& ref_tAIListforQMC() {return tAIListforQMC;}
	tAIListforQMC_t const& ref_tAIListforQMC() const {return tAIListforQMC;}
	struct iE_Extensions_t : ProtocolExtensionContainer<TAIBasedQMC_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<TAIBasedQMC_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(tAIListforQMC);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(tAIListforQMC);
		v(iE_Extensions);

	};
	void clear()
	{
		tAIListforQMC.clear();
		iE_Extensions.clear();

	};
	private:
	tAIListforQMC_t	tAIListforQMC;
	iE_Extensions_t	iE_Extensions;

};
/*
PLMNListforQMC ::= SEQUENCE (SIZE(1..maxnoofPLMNforQMC)) OF PLMN-Identity
*/

struct PLMNListforQMC_elm : PLMN_Identity
{
	static constexpr const char* name() {return "PLMNListforQMC_elm";}
	using parent_t = PLMN_Identity;

};
struct PLMNListforQMC : asn::sequenceof<PLMNListforQMC_elm>
{
	static constexpr const char* name() {return "PLMNListforQMC";}
	using parent_t = asn::sequenceof<PLMNListforQMC_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofPLMNforQMC >>;

};
/*
PLMNAreaBasedQMC-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct PLMNAreaBasedQMC_ExtIEs
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
PLMNAreaBasedQMC ::= SEQUENCE {
	plmnListforQMC		PLMNListforQMC,
	iE-Extensions		ProtocolExtensionContainer { {PLMNAreaBasedQMC-ExtIEs} } OPTIONAL,
	...
}
*/

struct PLMNAreaBasedQMC : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "PLMNAreaBasedQMC";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct plmnListforQMC_t : PLMNListforQMC
	{
		static constexpr const char* name() {return "plmnListforQMC_t";}
		using parent_t = PLMNListforQMC;

	};
	plmnListforQMC_t& ref_plmnListforQMC() {return plmnListforQMC;}
	plmnListforQMC_t const& ref_plmnListforQMC() const {return plmnListforQMC;}
	struct iE_Extensions_t : ProtocolExtensionContainer<PLMNAreaBasedQMC_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<PLMNAreaBasedQMC_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(plmnListforQMC);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(plmnListforQMC);
		v(iE_Extensions);

	};
	void clear()
	{
		plmnListforQMC.clear();
		iE_Extensions.clear();

	};
	private:
	plmnListforQMC_t	plmnListforQMC;
	iE_Extensions_t	iE_Extensions;

};
/*
AreaScopeOfQMC ::= CHOICE {
	cellBased					CellBasedQMC,
	tABased						TABasedQMC,
	tAIBased					TAIBasedQMC,
	pLMNAreaBased				PLMNAreaBasedQMC,
	...
}
*/

struct AreaScopeOfQMC : asn::choice<4, 0, true>
{
	static constexpr const char* name() {return "AreaScopeOfQMC";}
	using parent_t = asn::choice<4, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 5;}
	void set_unknown() { set_index(5);  }
	~AreaScopeOfQMC() {clear();}
	struct cellBased_t : CellBasedQMC
	{
		static constexpr const char* name() {return "cellBased_t";}
		using parent_t = CellBasedQMC;

	};
	struct tABased_t : TABasedQMC
	{
		static constexpr const char* name() {return "tABased_t";}
		using parent_t = TABasedQMC;

	};
	struct tAIBased_t : TAIBasedQMC
	{
		static constexpr const char* name() {return "tAIBased_t";}
		using parent_t = TAIBasedQMC;

	};
	struct pLMNAreaBased_t : PLMNAreaBasedQMC
	{
		static constexpr const char* name() {return "pLMNAreaBased_t";}
		using parent_t = PLMNAreaBasedQMC;

	};
	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<cellBased_t>(); break;
		case 2: var.destroy<tABased_t>(); break;
		case 3: var.destroy<tAIBased_t>(); break;
		case 4: var.destroy<pLMNAreaBased_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<cellBased_t>());
		case 2: set_index(2); return v(var.build<tABased_t>());
		case 3: set_index(3); return v(var.build<tAIBased_t>());
		case 4: set_index(4); return v(var.build<pLMNAreaBased_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<cellBased_t>());
		case 2: return v(var.as<tABased_t>());
		case 3: return v(var.as<tAIBased_t>());
		case 4: return v(var.as<pLMNAreaBased_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<cellBased_t>(1);
		v.template operator()<tABased_t>(2);
		v.template operator()<tAIBased_t>(3);
		v.template operator()<pLMNAreaBased_t>(4);

	}
	cellBased_t& select_cellBased() { if(get_index() != 1) { clear(); set_index(1); return var.build<cellBased_t>();} return var.as<cellBased_t>();}
	cellBased_t const* get_cellBased() const { if(get_index() == 1) { return &var.as<cellBased_t>();} return nullptr; }
	tABased_t& select_tABased() { if(get_index() != 2) { clear(); set_index(2); return var.build<tABased_t>();} return var.as<tABased_t>();}
	tABased_t const* get_tABased() const { if(get_index() == 2) { return &var.as<tABased_t>();} return nullptr; }
	tAIBased_t& select_tAIBased() { if(get_index() != 3) { clear(); set_index(3); return var.build<tAIBased_t>();} return var.as<tAIBased_t>();}
	tAIBased_t const* get_tAIBased() const { if(get_index() == 3) { return &var.as<tAIBased_t>();} return nullptr; }
	pLMNAreaBased_t& select_pLMNAreaBased() { if(get_index() != 4) { clear(); set_index(4); return var.build<pLMNAreaBased_t>();} return var.as<pLMNAreaBased_t>();}
	pLMNAreaBased_t const* get_pLMNAreaBased() const { if(get_index() == 4) { return &var.as<pLMNAreaBased_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(cellBased_t)];
		char dummy2[sizeof(tABased_t)];
		char dummy3[sizeof(tAIBased_t)];
		char dummy4[sizeof(pLMNAreaBased_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
FreqBandIndicator ::= INTEGER (1..256, ...)
*/

struct FreqBandIndicator : asn::integer<>
{
	using constraint_t = asn::constraints<true,asn::span<1, 256>>;
	static constexpr const char* name() {return "FreqBandIndicator";}
	using parent_t = asn::integer<>;

};

/*
BandInfo-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct BandInfo_ExtIEs
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
BandInfo	::= SEQUENCE {
	freqBandIndicator		FreqBandIndicator,
	iE-Extensions			ProtocolExtensionContainer { {BandInfo-ExtIEs} } 	OPTIONAL,
	...
}
*/

struct BandInfo : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "BandInfo";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct freqBandIndicator_t : FreqBandIndicator
	{
		static constexpr const char* name() {return "freqBandIndicator_t";}
		using parent_t = FreqBandIndicator;

	};
	freqBandIndicator_t& ref_freqBandIndicator() {return freqBandIndicator;}
	freqBandIndicator_t const& ref_freqBandIndicator() const {return freqBandIndicator;}
	struct iE_Extensions_t : ProtocolExtensionContainer<BandInfo_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<BandInfo_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(freqBandIndicator);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(freqBandIndicator);
		v(iE_Extensions);

	};
	void clear()
	{
		freqBandIndicator.clear();
		iE_Extensions.clear();

	};
	private:
	freqBandIndicator_t	freqBandIndicator;
	iE_Extensions_t	iE_Extensions;

};
/*
BandwidthReducedSI::= ENUMERATED {
	scheduled,
	...
}
*/

struct BandwidthReducedSI : asn::enumerated<1, 0, true>
{
	static constexpr const char* name() {return "BandwidthReducedSI";}
	using parent_t = asn::enumerated<1, 0, true>;
	typedef enum {
		scheduled
	} index_t;

};

/*
BearerType ::= ENUMERATED {
	non-IP,
	...
}
*/

struct BearerType : asn::enumerated<1, 0, true>
{
	static constexpr const char* name() {return "BearerType";}
	using parent_t = asn::enumerated<1, 0, true>;
	typedef enum {
		non_IP
	} index_t;

};

/*
BenefitMetric ::= INTEGER (-101..100, ...)
*/

struct BenefitMetric : asn::integer<>
{
	using constraint_t = asn::constraints<true,asn::span<-101, 100>>;
	static constexpr const char* name() {return "BenefitMetric";}
	using parent_t = asn::integer<>;

};

/*
BitRate ::= INTEGER (0..10000000000)
*/

struct BitRate : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 10000000000>>;
	static constexpr const char* name() {return "BitRate";}
	using parent_t = asn::integer<>;

};

/*
BluetoothMeasConfig::= ENUMERATED {setup,...}
*/

struct BluetoothMeasConfig : asn::enumerated<1, 0, true>
{
	static constexpr const char* name() {return "BluetoothMeasConfig";}
	using parent_t = asn::enumerated<1, 0, true>;
	typedef enum {
		setup
	} index_t;

};

/*
BluetoothName ::= OCTET STRING (SIZE (1..248))
*/

struct BluetoothName : asn::ostring<>
{
	using constraint_t = asn::constraints<false,asn::span<1, 248>>;
	static constexpr const char* name() {return "BluetoothName";}
	using parent_t = asn::ostring<>;

};

/*
BluetoothMeasConfigNameList ::= SEQUENCE (SIZE(1..maxnoofBluetoothName)) OF BluetoothName
*/

struct BluetoothMeasConfigNameList_elm : BluetoothName
{
	static constexpr const char* name() {return "BluetoothMeasConfigNameList_elm";}
	using parent_t = BluetoothName;

};
struct BluetoothMeasConfigNameList : asn::sequenceof<BluetoothMeasConfigNameList_elm>
{
	static constexpr const char* name() {return "BluetoothMeasConfigNameList";}
	using parent_t = asn::sequenceof<BluetoothMeasConfigNameList_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofBluetoothName >>;

};
/*
BluetoothMeasurementConfiguration-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct BluetoothMeasurementConfiguration_ExtIEs
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
BluetoothMeasurementConfiguration ::= SEQUENCE {
	bluetoothMeasConfig				BluetoothMeasConfig,
	bluetoothMeasConfigNameList		BluetoothMeasConfigNameList			OPTIONAL,
	bt-rssi							ENUMERATED {true, ...}				OPTIONAL,
	iE-Extensions		ProtocolExtensionContainer { {BluetoothMeasurementConfiguration-ExtIEs} } OPTIONAL,
	...
}
*/

struct BluetoothMeasurementConfiguration : asn::sequence<4, 0, true, 3>
{
	static constexpr const char* name() {return "BluetoothMeasurementConfiguration";}
	using parent_t = asn::sequence<4, 0, true, 3>;
	struct bluetoothMeasConfig_t : BluetoothMeasConfig
	{
		static constexpr const char* name() {return "bluetoothMeasConfig_t";}
		using parent_t = BluetoothMeasConfig;

	};
	bluetoothMeasConfig_t& ref_bluetoothMeasConfig() {return bluetoothMeasConfig;}
	bluetoothMeasConfig_t const& ref_bluetoothMeasConfig() const {return bluetoothMeasConfig;}
	struct bluetoothMeasConfigNameList_t : BluetoothMeasConfigNameList
	{
		static constexpr const char* name() {return "bluetoothMeasConfigNameList_t";}
		using parent_t = BluetoothMeasConfigNameList;
		static constexpr bool optional = true;

	};
	bluetoothMeasConfigNameList_t& set_bluetoothMeasConfigNameList() { bluetoothMeasConfigNameList.setpresent(true); return bluetoothMeasConfigNameList;}
	bluetoothMeasConfigNameList_t const* get_bluetoothMeasConfigNameList() const {return bluetoothMeasConfigNameList.is_valid() ? &bluetoothMeasConfigNameList : nullptr;}
	struct bt_rssi_t : asn::enumerated<1, 0, true>
	{
		static constexpr const char* name() {return "bt_rssi_t";}
		using parent_t = asn::enumerated<1, 0, true>;
		static constexpr bool optional = true;
		typedef enum {
			True
		} index_t;

	};

	bt_rssi_t& set_bt_rssi() { bt_rssi.setpresent(true); return bt_rssi;}
	bt_rssi_t const* get_bt_rssi() const {return bt_rssi.is_valid() ? &bt_rssi : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<BluetoothMeasurementConfiguration_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<BluetoothMeasurementConfiguration_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(bluetoothMeasConfig);
		v(bluetoothMeasConfigNameList);
		v(bt_rssi);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(bluetoothMeasConfig);
		v(bluetoothMeasConfigNameList);
		v(bt_rssi);
		v(iE_Extensions);

	};
	void clear()
	{
		bluetoothMeasConfig.clear();
		bluetoothMeasConfigNameList.clear();
		bt_rssi.clear();
		iE_Extensions.clear();

	};
	private:
	bluetoothMeasConfig_t	bluetoothMeasConfig;
	bluetoothMeasConfigNameList_t	bluetoothMeasConfigNameList;
	bt_rssi_t	bt_rssi;
	iE_Extensions_t	iE_Extensions;

};
/*
BroadcastPLMNs-Item ::= SEQUENCE (SIZE(1..maxnoofBPLMNs)) OF PLMN-Identity
*/

struct BroadcastPLMNs_Item_elm : PLMN_Identity
{
	static constexpr const char* name() {return "BroadcastPLMNs_Item_elm";}
	using parent_t = PLMN_Identity;

};
struct BroadcastPLMNs_Item : asn::sequenceof<BroadcastPLMNs_Item_elm>
{
	static constexpr const char* name() {return "BroadcastPLMNs-Item";}
	using parent_t = asn::sequenceof<BroadcastPLMNs_Item_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofBPLMNs >>;

};
/*
CNTypeRestrictionsItem-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct CNTypeRestrictionsItem_ExtIEs
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
CNTypeRestrictionsItem ::= SEQUENCE {
	plmn-Id				PLMN-Identity,
	cn-type				ENUMERATED {fiveGC-forbidden, ...},
	iE-Extensions		ProtocolExtensionContainer { {CNTypeRestrictionsItem-ExtIEs} } OPTIONAL,
	...
}
*/

struct CNTypeRestrictionsItem : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "CNTypeRestrictionsItem";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct plmn_Id_t : PLMN_Identity
	{
		static constexpr const char* name() {return "plmn_Id_t";}
		using parent_t = PLMN_Identity;

	};
	plmn_Id_t& ref_plmn_Id() {return plmn_Id;}
	plmn_Id_t const& ref_plmn_Id() const {return plmn_Id;}
	struct cn_type_t : asn::enumerated<1, 0, true>
	{
		static constexpr const char* name() {return "cn_type_t";}
		using parent_t = asn::enumerated<1, 0, true>;
		typedef enum {
			fiveGC_forbidden
		} index_t;

	};

	cn_type_t& ref_cn_type() {return cn_type;}
	cn_type_t const& ref_cn_type() const {return cn_type;}
	struct iE_Extensions_t : ProtocolExtensionContainer<CNTypeRestrictionsItem_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<CNTypeRestrictionsItem_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(plmn_Id);
		v(cn_type);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(plmn_Id);
		v(cn_type);
		v(iE_Extensions);

	};
	void clear()
	{
		plmn_Id.clear();
		cn_type.clear();
		iE_Extensions.clear();

	};
	private:
	plmn_Id_t	plmn_Id;
	cn_type_t	cn_type;
	iE_Extensions_t	iE_Extensions;

};
/*
CNTypeRestrictions ::= SEQUENCE (SIZE(1.. maxnoofEPLMNsPlusOne)) OF CNTypeRestrictionsItem
*/

struct CNTypeRestrictions_elm : CNTypeRestrictionsItem
{
	static constexpr const char* name() {return "CNTypeRestrictions_elm";}
	using parent_t = CNTypeRestrictionsItem;

};
struct CNTypeRestrictions : asn::sequenceof<CNTypeRestrictions_elm>
{
	static constexpr const char* name() {return "CNTypeRestrictions";}
	using parent_t = asn::sequenceof<CNTypeRestrictions_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofEPLMNsPlusOne >>;

};
/*
PDCP-SNExtended ::= INTEGER (0..32767)
*/

struct PDCP_SNExtended : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 32767>>;
	static constexpr const char* name() {return "PDCP-SNExtended";}
	using parent_t = asn::integer<>;

};

/*
HFNModified ::= INTEGER (0..131071)
*/

struct HFNModified : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 131071>>;
	static constexpr const char* name() {return "HFNModified";}
	using parent_t = asn::integer<>;

};

/*
COUNTValueExtended-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct COUNTValueExtended_ExtIEs
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
COUNTValueExtended ::= SEQUENCE {
	pDCP-SNExtended			PDCP-SNExtended,
	hFNModified				HFNModified,
	iE-Extensions			ProtocolExtensionContainer { {COUNTValueExtended-ExtIEs} } OPTIONAL,
	...
}
*/

struct COUNTValueExtended : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "COUNTValueExtended";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct pDCP_SNExtended_t : PDCP_SNExtended
	{
		static constexpr const char* name() {return "pDCP_SNExtended_t";}
		using parent_t = PDCP_SNExtended;

	};
	pDCP_SNExtended_t& ref_pDCP_SNExtended() {return pDCP_SNExtended;}
	pDCP_SNExtended_t const& ref_pDCP_SNExtended() const {return pDCP_SNExtended;}
	struct hFNModified_t : HFNModified
	{
		static constexpr const char* name() {return "hFNModified_t";}
		using parent_t = HFNModified;

	};
	hFNModified_t& ref_hFNModified() {return hFNModified;}
	hFNModified_t const& ref_hFNModified() const {return hFNModified;}
	struct iE_Extensions_t : ProtocolExtensionContainer<COUNTValueExtended_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<COUNTValueExtended_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(pDCP_SNExtended);
		v(hFNModified);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(pDCP_SNExtended);
		v(hFNModified);
		v(iE_Extensions);

	};
	void clear()
	{
		pDCP_SNExtended.clear();
		hFNModified.clear();
		iE_Extensions.clear();

	};
	private:
	pDCP_SNExtended_t	pDCP_SNExtended;
	hFNModified_t	hFNModified;
	iE_Extensions_t	iE_Extensions;

};
/*
PDCP-SN ::= INTEGER (0..4095)
*/

struct PDCP_SN : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 4095>>;
	static constexpr const char* name() {return "PDCP-SN";}
	using parent_t = asn::integer<>;

};

/*
HFN ::= INTEGER (0..1048575)
*/

struct HFN : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 1048575>>;
	static constexpr const char* name() {return "HFN";}
	using parent_t = asn::integer<>;

};

/*
COUNTvalue-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct COUNTvalue_ExtIEs
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
COUNTvalue ::= SEQUENCE {
	pDCP-SN					PDCP-SN,
	hFN						HFN,
	iE-Extensions			ProtocolExtensionContainer { {COUNTvalue-ExtIEs} } OPTIONAL,
	...
}
*/

struct COUNTvalue : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "COUNTvalue";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct pDCP_SN_t : PDCP_SN
	{
		static constexpr const char* name() {return "pDCP_SN_t";}
		using parent_t = PDCP_SN;

	};
	pDCP_SN_t& ref_pDCP_SN() {return pDCP_SN;}
	pDCP_SN_t const& ref_pDCP_SN() const {return pDCP_SN;}
	struct hFN_t : HFN
	{
		static constexpr const char* name() {return "hFN_t";}
		using parent_t = HFN;

	};
	hFN_t& ref_hFN() {return hFN;}
	hFN_t const& ref_hFN() const {return hFN;}
	struct iE_Extensions_t : ProtocolExtensionContainer<COUNTvalue_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<COUNTvalue_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(pDCP_SN);
		v(hFN);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(pDCP_SN);
		v(hFN);
		v(iE_Extensions);

	};
	void clear()
	{
		pDCP_SN.clear();
		hFN.clear();
		iE_Extensions.clear();

	};
	private:
	pDCP_SN_t	pDCP_SN;
	hFN_t	hFN;
	iE_Extensions_t	iE_Extensions;

};
/*
PDCP-SNlength18 ::= INTEGER (0..262143)
*/

struct PDCP_SNlength18 : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 262143>>;
	static constexpr const char* name() {return "PDCP-SNlength18";}
	using parent_t = asn::integer<>;

};

/*
HFNforPDCP-SNlength18 ::= INTEGER (0..16383)
*/

struct HFNforPDCP_SNlength18 : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 16383>>;
	static constexpr const char* name() {return "HFNforPDCP-SNlength18";}
	using parent_t = asn::integer<>;

};

/*
COUNTvaluePDCP-SNlength18-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct COUNTvaluePDCP_SNlength18_ExtIEs
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
COUNTvaluePDCP-SNlength18 ::= SEQUENCE {
	pDCP-SNlength18			PDCP-SNlength18,
	hFNforPDCP-SNlength18	HFNforPDCP-SNlength18,
	iE-Extensions			ProtocolExtensionContainer { {COUNTvaluePDCP-SNlength18-ExtIEs} } OPTIONAL,
	...
}
*/

struct COUNTvaluePDCP_SNlength18 : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "COUNTvaluePDCP-SNlength18";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct pDCP_SNlength18_t : PDCP_SNlength18
	{
		static constexpr const char* name() {return "pDCP_SNlength18_t";}
		using parent_t = PDCP_SNlength18;

	};
	pDCP_SNlength18_t& ref_pDCP_SNlength18() {return pDCP_SNlength18;}
	pDCP_SNlength18_t const& ref_pDCP_SNlength18() const {return pDCP_SNlength18;}
	struct hFNforPDCP_SNlength18_t : HFNforPDCP_SNlength18
	{
		static constexpr const char* name() {return "hFNforPDCP_SNlength18_t";}
		using parent_t = HFNforPDCP_SNlength18;

	};
	hFNforPDCP_SNlength18_t& ref_hFNforPDCP_SNlength18() {return hFNforPDCP_SNlength18;}
	hFNforPDCP_SNlength18_t const& ref_hFNforPDCP_SNlength18() const {return hFNforPDCP_SNlength18;}
	struct iE_Extensions_t : ProtocolExtensionContainer<COUNTvaluePDCP_SNlength18_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<COUNTvaluePDCP_SNlength18_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(pDCP_SNlength18);
		v(hFNforPDCP_SNlength18);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(pDCP_SNlength18);
		v(hFNforPDCP_SNlength18);
		v(iE_Extensions);

	};
	void clear()
	{
		pDCP_SNlength18.clear();
		hFNforPDCP_SNlength18.clear();
		iE_Extensions.clear();

	};
	private:
	pDCP_SNlength18_t	pDCP_SNlength18;
	hFNforPDCP_SNlength18_t	hFNforPDCP_SNlength18;
	iE_Extensions_t	iE_Extensions;

};
/*
CRNTI ::= BIT STRING (SIZE (16))
*/

struct CRNTI : asn::bstring<>
{
	using constraint_t = asn::constraints<false,asn::one<16>>;
	static constexpr const char* name() {return "CRNTI";}
	using parent_t = asn::bstring<>;

};

/*
CSG-Id ::= BIT STRING (SIZE (27))
*/

struct CSG_Id : asn::bstring<>
{
	using constraint_t = asn::constraints<false,asn::one<27>>;
	static constexpr const char* name() {return "CSG-Id";}
	using parent_t = asn::bstring<>;

};

/*
CSGMembershipStatus ::= ENUMERATED {
	member,
	not-member
}
*/

struct CSGMembershipStatus : asn::enumerated<2, 0, false>
{
	static constexpr const char* name() {return "CSGMembershipStatus";}
	using parent_t = asn::enumerated<2, 0, false>;
	typedef enum {
		member
		,not_member
	} index_t;

};

/*
UEID ::= BIT STRING (SIZE (16))
*/

struct UEID : asn::bstring<>
{
	using constraint_t = asn::constraints<false,asn::one<16>>;
	static constexpr const char* name() {return "UEID";}
	using parent_t = asn::bstring<>;

};

/*
WidebandCQICodeword1::= CHOICE {
	four-bitCQI								INTEGER (0..15, ...),
	three-bitSpatialDifferentialCQI			INTEGER (0..7, ...),
	...
}
*/

struct WidebandCQICodeword1 : asn::choice<2, 0, true>
{
	static constexpr const char* name() {return "WidebandCQICodeword1";}
	using parent_t = asn::choice<2, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 3;}
	void set_unknown() { set_index(3);  }
	~WidebandCQICodeword1() {clear();}
	struct four_bitCQI_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 15>>;
		static constexpr const char* name() {return "four_bitCQI_t";}
		using parent_t = asn::integer<>;

	};

	struct three_bitSpatialDifferentialCQI_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 7>>;
		static constexpr const char* name() {return "three_bitSpatialDifferentialCQI_t";}
		using parent_t = asn::integer<>;

	};

	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<four_bitCQI_t>(); break;
		case 2: var.destroy<three_bitSpatialDifferentialCQI_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<four_bitCQI_t>());
		case 2: set_index(2); return v(var.build<three_bitSpatialDifferentialCQI_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<four_bitCQI_t>());
		case 2: return v(var.as<three_bitSpatialDifferentialCQI_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<four_bitCQI_t>(1);
		v.template operator()<three_bitSpatialDifferentialCQI_t>(2);

	}
	four_bitCQI_t& select_four_bitCQI() { if(get_index() != 1) { clear(); set_index(1); return var.build<four_bitCQI_t>();} return var.as<four_bitCQI_t>();}
	four_bitCQI_t const* get_four_bitCQI() const { if(get_index() == 1) { return &var.as<four_bitCQI_t>();} return nullptr; }
	three_bitSpatialDifferentialCQI_t& select_three_bitSpatialDifferentialCQI() { if(get_index() != 2) { clear(); set_index(2); return var.build<three_bitSpatialDifferentialCQI_t>();} return var.as<three_bitSpatialDifferentialCQI_t>();}
	three_bitSpatialDifferentialCQI_t const* get_three_bitSpatialDifferentialCQI() const { if(get_index() == 2) { return &var.as<three_bitSpatialDifferentialCQI_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(four_bitCQI_t)];
		char dummy2[sizeof(three_bitSpatialDifferentialCQI_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
WidebandCQI-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct WidebandCQI_ExtIEs
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
WidebandCQI ::= SEQUENCE {
	widebandCQICodeword0		INTEGER (0..15, ...),
	widebandCQICodeword1		WidebandCQICodeword1		OPTIONAL,
	iE-Extensions				ProtocolExtensionContainer { {WidebandCQI-ExtIEs} } OPTIONAL,
	...
}
*/

struct WidebandCQI : asn::sequence<3, 0, true, 2>
{
	static constexpr const char* name() {return "WidebandCQI";}
	using parent_t = asn::sequence<3, 0, true, 2>;
	struct widebandCQICodeword0_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 15>>;
		static constexpr const char* name() {return "widebandCQICodeword0_t";}
		using parent_t = asn::integer<>;

	};

	widebandCQICodeword0_t& ref_widebandCQICodeword0() {return widebandCQICodeword0;}
	widebandCQICodeword0_t const& ref_widebandCQICodeword0() const {return widebandCQICodeword0;}
	struct widebandCQICodeword1_t : WidebandCQICodeword1
	{
		static constexpr const char* name() {return "widebandCQICodeword1_t";}
		using parent_t = WidebandCQICodeword1;
		static constexpr bool optional = true;

	};
	widebandCQICodeword1_t& set_widebandCQICodeword1() { widebandCQICodeword1.setpresent(true); return widebandCQICodeword1;}
	widebandCQICodeword1_t const* get_widebandCQICodeword1() const {return widebandCQICodeword1.is_valid() ? &widebandCQICodeword1 : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<WidebandCQI_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<WidebandCQI_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(widebandCQICodeword0);
		v(widebandCQICodeword1);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(widebandCQICodeword0);
		v(widebandCQICodeword1);
		v(iE_Extensions);

	};
	void clear()
	{
		widebandCQICodeword0.clear();
		widebandCQICodeword1.clear();
		iE_Extensions.clear();

	};
	private:
	widebandCQICodeword0_t	widebandCQICodeword0;
	widebandCQICodeword1_t	widebandCQICodeword1;
	iE_Extensions_t	iE_Extensions;

};
/*
SubbandSize ::= ENUMERATED {
	size2,
	size3,
	size4,
	size6,
	size8,
	...
}
*/

struct SubbandSize : asn::enumerated<5, 0, true>
{
	static constexpr const char* name() {return "SubbandSize";}
	using parent_t = asn::enumerated<5, 0, true>;
	typedef enum {
		size2
		,size3
		,size4
		,size6
		,size8
	} index_t;

};

/*
SubbandCQICodeword0 ::= CHOICE {
	four-bitCQI						INTEGER (0..15, ...),
	two-bitSubbandDifferentialCQI	INTEGER (0..3, ...),
	two-bitDifferentialCQI			INTEGER (0..3, ...),
	...
}
*/

struct SubbandCQICodeword0 : asn::choice<3, 0, true>
{
	static constexpr const char* name() {return "SubbandCQICodeword0";}
	using parent_t = asn::choice<3, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 4;}
	void set_unknown() { set_index(4);  }
	~SubbandCQICodeword0() {clear();}
	struct four_bitCQI_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 15>>;
		static constexpr const char* name() {return "four_bitCQI_t";}
		using parent_t = asn::integer<>;

	};

	struct two_bitSubbandDifferentialCQI_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 3>>;
		static constexpr const char* name() {return "two_bitSubbandDifferentialCQI_t";}
		using parent_t = asn::integer<>;

	};

	struct two_bitDifferentialCQI_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 3>>;
		static constexpr const char* name() {return "two_bitDifferentialCQI_t";}
		using parent_t = asn::integer<>;

	};

	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<four_bitCQI_t>(); break;
		case 2: var.destroy<two_bitSubbandDifferentialCQI_t>(); break;
		case 3: var.destroy<two_bitDifferentialCQI_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<four_bitCQI_t>());
		case 2: set_index(2); return v(var.build<two_bitSubbandDifferentialCQI_t>());
		case 3: set_index(3); return v(var.build<two_bitDifferentialCQI_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<four_bitCQI_t>());
		case 2: return v(var.as<two_bitSubbandDifferentialCQI_t>());
		case 3: return v(var.as<two_bitDifferentialCQI_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<four_bitCQI_t>(1);
		v.template operator()<two_bitSubbandDifferentialCQI_t>(2);
		v.template operator()<two_bitDifferentialCQI_t>(3);

	}
	four_bitCQI_t& select_four_bitCQI() { if(get_index() != 1) { clear(); set_index(1); return var.build<four_bitCQI_t>();} return var.as<four_bitCQI_t>();}
	four_bitCQI_t const* get_four_bitCQI() const { if(get_index() == 1) { return &var.as<four_bitCQI_t>();} return nullptr; }
	two_bitSubbandDifferentialCQI_t& select_two_bitSubbandDifferentialCQI() { if(get_index() != 2) { clear(); set_index(2); return var.build<two_bitSubbandDifferentialCQI_t>();} return var.as<two_bitSubbandDifferentialCQI_t>();}
	two_bitSubbandDifferentialCQI_t const* get_two_bitSubbandDifferentialCQI() const { if(get_index() == 2) { return &var.as<two_bitSubbandDifferentialCQI_t>();} return nullptr; }
	two_bitDifferentialCQI_t& select_two_bitDifferentialCQI() { if(get_index() != 3) { clear(); set_index(3); return var.build<two_bitDifferentialCQI_t>();} return var.as<two_bitDifferentialCQI_t>();}
	two_bitDifferentialCQI_t const* get_two_bitDifferentialCQI() const { if(get_index() == 3) { return &var.as<two_bitDifferentialCQI_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(four_bitCQI_t)];
		char dummy2[sizeof(two_bitSubbandDifferentialCQI_t)];
		char dummy3[sizeof(two_bitDifferentialCQI_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
SubbandCQICodeword1 ::= CHOICE {
	four-bitCQI							INTEGER (0..15, ...),
	three-bitSpatialDifferentialCQI		INTEGER (0..7, ...),
	two-bitSubbandDifferentialCQI		INTEGER (0..3, ...),
	two-bitDifferentialCQI				INTEGER (0..3, ...),
	...
}
*/

struct SubbandCQICodeword1 : asn::choice<4, 0, true>
{
	static constexpr const char* name() {return "SubbandCQICodeword1";}
	using parent_t = asn::choice<4, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 5;}
	void set_unknown() { set_index(5);  }
	~SubbandCQICodeword1() {clear();}
	struct four_bitCQI_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 15>>;
		static constexpr const char* name() {return "four_bitCQI_t";}
		using parent_t = asn::integer<>;

	};

	struct three_bitSpatialDifferentialCQI_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 7>>;
		static constexpr const char* name() {return "three_bitSpatialDifferentialCQI_t";}
		using parent_t = asn::integer<>;

	};

	struct two_bitSubbandDifferentialCQI_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 3>>;
		static constexpr const char* name() {return "two_bitSubbandDifferentialCQI_t";}
		using parent_t = asn::integer<>;

	};

	struct two_bitDifferentialCQI_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 3>>;
		static constexpr const char* name() {return "two_bitDifferentialCQI_t";}
		using parent_t = asn::integer<>;

	};

	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<four_bitCQI_t>(); break;
		case 2: var.destroy<three_bitSpatialDifferentialCQI_t>(); break;
		case 3: var.destroy<two_bitSubbandDifferentialCQI_t>(); break;
		case 4: var.destroy<two_bitDifferentialCQI_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<four_bitCQI_t>());
		case 2: set_index(2); return v(var.build<three_bitSpatialDifferentialCQI_t>());
		case 3: set_index(3); return v(var.build<two_bitSubbandDifferentialCQI_t>());
		case 4: set_index(4); return v(var.build<two_bitDifferentialCQI_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<four_bitCQI_t>());
		case 2: return v(var.as<three_bitSpatialDifferentialCQI_t>());
		case 3: return v(var.as<two_bitSubbandDifferentialCQI_t>());
		case 4: return v(var.as<two_bitDifferentialCQI_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<four_bitCQI_t>(1);
		v.template operator()<three_bitSpatialDifferentialCQI_t>(2);
		v.template operator()<two_bitSubbandDifferentialCQI_t>(3);
		v.template operator()<two_bitDifferentialCQI_t>(4);

	}
	four_bitCQI_t& select_four_bitCQI() { if(get_index() != 1) { clear(); set_index(1); return var.build<four_bitCQI_t>();} return var.as<four_bitCQI_t>();}
	four_bitCQI_t const* get_four_bitCQI() const { if(get_index() == 1) { return &var.as<four_bitCQI_t>();} return nullptr; }
	three_bitSpatialDifferentialCQI_t& select_three_bitSpatialDifferentialCQI() { if(get_index() != 2) { clear(); set_index(2); return var.build<three_bitSpatialDifferentialCQI_t>();} return var.as<three_bitSpatialDifferentialCQI_t>();}
	three_bitSpatialDifferentialCQI_t const* get_three_bitSpatialDifferentialCQI() const { if(get_index() == 2) { return &var.as<three_bitSpatialDifferentialCQI_t>();} return nullptr; }
	two_bitSubbandDifferentialCQI_t& select_two_bitSubbandDifferentialCQI() { if(get_index() != 3) { clear(); set_index(3); return var.build<two_bitSubbandDifferentialCQI_t>();} return var.as<two_bitSubbandDifferentialCQI_t>();}
	two_bitSubbandDifferentialCQI_t const* get_two_bitSubbandDifferentialCQI() const { if(get_index() == 3) { return &var.as<two_bitSubbandDifferentialCQI_t>();} return nullptr; }
	two_bitDifferentialCQI_t& select_two_bitDifferentialCQI() { if(get_index() != 4) { clear(); set_index(4); return var.build<two_bitDifferentialCQI_t>();} return var.as<two_bitDifferentialCQI_t>();}
	two_bitDifferentialCQI_t const* get_two_bitDifferentialCQI() const { if(get_index() == 4) { return &var.as<two_bitDifferentialCQI_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(four_bitCQI_t)];
		char dummy2[sizeof(three_bitSpatialDifferentialCQI_t)];
		char dummy3[sizeof(two_bitSubbandDifferentialCQI_t)];
		char dummy4[sizeof(two_bitDifferentialCQI_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
SubbandCQI-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct SubbandCQI_ExtIEs
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
SubbandCQI ::= SEQUENCE {
	subbandCQICodeword0			SubbandCQICodeword0,
	subbandCQICodeword1			SubbandCQICodeword1		OPTIONAL,
	iE-Extensions				ProtocolExtensionContainer { {SubbandCQI-ExtIEs} } OPTIONAL,
	...
}
*/

struct SubbandCQI : asn::sequence<3, 0, true, 2>
{
	static constexpr const char* name() {return "SubbandCQI";}
	using parent_t = asn::sequence<3, 0, true, 2>;
	struct subbandCQICodeword0_t : SubbandCQICodeword0
	{
		static constexpr const char* name() {return "subbandCQICodeword0_t";}
		using parent_t = SubbandCQICodeword0;

	};
	subbandCQICodeword0_t& ref_subbandCQICodeword0() {return subbandCQICodeword0;}
	subbandCQICodeword0_t const& ref_subbandCQICodeword0() const {return subbandCQICodeword0;}
	struct subbandCQICodeword1_t : SubbandCQICodeword1
	{
		static constexpr const char* name() {return "subbandCQICodeword1_t";}
		using parent_t = SubbandCQICodeword1;
		static constexpr bool optional = true;

	};
	subbandCQICodeword1_t& set_subbandCQICodeword1() { subbandCQICodeword1.setpresent(true); return subbandCQICodeword1;}
	subbandCQICodeword1_t const* get_subbandCQICodeword1() const {return subbandCQICodeword1.is_valid() ? &subbandCQICodeword1 : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<SubbandCQI_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<SubbandCQI_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(subbandCQICodeword0);
		v(subbandCQICodeword1);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(subbandCQICodeword0);
		v(subbandCQICodeword1);
		v(iE_Extensions);

	};
	void clear()
	{
		subbandCQICodeword0.clear();
		subbandCQICodeword1.clear();
		iE_Extensions.clear();

	};
	private:
	subbandCQICodeword0_t	subbandCQICodeword0;
	subbandCQICodeword1_t	subbandCQICodeword1;
	iE_Extensions_t	iE_Extensions;

};
/*
SubbandCQIItem-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct SubbandCQIItem_ExtIEs
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
SubbandCQIItem ::= SEQUENCE {
	subbandCQI			SubbandCQI,
	subbandIndex		INTEGER (0..27,...),
	iE-Extensions		ProtocolExtensionContainer { {SubbandCQIItem-ExtIEs} } OPTIONAL,
	...
}
*/

struct SubbandCQIItem : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "SubbandCQIItem";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct subbandCQI_t : SubbandCQI
	{
		static constexpr const char* name() {return "subbandCQI_t";}
		using parent_t = SubbandCQI;

	};
	subbandCQI_t& ref_subbandCQI() {return subbandCQI;}
	subbandCQI_t const& ref_subbandCQI() const {return subbandCQI;}
	struct subbandIndex_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 27>>;
		static constexpr const char* name() {return "subbandIndex_t";}
		using parent_t = asn::integer<>;

	};

	subbandIndex_t& ref_subbandIndex() {return subbandIndex;}
	subbandIndex_t const& ref_subbandIndex() const {return subbandIndex;}
	struct iE_Extensions_t : ProtocolExtensionContainer<SubbandCQIItem_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<SubbandCQIItem_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(subbandCQI);
		v(subbandIndex);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(subbandCQI);
		v(subbandIndex);
		v(iE_Extensions);

	};
	void clear()
	{
		subbandCQI.clear();
		subbandIndex.clear();
		iE_Extensions.clear();

	};
	private:
	subbandCQI_t	subbandCQI;
	subbandIndex_t	subbandIndex;
	iE_Extensions_t	iE_Extensions;

};
/*
SubbandCQIList ::= SEQUENCE (SIZE(1.. maxSubband)) OF SubbandCQIItem
*/

struct SubbandCQIList_elm : SubbandCQIItem
{
	static constexpr const char* name() {return "SubbandCQIList_elm";}
	using parent_t = SubbandCQIItem;

};
struct SubbandCQIList : asn::sequenceof<SubbandCQIList_elm>
{
	static constexpr const char* name() {return "SubbandCQIList";}
	using parent_t = asn::sequenceof<SubbandCQIList_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxSubband >>;

};
/*
CSIReportPerCSIProcessItem-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct CSIReportPerCSIProcessItem_ExtIEs
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
CSIReportPerCSIProcessItem ::= SEQUENCE (SIZE(1.. maxCSIReport)) OF
	SEQUENCE {
		rI								INTEGER (1..8, ...),
		widebandCQI						WidebandCQI,
		subbandSize						SubbandSize,
		subbandCQIList					SubbandCQIList	OPTIONAL,
		iE-Extensions					ProtocolExtensionContainer { {CSIReportPerCSIProcessItem-ExtIEs} } OPTIONAL,
		...
	}
*/

struct CSIReportPerCSIProcessItem_elm : asn::sequence<5, 0, true, 2>
{
	static constexpr const char* name() {return "CSIReportPerCSIProcessItem_elm";}
	using parent_t = asn::sequence<5, 0, true, 2>;
	struct rI_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<1, 8>>;
		static constexpr const char* name() {return "rI_t";}
		using parent_t = asn::integer<>;

	};

	rI_t& ref_rI() {return rI;}
	rI_t const& ref_rI() const {return rI;}
	struct widebandCQI_t : WidebandCQI
	{
		static constexpr const char* name() {return "widebandCQI_t";}
		using parent_t = WidebandCQI;

	};
	widebandCQI_t& ref_widebandCQI() {return widebandCQI;}
	widebandCQI_t const& ref_widebandCQI() const {return widebandCQI;}
	struct subbandSize_t : SubbandSize
	{
		static constexpr const char* name() {return "subbandSize_t";}
		using parent_t = SubbandSize;

	};
	subbandSize_t& ref_subbandSize() {return subbandSize;}
	subbandSize_t const& ref_subbandSize() const {return subbandSize;}
	struct subbandCQIList_t : SubbandCQIList
	{
		static constexpr const char* name() {return "subbandCQIList_t";}
		using parent_t = SubbandCQIList;
		static constexpr bool optional = true;

	};
	subbandCQIList_t& set_subbandCQIList() { subbandCQIList.setpresent(true); return subbandCQIList;}
	subbandCQIList_t const* get_subbandCQIList() const {return subbandCQIList.is_valid() ? &subbandCQIList : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<CSIReportPerCSIProcessItem_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<CSIReportPerCSIProcessItem_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(rI);
		v(widebandCQI);
		v(subbandSize);
		v(subbandCQIList);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(rI);
		v(widebandCQI);
		v(subbandSize);
		v(subbandCQIList);
		v(iE_Extensions);

	};
	void clear()
	{
		rI.clear();
		widebandCQI.clear();
		subbandSize.clear();
		subbandCQIList.clear();
		iE_Extensions.clear();

	};
	private:
	rI_t	rI;
	widebandCQI_t	widebandCQI;
	subbandSize_t	subbandSize;
	subbandCQIList_t	subbandCQIList;
	iE_Extensions_t	iE_Extensions;

};
struct CSIReportPerCSIProcessItem : asn::sequenceof<CSIReportPerCSIProcessItem_elm>
{
	static constexpr const char* name() {return "CSIReportPerCSIProcessItem";}
	using parent_t = asn::sequenceof<CSIReportPerCSIProcessItem_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxCSIReport >>;

};
/*
CSIReportPerCSIProcess-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct CSIReportPerCSIProcess_ExtIEs
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
CSIReportPerCSIProcess ::= SEQUENCE (SIZE(1.. maxCSIProcess)) OF
	SEQUENCE {
		cSIProcessConfigurationIndex	INTEGER (1..7, ...),
		cSIReportPerCSIProcessItem		CSIReportPerCSIProcessItem,
		iE-Extensions					ProtocolExtensionContainer { {CSIReportPerCSIProcess-ExtIEs} } OPTIONAL,
		...
	}
*/

struct CSIReportPerCSIProcess_elm : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "CSIReportPerCSIProcess_elm";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct cSIProcessConfigurationIndex_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<1, 7>>;
		static constexpr const char* name() {return "cSIProcessConfigurationIndex_t";}
		using parent_t = asn::integer<>;

	};

	cSIProcessConfigurationIndex_t& ref_cSIProcessConfigurationIndex() {return cSIProcessConfigurationIndex;}
	cSIProcessConfigurationIndex_t const& ref_cSIProcessConfigurationIndex() const {return cSIProcessConfigurationIndex;}
	struct cSIReportPerCSIProcessItem_t : CSIReportPerCSIProcessItem
	{
		static constexpr const char* name() {return "cSIReportPerCSIProcessItem_t";}
		using parent_t = CSIReportPerCSIProcessItem;

	};
	cSIReportPerCSIProcessItem_t& ref_cSIReportPerCSIProcessItem() {return cSIReportPerCSIProcessItem;}
	cSIReportPerCSIProcessItem_t const& ref_cSIReportPerCSIProcessItem() const {return cSIReportPerCSIProcessItem;}
	struct iE_Extensions_t : ProtocolExtensionContainer<CSIReportPerCSIProcess_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<CSIReportPerCSIProcess_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(cSIProcessConfigurationIndex);
		v(cSIReportPerCSIProcessItem);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(cSIProcessConfigurationIndex);
		v(cSIReportPerCSIProcessItem);
		v(iE_Extensions);

	};
	void clear()
	{
		cSIProcessConfigurationIndex.clear();
		cSIReportPerCSIProcessItem.clear();
		iE_Extensions.clear();

	};
	private:
	cSIProcessConfigurationIndex_t	cSIProcessConfigurationIndex;
	cSIReportPerCSIProcessItem_t	cSIReportPerCSIProcessItem;
	iE_Extensions_t	iE_Extensions;

};
struct CSIReportPerCSIProcess : asn::sequenceof<CSIReportPerCSIProcess_elm>
{
	static constexpr const char* name() {return "CSIReportPerCSIProcess";}
	using parent_t = asn::sequenceof<CSIReportPerCSIProcess_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxCSIProcess >>;

};
/*
CSIReportList-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct CSIReportList_ExtIEs
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
CSIReportList ::= SEQUENCE (SIZE(1..maxUEReport)) OF
	SEQUENCE {
		uEID							UEID,
		cSIReportPerCSIProcess			CSIReportPerCSIProcess,
		iE-Extensions					ProtocolExtensionContainer { {CSIReportList-ExtIEs} } OPTIONAL,
		...
	}
*/

struct CSIReportList_elm : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "CSIReportList_elm";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct uEID_t : UEID
	{
		static constexpr const char* name() {return "uEID_t";}
		using parent_t = UEID;

	};
	uEID_t& ref_uEID() {return uEID;}
	uEID_t const& ref_uEID() const {return uEID;}
	struct cSIReportPerCSIProcess_t : CSIReportPerCSIProcess
	{
		static constexpr const char* name() {return "cSIReportPerCSIProcess_t";}
		using parent_t = CSIReportPerCSIProcess;

	};
	cSIReportPerCSIProcess_t& ref_cSIReportPerCSIProcess() {return cSIReportPerCSIProcess;}
	cSIReportPerCSIProcess_t const& ref_cSIReportPerCSIProcess() const {return cSIReportPerCSIProcess;}
	struct iE_Extensions_t : ProtocolExtensionContainer<CSIReportList_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<CSIReportList_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(uEID);
		v(cSIReportPerCSIProcess);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(uEID);
		v(cSIReportPerCSIProcess);
		v(iE_Extensions);

	};
	void clear()
	{
		uEID.clear();
		cSIReportPerCSIProcess.clear();
		iE_Extensions.clear();

	};
	private:
	uEID_t	uEID;
	cSIReportPerCSIProcess_t	cSIReportPerCSIProcess;
	iE_Extensions_t	iE_Extensions;

};
struct CSIReportList : asn::sequenceof<CSIReportList_elm>
{
	static constexpr const char* name() {return "CSIReportList";}
	using parent_t = asn::sequenceof<CSIReportList_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxUEReport >>;

};
/*
CapacityValue ::= INTEGER (0..100)
*/

struct CapacityValue : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 100>>;
	static constexpr const char* name() {return "CapacityValue";}
	using parent_t = asn::integer<>;

};

/*
CauseRadioNetwork ::= ENUMERATED {
	handover-desirable-for-radio-reasons,
	time-critical-handover,
	resource-optimisation-handover,
	reduce-load-in-serving-cell,
	partial-handover,
	unknown-new-eNB-UE-X2AP-ID,
	unknown-old-eNB-UE-X2AP-ID,
	unknown-pair-of-UE-X2AP-ID,
	ho-target-not-allowed,
	tx2relocoverall-expiry,
	trelocprep-expiry,
	cell-not-available,
	no-radio-resources-available-in-target-cell,
	invalid-MME-GroupID,
	unknown-MME-Code,
	encryption-and-or-integrity-protection-algorithms-not-supported,
	reportCharacteristicsEmpty,
	noReportPeriodicity,
	existingMeasurementID,
	unknown-eNB-Measurement-ID,
	measurement-temporarily-not-available,
	unspecified,
	...,
	load-balancing,
	handover-optimisation,
	value-out-of-allowed-range,
	multiple-E-RAB-ID-instances,
	switch-off-ongoing,
	not-supported-QCI-value,
	measurement-not-supported-for-the-object,
	tDCoverall-expiry,
	tDCprep-expiry,
	action-desirable-for-radio-reasons,
	reduce-load,
	resource-optimisation,
	time-critical-action,
	target-not-allowed,
	no-radio-resources-available,
	invalid-QoS-combination,
	encryption-algorithms-not-aupported,
	procedure-cancelled,
	rRM-purpose,
	improve-user-bit-rate,
	user-inactivity,
	radio-connection-with-UE-lost,
	failure-in-the-radio-interface-procedure,
	bearer-option-not-supported,
	mCG-Mobility,
	sCG-Mobility,
	count-reaches-max-value,
	unknown-old-en-gNB-UE-X2AP-ID,
	pDCP-Overload

}
*/

struct CauseRadioNetwork : asn::enumerated<51, 29, true>
{
	static constexpr const char* name() {return "CauseRadioNetwork";}
	using parent_t = asn::enumerated<51, 29, true>;
	typedef enum {
		handover_desirable_for_radio_reasons
		,time_critical_handover
		,resource_optimisation_handover
		,reduce_load_in_serving_cell
		,partial_handover
		,unknown_new_eNB_UE_X2AP_ID
		,unknown_old_eNB_UE_X2AP_ID
		,unknown_pair_of_UE_X2AP_ID
		,ho_target_not_allowed
		,tx2relocoverall_expiry
		,trelocprep_expiry
		,cell_not_available
		,no_radio_resources_available_in_target_cell
		,invalid_MME_GroupID
		,unknown_MME_Code
		,encryption_and_or_integrity_protection_algorithms_not_supported
		,reportCharacteristicsEmpty
		,noReportPeriodicity
		,existingMeasurementID
		,unknown_eNB_Measurement_ID
		,measurement_temporarily_not_available
		,unspecified
		,load_balancing
		,handover_optimisation
		,value_out_of_allowed_range
		,multiple_E_RAB_ID_instances
		,switch_off_ongoing
		,not_supported_QCI_value
		,measurement_not_supported_for_the_object
		,tDCoverall_expiry
		,tDCprep_expiry
		,action_desirable_for_radio_reasons
		,reduce_load
		,resource_optimisation
		,time_critical_action
		,target_not_allowed
		,no_radio_resources_available
		,invalid_QoS_combination
		,encryption_algorithms_not_aupported
		,procedure_cancelled
		,rRM_purpose
		,improve_user_bit_rate
		,user_inactivity
		,radio_connection_with_UE_lost
		,failure_in_the_radio_interface_procedure
		,bearer_option_not_supported
		,mCG_Mobility
		,sCG_Mobility
		,count_reaches_max_value
		,unknown_old_en_gNB_UE_X2AP_ID
		,pDCP_Overload
	} index_t;

};

/*
CauseTransport ::= ENUMERATED {
	transport-resource-unavailable,
	unspecified,
	...
}
*/

struct CauseTransport : asn::enumerated<2, 0, true>
{
	static constexpr const char* name() {return "CauseTransport";}
	using parent_t = asn::enumerated<2, 0, true>;
	typedef enum {
		transport_resource_unavailable
		,unspecified
	} index_t;

};

/*
CauseProtocol ::= ENUMERATED {
	transfer-syntax-error,
	abstract-syntax-error-reject,
	abstract-syntax-error-ignore-and-notify,
	message-not-compatible-with-receiver-state,
	semantic-error,
	unspecified,
	abstract-syntax-error-falsely-constructed-message,
	...
}
*/

struct CauseProtocol : asn::enumerated<7, 0, true>
{
	static constexpr const char* name() {return "CauseProtocol";}
	using parent_t = asn::enumerated<7, 0, true>;
	typedef enum {
		transfer_syntax_error
		,abstract_syntax_error_reject
		,abstract_syntax_error_ignore_and_notify
		,message_not_compatible_with_receiver_state
		,semantic_error
		,unspecified
		,abstract_syntax_error_falsely_constructed_message
	} index_t;

};

/*
CauseMisc ::= ENUMERATED {
	control-processing-overload,
	hardware-failure,
	om-intervention,
	not-enough-user-plane-processing-resources,
	unspecified,
	...
}
*/

struct CauseMisc : asn::enumerated<5, 0, true>
{
	static constexpr const char* name() {return "CauseMisc";}
	using parent_t = asn::enumerated<5, 0, true>;
	typedef enum {
		control_processing_overload
		,hardware_failure
		,om_intervention
		,not_enough_user_plane_processing_resources
		,unspecified
	} index_t;

};

/*
Cause ::= CHOICE {
	radioNetwork		CauseRadioNetwork,
	transport			CauseTransport,
	protocol			CauseProtocol,
	misc				CauseMisc,
	...
}
*/

struct Cause : asn::choice<4, 0, true>
{
	static constexpr const char* name() {return "Cause";}
	using parent_t = asn::choice<4, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 5;}
	void set_unknown() { set_index(5);  }
	~Cause() {clear();}
	struct radioNetwork_t : CauseRadioNetwork
	{
		static constexpr const char* name() {return "radioNetwork_t";}
		using parent_t = CauseRadioNetwork;

	};
	struct transport_t : CauseTransport
	{
		static constexpr const char* name() {return "transport_t";}
		using parent_t = CauseTransport;

	};
	struct protocol_t : CauseProtocol
	{
		static constexpr const char* name() {return "protocol_t";}
		using parent_t = CauseProtocol;

	};
	struct misc_t : CauseMisc
	{
		static constexpr const char* name() {return "misc_t";}
		using parent_t = CauseMisc;

	};
	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<radioNetwork_t>(); break;
		case 2: var.destroy<transport_t>(); break;
		case 3: var.destroy<protocol_t>(); break;
		case 4: var.destroy<misc_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<radioNetwork_t>());
		case 2: set_index(2); return v(var.build<transport_t>());
		case 3: set_index(3); return v(var.build<protocol_t>());
		case 4: set_index(4); return v(var.build<misc_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<radioNetwork_t>());
		case 2: return v(var.as<transport_t>());
		case 3: return v(var.as<protocol_t>());
		case 4: return v(var.as<misc_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<radioNetwork_t>(1);
		v.template operator()<transport_t>(2);
		v.template operator()<protocol_t>(3);
		v.template operator()<misc_t>(4);

	}
	radioNetwork_t& select_radioNetwork() { if(get_index() != 1) { clear(); set_index(1); return var.build<radioNetwork_t>();} return var.as<radioNetwork_t>();}
	radioNetwork_t const* get_radioNetwork() const { if(get_index() == 1) { return &var.as<radioNetwork_t>();} return nullptr; }
	transport_t& select_transport() { if(get_index() != 2) { clear(); set_index(2); return var.build<transport_t>();} return var.as<transport_t>();}
	transport_t const* get_transport() const { if(get_index() == 2) { return &var.as<transport_t>();} return nullptr; }
	protocol_t& select_protocol() { if(get_index() != 3) { clear(); set_index(3); return var.build<protocol_t>();} return var.as<protocol_t>();}
	protocol_t const* get_protocol() const { if(get_index() == 3) { return &var.as<protocol_t>();} return nullptr; }
	misc_t& select_misc() { if(get_index() != 4) { clear(); set_index(4); return var.build<misc_t>();} return var.as<misc_t>();}
	misc_t const* get_misc() const { if(get_index() == 4) { return &var.as<misc_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(radioNetwork_t)];
		char dummy2[sizeof(transport_t)];
		char dummy3[sizeof(protocol_t)];
		char dummy4[sizeof(misc_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
Cell-Size ::= ENUMERATED {verysmall, small, medium, large, ... }
*/

struct Cell_Size : asn::enumerated<4, 0, true>
{
	static constexpr const char* name() {return "Cell-Size";}
	using parent_t = asn::enumerated<4, 0, true>;
	typedef enum {
		verysmall
		,small
		,medium
		,large
	} index_t;

};

/*
CellCapacityClassValue ::= INTEGER (1..100, ...)
*/

struct CellCapacityClassValue : asn::integer<>
{
	using constraint_t = asn::constraints<true,asn::span<1, 100>>;
	static constexpr const char* name() {return "CellCapacityClassValue";}
	using parent_t = asn::integer<>;

};

/*
CellDeploymentStatusIndicator ::= ENUMERATED {pre-change-notification, ...}
*/

struct CellDeploymentStatusIndicator : asn::enumerated<1, 0, true>
{
	static constexpr const char* name() {return "CellDeploymentStatusIndicator";}
	using parent_t = asn::enumerated<1, 0, true>;
	typedef enum {
		pre_change_notification
	} index_t;

};

/*
ReplacingCellsList-Item ::= SEQUENCE {
	eCGI			ECGI,
	...
}
*/

struct ReplacingCellsList_Item : asn::sequence<1, 0, true, 0>
{
	static constexpr const char* name() {return "ReplacingCellsList-Item";}
	using parent_t = asn::sequence<1, 0, true, 0>;
	struct eCGI_t : ECGI
	{
		static constexpr const char* name() {return "eCGI_t";}
		using parent_t = ECGI;

	};
	eCGI_t& ref_eCGI() {return eCGI;}
	eCGI_t const& ref_eCGI() const {return eCGI;}
	template<typename V> void decode(V& v)
	{
		v(eCGI);

	};
	template<typename V> void encode(V& v) const
	{
		v(eCGI);

	};
	void clear()
	{
		eCGI.clear();

	};
	private:
	eCGI_t	eCGI;

};
/*
ReplacingCellsList ::= SEQUENCE (SIZE(0.. maxCellineNB)) OF ReplacingCellsList-Item
*/

struct ReplacingCellsList_elm : ReplacingCellsList_Item
{
	static constexpr const char* name() {return "ReplacingCellsList_elm";}
	using parent_t = ReplacingCellsList_Item;

};
struct ReplacingCellsList : asn::sequenceof<ReplacingCellsList_elm>
{
	static constexpr const char* name() {return "ReplacingCellsList";}
	using parent_t = asn::sequenceof<ReplacingCellsList_elm>;
	using constraint_t = asn::constraints<false,asn::span<0,  maxCellineNB >>;

};
/*
CellReplacingInfo-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct CellReplacingInfo_ExtIEs
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
CellReplacingInfo ::= SEQUENCE {
	replacingCellsList				ReplacingCellsList,
	iE-Extensions					ProtocolExtensionContainer { {CellReplacingInfo-ExtIEs}}	OPTIONAL,
	...
}
*/

struct CellReplacingInfo : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "CellReplacingInfo";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct replacingCellsList_t : ReplacingCellsList
	{
		static constexpr const char* name() {return "replacingCellsList_t";}
		using parent_t = ReplacingCellsList;

	};
	replacingCellsList_t& ref_replacingCellsList() {return replacingCellsList;}
	replacingCellsList_t const& ref_replacingCellsList() const {return replacingCellsList;}
	struct iE_Extensions_t : ProtocolExtensionContainer<CellReplacingInfo_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<CellReplacingInfo_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(replacingCellsList);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(replacingCellsList);
		v(iE_Extensions);

	};
	void clear()
	{
		replacingCellsList.clear();
		iE_Extensions.clear();

	};
	private:
	replacingCellsList_t	replacingCellsList;
	iE_Extensions_t	iE_Extensions;

};
/*
CellReportingIndicator ::= ENUMERATED {stop-request, ... }
*/

struct CellReportingIndicator : asn::enumerated<1, 0, true>
{
	static constexpr const char* name() {return "CellReportingIndicator";}
	using parent_t = asn::enumerated<1, 0, true>;
	typedef enum {
		stop_request
	} index_t;

};

/*
CellType-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct CellType_ExtIEs
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
CellType ::= SEQUENCE {
	cell-Size						Cell-Size,
	iE-Extensions					ProtocolExtensionContainer { {CellType-ExtIEs}}	OPTIONAL,
	...
}
*/

struct CellType : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "CellType";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct cell_Size_t : Cell_Size
	{
		static constexpr const char* name() {return "cell_Size_t";}
		using parent_t = Cell_Size;

	};
	cell_Size_t& ref_cell_Size() {return cell_Size;}
	cell_Size_t const& ref_cell_Size() const {return cell_Size;}
	struct iE_Extensions_t : ProtocolExtensionContainer<CellType_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<CellType_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(cell_Size);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(cell_Size);
		v(iE_Extensions);

	};
	void clear()
	{
		cell_Size.clear();
		iE_Extensions.clear();

	};
	private:
	cell_Size_t	cell_Size;
	iE_Extensions_t	iE_Extensions;

};
/*
CoMPHypothesisSetItem-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct CoMPHypothesisSetItem_ExtIEs
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
CoMPHypothesisSetItem ::= SEQUENCE {
	coMPCellID						ECGI,
	coMPHypothesis					BIT STRING (SIZE(6..4400, ...)),
	iE-Extensions					ProtocolExtensionContainer { {CoMPHypothesisSetItem-ExtIEs} } OPTIONAL,
	...
}
*/

struct CoMPHypothesisSetItem : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "CoMPHypothesisSetItem";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct coMPCellID_t : ECGI
	{
		static constexpr const char* name() {return "coMPCellID_t";}
		using parent_t = ECGI;

	};
	coMPCellID_t& ref_coMPCellID() {return coMPCellID;}
	coMPCellID_t const& ref_coMPCellID() const {return coMPCellID;}
	struct coMPHypothesis_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<true,asn::span<6, 4400>>;
		static constexpr const char* name() {return "coMPHypothesis_t";}
		using parent_t = asn::bstring<>;

	};

	coMPHypothesis_t& ref_coMPHypothesis() {return coMPHypothesis;}
	coMPHypothesis_t const& ref_coMPHypothesis() const {return coMPHypothesis;}
	struct iE_Extensions_t : ProtocolExtensionContainer<CoMPHypothesisSetItem_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<CoMPHypothesisSetItem_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(coMPCellID);
		v(coMPHypothesis);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(coMPCellID);
		v(coMPHypothesis);
		v(iE_Extensions);

	};
	void clear()
	{
		coMPCellID.clear();
		coMPHypothesis.clear();
		iE_Extensions.clear();

	};
	private:
	coMPCellID_t	coMPCellID;
	coMPHypothesis_t	coMPHypothesis;
	iE_Extensions_t	iE_Extensions;

};
/*
CoMPHypothesisSet ::= SEQUENCE (SIZE(1..maxnoofCoMPCells)) OF CoMPHypothesisSetItem
*/

struct CoMPHypothesisSet_elm : CoMPHypothesisSetItem
{
	static constexpr const char* name() {return "CoMPHypothesisSet_elm";}
	using parent_t = CoMPHypothesisSetItem;

};
struct CoMPHypothesisSet : asn::sequenceof<CoMPHypothesisSet_elm>
{
	static constexpr const char* name() {return "CoMPHypothesisSet";}
	using parent_t = asn::sequenceof<CoMPHypothesisSet_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofCoMPCells >>;

};
/*
CoMPInformationItem-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct CoMPInformationItem_ExtIEs
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
CoMPInformationItem ::= SEQUENCE (SIZE(1..maxnoofCoMPHypothesisSet)) OF
	SEQUENCE {
		coMPHypothesisSet					CoMPHypothesisSet,
		benefitMetric						BenefitMetric,
		iE-Extensions						ProtocolExtensionContainer { {CoMPInformationItem-ExtIEs} } OPTIONAL,
		...
	}
*/

struct CoMPInformationItem_elm : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "CoMPInformationItem_elm";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct coMPHypothesisSet_t : CoMPHypothesisSet
	{
		static constexpr const char* name() {return "coMPHypothesisSet_t";}
		using parent_t = CoMPHypothesisSet;

	};
	coMPHypothesisSet_t& ref_coMPHypothesisSet() {return coMPHypothesisSet;}
	coMPHypothesisSet_t const& ref_coMPHypothesisSet() const {return coMPHypothesisSet;}
	struct benefitMetric_t : BenefitMetric
	{
		static constexpr const char* name() {return "benefitMetric_t";}
		using parent_t = BenefitMetric;

	};
	benefitMetric_t& ref_benefitMetric() {return benefitMetric;}
	benefitMetric_t const& ref_benefitMetric() const {return benefitMetric;}
	struct iE_Extensions_t : ProtocolExtensionContainer<CoMPInformationItem_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<CoMPInformationItem_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(coMPHypothesisSet);
		v(benefitMetric);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(coMPHypothesisSet);
		v(benefitMetric);
		v(iE_Extensions);

	};
	void clear()
	{
		coMPHypothesisSet.clear();
		benefitMetric.clear();
		iE_Extensions.clear();

	};
	private:
	coMPHypothesisSet_t	coMPHypothesisSet;
	benefitMetric_t	benefitMetric;
	iE_Extensions_t	iE_Extensions;

};
struct CoMPInformationItem : asn::sequenceof<CoMPInformationItem_elm>
{
	static constexpr const char* name() {return "CoMPInformationItem";}
	using parent_t = asn::sequenceof<CoMPInformationItem_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofCoMPHypothesisSet >>;

};
/*
CoMPInformationStartTime-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct CoMPInformationStartTime_ExtIEs
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
CoMPInformationStartTime ::= SEQUENCE (SIZE(0..1)) OF
	SEQUENCE {
		startSFN							INTEGER (0..1023, ...),
		startSubframeNumber					INTEGER (0..9, ...),
		iE-Extensions						ProtocolExtensionContainer { {CoMPInformationStartTime-ExtIEs} } OPTIONAL,
		...
	}
*/

struct CoMPInformationStartTime_elm : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "CoMPInformationStartTime_elm";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct startSFN_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 1023>>;
		static constexpr const char* name() {return "startSFN_t";}
		using parent_t = asn::integer<>;

	};

	startSFN_t& ref_startSFN() {return startSFN;}
	startSFN_t const& ref_startSFN() const {return startSFN;}
	struct startSubframeNumber_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 9>>;
		static constexpr const char* name() {return "startSubframeNumber_t";}
		using parent_t = asn::integer<>;

	};

	startSubframeNumber_t& ref_startSubframeNumber() {return startSubframeNumber;}
	startSubframeNumber_t const& ref_startSubframeNumber() const {return startSubframeNumber;}
	struct iE_Extensions_t : ProtocolExtensionContainer<CoMPInformationStartTime_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<CoMPInformationStartTime_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(startSFN);
		v(startSubframeNumber);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(startSFN);
		v(startSubframeNumber);
		v(iE_Extensions);

	};
	void clear()
	{
		startSFN.clear();
		startSubframeNumber.clear();
		iE_Extensions.clear();

	};
	private:
	startSFN_t	startSFN;
	startSubframeNumber_t	startSubframeNumber;
	iE_Extensions_t	iE_Extensions;

};
struct CoMPInformationStartTime : asn::sequenceof<CoMPInformationStartTime_elm>
{
	static constexpr const char* name() {return "CoMPInformationStartTime";}
	using parent_t = asn::sequenceof<CoMPInformationStartTime_elm>;
	using constraint_t = asn::constraints<false,asn::span<0, 1>>;

};
/*
CoMPInformation-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct CoMPInformation_ExtIEs
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
CoMPInformation ::= SEQUENCE {
	coMPInformationItem						CoMPInformationItem,
	coMPInformationStartTime				CoMPInformationStartTime,
	iE-Extensions							ProtocolExtensionContainer { {CoMPInformation-ExtIEs} } OPTIONAL,
	...
}
*/

struct CoMPInformation : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "CoMPInformation";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct coMPInformationItem_t : CoMPInformationItem
	{
		static constexpr const char* name() {return "coMPInformationItem_t";}
		using parent_t = CoMPInformationItem;

	};
	coMPInformationItem_t& ref_coMPInformationItem() {return coMPInformationItem;}
	coMPInformationItem_t const& ref_coMPInformationItem() const {return coMPInformationItem;}
	struct coMPInformationStartTime_t : CoMPInformationStartTime
	{
		static constexpr const char* name() {return "coMPInformationStartTime_t";}
		using parent_t = CoMPInformationStartTime;

	};
	coMPInformationStartTime_t& ref_coMPInformationStartTime() {return coMPInformationStartTime;}
	coMPInformationStartTime_t const& ref_coMPInformationStartTime() const {return coMPInformationStartTime;}
	struct iE_Extensions_t : ProtocolExtensionContainer<CoMPInformation_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<CoMPInformation_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(coMPInformationItem);
		v(coMPInformationStartTime);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(coMPInformationItem);
		v(coMPInformationStartTime);
		v(iE_Extensions);

	};
	void clear()
	{
		coMPInformationItem.clear();
		coMPInformationStartTime.clear();
		iE_Extensions.clear();

	};
	private:
	coMPInformationItem_t	coMPInformationItem;
	coMPInformationStartTime_t	coMPInformationStartTime;
	iE_Extensions_t	iE_Extensions;

};
/*
CompositeAvailableCapacity-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct CompositeAvailableCapacity_ExtIEs
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
CompositeAvailableCapacity ::= SEQUENCE {
	cellCapacityClassValue							CellCapacityClassValue				OPTIONAL,
	capacityValue									CapacityValue,
	iE-Extensions									ProtocolExtensionContainer { {CompositeAvailableCapacity-ExtIEs} } OPTIONAL,
	...
}
*/

struct CompositeAvailableCapacity : asn::sequence<3, 0, true, 2>
{
	static constexpr const char* name() {return "CompositeAvailableCapacity";}
	using parent_t = asn::sequence<3, 0, true, 2>;
	struct cellCapacityClassValue_t : CellCapacityClassValue
	{
		static constexpr const char* name() {return "cellCapacityClassValue_t";}
		using parent_t = CellCapacityClassValue;
		static constexpr bool optional = true;

	};
	cellCapacityClassValue_t& set_cellCapacityClassValue() { cellCapacityClassValue.setpresent(true); return cellCapacityClassValue;}
	cellCapacityClassValue_t const* get_cellCapacityClassValue() const {return cellCapacityClassValue.is_valid() ? &cellCapacityClassValue : nullptr;}
	struct capacityValue_t : CapacityValue
	{
		static constexpr const char* name() {return "capacityValue_t";}
		using parent_t = CapacityValue;

	};
	capacityValue_t& ref_capacityValue() {return capacityValue;}
	capacityValue_t const& ref_capacityValue() const {return capacityValue;}
	struct iE_Extensions_t : ProtocolExtensionContainer<CompositeAvailableCapacity_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<CompositeAvailableCapacity_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(cellCapacityClassValue);
		v(capacityValue);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(cellCapacityClassValue);
		v(capacityValue);
		v(iE_Extensions);

	};
	void clear()
	{
		cellCapacityClassValue.clear();
		capacityValue.clear();
		iE_Extensions.clear();

	};
	private:
	cellCapacityClassValue_t	cellCapacityClassValue;
	capacityValue_t	capacityValue;
	iE_Extensions_t	iE_Extensions;

};
/*
CompositeAvailableCapacityGroup-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct CompositeAvailableCapacityGroup_ExtIEs
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
CompositeAvailableCapacityGroup	::= SEQUENCE {
	dL-CompositeAvailableCapacity					CompositeAvailableCapacity,
	uL-CompositeAvailableCapacity					CompositeAvailableCapacity,
	iE-Extensions									ProtocolExtensionContainer { {CompositeAvailableCapacityGroup-ExtIEs} } OPTIONAL,
	...
}
*/

struct CompositeAvailableCapacityGroup : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "CompositeAvailableCapacityGroup";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct dL_CompositeAvailableCapacity_t : CompositeAvailableCapacity
	{
		static constexpr const char* name() {return "dL_CompositeAvailableCapacity_t";}
		using parent_t = CompositeAvailableCapacity;

	};
	dL_CompositeAvailableCapacity_t& ref_dL_CompositeAvailableCapacity() {return dL_CompositeAvailableCapacity;}
	dL_CompositeAvailableCapacity_t const& ref_dL_CompositeAvailableCapacity() const {return dL_CompositeAvailableCapacity;}
	struct uL_CompositeAvailableCapacity_t : CompositeAvailableCapacity
	{
		static constexpr const char* name() {return "uL_CompositeAvailableCapacity_t";}
		using parent_t = CompositeAvailableCapacity;

	};
	uL_CompositeAvailableCapacity_t& ref_uL_CompositeAvailableCapacity() {return uL_CompositeAvailableCapacity;}
	uL_CompositeAvailableCapacity_t const& ref_uL_CompositeAvailableCapacity() const {return uL_CompositeAvailableCapacity;}
	struct iE_Extensions_t : ProtocolExtensionContainer<CompositeAvailableCapacityGroup_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<CompositeAvailableCapacityGroup_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(dL_CompositeAvailableCapacity);
		v(uL_CompositeAvailableCapacity);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(dL_CompositeAvailableCapacity);
		v(uL_CompositeAvailableCapacity);
		v(iE_Extensions);

	};
	void clear()
	{
		dL_CompositeAvailableCapacity.clear();
		uL_CompositeAvailableCapacity.clear();
		iE_Extensions.clear();

	};
	private:
	dL_CompositeAvailableCapacity_t	dL_CompositeAvailableCapacity;
	uL_CompositeAvailableCapacity_t	uL_CompositeAvailableCapacity;
	iE_Extensions_t	iE_Extensions;

};
/*
Correlation-ID ::= OCTET STRING (SIZE (4))
*/

struct Correlation_ID : asn::ostring<>
{
	using constraint_t = asn::constraints<false,asn::one<4>>;
	static constexpr const char* name() {return "Correlation-ID";}
	using parent_t = asn::ostring<>;

};

/*
CoverageModification-Item ::= SEQUENCE {
	eCGI							ECGI,
	coverageState					INTEGER (0..15, ...),
	cellDeploymentStatusIndicator	CellDeploymentStatusIndicator			OPTIONAL,
	cellReplacingInfo				CellReplacingInfo						OPTIONAL,
-- Included in case the Cell Deployment Status Indicator IE is present
	...
}
*/

struct CoverageModification_Item : asn::sequence<4, 0, true, 2>
{
	static constexpr const char* name() {return "CoverageModification-Item";}
	using parent_t = asn::sequence<4, 0, true, 2>;
	struct eCGI_t : ECGI
	{
		static constexpr const char* name() {return "eCGI_t";}
		using parent_t = ECGI;

	};
	eCGI_t& ref_eCGI() {return eCGI;}
	eCGI_t const& ref_eCGI() const {return eCGI;}
	struct coverageState_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 15>>;
		static constexpr const char* name() {return "coverageState_t";}
		using parent_t = asn::integer<>;

	};

	coverageState_t& ref_coverageState() {return coverageState;}
	coverageState_t const& ref_coverageState() const {return coverageState;}
	struct cellDeploymentStatusIndicator_t : CellDeploymentStatusIndicator
	{
		static constexpr const char* name() {return "cellDeploymentStatusIndicator_t";}
		using parent_t = CellDeploymentStatusIndicator;
		static constexpr bool optional = true;

	};
	cellDeploymentStatusIndicator_t& set_cellDeploymentStatusIndicator() { cellDeploymentStatusIndicator.setpresent(true); return cellDeploymentStatusIndicator;}
	cellDeploymentStatusIndicator_t const* get_cellDeploymentStatusIndicator() const {return cellDeploymentStatusIndicator.is_valid() ? &cellDeploymentStatusIndicator : nullptr;}
	struct cellReplacingInfo_t : CellReplacingInfo
	{
		static constexpr const char* name() {return "cellReplacingInfo_t";}
		using parent_t = CellReplacingInfo;
		static constexpr bool optional = true;

	};
	cellReplacingInfo_t& set_cellReplacingInfo() { cellReplacingInfo.setpresent(true); return cellReplacingInfo;}
	cellReplacingInfo_t const* get_cellReplacingInfo() const {return cellReplacingInfo.is_valid() ? &cellReplacingInfo : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(eCGI);
		v(coverageState);
		v(cellDeploymentStatusIndicator);
		v(cellReplacingInfo);

	};
	template<typename V> void encode(V& v) const
	{
		v(eCGI);
		v(coverageState);
		v(cellDeploymentStatusIndicator);
		v(cellReplacingInfo);

	};
	void clear()
	{
		eCGI.clear();
		coverageState.clear();
		cellDeploymentStatusIndicator.clear();
		cellReplacingInfo.clear();

	};
	private:
	eCGI_t	eCGI;
	coverageState_t	coverageState;
	cellDeploymentStatusIndicator_t	cellDeploymentStatusIndicator;
	cellReplacingInfo_t	cellReplacingInfo;

};
/*
CoverageModificationList ::= SEQUENCE (SIZE (1..maxCellineNB)) OF CoverageModification-Item
*/

struct CoverageModificationList_elm : CoverageModification_Item
{
	static constexpr const char* name() {return "CoverageModificationList_elm";}
	using parent_t = CoverageModification_Item;

};
struct CoverageModificationList : asn::sequenceof<CoverageModificationList_elm>
{
	static constexpr const char* name() {return "CoverageModificationList";}
	using parent_t = asn::sequenceof<CoverageModificationList_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxCellineNB >>;

};
/*
TypeOfError ::= ENUMERATED {
	not-understood,
	missing,
	...
}
*/

struct TypeOfError : asn::enumerated<2, 0, true>
{
	static constexpr const char* name() {return "TypeOfError";}
	using parent_t = asn::enumerated<2, 0, true>;
	typedef enum {
		not_understood
		,missing
	} index_t;

};

/*
CriticalityDiagnostics-IE-List-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct CriticalityDiagnostics_IE_List_ExtIEs
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
CriticalityDiagnostics-IE-List ::= SEQUENCE (SIZE (1..maxNrOfErrors)) OF
	SEQUENCE {
		iECriticality			Criticality,
		iE-ID					ProtocolIE-ID,
		typeOfError				TypeOfError,
		iE-Extensions			ProtocolExtensionContainer { {CriticalityDiagnostics-IE-List-ExtIEs} } OPTIONAL,
		...
}
*/

struct CriticalityDiagnostics_IE_List_elm : asn::sequence<4, 0, true, 1>
{
	static constexpr const char* name() {return "CriticalityDiagnostics_IE_List_elm";}
	using parent_t = asn::sequence<4, 0, true, 1>;
	struct iECriticality_t : Criticality
	{
		static constexpr const char* name() {return "iECriticality_t";}
		using parent_t = Criticality;

	};
	iECriticality_t& ref_iECriticality() {return iECriticality;}
	iECriticality_t const& ref_iECriticality() const {return iECriticality;}
	struct iE_ID_t : ProtocolIE_ID
	{
		static constexpr const char* name() {return "iE_ID_t";}
		using parent_t = ProtocolIE_ID;

	};
	iE_ID_t& ref_iE_ID() {return iE_ID;}
	iE_ID_t const& ref_iE_ID() const {return iE_ID;}
	struct typeOfError_t : TypeOfError
	{
		static constexpr const char* name() {return "typeOfError_t";}
		using parent_t = TypeOfError;

	};
	typeOfError_t& ref_typeOfError() {return typeOfError;}
	typeOfError_t const& ref_typeOfError() const {return typeOfError;}
	struct iE_Extensions_t : ProtocolExtensionContainer<CriticalityDiagnostics_IE_List_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<CriticalityDiagnostics_IE_List_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(iECriticality);
		v(iE_ID);
		v(typeOfError);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(iECriticality);
		v(iE_ID);
		v(typeOfError);
		v(iE_Extensions);

	};
	void clear()
	{
		iECriticality.clear();
		iE_ID.clear();
		typeOfError.clear();
		iE_Extensions.clear();

	};
	private:
	iECriticality_t	iECriticality;
	iE_ID_t	iE_ID;
	typeOfError_t	typeOfError;
	iE_Extensions_t	iE_Extensions;

};
struct CriticalityDiagnostics_IE_List : asn::sequenceof<CriticalityDiagnostics_IE_List_elm>
{
	static constexpr const char* name() {return "CriticalityDiagnostics-IE-List";}
	using parent_t = asn::sequenceof<CriticalityDiagnostics_IE_List_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxNrOfErrors >>;

};
/*
CriticalityDiagnostics-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct CriticalityDiagnostics_ExtIEs
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
CriticalityDiagnostics ::= SEQUENCE {
	procedureCode					ProcedureCode					OPTIONAL,
	triggeringMessage				TriggeringMessage				OPTIONAL,
	procedureCriticality			Criticality						OPTIONAL,
	iEsCriticalityDiagnostics		CriticalityDiagnostics-IE-List	OPTIONAL,
	iE-Extensions					ProtocolExtensionContainer { {CriticalityDiagnostics-ExtIEs} }	OPTIONAL,
	...
}
*/

struct CriticalityDiagnostics : asn::sequence<5, 0, true, 5>
{
	static constexpr const char* name() {return "CriticalityDiagnostics";}
	using parent_t = asn::sequence<5, 0, true, 5>;
	struct procedureCode_t : ProcedureCode
	{
		static constexpr const char* name() {return "procedureCode_t";}
		using parent_t = ProcedureCode;
		static constexpr bool optional = true;

	};
	procedureCode_t& set_procedureCode() { procedureCode.setpresent(true); return procedureCode;}
	procedureCode_t const* get_procedureCode() const {return procedureCode.is_valid() ? &procedureCode : nullptr;}
	struct triggeringMessage_t : TriggeringMessage
	{
		static constexpr const char* name() {return "triggeringMessage_t";}
		using parent_t = TriggeringMessage;
		static constexpr bool optional = true;

	};
	triggeringMessage_t& set_triggeringMessage() { triggeringMessage.setpresent(true); return triggeringMessage;}
	triggeringMessage_t const* get_triggeringMessage() const {return triggeringMessage.is_valid() ? &triggeringMessage : nullptr;}
	struct procedureCriticality_t : Criticality
	{
		static constexpr const char* name() {return "procedureCriticality_t";}
		using parent_t = Criticality;
		static constexpr bool optional = true;

	};
	procedureCriticality_t& set_procedureCriticality() { procedureCriticality.setpresent(true); return procedureCriticality;}
	procedureCriticality_t const* get_procedureCriticality() const {return procedureCriticality.is_valid() ? &procedureCriticality : nullptr;}
	struct iEsCriticalityDiagnostics_t : CriticalityDiagnostics_IE_List
	{
		static constexpr const char* name() {return "iEsCriticalityDiagnostics_t";}
		using parent_t = CriticalityDiagnostics_IE_List;
		static constexpr bool optional = true;

	};
	iEsCriticalityDiagnostics_t& set_iEsCriticalityDiagnostics() { iEsCriticalityDiagnostics.setpresent(true); return iEsCriticalityDiagnostics;}
	iEsCriticalityDiagnostics_t const* get_iEsCriticalityDiagnostics() const {return iEsCriticalityDiagnostics.is_valid() ? &iEsCriticalityDiagnostics : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<CriticalityDiagnostics_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<CriticalityDiagnostics_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(procedureCode);
		v(triggeringMessage);
		v(procedureCriticality);
		v(iEsCriticalityDiagnostics);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(procedureCode);
		v(triggeringMessage);
		v(procedureCriticality);
		v(iEsCriticalityDiagnostics);
		v(iE_Extensions);

	};
	void clear()
	{
		procedureCode.clear();
		triggeringMessage.clear();
		procedureCriticality.clear();
		iEsCriticalityDiagnostics.clear();
		iE_Extensions.clear();

	};
	private:
	procedureCode_t	procedureCode;
	triggeringMessage_t	triggeringMessage;
	procedureCriticality_t	procedureCriticality;
	iEsCriticalityDiagnostics_t	iEsCriticalityDiagnostics;
	iE_Extensions_t	iE_Extensions;

};
/*
DL-Forwarding ::= ENUMERATED {
	dL-forwardingProposed,
	...
}
*/

struct DL_Forwarding : asn::enumerated<1, 0, true>
{
	static constexpr const char* name() {return "DL-Forwarding";}
	using parent_t = asn::enumerated<1, 0, true>;
	typedef enum {
		dL_forwardingProposed
	} index_t;

};

/*
DL-GBR-PRB-usage::= INTEGER (0..100)
*/

struct DL_GBR_PRB_usage : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 100>>;
	static constexpr const char* name() {return "DL-GBR-PRB-usage";}
	using parent_t = asn::integer<>;

};

/*
DL-Total-PRB-usage::= INTEGER (0..100)
*/

struct DL_Total_PRB_usage : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 100>>;
	static constexpr const char* name() {return "DL-Total-PRB-usage";}
	using parent_t = asn::integer<>;

};

/*
DL-non-GBR-PRB-usage::= INTEGER (0..100)
*/

struct DL_non_GBR_PRB_usage : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 100>>;
	static constexpr const char* name() {return "DL-non-GBR-PRB-usage";}
	using parent_t = asn::integer<>;

};

/*
DL-scheduling-PDCCH-CCE-usage::= INTEGER (0..100)
*/

struct DL_scheduling_PDCCH_CCE_usage : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 100>>;
	static constexpr const char* name() {return "DL-scheduling-PDCCH-CCE-usage";}
	using parent_t = asn::integer<>;

};

/*
DataTrafficResources ::= BIT STRING (SIZE(6..17600))
*/

struct DataTrafficResources : asn::bstring<>
{
	using constraint_t = asn::constraints<false,asn::span<6, 17600>>;
	static constexpr const char* name() {return "DataTrafficResources";}
	using parent_t = asn::bstring<>;

};

/*
DLResourceBitmapULandDLSharing ::= DataTrafficResources
*/

struct DLResourceBitmapULandDLSharing : DataTrafficResources
{
	static constexpr const char* name() {return "DLResourceBitmapULandDLSharing";}
	using parent_t = DataTrafficResources;

};
/*
DLResourcesULandDLSharing ::= CHOICE {
unchanged			NULL,
	changed				DLResourceBitmapULandDLSharing,
	...
}
*/

struct DLResourcesULandDLSharing : asn::choice<2, 0, true>
{
	static constexpr const char* name() {return "DLResourcesULandDLSharing";}
	using parent_t = asn::choice<2, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 3;}
	void set_unknown() { set_index(3);  }
	~DLResourcesULandDLSharing() {clear();}
	struct unchanged_t : asn::nulltype
	{
		static constexpr const char* name() {return "unchanged_t";}
		using parent_t = asn::nulltype;

	};
	struct changed_t : DLResourceBitmapULandDLSharing
	{
		static constexpr const char* name() {return "changed_t";}
		using parent_t = DLResourceBitmapULandDLSharing;

	};
	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<unchanged_t>(); break;
		case 2: var.destroy<changed_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<unchanged_t>());
		case 2: set_index(2); return v(var.build<changed_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<unchanged_t>());
		case 2: return v(var.as<changed_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<unchanged_t>(1);
		v.template operator()<changed_t>(2);

	}
	unchanged_t& select_unchanged() { if(get_index() != 1) { clear(); set_index(1); return var.build<unchanged_t>();} return var.as<unchanged_t>();}
	unchanged_t const* get_unchanged() const { if(get_index() == 1) { return &var.as<unchanged_t>();} return nullptr; }
	changed_t& select_changed() { if(get_index() != 2) { clear(); set_index(2); return var.build<changed_t>();} return var.as<changed_t>();}
	changed_t const* get_changed() const { if(get_index() == 2) { return &var.as<changed_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(unchanged_t)];
		char dummy2[sizeof(changed_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
DRB-ID ::= INTEGER (1..32)
*/

struct DRB_ID : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<1, 32>>;
	static constexpr const char* name() {return "DRB-ID";}
	using parent_t = asn::integer<>;

};

/*
ULOnlySharing-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct ULOnlySharing_ExtIEs
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
ULOnlySharing ::= SEQUENCE{
	uLResourceBitmapULOnlySharing	DataTrafficResources,
	iE-Extensions					ProtocolExtensionContainer { {ULOnlySharing-ExtIEs} }				OPTIONAL,
	...
}
*/

struct ULOnlySharing : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "ULOnlySharing";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct uLResourceBitmapULOnlySharing_t : DataTrafficResources
	{
		static constexpr const char* name() {return "uLResourceBitmapULOnlySharing_t";}
		using parent_t = DataTrafficResources;

	};
	uLResourceBitmapULOnlySharing_t& ref_uLResourceBitmapULOnlySharing() {return uLResourceBitmapULOnlySharing;}
	uLResourceBitmapULOnlySharing_t const& ref_uLResourceBitmapULOnlySharing() const {return uLResourceBitmapULOnlySharing;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ULOnlySharing_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ULOnlySharing_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(uLResourceBitmapULOnlySharing);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(uLResourceBitmapULOnlySharing);
		v(iE_Extensions);

	};
	void clear()
	{
		uLResourceBitmapULOnlySharing.clear();
		iE_Extensions.clear();

	};
	private:
	uLResourceBitmapULOnlySharing_t	uLResourceBitmapULOnlySharing;
	iE_Extensions_t	iE_Extensions;

};
/*
ULResourceBitmapULandDLSharing ::= DataTrafficResources
*/

struct ULResourceBitmapULandDLSharing : DataTrafficResources
{
	static constexpr const char* name() {return "ULResourceBitmapULandDLSharing";}
	using parent_t = DataTrafficResources;

};
/*
ULResourcesULandDLSharing ::= CHOICE {
	unchanged			NULL,
	changed				ULResourceBitmapULandDLSharing,
	...
}
*/

struct ULResourcesULandDLSharing : asn::choice<2, 0, true>
{
	static constexpr const char* name() {return "ULResourcesULandDLSharing";}
	using parent_t = asn::choice<2, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 3;}
	void set_unknown() { set_index(3);  }
	~ULResourcesULandDLSharing() {clear();}
	struct unchanged_t : asn::nulltype
	{
		static constexpr const char* name() {return "unchanged_t";}
		using parent_t = asn::nulltype;

	};
	struct changed_t : ULResourceBitmapULandDLSharing
	{
		static constexpr const char* name() {return "changed_t";}
		using parent_t = ULResourceBitmapULandDLSharing;

	};
	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<unchanged_t>(); break;
		case 2: var.destroy<changed_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<unchanged_t>());
		case 2: set_index(2); return v(var.build<changed_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<unchanged_t>());
		case 2: return v(var.as<changed_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<unchanged_t>(1);
		v.template operator()<changed_t>(2);

	}
	unchanged_t& select_unchanged() { if(get_index() != 1) { clear(); set_index(1); return var.build<unchanged_t>();} return var.as<unchanged_t>();}
	unchanged_t const* get_unchanged() const { if(get_index() == 1) { return &var.as<unchanged_t>();} return nullptr; }
	changed_t& select_changed() { if(get_index() != 2) { clear(); set_index(2); return var.build<changed_t>();} return var.as<changed_t>();}
	changed_t const* get_changed() const { if(get_index() == 2) { return &var.as<changed_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(unchanged_t)];
		char dummy2[sizeof(changed_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
ULandDLSharing-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct ULandDLSharing_ExtIEs
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
ULandDLSharing ::= SEQUENCE{
	uLResourcesULandDLSharing				ULResourcesULandDLSharing,
	dLResourcesULandDLSharing				DLResourcesULandDLSharing,
	iE-Extensions			ProtocolExtensionContainer { {ULandDLSharing-ExtIEs} }				OPTIONAL,
	...
}
*/

struct ULandDLSharing : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "ULandDLSharing";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct uLResourcesULandDLSharing_t : ULResourcesULandDLSharing
	{
		static constexpr const char* name() {return "uLResourcesULandDLSharing_t";}
		using parent_t = ULResourcesULandDLSharing;

	};
	uLResourcesULandDLSharing_t& ref_uLResourcesULandDLSharing() {return uLResourcesULandDLSharing;}
	uLResourcesULandDLSharing_t const& ref_uLResourcesULandDLSharing() const {return uLResourcesULandDLSharing;}
	struct dLResourcesULandDLSharing_t : DLResourcesULandDLSharing
	{
		static constexpr const char* name() {return "dLResourcesULandDLSharing_t";}
		using parent_t = DLResourcesULandDLSharing;

	};
	dLResourcesULandDLSharing_t& ref_dLResourcesULandDLSharing() {return dLResourcesULandDLSharing;}
	dLResourcesULandDLSharing_t const& ref_dLResourcesULandDLSharing() const {return dLResourcesULandDLSharing;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ULandDLSharing_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ULandDLSharing_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(uLResourcesULandDLSharing);
		v(dLResourcesULandDLSharing);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(uLResourcesULandDLSharing);
		v(dLResourcesULandDLSharing);
		v(iE_Extensions);

	};
	void clear()
	{
		uLResourcesULandDLSharing.clear();
		dLResourcesULandDLSharing.clear();
		iE_Extensions.clear();

	};
	private:
	uLResourcesULandDLSharing_t	uLResourcesULandDLSharing;
	dLResourcesULandDLSharing_t	dLResourcesULandDLSharing;
	iE_Extensions_t	iE_Extensions;

};
/*
SharedResourceType ::= CHOICE{
	uLOnlySharing		ULOnlySharing,
	uLandDLSharing		ULandDLSharing,
	...
}
*/

struct SharedResourceType : asn::choice<2, 0, true>
{
	static constexpr const char* name() {return "SharedResourceType";}
	using parent_t = asn::choice<2, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 3;}
	void set_unknown() { set_index(3);  }
	~SharedResourceType() {clear();}
	struct uLOnlySharing_t : ULOnlySharing
	{
		static constexpr const char* name() {return "uLOnlySharing_t";}
		using parent_t = ULOnlySharing;

	};
	struct uLandDLSharing_t : ULandDLSharing
	{
		static constexpr const char* name() {return "uLandDLSharing_t";}
		using parent_t = ULandDLSharing;

	};
	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<uLOnlySharing_t>(); break;
		case 2: var.destroy<uLandDLSharing_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<uLOnlySharing_t>());
		case 2: set_index(2); return v(var.build<uLandDLSharing_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<uLOnlySharing_t>());
		case 2: return v(var.as<uLandDLSharing_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<uLOnlySharing_t>(1);
		v.template operator()<uLandDLSharing_t>(2);

	}
	uLOnlySharing_t& select_uLOnlySharing() { if(get_index() != 1) { clear(); set_index(1); return var.build<uLOnlySharing_t>();} return var.as<uLOnlySharing_t>();}
	uLOnlySharing_t const* get_uLOnlySharing() const { if(get_index() == 1) { return &var.as<uLOnlySharing_t>();} return nullptr; }
	uLandDLSharing_t& select_uLandDLSharing() { if(get_index() != 2) { clear(); set_index(2); return var.build<uLandDLSharing_t>();} return var.as<uLandDLSharing_t>();}
	uLandDLSharing_t const* get_uLandDLSharing() const { if(get_index() == 2) { return &var.as<uLandDLSharing_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(uLOnlySharing_t)];
		char dummy2[sizeof(uLandDLSharing_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
SubframeType ::= ENUMERATED{mbsfn,nonmbsfn,...}
*/

struct SubframeType : asn::enumerated<2, 0, true>
{
	static constexpr const char* name() {return "SubframeType";}
	using parent_t = asn::enumerated<2, 0, true>;
	typedef enum {
		mbsfn
		,nonmbsfn
	} index_t;

};

/*
ReservedSubframePattern-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct ReservedSubframePattern_ExtIEs
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
ReservedSubframePattern ::= SEQUENCE{
	subframeType					SubframeType,
	reservedSubframePattern			BIT STRING (SIZE(10..160)),
	mBSFNControlRegionLength		INTEGER (0..3),
	iE-Extensions					ProtocolExtensionContainer { {ReservedSubframePattern-ExtIEs} }	OPTIONAL,
	...
}
*/

struct ReservedSubframePattern : asn::sequence<4, 0, true, 1>
{
	static constexpr const char* name() {return "ReservedSubframePattern";}
	using parent_t = asn::sequence<4, 0, true, 1>;
	struct subframeType_t : SubframeType
	{
		static constexpr const char* name() {return "subframeType_t";}
		using parent_t = SubframeType;

	};
	subframeType_t& ref_subframeType() {return subframeType;}
	subframeType_t const& ref_subframeType() const {return subframeType;}
	struct reservedSubframePattern_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<false,asn::span<10, 160>>;
		static constexpr const char* name() {return "reservedSubframePattern_t";}
		using parent_t = asn::bstring<>;

	};

	reservedSubframePattern_t& ref_reservedSubframePattern() {return reservedSubframePattern;}
	reservedSubframePattern_t const& ref_reservedSubframePattern() const {return reservedSubframePattern;}
	struct mBSFNControlRegionLength_t : asn::integer<>
	{
		using constraint_t = asn::constraints<false,asn::span<0, 3>>;
		static constexpr const char* name() {return "mBSFNControlRegionLength_t";}
		using parent_t = asn::integer<>;

	};

	mBSFNControlRegionLength_t& ref_mBSFNControlRegionLength() {return mBSFNControlRegionLength;}
	mBSFNControlRegionLength_t const& ref_mBSFNControlRegionLength() const {return mBSFNControlRegionLength;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ReservedSubframePattern_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ReservedSubframePattern_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(subframeType);
		v(reservedSubframePattern);
		v(mBSFNControlRegionLength);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(subframeType);
		v(reservedSubframePattern);
		v(mBSFNControlRegionLength);
		v(iE_Extensions);

	};
	void clear()
	{
		subframeType.clear();
		reservedSubframePattern.clear();
		mBSFNControlRegionLength.clear();
		iE_Extensions.clear();

	};
	private:
	subframeType_t	subframeType;
	reservedSubframePattern_t	reservedSubframePattern;
	mBSFNControlRegionLength_t	mBSFNControlRegionLength;
	iE_Extensions_t	iE_Extensions;

};
/*
DataTrafficResourceIndication-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct DataTrafficResourceIndication_ExtIEs
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
DataTrafficResourceIndication ::= SEQUENCE {
	activationSFN					INTEGER (0..1023),
	sharedResourceType				SharedResourceType,
	reservedSubframePattern 		ReservedSubframePattern OPTIONAL,
	iE-Extensions					ProtocolExtensionContainer { {DataTrafficResourceIndication-ExtIEs} } OPTIONAL,
...
}
*/

struct DataTrafficResourceIndication : asn::sequence<4, 0, true, 2>
{
	static constexpr const char* name() {return "DataTrafficResourceIndication";}
	using parent_t = asn::sequence<4, 0, true, 2>;
	struct activationSFN_t : asn::integer<>
	{
		using constraint_t = asn::constraints<false,asn::span<0, 1023>>;
		static constexpr const char* name() {return "activationSFN_t";}
		using parent_t = asn::integer<>;

	};

	activationSFN_t& ref_activationSFN() {return activationSFN;}
	activationSFN_t const& ref_activationSFN() const {return activationSFN;}
	struct sharedResourceType_t : SharedResourceType
	{
		static constexpr const char* name() {return "sharedResourceType_t";}
		using parent_t = SharedResourceType;

	};
	sharedResourceType_t& ref_sharedResourceType() {return sharedResourceType;}
	sharedResourceType_t const& ref_sharedResourceType() const {return sharedResourceType;}
	struct reservedSubframePattern_t : ReservedSubframePattern
	{
		static constexpr const char* name() {return "reservedSubframePattern_t";}
		using parent_t = ReservedSubframePattern;
		static constexpr bool optional = true;

	};
	reservedSubframePattern_t& set_reservedSubframePattern() { reservedSubframePattern.setpresent(true); return reservedSubframePattern;}
	reservedSubframePattern_t const* get_reservedSubframePattern() const {return reservedSubframePattern.is_valid() ? &reservedSubframePattern : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<DataTrafficResourceIndication_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<DataTrafficResourceIndication_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(activationSFN);
		v(sharedResourceType);
		v(reservedSubframePattern);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(activationSFN);
		v(sharedResourceType);
		v(reservedSubframePattern);
		v(iE_Extensions);

	};
	void clear()
	{
		activationSFN.clear();
		sharedResourceType.clear();
		reservedSubframePattern.clear();
		iE_Extensions.clear();

	};
	private:
	activationSFN_t	activationSFN;
	sharedResourceType_t	sharedResourceType;
	reservedSubframePattern_t	reservedSubframePattern;
	iE_Extensions_t	iE_Extensions;

};
/*
DeactivationIndication::= ENUMERATED {
	deactivated,
	...
}
*/

struct DeactivationIndication : asn::enumerated<1, 0, true>
{
	static constexpr const char* name() {return "DeactivationIndication";}
	using parent_t = asn::enumerated<1, 0, true>;
	typedef enum {
		deactivated
	} index_t;

};

/*
DeliveryStatus-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct DeliveryStatus_ExtIEs
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
DeliveryStatus ::= SEQUENCE {
	highestSuccessDeliveredPDCPSN		INTEGER (0..4095),
	iE-Extensions		ProtocolExtensionContainer { {DeliveryStatus-ExtIEs} } OPTIONAL,
	...
}
*/

struct DeliveryStatus : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "DeliveryStatus";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct highestSuccessDeliveredPDCPSN_t : asn::integer<>
	{
		using constraint_t = asn::constraints<false,asn::span<0, 4095>>;
		static constexpr const char* name() {return "highestSuccessDeliveredPDCPSN_t";}
		using parent_t = asn::integer<>;

	};

	highestSuccessDeliveredPDCPSN_t& ref_highestSuccessDeliveredPDCPSN() {return highestSuccessDeliveredPDCPSN;}
	highestSuccessDeliveredPDCPSN_t const& ref_highestSuccessDeliveredPDCPSN() const {return highestSuccessDeliveredPDCPSN;}
	struct iE_Extensions_t : ProtocolExtensionContainer<DeliveryStatus_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<DeliveryStatus_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(highestSuccessDeliveredPDCPSN);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(highestSuccessDeliveredPDCPSN);
		v(iE_Extensions);

	};
	void clear()
	{
		highestSuccessDeliveredPDCPSN.clear();
		iE_Extensions.clear();

	};
	private:
	highestSuccessDeliveredPDCPSN_t	highestSuccessDeliveredPDCPSN;
	iE_Extensions_t	iE_Extensions;

};
/*
DuplicationActivation::= ENUMERATED {active, inactive, ...}
*/

struct DuplicationActivation : asn::enumerated<2, 0, true>
{
	static constexpr const char* name() {return "DuplicationActivation";}
	using parent_t = asn::enumerated<2, 0, true>;
	typedef enum {
		active
		,inactive
	} index_t;

};

/*
PA-Values ::= ENUMERATED {
	dB-6,
	dB-4dot77,
	dB-3,
	dB-1dot77,
	dB0,
	dB1,
	dB2,
	dB3,
	...
}
*/

struct PA_Values : asn::enumerated<8, 0, true>
{
	static constexpr const char* name() {return "PA-Values";}
	using parent_t = asn::enumerated<8, 0, true>;
	typedef enum {
		dB_6
		,dB_4dot77
		,dB_3
		,dB_1dot77
		,dB0
		,dB1
		,dB2
		,dB3
	} index_t;

};

/*
DynamicNAICSInformation-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct DynamicNAICSInformation_ExtIEs
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
DynamicNAICSInformation ::= SEQUENCE {
	transmissionModes					BIT STRING (SIZE(8))												OPTIONAL,
	pB-information						INTEGER(0..3)														OPTIONAL,
	pA-list								SEQUENCE (SIZE(0..maxnoofPA)) OF PA-Values,
	iE-Extensions						ProtocolExtensionContainer { {DynamicNAICSInformation-ExtIEs} } OPTIONAL,
	...
}
*/

struct DynamicNAICSInformation : asn::sequence<4, 0, true, 3>
{
	static constexpr const char* name() {return "DynamicNAICSInformation";}
	using parent_t = asn::sequence<4, 0, true, 3>;
	struct transmissionModes_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<false,asn::one<8>>;
		static constexpr const char* name() {return "transmissionModes_t";}
		using parent_t = asn::bstring<>;
		static constexpr bool optional = true;

	};

	transmissionModes_t& set_transmissionModes() { transmissionModes.setpresent(true); return transmissionModes;}
	transmissionModes_t const* get_transmissionModes() const {return transmissionModes.is_valid() ? &transmissionModes : nullptr;}
	struct pB_information_t : asn::integer<>
	{
		using constraint_t = asn::constraints<false,asn::span<0, 3>>;
		static constexpr const char* name() {return "pB_information_t";}
		using parent_t = asn::integer<>;
		static constexpr bool optional = true;

	};

	pB_information_t& set_pB_information() { pB_information.setpresent(true); return pB_information;}
	pB_information_t const* get_pB_information() const {return pB_information.is_valid() ? &pB_information : nullptr;}
	struct pA_list_t_elm : PA_Values
	{
		static constexpr const char* name() {return "pA_list_t_elm";}
		using parent_t = PA_Values;

	};
	struct pA_list_t : asn::sequenceof<pA_list_t_elm>
	{
		static constexpr const char* name() {return "pA_list_t";}
		using parent_t = asn::sequenceof<pA_list_t_elm>;
		using constraint_t = asn::constraints<false,asn::span<0,  maxnoofPA >>;

	};
	pA_list_t& ref_pA_list() {return pA_list;}
	pA_list_t const& ref_pA_list() const {return pA_list;}
	struct iE_Extensions_t : ProtocolExtensionContainer<DynamicNAICSInformation_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<DynamicNAICSInformation_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(transmissionModes);
		v(pB_information);
		v(pA_list);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(transmissionModes);
		v(pB_information);
		v(pA_list);
		v(iE_Extensions);

	};
	void clear()
	{
		transmissionModes.clear();
		pB_information.clear();
		pA_list.clear();
		iE_Extensions.clear();

	};
	private:
	transmissionModes_t	transmissionModes;
	pB_information_t	pB_information;
	pA_list_t	pA_list;
	iE_Extensions_t	iE_Extensions;

};
/*
DynamicDLTransmissionInformation ::= CHOICE {
	naics-active			DynamicNAICSInformation,
	naics-inactive			NULL,
	...
}
*/

struct DynamicDLTransmissionInformation : asn::choice<2, 0, true>
{
	static constexpr const char* name() {return "DynamicDLTransmissionInformation";}
	using parent_t = asn::choice<2, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 3;}
	void set_unknown() { set_index(3);  }
	~DynamicDLTransmissionInformation() {clear();}
	struct naics_active_t : DynamicNAICSInformation
	{
		static constexpr const char* name() {return "naics_active_t";}
		using parent_t = DynamicNAICSInformation;

	};
	struct naics_inactive_t : asn::nulltype
	{
		static constexpr const char* name() {return "naics_inactive_t";}
		using parent_t = asn::nulltype;

	};
	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<naics_active_t>(); break;
		case 2: var.destroy<naics_inactive_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<naics_active_t>());
		case 2: set_index(2); return v(var.build<naics_inactive_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<naics_active_t>());
		case 2: return v(var.as<naics_inactive_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<naics_active_t>(1);
		v.template operator()<naics_inactive_t>(2);

	}
	naics_active_t& select_naics_active() { if(get_index() != 1) { clear(); set_index(1); return var.build<naics_active_t>();} return var.as<naics_active_t>();}
	naics_active_t const* get_naics_active() const { if(get_index() == 1) { return &var.as<naics_active_t>();} return nullptr; }
	naics_inactive_t& select_naics_inactive() { if(get_index() != 2) { clear(); set_index(2); return var.build<naics_inactive_t>();} return var.as<naics_inactive_t>();}
	naics_inactive_t const* get_naics_inactive() const { if(get_index() == 2) { return &var.as<naics_inactive_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(naics_active_t)];
		char dummy2[sizeof(naics_inactive_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
E-RAB-ID ::= INTEGER (0..15, ...)
*/

struct E_RAB_ID : asn::integer<>
{
	using constraint_t = asn::constraints<true,asn::span<0, 15>>;
	static constexpr const char* name() {return "E-RAB-ID";}
	using parent_t = asn::integer<>;

};

/*
E-RAB-Item-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct E_RAB_Item_ExtIEs
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
E-RAB-Item ::= SEQUENCE {
	e-RAB-ID				E-RAB-ID,
	cause						Cause,
	iE-Extensions				ProtocolExtensionContainer { {E-RAB-Item-ExtIEs} } OPTIONAL,
	...
}
*/

struct E_RAB_Item : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "E-RAB-Item";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct e_RAB_ID_t : E_RAB_ID
	{
		static constexpr const char* name() {return "e_RAB_ID_t";}
		using parent_t = E_RAB_ID;

	};
	e_RAB_ID_t& ref_e_RAB_ID() {return e_RAB_ID;}
	e_RAB_ID_t const& ref_e_RAB_ID() const {return e_RAB_ID;}
	struct cause_t : Cause
	{
		static constexpr const char* name() {return "cause_t";}
		using parent_t = Cause;

	};
	cause_t& ref_cause() {return cause;}
	cause_t const& ref_cause() const {return cause;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RAB_Item_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RAB_Item_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(e_RAB_ID);
		v(cause);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(e_RAB_ID);
		v(cause);
		v(iE_Extensions);

	};
	void clear()
	{
		e_RAB_ID.clear();
		cause.clear();
		iE_Extensions.clear();

	};
	private:
	e_RAB_ID_t	e_RAB_ID;
	cause_t	cause;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RAB-ItemIEs 	X2AP-PROTOCOL-IES ::= {
	{ ID id-E-RAB-Item	 CRITICALITY ignore 	TYPE E-RAB-Item 	PRESENCE mandatory },
	...
}
*/

struct E_RAB_ItemIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_E_RAB_Item() { set(id_E_RAB_Item); type=1;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_E_RAB_Item)) { type = 1; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(id_E_RAB_Item);} return false;
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
		void select_id_E_RAB_Item() { set(ignore); type=1;}
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
		E_RAB_Item& select_id_E_RAB_Item() { return set<E_RAB_Item>(1); }
		E_RAB_Item const* get_id_E_RAB_Item() const { return get<E_RAB_Item>(1); }
		bool is_unknown() const { return type == 2; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<E_RAB_Item>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<E_RAB_Item>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_E_RAB_Item()); return true;
			case 2: if(type != 2) {clear(); asn::base::set();} type = 2; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<E_RAB_Item>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(E_RAB_Item)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_E_RAB_Item() { set(mandatory); type=1;}
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
QCI ::= INTEGER (0..255)
*/

struct QCI : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 255>>;
	static constexpr const char* name() {return "QCI";}
	using parent_t = asn::integer<>;

};

/*
ExtendedBitRate	::= INTEGER (10000000001..4000000000000,...)
*/

struct ExtendedBitRate : asn::integer<>
{
	using constraint_t = asn::constraints<true,asn::span<10000000001, 4000000000000>>;
	static constexpr const char* name() {return "ExtendedBitRate";}
	using parent_t = asn::integer<>;

};

/*
GBR-QosInformation-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
-- Extension for maximum bitrate > 10Gbps --
	{ ID id-extended-e-RAB-MaximumBitrateDL		CRITICALITY ignore	EXTENSION ExtendedBitRate	PRESENCE optional}|
	{ ID id-extended-e-RAB-MaximumBitrateUL		CRITICALITY ignore	EXTENSION ExtendedBitRate	PRESENCE optional}|
	{ ID id-extended-e-RAB-GuaranteedBitrateDL	CRITICALITY ignore	EXTENSION ExtendedBitRate	PRESENCE optional}|
	{ ID id-extended-e-RAB-GuaranteedBitrateUL	CRITICALITY ignore	EXTENSION ExtendedBitRate	PRESENCE optional},
	...
}
*/

struct GBR_QosInformation_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 5; }
		void clear() {type = 0;}
		void select_id_extended_e_RAB_MaximumBitrateDL() { set(id_extended_e_RAB_MaximumBitrateDL); type=1;}
		void select_id_extended_e_RAB_MaximumBitrateUL() { set(id_extended_e_RAB_MaximumBitrateUL); type=2;}
		void select_id_extended_e_RAB_GuaranteedBitrateDL() { set(id_extended_e_RAB_GuaranteedBitrateDL); type=3;}
		void select_id_extended_e_RAB_GuaranteedBitrateUL() { set(id_extended_e_RAB_GuaranteedBitrateUL); type=4;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_extended_e_RAB_MaximumBitrateDL)) { type = 1; return true; }
			else if(equal(id_extended_e_RAB_MaximumBitrateUL)) { type = 2; return true; }
			else if(equal(id_extended_e_RAB_GuaranteedBitrateDL)) { type = 3; return true; }
			else if(equal(id_extended_e_RAB_GuaranteedBitrateUL)) { type = 4; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(id_extended_e_RAB_MaximumBitrateDL);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_extended_e_RAB_MaximumBitrateUL);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(id_extended_e_RAB_GuaranteedBitrateDL);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(id_extended_e_RAB_GuaranteedBitrateUL);} return false;
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
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 5; }
		void clear() {type = 0;}
		void select_id_extended_e_RAB_MaximumBitrateDL() { set(ignore); type=1;}
		void select_id_extended_e_RAB_MaximumBitrateUL() { set(ignore); type=2;}
		void select_id_extended_e_RAB_GuaranteedBitrateDL() { set(ignore); type=3;}
		void select_id_extended_e_RAB_GuaranteedBitrateUL() { set(ignore); type=4;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
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
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		ExtendedBitRate& select_id_extended_e_RAB_MaximumBitrateDL() { return set<ExtendedBitRate>(1); }
		ExtendedBitRate const* get_id_extended_e_RAB_MaximumBitrateDL() const { return get<ExtendedBitRate>(1); }
		ExtendedBitRate& select_id_extended_e_RAB_MaximumBitrateUL() { return set<ExtendedBitRate>(2); }
		ExtendedBitRate const* get_id_extended_e_RAB_MaximumBitrateUL() const { return get<ExtendedBitRate>(2); }
		ExtendedBitRate& select_id_extended_e_RAB_GuaranteedBitrateDL() { return set<ExtendedBitRate>(3); }
		ExtendedBitRate const* get_id_extended_e_RAB_GuaranteedBitrateDL() const { return get<ExtendedBitRate>(3); }
		ExtendedBitRate& select_id_extended_e_RAB_GuaranteedBitrateUL() { return set<ExtendedBitRate>(4); }
		ExtendedBitRate const* get_id_extended_e_RAB_GuaranteedBitrateUL() const { return get<ExtendedBitRate>(4); }
		bool is_unknown() const { return type == 5; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<ExtendedBitRate>(); break;
			case 2: var.destroy<ExtendedBitRate>(); break;
			case 3: var.destroy<ExtendedBitRate>(); break;
			case 4: var.destroy<ExtendedBitRate>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<ExtendedBitRate>(1);
			v.template operator()<ExtendedBitRate>(2);
			v.template operator()<ExtendedBitRate>(3);
			v.template operator()<ExtendedBitRate>(4);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_extended_e_RAB_MaximumBitrateDL()); return true;
			case 2: v(select_id_extended_e_RAB_MaximumBitrateUL()); return true;
			case 3: v(select_id_extended_e_RAB_GuaranteedBitrateDL()); return true;
			case 4: v(select_id_extended_e_RAB_GuaranteedBitrateUL()); return true;
			case 5: if(type != 5) {clear(); asn::base::set();} type = 5; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<ExtendedBitRate>()); return true;
			case 2: v(var.as<ExtendedBitRate>()); return true;
			case 3: v(var.as<ExtendedBitRate>()); return true;
			case 4: v(var.as<ExtendedBitRate>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(ExtendedBitRate)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 5; }
		void clear() {type = 0;}
		void select_id_extended_e_RAB_MaximumBitrateDL() { set(optional); type=1;}
		void select_id_extended_e_RAB_MaximumBitrateUL() { set(optional); type=2;}
		void select_id_extended_e_RAB_GuaranteedBitrateDL() { set(optional); type=3;}
		void select_id_extended_e_RAB_GuaranteedBitrateUL() { set(optional); type=4;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(optional)) { type = 1; return true; }
			else if(equal(optional)) { type = 2; return true; }
			else if(equal(optional)) { type = 3; return true; }
			else if(equal(optional)) { type = 4; return true; }
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
			case 2: type = 2; if(v(ref_nested())) { return equal(optional);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(optional);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(optional);} return false;
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
GBR-QosInformation ::= SEQUENCE {
	e-RAB-MaximumBitrateDL			BitRate,
	e-RAB-MaximumBitrateUL			BitRate,
	e-RAB-GuaranteedBitrateDL		BitRate,
	e-RAB-GuaranteedBitrateUL		BitRate,
	iE-Extensions					ProtocolExtensionContainer { {GBR-QosInformation-ExtIEs} } OPTIONAL,
	...
}
*/

struct GBR_QosInformation : asn::sequence<5, 0, true, 1>
{
	static constexpr const char* name() {return "GBR-QosInformation";}
	using parent_t = asn::sequence<5, 0, true, 1>;
	struct e_RAB_MaximumBitrateDL_t : BitRate
	{
		static constexpr const char* name() {return "e_RAB_MaximumBitrateDL_t";}
		using parent_t = BitRate;

	};
	e_RAB_MaximumBitrateDL_t& ref_e_RAB_MaximumBitrateDL() {return e_RAB_MaximumBitrateDL;}
	e_RAB_MaximumBitrateDL_t const& ref_e_RAB_MaximumBitrateDL() const {return e_RAB_MaximumBitrateDL;}
	struct e_RAB_MaximumBitrateUL_t : BitRate
	{
		static constexpr const char* name() {return "e_RAB_MaximumBitrateUL_t";}
		using parent_t = BitRate;

	};
	e_RAB_MaximumBitrateUL_t& ref_e_RAB_MaximumBitrateUL() {return e_RAB_MaximumBitrateUL;}
	e_RAB_MaximumBitrateUL_t const& ref_e_RAB_MaximumBitrateUL() const {return e_RAB_MaximumBitrateUL;}
	struct e_RAB_GuaranteedBitrateDL_t : BitRate
	{
		static constexpr const char* name() {return "e_RAB_GuaranteedBitrateDL_t";}
		using parent_t = BitRate;

	};
	e_RAB_GuaranteedBitrateDL_t& ref_e_RAB_GuaranteedBitrateDL() {return e_RAB_GuaranteedBitrateDL;}
	e_RAB_GuaranteedBitrateDL_t const& ref_e_RAB_GuaranteedBitrateDL() const {return e_RAB_GuaranteedBitrateDL;}
	struct e_RAB_GuaranteedBitrateUL_t : BitRate
	{
		static constexpr const char* name() {return "e_RAB_GuaranteedBitrateUL_t";}
		using parent_t = BitRate;

	};
	e_RAB_GuaranteedBitrateUL_t& ref_e_RAB_GuaranteedBitrateUL() {return e_RAB_GuaranteedBitrateUL;}
	e_RAB_GuaranteedBitrateUL_t const& ref_e_RAB_GuaranteedBitrateUL() const {return e_RAB_GuaranteedBitrateUL;}
	struct iE_Extensions_t : ProtocolExtensionContainer<GBR_QosInformation_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<GBR_QosInformation_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(e_RAB_MaximumBitrateDL);
		v(e_RAB_MaximumBitrateUL);
		v(e_RAB_GuaranteedBitrateDL);
		v(e_RAB_GuaranteedBitrateUL);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(e_RAB_MaximumBitrateDL);
		v(e_RAB_MaximumBitrateUL);
		v(e_RAB_GuaranteedBitrateDL);
		v(e_RAB_GuaranteedBitrateUL);
		v(iE_Extensions);

	};
	void clear()
	{
		e_RAB_MaximumBitrateDL.clear();
		e_RAB_MaximumBitrateUL.clear();
		e_RAB_GuaranteedBitrateDL.clear();
		e_RAB_GuaranteedBitrateUL.clear();
		iE_Extensions.clear();

	};
	private:
	e_RAB_MaximumBitrateDL_t	e_RAB_MaximumBitrateDL;
	e_RAB_MaximumBitrateUL_t	e_RAB_MaximumBitrateUL;
	e_RAB_GuaranteedBitrateDL_t	e_RAB_GuaranteedBitrateDL;
	e_RAB_GuaranteedBitrateUL_t	e_RAB_GuaranteedBitrateUL;
	iE_Extensions_t	iE_Extensions;

};
/*
Packet-LossRate	::= INTEGER(0..1000)
*/

struct Packet_LossRate : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 1000>>;
	static constexpr const char* name() {return "Packet-LossRate";}
	using parent_t = asn::integer<>;

};

/*
E-RAB-Level-QoS-Parameters-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
-- Extended for introduction of downlink and uplink packet loss rate for enhanced Voice performance –
	{ ID id-DownlinkPacketLossRate			CRITICALITY ignore	EXTENSION Packet-LossRate		PRESENCE optional}|
	{ ID id-UplinkPacketLossRate			CRITICALITY ignore	EXTENSION Packet-LossRate		PRESENCE optional},
	...
}
*/

struct E_RAB_Level_QoS_Parameters_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_DownlinkPacketLossRate() { set(id_DownlinkPacketLossRate); type=1;}
		void select_id_UplinkPacketLossRate() { set(id_UplinkPacketLossRate); type=2;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_DownlinkPacketLossRate)) { type = 1; return true; }
			else if(equal(id_UplinkPacketLossRate)) { type = 2; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(id_DownlinkPacketLossRate);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_UplinkPacketLossRate);} return false;
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
		void select_id_DownlinkPacketLossRate() { set(ignore); type=1;}
		void select_id_UplinkPacketLossRate() { set(ignore); type=2;}
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
		Packet_LossRate& select_id_DownlinkPacketLossRate() { return set<Packet_LossRate>(1); }
		Packet_LossRate const* get_id_DownlinkPacketLossRate() const { return get<Packet_LossRate>(1); }
		Packet_LossRate& select_id_UplinkPacketLossRate() { return set<Packet_LossRate>(2); }
		Packet_LossRate const* get_id_UplinkPacketLossRate() const { return get<Packet_LossRate>(2); }
		bool is_unknown() const { return type == 3; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<Packet_LossRate>(); break;
			case 2: var.destroy<Packet_LossRate>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<Packet_LossRate>(1);
			v.template operator()<Packet_LossRate>(2);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_DownlinkPacketLossRate()); return true;
			case 2: v(select_id_UplinkPacketLossRate()); return true;
			case 3: if(type != 3) {clear(); asn::base::set();} type = 3; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<Packet_LossRate>()); return true;
			case 2: v(var.as<Packet_LossRate>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(Packet_LossRate)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_DownlinkPacketLossRate() { set(optional); type=1;}
		void select_id_UplinkPacketLossRate() { set(optional); type=2;}
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
E-RAB-Level-QoS-Parameters ::= SEQUENCE {
	qCI								QCI,
	allocationAndRetentionPriority	AllocationAndRetentionPriority,
	gbrQosInformation				GBR-QosInformation													OPTIONAL,
	iE-Extensions					ProtocolExtensionContainer { {E-RAB-Level-QoS-Parameters-ExtIEs} }	OPTIONAL,
	...
}
*/

struct E_RAB_Level_QoS_Parameters : asn::sequence<4, 0, true, 2>
{
	static constexpr const char* name() {return "E-RAB-Level-QoS-Parameters";}
	using parent_t = asn::sequence<4, 0, true, 2>;
	struct qCI_t : QCI
	{
		static constexpr const char* name() {return "qCI_t";}
		using parent_t = QCI;

	};
	qCI_t& ref_qCI() {return qCI;}
	qCI_t const& ref_qCI() const {return qCI;}
	struct allocationAndRetentionPriority_t : AllocationAndRetentionPriority
	{
		static constexpr const char* name() {return "allocationAndRetentionPriority_t";}
		using parent_t = AllocationAndRetentionPriority;

	};
	allocationAndRetentionPriority_t& ref_allocationAndRetentionPriority() {return allocationAndRetentionPriority;}
	allocationAndRetentionPriority_t const& ref_allocationAndRetentionPriority() const {return allocationAndRetentionPriority;}
	struct gbrQosInformation_t : GBR_QosInformation
	{
		static constexpr const char* name() {return "gbrQosInformation_t";}
		using parent_t = GBR_QosInformation;
		static constexpr bool optional = true;

	};
	gbrQosInformation_t& set_gbrQosInformation() { gbrQosInformation.setpresent(true); return gbrQosInformation;}
	gbrQosInformation_t const* get_gbrQosInformation() const {return gbrQosInformation.is_valid() ? &gbrQosInformation : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RAB_Level_QoS_Parameters_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RAB_Level_QoS_Parameters_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(qCI);
		v(allocationAndRetentionPriority);
		v(gbrQosInformation);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(qCI);
		v(allocationAndRetentionPriority);
		v(gbrQosInformation);
		v(iE_Extensions);

	};
	void clear()
	{
		qCI.clear();
		allocationAndRetentionPriority.clear();
		gbrQosInformation.clear();
		iE_Extensions.clear();

	};
	private:
	qCI_t	qCI;
	allocationAndRetentionPriority_t	allocationAndRetentionPriority;
	gbrQosInformation_t	gbrQosInformation;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RAB-List ::= SEQUENCE (SIZE(1.. maxnoofBearers)) OF ProtocolIE-Single-Container { {E-RAB-ItemIEs} }
*/

struct E_RAB_List_elm : ProtocolIE_Single_Container<E_RAB_ItemIEs>
{
	static constexpr const char* name() {return "E_RAB_List_elm";}
	using parent_t = ProtocolIE_Single_Container<E_RAB_ItemIEs>;

};
struct E_RAB_List : asn::sequenceof<E_RAB_List_elm>
{
	static constexpr const char* name() {return "E-RAB-List";}
	using parent_t = asn::sequenceof<E_RAB_List_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofBearers >>;

};
/*
E-RABUsageReport-Item-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct E_RABUsageReport_Item_ExtIEs
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
E-RABUsageReport-Item ::= SEQUENCE {
	startTimeStamp				OCTET STRING (SIZE(4)),
	endTimeStamp					OCTET STRING (SIZE(4)),
	usageCountUL					INTEGER (0..4294967295),
	usageCountDL					INTEGER (0..4294967295),
	iE-Extensions				ProtocolExtensionContainer { {E-RABUsageReport-Item-ExtIEs} } OPTIONAL,
...
}
*/

struct E_RABUsageReport_Item : asn::sequence<5, 0, true, 1>
{
	static constexpr const char* name() {return "E-RABUsageReport-Item";}
	using parent_t = asn::sequence<5, 0, true, 1>;
	struct startTimeStamp_t : asn::ostring<>
	{
		using constraint_t = asn::constraints<false,asn::one<4>>;
		static constexpr const char* name() {return "startTimeStamp_t";}
		using parent_t = asn::ostring<>;

	};

	startTimeStamp_t& ref_startTimeStamp() {return startTimeStamp;}
	startTimeStamp_t const& ref_startTimeStamp() const {return startTimeStamp;}
	struct endTimeStamp_t : asn::ostring<>
	{
		using constraint_t = asn::constraints<false,asn::one<4>>;
		static constexpr const char* name() {return "endTimeStamp_t";}
		using parent_t = asn::ostring<>;

	};

	endTimeStamp_t& ref_endTimeStamp() {return endTimeStamp;}
	endTimeStamp_t const& ref_endTimeStamp() const {return endTimeStamp;}
	struct usageCountUL_t : asn::integer<>
	{
		using constraint_t = asn::constraints<false,asn::span<0, 4294967295>>;
		static constexpr const char* name() {return "usageCountUL_t";}
		using parent_t = asn::integer<>;

	};

	usageCountUL_t& ref_usageCountUL() {return usageCountUL;}
	usageCountUL_t const& ref_usageCountUL() const {return usageCountUL;}
	struct usageCountDL_t : asn::integer<>
	{
		using constraint_t = asn::constraints<false,asn::span<0, 4294967295>>;
		static constexpr const char* name() {return "usageCountDL_t";}
		using parent_t = asn::integer<>;

	};

	usageCountDL_t& ref_usageCountDL() {return usageCountDL;}
	usageCountDL_t const& ref_usageCountDL() const {return usageCountDL;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABUsageReport_Item_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABUsageReport_Item_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(startTimeStamp);
		v(endTimeStamp);
		v(usageCountUL);
		v(usageCountDL);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(startTimeStamp);
		v(endTimeStamp);
		v(usageCountUL);
		v(usageCountDL);
		v(iE_Extensions);

	};
	void clear()
	{
		startTimeStamp.clear();
		endTimeStamp.clear();
		usageCountUL.clear();
		usageCountDL.clear();
		iE_Extensions.clear();

	};
	private:
	startTimeStamp_t	startTimeStamp;
	endTimeStamp_t	endTimeStamp;
	usageCountUL_t	usageCountUL;
	usageCountDL_t	usageCountDL;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABUsageReport-ItemIEs X2AP-PROTOCOL-IES ::= {
	{ ID id-E-RABUsageReport-Item	 CRITICALITY ignore 	TYPE E-RABUsageReport-Item 	PRESENCE mandatory },
	...
}
*/

struct E_RABUsageReport_ItemIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_E_RABUsageReport_Item() { set(id_E_RABUsageReport_Item); type=1;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_E_RABUsageReport_Item)) { type = 1; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(id_E_RABUsageReport_Item);} return false;
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
		void select_id_E_RABUsageReport_Item() { set(ignore); type=1;}
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
		E_RABUsageReport_Item& select_id_E_RABUsageReport_Item() { return set<E_RABUsageReport_Item>(1); }
		E_RABUsageReport_Item const* get_id_E_RABUsageReport_Item() const { return get<E_RABUsageReport_Item>(1); }
		bool is_unknown() const { return type == 2; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<E_RABUsageReport_Item>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<E_RABUsageReport_Item>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_E_RABUsageReport_Item()); return true;
			case 2: if(type != 2) {clear(); asn::base::set();} type = 2; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<E_RABUsageReport_Item>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(E_RABUsageReport_Item)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_E_RABUsageReport_Item() { set(mandatory); type=1;}
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
E-RABUsageReportList ::= SEQUENCE (SIZE(1..maxnooftimeperiods)) OF ProtocolIE-Single-Container { {E-RABUsageReport-ItemIEs} }
*/

struct E_RABUsageReportList_elm : ProtocolIE_Single_Container<E_RABUsageReport_ItemIEs>
{
	static constexpr const char* name() {return "E_RABUsageReportList_elm";}
	using parent_t = ProtocolIE_Single_Container<E_RABUsageReport_ItemIEs>;

};
struct E_RABUsageReportList : asn::sequenceof<E_RABUsageReportList_elm>
{
	static constexpr const char* name() {return "E-RABUsageReportList";}
	using parent_t = asn::sequenceof<E_RABUsageReportList_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnooftimeperiods >>;

};
/*
EARFCN ::= INTEGER (0..maxEARFCN)
*/

struct EARFCN : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0,  maxEARFCN >>;
	static constexpr const char* name() {return "EARFCN";}
	using parent_t = asn::integer<>;

};

/*
EARFCNExtension ::= INTEGER(maxEARFCNPlusOne..newmaxEARFCN, ...)
*/

struct EARFCNExtension : asn::integer<>
{
	using constraint_t = asn::constraints<true,asn::span< maxEARFCNPlusOne ,  newmaxEARFCN >>;
	static constexpr const char* name() {return "EARFCNExtension";}
	using parent_t = asn::integer<>;

};

/*
EN-DC-ResourceConfigurationExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct EN_DC_ResourceConfigurationExtIEs
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
EN-DC-ResourceConfiguration ::= SEQUENCE {
	pDCPatSgNB		ENUMERATED {present, not-present, ...},
	mCGresources	ENUMERATED {present, not-present, ...},
	sCGresources	ENUMERATED {present, not-present, ...},
	iE-Extensions					ProtocolExtensionContainer { {EN-DC-ResourceConfigurationExtIEs} }	OPTIONAL,
	...
}
*/

struct EN_DC_ResourceConfiguration : asn::sequence<4, 0, true, 1>
{
	static constexpr const char* name() {return "EN-DC-ResourceConfiguration";}
	using parent_t = asn::sequence<4, 0, true, 1>;
	struct pDCPatSgNB_t : asn::enumerated<2, 0, true>
	{
		static constexpr const char* name() {return "pDCPatSgNB_t";}
		using parent_t = asn::enumerated<2, 0, true>;
		typedef enum {
			present
			,not_present
		} index_t;

	};

	pDCPatSgNB_t& ref_pDCPatSgNB() {return pDCPatSgNB;}
	pDCPatSgNB_t const& ref_pDCPatSgNB() const {return pDCPatSgNB;}
	struct mCGresources_t : asn::enumerated<2, 0, true>
	{
		static constexpr const char* name() {return "mCGresources_t";}
		using parent_t = asn::enumerated<2, 0, true>;
		typedef enum {
			present
			,not_present
		} index_t;

	};

	mCGresources_t& ref_mCGresources() {return mCGresources;}
	mCGresources_t const& ref_mCGresources() const {return mCGresources;}
	struct sCGresources_t : asn::enumerated<2, 0, true>
	{
		static constexpr const char* name() {return "sCGresources_t";}
		using parent_t = asn::enumerated<2, 0, true>;
		typedef enum {
			present
			,not_present
		} index_t;

	};

	sCGresources_t& ref_sCGresources() {return sCGresources;}
	sCGresources_t const& ref_sCGresources() const {return sCGresources;}
	struct iE_Extensions_t : ProtocolExtensionContainer<EN_DC_ResourceConfigurationExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<EN_DC_ResourceConfigurationExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(pDCPatSgNB);
		v(mCGresources);
		v(sCGresources);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(pDCPatSgNB);
		v(mCGresources);
		v(sCGresources);
		v(iE_Extensions);

	};
	void clear()
	{
		pDCPatSgNB.clear();
		mCGresources.clear();
		sCGresources.clear();
		iE_Extensions.clear();

	};
	private:
	pDCPatSgNB_t	pDCPatSgNB;
	mCGresources_t	mCGresources;
	sCGresources_t	sCGresources;
	iE_Extensions_t	iE_Extensions;

};
/*
ENB-ID ::= CHOICE {
	macro-eNB-ID	BIT STRING (SIZE (20)),
	home-eNB-ID		BIT STRING (SIZE (28)),
	... ,
	short-Macro-eNB-ID		BIT STRING (SIZE(18)),
	long-Macro-eNB-ID		BIT STRING (SIZE(21))
}
*/

struct ENB_ID : asn::choice<4, 2, true>
{
	static constexpr const char* name() {return "ENB-ID";}
	using parent_t = asn::choice<4, 2, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 5;}
	void set_unknown() { set_index(5);  }
	~ENB_ID() {clear();}
	struct macro_eNB_ID_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<false,asn::one<20>>;
		static constexpr const char* name() {return "macro_eNB_ID_t";}
		using parent_t = asn::bstring<>;

	};

	struct home_eNB_ID_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<false,asn::one<28>>;
		static constexpr const char* name() {return "home_eNB_ID_t";}
		using parent_t = asn::bstring<>;

	};

	struct short_Macro_eNB_ID_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<false,asn::one<18>>;
		static constexpr const char* name() {return "short_Macro_eNB_ID_t";}
		using parent_t = asn::bstring<>;

	};

	struct long_Macro_eNB_ID_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<false,asn::one<21>>;
		static constexpr const char* name() {return "long_Macro_eNB_ID_t";}
		using parent_t = asn::bstring<>;

	};

	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<macro_eNB_ID_t>(); break;
		case 2: var.destroy<home_eNB_ID_t>(); break;
		case 3: var.destroy<short_Macro_eNB_ID_t>(); break;
		case 4: var.destroy<long_Macro_eNB_ID_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<macro_eNB_ID_t>());
		case 2: set_index(2); return v(var.build<home_eNB_ID_t>());
		case 3: set_index(3); return v(var.build<short_Macro_eNB_ID_t>());
		case 4: set_index(4); return v(var.build<long_Macro_eNB_ID_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<macro_eNB_ID_t>());
		case 2: return v(var.as<home_eNB_ID_t>());
		case 3: return v(var.as<short_Macro_eNB_ID_t>());
		case 4: return v(var.as<long_Macro_eNB_ID_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<macro_eNB_ID_t>(1);
		v.template operator()<home_eNB_ID_t>(2);
		v.template operator()<short_Macro_eNB_ID_t>(3);
		v.template operator()<long_Macro_eNB_ID_t>(4);

	}
	macro_eNB_ID_t& select_macro_eNB_ID() { if(get_index() != 1) { clear(); set_index(1); return var.build<macro_eNB_ID_t>();} return var.as<macro_eNB_ID_t>();}
	macro_eNB_ID_t const* get_macro_eNB_ID() const { if(get_index() == 1) { return &var.as<macro_eNB_ID_t>();} return nullptr; }
	home_eNB_ID_t& select_home_eNB_ID() { if(get_index() != 2) { clear(); set_index(2); return var.build<home_eNB_ID_t>();} return var.as<home_eNB_ID_t>();}
	home_eNB_ID_t const* get_home_eNB_ID() const { if(get_index() == 2) { return &var.as<home_eNB_ID_t>();} return nullptr; }
	short_Macro_eNB_ID_t& select_short_Macro_eNB_ID() { if(get_index() != 3) { clear(); set_index(3); return var.build<short_Macro_eNB_ID_t>();} return var.as<short_Macro_eNB_ID_t>();}
	short_Macro_eNB_ID_t const* get_short_Macro_eNB_ID() const { if(get_index() == 3) { return &var.as<short_Macro_eNB_ID_t>();} return nullptr; }
	long_Macro_eNB_ID_t& select_long_Macro_eNB_ID() { if(get_index() != 4) { clear(); set_index(4); return var.build<long_Macro_eNB_ID_t>();} return var.as<long_Macro_eNB_ID_t>();}
	long_Macro_eNB_ID_t const* get_long_Macro_eNB_ID() const { if(get_index() == 4) { return &var.as<long_Macro_eNB_ID_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(macro_eNB_ID_t)];
		char dummy2[sizeof(home_eNB_ID_t)];
		char dummy3[sizeof(short_Macro_eNB_ID_t)];
		char dummy4[sizeof(long_Macro_eNB_ID_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
EPLMNs ::= SEQUENCE (SIZE(1..maxnoofEPLMNs)) OF PLMN-Identity
*/

struct EPLMNs_elm : PLMN_Identity
{
	static constexpr const char* name() {return "EPLMNs_elm";}
	using parent_t = PLMN_Identity;

};
struct EPLMNs : asn::sequenceof<EPLMNs_elm>
{
	static constexpr const char* name() {return "EPLMNs";}
	using parent_t = asn::sequenceof<EPLMNs_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofEPLMNs >>;

};
/*
UserPlaneTrafficActivityReport ::= ENUMERATED {inactive, re-activated, ...}
*/

struct UserPlaneTrafficActivityReport : asn::enumerated<2, 0, true>
{
	static constexpr const char* name() {return "UserPlaneTrafficActivityReport";}
	using parent_t = asn::enumerated<2, 0, true>;
	typedef enum {
		inactive
		,re_activated
	} index_t;

};

/*
ERABActivityNotifyItem-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct ERABActivityNotifyItem_ExtIEs
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
ERABActivityNotifyItem ::= SEQUENCE {
	e-RAB-ID						E-RAB-ID,
	activityReport					UserPlaneTrafficActivityReport,
	iE-Extensions					ProtocolExtensionContainer { {ERABActivityNotifyItem-ExtIEs} }	OPTIONAL,
	...
}
*/

struct ERABActivityNotifyItem : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "ERABActivityNotifyItem";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct e_RAB_ID_t : E_RAB_ID
	{
		static constexpr const char* name() {return "e_RAB_ID_t";}
		using parent_t = E_RAB_ID;

	};
	e_RAB_ID_t& ref_e_RAB_ID() {return e_RAB_ID;}
	e_RAB_ID_t const& ref_e_RAB_ID() const {return e_RAB_ID;}
	struct activityReport_t : UserPlaneTrafficActivityReport
	{
		static constexpr const char* name() {return "activityReport_t";}
		using parent_t = UserPlaneTrafficActivityReport;

	};
	activityReport_t& ref_activityReport() {return activityReport;}
	activityReport_t const& ref_activityReport() const {return activityReport;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ERABActivityNotifyItem_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ERABActivityNotifyItem_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(e_RAB_ID);
		v(activityReport);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(e_RAB_ID);
		v(activityReport);
		v(iE_Extensions);

	};
	void clear()
	{
		e_RAB_ID.clear();
		activityReport.clear();
		iE_Extensions.clear();

	};
	private:
	e_RAB_ID_t	e_RAB_ID;
	activityReport_t	activityReport;
	iE_Extensions_t	iE_Extensions;

};
/*
ERABActivityNotifyItemList ::= SEQUENCE (SIZE (0..maxnoofBearers)) OF ERABActivityNotifyItem
*/

struct ERABActivityNotifyItemList_elm : ERABActivityNotifyItem
{
	static constexpr const char* name() {return "ERABActivityNotifyItemList_elm";}
	using parent_t = ERABActivityNotifyItem;

};
struct ERABActivityNotifyItemList : asn::sequenceof<ERABActivityNotifyItemList_elm>
{
	static constexpr const char* name() {return "ERABActivityNotifyItemList";}
	using parent_t = asn::sequenceof<ERABActivityNotifyItemList_elm>;
	using constraint_t = asn::constraints<false,asn::span<0,  maxnoofBearers >>;

};
/*
Transmission-Bandwidth ::= ENUMERATED {
		bw6,
	 	bw15,
		bw25,
	 	bw50,
		bw75,
		bw100,
		...,
		bw1
}
*/

struct Transmission_Bandwidth : asn::enumerated<7, 1, true>
{
	static constexpr const char* name() {return "Transmission-Bandwidth";}
	using parent_t = asn::enumerated<7, 1, true>;
	typedef enum {
		bw6
		,bw15
		,bw25
		,bw50
		,bw75
		,bw100
		,bw1
	} index_t;

};

/*
OffsetOfNbiotChannelNumberToEARFCN ::= ENUMERATED {
		minusTen,
		minusNine,
		minusEight,
		minusSeven,
		minusSix,
		minusFive,
		minusFour,
		minusThree,
		minusTwo,
		minusOne,
		minusZeroDotFive,
		zero,
		one,
		two,
		three,
		four,
		five,
		six,
		seven,
		eight,
		nine,
		...
}
*/

struct OffsetOfNbiotChannelNumberToEARFCN : asn::enumerated<21, 0, true>
{
	static constexpr const char* name() {return "OffsetOfNbiotChannelNumberToEARFCN";}
	using parent_t = asn::enumerated<21, 0, true>;
	typedef enum {
		minusTen
		,minusNine
		,minusEight
		,minusSeven
		,minusSix
		,minusFive
		,minusFour
		,minusThree
		,minusTwo
		,minusOne
		,minusZeroDotFive
		,zero
		,one
		,two
		,three
		,four
		,five
		,six
		,seven
		,eight
		,nine
	} index_t;

};

/*
NRS-NSSS-PowerOffset ::= ENUMERATED { minusThree, zero, three, ...}
*/

struct NRS_NSSS_PowerOffset : asn::enumerated<3, 0, true>
{
	static constexpr const char* name() {return "NRS-NSSS-PowerOffset";}
	using parent_t = asn::enumerated<3, 0, true>;
	typedef enum {
		minusThree
		,zero
		,three
	} index_t;

};

/*
NSSS-NumOccasionDifferentPrecoder ::= ENUMERATED { two, four, eight, ...}
*/

struct NSSS_NumOccasionDifferentPrecoder : asn::enumerated<3, 0, true>
{
	static constexpr const char* name() {return "NSSS-NumOccasionDifferentPrecoder";}
	using parent_t = asn::enumerated<3, 0, true>;
	typedef enum {
		two
		,four
		,eight
	} index_t;

};

/*
FDD-Info-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	{ ID id-UL-EARFCNExtension						CRITICALITY reject	EXTENSION EARFCNExtension									PRESENCE optional}|
	{ ID id-DL-EARFCNExtension						CRITICALITY reject	EXTENSION EARFCNExtension									PRESENCE optional}|
	{ ID id-OffsetOfNbiotChannelNumberToDL-EARFCN	CRITICALITY reject	EXTENSION OffsetOfNbiotChannelNumberToEARFCN		PRESENCE optional}|
	{ ID id-OffsetOfNbiotChannelNumberToUL-EARFCN	CRITICALITY reject	EXTENSION OffsetOfNbiotChannelNumberToEARFCN		PRESENCE optional}|
	{ ID id-NRS-NSSS-PowerOffset					CRITICALITY ignore	EXTENSION NRS-NSSS-PowerOffset							PRESENCE optional}|
	{ ID id-NSSS-NumOccasionDifferentPrecoder		CRITICALITY ignore	EXTENSION NSSS-NumOccasionDifferentPrecoder			PRESENCE optional},
	...
}
*/

struct FDD_Info_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 7; }
		void clear() {type = 0;}
		void select_id_UL_EARFCNExtension() { set(id_UL_EARFCNExtension); type=1;}
		void select_id_DL_EARFCNExtension() { set(id_DL_EARFCNExtension); type=2;}
		void select_id_OffsetOfNbiotChannelNumberToDL_EARFCN() { set(id_OffsetOfNbiotChannelNumberToDL_EARFCN); type=3;}
		void select_id_OffsetOfNbiotChannelNumberToUL_EARFCN() { set(id_OffsetOfNbiotChannelNumberToUL_EARFCN); type=4;}
		void select_id_NRS_NSSS_PowerOffset() { set(id_NRS_NSSS_PowerOffset); type=5;}
		void select_id_NSSS_NumOccasionDifferentPrecoder() { set(id_NSSS_NumOccasionDifferentPrecoder); type=6;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_UL_EARFCNExtension)) { type = 1; return true; }
			else if(equal(id_DL_EARFCNExtension)) { type = 2; return true; }
			else if(equal(id_OffsetOfNbiotChannelNumberToDL_EARFCN)) { type = 3; return true; }
			else if(equal(id_OffsetOfNbiotChannelNumberToUL_EARFCN)) { type = 4; return true; }
			else if(equal(id_NRS_NSSS_PowerOffset)) { type = 5; return true; }
			else if(equal(id_NSSS_NumOccasionDifferentPrecoder)) { type = 6; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(id_UL_EARFCNExtension);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_DL_EARFCNExtension);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(id_OffsetOfNbiotChannelNumberToDL_EARFCN);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(id_OffsetOfNbiotChannelNumberToUL_EARFCN);} return false;
			case 5: type = 5; if(v(ref_nested())) { return equal(id_NRS_NSSS_PowerOffset);} return false;
			case 6: type = 6; if(v(ref_nested())) { return equal(id_NSSS_NumOccasionDifferentPrecoder);} return false;
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
		void select_id_UL_EARFCNExtension() { set(reject); type=1;}
		void select_id_DL_EARFCNExtension() { set(reject); type=2;}
		void select_id_OffsetOfNbiotChannelNumberToDL_EARFCN() { set(reject); type=3;}
		void select_id_OffsetOfNbiotChannelNumberToUL_EARFCN() { set(reject); type=4;}
		void select_id_NRS_NSSS_PowerOffset() { set(ignore); type=5;}
		void select_id_NSSS_NumOccasionDifferentPrecoder() { set(ignore); type=6;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(reject)) { type = 1; return true; }
			else if(equal(reject)) { type = 2; return true; }
			else if(equal(reject)) { type = 3; return true; }
			else if(equal(reject)) { type = 4; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(reject);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(reject);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(reject);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(reject);} return false;
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
		EARFCNExtension& select_id_UL_EARFCNExtension() { return set<EARFCNExtension>(1); }
		EARFCNExtension const* get_id_UL_EARFCNExtension() const { return get<EARFCNExtension>(1); }
		EARFCNExtension& select_id_DL_EARFCNExtension() { return set<EARFCNExtension>(2); }
		EARFCNExtension const* get_id_DL_EARFCNExtension() const { return get<EARFCNExtension>(2); }
		OffsetOfNbiotChannelNumberToEARFCN& select_id_OffsetOfNbiotChannelNumberToDL_EARFCN() { return set<OffsetOfNbiotChannelNumberToEARFCN>(3); }
		OffsetOfNbiotChannelNumberToEARFCN const* get_id_OffsetOfNbiotChannelNumberToDL_EARFCN() const { return get<OffsetOfNbiotChannelNumberToEARFCN>(3); }
		OffsetOfNbiotChannelNumberToEARFCN& select_id_OffsetOfNbiotChannelNumberToUL_EARFCN() { return set<OffsetOfNbiotChannelNumberToEARFCN>(4); }
		OffsetOfNbiotChannelNumberToEARFCN const* get_id_OffsetOfNbiotChannelNumberToUL_EARFCN() const { return get<OffsetOfNbiotChannelNumberToEARFCN>(4); }
		NRS_NSSS_PowerOffset& select_id_NRS_NSSS_PowerOffset() { return set<NRS_NSSS_PowerOffset>(5); }
		NRS_NSSS_PowerOffset const* get_id_NRS_NSSS_PowerOffset() const { return get<NRS_NSSS_PowerOffset>(5); }
		NSSS_NumOccasionDifferentPrecoder& select_id_NSSS_NumOccasionDifferentPrecoder() { return set<NSSS_NumOccasionDifferentPrecoder>(6); }
		NSSS_NumOccasionDifferentPrecoder const* get_id_NSSS_NumOccasionDifferentPrecoder() const { return get<NSSS_NumOccasionDifferentPrecoder>(6); }
		bool is_unknown() const { return type == 7; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<EARFCNExtension>(); break;
			case 2: var.destroy<EARFCNExtension>(); break;
			case 3: var.destroy<OffsetOfNbiotChannelNumberToEARFCN>(); break;
			case 4: var.destroy<OffsetOfNbiotChannelNumberToEARFCN>(); break;
			case 5: var.destroy<NRS_NSSS_PowerOffset>(); break;
			case 6: var.destroy<NSSS_NumOccasionDifferentPrecoder>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<EARFCNExtension>(1);
			v.template operator()<EARFCNExtension>(2);
			v.template operator()<OffsetOfNbiotChannelNumberToEARFCN>(3);
			v.template operator()<OffsetOfNbiotChannelNumberToEARFCN>(4);
			v.template operator()<NRS_NSSS_PowerOffset>(5);
			v.template operator()<NSSS_NumOccasionDifferentPrecoder>(6);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_UL_EARFCNExtension()); return true;
			case 2: v(select_id_DL_EARFCNExtension()); return true;
			case 3: v(select_id_OffsetOfNbiotChannelNumberToDL_EARFCN()); return true;
			case 4: v(select_id_OffsetOfNbiotChannelNumberToUL_EARFCN()); return true;
			case 5: v(select_id_NRS_NSSS_PowerOffset()); return true;
			case 6: v(select_id_NSSS_NumOccasionDifferentPrecoder()); return true;
			case 7: if(type != 7) {clear(); asn::base::set();} type = 7; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<EARFCNExtension>()); return true;
			case 2: v(var.as<EARFCNExtension>()); return true;
			case 3: v(var.as<OffsetOfNbiotChannelNumberToEARFCN>()); return true;
			case 4: v(var.as<OffsetOfNbiotChannelNumberToEARFCN>()); return true;
			case 5: v(var.as<NRS_NSSS_PowerOffset>()); return true;
			case 6: v(var.as<NSSS_NumOccasionDifferentPrecoder>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(EARFCNExtension)];
			char dummy2[sizeof(NRS_NSSS_PowerOffset)];
			char dummy3[sizeof(NSSS_NumOccasionDifferentPrecoder)];
			char dummy4[sizeof(OffsetOfNbiotChannelNumberToEARFCN)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 7; }
		void clear() {type = 0;}
		void select_id_UL_EARFCNExtension() { set(optional); type=1;}
		void select_id_DL_EARFCNExtension() { set(optional); type=2;}
		void select_id_OffsetOfNbiotChannelNumberToDL_EARFCN() { set(optional); type=3;}
		void select_id_OffsetOfNbiotChannelNumberToUL_EARFCN() { set(optional); type=4;}
		void select_id_NRS_NSSS_PowerOffset() { set(optional); type=5;}
		void select_id_NSSS_NumOccasionDifferentPrecoder() { set(optional); type=6;}
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
FDD-Info ::= SEQUENCE {
	uL-EARFCN						EARFCN,
	dL-EARFCN						EARFCN,
	uL-Transmission-Bandwidth		Transmission-Bandwidth,
	dL-Transmission-Bandwidth		Transmission-Bandwidth,
	iE-Extensions				ProtocolExtensionContainer { {FDD-Info-ExtIEs} } OPTIONAL,
	...
}
*/

struct FDD_Info : asn::sequence<5, 0, true, 1>
{
	static constexpr const char* name() {return "FDD-Info";}
	using parent_t = asn::sequence<5, 0, true, 1>;
	struct uL_EARFCN_t : EARFCN
	{
		static constexpr const char* name() {return "uL_EARFCN_t";}
		using parent_t = EARFCN;

	};
	uL_EARFCN_t& ref_uL_EARFCN() {return uL_EARFCN;}
	uL_EARFCN_t const& ref_uL_EARFCN() const {return uL_EARFCN;}
	struct dL_EARFCN_t : EARFCN
	{
		static constexpr const char* name() {return "dL_EARFCN_t";}
		using parent_t = EARFCN;

	};
	dL_EARFCN_t& ref_dL_EARFCN() {return dL_EARFCN;}
	dL_EARFCN_t const& ref_dL_EARFCN() const {return dL_EARFCN;}
	struct uL_Transmission_Bandwidth_t : Transmission_Bandwidth
	{
		static constexpr const char* name() {return "uL_Transmission_Bandwidth_t";}
		using parent_t = Transmission_Bandwidth;

	};
	uL_Transmission_Bandwidth_t& ref_uL_Transmission_Bandwidth() {return uL_Transmission_Bandwidth;}
	uL_Transmission_Bandwidth_t const& ref_uL_Transmission_Bandwidth() const {return uL_Transmission_Bandwidth;}
	struct dL_Transmission_Bandwidth_t : Transmission_Bandwidth
	{
		static constexpr const char* name() {return "dL_Transmission_Bandwidth_t";}
		using parent_t = Transmission_Bandwidth;

	};
	dL_Transmission_Bandwidth_t& ref_dL_Transmission_Bandwidth() {return dL_Transmission_Bandwidth;}
	dL_Transmission_Bandwidth_t const& ref_dL_Transmission_Bandwidth() const {return dL_Transmission_Bandwidth;}
	struct iE_Extensions_t : ProtocolExtensionContainer<FDD_Info_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<FDD_Info_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(uL_EARFCN);
		v(dL_EARFCN);
		v(uL_Transmission_Bandwidth);
		v(dL_Transmission_Bandwidth);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(uL_EARFCN);
		v(dL_EARFCN);
		v(uL_Transmission_Bandwidth);
		v(dL_Transmission_Bandwidth);
		v(iE_Extensions);

	};
	void clear()
	{
		uL_EARFCN.clear();
		dL_EARFCN.clear();
		uL_Transmission_Bandwidth.clear();
		dL_Transmission_Bandwidth.clear();
		iE_Extensions.clear();

	};
	private:
	uL_EARFCN_t	uL_EARFCN;
	dL_EARFCN_t	dL_EARFCN;
	uL_Transmission_Bandwidth_t	uL_Transmission_Bandwidth;
	dL_Transmission_Bandwidth_t	dL_Transmission_Bandwidth;
	iE_Extensions_t	iE_Extensions;

};
/*
SubframeAssignment ::= ENUMERATED {
	sa0,
	sa1,
	sa2,
	sa3,
	sa4,
	sa5,
	sa6,
	...
}
*/

struct SubframeAssignment : asn::enumerated<7, 0, true>
{
	static constexpr const char* name() {return "SubframeAssignment";}
	using parent_t = asn::enumerated<7, 0, true>;
	typedef enum {
		sa0
		,sa1
		,sa2
		,sa3
		,sa4
		,sa5
		,sa6
	} index_t;

};

/*
SpecialSubframePatterns ::= ENUMERATED {
	ssp0,
	ssp1,
	ssp2,
	ssp3,
	ssp4,
	ssp5,
	ssp6,
	ssp7,
	ssp8,
	...
}
*/

struct SpecialSubframePatterns : asn::enumerated<9, 0, true>
{
	static constexpr const char* name() {return "SpecialSubframePatterns";}
	using parent_t = asn::enumerated<9, 0, true>;
	typedef enum {
		ssp0
		,ssp1
		,ssp2
		,ssp3
		,ssp4
		,ssp5
		,ssp6
		,ssp7
		,ssp8
	} index_t;

};

/*
SpecialSubframe-Info-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct SpecialSubframe_Info_ExtIEs
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
SpecialSubframe-Info ::= SEQUENCE {
	specialSubframePatterns		SpecialSubframePatterns,
	cyclicPrefixDL				CyclicPrefixDL,
	cyclicPrefixUL				CyclicPrefixUL,
	iE-Extensions				ProtocolExtensionContainer { {SpecialSubframe-Info-ExtIEs} } OPTIONAL,
	...
}
*/

struct SpecialSubframe_Info : asn::sequence<4, 0, true, 1>
{
	static constexpr const char* name() {return "SpecialSubframe-Info";}
	using parent_t = asn::sequence<4, 0, true, 1>;
	struct specialSubframePatterns_t : SpecialSubframePatterns
	{
		static constexpr const char* name() {return "specialSubframePatterns_t";}
		using parent_t = SpecialSubframePatterns;

	};
	specialSubframePatterns_t& ref_specialSubframePatterns() {return specialSubframePatterns;}
	specialSubframePatterns_t const& ref_specialSubframePatterns() const {return specialSubframePatterns;}
	struct cyclicPrefixDL_t : CyclicPrefixDL
	{
		static constexpr const char* name() {return "cyclicPrefixDL_t";}
		using parent_t = CyclicPrefixDL;

	};
	cyclicPrefixDL_t& ref_cyclicPrefixDL() {return cyclicPrefixDL;}
	cyclicPrefixDL_t const& ref_cyclicPrefixDL() const {return cyclicPrefixDL;}
	struct cyclicPrefixUL_t : CyclicPrefixUL
	{
		static constexpr const char* name() {return "cyclicPrefixUL_t";}
		using parent_t = CyclicPrefixUL;

	};
	cyclicPrefixUL_t& ref_cyclicPrefixUL() {return cyclicPrefixUL;}
	cyclicPrefixUL_t const& ref_cyclicPrefixUL() const {return cyclicPrefixUL;}
	struct iE_Extensions_t : ProtocolExtensionContainer<SpecialSubframe_Info_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<SpecialSubframe_Info_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(specialSubframePatterns);
		v(cyclicPrefixDL);
		v(cyclicPrefixUL);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(specialSubframePatterns);
		v(cyclicPrefixDL);
		v(cyclicPrefixUL);
		v(iE_Extensions);

	};
	void clear()
	{
		specialSubframePatterns.clear();
		cyclicPrefixDL.clear();
		cyclicPrefixUL.clear();
		iE_Extensions.clear();

	};
	private:
	specialSubframePatterns_t	specialSubframePatterns;
	cyclicPrefixDL_t	cyclicPrefixDL;
	cyclicPrefixUL_t	cyclicPrefixUL;
	iE_Extensions_t	iE_Extensions;

};
/*
TDD-Info-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	{ ID id-AdditionalSpecialSubframe-Info	CRITICALITY ignore	EXTENSION AdditionalSpecialSubframe-Info	PRESENCE optional}|
	{ ID id-eARFCNExtension					CRITICALITY reject	EXTENSION EARFCNExtension						PRESENCE optional}|
	{ ID id-AdditionalSpecialSubframeExtension-Info	CRITICALITY ignore	EXTENSION AdditionalSpecialSubframeExtension-Info	PRESENCE optional},
	...
}
*/

struct TDD_Info_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 4; }
		void clear() {type = 0;}
		void select_id_AdditionalSpecialSubframe_Info() { set(id_AdditionalSpecialSubframe_Info); type=1;}
		void select_id_eARFCNExtension() { set(id_eARFCNExtension); type=2;}
		void select_id_AdditionalSpecialSubframeExtension_Info() { set(id_AdditionalSpecialSubframeExtension_Info); type=3;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_AdditionalSpecialSubframe_Info)) { type = 1; return true; }
			else if(equal(id_eARFCNExtension)) { type = 2; return true; }
			else if(equal(id_AdditionalSpecialSubframeExtension_Info)) { type = 3; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(id_AdditionalSpecialSubframe_Info);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_eARFCNExtension);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(id_AdditionalSpecialSubframeExtension_Info);} return false;
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
		void select_id_AdditionalSpecialSubframe_Info() { set(ignore); type=1;}
		void select_id_eARFCNExtension() { set(reject); type=2;}
		void select_id_AdditionalSpecialSubframeExtension_Info() { set(ignore); type=3;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else if(equal(reject)) { type = 2; return true; }
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
			case 2: type = 2; if(v(ref_nested())) { return equal(reject);} return false;
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
		AdditionalSpecialSubframe_Info& select_id_AdditionalSpecialSubframe_Info() { return set<AdditionalSpecialSubframe_Info>(1); }
		AdditionalSpecialSubframe_Info const* get_id_AdditionalSpecialSubframe_Info() const { return get<AdditionalSpecialSubframe_Info>(1); }
		EARFCNExtension& select_id_eARFCNExtension() { return set<EARFCNExtension>(2); }
		EARFCNExtension const* get_id_eARFCNExtension() const { return get<EARFCNExtension>(2); }
		AdditionalSpecialSubframeExtension_Info& select_id_AdditionalSpecialSubframeExtension_Info() { return set<AdditionalSpecialSubframeExtension_Info>(3); }
		AdditionalSpecialSubframeExtension_Info const* get_id_AdditionalSpecialSubframeExtension_Info() const { return get<AdditionalSpecialSubframeExtension_Info>(3); }
		bool is_unknown() const { return type == 4; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<AdditionalSpecialSubframe_Info>(); break;
			case 2: var.destroy<EARFCNExtension>(); break;
			case 3: var.destroy<AdditionalSpecialSubframeExtension_Info>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<AdditionalSpecialSubframe_Info>(1);
			v.template operator()<EARFCNExtension>(2);
			v.template operator()<AdditionalSpecialSubframeExtension_Info>(3);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_AdditionalSpecialSubframe_Info()); return true;
			case 2: v(select_id_eARFCNExtension()); return true;
			case 3: v(select_id_AdditionalSpecialSubframeExtension_Info()); return true;
			case 4: if(type != 4) {clear(); asn::base::set();} type = 4; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<AdditionalSpecialSubframe_Info>()); return true;
			case 2: v(var.as<EARFCNExtension>()); return true;
			case 3: v(var.as<AdditionalSpecialSubframeExtension_Info>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(AdditionalSpecialSubframeExtension_Info)];
			char dummy2[sizeof(AdditionalSpecialSubframe_Info)];
			char dummy3[sizeof(EARFCNExtension)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 4; }
		void clear() {type = 0;}
		void select_id_AdditionalSpecialSubframe_Info() { set(optional); type=1;}
		void select_id_eARFCNExtension() { set(optional); type=2;}
		void select_id_AdditionalSpecialSubframeExtension_Info() { set(optional); type=3;}
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
TDD-Info ::= SEQUENCE {
	eARFCN							EARFCN,
	transmission-Bandwidth			Transmission-Bandwidth,
	subframeAssignment				SubframeAssignment,
	specialSubframe-Info			SpecialSubframe-Info,
	iE-Extensions					ProtocolExtensionContainer { {TDD-Info-ExtIEs} } OPTIONAL,
	...
}
*/

struct TDD_Info : asn::sequence<5, 0, true, 1>
{
	static constexpr const char* name() {return "TDD-Info";}
	using parent_t = asn::sequence<5, 0, true, 1>;
	struct eARFCN_t : EARFCN
	{
		static constexpr const char* name() {return "eARFCN_t";}
		using parent_t = EARFCN;

	};
	eARFCN_t& ref_eARFCN() {return eARFCN;}
	eARFCN_t const& ref_eARFCN() const {return eARFCN;}
	struct transmission_Bandwidth_t : Transmission_Bandwidth
	{
		static constexpr const char* name() {return "transmission_Bandwidth_t";}
		using parent_t = Transmission_Bandwidth;

	};
	transmission_Bandwidth_t& ref_transmission_Bandwidth() {return transmission_Bandwidth;}
	transmission_Bandwidth_t const& ref_transmission_Bandwidth() const {return transmission_Bandwidth;}
	struct subframeAssignment_t : SubframeAssignment
	{
		static constexpr const char* name() {return "subframeAssignment_t";}
		using parent_t = SubframeAssignment;

	};
	subframeAssignment_t& ref_subframeAssignment() {return subframeAssignment;}
	subframeAssignment_t const& ref_subframeAssignment() const {return subframeAssignment;}
	struct specialSubframe_Info_t : SpecialSubframe_Info
	{
		static constexpr const char* name() {return "specialSubframe_Info_t";}
		using parent_t = SpecialSubframe_Info;

	};
	specialSubframe_Info_t& ref_specialSubframe_Info() {return specialSubframe_Info;}
	specialSubframe_Info_t const& ref_specialSubframe_Info() const {return specialSubframe_Info;}
	struct iE_Extensions_t : ProtocolExtensionContainer<TDD_Info_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<TDD_Info_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(eARFCN);
		v(transmission_Bandwidth);
		v(subframeAssignment);
		v(specialSubframe_Info);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(eARFCN);
		v(transmission_Bandwidth);
		v(subframeAssignment);
		v(specialSubframe_Info);
		v(iE_Extensions);

	};
	void clear()
	{
		eARFCN.clear();
		transmission_Bandwidth.clear();
		subframeAssignment.clear();
		specialSubframe_Info.clear();
		iE_Extensions.clear();

	};
	private:
	eARFCN_t	eARFCN;
	transmission_Bandwidth_t	transmission_Bandwidth;
	subframeAssignment_t	subframeAssignment;
	specialSubframe_Info_t	specialSubframe_Info;
	iE_Extensions_t	iE_Extensions;

};
/*
EUTRA-Mode-Info ::= CHOICE {
	fDD		FDD-Info,
	tDD		TDD-Info,
	...
}
*/

struct EUTRA_Mode_Info : asn::choice<2, 0, true>
{
	static constexpr const char* name() {return "EUTRA-Mode-Info";}
	using parent_t = asn::choice<2, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 3;}
	void set_unknown() { set_index(3);  }
	~EUTRA_Mode_Info() {clear();}
	struct fDD_t : FDD_Info
	{
		static constexpr const char* name() {return "fDD_t";}
		using parent_t = FDD_Info;

	};
	struct tDD_t : TDD_Info
	{
		static constexpr const char* name() {return "tDD_t";}
		using parent_t = TDD_Info;

	};
	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<fDD_t>(); break;
		case 2: var.destroy<tDD_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<fDD_t>());
		case 2: set_index(2); return v(var.build<tDD_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<fDD_t>());
		case 2: return v(var.as<tDD_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<fDD_t>(1);
		v.template operator()<tDD_t>(2);

	}
	fDD_t& select_fDD() { if(get_index() != 1) { clear(); set_index(1); return var.build<fDD_t>();} return var.as<fDD_t>();}
	fDD_t const* get_fDD() const { if(get_index() == 1) { return &var.as<fDD_t>();} return nullptr; }
	tDD_t& select_tDD() { if(get_index() != 2) { clear(); set_index(2); return var.build<tDD_t>();} return var.as<tDD_t>();}
	tDD_t const* get_tDD() const { if(get_index() == 2) { return &var.as<tDD_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(fDD_t)];
		char dummy2[sizeof(tDD_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
EUTRANTraceID		::= OCTET STRING (SIZE (8))
*/

struct EUTRANTraceID : asn::ostring<>
{
	using constraint_t = asn::constraints<false,asn::one<8>>;
	static constexpr const char* name() {return "EUTRANTraceID";}
	using parent_t = asn::ostring<>;

};

/*
EncryptionAlgorithms ::= BIT STRING (SIZE (16, ...))
*/

struct EncryptionAlgorithms : asn::bstring<>
{
	using constraint_t = asn::constraints<true,asn::one<16>>;
	static constexpr const char* name() {return "EncryptionAlgorithms";}
	using parent_t = asn::bstring<>;

};

/*
RNTP-Threshold ::= ENUMERATED {
	minusInfinity,
	minusEleven,
	minusTen,
	minusNine,
	minusEight,
	minusSeven,
	minusSix,
	minusFive,
	minusFour,
	minusThree,
	minusTwo,
	minusOne,
	zero,
	one,
	two,
	three,
	...
}
*/

struct RNTP_Threshold : asn::enumerated<16, 0, true>
{
	static constexpr const char* name() {return "RNTP-Threshold";}
	using parent_t = asn::enumerated<16, 0, true>;
	typedef enum {
		minusInfinity
		,minusEleven
		,minusTen
		,minusNine
		,minusEight
		,minusSeven
		,minusSix
		,minusFive
		,minusFour
		,minusThree
		,minusTwo
		,minusOne
		,zero
		,one
		,two
		,three
	} index_t;

};

/*
EnhancedRNTPStartTime-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct EnhancedRNTPStartTime_ExtIEs
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
EnhancedRNTPStartTime ::= SEQUENCE {
		startSFN				INTEGER (0..1023, ...),
		startSubframeNumber		INTEGER (0..9, ...),
		iE-Extensions			ProtocolExtensionContainer { {EnhancedRNTPStartTime-ExtIEs} } OPTIONAL,
		...
	}
*/

struct EnhancedRNTPStartTime : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "EnhancedRNTPStartTime";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct startSFN_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 1023>>;
		static constexpr const char* name() {return "startSFN_t";}
		using parent_t = asn::integer<>;

	};

	startSFN_t& ref_startSFN() {return startSFN;}
	startSFN_t const& ref_startSFN() const {return startSFN;}
	struct startSubframeNumber_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 9>>;
		static constexpr const char* name() {return "startSubframeNumber_t";}
		using parent_t = asn::integer<>;

	};

	startSubframeNumber_t& ref_startSubframeNumber() {return startSubframeNumber;}
	startSubframeNumber_t const& ref_startSubframeNumber() const {return startSubframeNumber;}
	struct iE_Extensions_t : ProtocolExtensionContainer<EnhancedRNTPStartTime_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<EnhancedRNTPStartTime_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(startSFN);
		v(startSubframeNumber);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(startSFN);
		v(startSubframeNumber);
		v(iE_Extensions);

	};
	void clear()
	{
		startSFN.clear();
		startSubframeNumber.clear();
		iE_Extensions.clear();

	};
	private:
	startSFN_t	startSFN;
	startSubframeNumber_t	startSubframeNumber;
	iE_Extensions_t	iE_Extensions;

};
/*
EnhancedRNTP-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct EnhancedRNTP_ExtIEs
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
EnhancedRNTP ::= SEQUENCE {
	enhancedRNTPBitmap			BIT STRING (SIZE(12..8800, ...)),
	rNTP-High-Power-Threshold	RNTP-Threshold,
	enhancedRNTPStartTime		EnhancedRNTPStartTime OPTIONAL,
	iE-Extensions				ProtocolExtensionContainer { {EnhancedRNTP-ExtIEs} } OPTIONAL,
	...
}
*/

struct EnhancedRNTP : asn::sequence<4, 0, true, 2>
{
	static constexpr const char* name() {return "EnhancedRNTP";}
	using parent_t = asn::sequence<4, 0, true, 2>;
	struct enhancedRNTPBitmap_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<true,asn::span<12, 8800>>;
		static constexpr const char* name() {return "enhancedRNTPBitmap_t";}
		using parent_t = asn::bstring<>;

	};

	enhancedRNTPBitmap_t& ref_enhancedRNTPBitmap() {return enhancedRNTPBitmap;}
	enhancedRNTPBitmap_t const& ref_enhancedRNTPBitmap() const {return enhancedRNTPBitmap;}
	struct rNTP_High_Power_Threshold_t : RNTP_Threshold
	{
		static constexpr const char* name() {return "rNTP_High_Power_Threshold_t";}
		using parent_t = RNTP_Threshold;

	};
	rNTP_High_Power_Threshold_t& ref_rNTP_High_Power_Threshold() {return rNTP_High_Power_Threshold;}
	rNTP_High_Power_Threshold_t const& ref_rNTP_High_Power_Threshold() const {return rNTP_High_Power_Threshold;}
	struct enhancedRNTPStartTime_t : EnhancedRNTPStartTime
	{
		static constexpr const char* name() {return "enhancedRNTPStartTime_t";}
		using parent_t = EnhancedRNTPStartTime;
		static constexpr bool optional = true;

	};
	enhancedRNTPStartTime_t& set_enhancedRNTPStartTime() { enhancedRNTPStartTime.setpresent(true); return enhancedRNTPStartTime;}
	enhancedRNTPStartTime_t const* get_enhancedRNTPStartTime() const {return enhancedRNTPStartTime.is_valid() ? &enhancedRNTPStartTime : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<EnhancedRNTP_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<EnhancedRNTP_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(enhancedRNTPBitmap);
		v(rNTP_High_Power_Threshold);
		v(enhancedRNTPStartTime);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(enhancedRNTPBitmap);
		v(rNTP_High_Power_Threshold);
		v(enhancedRNTPStartTime);
		v(iE_Extensions);

	};
	void clear()
	{
		enhancedRNTPBitmap.clear();
		rNTP_High_Power_Threshold.clear();
		enhancedRNTPStartTime.clear();
		iE_Extensions.clear();

	};
	private:
	enhancedRNTPBitmap_t	enhancedRNTPBitmap;
	rNTP_High_Power_Threshold_t	rNTP_High_Power_Threshold;
	enhancedRNTPStartTime_t	enhancedRNTPStartTime;
	iE_Extensions_t	iE_Extensions;

};
/*
EventType ::= ENUMERATED{
	change-of-serving-cell,
	...
}
*/

struct EventType : asn::enumerated<1, 0, true>
{
	static constexpr const char* name() {return "EventType";}
	using parent_t = asn::enumerated<1, 0, true>;
	typedef enum {
		change_of_serving_cell
	} index_t;

};

/*
ExpectedActivityPeriod ::= INTEGER (1..30|40|50|60|80|100|120|150|180|181,...)
*/

struct ExpectedActivityPeriod : asn::integer<>
{
	using constraint_t = asn::constraints<true,asn::span<1, 30>,asn::one<40>,asn::one<50>,asn::one<60>,asn::one<80>,asn::one<100>,asn::one<120>,asn::one<150>,asn::one<180>,asn::one<181>>;
	static constexpr const char* name() {return "ExpectedActivityPeriod";}
	using parent_t = asn::integer<>;

};

/*
ExpectedHOInterval ::= ENUMERATED {
	sec15, sec30, sec60, sec90, sec120, sec180, long-time,
	...
}
*/

struct ExpectedHOInterval : asn::enumerated<7, 0, true>
{
	static constexpr const char* name() {return "ExpectedHOInterval";}
	using parent_t = asn::enumerated<7, 0, true>;
	typedef enum {
		sec15
		,sec30
		,sec60
		,sec90
		,sec120
		,sec180
		,long_time
	} index_t;

};

/*
ExpectedIdlePeriod ::= INTEGER (1..30|40|50|60|80|100|120|150|180|181,...)
*/

struct ExpectedIdlePeriod : asn::integer<>
{
	using constraint_t = asn::constraints<true,asn::span<1, 30>,asn::one<40>,asn::one<50>,asn::one<60>,asn::one<80>,asn::one<100>,asn::one<120>,asn::one<150>,asn::one<180>,asn::one<181>>;
	static constexpr const char* name() {return "ExpectedIdlePeriod";}
	using parent_t = asn::integer<>;

};

/*
SourceOfUEActivityBehaviourInformation ::= ENUMERATED {
	subscription-information,
	statistics,
	...
}
*/

struct SourceOfUEActivityBehaviourInformation : asn::enumerated<2, 0, true>
{
	static constexpr const char* name() {return "SourceOfUEActivityBehaviourInformation";}
	using parent_t = asn::enumerated<2, 0, true>;
	typedef enum {
		subscription_information
		,statistics
	} index_t;

};

/*
ExpectedUEActivityBehaviour-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct ExpectedUEActivityBehaviour_ExtIEs
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
ExpectedUEActivityBehaviour ::= SEQUENCE {
	expectedActivityPeriod					ExpectedActivityPeriod					OPTIONAL,
	expectedIdlePeriod						ExpectedIdlePeriod						OPTIONAL,
	sourceofUEActivityBehaviourInformation	SourceOfUEActivityBehaviourInformation	OPTIONAL,
	iE-Extensions		ProtocolExtensionContainer { {ExpectedUEActivityBehaviour-ExtIEs} } OPTIONAL,
	...
}
*/

struct ExpectedUEActivityBehaviour : asn::sequence<4, 0, true, 4>
{
	static constexpr const char* name() {return "ExpectedUEActivityBehaviour";}
	using parent_t = asn::sequence<4, 0, true, 4>;
	struct expectedActivityPeriod_t : ExpectedActivityPeriod
	{
		static constexpr const char* name() {return "expectedActivityPeriod_t";}
		using parent_t = ExpectedActivityPeriod;
		static constexpr bool optional = true;

	};
	expectedActivityPeriod_t& set_expectedActivityPeriod() { expectedActivityPeriod.setpresent(true); return expectedActivityPeriod;}
	expectedActivityPeriod_t const* get_expectedActivityPeriod() const {return expectedActivityPeriod.is_valid() ? &expectedActivityPeriod : nullptr;}
	struct expectedIdlePeriod_t : ExpectedIdlePeriod
	{
		static constexpr const char* name() {return "expectedIdlePeriod_t";}
		using parent_t = ExpectedIdlePeriod;
		static constexpr bool optional = true;

	};
	expectedIdlePeriod_t& set_expectedIdlePeriod() { expectedIdlePeriod.setpresent(true); return expectedIdlePeriod;}
	expectedIdlePeriod_t const* get_expectedIdlePeriod() const {return expectedIdlePeriod.is_valid() ? &expectedIdlePeriod : nullptr;}
	struct sourceofUEActivityBehaviourInformation_t : SourceOfUEActivityBehaviourInformation
	{
		static constexpr const char* name() {return "sourceofUEActivityBehaviourInformation_t";}
		using parent_t = SourceOfUEActivityBehaviourInformation;
		static constexpr bool optional = true;

	};
	sourceofUEActivityBehaviourInformation_t& set_sourceofUEActivityBehaviourInformation() { sourceofUEActivityBehaviourInformation.setpresent(true); return sourceofUEActivityBehaviourInformation;}
	sourceofUEActivityBehaviourInformation_t const* get_sourceofUEActivityBehaviourInformation() const {return sourceofUEActivityBehaviourInformation.is_valid() ? &sourceofUEActivityBehaviourInformation : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ExpectedUEActivityBehaviour_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ExpectedUEActivityBehaviour_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(expectedActivityPeriod);
		v(expectedIdlePeriod);
		v(sourceofUEActivityBehaviourInformation);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(expectedActivityPeriod);
		v(expectedIdlePeriod);
		v(sourceofUEActivityBehaviourInformation);
		v(iE_Extensions);

	};
	void clear()
	{
		expectedActivityPeriod.clear();
		expectedIdlePeriod.clear();
		sourceofUEActivityBehaviourInformation.clear();
		iE_Extensions.clear();

	};
	private:
	expectedActivityPeriod_t	expectedActivityPeriod;
	expectedIdlePeriod_t	expectedIdlePeriod;
	sourceofUEActivityBehaviourInformation_t	sourceofUEActivityBehaviourInformation;
	iE_Extensions_t	iE_Extensions;

};
/*
ExpectedUEBehaviour-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct ExpectedUEBehaviour_ExtIEs
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
ExpectedUEBehaviour ::= SEQUENCE {
	expectedActivity		ExpectedUEActivityBehaviour OPTIONAL,
	expectedHOInterval		ExpectedHOInterval			OPTIONAL,
	iE-Extensions			ProtocolExtensionContainer { {ExpectedUEBehaviour-ExtIEs} } OPTIONAL,
	...
}
*/

struct ExpectedUEBehaviour : asn::sequence<3, 0, true, 3>
{
	static constexpr const char* name() {return "ExpectedUEBehaviour";}
	using parent_t = asn::sequence<3, 0, true, 3>;
	struct expectedActivity_t : ExpectedUEActivityBehaviour
	{
		static constexpr const char* name() {return "expectedActivity_t";}
		using parent_t = ExpectedUEActivityBehaviour;
		static constexpr bool optional = true;

	};
	expectedActivity_t& set_expectedActivity() { expectedActivity.setpresent(true); return expectedActivity;}
	expectedActivity_t const* get_expectedActivity() const {return expectedActivity.is_valid() ? &expectedActivity : nullptr;}
	struct expectedHOInterval_t : ExpectedHOInterval
	{
		static constexpr const char* name() {return "expectedHOInterval_t";}
		using parent_t = ExpectedHOInterval;
		static constexpr bool optional = true;

	};
	expectedHOInterval_t& set_expectedHOInterval() { expectedHOInterval.setpresent(true); return expectedHOInterval;}
	expectedHOInterval_t const* get_expectedHOInterval() const {return expectedHOInterval.is_valid() ? &expectedHOInterval : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ExpectedUEBehaviour_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ExpectedUEBehaviour_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(expectedActivity);
		v(expectedHOInterval);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(expectedActivity);
		v(expectedHOInterval);
		v(iE_Extensions);

	};
	void clear()
	{
		expectedActivity.clear();
		expectedHOInterval.clear();
		iE_Extensions.clear();

	};
	private:
	expectedActivity_t	expectedActivity;
	expectedHOInterval_t	expectedHOInterval;
	iE_Extensions_t	iE_Extensions;

};
/*
UL-InterferenceOverloadIndication-Item ::= ENUMERATED {
	high-interference,
	medium-interference,
	low-interference,
	...
}
*/

struct UL_InterferenceOverloadIndication_Item : asn::enumerated<3, 0, true>
{
	static constexpr const char* name() {return "UL-InterferenceOverloadIndication-Item";}
	using parent_t = asn::enumerated<3, 0, true>;
	typedef enum {
		high_interference
		,medium_interference
		,low_interference
	} index_t;

};

/*
UL-InterferenceOverloadIndication ::= SEQUENCE (SIZE(1..maxnoofPRBs)) OF UL-InterferenceOverloadIndication-Item
*/

struct UL_InterferenceOverloadIndication_elm : UL_InterferenceOverloadIndication_Item
{
	static constexpr const char* name() {return "UL_InterferenceOverloadIndication_elm";}
	using parent_t = UL_InterferenceOverloadIndication_Item;

};
struct UL_InterferenceOverloadIndication : asn::sequenceof<UL_InterferenceOverloadIndication_elm>
{
	static constexpr const char* name() {return "UL-InterferenceOverloadIndication";}
	using parent_t = asn::sequenceof<UL_InterferenceOverloadIndication_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofPRBs >>;

};
/*
ExtendedULInterferenceOverloadInfo-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct ExtendedULInterferenceOverloadInfo_ExtIEs
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
ExtendedULInterferenceOverloadInfo ::= SEQUENCE {
	associatedSubframes							BIT STRING (SIZE (5)),
	extended-ul-InterferenceOverloadIndication	UL-InterferenceOverloadIndication,
	iE-Extensions								ProtocolExtensionContainer { {ExtendedULInterferenceOverloadInfo-ExtIEs} } OPTIONAL,
	...
}
*/

struct ExtendedULInterferenceOverloadInfo : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "ExtendedULInterferenceOverloadInfo";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct associatedSubframes_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<false,asn::one<5>>;
		static constexpr const char* name() {return "associatedSubframes_t";}
		using parent_t = asn::bstring<>;

	};

	associatedSubframes_t& ref_associatedSubframes() {return associatedSubframes;}
	associatedSubframes_t const& ref_associatedSubframes() const {return associatedSubframes;}
	struct extended_ul_InterferenceOverloadIndication_t : UL_InterferenceOverloadIndication
	{
		static constexpr const char* name() {return "extended_ul_InterferenceOverloadIndication_t";}
		using parent_t = UL_InterferenceOverloadIndication;

	};
	extended_ul_InterferenceOverloadIndication_t& ref_extended_ul_InterferenceOverloadIndication() {return extended_ul_InterferenceOverloadIndication;}
	extended_ul_InterferenceOverloadIndication_t const& ref_extended_ul_InterferenceOverloadIndication() const {return extended_ul_InterferenceOverloadIndication;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ExtendedULInterferenceOverloadInfo_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ExtendedULInterferenceOverloadInfo_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(associatedSubframes);
		v(extended_ul_InterferenceOverloadIndication);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(associatedSubframes);
		v(extended_ul_InterferenceOverloadIndication);
		v(iE_Extensions);

	};
	void clear()
	{
		associatedSubframes.clear();
		extended_ul_InterferenceOverloadIndication.clear();
		iE_Extensions.clear();

	};
	private:
	associatedSubframes_t	associatedSubframes;
	extended_ul_InterferenceOverloadIndication_t	extended_ul_InterferenceOverloadIndication;
	iE_Extensions_t	iE_Extensions;

};
/*
FiveGS-TAC ::= OCTET STRING (SIZE (3))
*/

struct FiveGS_TAC : asn::ostring<>
{
	using constraint_t = asn::constraints<false,asn::one<3>>;
	static constexpr const char* name() {return "FiveGS-TAC";}
	using parent_t = asn::ostring<>;

};

/*
ForbiddenInterRATs ::= ENUMERATED {
	all,
	geran,
	utran,
	cdma2000,
	...,
	geranandutran,
	cdma2000andutran

}
*/

struct ForbiddenInterRATs : asn::enumerated<6, 2, true>
{
	static constexpr const char* name() {return "ForbiddenInterRATs";}
	using parent_t = asn::enumerated<6, 2, true>;
	typedef enum {
		all
		,geran
		,utran
		,cdma2000
		,geranandutran
		,cdma2000andutran
	} index_t;

};

/*
LAC					::= OCTET STRING (SIZE (2)) --(EXCEPT ('0000'H|'FFFE'H))
*/

struct LAC : asn::ostring<>
{
	using constraint_t = asn::constraints<false,asn::one<2>>;
	static constexpr const char* name() {return "LAC";}
	using parent_t = asn::ostring<>;

};

/*
ForbiddenLACs ::= SEQUENCE (SIZE(1..maxnoofForbLACs)) OF LAC
*/

struct ForbiddenLACs_elm : LAC
{
	static constexpr const char* name() {return "ForbiddenLACs_elm";}
	using parent_t = LAC;

};
struct ForbiddenLACs : asn::sequenceof<ForbiddenLACs_elm>
{
	static constexpr const char* name() {return "ForbiddenLACs";}
	using parent_t = asn::sequenceof<ForbiddenLACs_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofForbLACs >>;

};
/*
ForbiddenLAs-Item-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct ForbiddenLAs_Item_ExtIEs
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
ForbiddenLAs-Item ::= SEQUENCE {
	pLMN-Identity		PLMN-Identity,
	forbiddenLACs		ForbiddenLACs,
	iE-Extensions		ProtocolExtensionContainer { {ForbiddenLAs-Item-ExtIEs} } OPTIONAL,
	...
}
*/

struct ForbiddenLAs_Item : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "ForbiddenLAs-Item";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct pLMN_Identity_t : PLMN_Identity
	{
		static constexpr const char* name() {return "pLMN_Identity_t";}
		using parent_t = PLMN_Identity;

	};
	pLMN_Identity_t& ref_pLMN_Identity() {return pLMN_Identity;}
	pLMN_Identity_t const& ref_pLMN_Identity() const {return pLMN_Identity;}
	struct forbiddenLACs_t : ForbiddenLACs
	{
		static constexpr const char* name() {return "forbiddenLACs_t";}
		using parent_t = ForbiddenLACs;

	};
	forbiddenLACs_t& ref_forbiddenLACs() {return forbiddenLACs;}
	forbiddenLACs_t const& ref_forbiddenLACs() const {return forbiddenLACs;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ForbiddenLAs_Item_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ForbiddenLAs_Item_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(pLMN_Identity);
		v(forbiddenLACs);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(pLMN_Identity);
		v(forbiddenLACs);
		v(iE_Extensions);

	};
	void clear()
	{
		pLMN_Identity.clear();
		forbiddenLACs.clear();
		iE_Extensions.clear();

	};
	private:
	pLMN_Identity_t	pLMN_Identity;
	forbiddenLACs_t	forbiddenLACs;
	iE_Extensions_t	iE_Extensions;

};
/*
ForbiddenLAs ::= SEQUENCE (SIZE(1..maxnoofEPLMNsPlusOne)) OF ForbiddenLAs-Item
*/

struct ForbiddenLAs_elm : ForbiddenLAs_Item
{
	static constexpr const char* name() {return "ForbiddenLAs_elm";}
	using parent_t = ForbiddenLAs_Item;

};
struct ForbiddenLAs : asn::sequenceof<ForbiddenLAs_elm>
{
	static constexpr const char* name() {return "ForbiddenLAs";}
	using parent_t = asn::sequenceof<ForbiddenLAs_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofEPLMNsPlusOne >>;

};
/*
ForbiddenTACs ::= SEQUENCE (SIZE(1..maxnoofForbTACs)) OF TAC
*/

struct ForbiddenTACs_elm : TAC
{
	static constexpr const char* name() {return "ForbiddenTACs_elm";}
	using parent_t = TAC;

};
struct ForbiddenTACs : asn::sequenceof<ForbiddenTACs_elm>
{
	static constexpr const char* name() {return "ForbiddenTACs";}
	using parent_t = asn::sequenceof<ForbiddenTACs_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofForbTACs >>;

};
/*
ForbiddenTAs-Item-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct ForbiddenTAs_Item_ExtIEs
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
ForbiddenTAs-Item ::= SEQUENCE {
	pLMN-Identity		PLMN-Identity,
	forbiddenTACs		ForbiddenTACs,
	iE-Extensions		ProtocolExtensionContainer { {ForbiddenTAs-Item-ExtIEs} } OPTIONAL,
	...
}
*/

struct ForbiddenTAs_Item : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "ForbiddenTAs-Item";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct pLMN_Identity_t : PLMN_Identity
	{
		static constexpr const char* name() {return "pLMN_Identity_t";}
		using parent_t = PLMN_Identity;

	};
	pLMN_Identity_t& ref_pLMN_Identity() {return pLMN_Identity;}
	pLMN_Identity_t const& ref_pLMN_Identity() const {return pLMN_Identity;}
	struct forbiddenTACs_t : ForbiddenTACs
	{
		static constexpr const char* name() {return "forbiddenTACs_t";}
		using parent_t = ForbiddenTACs;

	};
	forbiddenTACs_t& ref_forbiddenTACs() {return forbiddenTACs;}
	forbiddenTACs_t const& ref_forbiddenTACs() const {return forbiddenTACs;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ForbiddenTAs_Item_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ForbiddenTAs_Item_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(pLMN_Identity);
		v(forbiddenTACs);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(pLMN_Identity);
		v(forbiddenTACs);
		v(iE_Extensions);

	};
	void clear()
	{
		pLMN_Identity.clear();
		forbiddenTACs.clear();
		iE_Extensions.clear();

	};
	private:
	pLMN_Identity_t	pLMN_Identity;
	forbiddenTACs_t	forbiddenTACs;
	iE_Extensions_t	iE_Extensions;

};
/*
ForbiddenTAs ::= SEQUENCE (SIZE(1.. maxnoofEPLMNsPlusOne)) OF ForbiddenTAs-Item
*/

struct ForbiddenTAs_elm : ForbiddenTAs_Item
{
	static constexpr const char* name() {return "ForbiddenTAs_elm";}
	using parent_t = ForbiddenTAs_Item;

};
struct ForbiddenTAs : asn::sequenceof<ForbiddenTAs_elm>
{
	static constexpr const char* name() {return "ForbiddenTAs";}
	using parent_t = asn::sequenceof<ForbiddenTAs_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofEPLMNsPlusOne >>;

};
/*
Fourframes ::= BIT STRING (SIZE (24))
*/

struct Fourframes : asn::bstring<>
{
	using constraint_t = asn::constraints<false,asn::one<24>>;
	static constexpr const char* name() {return "Fourframes";}
	using parent_t = asn::bstring<>;

};

/*
FreqBandIndicatorPriority ::= ENUMERATED {
	not-broadcasted,
	broadcasted,
	...
}
*/

struct FreqBandIndicatorPriority : asn::enumerated<2, 0, true>
{
	static constexpr const char* name() {return "FreqBandIndicatorPriority";}
	using parent_t = asn::enumerated<2, 0, true>;
	typedef enum {
		not_broadcasted
		,broadcasted
	} index_t;

};

/*
SupportedSULFreqBandItem-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct SupportedSULFreqBandItem_ExtIEs
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
SupportedSULFreqBandItem ::= SEQUENCE {
	freqBandIndicatorNr 			INTEGER (1..1024,...),
	iE-Extensions			ProtocolExtensionContainer { {SupportedSULFreqBandItem-ExtIEs} }		OPTIONAL,
	...
}
*/

struct SupportedSULFreqBandItem : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "SupportedSULFreqBandItem";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct freqBandIndicatorNr_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<1, 1024>>;
		static constexpr const char* name() {return "freqBandIndicatorNr_t";}
		using parent_t = asn::integer<>;

	};

	freqBandIndicatorNr_t& ref_freqBandIndicatorNr() {return freqBandIndicatorNr;}
	freqBandIndicatorNr_t const& ref_freqBandIndicatorNr() const {return freqBandIndicatorNr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<SupportedSULFreqBandItem_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<SupportedSULFreqBandItem_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(freqBandIndicatorNr);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(freqBandIndicatorNr);
		v(iE_Extensions);

	};
	void clear()
	{
		freqBandIndicatorNr.clear();
		iE_Extensions.clear();

	};
	private:
	freqBandIndicatorNr_t	freqBandIndicatorNr;
	iE_Extensions_t	iE_Extensions;

};
/*
FreqBandNrItem-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct FreqBandNrItem_ExtIEs
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
FreqBandNrItem ::= SEQUENCE {
	freqBandIndicatorNr 			INTEGER (1..1024,...),
	supportedSULBandList	SEQUENCE (SIZE(0..maxnoofNrCellBands)) OF SupportedSULFreqBandItem,
	iE-Extensions				ProtocolExtensionContainer { {FreqBandNrItem-ExtIEs} } OPTIONAL,
	...
}
*/

struct FreqBandNrItem : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "FreqBandNrItem";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct freqBandIndicatorNr_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<1, 1024>>;
		static constexpr const char* name() {return "freqBandIndicatorNr_t";}
		using parent_t = asn::integer<>;

	};

	freqBandIndicatorNr_t& ref_freqBandIndicatorNr() {return freqBandIndicatorNr;}
	freqBandIndicatorNr_t const& ref_freqBandIndicatorNr() const {return freqBandIndicatorNr;}
	struct supportedSULBandList_t_elm : SupportedSULFreqBandItem
	{
		static constexpr const char* name() {return "supportedSULBandList_t_elm";}
		using parent_t = SupportedSULFreqBandItem;

	};
	struct supportedSULBandList_t : asn::sequenceof<supportedSULBandList_t_elm>
	{
		static constexpr const char* name() {return "supportedSULBandList_t";}
		using parent_t = asn::sequenceof<supportedSULBandList_t_elm>;
		using constraint_t = asn::constraints<false,asn::span<0,  maxnoofNrCellBands >>;

	};
	supportedSULBandList_t& ref_supportedSULBandList() {return supportedSULBandList;}
	supportedSULBandList_t const& ref_supportedSULBandList() const {return supportedSULBandList;}
	struct iE_Extensions_t : ProtocolExtensionContainer<FreqBandNrItem_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<FreqBandNrItem_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(freqBandIndicatorNr);
		v(supportedSULBandList);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(freqBandIndicatorNr);
		v(supportedSULBandList);
		v(iE_Extensions);

	};
	void clear()
	{
		freqBandIndicatorNr.clear();
		supportedSULBandList.clear();
		iE_Extensions.clear();

	};
	private:
	freqBandIndicatorNr_t	freqBandIndicatorNr;
	supportedSULBandList_t	supportedSULBandList;
	iE_Extensions_t	iE_Extensions;

};
/*
GNB-ID ::= CHOICE {
	gNB-ID	BIT STRING (SIZE (22..32)),
	...
}
*/

struct GNB_ID : asn::choice<1, 0, true>
{
	static constexpr const char* name() {return "GNB-ID";}
	using parent_t = asn::choice<1, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 2;}
	void set_unknown() { set_index(2);  }
	~GNB_ID() {clear();}
	struct gNB_ID_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<false,asn::span<22, 32>>;
		static constexpr const char* name() {return "gNB_ID_t";}
		using parent_t = asn::bstring<>;

	};

	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<gNB_ID_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<gNB_ID_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<gNB_ID_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<gNB_ID_t>(1);

	}
	gNB_ID_t& select_gNB_ID() { if(get_index() != 1) { clear(); set_index(1); return var.build<gNB_ID_t>();} return var.as<gNB_ID_t>();}
	gNB_ID_t const* get_gNB_ID() const { if(get_index() == 1) { return &var.as<gNB_ID_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(gNB_ID_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
GNBOverloadInformation ::= ENUMERATED {overloaded, not-overloaded, ...}
*/

struct GNBOverloadInformation : asn::enumerated<2, 0, true>
{
	static constexpr const char* name() {return "GNBOverloadInformation";}
	using parent_t = asn::enumerated<2, 0, true>;
	typedef enum {
		overloaded
		,not_overloaded
	} index_t;

};

/*
GTP-TEI					::= OCTET STRING (SIZE (4))
*/

struct GTP_TEI : asn::ostring<>
{
	using constraint_t = asn::constraints<false,asn::one<4>>;
	static constexpr const char* name() {return "GTP-TEI";}
	using parent_t = asn::ostring<>;

};

/*
TransportLayerAddress			::= BIT STRING (SIZE(1..160, ...))
*/

struct TransportLayerAddress : asn::bstring<>
{
	using constraint_t = asn::constraints<true,asn::span<1, 160>>;
	static constexpr const char* name() {return "TransportLayerAddress";}
	using parent_t = asn::bstring<>;

};

/*
GTPtunnelEndpoint-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct GTPtunnelEndpoint_ExtIEs
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
GTPtunnelEndpoint ::= SEQUENCE {
	transportLayerAddress			TransportLayerAddress,
	gTP-TEID						GTP-TEI,
	iE-Extensions					ProtocolExtensionContainer { {GTPtunnelEndpoint-ExtIEs} } OPTIONAL,
	...
}
*/

struct GTPtunnelEndpoint : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "GTPtunnelEndpoint";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct transportLayerAddress_t : TransportLayerAddress
	{
		static constexpr const char* name() {return "transportLayerAddress_t";}
		using parent_t = TransportLayerAddress;

	};
	transportLayerAddress_t& ref_transportLayerAddress() {return transportLayerAddress;}
	transportLayerAddress_t const& ref_transportLayerAddress() const {return transportLayerAddress;}
	struct gTP_TEID_t : GTP_TEI
	{
		static constexpr const char* name() {return "gTP_TEID_t";}
		using parent_t = GTP_TEI;

	};
	gTP_TEID_t& ref_gTP_TEID() {return gTP_TEID;}
	gTP_TEID_t const& ref_gTP_TEID() const {return gTP_TEID;}
	struct iE_Extensions_t : ProtocolExtensionContainer<GTPtunnelEndpoint_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<GTPtunnelEndpoint_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(transportLayerAddress);
		v(gTP_TEID);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(transportLayerAddress);
		v(gTP_TEID);
		v(iE_Extensions);

	};
	void clear()
	{
		transportLayerAddress.clear();
		gTP_TEID.clear();
		iE_Extensions.clear();

	};
	private:
	transportLayerAddress_t	transportLayerAddress;
	gTP_TEID_t	gTP_TEID;
	iE_Extensions_t	iE_Extensions;

};
/*
MME-Group-ID	::= OCTET STRING (SIZE (2))
*/

struct MME_Group_ID : asn::ostring<>
{
	using constraint_t = asn::constraints<false,asn::one<2>>;
	static constexpr const char* name() {return "MME-Group-ID";}
	using parent_t = asn::ostring<>;

};

/*
GU-Group-ID-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct GU_Group_ID_ExtIEs
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
GU-Group-ID			::= SEQUENCE {
	pLMN-Identity		PLMN-Identity,
	mME-Group-ID		MME-Group-ID,
	iE-Extensions		ProtocolExtensionContainer { {GU-Group-ID-ExtIEs} } OPTIONAL,
	...
}
*/

struct GU_Group_ID : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "GU-Group-ID";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct pLMN_Identity_t : PLMN_Identity
	{
		static constexpr const char* name() {return "pLMN_Identity_t";}
		using parent_t = PLMN_Identity;

	};
	pLMN_Identity_t& ref_pLMN_Identity() {return pLMN_Identity;}
	pLMN_Identity_t const& ref_pLMN_Identity() const {return pLMN_Identity;}
	struct mME_Group_ID_t : MME_Group_ID
	{
		static constexpr const char* name() {return "mME_Group_ID_t";}
		using parent_t = MME_Group_ID;

	};
	mME_Group_ID_t& ref_mME_Group_ID() {return mME_Group_ID;}
	mME_Group_ID_t const& ref_mME_Group_ID() const {return mME_Group_ID;}
	struct iE_Extensions_t : ProtocolExtensionContainer<GU_Group_ID_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<GU_Group_ID_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(pLMN_Identity);
		v(mME_Group_ID);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(pLMN_Identity);
		v(mME_Group_ID);
		v(iE_Extensions);

	};
	void clear()
	{
		pLMN_Identity.clear();
		mME_Group_ID.clear();
		iE_Extensions.clear();

	};
	private:
	pLMN_Identity_t	pLMN_Identity;
	mME_Group_ID_t	mME_Group_ID;
	iE_Extensions_t	iE_Extensions;

};
/*
GUGroupIDList		::= SEQUENCE (SIZE (1..maxPools)) OF GU-Group-ID
*/

struct GUGroupIDList_elm : GU_Group_ID
{
	static constexpr const char* name() {return "GUGroupIDList_elm";}
	using parent_t = GU_Group_ID;

};
struct GUGroupIDList : asn::sequenceof<GUGroupIDList_elm>
{
	static constexpr const char* name() {return "GUGroupIDList";}
	using parent_t = asn::sequenceof<GUGroupIDList_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxPools >>;

};
/*
MME-Code		::= OCTET STRING (SIZE (1))
*/

struct MME_Code : asn::ostring<>
{
	using constraint_t = asn::constraints<false,asn::one<1>>;
	static constexpr const char* name() {return "MME-Code";}
	using parent_t = asn::ostring<>;

};

/*
GUMMEI-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct GUMMEI_ExtIEs
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
GUMMEI			::= SEQUENCE {

	gU-Group-ID		GU-Group-ID,
	mME-Code			MME-Code,
	iE-Extensions					ProtocolExtensionContainer { {GUMMEI-ExtIEs} } OPTIONAL,
	...
}
*/

struct GUMMEI : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "GUMMEI";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct gU_Group_ID_t : GU_Group_ID
	{
		static constexpr const char* name() {return "gU_Group_ID_t";}
		using parent_t = GU_Group_ID;

	};
	gU_Group_ID_t& ref_gU_Group_ID() {return gU_Group_ID;}
	gU_Group_ID_t const& ref_gU_Group_ID() const {return gU_Group_ID;}
	struct mME_Code_t : MME_Code
	{
		static constexpr const char* name() {return "mME_Code_t";}
		using parent_t = MME_Code;

	};
	mME_Code_t& ref_mME_Code() {return mME_Code;}
	mME_Code_t const& ref_mME_Code() const {return mME_Code;}
	struct iE_Extensions_t : ProtocolExtensionContainer<GUMMEI_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<GUMMEI_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(gU_Group_ID);
		v(mME_Code);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(gU_Group_ID);
		v(mME_Code);
		v(iE_Extensions);

	};
	void clear()
	{
		gU_Group_ID.clear();
		mME_Code.clear();
		iE_Extensions.clear();

	};
	private:
	gU_Group_ID_t	gU_Group_ID;
	mME_Code_t	mME_Code;
	iE_Extensions_t	iE_Extensions;

};
/*
GlobalENB-ID-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct GlobalENB_ID_ExtIEs
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
GlobalENB-ID ::= SEQUENCE {
	pLMN-Identity			PLMN-Identity,
	eNB-ID					ENB-ID,
	iE-Extensions			ProtocolExtensionContainer { {GlobalENB-ID-ExtIEs} } OPTIONAL,
	...
}
*/

struct GlobalENB_ID : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "GlobalENB-ID";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct pLMN_Identity_t : PLMN_Identity
	{
		static constexpr const char* name() {return "pLMN_Identity_t";}
		using parent_t = PLMN_Identity;

	};
	pLMN_Identity_t& ref_pLMN_Identity() {return pLMN_Identity;}
	pLMN_Identity_t const& ref_pLMN_Identity() const {return pLMN_Identity;}
	struct eNB_ID_t : ENB_ID
	{
		static constexpr const char* name() {return "eNB_ID_t";}
		using parent_t = ENB_ID;

	};
	eNB_ID_t& ref_eNB_ID() {return eNB_ID;}
	eNB_ID_t const& ref_eNB_ID() const {return eNB_ID;}
	struct iE_Extensions_t : ProtocolExtensionContainer<GlobalENB_ID_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<GlobalENB_ID_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(pLMN_Identity);
		v(eNB_ID);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(pLMN_Identity);
		v(eNB_ID);
		v(iE_Extensions);

	};
	void clear()
	{
		pLMN_Identity.clear();
		eNB_ID.clear();
		iE_Extensions.clear();

	};
	private:
	pLMN_Identity_t	pLMN_Identity;
	eNB_ID_t	eNB_ID;
	iE_Extensions_t	iE_Extensions;

};
/*
GlobalGNB-ID-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct GlobalGNB_ID_ExtIEs
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
GlobalGNB-ID ::= SEQUENCE {
	pLMN-Identity			PLMN-Identity,
	gNB-ID					GNB-ID,
	iE-Extensions			ProtocolExtensionContainer { {GlobalGNB-ID-ExtIEs} } OPTIONAL,
	...
}
*/

struct GlobalGNB_ID : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "GlobalGNB-ID";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct pLMN_Identity_t : PLMN_Identity
	{
		static constexpr const char* name() {return "pLMN_Identity_t";}
		using parent_t = PLMN_Identity;

	};
	pLMN_Identity_t& ref_pLMN_Identity() {return pLMN_Identity;}
	pLMN_Identity_t const& ref_pLMN_Identity() const {return pLMN_Identity;}
	struct gNB_ID_t : GNB_ID
	{
		static constexpr const char* name() {return "gNB_ID_t";}
		using parent_t = GNB_ID;

	};
	gNB_ID_t& ref_gNB_ID() {return gNB_ID;}
	gNB_ID_t const& ref_gNB_ID() const {return gNB_ID;}
	struct iE_Extensions_t : ProtocolExtensionContainer<GlobalGNB_ID_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<GlobalGNB_ID_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(pLMN_Identity);
		v(gNB_ID);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(pLMN_Identity);
		v(gNB_ID);
		v(iE_Extensions);

	};
	void clear()
	{
		pLMN_Identity.clear();
		gNB_ID.clear();
		iE_Extensions.clear();

	};
	private:
	pLMN_Identity_t	pLMN_Identity;
	gNB_ID_t	gNB_ID;
	iE_Extensions_t	iE_Extensions;

};
/*
LoadIndicator ::= ENUMERATED {
	lowLoad,
	mediumLoad,
	highLoad,
	overLoad,
	...
}
*/

struct LoadIndicator : asn::enumerated<4, 0, true>
{
	static constexpr const char* name() {return "LoadIndicator";}
	using parent_t = asn::enumerated<4, 0, true>;
	typedef enum {
		lowLoad
		,mediumLoad
		,highLoad
		,overLoad
	} index_t;

};

/*
HWLoadIndicator-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct HWLoadIndicator_ExtIEs
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
HWLoadIndicator ::= SEQUENCE {
	dLHWLoadIndicator			LoadIndicator,
	uLHWLoadIndicator			LoadIndicator,
	iE-Extensions				ProtocolExtensionContainer { {HWLoadIndicator-ExtIEs} } OPTIONAL,
	...
}
*/

struct HWLoadIndicator : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "HWLoadIndicator";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct dLHWLoadIndicator_t : LoadIndicator
	{
		static constexpr const char* name() {return "dLHWLoadIndicator_t";}
		using parent_t = LoadIndicator;

	};
	dLHWLoadIndicator_t& ref_dLHWLoadIndicator() {return dLHWLoadIndicator;}
	dLHWLoadIndicator_t const& ref_dLHWLoadIndicator() const {return dLHWLoadIndicator;}
	struct uLHWLoadIndicator_t : LoadIndicator
	{
		static constexpr const char* name() {return "uLHWLoadIndicator_t";}
		using parent_t = LoadIndicator;

	};
	uLHWLoadIndicator_t& ref_uLHWLoadIndicator() {return uLHWLoadIndicator;}
	uLHWLoadIndicator_t const& ref_uLHWLoadIndicator() const {return uLHWLoadIndicator;}
	struct iE_Extensions_t : ProtocolExtensionContainer<HWLoadIndicator_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<HWLoadIndicator_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(dLHWLoadIndicator);
		v(uLHWLoadIndicator);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(dLHWLoadIndicator);
		v(uLHWLoadIndicator);
		v(iE_Extensions);

	};
	void clear()
	{
		dLHWLoadIndicator.clear();
		uLHWLoadIndicator.clear();
		iE_Extensions.clear();

	};
	private:
	dLHWLoadIndicator_t	dLHWLoadIndicator;
	uLHWLoadIndicator_t	uLHWLoadIndicator;
	iE_Extensions_t	iE_Extensions;

};
/*
HandoverReportType ::= ENUMERATED {
	hoTooEarly,
	hoToWrongCell,
	...,
	interRATpingpong
}
*/

struct HandoverReportType : asn::enumerated<3, 1, true>
{
	static constexpr const char* name() {return "HandoverReportType";}
	using parent_t = asn::enumerated<3, 1, true>;
	typedef enum {
		hoTooEarly
		,hoToWrongCell
		,interRATpingpong
	} index_t;

};

/*
NRrestrictioninEPSasSecondaryRAT ::= ENUMERATED {
	nRrestrictedinEPSasSecondaryRAT,
	...
}
*/

struct NRrestrictioninEPSasSecondaryRAT : asn::enumerated<1, 0, true>
{
	static constexpr const char* name() {return "NRrestrictioninEPSasSecondaryRAT";}
	using parent_t = asn::enumerated<1, 0, true>;
	typedef enum {
		nRrestrictedinEPSasSecondaryRAT
	} index_t;

};

/*
NRrestrictionin5GS ::= ENUMERATED {
	nRrestrictedin5GS,
	...
}
*/

struct NRrestrictionin5GS : asn::enumerated<1, 0, true>
{
	static constexpr const char* name() {return "NRrestrictionin5GS";}
	using parent_t = asn::enumerated<1, 0, true>;
	typedef enum {
		nRrestrictedin5GS
	} index_t;

};

/*
HandoverRestrictionList-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	{ ID id-NRrestrictioninEPSasSecondaryRAT			CRITICALITY ignore	EXTENSION NRrestrictioninEPSasSecondaryRAT			PRESENCE optional}|
	{ ID id-CNTypeRestrictions						CRITICALITY ignore	EXTENSION CNTypeRestrictions								PRESENCE optional}|
	{ ID id-NRrestrictionin5GS						CRITICALITY ignore	EXTENSION NRrestrictionin5GS								PRESENCE optional},
	...
}
*/

struct HandoverRestrictionList_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 4; }
		void clear() {type = 0;}
		void select_id_NRrestrictioninEPSasSecondaryRAT() { set(id_NRrestrictioninEPSasSecondaryRAT); type=1;}
		void select_id_CNTypeRestrictions() { set(id_CNTypeRestrictions); type=2;}
		void select_id_NRrestrictionin5GS() { set(id_NRrestrictionin5GS); type=3;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_NRrestrictioninEPSasSecondaryRAT)) { type = 1; return true; }
			else if(equal(id_CNTypeRestrictions)) { type = 2; return true; }
			else if(equal(id_NRrestrictionin5GS)) { type = 3; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(id_NRrestrictioninEPSasSecondaryRAT);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_CNTypeRestrictions);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(id_NRrestrictionin5GS);} return false;
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
		void select_id_NRrestrictioninEPSasSecondaryRAT() { set(ignore); type=1;}
		void select_id_CNTypeRestrictions() { set(ignore); type=2;}
		void select_id_NRrestrictionin5GS() { set(ignore); type=3;}
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
		NRrestrictioninEPSasSecondaryRAT& select_id_NRrestrictioninEPSasSecondaryRAT() { return set<NRrestrictioninEPSasSecondaryRAT>(1); }
		NRrestrictioninEPSasSecondaryRAT const* get_id_NRrestrictioninEPSasSecondaryRAT() const { return get<NRrestrictioninEPSasSecondaryRAT>(1); }
		CNTypeRestrictions& select_id_CNTypeRestrictions() { return set<CNTypeRestrictions>(2); }
		CNTypeRestrictions const* get_id_CNTypeRestrictions() const { return get<CNTypeRestrictions>(2); }
		NRrestrictionin5GS& select_id_NRrestrictionin5GS() { return set<NRrestrictionin5GS>(3); }
		NRrestrictionin5GS const* get_id_NRrestrictionin5GS() const { return get<NRrestrictionin5GS>(3); }
		bool is_unknown() const { return type == 4; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<NRrestrictioninEPSasSecondaryRAT>(); break;
			case 2: var.destroy<CNTypeRestrictions>(); break;
			case 3: var.destroy<NRrestrictionin5GS>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<NRrestrictioninEPSasSecondaryRAT>(1);
			v.template operator()<CNTypeRestrictions>(2);
			v.template operator()<NRrestrictionin5GS>(3);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_NRrestrictioninEPSasSecondaryRAT()); return true;
			case 2: v(select_id_CNTypeRestrictions()); return true;
			case 3: v(select_id_NRrestrictionin5GS()); return true;
			case 4: if(type != 4) {clear(); asn::base::set();} type = 4; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<NRrestrictioninEPSasSecondaryRAT>()); return true;
			case 2: v(var.as<CNTypeRestrictions>()); return true;
			case 3: v(var.as<NRrestrictionin5GS>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(CNTypeRestrictions)];
			char dummy2[sizeof(NRrestrictionin5GS)];
			char dummy3[sizeof(NRrestrictioninEPSasSecondaryRAT)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 4; }
		void clear() {type = 0;}
		void select_id_NRrestrictioninEPSasSecondaryRAT() { set(optional); type=1;}
		void select_id_CNTypeRestrictions() { set(optional); type=2;}
		void select_id_NRrestrictionin5GS() { set(optional); type=3;}
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
HandoverRestrictionList ::= SEQUENCE {
	servingPLMN					PLMN-Identity,
	equivalentPLMNs				EPLMNs					OPTIONAL,
	forbiddenTAs				ForbiddenTAs			OPTIONAL,
	forbiddenLAs				ForbiddenLAs			OPTIONAL,
	forbiddenInterRATs			ForbiddenInterRATs		OPTIONAL,
	iE-Extensions				ProtocolExtensionContainer { {HandoverRestrictionList-ExtIEs} }	OPTIONAL,
	...
}
*/

struct HandoverRestrictionList : asn::sequence<6, 0, true, 5>
{
	static constexpr const char* name() {return "HandoverRestrictionList";}
	using parent_t = asn::sequence<6, 0, true, 5>;
	struct servingPLMN_t : PLMN_Identity
	{
		static constexpr const char* name() {return "servingPLMN_t";}
		using parent_t = PLMN_Identity;

	};
	servingPLMN_t& ref_servingPLMN() {return servingPLMN;}
	servingPLMN_t const& ref_servingPLMN() const {return servingPLMN;}
	struct equivalentPLMNs_t : EPLMNs
	{
		static constexpr const char* name() {return "equivalentPLMNs_t";}
		using parent_t = EPLMNs;
		static constexpr bool optional = true;

	};
	equivalentPLMNs_t& set_equivalentPLMNs() { equivalentPLMNs.setpresent(true); return equivalentPLMNs;}
	equivalentPLMNs_t const* get_equivalentPLMNs() const {return equivalentPLMNs.is_valid() ? &equivalentPLMNs : nullptr;}
	struct forbiddenTAs_t : ForbiddenTAs
	{
		static constexpr const char* name() {return "forbiddenTAs_t";}
		using parent_t = ForbiddenTAs;
		static constexpr bool optional = true;

	};
	forbiddenTAs_t& set_forbiddenTAs() { forbiddenTAs.setpresent(true); return forbiddenTAs;}
	forbiddenTAs_t const* get_forbiddenTAs() const {return forbiddenTAs.is_valid() ? &forbiddenTAs : nullptr;}
	struct forbiddenLAs_t : ForbiddenLAs
	{
		static constexpr const char* name() {return "forbiddenLAs_t";}
		using parent_t = ForbiddenLAs;
		static constexpr bool optional = true;

	};
	forbiddenLAs_t& set_forbiddenLAs() { forbiddenLAs.setpresent(true); return forbiddenLAs;}
	forbiddenLAs_t const* get_forbiddenLAs() const {return forbiddenLAs.is_valid() ? &forbiddenLAs : nullptr;}
	struct forbiddenInterRATs_t : ForbiddenInterRATs
	{
		static constexpr const char* name() {return "forbiddenInterRATs_t";}
		using parent_t = ForbiddenInterRATs;
		static constexpr bool optional = true;

	};
	forbiddenInterRATs_t& set_forbiddenInterRATs() { forbiddenInterRATs.setpresent(true); return forbiddenInterRATs;}
	forbiddenInterRATs_t const* get_forbiddenInterRATs() const {return forbiddenInterRATs.is_valid() ? &forbiddenInterRATs : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<HandoverRestrictionList_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<HandoverRestrictionList_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { 