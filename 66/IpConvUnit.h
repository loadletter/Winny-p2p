//---------------------------------------------------------------------------

#ifndef IpConvUnitH
#define IpConvUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TIpConvForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TLabel *                       Label1                        ;   //fr    752      4 
	TLabel *                       Label2                        ;   //fr    756      4 
	TEdit *                        OriginalEdit                  ;   //fr    760      4 
	TLabel *                       Label3                        ;   //fr    764      4 
	TEdit *                        CryptEdit                     ;   //fr    768      4 
	TLabel *                       Label4                        ;   //fr    772      4 
	TButton *                      Button1                       ;   //fr    776      4 
	TButton *                      Button2                       ;   //fr    780      4 
	void __fastcall Button2Click(TObject * Sender);
	void __fastcall Button1Click(TObject * Sender);
	void __fastcall FormClose(TObject * Sender,TCloseAction & Action);

private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TIpConvForm(TComponent * Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TIpConvForm *IpConvForm;
//---------------------------------------------------------------------------
#endif
