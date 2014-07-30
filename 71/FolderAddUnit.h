//---------------------------------------------------------------------------

#ifndef FolderAddUnitH
#define FolderAddUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFolderAddForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TButton *                      OkButton                      ;   //fr    752      4 
	TButton *                      CancelButton                  ;   //fr    756      4 
	TLabel *                       Label1                        ;   //fr    760      4 
	TLabel *                       Label2                        ;   //fr    764      4 
	TLabel *                       Label3                        ;   //fr    768      4 
	TGroupBox *                    GroupBox1                     ;   //fr    772      4 
	TLabel *                       Label4                        ;   //fr    776      4 
	TEdit *                        NameEdit                      ;   //fr    780      4 
	TLabel *                       Label5                        ;   //fr    784      4 
	TEdit *                        PathEdit                      ;   //fr    788      4 
	TLabel *                       Label6                        ;   //fr    792      4 
	TButton *                      ReferButton                   ;   //fr    796      4 
	TComboBox *                    TripCombo                     ;   //fr    800      4 
	void __fastcall CancelButtonClick(TObject * Sender);
	void __fastcall OkButtonClick(TObject * Sender);
	void __fastcall FormHide(TObject * Sender);
	void __fastcall ReferButtonClick(TObject * Sender);
	void __fastcall FormClose(TObject * Sender,TCloseAction & Action);

private:	// ユーザー宣言
public:		// ユーザー宣言
	Bb                             m_flag                        ;   //fr    804      1 

	__fastcall TFolderAddForm(TComponent * Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TFolderAddForm *FolderAddForm;
//---------------------------------------------------------------------------
#endif
