//---------------------------------------------------------------------------

#ifndef OptionUnitH
#define OptionUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TOptionForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TButton *                      OkButton               ;
	TButton *                      CancelButton           ;
	TPageControl *                 SystemPage             ;
	TTabSheet *                    ComSheet               ;
	TTabSheet *                    FolderSheet            ;
	TLabel *                       Label1                 ;
	TLabel *                       Label2                 ;
	TEdit *                        FilePortEdit           ;
	TLabel *                       Label3                 ;
	TEdit *                        BbsPortEdit            ;
	TCheckBox *                    Port0Check             ;
	TLabel *                       Label6                 ;
	TLabel *                       Label7                 ;
	TEdit *                        CachePathEdit          ;
	TButton *                      CachePathReferButton   ;
	TLabel *                       Label8                 ;
	TEdit *                        BbsPathEdit            ;
	TButton *                      BbsPathReferButton     ;
	TLabel *                       Label9                 ;
	TEdit *                        DownPathEdit           ;
	TButton *                      DownPathReferButton    ;
	TTabSheet *                    DownloadSheet          ;
	TLabel *                       Label4                 ;
	TEdit *                        DdnsEdit               ;
	TTabSheet *                    TaskSheet              ;
	TLabel *                       Label12                ;
	TCheckBox *                    NotConvertCheck        ;
	TComboBox *                    LineSpeedCombo         ;
	TLabel *                       Label5                 ;
	TLabel *                       Label13                ;
	TCheckBox *                    AutoDisconnectCheckBox   ;
	TCheckBox *                    FastDownCheckBox       ;
	TButton *                      InitButton             ;
	TLabel *                       Label10                ;
	TTabSheet *                    BbsSheet               ;
	TFontDialog *                  FontDialog             ;
	TTabSheet *                    FileColorSheet         ;
	TLabel *                       Label17                ;
	TComboBox *                    VirtualKeyCombo        ;
	TTabSheet *                    BbsColorSheet          ;
	TLabel *                       Label15                ;
	TStaticText *                  StaticText7            ;
	TStaticText *                  StaticText10           ;
	TColorBox *                    BbsToolbarColorBox     ;
	TColorBox *                    BbsSearchBarColorBox   ;
	TStaticText *                  StaticText8            ;
	TStaticText *                  StaticText9            ;
	TColorBox *                    BbsToolStringColorBox   ;
	TColorBox *                    BbsSearchStringColorBox   ;
	TLabel *                       Label11                ;
	TStaticText *                  StaticText2            ;
	TStaticText *                  StaticText5            ;
	TColorBox *                    ToolbarColorBox        ;
	TColorBox *                    SearchBarColorBox      ;
	TStaticText *                  StaticText3            ;
	TStaticText *                  StaticText6            ;
	TColorBox *                    ToolStringColorBox     ;
	TColorBox *                    SearchStringColorBox   ;
	TCheckBox *                    CacheVersionCheck      ;
	TLabel *                       Label16                ;
	TCheckBox *                    BbsOnlyCheckBox        ;
	TLabel *                       Label23                ;
	TCheckBox *                    AutoTabChangeCheckBox   ;
	TGroupBox *                    SearchTabGroupBox      ;
	TCheckBox *                    SearchTabUseCheck      ;
	TCheckBox *                    UpperSearchTabCheck    ;
	TCheckBox *                    AlwaysShowSearchTabCheck   ;
	TGroupBox *                    BbsClickGroupBox       ;
	TLabel *                       Label18                ;
	TLabel *                       Label19                ;
	TLabel *                       Label20                ;
	TLabel *                       Label21                ;
	TComboBox *                    ThreadDoubleClickCombo   ;
	TComboBox *                    ThreadClickCombo       ;
	TComboBox *                    TreeDoubleClickCombo   ;
	TComboBox *                    TreeClickCombo         ;
	TComboBox *                    FileTabModeCombo       ;
	TLabel *                       Label24                ;
	TLabel *                       Label25                ;
	TComboBox *                    BoardTabModeCombo      ;
	TLabel *                       Label26                ;
	TComboBox *                    BbsTabModeCombo        ;
	TGroupBox *                    GroupBox1              ;
	TColorBox *                    WindowColorBox         ;
	TButton *                      ListFontButton         ;
	TTrackBar *                    ColorTrackBar          ;
	TButton *                      WhiteColorButton       ;
	TButton *                      BlackColorButton       ;
	TStaticText *                  StaticText1            ;
	TLabel *                       Label14                ;
	TGroupBox *                    GroupBox2              ;
	TStaticText *                  StaticText4            ;
	TColorBox *                    BbsWindowColorBox      ;
	TButton *                      BoardFontButton        ;
	TButton *                      BbsFontButton          ;
	TTrackBar *                    BbsColorTrackBar       ;
	TLabel *                       Label22                ;
	TButton *                      BbsWhiteColorButton    ;
	TButton *                      BbsBlackColorButton    ;
	TLabel *                       Label27                ;
	TComboBox *                    SearchTabModeCombo     ;
	TCheckBox *                    V4CacheNotDownCheck    ;
	TCheckBox *                    FlatToolBarCheck       ;
	TCheckBox *                    TransparentToolBarCheck   ;
	TCheckBox *                    BbsFlatToolBarCheck    ;
	TCheckBox *                    BbsTransparentToolBarCheck   ;
	TStaticText *                  StaticText11           ;
	TColorBox *                    SubStatusColorBox      ;
	TCheckBox *                    AutoCopyDownInfoCheck   ;
	TCheckBox *                    MakeMarkCheck          ;
	TLabel *                       Label28                ;
	TEdit *                        MaxNameLengthEdit      ;
	TCheckBox *                    DownloadIgnoreKeyCheck   ;
	TCheckBox *                    IgnoreSortCheck        ;
	TLabel *                       Label29                ;
	TEdit *                        BbsInterLineSpaceEdit   ;
	TCheckBox *                    KeepSearchHistoryCheck   ;

	void __fastcall CancelButtonClick(TObject * Sender);
	void __fastcall CachePathReferButtonClick(TObject * Sender);
	void __fastcall BbsPathReferButtonClick(TObject * Sender);
	void __fastcall DownPathReferButtonClick(TObject * Sender);
	void __fastcall OkButtonClick(TObject * Sender);
	void __fastcall WindowColorBoxChange(TObject * Sender);
	void __fastcall WhiteColorButtonClick(TObject * Sender);
	void __fastcall BlackColorButtonClick(TObject * Sender);
	void __fastcall ToolbarColorBoxChange(TObject * Sender);
	void __fastcall LineSpeedComboChange(TObject * Sender);
	void __fastcall FilePortEditChange(TObject * Sender);
	void __fastcall BbsPortEditChange(TObject * Sender);
	void __fastcall Port0CheckClick(TObject * Sender);
	void __fastcall DdnsEditChange(TObject * Sender);
	void __fastcall CachePathEditChange(TObject * Sender);
	void __fastcall BbsPathEditChange(TObject * Sender);
	void __fastcall DownPathEditChange(TObject * Sender);
	void __fastcall FormShow(TObject * Sender);
	void __fastcall InitButtonClick(TObject * Sender);
	void __fastcall BbsWindowColorBoxChange(TObject * Sender);
	void __fastcall BbsWhiteColorButtonClick(TObject * Sender);
	void __fastcall BbsBlackColorButtonClick(TObject * Sender);
	void __fastcall ColorTrackBarChange(TObject * Sender);
	void __fastcall ListFontButtonClick(TObject * Sender);
	void __fastcall BoardFontButtonClick(TObject * Sender);
	void __fastcall BbsFontButtonClick(TObject * Sender);
	void __fastcall BbsColorTrackBarChange(TObject * Sender);
	void __fastcall VirtualKeyComboChange(TObject * Sender);
	void __fastcall UpperSearchTabCheckClick(TObject * Sender);
	void __fastcall FileTabModeComboChange(TObject * Sender);
	void __fastcall BoardTabModeComboChange(TObject * Sender);
	void __fastcall BbsTabModeComboChange(TObject * Sender);
	void __fastcall SearchTabModeComboChange(TObject * Sender);
	void __fastcall FlatToolBarCheckClick(TObject * Sender);

private:	// ユーザー宣言
public:		// ユーザー宣言

	Bb                             m_flag                        ;   //fr   1236      1
	
	__fastcall TOptionForm(TComponent * Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TOptionForm *OptionForm;
//---------------------------------------------------------------------------
#endif
