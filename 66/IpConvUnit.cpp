//---------------------------------------------------------------------------
#include "hdrs.h"

#include <vcl.h>
#pragma hdrstop

#include "def.h"

#include "IpConvUnit.h"

#include "MainUnit.h"

#include "def2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TIpConvForm *IpConvForm;
//---------------------------------------------------------------------------

__fastcall TIpConvForm::TIpConvForm(TComponent * Owner)
        : TForm(Owner)
{
}


void __fastcall TIpConvForm::Button2Click(TObject * Sender)
{
	Close();
	return;
}


void __fastcall TIpConvForm::Button1Click(TObject * Sender)
{
	char local_01[256];
	char local_02[256];
	CKey local_00;
	local_00.mf_CKey_0060();
	local_00.m_int_unk203=1;
	strcpy(local_02,OriginalEdit->Text.c_str());
	if (! (!((int)local_02[0]==64||strlen(local_02)<5)&&strchr(local_02,58)!=0) ) {
		CryptEdit->Text="@";
	}
	else {
	local_00.mf_CKey_0070(local_02,strlen(local_02),false);
	local_00.mf_CKey_0270("opiewf6ascxlv",local_01);
	CryptEdit->Text=local_01;
	}
}


void __fastcall TIpConvForm::FormClose(TObject * Sender,TCloseAction & Action)
{
	IpConvForm->Release();
	IpConvForm=NULLPO;
	return;
}




//---------------------------------------------------------------------------
