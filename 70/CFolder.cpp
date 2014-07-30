//---------------------------------------------------------------------------
#include "hdrs.h"

//#include <vcl.h>
#pragma hdrstop

#include <system.hpp>

#include "def0.h"

#include "CFolder.h"

void ny_htmlproc_5(const char * src,char * dest);



CFolder::CFolder()
{
}


CFolder::~CFolder()
{
}


void CFolder::mf_CFolder_0000()
{
	m__unknown_000="";
	m__unknown_001="";
	m__unknown_002="";
	m__unknown_003="";
	m_int_unk1=0;
	m_int_unk2=0;
	m_flg_unk3=true;
	m_flg_unk4=false;
}



void CFolder::mf_CFolder_0010(AnsiString arg_0)
{
	char local_00[1024];
	char local_01[16];
	m__unknown_003=arg_0;
	if (arg_0.Length()==0) {
		m__unknown_002="";
		return;
	}
	strcpy(local_00,arg_0.c_str());
	ny_htmlproc_5(local_00,local_01);
	m__unknown_002=local_01;
}

