#ifndef _CLASSES_H_INCLUDED
#define _CLASSES_H_INCLUDED


#include "md5.h"

#include "CKey.h"


class CBoardSorter
{
public:
	int                            m_int_unk4                    ;   //fr      0      4
	int                            m_int_unk5                    ;   //fr      4      4
	CKey *                         m_pCKey                       ;   //fr      8      4
	char                      m_szstr_unk1[512]                  ;   //fr     12    512
	char                       m_char48_unk6[36]                 ;   //fr    524     48
	double                         m_double_unk2                 ;   //fr    560      8
	int                            m_int_unk3                    ;   //fr    568      4
	Bb                             m_flag_unk4                   ;   //fr    572      1

	bool operator < (const CBoardSorter & arg_0) const
	{
		int local_00;
		int local_01;
		int local_02;
		int local_03;
		if (m_flag_unk4) {
			switch (m_int_unk3) {
			case 0:  
				local_00=!((int)m_pCKey->m_char_keyType_+(unsigned int)m_pCKey->m_bln_unk301==0)?5:0;
				local_01=!((int)arg_0.m_pCKey->m_char_keyType_+(unsigned int)arg_0.m_pCKey->m_bln_unk301==0)?5:0;
				if (local_00==local_01) {
					return (bool)(m_int_unk5<arg_0.m_int_unk5);
				}
				return (bool)(local_00>local_01);
			case 1:  
				return (bool)(m_int_unk5<arg_0.m_int_unk5);
			case 3:  
				if (m_double_unk2==arg_0.m_double_unk2) {
					return (bool)(strcmp(m_szstr_unk1,arg_0.m_szstr_unk1)>0);
				}
				return (bool)(m_double_unk2<arg_0.m_double_unk2);
			case 4:  
				if (strcmp(m_char48_unk6,arg_0.m_char48_unk6)==0) {
					return (bool)(m_int_unk5>arg_0.m_int_unk5);
				}
				return (bool)(strcmp(m_char48_unk6,arg_0.m_char48_unk6)<0);
			case 5:  
				return (bool)((unsigned int)m_pCKey->m_time_<(unsigned int)arg_0.m_pCKey->m_time_);
			case 6:
				if (strcmp(m_pCKey->mf_CKey_0000(),arg_0.m_pCKey->mf_CKey_0000())==0) {
					return (bool)(strcmp(m_szstr_unk1,arg_0.m_szstr_unk1)>0);
				}
				return (bool)(strcmp(m_pCKey->mf_CKey_0000(),arg_0.m_pCKey->mf_CKey_0000())>0);
			case 7:  
				return (bool)(m_pCKey->m_uint_unk13<arg_0.m_pCKey->m_uint_unk13);
			case 8:  
				return (bool)(memcmp((unsigned char *)m_pCKey->m_hash_tabun,(unsigned char *)arg_0.m_pCKey->m_hash_tabun,16)>0);
			}
			return (bool)(strcmp(m_szstr_unk1,arg_0.m_szstr_unk1)>0);
		}
		switch (m_int_unk3) {
		case 0:
			local_02=!((int)m_pCKey->m_char_keyType_+(unsigned int)m_pCKey->m_bln_unk301==0)?5:0;
			local_03=!((int)arg_0.m_pCKey->m_char_keyType_+(unsigned int)arg_0.m_pCKey->m_bln_unk301==0)?5:0;
			if (local_02==local_03) {
				return (bool)(m_int_unk5>arg_0.m_int_unk5);
			}
			return (bool)(local_02<local_03);
		case 1:  
			return (bool)(m_int_unk5>arg_0.m_int_unk5);
		case 3:
			if (m_double_unk2==arg_0.m_double_unk2) {
				return (bool)(strcmp(m_szstr_unk1,arg_0.m_szstr_unk1)<0);
			}
			return (bool)(m_double_unk2>arg_0.m_double_unk2);
		case 4:
			if (strcmp(m_char48_unk6,arg_0.m_char48_unk6)==0) {
				return (bool)(m_int_unk5<arg_0.m_int_unk5);
			}
			return (bool)(strcmp(m_char48_unk6,arg_0.m_char48_unk6)>0);
		case 5:
			return (bool)((unsigned int)m_pCKey->m_time_>(unsigned int)arg_0.m_pCKey->m_time_);
		case 6:
			if (strcmp(m_pCKey->mf_CKey_0000(),arg_0.m_pCKey->mf_CKey_0000())==0) {
				return (bool)(strcmp(m_szstr_unk1,arg_0.m_szstr_unk1)<0);
			}
			return (bool)(strcmp(m_pCKey->mf_CKey_0000(),arg_0.m_pCKey->mf_CKey_0000())<0);
		case 7:
			return (bool)(m_pCKey->m_uint_unk13>arg_0.m_pCKey->m_uint_unk13);
		case 8:
			return (bool)(memcmp((unsigned char *)m_pCKey->m_hash_tabun,(unsigned char *)arg_0.m_pCKey->m_hash_tabun,16)<0);
		}
		return (bool)(strcmp(m_szstr_unk1,arg_0.m_szstr_unk1)<0);
	}

};




class t_hash {
public:
        union {
                unsigned char data[16];
                unsigned int data_d[4];
        };
        unsigned char inline operator [] (int idx) { return data[idx]; }
        inline operator unsigned char *() { return data; }

        t_hash() { memset(data,0,sizeof(data)); }
        //デフォルトコンストラクタがあると、non-ex structured copyになる模様。TBbsTabのほうにおいてもいいかもしれないけど

};



class TBbsTab
{
public:
	t_hash              m_hash                        ;   //fr      0     16
	char                      m_name[256]                        ;   //fr     16    256
	int                            m_int_unk1                    ;   //fr    272      4
	int                            m_int_unk1_1                  ;   //fr    276      4
	
	TBbsTab() { m_name[0]=0; m_int_unk1=-1; m_int_unk1_1=-1; }
};




class CUpfileInfo
{
public:
    char m_unk[24];
};


#include "CKeyBlock.h"



#endif// _CLASSES_H_INCLUDED

