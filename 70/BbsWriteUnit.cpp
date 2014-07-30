//---------------------------------------------------------------------------
#include "hdrs.h"

#include <vcl.h>
#pragma hdrstop

#include "def.h"

#include "BbsWriteUnit.h"
#include "def2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBbsWriteForm *BbsWriteForm;
//---------------------------------------------------------------------------



__fastcall TBbsWriteForm::TBbsWriteForm(TComponent * Owner)
        : TForm(Owner)
{
	memset(m_hash,16,0);
}


void __fastcall TBbsWriteForm::WriteButtonClick(TObject * Sender)
{
	int local_03;
	char local_12[5000];
	char local_13[256];
	char local_14[1024];

	if (MessageEdit->Text.Length()>3000) {
		strcpy(g_pCMainControl->m_szstr_errormsg_,"本文が長すぎます");
		return;
	}
	if (TripCombo->Text.Length()>64) {
		strcpy(g_pCMainControl->m_szstr_errormsg_,"トリップが長すぎます");
		return;
	}
	if (NameCombo->Text.Length()>64) {
		strcpy(g_pCMainControl->m_szstr_errormsg_,"名前が長すぎます");
		return;
	}
	ny_unknown_0020(MessageEdit->Text.c_str(),local_12);
	ny_unknown_0020(NameCombo->Text.c_str(),local_13);
	CGlobalLock CGLock;
	g_pCMainControl->mf_CMainControl_1450(local_13,TripCombo->Text.c_str(),local_12,m_hash);
	WriteButton->Enabled=false;
	BbsCheckTimer->Enabled=true;
	AnsiString local_00=(TripCombo->Text);
	local_03=0;
	if (local_00.Length()>=2) {
		int local_04=TripCombo->Items->Count;
		int local_05=0;
		bool local_06=false;
		for (int local_07=0; local_07<local_04; local_07++) {
			AnsiString local_01=(TripCombo->Items->Strings[local_07]);
			if (local_01.AnsiCompare(local_00)==0) {
				local_06=true;
				local_05=local_07;
				break;
			}
		}
		if (!local_06) {
			TripCombo->Items->Insert(local_05,local_00);
			local_03=local_03+1;
		}
	}
	sprintf(local_14,"%s%s",/*(const char *)*/g_AppPath,"BbsTripString.txt");
	try {
		TripCombo->Items->SaveToFile(local_14);
	}
	catch (const EFOpenError & ex_140) {
	}
	local_00=NameCombo->Text;
	local_03=0;
	if (local_00.Length()>=2) {
		int		local_08=NameCombo->Items->Count;
		int		local_09=0;
		bool	local_10=false;
		for (int local_11=0; local_11<local_08; local_11++) {
			AnsiString local_02=(NameCombo->Items->Strings[local_11]);
			if (local_02.AnsiCompare(local_00)==0) {
				local_10=true;
				local_09=local_11;
				break;
			}
		}
		if (!local_10) {
			NameCombo->Items->Insert(local_09,local_00);
			local_03=local_03+1;
		}
	}
	sprintf(local_14,"%s%s",/*(const char *)*/g_AppPath,"BbsUserName.txt");
	try {
		NameCombo->Items->SaveToFile(local_14);
	}
	catch (const EFOpenError & ex_200) {
	}
	return;
}


void __fastcall TBbsWriteForm::CloseButtonClick(TObject * Sender)
{
	Close();
	return;
}


void __fastcall TBbsWriteForm::BbsCheckTimerTimer(TObject * Sender)
{
	StateLabel->Caption=g_pCMainControl->m_szstr_errormsg_;
	if (strcmp(g_pCMainControl->m_szstr_errormsg_,"投稿に成功しました")==0) {
		WriteButton->Enabled=false;
		BbsCheckTimer->Enabled=false;
		CloseTimer->Enabled=true;
	} else if (*g_pCMainControl->m_szstr_errormsg_!=0) {
		WriteButton->Enabled=true;
		BbsCheckTimer->Enabled=false;
	}
	return;
}


void __fastcall TBbsWriteForm::FormHide(TObject * Sender)
{
	BbsCheckTimer->Enabled=false;
	return;
}


void __fastcall TBbsWriteForm::CloseTimerTimer(TObject * Sender)
{
	CloseTimer->Enabled=false;
	Close();
	return;
}


void __fastcall TBbsWriteForm::FormShow(TObject * Sender)
{
	WriteButton->Enabled=true;
	return;
}


//---------------------------------------------------------------------------
