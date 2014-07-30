//CRC4

//---------------------------------------------------------------------------
#include "hdrs.h"

#include <vcl.h>
#pragma hdrstop

#include "def.h"

#include "CRC4.h"



CRC4::CRC4()
{
	m_tbl_3[0]=1;
	m_tbl_3[1]=0;
}


CRC4::~CRC4()
{
}


void CRC4::setupkey(const char * key)
{
	int local_00;
	int local_01;
	int local_02;
	char local_03[256];
	
	local_00=strlen(key);
	if (strcmp((const char *)m_tbl_3,key)==0) {
		memcpy(this,m_tbl_2,256);
		m_uchar_1=m_uchar_2=0;
		return;
	}
	local_01=0;
	for (local_02=0; local_02<256; local_02++) {
		m_tbl_1[local_02]=*((unsigned char *)(&local_02));
		*(local_03+local_02)=*(key+local_01);
		local_01=local_01+1;
		if (local_01<local_00) continue;
		local_01=0;
	}
	m_uchar_2=local_02=0;
	for ( ; local_02<256; local_02++) {
		m_uchar_2+=local_03[local_02]+m_tbl_1[local_02];
		m_uchar_3=m_tbl_1[local_02];
		m_tbl_1[local_02]=m_tbl_1[m_uchar_2];
		m_tbl_1[m_uchar_2]=m_uchar_3;
	}
	m_uchar_1=m_uchar_2=0;
	memcpy(m_tbl_2,this,256);
	strcpy((char *)m_tbl_3,key);
	return;
}


unsigned char CRC4::mf_CRC4_0000()
{
	m_uchar_1=m_uchar_1+1;
	m_uchar_2=m_uchar_2+m_tbl_1[m_uchar_1];
	m_uchar_3=m_tbl_1[m_uchar_1];
	m_tbl_1[m_uchar_1]=m_tbl_1[m_uchar_2];
	m_tbl_1[m_uchar_2]=m_uchar_3;
	m_uchar_3=m_tbl_1[m_uchar_1]+m_tbl_1[m_uchar_2];
	return m_tbl_1[m_uchar_3];
}


void CRC4::crypter(char * buf,int len)
{
	int local_00;
	for (local_00=0; local_00<len; local_00++) {
		*buf=*buf^mf_CRC4_0000();
		buf=buf+1;
	}
	return;
}




