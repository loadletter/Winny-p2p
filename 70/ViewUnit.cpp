//---------------------------------------------------------------------------
#include "hdrs.h"

#include <vcl.h>
#pragma hdrstop

#include "def.h"

#include "ViewUnit.h"
#include "AutoDownUnit.h"
#include "MainUnit.h"

#include "def2.h"
#include "globals.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TViewForm *ViewForm;
//---------------------------------------------------------------------------

__fastcall TViewForm::TViewForm(TComponent * Owner)
        : TForm(Owner)
{
	char local_01[256];
	ViewGrid->ColWidths[0]=70;
	ViewGrid->ColWidths[1]=500;
	ViewGrid->Cells[0][0]="  Addr.";
	ViewGrid->Cells[1][0]=" +0 +1 +2 +3 +4 +5 +6 +7 +8 +9 +A +B +C +D +E +F   0123456789ABCDEF";
	for (int local_00=0; ViewGrid->RowCount-1>local_00; local_00++) {
		sprintf(local_01," %06X",local_00<<4);
		ViewGrid->Cells[0][local_00+1]=local_01;
	}
}


void __fastcall TViewForm::CancelButtonClick(TObject * Sender)
{
	Close();
	return;
}


void __fastcall TViewForm::FormResize(TObject * Sender)
{
	ViewGrid->ColWidths[1]=ViewGrid->Width-ViewGrid->ColWidths[0];
	return;
}


void __fastcall TViewForm::RefreshButtonClick(TObject * Sender)
{
	int local_00;
	int local_01;
	char local_05[256];
	char local_06[256];
	unsigned char local_07[131072];
	CGlobalLock CGLock;

	for (local_01=1; ViewGrid->RowCount-1>local_01; local_01++) {
		ViewGrid->Cells[1][local_01]="";
	}
	CKey *	local_02=g_pCMainControl->mf_CMainControl_0180(0,m_hash);
	if (local_02!=0) {
		TitleEdit->Text=local_02->mf_CKey_0260();
		if (g_pCMainControl->mf_CMainControl_1300(-1,local_02->m_hash_tabun,0,local_07,0x00010000)) {
			for (local_01=0; ViewGrid->RowCount-1>local_01; local_01++) {
				strcpy(local_06," ");
				for (local_00=0; local_00<16; local_00++) {
					sprintf(local_05,"%02X ",(unsigned int)*((local_07+local_01*16)+local_00));
					strcat(local_06,local_05);
				}
				strcat(local_06,": ");
				char * local_03=strlen(local_06)+local_06;
				for (local_00=0; local_00<16; local_00++) {
					unsigned char local_04=*((local_07+local_01*16)+local_00);
					if (local_04>=' ') {
						*local_03=local_04;
					} else {
						*local_03='.';
					}
					local_03=local_03+1;
				}
				*local_03=0;
				ViewGrid->Cells[1][local_01+1]=local_06;
			}
		}
	} else {
		TitleEdit->Text=("Žw’è‚³‚ê‚½ƒL[‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ");
	}
	return;
}


void __fastcall TViewForm::FormShow(TObject * Sender)
{
	Width=g_pTIniFile->ReadInteger("ViewFrame","Width",600);
	Height=g_pTIniFile->ReadInteger("ViewFrame","Height",500);
	return;
}


void __fastcall TViewForm::FormHide(TObject * Sender)
{
	g_pTIniFile->WriteInteger("ViewFrame","Width",Width);
	g_pTIniFile->WriteInteger("ViewFrame","Height",Height);
	return;
}


void __fastcall TViewForm::IgnoreButtonClick(TObject * Sender)
{
	CKey * local_00;
	char local_01[256];
	CGlobalLock CGLock;
	local_00=g_pCMainControl->mf_CMainControl_0180(0,m_hash);
	if (local_00==0) {
		return;
	}
	AutoDownForm->KeywordCombo->Text=local_00->mf_CKey_0260();
	AutoDownForm->TripCombo->Text=local_00->mf_CKey_0000();
	ny_binhash2aschash(local_00->m_hash_tabun,local_01);
	AutoDownForm->HashEdit->Text=local_01;
	AutoDownForm->UpperSizeEdit->Text="";
	AutoDownForm->LowerSizeEdit->Text="";
	AutoDownForm->BbsCheck->Checked=false;
	AutoDownForm->AutoDeleteCheck->Checked=false;
	AutoDownForm->IgnoreCheck->Checked=true;
	AutoDownForm->DeleteCheck->Checked=true;
	AutoDownForm->DisconnectCheck->Checked=true;
	AutoDownForm->DeleteCheck->Enabled=false;
	AutoDownForm->DisconnectCheck->Enabled=false;
	AutoDownForm->DisconnectLabel->Enabled=false;
	AutoDownForm->OkButton->Caption="’Ç‰Á";
	AutoDownForm->m_int1=-1;
	AutoDownForm->m_int2=-1;
	Close();
	AutoDownForm->Show();
	AutoDownForm->KeywordCombo->SetFocus();
	return;
}


//---------------------------------------------------------------------------
