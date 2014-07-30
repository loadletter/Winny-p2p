//---------------------------------------------------------------------------
#include "hdrs.h"

#include <vcl.h>
#pragma hdrstop

#include "def.h"

#include "AboutUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAboutForm *AboutForm;
//---------------------------------------------------------------------------


__fastcall TAboutForm::TAboutForm(TComponent * Owner)
        : TForm(Owner)
{
}


void __fastcall TAboutForm::AboutCloseButtonClick(TObject * Sender)
{
	Close();
}


void __fastcall TAboutForm::FormClose(TObject * Sender,TCloseAction & Action)
{
	AboutForm->Release();
	AboutForm=NULLPO;
	return;
}


//---------------------------------------------------------------------------
