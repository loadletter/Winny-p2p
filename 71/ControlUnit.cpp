//---------------------------------------------------------------------------
#include "hdrs.h"

#include <vcl.h>
#pragma hdrstop

#include <Forms.hpp>
#include <IniFiles.hpp>

#include "def.h"
#include "ControlUnit.h"
#include "util.h"
#include "md5.h"
#include "globals.h"

#include "MainUnit.h"
#include "AboutUnit.h"

#include "CMainControl.h"
extern CMainControl *g_pCMainControl;


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TControlForm *ControlForm;

bool                           gi_flag_unk300=false         ;				//fr 0053D930 00000001

//---------------------------------------------------------------------------

__fastcall TControlForm::TControlForm(TComponent* Owner)
        : TForm(Owner)
{
	g_pTIniFile=new TIniFile(ChangeFileExt(Application->ExeName,".ini"));
	g_AppPath=Application->ExeName;
	g_AppPath[g_AppPath.LastDelimiter("\\")+1]=0;
	g_pCMainControl=new CMainControl();
	g_pCMainControl->mf_CMainControl_0190();
	int tmp;
}


__fastcall TControlForm::~TControlForm()
{
	CGlobalLock CGLock;
	MainTimer->Enabled=false;
	g_bool_unk100=true;
	if (g_pCMainControl!=0) {
		delete g_pCMainControl;
	}
	g_pCMainControl=NULLPO;
	mf_TControlForm_0010();
	if (g_pTIniFile!=0) {
		delete g_pTIniFile;
	}
	g_pTIniFile=NULLPO;
}


void __fastcall TControlForm::WndProc(TMessage & Message)
{
	TCustomForm::WndProc(Message);
	if (g_pCMainControl==0) {
		return;
	}
	if (Message.Msg==11024) {
		if (! (Message.LParam!=517||Message.WParam!=511) ) {
			TPoint local_00;
			SetForegroundWindow(Handle);
			GetCursorPos(&local_00);
			SystemMenu->PopupComponent=this;
			SystemMenu->Popup(local_00.x,local_00.y);
		}
		if (! (Message.LParam!=514||Message.WParam!=511) ) {
			RestoreClick(NULLPO);
		}
	} else {
		CGlobalLock CGLock;
		g_pCMainControl->mf_CMainControl_0230(Message.Msg,Message.WParam,Message.LParam);
	}
	return;
}


void __fastcall TControlForm::FormClick(TObject * Sender)
{
	MainForm->Show();
	return;
}


//ライブラリのを使うと大きい模様
typedef struct {
        DWORD cbSize;
        HWND hWnd;
        UINT uID;
        UINT uFlags;
        UINT uCallbackMessage;
        HICON hIcon;
        CHAR   szTip[64];
} __NOTIFYICONDATA;


void TControlForm::mf_TControlForm_0000()
{
	if (g_pCMainControl==0) {
		return;
	}
	__NOTIFYICONDATA local_00;
	CGlobalLock CGLock;
	local_00.cbSize=88;
	local_00.hWnd=Handle;
	local_00.uID=511;
	local_00.uFlags=7;
	local_00.uCallbackMessage=11024;
	local_00.hIcon=Application->Icon->Handle;
	if (! (!(g_pCMainControl->m_optflg_showVersionWarning_||g_pCMainControl->m_flag_downFolderDiskFull_||g_pCMainControl->m_flag_cacheFolderDiskFull_)&&g_pCMainControl->m_int_portWarnedCount_<20) ) {
		local_00.hIcon=Application->Icon->Handle;
	} else {
		local_00.hIcon=Application->Icon->Handle;
	}
	sprintf(local_00.szTip,"%s \n    up: %d / %dk \ndown: %d / %dk",g_szstr_Version,g_pCMainControl->m_int_CurrentTransferUpConnectionCount_,(int)g_pCMainControl->m_double_upKBytePerSec_,g_pCMainControl->m_int_CurrentTransferDownConnectionCount_,(int)g_pCMainControl->m_double_downKBytePerSec_);
	bool tmp=( Shell_NotifyIcon(1,(NOTIFYICONDATA*)&local_00)!=0 ? true:false );
	if (!tmp && !Shell_NotifyIcon(0,(NOTIFYICONDATA*)&local_00) ) {
		RestoreClick(NULLPO);
	}
	return;
}


void TControlForm::mf_TControlForm_0010()
{
	__NOTIFYICONDATA local_00;
	local_00.cbSize=88;
	local_00.hWnd=Handle;
	local_00.uID=511;
	Shell_NotifyIcon(2,(NOTIFYICONDATA*)&local_00);
	return;
}


void __fastcall TControlForm::IconCheckTimerTimer(TObject * Sender)
{
	IconCheckTimer->Enabled=false;
	if (! (MainForm==0||MainForm->Visible) ) {
		mf_TControlForm_0000();
	}
	IconCheckTimer->Enabled=true;
	return;
}


void __fastcall TControlForm::FormClose(TObject * Sender,TCloseAction & Action)
{
	char local_00[1024];
	if (!gi_flag_unk300) {
		gi_flag_unk300=true;
	} else {
		return;
	}
	if (! (!gi_flag_unk300||g_bool_unk100||MessageBox(NULL,"Winnyを終了しますか？","Winny",0x00042024)!=7) ) {
		Action=(TCloseAction)0;
		gi_flag_unk300=false;
		return;
	}
	gi_flag_unk300=false;
	if (!g_bool_unk100) {
		MainForm->AllBbsTabCloseClick(NULLPO);
	}
	g_pTIniFile->WriteInteger("Frame","Maxmize",!(MainForm->WindowState!=(TWindowState)2)?1:0);
	g_pTIniFile->WriteInteger("Frame","Minimize",!MainForm->Visible?1:0);
	if (g_pCMainControl!=0) {
		CGlobalLock CGLock;
		g_pCMainControl->mf_CMainControl_0620();
		if (g_pCMainControl->m_optflag_Connect__) {
			sprintf(local_00,"%s%s",/*(const char *)*/g_AppPath,"Noderef.txt");
			g_pCMainControl->mf_CMainControl_1220(local_00,false,true);
			sprintf(local_00,"%s%s",/*(const char *)*/g_AppPath,"BbsNoderef.txt");
			g_pCMainControl->mf_CMainControl_1220(local_00,true,true);
		}
	}
	return;
}


void __fastcall TControlForm::ExitClick(TObject * Sender)
{
	Close();
	return;
}


void __fastcall TControlForm::RestoreClick(TObject * Sender)
{
	if (MainForm!=0) {
		mf_TControlForm_0010();
		MainForm->Show();
		MainForm->mf_TMainForm_0080();
	}
	return;
}


void __fastcall TControlForm::VersionInfoClick(TObject * Sender)
{
	char local_00[260];
	if (AboutForm==0) {
		AboutForm=new TAboutForm(this);
	}
	sprintf(local_00,"%s ( %s )",g_szstr_Version,"03/11/16");
	AboutForm->VersionText->Caption=local_00;
	AboutForm->Show();
	return;
}


void __fastcall TControlForm::AppIdle(TObject *Sender,bool &Done)
{
	if (g_pCMainControl!=0) {
		g_pCMainControl->mf_CMainControl_0210();
	}
	Sleep(1);
	return;
}



void __fastcall TControlForm::FormCreate(TObject * Sender)
{
#ifndef _DEBUG
	Application->OnException=AppException;
#endif
	Application->OnIdle=AppIdle;
	return;
}


void __fastcall TControlForm::MainTimerTimer(TObject * Sender)
{
	MainTimer->Enabled=false;
	if (g_pCMainControl!=0) {
		g_pCMainControl->mf_CMainControl_0210();
	}
	MainTimer->Enabled=true;
	return;
}



void __fastcall TControlForm::AppException(TObject * Sender,Exception *E)
{
	MainTimer->Enabled=false;
	g_bool_unk100=true;
	Application->ShowException(E);
	Close();
	return;
}



//---------------------------------------------------------------------------


