//---------------------------------------------------------------------------

#ifndef BbsWriteUnitH
#define BbsWriteUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TBbsWriteForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TPanel *                       TopPanel                      ;   //fr    752      4 
	TPanel *                       BottomPanel                   ;   //fr    756      4 
	TButton *                      WriteButton                   ;   //fr    760      4 
	TButton *                      CloseButton                   ;   //fr    764      4 
	TPanel *                       MainPanel                     ;   //fr    768      4 
	TMemo *                        MessageEdit                   ;   //fr    772      4 
	TPanel *                       TitlePanel                    ;   //fr    776      4 
	TLabel *                       TitleLabel                    ;   //fr    780      4 
	TLabel *                       Label1                        ;   //fr    784      4 
	TComboBox *                    NameCombo                     ;   //fr    788      4 
	TLabel *                       Label2                        ;   //fr    792      4 
	TComboBox *                    TripCombo                     ;   //fr    796      4 
	TLabel *                       StateLabel                    ;   //fr    800      4 
	TTimer *                       BbsCheckTimer                 ;   //fr    804      4 
	TTimer *                       CloseTimer                    ;   //fr    808      4 
	void __fastcall WriteButtonClick(TObject * Sender);
	void __fastcall CloseButtonClick(TObject * Sender);
	void __fastcall BbsCheckTimerTimer(TObject * Sender);
	void __fastcall FormHide(TObject * Sender);
	void __fastcall CloseTimerTimer(TObject * Sender);
	void __fastcall FormShow(TObject * Sender);

private:	// ユーザー宣言
public:		// ユーザー宣言
	unsigned char              m_hash[16]                        ;   //fr    812     16
	int                            m_int_notused                 ;   //fr    828      4
	__fastcall TBbsWriteForm(TComponent * Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBbsWriteForm *BbsWriteForm;
//---------------------------------------------------------------------------
#endif
