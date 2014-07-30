//---------------------------------------------------------------------------

#ifndef AboutUnitH
#define AboutUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TAboutForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TBitBtn *                      AboutCloseButton              ;   //fr    752      4 
	TImage *                       AboutImage                    ;   //fr    756      4 
	TStaticText *                  VersionText                   ;   //fr    760      4 
	TStaticText *                  CopyrightText                 ;   //fr    764      4 
	void __fastcall AboutCloseButtonClick(TObject * Sender);
	void __fastcall FormClose(TObject * Sender,TCloseAction & Action);

private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TAboutForm(TComponent *Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAboutForm *AboutForm;
//---------------------------------------------------------------------------
#endif
