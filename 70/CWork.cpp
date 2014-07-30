//---------------------------------------------------------------------------
#include "hdrs.h"

#include <vcl.h>
#pragma hdrstop

#include "def.h"

#include "CKey.h"

#include "def2.h"
#include "globals.h"


int                            g_int_1=0                ;				//fr 0053E574 00000004


CWork::CWork()
{
}


CWork::~CWork()
{
}


void CWork::mf_CWork_0000()
{
	int local_00;
	m_worktype_=WORKTYPE00;
	m_hostIdx_=-1;
	m_hostIdx_mouikko_=-1;
	m_uint_countNow=0;
	m_uint_countMax_=0;
	memset(m_uchar16_unk1,0,16);
	memset(m_uchar16_unk2,0,16);
	m_flgIsFinished_370=false;
	m_int_unk304=0;
	*m_sz_foldername_kamo_=0;
	*m_char256_unk10=0;
	*m_char16_unk301=0;
	*m_char256_unk3=0;
	m_flg_unk302=false;
	m_flgkasiraso_=false;
	m_flgkasiraso_3=false;
	m_int_unk31=0;
	m_int_unk30=0;
	for (local_00=0; local_00<60; local_00++) {
		m_intarray60_unk306[local_00]=0;
	}
	m_int_unk220_=0;
	m_double_unk6=0.0;
	m_uint_unk210=0;
	m_int_unk32=-1;
	m_int_unk34=-1;
	m_int_errorcode_kamo_=-1;
	m_flgkasiraso_2=false;
	m_flgkasiraso_1=false;
	m_int_unk211=-1;
	m_flgkasiraso_4=false;
	m_flgkasiraso_5=false;
	m_socket_unk5=0;//INVALID_SOCKET;
	m_int_unk300=g_int_1;
	g_int_1=g_int_1+1;
	m_pchar_unk=NULLPO;
	m_flg_unk200=false;
	m_flg_unk201=false;
	m_flg_unk202=false;
	m_flg_unk212=false;
	if (g_int_1>0x000186A0) {
		g_int_1=0;
	}
	m_pchar_status_=NULLPO;
	m_fileptr=NULLPO;
	return;
}


void CWork::mf_CWork_0010(bool arg_0,bool arg_1)
{
	CKey * local_00;
	m_flgIsSuccessed_371=(bool)!arg_0;
	m_flgIsFinished_370=true;
	local_00=g_pCMainControl->mf_CMainControl_0180(m_uint_countMax_,m_uchar16_unk1);
	if (local_00!=0) {
		local_00->mf_CKey_0030();
		if (! (!local_00->m_bln_unk308||m_worktype_!=WORKTYPE01) ) {
			g_pCMainControl->m_flgarray_unk[10]=true;
		}
	}
	if (! (!arg_1||m_hostIdx_<0||m_flgkasiraso_1) ) {
		g_pCMainControl->m_hostArray[m_hostIdx_].mf_CHost_0190(true);
	}
	m_hostIdx_=-1;
	if ((int)m_socket_unk5>0) {
		closesocket(m_socket_unk5);
		m_socket_unk5=0/*INVALID_SOCKET ‚Í-1‚¾‚ª0‚ð“ü‚ê‚Ä‚¢‚é–Í—l*/;
		g_int_unk506=g_int_unk506+1;
	}
	mf_CWork_0020();
	if (m_fileptr!=0) {
		fclose(m_fileptr);
	}
	m_fileptr=NULLPO;
	if (m_worktype_==WORKTYPE10) {
		g_pCMainControl->m_flg_unk15511=false;
	}
	return;
}


void CWork::mf_CWork_0020()
{
	if (m_pchar_unk!=0) {
		free(m_pchar_unk);
	}
	m_pchar_unk=NULLPO;
	return;
}


void CWork::mf_CWork_0030()
{
	CKey * local_00;
	m_flg_unk302=true;
	m_flgIsFinished_370=true;
	m_flgIsSuccessed_371=true;
	local_00=g_pCMainControl->mf_CMainControl_0180(m_uint_countMax_,m_uchar16_unk1);
	if (local_00!=0) {
		local_00->mf_CKey_0030();
	}
	return;
}


void CWork::mf_CWork_0040(int arg_0)
{
	m_intarray60_unk306[m_int_unk220_]=m_intarray60_unk306[m_int_unk220_]+arg_0;
	return;
}


void CWork::mf_CWork_0050()
{
	int local_00;
	unsigned int local_01;
	if (m_uint_unk210>=60) {
		m_uint_unk210=60;
	}
	local_00=0;
	for (local_01=0; local_01<m_uint_unk210; local_01++) {
		local_00=local_00+m_intarray60_unk306[local_01];
	}
	m_int_unk220_=m_int_unk220_+1;
	if (m_int_unk220_>=60) {
		m_int_unk220_=0;
	}
	m_intarray60_unk306[m_int_unk220_]=0;
	m_uint_unk210=m_uint_unk210+1;
	if (m_uint_unk210>=60) {
		m_uint_unk210=60;
	}
	if (m_uint_unk210==0) {
		m_double_unk6=0.0;
	} else {
		m_double_unk6=((double)local_00/(double)m_uint_unk210)/1000.0;
	}
}


double CWork::mf_CWork_0060()
{
	CKey * local_00;
	if (! (!(m_double_unk6<(float)0.01)&&(m_worktype_==WORKTYPE01||m_worktype_==WORKTYPE02||m_worktype_==WORKTYPE03)) ) {
		return 1e+010;
	}
	if (g_pCMainControl==0) {
		return 0.0;
	}
	local_00=g_pCMainControl->mf_CMainControl_0180(m_uint_countMax_,m_uchar16_unk1);
	if (! (!(local_00==0)&&local_00->m_int_unk0x!=0) ) {
		return 1e+010;
	}
	return ((double)(local_00->m_uint_unk13-m_uint_countNow)/m_double_unk6)/1000.0;
}


void CWork::mf_CWork_0070(char * arg_0,int arg_1)
{
	if (arg_0!=0) {
		if (m_pchar_unk!=0) {
			free(m_pchar_unk);
		}
		m_pchar_unk=(char *)malloc(arg_1+1);
		memcpy(m_pchar_unk,arg_0,arg_1);
		*(m_pchar_unk+arg_1)=0;
	}
	return;
}


void CWork::mf_CWork_0080(int arg_0,int arg_1,char * arg_2,char * arg_3)
{
	mf_CWork_0000();
	if (arg_3!=0) {
		mf_CWork_0070(arg_3,strlen(arg_3));
	}
	m_worktype_=WORKTYPE09;
	m_hostIdx_=arg_0;
	m_hostIdx_mouikko_=arg_1;
	memcpy(m_uchar16_unk1,arg_2,16);
	m_uint_unk305=20000;
	m_flgkasiraso_=true;
	m_tick_created_kamo_=GetTickCount();
	return;
}


void CWork::mf_CWork_0090(int arg1,unsigned int arg2,unsigned char * arg3,int arg4,int arg5)
{
	CKey * local_00;
	mf_CWork_0000();
	m_worktype_=WORKTYPE01;
	m_hostIdx_=arg1;
	m_hostIdx_mouikko_=arg5;
	memcpy(m_uchar16_unk1,arg3,16);
	m_uint_countMax_=arg2;
	m_int_unk32=arg4;
	m_uint_unk305=1;
	if (g_pCMainControl!=0) {
		local_00=g_pCMainControl->mf_CMainControl_0180(arg2,arg3);
		if (local_00!=0) {
			strcpy(m_char256_unk10,local_00->mf_CKey_0260());
			local_00->mf_CKey_0020();
			local_00->mf_CKey_0110();
			if (local_00->m_bln_unk308) {
				m_uint_unk305=30000;
			} else {
				m_uint_unk305=60000;
			}
		}
	}
	m_flgkasiraso_=true;
	m_int_unk304=1;
	m_int_unk34=5;
	m_tick_created_kamo_=GetTickCount();
	return;
}


void CWork::mf_CWork_0100(int arg1,unsigned int arg2,char * arg3,int arg4,int arg5,int arg6)
{
	CKey * local_00;
	mf_CWork_0000();
	m_worktype_=WORKTYPE05;
	m_hostIdx_=arg1;
	memcpy(m_uchar16_unk1,arg3,16);
	m_uint_countMax_=arg2;
	m_int_unk31=arg4;
	m_int_unk30=arg5;
	m_int_unk20=arg6;
	m_uint_unk305=1;
	if (g_pCMainControl!=0) {
		local_00=g_pCMainControl->mf_CMainControl_0180(arg2,(unsigned char *)arg3);
		if (local_00!=0) {
			local_00->mf_CKey_0020();
			m_uint_unk305=60000;
		}
	}
	m_tick_created_kamo_=GetTickCount();
	return;
}


void CWork::mf_CWork_0110(unsigned int arg_0,unsigned char * arg_1,const char * arg_2)
{
	CKey * local_00;
	mf_CWork_0000();
	m_worktype_=WORKTYPE02;
	memcpy(m_uchar16_unk1,arg_1,16);
	m_uint_countMax_=arg_0;
	m_flgkasiraso_4=true;
	strcpy(m_sz_foldername_kamo_,arg_2);
	m_uint_unk305=1;
	if (g_pCMainControl!=0) {
		local_00=g_pCMainControl->mf_CMainControl_0180(arg_0,arg_1);
		if (local_00!=0) {
			strcpy(m_char256_unk10,local_00->mf_CKey_0260());
			local_00->mf_CKey_0020();
			m_uint_unk305=60000;
		}
	}
	m_tick_created_kamo_=GetTickCount();
	return;
}


void CWork::mf_CWork_0120(unsigned int arg_0,unsigned char * arg_1,const char * arg_2,bool arg_3)
{
	CKey * local_00;
	mf_CWork_0000();
	m_worktype_=WORKTYPE03;
	memcpy(m_uchar16_unk1,arg_1,16);
	m_uint_countMax_=arg_0;
	m_flgkasiraso_4=true;
	strcpy(m_sz_foldername_kamo_,arg_2);
	m_flgkasiraso_3=arg_3;
	m_uint_unk305=1;
	if (g_pCMainControl!=0) {
		local_00=g_pCMainControl->mf_CMainControl_0180(arg_0,arg_1);
		if (local_00!=0) {
			strcpy(m_char256_unk10,local_00->mf_CKey_0260());
			local_00->mf_CKey_0020();
			m_uint_unk305=60000;
		}
	}
	m_tick_created_kamo_=GetTickCount();
	return;
}


void CWork::mf_CWork_0130(int arg_0,bool arg_1)
{
	mf_CWork_0000();
	m_flgkasiraso_5=arg_1;
	m_worktype_=WORKTYPE06;
	m_hostIdx_=arg_0;
	m_uint_countNow=1;
	m_tick_created_kamo_=GetTickCount();
	m_uint_unk305=60000;
	return;
}


void CWork::mf_CWork_0140(const char * arg_0,const char * arg_1,int arg_2)
{
	mf_CWork_0000();
	m_worktype_=WORKTYPE04;
	strcpy(m_sz_foldername_kamo_,arg_0);
	if (arg_1!=0) {
		strcpy(m_char16_unk301,arg_1);
	}
	m_int_unk33=arg_2;
	m_tick_created_kamo_=GetTickCount();
	m_uint_unk305=6000000;
	return;
}


void CWork::mf_CWork_0150(char * arg_0,int arg_1)
{
	mf_CWork_0000();
	m_worktype_=WORKTYPE07;
	if (arg_0!=0) {
		strcpy(m_char16_unk301,arg_0);
	}
	m_int_unk33=arg_1;
	m_tick_created_kamo_=GetTickCount();
	m_uint_unk305=6000000;
	return;
}


void CWork::mf_CWork_0160(int arg_0)
{
	mf_CWork_0000();
	m_worktype_=WORKTYPE08;
	m_hostIdx_=arg_0;
	m_tick_created_kamo_=GetTickCount();
	m_uint_unk305=60000;
	return;
}


void CWork::mf_CWork_0170()
{
	mf_CWork_0000();
	m_worktype_=WORKTYPE10;
	m_tick_created_kamo_=GetTickCount();
	g_pCMainControl->m_flg_unk15511=true;
	m_uint_unk305=10000;
	return;
}

