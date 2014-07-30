//---------------------------------------------------------------------------
#include "hdrs.h"

#include <vcl.h>
#pragma hdrstop

#include "def.h"

#include "DownParamUnit.h"
#include "MainUnit.h"

#include "def2.h"
#include "globals.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDownParamForm *DownParamForm;
//---------------------------------------------------------------------------

__fastcall TDownParamForm::TDownParamForm(TComponent * Owner)
        : TForm(Owner)
{
}


void __fastcall TDownParamForm::CancelButtonClick(TObject * Sender)
{
	Close();
	return;
}


void __fastcall TDownParamForm::ClearButtonClick(TObject * Sender)
{
	SizeBar->Position=0;
	BlockBar->Position=0;
	ReferBar->Position=0;
	TimeBar->Position=0;
	return;
}


void __fastcall TDownParamForm::OkButtonClick(TObject * Sender)
{
	char local_00[256];
	CGlobalLock CGLock;
	g_pCMainControl->m_double_optDownParamSize_=(double)SizeBar->Position/100.0;
	g_pCMainControl->m_double_optDownParamBlock_=(double)BlockBar->Position/100.0;
	g_pCMainControl->m_double_optDownParamRef_=(double)ReferBar->Position/100.0;
	g_pCMainControl->m_double_optDownParamTime_=(double)TimeBar->Position/100.0;
	sprintf(local_00,"%g",g_pCMainControl->m_double_optDownParamSize_);
	g_pTIniFile->WriteString("Option","DownParamSize",local_00);
	sprintf(local_00,"%g",g_pCMainControl->m_double_optDownParamBlock_);
	g_pTIniFile->WriteString("Option","DownParamBlock",local_00);
	sprintf(local_00,"%g",g_pCMainControl->m_double_optDownParamTime_);
	g_pTIniFile->WriteString("Option","DownParamTime",local_00);
	sprintf(local_00,"%g",g_pCMainControl->m_double_optDownParamRef_);
	g_pTIniFile->WriteString("Option","DownParamRef",local_00);
	g_pCMainControl->mf_CMainControl_1260();
	MainForm->TabControlChange(MainForm->TabControl);
	MainForm->TabControlChange(MainForm->SubTabControl);
	return;
}


void __fastcall TDownParamForm::FormClose(TObject * Sender,TCloseAction & Action)
{
	DownParamForm->Release();
	DownParamForm=NULLPO;
	return;
}



//---------------------------------------------------------------------------
