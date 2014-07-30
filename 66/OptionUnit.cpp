//---------------------------------------------------------------------------
#include "hdrs.h"

#include <vcl.h>
#pragma hdrstop


#include <shlobj.h>

#include "def.h"

#include "MainUnit.h"
#include "OptionUnit.h"

#include "def2.h"
#include "globals.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TOptionForm *OptionForm;
//---------------------------------------------------------------------------

__fastcall TOptionForm::TOptionForm(TComponent * Owner)
        : TForm(Owner)
{
	FormShow(NULLPO);
}


void __fastcall TOptionForm::FormShow(TObject * Sender)
{
	TColor local_01;
	char local_02[256];
	AnsiString local_00;
	BbsOnlyCheckBox->Checked=g_pCMainControl->m_optflg_UseBbsOnly_;
	AutoDisconnectCheckBox->Checked=g_pCMainControl->m_optflg_autoDisconnect_;
	FastDownCheckBox->Checked=g_pCMainControl->m_optflg_downRetryFast_;
	MultiDownCheckBox->Checked=g_pCMainControl->m_optflg_useMultiDownload_;
	SlowCutCheckBox->Checked=g_pCMainControl->m_optflg_cutSlowTransfer_;
	TransLimitCheckBox->Checked=g_pCMainControl->m_optflg_useTransferLimit_;
	AutoTabChangeCheckBox->Checked=g_pCMainControl->m_optflg_autoTabChange_;
	NotConvertCheck->Checked=g_pCMainControl->m_optflag_notConvert__;
	CacheVersionCheck->Checked=g_pCMainControl->m_optflg_displayNewCache_;
	VirtualKeyCombo->Text=g_pCMainControl->m_int_virtualKeyMax_;
	V4CacheNotDownCheck->Checked=g_pCMainControl->m_optflg_V4CacheNotDown_;
	MakeMarkCheck->Checked=g_pCMainControl->m_optflg_makeMarkFile_;
	local_00=g_pTIniFile->ReadString("Color","WindowBackGround","300000");
	sscanf(local_00.c_str(),"%X",&local_01);
	WindowColorBox->Selected=local_01;
	sprintf(local_02,"%X",0x80000005);
	local_00=g_pTIniFile->ReadString("Color","BbsWindowBackGround",local_02);
	sscanf(local_00.c_str(),"%X",&local_01);
	BbsWindowColorBox->Selected=local_01;
	local_00=g_pTIniFile->ReadString("Color","ToolBarBackGround","808080");
	sscanf(local_00.c_str(),"%X",&local_01);
	ToolbarColorBox->Selected=local_01;
	local_00=g_pTIniFile->ReadString("Color","ToolBarString","008000");
	sscanf(local_00.c_str(),"%X",&local_01);
	ToolStringColorBox->Selected=local_01;
	sprintf(local_02,"%X",0x8000000F);
	local_00=g_pTIniFile->ReadString("Color","SearchBarBackGround",local_02);
	sscanf(local_00.c_str(),"%X",&local_01);
	SearchBarColorBox->Selected=local_01;
	sprintf(local_02,"%X",0x80000012);
	local_00=g_pTIniFile->ReadString("Color","SearchBarString",local_02);
	sscanf(local_00.c_str(),"%X",&local_01);
	SearchStringColorBox->Selected=local_01;
	local_00=g_pTIniFile->ReadString("Color","BbsToolBarBackGround","808080");
	sscanf(local_00.c_str(),"%X",&local_01);
	BbsToolbarColorBox->Selected=local_01;
	local_00=g_pTIniFile->ReadString("Color","BbsToolBarString","FFFFFF");
	sscanf(local_00.c_str(),"%X",&local_01);
	BbsToolStringColorBox->Selected=local_01;
	sprintf(local_02,"%X",0x8000000F);
	local_00=g_pTIniFile->ReadString("Color","BbsSearchBarBackGround",local_02);
	sscanf(local_00.c_str(),"%X",&local_01);
	BbsSearchBarColorBox->Selected=local_01;
	sprintf(local_02,"%X",0x80000012);
	local_00=g_pTIniFile->ReadString("Color","BbsSearchBarString",local_02);
	sscanf(local_00.c_str(),"%X",&local_01);
	BbsSearchStringColorBox->Selected=local_01;
	local_00=g_pTIniFile->ReadString("Color","SubStatusString","FFFFFF");
	sscanf(local_00.c_str(),"%X",&local_01);
	SubStatusColorBox->Selected=local_01;
	ColorTrackBar->Position=g_pTIniFile->ReadInteger("Color","StringColor",0);
	BbsColorTrackBar->Position=g_pTIniFile->ReadInteger("Color","BbsStringColor",2);
	TreeClickCombo->ItemIndex=(g_pTIniFile->ReadInteger("Bbs","TreeClickAction",1));
	TreeDoubleClickCombo->ItemIndex=(g_pTIniFile->ReadInteger("Bbs","TreeDoubleClickAction",2));
	ThreadClickCombo->ItemIndex=(g_pTIniFile->ReadInteger("Bbs","ThreadClickAction",1));
	ThreadDoubleClickCombo->ItemIndex=(g_pTIniFile->ReadInteger("Bbs","ThreadDoubleClickAction",2));
	MainForm->SystemView->Font->Name=g_pTIniFile->ReadString("FileFont","Name","ＭＳ Ｐゴシック");
	MainForm->SystemView->Font->Size=g_pTIniFile->ReadInteger("FileFont","Size",9);
	MainForm->SystemView->Font->Charset=(TFontCharset)1;
	local_00=g_pTIniFile->ReadString("FileFont","Color","FFFFFF");
	sscanf(local_00.c_str(),"%X",&local_01);
	MainForm->SystemView->Font->Color=local_01;
	MainForm->BbsBoardView->Font->Name=g_pTIniFile->ReadString("BoardFont","Name","ＭＳ Ｐゴシック");
	MainForm->BbsBoardView->Font->Size=g_pTIniFile->ReadInteger("BoardFont","Size",9);
	MainForm->BbsBoardView->Font->Charset=(TFontCharset)1;
	local_00=g_pTIniFile->ReadString("BoardFont","Color","0");
	sscanf(local_00.c_str(),"%X",&local_01);
	MainForm->BbsBoardView->Font->Color=local_01;
	MainForm->BbsView->Font->Name=g_pTIniFile->ReadString("BbsFont","Name","ＭＳ Ｐゴシック");
	MainForm->BbsView->Font->Size=g_pTIniFile->ReadInteger("BbsFont","Size",9);
	MainForm->BbsView->Font->Charset=(TFontCharset)1;
	local_00=g_pTIniFile->ReadString("BbsFont","Color","0");
	sscanf(local_00.c_str(),"%X",&local_01);
	MainForm->BbsView->Font->Color=local_01;
	MainForm->BbsView->SetFont(MainForm->BbsView->Font->Name,MainForm->BbsView->Font->Size);
	SearchTabUseCheck->Checked=g_pTIniFile->ReadInteger("Option","SearchTabUse",1)>0;
	UpperSearchTabCheck->Checked=g_pTIniFile->ReadInteger("Option","UpperSearchTab",1)>0;
	AlwaysShowSearchTabCheck->Checked=g_pTIniFile->ReadInteger("Option","AlwaysShowSearchTab",0)>0;
	InitialFileViewLeftPaneCheck->Checked=g_pTIniFile->ReadInteger("Option","InitialFileViewLeftPane",0)>0;
	InitialFileViewTopPaneCheck->Checked=g_pTIniFile->ReadInteger("Option","InitialFileViewTopPane",1)>0;
	InitialFileViewBottomPaneCheck->Checked=g_pTIniFile->ReadInteger("Option","InitialFileViewBottomPane",0)>0;
	InitialBbsViewLeftPaneCheck->Checked=g_pTIniFile->ReadInteger("Option","InitialBbsViewLeftPane",1)>0;
	InitialBbsViewTopPaneCheck->Checked=g_pTIniFile->ReadInteger("Option","InitialBbsViewTopPane",1)>0;
	InitialBbsViewBottomPaneCheck->Checked=g_pTIniFile->ReadInteger("Option","InitialBbsViewBottomPane",1)>0;
	FileTabModeCombo->ItemIndex=(g_pTIniFile->ReadInteger("Option","FileTabMode",1));
	SearchTabModeCombo->ItemIndex=(g_pTIniFile->ReadInteger("Option","SearchTabMode",2));
	BoardTabModeCombo->ItemIndex=(g_pTIniFile->ReadInteger("Option","BoardTabMode",2));
	BbsTabModeCombo->ItemIndex=(g_pTIniFile->ReadInteger("Option","BbsTabMode",2));
	FlatToolBarCheck->Checked=g_pTIniFile->ReadInteger("Option","FileFlatToolBar",0)!=0;
	BbsFlatToolBarCheck->Checked=g_pTIniFile->ReadInteger("Option","BbsFlatToolBar",1)!=0;
	TransparentToolBarCheck->Checked=g_pTIniFile->ReadInteger("Option","FileTransparentToolBar",1)!=0;
	BbsTransparentToolBarCheck->Checked=g_pTIniFile->ReadInteger("Option","BbsTransparentToolBar",1)!=0;
	AutoCopyDownInfoCheck->Checked=g_pTIniFile->ReadInteger("Option","AutoCopyDownInfoToTab",1)>0;
	UpperSearchTabCheckClick(NULLPO);
	WindowColorBoxChange(NULLPO);
	BbsWindowColorBoxChange(NULLPO);
	ToolbarColorBoxChange(NULLPO);
	FileTabModeComboChange(NULLPO);
	SearchTabModeComboChange(NULLPO);
	BoardTabModeComboChange(NULLPO);
	BbsTabModeComboChange(NULLPO);
	FlatToolBarCheckClick(NULLPO);
	m_flag=false;
	return;
}


void __fastcall TOptionForm::CancelButtonClick(TObject * Sender)
{
	FormShow(NULLPO);
	MainForm->BbsTabControlChange(MainForm->BbsTabControl);
	Close();
	return;
}


void __fastcall TOptionForm::CachePathReferButtonClick(TObject * Sender)
{
	IMalloc * local_00;
	ITEMIDLIST * local_01;
	BROWSEINFO local_02;
	char local_03[260];
	if (SHGetMalloc(&local_00)>=0) {
		local_02.hwndOwner=Handle;
		local_02.pidlRoot=NULLPO;
		local_02.pszDisplayName=NULLPO;
		local_02.lpszTitle="フォルダ選択";
		local_02.ulFlags=1;
		local_02.lpfn=NULLPO;
		local_02.lParam=0;
		local_02.iImage=0;
		local_01=SHBrowseForFolder(&local_02);
		if (local_01!=0) {
			SHGetPathFromIDList(local_01,local_03);
			CachePathEdit->Text=local_03;
			local_00->Free(local_01);
		}
		local_00->Release();
	}
	return;
}


void __fastcall TOptionForm::BbsPathReferButtonClick(TObject * Sender)
{
	IMalloc * local_00;
	ITEMIDLIST * local_01;
	BROWSEINFO local_02;
	char local_03[260];
	if (SHGetMalloc(&local_00)>=0) {
		local_02.hwndOwner=Handle;
		local_02.pidlRoot=NULLPO;
		local_02.pszDisplayName=NULLPO;
		local_02.lpszTitle="フォルダ選択";
		local_02.ulFlags=1;
		local_02.lpfn=NULLPO;
		local_02.lParam=0;
		local_02.iImage=0;
		local_01=SHBrowseForFolder(&local_02);
		if (local_01!=0) {
			SHGetPathFromIDList(local_01,local_03);
			BbsPathEdit->Text=local_03;
			local_00->Free(local_01);
		}
		local_00->Release();
	}
	return;
}


void __fastcall TOptionForm::DownPathReferButtonClick(TObject * Sender)
{
	IMalloc * local_00;
	ITEMIDLIST * local_01;
	BROWSEINFO local_02;
	char local_03[260];
	if (SHGetMalloc(&local_00)>=0) {
		local_02.hwndOwner=Handle;
		local_02.pidlRoot=NULLPO;
		local_02.pszDisplayName=NULLPO;
		local_02.lpszTitle="フォルダ選択";
		local_02.ulFlags=1;
		local_02.lpfn=NULLPO;
		local_02.lParam=0;
		local_02.iImage=0;
		local_01=SHBrowseForFolder(&local_02);
		if (local_01!=0) {
			SHGetPathFromIDList(local_01,local_03);
			DownPathEdit->Text=local_03;
			local_00->Free(local_01);
		}
		local_00->Release();
	}
	return;
}


void __fastcall TOptionForm::OkButtonClick(TObject * Sender)
{
	char local_03[256];

	g_pCMainControl->m_optflg_downRetryFast_=FastDownCheckBox->Checked;
	g_pTIniFile->WriteInteger("Option","DownRetryFast",!(!g_pCMainControl->m_optflg_downRetryFast_)?1:0);
	g_pCMainControl->m_optflg_autoDisconnect_=AutoDisconnectCheckBox->Checked;
	g_pTIniFile->WriteInteger("Option","AutoDisconnect",!(!g_pCMainControl->m_optflg_autoDisconnect_)?1:0);
	g_pCMainControl->m_optflg_useMultiDownload_=MultiDownCheckBox->Checked;
	g_pTIniFile->WriteInteger("Option","UseMultiDownload",!(!g_pCMainControl->m_optflg_useMultiDownload_)?1:0);
	g_pCMainControl->m_optflg_cutSlowTransfer_=SlowCutCheckBox->Checked;
	g_pTIniFile->WriteInteger("Option","CutSlowLine",!(!g_pCMainControl->m_optflg_cutSlowTransfer_)?1:0);
	g_pCMainControl->m_optflg_useTransferLimit_=TransLimitCheckBox->Checked;
	g_pTIniFile->WriteInteger("Option","UseTransferLimit",!(!g_pCMainControl->m_optflg_useTransferLimit_)?1:0);
	g_pCMainControl->m_optflg_autoTabChange_=AutoTabChangeCheckBox->Checked;
	g_pTIniFile->WriteInteger("Option","AutoTabChange",!(!g_pCMainControl->m_optflg_autoTabChange_)?1:0);
	g_pCMainControl->m_optflag_notConvert__=NotConvertCheck->Checked;
	g_pTIniFile->WriteInteger("Option","NotConvert",!(!g_pCMainControl->m_optflag_notConvert__)?1:0);
	g_pCMainControl->m_optflg_displayNewCache_=CacheVersionCheck->Checked;
	g_pTIniFile->WriteInteger("Option","DisplayNewCache",CacheVersionCheck->Checked?1:0);
	g_pCMainControl->m_optflg_V4CacheNotDown_=V4CacheNotDownCheck->Checked;
	g_pTIniFile->WriteInteger("Option","V4CacheNotDown",V4CacheNotDownCheck->Checked?1:0);
	g_pCMainControl->m_optflg_makeMarkFile_=MakeMarkCheck->Checked;
	g_pTIniFile->WriteInteger("Option","MakeMarkFile",MakeMarkCheck->Checked?1:0);
	int	local_01=callatol(VirtualKeyCombo->Text.c_str());
	if (! (!(local_01>50000)&&local_01>=5000) ) {
		MessageBox(Handle,"仮想キー個数は5千から5万の間に設定してください","Winny",0x00042030);
		VirtualKeyCombo->Text="15000";
		return;
	}
	g_pTIniFile->WriteString("Option","CacheFolderPath",CachePathEdit->Text.c_str());
	g_pTIniFile->WriteString("Option","DownFolderPath",DownPathEdit->Text.c_str());
	g_pTIniFile->WriteString("Option","BbsFolderPath",BbsPathEdit->Text.c_str());

	AnsiString local_00=(LineSpeedCombo->Text);
	int	local_02=local_00.Pos(" ");
	if (local_02>0) {
		local_00=local_00.SubString(0,local_02);
	}
	g_pTIniFile->WriteInteger("Option","LineTransferSpeed",callatol(local_00.c_str()));
	g_pTIniFile->WriteInteger("Option","AcceptPort",callatol(FilePortEdit->Text.c_str()));
	g_pTIniFile->WriteInteger("Option","BbsAcceptPort",callatol(BbsPortEdit->Text.c_str()));
	g_pTIniFile->WriteInteger("Option","NotConnected",Port0Check->Checked?1:0);
	g_pTIniFile->WriteString("Option","HostName",DdnsEdit->Text);
	g_pTIniFile->WriteInteger("Option","VirtualKeyMax",local_01);
	sprintf(local_03,"%X",WindowColorBox->Selected);
	g_pTIniFile->WriteString("Color","WindowBackGround",local_03);
	sprintf(local_03,"%X",BbsWindowColorBox->Selected);
	g_pTIniFile->WriteString("Color","BbsWindowBackGround",local_03);
	sprintf(local_03,"%X",ToolbarColorBox->Selected);
	g_pTIniFile->WriteString("Color","ToolBarBackGround",local_03);
	sprintf(local_03,"%X",ToolStringColorBox->Selected);
	g_pTIniFile->WriteString("Color","ToolBarString",local_03);
	sprintf(local_03,"%X",SearchBarColorBox->Selected);
	g_pTIniFile->WriteString("Color","SearchBarBackGround",local_03);
	sprintf(local_03,"%X",SearchStringColorBox->Selected);
	g_pTIniFile->WriteString("Color","SearchBarString",local_03);
	sprintf(local_03,"%X",BbsToolbarColorBox->Selected);
	g_pTIniFile->WriteString("Color","BbsToolBarBackGround",local_03);
	sprintf(local_03,"%X",BbsToolStringColorBox->Selected);
	g_pTIniFile->WriteString("Color","BbsToolBarString",local_03);
	sprintf(local_03,"%X",BbsSearchBarColorBox->Selected);
	g_pTIniFile->WriteString("Color","BbsSearchBarBackGround",local_03);
	sprintf(local_03,"%X",BbsSearchStringColorBox->Selected);
	g_pTIniFile->WriteString("Color","BbsSearchBarString",local_03);
	sprintf(local_03,"%X",SubStatusColorBox->Selected);
	g_pTIniFile->WriteString("Color","SubStatusString",local_03);
	g_pTIniFile->WriteInteger("Color","StringColor",ColorTrackBar->Position);
	g_pTIniFile->WriteInteger("Color","BbsStringColor",BbsColorTrackBar->Position);
	g_pTIniFile->WriteInteger("Bbs","TreeClickAction",TreeClickCombo->ItemIndex);
	g_pTIniFile->WriteInteger("Bbs","TreeDoubleClickAction",TreeDoubleClickCombo->ItemIndex);
	g_pTIniFile->WriteInteger("Bbs","ThreadClickAction",ThreadClickCombo->ItemIndex);
	g_pTIniFile->WriteInteger("Bbs","ThreadDoubleClickAction",ThreadDoubleClickCombo->ItemIndex);
	g_pTIniFile->WriteString("FileFont","Name",MainForm->SystemView->Font->Name);
	g_pTIniFile->WriteInteger("FileFont","Size",MainForm->SystemView->Font->Size);
	sprintf(local_03,"%X",MainForm->SystemView->Font->Color);
	g_pTIniFile->WriteString("FileFont","Color",local_03);
	g_pTIniFile->WriteString("BoardFont","Name",MainForm->BbsBoardView->Font->Name);
	g_pTIniFile->WriteInteger("BoardFont","Size",MainForm->BbsBoardView->Font->Size);
	sprintf(local_03,"%X",MainForm->BbsBoardView->Font->Color);
	g_pTIniFile->WriteString("BoardFont","Color",local_03);
	g_pTIniFile->WriteString("BbsFont","Name",MainForm->BbsView->Font->Name);
	g_pTIniFile->WriteInteger("BbsFont","Size",MainForm->BbsView->Font->Size);
	sprintf(local_03,"%X",MainForm->BbsView->Font->Color);
	g_pTIniFile->WriteString("BbsFont","Color",local_03);
	g_pTIniFile->WriteInteger("Option","SearchTabUse",SearchTabUseCheck->Checked?1:0);
	g_pTIniFile->WriteInteger("Option","UpperSearchTab",UpperSearchTabCheck->Checked?1:0);
	g_pTIniFile->WriteInteger("Option","AlwaysShowSearchTab",AlwaysShowSearchTabCheck->Checked?1:0);
	g_pTIniFile->WriteInteger("Option","InitialFileViewLeftPane",InitialFileViewLeftPaneCheck->Checked?1:0);
	g_pTIniFile->WriteInteger("Option","InitialFileViewTopPane",InitialFileViewTopPaneCheck->Checked?1:0);
	g_pTIniFile->WriteInteger("Option","InitialFileViewBottomPane",InitialFileViewBottomPaneCheck->Checked?1:0);
	g_pTIniFile->WriteInteger("Option","InitialBbsViewLeftPane",InitialBbsViewLeftPaneCheck->Checked?1:0);
	g_pTIniFile->WriteInteger("Option","InitialBbsViewTopPane",InitialBbsViewTopPaneCheck->Checked?1:0);
	g_pTIniFile->WriteInteger("Option","InitialBbsViewBottomPane",InitialBbsViewBottomPaneCheck->Checked?1:0);
	g_pTIniFile->WriteInteger("Option","FileTabMode",FileTabModeCombo->ItemIndex);
	g_pTIniFile->WriteInteger("Option","SearchTabMode",SearchTabModeCombo->ItemIndex);
	g_pTIniFile->WriteInteger("Option","BoardTabMode",BoardTabModeCombo->ItemIndex);
	g_pTIniFile->WriteInteger("Option","BbsTabMode",BbsTabModeCombo->ItemIndex);
	g_pTIniFile->WriteInteger("Option","FileFlatToolBar",FlatToolBarCheck->Checked?1:0);
	g_pTIniFile->WriteInteger("Option","BbsFlatToolBar",BbsFlatToolBarCheck->Checked?1:0);
	g_pTIniFile->WriteInteger("Option","FileTransparentToolBar",TransparentToolBarCheck->Checked?1:0);
	g_pTIniFile->WriteInteger("Option","BbsTransparentToolBar",BbsTransparentToolBarCheck->Checked?1:0);
	g_pTIniFile->WriteInteger("Option","AutoCopyDownInfoToTab",AutoCopyDownInfoCheck->Checked?1:0);
	Close();
	if (! (g_pCMainControl->m_optflg_UseBbsOnly_||!BbsOnlyCheckBox->Checked) ) {
		if (MessageBox(Handle,"BBS専用ノードにするとファイル共有側のリンクが切断されます。よろしいですか？","Winny",0x00042024)==6) {
			CGlobalLock CGLock;
			g_pCMainControl->mf_CMainControl_0330(true);
			g_pCMainControl->mf_CMainControl_0350();
			g_pCMainControl->mf_CMainControl_0700();
		} else {
			BbsOnlyCheckBox->Checked=false;
		}
	}
	g_pCMainControl->m_optflg_UseBbsOnly_=BbsOnlyCheckBox->Checked;
	g_pTIniFile->WriteInteger("Option","UseBbsOnly",!(!g_pCMainControl->m_optflg_UseBbsOnly_)?1:0);
	if (! (!m_flag||MessageBox(NULL,"設定を反映させるにはプログラムを再起動させる必要があります。Winnyを再起動しますか？","Winny",0x00042024)!=6) ) {
		g_bool_unk100=true;
		ControlForm->Close();
		ShellExecute(NULL,"open",Application->ExeName.c_str(),"","",5);
	}
	FormShow(NULLPO);
	MainForm->TabControlChange(MainForm->TabControl);
	MainForm->TabControlChange(MainForm->SubTabControl);
	return;
}


void __fastcall TOptionForm::WindowColorBoxChange(TObject * Sender)
{
	MainForm->NodeView->Color=WindowColorBox->Selected;
	MainForm->FolderView->Color=WindowColorBox->Selected;
	MainForm->FileView->Color=WindowColorBox->Selected;
	MainForm->DownView->Color=WindowColorBox->Selected;
	MainForm->IgnoreView->Color=WindowColorBox->Selected;
	MainForm->TaskView->Color=WindowColorBox->Selected;
	MainForm->LogView->Color=WindowColorBox->Selected;
	MainForm->SystemView->Color=WindowColorBox->Selected;
	MainForm->SubNodeView->Color=WindowColorBox->Selected;
	MainForm->SubFolderView->Color=WindowColorBox->Selected;
	MainForm->SubFileView->Color=WindowColorBox->Selected;
	MainForm->SubDownView->Color=WindowColorBox->Selected;
	MainForm->SubIgnoreView->Color=WindowColorBox->Selected;
	MainForm->SubTaskView->Color=WindowColorBox->Selected;
	MainForm->SubLogView->Color=WindowColorBox->Selected;
	MainForm->SubSystemView->Color=WindowColorBox->Selected;
	MainForm->NodeView->Font=MainForm->SystemView->Font;
	MainForm->FolderView->Font=MainForm->SystemView->Font;
	MainForm->FileView->Font=MainForm->SystemView->Font;
	MainForm->DownView->Font=MainForm->SystemView->Font;
	MainForm->IgnoreView->Font=MainForm->SystemView->Font;
	MainForm->TaskView->Font=MainForm->SystemView->Font;
	MainForm->LogView->Font=MainForm->SystemView->Font;
	MainForm->SubNodeView->Font=MainForm->SystemView->Font;
	MainForm->SubFolderView->Font=MainForm->SystemView->Font;
	MainForm->SubFileView->Font=MainForm->SystemView->Font;
	MainForm->SubDownView->Font=MainForm->SystemView->Font;
	MainForm->SubIgnoreView->Font=MainForm->SystemView->Font;
	MainForm->SubTaskView->Font=MainForm->SystemView->Font;
	MainForm->SubLogView->Font=MainForm->SystemView->Font;
	MainForm->SubSystemView->Font=MainForm->SystemView->Font;
	return;
}


void __fastcall TOptionForm::BbsWindowColorBoxChange(TObject * Sender)
{
	MainForm->BbsBoardView->Color=BbsWindowColorBox->Selected;
	MainForm->BbsView->Color=BbsWindowColorBox->Selected;
	MainForm->BbsTree->Color=BbsWindowColorBox->Selected;
	MainForm->BbsTree->Font->Color=MainForm->BbsBoardView->Font->Color;
	return;
}


void __fastcall TOptionForm::WhiteColorButtonClick(TObject * Sender)
{
	WindowColorBox->Selected=(TColor)0x00FFFFFF;
	ColorTrackBar->Position=3;
	MainForm->SystemView->Font->Color=(TColor)0x00000000;
	WindowColorBoxChange(NULLPO);
	return;
}


void __fastcall TOptionForm::BlackColorButtonClick(TObject * Sender)
{
	WindowColorBox->Selected=(TColor)0x00000000;
	ColorTrackBar->Position=1;
	MainForm->SystemView->Font->Color=(TColor)0x00FFFFFF;
	WindowColorBoxChange(NULLPO);
	return;
}


void __fastcall TOptionForm::BbsWhiteColorButtonClick(TObject * Sender)
{
	BbsWindowColorBox->Selected=(TColor)0x00FFFFFF;
	BbsColorTrackBar->Position=2;
	MainForm->BbsBoardView->Font->Color=(TColor)0x00000000;
	MainForm->BbsView->Font->Color=(TColor)0x00000000;
	BbsWindowColorBoxChange(NULLPO);
	MainForm->BbsTabControlChange(MainForm->BbsTabControl);
	return;
}


void __fastcall TOptionForm::BbsBlackColorButtonClick(TObject * Sender)
{
	BbsWindowColorBox->Selected=(TColor)0x00000000;
	BbsColorTrackBar->Position=1;
	MainForm->BbsBoardView->Font->Color=(TColor)0x00FFFFFF;
	MainForm->BbsView->Font->Color=(TColor)0x00FFFFFF;
	BbsWindowColorBoxChange(NULLPO);
	MainForm->BbsTabControlChange(MainForm->BbsTabControl);
	return;
}


void __fastcall TOptionForm::ToolbarColorBoxChange(TObject * Sender)
{
	MainForm->TopToolBar->Color=ToolbarColorBox->Selected;
	MainForm->BottomToolBar->Color=ToolbarColorBox->Selected;
	MainForm->BoardToolBar->Font->Color=BbsToolStringColorBox->Selected;
	MainForm->BoardToolBar->Color=BbsToolbarColorBox->Selected;
	MainForm->BbsToolBar->Color=BbsToolbarColorBox->Selected;
	MainForm->TopToolBar->Font->Color=ToolStringColorBox->Selected;
	MainForm->BottomToolBar->Font->Color=ToolStringColorBox->Selected;
	MainForm->BbsToolBar->Font->Color=BbsToolStringColorBox->Selected;
	MainForm->SearchPanel->Color=SearchBarColorBox->Selected;
	MainForm->BbsSearchPanel->Color=BbsSearchBarColorBox->Selected;
	MainForm->SearchLabel->Font->Color=SearchStringColorBox->Selected;
	MainForm->HitLabel->Font->Color=SearchStringColorBox->Selected;
	MainForm->TripLabel->Font->Color=SearchStringColorBox->Selected;
	MainForm->BbsSearchLabel->Font->Color=BbsSearchStringColorBox->Selected;
	MainForm->BbsHitLabel->Font->Color=BbsSearchStringColorBox->Selected;
	MainForm->StatusPanel->Font->Color=SubStatusColorBox->Selected;
	MainForm->SubStatusPanel->Font->Color=SubStatusColorBox->Selected;
	return;
}


void __fastcall TOptionForm::LineSpeedComboChange(TObject * Sender)
{
	m_flag=true;
	return;
}


void __fastcall TOptionForm::FilePortEditChange(TObject * Sender)
{
	m_flag=true;
	return;
}


void __fastcall TOptionForm::BbsPortEditChange(TObject * Sender)
{
	m_flag=true;
	return;
}


void __fastcall TOptionForm::Port0CheckClick(TObject * Sender)
{
	m_flag=true;
	return;
}


void __fastcall TOptionForm::DdnsEditChange(TObject * Sender)
{
	m_flag=true;
	return;
}


void __fastcall TOptionForm::CachePathEditChange(TObject * Sender)
{
	m_flag=true;
	return;
}


void __fastcall TOptionForm::BbsPathEditChange(TObject * Sender)
{
	m_flag=true;
	return;
}


void __fastcall TOptionForm::DownPathEditChange(TObject * Sender)
{
	m_flag=true;
	return;
}


void __fastcall TOptionForm::VirtualKeyComboChange(TObject * Sender)
{
	m_flag=true;
	return;
}


void __fastcall TOptionForm::InitButtonClick(TObject * Sender)
{
	NotConvertCheck->Checked=false;
	FastDownCheckBox->Checked=true;
	MultiDownCheckBox->Checked=true;
	SlowCutCheckBox->Checked=false;
	TransLimitCheckBox->Checked=false;
	AutoDisconnectCheckBox->Checked=false;
	V4CacheNotDownCheck->Checked=false;
	return;
}


void __fastcall TOptionForm::ColorTrackBarChange(TObject * Sender)
{
	MainForm->TabControlChange(MainForm->TabControl);
	MainForm->TabControlChange(MainForm->SubTabControl);
	return;
}


void __fastcall TOptionForm::BbsColorTrackBarChange(TObject * Sender)
{
	MainForm->BbsTabControlChange(MainForm->BbsTabControl);
	return;
}


void __fastcall TOptionForm::ListFontButtonClick(TObject * Sender)
{
	FontDialog->Font=MainForm->SystemView->Font;
	if (FontDialog->Execute()) {
		MainForm->SystemView->Font=FontDialog->Font;
		WindowColorBoxChange(NULLPO);
	}
	return;
}


void __fastcall TOptionForm::BoardFontButtonClick(TObject * Sender)
{
	FontDialog->Font=MainForm->BbsBoardView->Font;
	if (FontDialog->Execute()) {
		MainForm->BbsBoardView->Font=FontDialog->Font;
	}
	return;
}


void __fastcall TOptionForm::BbsFontButtonClick(TObject * Sender)
{
	FontDialog->Font=MainForm->BbsView->Font;
	if (FontDialog->Execute()) {
		MainForm->BbsView->Font=FontDialog->Font;
		MainForm->BbsView->SetFont(FontDialog->Font->Name,FontDialog->Font->Size);
		MainForm->BbsTabControlChange(MainForm->BbsTabControl);
	}
	return;
}


void __fastcall TOptionForm::UpperSearchTabCheckClick(TObject * Sender)
{
	MainForm->DisableAlign();
	if (UpperSearchTabCheck->Checked) {
		MainForm->SearchTabControl->Align=alTop;
		MainForm->SubSearchTabControl->Align=alTop;
		MainForm->SearchTabControl->TabPosition=tpTop;
		MainForm->SubSearchTabControl->TabPosition=tpTop;
	} else {
		MainForm->SearchTabControl->Align=alBottom;
		MainForm->SubSearchTabControl->Align=alBottom;
		if (MainForm->SearchTabControl->Style==0) {
			MainForm->SearchTabControl->TabPosition=tpBottom;
		}
		if (MainForm->SubSearchTabControl->Style==0) {
			MainForm->SubSearchTabControl->TabPosition=tpBottom;
		}
	}
	MainForm->EnableAlign();
	return;
}


void __fastcall TOptionForm::FileTabModeComboChange(TObject * Sender)
{
	switch (FileTabModeCombo->ItemIndex) {
	case 0:  
		MainForm->TabControl->Style=tsButtons;
		MainForm->SubTabControl->Style=tsButtons;
		break;
	case 1:  
		MainForm->TabControl->Style=tsFlatButtons;
		MainForm->SubTabControl->Style=tsFlatButtons;
		break;
	case 2:  
		MainForm->TabControl->Style=tsTabs;
		MainForm->SubTabControl->Style=tsTabs;
	}
	return;
}


void __fastcall TOptionForm::SearchTabModeComboChange(TObject * Sender)
{
	MainForm->DisableAlign();
	switch (SearchTabModeCombo->ItemIndex) {
	case 0:  
		MainForm->SearchTabControl->TabPosition=tpTop;
		MainForm->SubSearchTabControl->TabPosition=tpTop;
		MainForm->SearchTabControl->Style=tsButtons;
		MainForm->SubSearchTabControl->Style=tsButtons;
		break;
	case 1:  
		MainForm->SearchTabControl->TabPosition=tpTop;
		MainForm->SubSearchTabControl->TabPosition=tpTop;
		MainForm->SearchTabControl->Style=tsFlatButtons;
		MainForm->SubSearchTabControl->Style=tsFlatButtons;
		break;
	case 2:  
		MainForm->SearchTabControl->Style=tsTabs;
		MainForm->SubSearchTabControl->Style=tsTabs;
		if (!UpperSearchTabCheck->Checked) {
			MainForm->SearchTabControl->TabPosition=tpBottom;
			MainForm->SubSearchTabControl->TabPosition=tpBottom;
			break;
		}
		MainForm->SearchTabControl->TabPosition=tpTop;
		MainForm->SubSearchTabControl->TabPosition=tpTop;
	}
	MainForm->EnableAlign();
	return;
}


void __fastcall TOptionForm::BoardTabModeComboChange(TObject * Sender)
{
	switch (BoardTabModeCombo->ItemIndex) {
	case 0:  
		MainForm->BoardTabControl->Style=tsButtons;
		break;
	case 1:  
		MainForm->BoardTabControl->Style=tsFlatButtons;
		break;
	case 2:  
		MainForm->BoardTabControl->Style=tsTabs;
	}
	return;
}


void __fastcall TOptionForm::BbsTabModeComboChange(TObject * Sender)
{
	switch (BbsTabModeCombo->ItemIndex) {
	case 0:  
		MainForm->BbsTabControl->Style=tsButtons;
		break;
	case 1:  
		MainForm->BbsTabControl->Style=tsFlatButtons;
		break;
	case 2:  
		MainForm->BbsTabControl->Style=tsTabs;
	}
	return;
}


void __fastcall TOptionForm::FlatToolBarCheckClick(TObject * Sender)
{
	TransparentToolBarCheck->Enabled=FlatToolBarCheck->Checked;
	BbsTransparentToolBarCheck->Enabled=BbsFlatToolBarCheck->Checked;
	MainForm->TopToolButton1->Flat=FlatToolBarCheck->Checked;
	MainForm->TopToolButton2->Flat=FlatToolBarCheck->Checked;
	MainForm->TopToolButton3->Flat=FlatToolBarCheck->Checked;
	MainForm->TopToolButton4->Flat=FlatToolBarCheck->Checked;
	MainForm->TopToolButton5->Flat=FlatToolBarCheck->Checked;
	MainForm->TopToolButton6->Flat=FlatToolBarCheck->Checked;
	MainForm->SetupButton->Flat=FlatToolBarCheck->Checked;
	MainForm->BottomToolButton1->Flat=FlatToolBarCheck->Checked;
	MainForm->BottomToolButton2->Flat=FlatToolBarCheck->Checked;
	MainForm->BottomToolButton3->Flat=FlatToolBarCheck->Checked;
	MainForm->BottomToolButton4->Flat=FlatToolBarCheck->Checked;
	MainForm->BottomToolButton5->Flat=FlatToolBarCheck->Checked;
	MainForm->BottomToolButton6->Flat=FlatToolBarCheck->Checked;
	MainForm->SubSetupButton->Flat=FlatToolBarCheck->Checked;
	MainForm->BbsSetupButton->Flat=BbsFlatToolBarCheck->Checked;
	MainForm->MakeBbsButton->Flat=BbsFlatToolBarCheck->Checked;
	MainForm->RefreshBoardButton->Flat=BbsFlatToolBarCheck->Checked;
	MainForm->CacheClearButton2->Flat=BbsFlatToolBarCheck->Checked;
	MainForm->BbsViewCache->Flat=BbsFlatToolBarCheck->Checked;
	MainForm->BbsBrowserButton->Flat=BbsFlatToolBarCheck->Checked;
	MainForm->BbsPortScanButton2->Flat=BbsFlatToolBarCheck->Checked;
	MainForm->TopToolButton1->Transparent=TransparentToolBarCheck->Checked;
	MainForm->TopToolButton2->Transparent=TransparentToolBarCheck->Checked;
	MainForm->TopToolButton3->Transparent=TransparentToolBarCheck->Checked;
	MainForm->TopToolButton4->Transparent=TransparentToolBarCheck->Checked;
	MainForm->TopToolButton5->Transparent=TransparentToolBarCheck->Checked;
	MainForm->TopToolButton6->Transparent=TransparentToolBarCheck->Checked;
	MainForm->SetupButton->Transparent=TransparentToolBarCheck->Checked;
	MainForm->BottomToolButton1->Transparent=TransparentToolBarCheck->Checked;
	MainForm->BottomToolButton2->Transparent=TransparentToolBarCheck->Checked;
	MainForm->BottomToolButton3->Transparent=TransparentToolBarCheck->Checked;
	MainForm->BottomToolButton4->Transparent=TransparentToolBarCheck->Checked;
	MainForm->BottomToolButton5->Transparent=TransparentToolBarCheck->Checked;
	MainForm->BottomToolButton6->Transparent=TransparentToolBarCheck->Checked;
	MainForm->SubSetupButton->Transparent=TransparentToolBarCheck->Checked;
	MainForm->BbsSetupButton->Transparent=BbsTransparentToolBarCheck->Checked;
	MainForm->MakeBbsButton->Transparent=BbsTransparentToolBarCheck->Checked;
	MainForm->RefreshBoardButton->Transparent=BbsTransparentToolBarCheck->Checked;
	MainForm->BbsViewCache->Transparent=BbsTransparentToolBarCheck->Checked;
	MainForm->BbsBrowserButton->Transparent=BbsTransparentToolBarCheck->Checked;
	MainForm->BbsPortScanButton2->Transparent=BbsTransparentToolBarCheck->Checked;
	MainForm->CacheClearButton2->Transparent=BbsTransparentToolBarCheck->Checked;
	return;
}



//---------------------------------------------------------------------------
