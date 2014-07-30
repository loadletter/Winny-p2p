//---------------------------------------------------------------------------

#ifndef NodeAddUnitH
#define NodeAddUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TNodeAddForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TBitBtn *                      OkButton                      ;   //fr    752      4 
	TBitBtn *                      CancelButton                  ;   //fr    756      4 
	TStaticText *                  StaticText1                   ;   //fr    760      4 
	TStaticText *                  StaticText2                   ;   //fr    764      4 
	TEdit *                        NodeEdit                      ;   //fr    768      4 
	TLabel *                       Label1                        ;   //fr    772      4 
	void __fastcall CancelButtonClick(TObject * Sender);
	void __fastcall OkButtonClick(TObject * Sender);
	void __fastcall FormClose(TObject * Sender,TCloseAction & Action);

private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TNodeAddForm(TComponent * Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TNodeAddForm *NodeAddForm;
//---------------------------------------------------------------------------
#endif
