//---------------------------------------------------------------------------
#include "hdrs.h"

#include <vcl.h>
#pragma hdrstop

#include "def.h"

//Initializer/Finalizerの登録順序は、コンパイル順に影響される模様。
//これをtouchしてbuildすると良い場合がある
                         
#include "def2.h"

#include "globals.h"

#include "OptionUnit.h"
#include "MainUnit.h"

#include "AutoDownUnit.h"



//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAutoDownForm *AutoDownForm;
//---------------------------------------------------------------------------

__fastcall TAutoDownForm::TAutoDownForm(TComponent * Owner)
        : TForm(Owner)
{
	m_int1=-1;
	m_int2=-1;
}


void __fastcall TAutoDownForm::CancelButtonClick(TObject * Sender)
{
	Close();
	m_int1=-1;
	m_int2=-1;
	return;
}



void __fastcall TAutoDownForm::OkButtonClick(TObject * Sender)
{
	CAutoDownList * local_06;
	CAutoDownList * local_07;

	char local_20[16];
	char local_21[64];
	char local_22[1024];

	local_06=NULLPO;
	local_07=NULLPO;
	if (m_int1>=0) {
		for (int local_08=0; (int)g_pCMainControl->m_DownCondition_.size()>local_08; local_08++) {
			if (g_pCMainControl->mf_CMainControl_0130(local_08)->Get_int_unk21()!=m_int1) continue;
			local_06=g_pCMainControl->mf_CMainControl_0130(local_08);
			g_pCMainControl->mf_CMainControl_0150(local_08);
			break;
		}
	}
	if (m_int2>=0) {
		for (int local_09=0; (int)g_pCMainControl->m_IgnoreCondition_.size()>local_09; local_09++) {
			if (g_pCMainControl->mf_CMainControl_0140(local_09)->Get_int_unk21()!=m_int2) continue;
			local_07=g_pCMainControl->mf_CMainControl_0140(local_09);
			g_pCMainControl->mf_CMainControl_0160(local_09);
			break;
		}
	}

	char * local_10=NULLPO;
	int local_11=HashEdit->Text.Length();
	if (local_11==32) {
		strcpy(local_21,HashEdit->Text.c_str());
		for (int local_12=0; local_12<16; local_12++) {
			int local_13;
			sscanf(&local_21[local_12*2],"%2x",&local_13);
			*(local_20+local_12)=local_13;
		}
		local_10=local_20;
	}

	if ( ((local_10!=0)||(KeywordCombo->Text.Length()>1)) ) {
		CGlobalLock CGLock;
		if (IgnoreCheck->Checked) {
			if (local_07==0) {
				g_pCMainControl->mf_CMainControl_0070(KeywordCombo->Text.c_str(),NULLPO,local_10,(unsigned char *)TripCombo->Text.c_str(),atof(UpperSizeEdit->Text.c_str()),atof(LowerSizeEdit->Text.c_str()),BbsCheck->Checked,AutoDeleteCheck->Checked,DeleteCheck->Checked,DisconnectCheck->Checked);
			} else {
				local_07->m_flg_unk0=true;
				local_07->Set_keyword(KeywordCombo->Text.c_str());
				local_07->Set_Tripstr(TripCombo->Text.c_str());
				char * local_14;
				local_14=local_10;
				if (local_14!=0) {
					memcpy(local_07->m_hash,local_14,16);
				} else {
					memset(local_07->m_hash,0,16);
				}
				local_07->m_flg_unk0=true;
				local_07->Set_UpperSizeLimit(atof(UpperSizeEdit->Text.c_str()));
				local_07->Set_LowerSizeLimit(atof(LowerSizeEdit->Text.c_str()));
				local_07->Set_flag_Bbs(BbsCheck->Checked);
				local_07->Set_flag_AutoDelete(AutoDeleteCheck->Checked);
				local_07->Set_flag_Delete(DeleteCheck->Checked);
				local_07->Set_flag_Disconnect(DisconnectCheck->Checked);
			}
		} else {
			if (local_06==0) {
				g_pCMainControl->mf_CMainControl_0060(KeywordCombo->Text.c_str(),0,(unsigned char *)local_10,(char *)TripCombo->Text.c_str(),atof(UpperSizeEdit->Text.c_str()),atof(LowerSizeEdit->Text.c_str()),BbsCheck->Checked,AutoDeleteCheck->Checked,DeleteCheck->Checked,DisconnectCheck->Checked,false);
			} else {
				local_06->m_flg_unk0=true;
				local_06->Set_keyword(KeywordCombo->Text.c_str());
				local_06->Set_Tripstr(TripCombo->Text.c_str());
				char * local_17;
				local_17=local_10;
				if (local_17!=0) {
					memcpy(local_06->m_hash,local_17,16);
				} else {
					memset(local_06->m_hash,0,16);
				}
				local_06->m_flg_unk0=true;
				local_06->Set_UpperSizeLimit(atof(UpperSizeEdit->Text.c_str()));
				local_06->Set_LowerSizeLimit(atof(LowerSizeEdit->Text.c_str()));
				local_06->Set_flag_Bbs(BbsCheck->Checked);
				local_06->Set_flag_AutoDelete(AutoDeleteCheck->Checked);
				local_06->Set_flag_Delete(DeleteCheck->Checked);
				local_06->Set_flag_Disconnect(DisconnectCheck->Checked);
			}
		}
		sprintf(local_22,"%s%s",g_AppPath,"Ignore.txt");
		g_pCMainControl->mf_CMainControl_0120(local_22);
		sprintf(local_22,"%s%s",g_AppPath,"Download.txt");
		g_pCMainControl->mf_CMainControl_0110(local_22);
		Close();
		m_int1=-1;
		m_int2=-1;
		if (! (IgnoreCheck->Checked||!OptionForm->AutoCopyDownInfoCheck->Checked) ) {
			if (MainForm->TopButton->Down) {
				MainForm->mf_TMainForm_0180(KeywordCombo->Text,false);
			}
			if (MainForm->BottomButton->Down) {
				MainForm->mf_TMainForm_0180(KeywordCombo->Text,true);
			}
		}
		if (IgnoreCheck->Checked) {
			MainForm->mf_TMainForm_0150(pt05);
		} else {
			MainForm->mf_TMainForm_0150(pt04);
		}
	}
	else {
		MessageBox(Handle,"ハッシュか二文字以上のキーワードを指定してください","Winny",0x00042030);
	}
}


void __fastcall TAutoDownForm::IgnoreCheckClick(TObject * Sender)
{
	FormShow(NULLPO);
	return;
}


void __fastcall TAutoDownForm::ClusterButtonClick(TObject * Sender)
{
	LowerSizeEdit->Text=4096;
	HashEdit->Text="";
	HashEdit->Text="";
	LowerSizeEdit->Text="4096";
	BbsCheck->Checked=false;
	AutoDeleteCheck->Checked=false;
	IgnoreCheck->Checked=false;
	DeleteCheck->Checked=false;
	DisconnectCheck->Checked=false;
	return;
}


void __fastcall TAutoDownForm::FormShow(TObject * Sender)
{
	DeleteCheck->Enabled=IgnoreCheck->Checked;
	DisconnectCheck->Enabled=IgnoreCheck->Checked;
	DisconnectLabel->Enabled=IgnoreCheck->Checked;
	return;
}


//---------------------------------------------------------------------------
