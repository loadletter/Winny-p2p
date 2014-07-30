//---------------------------------------------------------------------------

#ifndef ControlUnitH
#define ControlUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>

#include "md5.h"
#include "miscclass.h"
#include "util.h"

extern int                            g_TControlForm_inifincount   ;				//fr 0055648C 00000004 
extern char                   gbuf10000_211    [65536]       ;				//fr 00556490 00010000 
extern char                   gbuf10010_210    [65552]       ;				//fr 00566490 00010010 
extern char                   gbuf400_001      [1024]        ;				//fr 005764A0 00000400 
extern char                   gbuf400_002      [1024]        ;				//fr 005768A0 00000400 
extern unsigned char                   gbuf400_003      [1024]        ;				//fr 00576CA0 00000400
extern unsigned char                   gbuf7800_200     [30720]       ;				//fr 005770A0 00007800 
extern char                   gbuf400_004      [1024]        ;				//fr 0057E8A0 00000400 
extern char                   gbuf20000_201    [131072]      ;				//fr 0057ECA0 00020000 
extern unsigned char                   gbuf20000_202    [131072]      ;				//fr 0059ECA0 00020000
extern char                   gbuf_131072_unk1 [131072]      ;				//fr 005BECA0 00020000
extern char                   gbuf_1024_unk3   [1024]        ;				//fr 005DECA0 00000400 
extern char                   gbuf_8192_unk2   [8192]        ;				//fr 005DF0A0 00002000 
extern unsigned char              g_exesignature_defined     [16];				//fr 005E10A0 00000010 
extern unsigned char              g_memorysignature_compared [16]  ;				//fr 005E10B0 00000010 
extern char                   gbuf20000_r1          [131072] ;				//fr 005E10C0 00020000 
extern char                   gbuf_sendbuf          [131072] ;				//fr 006010C0 00020000 
extern char                   gbuf1000_memsigwork   [4096]   ;				//fr 006210C0 00001000 
extern char                   gbuf20000_hatena1     [131072] ;				//fr 006220C0 00020000 
extern char                   gbuf_recvbuf          [131072] ;				//fr 006420C0 00020000 
extern char                   gbuf20000_hatena2     [131072] ;				//fr 006620C0 00020000 
extern char                   gbuf20000_hatena3     [131072] ;				//fr 006820C0 00020000 
extern char                   gbuf20000_hatena4     [131072] ;				//fr 006A20C0 00020000 
extern char                   gbuf20000_hatena5     [131072] ;				//fr 006C20C0 00020000 
extern char                   gbuf20000_hatena6     [131072] ;				//fr 006E20C0 00020000 
extern char                   gbuf20000_hatena7     [131072] ;				//fr 007020C0 00020000 
extern char                   gbuf20000_hatena8     [131072] ;				//fr 007220C0 00020000 
extern char                   gbuf40000_1           [262144] ;				//fr 007420C0 00040000 
extern char                   gbuf40000_2           [262144] ;				//fr 007820C0 00040000 
extern char                   gbuf40000_3           [262144] ;				//fr 007C20C0 00040000 
extern char                   gbuf40000_4           [262144] ;				//fr 008020C0 00040000 
extern char                   gbuf20000_hatena01    [131072] ;				//fr 008420C0 00020000 
extern char                   gbuf40000_hatena02    [262144] ;				//fr 008620C0 00040000 
extern char                   gbuf40000_hatena03    [262144] ;				//fr 008A20C0 00040000 
extern char                   gbuf40000_hatena04    [262144] ;				//fr 008E20C0 00040000 
extern char                   gbuf20000_hatena05    [131072] ;				//fr 009220C0 00020000 
extern char                   gbuf20000_hatena06    [131072] ;				//fr 009420C0 00020000 
extern MD5CTX                         g_MD5CTX_1             ;				//fr 009620C0 00000058 
extern MD5CTX                         g_MD5CTX_2             ;				//fr 00962118 00000058 
extern _STL::vector<AnsiString>             g_Log                  ;				//fr 00962170 00000018 
extern AnsiString                     g_AppPath              ;				//fr 00962188 00000004 
extern char                      g_szstr_Version   [256]     ;				//fr 0096218C 00000100 
extern CKeyBlock             g_KeyBlocks[2][1000]           ;				//fr 0096228C 00007D00
extern int                         g_intarray2 [2]           ;				//fr 00969F8C 00000008
extern char         g_listitemarray[2][1010][10][280]        ;				//fr 00969F94 00564DC0 
extern int                   g_nazouintarray  [2][1010]      ;				//fr 00ECED54 00001F90 
extern char                  g_nazocharbuf    [2][2000]      ;				//fr 00ED0CE4 000007D0

//---------------------------------------------------------------------------
class TControlForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TTimer *                       IconCheckTimer                ;   //fr    752      4 
	TPopupMenu *                   SystemMenu                    ;   //fr    756      4 
	TMenuItem *                    Exit                          ;   //fr    760      4 
	TMenuItem *                    Restore                       ;   //fr    764      4 
	TMenuItem *                    N1                            ;   //fr    768      4 
	TMenuItem *                    VersionInfo                   ;   //fr    772      4 
	TTimer *                       MainTimer                     ;   //fr    776      4 
	TLabel *                       CheckLabel                    ;   //fr    780      4 
	void __fastcall FormClick(TObject * Sender);
	void __fastcall IconCheckTimerTimer(TObject * Sender);
	void __fastcall FormClose(TObject * Sender,TCloseAction & Action);
	void __fastcall ExitClick(TObject * Sender);
	void __fastcall RestoreClick(TObject * Sender);
	void __fastcall VersionInfoClick(TObject * Sender);
	void __fastcall FormCreate(TObject * Sender);
	void __fastcall MainTimerTimer(TObject * Sender);

private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TControlForm(TComponent * Owner);
	__fastcall ~TControlForm();

	void __fastcall WndProc(TMessage & Message);

	void mf_TControlForm_0000();
	void mf_TControlForm_0010();
	void __fastcall AppIdle(TObject *Sender,bool &Done);
	void __fastcall AppException(TObject *Sender,Exception *E);

};
//---------------------------------------------------------------------------
extern PACKAGE TControlForm *ControlForm;
//---------------------------------------------------------------------------
#endif
