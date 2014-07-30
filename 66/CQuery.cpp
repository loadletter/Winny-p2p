//---------------------------------------------------------------------------
#include "hdrs.h"

#include <vcl.h>
#pragma hdrstop

#include "def.h"

#include "CQuery.h"



CQuery::CQuery()
{
}


CQuery::~CQuery()
{
}


void CQuery::mf_CQuery_0000(const char * arg_0,const char * arg_1,int arg_2)
{
	strcpy(m_sz_filename__,arg_0);
	strcpy((char *)m_uchar16_unk1,arg_1);
	m_vectorCHostHeader_.clear();
	m_vectorCKeyHeader_.clear();
	m_flg_unk02=false;
	m_flg_unk03=false;
	m_flg_unk01=false;
	m_flg_unk04=true;
	m_flg_isBbsQuery__=false;
	m_int_unk2=arg_2;
	m_flg_isFromPortZero__=false;
	return;
}


void CQuery::mf_CQuery_0010(_in_addr * arg_0,int arg_1)
{
	try {
		int local_00=m_vectorCHostHeader_.size();
		m_vectorCHostHeader_.resize(local_00+1);
		memcpy(&m_vectorCHostHeader_[local_00],arg_0,4);
		m_vectorCHostHeader_[local_00].m__unknown_000=arg_1;
	}
	catch (std::bad_alloc ex_8) {
		m_flg_unk04=false;
	}
	return;
}


Bb CQuery::mf_CQuery_0020(_in_addr * arg_0,int * arg_1)
{
	try {
		int local_00=m_vectorCHostHeader_.size();
		if (local_00>0) {
			memcpy(arg_0,&m_vectorCHostHeader_[local_00-1].m_ipaddr1,4);
			*arg_1=m_vectorCHostHeader_[local_00-1].m__unknown_000;
			m_vectorCHostHeader_.resize(local_00-1);
			return true;
		}
		return false;
	}
	catch (std::bad_alloc ex_8) {
		m_flg_unk04=false;
		return false;
	}
}



bool CQuery::mf_CQuery_0030(CKey * arg_0,CHost * arg_1,bool arg_2,bool arg_3,int arg_4)
{
	try {
		int local_00=m_vectorCKeyHeader_.size();
		if (! (m_flg_unk01||local_00<=30) ) {
			return false;
		}
		if (! (!m_flg_unk01||local_00<=arg_4) ) {
			return false;
		}
		int local_01;
		for (local_01=0; local_01<local_00; local_01++) {
			CKeyHeader * local_02=&m_vectorCKeyHeader_[local_01];
			if (memcmp(local_02->m_hash_kamo,arg_0->m_hash_tabun,16)==0) break;
		}
		if (local_01==local_00) {
			m_vectorCKeyHeader_.resize(local_00+1);
		} else {
			if (arg_0->m_bln_unk308) {
				if ((unsigned int)m_vectorCKeyHeader_[local_01].m__unknown_000>=(unsigned int)arg_0->m_time_) {
					return true;
				}
			} else {
				if (! (!arg_3&&(arg_0->m_char_keyType_>KEYTYPE01||m_vectorCKeyHeader_[local_01].m_int_unk10<=arg_0->m_int_unk200)) ) {
					return true;
				}
			}
		}
		CKeyHeader * local_03=&m_vectorCKeyHeader_[local_01];
		if (arg_2) {
			memcpy(local_03,&arg_1->m_ipaddr3,4);
			local_03->m_port_tabun1=arg_1->m_port1;
		} else {
			memcpy(local_03,&arg_0->m_ipaddr_0__,4);
			local_03->m_ipaddr_tabun1.b2=local_03->m_ipaddr_tabun1.b2^'^';
			local_03->m_ipaddr_tabun1.b3=local_03->m_ipaddr_tabun1.b3^'^';
			local_03->m_ipaddr_tabun1.b4=local_03->m_ipaddr_tabun1.b4^'^';
			local_03->m_port_tabun1=arg_0->m_portno_0__;
		}
		if (arg_0->m_bln_unk308) {
			memcpy(&local_03->m_ipaddr_tabun2,&arg_0->m_ipaddr_1__,4);
			local_03->m_ipaddr_tabun2.b2=local_03->m_ipaddr_tabun2.b2^'^';
			local_03->m_ipaddr_tabun2.b3=local_03->m_ipaddr_tabun2.b3^'^';
			local_03->m_ipaddr_tabun2.b4=local_03->m_ipaddr_tabun2.b4^'^';
			local_03->m_port_tabun2=arg_0->m_portno_1__;
		} else {
			memset(&local_03->m_ipaddr_tabun2,0,4);
			local_03->m_port_tabun2=0;
		}
		if (!(!arg_0->m_bln_unk308)&&arg_0->m_char_keyType_!=KEYTYPE02||arg_0->m_char_keyType_<=KEYTYPE01) {
			local_03->m_int_unk10=arg_0->m_int_unk200;
		} else {
			if (arg_0->m_bln_unk308) {
				local_03->m_int_unk10=rand()%10+1500;
			} else {
				local_03->m_int_unk10=rand()%100+1500;
			}
		}
		memcpy(local_03->m_hash_kamo,arg_0->m_hash_tabun,16);
		local_03->m_uint_unk0_=arg_0->m_uint_unk13;
		local_03->m_int_unk11=arg_0->m_uint_unk204^0x98765432;
		memcpy(local_03->m_char12_unk1_,arg_0->mf_CKey_0000(),11);
		local_03->m_char12_unk1_[11]=0;
		local_03->m__unknown_002=(arg_0->m_bln_unk313?true:false);
		local_03->m__unknown_000=arg_0->m_time_;
		local_03->m__unknown_001=(arg_0->m_bln_unk311?true:false);
		local_03->m_flg_unk12=*((bool *)(&arg_0->m_int_unk203));
		memcpy(local_03->m_sz_filename_,arg_0->m_sz_originalFilename_maybe__,arg_0->m_int_lenOriginalFilename_+2);
		local_03->m_uchar_filenamelen_=*((unsigned char *)(&arg_0->m_int_lenOriginalFilename_));
		memcpy(local_03->m_char12_unk2_,arg_0->m_char16_char11kamo,12);
		return true;
	}
	catch (std::bad_alloc ex_8) {
		m_flg_unk04=false;
		return false;
	}
}


bool CQuery::mf_CQuery_0040(int arg_0,_in_addr * arg_1,int * arg_2,_in_addr * arg_3,int * arg_4,char * arg_5,unsigned int * arg_6,unsigned int * arg_7,unsigned char * arg_8,int * arg_9,int * arg_10,bool * arg_11,time_t * arg_12,char * arg_13,bool * arg_14,char * arg_15)
{
	int tmp=m_vectorCKeyHeader_.size();
	if (tmp>arg_0&&arg_0>=0) {
		memcpy(arg_1,&m_vectorCKeyHeader_[arg_0],4);
		*arg_2=m_vectorCKeyHeader_[arg_0].m_port_tabun1;
		memcpy(arg_3,&m_vectorCKeyHeader_[arg_0].m_ipaddr_tabun2,4);
		*arg_4=m_vectorCKeyHeader_[arg_0].m_port_tabun2;
		*arg_6=(unsigned int)m_vectorCKeyHeader_[arg_0].m_uchar_filenamelen_;
		memcpy(arg_5,m_vectorCKeyHeader_[arg_0].m_sz_filename_,*arg_6+2);
		memcpy(arg_8,m_vectorCKeyHeader_[arg_0].m_hash_kamo,16);
		*arg_9=m_vectorCKeyHeader_[arg_0].m_int_unk10;
		*arg_7=m_vectorCKeyHeader_[arg_0].m_uint_unk0_;
		*arg_10=m_vectorCKeyHeader_[arg_0].m_int_unk11;
		*arg_11=(bool)((unsigned char)m_vectorCKeyHeader_[arg_0].m__unknown_002>0);
		*arg_12=m_vectorCKeyHeader_[arg_0].m__unknown_000;
		memcpy(arg_13,m_vectorCKeyHeader_[arg_0].m_char12_unk1_,11);
		*(arg_13+11)=0;
		memcpy(arg_15,m_vectorCKeyHeader_[arg_0].m_char12_unk2_,11);
		*(arg_15+11)=0;
		*arg_14=m_vectorCKeyHeader_[arg_0].m_flg_unk12;
		return true;
	}
	return false;
}


sl CQuery::mf_CQuery_0050(_in_addr * arg_0,int arg_1)
{
	int local_00;
	local_00=m_vectorCHostHeader_.size();
	for (int local_01=0; local_01<local_00; local_01++) {
CHostHeader *		local_02=&m_vectorCHostHeader_[local_01];
		if (local_02->m_ipaddr1.b1!=arg_0->b1||local_02->m_ipaddr1.b2!=arg_0->b2||local_02->m_ipaddr1.b3!=arg_0->b3||local_02->m_ipaddr1.b4!=arg_0->b4||local_02->m__unknown_000!=arg_1) continue;
		return local_01;
	}
	return -1;
}


void CQuery::mf_CQuery_0060(CHost * arg_0,_in_addr * arg_1,int arg_2)
{
	int local_00;
	local_00=m_vectorCHostHeader_.size();
	int local_01;
	for (local_01=0; local_01<local_00; local_01++) {
		CHostHeader * local_02=&m_vectorCHostHeader_[local_01];
		if (local_02->m_ipaddr1.b1!=arg_0->m_ipaddr1.b1||local_02->m_ipaddr1.b2!=arg_0->m_ipaddr1.b2||local_02->m_ipaddr1.b3!=arg_0->m_ipaddr1.b3||local_02->m_ipaddr1.b4!=arg_0->m_ipaddr1.b4||local_02->m__unknown_000!=arg_2) continue;
		local_02->m_ipaddr1.b1=arg_1->b1;
		local_02->m_ipaddr1.b2=arg_1->b2;
		local_02->m_ipaddr1.b3=arg_1->b3;
		local_02->m_ipaddr1.b4=arg_1->b4;
	}
	local_00=m_vectorCKeyHeader_.size();
	for (local_01=0; local_01<local_00; local_01++) {
		CKeyHeader * local_03=&m_vectorCKeyHeader_[local_01];
		if (! (local_03->m_ipaddr_tabun1.b1!=arg_0->m_ipaddr1.b1||local_03->m_ipaddr_tabun1.b2!=arg_0->m_ipaddr1.b2||local_03->m_ipaddr_tabun1.b3!=arg_0->m_ipaddr1.b3||local_03->m_ipaddr_tabun1.b4!=arg_0->m_ipaddr1.b4||local_03->m_port_tabun1!=arg_2) ) {
			local_03->m_ipaddr_tabun1.b1=arg_1->b1;
			local_03->m_ipaddr_tabun1.b2=arg_1->b2;
			local_03->m_ipaddr_tabun1.b3=arg_1->b3;
			local_03->m_ipaddr_tabun1.b4=arg_1->b4;
		}
		if (local_03->m_ipaddr_tabun2.b1!=arg_0->m_ipaddr1.b1||local_03->m_ipaddr_tabun2.b2!=arg_0->m_ipaddr1.b2||local_03->m_ipaddr_tabun2.b3!=arg_0->m_ipaddr1.b3||local_03->m_ipaddr_tabun2.b4!=arg_0->m_ipaddr1.b4||local_03->m_port_tabun2!=arg_2) continue;
		local_03->m_ipaddr_tabun2.b1=arg_1->b1;
		local_03->m_ipaddr_tabun2.b2=arg_1->b2;
		local_03->m_ipaddr_tabun2.b3=arg_1->b3;
		local_03->m_ipaddr_tabun2.b4=arg_1->b4;
	}
	return;
}


int CQuery::mf_CQuery_0070(char * arg_0,CHost * arg_1,CHost * arg_2,bool arg_3)
{
	int local_00;
	int local_01;
	local_00=0;
	arg_0[0]=13;
	local_00=local_00+1;
	if (m_flg_unk02) {
		*(arg_0+local_00)=1;
	} else {
		*(arg_0+local_00)=0;
	}
	local_00=local_00+1;
	if (m_flg_unk01) {
		*(arg_0+local_00)=1;
	} else {
		*(arg_0+local_00)=0;
	}
	local_00=local_00+1;
	if (m_flg_unk03) {
		*(arg_0+local_00)=1;
	} else {
		*(arg_0+local_00)=0;
	}
	local_00=local_00+1;
	if (m_flg_isBbsQuery__) {
		*(arg_0+local_00)=1;
	} else {
		*(arg_0+local_00)=0;
	}
	local_00=local_00+1;
	*(int *)(arg_0+local_00)=m_int_unk2;
	local_00=local_00+4;
	local_01=strlen(m_sz_filename__);
	if (local_01>255) {
		local_01=255;
	}
	*(arg_0+local_00)=*((char *)(&local_01));
	local_00=local_00+1;
	memcpy(arg_0+local_00,this,local_01);
	local_00=local_00+local_01;
	memcpy(arg_0+local_00,m_uchar16_unk1,11);
	local_00=local_00+11;
	unsigned int local_02=m_vectorCHostHeader_.size();
	*(arg_0+local_00)=*((char *)(&local_02));
	local_00=local_00+1;
	int local_03;
	CHostHeader * local_04;
	for (local_03=0; local_03<(int)local_02; local_03++) {
		local_04=&m_vectorCHostHeader_[local_03];
		if (! (!arg_2->m_flgIsNAT||arg_2->m_port1!=local_04->m__unknown_000|| !(char)local_04->IsIpaddr_Host_x(*arg_2) ) ) {
			_in_addr *tmp=&arg_2->m_ipaddr1;
			memcpy(arg_0+local_00,tmp,4);
		} else {
			memcpy(arg_0+local_00,&local_04->m_ipaddr1,4);
		}
		local_00=local_00+4;
		*((short *)(arg_0+local_00))=*((short *)(&local_04->m__unknown_000));
		local_00=local_00+2;
	}
	local_02=m_vectorCKeyHeader_.size();
	int local_05;
	CKeyHeader * local_06;
	local_05=0;
	for (local_03=0; local_03<(int)local_02; local_03++) {
		local_06=&m_vectorCKeyHeader_[local_03];
		if (!(!arg_3) && *(unsigned char *)&local_06->m_flg_unk12>4) continue;
		local_05=local_05+1;
	}
	*((short *)(arg_0+local_00))=*((short *)(&local_05));
	local_00=local_00+2;
	for (local_03=0; local_03<(int)local_02; local_03++) {
		CKeyHeader * local_07;
		local_07=&m_vectorCKeyHeader_[local_03];
		if (!(!arg_3)&& *(unsigned char *)&local_07->m_flg_unk12>4) continue;
		if (! (arg_1==0||(unsigned char)local_07->m__unknown_001<=0) ) {
			_in_addr *tmp=&arg_1->m_ipaddr3;
			memcpy(arg_0+local_00,tmp,4);
			local_00=local_00+4;
			*((short *)(arg_0+local_00))=*((short *)(&arg_1->m_port1));
			local_00=local_00+2;
			memset(arg_0+local_00,0,6);
			local_00=local_00+6;
		} else {
			if (! (!arg_2->m_flgIsNAT||arg_2->m_port1!=local_07->m_port_tabun1|| !(char)arg_2->IsInternalIpaddr_x(local_07->m_ipaddr_tabun1) ) ) {
				_in_addr *tmp=&arg_2->m_ipaddr1;
				memcpy(arg_0+local_00,tmp,4);
			} else {
				memcpy(arg_0+local_00,&local_07->m_ipaddr_tabun1,4);
			}
			local_00=local_00+4;
			*((short *)(arg_0+local_00))=*((short *)(&local_07->m_port_tabun1));
			local_00=local_00+2;
			if (! (!arg_2->m_flgIsNAT||arg_2->m_port1!=local_07->m_port_tabun1|| !(char)arg_2->IsInternalIpaddr_x(local_07->m_ipaddr_tabun1) ) ) {
				_in_addr *tmp=&arg_2->m_ipaddr1;
				memcpy(arg_0+local_00,tmp,4);
			} else {
				memcpy(arg_0+local_00,&local_07->m_ipaddr_tabun2,4);
			}
			local_00=local_00+4;
			*((short *)(arg_0+local_00))=*((short *)(&local_07->m_port_tabun2));
			local_00=local_00+2;
		}
		*(unsigned int *)(arg_0+local_00)=local_07->m_uint_unk0_;
		local_00=local_00+4;
		memcpy(arg_0+local_00,local_07->m_hash_kamo,16);
		local_00=local_00+16;
		unsigned int local_08;
		local_08=(unsigned int)local_07->m_uchar_filenamelen_;
		if (local_08>255) {
			local_08=255;
		}
		*(arg_0+local_00)=*((char *)(&local_08));
		local_00=local_00+1;
		memcpy(arg_0+local_00,local_07->m_sz_filename_,local_08+2);
		local_00=local_08+local_00+2;
		memcpy(arg_0+local_00,local_07->m_char12_unk1_,11);
		local_00=local_00+11;
		local_08=strlen(local_07->m_char12_unk2_);
		if (local_08>11) {
			local_08=11;
		}
		*(arg_0+local_00)=*((char *)(&local_08));
		local_00=local_00+1;
		memcpy(arg_0+local_00,local_07->m_char12_unk2_,local_08);
		local_00=local_00+local_08;
		*((short *)(arg_0+local_00))=*((short *)(&local_07->m_int_unk10));
		local_00=local_00+2;
		*(int *)(arg_0+local_00)=local_07->m_int_unk11;
		local_00=local_00+4;
		*(time_t *)(arg_0+local_00)=local_07->m__unknown_000;
		local_00=local_00+4;
		*(arg_0+local_00)=(char)local_07->m__unknown_002;
		local_00=local_00+1;
		*(arg_0+local_00)=(char)local_07->m_flg_unk12;
		local_00=local_00+1;
	}
	return local_00;
}


void CQuery::mf_CQuery_0080(unsigned char * arg_0,int arg_1,bool arg_2)
{
	unsigned int local_00;
	try {
		mf_CQuery_0000("","",-1);
		arg_0=arg_0+1;
		arg_1=arg_1-1;
		if (arg_1<=0) {
			m_flg_unk04=false;
			return;
		}
		if (*arg_0!=0) {
			m_flg_unk02=true;
		} else {
			m_flg_unk02=false;
		}
		arg_0=arg_0+1;
		if (*arg_0!=0) {
			m_flg_unk01=true;
		} else {
			m_flg_unk01=false;
		}
		arg_0=arg_0+1;
		if (*arg_0!=0) {
			m_flg_unk03=true;
		} else {
			m_flg_unk03=false;
		}
		arg_0=arg_0+1;
		if (*arg_0!=0) {
			m_flg_isBbsQuery__=true;
		} else {
			m_flg_isBbsQuery__=false;
		}
		arg_0=arg_0+1;
		m_int_unk2=*((int *)arg_0);
		arg_0=arg_0+4;
		local_00=(int)((unsigned int)*arg_0);
		arg_0=arg_0+1;
		memcpy(this,arg_0,local_00);
		*(m_sz_filename__+local_00)=0;
		arg_0=arg_0+local_00;
		memcpy(m_uchar16_unk1,arg_0,11);
		m_uchar16_unk1[11]=0;
		arg_0=arg_0+11;
		local_00=(int)((unsigned int)*arg_0);
		m_vectorCHostHeader_.resize(local_00);
		arg_0=arg_0+1;

		int local_01;

		for (local_01=0; local_01<(int)local_00; local_01++) {
			CHostHeader * local_02=&m_vectorCHostHeader_[local_01];
			memcpy(local_02,arg_0,4);
			arg_0=arg_0+4;
			local_02->m__unknown_000=(int)((unsigned int)*((unsigned short *)arg_0));
			arg_0=arg_0+2;
		}
		local_00=(int)((unsigned int)*((unsigned short *)arg_0));
		m_vectorCKeyHeader_.resize(local_00);
		arg_0=arg_0+2;
		for (local_01=0; local_01<(int)local_00; local_01++) {
			CKeyHeader * local_03=&m_vectorCKeyHeader_[local_01];
			memcpy(local_03,arg_0,4);
			arg_0=arg_0+4;
			local_03->m_port_tabun1=(int)((unsigned int)*((unsigned short *)arg_0));
			arg_0=arg_0+2;
			memcpy(&local_03->m_ipaddr_tabun2,arg_0,4);
			arg_0=arg_0+4;
			local_03->m_port_tabun2=(int)((unsigned int)*((unsigned short *)arg_0));
			arg_0=arg_0+2;
			local_03->m_uint_unk0_=*((unsigned int *)arg_0);
			arg_0=arg_0+4;
			memcpy(local_03->m_hash_kamo,arg_0,16);
			arg_0=arg_0+16;
			local_03->m_uchar_filenamelen_=*((unsigned char *)arg_0);
			arg_0=arg_0+1;
			memcpy(local_03->m_sz_filename_,arg_0,(unsigned int)local_03->m_uchar_filenamelen_+2);
			*(local_03->m_sz_filename_+(unsigned int)local_03->m_uchar_filenamelen_+2)=0;
			arg_0+=2+(unsigned int)local_03->m_uchar_filenamelen_;
			memcpy(local_03->m_char12_unk1_,arg_0,11);
			local_03->m_char12_unk1_[11]=0;
			arg_0=arg_0+11;
			unsigned char local_04;
			local_04=*arg_0;
			if (local_04>11) {
				local_04=11;
			}
			arg_0=arg_0+1;
			memcpy(local_03->m_char12_unk2_,arg_0,(unsigned int)local_04);
			*(local_03->m_char12_unk2_+(unsigned int)local_04)=0;
			arg_0=arg_0+(unsigned int)local_04;
			local_03->m_int_unk10=(int)((unsigned int)*((unsigned short *)arg_0));
			arg_0=arg_0+2;
			local_03->m_int_unk11=*((int *)arg_0);
			arg_0=arg_0+4;
			local_03->m__unknown_000=*((time_t *)arg_0);
			arg_0=arg_0+4;
			(unsigned char)local_03->m__unknown_002=/*(bool)*/*arg_0;
			arg_0=arg_0+1;
			(unsigned char)local_03->m_flg_unk12=/*(bool)*/*arg_0;
			arg_0=arg_0+1;
			local_03->m__unknown_001=false;
		}
		m_flg_unk04=true;
	}
	catch (std::bad_alloc ex_8) {
		m_flg_unk04=false;
	}
	return;
}



