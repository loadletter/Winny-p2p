//---------------------------------------------------------------------------

#ifndef MainUnitH
#define MainUnitH
//---------------------------------------------------------------------------
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <CheckLst.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>


#include "RichTextView.hpp"
#include "miscclass.h"


enum enumPageType {
        pt00,pt01,pt02,pt03,pt04,pt05,pt06,pt07,pt08,pt09,pt10
};


//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TTimer *                       Timer                  ;
	TMainMenu *                    MainMenu               ;
	TMenuItem *                    FileMenu               ;
	TMenuItem *                    Exit                   ;
	TPanel *                       LeftPanel              ;
	TSplitter *                    SplitterV              ;
	TMenuItem *                    ViewMenu               ;
	TMenuItem *                    BottomViewEnable       ;
	TMenuItem *                    LeftViewEnable         ;
	TPanel *                       LeftTopPanel           ;
	TTabControl *                  LeftTabControl         ;
	TSpeedButton *                 LeftPanelCloseButton   ;
	TPanel *                       LeftFilePanel          ;
	TPanel *                       LeftBbsPanel           ;
	TLabel *                       TopListBoxLabel        ;
	TCheckListBox *                TopCheckListBox        ;
	TLabel *                       BottomListBoxLabel     ;
	TCheckListBox *                BottomCheckListBox     ;
	TTreeView *                    BbsTree                ;
	TPopupMenu *                   SearchTabMenu          ;
	TMenuItem *                    SearchTabDelete        ;
	TMenuItem *                    HelpMenu               ;
	TMenuItem *                    VersionInfo            ;
	TPanel *                       RightPanel             ;
	TPanel *                       MainPanel              ;
	TSplitter *                    SplitterH              ;
	TPanel *                       TopPanel               ;
	TPanel *                       TopTopPanel            ;
	TPanel *                       BottomPanel            ;
	TPanel *                       BottomTopPanel         ;
	TMenuItem *                    StatusPanelEnable      ;
	TPopupMenu *                   TabMenu                ;
	TMenuItem *                    TabClose               ;
	TPopupMenu *                   SubTabMenu             ;
	TMenuItem *                    SubTabClose            ;
	TStatusBar *                   TransStatusBar         ;
	TStatusBar *                   StatusBar              ;
	TPopupMenu *                   FolderPopupMenu        ;
	TMenuItem *                    OpenFolder             ;
	TMenuItem *                    RemoveFolder           ;
	TPopupMenu *                   FilePopupMenu          ;
	TMenuItem *                    AddDownLoad            ;
	TMenuItem *                    EditDownList           ;
	TMenuItem *                    DownLoad               ;
	TMenuItem *                    RemoveDownList         ;
	TMenuItem *                    N1                     ;
	TMenuItem *                    ViewBlock              ;
	TMenuItem *                    Convert                ;
	TMenuItem *                    N2                     ;
	TMenuItem *                    GetFileInfo            ;
	TMenuItem *                    GetFileHash            ;
	TMenuItem *                    GetFileTrip            ;
	TMenuItem *                    GetFileName            ;
	TPopupMenu *                   DownPopupMenu          ;
	TMenuItem *                    EditDown               ;
	TMenuItem *                    ViewDownBlock          ;
	TMenuItem *                    N7                     ;
	TMenuItem *                    TaskSkip               ;
	TMenuItem *                    TaskConvert            ;
	TMenuItem *                    DeleteDownList         ;
	TPopupMenu *                   IgnorePopupMenu        ;
	TMenuItem *                    EditIgnore             ;
	TMenuItem *                    DeleteIgnoreList       ;
	TPopupMenu *                   TaskPopupMenu          ;
	TMenuItem *                    ViewWork               ;
	TMenuItem *                    EditWork               ;
	TMenuItem *                    N8                     ;
	TMenuItem *                    ConvertWork            ;
	TMenuItem *                    ClearTask              ;
	TPopupMenu *                   SystemPopupMenu        ;
	TMenuItem *                    LogCopy                ;
	TPopupMenu *                   SubFolderPopupMenu     ;
	TMenuItem *                    SubOpenFolder          ;
	TMenuItem *                    SubRemoveFolder        ;
	TPopupMenu *                   SubFilePopupMenu       ;
	TMenuItem *                    SubAddDownLoad         ;
	TMenuItem *                    SubEditDownList        ;
	TMenuItem *                    SubDownLoad            ;
	TMenuItem *                    SubRemoveDownList      ;
	TMenuItem *                    MenuItem7              ;
	TMenuItem *                    SubViewBlock           ;
	TMenuItem *                    SubConvert             ;
	TMenuItem *                    MenuItem10             ;
	TMenuItem *                    SubGetFileName         ;
	TMenuItem *                    SubGetTripName         ;
	TMenuItem *                    SubGetHashName         ;
	TMenuItem *                    SubGetFileInfo         ;
	TPopupMenu *                   SubDownPopupMenu       ;
	TMenuItem *                    SubEditDown            ;
	TMenuItem *                    SubViewDownBlock       ;
	TMenuItem *                    MenuItem17             ;
	TMenuItem *                    SubTaskConvert         ;
	TMenuItem *                    SubTaskSkip            ;
	TMenuItem *                    SubDeleteDownList      ;
	TPopupMenu *                   SubIgnorePopupMenu     ;
	TMenuItem *                    SubEditIgnore          ;
	TMenuItem *                    SubDeleteIgnoreList    ;
	TPopupMenu *                   SubTaskPopupMenu       ;
	TMenuItem *                    SubViewWork            ;
	TMenuItem *                    SubEditWork            ;
	TMenuItem *                    MenuItem25             ;
	TMenuItem *                    SubConvertWork         ;
	TMenuItem *                    SubClearTask           ;
	TPopupMenu *                   SubSystemPopupMenu     ;
	TMenuItem *                    SubLogCopy             ;
	TPanel *                       BbsToolBar             ;
	TImageList *                   BbsTreeImageList       ;
	TTimer *                       BoardCheckTimer        ;
	TPopupMenu *                   BbsTreeMenu            ;
	TMenuItem *                    RemoveTreeItem         ;
	TMenuItem *                    AddDefault             ;
	TMenuItem *                    BoardOpen              ;
	TMenuItem *                    BoardNewOpen           ;
	TMenuItem *                    N3                     ;
	TTimer *                       BbsTreeClickTimer      ;
	TTimer *                       UpQueryTimer           ;
	TTimer *                       DownQueryTimer         ;
	TPopupMenu *                   BoardTabMenu           ;
	TMenuItem *                    BoardTabClose          ;
	TPopupMenu *                   BoardMenu              ;
	TMenuItem *                    BbsOpen                ;
	TMenuItem *                    NewBbsOpen             ;
	TTimer *                       OpenBbsTimer           ;
	TListView *                    NodeView               ;
	TListView *                    FolderView             ;
	TListView *                    FileView               ;
	TListView *                    DownView               ;
	TListView *                    IgnoreView             ;
	TListView *                    LogView                ;
	TListView *                    TaskView               ;
	TListView *                    BbsBoardView           ;
	TListView *                    SystemView             ;
	TListView *                    SubNodeView            ;
	TListView *                    SubFolderView          ;
	TListView *                    SubFileView            ;
	TListView *                    SubDownView            ;
	TListView *                    SubIgnoreView          ;
	TListView *                    SubLogView             ;
	TListView *                    SubTaskView            ;
	TListView *                    SubSystemView          ;
	TMenuItem *                    N4                     ;
	TMenuItem *                    BbsGetFileName         ;
	TMenuItem *                    BbsGetTrip             ;
	TMenuItem *                    BbsGetFileHash         ;
	TMenuItem *                    BbsGetFileData         ;
	TMenuItem *                    SearchTabRightDelete   ;
	TMenuItem *                    SearchTabLeftDelete    ;
	TMenuItem *                    AllSearchTabDelete     ;
	TPopupMenu *                   SubSearchTabMenu       ;
	TMenuItem *                    SubSearchTabDelete     ;
	TMenuItem *                    SubSearchTabRightDelete;
	TMenuItem *                    SubSearchTabLeftDelete ;
	TMenuItem *                    SubSearchTabAllDelete  ;
	TLabel *                       BbsStatusLabel         ;
	TLabel *                       BbsTitleLabel          ;
	TPanel *                       TopTabPanel            ;
	TTabControl *                  TabControl             ;
	TTabControl *                  BoardTabControl        ;
	TPanel *                       BottomTabPanel         ;
	TTabControl *                  SubTabControl          ;
	TTabControl *                  BbsTabControl          ;
	TPanel *                       SubClosePanel          ;
	TSpeedButton *                 SubClosePanelButton    ;
	TPopupMenu *                   BbsMenu                ;
	TMenuItem *                    BbsCopy                ;
	TTimer *                       ReloadBoardTimer       ;
	TMenuItem *                    OpenWinnyWebSite       ;
	TPanel *                       Panel1                 ;
	TSpeedButton *                 BbsCloseButton         ;
	TSpeedButton *                 BbsWriteButton         ;
	TSpeedButton *                 BbsRefreshButton       ;
	TPopupMenu *                   BbsTabMenu             ;
	TMenuItem *                    BbsClose               ;
	TMenuItem *                    AllBbsTabClose         ;
	TMenuItem *                    AllBoardTabClose       ;
	TMenuItem *                    N5                     ;
	TMenuItem *                    BbsOpenWeb             ;
	TPanel *                       BoardToolBar           ;
	TSpeedButton *                 BbsSetupButton         ;
	TSpeedButton *                 MakeBbsButton          ;
	TSpeedButton *                 RefreshBoardButton     ;
	TSpeedButton *                 BbsViewCache           ;
	TSpeedButton *                 BbsBrowserButton       ;
	TSpeedButton *                 BbsPortScanButton2     ;
	TSpeedButton *                 CacheClearButton2      ;
	TRichTextView *                BbsView                ;
	TMenuItem *                    FileIgnore             ;
	TMenuItem *                    SubFileIgnore          ;
	TMenuItem *                    N6                     ;
	TMenuItem *                    N9                     ;
	TMenuItem *                    N10                    ;
	TMenuItem *                    CopyDownToSearchTab    ;
	TMenuItem *                    N11                    ;
	TMenuItem *                    SubCopyDownToSearchTab ;
	TMenuItem *                    ClearCopyDownToSearchTab;
	TMenuItem *                    SubClearCopyDownToSearchTab;
	TMenuItem *                    TaskAddIgnore          ;
	TMenuItem *                    SubTaskAddIgnore       ;
	TPanel *                       TopToolBar             ;
	TSpeedButton *                 SetupButton            ;
	TSpeedButton *                 TopToolButton1         ;
	TSpeedButton *                 TopToolButton2         ;
	TSpeedButton *                 TopToolButton3         ;
	TSpeedButton *                 TopToolButton4         ;
	TSpeedButton *                 TopToolButton5         ;
	TSpeedButton *                 TopToolButton6         ;
	TPanel *                       BottomToolBar          ;
	TSpeedButton *                 SubSetupButton         ;
	TSpeedButton *                 BottomToolButton1      ;
	TSpeedButton *                 BottomToolButton2      ;
	TSpeedButton *                 BottomToolButton3      ;
	TSpeedButton *                 BottomToolButton4      ;
	TSpeedButton *                 BottomToolButton5      ;
	TSpeedButton *                 BottomToolButton6      ;
	TPanel *                       ToolPanel              ;
	TPanel *                       SearchPanel            ;
	TLabel *                       TripLabel              ;
	TLabel *                       SearchLabel            ;
	TLabel *                       HitLabel               ;
	TComboBox *                    SearchComboBox         ;
	TComboBox *                    TripComboBox           ;
	TButton *                      SearchButton           ;
	TButton *                      SubSearchButton        ;
	TPanel *                       BbsSearchPanel         ;
	TLabel *                       BbsSearchLabel         ;
	TLabel *                       BbsHitLabel            ;
	TLabel *                       BbsClusterLabel        ;
	TComboBox *                    BbsSearchComboBox      ;
	TButton *                      BbsSearchButton        ;
	TPanel *                       TopRightPanel          ;
	TSpeedButton *                 BbsButton              ;
	TSpeedButton *                 LeftButton             ;
	TSpeedButton *                 BottomButton           ;
	TPanel *                       ClosePanel             ;
	TSpeedButton *                 ClosePaneButton        ;
	TSpeedButton *                 TopButton              ;
	TMenuItem *                    TopViewEnable          ;
	TPanel *                       StatusPanel            ;
	TLabel *                       UpStatusLabel          ;
	TLabel *                       DownStatusLabel        ;
	TMenuItem *                    SubStatusPanelEnable   ;
	TPanel *                       SubStatusPanel         ;
	TLabel *                       SubUpStatusLabel       ;
	TLabel *                       SubDownStatusLabel     ;
	TTabControl *                  SearchTabControl       ;
	TTabControl *                  SubSearchTabControl    ;
	TPopupMenu *                   SearchComboMenu        ;
	TMenuItem *                    ClearSearchHistory     ;
	TMenuItem *                    EditSearchHistroy      ;
	TMenuItem *                    ReloadSearchHistory    ;
	TMenuItem *                    N12                    ;
	TMenuItem *                    ClearTripHistory       ;
	TMenuItem *                    EditTab                ;
	TMenuItem *                    ReloadTab              ;
	TMenuItem *                    N13                    ;
	TMenuItem *                    SubEditTab             ;
	TMenuItem *                    SubReloadTab           ;
	TMenuItem *                    N14                    ;
	TMenuItem *                    N15                    ;
	TMenuItem *                    SearchHistoryMenu      ;
	TMenuItem *                    C1                     ;
	TMenuItem *                    N16                    ;
	TMenuItem *                    E1                     ;
	TMenuItem *                    R1                     ;
	TMenuItem *                    N17                    ;
	TMenuItem *                    T1                     ;
	TPopupMenu *                   ModeTabMenu            ;
	TMenuItem *                    NodeMode               ;
	TMenuItem *                    BbsNodeMode            ;
	TMenuItem *                    FolderMode             ;
	TMenuItem *                    FileMode               ;
	TMenuItem *                    DownMode               ;
	TMenuItem *                    IgnoreMode             ;
	TMenuItem *                    TaskMode               ;
	TMenuItem *                    LogMode                ;
	TMenuItem *                    SystemMode             ;
	TPopupMenu *                   SubModeTabMenu         ;
	TMenuItem *                    SubNodeMode            ;
	TMenuItem *                    SubBbsNodeMode         ;
	TMenuItem *                    SubFolderMode          ;
	TMenuItem *                    SubFileMode            ;
	TMenuItem *                    SubDownMode            ;
	TMenuItem *                    SubIgnoreMode          ;
	TMenuItem *                    SubTaskMode            ;
	TMenuItem *                    SubLogMode             ;
	TMenuItem *                    SubSystemMode          ;
	TMenuItem *                    FileCut                ;
	TMenuItem *                    SubFileCut             ;
	TImageList *                   ItemImageList          ;
	TTimer *                       BoardRefreshTimer      ;

	void __fastcall TimerTimer(TObject * Sender);
	void __fastcall TabControlChange(TObject * Sender)                ;
	void __fastcall TopCheckListBoxClick(TObject * Sender)             ;
	void __fastcall LeftButtonClick(TObject * Sender)                    ;
	void __fastcall BottomButtonClick(TObject * Sender)                    ;
	void __fastcall BottomCheckListBoxClick(TObject * Sender)           ;
	void __fastcall SearchButtonClick(TObject * Sender)                     ;
	void __fastcall SearchTabControlChange(TObject * Sender)                 ;
	void __fastcall SubSearchTabControlChange(TObject * Sender)               ;
	void __fastcall FormClose(TObject * Sender,TCloseAction & Action);
	void __fastcall LeftViewEnableClick(TObject * Sender);
	void __fastcall BottomViewEnableClick(TObject * Sender);
	void __fastcall LeftTabControlChange(TObject * Sender)      ;
	void __fastcall LeftPanelCloseButtonClick(TObject * Sender)  ;
	void __fastcall SubClosePanelButtonClick(TObject * Sender)     ;
	void __fastcall ExitClick(TObject * Sender)                     ;
	void __fastcall SearchTabControlMouseDown(TObject * Sender,TMouseButton Button,TShiftState Shift,int X,int Y);
	void __fastcall SubSearchTabControlMouseDown(TObject * Sender,TMouseButton Button,TShiftState Shift,int X,int Y);
	void __fastcall SearchTabDeleteClick(TObject * Sender);
	void __fastcall VersionInfoClick(TObject * Sender)               ;
	void __fastcall StatusPanelEnableClick(TObject * Sender);
	void __fastcall TabCloseClick(TObject * Sender)                   ;
	void __fastcall SubTabControlMouseDown(TObject * Sender,TMouseButton Button,TShiftState Shift,int X,int Y);
	void __fastcall TabControlMouseDown(TObject * Sender,TMouseButton Button,TShiftState Shift,int X,int Y)   ;
	void __fastcall SubTabCloseClick(TObject * Sender)                 ;
	void __fastcall NodeDisconnectButtonClick();
	void __fastcall NodeSearchDisconnectButtonClick();
	void __fastcall NodeConnectButtonClick();
	void __fastcall NodeAutoDisconnectButtonClick(int arg_0);
	void __fastcall BbsNodeDisconnectButtonClick();
	void __fastcall BbsPortScanButtonClick();
	void __fastcall FolderRefreshButtonClick();
	void __fastcall DownFolderOpenButtonClick();
	void __fastcall SearchUpFolderButtonClick();
	void __fastcall SearchCacheFolderButtonClick();
	void __fastcall SearchTmpCacheButtonClick();
	void __fastcall DownEditButtonClick();
	void __fastcall DownReloadButtonClick();
	void __fastcall IgnoreEditButtonClick();
	void __fastcall IgnoreReloadButtonClick();
	void __fastcall IgnoreSearchButtonClick();
	void __fastcall TaskClearButtonClick(bool arg_0);
	void __fastcall LogClearButtonClick();
	void __fastcall BbsButtonClick(TObject * Sender);
	void __fastcall DownAddButtonClick();
	void __fastcall IgnoreAddButtonClick();
	void __fastcall DownDeleteButtonClick(TObject * Sender);
	void __fastcall IgnoreDeleteButtonClick(TObject * Sender);
	void __fastcall FolderDeleteButtonClick(TObject * Sender);
	void __fastcall UpFolderOpenButtonClick(TObject * Sender);
	void __fastcall TaskDeleteButtonClick(TObject * Sender);
	void __fastcall NodeAddButtonClick();
	void __fastcall BbsNodeAddButtonClick();
	void __fastcall FolderAddButtonClick();
	void __fastcall SearchPriorButtonClick();
	void __fastcall IpConvButtonClick();
	void __fastcall SystemOptionButtonClick(TObject * Sender);
	void __fastcall AddDownLoadClick(TObject * Sender);
	void __fastcall EditDownListClick(TObject * Sender);
	void __fastcall DownLoadClick(TObject * Sender);
	void __fastcall RemoveDownListClick(TObject * Sender);
	void __fastcall ConvertClick(TObject * Sender);
	void __fastcall GetFileNameClick(TObject * Sender);
	void __fastcall GetFileTripClick(TObject * Sender);
	void __fastcall GetFileHashClick(TObject * Sender);
	void __fastcall GetFileInfoClick(TObject * Sender);
	void __fastcall EditDownClick(TObject * Sender);
	void __fastcall EditIgnoreClick(TObject * Sender);
	void __fastcall TaskConvertClick(TObject * Sender);
	void __fastcall TaskSkipClick(TObject * Sender);
	void __fastcall EditWorkClick(TObject * Sender);
	void __fastcall ConvertWorkClick(TObject * Sender);
	void __fastcall LogCopyClick(TObject * Sender);
	void __fastcall ViewBlockClick(TObject * Sender);
	void __fastcall ViewDownBlockClick(TObject * Sender);
	void __fastcall ViewWorkClick(TObject * Sender);
	void __fastcall NodeViewDblClick(TObject * Sender);
	void __fastcall BoardCheckTimerTimer(TObject * Sender);
	void __fastcall RemoveTreeItemClick(TObject * Sender);
	void __fastcall BbsTreeDragDrop(TObject * Sender,TObject * Source,int X,int Y);
	void __fastcall BbsTreeDragOver(TObject * Sender,TObject * Source,int X,int Y,TDragState State,bool & Accept);
	void __fastcall SplitterHMoved(TObject * Sender);
	void __fastcall AddDefaultClick(TObject * Sender);
	void __fastcall BbsTreeClick(TObject * Sender);
	void __fastcall BbsTreeDblClick(TObject * Sender);
	void __fastcall BoardOpenClick(TObject * Sender);
	void __fastcall BoardNewOpenClick(TObject * Sender);
	void __fastcall BbsTreeClickTimerTimer(TObject * Sender);
	void __fastcall BbsTreeMenuPopup(TObject * Sender);
	void __fastcall UpQueryTimerTimer(TObject * Sender);
	void __fastcall DownQueryTimerTimer(TObject * Sender);
	void __fastcall BbsSearchButtonClick(TObject * Sender);
	void __fastcall RefreshBoardButtonClick(TObject * Sender);
	void __fastcall MakeBbsButtonClick(TObject * Sender);
	void __fastcall BoardTabControlMouseDown(TObject * Sender,TMouseButton Button,TShiftState Shift,int X,int Y);
	void __fastcall BoardTabCloseClick(TObject * Sender);
	void __fastcall BbsOpenClick(TObject * Sender);
	void __fastcall NewBbsOpenClick(TObject * Sender);
	void __fastcall OpenBbsTimerTimer(TObject * Sender);
	void __fastcall FormShow(TObject * Sender);
	void __fastcall FormHide(TObject * Sender);
	void __fastcall NodeToolBarClick(int arg_0);
	void __fastcall NodeBbsToolBarClick(int arg_0);
	void __fastcall FolderToolBarClick(int arg_0);
	void __fastcall FileToolBarClick(int arg_0)   ;
	void __fastcall DownToolBarClick(int arg_0)    ;
	void __fastcall IgnoreToolBarClick(int arg_0);
	void __fastcall TaskToolBarClick(int arg_0);
	void __fastcall LogToolBarClick(int arg_0);
	void __fastcall BoardToolBarClick(TObject * Sender);
	void __fastcall SystemToolBarClick(TObject * Sender);
	void __fastcall BbsBoardViewMouseDown(TObject * Sender,TMouseButton Button,TShiftState Shift,int X,int Y);
	void __fastcall NodeViewColumnClick(TObject * Sender,TListColumn * Column);
	void __fastcall SubNodeToolBarClick(int arg_0);
	void __fastcall SubNodeBbsToolBarClick(int arg_0);
	void __fastcall SubFolderToolBarClick(int arg_0);
	void __fastcall SubFileToolBarClick(int arg_0);
	void __fastcall SubDownToolBarClick(int arg_0);
	void __fastcall SubIgnoreToolBarClick(int arg_0);
	void __fastcall SubTaskToolBarClick(int arg_0);
	void __fastcall SubLogToolBarClick(int arg_0);
	void __fastcall SubSystemToolBarClick(int arg_0);
	void __fastcall SearchComboBoxChange(TObject * Sender);
	void __fastcall TripComboBoxChange(TObject * Sender);
	void __fastcall BbsSearchComboBoxChange(TObject * Sender);
	void __fastcall SearchTabRightDeleteClick(TObject * Sender);
	void __fastcall SearchTabLeftDeleteClick(TObject * Sender);
	void __fastcall AllSearchTabDeleteClick(TObject * Sender);
	void __fastcall BbsTabControlChange(TObject * Sender);
	void __fastcall CacheClearButtonClick();
	void __fastcall BbsViewMouseMove(TObject * Sender,TShiftState Shift,int X,int Y);
	void __fastcall BbsCopyClick(TObject * Sender);
	void __fastcall ReloadBoardTimerTimer(TObject * Sender);
	void __fastcall OpenWinnyWebSiteClick(TObject * Sender);
	void __fastcall BbsWriteButtonClick(TObject * Sender);
	void __fastcall BbsCloseClick(TObject * Sender);
	void __fastcall AllBbsTabCloseClick(TObject * Sender);
	void __fastcall AllBoardTabCloseClick(TObject * Sender);
	void __fastcall BbsTabControlMouseDown(TObject * Sender,TMouseButton Button,TShiftState Shift,int X,int Y);
	void __fastcall BbsOpenWebClick(TObject * Sender);
	void __fastcall BbsTabControlChanging(TObject * Sender,bool & AllowChange);
	void __fastcall BbsRefreshButtonClick(TObject * Sender);
	void __fastcall BbsViewCacheClick(TObject * Sender);
	void __fastcall NodeViewColumnDragged(TObject * Sender);
	void __fastcall WndProc(TMessage & Message);
	void __fastcall FileViewAdvancedCustomDrawItem(TCustomListView * Sender,TListItem * Item,TCustomDrawState State,TCustomDrawStage Stage,bool & DefaultDraw);
	void __fastcall ConvertWaitButtonClick();
	void __fastcall BbsBoardViewAdvancedCustomDraw(TCustomListView * Sender,const TRect & ARect,TCustomDrawStage Stage,bool & DefaultDraw);
	void __fastcall CopyDownToSearchTabClick(TObject * Sender);
	void __fastcall ClearCopyDownToSearchTabClick(TObject * Sender);
	void __fastcall TaskAddIgnoreClick(TObject * Sender);
	void __fastcall TopToolButton1Click(TObject * Sender);
	void __fastcall TopToolButton2Click(TObject * Sender);
	void __fastcall TopToolButton3Click(TObject * Sender);
	void __fastcall TopToolButton4Click(TObject * Sender);
	void __fastcall TopToolButton5Click(TObject * Sender);
	void __fastcall TopToolButton6Click(TObject * Sender);
	void __fastcall BottomToolButton1Click(TObject * Sender);
	void __fastcall BottomToolButton2Click(TObject * Sender);
	void __fastcall BottomToolButton3Click(TObject * Sender);
	void __fastcall BottomToolButton4Click(TObject * Sender);
	void __fastcall BottomToolButton5Click(TObject * Sender);
	void __fastcall BottomToolButton6Click(TObject * Sender);
	void __fastcall TopButtonClick(TObject * Sender)                      ;
	void __fastcall ClosePaneButtonClick(TObject * Sender)        ;
	void __fastcall TopViewEnableClick(TObject * Sender)  ;
	void __fastcall BbsTreeMouseDown(TObject * Sender,TMouseButton Button,TShiftState Shift,int X,int Y);
	void __fastcall BbsBrowserButtonClick(TObject * Sender);
	void __fastcall CacheClearButton2Click(TObject * Sender);
	void __fastcall BbsPortScanButton2Click(TObject * Sender);
	void __fastcall BbsViewMouseDown(TObject * Sender,TMouseButton Button,TShiftState Shift,int X,int Y);
	void __fastcall SubStatusPanelEnableClick(TObject * Sender);
	void __fastcall SearchTabModeButtonClick(int arg_0);
	void __fastcall ReloadSearchHistoryClick(TObject * Sender);
	void __fastcall ClearSearchHistoryClick(TObject * Sender);
	void __fastcall EditSearchHistroyClick(TObject * Sender);
	void __fastcall ClearTripHistoryClick(TObject * Sender);
	void __fastcall EditTabClick(TObject * Sender);
	void __fastcall ReloadTabClick(TObject * Sender);
	void __fastcall NodeModeClick(TObject * Sender);
	void __fastcall BbsNodeModeClick(TObject * Sender);
	void __fastcall FolderModeClick(TObject * Sender);
	void __fastcall FileModeClick(TObject * Sender);
	void __fastcall DownModeClick(TObject * Sender);
	void __fastcall IgnoreModeClick(TObject * Sender);
	void __fastcall TaskModeClick(TObject * Sender);
	void __fastcall LogModeClick(TObject * Sender);
	void __fastcall SystemModeClick(TObject * Sender);
	void __fastcall SubNodeModeClick(TObject * Sender);
	void __fastcall SubBbsNodeModeClick(TObject * Sender);
	void __fastcall SubFolderModeClick(TObject * Sender);
	void __fastcall SubFileModeClick(TObject * Sender);
	void __fastcall SubDownModeClick(TObject * Sender);
	void __fastcall SubIgnoreModeClick(TObject * Sender);
	void __fastcall SubTaskModeClick(TObject * Sender);
	void __fastcall SubLogModeClick(TObject * Sender);
	void __fastcall SubSystemModeClick(TObject * Sender);
	void __fastcall FileIgnoreClick(TObject * Sender);
	void __fastcall BoardRefreshTimerTimer(TObject * Sender);

private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TMainForm(TComponent* Owner);

	TColor                         m_color01                     ;   //fr   1788      4
	TColor                         m_color02                     ;   //fr   1792      4
	TColor                         m_color03                     ;   //fr   1796      4
	TColor                         m_color04                     ;   //fr   1800      4
	TColor                         m_color05                     ;   //fr   1804      4
	TColor                         m_color06                     ;   //fr   1808      4
	TColor                         m_color07                     ;   //fr   1812      4
	TColor                         m_color08                     ;   //fr   1816      4
	TColor                         m_color09                     ;   //fr   1820      4
	TColor                         m_color10                     ;   //fr   1824      4
	TColor                         m_color11                     ;   //fr   1828      4
	TColor                         m_color12                     ;   //fr   1832      4
	TColor                         m_color13                     ;   //fr   1836      4
	TColor                         m_color14                     ;   //fr   1840      4
	TColor                         m_color15                     ;   //fr   1844      4
	TColor                         m_color16                     ;   //fr   1848      4
	TColor                         m_color17                     ;   //fr   1852      4
	TColor                         m_color18                     ;   //fr   1856      4
	TColor                         m_color19                     ;   //fr   1860      4
	TColor                         m_color20                     ;   //fr   1864      4
	TColor                         m_color21                     ;   //fr   1868      4
	TColor                         m_color22                     ;   //fr   1872      4
	TColor                         m_color23                     ;   //fr   1876      4
	TColor                         m_color24                     ;   //fr   1880      4
	TColor                         m_color25                     ;   //fr   1884      4
	TColor                         m_color26                     ;   //fr   1888      4
	TColor                         m_color27                     ;   //fr   1892      4
	TColor                         m_color28                     ;   //fr   1896      4
	int                        m_intarray_unk_ [20]              ;   //fr   1900     80
	AnsiString                     m__unknown_000                ;   //fr   1980      4
	AnsiString                     m__unknown_001                ;   //fr   1984      4
	int pad;
	vector<TBbsTab>                m__unknown_002                ;   //fr   1992     24
	enumPageType                           m_char_upperPageType_         ;   //fr   2016      1
	enumPageType                           m_char_lowerPageType_         ;   //fr   2017      1
//	int pad;
	char	m_notused[1024];


	__fastcall ~TMainForm();
	void mf_TMainForm_0000();
	void mf_TMainForm_0010();
	void mf_TMainForm_0015();
	void mf_TMainForm_0020(xint arg_0);
	void mf_TMainForm_0030(xint arg_0);
	void mf_TMainForm_0040();
	void mf_TMainForm_0050();
	sl mf_TMainForm_0060();
	sl mf_TMainForm_0070();
	void mf_TMainForm_0080();
	void mf_TMainForm_0090();
	Bb mf_TMainForm_0100(char arg_0);
	Bb mf_TMainForm_0110(char arg_0);
	void mf_TMainForm_0120();
	void mf_TMainForm_0130();
	void mf_TMainForm_0140();
	void mf_TMainForm_0150(enumPageType arg_0);
	void mf_TMainForm_0160();
	void mf_TMainForm_0170() ;
	void mf_TMainForm_0180(/*const*/ AnsiString & arg_0,bool arg_1);
	void mf_TMainForm_0190();
	void mf_TMainForm_0200();
	void mf_TMainForm_0210(int arg_0,TCanvas * arg_1,TRect * arg_2);
	void mf_TMainForm_0220();


};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
