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
	TButton *                      OkButton                      ;   //fr    752      4 
	TButton *                      CancelButton                  ;   //fr    756      4 
	TPageControl *                 SystemPage                    ;   //fr    760      4 
	TTabSheet *                    ComSheet                      ;   //fr    764      4 
	TTabSheet *                    FolderSheet                   ;   //fr    768      4 
	TLabel *                       Label1                        ;   //fr    772      4 
	TLabel *                       Label2                        ;   //fr    776      4 
	TEdit *                        FilePortEdit                  ;   //fr    780      4 
	TLabel *                       Label3                        ;   //fr    784      4 
	TEdit *                        BbsPortEdit                   ;   //fr    788      4 
	TCheckBox *                    Port0Check                    ;   //fr    792      4 
	TLabel *                       Label6                        ;   //fr    796      4 
	TLabel *                       Label7                        ;   //fr    800      4 
	TEdit *                        CachePathEdit                 ;   //fr    804      4 
	TButton *                      CachePathReferButton          ;   //fr    808      4 
	TLabel *                       Label8                        ;   //fr    812      4 
	TEdit *                        BbsPathEdit                   ;   //fr    816      4 
	TButton *                      BbsPathReferButton            ;   //fr    820      4 
	TLabel *                       Label9                        ;   //fr    824      4 
	TEdit *                        DownPathEdit                  ;   //fr    828      4 
	TButton *                      DownPathReferButton           ;   //fr    832      4 
	TTabSheet *                    DownloadSheet                 ;   //fr    836      4 
	TLabel *                       Label4                        ;   //fr    840      4 
	TEdit *                        DdnsEdit                      ;   //fr    844      4 
	TTabSheet *                    TaskSheet                     ;   //fr    848      4 
	TLabel *                       Label12                       ;   //fr    852      4 
	TCheckBox *                    NotConvertCheck               ;   //fr    856      4 
	TComboBox *                    LineSpeedCombo                ;   //fr    860      4 
	TLabel *                       Label5                        ;   //fr    864      4 
	TLabel *                       Label13                       ;   //fr    868      4 
	TCheckBox *                    AutoDisconnectCheckBox        ;   //fr    872      4 
	TCheckBox *                    FastDownCheckBox              ;   //fr    876      4 
	TButton *                      InitButton                    ;   //fr    880      4 
	TCheckBox *                    MultiDownCheckBox             ;   //fr    884      4 
	TCheckBox *                    SlowCutCheckBox               ;   //fr    888      4 
	TCheckBox *                    TransLimitCheckBox            ;   //fr    892      4 
	TLabel *                       Label10                       ;   //fr    896      4 
	TTabSheet *                    BbsSheet                      ;   //fr    900      4 
	TFontDialog *                  FontDialog                    ;   //fr    904      4 
	TTabSheet *                    FileColorSheet                ;   //fr    908      4 
	TLabel *                       Label17                       ;   //fr    912      4 
	TComboBox *                    VirtualKeyCombo               ;   //fr    916      4 
	TTabSheet *                    BbsColorSheet                 ;   //fr    920      4 
	TLabel *                       Label15                       ;   //fr    924      4 
	TStaticText *                  StaticText7                   ;   //fr    928      4 
	TStaticText *                  StaticText10                  ;   //fr    932      4 
	TColorBox *                    BbsToolbarColorBox            ;   //fr    936      4 
	TColorBox *                    BbsSearchBarColorBox          ;   //fr    940      4 
	TStaticText *                  StaticText8                   ;   //fr    944      4 
	TStaticText *                  StaticText9                   ;   //fr    948      4 
	TColorBox *                    BbsToolStringColorBox         ;   //fr    952      4 
	TColorBox *                    BbsSearchStringColorBox       ;   //fr    956      4 
	TLabel *                       Label11                       ;   //fr    960      4 
	TStaticText *                  StaticText2                   ;   //fr    964      4 
	TStaticText *                  StaticText5                   ;   //fr    968      4 
	TColorBox *                    ToolbarColorBox               ;   //fr    972      4 
	TColorBox *                    SearchBarColorBox             ;   //fr    976      4 
	TStaticText *                  StaticText3                   ;   //fr    980      4 
	TStaticText *                  StaticText6                   ;   //fr    984      4 
	TColorBox *                    ToolStringColorBox            ;   //fr    988      4 
	TColorBox *                    SearchStringColorBox          ;   //fr    992      4 
	TCheckBox *                    CacheVersionCheck             ;   //fr    996      4 
	TLabel *                       Label16                       ;   //fr   1000      4 
	TCheckBox *                    BbsOnlyCheckBox               ;   //fr   1004      4 
	TLabel *                       Label23                       ;   //fr   1008      4 
	TCheckBox *                    AutoTabChangeCheckBox         ;   //fr   1012      4 
	TGroupBox *                    SearchTabGroupBox             ;   //fr   1016      4 
	TCheckBox *                    SearchTabUseCheck             ;   //fr   1020      4 
	TCheckBox *                    UpperSearchTabCheck           ;   //fr   1024      4 
	TCheckBox *                    AlwaysShowSearchTabCheck      ;   //fr   1028      4 
	TGroupBox *                    BbsClickGroupBox              ;   //fr   1032      4 
	TLabel *                       Label18                       ;   //fr   1036      4 
	TLabel *                       Label19                       ;   //fr   1040      4 
	TLabel *                       Label20                       ;   //fr   1044      4 
	TLabel *                       Label21                       ;   //fr   1048      4 
	TComboBox *                    ThreadDoubleClickCombo        ;   //fr   1052      4 
	TComboBox *                    ThreadClickCombo              ;   //fr   1056      4 
	TComboBox *                    TreeDoubleClickCombo          ;   //fr   1060      4 
	TComboBox *                    TreeClickCombo                ;   //fr   1064      4 
	TComboBox *                    FileTabModeCombo              ;   //fr   1068      4 
	TLabel *                       Label24                       ;   //fr   1072      4 
	TLabel *                       Label25                       ;   //fr   1076      4 
	TComboBox *                    BoardTabModeCombo             ;   //fr   1080      4 
	TLabel *                       Label26                       ;   //fr   1084      4 
	TComboBox *                    BbsTabModeCombo               ;   //fr   1088      4 
	TGroupBox *                    GroupBox1                     ;   //fr   1092      4 
	TColorBox *                    WindowColorBox                ;   //fr   1096      4 
	TButton *                      ListFontButton                ;   //fr   1100      4 
	TTrackBar *                    ColorTrackBar                 ;   //fr   1104      4 
	TButton *                      WhiteColorButton              ;   //fr   1108      4 
	TButton *                      BlackColorButton              ;   //fr   1112      4 
	TStaticText *                  StaticText1                   ;   //fr   1116      4 
	TLabel *                       Label14                       ;   //fr   1120      4 
	TGroupBox *                    GroupBox2                     ;   //fr   1124      4 
	TStaticText *                  StaticText4                   ;   //fr   1128      4 
	TColorBox *                    BbsWindowColorBox             ;   //fr   1132      4 
	TButton *                      BoardFontButton               ;   //fr   1136      4 
	TButton *                      BbsFontButton                 ;   //fr   1140      4 
	TTrackBar *                    BbsColorTrackBar              ;   //fr   1144      4 
	TLabel *                       Label22                       ;   //fr   1148      4 
	TButton *                      BbsWhiteColorButton           ;   //fr   1152      4 
	TButton *                      BbsBlackColorButton           ;   //fr   1156      4 
	TLabel *                       Label27                       ;   //fr   1160      4 
	TComboBox *                    SearchTabModeCombo            ;   //fr   1164      4 
	TCheckBox *                    V4CacheNotDownCheck           ;   //fr   1168      4 
	TCheckBox *                    FlatToolBarCheck              ;   //fr   1172      4 
	TCheckBox *                    TransparentToolBarCheck       ;   //fr   1176      4 
	TCheckBox *                    BbsFlatToolBarCheck           ;   //fr   1180      4 
	TCheckBox *                    BbsTransparentToolBarCheck    ;   //fr   1184      4 
	TGroupBox *                    InitialGroupBox               ;   //fr   1188      4 
	TCheckBox *                    InitialFileViewLeftPaneCheck  ;   //fr   1192      4 
	TCheckBox *                    InitialFileViewTopPaneCheck   ;   //fr   1196      4 
	TCheckBox *                    InitialFileViewBottomPaneCheck;   //fr   1200      4 
	TGroupBox *                    BbsInitialGroupBox            ;   //fr   1204      4 
	TCheckBox *                    InitialBbsViewLeftPaneCheck   ;   //fr   1208      4 
	TCheckBox *                    InitialBbsViewBottomPaneCheck ;   //fr   1212      4 
	TCheckBox *                    InitialBbsViewTopPaneCheck    ;   //fr   1216      4 
	TStaticText *                  StaticText11                  ;   //fr   1220      4 
	TColorBox *                    SubStatusColorBox             ;   //fr   1224      4 
	TCheckBox *                    AutoCopyDownInfoCheck         ;   //fr   1228      4 
	TCheckBox *                    MakeMarkCheck                 ;   //fr   1232      4 

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
