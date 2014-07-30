//---------------------------------------------------------------------------
#include "hdrs.h"

#include <vcl.h>
#pragma hdrstop

#include <shlobj.h>

#include "def.h"

#include "MainUnit.h"

#include "FolderAddUnit.h"

#include "def2.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFolderAddForm *FolderAddForm;
//---------------------------------------------------------------------------

__fastcall TFolderAddForm::TFolderAddForm(TComponent * Owner)
        : TForm(Owner)
{
	m_flag=false;
}


void __fastcall TFolderAddForm::CancelButtonClick(TObject * Sender)
{
	Close();
	return;
}


void __fastcall TFolderAddForm::OkButtonClick(TObject * Sender)
{
	char local_04[1024];
	CGlobalLock CGLock;
	g_pCMainControl->mf_CMainControl_0010(NameEdit->Text.c_str(),PathEdit->Text.c_str(),TripCombo->Text.c_str(),0);
	sprintf(local_04,"%s%s",/*(const char *)*/g_AppPath,"UpFolder.txt");
	g_pCMainControl->mf_CMainControl_0050(local_04);
	m_flag=true;
	AnsiString local_00=(TripCombo->Text);
	if (local_00.Length()>0) {
		bool local_02;
		int local_03;
		local_02=false;
		for (local_03=0; TripCombo->Items->Count>local_03; local_03++) {
			AnsiString local_01=(TripCombo->Items->Strings[local_03]);
			if (local_01.AnsiCompare(local_00)==0) {
				local_02=true;
				break;
			}
		}
		if (!local_02) {
			TripCombo->Items->Insert(0,local_00);
		}
		sprintf(local_04,"%s%s",/*(const char *)*/g_AppPath,"TripString.txt");
		try {
			TripCombo->Items->SaveToFile(local_04);
		}
		catch (const EFOpenError & ex_80) {
		}
		MainForm->TabControlChange(MainForm->TabControl);
		MainForm->TabControlChange(MainForm->SubTabControl);
	}
	return;
}


void __fastcall TFolderAddForm::FormHide(TObject * Sender)
{
	if (! (!m_flag||g_pCMainControl->m_flg_unk15510) ) {
		CGlobalLock CGLock;
		g_pCMainControl->mf_CMainControl_0380();
	}
	m_flag=false;
	return;
}


void __fastcall TFolderAddForm::ReferButtonClick(TObject * Sender)
{
	IMalloc * local_00;
	ITEMIDLIST * local_01;
	BROWSEINFO local_02;
	char local_03[260];
	if (SHGetMalloc(&local_00)>=0) {
		local_02.hwndOwner=Handle;
		local_02.pidlRoot=NULLPO;
		local_02.pszDisplayName=NULLPO;
		local_02.lpszTitle="フォルダ選択";
		local_02.ulFlags=1;
		local_02.lpfn=NULLPO;
		local_02.lParam=0;
		local_02.iImage=0;
		local_01=SHBrowseForFolder(&local_02);
		if (local_01!=0) {
			SHGetPathFromIDList(local_01,local_03);
			PathEdit->Text=local_03;
			local_00->Free(local_01);
		}
		local_00->Release();
	}
	return;
}


void __fastcall TFolderAddForm::FormClose(TObject * Sender,TCloseAction & Action)
{
	FolderAddForm->Release();
	FolderAddForm=NULLPO;
	return;
}



//---------------------------------------------------------------------------
