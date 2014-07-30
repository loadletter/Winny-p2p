//---------------------------------------------------------------------------

#ifndef ViewUnitH
#define ViewUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TViewForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TPanel *                       Panel1                        ;   //fr    752      4 
	TStringGrid *                  ViewGrid                      ;   //fr    756      4 
	TButton *                      CancelButton                  ;   //fr    760      4 
	TButton *                      RefreshButton                 ;   //fr    764      4 
	TMemo *                        TitleEdit                     ;   //fr    768      4 
	TButton *                      IgnoreButton                  ;   //fr    772      4 
	void __fastcall CancelButtonClick(TObject * Sender);
	void __fastcall FormResize(TObject * Sender);
	void __fastcall RefreshButtonClick(TObject * Sender);
	void __fastcall FormShow(TObject * Sender);
	void __fastcall FormHide(TObject * Sender);
	void __fastcall IgnoreButtonClick(TObject * Sender);

private:	// ユーザー宣言
public:		// ユーザー宣言
	unsigned char              m_hash[16]                        ;   //fr    776     16 

	__fastcall TViewForm(TComponent * Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TViewForm *ViewForm;
//---------------------------------------------------------------------------
#endif
