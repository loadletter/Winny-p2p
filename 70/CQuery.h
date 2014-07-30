#ifndef _CQUERY_H_INCLUDED
#define _CQUERY_H_INCLUDED


#include "CKey.h"
#include "CHost.h"


class CQuery 
{
public:
	char                     m_sz_filename__[1024]               ;   //fr      0   1024 
	unsigned char              m_uchar16_unk1[16]                ;   //fr   1024     16 
	_STL::vector<CHostHeader>            m_vectorCHostHeader_          ;   //fr   1040     24
	_STL::vector<CKeyHeader>             m_vectorCKeyHeader_           ;   //fr   1064     24 
	int                            m_int_unk2                    ;   //fr   1088      4 
	int                            m_int_unk3                    ;   //fr   1092      4 
	_in_addr                       m_ipaddr_                     ;   //fr   1096      4 
	int                            m_port_                       ;   //fr   1100      4 
	Bb                             m_flg_isBbsQuery__            ;   //fr   1104      1
	Bb                             m_flg_unk01                   ;   //fr   1105      1 
	Bb                             m_flg_unk02                   ;   //fr   1106      1 
	Bb                             m_flg_unk03                   ;   //fr   1107      1 
	Bb                             m_flg_unk04                   ;   //fr   1108      1 
	Bb                             m_flg_isFromPortZero__        ;   //fr   1109      1 

	CQuery();
	~CQuery();
	void mf_CQuery_0000(const char * arg_0,const char * arg_1,int arg_2);
	void mf_CQuery_0010(_in_addr * arg_0,int arg_1);
	Bb mf_CQuery_0020(_in_addr * arg_0,int * arg_1);
	bool mf_CQuery_0030(CKey * arg_0,CHost * arg_1,bool arg_2,bool arg_3,int arg_4);
	bool mf_CQuery_0040(int arg_0,_in_addr * arg_1,int * arg_2,_in_addr * arg_3,int * arg_4,char * arg_5,unsigned int * arg_6,unsigned int * arg_7,unsigned char * arg_8,int * arg_9,int * arg_10,bool * arg_11,time_t * arg_12,char * arg_13,bool * arg_14,char * arg_15);
	sl mf_CQuery_0050(_in_addr * arg_0,int arg_1);
	void mf_CQuery_0060(CHost * arg_0,_in_addr * arg_1,int arg_2);
	int mf_CQuery_0070(char * arg_0,CHost * arg_1,CHost * arg_2,bool arg_3);
	void mf_CQuery_0080(unsigned char * arg_0,int arg_1,bool arg_2);

	bool Get_flg_unk04() _CONST { return m_flg_unk04; }
	void Set_flg_unk04(_CONST bool s) { m_flg_unk04=s; }
	void Set_flg_isBbsQuery__(_CONST bool s) { m_flg_isBbsQuery__=s; }

	void SetPort(_CONST int s) { m_port_=s; }
	void SetIpaddr(_CONST _in_addr *s) { memcpy(&m_ipaddr_,s,4); }
};



#endif// _CQUERY_H_INCLUDED

