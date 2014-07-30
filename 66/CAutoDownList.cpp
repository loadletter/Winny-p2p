//---------------------------------------------------------------------------
#include "hdrs.h"

#include <vcl.h>
#pragma hdrstop

#include "def.h"

#include "CKey.h"

#include "def2.h"
#include "globals.h"


int                            CAutoDownList::g_int=0                  ;				//fr 0053E5A0 00000004


CAutoDownList::CAutoDownList()
{
}


CAutoDownList::~CAutoDownList()
{
}


void CAutoDownList::mf_CAutoDownList_0000()
{
	m_flg_unk0=false;
	m_int_unk20=0;
	*m_char256_unk1=0;
	*m_char256_unk2=0;
	m_int_unk4=-1;
	m_double_unk9=0.0;
	m_double_unk10=0.0;
	m_flag_unk8=false;
	m_flag_unk7=false;
	m_flag_unk5=false;
	m_flag_unk6=false;
	memset(m_hash,0,16);
	memset(m_hash_kamo,0,16);
	*m_char256_unk3=0;
	m__unknown_000=0;
	m__unknown_001=0;
	m_int_unk21=g_int;
	g_int=g_int+1;
	return;
}


Bb CAutoDownList::mf_CAutoDownList_0010()
{
	char local_00[64];
	memset(local_00,0,16);
	if (memcmp(m_hash,local_00,16)!=0) {
		return true;
	}
	return false;
}


Bb CAutoDownList::mf_CAutoDownList_0020()
{
	char local_00[64];
	memset(local_00,0,16);
	if (memcmp(m_hash_kamo,local_00,16)!=0) {
		return true;
	}
	return false;
}
