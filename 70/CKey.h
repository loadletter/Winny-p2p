#ifndef _CKEY_H_INCLUDED
#define _CKEY_H_INCLUDED


#include "CLongInt.h"

#include "CRC4.h"


enum enumKeyType {
		KEYTYPE00,KEYTYPE01,KEYTYPE02,KEYTYPE03
};


//typedef unsigned char __uchar;

class CKey
{
public:
	int                            m_int_unk0x                    ;   //fr      0      4
	char                      m_sz_originalFilename_maybe__[258] ;   //fr      4    258
	char                      m_char258_unk1[258]                ;   //fr    262    258
	char                       m_sz_filename_[36]                ;   //fr    520     36
	int                            m_int_lenOriginalFilename_    ;   //fr    556      4
	char                       m_char11_nazo2[16]                ;   //fr    560     16
	unsigned char              m_hash_tabun[16]                  ;   //fr    576     16
	unsigned char              m_char16_char11kamo[16]           ;   //fr    592     16
	_in_addr                       m_ipaddr_0__                  ;   //fr    608      4
	_in_addr                       m_ipaddr_1__                  ;   //fr    612      4
	_in_addr                       m_ipaddr_2__                  ;   //fr    616      4
	int                            m_portno_0__                  ;   //fr    620      4
	int                            m_portno_1__                  ;   //fr    624      4
	int                            m_portno_2__                  ;   //fr    628      4
	int                            m_int_unk200                  ;   //fr    632      4
	unsigned int                   m_uint_unk13                  ;   //fr    636      4
	enumKeyType                          m_char_keyType_               ;   //fr    640      1
	int                            m_int_unk201                  ;   //fr    644      4
	int                            m_int_unk16                   ;   //fr    648      4
	int                            m_int_unk202                  ;   //fr    652      4
	int                            m_int_refcountOfFileptr_      ;   //fr    656      4
	int                            m_int_unk14                   ;   //fr    660      4
	int                            m_int_unk203                  ;   //fr    664      4
	unsigned int                   m_uint_unk204                 ;   //fr    668      4
	time_t                         m_time_                       ;   //fr    672      4
	int                            m_int_unk205                  ;   //fr    676      4
	float                          m_float_unk15                 ;   //fr    680      4
private:
	unsigned int                   m_uint_unk206                 ;   //fr    684      4
public:
	int                            m_int_unk17                   ;   //fr    688      4
	bool                           m_bln_unk301                  ;   //fr    692      1
	bool                           m_bln_unk302                  ;   //fr    693      1
	bool                           m_bln_unk303                  ;   //fr    694      1
	bool                           m_bln_unk304                  ;   //fr    695      1
	bool                           m_bln_unk305                  ;   //fr    696      1
	bool                           m_bln_unk306                  ;   //fr    697      1
	bool                           m_bln_unk307                  ;   //fr    698      1
	bool                           m_bln_unk308                  ;   //fr    699      1
	bool                           m_bln_unk309                  ;   //fr    700      1
	bool                           m_bln_unk310                  ;   //fr    701      1
	bool                           m_bln_unk311                  ;   //fr    702      1
	bool                           m_bln_unk312                  ;   //fr    703      1
	bool                           m_bln_unk313                  ;   //fr    704      1
	bool                           m_bln_unk314                  ;   //fr    705      1
	FILE *                         m_fileptr_                    ;   //fr    708      4
	vector<unsigned char>          m_vectorUchar_                ;   //fr    712     24

	CKey();
	~CKey();
	char * mf_CKey_0000();
	Bb mf_CKey_0010();
	int mf_CKey_0020();
	void mf_CKey_0030();
	bool mf_CKey_0040(const char * arg_0,const char * arg_1,bool arg_2);
	void mf_CKey_0050(time_t arg_0);
	float mf_CKey_0055();           	//doubleÇ©Ç‡
	void mf_CKey_0060();
	void mf_CKey_0070(char * arg_0,unsigned int arg_1,bool arg_2);
	void mf_CKey_0080();
	int mf_CKey_0090();
	int mf_CKey_0100();
	int mf_CKey_0110();
	void mf_CKey_0120();
	void mf_CKey_0130();
	Bb mf_CKey_0140();
	sl mf_CKey_0150();
	int mf_CKey_0160();
	unsigned int mf_CKey_0170();
	void mf_CKey_0180(unsigned int arg_0,unsigned char arg_1);
	unsigned char mf_CKey_0190(int arg_0);
	void mf_CKey_0200(int arg_0,char * arg_1);
	AnsiString mf_CKey_0210();
	void mf_CKey_0220();
	AnsiString mf_CKey_0230();
	void mf_CKey_0240(unsigned int arg_0);
	Bb mf_CKey_0250();
	char * mf_CKey_0260();
	void mf_CKey_0270(const char * arg_0,char * arg_1);
	void mf_CKey_0280(char * arg_0,bool arg_1);
	void mf_CKey_0290();


	void Set_char11_nazo2(const char * _CONST s) { strcpy(m_char11_nazo2,s); }
	inline void Set_int_unk14(_CONST int s) { m_int_unk14=s; }
	void Set_int_unk16(_CONST int s) { m_int_unk16=s; }
	void Set_bln_unk307(_CONST bool s) { m_bln_unk307=s; }
	void Set_bln_unk308(_CONST bool s) { m_bln_unk308=s; }
	void Set_bln_unk313(_CONST bool s) { m_bln_unk313=s; }
	void Set_bln_unk314(_CONST bool s) { m_bln_unk314=s; }
	int Get_int_unk0x() _CONST { return m_int_unk0x; }
	void Set_int_unk0x(_CONST int s) { m_int_unk0x=s; }
	unsigned int Get_uint_unk206() { return m_uint_unk206; }
	void Set_uint_unk206(_CONST unsigned int s) { m_uint_unk206=s; }
	void Set_int_unk200(_CONST int s) { m_int_unk200=s; }
	void Set_int_unk201(_CONST int s) { m_int_unk201=s; }
	void Set_int_unk203(_CONST int s) { m_int_unk203=s; }
	void Set_portno_0(_CONST int s) { m_portno_0__=s; }
	void Set_portno_1(_CONST int s) { m_portno_1__=s; }
	void Set_portno_2(_CONST int s) { m_portno_2__=s; }
	time_t Get_time() { return m_time_; }
	void Set_time(_CONST time_t s) { m_time_=s; }
	void SetKeyType(_CONST enumKeyType s) { m_char_keyType_=s; }
	void Set_hash_tabun(unsigned char * _CONST s) {	memcpy(m_hash_tabun,s,16); }
	int memcmp_hash_tabun(unsigned char * _CONST s) _CONST { return memcmp(m_hash_tabun,s,16); }
	void Set_ipaddr_0(_in_addr * _CONST s) { memcpy(&m_ipaddr_0__,s,4); }
	void SetRefs(_CONST unsigned int s) { m_uint_unk204=s^0x98765432; }
	unsigned int GetRefs() { return m_uint_unk204^0x98765432; }
	void IncrementRefs() { m_uint_unk204=((m_uint_unk204^0x98765432)+1)^0x98765432; }
	_in_addr * GetIpaddr1() { return &m_ipaddr_1__; }


	static CRC4                           g_CRC4                 ;				//fr 0053ED38 00000303
};


class CKeyHeader 
{
public:
	_in_addr                       m_ipaddr_tabun1               ;   //fr      0      4 
	int                            m_port_tabun1                 ;   //fr      4      4 
	_in_addr                       m_ipaddr_tabun2               ;   //fr      8      4 
	int                            m_port_tabun2                 ;   //fr     12      4 
	unsigned int                   m_uint_unk0_                  ;   //fr     16      4 
	unsigned char              m_hash_kamo[16]                   ;   //fr     20     16 
	char                      m_sz_filename_[512]                ;   //fr     36    512 
	char                       m_char12_unk1_[12]                ;   //fr    548     12 
	char                       m_char12_unk2_[12]                ;   //fr    560     12 
	int                            m_int_unk10                   ;   //fr    572      4 
	int                            m_int_unk11                   ;   //fr    576      4 
	time_t                         m__unknown_000                ;   //fr    580      4 
	unsigned char                  m_uchar_filenamelen_          ;   //fr    584      1 

	Bb                             m__unknown_001                ;   //fr    585      1
		//ucharÇ©Ç‡ÇµÇÍÇ»Ç¢

	Bb                             m__unknown_002                ;   //fr    586      1

	bool                             m_flg_unk12                   ;   //fr    587      1
		//ucharÇ©Ç‡ÇµÇÍÇ»Ç¢ÇÃÇ≈íçà”


	CKeyHeader(){}

};



class CKeySorter 
{
public:
	int                            m_int_unk0                    ;   //fr      0      4 
	CKey *                         m_pCKey                       ;   //fr      4      4 
	char                      m_szstr_unk1[512]                  ;   //fr      8    512 
	double                         m_double_unk2                 ;   //fr    520      8 
	int                            m_int_unk3                    ;   //fr    528      4 
	Bb                             m_flag_unk4                   ;   //fr    532      1 

	bool operator < (const CKeySorter & arg_0) const
	{
		float local_00;
		float local_01;
		float local_02;
		float local_03;
		if (m_flag_unk4) {
			switch (m_int_unk3) {
			case 1:  
				if (strcmp(m_pCKey->mf_CKey_0000(),arg_0.m_pCKey->mf_CKey_0000())==0) {
					return (bool)(strcmp(m_szstr_unk1,arg_0.m_szstr_unk1)>0);
				}
				return (bool)(strcmp(m_pCKey->mf_CKey_0000(),arg_0.m_pCKey->mf_CKey_0000())>0);
			case 2:  
				return (bool)(m_pCKey->m_uint_unk13<arg_0.m_pCKey->m_uint_unk13);
			case 3:
				local_00=m_pCKey->mf_CKey_0055();
				local_01=arg_0.m_pCKey->mf_CKey_0055();
				if (local_00==local_01) {
					return (bool)(strcmp(m_szstr_unk1,arg_0.m_szstr_unk1)>0);
				}
				return (bool)(local_00>local_01);
			case 4:
				if (m_pCKey->m_char_keyType_==arg_0.m_pCKey->m_char_keyType_) {
					return (bool)(strcmp(m_szstr_unk1,arg_0.m_szstr_unk1)>0);
				}
				return (bool)(m_pCKey->m_char_keyType_<arg_0.m_pCKey->m_char_keyType_);
			case 5:
				if (m_double_unk2==arg_0.m_double_unk2) {
					return (bool)(strcmp(m_szstr_unk1,arg_0.m_szstr_unk1)>0);
				}
				return (bool)(m_double_unk2<arg_0.m_double_unk2);
			case 6:
				return (bool)((unsigned int)m_pCKey->m_time_<(unsigned int)arg_0.m_pCKey->m_time_);
			case 7:
				if (m_pCKey->m_float_unk15==arg_0.m_pCKey->m_float_unk15) {
					return (bool)(strcmp(m_szstr_unk1,arg_0.m_szstr_unk1)>0);
				}
				return (bool)(m_pCKey->m_float_unk15>arg_0.m_pCKey->m_float_unk15);
			case 8:
				if (m_pCKey->m_int_unk203==arg_0.m_pCKey->m_int_unk203) {
					return (bool)(strcmp(m_szstr_unk1,arg_0.m_szstr_unk1)>0);
				}
				return (bool)(m_pCKey->m_int_unk203>arg_0.m_pCKey->m_int_unk203);
			case 9:
				return (bool)(memcmp((unsigned char *)m_pCKey->m_hash_tabun,(unsigned char *)arg_0.m_pCKey->m_hash_tabun,16)>0);
			}
			return (bool)(strcmp(m_szstr_unk1,arg_0.m_szstr_unk1)>0);
		}
		switch (m_int_unk3) {
		case 1:
			if (strcmp(m_pCKey->mf_CKey_0000(),arg_0.m_pCKey->mf_CKey_0000())==0) {
				return (bool)(strcmp(m_szstr_unk1,arg_0.m_szstr_unk1)<0);
			}
			return (bool)(strcmp(m_pCKey->mf_CKey_0000(),arg_0.m_pCKey->mf_CKey_0000())<0);
		case 2:
			return (bool)(m_pCKey->m_uint_unk13>arg_0.m_pCKey->m_uint_unk13);
		case 3:
			local_02=m_pCKey->mf_CKey_0055();
			local_03=arg_0.m_pCKey->mf_CKey_0055();
			if (local_02==local_03) {
				return (bool)(strcmp(m_szstr_unk1,arg_0.m_szstr_unk1)<0);
			}
			return (bool)(local_02<local_03);
		case 4:  
			if (m_pCKey->m_char_keyType_==arg_0.m_pCKey->m_char_keyType_) {
				return (bool)(strcmp(m_szstr_unk1,arg_0.m_szstr_unk1)<0);
			}
			return (bool)(m_pCKey->m_char_keyType_>arg_0.m_pCKey->m_char_keyType_);
		case 5:  
			if (m_double_unk2==arg_0.m_double_unk2) {
				return (bool)(strcmp(m_szstr_unk1,arg_0.m_szstr_unk1)<0);
			}
			return (bool)(m_double_unk2>arg_0.m_double_unk2);
		case 6:  
			return (bool)((unsigned int)m_pCKey->m_time_>(unsigned int)arg_0.m_pCKey->m_time_);
		case 7:
			if (m_pCKey->m_float_unk15==arg_0.m_pCKey->m_float_unk15) {
				return (bool)(strcmp(m_szstr_unk1,arg_0.m_szstr_unk1)<0);
			}
			return (bool)(m_pCKey->m_float_unk15<arg_0.m_pCKey->m_float_unk15);
		case 8:  
			if (m_pCKey->m_int_unk203==arg_0.m_pCKey->m_int_unk203) {
				return (bool)(strcmp(m_szstr_unk1,arg_0.m_szstr_unk1)<0);
			}
			return (bool)(m_pCKey->m_int_unk203<arg_0.m_pCKey->m_int_unk203);
		case 9:  
			return (bool)(memcmp((unsigned char *)m_pCKey->m_hash_tabun,(unsigned char *)arg_0.m_pCKey->m_hash_tabun,16)<0);
		}
		return (bool)(strcmp(m_szstr_unk1,arg_0.m_szstr_unk1)<0);
	}

};

#endif// _CKEY_H_INCLUDED
