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
	TTimer *                       Timer                         ;   //fr    752      4 
	TMainMenu *                    MainMenu                      ;   //fr    756      4 
	TMenuItem *                    FileMenu                      ;   //fr    760      4 
	TMenuItem *                    Exit                          ;   //fr    764      4 
	TPanel *                       LeftPanel                     ;   //fr    768      4 
	TSplitter *                    SplitterV                     ;   //fr    772      4 
	TMenuItem *                    ViewMenu                      ;   //fr    776      4 
	TMenuItem *                    BottomViewEnable              ;   //fr    780      4 
	TMenuItem *                    LeftViewEnable                ;   //fr    784      4 
	TPanel *                       LeftTopPanel                  ;   //fr    788      4 
	TTabControl *                  LeftTabControl                ;   //fr    792      4 
	TSpeedButton *                 LeftPanelCloseButton          ;   //fr    796      4 
	TPanel *                       LeftFilePanel                 ;   //fr    800      4 
	TPanel *                       LeftBbsPanel                  ;   //fr    804      4 
	TLabel *                       TopListBoxLabel               ;   //fr    808      4 
	TCheckListBox *                TopCheckListBox               ;   //fr    812      4 
	TLabel *                       BottomListBoxLabel            ;   //fr    816      4 
	TCheckListBox *                BottomCheckListBox            ;   //fr    820      4 
	TTreeView *                    BbsTree                       ;   //fr    824      4 
	TPopupMenu *                   SearchTabMenu                 ;   //fr    828      4 
	TMenuItem *                    SearchTabDelete               ;   //fr    832      4 
	TMenuItem *                    HelpMenu                      ;   //fr    836      4 
	TMenuItem *                    VersionInfo                   ;   //fr    840      4 
	TPanel *                       RightPanel                    ;   //fr    844      4 
	TPanel *                       MainPanel                     ;   //fr    848      4 
	TSplitter *                    SplitterH                     ;   //fr    852      4 
	TPanel *                       TopPanel                      ;   //fr    856      4 
	TPanel *                       TopTopPanel                   ;   //fr    860      4 
	TPanel *                       BottomPanel                   ;   //fr    864      4 
	TPanel *                       BottomTopPanel                ;   //fr    868      4
	TMenuItem *                    StatusPanelEnable             ;   //fr    872      4 
	TPopupMenu *                   TabMenu                       ;   //fr    876      4 
	TMenuItem *                    TabClose                      ;   //fr    880      4 
	TPopupMenu *                   SubTabMenu                    ;   //fr    884      4 
	TMenuItem *                    SubTabClose                   ;   //fr    888      4 
	TStatusBar *                   TransStatusBar                ;   //fr    892      4 
	TStatusBar *                   StatusBar                     ;   //fr    896      4 
	TPopupMenu *                   FolderPopupMenu               ;   //fr    900      4 
	TMenuItem *                    OpenFolder                    ;   //fr    904      4 
	TMenuItem *                    RemoveFolder                  ;   //fr    908      4 
	TPopupMenu *                   FilePopupMenu                 ;   //fr    912      4 
	TMenuItem *                    AddDownLoad                   ;   //fr    916      4 
	TMenuItem *                    EditDownList                  ;   //fr    920      4 
	TMenuItem *                    DownLoad                      ;   //fr    924      4 
	TMenuItem *                    RemoveDownList                ;   //fr    928      4 
	TMenuItem *                    N1                            ;   //fr    932      4 
	TMenuItem *                    ViewBlock                     ;   //fr    936      4 
	TMenuItem *                    Convert                       ;   //fr    940      4 
	TMenuItem *                    N2                            ;   //fr    944      4 
	TMenuItem *                    GetFileInfo                   ;   //fr    948      4 
	TMenuItem *                    GetFileHash                   ;   //fr    952      4 
	TMenuItem *                    GetFileTrip                   ;   //fr    956      4 
	TMenuItem *                    GetFileName                   ;   //fr    960      4 
	TPopupMenu *                   DownPopupMenu                 ;   //fr    964      4 
	TMenuItem *                    EditDown                      ;   //fr    968      4 
	TMenuItem *                    ViewDownBlock                 ;   //fr    972      4 
	TMenuItem *                    N7                            ;   //fr    976      4 
	TMenuItem *                    TaskSkip                      ;   //fr    980      4 
	TMenuItem *                    TaskConvert                   ;   //fr    984      4 
	TMenuItem *                    DeleteDownList                ;   //fr    988      4 
	TPopupMenu *                   IgnorePopupMenu               ;   //fr    992      4 
	TMenuItem *                    EditIgnore                    ;   //fr    996      4 
	TMenuItem *                    DeleteIgnoreList              ;   //fr   1000      4 
	TPopupMenu *                   TaskPopupMenu                 ;   //fr   1004      4 
	TMenuItem *                    ViewWork                      ;   //fr   1008      4 
	TMenuItem *                    EditWork                      ;   //fr   1012      4
	TMenuItem *                    N8                            ;   //fr   1016      4 
	TMenuItem *                    ConvertWork                   ;   //fr   1020      4
	TMenuItem *                    ClearTask                     ;   //fr   1024      4 
	TPopupMenu *                   SystemPopupMenu               ;   //fr   1028      4 
	TMenuItem *                    LogCopy                       ;   //fr   1032      4 
	TPopupMenu *                   SubFolderPopupMenu            ;   //fr   1036      4 
	TMenuItem *                    SubOpenFolder                 ;   //fr   1040      4 
	TMenuItem *                    SubRemoveFolder               ;   //fr   1044      4 
	TPopupMenu *                   SubFilePopupMenu              ;   //fr   1048      4 
	TMenuItem *                    SubAddDownLoad                ;   //fr   1052      4 
	TMenuItem *                    SubEditDownList               ;   //fr   1056      4 
	TMenuItem *                    SubDownLoad                   ;   //fr   1060      4 
	TMenuItem *                    SubRemoveDownList             ;   //fr   1064      4 
	TMenuItem *                    MenuItem7                     ;   //fr   1068      4 
	TMenuItem *                    SubViewBlock                  ;   //fr   1072      4 
	TMenuItem *                    SubConvert                    ;   //fr   1076      4 
	TMenuItem *                    MenuItem10                    ;   //fr   1080      4 
	TMenuItem *                    SubGetFileName                ;   //fr   1084      4 
	TMenuItem *                    SubGetTripName                ;   //fr   1088      4 
	TMenuItem *                    SubGetHashName                ;   //fr   1092      4 
	TMenuItem *                    SubGetFileInfo                ;   //fr   1096      4 
	TPopupMenu *                   SubDownPopupMenu              ;   //fr   1100      4 
	TMenuItem *                    SubEditDown                   ;   //fr   1104      4 
	TMenuItem *                    SubViewDownBlock              ;   //fr   1108      4 
	TMenuItem *                    MenuItem17                    ;   //fr   1112      4 
	TMenuItem *                    SubTaskConvert                ;   //fr   1116      4 
	TMenuItem *                    SubTaskSkip                   ;   //fr   1120      4 
	TMenuItem *                    SubDeleteDownList             ;   //fr   1124      4 
	TPopupMenu *                   SubIgnorePopupMenu            ;   //fr   1128      4 
	TMenuItem *                    SubEditIgnore                 ;   //fr   1132      4 
	TMenuItem *                    SubDeleteIgnoreList           ;   //fr   1136      4 
	TPopupMenu *                   SubTaskPopupMenu              ;   //fr   1140      4 
	TMenuItem *                    SubViewWork                   ;   //fr   1144      4 
	TMenuItem *                    SubEditWork                   ;   //fr   1148      4 
	TMenuItem *                    MenuItem25                    ;   //fr   1152      4 
	TMenuItem *                    SubConvertWork                ;   //fr   1156      4
	TMenuItem *                    SubClearTask                  ;   //fr   1160      4 
	TPopupMenu *                   SubSystemPopupMenu            ;   //fr   1164      4 
	TMenuItem *                    SubLogCopy                    ;   //fr   1168      4 
	TPanel *                       BbsToolBar                    ;   //fr   1172      4 
	TImageList *                   BbsTreeImageList              ;   //fr   1176      4 
	TTimer *                       BoardCheckTimer               ;   //fr   1180      4 
	TPopupMenu *                   BbsTreeMenu                   ;   //fr   1184      4 
	TMenuItem *                    RemoveTreeItem                ;   //fr   1188      4 
	TMenuItem *                    AddDefault                    ;   //fr   1192      4 
	TMenuItem *                    BoardOpen                     ;   //fr   1196      4 
	TMenuItem *                    BoardNewOpen                  ;   //fr   1200      4 
	TMenuItem *                    N3                            ;   //fr   1204      4 
	TTimer *                       BbsTreeClickTimer             ;   //fr   1208      4 
	TTimer *                       UpQueryTimer                  ;   //fr   1212      4 
	TTimer *                       DownQueryTimer                ;   //fr   1216      4 
	TPopupMenu *                   BoardTabMenu                  ;   //fr   1220      4 
	TMenuItem *                    BoardTabClose                 ;   //fr   1224      4 
	TPopupMenu *                   BoardMenu                     ;   //fr   1228      4 
	TMenuItem *                    BbsOpen                       ;   //fr   1232      4 
	TMenuItem *                    NewBbsOpen                    ;   //fr   1236      4 
	TTimer *                       OpenBbsTimer                  ;   //fr   1240      4 
	TListView *                    NodeView                      ;   //fr   1244      4 
	TListView *                    FolderView                    ;   //fr   1248      4 
	TListView *                    FileView                      ;   //fr   1252      4 
	TListView *                    DownView                      ;   //fr   1256      4 
	TListView *                    IgnoreView                    ;   //fr   1260      4 
	TListView *                    LogView                       ;   //fr   1264      4 
	TListView *                    TaskView                      ;   //fr   1268      4 
	TListView *                    BbsBoardView                  ;   //fr   1272      4 
	TListView *                    SystemView                    ;   //fr   1276      4 
	TListView *                    SubNodeView                   ;   //fr   1280      4 
	TListView *                    SubFolderView                 ;   //fr   1284      4 
	TListView *                    SubFileView                   ;   //fr   1288      4 
	TListView *                    SubDownView                   ;   //fr   1292      4 
	TListView *                    SubIgnoreView                 ;   //fr   1296      4 
	TListView *                    SubLogView                    ;   //fr   1300      4
	TListView *                    SubTaskView                   ;   //fr   1304      4 
	TListView *                    SubSystemView                 ;   //fr   1308      4 
	TMenuItem *                    N4                            ;   //fr   1312      4 
	TMenuItem *                    BbsGetFileName                ;   //fr   1316      4 
	TMenuItem *                    BbsGetTrip                    ;   //fr   1320      4 
	TMenuItem *                    BbsGetFileHash                ;   //fr   1324      4 
	TMenuItem *                    BbsGetFileData                ;   //fr   1328      4 
	TMenuItem *                    SearchTabRightDelete          ;   //fr   1332      4 
	TMenuItem *                    SearchTabLeftDelete           ;   //fr   1336      4 
	TMenuItem *                    AllSearchTabDelete            ;   //fr   1340      4 
	TPopupMenu *                   SubSearchTabMenu              ;   //fr   1344      4 
	TMenuItem *                    SubSearchTabDelete            ;   //fr   1348      4 
	TMenuItem *                    SubSearchTabRightDelete       ;   //fr   1352      4 
	TMenuItem *                    SubSearchTabLeftDelete        ;   //fr   1356      4 
	TMenuItem *                    SubSearchTabAllDelete         ;   //fr   1360      4 
	TLabel *                       BbsStatusLabel                ;   //fr   1364      4 
	TLabel *                       BbsTitleLabel                 ;   //fr   1368      4 
	TPanel *                       TopTabPanel                   ;   //fr   1372      4 
	TTabControl *                  TabControl                    ;   //fr   1376      4 
	TTabControl *                  BoardTabControl               ;   //fr   1380      4 
	TPanel *                       BottomTabPanel                ;   //fr   1384      4 
	TTabControl *                  SubTabControl                 ;   //fr   1388      4 
	TTabControl *                  BbsTabControl                 ;   //fr   1392      4 
	TPanel *                       SubClosePanel                 ;   //fr   1396      4 
	TSpeedButton *                 SubClosePanelButton           ;   //fr   1400      4 
	TPopupMenu *                   BbsMenu                       ;   //fr   1404      4 
	TMenuItem *                    BbsCopy                       ;   //fr   1408      4 
	TTimer *                       ReloadBoardTimer              ;   //fr   1412      4 
	TMenuItem *                    OpenWinnyWebSite              ;   //fr   1416      4 
	TPanel *                       Panel1                        ;   //fr   1420      4 
	TSpeedButton *                 BbsCloseButton                ;   //fr   1424      4 
	TSpeedButton *                 BbsWriteButton                ;   //fr   1428      4 
	TSpeedButton *                 BbsRefreshButton              ;   //fr   1432      4 
	TPopupMenu *                   BbsTabMenu                    ;   //fr   1436      4 
	TMenuItem *                    BbsClose                      ;   //fr   1440      4 
	TMenuItem *                    AllBbsTabClose                ;   //fr   1444      4
	TMenuItem *                    AllBoardTabClose              ;   //fr   1448      4 
	TMenuItem *                    N5                            ;   //fr   1452      4 
	TMenuItem *                    BbsOpenWeb                    ;   //fr   1456      4 
	TPanel *                       BoardToolBar                  ;   //fr   1460      4 
	TSpeedButton *                 BbsSetupButton                ;   //fr   1464      4 
	TSpeedButton *                 MakeBbsButton                 ;   //fr   1468      4 
	TSpeedButton *                 RefreshBoardButton            ;   //fr   1472      4 
	TSpeedButton *                 BbsViewCache                  ;   //fr   1476      4 
	TSpeedButton *                 BbsBrowserButton              ;   //fr   1480      4 
	TSpeedButton *                 BbsPortScanButton2            ;   //fr   1484      4 
	TSpeedButton *                 CacheClearButton2             ;   //fr   1488      4 
	TRichTextView *                BbsView                       ;   //fr   1492      4 
	TMenuItem *                    FileIgnore                    ;   //fr   1496      4 
	TMenuItem *                    SubFileIgnore                 ;   //fr   1500      4 
	TMenuItem *                    N6                            ;   //fr   1504      4 
	TMenuItem *                    N9                            ;   //fr   1508      4 
	TMenuItem *                    N10                           ;   //fr   1512      4 
	TMenuItem *                    CopyDownToSearchTab           ;   //fr   1516      4 
	TMenuItem *                    N11                           ;   //fr   1520      4 
	TMenuItem *                    SubCopyDownToSearchTab        ;   //fr   1524      4 
	TMenuItem *                    ClearCopyDownToSearchTab      ;   //fr   1528      4 
	TMenuItem *                    SubClearCopyDownToSearchTab   ;   //fr   1532      4 
	TMenuItem *                    TaskAddIgnore                 ;   //fr   1536      4 
	TMenuItem *                    SubTaskAddIgnore              ;   //fr   1540      4 
	TPanel *                       TopToolBar                    ;   //fr   1544      4 
	TSpeedButton *                 SetupButton                   ;   //fr   1548      4 
	TSpeedButton *                 TopToolButton1                ;   //fr   1552      4 
	TSpeedButton *                 TopToolButton2                ;   //fr   1556      4 
	TSpeedButton *                 TopToolButton3                ;   //fr   1560      4 
	TSpeedButton *                 TopToolButton4                ;   //fr   1564      4 
	TSpeedButton *                 TopToolButton5                ;   //fr   1568      4 
	TSpeedButton *                 TopToolButton6                ;   //fr   1572      4 
	TPanel *                       BottomToolBar                 ;   //fr   1576      4 
	TSpeedButton *                 SubSetupButton                ;   //fr   1580      4 
	TSpeedButton *                 BottomToolButton1             ;   //fr   1584      4 
	TSpeedButton *                 BottomToolButton2             ;   //fr   1588      4
	TSpeedButton *                 BottomToolButton3             ;   //fr   1592      4 
	TSpeedButton *                 BottomToolButton4             ;   //fr   1596      4 
	TSpeedButton *                 BottomToolButton5             ;   //fr   1600      4 
	TSpeedButton *                 BottomToolButton6             ;   //fr   1604      4 
	TPanel *                       ToolPanel                     ;   //fr   1608      4 
	TPanel *                       SearchPanel                   ;   //fr   1612      4 
	TLabel *                       TripLabel                     ;   //fr   1616      4 
	TLabel *                       SearchLabel                   ;   //fr   1620      4 
	TLabel *                       HitLabel                      ;   //fr   1624      4 
	TComboBox *                    SearchComboBox                ;   //fr   1628      4 
	TComboBox *                    TripComboBox                  ;   //fr   1632      4 
	TButton *                      SearchButton                  ;   //fr   1636      4 
	TButton *                      SubSearchButton               ;   //fr   1640      4 
	TPanel *                       BbsSearchPanel                ;   //fr   1644      4 
	TLabel *                       BbsSearchLabel                ;   //fr   1648      4 
	TLabel *                       BbsHitLabel                   ;   //fr   1652      4 
	TLabel *                       BbsClusterLabel               ;   //fr   1656      4 
	TComboBox *                    BbsSearchComboBox             ;   //fr   1660      4 
	TButton *                      BbsSearchButton               ;   //fr   1664      4 
	TPanel *                       TopRightPanel                 ;   //fr   1668      4 
	TSpeedButton *                 BbsButton                     ;   //fr   1672      4 
	TSpeedButton *                 LeftButton                    ;   //fr   1676      4 
	TSpeedButton *                 BottomButton                  ;   //fr   1680      4 
	TPanel *                       ClosePanel                    ;   //fr   1684      4 
	TSpeedButton *                 ClosePaneButton               ;   //fr   1688      4 
	TSpeedButton *                 TopButton                     ;   //fr   1692      4 
	TMenuItem *                    TopViewEnable                 ;   //fr   1696      4 
	TPanel *                       StatusPanel                   ;   //fr   1700      4 
	TLabel *                       UpStatusLabel                 ;   //fr   1704      4 
	TLabel *                       DownStatusLabel               ;   //fr   1708      4 
	TMenuItem *                    SubStatusPanelEnable          ;   //fr   1712      4 
	TPanel *                       SubStatusPanel                ;   //fr   1716      4 
	TLabel *                       SubUpStatusLabel              ;   //fr   1720      4 
	TLabel *                       SubDownStatusLabel            ;   //fr   1724      4 
	TTabControl *                  SearchTabControl              ;   //fr   1728      4 
	TTabControl *                  SubSearchTabControl           ;   //fr   1732      4
	TPopupMenu *                   SearchComboMenu               ;   //fr   1736      4 
	TMenuItem *                    ClearSearchHistory            ;   //fr   1740      4 
	TMenuItem *                    EditSearchHistroy             ;   //fr   1744      4 
	TMenuItem *                    ReloadSearchHistory           ;   //fr   1748      4 
	TMenuItem *                    N12                           ;   //fr   1752      4 
	TMenuItem *                    ClearTripHistory              ;   //fr   1756      4 
	TMenuItem *                    EditTab                       ;   //fr   1760      4 
	TMenuItem *                    ReloadTab                     ;   //fr   1764      4 
	TMenuItem *                    N13                           ;   //fr   1768      4 
	TMenuItem *                    SubEditTab                    ;   //fr   1772      4 
	TMenuItem *                    SubReloadTab                  ;   //fr   1776      4 
	TMenuItem *                    N14                           ;   //fr   1780      4 
	TMenuItem *                    N15                           ;   //fr   1784      4 

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
	void __fastcall FileIgnoreClick(TObject * Sender);
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
	vector<TBbsTab>                m__unknown_002                ;   //fr   1992     24
	enumPageType                           m_char_upperPageType_         ;   //fr   2016      1
	enumPageType                           m_char_lowerPageType_         ;   //fr   2017      1
	char	m_notused[1024];


	__fastcall ~TMainForm();
	void mf_TMainForm_0000();
	void mf_TMainForm_0010() ;
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
