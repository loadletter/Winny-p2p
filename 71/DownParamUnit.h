//---------------------------------------------------------------------------

#ifndef DownParamUnitH
#define DownParamUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TDownParamForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TLabel *                       Label1                        ;   //fr    752      4 
	TLabel *                       Label2                        ;   //fr    756      4 
	TTrackBar *                    SizeBar                       ;   //fr    760      4 
	TLabel *                       Label3                        ;   //fr    764      4 
	TLabel *                       Label4                        ;   //fr    768      4 
	TLabel *                       Label5                        ;   //fr    772      4 
	TTrackBar *                    BlockBar                      ;   //fr    776      4 
	TLabel *                       Label6                        ;   //fr    780      4 
	TLabel *                       Label7                        ;   //fr    784      4 
	TLabel *                       Label8                        ;   //fr    788      4 
	TTrackBar *                    ReferBar                      ;   //fr    792      4 
	TLabel *                       Label9                        ;   //fr    796      4 
	TLabel *                       Label10                       ;   //fr    800      4 
	TLabel *                       Label11                       ;   //fr    804      4 
	TTrackBar *                    TimeBar                       ;   //fr    808      4 
	TLabel *                       Label12                       ;   //fr    812      4 
	TLabel *                       Label13                       ;   //fr    816      4 
	TButton *                      OkButton                      ;   //fr    820      4 
	TButton *                      CancelButton                  ;   //fr    824      4 
	TButton *                      ClearButton                   ;   //fr    828      4 
	void __fastcall CancelButtonClick(TObject * Sender);
	void __fastcall ClearButtonClick(TObject * Sender);
	void __fastcall OkButtonClick(TObject * Sender);
	void __fastcall FormClose(TObject * Sender,TCloseAction & Action);

private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TDownParamForm(TComponent * Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDownParamForm *DownParamForm;
//---------------------------------------------------------------------------
#endif
