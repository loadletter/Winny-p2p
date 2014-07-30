//---------------------------------------------------------------------------
#include "hdrs.h"

#include <vcl.h>
#pragma hdrstop

#include "def.h"

#include "NodeAddUnit.h"

#include "def2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TNodeAddForm *NodeAddForm;
//---------------------------------------------------------------------------

__fastcall TNodeAddForm::TNodeAddForm(TComponent * Owner)
        : TForm(Owner)
{
}


void __fastcall TNodeAddForm::CancelButtonClick(TObject * Sender)
{
	Close();
	return;
}


void __fastcall TNodeAddForm::OkButtonClick(TObject * Sender)
{
	CGlobalLock CGLock;
	g_pCMainControl->mf_CMainControl_1230(NodeEdit->Text,Caption.Pos("BBS")>0);
	NodeEdit->Text="";
	NodeEdit->SetFocus();
	return;
}


void __fastcall TNodeAddForm::FormClose(TObject * Sender,TCloseAction & Action)
{
	NodeAddForm->Release();
	NodeAddForm=NULLPO;
	return;
}



//---------------------------------------------------------------------------
