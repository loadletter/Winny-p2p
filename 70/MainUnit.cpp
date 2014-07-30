//---------------------------------------------------------------------------
#include "hdrs.h"

#include <vcl.h>
#pragma hdrstop

#include <Forms.hpp>
#include <IniFiles.hpp>
#include <Graphics.hpp>
#include <ComCtrls.hpp>


#include "def.h"

#include "MainUnit.h"


#include "ControlUnit.h"
#include "OptionUnit.h"
#include "AutoDownUnit.h"
#include "DownParamUnit.h"
#include "IpConvUnit.h"
#include "ViewUnit.h"
#include "BbsMakeUnit.h"
#include "BbsWriteUnit.h"
#include "NodeAddUnit.h"
#include "FolderAddUnit.h"

#include "RichTextView.hpp"

#include "def2.h"
#include "globals.h"


//---------------------------------------------------------------------------
//後ろに書いたほうが前に来るような雰囲気だが、よくわからん
//ここでinifin順が微妙に決定される
#pragma package(smart_init)
#pragma link "trayicon"
#pragma link "RichTextView"
#pragma resource "*.dfm"

TMainForm *MainForm;  //参照形式を同一にするため、これは後ろにもっていかないとﾀﾞﾒ


TListView *                g_UpperListViews[11]       ;				//fr 0055642C 0000002C
TListView *                g_LowerListViews[11]       ;				//fr 00556458 0000002C


const char * g_tagnames[]={
	"ノード情報",
	"BBSノード情報",
	"フォルダ情報",
	"ファイル検索",
	"ダウン条件",
	"無視条件",
	"タスク情報",
	"ログ情報",
	"システム情報",
	"BBSボード情報",
};

int                            g_int_unk000=-1           ;				//fr 005351C0 00000004
int                            g_int_unk001=-1           ;				//fr 005351C4 00000004
int                            g_int_flag_logged_newversion=0   ;				//fr 005351C8 00000004
int                            g_int_flag_logged_downfolderdisk=0   ;				//fr 005351CC 00000004
int                            g_int_flag_logged_cachefolderdisk=0   ;				//fr 005351D0 00000004
int g_int_unk005_70=-1;
int g_int_unk006_70=-1;



//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
	int local_00;
	int local_01;

	sprintf(g_szstr_Version,"Winny v2.0b%g",7.0);
	Caption=g_szstr_Version;
	for (local_01=0; local_01<1000; local_01++) {
		for (local_00=0; local_00<10; local_00++) {
			*g_listitemarray[0][local_01][local_00]=0;
			*g_listitemarray[1][local_01][local_00]=0;
		}
		g_nazocharbuf[0][local_01]=0;
		g_nazocharbuf[1][local_01]=0;
		g_nazouintarray[0][local_01]=-1;
		g_nazouintarray[1][local_01]=-1;
		g_KeyBlocks[0][local_01].m_char_unk1=0;
		g_KeyBlocks[1][local_01].m_char_unk1=0;
		g_KeyBlocks[0][local_01].m_pchar_unk4=NULLPO;
		g_KeyBlocks[1][local_01].m_pchar_unk4=NULLPO;
	}
	MainPanel->Visible=false;
	MainPanel->DisableAlign();
	TabControl->Align=alClient;
	SubTabControl->Align=alClient;
	BoardTabControl->Align=alClient;
	BbsTabControl->Align=alClient;
	NodeView->Align=alClient;
	FolderView->Align=alClient;
	FileView->Align=alClient;
	BbsBoardView->Align=alClient;
	DownView->Align=alClient;
	IgnoreView->Align=alClient;
	TaskView->Align=alClient;
	LogView->Align=alClient;
	SystemView->Align=alClient;
	SubNodeView->Align=alClient;
	SubFolderView->Align=alClient;
	SubFileView->Align=alClient;
	SubDownView->Align=alClient;
	SubIgnoreView->Align=alClient;
	SubTaskView->Align=alClient;
	SubLogView->Align=alClient;
	SubSystemView->Align=alClient;
	BbsView->Align=alClient;
	ToolPanel->Height=SearchPanel->Height+4;
	SearchPanel->Top=2;
	SearchPanel->Align=alClient;
	BbsSearchPanel->Top=2;
	TopTopPanel->Height=ClosePanel->Height+TopToolBar->Height+1;
	BottomTopPanel->Height=SubClosePanel->Height+BottomToolBar->Height+1;
	SetupButton->Left=(TopToolBar->Width-SetupButton->Width)+-4;
	SubSetupButton->Left=(BottomToolBar->Width-SubSetupButton->Width)+-4;
	BbsSetupButton->Left=(BoardToolBar->Width-BbsSetupButton->Width)+-4;
	StatusPanel->Left=(SetupButton->Left-StatusPanel->Width)+-2;
	SubStatusPanel->Left=(SubSetupButton->Left-SubStatusPanel->Width)+-2;
	g_UpperListViews[0]=NodeView;
	g_UpperListViews[1]=NodeView;
	g_UpperListViews[2]=FolderView;
	g_UpperListViews[3]=FileView;
	g_UpperListViews[9]=BbsBoardView;
	g_UpperListViews[4]=DownView;
	g_UpperListViews[5]=IgnoreView;
	g_UpperListViews[6]=TaskView;
	g_UpperListViews[7]=LogView;
	g_UpperListViews[8]=SystemView;
	g_LowerListViews[0]=SubNodeView;
	g_LowerListViews[1]=SubNodeView;
	g_LowerListViews[2]=SubFolderView;
	g_LowerListViews[3]=SubFileView;
	g_LowerListViews[9]=NULLPO;
	g_LowerListViews[4]=SubDownView;
	g_LowerListViews[5]=SubIgnoreView;
	g_LowerListViews[6]=SubTaskView;
	g_LowerListViews[7]=SubLogView;
	g_LowerListViews[8]=SubSystemView;
	MainPanel->Visible=true;
	TopPanel->Visible=true;
	BottomPanel->Visible=true;
	MainPanel->EnableAlign();
	NodeView->DoubleBuffered=true;
	FolderView->DoubleBuffered=true;
	FileView->DoubleBuffered=true;
	BbsBoardView->DoubleBuffered=true;
	DownView->DoubleBuffered=true;
	IgnoreView->DoubleBuffered=true;
	TaskView->DoubleBuffered=true;
	LogView->DoubleBuffered=true;
	SystemView->DoubleBuffered=true;
	SubNodeView->DoubleBuffered=true;
	SubFolderView->DoubleBuffered=true;
	SubFileView->DoubleBuffered=true;
	SubDownView->DoubleBuffered=true;
	SubIgnoreView->DoubleBuffered=true;
	SubTaskView->DoubleBuffered=true;
	SubLogView->DoubleBuffered=true;
	SubSystemView->DoubleBuffered=true;
	mf_TMainForm_0000();
	mf_TMainForm_0160();
}


__fastcall TMainForm::~TMainForm()
{
}


void __fastcall TMainForm::FormClose(TObject * Sender,TCloseAction & Action)
{
	mf_TMainForm_0010();
	ControlForm->Close();
	*((char *)(&Action))=0;
	return;
}


void TMainForm::mf_TMainForm_0000()
{
	FILE * local_00;
	char local_01[1024];
	sprintf(local_01,"%s%s",/*(const char *)*/g_AppPath,"Search.txt");
	local_00=fopen(local_01,"rt");
	if (local_00!=0) {
		fclose(local_00);
		SearchComboBox->Items->LoadFromFile(local_01);
	}
	sprintf(local_01,"%s%s",/*(const char *)*/g_AppPath,"SearchTrip.txt");
	local_00=fopen(local_01,"rt");
	if (local_00!=0) {
		fclose(local_00);
		TripComboBox->Items->LoadFromFile(local_01);
	}
	sprintf(local_01,"%s%s",/*(const char *)*/g_AppPath,"Tab1.txt");
	local_00=fopen(local_01,"rt");
	if (local_00!=0) {
		fclose(local_00);
		SearchTabControl->Tabs->LoadFromFile(local_01);
		SearchTabControl->TabIndex=g_pTIniFile->ReadInteger("SearchTab","UpIndex",0);
	}
	sprintf(local_01,"%s%s",/*(const char *)*/g_AppPath,"Tab2.txt");
	local_00=fopen(local_01,"rt");
	if (local_00!=0) {
		fclose(local_00);
		SubSearchTabControl->Tabs->LoadFromFile(local_01);
		SubSearchTabControl->TabIndex=g_pTIniFile->ReadInteger("SearchTab","DownIndex",0);
	}
	LeftPanel->Width=100;
	TopPanel->Height=100;
	BbsButton->Down=g_pTIniFile->ReadInteger("Option","BbsOn",0)>0;
	if (BbsButton->Down) {
		TopButton->Down=g_pTIniFile->ReadInteger("BbsTopView","Visible",1)>0;
		BottomButton->Down=g_pTIniFile->ReadInteger("BbsBottomView","Visible",1)>0;
		LeftButton->Down=g_pTIniFile->ReadInteger("BbsLeftView","Visible",1)>0;
	} else {
		TopButton->Down=g_pTIniFile->ReadInteger("TopView","Visible",1)>0;
		BottomButton->Down=g_pTIniFile->ReadInteger("BottomView","Visible",0)>0;
		LeftButton->Down=g_pTIniFile->ReadInteger("LeftView","Visible",0)>0;
	}
	BoardTabControl->Top=0;
	BbsTabControl->Top=0;
	Left=g_pTIniFile->ReadInteger("Frame","Left",100);
	Top=g_pTIniFile->ReadInteger("Frame","Top",100);
	Width=g_pTIniFile->ReadInteger("Frame","Width",860);
	Height=g_pTIniFile->ReadInteger("Frame","Height",600);
	LeftPanel->Width=g_pTIniFile->ReadInteger("LeftView","Width",200);
	if (BottomButton->Down) {
		if (BbsButton->Down) {
			TopPanel->Height=g_pTIniFile->ReadInteger("TopView","BbsHeight",200);
		} else {
			TopPanel->Height=g_pTIniFile->ReadInteger("TopView","Height",200);
		}
	}
	TopCheckListBox->Checked[0]=g_pTIniFile->ReadInteger("TopView","ViewNodeTab",1)>0;
	TopCheckListBox->Checked[1]=g_pTIniFile->ReadInteger("TopView","ViewBbsNodeTab",1)>0;
	TopCheckListBox->Checked[2]=g_pTIniFile->ReadInteger("TopView","ViewFolderTab",1)>0;
	TopCheckListBox->Checked[3]=g_pTIniFile->ReadInteger("TopView","ViewFileTab",1)>0;
	TopCheckListBox->Checked[4]=g_pTIniFile->ReadInteger("TopView","ViewDownTab",1)>0;
	TopCheckListBox->Checked[5]=g_pTIniFile->ReadInteger("TopView","ViewIgnoreTab",1)>0;
	TopCheckListBox->Checked[6]=g_pTIniFile->ReadInteger("TopView","ViewTaskTab",1)>0;
	TopCheckListBox->Checked[7]=g_pTIniFile->ReadInteger("TopView","ViewLogTab",1)>0;
	TopCheckListBox->Checked[8]=g_pTIniFile->ReadInteger("TopView","ViewSystemTab",1)>0;
	BottomCheckListBox->Checked[0]=g_pTIniFile->ReadInteger("BottomView","ViewNodeTab",1)>0;
	BottomCheckListBox->Checked[1]=g_pTIniFile->ReadInteger("BottomView","ViewBbsNodeTab",1)>0;
	BottomCheckListBox->Checked[2]=g_pTIniFile->ReadInteger("BottomView","ViewFolderTab",1)>0;
	BottomCheckListBox->Checked[3]=g_pTIniFile->ReadInteger("BottomView","ViewFileTab",1)>0;
	BottomCheckListBox->Checked[4]=g_pTIniFile->ReadInteger("BottomView","ViewDownTab",1)>0;
	BottomCheckListBox->Checked[5]=g_pTIniFile->ReadInteger("BottomView","ViewIgnoreTab",1)>0;
	BottomCheckListBox->Checked[6]=g_pTIniFile->ReadInteger("BottomView","ViewTaskTab",1)>0;
	BottomCheckListBox->Checked[7]=g_pTIniFile->ReadInteger("BottomView","ViewLogTab",1)>0;
	BottomCheckListBox->Checked[8]=g_pTIniFile->ReadInteger("BottomView","ViewSystemTab",1)>0;
	StatusPanelEnable->Checked=g_pTIniFile->ReadInteger("StatusPanel","Visible",1)>0;
	SubStatusPanelEnable->Checked=g_pTIniFile->ReadInteger("SubStatusPanel","Visible",1)>0;
	if (g_pTIniFile->ReadInteger("Frame","Maxmize",0)>0) {
		WindowState=wsMaximized;
	} else {
		if (g_pTIniFile->ReadInteger("Frame","Minimize",0)>0) {
			ControlForm->mf_TControlForm_0000();
		} else {
			WindowState=wsNormal;
		}
	}
	mf_TMainForm_0040();
	mf_TMainForm_0050();
	mf_TMainForm_0080();
	TabControl->TabIndex=g_pTIniFile->ReadInteger("Tab","MainIndex",0);
	SubTabControl->TabIndex=g_pTIniFile->ReadInteger("Tab","SubIndex",0);
	return;
}


void TMainForm::mf_TMainForm_0010()
{
	g_pTIniFile->WriteInteger("SearchTab","UpIndex",SearchTabControl->TabIndex);
	g_pTIniFile->WriteInteger("SearchTab","DownIndex",SubSearchTabControl->TabIndex);
	if (WindowState==0) {
		g_pTIniFile->WriteInteger("Frame","Width",Width);
		g_pTIniFile->WriteInteger("Frame","Height",Height);
		g_pTIniFile->WriteInteger("Frame","Left",Left);
		g_pTIniFile->WriteInteger("Frame","Top",Top);
	}
	g_pTIniFile->WriteInteger("Tab","MainIndex",TabControl->TabIndex);
	g_pTIniFile->WriteInteger("Tab","SubIndex",SubTabControl->TabIndex);
	g_pTIniFile->WriteInteger("LeftView","Width",LeftPanel->Width);
	if (BottomButton->Down) {
		if (BbsButton->Down) {
			g_pTIniFile->WriteInteger("TopView","BbsHeight",TopPanel->Height);
		} else {
			g_pTIniFile->WriteInteger("TopView","Height",TopPanel->Height);
		}
	}
	g_pTIniFile->WriteInteger("TopView","ViewNodeTab",TopCheckListBox->Checked[0]?1:0);
	g_pTIniFile->WriteInteger("TopView","ViewBbsNodeTab",TopCheckListBox->Checked[1]?1:0);
	g_pTIniFile->WriteInteger("TopView","ViewFolderTab",TopCheckListBox->Checked[2]?1:0);
	g_pTIniFile->WriteInteger("TopView","ViewFileTab",TopCheckListBox->Checked[3]?1:0);
	g_pTIniFile->WriteInteger("TopView","ViewDownTab",TopCheckListBox->Checked[4]?1:0);
	g_pTIniFile->WriteInteger("TopView","ViewIgnoreTab",TopCheckListBox->Checked[5]?1:0);
	g_pTIniFile->WriteInteger("TopView","ViewTaskTab",TopCheckListBox->Checked[6]?1:0);
	g_pTIniFile->WriteInteger("TopView","ViewLogTab",TopCheckListBox->Checked[7]?1:0);
	g_pTIniFile->WriteInteger("TopView","ViewSystemTab",TopCheckListBox->Checked[8]?1:0);
	g_pTIniFile->WriteInteger("BottomView","ViewNodeTab",BottomCheckListBox->Checked[0]?1:0);
	g_pTIniFile->WriteInteger("BottomView","ViewBbsNodeTab",BottomCheckListBox->Checked[1]?1:0);
	g_pTIniFile->WriteInteger("BottomView","ViewFolderTab",BottomCheckListBox->Checked[2]?1:0);
	g_pTIniFile->WriteInteger("BottomView","ViewFileTab",BottomCheckListBox->Checked[3]?1:0);
	g_pTIniFile->WriteInteger("BottomView","ViewDownTab",BottomCheckListBox->Checked[4]?1:0);
	g_pTIniFile->WriteInteger("BottomView","ViewIgnoreTab",BottomCheckListBox->Checked[5]?1:0);
	g_pTIniFile->WriteInteger("BottomView","ViewTaskTab",BottomCheckListBox->Checked[6]?1:0);
	g_pTIniFile->WriteInteger("BottomView","ViewLogTab",BottomCheckListBox->Checked[7]?1:0);
	g_pTIniFile->WriteInteger("BottomView","ViewSystemTab",BottomCheckListBox->Checked[8]?1:0);
	g_pTIniFile->WriteInteger("StatusPanel","Visible",!(!StatusPanelEnable->Checked)?1:0);
	g_pTIniFile->WriteInteger("SubStatusPanel","Visible",!(!SubStatusPanelEnable->Checked)?1:0);
	g_pTIniFile->WriteInteger("Option","BbsOn",!(!BbsButton->Down)?1:0);
	mf_TMainForm_0015();
	mf_TMainForm_0140();
	return;
}


void TMainForm::mf_TMainForm_0015()
{
	if (BbsButton->Down) {
		g_pTIniFile->WriteInteger("BbsTopView","Visible",!(!TopButton->Down)?1:0);
		g_pTIniFile->WriteInteger("BbsBottomView","Visible",!(!BottomButton->Down)?1:0);
		g_pTIniFile->WriteInteger("BbsLeftView","Visible",!(!LeftButton->Down)?1:0);
	} else {
		g_pTIniFile->WriteInteger("TopView","Visible",!(!TopButton->Down)?1:0);
		g_pTIniFile->WriteInteger("BottomView","Visible",!(!BottomButton->Down)?1:0);
		g_pTIniFile->WriteInteger("LeftView","Visible",!(!LeftButton->Down)?1:0);
	}
}


void TMainForm::mf_TMainForm_0020(xint arg_0)
{
	int local_00;
	int local_01;
	for (local_01=0; local_01<1000; local_01++) {
		for (local_00=0; local_00<10; local_00++) {
			*g_listitemarray[arg_0][local_01][local_00]=0;
		}
		g_nazocharbuf[arg_0][local_01]=0;
		g_nazouintarray[arg_0][local_01]=-1;
		g_KeyBlocks[arg_0][local_01].m_char_unk1=0;
		if (g_KeyBlocks[arg_0][local_01].m_pchar_unk4!=0) {
			free(g_KeyBlocks[arg_0][local_01].m_pchar_unk4);
		}
		g_KeyBlocks[arg_0][local_01].m_pchar_unk4=NULLPO;
	}
	return;
}


void __fastcall TMainForm::TabControlChange(TObject * Sender)
{
	xint local_02;
	int local_03;
	xint local_04;
	TListView * local_05;
	TTabControl * local_06;
	xint local_07;
	char local_18[256];
	if (g_pCMainControl==0) {
		return;
	}
	local_02=-1;
	MainPanel->DisableAlign();
	BbsClusterLabel->Visible=g_pCMainControl->m_flg_IsJoiningBBSCluster_;
	local_03=-1;
	local_04=0;
	local_05=NULLPO;
	local_06=NULLPO;
	if (BbsButton->Down) {
		local_06=BoardTabControl;
		local_02=9;
		local_03=(int)local_02;
		local_05=g_UpperListViews[local_02];
		m_char_upperPageType_=(enumPageType)*((char *)(&local_02));
		m_char_lowerPageType_=pt10;
		NodeView->Visible=false;
		FolderView->Visible=false;
		FileView->Visible=false;
		DownView->Visible=false;
		IgnoreView->Visible=false;
		TaskView->Visible=false;
		LogView->Visible=false;
		SystemView->Visible=false;
		SubNodeView->Visible=false;
		SubFolderView->Visible=false;
		SubFileView->Visible=false;
		SubDownView->Visible=false;
		SubIgnoreView->Visible=false;
		SubTaskView->Visible=false;
		SubLogView->Visible=false;
		SubSystemView->Visible=false;
		if (!BbsBoardView->Visible) {
			BbsBoardView->Visible=true;
			BbsBoardView->DoubleBuffered=true;
		}
	} else {
		if (TabControl==Sender) {
			local_06=SearchTabControl;
			local_02=mf_TMainForm_0060();
			local_03=g_int_unk000;
			m_char_upperPageType_=(enumPageType)*((char *)(&local_02));
			if (local_02>=0) {
				local_05=g_UpperListViews[local_02];
				if (!local_05->Visible) {
					local_05->Visible=true;
					local_05->DoubleBuffered=true;
				}
				local_05->BringToFront();
			} else {
				NodeView->Visible=false;
				FolderView->Visible=false;
				FileView->Visible=false;
				DownView->Visible=false;
				IgnoreView->Visible=false;
				TaskView->Visible=false;
				LogView->Visible=false;
				SystemView->Visible=false;
			}
			BbsBoardView->Visible=false;
		} else {
			local_06=SubSearchTabControl;
			local_02=mf_TMainForm_0070();
			local_03=g_int_unk001;
			m_char_lowerPageType_=(enumPageType)*((char *)(&local_02));
			if (local_02>=0) {
				local_05=g_LowerListViews[local_02];
				local_04=1;
				if (!local_05->Visible) {
					local_05->Visible=true;
					local_05->DoubleBuffered=true;
				}
				local_05->BringToFront();
			} else {
				SubNodeView->Visible=false;
				SubFolderView->Visible=false;
				SubFileView->Visible=false;
				SubDownView->Visible=false;
				SubIgnoreView->Visible=false;
				SubTaskView->Visible=false;
				SubLogView->Visible=false;
				SubSystemView->Visible=false;
			}
		}
	}
	MainPanel->EnableAlign();
	if (local_02<0) {
		return;
	}
	if (local_05==0) {
		return;
	}
	mf_TMainForm_0140();
	mf_TMainForm_0020(local_04);
	if (! (!BbsButton->Down||local_06->TabIndex>=0) ) {
		local_05->Clear();
		return;
	}

	local_07=0;
	if (local_02==9) {
		local_07=1;
	}
	int	local_08=g_pTIniFile->ReadInteger("TabSort",g_tagnames[local_02],(int)local_07);
	bool	local_09=g_pTIniFile->ReadInteger("TabSortMode",g_tagnames[local_02],1)>0;
	Integer local_10;
	if (local_02==0) {
		g_pCMainControl->mf_CMainControl_0510(local_04,false,local_08,local_09);
	} else {
		if (local_02==1) {
			g_pCMainControl->mf_CMainControl_0510(local_04,true,local_08,local_09);
		} else {
			if (local_02==2) {
				g_pCMainControl->mf_CMainControl_0480(local_04,local_08,local_09);
			} else {
				if (local_02==3) {
					g_pCMainControl->mf_CMainControl_0490(local_04,SearchComboBox->Text.c_str(),TripComboBox->Text.c_str(),local_08,local_09);
				} else {
					if (local_02==9) {
						if (local_05->Items->Count>0) {
							local_05->Items->Item[0]->MakeVisible(true);
						}
						local_10=local_06->TabIndex;
						AnsiString local_00="";
						if (local_10>=0) {
							AnsiString local_01=local_06->Tabs->Strings[local_10];
							if (local_01.SubString(0,2)=="* ") {
								local_00=local_01.SubString(3,255);
							} else {
								local_00=("[BBS_"+local_01)+"]";
							}
							g_pCMainControl->mf_CMainControl_1070(local_00.c_str());
							if (ReloadBoardTimer!=Sender) {
								ReloadBoardTimer->Enabled=true;
							}
						}
						g_pCMainControl->mf_CMainControl_0500(local_04,local_00.c_str(),local_08,local_09);
						g_pCMainControl->m_flg_IsBBSSearchLinkOn_=true;
						g_pCMainControl->m_int_unk30=0;
					} else {
						if (local_02==4) {
							g_pCMainControl->mf_CMainControl_0530(local_04);
						} else {
							if (local_02==5) {
								g_pCMainControl->mf_CMainControl_0540(local_04);
							} else {
								if (local_02==6) {
									local_05->ClearSelection();
									g_pCMainControl->mf_CMainControl_0520(local_04,local_08,local_09);
								} else {
									if (local_02==7) {
										mf_TMainForm_0030(local_04);
									} else {
										if (local_02==8) {
											g_pCMainControl->mf_CMainControl_0550(local_04);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (! (!(local_03!=local_02||local_02==3)&&local_02!=9) ) {
		local_05->Items->BeginUpdate();
	}
	local_05->Items->Count=(g_intarray2[local_04]);
	int local_11;
	local_11=local_05->Items->Count;
    int local_12;
	for (local_12=0; g_intarray2[local_04]>local_12; local_12++) {
		if (local_12>=local_11) {
			TListItem * local_13=local_05->Items->Add();
			local_13->Caption=g_listitemarray[local_04][local_12][0];
			for (int local_14=1; local_05->Columns->Count>local_14; local_14++) {
				local_13->SubItems->Add(g_listitemarray[local_04][local_12][local_14]);
			}
		} else {
			TListItem * local_15=local_05->Items->Item[local_12];
			if (strcmp(local_15->Caption.c_str(),g_listitemarray[local_04][local_12][0])!=0) {
				local_15->Caption=g_listitemarray[local_04][local_12][0];
			}
			for (int local_16=local_05->Columns->Count-1; local_16>=1; local_16--) {
				if (strcmp(local_15->SubItems->Strings[local_16-1].c_str(),g_listitemarray[local_04][local_12][local_16])) {//continue;
					//==0にすると、stringをdestructする前にtest/setzしてpushするが、コードはpushしてdestructのあとpop/testになっている
					local_15->SubItems->Strings[local_16-1]=g_listitemarray[local_04][local_12][local_16];
				}
			}
		}
	}
	for (int local_17=local_11-1; g_intarray2[local_04]<=local_17; local_17--) {
		local_05->Items->Delete(local_17);
	}
	if (! (local_02!=7||local_05->Items->Count<=0) ) {
		local_05->Items->Item[local_05->Items->Count-1]->MakeVisible(true);
	}
	if (! (!(local_03!=local_02||local_02==3)&&local_02!=9) ) {
		local_05->Items->EndUpdate();
	}
	if (!BbsButton->Down) {
		if (TabControl==Sender) {
			g_int_unk000=(int)local_02;
		} else {
			g_int_unk001=(int)local_02;
		}
	}
	sprintf(local_18,"Hit : %d",g_pCMainControl->m_int_unk17);
	HitLabel->Caption=local_18;
	BbsHitLabel->Caption=local_18;
	return;
}


void TMainForm::mf_TMainForm_0030(xint arg_0)
{
	unsigned int local_00;
	for (local_00=0; g_Log.size()>local_00; local_00++) {
		strcpy(g_listitemarray[arg_0][local_00][0],g_Log[local_00].c_str());
	}
	g_intarray2[arg_0]=g_Log.size();
	return;
}


void TMainForm::mf_TMainForm_0040()
{
	TabControl->Tabs->Clear();
	for (int local_00=0; TopCheckListBox->Items->Count>local_00; local_00++) {
		if (!TopCheckListBox->Checked[local_00]) continue;
		TabControl->Tabs->Add(TopCheckListBox->Items->Strings[local_00]);
	}
	return;
}


void TMainForm::mf_TMainForm_0050()
{
	SubTabControl->Tabs->Clear();
	for (int local_00=0; BottomCheckListBox->Items->Count>local_00; local_00++) {
		if (!BottomCheckListBox->Checked[local_00]) continue;
		SubTabControl->Tabs->Add(BottomCheckListBox->Items->Strings[local_00]);
	}
	return;
}


sl TMainForm::mf_TMainForm_0060()
{
	if (BbsButton->Down) {
		return 9;
	}
	if (TabControl->TabIndex<0) {
		return -1;
	}
	AnsiString local_00=(TabControl->Tabs->Strings[TabControl->TabIndex]);
	for (int local_01=0; local_01<10; local_01++) {
		if (local_00.AnsiCompare(g_tagnames[local_01])==0) {
			return local_01;
		}
	}
	return -1;
}


sl TMainForm::mf_TMainForm_0070()
{
	if (BbsButton->Down) {
		return -1;
	}
	if (SubTabControl->TabIndex<0) {
		return -1;
	}
	AnsiString local_00=(SubTabControl->Tabs->Strings[SubTabControl->TabIndex]);
	for (int local_01=0; local_01<10; local_01++) {
		if (local_00.AnsiCompare(g_tagnames[local_01])==0) {
			return local_01;
		}
	}
	return -1;
}


void __fastcall TMainForm::TopCheckListBoxClick(TObject * Sender)
{
	mf_TMainForm_0040();
	mf_TMainForm_0080();
	return;
}


void __fastcall TMainForm::BottomCheckListBoxClick(TObject * Sender)
{
	mf_TMainForm_0050();
	mf_TMainForm_0080();
	return;
}


void TMainForm::mf_TMainForm_0080()
{
	SearchButton->Enabled=TopCheckListBox->Checked[3];
	SubSearchButton->Enabled=BottomCheckListBox->Checked[3];
	if (! (SearchButton->Enabled||!SubSearchButton->Enabled) ) {
		SubSearchButton->Default=true;
	} else {
		if (SearchButton->Enabled) {
			SearchButton->Default=true;
		}
	}
	if (!BbsButton->Down) {
		TabControl->Visible=true;
		SubTabControl->Visible=true;
		BoardTabControl->Visible=false;
		BbsTabControl->Visible=false;
		BbsView->Visible=false;
		LeftTabControl->TabIndex=1;
		if (!LeftFilePanel->Visible) {
			LeftFilePanel->Visible=true;
		}
		LeftFilePanel->Align=alClient;
		LeftBbsPanel->Visible=false;
		if (!SearchPanel->Visible) {
			SearchPanel->Visible=true;
		}
		BbsSearchPanel->Visible=false;
		SearchButton->Default=(TopButton->Down||!BottomButton->Down&&!TopButton->Down);
		SubSearchButton->Default=(!(!BottomButton->Down)&&!TopButton->Down);
	} else {
		TabControl->Visible=false;
		SubTabControl->Visible=false;
		if (!BoardTabControl->Visible) {
			BoardTabControl->Visible=true;
		}
		if (!BbsTabControl->Visible) {
			BbsTabControl->Visible=true;
		}
		SearchTabControl->Visible=false;
		SubSearchTabControl->Visible=false;
		if (!BbsView->Visible) {
			BbsView->Visible=true;
			BbsView->DoubleBuffered=true;
		}
		LeftTabControl->TabIndex=0;
		if (!LeftBbsPanel->Visible) {
			LeftBbsPanel->Visible=true;
		}
		LeftBbsPanel->Align=alClient;
		LeftFilePanel->Visible=false;
		SearchPanel->Visible=false;
		if (!BbsSearchPanel->Visible) {
			BbsSearchPanel->Visible=true;
		}
	}
	if (! (!BottomButton->Down||TopPanel->Height<=RightPanel->Height+-100) ) {
		TopPanel->Height=RightPanel->Height/2;
	}
	if (LeftButton->Down) {
		if (!LeftPanel->Visible) {
			LeftPanel->Visible=true;
		}
		if (!SplitterV->Visible) {
			SplitterV->Visible=true;
		}
		if (!LeftViewEnable->Checked) {
			LeftViewEnable->Checked=true;
		}
	} else {
		SplitterV->Visible=false;
		LeftPanel->Visible=false;
		LeftViewEnable->Checked=false;
	}
	if (! (!TopButton->Down||!BottomButton->Down) ) {
		TopPanel->Align=alTop;
		SplitterH->Visible=true;
		BottomPanel->Align=alClient;
		BottomPanel->Visible=true;
		TopViewEnable->Checked=true;
		BottomViewEnable->Checked=true;
		TopPanel->Visible=true;
		if (BbsButton->Down) {
			TopPanel->Height=g_pTIniFile->ReadInteger("TopView","BbsHeight",200);
		} else {
			TopPanel->Height=g_pTIniFile->ReadInteger("TopView","Height",200);
		}
	} else {
		if (TopButton->Down) {
			BottomPanel->Visible=false;
			SplitterH->Visible=false;
			TopViewEnable->Checked=true;
			BottomViewEnable->Checked=false;
			TopPanel->Align=alClient;
			TopPanel->Visible=true;
		} else {
			if (BottomButton->Down) {
				TopPanel->Visible=false;
				SplitterH->Visible=false;
				TopViewEnable->Checked=false;
				BottomViewEnable->Checked=true;
				BottomPanel->Align=alClient;
				BottomPanel->Visible=true;
			} else {
				BottomPanel->Visible=false;
				SplitterH->Visible=false;
				TopPanel->Visible=false;
				TopViewEnable->Checked=false;
				BottomViewEnable->Checked=false;
			}
		}
	}
	if (TransStatusBar->Visible!=StatusPanelEnable->Checked) {
		TransStatusBar->Visible=StatusPanelEnable->Checked;
	}
	if (StatusPanel->Visible!=SubStatusPanelEnable->Checked) {
		StatusPanel->Visible=SubStatusPanelEnable->Checked;
	}
	if (SubStatusPanel->Visible!=SubStatusPanelEnable->Checked) {
		SubStatusPanel->Visible=SubStatusPanelEnable->Checked;
	}
	if (BbsButton->Down) {
		m_char_upperPageType_=pt09;
		m_char_lowerPageType_=pt10;
	}
	mf_TMainForm_0140();
	return;
}


void __fastcall TMainForm::LeftButtonClick(TObject * Sender)
{
	MainPanel->DisableAlign();
	mf_TMainForm_0015();
	mf_TMainForm_0080();
	MainPanel->EnableAlign();
	return;
}


void __fastcall TMainForm::TopButtonClick(TObject * Sender)
{
	MainPanel->DisableAlign();
	mf_TMainForm_0015();
	mf_TMainForm_0080();
	MainPanel->EnableAlign();
	return;
}


void __fastcall TMainForm::BottomButtonClick(TObject * Sender)
{
	MainPanel->DisableAlign();
	mf_TMainForm_0015();
	mf_TMainForm_0080();
	MainPanel->EnableAlign();
	return;
}


void TMainForm::mf_TMainForm_0090()
{
	char local_00[4096];
	if (g_AppPath.Length()!=0) {
		sprintf(local_00,"%s%s",/*(const char *)*/g_AppPath,"Tab1.txt");
		try {
			SearchTabControl->Tabs->SaveToFile(local_00);
		}
		catch (const EFOpenError & ex_8) {
		}
		sprintf(local_00,"%s%s",/*(const char *)*/g_AppPath,"Tab2.txt");
		try {
			SubSearchTabControl->Tabs->SaveToFile(local_00);
		}
		catch (const EFOpenError & ex_32) {
		}
	}
	return;
}


void __fastcall TMainForm::SearchButtonClick(TObject * Sender)
{
	char local_17[1024];
	if (g_pCMainControl!=0) {
		g_pCMainControl->m_flg_unk15462=true;
	}
	AnsiString local_00=(SearchComboBox->Text);
	AnsiString local_01=(TripComboBox->Text);
	if (local_01.Length()>12) {
		local_01=local_01.SubString(0,12);
	}
	sprintf(local_17,"%s%s",/*(const char *)*/g_AppPath,"SearchTrip.txt");
	FILE * local_05=fopen(local_17,"rt");
	if (local_05!=0) {
		fclose(local_05);
		TripComboBox->Items->LoadFromFile(local_17);
	}
	if (local_00.Length()>0) {
		sprintf(local_17,"%s%s",/*(const char *)*/g_AppPath,"Search.txt");
		local_05=fopen(local_17,"rt");
		if (local_05!=0) {
			fclose(local_05);
			SearchComboBox->Items->LoadFromFile(local_17);
		}
	}
	MainPanel->DisableAlign();
	TTabControl * local_06=SearchTabControl;
	if (SubSearchButton==Sender) {
		local_06=SubSearchTabControl;
		if (!BottomButton->Down) {
			BottomButton->Down=true;
			mf_TMainForm_0080();
		}
	} else {
		if (!TopButton->Down) {
			TopButton->Down=true;
			mf_TMainForm_0080();
		}
	}
	if (local_00.Length()>=2) {
		int local_08=SearchComboBox->Items->Count;
		int local_10;
		for (local_10=0; local_10<local_08; local_10++) {
			AnsiString local_02=SearchComboBox->Items->Strings[local_10];
			if (local_02.AnsiCompare(local_00)==0) {
				SearchComboBox->Items->Delete(local_10);
				local_08=local_08-1;
				local_10=local_10-1;
			}
		}
		SearchComboBox->Items->Insert(0,local_00);
		local_08=local_06->Tabs->Count;
		int local_11=0;
		bool local_09=false;
		for (int local_12=0; local_12<local_08; local_12++) {
			AnsiString local_03=(local_06->Tabs->Strings[local_12]);
			if (local_03.AnsiCompare(local_00)==0) {
				local_09=true;
				local_11=local_12;
				break;
			}
		}
		if (!local_09) {
			local_11=local_08;
			local_06->Tabs->Add(local_00);
		}
		local_06->TabIndex=local_11;
	}
	if (local_01.Length()>=2) {
		int		local_13=TripComboBox->Items->Count;
		int		local_14=0;
		bool		local_15=false;
		for (int local_16=0; local_16<local_13; local_16++) {
			AnsiString local_04=(TripComboBox->Items->Strings[local_16]);
			if (local_04.AnsiCompare(local_01)==0) {
				local_15=true;
				local_14=local_16;
				break;
			}
		}
		if (!local_15) {
			TripComboBox->Items->Insert(local_14,local_01);
		}
	}
	if (SubSearchButton==Sender) {
		DownQueryTimer->Enabled=true;
	} else {
		UpQueryTimer->Enabled=true;
	}
	if (SubSearchButton==Sender) {
		mf_TMainForm_0110(3);
	} else {
		mf_TMainForm_0100(3);
	}
	if (g_AppPath.Length()!=0) {
		sprintf(local_17,"%s%s",/*(const char *)*/g_AppPath,"Search.txt");
		try {
			SearchComboBox->Items->SaveToFile(local_17);
		}
		catch (const EFOpenError & ex_152) {
		}
		sprintf(local_17,"%s%s",/*(const char *)*/g_AppPath,"SearchTrip.txt");
		try {
			TripComboBox->Items->SaveToFile(local_17);
		}
		catch (const EFOpenError & ex_176) {
		}
	}
	mf_TMainForm_0090();
	if (SubSearchButton==Sender) {
		TabControlChange(SubTabControl);
	} else {
		TabControlChange(TabControl);
	}
	MainPanel->EnableAlign();
	CGlobalLock CGLock;
	g_pCMainControl->mf_CMainControl_1080(local_00.c_str(),(char *)local_01.c_str(),true,3);
	return;
}


void __fastcall TMainForm::SearchTabControlChange(TObject * Sender)
{
	TTabControl * local_01;
	local_01=SearchTabControl;
	if (local_01->TabIndex<0) {
		return;
	}
	AnsiString local_00=(local_01->Tabs->Strings[local_01->TabIndex]);
	int	local_02=local_01->TabIndex;
	SearchComboBox->Text=local_00;
	mf_TMainForm_0100(3);
	local_01->TabIndex=local_02;
	TabControlChange(TabControl);
	return;
}


void __fastcall TMainForm::SubSearchTabControlChange(TObject * Sender)
{
	TTabControl * local_01;
	local_01=SubSearchTabControl;
	if (local_01->TabIndex<0) {
		return;
	}
	AnsiString local_00=(local_01->Tabs->Strings[local_01->TabIndex]);
	int	local_02=local_01->TabIndex;
	SearchComboBox->Text=local_00;
	mf_TMainForm_0110(3);
	local_01->TabIndex=local_02;
	TabControlChange(SubTabControl);
	return;
}


void __fastcall TMainForm::SearchTabControlMouseDown(TObject * Sender,TMouseButton Button,TShiftState Shift,int X,int Y)
{
	TTabControl * local_00;
	Integer local_01;
	local_00=SearchTabControl;
	local_01=local_00->IndexOfTabAt(X,Y);
	if (local_01>=0) {
		local_00->TabIndex=local_01;
		SearchTabControlChange(NULLPO);
		if (Button==mbMiddle/*2*/) {     //middle buttonに対応しているのが微妙
			SearchTabDeleteClick(SearchTabDelete);
		}
	}
	return;
}


void __fastcall TMainForm::SubSearchTabControlMouseDown(TObject * Sender,TMouseButton Button,TShiftState Shift,int X,int Y)
{
	TTabControl * local_00;
	Integer local_01;
	local_00=SubSearchTabControl;
	local_01=local_00->IndexOfTabAt(X,Y);
	if (local_01>=0) {
		local_00->TabIndex=local_01;
		SubSearchTabControlChange(NULLPO);
		if (Button==mbMiddle/*2*/) {
			SearchTabDeleteClick(SubSearchTabDelete);
		}
	}
	return;
}


Bb TMainForm::mf_TMainForm_0100(char arg_0)
{
	int local_01;
	local_01=TabControl->Tabs->Count;
	for (int local_02=0; local_02<local_01; local_02++) {
		AnsiString local_00=(TabControl->Tabs->Strings[local_02]);
		if ((local_00.AnsiCompare(g_tagnames[arg_0])==0)) {
			TabControl->TabIndex=local_02;
			return true;
		}
	}
	return false;
}


Bb TMainForm::mf_TMainForm_0110(char arg_0)
{
	int local_01;
	local_01=SubTabControl->Tabs->Count;
	for (int local_02=0; local_02<local_01; local_02++) {
		AnsiString local_00=(SubTabControl->Tabs->Strings[local_02]);
		if ((local_00.AnsiCompare(g_tagnames[arg_0])==0)) {
			SubTabControl->TabIndex=local_02;
			return true;
		}
	}
	return false;
}


void __fastcall TMainForm::LeftViewEnableClick(TObject * Sender)
{
	MainPanel->DisableAlign();
	LeftButton->Down=!LeftButton->Down;
	mf_TMainForm_0080();
	MainPanel->EnableAlign();
	return;
}


void __fastcall TMainForm::TopViewEnableClick(TObject * Sender)
{
	MainPanel->DisableAlign();
	TopButton->Down=!TopButton->Down;
	mf_TMainForm_0080();
	MainPanel->EnableAlign();
	return;
}


void __fastcall TMainForm::BottomViewEnableClick(TObject * Sender)
{
	MainPanel->DisableAlign();
	BottomButton->Down=!BottomButton->Down;
	mf_TMainForm_0080();
	MainPanel->EnableAlign();
	return;
}


void __fastcall TMainForm::StatusPanelEnableClick(TObject * Sender)
{
	MainPanel->DisableAlign();
	StatusPanelEnable->Checked=!StatusPanelEnable->Checked;
	mf_TMainForm_0080();
	MainPanel->EnableAlign();
	return;
}


void __fastcall TMainForm::SubStatusPanelEnableClick(TObject * Sender)
{
	MainPanel->DisableAlign();
	SubStatusPanelEnable->Checked=!SubStatusPanelEnable->Checked;
	mf_TMainForm_0080();
	MainPanel->EnableAlign();
	return;
}


void __fastcall TMainForm::LeftTabControlChange(TObject * Sender)
{
	MainPanel->DisableAlign();
	BbsButton->Down=LeftTabControl->TabIndex!=1;
	mf_TMainForm_0080();
	TabControlChange(TabControl);
	TabControlChange(SubTabControl);
	MainPanel->EnableAlign();
	return;
}


void __fastcall TMainForm::LeftPanelCloseButtonClick(TObject * Sender)
{
	MainPanel->DisableAlign();
	LeftButton->Down=false;
	mf_TMainForm_0080();
	mf_TMainForm_0015();
	MainPanel->EnableAlign();
	return;
}


void __fastcall TMainForm::ClosePaneButtonClick(TObject * Sender)
{
	MainPanel->DisableAlign();
	TopButton->Down=false;
	if (!BottomButton->Down) {
		BottomButton->Down=true;
	}
	mf_TMainForm_0080();
	mf_TMainForm_0015();
	MainPanel->EnableAlign();
	return;
}


void __fastcall TMainForm::SubClosePanelButtonClick(TObject * Sender)
{
	MainPanel->DisableAlign();
	BottomButton->Down=false;
	if (!TopButton->Down) {
		TopButton->Down=true;
	}
	mf_TMainForm_0080();
	mf_TMainForm_0015();
	MainPanel->EnableAlign();
	return;
}


void TMainForm::mf_TMainForm_0120()
{
	int local_00;
	char local_01[1024];
	char local_02[1024];
	if (g_pCMainControl==0) {
		return;
	}
	local_00=(!(g_pCMainControl->m_int_CurrentTransferUpConnectionCount_==0||g_pCMainControl->m_double_upKBytePerSec_<=40.0)?1:0)+g_pCMainControl->m_int_currentTransferUpConnectionMax_;
	if (BbsButton->Down) {
		ny_decryptstring("%C.%c.%t.%!.%T.%f.%b.%s.%d.%i.%!.%V.%q.%!.%&.%e.%!.%0.%!.%E.%p.%x.%o.%!.%&.%e.",local_02);
		sprintf(local_01,local_02,g_pCMainControl->m_int_CurrentBBSUpConnectionCount_,g_pCMainControl->m_int_CurrentBBSDownConnectionCount_);
	} else {
		ny_decryptstring("%G.%j.%m.%f.%!.%T.%f.%b.%s.%d.%i.%!.%V.%q.%!.%&.%e.%!.%0.%!.%E.%p.%x.%o.%!.%&.%e.",local_02);
		sprintf(local_01,local_02,g_pCMainControl->m_int_CurrentSearchUpConnectionCount_,g_pCMainControl->m_int_CurrentSearchDownConnectionCount_);
	}
	TransStatusBar->Panels->Items[0]->Text=local_01;
	ny_decryptstring("%U.%s.%b.%o.%t.%!.%V.%q.%!.%&.%e.%!.%0.%!.%&.%e.%!.%!.%E.%p.%x.%o.%!.%&.%e.%!.%0.%!.%&.%e.",local_02);
	sprintf(local_01,local_02,g_pCMainControl->m_int_CurrentTransferUpConnectionCount_,g_pCMainControl->m_int_currentTransferUpConnectionMax_,g_pCMainControl->m_int_CurrentTransferDownConnectionCount_,local_00);
	TransStatusBar->Panels->Items[1]->Text=local_01;
	ny_decryptstring("%U.%p.%u.%b.%m.%!.%V.%q.%!.%&.%9.%/.%2.%g.%!.%0.%!.%E.%p.%x.%o.%!.%&.%9.%/.%2.%g.%!.%L.%c.%z.%u.%f.%0.%t.",local_02);
	sprintf(local_01,local_02,g_pCMainControl->m_double_upKBytePerSec_,g_pCMainControl->m_double_downKBytePerSec_);
	TransStatusBar->Panels->Items[2]->Text=local_01;
	ny_decryptstring("%V.%!.%!.%t.%;.%&.%3.%e.%!.%!.%u.%;.%!.%&.%3.%e.%!.%0.%&.%3.%e.%!.%&.%9.%/.%2.%g.%L.",local_02);
	sprintf(local_01,local_02,g_pCMainControl->m_int_CurrentSearchUpConnectionCount_,g_pCMainControl->m_int_CurrentTransferUpConnectionCount_,g_pCMainControl->m_int_currentTransferUpConnectionMax_,g_pCMainControl->m_double_upKBytePerSec_);
	UpStatusLabel->Caption=local_01;
	SubUpStatusLabel->Caption=local_01;
	ny_decryptstring("%E.%!.%!.%t.%;.%&.%3.%e.%!.%!.%u.%;.%!.%&.%3.%e.%!.%0.%&.%3.%e.%!.%&.%9.%/.%2.%g.%L.",local_02);
	sprintf(local_01,local_02,g_pCMainControl->m_int_CurrentSearchDownConnectionCount_,g_pCMainControl->m_int_CurrentTransferDownConnectionCount_,local_00,g_pCMainControl->m_double_downKBytePerSec_);
	DownStatusLabel->Caption=local_01;
	SubDownStatusLabel->Caption=local_01;
	return;
}


void __fastcall TMainForm::ExitClick(TObject * Sender)
{
	Close();
	return;
}


void __fastcall TMainForm::VersionInfoClick(TObject * Sender)
{
	ControlForm->VersionInfoClick(NULLPO);
	return;
}


void __fastcall TMainForm::TabCloseClick(TObject * Sender)
{
	if (TabControl->TabIndex<0) {
		return;
	}
	int local_01=TabControl->TabIndex;
	AnsiString local_00=(TabControl->Tabs->Strings[TabControl->TabIndex]);
	for (int local_02=0; TopCheckListBox->Items->Count>local_02; local_02++) {
		if ((TopCheckListBox->Items->Strings[local_02]==local_00)) {
			TopCheckListBox->Checked[local_02]=false;
		}
	}
	TabControl->Tabs->Delete(TabControl->TabIndex);
	if (TabControl->TabIndex<=local_01) {
		local_01=TabControl->TabIndex-1;
	}
	TabControl->TabIndex=local_01;
	return;
}


void __fastcall TMainForm::SubTabCloseClick(TObject * Sender)
{
	if (SubTabControl->TabIndex<0) {
		return;
	}
	int local_01=SubTabControl->TabIndex;
	AnsiString local_00=(SubTabControl->Tabs->Strings[SubTabControl->TabIndex]);
	for (int local_02=0; BottomCheckListBox->Items->Count>local_02; local_02++) {
		if ((BottomCheckListBox->Items->Strings[local_02]==local_00)) {
			BottomCheckListBox->Checked[local_02]=false;
		}
	}
	SubTabControl->Tabs->Delete(SubTabControl->TabIndex);
	if (SubTabControl->TabIndex<=local_01) {
		local_01=SubTabControl->TabIndex-1;
	}
	SubTabControl->TabIndex=local_01;
	return;
}


void __fastcall TMainForm::SubTabControlMouseDown(TObject * Sender,TMouseButton Button,TShiftState Shift,int X,int Y)
{
	Integer local_00;
	if (Button!=0) {
		local_00=SubTabControl->IndexOfTabAt(X,Y);
		SubTabControl->TabIndex=local_00;
		if (Button==mbMiddle/*2*/) {
			SubTabCloseClick(NULLPO);
			if (SubTabControl->Tabs->Count<=local_00) {
				local_00=SubTabControl->Tabs->Count-1;
			}
			SubTabControl->TabIndex=local_00;
		} else {
			if (local_00>=0) {
				TabControlChange(Sender);
			}
		}
	}
	return;
}


void __fastcall TMainForm::TabControlMouseDown(TObject * Sender,TMouseButton Button,TShiftState Shift,int X,int Y)
{
	Integer local_00;
	if (Button!=0) {
		local_00=TabControl->IndexOfTabAt(X,Y);
		TabControl->TabIndex=local_00;
		if (Button==mbMiddle/*2*/) {
			TabCloseClick(NULLPO);
			if (TabControl->Tabs->Count<=local_00) {
				local_00=TabControl->Tabs->Count-1;
			}
			TabControl->TabIndex=local_00;
		} else {
			if (local_00>=0) {
				TabControlChange(Sender);
			}
		}
	}
	return;
}


void TMainForm::mf_TMainForm_0130()
{
	char local_00[1024];
	if (g_pCMainControl==0) {
		return;
	}
	local_00[0]=0;
	if (! (!(m_char_upperPageType_==pt00||m_char_upperPageType_==pt03)&&(!BottomButton->Down||!(m_char_lowerPageType_==pt00)&&m_char_lowerPageType_!=pt03)||!g_pCMainControl->m_optflg_UseBbsOnly_) ) {
		sprintf(local_00,"注意：BBS専用ノードに設定されているためファイル共有機能\が使えません");
		StatusBar->Color=(TColor)0x0000FFFF;
	}
	if (! (m_char_upperPageType_!=pt09||g_pCMainControl->m_int_CurrentBBSUpConnectionCount_!=0||g_pCMainControl->m_int_CurrentBBSDownConnectionCount_!=0) ) {
		sprintf(local_00,"注意：BBS検索リンクが繋がっていないので板一覧の取得ができない状態です");
		StatusBar->Color=(TColor)0x0000FFFF;
	}
	if (! (!(m_char_upperPageType_==pt00)&&(!BottomButton->Down||m_char_lowerPageType_!=pt00)||(g_pCMainControl->m_optflg_UseBbsOnly_||!g_pCMainControl->m_optflag_notConnected__)) ) {
		sprintf(local_00,"注意：Port0設定になっているためダウン速度が制限されています");
		StatusBar->Color=(TColor)0x0000FFFF;
	}
	if (g_pCMainControl->m_optflg_showVersionWarning_) {
		sprintf(local_00,"警告：新しいバージョンのWinnyノード接続がありました。Winny本体の最新バージョンを確認してください。");
		StatusBar->Color=(TColor)0x000000FF;
		if (g_int_flag_logged_newversion==0) {
			g_int_flag_logged_newversion=1;
			ny_addlog("新しいバージョンのWinnyノード接続");
		}
	}
	if (g_pCMainControl->m_int_cacheOpenErrorCount_>1000) {
		sprintf(local_00,"警告：キャッシュオープンエラーが多すぎるため通信を停止しました。キャッシュフォルダが破損していないか確認してください。");
		StatusBar->Color=(TColor)0x000000FF;
		if (g_pCMainControl->m_optflag_Connect__) {
			g_pCMainControl->mf_CMainControl_0320();
			g_pCMainControl->m_optflag_Connect__=false;
			ny_addlog("キャッシュオープンエラー警告");
		}
	}
	if (g_pCMainControl->m_flag_downFolderDiskFull_) {
		sprintf(local_00,"警告：ダウンフォルダ（%s）の空き容量が足りません。キャッシュを一部消すなどして空き容量を確保してください。",g_pCMainControl->m_sz_DownFolderPath_);
		StatusBar->Color=(TColor)0x000000FF;
		if (g_int_flag_logged_downfolderdisk==0) {
			g_int_flag_logged_downfolderdisk=1;
			ny_addlog("ダウンフォルダ容量警告");
		}
	}
	if (g_pCMainControl->m_flag_cacheFolderDiskFull_) {
		sprintf(local_00,"警告：キャッシュフォルダ（%s）の空き容量が足りません。キャッシュを一部消すなどして空き容量を確保してください。",g_pCMainControl->m_sz_CacheFolderPath_);
		StatusBar->Color=(TColor)0x000000FF;
		if (g_int_flag_logged_cachefolderdisk==0) {
			g_int_flag_logged_cachefolderdisk=1;
			ny_addlog("キャッシュフォルダ容量警告");
		}
	}
	if (g_pCMainControl->m_int_portWarnedCount_>=30) {
		CGlobalLock CGLock;
		sprintf(local_00,"警告：ポート警告が多すぎるので接続停止しました。ポート設定を見直して再起動してください。");
		StatusBar->Color=(TColor)0x000000FF;
		if (g_pCMainControl->m_optflag_Connect__) {
			g_pCMainControl->mf_CMainControl_0320();
			g_pCMainControl->m_optflag_Connect__=false;
			ny_addlog("ポート警告による接続停止");
		}
	}
	if (local_00[0]!=0) {
		StatusBar->SimpleText=local_00;
		if (!StatusBar->Visible) {
			StatusBar->Visible=true;
		}
	} else {
		StatusBar->Visible=false;
	}
	if (! (!g_pCMainControl->m_optflag_notConnected__||!g_pCMainControl->m_flg_unk15469) ) {
		g_bool_unk100=true;
		Timer->Enabled=false;
		g_pTIniFile->WriteInteger("Option","NotConnected",1);
		sprintf(local_00,"ポート番号(%d)は既に他のアプリで使われています。ポート設定を見直してください",g_pCMainControl->m_port_accept_);
		MessageBox(NULL,local_00,"Winny",0x00042030);
		g_bool_unk100=true;
		ControlForm->Close();
	} else {
		if (! (!g_pCMainControl->m_optflag_notConnected__||!g_pCMainControl->m_flg_unk15470) ) {
			Timer->Enabled=false;
			g_bool_unk100=true;
			g_pTIniFile->WriteInteger("Option","NotConnected",1);
			sprintf(local_00,"BBSポート番号(%d)は既に他のアプリで使われています。ポート設定を見直してください",g_pCMainControl->m_port_bbsaccept_);
			MessageBox(NULL,local_00,"Winny",0x00042030);
			g_bool_unk100=true;
			ControlForm->Close();
		}
	}
}


void TMainForm::mf_TMainForm_0140()
{
	bool local_00;
	if (BbsButton->Down) {
		SearchHistoryMenu->Visible=false;
		BoardToolBar->Visible=true;
		BbsToolBar->Visible=true;
		TopToolBar->Visible=false;
		BottomToolBar->Visible=false;
	} else {
		SearchHistoryMenu->Visible=true;
		BoardToolBar->Visible=false;
		BbsToolBar->Visible=false;
		TopToolBar->Visible=true;
		BottomToolBar->Visible=true;
		if ((int)m_char_upperPageType_!=g_int_unk005_70) {
			g_int_unk005_70=(int)m_char_upperPageType_;
			switch ((int)m_char_upperPageType_) {
			case 0:
				TopToolButton1->Visible=true;
				TopToolButton2->Visible=true;
				TopToolButton3->Visible=true;
				TopToolButton4->Visible=true;
				TopToolButton5->Visible=true;
				TopToolButton6->Visible=false;
				TopToolButton1->GroupIndex=0;
				TopToolButton2->GroupIndex=1;
				TopToolButton3->GroupIndex=0;
				TopToolButton4->GroupIndex=0;
				TopToolButton5->GroupIndex=0;
				TopToolButton6->GroupIndex=0;
				TopToolButton1->Down=false;
				TopToolButton3->Down=false;
				TopToolButton4->Down=false;
				TopToolButton5->Down=false;
				TopToolButton6->Down=false;
				TopToolButton1->Enabled=true;
				TopToolButton2->Enabled=true;
				TopToolButton5->Enabled=true;
				TopToolButton6->Enabled=true;
				TopToolButton1->Caption="ノード追加";
				TopToolButton2->Caption="接続";
				TopToolButton3->Caption="全切断";
				TopToolButton4->Caption="検索切断";
				TopToolButton5->Caption="アドレス暗号化";
				TopToolButton6->Caption="";
				TopToolButton2->Down=g_pCMainControl->m_optflag_Connect__;
				TopToolButton3->Enabled=g_pCMainControl->m_optflag_Connect__;
				TopToolButton4->Enabled=g_pCMainControl->m_optflag_Connect__;
				ItemImageList->GetBitmap(0,TopToolButton2->Glyph);
				TopToolButton1->Glyph=NULLPO;
				TopToolButton3->Glyph=NULLPO;
				TopToolButton4->Glyph=NULLPO;
				TopToolButton5->Glyph=NULLPO;
				TopToolButton6->Glyph=NULLPO;
				TopToolButton1->Hint="初期接続用のノード情報を追加します";
				TopToolButton2->Hint="外部ノードへの接続・切断を切り替えます";
				TopToolButton3->Hint="検索・転送の全リンクを強制切断します";
				TopToolButton4->Hint="検索に用いる検索リンクのみを強制切断します";
				TopToolButton5->Hint="自ノードを初期ノードとして外部公開するための変換作業を行います";
				TopToolButton6->Hint="";
				break;
			case 1:  
				TopToolButton1->Visible=true;
				TopToolButton2->Visible=true;
				TopToolButton3->Visible=true;
				TopToolButton4->Visible=true;
				TopToolButton5->Visible=true;
				TopToolButton6->Visible=false;
				TopToolButton1->GroupIndex=0;
				TopToolButton2->GroupIndex=0;
				TopToolButton3->GroupIndex=0;
				TopToolButton4->GroupIndex=0;
				TopToolButton5->GroupIndex=0;
				TopToolButton6->GroupIndex=0;
				TopToolButton1->Down=false;
				TopToolButton2->Down=false;
				TopToolButton3->Down=false;
				TopToolButton4->Down=false;
				TopToolButton5->Down=false;
				TopToolButton6->Down=false;
				TopToolButton3->Enabled=true;
				TopToolButton4->Enabled=true;
				TopToolButton6->Enabled=true;
				TopToolButton1->Caption="ノード追加";
				TopToolButton2->Caption="BBS切断";
				TopToolButton3->Caption="キャッシュクリア";
				TopToolButton4->Caption="外部ブラウザ";
				TopToolButton5->Caption="ポート検索";
				TopToolButton6->Caption="";
				TopToolButton2->Enabled=g_pCMainControl->m_optflag_Connect__;
				TopToolButton5->Enabled=!g_pCMainControl->m_flg_unk15511;
				TopToolButton1->Glyph=NULLPO;
				TopToolButton2->Glyph=NULLPO;
				TopToolButton3->Glyph=NULLPO;
				TopToolButton4->Glyph=NULLPO;
				TopToolButton5->Glyph=NULLPO;
				TopToolButton6->Glyph=NULLPO;
				TopToolButton1->Hint="BBS初期接続用のノード情報を追加します";
				TopToolButton2->Hint="BBSキーの検索に用いるBBS検索リンクのみ強制切断します";
				TopToolButton3->Hint="初期接続用のノード情報を追加します";
				TopToolButton4->Hint="キャッシュフォルダ内のBBSキャッシュのみを全削除します";
				TopToolButton5->Hint="他のノードの外部ブラウザ用ポートを検索してBBSブラウザ起動します";
				TopToolButton6->Hint="";
				break;
			case 2:
				TopToolButton1->Visible=true;
				TopToolButton2->Visible=true;
				TopToolButton3->Visible=true;
				TopToolButton4->Visible=true;
				TopToolButton5->Visible=true;
				TopToolButton6->Visible=false;
				TopToolButton1->Down=false;
				TopToolButton2->Down=false;
				TopToolButton3->Down=false;
				TopToolButton4->Down=false;
				TopToolButton5->Down=false;
				TopToolButton6->Down=false;
				TopToolButton1->GroupIndex=0;
				TopToolButton2->GroupIndex=0;
				TopToolButton3->GroupIndex=0;
				TopToolButton4->GroupIndex=0;
				TopToolButton5->GroupIndex=0;
				TopToolButton6->GroupIndex=0;
				TopToolButton1->Enabled=true;
				TopToolButton2->Enabled=true;
				TopToolButton4->Enabled=true;
				TopToolButton5->Enabled=true;
				TopToolButton6->Enabled=true;
				TopToolButton1->Caption="フォルダ追加";
				TopToolButton2->Caption="フォルダ削除";
				TopToolButton3->Caption="再チェック";
				TopToolButton4->Caption="UPフォルダ開";
				TopToolButton5->Caption="ダウンフォルダ";
				TopToolButton6->Caption="";
				TopToolButton3->Enabled=!g_pCMainControl->m_flg_unk15510;
				TopToolButton1->Glyph=NULLPO;
				TopToolButton2->Glyph=NULLPO;
				TopToolButton3->Glyph=NULLPO;
				TopToolButton4->Glyph=NULLPO;
				TopToolButton5->Glyph=NULLPO;
				TopToolButton6->Glyph=NULLPO;
				TopToolButton1->Hint="外部に公開するアップフォルダを追加します";
				TopToolButton2->Hint="公開リストからアップフォルダを削除します";
				TopToolButton3->Hint="アップフォルダとキャッシュフォルダ内を再チェックします";
				TopToolButton4->Hint="選択したアップフォルダを開きます";
				TopToolButton5->Hint="ダウンロードしたファイルが格納されるダウンフォルダを開きます";
				TopToolButton6->Hint="";
				break;
			case 3:
				TopToolButton1->Visible=true;
				TopToolButton2->Visible=true;
				TopToolButton3->Visible=true;
				TopToolButton4->Visible=true;
				TopToolButton5->Visible=false;
				TopToolButton6->Visible=false;
				TopToolButton4->Down=false;
				TopToolButton1->GroupIndex=3;
				TopToolButton2->GroupIndex=4;
				TopToolButton3->GroupIndex=5;
				TopToolButton4->GroupIndex=0;
				TopToolButton5->GroupIndex=0;
				TopToolButton6->GroupIndex=0;
				TopToolButton1->Enabled=true;
				TopToolButton2->Enabled=true;
				TopToolButton3->Enabled=true;
				TopToolButton4->Enabled=true;
				TopToolButton5->Enabled=true;
				TopToolButton6->Enabled=true;
				TopToolButton1->Caption="UPフォルダ内";
				TopToolButton2->Caption="完全キャッシュ";
				TopToolButton3->Caption="部分キャッシュ";
				TopToolButton4->Caption="ダウン優先度";
				TopToolButton5->Caption="";
				TopToolButton6->Caption="";
				TopToolButton1->Down=g_pCMainControl->m_optflg_displayUpFile_;
				TopToolButton2->Down=g_pCMainControl->m_optflg_displayCacheFile_;
				TopToolButton3->Down=g_pCMainControl->m_optflg_displayTmpCacheFile_;
				ItemImageList->GetBitmap(0,TopToolButton1->Glyph);
				ItemImageList->GetBitmap(0,TopToolButton2->Glyph);
				ItemImageList->GetBitmap(0,TopToolButton3->Glyph);
				TopToolButton4->Glyph=NULLPO;
				TopToolButton5->Glyph=NULLPO;
				TopToolButton6->Glyph=NULLPO;
				TopToolButton1->Hint="自分のアップフォルダ内のファイルを検索結果に含めます";
				TopToolButton2->Hint="キャッシュフォルダ内の完全キャッシュを検索結果に含めます";
				TopToolButton3->Hint="キャッシュフォルダ内のダウン不可能\な部分キャッシュを検索結果に含めます";
				TopToolButton4->Hint="自動ダウンでダウン対象が複数ある場合の選択優先度設定";
				TopToolButton5->Hint="";
				TopToolButton6->Hint="";
				break;
			case 4:
				TopToolButton1->Visible=true;
				TopToolButton2->Visible=true;
				TopToolButton3->Visible=true;
				TopToolButton4->Visible=true;
				TopToolButton5->Visible=true;
				TopToolButton6->Visible=false;
				TopToolButton1->Enabled=true;
				TopToolButton2->Enabled=true;
				TopToolButton3->Enabled=true;
				TopToolButton4->Enabled=true;
				TopToolButton5->Enabled=true;
				TopToolButton6->Enabled=true;
				TopToolButton1->GroupIndex=0;
				TopToolButton2->GroupIndex=0;
				TopToolButton3->GroupIndex=0;
				TopToolButton4->GroupIndex=0;
				TopToolButton5->GroupIndex=0;
				TopToolButton6->GroupIndex=0;
				TopToolButton1->Caption="ダウン追加";
				TopToolButton2->Caption="リスト削除";
				TopToolButton3->Caption="リスト編集";
				TopToolButton4->Caption="リスト再読";
				TopToolButton5->Caption="未変換チェック";
				TopToolButton6->Caption="";
				TopToolButton1->Down=false;
				TopToolButton2->Down=false;
				TopToolButton3->Down=false;
				TopToolButton4->Down=false;
				TopToolButton5->Down=false;
				TopToolButton6->Down=false;
				TopToolButton1->Glyph=NULLPO;
				TopToolButton2->Glyph=NULLPO;
				TopToolButton3->Glyph=NULLPO;
				TopToolButton4->Glyph=NULLPO;
				TopToolButton5->Glyph=NULLPO;
				TopToolButton6->Glyph=NULLPO;
				TopToolButton1->Hint="自動的にダウンロードをかける条件を新規追加します";
				TopToolButton2->Hint="ダウンロードリストから選択項目を削除します";
				TopToolButton3->Hint="ダウンロードリスト設定ファイルをエディタで開きます";
				TopToolButton4->Hint="ダウンロードリスト設定ファイルを再読み込みします";
				TopToolButton5->Hint="未変換になっているファイルを再変換（設定でキャッシュ変換がOFF用）";
				TopToolButton6->Hint="";
				break;
			case 5:  
				TopToolButton1->Visible=true;
				TopToolButton2->Visible=true;
				TopToolButton3->Visible=true;
				TopToolButton4->Visible=true;
				TopToolButton5->Visible=true;
				TopToolButton6->Visible=false;
				TopToolButton1->Enabled=true;
				TopToolButton2->Enabled=true;
				TopToolButton3->Enabled=true;
				TopToolButton4->Enabled=true;
				TopToolButton5->Enabled=true;
				TopToolButton6->Enabled=true;
				TopToolButton1->GroupIndex=0;
				TopToolButton2->GroupIndex=0;
				TopToolButton3->GroupIndex=0;
				TopToolButton4->GroupIndex=0;
				TopToolButton5->GroupIndex=1;
				TopToolButton6->GroupIndex=0;
				TopToolButton1->Caption="無視追加";
				TopToolButton2->Caption="リスト削除";
				TopToolButton3->Caption="リスト編集";
				TopToolButton4->Caption="リスト再読";
				TopToolButton5->Caption="検索にも反映";
				TopToolButton6->Caption="";
				TopToolButton1->Down=false;
				TopToolButton2->Down=false;
				TopToolButton3->Down=false;
				TopToolButton4->Down=false;
				TopToolButton6->Down=false;
				TopToolButton5->Down=g_pCMainControl->m_optflg_searchIgnore_;
				ItemImageList->GetBitmap(0,TopToolButton5->Glyph);
				TopToolButton1->Glyph=NULLPO;
				TopToolButton2->Glyph=NULLPO;
				TopToolButton3->Glyph=NULLPO;
				TopToolButton4->Glyph=NULLPO;
				TopToolButton6->Glyph=NULLPO;
				TopToolButton1->Hint="ダウンロードを抑制する無視条件を追加します";
				TopToolButton2->Hint="無視リストから選択要素を削除します";
				TopToolButton3->Hint="無視リスト設定ファイルをエディタで編集します";
				TopToolButton4->Hint="無視リスト設定ファイルを再読み込みします";
				TopToolButton5->Hint="無視条件をファイル検索結果にも反映させます";
				TopToolButton6->Hint="";
				break;
			case 6:
				TopToolButton1->Visible=true;
				TopToolButton2->Visible=true;
				TopToolButton3->Visible=true;
				TopToolButton4->Visible=true;
				TopToolButton5->Visible=true;
				TopToolButton6->Visible=true;
				TopToolButton1->Enabled=true;
				TopToolButton2->Enabled=true;
				TopToolButton3->Enabled=true;
				TopToolButton4->Enabled=true;
				TopToolButton5->Enabled=true;
				TopToolButton6->Enabled=true;
				TopToolButton1->GroupIndex=0;
				TopToolButton2->GroupIndex=0;
				TopToolButton3->GroupIndex=1;
				TopToolButton4->GroupIndex=2;
				TopToolButton5->GroupIndex=3;
				TopToolButton6->GroupIndex=4;
				TopToolButton1->Caption="リスト消去";
				TopToolButton2->Caption="タスク取り消し";
				TopToolButton3->Caption="変換保留";
				TopToolButton4->Caption="多重ダウン";
				TopToolButton5->Caption="低速自動切断";
				TopToolButton6->Caption="帯域制限";
				TopToolButton1->Down=false;
				TopToolButton2->Down=false;
				TopToolButton3->Down=g_pCMainControl->m_flg_unk15509;
				TopToolButton4->Down=g_pCMainControl->m_optflg_useMultiDownload_;
				TopToolButton5->Down=g_pCMainControl->m_optflg_cutSlowTransfer_;
				TopToolButton6->Down=g_pCMainControl->m_optflg_useTransferLimit_;
				ItemImageList->GetBitmap(0,TopToolButton3->Glyph);
				ItemImageList->GetBitmap(0,TopToolButton4->Glyph);
				ItemImageList->GetBitmap(0,TopToolButton5->Glyph);
				ItemImageList->GetBitmap(0,TopToolButton6->Glyph);
				TopToolButton1->Glyph=NULLPO;
				TopToolButton2->Glyph=NULLPO;
				TopToolButton1->Hint="終了しているタスク表\示を消去します";
				TopToolButton2->Hint="選択しているタスクを取り消します";
				TopToolButton3->Hint="キャッシュ変換タスクを一時的に停止させます（負荷を下げる用）";
				TopToolButton4->Hint="一つのダウン条件で複数のダウンタスクを生成するかどうか";
				TopToolButton5->Hint="ダウン速度が20KB/s以下のダウン転送リンクを自動的に切断します";
				TopToolButton6->Hint="設定ダイアログでの自ノードアップ速度以下にダウン・アップ速度を帯域制限します";
				break;
			case 7:  
				TopToolButton1->Visible=true;
				TopToolButton2->Visible=false;
				TopToolButton3->Visible=false;
				TopToolButton4->Visible=false;
				TopToolButton5->Visible=false;
				TopToolButton6->Visible=false;
				TopToolButton1->Enabled=true;
				TopToolButton2->Enabled=true;
				TopToolButton3->Enabled=true;
				TopToolButton4->Enabled=true;
				TopToolButton5->Enabled=true;
				TopToolButton6->Enabled=true;
				TopToolButton1->GroupIndex=0;
				TopToolButton2->GroupIndex=0;
				TopToolButton3->GroupIndex=0;
				TopToolButton4->GroupIndex=0;
				TopToolButton5->GroupIndex=0;
				TopToolButton6->GroupIndex=0;
				TopToolButton1->Caption="ログ消去";
				TopToolButton2->Caption="";
				TopToolButton3->Caption="";
				TopToolButton4->Caption="";
				TopToolButton5->Caption="";
				TopToolButton6->Caption="";
				TopToolButton1->Glyph=NULLPO;
				TopToolButton2->Glyph=NULLPO;
				TopToolButton3->Glyph=NULLPO;
				TopToolButton4->Glyph=NULLPO;
				TopToolButton5->Glyph=NULLPO;
				TopToolButton6->Glyph=NULLPO;
				TopToolButton1->Hint="";
				TopToolButton2->Hint="";
				TopToolButton3->Hint="";
				TopToolButton4->Hint="";
				TopToolButton5->Hint="";
				TopToolButton6->Hint="";
				break;
			case 8:  
				TopToolButton1->Visible=false;
				TopToolButton2->Visible=false;
				TopToolButton3->Visible=false;
				TopToolButton4->Visible=false;
				TopToolButton5->Visible=false;
				TopToolButton6->Visible=false;
				TopToolButton1->Enabled=true;
				TopToolButton2->Enabled=true;
				TopToolButton3->Enabled=true;
				TopToolButton4->Enabled=true;
				TopToolButton5->Enabled=true;
				TopToolButton6->Enabled=true;
				TopToolButton1->GroupIndex=0;
				TopToolButton2->GroupIndex=0;
				TopToolButton3->GroupIndex=0;
				TopToolButton4->GroupIndex=0;
				TopToolButton5->GroupIndex=0;
				TopToolButton6->GroupIndex=0;
				TopToolButton1->Caption="";
				TopToolButton2->Caption="";
				TopToolButton3->Caption="";
				TopToolButton4->Caption="";
				TopToolButton5->Caption="";
				TopToolButton6->Caption="";
				TopToolButton1->Glyph=NULLPO;
				TopToolButton2->Glyph=NULLPO;
				TopToolButton3->Glyph=NULLPO;
				TopToolButton4->Glyph=NULLPO;
				TopToolButton5->Glyph=NULLPO;
				TopToolButton6->Glyph=NULLPO;
				TopToolButton1->Hint="";
				TopToolButton2->Hint="";
				TopToolButton3->Hint="";
				TopToolButton4->Hint="";
				TopToolButton5->Hint="";
				TopToolButton6->Hint="";
			}
		}
		if ((int)m_char_lowerPageType_!=g_int_unk006_70) {
			g_int_unk006_70=(int)m_char_lowerPageType_;
			switch ((int)m_char_lowerPageType_) {
			case 0:  
				BottomToolButton1->Visible=true;
				BottomToolButton2->Visible=true;
				BottomToolButton3->Visible=true;
				BottomToolButton4->Visible=true;
				BottomToolButton5->Visible=true;
				BottomToolButton6->Visible=false;
				BottomToolButton1->GroupIndex=0;
				BottomToolButton2->GroupIndex=1;
				BottomToolButton3->GroupIndex=0;
				BottomToolButton4->GroupIndex=0;
				BottomToolButton5->GroupIndex=0;
				BottomToolButton6->GroupIndex=0;
				BottomToolButton1->Down=false;
				BottomToolButton3->Down=false;
				BottomToolButton4->Down=false;
				BottomToolButton5->Down=false;
				BottomToolButton6->Down=false;
				BottomToolButton1->Enabled=true;
				BottomToolButton2->Enabled=true;
				BottomToolButton5->Enabled=true;
				BottomToolButton6->Enabled=true;
				BottomToolButton1->Caption="ノード追加";
				BottomToolButton2->Caption="接続";
				BottomToolButton3->Caption="全切断";
				BottomToolButton4->Caption="検索切断";
				BottomToolButton5->Caption="アドレス暗号化";
				BottomToolButton6->Caption="";
				BottomToolButton2->Down=g_pCMainControl->m_optflag_Connect__;
				BottomToolButton3->Enabled=g_pCMainControl->m_optflag_Connect__;
				BottomToolButton4->Enabled=g_pCMainControl->m_optflag_Connect__;
				ItemImageList->GetBitmap(0,BottomToolButton2->Glyph);
				BottomToolButton1->Glyph=NULLPO;
				BottomToolButton3->Glyph=NULLPO;
				BottomToolButton4->Glyph=NULLPO;
				BottomToolButton5->Glyph=NULLPO;
				BottomToolButton6->Glyph=NULLPO;
				BottomToolButton1->Hint="初期接続用のノード情報を追加します";
				BottomToolButton2->Hint="外部ノードへの接続・切断を切り替えます";
				BottomToolButton3->Hint="検索・転送の全リンクを強制切断します";
				BottomToolButton4->Hint="検索に用いる検索リンクのみを強制切断します";
				BottomToolButton5->Hint="自ノードを初期ノードとして外部公開するための変換作業を行います";
				BottomToolButton6->Hint="";
				break;
			case 1:
				BottomToolButton1->Visible=true;
				BottomToolButton2->Visible=true;
				BottomToolButton3->Visible=true;
				BottomToolButton4->Visible=true;
				BottomToolButton5->Visible=true;
				BottomToolButton6->Visible=false;
				BottomToolButton1->GroupIndex=0;
				BottomToolButton2->GroupIndex=0;
				BottomToolButton3->GroupIndex=0;
				BottomToolButton4->GroupIndex=0;
				BottomToolButton5->GroupIndex=0;
				BottomToolButton6->GroupIndex=0;
				BottomToolButton1->Down=false;
				BottomToolButton2->Down=false;
				BottomToolButton3->Down=false;
				BottomToolButton4->Down=false;
				BottomToolButton5->Down=false;
				BottomToolButton6->Down=false;
				BottomToolButton3->Enabled=true;
				BottomToolButton4->Enabled=true;
				BottomToolButton6->Enabled=true;
				BottomToolButton1->Caption="ノード追加";
				BottomToolButton2->Caption="BBS切断";
				BottomToolButton3->Caption="キャッシュクリア";
				BottomToolButton4->Caption="外部ブラウザ";
				BottomToolButton5->Caption="ポート検索";
				BottomToolButton6->Caption="";
				BottomToolButton2->Enabled=g_pCMainControl->m_optflag_Connect__;
				BottomToolButton5->Enabled=!g_pCMainControl->m_flg_unk15511;
				BottomToolButton1->Glyph=NULLPO;
				BottomToolButton2->Glyph=NULLPO;
				BottomToolButton3->Glyph=NULLPO;
				BottomToolButton4->Glyph=NULLPO;
				BottomToolButton5->Glyph=NULLPO;
				BottomToolButton6->Glyph=NULLPO;
				BottomToolButton1->Hint="BBS初期接続用のノード情報を追加します";
				BottomToolButton2->Hint="BBSキーの検索に用いるBBS検索リンクのみ強制切断します";
				BottomToolButton3->Hint="初期接続用のノード情報を追加します";
				BottomToolButton4->Hint="キャッシュフォルダ内のBBSキャッシュのみを全削除します";
				BottomToolButton5->Hint="他のノードの外部ブラウザ用ポートを検索してBBSブラウザ起動します";
				BottomToolButton6->Hint="";
				break;
			case 2:
				BottomToolButton1->Visible=true;
				BottomToolButton2->Visible=true;
				BottomToolButton3->Visible=true;
				BottomToolButton4->Visible=true;
				BottomToolButton5->Visible=true;
				BottomToolButton6->Visible=false;
				BottomToolButton1->Down=false;
				BottomToolButton2->Down=false;
				BottomToolButton3->Down=false;
				BottomToolButton4->Down=false;
				BottomToolButton5->Down=false;
				BottomToolButton6->Down=false;
				BottomToolButton1->GroupIndex=0;
				BottomToolButton2->GroupIndex=0;
				BottomToolButton3->GroupIndex=0;
				BottomToolButton4->GroupIndex=0;
				BottomToolButton5->GroupIndex=0;
				BottomToolButton6->GroupIndex=0;
				BottomToolButton1->Enabled=true;
				BottomToolButton2->Enabled=true;
				BottomToolButton4->Enabled=true;
				BottomToolButton5->Enabled=true;
				BottomToolButton6->Enabled=true;
				BottomToolButton1->Caption="フォルダ追加";
				BottomToolButton2->Caption="フォルダ削除";
				BottomToolButton3->Caption="再チェック";
				BottomToolButton4->Caption="UPフォルダ開";
				BottomToolButton5->Caption="ダウンフォルダ";
				BottomToolButton6->Caption="";
				BottomToolButton3->Enabled=!g_pCMainControl->m_flg_unk15510;
				BottomToolButton1->Glyph=NULLPO;
				BottomToolButton2->Glyph=NULLPO;
				BottomToolButton3->Glyph=NULLPO;
				BottomToolButton4->Glyph=NULLPO;
				BottomToolButton5->Glyph=NULLPO;
				BottomToolButton6->Glyph=NULLPO;
				BottomToolButton1->Hint="外部に公開するアップフォルダを追加します";
				BottomToolButton2->Hint="公開リストからアップフォルダを削除します";
				BottomToolButton3->Hint="アップフォルダとキャッシュフォルダ内を再チェックします";
				BottomToolButton4->Hint="選択したアップフォルダを開きます";
				BottomToolButton5->Hint="ダウンロードしたファイルが格納されるダウンフォルダを開きます";
				BottomToolButton6->Hint="";
				break;
			case 3:
				BottomToolButton1->Visible=true;
				BottomToolButton2->Visible=true;
				BottomToolButton3->Visible=true;
				BottomToolButton4->Visible=true;
				BottomToolButton5->Visible=false;
				BottomToolButton6->Visible=false;
				BottomToolButton4->Down=false;
				BottomToolButton1->GroupIndex=3;
				BottomToolButton2->GroupIndex=4;
				BottomToolButton3->GroupIndex=5;
				BottomToolButton4->GroupIndex=0;
				BottomToolButton5->GroupIndex=0;
				BottomToolButton6->GroupIndex=0;
				BottomToolButton1->Enabled=true;
				BottomToolButton2->Enabled=true;
				BottomToolButton3->Enabled=true;
				BottomToolButton4->Enabled=true;
				BottomToolButton5->Enabled=true;
				BottomToolButton6->Enabled=true;
				BottomToolButton1->Caption="UPフォルダ内";
				BottomToolButton2->Caption="完全キャッシュ";
				BottomToolButton3->Caption="部分キャッシュ";
				BottomToolButton4->Caption="ダウン優先度";
				BottomToolButton1->Down=g_pCMainControl->m_optflg_displayUpFile_;
				BottomToolButton2->Down=g_pCMainControl->m_optflg_displayCacheFile_;
				BottomToolButton3->Down=g_pCMainControl->m_optflg_displayTmpCacheFile_;
				ItemImageList->GetBitmap(0,BottomToolButton1->Glyph);
				ItemImageList->GetBitmap(0,BottomToolButton2->Glyph);
				ItemImageList->GetBitmap(0,BottomToolButton3->Glyph);
				BottomToolButton4->Glyph=NULLPO;
				BottomToolButton5->Glyph=NULLPO;
				BottomToolButton6->Glyph=NULLPO;
				BottomToolButton1->Hint="自分のアップフォルダ内のファイルを検索結果に含めます";
				BottomToolButton2->Hint="キャッシュフォルダ内の完全キャッシュを検索結果に含めます";
				BottomToolButton3->Hint="キャッシュフォルダ内のダウン不可能\な部分キャッシュを検索結果に含めます";
				BottomToolButton4->Hint="自動ダウンでダウン対象が複数ある場合の選択優先度設定";
				BottomToolButton5->Hint="";
				BottomToolButton6->Hint="";
				break;
			case 4:  
				BottomToolButton1->Visible=true;
				BottomToolButton2->Visible=true;
				BottomToolButton3->Visible=true;
				BottomToolButton4->Visible=true;
				BottomToolButton5->Visible=true;
				BottomToolButton6->Visible=false;
				BottomToolButton1->Enabled=true;
				BottomToolButton2->Enabled=true;
				BottomToolButton3->Enabled=true;
				BottomToolButton4->Enabled=true;
				BottomToolButton5->Enabled=true;
				BottomToolButton6->Enabled=true;
				BottomToolButton1->GroupIndex=0;
				BottomToolButton2->GroupIndex=0;
				BottomToolButton3->GroupIndex=0;
				BottomToolButton4->GroupIndex=0;
				BottomToolButton5->GroupIndex=0;
				BottomToolButton6->GroupIndex=0;
				BottomToolButton1->Caption="ダウン追加";
				BottomToolButton2->Caption="リスト削除";
				BottomToolButton3->Caption="リスト編集";
				BottomToolButton4->Caption="リスト再読";
				BottomToolButton5->Caption="未変換チェック";
				BottomToolButton6->Caption="";
				BottomToolButton1->Down=false;
				BottomToolButton2->Down=false;
				BottomToolButton3->Down=false;
				BottomToolButton4->Down=false;
				BottomToolButton5->Down=false;
				BottomToolButton6->Down=false;
				BottomToolButton1->Glyph=NULLPO;
				BottomToolButton2->Glyph=NULLPO;
				BottomToolButton3->Glyph=NULLPO;
				BottomToolButton4->Glyph=NULLPO;
				BottomToolButton5->Glyph=NULLPO;
				BottomToolButton6->Glyph=NULLPO;
				BottomToolButton1->Hint="自動的にダウンロードをかける条件を新規追加します";
				BottomToolButton2->Hint="ダウンロードリストから選択項目を削除します";
				BottomToolButton3->Hint="ダウンロードリスト設定ファイルをエディタで開きます";
				BottomToolButton4->Hint="ダウンロードリスト設定ファイルを再読み込みします";
				BottomToolButton5->Hint="未変換になっているファイルを再変換（設定でキャッシュ変換がOFF用）";
				BottomToolButton6->Hint="";
				break;
			case 5:
				BottomToolButton1->Visible=true;
				BottomToolButton2->Visible=true;
				BottomToolButton3->Visible=true;
				BottomToolButton4->Visible=true;
				BottomToolButton5->Visible=true;
				BottomToolButton6->Visible=false;
				BottomToolButton1->Enabled=true;
				BottomToolButton2->Enabled=true;
				BottomToolButton3->Enabled=true;
				BottomToolButton4->Enabled=true;
				BottomToolButton5->Enabled=true;
				BottomToolButton6->Enabled=true;
				BottomToolButton1->GroupIndex=0;
				BottomToolButton2->GroupIndex=0;
				BottomToolButton3->GroupIndex=0;
				BottomToolButton4->GroupIndex=0;
				BottomToolButton5->GroupIndex=1;
				BottomToolButton6->GroupIndex=0;
				BottomToolButton1->Caption="無視追加";
				BottomToolButton2->Caption="リスト削除";
				BottomToolButton3->Caption="リスト編集";
				BottomToolButton4->Caption="リスト再読";
				BottomToolButton5->Caption="検索にも反映";
				BottomToolButton6->Caption="";
				BottomToolButton1->Down=false;
				BottomToolButton2->Down=false;
				BottomToolButton3->Down=false;
				BottomToolButton4->Down=false;
				BottomToolButton6->Down=false;
				BottomToolButton5->Down=g_pCMainControl->m_optflg_searchIgnore_;
				ItemImageList->GetBitmap(0,BottomToolButton5->Glyph);
				BottomToolButton1->Glyph=NULLPO;
				BottomToolButton2->Glyph=NULLPO;
				BottomToolButton3->Glyph=NULLPO;
				BottomToolButton4->Glyph=NULLPO;
				BottomToolButton6->Glyph=NULLPO;
				BottomToolButton1->Hint="ダウンロードを抑制する無視条件を追加します";
				BottomToolButton2->Hint="無視リストから選択要素を削除します";
				BottomToolButton3->Hint="無視リスト設定ファイルをエディタで編集します";
				BottomToolButton4->Hint="無視リスト設定ファイルを再読み込みします";
				BottomToolButton5->Hint="無視条件をファイル検索結果にも反映させます";
				BottomToolButton6->Hint="";
				break;
			case 6:
				BottomToolButton1->Visible=true;
				BottomToolButton2->Visible=true;
				BottomToolButton3->Visible=true;
				BottomToolButton4->Visible=true;
				BottomToolButton5->Visible=true;
				BottomToolButton6->Visible=true;
				BottomToolButton1->Enabled=true;
				BottomToolButton2->Enabled=true;
				BottomToolButton3->Enabled=true;
				BottomToolButton4->Enabled=true;
				BottomToolButton5->Enabled=true;
				BottomToolButton6->Enabled=true;
				BottomToolButton1->GroupIndex=0;
				BottomToolButton2->GroupIndex=0;
				BottomToolButton3->GroupIndex=1;
				BottomToolButton4->GroupIndex=2;
				BottomToolButton5->GroupIndex=3;
				BottomToolButton6->GroupIndex=4;
				BottomToolButton1->Caption="リスト消去";
				BottomToolButton2->Caption="タスク取り消し";
				BottomToolButton3->Caption="変換保留";
				BottomToolButton4->Caption="多重ダウン";
				BottomToolButton5->Caption="低速自動切断";
				BottomToolButton6->Caption="帯域制限";
				BottomToolButton1->Down=false;
				BottomToolButton2->Down=false;
				BottomToolButton3->Down=g_pCMainControl->m_flg_unk15509;
				BottomToolButton4->Down=g_pCMainControl->m_optflg_useMultiDownload_;
				BottomToolButton5->Down=g_pCMainControl->m_optflg_cutSlowTransfer_;
				BottomToolButton6->Down=g_pCMainControl->m_optflg_useTransferLimit_;
				ItemImageList->GetBitmap(0,BottomToolButton3->Glyph);
				ItemImageList->GetBitmap(0,BottomToolButton4->Glyph);
				ItemImageList->GetBitmap(0,BottomToolButton5->Glyph);
				ItemImageList->GetBitmap(0,BottomToolButton6->Glyph);
				BottomToolButton1->Glyph=NULLPO;
				BottomToolButton2->Glyph=NULLPO;
				BottomToolButton1->Hint="終了しているタスク表\示を消去します";
				BottomToolButton2->Hint="選択しているタスクを取り消します";
				BottomToolButton3->Hint="キャッシュ変換タスクを一時的に停止させます（負荷を下げる用）";
				BottomToolButton4->Hint="一つのダウン条件で複数のダウンタスクを生成するかどうか";
				BottomToolButton5->Hint="ダウン速度が20KB/s以下のダウン転送リンクを自動的に切断します";
				BottomToolButton6->Hint="設定ダイアログでの自ノードアップ速度以下にダウン・アップ速度を帯域制限します";
				break;
			case 7:
				BottomToolButton1->Visible=true;
				BottomToolButton2->Visible=false;
				BottomToolButton3->Visible=false;
				BottomToolButton4->Visible=false;
				BottomToolButton5->Visible=false;
				BottomToolButton6->Visible=false;
				BottomToolButton1->Enabled=true;
				BottomToolButton2->Enabled=true;
				BottomToolButton3->Enabled=true;
				BottomToolButton4->Enabled=true;
				BottomToolButton5->Enabled=true;
				BottomToolButton6->Enabled=true;
				BottomToolButton1->GroupIndex=0;
				BottomToolButton2->GroupIndex=0;
				BottomToolButton3->GroupIndex=0;
				BottomToolButton4->GroupIndex=0;
				BottomToolButton5->GroupIndex=0;
				BottomToolButton6->GroupIndex=0;
				BottomToolButton1->Caption="ログ消去";
				BottomToolButton2->Caption="";
				BottomToolButton3->Caption="";
				BottomToolButton4->Caption="";
				BottomToolButton5->Caption="";
				BottomToolButton6->Caption="";
				BottomToolButton1->Glyph=NULLPO;
				BottomToolButton2->Glyph=NULLPO;
				BottomToolButton3->Glyph=NULLPO;
				BottomToolButton4->Glyph=NULLPO;
				BottomToolButton5->Glyph=NULLPO;
				BottomToolButton6->Glyph=NULLPO;
				BottomToolButton1->Hint="";
				BottomToolButton2->Hint="";
				BottomToolButton3->Hint="";
				BottomToolButton4->Hint="";
				BottomToolButton5->Hint="";
				BottomToolButton6->Hint="";
				break;
			case 8:
				BottomToolButton1->Visible=false;
				BottomToolButton2->Visible=false;
				BottomToolButton3->Visible=false;
				BottomToolButton4->Visible=false;
				BottomToolButton5->Visible=false;
				BottomToolButton6->Visible=false;
				BottomToolButton1->Enabled=true;
				BottomToolButton2->Enabled=true;
				BottomToolButton3->Enabled=true;
				BottomToolButton4->Enabled=true;
				BottomToolButton5->Enabled=true;
				BottomToolButton6->Enabled=true;
				BottomToolButton1->GroupIndex=0;
				BottomToolButton2->GroupIndex=0;
				BottomToolButton3->GroupIndex=0;
				BottomToolButton4->GroupIndex=0;
				BottomToolButton5->GroupIndex=0;
				BottomToolButton6->GroupIndex=0;
				BottomToolButton1->Caption="";
				BottomToolButton2->Caption="";
				BottomToolButton3->Caption="";
				BottomToolButton4->Caption="";
				BottomToolButton5->Caption="";
				BottomToolButton6->Caption="";
				BottomToolButton1->Glyph=NULLPO;
				BottomToolButton2->Glyph=NULLPO;
				BottomToolButton3->Glyph=NULLPO;
				BottomToolButton4->Glyph=NULLPO;
				BottomToolButton5->Glyph=NULLPO;
				BottomToolButton6->Glyph=NULLPO;
				BottomToolButton1->Hint="";
				BottomToolButton2->Hint="";
				BottomToolButton3->Hint="";
				BottomToolButton4->Hint="";
				BottomToolButton5->Hint="";
				BottomToolButton6->Hint="";
			}
		}
	}
	ModeTabMenu->AutoPopup=(Boolean)!BbsButton->Down;
	SubModeTabMenu->AutoPopup=(Boolean)!BbsButton->Down;
	NodeMode->Checked=TopCheckListBox->Checked[0];
	BbsNodeMode->Checked=TopCheckListBox->Checked[1];
	FolderMode->Checked=TopCheckListBox->Checked[2];
	FileMode->Checked=TopCheckListBox->Checked[3];
	DownMode->Checked=TopCheckListBox->Checked[4];
	IgnoreMode->Checked=TopCheckListBox->Checked[5];
	TaskMode->Checked=TopCheckListBox->Checked[6];
	LogMode->Checked=TopCheckListBox->Checked[7];
	SystemMode->Checked=TopCheckListBox->Checked[8];
	SubNodeMode->Checked=BottomCheckListBox->Checked[0];
	SubBbsNodeMode->Checked=BottomCheckListBox->Checked[1];
	SubFolderMode->Checked=BottomCheckListBox->Checked[2];
	SubFileMode->Checked=BottomCheckListBox->Checked[3];
	SubDownMode->Checked=BottomCheckListBox->Checked[4];
	SubIgnoreMode->Checked=BottomCheckListBox->Checked[5];
	SubTaskMode->Checked=BottomCheckListBox->Checked[6];
	SubLogMode->Checked=BottomCheckListBox->Checked[7];
	SubSystemMode->Checked=BottomCheckListBox->Checked[8];
	BbsViewCache->Down=g_pCMainControl->m_optflg_displayNonWritableBbs_;
	if (OptionForm!=0) {
		local_00=!(BbsButton->Down||!TopCheckListBox->Checked[3]||!OptionForm->SearchTabUseCheck->Checked)&&((OptionForm)->AlwaysShowSearchTabCheck->Checked||m_char_upperPageType_==pt03);
		if (SearchTabControl->Visible!=local_00) {
			SearchTabControl->Visible=local_00;
		}
		local_00=(!(BbsButton->Down||!BottomCheckListBox->Checked[3]||!OptionForm->SearchTabUseCheck->Checked)&&((OptionForm)->AlwaysShowSearchTabCheck->Checked||m_char_lowerPageType_==pt03));
		if (SubSearchTabControl->Visible!=local_00) {
			SubSearchTabControl->Visible=local_00;
		}
	}
	return;
}


void __fastcall TMainForm::NodeDisconnectButtonClick()
{
	if (! (g_bool_unk100||MessageBox(NULL,"全てのリンクを切断しますか？","Winny",0x00042024)!=6) ) {
		CGlobalLock CGLock;
		g_pCMainControl->mf_CMainControl_0320();
		mf_TMainForm_0140();
	}
	return;
}


void __fastcall TMainForm::NodeSearchDisconnectButtonClick()
{
	CGlobalLock CGLock;
	g_pCMainControl->mf_CMainControl_0330(true);
	return;
}


void __fastcall TMainForm::NodeConnectButtonClick()
{
	char local_00[1024];
	char local_01[1024];
	CGlobalLock CGLock;
	if (!g_pCMainControl->m_optflag_Connect__) {
		sprintf(local_00,"%s%s",/*(const char *)*/g_AppPath,"Noderef.txt");
		g_pCMainControl->mf_CMainControl_1210(local_00,false);
		sprintf(local_00,"%s%s",/*(const char *)*/g_AppPath,"BbsNoderef.txt");
		g_pCMainControl->mf_CMainControl_1210(local_00,true);
		g_pCMainControl->m_optflag_Connect__=true;
		g_pCMainControl->mf_CMainControl_0240();
		g_pTIniFile->WriteInteger("Option","Connect",!(!g_pCMainControl->m_optflag_Connect__)?1:0);
	} else {
		if (MessageBox(NULL,"全てのリンクを切断して接続停止状態にしますか？","Winny",0x00042024)==6) {
			g_pCMainControl->mf_CMainControl_0320();
			g_pCMainControl->m_optflag_Connect__=false;
			if (g_AppPath.Length()!=0) {
				sprintf(local_01,"%s%s",/*(const char *)*/g_AppPath,"Noderef.txt");
				g_pCMainControl->mf_CMainControl_1220(local_01,false,true);
				sprintf(local_01,"%s%s",/*(const char *)*/g_AppPath,"BbsNoderef.txt");
				g_pCMainControl->mf_CMainControl_1220(local_01,true,true);
			}
			g_pTIniFile->WriteInteger("Option","Connect",!(!g_pCMainControl->m_optflag_Connect__)?1:0);
		}
	}
	mf_TMainForm_0140();
	return;
}


void __fastcall TMainForm::NodeAutoDisconnectButtonClick(int arg_0)
{
	g_pCMainControl->m_optflg_autoDisconnect_=!g_pCMainControl->m_optflg_autoDisconnect_;
	g_pTIniFile->WriteInteger("Option","AutoDisconnect",!(!g_pCMainControl->m_optflg_autoDisconnect_)?1:0);
	mf_TMainForm_0140();
	return;
}


void __fastcall TMainForm::BbsNodeDisconnectButtonClick()
{
	CGlobalLock CGLock;
	g_pCMainControl->mf_CMainControl_0340();
	return;
}


void __fastcall TMainForm::BbsPortScanButtonClick()
{
	CGlobalLock CGLock;
	if (!g_pCMainControl->m_flg_unk15511) {
		g_pCMainControl->mf_CMainControl_1050();
	}
	mf_TMainForm_0140();
	return;
}


void __fastcall TMainForm::FolderRefreshButtonClick()
{
	CGlobalLock CGLock;
	g_pCMainControl->mf_CMainControl_0690();
	g_pCMainControl->mf_CMainControl_0380();
	mf_TMainForm_0140();
	return;
}


void __fastcall TMainForm::DownFolderOpenButtonClick()
{
	CGlobalLock CGLock;
	g_pCMainControl->mf_CMainControl_1030(-1);
	return;
}


void __fastcall TMainForm::SearchUpFolderButtonClick()
{
	if (g_pCMainControl==0) {
		return;
	}
	g_pCMainControl->m_optflg_displayUpFile_=(bool)!g_pCMainControl->m_optflg_displayUpFile_;
	g_pTIniFile->WriteInteger("Option","DisplayUpFile",!(!g_pCMainControl->m_optflg_displayUpFile_)?1:0);
	mf_TMainForm_0140();
	TabControlChange(TabControl);
	TabControlChange(SubTabControl);
	return;
}


void __fastcall TMainForm::SearchCacheFolderButtonClick()
{
	if (g_pCMainControl==0) {
		return;
	}
	g_pCMainControl->m_optflg_displayCacheFile_=(bool)!g_pCMainControl->m_optflg_displayCacheFile_;
	g_pTIniFile->WriteInteger("Option","DisplayCacheFile",!(!g_pCMainControl->m_optflg_displayCacheFile_)?1:0);
	mf_TMainForm_0140();
	TabControlChange(TabControl);
	TabControlChange(SubTabControl);
	return;
}


void __fastcall TMainForm::SearchTmpCacheButtonClick()
{
	if (g_pCMainControl==0) {
		return;
	}
	g_pCMainControl->m_optflg_displayTmpCacheFile_=(bool)!g_pCMainControl->m_optflg_displayTmpCacheFile_;
	g_pTIniFile->WriteInteger("Option","DisplayTmpCacheFile",!(!g_pCMainControl->m_optflg_displayTmpCacheFile_)?1:0);
	mf_TMainForm_0140();
	TabControlChange(TabControl);
	TabControlChange(SubTabControl);
	return;
}


void __fastcall TMainForm::DownEditButtonClick()
{
	char local_00[1024];
	SHELLEXECUTEINFO local_01;
	CGlobalLock CGLock;
	sprintf(local_00,"%s%s",/*(const char *)*/g_AppPath,"Download.txt");
	local_01.cbSize=60;
	local_01.hwnd=NULL;
	local_01.fMask=0;
	local_01.lpVerb="open";
	if (g_pCMainControl->m_str_optDownlistEditor_.Length()>0) {
		local_01.lpFile=g_pCMainControl->m_str_optDownlistEditor_.c_str();
		local_01.lpParameters=local_00;
	} else {
		local_01.lpFile=local_00;
		local_01.lpParameters=NULLPO;
	}
	local_01.lpDirectory=NULLPO;
	local_01.nShow=1;
	local_01.lpIDList=NULLPO;
	ShellExecuteEx(&local_01);
	return;
}


void __fastcall TMainForm::DownReloadButtonClick()
{
	char local_00[1024];
	sprintf(local_00,"%s%s",/*(const char *)*/g_AppPath,"Download.txt");
	CGlobalLock CGLock;
	g_pCMainControl->mf_CMainControl_0090(local_00,true);
	return;
}


void __fastcall TMainForm::IgnoreEditButtonClick()
{
	char local_00[1024];
	SHELLEXECUTEINFO local_01;
	CGlobalLock CGLock;
	sprintf(local_00,"%s%s",/*(const char *)*/g_AppPath,"Ignore.txt");
	local_01.cbSize=60;
	local_01.hwnd=NULL;
	local_01.fMask=0;
	local_01.lpVerb="open";
	if (g_pCMainControl->m_str_optDownlistEditor_.Length()>0) {
		local_01.lpFile=g_pCMainControl->m_str_optDownlistEditor_.c_str();
		local_01.lpParameters=local_00;
	} else {
		local_01.lpFile=local_00;
		local_01.lpParameters=NULLPO;
	}
	local_01.lpDirectory=NULLPO;
	local_01.nShow=1;
	local_01.lpIDList=NULLPO;
	ShellExecuteEx(&local_01);
	return;
}


void __fastcall TMainForm::IgnoreReloadButtonClick()
{
	char local_00[1024];
	sprintf(local_00,"%s%s",/*(const char *)*/g_AppPath,"Ignore.txt");
	CGlobalLock CGLock;
	g_pCMainControl->mf_CMainControl_0100(local_00,true);
	return;
}


void __fastcall TMainForm::IgnoreSearchButtonClick()
{
	g_pCMainControl->m_optflg_searchIgnore_=!g_pCMainControl->m_optflg_searchIgnore_;
	g_pTIniFile->WriteInteger("Option","SearchIgnore",!(!g_pCMainControl->m_optflg_searchIgnore_)?1:0);
	TabControlChange(TabControl);
	TabControlChange(SubTabControl);
	mf_TMainForm_0140();
	return;
}


void __fastcall TMainForm::TaskClearButtonClick(bool arg_0)
{
	CGlobalLock CGLock;
	g_pCMainControl->mf_CMainControl_0630();
	if (arg_0) {
		TabControlChange(SubTabControl);
	} else {
	TabControlChange(TabControl);
	}
}


void __fastcall TMainForm::LogClearButtonClick()
{
	ny_logclear();
	TabControlChange(TabControl);
	return;
}


void __fastcall TMainForm::BbsButtonClick(TObject * Sender)
{
	MainPanel->DisableAlign();
	TopPanel->DisableAlign();
	BottomPanel->DisableAlign();
	if (BbsButton->Down) {
		TopButton->Down=g_pTIniFile->ReadInteger("BbsTopView","Visible",1)>0;	//?true:false;
		BottomButton->Down=g_pTIniFile->ReadInteger("BbsBottomView","Visible",1)>0;	//?true:false;
		LeftButton->Down=g_pTIniFile->ReadInteger("BbsLeftView","Visible",1)>0;	//?true:false;
		SearchHistoryMenu->Visible=false;
	} else {
		TopButton->Down=g_pTIniFile->ReadInteger("TopView","Visible",1)>0;	//?true:false;
		BottomButton->Down=g_pTIniFile->ReadInteger("BottomView","Visible",0)>0;	//?true:false;
		LeftButton->Down=g_pTIniFile->ReadInteger("LeftView","Visible",0)>0;	//?true:false;
		SearchHistoryMenu->Visible=true;
	}
	mf_TMainForm_0080();
	TabControlChange(TabControl);
	TabControlChange(SubTabControl);
	BottomPanel->EnableAlign();
	TopPanel->EnableAlign();
	MainPanel->EnableAlign();
	NodeView->DoubleBuffered=true;
	FolderView->DoubleBuffered=true;
	FileView->DoubleBuffered=true;
	BbsBoardView->DoubleBuffered=true;
	DownView->DoubleBuffered=true;
	IgnoreView->DoubleBuffered=true;
	TaskView->DoubleBuffered=true;
	LogView->DoubleBuffered=true;
	SystemView->DoubleBuffered=true;
	SubNodeView->DoubleBuffered=true;
	SubFolderView->DoubleBuffered=true;
	SubFileView->DoubleBuffered=true;
	SubDownView->DoubleBuffered=true;
	SubIgnoreView->DoubleBuffered=true;
	SubTaskView->DoubleBuffered=true;
	SubLogView->DoubleBuffered=true;
	SubSystemView->DoubleBuffered=true;
	return;
}


void __fastcall TMainForm::DownAddButtonClick()
{
	if (BbsButton->Down) {
		AutoDownForm->KeywordCombo->Items=(BbsSearchComboBox->Items);
	} else {
		AutoDownForm->KeywordCombo->Items=(SearchComboBox->Items);
		AutoDownForm->TripCombo->Items=(TripComboBox->Items);
	}
	AutoDownForm->KeywordCombo->Text="";
	AutoDownForm->TripCombo->Text="";
	AutoDownForm->HashEdit->Text="";
	AutoDownForm->UpperSizeEdit->Text="";
	AutoDownForm->LowerSizeEdit->Text="";
	AutoDownForm->BbsCheck->Checked=false;
	AutoDownForm->AutoDeleteCheck->Checked=false;
	AutoDownForm->IgnoreCheck->Checked=false;
	AutoDownForm->DeleteCheck->Checked=false;
	AutoDownForm->DisconnectCheck->Checked=false;
	AutoDownForm->DeleteCheck->Enabled=false;
	AutoDownForm->DisconnectCheck->Enabled=false;
	AutoDownForm->DisconnectLabel->Enabled=false;
	AutoDownForm->OkButton->Caption="追加";
	AutoDownForm->m_int1=-1;
	AutoDownForm->m_int2=-1;
	AutoDownForm->Show();
	AutoDownForm->KeywordCombo->SetFocus();
	return;
}


void __fastcall TMainForm::IgnoreAddButtonClick()
{
	if (BbsButton->Down) {
		AutoDownForm->KeywordCombo->Items=(BbsSearchComboBox->Items);
	} else {
		AutoDownForm->KeywordCombo->Items=(SearchComboBox->Items);
		AutoDownForm->TripCombo->Items=(TripComboBox->Items);
	}
	AutoDownForm->KeywordCombo->Text="";
	AutoDownForm->TripCombo->Text="";
	AutoDownForm->HashEdit->Text="";
	AutoDownForm->UpperSizeEdit->Text="";
	AutoDownForm->LowerSizeEdit->Text="";
	AutoDownForm->BbsCheck->Checked=false;
	AutoDownForm->AutoDeleteCheck->Checked=false;
	AutoDownForm->IgnoreCheck->Checked=true;
	AutoDownForm->DeleteCheck->Checked=false;
	AutoDownForm->DisconnectCheck->Checked=false;
	AutoDownForm->DeleteCheck->Enabled=true;
	AutoDownForm->DisconnectCheck->Enabled=true;
	AutoDownForm->DisconnectLabel->Enabled=true;
	AutoDownForm->OkButton->Caption="追加";
	AutoDownForm->m_int1=-1;
	AutoDownForm->m_int2=-1;
	AutoDownForm->Show();
	AutoDownForm->KeywordCombo->SetFocus();
	return;
}


void __fastcall TMainForm::DownDeleteButtonClick(TObject * Sender)
{
	TListView * local_00;
	xint local_01;
	int local_02;
	char local_03[1024];
	CGlobalLock CGLock;
	local_00=g_UpperListViews[m_char_upperPageType_];
	local_01=0;
	if (SubDeleteDownList==Sender) {
		local_00=g_LowerListViews[m_char_lowerPageType_];
		local_01=1;
	}
	for (local_02=0; local_00->Items->Count>local_02; local_02++) {
		if (!local_00->Items->Item[local_02]->Selected||g_nazouintarray[local_01][local_02]<0) continue;
		g_pCMainControl->mf_CMainControl_0150(g_nazouintarray[local_01][local_02]);
	}
	if (g_AppPath.Length()!=0) {
		sprintf(local_03,"%s%s",/*(const char *)*/g_AppPath,"Download.txt");
		g_pCMainControl->mf_CMainControl_0110(local_03);
		g_pCMainControl->mf_CMainControl_0090(local_03,true);
	}
	if (SubDeleteDownList==Sender) {
		TabControlChange(SubTabControl);
	} else {
			TabControlChange(TabControl);
	}
}


void __fastcall TMainForm::IgnoreDeleteButtonClick(TObject * Sender)
{
	TListView * local_00;
	xint local_01;
	int local_02;
	char local_03[1024];
	CGlobalLock CGLock;
	local_00=g_UpperListViews[m_char_upperPageType_];
	local_01=0;
	if (SubDeleteIgnoreList==Sender) {
		local_00=g_LowerListViews[m_char_lowerPageType_];
		local_01=1;
	}
	for (local_02=0; local_00->Items->Count>local_02; local_02++) {
		if (!local_00->Items->Item[local_02]->Selected||g_nazouintarray[local_01][local_02]<0) continue;
		g_pCMainControl->mf_CMainControl_0160(g_nazouintarray[local_01][local_02]);
	}
	if (g_AppPath.Length()!=0) {
		sprintf(local_03,"%s%s",/*(const char *)*/g_AppPath,"Ignore.txt");
		g_pCMainControl->mf_CMainControl_0120(local_03);
		g_pCMainControl->mf_CMainControl_0100(local_03,true);
	}
	if (SubDeleteIgnoreList==Sender) {
		TabControlChange(SubTabControl);
	} else {
		TabControlChange(TabControl);
	}
}


void __fastcall TMainForm::FolderDeleteButtonClick(TObject * Sender)
{
	TListView * local_00;
	xint local_01;
	int local_02;
	int tmp;
	char local_03[1024];
	CGlobalLock CGLock;
	local_00=g_UpperListViews[m_char_upperPageType_];
	local_01=0;
	if (SubRemoveFolder==Sender) {
		local_00=g_LowerListViews[m_char_lowerPageType_];
		local_01=1;
	}
	for (local_02=1; local_00->Items->Count>local_02; local_02++) {
		if (! (!local_00->Items->Item[local_02]->Selected||g_nazouintarray[local_01][local_02]<0) ) {
			tmp=g_nazouintarray[local_01][local_02];
			g_pCMainControl->m_vectorCFolder_.begin()[tmp].m_flg_unk3=false;
		}
	}
	if (g_AppPath.Length()!=0) {
		sprintf(local_03,"%s%s",/*(const char *)*/g_AppPath,"UpFolder.txt");
		g_pCMainControl->mf_CMainControl_0050(local_03);
		g_pCMainControl->mf_CMainControl_0380();
	}
	if (SubRemoveFolder==Sender) {
		TabControlChange(SubTabControl);
	} else {
		TabControlChange(TabControl);
	}
}


void __fastcall TMainForm::UpFolderOpenButtonClick(TObject * Sender)
{
	TListView * local_00;
	xint local_01;
	int local_02;
	CGlobalLock CGLock;
	local_00=g_UpperListViews[m_char_upperPageType_];
	local_01=0;
	if (SubOpenFolder==Sender) {
		local_00=g_LowerListViews[m_char_lowerPageType_];
		local_01=1;
	}
	for (local_02=0; local_00->Items->Count>local_02; local_02++) {
		if (!local_00->Items->Item[local_02]->Selected||g_nazouintarray[local_01][local_02]<0) continue;
		g_pCMainControl->mf_CMainControl_1030(g_nazouintarray[local_01][local_02]);
	}
	return;
}


void __fastcall TMainForm::TaskDeleteButtonClick(TObject * Sender)
{
	TListView * local_00;
	xint local_01;
	int local_02;
	CGlobalLock CGLock;
	local_00=g_UpperListViews[m_char_upperPageType_];
	local_01=0;
	if (SubClearTask==Sender) {
		local_00=g_LowerListViews[m_char_lowerPageType_];
		local_01=1;
	}
	for (local_02=0; local_00->Items->Count>local_02; local_02++) {
		if (!local_00->Items->Item[local_02]->Selected||g_nazouintarray[local_01][local_02]<0) continue;
		g_pCMainControl->mf_CMainControl_0640(g_nazouintarray[local_01][local_02]);
	}
	if (local_01==1) {
		TabControlChange(SubTabControl);
	} else {
		TabControlChange(TabControl);
	}
}


void __fastcall TMainForm::NodeAddButtonClick()
{
	if (NodeAddForm==0) {
		NodeAddForm=new TNodeAddForm(this);
	}
	NodeAddForm->NodeEdit->Text="";
	NodeAddForm->Caption="ノード追加";
	NodeAddForm->Show();
	NodeAddForm->NodeEdit->SetFocus();
	return;
}


void __fastcall TMainForm::BbsNodeAddButtonClick()
{
	if (NodeAddForm==0) {
		NodeAddForm=new TNodeAddForm(this);
	}
	NodeAddForm->NodeEdit->Text="";
	NodeAddForm->Caption="BBSノード追加";
	NodeAddForm->Show();
	NodeAddForm->NodeEdit->SetFocus();
	return;
}


void __fastcall TMainForm::FolderAddButtonClick()
{
	FILE * local_00;
	char local_01[1024];
	if (FolderAddForm==0) {
		FolderAddForm=new TFolderAddForm(this);
	}
	FolderAddForm->NameEdit->Text="";
	FolderAddForm->PathEdit->Text="";
	FolderAddForm->TripCombo->Text="";
	sprintf(local_01,"%s%s",/*(const char *)*/g_AppPath,"TripString.txt");
	local_00=fopen(local_01,"rt");
	if (local_00!=0) {
		fclose(local_00);
		FolderAddForm->TripCombo->Items->LoadFromFile(local_01);
	}
	FolderAddForm->Show();
	FolderAddForm->NameEdit->SetFocus();
	return;
}


void __fastcall TMainForm::SearchPriorButtonClick()
{
	if (DownParamForm==0) {
		DownParamForm=new TDownParamForm(this);
	}
	DownParamForm->SizeBar->Position=(Integer)(g_pCMainControl->m_double_optDownParamSize_*100.0);
	DownParamForm->TimeBar->Position=(Integer)(g_pCMainControl->m_double_optDownParamTime_*100.0);
	DownParamForm->BlockBar->Position=(Integer)(g_pCMainControl->m_double_optDownParamBlock_*100.0);
	DownParamForm->ReferBar->Position=(Integer)(g_pCMainControl->m_double_optDownParamRef_*100.0);
	DownParamForm->Show();
	return;
}


void __fastcall TMainForm::IpConvButtonClick()
{
	int local_00;
	_in_addr * local_01;
	char local_02[1024];
	if (IpConvForm==0) {
		IpConvForm=new TIpConvForm(this);
	}
	local_00=g_pCMainControl->m_hostArray[0].m_port1;
	if (*g_pCMainControl->m_sz_MyDDNSname_!=0) {
		sprintf(local_02,"%s:%d",g_pCMainControl->m_sz_MyDDNSname_,local_00);
	} else {
		local_01=&g_pCMainControl->m_hostArray->m_ipaddr3;
		sprintf(local_02,"%d.%d.%d.%d:%d",(unsigned int)local_01->b1,(unsigned int)local_01->b2,(unsigned int)local_01->b3,(unsigned int)local_01->b4,local_00);
	}
	IpConvForm->OriginalEdit->Text=local_02;
	IpConvForm->Show();
	IpConvForm->OriginalEdit->SetFocus();
	return;
}


void __fastcall TMainForm::SystemOptionButtonClick(TObject * Sender)
{
	OptionForm->LineSpeedCombo->Text=g_pCMainControl->m_int_linespeed_;
	OptionForm->DdnsEdit->Text=g_pCMainControl->m_sz_MyDDNSname_;
	OptionForm->FilePortEdit->Text=g_pCMainControl->m_port_accept_;
	OptionForm->BbsPortEdit->Text=g_pCMainControl->m_port_bbsaccept_;
	OptionForm->Port0Check->Checked=g_pCMainControl->m_optflag_notConnected__;
	OptionForm->CachePathEdit->Text=g_pCMainControl->m_sz_CacheFolderPath_;
	OptionForm->DownPathEdit->Text=g_pCMainControl->m_sz_DownFolderPath_;
	OptionForm->BbsPathEdit->Text=g_pCMainControl->m_sz_BbsFolderPath_;
	OptionForm->NotConvertCheck->Checked=g_pCMainControl->m_optflag_notConvert__;
	OptionForm->CacheVersionCheck->Checked=g_pCMainControl->m_optflg_displayNewCache_;
	OptionForm->Show();
	return;
}


void __fastcall TMainForm::AddDownLoadClick(TObject * Sender)
{
	TListView * local_00;
	xint local_01;
	int local_02;
	int local_03;
	int local_04;
	local_00=g_UpperListViews[m_char_upperPageType_];
	local_01=0;
	if (SubAddDownLoad==Sender) {
		local_00=g_LowerListViews[m_char_lowerPageType_];
		local_01=1;
	}
	local_02=0;
	CGlobalLock CGLock;
	for (local_03=0; local_00->Items->Count>local_03; local_03++) {
		if (!local_00->Items->Item[local_03]->Selected||g_nazouintarray[local_01][local_03]<0) continue;
		g_pCMainControl->mf_CMainControl_1020((int)local_01,local_03,false,true,false,local_04,3);
		local_02=local_02+1;
		if (local_02>=100) break;
	}
	if (local_02!=0) {
		mf_TMainForm_0150(pt04);
	}
	return;
}


void __fastcall TMainForm::EditDownListClick(TObject * Sender)
{
	TListView * local_00;
	local_00=g_UpperListViews[m_char_upperPageType_];
	int local_01=0;
	if (SubEditDownList==Sender||SubFileIgnore==Sender) {
		local_00=g_LowerListViews[m_char_lowerPageType_];
		local_01=1;
	}
	AutoDownForm->KeywordCombo->Items=(SearchComboBox->Items);
	AutoDownForm->TripCombo->Items=(TripComboBox->Items);
	for (int local_02=0; local_00->Items->Count>local_02; local_02++) {
		if (! (!local_00->Items->Item[local_02]->Selected||g_nazouintarray[local_01][local_02]<0) ) {
			AutoDownForm->KeywordCombo->Text=local_00->Items->Item[local_02]->Caption;
			AutoDownForm->TripCombo->Text=local_00->Items->Item[local_02]->SubItems->Strings[0];
			AutoDownForm->HashEdit->Text=local_00->Items->Item[local_02]->SubItems->Strings[8];
			break;
		}
	}
	AutoDownForm->UpperSizeEdit->Text="";
	AutoDownForm->LowerSizeEdit->Text="";
	AutoDownForm->BbsCheck->Checked=false;
	AutoDownForm->AutoDeleteCheck->Checked=false;
	AutoDownForm->IgnoreCheck->Checked=(FileIgnore==Sender||SubFileIgnore==Sender);
	AutoDownForm->DeleteCheck->Checked=false;
	AutoDownForm->DisconnectCheck->Checked=false;
	AutoDownForm->DeleteCheck->Enabled=false;
	AutoDownForm->DisconnectCheck->Enabled=false;
	AutoDownForm->DisconnectLabel->Enabled=false;
	AutoDownForm->OkButton->Caption="変更";
	AutoDownForm->m_int1=-1;
	AutoDownForm->m_int2=-1;
	AutoDownForm->Show();
	AutoDownForm->KeywordCombo->SetFocus();
	return;
}


void __fastcall TMainForm::FileIgnoreClick(TObject * Sender)
{
	TListView * local_00;
	unsigned char local_04[16];

	local_00=g_UpperListViews[m_char_upperPageType_];
	int local_01=0;
	if (SubFileIgnore==Sender||SubFileCut==Sender) {
		local_00=g_LowerListViews[m_char_lowerPageType_];
		local_01=1;
	}
	int local_02=0;
	CGlobalLock CGLock;
	for (int local_03=0; local_00->Items->Count>local_03; local_03++) {
		int notused;
		if (!local_00->Items->Item[local_03]->Selected||g_nazouintarray[local_01][local_03]<0) continue;
		ny_aschash2binhash(local_00->Items->Item[local_03]->SubItems->Strings[8].c_str(),local_04);
		//ここのnull stringはこれでいいかは微妙
		g_pCMainControl->mf_CMainControl_0070(local_00->Items->Item[local_03]->Caption.c_str(),NULLPO,local_04,"",0.0,0.0,false,false,(FileCut==Sender||SubFileCut==Sender),(FileCut==Sender||SubFileCut==Sender));
		local_02=local_02+1;
		if (local_02>=100) break;
	}
	if (local_02!=0) {
		mf_TMainForm_0150(pt05);
	}
	return;
}


void __fastcall TMainForm::DownLoadClick(TObject * Sender)
{
	TListView * local_00;
	xint local_01;
	int local_02;
	int local_03;
	int local_04;
	local_00=g_UpperListViews[m_char_upperPageType_];
	local_01=0;
	if (SubDownLoad==Sender) {
		local_00=g_LowerListViews[m_char_lowerPageType_];
		local_01=1;
	}
	local_02=0;
	CGlobalLock CGLock;
	for (local_03=0; local_00->Items->Count>local_03; local_03++) {
		if (!local_00->Items->Item[local_03]->Selected||g_nazouintarray[local_01][local_03]<0) continue;
		g_pCMainControl->mf_CMainControl_1020((int)local_01,local_03,false,false,false,local_04,3);
		local_02=local_02+1;
		if (g_pCMainControl->m_int_currentTransferUpConnectionMax_+1<=local_02) break;
	}
	if (local_02!=0) {
		mf_TMainForm_0150(pt06);
	}
	return;
}


void __fastcall TMainForm::RemoveDownListClick(TObject * Sender)
{
	TListView * local_00;
	xint local_01;

	local_00=g_UpperListViews[m_char_upperPageType_];
	local_01=0;
	if (SubRemoveDownList==Sender) {
		local_00=g_LowerListViews[m_char_lowerPageType_];
		local_01=1;
	}
	CGlobalLock CGLock;

	int local_02;
	int local_03;
	int notused;

	local_02=0;
	for (local_03=0; local_00->Items->Count>local_03; local_03++) {
		if (!local_00->Items->Item[local_03]->Selected||g_nazouintarray[local_01][local_03]<0) continue;
		g_pCMainControl->mf_CMainControl_0080(local_01,local_03);
		local_02=local_02+1;
	}
	if (local_02!=0) {
		mf_TMainForm_0150(pt04);
	}
	return;
}


void __fastcall TMainForm::ConvertClick(TObject * Sender)
{
	TListView * local_00;
	xint local_01;
	int local_02;
	int local_03;
	int local_04;
	local_00=g_UpperListViews[m_char_upperPageType_];
	local_01=0;
	if (SubConvert==Sender) {
		local_00=g_LowerListViews[m_char_lowerPageType_];
		local_01=1;
	}
	local_02=0;
	CGlobalLock CGLock;
	for (local_03=0; local_00->Items->Count>local_03; local_03++) {
		if (!local_00->Items->Item[local_03]->Selected||g_nazouintarray[local_01][local_03]<0) continue;
		g_pCMainControl->mf_CMainControl_1020((int)local_01,local_03,true,false,false,local_04,3);
		local_02=local_02+1;
		if (local_02>=100) break;
	}
	if (local_02!=0) {
		mf_TMainForm_0150(pt06);
	}
	return;
}


void __fastcall TMainForm::GetFileNameClick(TObject * Sender)
{
	TListView * local_01;
	enumPageType local_02;
	xint local_03;
	int local_04;
	bool local_05;
	int local_06;
	unsigned char local_08[16];
	local_01=g_UpperListViews[m_char_upperPageType_];
	local_02=m_char_upperPageType_;
	local_03=0;
	if (SubGetFileName==Sender) {
		local_01=g_LowerListViews[m_char_lowerPageType_];
		local_02=m_char_lowerPageType_;
		local_03=1;
	}
	local_04=0;
	AnsiString local_00="";
	local_05=false;
	for (local_06=0; local_01->Items->Count>local_06; local_06++) {
		if (!local_01->Items->Item[local_06]->Selected||g_nazouintarray[local_03][local_06]<0) continue;
		if (local_05) {
			local_00+="\r\n";
		}
		if (local_02==pt09) {
			ny_aschash2binhash(local_01->Items->Item[local_06]->SubItems->Strings[7].c_str(),local_08);
			CGlobalLock CGLock;
			CKey * local_07=g_pCMainControl->mf_CMainControl_0180(0,local_08);
			if (local_07!=0) {
				local_00+=local_07->mf_CKey_0260();
			} else {
				local_00+=local_01->Items->Item[local_06]->SubItems->Strings[1];
			}
		} else {
			local_00+=local_01->Items->Item[local_06]->Caption;
		}
		local_05=true;
		local_04=local_04+1;
		if (local_04>=100) break;
	}
	Clipboard()->AsText=local_00;
	return;
}


void __fastcall TMainForm::GetFileTripClick(TObject * Sender)
{
	TListView * local_01;
	enumPageType local_02;
	xint local_03;
	int local_04;
	bool local_05;
	int local_06;
	local_01=g_UpperListViews[m_char_upperPageType_];
	local_02=m_char_upperPageType_;
	local_03=0;
	if (SubGetTripName==Sender) {
		local_01=g_LowerListViews[m_char_lowerPageType_];
		local_02=m_char_lowerPageType_;
		local_03=1;
	}
	local_04=0;
	AnsiString local_00="";
	local_05=false;
	for (local_06=0; local_01->Items->Count>local_06; local_06++) {
		if (!local_01->Items->Item[local_06]->Selected||g_nazouintarray[local_03][local_06]<0) continue;
		if (local_05) {
			local_00+="\r\n";
		}
		local_00+=local_01->Items->Item[local_06]->SubItems->Strings[(local_02==pt09)?5:0];
		local_05=true;
		local_04=local_04+1;
		if (local_04>=100) break;
	}
	Clipboard()->AsText=local_00;
	return;
}


void __fastcall TMainForm::GetFileHashClick(TObject * Sender)
{
	TListView * local_01;
	enumPageType local_02;
	xint local_03;
	int local_04;
	bool local_05;
	int local_06;
	local_01=g_UpperListViews[m_char_upperPageType_];
	local_02=m_char_upperPageType_;
	local_03=0;
	if (SubGetHashName==Sender) {
		local_01=g_LowerListViews[m_char_lowerPageType_];
		local_02=m_char_lowerPageType_;
		local_03=1;
	}
	local_04=0;
	AnsiString local_00="";
	local_05=false;
	for (local_06=0; local_01->Items->Count>local_06; local_06++) {
		if (!local_01->Items->Item[local_06]->Selected||g_nazouintarray[local_03][local_06]<0) continue;
		if (local_05) {
			local_00+="\r\n";
		}
		local_00+=local_01->Items->Item[local_06]->SubItems->Strings[(local_02==pt09)?7:8];
		local_05=true;
		local_04=local_04+1;
		if (local_04>=100) break;
	}
	Clipboard()->AsText=local_00;
	return;
}


void __fastcall TMainForm::GetFileInfoClick(TObject * Sender)
{
	TListView * local_01;
	enumPageType local_02;
	xint local_03;
	int local_04;
	bool local_05;
	int local_06;
	unsigned char local_08[16];
	local_01=g_UpperListViews[m_char_upperPageType_];
	local_02=m_char_upperPageType_;
	local_03=0;
	if (SubGetFileInfo==Sender) {
		local_01=g_LowerListViews[m_char_lowerPageType_];
		local_02=m_char_lowerPageType_;
		local_03=1;
	}
	local_04=0;
	AnsiString local_00="";
	local_05=false;
	for (local_06=0; local_01->Items->Count>local_06; local_06++) {
		if (!local_01->Items->Item[local_06]->Selected||g_nazouintarray[local_03][local_06]<0) continue;
		if (local_05) {
			local_00+="\r\n";
		}
		if (local_02==pt09) {
			ny_aschash2binhash(local_01->Items->Item[local_06]->SubItems->Strings[7].c_str(),local_08);
			CGlobalLock CGLock;
			CKey * local_07=g_pCMainControl->mf_CMainControl_0180(0,local_08);
			if (local_07!=0) {
				local_00+=local_07->mf_CKey_0260();
			} else {
				local_00+=local_01->Items->Item[local_06]->SubItems->Strings[1];
			}
			local_00+=" ";
			local_00+=local_01->Items->Item[local_06]->SubItems->Strings[5];
			local_00+=" ";
			local_00+=local_01->Items->Item[local_06]->SubItems->Strings[7];
		} else {
			local_00+=local_01->Items->Item[local_06]->Caption;
			local_00+=" ";
			local_00+=local_01->Items->Item[local_06]->SubItems->Strings[0];
			local_00+=" ";
			local_00+=local_01->Items->Item[local_06]->SubItems->Strings[1];
			local_00+=" ";
			local_00+=local_01->Items->Item[local_06]->SubItems->Strings[8];
		}
		local_05=true;
		local_04=local_04+1;
		if (local_04>=20) break;
	}
	Clipboard()->AsText=local_00;
	return;
}


void __fastcall TMainForm::EditDownClick(TObject * Sender)
{
	TListView * local_00;
	xint local_01;
	int local_02;
	CAutoDownList * local_03;
	char local_04[1024];
	char local_05[256];
	local_00=g_UpperListViews[m_char_upperPageType_];
	local_01=0;
	if (SubEditDown==Sender) {
		local_00=g_LowerListViews[m_char_lowerPageType_];
		local_01=1;
	}
	AutoDownForm->KeywordCombo->Items=(SearchComboBox->Items);
	AutoDownForm->TripCombo->Items=(TripComboBox->Items);
	for (local_02=0; local_00->Items->Count>local_02; local_02++) {
		if (!local_00->Items->Item[local_02]->Selected||g_nazouintarray[local_01][local_02]<0) continue;
		CGlobalLock CGLock;
		local_03=g_pCMainControl->mf_CMainControl_0130(g_nazouintarray[local_01][local_02]);
		AutoDownForm->BbsCheck->Checked=local_03->m_flag_unk5;
		AutoDownForm->AutoDeleteCheck->Checked=local_03->m_flag_unk6;
		AutoDownForm->DisconnectCheck->Checked=local_03->m_flag_unk8;
		AutoDownForm->DeleteCheck->Checked=local_03->m_flag_unk7;
		AutoDownForm->TripCombo->Text=local_03->m_char256_unk2;
		AutoDownForm->KeywordCombo->Text=local_03->m_char256_unk1;
		sprintf(local_04,"%g",local_03->m_double_unk10);
		AutoDownForm->LowerSizeEdit->Text=local_04;
		sprintf(local_04,"%g",local_03->m_double_unk9);
		AutoDownForm->UpperSizeEdit->Text=local_04;
		if (local_03->mf_CAutoDownList_0010()) {
			ny_binhash2aschash(local_03->m_hash,local_05);
			AutoDownForm->HashEdit->Text=local_05;
		} else {
			AutoDownForm->HashEdit->Text="";
		}
		AutoDownForm->m_int1=local_03->m_int_unk21;
		break;
	}
	AutoDownForm->IgnoreCheck->Checked=false;
	AutoDownForm->DeleteCheck->Enabled=false;
	AutoDownForm->DisconnectCheck->Enabled=false;
	AutoDownForm->DisconnectLabel->Enabled=false;
	AutoDownForm->OkButton->Caption="変更";
	AutoDownForm->m_int2=-1;
	AutoDownForm->Show();
	AutoDownForm->KeywordCombo->SetFocus();
	return;
}


void __fastcall TMainForm::EditIgnoreClick(TObject * Sender)
{
	TListView * local_00;
	xint local_01;
	int local_02;
	CAutoDownList * local_03;
	char local_04[1024];
	char local_05[256];
	local_00=g_UpperListViews[m_char_upperPageType_];
	local_01=0;
	if (SubEditIgnore==Sender) {
		local_00=g_LowerListViews[m_char_lowerPageType_];
		local_01=1;
	}
	AutoDownForm->KeywordCombo->Items=(SearchComboBox->Items);
	AutoDownForm->TripCombo->Items=(TripComboBox->Items);
	for (local_02=0; local_00->Items->Count>local_02; local_02++) {
		if (!local_00->Items->Item[local_02]->Selected||g_nazouintarray[local_01][local_02]<0) continue;
		CGlobalLock CGLock;
		local_03=g_pCMainControl->mf_CMainControl_0140(g_nazouintarray[local_01][local_02]);
		AutoDownForm->BbsCheck->Checked=local_03->m_flag_unk5;
		AutoDownForm->AutoDeleteCheck->Checked=local_03->m_flag_unk6;
		AutoDownForm->DisconnectCheck->Checked=local_03->m_flag_unk8;
		AutoDownForm->DeleteCheck->Checked=local_03->m_flag_unk7;
		AutoDownForm->TripCombo->Text=local_03->m_char256_unk2;
		AutoDownForm->KeywordCombo->Text=local_03->m_char256_unk1;
		sprintf(local_04,"%g",local_03->m_double_unk10);
		AutoDownForm->LowerSizeEdit->Text=local_04;
		sprintf(local_04,"%g",local_03->m_double_unk9);
		AutoDownForm->UpperSizeEdit->Text=local_04;
		if (local_03->mf_CAutoDownList_0010()) {
			ny_binhash2aschash(local_03->m_hash,local_05);
			AutoDownForm->HashEdit->Text=local_05;
		} else {
			AutoDownForm->HashEdit->Text="";
		}
		AutoDownForm->m_int2=local_03->m_int_unk21;
		break;
	}
	(*((TAutoDownForm * *)&AutoDownForm))->IgnoreCheck->Checked=true;
	AutoDownForm->DeleteCheck->Enabled=false;
	AutoDownForm->DisconnectCheck->Enabled=false;
	AutoDownForm->DisconnectLabel->Enabled=false;
	AutoDownForm->OkButton->Caption="変更";
	AutoDownForm->m_int1=-1;
	AutoDownForm->Show();
	AutoDownForm->KeywordCombo->SetFocus();
	return;
}


void __fastcall TMainForm::TaskConvertClick(TObject * Sender)
{
	TListView *	local_00=g_UpperListViews[m_char_upperPageType_];
	int	local_01=0;
	if (SubTaskConvert==Sender) {
		local_00=g_LowerListViews[m_char_lowerPageType_];
		local_01=1;
	}
	int	local_02=0;
	{
		CGlobalLock CGLock;
		for (int local_03=0; local_00->Items->Count>local_03; local_03++) {
			if (!local_00->Items->Item[local_03]->Selected||g_nazouintarray[local_01][local_03]<0) continue;
			CAutoDownList *		local_04=g_pCMainControl->mf_CMainControl_0130(g_nazouintarray[local_01][local_03]);
			CWork *		local_05=NULLPO;
			if (local_04->m_int_unk4>=0) {
				local_05=g_pCMainControl->GetWork(local_04->m_int_unk4);
			}
			CKey *		local_06=NULLPO;
			if (! (!(local_05==0)&&local_05->m_worktype_==WORKTYPE01) ) {
				if (local_04->mf_CAutoDownList_0020()) {
					local_06=g_pCMainControl->mf_CMainControl_0180(0,local_04->m_hash_kamo);
				}
			} else {
				local_06=g_pCMainControl->mf_CMainControl_0180(local_05->m_uint_countMax_,local_05->m_uchar16_unk1);
			}
			if (local_06==0) {
				return;
			}
			g_pCMainControl->mf_CMainControl_0980(local_06->m_uint_unk13,local_06->m_hash_tabun,false);
			local_02=local_02+1;
			if (local_02>=100) break;
		}
		if (local_02!=0) {
			mf_TMainForm_0150(pt06);
		}
	}
	//ここex countがうまく取れてない。どういう構造か謎
}


void __fastcall TMainForm::TaskSkipClick(TObject * Sender)
{
	TListView * local_00;
	xint local_01;
	int local_02;
	int dummy;

	local_00=g_UpperListViews[m_char_upperPageType_];
	local_01=0;
	if (SubTaskSkip==Sender) {
		local_00=g_LowerListViews[m_char_lowerPageType_];
		local_01=1;
	}
	CGlobalLock CGLock;
	for (local_02=0; local_00->Items->Count>local_02; local_02++) {
		if (!local_00->Items->Item[local_02]->Selected||g_nazouintarray[local_01][local_02]<0) continue;
		g_pCMainControl->mf_CMainControl_0650(g_nazouintarray[local_01][local_02]);
	}
	return;
}


void __fastcall TMainForm::EditWorkClick(TObject * Sender)
{
	TListView * local_00;
	xint local_01;
	char local_05[1024];
	local_00=g_UpperListViews[m_char_upperPageType_];
	local_01=0;
	if (SubEditWork==Sender) {
		local_00=g_LowerListViews[m_char_lowerPageType_];
		local_01=1;
	}
	AutoDownForm->KeywordCombo->Items=(SearchComboBox->Items);
	AutoDownForm->TripCombo->Items=(TripComboBox->Items);
	CGlobalLock CGLock;
	for (int local_02=0; local_00->Items->Count>local_02; local_02++) {
		if (!local_00->Items->Item[local_02]->Selected||g_nazouintarray[local_01][local_02]<0) continue;
		CWork *		local_03=g_pCMainControl->GetWork(g_nazouintarray[local_01][local_02]);
		if (local_03==0) break;
		int notused;
		CKey *		local_04=NULLPO;
		local_04=g_pCMainControl->mf_CMainControl_0180(local_03->m_uint_countMax_,local_03->m_uchar16_unk1);
		if (local_04==0) {
			MessageBox(NULL,"キーが見つかりません","Winny",0x00042030);
			break;
		}
		AutoDownForm->BbsCheck->Checked=local_04->m_bln_unk308;
		AutoDownForm->TripCombo->Text=local_04->mf_CKey_0000();
		AutoDownForm->KeywordCombo->Text=local_04->mf_CKey_0260();
		ny_binhash2aschash(local_04->m_hash_tabun,local_05);
		AutoDownForm->HashEdit->Text=local_05;
		break;
	}
	AutoDownForm->AutoDeleteCheck->Checked=false;
	AutoDownForm->DisconnectCheck->Checked=false;
	AutoDownForm->DeleteCheck->Checked=false;
	AutoDownForm->LowerSizeEdit->Text="";
	AutoDownForm->UpperSizeEdit->Text="";
	AutoDownForm->IgnoreCheck->Checked=true;
	AutoDownForm->DeleteCheck->Enabled=false;
	AutoDownForm->DisconnectCheck->Enabled=false;
	AutoDownForm->DisconnectLabel->Enabled=false;
	AutoDownForm->OkButton->Caption="追加";
	AutoDownForm->m_int1=-1;
	AutoDownForm->m_int2=-1;
	AutoDownForm->Show();
	AutoDownForm->KeywordCombo->SetFocus();
	return;
}


void __fastcall TMainForm::ConvertWorkClick(TObject * Sender)
{
	TListView * local_00;
	xint local_01;
	int local_02;
	int local_03;
	int dummy;
	
	local_00=g_UpperListViews[m_char_upperPageType_];
	local_01=0;
	if (SubConvertWork==Sender) {
		local_00=g_LowerListViews[m_char_lowerPageType_];
		local_01=1;
	}
	local_02=0;
	CGlobalLock CGLock;
	for (local_03=0; local_00->Items->Count>local_03; local_03++) {
		if (!local_00->Items->Item[local_03]->Selected||g_nazouintarray[local_01][local_03]<0) continue;
		g_pCMainControl->mf_CMainControl_1280(g_nazouintarray[local_01][local_03]);
		local_02=local_02+1;
		if (local_02>=100) break;
	}
	if (local_01==1) {
		TabControlChange(SubTabControl);
	} else {
		TabControlChange(TabControl);
	}
}


void __fastcall TMainForm::LogCopyClick(TObject * Sender)
{
	TListView * local_01;
	local_01=g_UpperListViews[m_char_upperPageType_];
	if (SubLogCopy==Sender) {
		local_01=g_LowerListViews[m_char_lowerPageType_];
	}
	AnsiString local_00="";
	for (int local_02=0; local_01->Items->Count>local_02; local_02++) {
		if (!local_01->Items->Item[local_02]->Selected) continue;
		for (int local_03=0; local_01->Items->Item[local_02]->SubItems->Count>=local_03; local_03++) {
			if (local_03==0) {
				local_00+=local_01->Items->Item[local_02]->Caption;
			} else {
				local_00+=local_01->Items->Item[local_02]->SubItems->Strings[local_03-1];
			}
			if (local_01->Items->Item[local_02]->SubItems->Count<=local_03) continue;
			local_00+="\t";
		}
		local_00+="\r\n";
	}
	Clipboard()->AsText=local_00;
	return;
}


void __fastcall TMainForm::ViewBlockClick(TObject * Sender)
{
	TListView * local_00;
	xint local_01;
	int local_02;
	local_00=g_UpperListViews[m_char_upperPageType_];
	local_01=0;
	if (SubViewBlock==Sender) {
		local_00=g_LowerListViews[m_char_lowerPageType_];
		local_01=1;
	}
	memset(ViewForm->m_hash,0,16);
	for (local_02=0; local_00->Items->Count>local_02; local_02++) {
		if (!local_00->Items->Item[local_02]->Selected||g_nazouintarray[local_01][local_02]<0) continue;
		ny_aschash2binhash(local_00->Items->Item[local_02]->SubItems->Strings[8].c_str(),ViewForm->m_hash);
		break;
	}
	ViewForm->Show();
	ViewForm->ViewGrid->TopRow=1;
	ViewForm->RefreshButtonClick(NULLPO);
	return;
}


void __fastcall TMainForm::ViewDownBlockClick(TObject * Sender)
{
	TListView * local_00;
	xint local_01;
	local_00=g_UpperListViews[m_char_upperPageType_];
	local_01=0;
	if (SubViewDownBlock==Sender) {
		local_00=g_LowerListViews[m_char_lowerPageType_];
		local_01=1;
	}
	memset(ViewForm->m_hash,0,16);
	for (int local_02=0; local_00->Items->Count>local_02; local_02++) {
		if (!local_00->Items->Item[local_02]->Selected||g_nazouintarray[local_01][local_02]<0) continue;
		CGlobalLock CGLock;
		CAutoDownList *		local_03=g_pCMainControl->mf_CMainControl_0130(g_nazouintarray[local_01][local_02]);
		CWork *		local_04=NULLPO;
		if (local_03->m_int_unk4>=0) {
			local_04=g_pCMainControl->GetWork(local_03->m_int_unk4);
		}
		CKey *		local_05=NULLPO;
		if (! (!(local_04==0)&&local_04->m_worktype_==WORKTYPE01) ) {
			if (local_03->mf_CAutoDownList_0020()) {
				local_05=g_pCMainControl->mf_CMainControl_0180(0,local_03->m_hash_kamo);
			}
		} else {
			local_05=g_pCMainControl->mf_CMainControl_0180(local_04->m_uint_countMax_,local_04->m_uchar16_unk1);
		}
		if (local_05!=0) {
			memcpy(ViewForm->m_hash,(unsigned char *)local_05->m_hash_tabun,16);
		}
		break;
	}
	ViewForm->Show();
	ViewForm->ViewGrid->TopRow=1;
	ViewForm->RefreshButtonClick(NULLPO);
	return;
}


void __fastcall TMainForm::ViewWorkClick(TObject * Sender)
{
	TListView * local_00;
	xint local_01;
	local_00=g_UpperListViews[m_char_upperPageType_];
	local_01=0;
	if (SubViewWork==Sender) {
		local_00=g_LowerListViews[m_char_lowerPageType_];
		local_01=1;
	}
	memset(ViewForm->m_hash,0,16);
	for (int local_02=0; local_00->Items->Count>local_02; local_02++) {
		if (!local_00->Items->Item[local_02]->Selected||g_nazouintarray[local_01][local_02]<0) continue;
		CGlobalLock CGLock;
		CWork * local_03=g_pCMainControl->GetWork(g_nazouintarray[local_01][local_02]);
		if (local_03!=0) {
			CKey * local_04=g_pCMainControl->mf_CMainControl_0180(local_03->m_uint_countMax_,local_03->m_uchar16_unk1);
			if (local_04!=0) {
				memcpy(ViewForm->m_hash,(unsigned char *)local_04->m_hash_tabun,16);
			}
		}
		break;
	}
	ViewForm->Show();
	ViewForm->ViewGrid->TopRow=1;
	ViewForm->RefreshButtonClick(NULLPO);
	return;
}


void __fastcall TMainForm::NodeViewDblClick(TObject * Sender)
{
	TListView * local_00;
	enumPageType local_01;
	xint local_02;
	int local_03;
	CGlobalLock CGLock;
	local_00=g_UpperListViews[m_char_upperPageType_];
	local_01=m_char_upperPageType_;
	local_02=0;
	if (! (!(Sender==SubFolderView||Sender==SubFileView||Sender==SubDownView||Sender==SubIgnoreView||Sender==SubTaskView)&&Sender!=SubSystemView) ) {
		local_00=g_LowerListViews[m_char_lowerPageType_];
		local_02=1;
		local_01=m_char_lowerPageType_;
	}
	if (! (local_02!=0||m_char_upperPageType_!=pt09) ) {
		switch (OptionForm->ThreadDoubleClickCombo->ItemIndex) {
		case 1:
			BbsOpenClick(NULLPO);
			break;
		case 2:
			NewBbsOpenClick(NULLPO);
		}
	} else if (local_01==pt04) {
		EditDownClick(!(local_02==0)?SubEditDown:EditDown);
	} else if (local_01==pt05) {
		EditIgnoreClick(!(local_02==0)?SubEditIgnore:EditIgnore);
	} else if (! (!(local_01==pt03)&&local_01!=pt06) ) {
		for (local_03=0; local_00->Items->Count>local_03; local_03++) {
			if (!local_00->Items->Item[local_03]->Selected||g_nazouintarray[local_02][local_03]<0) continue;
			unsigned char local_04=g_pCMainControl->mf_CMainControl_1020((int)local_02,local_03,false,true,local_01==pt06,0,local_01);
			if ((unsigned char)local_04==10) break;
			mf_TMainForm_0150((enumPageType)local_04);
			break;
		}
	} else if (local_01==pt02) {
		for (int local_05=0; local_00->Items->Count>local_05; local_05++) {
			if (!local_00->Items->Item[local_05]->Selected||g_nazouintarray[local_02][local_05]<0) continue;
			g_pCMainControl->mf_CMainControl_1030(g_nazouintarray[local_02][local_05]);
			break;
		}
	}
}


void TMainForm::mf_TMainForm_0150(enumPageType arg_0)
{
	if (! (arg_0==0||!g_pCMainControl->m_optflg_autoTabChange_) ) {
		MainPanel->DisableAlign();
		if (! (m_char_upperPageType_==arg_0||!BottomCheckListBox->Checked[(int)arg_0]) ) {
			if (! (!mf_TMainForm_0110(arg_0)||BottomButton->Down) ) {
				BottomButton->Down=true;
				mf_TMainForm_0080();
			}
			TabControlChange(SubTabControl);
		} else {
			if (TopCheckListBox->Checked[(int)arg_0]) {
				if (! (!mf_TMainForm_0100(arg_0)||TopButton->Down) ) {
					TopButton->Down=true;
					mf_TMainForm_0080();
				}
				TabControlChange(TabControl);
			}
		}
		MainPanel->EnableAlign();
	}
	return;
}



void __fastcall TMainForm::BoardCheckTimerTimer(TObject * Sender)
{
	int local_01;
	if (! (!(BbsButton->Down||!g_pCMainControl->m_flg_unk16402)&&BbsTree->Items->Count<200) ) {
		return;
	}
	local_01=0;
	for (int local_02=0; BbsTree->Items->Count>local_02; local_02++) {
		if ((*BbsTree->Items)[local_02]->Text.AnsiCompare("その他BBS")==0) {
			local_01=local_02;
			break;
		}
	}
	CGlobalLock CGLock;
	map<AnsiString,int> *	local_03=&g_pCMainControl->m_mapStringInt_;
	int	local_04=0;
	map<AnsiString,int>::iterator local_05;
	for (local_05=local_03->begin(); local_05!=local_03->end(); local_05++) {
		AnsiString local_00=local_05->first;
		bool local_06=false;
		for (int local_07=0; BbsTree->Items->Count>local_07; local_07++) {
			if ((*BbsTree->Items)[local_07]->Text.AnsiCompare(local_00)!=0) continue;
			local_06=true;
			local_04=local_04+1;
			break;
		}
		if (!local_06) {
			for (int local_08=0; (BbsTree->Items+1)->Count>local_08; local_08++) {
				if ((*(BbsTree->Items+1))[local_08]->Text.AnsiCompare(local_00)!=0) continue;
				local_06=true;
				local_04=local_04+1;
				break;
			}
		}
		if (! (local_06||local_04>=200) ) {
			TTreeNode * local_09=BbsTree->Items->AddNode(NULLPO,BbsTree->Items->Item[local_01],local_00,NULLPO,(TNodeAttachMode)2);
			if (local_09!=0) {
				local_09->SelectedIndex=(1);
				local_09->ImageIndex=((TImageIndex)1);
			}
		}
	}
	return;
}



void TMainForm::mf_TMainForm_0160()
{
	FILE * local_00;
	int local_01;
	char local_03[1024];

	sprintf((char *)local_03,"%s%s",/*(const char *)*/g_AppPath,"BoardList.txt");
	local_00=fopen((const char *)local_03,"rt");
	if (local_00==0) {
		return;
	}
	while (true) {
		if (feof(local_00)) break;
		local_03[0]=0;
		fgets((char *)local_03,1024,local_00);
		local_01=strlen((const char *)local_03);
		if (! (local_01<=0 || local_03[local_01-1]!=10) ) {
			local_03[local_01-1]=0;
		}
		if ((unsigned char)local_03[0]<=' ') continue;
		TTreeNode * local_02=BbsTree->Items->AddNode(NULLPO,BbsTree->Items->Item[0],(const char *)local_03,NULLPO,naAddChild/*(TNodeAttachMode)2*/);
		if (local_02!=0) {
			local_02->SelectedIndex=(1);
			local_02->ImageIndex=((TImageIndex)1);
		}
	}
	fclose(local_00);
	BbsTree->Items->Item[0]->Expand(true);
	return;
}



void TMainForm::mf_TMainForm_0170()
{
	char local_04[1024];
	BbsMakeForm->BoardListCombo->Items->Clear();
	if (g_AppPath.Length()==0) {
		return;
	}
	sprintf(local_04,"%s%s",/*(const char *)*/g_AppPath,"BoardList.txt");
	FILE * local_01=fopen(local_04,"wt");
	if (local_01==0) {
		return;
	}
	for (int local_02=1; BbsTree->Items->Count>local_02; local_02++) {
		if ((*BbsTree->Items)[local_02]->ImageIndex==0) break;
		fprintf(local_01,"%s\n",/*(const char *)*/(*BbsTree->Items)[local_02]->Text);
		BbsMakeForm->BoardListCombo->Items->Add((*BbsTree->Items)[local_02]->Text);
	}
	fclose(local_01);
	return;
}


void __fastcall TMainForm::RemoveTreeItemClick(TObject * Sender)
{
	if (! (BbsTree->Selected==0||BbsTree->Selected->ImageIndex!=1) ) {
		BbsTree->Items->Delete(BbsTree->Selected);
		mf_TMainForm_0170();
	}
	return;
}


void __fastcall TMainForm::BbsTreeDragDrop(TObject * Sender,TObject * Source,int X,int Y)
{
	TTreeNode * local_00;
	bool local_01;
	int local_02;
	TTreeNode * local_03;
	BbsTreeClickTimer->Enabled=false;
	if (! (BbsTree->Selected==0||BbsTree->Selected->ImageIndex!=1) ) {
		local_00=BbsTree->DropTarget;
		local_01=false;
		for (local_02=1; BbsTree->Items->Count>local_02; local_02++) {
			if (BbsTree->Items->Item[local_02]==BbsTree->DropTarget) {
				if (!local_01||BbsTree->Items->Count<=local_02+1) break;
				local_00=BbsTree->Items->Item[local_02+1];
				if (local_00->ImageIndex==1) break;
				local_00=BbsTree->Items->Item[0];
				break;
			}
			if (BbsTree->Items->Item[local_02]!=BbsTree->Selected) continue;
			local_01=true;
		}
		local_03=BbsTree->Selected;
		local_03->MoveTo(local_00,(TNodeAttachMode)(!(local_00==0||local_00->ImageIndex!=1)?4:2));
		mf_TMainForm_0170();
	}
	return;
}


void __fastcall TMainForm::BbsTreeDragOver(TObject * Sender,TObject * Source,int X,int Y,TDragState State,bool & Accept)
{
	Accept=true;
	return;
}


void __fastcall TMainForm::SplitterHMoved(TObject * Sender)
{
	if (BottomButton->Down) {
		if (BbsButton->Down) {
			g_pTIniFile->WriteInteger("TopView","BbsHeight",TopPanel->Height);
		} else {
			g_pTIniFile->WriteInteger("TopView","Height",TopPanel->Height);
		}
	}
}


void __fastcall TMainForm::AddDefaultClick(TObject * Sender)
{
	if (! (BbsTree->Selected==0||BbsTree->Selected->ImageIndex!=1) ) {
		BbsTree->Selected->MoveTo(BbsTree->Items->Item[0],naAddChild/*(TNodeAttachMode)2*/);
		mf_TMainForm_0170();
	}
	return;
}


void __fastcall TMainForm::BbsTreeClick(TObject * Sender)
{
	return;
}


void __fastcall TMainForm::BbsTreeDblClick(TObject * Sender)
{
	switch (OptionForm->TreeDoubleClickCombo->ItemIndex) {
	case 1:
		BoardOpenClick(NULLPO);
		break;
	case 2:
		BoardNewOpenClick(NULLPO);
	}
	return;
}


void __fastcall TMainForm::BoardOpenClick(TObject * Sender)
{
	TTreeNode * local_00;
	BbsTreeClickTimer->Enabled=false;
	if (BbsTree->SelectionCount==0) {
		return;
	}
	local_00=BbsTree->Selected;
	if (local_00->ImageIndex!=1) {
		return;
	}
	if (!TopButton->Down||!BottomButton->Down) {
		TopButton->Down=true;
		BottomButton->Down=false;
		MainPanel->DisableAlign();
		mf_TMainForm_0080();
		MainPanel->EnableAlign();
	}
	TTabControl *	local_01=MainForm->BoardTabControl;
	for (int local_02=0; local_01->Tabs->Count>local_02; local_02++) {
		if (local_01->Tabs->Strings[local_02].AnsiCompare(local_00->Text)==0) {
			local_01->TabIndex=local_02;
			TabControlChange(BoardTabControl);
			return;
		}
	}
	if (local_01->TabIndex<0) {
		local_01->Tabs->Add(local_00->Text);
		local_01->TabIndex=0;
	} else {
		local_01->Tabs->Strings[local_01->TabIndex]=local_00->Text;
	}
	TabControlChange(BoardTabControl);
	return;
}


void __fastcall TMainForm::BoardNewOpenClick(TObject * Sender)
{
	BbsTreeClickTimer->Enabled=false;
	if (BbsTree->SelectionCount==0) {
		return;
	}
	TTreeNode* local_00=BbsTree->Selected;
	if (local_00->ImageIndex!=1) {
		return;
	}
	TTabControl * local_01=MainForm->BoardTabControl;
	for (int local_02=0; local_01->Tabs->Count>local_02; local_02++) {
		if ((local_01->Tabs->Strings[local_02].AnsiCompare(local_00->Text)==0)) {
			local_01->TabIndex=local_02;
			TabControlChange(BoardTabControl);
			return;
		}
	}
	local_01->Tabs->Add(local_00->Text);
	local_01->TabIndex=local_01->Tabs->Count-1;
	TabControlChange(BoardTabControl);
}


void __fastcall TMainForm::BbsTreeClickTimerTimer(TObject * Sender)
{
	BbsTreeClickTimer->Enabled=false;
	switch (OptionForm->TreeClickCombo->ItemIndex) {
	case 1:
		BoardOpenClick(NULLPO);
		break;
	case 2:  
		BoardNewOpenClick(NULLPO);
	}
	return;
}


void __fastcall TMainForm::BbsTreeMenuPopup(TObject * Sender)
{
	BbsTree->Selected=BbsTree->Selected;
	return;
}


void __fastcall TMainForm::UpQueryTimerTimer(TObject * Sender)
{
	UpQueryTimer->Enabled=false;
	TabControlChange(TabControl);
	return;
}


void __fastcall TMainForm::DownQueryTimerTimer(TObject * Sender)
{
	DownQueryTimer->Enabled=false;
	TabControlChange(SubTabControl);
	return;
}



void __fastcall TMainForm::BbsSearchButtonClick(TObject * Sender)
{
	int local_03;
	char buf[1024];

	if (g_pCMainControl!=0) {
		g_pCMainControl->m_flg_unk15462=true;
	}
	if (! (!(!TopButton->Down)&&BottomButton->Down) ) {
		TopButton->Down=true;
		BottomButton->Down=false;
		MainPanel->DisableAlign();
		mf_TMainForm_0080();
		MainPanel->EnableAlign();
	}
//combo boxのインライン展開かも
	AnsiString local_00=(BbsSearchComboBox->Text);
	local_03=0;
	if (local_00.Length()>=2) {
		int local_04;
		local_04=BbsSearchComboBox->Items->Count;
		int local_05;
		local_05=0;
		bool local_06;
		local_06=false;
		int local_07;
		for (local_07=0; local_07<local_04; local_07++) {
			AnsiString local_02=(BbsSearchComboBox->Items->Strings[local_07]);
			if (local_02.AnsiCompare(local_00)==0) {
					local_06=true;
					local_05=local_07;
								break;
			}
		}
		if (!local_06) {
			BbsSearchComboBox->Items->Insert(local_05,local_00);
			local_03=local_03+1;
		}
	}
	TabControlChange(SubTabControl);

	CGlobalLock CGLock;
	g_pCMainControl->mf_CMainControl_1080(local_00.c_str(),"",true,3);
	AnsiString local_01=("* "+local_00);

	TTabControl * local_08;
	Integer local_09;

	local_08=MainForm->BoardTabControl;
	for (local_09=0; local_08->Tabs->Count>local_09; local_09++) {
		if (local_08->Tabs->Strings[local_09].AnsiCompare(local_01)==0) {
			local_08->TabIndex=local_09;
			TabControlChange(BoardTabControl);
			return;
		}
	}
	local_08->Tabs->Add(local_01);
	local_08->TabIndex=local_08->Tabs->Count-1;
	TabControlChange(BoardTabControl);
	return;
}


void __fastcall TMainForm::RefreshBoardButtonClick(TObject * Sender)
{
	TabControlChange(BoardTabControl);
	return;
}


void __fastcall TMainForm::MakeBbsButtonClick(TObject * Sender)
{
	char local_03[1024];
	AnsiString local_00=("");
	if (BoardTabControl->TabIndex>=0) {
		local_00=BoardTabControl->Tabs->Strings[BoardTabControl->TabIndex];
	}
	BbsMakeForm->BoardListCombo->ItemIndex=0;
	for (int local_01=0; BbsMakeForm->BoardListCombo->Items->Count>local_01; local_01++) {
		if (BbsMakeForm->BoardListCombo->Items->Strings[local_01]==local_00) {
			BbsMakeForm->BoardListCombo->ItemIndex=(local_01);
			break;
		}
	}
	BbsMakeForm->TitleEdit->Text="";
	sprintf(local_03,"%s%s",/*(const char *)*/g_AppPath,"BbsTripString.txt");
	FILE *	local_02=fopen(local_03,"rt");
	if (local_02!=0) {
		fclose(local_02);
		BbsMakeForm->TripCombo->Items->LoadFromFile(local_03);
	}
	BbsMakeForm->Show();
	BbsMakeForm->TitleEdit->SetFocus();
	return;
}


void __fastcall TMainForm::BoardTabControlMouseDown(TObject * Sender,TMouseButton Button,TShiftState Shift,int X,int Y)
{
	Integer local_00;
	if (Button!=mbLeft/*0*/) {
		local_00=BoardTabControl->IndexOfTabAt(X,Y);
		if (local_00>=0) {
			BoardTabControl->TabIndex=local_00;
			TabControlChange(Sender);
		}
		if (Button==mbMiddle/*2*/) {
			BoardTabCloseClick(NULLPO);
		}
	}
	return;
}


void __fastcall TMainForm::BoardTabCloseClick(TObject * Sender)
{
	TTabControl * local_00;
	Integer local_01;
	local_00=BoardTabControl;
	if (local_00->TabIndex>=0) {
		local_01=local_00->TabIndex;
		local_00->Tabs->Delete(local_00->TabIndex);
		local_00->TabIndex=local_01;
		if (local_00->TabIndex<0) {
			local_00->TabIndex=local_01-1;
		}
		TabControlChange(TabControl);
	}
	return;
}



void __fastcall TMainForm::BbsOpenClick(TObject * Sender)
{
	int local_02;
	int local_03;
	unsigned char local_06[16];
	if (m_char_upperPageType_!=pt09) {
		return;
	}
	mf_TMainForm_0200();
	local_02=-1;
	for (local_03=0; BbsBoardView->Items->Count>local_03; local_03++) {
		if (!BbsBoardView->Items->Item[local_03]->Selected||g_nazouintarray[0][local_03]<0) continue;
		local_02=local_03;
		break;
	}
	if (local_02<0) {
		return;
	}
	if (! (!(!TopButton->Down)&&BottomButton->Down) ) {
		TopButton->Down=false;
		BottomButton->Down=true;
		MainPanel->DisableAlign();
		mf_TMainForm_0080();
		MainPanel->EnableAlign();
	} else {
		if (!BottomButton->Down) {
			MainPanel->DisableAlign();
			BottomButton->Down=true;
			mf_TMainForm_0080();
			MainPanel->EnableAlign();
		}
	}
	AnsiString local_00=(BbsBoardView->Items->Item[local_02]->SubItems->Strings[1]);
	ny_aschash2binhash(BbsBoardView->Items->Item[local_02]->SubItems->Strings[7].c_str(),local_06);
	for (unsigned int local_04=0; m__unknown_002.size()>local_04; local_04++) {
		if (memcmp(&m__unknown_002[local_04],local_06,16)!=0) continue;
		BbsTabControl->TabIndex=local_04;
		BbsTabControlChange(NULLPO);
		return;
	}
	AnsiString 	local_01=local_00;
	if (local_00.Length()>32) {
		local_01=local_00.SubString(0,31)+" ・・";
	}
	int	local_05=BbsTabControl->TabIndex;
	if (local_05>=0) {
		memcpy(m__unknown_002[local_05].m_hash,local_06,16);
		*m__unknown_002[local_05].m_name=0;
		m__unknown_002[local_05].m_int_unk1=-1;
		BbsTabControl->Tabs->Strings[local_05]=local_01;
	} else {
		TBbsTab local_07;
		memcpy(local_07.m_hash,local_06,16);
		m__unknown_002.push_back(local_07);
		BbsTabControl->Tabs->Add(local_01);
	}
	BbsTabControlChange(NULLPO);
	return;
}


void __fastcall TMainForm::NewBbsOpenClick(TObject * Sender)
{
	OpenBbsTimer->Enabled=false;
	BbsTabControl->TabIndex=-1;
	BbsOpenClick(NULLPO);
	return;
}


void __fastcall TMainForm::OpenBbsTimerTimer(TObject * Sender)
{
	OpenBbsTimer->Enabled=false;
	switch (OptionForm->ThreadClickCombo->ItemIndex) {
	case 1:  
		BbsOpenClick(NULLPO);
		break;
	case 2:  
		NewBbsOpenClick(NULLPO);
	}
	return;
}


void __fastcall TMainForm::FormShow(TObject * Sender)
{
	int local_00;
	int local_01;
	int array[10];

	char local_14[256];
	char local_15[256];
	for (local_00=0; local_00<10; local_00++) {
		if (local_00==1) continue;
		for (local_01=0; local_01<10; local_01++) {
			array[local_01]=100;
		}
		switch (local_00) {
		case 0:
			array[8]=300;
			break;
		case 1:
			array[8]=300;
			break;
		case 2:
			array[1]=200;
			array[2]=120;
			array[3]=120;
			array[4]=120;
			array[5]=300;
			break;
		case 3:
			array[0]=250;
			array[9]=300;
			break;
		case 9:
			array[0]=40;
			array[1]=50;
			array[2]=250;
			array[8]=300;
			break;
		case 4:
			array[0]=150;
			array[4]=150;
			array[5]=200;
			array[8]=150;
			break;
		case 5:
			array[0]=150;
			array[4]=150;
			array[5]=200;
			array[8]=150;
			break;
		case 6:
			array[0]=200;
			array[1]=170;
			array[2]=200;
			array[3]=150;
			array[5]=150;
			break;
		case 7:
			array[0]=1000;
			break;
		case 8:
			array[0]=200;
			array[1]=200;
			array[2]=200;
			array[3]=200;
		}
		for (int local_02=0; g_UpperListViews[local_00]->Columns->Count>local_02; local_02++) {
			sprintf(local_14,"%s%02d",g_tagnames[local_00],local_02);
			int local_03=g_pTIniFile->ReadInteger("TabWidth",local_14,array[local_02]);
			if (g_UpperListViews[local_00]!=0) {
				g_UpperListViews[local_00]->Column[local_02]->Width=(TWidth)local_03;
			}
		}
		if (local_00>=9) continue;
		for (int local_04=0; g_LowerListViews[local_00]->Columns->Count>local_04; local_04++) {
			sprintf(local_15,"%s%02d",g_tagnames[local_00],local_04);
			int local_05=g_pTIniFile->ReadInteger("SubTabWidth",local_15,array[local_04]);
			if (g_LowerListViews[local_00]!=0) {//continue;
				g_LowerListViews[local_00]->Column[local_04]->Width=(TWidth)local_05;
			}
		}
	}
	return;
}


void __fastcall TMainForm::FormHide(TObject * Sender)
{
	int local_00;
	int local_01;
	int local_02;
	int local_03;
	char local_04[256];
	char local_05[256];
	for (local_00=0; local_00<9; local_00++) {
		if (local_00==1||!BottomCheckListBox->Checked[local_00]||g_LowerListViews[local_00]==0) continue;
		for (local_01=0; g_LowerListViews[local_00]->Columns->Count>local_01; local_01++) {
			sprintf(local_04,"%s%02d",g_tagnames[local_00],local_01);
			g_pTIniFile->WriteInteger("SubTabWidth",local_04,(int)g_LowerListViews[local_00]->Column[local_01]->Width);
		}
	}
	for (local_02=0; local_02<10; local_02++) {
		if (local_02==1||!(local_02>=9)&&!TopCheckListBox->Checked[local_02]||g_UpperListViews[local_02]==0) continue;
		for (local_03=0; g_UpperListViews[local_02]->Columns->Count>local_03; local_03++) {
			if (g_UpperListViews[local_02]->Column[local_03]->Width==0) {
				g_UpperListViews[local_02]->Column[local_03]->Width=(TWidth)2;
			}
			sprintf(local_05,"%s%02d",g_tagnames[local_02],local_03);
			g_pTIniFile->WriteInteger("TabWidth",local_05,(int)g_UpperListViews[local_02]->Column[local_03]->Width);
		}
	}
	return;
}


void __fastcall TMainForm::NodeToolBarClick(int arg_0)
{
	NodeView->ClearSelection();
	return;
}


void __fastcall TMainForm::NodeBbsToolBarClick(int arg_0)
{
	NodeView->ClearSelection();
	return;
}


void __fastcall TMainForm::FolderToolBarClick(int arg_0)
{
	FolderView->ClearSelection();
	return;
}


void __fastcall TMainForm::FileToolBarClick(int arg_0)
{
	FileView->ClearSelection();
	return;
}


void __fastcall TMainForm::DownToolBarClick(int arg_0)
{
	DownView->ClearSelection();
	return;
}


void __fastcall TMainForm::IgnoreToolBarClick(int arg_0)
{
	IgnoreView->ClearSelection();
	return;
}


void __fastcall TMainForm::TaskToolBarClick(int arg_0)
{
	TaskView->ClearSelection();
	return;
}


void __fastcall TMainForm::LogToolBarClick(int arg_0)
{
	LogView->ClearSelection();
	return;
}


void __fastcall TMainForm::BoardToolBarClick(TObject * Sender)
{
	BbsBoardView->ClearSelection();
	return;
}


void __fastcall TMainForm::SystemToolBarClick(TObject * Sender)
{
	SystemView->ClearSelection();
	return;
}


void __fastcall TMainForm::BbsBoardViewMouseDown(TObject * Sender,TMouseButton Button,TShiftState Shift,int X,int Y)
{
	if (m_char_upperPageType_==pt09) {
		OpenBbsTimer->Enabled=true;
	}
	return;
}


void __fastcall TMainForm::NodeViewColumnClick(TObject * Sender,TListColumn * Column)
{
	xint local_00;
	int local_01;
	local_00=0;
	local_01=(int)m_char_upperPageType_;
	if (! (!(Sender==SubNodeView||Sender==SubFolderView||Sender==SubFileView||Sender==SubDownView||Sender==SubIgnoreView||Sender==SubTaskView||Sender==SubLogView)&&Sender!=SubSystemView) ) {
		local_01=(int)m_char_lowerPageType_;
		local_00=1;
	}
	g_pTIniFile->WriteInteger("TabSort",g_tagnames[local_01],Column->Index);
	bool local_02=g_pTIniFile->ReadInteger("TabSortMode",g_tagnames[local_01],0)==0;
	g_pTIniFile->WriteInteger("TabSortMode",g_tagnames[local_01],!(!local_02)?1:0);
	if ((int)m_char_upperPageType_==local_01) {
		TabControlChange(TabControl);
	}
	if ((int)m_char_lowerPageType_==local_01) {
		TabControlChange(SubTabControl);
	}
	return;
}


void __fastcall TMainForm::SubNodeToolBarClick(int arg_0)
{
	SubNodeView->ClearSelection();
	return;
}


void __fastcall TMainForm::SubNodeBbsToolBarClick(int arg_0)
{
	SubNodeView->ClearSelection();
	return;
}


void __fastcall TMainForm::SubFolderToolBarClick(int arg_0)
{
	SubFolderView->ClearSelection();
	return;
}


void __fastcall TMainForm::SubFileToolBarClick(int arg_0)
{
	SubFileView->ClearSelection();
	return;
}


void __fastcall TMainForm::SubDownToolBarClick(int arg_0)
{
	SubDownView->ClearSelection();
	return;
}


void __fastcall TMainForm::SubIgnoreToolBarClick(int arg_0)
{
	SubIgnoreView->ClearSelection();
	return;
}


void __fastcall TMainForm::SubTaskToolBarClick(int arg_0)
{
	SubTaskView->ClearSelection();
	return;
}


void __fastcall TMainForm::SubLogToolBarClick(int arg_0)
{
	SubLogView->ClearSelection();
	return;
}


void __fastcall TMainForm::SubSystemToolBarClick(int arg_0)
{
	SubSystemView->ClearSelection();
	return;
}


void __fastcall TMainForm::SearchComboBoxChange(TObject * Sender)
{
	if (g_pCMainControl!=0) {
		g_pCMainControl->m_flg_unk15462=true;
	}
	return;
}


void __fastcall TMainForm::TripComboBoxChange(TObject * Sender)
{
	if (g_pCMainControl!=0) {
		g_pCMainControl->m_flg_unk15462=true;
	}
	return;
}


void __fastcall TMainForm::BbsSearchComboBoxChange(TObject * Sender)
{
	if (g_pCMainControl!=0) {
		g_pCMainControl->m_flg_unk15462=true;
	}
	return;
}


void __fastcall TMainForm::SearchTabDeleteClick(TObject * Sender)
{
	TTabControl * local_00;
	local_00=SearchTabControl;
	if (Sender==SubSearchTabDelete) {
		local_00=SubSearchTabControl;
	}
	if (local_00->TabIndex<0) {
		return;
	}
	local_00->Tabs->Delete(local_00->TabIndex);
	SearchComboBox->Text="";
	if (Sender==SubSearchTabDelete) {
		SearchButtonClick(SubSearchButton);
	} else {
			SearchButtonClick(SearchButton);
	}
}


void __fastcall TMainForm::SearchTabRightDeleteClick(TObject * Sender)
{
	TTabControl * local_00;
	int local_01;
	local_00=SearchTabControl;
	if (SubSearchTabRightDelete==Sender) {
		local_00=SubSearchTabControl;
	}
	if (local_00->TabIndex<0) {
		return;
	}
	for (local_01=local_00->Tabs->Count-1; local_00->TabIndex<local_01; local_01--) {
		local_00->Tabs->Delete(local_01);
	}
	SearchComboBox->Text="";
	if (SubSearchTabRightDelete==Sender) {
		SearchButtonClick(SubSearchButton);
	} else {
		SearchButtonClick(SearchButton);
	}
}


void __fastcall TMainForm::SearchTabLeftDeleteClick(TObject * Sender)
{
	TTabControl * local_00;
	Integer local_01;
	int local_02;
	local_00=SearchTabControl;
	if (Sender==SubSearchTabLeftDelete) {
		local_00=SubSearchTabControl;
	}
	if (local_00->TabIndex<0) {
		return;
	}
	local_01=local_00->TabIndex;
	for (local_02=0; local_02<local_01; local_02++) {
		local_00->Tabs->Delete(0);
	}
	SearchComboBox->Text="";
	if (Sender==SubSearchTabLeftDelete) {
		SearchButtonClick(SubSearchButton);
	} else {
		SearchButtonClick(SearchButton);
	}
}


void __fastcall TMainForm::AllSearchTabDeleteClick(TObject * Sender)
{
	TTabControl * local_00;
	local_00=SearchTabControl;
	if (Sender==SubSearchTabAllDelete) {
		local_00=SubSearchTabControl;
	}
	local_00->Tabs->Clear();
	SearchComboBox->Text="";
	if (Sender==SubSearchTabAllDelete) {
		SearchButtonClick(SubSearchButton);
	} else {
		SearchButtonClick(SearchButton);
	}
}


void TMainForm::mf_TMainForm_0180(/*const*/ AnsiString & arg_0,bool arg_1)
{
	TTabControl * local_01;
	local_01=SearchTabControl;
	if (arg_1) {
		local_01=SubSearchTabControl;
	}
	if (arg_0.Length()>=2) {
		int local_02;
		local_02=local_01->Tabs->Count;
		int local_03;
		bool local_04;
		local_04=false;
		for (local_03=0; local_03<local_02; local_03++) {
			AnsiString local_00=(local_01->Tabs->Strings[local_03]);
			if (strcmp(local_00.c_str(),arg_0.c_str())==0) {
				local_04=true;
				break;
			}
		}
		if (!local_04) {
			local_01->Tabs->Add(arg_0);
		}
	}
	mf_TMainForm_0090();
	return;
}


void __fastcall TMainForm::CopyDownToSearchTabClick(TObject * Sender)
{
	TTabControl * local_01;
	int local_02;

	local_01=SearchTabControl;
	if (SubCopyDownToSearchTab==Sender) {
		local_01=SubSearchTabControl;
	}
	local_02=g_pCMainControl->m_DownCondition_.size();
	if (local_02>0) {
		int local_03;
		CAutoDownList * local_04;
		for (local_03=0; local_03<local_02; local_03++) {
			local_04=g_pCMainControl->mf_CMainControl_0130(local_03);
			if (!local_04->m_flg_unk0||local_04->m_flag_unk5||local_04->mf_CAutoDownList_0010()||strlen(local_04->m_char256_unk1)<2) continue;
			int local_05=local_01->Tabs->Count;
			int local_06=0;
			int local_07;
			bool local_08;
			local_08=false;
			for (local_07=0; local_07<local_05; local_07++) {
				AnsiString local_00=(local_01->Tabs->Strings[local_07]);
				if (strcmp(local_04->m_char256_unk1,local_00.c_str())==0) {
					local_08=true;
					local_06=local_07;
					break;
				}
			}
			if (local_08) continue;
			local_01->Tabs->Add(local_04->m_char256_unk1);
		}
	}
	local_01->TabIndex=-1;
	SearchComboBox->Text="";
	mf_TMainForm_0090();
	return;
}


void __fastcall TMainForm::ClearCopyDownToSearchTabClick(TObject * Sender)
{
	TTabControl * local_00;
	local_00=SearchTabControl;
	if (Sender==SubClearCopyDownToSearchTab) {
		local_00=SubSearchTabControl;
	}
	local_00->Tabs->Clear();
	if (Sender==SubClearCopyDownToSearchTab) {
		CopyDownToSearchTabClick(SubCopyDownToSearchTab);
		return;
	}
	CopyDownToSearchTabClick(CopyDownToSearchTab);
	return;
}



void __fastcall TMainForm::BbsTabControlChange(TObject * Sender)
{
	Integer local_00;
	TBbsTab * local_01;
	if (!BottomButton->Down) {
		return;
	}
	local_00=BbsTabControl->TabIndex;
	if (local_00<0) {
		BbsTitleLabel->Caption="";
		BbsView->Clear();
		BbsRefreshButton->Enabled=false;
		BbsCloseButton->Enabled=false;
		BbsWriteButton->Enabled=false;
		return;
	}
	Screen->Cursor=(TCursor)-11;
	MainPanel->DisableAlign();
	BbsRefreshButton->Enabled=true;
	BbsCloseButton->Enabled=true;
	BbsWriteButton->Enabled=true;
	local_01=&m__unknown_002[local_00];

	bool local_02;
	int local_03;
	CGlobalLock CGLock;
	if (Sender==0) {
		*local_01->m_name=0;
		BbsStatusLabel->Caption="";
		g_pCMainControl->mf_CMainControl_0880(0,local_01->m_hash,-1,0,&local_02,&local_03,local_01->m_name);
		local_01->m_int_unk1_1=local_03;
	}
	BbsTitleLabel->Caption=BbsTabControl->Tabs->Strings[local_00];
	unsigned short	local_04=(unsigned short)g_pCMainControl->mf_CMainControl_1330(local_01,BbsView,BbsTitleLabel);
	if (local_01->m_int_unk1<0) {
		local_01->m_int_unk1=(int)((unsigned int)local_04);
	}
	BbsView->SetTop(local_01->m_int_unk1);
	MainPanel->EnableAlign();
	if (BbsButton->Down) {
		BbsView->SetFocus();
	}
	mf_TMainForm_0190();
	Screen->Cursor=(TCursor)0;
	return;
}


void TMainForm::mf_TMainForm_0190()
{
	Integer local_00;
	TBbsTab * local_01;
	char local_02[1024];
	local_00=BbsTabControl->TabIndex;
	if (local_00<0) {
		BbsStatusLabel->Caption="";
		return;
	}
	local_01=&m__unknown_002[local_00];
	if (strcmp(local_01->m_name,"ダウン完了")==0) {
		strcpy(local_01->m_name,"OK");
		BbsTabControlChange(BbsTabControl);
	}
	sprintf(local_02," < %s >",local_01->m_name);
	BbsStatusLabel->Caption=local_02;
	return;
}


void __fastcall TMainForm::CacheClearButtonClick()
{
	if (MessageBox(NULL,"保持しているBBSキャッシュを全てクリアしますか？","Winny",0x00042024)==6) {
		CGlobalLock CGLock;
		g_pCMainControl->mf_CMainControl_0750();
		TabControlChange(NULLPO);
	}
	return;
}



void __fastcall TMainForm::BbsViewMouseMove(TObject * Sender,TShiftState Shift,int X,int Y)
{
	TPoint local_point;
	char local_25[4096];
	char local_26[4096];

	local_point=BbsView->ClientToPhysicalCharPos(X,Y);
	bool local_05;
	local_05=false;
	if (local_point.y/*local_02*/>=0) {
		TRichTVItem * local_06=BbsView->Strings->Items[local_point.y/*local_02*/];
		if (local_06->HasEmbed(local_point.x/*local_03*/+1)) {
			AnsiString local_00=(AnsiString)local_06->GetEmbed(local_point.x/*local_03*/+1);
			char * local_07;
			char * local_08;
			const char * local_09;
			const char * local_10;
			local_07=local_00.c_str();
			if ((int)*local_07==62) {   // >
				CGlobalLock CGLock;
				local_08=local_07+1;
				if ((int)*(local_07+1)==62) {   // >
					local_08=local_08+1;
				}
				local_09=local_08;
				local_10=NULLPO;
				for ( ; !((int)*local_08<48)&&(int)*local_08<=57; local_08++) {  // 0..9
				}
				if ((int)*local_08==45) {  // -
					*local_08=(const char)0;
					local_08=local_08+1;
					local_10=local_08;
					while ((int)*local_08>=48 && (int)*local_08<=57) {
						local_08=local_08+1;
					}
				} else {
					*local_08=(const char)0;
				}
				//何かがインライン展開されている模様だけどよくわからん
				int local_11=callatol(local_09)-1;
				int local_12=local_11;
				if (local_10!=0) {
					local_12=callatol(local_10)-1;
					if (local_12==-1) {
						local_12=local_11+10;
					}
					if (g_pCMainControl->m_vectorInt__1.size()<=(unsigned int)local_12) {
						local_12=g_pCMainControl->m_vectorInt__1.size()-1;
					}
				}
				if (local_11<0) {
					return;
				}
				if (g_pCMainControl->m_vectorInt__1.size()<=(unsigned int)local_11) {
					return;
				}
				if (local_12<0) {
					return;
				}
				if (g_pCMainControl->m_vectorInt__1.size()<=(unsigned int)local_12) {
					return;
				}
				if (local_11+10<local_12) {
					local_12=local_11+10;
				}
				AnsiString local_01;
				TRichTVItems * local_13=BbsView->Strings;
				int local_14=0;
				for (int local_15=local_11; local_15<=local_12; local_15++) {
					int local_16=g_pCMainControl->m_vectorInt__1[local_15];
					int local_17=local_13->Count;
					if (g_pCMainControl->m_vectorInt__1.size()-1>(unsigned int)local_15) {
						local_17=g_pCMainControl->m_vectorInt__1[local_15+1];
					}
					for (int local_18=local_16; local_18<local_17; local_18++) {
						if (local_13->Count<=local_18) continue;
						strcpy(local_25,local_13->Items[local_18]->FText.c_str());
						char * local_20=local_25;
						char * local_21=local_26;
						while (!(*local_20==0)&&local_20-local_25<4095) {
							if (ny_iskanji(*local_20)) {
								*local_21=*local_20;
								local_20=local_20+1;
								local_21=local_21+1;
								if (*local_20!=0) {
									*local_21=*local_20;
									local_20=local_20+1;
									local_21=local_21+1;
								}
							} else {
								if ((int)*local_20==124) {
									*local_21='l';
									local_21=local_21+1;
									local_20=local_20+1;
								} else {
									*local_21=*local_20;
									local_20=local_20+1;
									local_21=local_21+1;
								}
							}
						}
						*local_21=0;
						local_01+=local_26;
						local_01+="\n";
					}
				}
				int local_22=local_01.Length()-1;
				while (local_22>0 && (local_01[local_22]==10||local_01[local_22]==32) ) {
					local_22=local_22-1;
				}
				if (local_22>0) {
					local_01.SetLength(local_22);
				}
				Application->HintHidePause=0x3B9ACA00;
				Application->HintPause=10;
				BbsView->Hint=local_01;
				BbsView->ShowHint=true;
			}
			BbsView->Cursor=(TCursor)65515;
			local_05=true;
		}
	}
	if (!local_05) {
		BbsView->Hint="";
		BbsView->ShowHint=false;
		Application->HintHidePause=2500;
		Application->HintPause=500;
		if (local_point.y>=0) {
			BbsView->Cursor=(TCursor)65532;
		} else {
			BbsView->Cursor=(TCursor)0;
		}
	}
	return;
}


void __fastcall TMainForm::BbsCopyClick(TObject * Sender)
{
	BbsView->CopySelection();
	return;
}


void __fastcall TMainForm::ReloadBoardTimerTimer(TObject * Sender)
{
	ReloadBoardTimer->Enabled=false;
	TabControlChange(ReloadBoardTimer);
	return;
}


void __fastcall TMainForm::OpenWinnyWebSiteClick(TObject * Sender)
{
	SHELLEXECUTEINFO local_00;
	local_00.cbSize=60;
	local_00.hwnd=NULL;
	local_00.fMask=0;
	local_00.lpVerb="open";
	local_00.lpFile="http://www.geocities.co.jp/SiliconValley/2949/";
	local_00.lpParameters=NULLPO;
	local_00.lpDirectory=NULLPO;
	local_00.nShow=1;
	local_00.lpIDList=NULLPO;
	ShellExecuteEx(&local_00);
	return;
}


void __fastcall TMainForm::BbsWriteButtonClick(TObject * Sender)
{
	TTabControl * local_00;
	FILE * local_01;
	char local_03[1024];

	local_00=BbsTabControl;
	if (local_00->TabIndex<0) {
		return;
	}
	if (BbsWriteForm->Visible) {
		BbsWriteForm->WindowState=wsNormal;
		return;
	}
	sprintf(local_03,"%s%s",/*(const char *)*/g_AppPath,"BbsTripString.txt");
	local_01=fopen(local_03,"rt");
	if (local_01!=0) {
		fclose(local_01);
		BbsWriteForm->TripCombo->Items->LoadFromFile(local_03);
	}
	sprintf(local_03,"%s%s",/*(const char *)*/g_AppPath,"BbsUserName.txt");
	local_01=fopen(local_03,"rt");
	if (local_01!=0) {
		fclose(local_01);
		BbsWriteForm->NameCombo->Items->LoadFromFile(local_03);
	}
	CGlobalLock CGLock;
	CKey * local_02;
	local_02=g_pCMainControl->mf_CMainControl_0180(0,m__unknown_002[local_00->TabIndex].m_hash);
	if (local_02!=0) {
		*g_pCMainControl->m_szstr_errormsg_=0;
		memcpy(BbsWriteForm->m_hash,&m__unknown_002[local_00->TabIndex],16);
		sprintf(local_03,"  %s",local_02->mf_CKey_0260());
		BbsWriteForm->TitleLabel->Caption=local_03;
		BbsWriteForm->WriteButton->Enabled=true;
		BbsWriteForm->MessageEdit->Text="";
		BbsWriteForm->StateLabel->Caption="";
		BbsWriteForm->Show();
		BbsWriteForm->MessageEdit->SetFocus();
	} else {
		MessageBox(NULL,"キーが見つかりません","Winny",0x00042030);
	}
	return;
}


void __fastcall TMainForm::BbsCloseClick(TObject * Sender)
{
	TTabControl * local_00;

	local_00=BbsTabControl;
	if (local_00->TabIndex>=0) {
		mf_TMainForm_0200();
		for (unsigned int local_01=local_00->TabIndex; m__unknown_002.size()-1>local_01; local_01++) {
			m__unknown_002[local_01]=m__unknown_002[local_01+1];
		}
		m__unknown_002.pop_back();

		int local_03=local_00->TabIndex;
		local_00->Tabs->Delete(local_00->TabIndex);
		if (local_00->Tabs->Count>local_03) {
			local_00->TabIndex=local_03;
		} else {
			local_00->TabIndex=local_00->Tabs->Count-1;
		}
		BbsTabControlChange(BbsTabControl);
	}
	return;
}


void TMainForm::mf_TMainForm_0200()
{
	TBbsTab * local_00;
	if (BbsTabControl->TabIndex<0) {
		return;
	}
	local_00=&m__unknown_002[BbsTabControl->TabIndex];
	CGlobalLock CGLock;
	CKey * local_01=g_pCMainControl->mf_CMainControl_0180(0,local_00->m_hash);
	if (! (local_01==0||local_01->m_char_keyType_==KEYTYPE00) ) {
		local_00->m_int_unk1=BbsView->TopLine;
		int tmp=local_00->m_int_unk1;
		local_01->m_int_unk17=tmp;
		local_01->mf_CKey_0110();
	}
	return;
}


void __fastcall TMainForm::AllBbsTabCloseClick(TObject * Sender)
{
	TTabControl * local_00;
	unsigned int local_01;

	local_00=BbsTabControl;
	mf_TMainForm_0200();
	CGlobalLock CGLock;
	for (local_01=0; m__unknown_002.size()>local_01; local_01++) {
		TBbsTab *		local_02=&m__unknown_002[local_01];
		CKey * local_03;
		local_03=g_pCMainControl->mf_CMainControl_0180(0,local_02->m_hash);
		if (local_03==0||local_03->m_char_keyType_==KEYTYPE00) continue;
		int tmp=local_02->m_int_unk1;
		local_03->m_int_unk17=tmp;
		local_03->mf_CKey_0110();
	}
	m__unknown_002.clear();
	local_00->Tabs->Clear();
	BbsTabControlChange(BbsTabControl);
	return;
}


void __fastcall TMainForm::AllBoardTabCloseClick(TObject * Sender)
{
	TTabControl *tmp=BoardTabControl;
	tmp->Tabs->Clear();
	TabControlChange(TabControl);
	return;
}


void __fastcall TMainForm::BbsTabControlMouseDown(TObject * Sender,TMouseButton Button,TShiftState Shift,int X,int Y)
{
	Integer local_00;
	if (Button!=0) {
		local_00=BbsTabControl->IndexOfTabAt(X,Y);
		mf_TMainForm_0200();
		if (local_00>=0) {
			BbsTabControl->TabIndex=local_00;
			BbsTabControlChange(BbsTabControl);
		}
		if (Button==mbMiddle/*2*/) {
			BbsCloseClick(NULLPO);
		}
	}
	return;
}


void __fastcall TMainForm::BbsOpenWebClick(TObject * Sender)
{
	int local_00;
	unsigned char local_02[16];
	CGlobalLock CGLock;
	for (local_00=0; BbsBoardView->Items->Count>local_00; local_00++) {
		if (! (!BbsBoardView->Items->Item[local_00]->Selected||g_nazouintarray[0][local_00]<0) ) {
			ny_aschash2binhash(BbsBoardView->Items->Item[local_00]->SubItems->Strings[7].c_str(),local_02);
			CKey * local_01=g_pCMainControl->mf_CMainControl_0180(0,local_02);
			g_pCMainControl->mf_CMainControl_1040(0,local_01);
			break;
		}
	}
	return;
}


void __fastcall TMainForm::BbsTabControlChanging(TObject * Sender,bool & AllowChange)
{
	mf_TMainForm_0200();
	return;
}


void __fastcall TMainForm::BbsRefreshButtonClick(TObject * Sender)
{
	mf_TMainForm_0200();
	BbsTabControlChange(NULLPO);
	return;
}


void __fastcall TMainForm::BbsViewCacheClick(TObject * Sender)
{
	g_pCMainControl->m_optflg_displayNonWritableBbs_=!g_pCMainControl->m_optflg_displayNonWritableBbs_;
	g_pTIniFile->WriteInteger("Option","DisplayNonWritableBbs",!(!g_pCMainControl->m_optflg_displayNonWritableBbs_)?1:0);
	mf_TMainForm_0140();
	TabControlChange(NULLPO);
	return;
}


void __fastcall TMainForm::NodeViewColumnDragged(TObject * Sender)
{
	((TControl *)Sender)->Refresh();
	return;
}


void __fastcall TMainForm::WndProc(TMessage & Message)
{
	if (g_pCMainControl!=0) {
		if (! ((Message.Msg!=274||Message.WParam!=0x0000F020)) ) {
			ControlForm->mf_TControlForm_0000();
			Hide();
			return;
		}
		TCustomForm::WndProc(Message);
	}
	return;
}


void __fastcall TMainForm::ConvertWaitButtonClick()
{
	g_pCMainControl->m_flg_unk15509=(bool)!g_pCMainControl->m_flg_unk15509;
	mf_TMainForm_0140();
	return;
}


void __fastcall TMainForm::BbsBoardViewAdvancedCustomDraw(TCustomListView * Sender,const TRect & ARect,TCustomDrawStage Stage,bool & DefaultDraw)
{
	float local_00;
	local_00=1.0;
	if (BbsButton->Down) {
		local_00=(double)(OptionForm->BbsColorTrackBar->Position+1)*0.5;
	} else {
		local_00=(double)(OptionForm->ColorTrackBar->Position+1)*0.5;
	}
	TColor	local_01=(TColor)GetSysColor(13);
	m_color01=(TColor)GetSysColor(8);
	if (! (OptionForm==0||BbsButton->Down) ) {
		m_color01=SystemView->Font->Color;
	}
	if (! (OptionForm==0||!BbsButton->Down) ) {
		m_color01=BbsBoardView->Font->Color;
	}
	//このへんはRGBマクロを使っていると思われる
	m_color02=(TColor)((unsigned int)((unsigned char)((int)(180.0/local_00))));
	m_color03=(TColor)((unsigned int)((unsigned char)((int)(255.0/local_00)))|(unsigned int)((unsigned short)((unsigned int)((unsigned char)((int)(64.0/local_00)))))<<8);
	m_color04=(TColor)((unsigned int)((unsigned char)((int)(255.0/local_00)))|(unsigned int)((unsigned short)((unsigned int)((unsigned char)((int)(128.0/local_00)))))<<8);
	m_color05=(TColor) RGB(0,(255.0/local_00),0);
	m_color06=(TColor)(((unsigned int)((unsigned char)((int)(255.0/local_00)))));
	m_color07=(TColor)((unsigned int)((unsigned char)((int)(255.0/local_00)))|(unsigned int)((unsigned char)((int)(255.0/local_00)))<<16);
	m_color08=(TColor)((unsigned int)((unsigned char)((int)(255.0/local_00)))|(unsigned int)((unsigned short)((unsigned int)((unsigned char)((int)(255.0/local_00)))))<<8);
	m_color09=(TColor)(((unsigned int)((unsigned char)((int)(128.0/local_00)))|(unsigned int)((unsigned short)((unsigned int)((unsigned char)((int)(128.0/local_00)))))<<8)|(unsigned int)((unsigned char)((int)(255.0/local_00)))<<16);
	m_color10=(TColor)((unsigned int)((unsigned char)((int)(128.0/local_00)))|(unsigned int)((unsigned short)((unsigned int)((unsigned char)((int)(128.0/local_00)))))<<8);
	m_color11=(TColor)(((unsigned int)((unsigned char)((int)(160.0/local_00)))|(unsigned int)((unsigned short)((unsigned int)((unsigned char)((int)(160.0/local_00)))))<<8)|(unsigned int)((unsigned char)((int)(255.0/local_00)))<<16);
	m_color12=(TColor)(((unsigned int)((unsigned char)((int)(64.0/local_00)))|(unsigned int)((unsigned short)((unsigned int)((unsigned char)((int)(64.0/local_00)))))<<8)|(unsigned int)((unsigned char)((int)(255.0/local_00)))<<16);
	m_color13=(TColor)(((unsigned int)((unsigned char)((int)(255.0/local_00)))|(unsigned int)((unsigned short)((unsigned int)((unsigned char)((int)(255.0/local_00)))))<<8)|(unsigned int)((unsigned char)((int)(128.0/local_00)))<<16);
	m_color14=(TColor) RGB(0,0,(255.0/local_00));
	m_color15=(TColor)GetSysColor(14);
	m_color16=(TColor) RGB((255.0-180.0/local_00),0xFF,0xFF);
	m_color17=(TColor)(((unsigned int)((unsigned char)((int)(255.0-255.0/local_00)))|(unsigned int)((unsigned short)((unsigned int)((unsigned char)((int)(255.0-64.0/local_00)))))<<8)|0x00FF0000);
	m_color18=(TColor)(((unsigned int)((unsigned char)((int)(255.0-255.0/local_00)))|(unsigned int)((unsigned short)((unsigned int)((unsigned char)((int)(255.0-128.0/local_00)))))<<8)|0x00FF0000);
	m_color19=(TColor) RGB(0xff,(255.0-255.0/local_00),0xFF);
	m_color20=(TColor) RGB((255.0-255.0/local_00),0xFF,0xFF);
	m_color21=(TColor) RGB(255.0-255.0/local_00,0xFF,255.0-255.0/local_00);

	m_color22=(TColor)((unsigned int)((unsigned char)((int)(255.0-255.0/local_00)))<<16|0x0000FFFF);
	m_color23=(TColor)(((unsigned int)((unsigned char)((int)(255.0-128.0/local_00)))|(unsigned int)((unsigned short)((unsigned int)((unsigned char)((int)(255.0-128.0/local_00)))))<<8)|(unsigned int)((unsigned char)((int)(255.0-255.0/local_00)))<<16);
	m_color24=(TColor)(((unsigned int)((unsigned char)((int)(255.0-128.0/local_00)))|(unsigned int)((unsigned short)((unsigned int)((unsigned char)((int)(255.0-128.0/local_00)))))<<8)|0x00FF0000);
	m_color25=(TColor)(((unsigned int)((unsigned char)((int)(255.0-160.0/local_00)))|(unsigned int)((unsigned short)((unsigned int)((unsigned char)((int)(255.0-160.0/local_00)))))<<8)|(unsigned int)((unsigned char)((int)(255.0-255.0/local_00)))<<16);
	m_color26=(TColor)(((unsigned int)((unsigned char)((int)(255.0-64.0/local_00)))|(unsigned int)((unsigned short)((unsigned int)((unsigned char)((int)(255.0-64.0/local_00)))))<<8)|(unsigned int)((unsigned char)((int)(255.0-255.0/local_00)))<<16);
	m_color27=(TColor)(((unsigned int)((unsigned char)((int)(255.0-255.0/local_00)))|(unsigned int)((unsigned short)((unsigned int)((unsigned char)((int)(255.0-255.0/local_00)))))<<8)|(unsigned int)((unsigned char)((int)(255.0-128.0/local_00)))<<16);
	m_color28=(TColor)((unsigned int)((unsigned char)((int)(255.0-255.0/local_00)))<<16|0x0000FFFF);
	if (ny_colordiff(m_color02,local_01)>ny_colordiff(m_color16,local_01)) {
		m_color16=m_color02;
	}
	if (ny_colordiff(m_color03,local_01)>ny_colordiff(m_color17,local_01)) {
		m_color17=m_color03;
	}
	if (ny_colordiff(m_color04,local_01)>ny_colordiff(m_color18,local_01)) {
		m_color18=m_color04;
	}
	if (ny_colordiff(m_color05,local_01)>ny_colordiff(m_color19,local_01)) {
		m_color19=m_color05;
	}
	if (ny_colordiff(m_color06,local_01)>ny_colordiff(m_color20,local_01)) {
		m_color20=m_color06;
	}
	if (ny_colordiff(m_color07,local_01)>ny_colordiff(m_color21,local_01)) {
		m_color21=m_color07;
	}
	if (ny_colordiff(m_color08,local_01)>ny_colordiff(m_color22,local_01)) {
		m_color22=m_color08;
	}
	if (ny_colordiff(m_color09,local_01)>ny_colordiff(m_color23,local_01)) {
		m_color23=m_color09;
	}
	if (ny_colordiff(m_color10,local_01)>ny_colordiff(m_color24,local_01)) {
		m_color24=m_color10;
	}
	if (ny_colordiff(m_color11,local_01)>ny_colordiff(m_color25,local_01)) {
		m_color25=m_color11;
	}
	if (ny_colordiff(m_color12,local_01)>ny_colordiff(m_color26,local_01)) {
		m_color26=m_color12;
	}
	if (ny_colordiff(m_color13,local_01)>ny_colordiff(m_color27,local_01)) {
		m_color27=m_color13;
	}
	if (ny_colordiff(m_color14,local_01)>ny_colordiff(m_color28,local_01)) {
		m_color28=m_color14;
	}
	if (Sender->Handle!=0) {
		for (int local_02=0; local_02<20; local_02++) {
			m_intarray_unk_[local_02]=SendMessage(Sender->Handle,4125,local_02,0);
		}
	}
	return;
}


void __fastcall TMainForm::FileViewAdvancedCustomDrawItem(TCustomListView * Sender,TListItem * Item,TCustomDrawState State,TCustomDrawStage Stage,bool & DefaultDraw)
{
	TCanvas * local_01;
	enumPageType local_02;
	xint local_03;
	int local_04;
	bool local_05;
	TStrings * local_06;
	int local_07;

	DefaultDraw=false;
	if (Stage!=0) {
		return;
	}
	local_01=Sender->Canvas;
	local_02=m_char_upperPageType_;
	local_03=0;
	if (! (!(SubNodeView==Sender||SubFolderView==Sender||SubFileView==Sender||SubDownView==Sender||SubIgnoreView==Sender||SubTaskView==Sender||SubLogView==Sender)&&SubSystemView!=Sender) ) {
		local_02=m_char_lowerPageType_;
		local_03=1;
	}
	local_04=Item->Index;
	if (local_04<0) {
		return;
	}
	TRect	local_13=Item->DisplayRect((TDisplayCode)0);
	TRect	local_14=local_13;
	if (local_14.Top<10) {
		return;
	}
	local_05=(! (g_intarray2[local_03]<=0 || !State.Contains(cdsSelected)) );
	if (local_05) {
		local_01->Brush->Color=(TColor)0x8000000D;
	}
	TRect local_15;
	local_15.Left=local_13.Left;
	local_15.Top=local_13.Top;
	local_15.Right=local_13.Right;
	local_15.Bottom=local_13.Bottom;
	Sender->Canvas->FillRect(local_15);
	local_14.Top=local_13.Top-1;
	local_14.Left=Sender->TopItem->Left+4;
	local_14.Right=Sender->TopItem->Left+m_intarray_unk_[0]+-4;
	local_06=Item->SubItems;
	for (local_07=0; local_06->Count>=local_07; local_07++) {
		AnsiString local_00;
		if (local_07==0) {
			local_00=Item->Caption;
		} else {
			local_00=local_06->Strings[local_07-1];
		}
		const char *		local_08=local_00.c_str();
		TColor		local_09=!(!local_05)?m_color15:m_color01;
		if (*local_08!=0) {
			switch ((int)local_02) {
			case 0:  case 1:
				if (! (local_07!=0||strcmp(local_08,"検索中")!=0) ) {
					local_09=!(!local_05)?m_color16:m_color02;
					break;
				}
				if (! (local_07!=0||strcmp(local_08,"BBS接続テスト")!=0) ) {
					local_09=!(!local_05)?m_color17:m_color03;
					break;
				}
				if (! (local_07!=0||strcmp(local_08,"接続テスト")!=0) ) {
					local_09=!(!local_05)?m_color18:m_color04;
					break;
				}
				if (! (local_07!=0||strcmp(local_08,"BBS Port")!=0) ) {
					local_09=!(!local_05)?m_color19:m_color05;
					break;
				}
				if (! (local_07!=0||strcmp(local_08,"待機")!=0) ) {
					local_09=!(!local_05)?m_color15:m_color01;
					break;
				}
				if (! (local_07!=0||strcmp(local_08,"検索リンク")!=0) ) {
					local_09=!(!local_05)?m_color21:m_color07;
					break;
				}
				if (! (local_07!=0||strcmp(local_08,"BBS検索リンク")!=0) ) {
					local_09=!(!local_05)?m_color21:m_color07;
					break;
				}
				if (! (local_07!=0||strstr(local_08,"転送リンク")==0) ) {
					local_09=!(!local_05)?m_color28:m_color14;
					break;
				}
				if (! (local_07!=1||strstr(local_08,"上流")==0) ) {
					local_09=!(!local_05)?m_color19:m_color05;
					break;
				}
				if (! (local_07!=1||strstr(local_08,"下流")==0) ) {
					local_09=!(!local_05)?m_color22:m_color08;
					break;
				}
				if (! (local_07!=3||strcmp(local_08,"ポート警告")!=0) ) {
					local_09=!(!local_05)?m_color20:m_color06;
					break;
				}
				if (! (local_07!=3||strcmp(local_08,"無視ノード警告")!=0) ) {
					local_09=!(!local_05)?m_color22:m_color08;
					break;
				}
				if (! (local_07!=3||strcmp(local_08,"捏造警告")!=0) ) {
					local_09=!(!local_05)?m_color20:m_color06;
					break;
				}
				if (local_07!=7||strstr(local_08,"+")==0) break;
				local_09=!(!local_05)?m_color23:m_color09;
				break;
			case 2:
				if (local_07==0) {
					local_09=!(!local_05)?m_color19:m_color05;
					break;
				}
				if (local_07==1) {
					local_09=!(!local_05)?m_color18:m_color04;
					break;
				}
				if (local_07==2) {
					local_09=!(!local_05)?m_color23:m_color09;
					break;
				}
				if (local_07!=5||strstr(local_08,"済み")!=0) break;
				local_09=!(!local_05)?m_color20:m_color06;
				break;
			case 9:
				if (local_07==5) {
					local_09=!(!local_05)?m_color23:m_color09;
					break;
				}
				if (! (local_07!=0||strcmp(local_08,"読")!=0) ) {
					local_09=!(!local_05)?m_color18:m_color04;
					break;
				}
				if (! (local_07!=0||strcmp(local_08,"書")!=0) ) {
					local_09=!(!local_05)?m_color23:m_color09;
					break;
				}
				if (! (local_07!=0||strcmp(local_08,"自")!=0) ) {
					local_09=!(!local_05)?m_color20:m_color06;
					break;
				}
				if (local_07!=0||strcmp(local_08,"新")!=0) break;
				local_09=!(!local_05)?m_color19:m_color05;
				break;
			case 3:
				if (local_07==0) {
					if (! (!g_pCMainControl->m_optflg_displayNewCache_||(int)*g_listitemarray[local_03][local_04][8]!=52) ) {
						local_09=!(!local_05)?m_color25:m_color11;
						break;
					}
					local_09=!(!local_05)?m_color19:m_color05;
					break;
				}
				if (local_07==1) {
					local_09=!(!local_05)?m_color23:m_color09;
					break;
				}
				if (local_07==2) {
					local_09=!(!local_05)?m_color18:m_color04;
					break;
				}
				if (local_07==4) {
					if (strcmp(local_08,"仮想ファイル")==0) {
						local_09=!(!local_05)?m_color23:m_color09;
						break;
					}
					if (strcmp(local_08,"完全キャッシュ")==0) {
						local_09=!(!local_05)?m_color18:m_color04;
						break;
					}
					if (strcmp(local_08,"部分キャッシュ")==0) {
						local_09=!(!local_05)?m_color24:m_color10;
						break;
					}
					if (strcmp(local_08,"受可キャッシュ")==0) {
						local_09=!(!local_05)?m_color22:m_color08;
						break;
					}
					if (strcmp(local_08,"UPフォルダ内")!=0) break;
					local_09=!(!local_05)?m_color20:m_color06;
					break;
				}
				if (local_07!=5) break;
				if (g_nazocharbuf[local_03][local_04]!=0) {
					local_09=!(!local_05)?m_color20:m_color06;
					break;
				}
				local_09=!(!local_05)?m_color15:m_color01;
				break;
			case 4:
				if (local_07==0) {
					local_09=!(!local_05)?m_color19:m_color05;
					break;
				}
				if (! (local_07!=1||strcmp(local_08,"BBS")!=0) ) {
					local_09=!(!local_05)?m_color22:m_color08;
					break;
				}
				if (local_07==4) {
					if (*g_listitemarray[local_03][local_04][8]!=0) {
						local_09=!(!local_05)?m_color23:m_color09;
						break;
					}
					if (callatol(g_listitemarray[local_03][local_04][3])>0) {
						local_09=!(!local_05)?m_color22:m_color08;
						break;
					}
					local_09=!(!local_05)?m_color20:m_color06;
					break;
				}
				if (local_07!=6) break;
				local_09=!(!local_05)?m_color22:m_color08;
				break;
			case 5:
				if (local_07==0) {
					local_09=!(!local_05)?m_color19:m_color05;
					break;
				}
				if (! (local_07!=1||strcmp(local_08,"BBS")!=0) ) {
					local_09=!(!local_05)?m_color22:m_color08;
					break;
				}
				if (!(local_07==4)&&local_07!=5) break;
				if (strcmp(local_08,"ON")==0) {
					local_09=!(!local_05)?m_color22:m_color08;
					break;
				}
				local_09=!(!local_05)?m_color26:m_color12;
				break;
			case 6:
				if (local_07==0) {
					if (g_nazocharbuf[local_03][local_04]!=0) {
						local_09=!(!local_05)?m_color20:m_color06;
						break;
					}
					local_09=!(!local_05)?m_color19:m_color05;
					break;
				}
				if (! (local_07!=1||strstr(local_08,"多重")==0) ) {
					local_09=!(!local_05)?m_color27:m_color13;
					break;
				}
				if (! (local_07!=1||strstr(local_08,"失敗")==0) ) {
					local_09=!(!local_05)?m_color20:m_color06;
					break;
				}
				if (! (local_07!=1||strstr(local_08,"済み")==0) ) {
					local_09=!(!local_05)?m_color19:m_color05;
					break;
				}
				if (! (local_07!=1||strstr(local_08,"中")==0) ) {
					local_09=!(!local_05)?m_color22:m_color08;
					break;
				}
				if (! (local_07!=3||strstr(local_08,"キャンセル")==0) ) {
					local_09=!(!local_05)?m_color20:m_color06;
					break;
				}
				if (! (local_07!=3||strstr(local_08,"エラー")==0) ) {
					local_09=!(!local_05)?m_color20:m_color06;
					break;
				}
				if (! (local_07!=3||strstr(local_08,"正常")==0) ) {
					local_09=!(!local_05)?m_color19:m_color05;
					break;
				}
				if (local_07!=3||strstr(local_08,"時間切れ")==0) break;
				local_09=!(!local_05)?m_color20:m_color06;
				break;
			case 7:
				if ((int)*local_08==42) {
					local_09=!(!local_05)?m_color20:m_color06;
					break;
				}
				local_09=!(!local_05)?m_color19:m_color05;
				break;
			case 8:
				if (local_07%2!=0) break;
				local_09=!(!local_05)?m_color19:m_color05;
			}
		}
		bool local_10=( (!(local_07!=0)&&(local_02==pt04||local_02==pt05)) );
		bool local_11=false;
		if (! (!local_10||(int)*local_08!=45) ) {
			local_11=true;
		}
		if (! (local_02!=pt03||local_07!=3) ) {
			TRect local_16=local_14;
			local_16.Bottom=local_16.Bottom-1;
			g_KeyBlocks[local_03][local_04].mf_CKeyBlock_0000(local_01,&local_16);
		} else {
			if (! ((int)*local_08!=32||!(!(local_02!=pt04)&&local_07==6)&&(local_02!=pt06||local_07!=3)) ) {
				TRect local_17=local_14;
				local_17.Bottom=local_17.Bottom-1;
				mf_TMainForm_0210(callatol(local_08+1),local_01,&local_17);
			} else {
				if (*local_08!=0) {
					SetTextColor(Sender->Canvas->Handle,local_09);
					SetBkMode(Sender->Canvas->Handle,1);
					if (! (!(!(local_02!=pt02||local_07<=2)&&local_07<5||!(local_02!=pt03||local_07<=1||local_07>8)&&local_07!=4||!(local_02!=pt09)&&(local_07==1||local_07==3||local_07==7)||!(local_02!=pt04||local_07<=1||local_07==4)&&local_07!=6)&&(!(!(local_02!=pt05)&&(local_07==2||local_07==3))&&(local_02!=pt06||local_07<=1||local_07==3))) ) {
						DrawText(Sender->Canvas->Handle,local_08,-1,&local_14,2086);
					} else {
						DrawText(Sender->Canvas->Handle,!(!local_10)?local_08+1:local_08,-1,&local_14,2084);
					}
				}
			}
		}
		int local_12=(local_14.Top+local_14.Bottom)/2;
		TRect local_18;
		local_18.Left=Sender->TopItem->Left;
		local_18.Right=Sender->TopItem->Left+4;
		local_18.Top=local_12+-2;
		local_18.Bottom=local_12+2;
		if (local_11) {
			Sender->Canvas->Brush->Color=(TColor)0x000000FF;
		}
		Sender->Canvas->FillRect(local_18);
		if (local_06->Count>local_07) {//continue;
			local_14.Left=local_14.Right+8;
			local_14.Right=local_14.Right+m_intarray_unk_[local_07+1];
		}
	}
	return;
}


//このへん不一致あり。むずい。
void TMainForm::mf_TMainForm_0210(int arg_0,TCanvas * arg_1,TRect * arg_2)
{
	float local_00;
	TColor local_01;
	TColor local_02;
	int local_03;
	local_00=(long double)(OptionForm->ColorTrackBar->Position+9)/10.0;
	local_01=(TColor)(((unsigned int)((unsigned char)((int)(255.0/local_00)))|(unsigned int)((unsigned short)((unsigned int)((unsigned char)((int)(255.0/local_00)))))<<8)|(unsigned int)((unsigned char)((int)(128.0/local_00)))<<16);
	local_02=(TColor)(((unsigned int)((unsigned char)((int)(128.0/local_00)))|(unsigned int)((unsigned short)((unsigned int)((unsigned char)((int)(128.0/local_00)))))<<8)|(unsigned int)((unsigned char)((int)(255.0/local_00)))<<16);
	arg_2->Top=arg_2->Top+1;
	arg_2->Bottom=arg_2->Bottom-1;
	local_03=arg_2->Right-arg_2->Left;

	if (g_pCMainControl!=0) {
		TColor local_04;
		double local_05;
		int local_06;
		local_04=arg_1->Brush->Color;
		local_05=arg_0/10000.0;
		local_06=(int)((double)local_03*local_05);
		int local_07;
		int local_08;
		int local_09;
		int local_10;
		local_10=arg_2->Left;
		local_08=arg_2->Left+local_06;
		local_09=arg_2->Top;
		local_07=arg_2->Bottom;
		arg_1->Brush->Color=local_01;
		TRect local_11;
		local_11.Left=local_10;
		local_11.Top=local_09;
		local_11.Right=local_08;
		local_11.Bottom=local_07;
		arg_1->FillRect(local_11);
		local_10=arg_2->Left+local_06;
		local_08=arg_2->Right;
		arg_1->Brush->Color=local_02;
		TRect local_12;
		local_12.Left=local_10;
		local_12.Top=local_09;
		local_12.Right=local_08;
		local_12.Bottom=local_07;
		arg_1->FillRect(local_12);
		SetBkMode(arg_1->Handle,1);

		char local_13[32];
		sprintf(local_13,"%d%%",(int)(local_05*100.0));
		SetTextColor(arg_1->Handle,0);
		arg_2->Top=arg_2->Top+1;
		arg_2->Bottom=arg_2->Bottom+1;
		DrawText(arg_1->Handle,local_13,-1,arg_2,2085);
		SetTextColor(arg_1->Handle,(TColor)0x80ff80);
		arg_2->Left=arg_2->Left-1;
		arg_2->Right=arg_2->Right-1;
		arg_2->Top=arg_2->Top-1;
		arg_2->Bottom=arg_2->Bottom-1;
		DrawText(arg_1->Handle,local_13,-1,arg_2,2085);

		arg_1->Brush->Color=local_04;
	}
	return;
}


void __fastcall TMainForm::TaskAddIgnoreClick(TObject * Sender)
{
	TListView * local_00;
	xint local_01;
	char local_06[256];
	local_00=g_UpperListViews[m_char_upperPageType_];
	local_01=0;
	if (SubTaskAddIgnore==Sender) {
		local_00=g_LowerListViews[m_char_lowerPageType_];
		local_01=1;
	}
	for (int local_02=0; local_00->Items->Count>local_02; local_02++) {
		if (!local_00->Items->Item[local_02]->Selected||g_nazouintarray[local_01][local_02]<0) continue;
		CGlobalLock CGLock;
		CAutoDownList * local_03;
		local_03=g_pCMainControl->mf_CMainControl_0130(g_nazouintarray[local_01][local_02]);
		CWork * local_04;
		local_04=NULLPO;
		if (local_03->m_int_unk4>=0) {
			local_04=g_pCMainControl->GetWork(local_03->m_int_unk4);
		}
		CKey * local_05;
		local_05=NULLPO;
		if (! (!(local_04==0)&&local_04->m_worktype_==WORKTYPE01) ) {
			if (local_03->mf_CAutoDownList_0020()) {
				local_05=g_pCMainControl->mf_CMainControl_0180(0,local_03->m_hash_kamo);
			}
		} else {
			local_05=g_pCMainControl->mf_CMainControl_0180(local_04->m_uint_countMax_,local_04->m_uchar16_unk1);
		}
		if (local_05!=0) {
			AutoDownForm->KeywordCombo->Items=(SearchComboBox->Items);
			AutoDownForm->TripCombo->Items=(TripComboBox->Items);
			AutoDownForm->KeywordCombo->Text=local_05->mf_CKey_0260();
			AutoDownForm->TripCombo->Text=local_05->mf_CKey_0000();
			ny_binhash2aschash(local_05->m_hash_tabun,local_06);
			AutoDownForm->HashEdit->Text=local_06;
			AutoDownForm->UpperSizeEdit->Text="";
			AutoDownForm->LowerSizeEdit->Text="";
			AutoDownForm->BbsCheck->Checked=false;
			AutoDownForm->AutoDeleteCheck->Checked=false;
			AutoDownForm->IgnoreCheck->Checked=true;
			AutoDownForm->DeleteCheck->Checked=true;
			AutoDownForm->DisconnectCheck->Checked=true;
			AutoDownForm->DeleteCheck->Enabled=false;
			AutoDownForm->DisconnectCheck->Enabled=false;
			AutoDownForm->DisconnectLabel->Enabled=false;
			AutoDownForm->OkButton->Caption="追加";
			AutoDownForm->m_int1=-1;
			AutoDownForm->m_int2=-1;
			AutoDownForm->Show();
			AutoDownForm->KeywordCombo->SetFocus();
		} else {
			MessageBox(NULL,"キーが見つかりません","Winny",0x00042030);
		}
		break;
	}
	return;
}


void __fastcall TMainForm::TopToolButton1Click(TObject * Sender)
{
	switch ((int)m_char_upperPageType_) {
	case 0:  
		NodeAddButtonClick();
		break;
	case 1:  
		BbsNodeAddButtonClick();
		break;
	case 2:  
		FolderAddButtonClick();
		break;
	case 3:  
		SearchUpFolderButtonClick();
		break;
	case 4:
		DownAddButtonClick();
		break;
	case 5:  
		IgnoreAddButtonClick();
		break;
	case 6:
		TaskClearButtonClick(false);
		break;
	case 7:  
		LogClearButtonClick();
	}
	return;
}


void __fastcall TMainForm::TopToolButton2Click(TObject * Sender)
{
	switch ((int)m_char_upperPageType_) {
	case 0:  
		NodeConnectButtonClick();
		break;
	case 1:  
		BbsNodeDisconnectButtonClick();
		break;
	case 2:  
		FolderDeleteButtonClick(RemoveFolder);
		break;
	case 3:  
		SearchCacheFolderButtonClick();
		break;
	case 4:  
		DownDeleteButtonClick(DeleteDownList);
		break;
	case 5:  
		IgnoreDeleteButtonClick(DeleteIgnoreList);
		break;
	case 6:  
		TaskDeleteButtonClick(ClearTask);
	}
	return;
}


void __fastcall TMainForm::TopToolButton3Click(TObject * Sender)
{
	switch ((int)m_char_upperPageType_) {
	case 0:
		NodeDisconnectButtonClick();
		break;
	case 1:  
		CacheClearButtonClick();
		break;
	case 2:  
		FolderRefreshButtonClick();
		break;
	case 3:
		SearchTmpCacheButtonClick();
		break;
	case 4:  
		DownEditButtonClick();
		break;
	case 5:  
		IgnoreEditButtonClick();
		break;
	case 6:  
		ConvertWaitButtonClick();
	}
	return;
}


void __fastcall TMainForm::TopToolButton4Click(TObject * Sender)
{
	switch ((int)m_char_upperPageType_) {
	case 0:  
		NodeSearchDisconnectButtonClick();
		break;
	case 1:  
		BbsBrowserButtonClick(NULLPO);
		break;
	case 2:  
		UpFolderOpenButtonClick(OpenFolder);
		break;
	case 3:  
		SearchPriorButtonClick();
		break;
	case 4:  
		DownReloadButtonClick();
		break;
	case 5:  
		IgnoreReloadButtonClick();
		break;
	case 6:  
		g_pCMainControl->m_optflg_useMultiDownload_=!g_pCMainControl->m_optflg_useMultiDownload_;
		g_pTIniFile->WriteInteger("Option","UseMultiDownload",!(!g_pCMainControl->m_optflg_useMultiDownload_)?1:0);
	}
	return;
}


void __fastcall TMainForm::TopToolButton5Click(TObject * Sender)
{
	switch ((int)m_char_upperPageType_) {
	case 0:  
		IpConvButtonClick();
		break;
	case 1:  
		BbsPortScanButtonClick();
		break;
	case 2:  
		DownFolderOpenButtonClick();
		break;
	case 4:  
		mf_TMainForm_0220();
		break;
	case 5:  
		IgnoreSearchButtonClick();
		break;
	case 6:  
		g_pCMainControl->m_optflg_cutSlowTransfer_=!g_pCMainControl->m_optflg_cutSlowTransfer_;
		g_pTIniFile->WriteInteger("Option","CutSlowLine",!(!g_pCMainControl->m_optflg_cutSlowTransfer_)?1:0);
	}
	return;
}



void __fastcall TMainForm::TopToolButton6Click(TObject * Sender)
{
	switch (m_char_upperPageType_) {
	case 6:  
		g_pCMainControl->m_optflg_useTransferLimit_=(bool)!g_pCMainControl->m_optflg_useTransferLimit_;
		g_pTIniFile->WriteInteger("Option","UseTransferLimit",!(!g_pCMainControl->m_optflg_useTransferLimit_)?1:0);
	}
	return;
}


void __fastcall TMainForm::BottomToolButton1Click(TObject * Sender)
{
	switch ((int)m_char_lowerPageType_) {
	case 0:  
		NodeAddButtonClick();
		break;
	case 1:  
		BbsNodeAddButtonClick();
		break;
	case 2:  
		FolderAddButtonClick();
		break;
	case 3:  
		SearchUpFolderButtonClick();
		break;
	case 4:  
		DownAddButtonClick();
		break;
	case 5:  
		IgnoreAddButtonClick();
		break;
	case 6:  
		TaskClearButtonClick(true);
		break;
	case 7:  
		LogClearButtonClick();
	}
	return;
}


void __fastcall TMainForm::BottomToolButton2Click(TObject * Sender)
{
	switch ((int)m_char_lowerPageType_) {
	case 0:  
		NodeConnectButtonClick();
		break;
	case 1:  
		BbsNodeDisconnectButtonClick();
		break;
	case 2:  
		FolderDeleteButtonClick(SubRemoveFolder);
		break;
	case 3:  
		SearchCacheFolderButtonClick();
		break;
	case 4:  
		DownDeleteButtonClick(SubDeleteDownList);
		break;
	case 5:  
		IgnoreDeleteButtonClick(SubDeleteIgnoreList);
		break;
	case 6:
		TaskDeleteButtonClick(SubClearTask);
	}
	return;
}


void __fastcall TMainForm::BottomToolButton3Click(TObject * Sender)
{
	switch ((int)m_char_lowerPageType_) {
	case 0:  
		NodeDisconnectButtonClick();
		break;
	case 1:  
		CacheClearButtonClick();
		break;
	case 2:  
		FolderRefreshButtonClick();
		break;
	case 3:  
		SearchTmpCacheButtonClick();
		break;
	case 4:  
		DownEditButtonClick();
		break;
	case 5:
		IgnoreEditButtonClick();
		break;
	case 6:  
		ConvertWaitButtonClick();
	}
	return;
}


void __fastcall TMainForm::BottomToolButton4Click(TObject * Sender)
{
	switch ((int)m_char_lowerPageType_) {
	case 0:  
		NodeSearchDisconnectButtonClick();
		break;
	case 1:
		BbsBrowserButtonClick(NULLPO);
		break;
	case 2:  
		UpFolderOpenButtonClick(SubOpenFolder);
		break;
	case 3:  
		SearchPriorButtonClick();
		break;
	case 4:  
		DownReloadButtonClick();
		break;
	case 5:  
		IgnoreReloadButtonClick();
		break;
	case 6:  
		g_pCMainControl->m_optflg_useMultiDownload_=!g_pCMainControl->m_optflg_useMultiDownload_;
		g_pTIniFile->WriteInteger("Option","UseMultiDownload",!(!g_pCMainControl->m_optflg_useMultiDownload_)?1:0);
	}
	return;
}


void __fastcall TMainForm::BottomToolButton5Click(TObject * Sender)
{
	switch ((int)m_char_lowerPageType_) {
	case 0:  
		IpConvButtonClick();
		break;
	case 1:  
		BbsPortScanButtonClick();
		break;
	case 2:  
		DownFolderOpenButtonClick();
		break;
	case 4:
		mf_TMainForm_0220();
		break;
	case 5:
		IgnoreSearchButtonClick();
		break;
	case 6:  
		g_pCMainControl->m_optflg_cutSlowTransfer_=!g_pCMainControl->m_optflg_cutSlowTransfer_;
		g_pTIniFile->WriteInteger("Option","CutSlowLine",!(!g_pCMainControl->m_optflg_cutSlowTransfer_)?1:0);
	}
	return;
}



void __fastcall TMainForm::BottomToolButton6Click(TObject * Sender)
{
	switch (m_char_lowerPageType_) {
	case 6:  
		g_pCMainControl->m_optflg_useTransferLimit_=(bool)!g_pCMainControl->m_optflg_useTransferLimit_;
		g_pTIniFile->WriteInteger("Option","UseTransferLimit",!(!g_pCMainControl->m_optflg_useTransferLimit_)?1:0);
	}
	return;
}


void __fastcall TMainForm::BbsTreeMouseDown(TObject * Sender,TMouseButton Button,TShiftState Shift,int X,int Y)
{
	BbsTreeClickTimer->Enabled=true;
	return;
}


void __fastcall TMainForm::BbsBrowserButtonClick(TObject * Sender)
{
	CGlobalLock CGLock;
	g_pCMainControl->mf_CMainControl_1040(0,NULLPO);
	return;
}


void __fastcall TMainForm::CacheClearButton2Click(TObject * Sender)
{
	CacheClearButtonClick();
	return;
}


void __fastcall TMainForm::BbsPortScanButton2Click(TObject * Sender)
{
	BbsPortScanButtonClick();
	return;
}



void __fastcall TMainForm::BbsViewMouseDown(TObject * Sender,TMouseButton Button,TShiftState Shift,int X,int Y)
{
	char local_11[1024];
	if (Button==mbLeft/*0*/) {
		TPoint local_03;
		TPoint		local_point=BbsView->ClientToPhysicalCharPos(X,Y);
		local_03=local_point;
		if (local_03.y/*local_01*/>=0) {
			TRichTVItem * local_04=BbsView->Strings->Items[local_03.y/*local_01*/];
			AnsiString local_00=(AnsiString)local_04->GetEmbed(local_03.x/*local_02*/+1);
			const char * local_05=local_00.c_str();
			if (local_05!=0) {
				CGlobalLock CGLock;
				if ((int)*local_05==62) {
					strcpy(local_11,local_05);
					char * local_06=local_11+1;
					if ((int)local_11[1]==62) {
						local_06=local_06+1;
					}
					char * local_07=local_06;
					int local_08=0;
					for ( ; !((int)*local_06<48)&&(int)*local_06<=57; local_06++) {
					}
					*local_06=0;
					unsigned int local_09=callatol(local_07)-1;
					int local_10=0;
					if (g_pCMainControl->m_vectorInt__1.size()>local_09) {
						local_10=g_pCMainControl->m_vectorInt__1[local_09];
					}
					BbsView->SetTop(local_10-1);
					BbsView->SetMarkCommand();
					BbsView->Refresh();
				}
				if (strncmp(local_05,"http://",7)==0) {
					SHELLEXECUTEINFO local_12;
					local_12.cbSize=60;
					local_12.hwnd=NULL;
					local_12.fMask=0;
					local_12.lpVerb="open";
					if (g_pCMainControl->m_str_optUrlBrowser_.Length()>0) {
						local_12.lpFile=g_pCMainControl->m_str_optUrlBrowser_.c_str();
						local_12.lpParameters=local_05;
					} else {
						local_12.lpFile=local_05;
						local_12.lpParameters=NULLPO;
					}
					local_12.lpDirectory=NULLPO;
					local_12.nShow=1;
					local_12.lpIDList=NULLPO;
					ShellExecuteEx(&local_12);
				}
			}
		}
	}
	return;
}



void TMainForm::mf_TMainForm_0220()
{
	FILE * local_01;
	int local_02;
	char local_03[4096];
	char local_04[4096];
	char pad[240];	//local_05が256の可能性が大かも
	unsigned char local_05[16];
	struct__finddata_t local_06;
	if (MessageBox(NULL,"ダウンフォルダ内のマークファイルを元に、変換保留したキャッシュを再変換しますか？","Winny",0x00042024)==7) {
		return;
	}
	CGlobalLock CGLock;
	sprintf(local_03,"%s%s",/*(const char *)*/g_AppPath,"Download.txt");
	local_01=fopen(local_03,"at");
	if (local_01==0) {
		return;
	}
	sprintf(local_03,"%s\\*.*",g_pCMainControl->m_sz_DownFolderPath_);
	if ((local_02=_findfirst(local_03,&local_06))>=0) {
		AnsiString local_00;
		if (! ((*((char *)(&local_06.attrib))&16)!=0||strlen(local_06.name)<34||(int)local_06.name[0]!=95||(int)local_06.name[33]!=95||local_06.size!=0) ) {
			strcpy(local_04,local_06.name);
			local_04[33]=0;
			ny_aschash2binhash(&local_04[1],local_05);
			g_pCMainControl->mf_CMainControl_0060(&local_04[34],0,local_05,"",0.0,0.0,false,true,false,false,true);
			sprintf(local_03,"%s\\%s",g_pCMainControl->m_sz_DownFolderPath_,local_06.name);
			_unlink(local_03);
		}
		while (_findnext(local_02,&local_06)==0) {
			if (! ((*((char *)(&local_06.attrib))&16)!=0||strlen(local_06.name)<34||(int)local_06.name[0]!=95||(int)local_06.name[33]!=95||local_06.size!=0) ) {
				strcpy(local_04,local_06.name);
				local_04[33]=0;
				ny_aschash2binhash(&local_04[1],local_05);
				g_pCMainControl->mf_CMainControl_0060(&local_04[34],0,local_05,"",0.0,0.0,false,true,false,false,true);
				sprintf(local_03,"%s\\%s",g_pCMainControl->m_sz_DownFolderPath_,local_06.name);
				_unlink(local_03);
			}
		}
		_findclose(local_02);
	}
	fclose(local_01);
	if (g_AppPath.Length()!=0) {
		sprintf(local_03,"%s%s",/*(const char *)*/g_AppPath,"Download.txt");
		g_pCMainControl->mf_CMainControl_0110(local_03);
	}
	DownReloadButtonClick();
	mf_TMainForm_0150(pt04);
	g_pCMainControl->mf_CMainControl_0760();
	return;
}


void __fastcall TMainForm::SearchTabModeButtonClick(int arg_0)
{
	mf_TMainForm_0140();
	return;
}


void __fastcall TMainForm::ReloadSearchHistoryClick(TObject * Sender)
{
	FILE * local_00;
	char local_01[1024];
	sprintf(local_01,"%s%s",/*(const char *)*/g_AppPath,"Search.txt");
	local_00=fopen(local_01,"rt");
	if (local_00!=0) {
		fclose(local_00);
		SearchComboBox->Items->LoadFromFile(local_01);
	}
	return;
}


void __fastcall TMainForm::ClearSearchHistoryClick(TObject * Sender)
{
	if (MessageBox(NULL,"検索履歴をクリアしますか？","Winny",0x00042024)==7) {
		return;
	}
	SearchComboBox->Items->Clear();
	SearchComboBox->Text="";
	SearchButtonClick(SearchButton);
	return;
}


void __fastcall TMainForm::EditSearchHistroyClick(TObject * Sender)
{
	char local_00[1024];
	SHELLEXECUTEINFO local_01;
	sprintf(local_00,"%s%s",/*(const char *)*/g_AppPath,"Search.txt");
	local_01.cbSize=60;
	local_01.hwnd=NULL;
	local_01.fMask=0;
	local_01.lpVerb="open";
	local_01.lpFile=local_00;
	local_01.lpParameters=NULLPO;
	local_01.lpDirectory=NULLPO;
	local_01.nShow=1;
	local_01.lpIDList=NULLPO;
	ShellExecuteEx(&local_01);
	return;
}


void __fastcall TMainForm::ClearTripHistoryClick(TObject * Sender)
{
	char local_00[1024];
	if (MessageBox(NULL,"トリップ履歴をクリアしますか？","Winny",0x00042024)==7) {
		return;
	}
	sprintf(local_00,"%s%s",/*(const char *)*/g_AppPath,"SearchTrip.txt");
	FILE *fp=fopen(local_00,"wt");
	fclose(fp);
	TripComboBox->Items->Clear();
	TripComboBox->Text="";
	SearchButtonClick(SearchButton);
}


void __fastcall TMainForm::EditTabClick(TObject * Sender)
{
	char local_00[1024];
	SHELLEXECUTEINFO local_01;
	sprintf(local_00,"%s%s",/*(const char *)*/g_AppPath,!(Sender!=EditTab)?"Tab1.txt":"Tab2.txt");
	local_01.cbSize=60;
	local_01.hwnd=NULL;
	local_01.fMask=0;
	local_01.lpVerb="open";
	local_01.lpFile=local_00;
	local_01.lpParameters=NULLPO;
	local_01.lpDirectory=NULLPO;
	local_01.nShow=1;
	local_01.lpIDList=NULLPO;
	ShellExecuteEx(&local_01);
	return;
}


void __fastcall TMainForm::ReloadTabClick(TObject * Sender)
{
	char local_02[1024];
	if (Sender==ReloadTab) {
		sprintf(local_02,"%s%s",/*(const char *)*/g_AppPath,"Tab1.txt");
		FILE * local_00=fopen(local_02,"rt");
		if (local_00!=0) {
			fclose(local_00);
			SearchTabControl->Tabs->LoadFromFile(local_02);
		}
	} else {
		sprintf(local_02,"%s%s",/*(const char *)*/g_AppPath,"Tab2.txt");
		FILE * local_01=fopen(local_02,"rt");
		if (local_01!=0) {
			fclose(local_01);
			SubSearchTabControl->Tabs->LoadFromFile(local_02);
		}
	}
	return;
}


void __fastcall TMainForm::TimerTimer(TObject * Sender)
{
	int local_00;
	int local_01;
	if (! (g_pCMainControl==0||MainForm==0||!Visible) ) {
		Timer->Enabled=false;
		if (!BbsButton->Down) {
			local_00=mf_TMainForm_0070();
			if (! (!(local_00!=6)&&SubTaskView->Selected!=0||(local_00==3||!BottomButton->Down)) ) {
				TabControlChange(SubTabControl);
			}
			local_01=mf_TMainForm_0060();
			if (! (!(local_01!=6)&&TaskView->Selected!=0||local_01==3) ) {
				TabControlChange(TabControl);
			}
		}
		MainPanel->DisableAlign();
		mf_TMainForm_0120();
		mf_TMainForm_0130();
		mf_TMainForm_0140();
		MainPanel->EnableAlign();
		if (BbsButton->Down) {
			mf_TMainForm_0190();
		}
		Timer->Enabled=true;
	}
	return;
}


void __fastcall TMainForm::NodeModeClick(TObject * Sender)
{
	TopCheckListBox->Checked[0]=!TopCheckListBox->Checked[0];
	mf_TMainForm_0040();
	mf_TMainForm_0080();
	return;
}


void __fastcall TMainForm::BbsNodeModeClick(TObject * Sender)
{
	TopCheckListBox->Checked[1]=!TopCheckListBox->Checked[1];
	mf_TMainForm_0040();
	mf_TMainForm_0080();
	return;
}


void __fastcall TMainForm::FolderModeClick(TObject * Sender)
{
	TopCheckListBox->Checked[2]=!TopCheckListBox->Checked[2];
	mf_TMainForm_0040();
	mf_TMainForm_0080();
	return;
}


void __fastcall TMainForm::FileModeClick(TObject * Sender)
{
	TopCheckListBox->Checked[3]=!TopCheckListBox->Checked[3];
	mf_TMainForm_0040();
	mf_TMainForm_0080();
	return;
}


void __fastcall TMainForm::DownModeClick(TObject * Sender)
{
	TopCheckListBox->Checked[4]=!TopCheckListBox->Checked[4];
	mf_TMainForm_0040();
	mf_TMainForm_0080();
	return;
}


void __fastcall TMainForm::IgnoreModeClick(TObject * Sender)
{
	TopCheckListBox->Checked[5]=!TopCheckListBox->Checked[5];
	mf_TMainForm_0040();
	mf_TMainForm_0080();
	return;
}


void __fastcall TMainForm::TaskModeClick(TObject * Sender)
{
	TopCheckListBox->Checked[6]=!TopCheckListBox->Checked[6];
	mf_TMainForm_0040();
	mf_TMainForm_0080();
	return;
}


void __fastcall TMainForm::LogModeClick(TObject * Sender)
{
	TopCheckListBox->Checked[7]=!TopCheckListBox->Checked[7];
	mf_TMainForm_0040();
	mf_TMainForm_0080();
	return;
}


void __fastcall TMainForm::SystemModeClick(TObject * Sender)
{
	TopCheckListBox->Checked[8]=!TopCheckListBox->Checked[8];
	mf_TMainForm_0040();
	mf_TMainForm_0080();
	return;
}


void __fastcall TMainForm::SubNodeModeClick(TObject * Sender)
{
	BottomCheckListBox->Checked[0]=!BottomCheckListBox->Checked[0];
	mf_TMainForm_0050();
	mf_TMainForm_0080();
	return;
}


void __fastcall TMainForm::SubBbsNodeModeClick(TObject * Sender)
{
	BottomCheckListBox->Checked[1]=!BottomCheckListBox->Checked[1];
	mf_TMainForm_0050();
	mf_TMainForm_0080();
	return;
}


void __fastcall TMainForm::SubFolderModeClick(TObject * Sender)
{
	BottomCheckListBox->Checked[2]=!BottomCheckListBox->Checked[2];
	mf_TMainForm_0050();
	mf_TMainForm_0080();
	return;
}


void __fastcall TMainForm::SubFileModeClick(TObject * Sender)
{
	BottomCheckListBox->Checked[3]=!BottomCheckListBox->Checked[3];
	mf_TMainForm_0050();
	mf_TMainForm_0080();
	return;
}


void __fastcall TMainForm::SubDownModeClick(TObject * Sender)
{
	BottomCheckListBox->Checked[4]=!BottomCheckListBox->Checked[4];
	mf_TMainForm_0050();
	mf_TMainForm_0080();
	return;
}


void __fastcall TMainForm::SubIgnoreModeClick(TObject * Sender)
{
	BottomCheckListBox->Checked[5]=!BottomCheckListBox->Checked[5];
	mf_TMainForm_0050();
	mf_TMainForm_0080();
	return;
}


void __fastcall TMainForm::SubTaskModeClick(TObject * Sender)
{
	BottomCheckListBox->Checked[6]=!BottomCheckListBox->Checked[6];
	mf_TMainForm_0050();
	mf_TMainForm_0080();
	return;
}


void __fastcall TMainForm::SubLogModeClick(TObject * Sender)
{
	BottomCheckListBox->Checked[7]=!BottomCheckListBox->Checked[7];
	mf_TMainForm_0050();
	mf_TMainForm_0080();
	return;
}


void __fastcall TMainForm::SubSystemModeClick(TObject * Sender)
{
	BottomCheckListBox->Checked[8]=!BottomCheckListBox->Checked[8];
	mf_TMainForm_0050();
	mf_TMainForm_0080();
	return;
}


void __fastcall TMainForm::BoardRefreshTimerTimer(TObject * Sender)
{
	if (!BbsButton->Down) {
		return;
	}
	if (BoardTabControl->Tabs->Count<=0) {
		return;
	}
	int local_02=BoardTabControl->TabIndex;
	AnsiString local_00="";
	if (local_02>=0) {
		AnsiString local_01=(BoardTabControl->Tabs->Strings[local_02]);
		if (local_01=="* ") {
			local_00="[BBS_";
		} else {
			if (local_01.SubString(0,2)=="* ") {
				local_00=local_01.SubString(3,255);
			} else {
				local_00=("[BBS_"+local_01)+"]";
			}
		}
		g_pCMainControl->mf_CMainControl_1070(local_00.c_str());
	}
	return;
}





//---------------------------------------------------------------------------
