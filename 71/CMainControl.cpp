//---------------------------------------------------------------------------
#include "hdrs.h"

#include <vcl.h>
#pragma hdrstop

#include "def.h"


#include <IniFiles.hpp>

#include "CMainControl.h"

#include "ControlUnit.h"
#include "MainUnit.h"
#include "BbsMakeUnit.h"
#include "OptionUnit.h"

#include "RSA.h"

#include "def2.h"

#include "globals.h"



int                            g_int_unk500=0x47470104           ;				//fr 0053F414 00000004 
int                            g_int_unk501=0x47470105           ;				//fr 0053F418 00000004 
int                            g_int_unk502=0x47470106           ;				//fr 0053F41C 00000004 
int                            g_int_unk503=0           ;				//fr 0053F420 00000004 
int                            g_int_unk504=0           ;				//fr 0053F424 00000004 
int                            g_int_unk505=0           ;				//fr 0053F428 00000004 
int                            g_int_unk506=0           ;				//fr 0053F42C 00000004 
float                          g_float_unk101=1.0         ;				//fr 0053F430 00000004 
float                          g_float_unk102=1.0         ;				//fr 0053F434 00000004 
bool                           g_bool_unk100=false          ;				//fr 0053F438 00000001 

int padding0000=0;	//??

CMainControl *                 g_pCMainControl=NULLPO        ;				//fr 0053F440 00000004
HMODULE                        g_hmodule_unk=NULL          ;				//fr 0053F444 00000004 

/*
typedef BOOL (*t_pfn_ReadProcessMemory)(
  HANDLE hProcess,  // handle to the process whose memory is read
  LPCVOID lpBaseAddress,
                    // address to start reading
  LPVOID lpBuffer,  // address of buffer to place read data
  DWORD nSize,      // number of bytes to read
  LPDWORD lpNumberOfBytesRead
                    // address of number of bytes read
);

typedef EXECUTION_STATE (*t_pfn_SetThreadExecutionState)(
  EXECUTION_STATE esFlags  // execution requirements
);*/



t_pfn_SetThreadExecutionState  g_pproc_SetThreadExecutionState=NULL   ;				//fr 0053F448 00000004
HANDLE                         g_handle_uxthemeDll=NULL    ;				//fr 0053F44C 00000004
PPROC                          g_pproc_EnableThemeNantoka=NULL   ;				//fr 0053F450 00000004
t_pfn_ReadProcessMemory        g_pproc_ReadProcessMemory=NULL   ;				//fr 0053F454 00000004

int padding0001=1;	//??

int                            g_int_unk400=0           ;				//fr 0053F45C 00000004 
int                            g_int_unk401=0           ;				//fr 0053F460 00000004 
int                            g_int_unk402=0           ;				//fr 0053F464 00000004 
int                            g_int_unk403=0           ;				//fr 0053F468 00000004 
int                            g_int_unk404=0           ;				//fr 0053F46C 00000004 
int                            g_int_unk405=0           ;				//fr 0053F470 00000004
int                            g_int_unk406=0           ;				//fr 0053F474 00000004 
int                            g_int_unk407=0           ;				//fr 0053F478 00000004 
int                            g_int_unk408=0           ;				//fr 0053F47C 00000004 
int                            g_int_unk409=0           ;				//fr 0053F480 00000004
int                            g_int_unk410=0           ;				//fr 0053F484 00000004
int                            g_int_unk411=0           ;				//fr 0053F488 00000004
int                            g_int_unk412=0           ;				//fr 0053F48C 00000004
int                            g_int_unk413=0           ;				//fr 0053F490 00000004
int                            g_int_unk414=1           ;				//fr 0053F494 00000004
int                            g_int_unk415=10           ;				//fr 0053F498 00000004
int                            g_int_unk415a_70=11           ;				//fr 0053F498 00000004
int                            g_int_unk416=0           ;				//fr 0053F49C 00000004
int                            g_int_unk417=0           ;				//fr 0053F4A0 00000004


int                            CGlobalLock::g_globallock=0           ;				//fr 00544958 00000004


CMainControl::CMainControl() : m_DownCondition_(),m_IgnoreCondition_()
{
	int local_03;
	_in_addr local_04;
	char local_05[256];

	CGlobalLock::g_globallock=0;
	m_hwnd_unk32=ControlForm->Handle;
	g_hmodule_unk=LoadLibrary("Kernel32.dll");

	if (g_hmodule_unk!=0) {
		g_pproc_SetThreadExecutionState=(t_pfn_SetThreadExecutionState)GetProcAddress(g_hmodule_unk,"SetThreadExecutionState");
		ny_decryptstring("%S.%f.%b.%e.%Q.%s.%p.%d.%f.%t.%t.%N.%f.%n.%p.%s.%z.",local_05);
		g_pproc_ReadProcessMemory=(t_pfn_ReadProcessMemory)GetProcAddress(g_hmodule_unk,local_05);
	}
	g_handle_uxthemeDll=LoadLibrary("uxtheme.dll");
	if (g_handle_uxthemeDll!=0) {
		g_pproc_EnableThemeNantoka=GetProcAddress(g_handle_uxthemeDll,"EnableThemeDialogTexture");
	}
	srand(GetTickCount());

	for (local_03=0; local_03<600; local_03++) {
		m_hostArray[local_03].mf_CHost_0000();
		m_hostArray[local_03].m_flgIsValid=false;
	}
	*m_szstr_errormsg_=0;
	m_flg_unk203=false;
	m_int_unk15=0;
	m_uint_unk14=0;
	m_int_CurrentSearchUpConnectionCount_=0;
	m_int_CurrentSearchDownConnectionCount_=0;
	m_int_CurrentTransferUpConnectionCount_=0;
	m_int_CurrentTransferDownConnectionCount_=0;
	m_int_CurrentTransferUpToPortzeroConnectionCount_=0;
	m_int_CurrentBBSTransferUpConnectionCount_=0;
	m_int_CurrentBBSTransferDownConnectionCount_=0;
	m_int_CurrentBBSUpConnectionCount_=0;
	m_int_CurrentBBSDownConnectionCount_=0;
	m_int_CurrentTransferProxyConnectionCount_=0;
	m_flg_unk200=false;
	m_flg_unk201=false;
	m_socket_accepting__=0;//INVALID_SOCKET;
	m_socket_unk33=0;//INVALID_SOCKET;
	m_int_portWarnedCount_=0;
	mf_CMainControl_0000();
	m_flg_unk202=false;
	m_flg_unk15511=false;
	m_flg_unk15469=false;
	m_flg_unk15470=false;
	m_flg_unk16400=false;
	m_int_downTrial_TimeInSec_=0;
	m_int_downTrial_NumberOfTry_=0;
	m_int_downTrial_NumberOfSuccessTry_=0;
	m_int_downTrial_NumberOfKeylostDisconnect_=0;
	m_int_downTrial_NumberOfTimeout_=0;
	m_int_downTrial_LimitTryCount_=0;
	m_double_totalFileSize_=0.0;
	m_double_totalReferenceSize_=0.0;
	m_double_unk12=1.0;
	m_double_unk13=1.0;
	m_int_unk31=1;
	m_double_14424=0.0;
	m_int_virtualKeyMax_=10000;
	m_int_unk41=0;
	local_04.b1=127;
	local_04.b2=0;
	local_04.b3=0;
	local_04.b4=1;
	mf_CMainControl_0560(&local_04,0);
	m_int_unk42=0;
	ny_addlog(" ログ取得開始");
	m_flgarray_unk[7]=true;
	m_flag_cacheFolderDiskFull_=false;
	m_flag_downFolderDiskFull_=false;
	m_int_linespeed_=40;
	m_double_currentCacheSize_=0.0;
	m_int_numberOfUpFile_=0;
	m_int_numberOfBbsUpFile_=0;
	m_int_numberOfCacheFile_=0;
	m_int_numberOfCompleteCacheFile_=0;
	m_optflag_notConnected__=false;
	m_optflag_Connect__=true;
	m_int_14416=0;
	m_int_14420=0;
	m_double_upKBytePerSec_=0.0;
	m_double_downKBytePerSec_=0.0;
	m_int_unk15=0;
	for (local_03=0; local_03<60; local_03++) {
		m_arraydouble_unk10[local_03]=0.0;
		m_arraydouble_unk11[local_03]=0.0;
	}
	m_int_unk15=0;
	m_int_unk20=0;
	m_int_related_maxconnection__=2;
	m_int_currentTransferUpConnectionMax_=2;
	m_int_unk16=-1;
	m_flg_unk15462=true;
	*m_char512_unk1_=0;
	m_flag_exeSignatureIsOkay_=false;
	m_int_unk18=0;
	m_int_unk19=0;
	m_int_unk21=0;
	m_int_unk43=0;
	m_int_unk17=0;
	m_int_cacheOpenErrorCount_=0;
	m_flg_unk16402=false;
	m_flg_unk15510=false;
	m_optflg_showVersionWarning_=false;
	m_flg_IsJoiningBBSCluster_=false;
	m_flg_IsBBSSearchLinkOn_=true;
	m_optflg_UseBbsOnly_=false;
	m_int_unk30=0;
	m_flg_notused_=false;
	m_flg_unk16408=false;
}


CMainControl::~CMainControl()
{
	int local_00;
	mf_CMainControl_0320();
	local_00=m_vectorpCWork_.size();
	for (int local_01=0; local_01<local_00; local_01++) {
		m_vectorpCWork_[local_01]->mf_CWork_0010(false,false);
		delete m_vectorpCWork_[local_01];
	}
	WSACleanup();
	if (g_hmodule_unk!=0) {
		FreeLibrary(g_hmodule_unk);
	}
	if (g_handle_uxthemeDll!=0) {
		FreeLibrary(g_handle_uxthemeDll);
	}
}


void CMainControl::mf_CMainControl_1550()
{
	int local_00;
	m_int_numberOfBbsUpFile_=0;
	m_vectorCFolder_.begin()->m_int_unk2=0;
	m_vectorCFolder_.begin()->m_int_unk1=0;
	local_00=mf_CMainControl_0610();
	if (local_00>=0) {
		m_vectorpCWork_[local_00]->mf_CWork_0140(m_vectorCFolder_.begin()->m__unknown_001.c_str(),m_vectorCFolder_.begin()->m__unknown_002.c_str(),0);
	}
	return;
}


void CMainControl::mf_CMainControl_0010(const AnsiString & arg_0,const AnsiString & arg_1,const AnsiString & arg_2,int arg_3)
{
	long local_01;
	char local_02[4096];
	struct__finddata_t local_03;

	mf_CMainControl_0020(arg_0,arg_1,arg_2);
	sprintf(local_02,"%s\\*.*",arg_1);

	if ((local_01=_findfirst(local_02,&local_03))>=0) {
		AnsiString local_00;   //使っていない模様
		if (! ((*((char *)(&local_03.attrib))&16)==0||(*((char *)(&local_03.attrib))&2)!=0||strcmp(local_03.name,".")==0||strcmp(local_03.name,"..")==0) ) {
			this->mf_CMainControl_0010(((arg_0+"_")+local_03.name),((arg_1+"\\")+local_03.name),arg_2,arg_3+1);
		}
		while (_findnext(local_01,&local_03)==0) {
			if (! ((*((char *)(&local_03.attrib))&16)==0||(*((char *)(&local_03.attrib))&2)!=0||strcmp(local_03.name,".")==0||strcmp(local_03.name,"..")==0) ) {
				this->mf_CMainControl_0010(((arg_0+"_")+local_03.name),((arg_1+"\\")+local_03.name),arg_2,arg_3+1);
			}
		}
		_findclose(local_01);
	}
	return;
}


void CMainControl::mf_CMainControl_0020(const AnsiString & arg_0,const AnsiString & arg_1,const AnsiString & arg_2)
{
	unsigned int local_01;
	for (local_01=0; m_vectorCFolder_.size()>local_01; local_01++) {
		if (!GetFolder(local_01)->Get_flg_unk3()) continue;
		if (strcmp(m_vectorCFolder_[local_01].Get_001_cstr(),arg_1.c_str())==0) {
			return;
		}
		if (strcmp(m_sz_CacheFolderPath_,arg_1.c_str())==0) {
			return;
		}
		if (strcmp(m_sz_DownFolderPath_,arg_1.c_str())==0) {
        		return;
                }
	}
	try {
		CFolder local_00;
		local_00.mf_CFolder_0000();
		local_00.mf_CFolder_0020(arg_0);
		local_00.mf_CFolder_0030(arg_1);
		local_00.mf_CFolder_0010(arg_2);
		m_vectorCFolder_.push_back(local_00);
	}
	catch (std::bad_alloc ex_8) {
	}
	return;
}


//バグか？ansistringのcstrとmemberのchar*を比べてるぞ
void CMainControl::mf_CMainControl_0030()
{
	unsigned int local_00;
	for (local_00=1; m_vectorCFolder_.size()>local_00; local_00++) {
		if (m_vectorCFolder_[local_00].Get_001_cstr()==m_sz_DownFolderPath_) {
			unsigned int tmp1=local_00;
			m_vectorCFolder_.begin()[tmp1].m_flg_unk3=false;
		}
		if (m_vectorCFolder_[local_00].Get_001_cstr()==m_sz_CacheFolderPath_) {
			unsigned int tmp2=local_00;
			m_vectorCFolder_.begin()[tmp2].m_flg_unk3=false;
		}
		if (m_vectorCFolder_[local_00].Get_001_cstr()==m_sz_BbsFolderPath_) {
			unsigned int tmp3=local_00;
			m_vectorCFolder_.begin()[tmp3].m_flg_unk3=false;
		}
	}
	return;
}



void CMainControl::mf_CMainControl_0040(const char * arg_0)
{
	char local_08[1024];
	try {
		m_vectorCFolder_.resize(1);
		m_vectorCFolder_.begin()->mf_CFolder_0000();
		m_vectorCFolder_.begin()->mf_CFolder_0020("BBS");
		m_vectorCFolder_.begin()->mf_CFolder_0030(m_sz_BbsFolderPath_);
		m_vectorCFolder_.begin()->mf_CFolder_0010("");
		FILE * local_02=fopen(arg_0,"r");
		if (local_02==0) {
			sprintf(local_08,"アップフォルダファイル読み込み失敗(%s)",arg_0);
			ny_addlog(local_08);
			m_flgarray_unk[7]=true;
			return;
		}
		int		local_03=1;
		while (true) {
			if (feof(local_02)||fgets(local_08,1024,local_02)==0) break;
			if (strlen(local_08)<3) continue;
			int			local_04=strlen(local_08)-1;
			if ((int)*(local_08+local_04)==10) {
				*(local_08+local_04)=0;
			}
			local_04=strlen(local_08);
			if ((int)*(local_08+local_04)==13) {
				*(local_08+local_04)=0;
			}
			if ((int)local_08[0]==91) {
				char * local_05=local_08+1;
				char * local_06=local_05;
				for ( ; !(*local_05==0)&&(int)*local_05!=93; local_05++) {
				}
				if (*local_05==0) continue;
				*local_05=0;
				local_03=local_03+1;
				CFolder local_01;
				local_01.mf_CFolder_0000();
				local_01.mf_CFolder_0020(local_06);
				m_vectorCFolder_.push_back(local_01);
				continue;
			}
						char *local_07;
			for (local_07=local_08; !(*local_07==0)&&(int)*local_07!=61; local_07++) {
			}
			if (*local_07==0) continue;
			for (local_07=local_07+1; !(*local_07==0)&&((int)*local_07==32||(int)*local_07==9); local_07++) {
			}
			if (*local_07==0||(int)*local_07==10||local_03==0) continue;
			if (strnicmp(local_08,"name",4)==0) {
				m_vectorCFolder_[local_03-1].mf_CFolder_0020(local_07);
			}
			if (strnicmp(local_08,"path",4)==0) {
				m_vectorCFolder_[local_03-1].mf_CFolder_0030(local_07);
			}
			if (strnicmp(local_08,"trip",4)!=0) continue;
			m_vectorCFolder_[local_03-1].mf_CFolder_0010(local_07);
		}
		fclose(local_02);
		m_flgarray_unk[2]=true;
		mf_CMainControl_0030();
	}
	catch (std::bad_alloc ex_8) {
	}
	return;
}


void CMainControl::mf_CMainControl_0050(const char * arg_0)
{
	char local_03[1024];
	FILE *	local_00=fopen(arg_0,"w");
	if (local_00==0) {
		sprintf(local_03,"アップフォルダファイル書き込み失敗(%s)",arg_0);
		ny_addlog(local_03);
		m_flgarray_unk[7]=true;
		return;
	}
	int	local_01=m_vectorCFolder_.size();
	int local_02;
	for (local_02=1; local_02<local_01; local_02++) {
		if (!GetFolder(local_02)->Get_flg_unk3()) continue;
		sprintf(local_03,"[%s]\n",m_vectorCFolder_[local_02].Get_000_cstr());
		fputs(local_03,local_00);
		sprintf(local_03,"Path=%s\n",m_vectorCFolder_[local_02].Get_001_cstr());
		fputs(local_03,local_00);
		sprintf(local_03,"Trip=%s\n\n",m_vectorCFolder_[local_02].Get_003_cstr());
		fputs(local_03,local_00);
	}
	fclose(local_00);
	return;
}


void CMainControl::mf_CMainControl_0170(int arg_0)
{
	try {
		int local_00;
		for (local_00=0; local_00<600; local_00++) {
			if (local_00==arg_0||!m_hostArray[local_00].m_flgIsValid) continue;
			int local_01=m_hostArray[local_00].mf_CHost_0220(m_hostArray+arg_0);
			int tmp=local_01;
			m_hostArray[local_00].m_int_preference1=tmp;
			if (arg_0==0) {
				local_01=local_01+m_hostArray[local_00].m_int_preference2_positive;
			}
			int tmp2=local_01;
			m_hostArray[local_00].m_int_unk10=tmp2;
			if (m_hostArray[local_00].m_int_unk10>100) {
				m_hostArray[local_00].m_int_unk10=100;
			}
			if (m_hostArray[local_00].m_int_preference2_positive>100) {
				m_hostArray[local_00].m_int_preference2_positive=100;
			}
			if (m_hostArray[local_00].m_int_preference2_positive<0) {
				m_hostArray[local_00].m_int_preference2_positive=0;
			}
		}
		int		local_02=0;
		for (local_00=1; local_00<600; local_00++) {
			if (!m_hostArray[local_00].m_flgIsValid) continue;
			local_02=local_02+1;
		}
		m_vectorCHostSorter_.resize(local_02);
		local_02=0;
		for (local_00=1; local_00<600; local_00++) {
			if (!m_hostArray[local_00].m_flgIsValid) continue;
			m_vectorCHostSorter_[local_02].m_int_unk00=local_00;
			m_vectorCHostSorter_[local_02].m_CHost_unk2=m_hostArray+local_00;
			if (m_hostArray[local_00].m_flgIsTransferLink_8) {
				m_vectorCHostSorter_[local_02].m_float_unk1=-10000.0;
			} else {
				m_vectorCHostSorter_[local_02].m_float_unk1=(float)m_hostArray[local_00].m_int_unk10;
				if (arg_0==0) {
					m_vectorCHostSorter_[local_02].m_float_unk1-=(m_hostArray[local_00].m_int_preference2_negative<<3);
				}
			}
			m_vectorCHostSorter_[local_02].m_int_unk3=7;
			m_vectorCHostSorter_[local_02].m_bool_unk4=false;
			local_02=local_02+1;
		}
		sort(m_vectorCHostSorter_.begin(),m_vectorCHostSorter_.end());
	}
	catch (std::bad_alloc ex_8) {
	}
	return;
}


CKey * CMainControl::mf_CMainControl_0180(unsigned int n,unsigned char * hash)
{
	unsigned int local_00;
	local_00=*((unsigned int *)hash);

	int tmp=m_KeyBuffer_.count(local_00);
	if (tmp==0) {
		return NULLPO;
	}
	multimap<unsigned int,CKey>::iterator local_01;
	for (local_01=m_KeyBuffer_.find(local_00); local_01!=m_KeyBuffer_.end(); local_01++) {
		CKey *		local_02=&local_01->second;
		if (memcmp((unsigned char *)local_02->m_hash_tabun,hash,16)==0) {
			return local_02;
		}
		if (*((int *)local_02->m_hash_tabun)!=(int)local_00) break;
	}
	return NULLPO;
}


//printfでよくansistringをそのまま使っているが、バグの元になっている。(null)Noderef.txtみたいなファイルが出来てしまうのは、これが原因
//ansistringの中身は４バイトで、コンストラクト直後は0になっているが、何かが入るとその文字列へのポインタになるため、通常はうまく動作している
void CMainControl::mf_CMainControl_0190()
{
	char local_09[1024];

	TIniFile *	local_05=new TIniFile(ChangeFileExt(Application->ExeName,".ini"));
	sprintf(local_09,"%sCache",/*(const char *)*/g_AppPath);
	AnsiString local_00=(local_05->ReadString("Option","CacheFolderPath",local_09));
	strcpy(m_sz_CacheFolderPath_,local_00.c_str());
	sprintf(local_09,"%sBbs",/*(const char *)*/g_AppPath);
	local_00=local_05->ReadString("Option","BbsFolderPath",local_09);
	strcpy(m_sz_BbsFolderPath_,local_00.c_str());
	sprintf(local_09,"%sDown",/*(const char *)*/g_AppPath);
	strcpy(m_sz_DownFolderPath_,local_05->ReadString("Option","DownFolderPath",local_09).c_str());
	int	local_06=rand()%31743+1024;
	m_port_accept_=local_05->ReadInteger("Option","AcceptPort",local_06);
	if (! (!(m_port_accept_<=0)&&m_port_accept_<=32767) ) {
		m_port_accept_=local_06;
		local_05->WriteInteger("Option","NotConnected",1);
		m_optflag_notConnected__=true;
	}
	local_05->WriteInteger("Option","AcceptPort",m_port_accept_);
	int	local_07=rand()%31743+1024;
	if (local_07==local_06) {
		local_07=local_07+1;
	}
	m_port_bbsaccept_=local_05->ReadInteger("Option","BbsAcceptPort",local_07);
	if (! (!(m_port_bbsaccept_<0)&&m_port_bbsaccept_<=32767) ) {
		m_port_bbsaccept_=local_07;
	}
	local_05->WriteInteger("Option","BbsAcceptPort",m_port_bbsaccept_);
	int	local_08=local_05->ReadInteger("Option","AutoDisconnect",0);
	m_optflg_autoDisconnect_=(local_08?true:false);
	local_08=local_05->ReadInteger("Option","NotConnected",0);
	m_optflag_notConnected__=(local_08?true:false);
	local_08=local_05->ReadInteger("Option","NotConvert",0);
	m_optflag_notConvert__=(local_08?true:false);
	local_08=local_05->ReadInteger("Option","Connect",1);
	m_optflag_Connect__=(local_08?true:false);
	local_08=local_05->ReadInteger("Option","DisplayUpFile",1);
	m_optflg_displayUpFile_=(local_08?true:false);
	local_08=local_05->ReadInteger("Option","DisplayCacheFile",1);
	m_optflg_displayCacheFile_=(local_08?true:false);
	local_08=local_05->ReadInteger("Option","DisplayTmpCacheFile",1);
	m_optflg_displayTmpCacheFile_=(local_08?true:false);
	local_08=local_05->ReadInteger("Option","DisplayNonWritableBbs",1);
	m_optflg_displayNonWritableBbs_=(local_08?true:false);
	local_08=local_05->ReadInteger("Option","UseTransferLimit",0);
	m_optflg_useTransferLimit_=(local_08?true:false);
	local_08=local_05->ReadInteger("Option","UseMultiDownload",1);
	m_optflg_useMultiDownload_=(local_08?true:false);
	m_flg_unk15509=false;
	local_08=local_05->ReadInteger("Option","CutSlowLine",0);
	m_optflg_cutSlowTransfer_=(local_08?true:false);
	local_08=local_05->ReadInteger("Option","DownRetryFast",1);
	m_optflg_downRetryFast_=(local_08?true:false);
	local_08=local_05->ReadInteger("Option","SearchIgnore",0);
	m_optflg_searchIgnore_=(local_08?true:false);
	local_08=local_05->ReadInteger("Option","AutoTabChange",1);
	m_optflg_autoTabChange_=(local_08?true:false);
	local_08=local_05->ReadInteger("Option","DisplayNewCache",0);
	m_optflg_displayNewCache_=(local_08?true:false);
	local_08=local_05->ReadInteger("Option","UseTipPopup",1);
	m_optflg_useTipPopup_=(local_08?true:false);
	local_08=local_05->ReadInteger("Option","UseBlackColor",0);
	m_optflg_UseBlackColor_=(local_08?true:false);
	local_08=local_05->ReadInteger("Option","UseBlackColor",0);
	m_optflg_UseBlackColor_=(local_08?true:false);
	local_08=local_05->ReadInteger("Option","UseBbsOnly",0);
	m_optflg_UseBbsOnly_=(local_08?true:false);
	local_08=local_05->ReadInteger("Option","MakeMarkFile",1);
	m_optflg_makeMarkFile_=(local_08?true:false);
	g_float_unk101=!(!m_optflg_UseBlackColor_)?(float)1.0:(float)3.0;
	local_08=local_05->ReadInteger("Option","UseBbsBlackColor",0);
	m_optflg_UseBbsBlackColor_=(local_08?true:false);
	local_08=local_05->ReadInteger("Option","V4CacheNotDown",0);
	m_optflg_V4CacheNotDown_=(local_08?true:false);

	local_08=local_05->ReadInteger("Option","DownloadIgnoreKey",0);
	m_unknown_000_70=(local_08?true:false);
	local_08=local_05->ReadInteger("Option","IgnoreRefSort",1);
	m_unknown_001_70=(local_08?true:false);

	g_float_unk102=!(!m_optflg_UseBbsBlackColor_)?(float)1.0:(float)3.0;
	strcpy(m_sz_MyDDNSname_,local_05->ReadString("Option","Hostname","").c_str());
	m_int_linespeed_=local_05->ReadInteger("Option","LineTransferSpeed",120);
	if (m_int_linespeed_<1) {
		m_int_linespeed_=1;
	}
	m_int_virtualKeyMax_=local_05->ReadInteger("Option","VirtualKeyMax",15000);
	if (m_int_virtualKeyMax_<5000) {
		m_int_virtualKeyMax_=5000;
	}
	if (m_int_virtualKeyMax_>50000) {
		m_int_virtualKeyMax_=50000;
	}
	local_05->WriteInteger("Option","VirtualKeyMax",m_int_virtualKeyMax_);
	m_double_optDownParamSize_=atof(local_05->ReadString("Option","DownParamSize","0").c_str());
	m_double_optDownParamBlock_=atof(local_05->ReadString("Option","DownParamBlock","0.5").c_str());
	m_double_optDownParamTime_=atof(local_05->ReadString("Option","DownParamTime","0.5").c_str());
	m_double_optDownParamRef_=atof(local_05->ReadString("Option","DownParamRef","0.5").c_str());
	m_str_optBbsBrowser_=local_05->ReadString("Option","BbsBrowser","iexplore.exe");
	m_str_optUrlBrowser_=local_05->ReadString("Option","UrlBrowser","iexplore.exe");
	local_05->WriteString("Option","BbsBrowser",m_str_optBbsBrowser_);
	local_05->WriteString("Option","UrlBrowser",m_str_optUrlBrowser_);
	m_str_optDownlistEditor_=local_05->ReadString("Option","DownlistEditor","");
	local_05->WriteString("Option","DownlistEditor",m_str_optDownlistEditor_);
	m_str_optFolderBrowser_=local_05->ReadString("Option","FolderBrowser","explorer.exe");
	local_05->WriteString("Option","FolderBrowser",m_str_optFolderBrowser_);
	m_str_fontName_=local_05->ReadString("Option","FontName","ＭＳ Ｐゴシック");
	m_double_fontSize_=atof(local_05->ReadString("Option","FontSize","9").c_str());
	g_opt_longFontSpace=local_05->ReadInteger("Option","FontSpace",15);
	if (g_opt_longFontSpace<1) {
		g_opt_longFontSpace=1;
	}

	g_pCMainControl->m_int_maxnamelen_70=local_05->ReadInteger("Option","MaxNameLength",255);
	if (g_pCMainControl->m_int_maxnamelen_70>255) {
		g_pCMainControl->m_int_maxnamelen_70=255;
	}
	if (g_pCMainControl->m_int_maxnamelen_70<16) {
		g_pCMainControl->m_int_maxnamelen_70=16;
	}

	sprintf(local_09,"%s%s",/*(const char *)*/g_AppPath,"UpFolder.txt");
	mf_CMainControl_0040(local_09);
	mf_CMainControl_1570();
	sprintf(local_09,"%s%s",/*(const char *)*/g_AppPath,"DownList.txt");
	mf_CMainControl_0090(local_09,false);
	sprintf(local_09,"%s%s",/*(const char *)*/g_AppPath,"Download.txt");
	mf_CMainControl_0090(local_09,true);
	mf_CMainControl_0110(local_09);
	sprintf(local_09,"%s%s",/*(const char *)*/g_AppPath,"DownList.txt");
	mf_CMainControl_0100(local_09,false);
	sprintf(local_09,"%s%s",/*(const char *)*/g_AppPath,"Delete.txt");
	mf_CMainControl_0100(local_09,false);
	sprintf(local_09,"%s%s",/*(const char *)*/g_AppPath,"Ignore.txt");
	mf_CMainControl_0100(local_09,true);
	mf_CMainControl_0120(local_09);
	m_int_related_maxconnection__=m_int_linespeed_/80;
	if (m_int_related_maxconnection__<2) {
		m_int_related_maxconnection__=2;
	}
	m_int_currentTransferUpConnectionMax_=m_int_related_maxconnection__;
	mf_CMainControl_0220();
	mf_CMainControl_0380();
	sprintf(local_09,"%s%s",/*(const char *)*/g_AppPath,"Noderef.txt");
	mf_CMainControl_1210(local_09,false);
	sprintf(local_09,"%s%s",/*(const char *)*/g_AppPath,"BbsNoderef.txt");
	mf_CMainControl_1210(local_09,true);
	m_flg_unk203=true;
	mf_CMainControl_0300();
	mf_CMainControl_0280();
	if (m_optflag_Connect__) {
		mf_CMainControl_0240();
	}
	if (local_05!=NULLPO) delete local_05;
	return;
}


void CMainControl::mf_CMainControl_0200()
{
	_in_addr local_00;
	char local_07[256];

	ny_addrset(&local_00,127,0,0,1);
        int tmp1=m_port_accept_;
	m_hostArray[0].m_port1=tmp1;
        int tmp2=m_port_bbsaccept_;
	m_hostArray[0].m_port2=tmp2;
	if (! (gethostname(local_07,256)!=0||strlen(local_07)<=0) ) {
	HOSTENT *		local_01=gethostbyname(local_07);
		if (local_01!=0) {
			unsigned char local_02,local_03,local_04,local_05;
			local_05=(*(local_01->h_addr_list))[0];//->b1;
			local_04=(*local_01->h_addr_list)[1];//->b2;
			local_03=(*local_01->h_addr_list)[2];//->b3;
			local_02=(*local_01->h_addr_list)[3];//->b4;
			CHost*			local_06=m_hostArray;
			local_06->m_ipaddr3.b1=local_05;
			local_06->m_ipaddr3.b2=local_04;
			local_06->m_ipaddr3.b3=local_03;
			local_06->m_ipaddr3.b4=local_02;
		}
	}
	if (strlen(m_sz_MyDDNSname_)>0) {
		m_hostArray[0].mf_CHost_0230(m_sz_MyDDNSname_);
		m_hostArray[0].mf_CHost_0200();
	} else {
		m_hostArray[0].mf_CHost_0230("");
	}
}


void CMainControl::mf_CMainControl_0210()
{
	m_hostArray[0].SetPort(m_port_accept_);
	m_hostArray[0].SetBbsPort(m_port_bbsaccept_);
	CGlobalLock::g_globallock=2;
	ny_nazo(1.0);
	mf_CMainControl_0810();
	ny_nazo(2.0);
	mf_CMainControl_0820();
	CGlobalLock::g_globallock=0;
	ny_nazo(3.0);

	int local_00;
	int local_01;
	local_00=2;
	for (local_01=0; local_01<local_00; local_01++) {
		CGlobalLock::g_globallock=2;
		mf_CMainControl_0800();
		CGlobalLock::g_globallock=0;
	}
	ny_nazo(4.0);
	CGlobalLock::g_globallock=2;
	mf_CMainControl_1090();
	CGlobalLock::g_globallock=0;
	ny_nazo(5.0);
	return;
}



void CMainControl::mf_CMainControl_0220()
{
	int local_00;
	if ((local_00=WSAStartup(257,&m_wsadata_))!=0) {
		ny_addlog("WSAStartup() 失敗");
		switch (local_00) {
		case 10091:  
			ny_addlog("Indicates that the underlying network subsystem is not ready for network communication.");
			break;
		case 10092:  
			ny_addlog("The version of Windows Sockets support requested is not provided by this particular Windows Sockets implementation. ");
			break;
		case 10036:  
			ny_addlog("A blocking Windows Sockets 1.1 operation is in progress. ");
			break;
		case 10067:
			ny_addlog("Limit on the number of tasks supported by the Windows Sockets implementation has been reached. ");
			break;
		case 10014:
			ny_addlog("The lpWSAData is not a valid pointer. ");
		}
		m_flgarray_unk[7]=true;
		return;
	}
	mf_CMainControl_0200();
	return;
}


void CMainControl::mf_CMainControl_0230(unsigned int arg_0,int arg_1,int arg_2)
{
	if (arg_0>1024) {
		arg_0=arg_0-1024;
		if (arg_0==1) {
			mf_CMainControl_0290(arg_1,arg_2);
			return;
		}
		if (arg_0==2) {
			mf_CMainControl_0310(arg_1,arg_2);
			return;
		}
		for (int local_00=0; local_00<600; local_00++) {
			if (!m_hostArray[local_00].m_flgIsValid) continue;
			if (m_hostArray[local_00].GetWmsgOfs_connect()==arg_0) {
				mf_CMainControl_0270(local_00,arg_1,arg_2);
			}
			if (m_hostArray[local_00].GetWmsgOfs_gethostbyname()==arg_0) {
				m_hostArray[local_00].mf_CHost_0210(arg_1,arg_2);
			}
			if (m_hostArray[local_00].GetWmsgOfs_crw()!=arg_0) continue;
			if ( ((unsigned short)arg_2&(unsigned short)0xffff)==(unsigned short)2) {
				m_hostArray[local_00].mf_CHost_0180();
				continue;
			}
			if (m_hostArray[local_00].m_field_7C) continue;
			mf_CMainControl_0360(local_00,arg_2);
		}
	}
	return;
}


void CMainControl::mf_CMainControl_0240()
{
	unsigned	int local_00;
	unsigned int local_01;
	int local_02;
	if (! (m_optflg_UseBbsOnly_||!m_optflag_Connect__||m_vectorCHostSorter_.size()==0) ) {
		local_00=(int)GetTickCount();
		if (local_00-g_int_unk400>=4000) {
			g_int_unk400=local_00;
			for (local_01=0; m_vectorCHostSorter_.size()>local_01; local_01++) {
				local_02=m_vectorCHostSorter_[local_01].m_int_unk00;
				if (local_02<0) continue;
				CHost * local_03;
				local_03=m_hostArray+local_02;
				if ((!local_03->m_flgIsValid||local_03->m_flgIsBBSNode_8||local_03->m_flg_IsBBSPort||local_03->m_field_8E||local_03->m_flgIsPortZero_9||local_03->m_flgIsBadPortZero_9||local_03->m_field_82||local_03->m_flgNetsuzouWarning_8||local_03->m_flgIgnoredWarning_8||local_03->m_flgIsConnected||local_03->m_field_81)||!(local_03->m_int_lineSpeed<0)&&local_03->m_int_lineSpeed<=20) continue;
				mf_CMainControl_0260(local_02,false);
				local_03->m_int_preference2_negative=local_03->m_int_preference2_negative+1;
				break;
			}
		}
	}
	return;
}


void CMainControl::mf_CMainControl_0250()
{
	unsigned int local_00;
	unsigned int local_01;
	int local_02;
	if (! (!m_optflag_Connect__||m_vectorCHostSorter_.size()==0) ) {
		local_00=(int)GetTickCount();
		if (local_00-g_int_unk401>=4000) {
			g_int_unk401=local_00;
			for (local_01=0; m_vectorCHostSorter_.size()>local_01; local_01++) {
				local_02=m_vectorCHostSorter_[local_01].m_int_unk00;
				if (local_02<0) continue;
	CHost * local_03;
				local_03=m_hostArray+local_02;
				if ((!local_03->m_flgIsValid||!local_03->m_flgIsBBSNode_8||local_03->m_flg_IsBBSPort||local_03->m_field_8E||local_03->m_flgIsPortZero_9||local_03->m_flgIsBadPortZero_9||local_03->m_field_82||local_03->m_flgNetsuzouWarning_8||local_03->m_flgIgnoredWarning_8||local_03->m_flgIsConnected||local_03->m_field_81)||!(local_03->m_int_lineSpeed<0)&&local_03->m_int_lineSpeed<=20) continue;
				mf_CMainControl_0260(local_02,false);
				local_03->m_int_preference2_negative=local_03->m_int_preference2_negative+1;
				break;
			}
		}
	}
	return;
}


void CMainControl::mf_CMainControl_0260(int arg_0,bool arg_1)
{
	SOCKADDR_IN local_08;
	char local_09[200];
	if (! (!(g_bool_unk100||arg_0<0||arg_0>=600)&&m_optflag_Connect__) ) {
		return;
	}
	CHost * local_00;
	_in_addr * local_01;
	local_00=m_hostArray+arg_0;
	local_01=&local_00->m_ipaddr3;
	if (! (!(local_01->b1==0||local_00->m_port1==0)&&(!arg_1||local_00->m_port2!=0)) ) {
		return;
	}
	if (! (!(local_00->IsInternalIpaddr(m_hostArray[0].m_ipaddr3))||local_00->m_port1!=m_port_accept_) ) {
		return;
	}
	if (local_00->m_field_8E) {
		return;
	}

	SOCKET local_02;
	int local_03;
	int local_04;
	SOCKET local_05;

	local_00->m_flg_isDownConnection=false;
	local_00->m_field_94=false;
	local_00->m_field_7E=false;
	local_00->m_field_8D=false;
	local_00->m_int_connectionTimeInSec=0;
	local_02=socket(2,1,0);
	g_int_unk505=g_int_unk505+1;
	if (local_02==-1) {
		local_03=WSAGetLastError();
		ny_addlog("socket() 失敗");
		mf_CMainControl_1660(local_03);
		m_flgarray_unk[7]=true;
		return;
	}
	local_04=1;
	setsockopt(local_02,0x0000FFFF,-129,(const char *)&local_04,4);
	local_08.sin_family=2;
	if (arg_1) {
		local_08.sin_port=htons(*((unsigned short *)(&local_00->m_port2)));
	} else {
		local_08.sin_port=htons(*((unsigned short *)(&local_00->m_port1)));
	}
	local_01=&local_00->m_ipaddr3;
	local_08.sin_addr.S_un.S_un_b.s_b1=local_01->b1;
	local_08.sin_addr.S_un.S_un_b.s_b2=local_01->b2;
	local_08.sin_addr.S_un.S_un_b.s_b3=local_01->b3;
	local_08.sin_addr.S_un.S_un_b.s_b4=local_01->b4;
	local_05=local_00->m_socket;
	if (local_05!=0) {
		closesocket(local_05);
		g_int_unk506=g_int_unk506+1;
		local_00->m_socket=0;//INVALID_SOCKET;
	}
	local_00->SetSocket(local_02);
	local_00->m_flgIsConnected=false;
	local_00->m_field_81=true;
	local_00->m_int_lineSpeed=-1;
		bool tmp1=arg_1;
	local_00->m_flgIsBBSConnectionTest=tmp1;//arg_1;
	if (WSAAsyncSelect(local_02,m_hwnd_unk32,local_00->GetWmsgOfs_connect()+1024,16)==-1) {
		int		local_06=WSAGetLastError();
		sprintf(local_09,"WSAAsyncSelect(connect) 失敗");
		ny_addlog(local_09);
		mf_CMainControl_1590(local_06);
		local_00->mf_CHost_0190(true);
		m_flgarray_unk[7]=true;
		return;
	}
	if (connect(local_02,(sockaddr *)&local_08,16)==-1) {
		int		local_07=WSAGetLastError();
		if (local_07!=10035) {
			if (! (local_07==10053||local_07==10054) ) {
				ny_addlog("connect() 失敗");
				mf_CMainControl_1600(local_07);
				m_flgarray_unk[7]=true;
			}
			local_00->mf_CHost_0190(true);
			return;
		}
	}
	m_flgarray_unk[7]=true;
	return;
}


void CMainControl::mf_CMainControl_0270(int arg_0,int arg_1,int arg_2)
{
	CHost * local_00;
	SOCKET local_01;
	char local_03[200];
	if (! (!(arg_0<0)&&arg_0<600) ) {
		return;
	}
	local_00=m_hostArray+arg_0;
	if (!local_00->m_flgIsValid) {
		return;
	}
	local_01=local_00->m_socket;
	if ((short)((unsigned int)arg_2>>16)!=0) {
		local_00->mf_CHost_0190(true);
		local_00->m_field_8C=true;
		local_00->m_flgIsValid=false;
		m_flgarray_unk[7]=true;
		return;
	}
	if (local_00->m_flgIsBBSConnectionTest) {
		local_00->m_flgIsConnected=true;
		return;
	}
	unsigned int tmp=local_00->GetWmsgOfs_crw();
	if (WSAAsyncSelect(local_01,m_hwnd_unk32,tmp+1024,35)==-1) {
		int		local_02=WSAGetLastError();
		if (local_02!=10038) {
			sprintf(local_03,"WSAAsyncSelect(connected) 失敗");
			ny_addlog(local_03);
			mf_CMainControl_1590(local_02);
			m_flgarray_unk[7]=true;
		}
		local_00->mf_CHost_0190(true);
	} else {
		local_00->m_flgIsConnected=true;
		local_00->m_flgUnknown_80=true;
		local_00->m_field_81=false;
		mf_CMainControl_0670(arg_0,0);
		m_flgarray_unk[7]=true;
	}
	return;
}


void CMainControl::mf_CMainControl_0280()
{
	int local_00;
	char local_05[200];
	SOCKADDR_IN local_06;
	if (!m_optflag_Connect__) {
		return;
	}
	for (local_00=1; local_00<600; local_00++) {
		m_hostArray[local_00].m_field_94=false;
	}
	ny_addlog(" ポート待ち受け開始");
	m_flgarray_unk[7]=true;
	m_socket_accepting__=socket(2,1,0);
	if (m_socket_accepting__==-1) {
		int		local_01=WSAGetLastError();
		ny_addlog("socket() 失敗");
		mf_CMainControl_1660(local_01);
		m_flgarray_unk[7]=true;
		return;
	}
	g_int_unk503=g_int_unk503+1;
	if (WSAAsyncSelect(m_socket_accepting__,m_hwnd_unk32,1025,8)==-1) {
		int		local_02=WSAGetLastError();
		sprintf(local_05,"WSAAsyncSelect(accept) 失敗");
		ny_addlog(local_05);
		mf_CMainControl_1590(local_02);
		m_socket_accepting__=0;//INVALID_SOCKET;
		m_flgarray_unk[7]=true;
	}
	local_06.sin_family=2;
	local_06.sin_addr.S_un.S_addr=0;
	local_06.sin_port=htons(*((unsigned short *)(&m_port_accept_)));
		int tmp=sizeof(sockaddr);
	if (bind(m_socket_accepting__,(sockaddr *)&local_06,tmp)==-1) {
		int		local_03=WSAGetLastError();
		if (local_03==10048) {
			m_flg_unk15469=true;
			m_optflag_Connect__=false;
			return;
		}
		ny_addlog("bind() 失敗");
		mf_CMainControl_1620(local_03);
		m_flgarray_unk[7]=true;
		return;
	}
	if (listen(m_socket_accepting__,40)==-1) {
		int		local_04=WSAGetLastError();
		ny_addlog("listen() 失敗");
		mf_CMainControl_1630(local_04);
		m_flgarray_unk[7]=true;
		return;
	}
	m_flg_unk200=true;
	return;
}


void CMainControl::mf_CMainControl_0290(int arg_0,int arg_1)
{
	int local_00;
	SOCKET local_01;
	int local_02;
	int local_03;
	_in_addr local_04;
	int local_05;
	SOCKET local_06;
	CHost * local_07;

	SOCKADDR_IN local_09;
	char local_10[200];
	if ((short)((unsigned int)arg_1>>16)!=0) {
		ny_addlog("ネットワークサブシステム異常のため待ちうけポートを再初期化しました");
		if (m_socket_accepting__!=0) {
			closesocket(m_socket_accepting__);
			m_socket_accepting__=0;//INVALID_SOCKET;
			g_int_unk506=g_int_unk506+1;
		}
		m_flg_unk200=false;
		m_socket_accepting__=0;//INVALID_SOCKET;
		m_flgarray_unk[7]=true;
		return;
	}
	local_00=16;
	if ((local_01=accept(m_socket_accepting__,(sockaddr *)&local_09,&local_00))==-1) {
		local_02=WSAGetLastError();
		if (local_02!=10035) {
			if (! (local_02==10053||local_02==10054) ) {
				ny_addlog("accept() 失敗");
				mf_CMainControl_1610(local_02);
				m_flgarray_unk[7]=true;
			}
			m_socket_accepting__=0;//INVALID_SOCKET;
			return;
		}
		return;
	}
	g_int_unk504=g_int_unk504+1;
	if (! (!(m_int_CurrentSearchDownConnectionCount_>10)&&m_int_CurrentSearchUpConnectionCount_<=4) ) {
		closesocket(local_01);
		g_int_unk506=g_int_unk506+1;
		return;
	}
	local_03=1;
	setsockopt(local_01,0x0000FFFF,-129,(char *)&local_03,4);
	local_04.b1=local_09.sin_addr.S_un.S_un_b.s_b1;
	local_04.b2=local_09.sin_addr.S_un.S_un_b.s_b2;
	local_04.b3=local_09.sin_addr.S_un.S_un_b.s_b3;
	local_04.b4=local_09.sin_addr.S_un.S_un_b.s_b4;
	local_05=mf_CMainControl_0560(&local_04,0);
	local_06=m_hostArray[local_05].m_socket;
	if (local_06!=0) {
		closesocket(local_06);
		g_int_unk506=g_int_unk506+1;
		m_hostArray[local_05].m_socket=0;//INVALID_SOCKET;
	}
	local_07=m_hostArray+local_05;
	local_07->m_ipaddr3.b1=local_04.b1;
	local_07->m_ipaddr3.b2=local_04.b2;
	local_07->m_ipaddr3.b3=local_04.b3;
	local_07->m_ipaddr3.b4=local_04.b4;
	m_hostArray[local_05].m_port1=0;
	m_hostArray[local_05].SetSocket(local_01);
	m_hostArray[local_05].m_flgIsConnected=true;
	m_hostArray[local_05].m_flgIsValid=true;
	m_hostArray[local_05].m_field_94=false;
	m_hostArray[local_05].m_field_8D=false;
	m_hostArray[local_05].m_int_connectionTimeInSec=0;
	m_hostArray[local_05].m_flg_IsBBSPort=false;
	m_hostArray[local_05].m_int_lineSpeed=-1;
	if (WSAAsyncSelect(local_01,m_hwnd_unk32,m_hostArray[local_05].GetWmsgOfs_crw()+1024,35)==-1) {
		int		local_08=WSAGetLastError();
		if (local_08!=10038) {
			sprintf(local_10,"WSAAsyncSelect(accepted) 失敗");
			ny_addlog(local_10);
			mf_CMainControl_1590(local_08);
			m_flgarray_unk[7]=true;
		}
		m_hostArray[local_05].mf_CHost_0190(false);
	} else {
		Sleep(1);
		mf_CMainControl_0670(local_05,1);
	}
	m_flgarray_unk[7]=true;
	return;
}


void CMainControl::mf_CMainControl_0300()
{
	char local_04[200];
	SOCKADDR_IN local_05;
	if (m_port_bbsaccept_==0) {
		return;
	}
	ny_addlog(" BBSポート待ち受け開始");
	m_flgarray_unk[7]=true;
	m_socket_unk33=socket(2,1,0);
	if (m_socket_unk33==-1) {
		int		local_00=WSAGetLastError();
		ny_addlog("socket() 失敗");
		mf_CMainControl_1660(local_00);
		m_port_bbsaccept_=0;
		m_flgarray_unk[7]=true;
		return;
	}
	g_int_unk503=g_int_unk503+1;
	if (WSAAsyncSelect(m_socket_unk33,m_hwnd_unk32,1026,8)==-1) {
		int		local_01=WSAGetLastError();
		sprintf(local_04,"WSAAsyncSelect(accept) 失敗");
		ny_addlog(local_04);
		mf_CMainControl_1590(local_01);
		m_socket_unk33=0;//INVALID_SOCKET;
		m_port_bbsaccept_=0;
		m_flgarray_unk[7]=true;
	}
	local_05.sin_family=2;
	local_05.sin_addr.S_un.S_addr=0;
	local_05.sin_port=htons(*((unsigned short *)(&m_port_bbsaccept_)));
		int tmp=sizeof(sockaddr);
	if (bind(m_socket_unk33,(sockaddr *)&local_05,tmp/*16*/)==-1) {
		int		local_02=WSAGetLastError();
		if (local_02==10048) {
			m_flg_unk15470=true;
			m_optflag_Connect__=false;
			return;
		}
		m_port_bbsaccept_=0;
		ny_addlog("bind() 失敗");
		mf_CMainControl_1620(local_02);
		m_flgarray_unk[7]=true;
		return;
	}
	if (listen(m_socket_unk33,40)==-1) {
		int		local_03=WSAGetLastError();
		ny_addlog("listen() 失敗");
		mf_CMainControl_1630(local_03);
		m_port_bbsaccept_=0;
		m_flgarray_unk[7]=true;
		return;
	}
	m_flg_unk201=true;
	return;
}


void CMainControl::mf_CMainControl_0310(int arg_0,int arg_1)
{
	int local_00;
	SOCKET local_01;
	int local_02;
	int local_03;
	_in_addr local_04;
	int local_05;
	SOCKET local_06;
	CHost * local_07;
	SOCKADDR_IN local_10;
	char local_11[200];
	char local_12[256];
	if ((short)((unsigned int)arg_1>>16)!=0) {
		ny_addlog("ネットワークサブシステム異常のため待ちうけポートを再初期化しました");
		if (m_socket_unk33!=0) {
			closesocket(m_socket_unk33);
			m_socket_unk33=0;//INVALID_SOCKET;
			g_int_unk506=g_int_unk506+1;
		}
		m_flg_unk201=false;
		m_socket_unk33=0;//INVALID_SOCKET;
		m_flgarray_unk[7]=true;
		return;
	}
	local_00=16;
	if ((local_01=accept(m_socket_unk33,(sockaddr *)&local_10,&local_00))==-1) {
		local_02=WSAGetLastError();
		if (local_02!=10035) {
			if (! (local_02==10053||local_02==10054) ) {
				ny_addlog("accept() 失敗");
				mf_CMainControl_1610(local_02);
				m_flgarray_unk[7]=true;
			}
			m_socket_unk33=0;//INVALID_SOCKET;
			return;
		}
		return;
	}
	g_int_unk504=g_int_unk504+1;
	local_03=1;
	setsockopt(local_01,0x0000FFFF,-129,(char *)&local_03,4);
	local_04.b1=local_10.sin_addr.S_un.S_un_b.s_b1;
	local_04.b2=local_10.sin_addr.S_un.S_un_b.s_b2;
	local_04.b3=local_10.sin_addr.S_un.S_un_b.s_b3;
	local_04.b4=local_10.sin_addr.S_un.S_un_b.s_b4;
	local_05=mf_CMainControl_0560(&local_04,0);
	local_06=m_hostArray[local_05].m_socket;
	if (local_06!=0) {
		closesocket(local_06);
		g_int_unk506=g_int_unk506+1;
		m_hostArray[local_05].m_socket=0;//INVALID_SOCKET;
	}
	local_07=m_hostArray+local_05;
	local_07->m_ipaddr3.b1=local_04.b1;
	local_07->m_ipaddr3.b2=local_04.b2;
	local_07->m_ipaddr3.b3=local_04.b3;
	local_07->m_ipaddr3.b4=local_04.b4;
	m_hostArray[local_05].m_port1=0;
	m_hostArray[local_05].SetSocket(local_01);
	m_hostArray[local_05].m_flgIsConnected=true;
	m_hostArray[local_05].m_flgIsValid=true;
	m_hostArray[local_05].m_field_94=false;
	m_hostArray[local_05].m_field_8D=false;
	m_hostArray[local_05].m_int_connectionTimeInSec=0;
	m_hostArray[local_05].m_int_lineSpeed=-1;
	m_hostArray[local_05].m_flg_IsBBSPort=true;
	if (WSAAsyncSelect(local_01,m_hwnd_unk32,m_hostArray[local_05].GetWmsgOfs_crw()+1024,35)==-1) {
		int		local_08=WSAGetLastError();
		if (local_08!=10038) {
			sprintf(local_11,"WSAAsyncSelect(accept) 失敗");
			ny_addlog(local_11);
			mf_CMainControl_1590(local_08);
			m_flgarray_unk[7]=true;
			m_hostArray[local_05].mf_CHost_0190(true);
		}
	} else {
		Sleep(1);
		int		local_09=mf_CMainControl_0610();
		m_vectorpCWork_[local_09]->mf_CWork_0160(local_05);
		sprintf(local_12,"%d.%d.%d.%d",(unsigned int)local_04.b1,(unsigned int)local_04.b2,(unsigned int)local_04.b3,(unsigned int)local_04.b4);
				CWork *tmp2=(m_vectorpCWork_[local_09]);
		strcpy(tmp2->m_char256_unk10,local_12);
		m_flgarray_unk[7]=true;
	}
	return;
}


void CMainControl::mf_CMainControl_0320()
{
	unsigned int local_00;
	for (local_00=1; local_00<600; local_00++) {
		m_hostArray[local_00].mf_CHost_0190(true);
	}
	for (local_00=0; m_vectorpCWork_.size()>local_00; local_00++) {
		if ((*GetWorkNP(local_00))->GetWorkType()!=WORKTYPE01||(*GetWorkNP(local_00))->IsFinished()) continue;
		m_vectorpCWork_[local_00]->mf_CWork_0010(false,true);
	}
	m_int_unk42=0;
	m_flgarray_unk[7]=true;
	m_uint_unk14=0;
	m_int_unk15=0;
	mf_CMainControl_0700();
	return;
}


void CMainControl::mf_CMainControl_0330(bool arg_0)
{
	int local_00;
	for (local_00=1; local_00<600; local_00++) {
		if (!(!m_hostArray[local_00].m_flgIsConnected)&&(m_hostArray[local_00].m_flgIsTransferLink_8||!(m_hostArray[local_00].m_flgIsBBSNode_8||arg_0)&&m_hostArray[local_00].m_flgIsPortZero_9)) continue;
		m_hostArray[local_00].mf_CHost_0190(true);
	}
	m_int_unk42=0;
	return;
}


void CMainControl::mf_CMainControl_0340()
{
	int local_00;
	for (local_00=1; local_00<600; local_00++) {
		if (!(!m_hostArray[local_00].m_flgIsConnected)&&(!m_hostArray[local_00].m_flgIsBBSNode_8||m_hostArray[local_00].m_flgIsTransferLink_8)) continue;
		m_hostArray[local_00].mf_CHost_0190(true);
	}
	return;
}


void CMainControl::mf_CMainControl_0350()
{
	int local_00;
	for (local_00=1; local_00<600; local_00++) {
		if (!(!m_hostArray[local_00].m_flgIsConnected)&&!m_hostArray[local_00].m_flgIsTransferLink_8) continue;
		m_hostArray[local_00].mf_CHost_0190(true);
	}
	m_flgarray_unk[7]=true;
	return;
}



void CMainControl::mf_CMainControl_0360(int arg_0,int arg_1)
{
	CHost * local_00;
	int local_01;
	SOCKET local_02;
	int local_03;
	char local_04;
	char * local_05;
	if (! (!(arg_0<0)&&arg_0<600) ) {
		return;
	}
	local_00=m_hostArray+arg_0;
	if (!local_00->m_flgIsConnected) {
		return;
	}
	if ( (((unsigned short)arg_1)&(unsigned short)0xffff)==(unsigned short)32) {
		local_00->mf_CHost_0190(true);
		return;
	}
	local_01=-1;
	local_02=local_00->m_socket;
	if (local_02==0) {
		local_00->mf_CHost_0190(true);
		return;
	}
	local_01=recv(local_02,gbuf20000_r1,0x0001FFFC,0);
	if (local_01==0) {
		local_00->mf_CHost_0190(true);
		return;
	}
	local_00->m_int_nodataTimeInSec=0;
	if (local_01==-1) {
		local_03=WSAGetLastError();
		if (local_03!=10035) {
			if (! (local_03==10053||local_03==10054||local_03==10057) ) {
				ny_addlog("recv() 失敗");
				mf_CMainControl_1640(local_03);
				m_flgarray_unk[7]=true;
				if (!local_00->m_flg_IsBBSPort) {
					local_04=31;
					mf_CMainControl_0370(arg_0,&local_04,1);
				}
			}
			local_00->mf_CHost_0190(true);
			return;
		}
		Sleep(10);
		goto ret;
	}
	if (local_00->m_flg_IsBBSPort) {
		local_00->mf_CHost_0100(gbuf20000_r1,local_01);
		goto ret;
	}
	
	if (!local_00->m_flgRecvKeyok_9) {

		if (local_01>=6) {

			local_05=local_00->m_cryptseed_recv;
			memcpy(local_05,gbuf20000_r1+2,4);
			*(local_05+4)=0;
			local_00->mf_CHost_0060(local_05);
			local_00->mf_CHost_0110(gbuf20000_r1+6,local_01+-6);
			goto ret2;

		}

		local_00->mf_CHost_0190(true);
		return;

	}
	local_00->mf_CHost_0110(gbuf20000_r1,local_01);
ret2:
	m_int_14420=m_int_14420+local_01;
ret:
	return;
}


void CMainControl::mf_CMainControl_0370(int hostidx,char * buf,int len)
{
	CHost * local_00;
	if (! (hostidx<0||hostidx>=600) ) {
		local_00=m_hostArray+hostidx;
		*((int *)gbuf_sendbuf)=len;
		memcpy(gbuf_sendbuf+4,buf,len);
		local_00->mf_CHost_0160(gbuf_sendbuf,len+4);
		local_00->mf_CHost_0180();
	}
	return;
}


void CMainControl::mf_CMainControl_0380()
{
	try {
		m_flg_IsJoiningBBSCluster_=false;
		mf_CMainControl_0460();
		mf_CMainControl_0690();
		m_flg_unk15510=true;
		int		local_00=m_vectorCFolder_.size();
		m_vectorInt_.resize(local_00);
		for (int local_01=0; local_01<local_00; local_01++) {
			m_vectorInt_[local_01]=-1;
			GetFolder(local_01)->Set_flg_unk4(false);
		}
		int		local_02=mf_CMainControl_0610();
		m_vectorpCWork_[local_02]->mf_CWork_0140(m_sz_CacheFolderPath_,"",-1);
		m_int_unk16=local_02;
	}
	catch (std::bad_alloc ex_8) {
	}
	return;
}


void CMainControl::mf_CMainControl_0390()
{
	try {
		mf_CMainControl_0710();
		int		local_00=m_vectorCFolder_.size();
		m_vectorInt_.resize(local_00);
		int local_01;
		for (local_01=0; local_01<local_00; local_01++) {
			m_vectorInt_[local_01]=-1;
		}
		for (local_01=0; local_01<local_00; local_01++) {
			if (!GetFolder(local_01)->Get_flg_unk3()) continue;
			GetFolder(local_01)->Set_int_unk2(0);
			GetFolder(local_01)->Set_int_unk1(0);
		}
		m_int_unk40=0;
		if (m_int_unk40<local_00) {
int			local_02=mf_CMainControl_0610();
			m_vectorpCWork_[local_02]->mf_CWork_0140(GetFolder(m_int_unk40)->Get_001_cstr(),GetFolder(m_int_unk40)->Get_002_cstr(),m_int_unk40);
			m_vectorInt_[m_int_unk40]=local_02;
		} else {
			m_flg_unk15510=false;
			m_flgarray_unk[2]=true;
			m_flgarray_unk[9]=true;
			m_flgarray_unk[3]=true;
		}
	}
	catch (std::bad_alloc ex_8) {
	}
	return;
}


void CMainControl::mf_CMainControl_0400()
{
	int local_00;
	if (m_flg_unk15510) {
		local_00=m_vectorInt_.size();
		if (! (!(m_int_unk16<0)&&!(*GetWorkNP(m_int_unk16))->IsFinished()) ) {
			if (m_int_unk16>=0) {
				(*GetWorkNP(m_int_unk16))->SetWorkType(WORKTYPE00);
				mf_CMainControl_0390();
			}
			m_int_unk16=-1;
			if (! (!(m_int_unk40>=local_00)&&m_vectorInt_[m_int_unk40]>=0) ) {
				m_flg_unk15510=false;
				return;
			}
			if ((*GetWorkNP(m_vectorInt_[m_int_unk40]))->IsFinished()) {
				(*GetWorkNP(m_vectorInt_[m_int_unk40]))->SetWorkType(WORKTYPE00);
				m_vectorInt_[m_int_unk40]=-1;
				GetFolderR(m_int_unk40).Set_flg_unk4(true);
				for (m_int_unk40=m_int_unk40+1; !(m_int_unk40>=local_00)&&!GetFolderR(m_int_unk40).Get_flg_unk3(); m_int_unk40++) {
				}
				if (m_int_unk40<local_00) {
					int local_01=mf_CMainControl_0610();
					m_vectorpCWork_[local_01]->mf_CWork_0140(GetFolder(m_int_unk40)->Get_001_cstr(),GetFolder(m_int_unk40)->Get_002_cstr(),m_int_unk40);
					m_vectorInt_[m_int_unk40]=local_01;
					return;
				}
				mf_CMainControl_7000();
				mf_CMainControl_1200();
				m_flg_unk15510=false;
				mf_CMainControl_0740();
				m_flgarray_unk[2]=true;
				m_flgarray_unk[9]=true;
				m_flgarray_unk[3]=true;
			}
		}
	}
	return;
}


void CMainControl::mf_CMainControl_0410(const char * arg_0)
{
	int local_00;
	char local_01[4096];
	struct__finddata_t local_02;
	sprintf(local_01,"%s\\%s",m_sz_BbsFolderPath_,arg_0);
	if ((local_00=_findfirst(local_01,&local_02))>=0) {
		mf_CMainControl_0470(&local_02,true);
	}
	_findclose(local_00);
	m_flgarray_unk[9]=true;
	return;
}


void CMainControl::mf_CMainControl_0420()
{
	FILE * local_00;
	char local_01[1024];
	strcpy(local_01,Application->ExeName.c_str());
	local_00=fopen(local_01,"rb");
	if (local_00==0) {
		return;
	}
	if (fseek(local_00,1520,0)!=0) {
		fclose(local_00);
		return;
	}
	fread(g_exesignature_defined,1,16,local_00);
	fclose(local_00);
	MD5_exechecksub(local_01,g_pCMainControl->m_hash_exeHash_);
	m_flag_exeSignatureIsOkay_=(!(memcmp(m_hash_exeHash_,g_exesignature_defined,16)!=0)?true:false);
	return;
}


void CMainControl::mf_CMainControl_0430()
{
	int local_00;
	HANDLE local_01;
	int local_02;
	DWORD readbyte;
	int local_03;
    char unkbuf[1024];
	unsigned char local_04[16];
	ny_aschash2binhash(ControlForm->CheckLabel->Caption.c_str(),g_memorysignature_compared);
	for (local_00=0; local_00<16; local_00++) {
		m_hash_memorySignature_[local_00]=0;
	}
	if (g_pproc_ReadProcessMemory==0) {
		return;
	}
	local_01=GetCurrentProcess();
	for (local_02=1026; local_02<1280; local_02++) {
		g_pproc_ReadProcessMemory(local_01,(void *)(local_02<<12),gbuf1000_memsigwork,4096,&readbyte);
		MD5calc(gbuf1000_memsigwork,local_04,4096);
		for (local_03=0; local_03<16; local_03++) {
			m_hash_memorySignature_[local_03]=(m_hash_memorySignature_[local_03]^local_04[local_03]);
		}
	}
	return;
}


void CMainControl::mf_CMainControl_0440(int arg_0)
{
	int local_00;
	unsigned int local_01;
	int local_02;
	char local_09[4096];

	local_00=1000;
	local_01=GetTickCount();
	local_02=0;
	if (local_02>=local_00) return;
	do {
		if (!(/**/(*GetWorkNP(arg_0))->Get_int_unk211()<0||/**/(*GetWorkNP(/**/(*GetWorkNP(arg_0))->Get_int_unk211()))->GetWorkType()!=WORKTYPE07)&&!(*GetWorkNP((*GetWorkNP(arg_0))->Get_int_unk211()))->IsFinished()) return;
		if (! (!m_optflag_notConnected__||(*GetWorkNP(arg_0))->Get_int_unk33()!=0) ) {
			m_vectorpCWork_[arg_0]->mf_CWork_0010(true,false);
			m_flgarray_unk[2]=true;
			return;
		}
	unsigned int local_03;
		local_03=GetTickCount();
		if (/**/(*GetWorkNP(arg_0))->IsFinished()||local_03-local_01>200) return;
		if (/**/(*GetWorkNP(arg_0))->GetCountNow()==0) {
			sprintf(local_09,"%s\\*.*",/**/(*GetWorkNP(arg_0))->GetFolderName());
			if (( /**/(*GetWorkNP(arg_0))->m_ffresult__ = _findfirst(local_09,&(m_vectorpCWork_[arg_0]->m_finddata_)) )>=0) {
				if (! ((int)*/**/(*GetWorkNP(arg_0))->m_finddata_.name==64||!(/**/(*GetWorkNP(arg_0))->Get_int_unk33()<=0)&&/**/(*GetWorkNP(arg_0))->m_finddata_.size==0||((*((char *)(&/**/(*GetWorkNP(arg_0))->m_finddata_.attrib))&16)!=0||(*((char *)(&/**/(*GetWorkNP(arg_0))->m_finddata_.attrib))&2)!=0||strcmp(/**/(*GetWorkNP(arg_0))->m_finddata_.name,".")==0||strcmp(/**/(*GetWorkNP(arg_0))->m_finddata_.name,"..")==0)||!(/**/(*GetWorkNP(arg_0))->Get_int_unk33()!=0)&&/**/(*GetWorkNP(arg_0))->m_finddata_.size>0x00100000) ) {
					if (/**/(*GetWorkNP(arg_0))->Get_int_unk33()>=0) {
int						local_05=mf_CMainControl_0610();
						/**/(*GetWorkNP(arg_0))->Set_int_unk211(local_05);
						m_vectorpCWork_[local_05]->mf_CWork_0150(/**/(*GetWorkNP(arg_0))->Get_char16_unk301(),/**/(*GetWorkNP(arg_0))->Get_int_unk33());
						/**/(*GetWorkNP(local_05))->m_finddata_=/**/(*GetWorkNP(arg_0))->m_finddata_;
					} else {
						mf_CMainControl_0470(&/**/(*GetWorkNP(arg_0))->m_finddata_,/**/(*GetWorkNP(arg_0))->Get_int_unk33()==0);
					}
				}
CWork *				local_06=m_vectorpCWork_[arg_0];
				local_06->m_uint_countNow=local_06->m_uint_countNow+1;
			} else {
				_findclose(/**/(*GetWorkNP(arg_0))->m_ffresult__);
				m_vectorpCWork_[arg_0]->mf_CWork_0010(true,false);
				m_flgarray_unk[2]=true;
			}
		} else {
			if (_findnext(/**/(*GetWorkNP(arg_0))->m_ffresult__,&/**/(*GetWorkNP(arg_0))->m_finddata_)==0) {
				if (! ((int)*/**/(*GetWorkNP(arg_0))->m_finddata_.name==64||!(/**/(*GetWorkNP(arg_0))->Get_int_unk33()<=0)&&/**/(*GetWorkNP(arg_0))->m_finddata_.size==0||((*((char *)(&/**/(*GetWorkNP(arg_0))->m_finddata_.attrib))&16)!=0||(*((char *)(&/**/(*GetWorkNP(arg_0))->m_finddata_.attrib))&2)!=0||strcmp(/**/(*GetWorkNP(arg_0))->m_finddata_.name,".")==0||strcmp(/**/(*GetWorkNP(arg_0))->m_finddata_.name,"..")==0)||!(/**/(*GetWorkNP(arg_0))->Get_int_unk33()!=0)&&/**/(*GetWorkNP(arg_0))->m_finddata_.size>0x00100000) ) {
					if (/**/(*GetWorkNP(arg_0))->Get_int_unk33()>=0) {
int						local_07=mf_CMainControl_0610();
						/**/(*GetWorkNP(arg_0))->Set_int_unk211(local_07);
						m_vectorpCWork_[local_07]->mf_CWork_0150(/**/(*GetWorkNP(arg_0))->Get_char16_unk301(),/**/(*GetWorkNP(arg_0))->Get_int_unk33());
						/**/(*GetWorkNP(local_07))->m_finddata_=/**/(*GetWorkNP(arg_0))->m_finddata_;
					} else {
						mf_CMainControl_0470(&/**/(*GetWorkNP(arg_0))->m_finddata_,/**/(*GetWorkNP(arg_0))->Get_int_unk33()==0);
					}
				}
CWork*				local_08=m_vectorpCWork_[arg_0];
				local_08->m_uint_countNow=local_08->m_uint_countNow+1;
			} else {
				_findclose(/**/(*GetWorkNP(arg_0))->m_ffresult__);
				m_vectorpCWork_[arg_0]->mf_CWork_0010(true,false);
				m_flgarray_unk[2]=true;
			}
		}
		local_02=local_02+1;
	} while (local_02<local_00);
	return;
}


inline int blockcount(int local_06) {
	int local_07;
	local_07=(local_06/0x00010000);
	if (! (!(local_06==0)&&local_06%0x00010000==0) ) {
		local_07=local_07+1;
	}
	return local_07;
}


void CMainControl::mf_CMainControl_0450(int arg_0)
{
	CWork * local_05=GetWorkUnya(arg_0);
	int	local_06=local_05->m_finddata_.size;
	int local_07;
	local_07=(unsigned int)(local_06/0x00010000);
	if (! (!(local_06==0)&&local_06%0x00010000==0) ) {
		local_07=local_07+1;
	}
	if (! (!((int)*local_05->m_finddata_.name==64)&&(int)*local_05->m_finddata_.name!=37) ) {
		local_05->mf_CWork_0010(true,false);
		return;
	}

	time_t local_08;
	int local_09;
	bool local_10;
	CKey * local_11;
	unsigned char local_28[16];
	char local_29[16];
	char local_30[36];	//本来は[20]と[16]な模様

	time(&local_08);
	local_09=local_05->m_uint_countNow;
	if (local_09>=local_07) {
		local_05->mf_CWork_0010(true,false);
		MD5final(local_28,&local_05->m_md5ctx);
		local_11=mf_CMainControl_0600(false,local_05->m_finddata_.name,strlen(local_05->m_finddata_.name),local_06,local_28,2,&local_10,local_05->m_char16_unk301,local_05->m_int_unk33,false,0,0);
		if (local_11==0) {
			local_05->mf_CWork_0010(true,false);
			return;
		}
		_unlink(local_11->mf_CKey_0210().c_str());
		local_11->mf_CKey_0130();
		memcpy((unsigned char *)local_11->m_hash_tabun,local_28,16);
		local_11->m_int_unk0x=1;
		local_11->m_char_keyType_=KEYTYPE02;
		local_11->Set_char11_nazo2(local_05->m_char16_unk301);
		local_11->Set_int_unk16(local_05->m_int_unk33);
		local_11->mf_CKey_0070(local_05->m_finddata_.name,strlen(local_05->m_finddata_.name),false);
		local_11->Set_bln_unk314(true);
		time_t local_12;
		local_12=local_08-rand()%10000;
		if (local_12<local_05->m_finddata_.time_write) {
			local_12=local_05->m_finddata_.time_write;
		}
		local_11->Set_time(local_12);
		local_11->SetRefs(rand()%1000+10);
		local_11->mf_CKey_0110();
		if (!local_10) {
			m_int_numberOfUpFile_=m_int_numberOfUpFile_+1;
		}
		GetFolderUnya(local_05->m_int_unk33)->AddFileSize(local_06);
		mf_CMainControl_0580(local_11);
		return;
	}

	FILE * local_15;
	local_15=NULLPO;
	CKey local_00;
	local_00.mf_CKey_0060();
	local_00.m_char_keyType_=KEYTYPE02;

	local_00.Set_char11_nazo2(local_05->m_char16_unk301);
	local_00.Set_int_unk16(local_05->m_int_unk33);

	local_00.mf_CKey_0070(local_05->m_finddata_.name,strlen(local_05->m_finddata_.name),false);
	memset(local_29,0,16);
	if (! (local_09!=0||local_05->m_int_unk33<=0) ) {
		multimap<unsigned int,CKey>::iterator local_16;
		for (local_16=m_KeyBuffer_.begin(); local_16!=m_KeyBuffer_.end(); local_16++) {
			CKey * local_17=&local_16->second;
			if (local_17->m_int_unk0x==0||!local_17->m_bln_unk302||local_17->m_bln_unk308) continue;
			local_17->mf_CKey_0280(gbuf20000_hatena1,false);
			if (local_17->m_bln_unk308||local_17->m_int_unk203!=5
			  ||memcmp((unsigned char *)local_17->m_hash_tabun,local_29,16)==0
			  ||(unsigned char)gbuf20000_hatena1[0]=='@'
			  ||strcmp(gbuf20000_hatena1,local_05->m_finddata_.name)!=0||local_17->m_uint_unk13!=local_05->m_finddata_.size
			  ||(unsigned int)local_17->m_time_<(unsigned int)local_05->m_finddata_.time_write) continue;

			local_17->mf_CKey_0240(local_05->m_finddata_.size);
			local_17->m_char_keyType_=KEYTYPE02;
			local_17->Set_char11_nazo2(local_05->m_char16_unk301);

			//!!4391df 順序が変かも
			local_17->Set_int_unk16(local_05->m_int_unk33);

			local_17->mf_CKey_0070(local_05->m_finddata_.name,strlen(local_05->m_finddata_.name),false);
			local_17->m_bln_unk314=true;
			if (local_17->m_int_unk0x!=0) {
				m_int_numberOfUpFile_=m_int_numberOfUpFile_+1;
				GetFolderUnya(local_05->m_int_unk33)->AddFileSize(local_05->m_finddata_.size);
				m_flgarray_unk[9]=true;
			}
			local_05->mf_CWork_0010(true,false);
			return;
		}
		MD5init(&local_05->m_md5ctx);
	}
	if (local_05->m_int_unk33==0) {
		if (! (m_int_numberOfBbsUpFile_>=100||m_optflag_notConnected__) ) {
			CKey local_01;
			local_01.mf_CKey_0060();
			local_01.m_bln_unk308=true;
			local_01.m_char_keyType_=KEYTYPE02;
			local_01.mf_CKey_0240(local_05->m_finddata_.size);
			local_01.mf_CKey_0070(local_05->m_finddata_.name,strlen(local_05->m_finddata_.name),false);
			CBbsFile local_02;
			local_02.mf_CBbsFile_0080(local_05->m_finddata_.name);
			if (local_02.mf_CBbsFile_0000(&local_01)) {
				local_02.mf_CBbsFile_0020(&local_01);
			}
			sprintf(gbuf20000_hatena1,"%s\\%s",m_sz_BbsFolderPath_,local_05->m_finddata_.name);
			FILE * local_20=fopen(gbuf20000_hatena1,"rt");
			if (local_20!=0) {
				gbuf20000_hatena1[0]=0;
				fgets(gbuf20000_hatena1,0x00020000,local_20);
				if (strlen(gbuf20000_hatena1)>0) {
					*(gbuf20000_hatena1+strlen(gbuf20000_hatena1)-1)=0;
				}
				fclose(local_20);
				if (strncmp(gbuf20000_hatena1,"WinnyBBS 2.0b1 ",strlen("WinnyBBS 2.0b1 "))==0) {
					*(local_30+0)=0;
					RSA local_03;
					local_03.mf_RSA_0000(strlen("WinnyBBS 2.0b1 ")+gbuf20000_hatena1);
					sprintf(gbuf20000_hatena1,"%11s#%s",local_03.m_szstr,local_05->m_finddata_.name);
					MD5calc(gbuf20000_hatena1,(unsigned char *)(local_30+20),strlen(gbuf20000_hatena1));
					(local_30+20)[3]=(local_30+20)[3]&127;
					int tmp=*((int *)(local_30+20));
					CLongInt local_31=_CLongInt_letint(tmp/* *((int *)(local_30+20))*/);
					char local_32[256];
					bool local_21;
					CKey * local_22;
					local_03.mf_RSA_0050(local_03.mf_RSA_0030(&local_31),local_30);
					local_22=this->mf_CMainControl_0600(false,local_05->m_finddata_.name,strlen(local_05->m_finddata_.name),local_06,(unsigned char *)(local_30+20),2,&local_21,local_05->m_char16_unk301,0,true,0,0);
					if (local_22!=0) {
						CBbsFile local_04;
						local_04.mf_CBbsFile_0080(local_05->m_finddata_.name);
						if (!local_04.mf_CBbsFile_0010(local_22)) {
							local_22->m_int_unk0x=0;
						} else {
							m_flg_IsJoiningBBSCluster_=true;
							strcpy((char *)local_22->m_char16_char11kamo,local_30);
							local_22->Set_char11_nazo2(local_03.m_szstr);
							local_22->m_bln_unk308=true;
							local_22->m_bln_unk314=true;
							local_22->mf_CKey_0120();
							local_22->Set_time(local_05->m_finddata_.time_write);
							mf_CMainControl_0580(local_22);
							m_int_numberOfBbsUpFile_=m_int_numberOfBbsUpFile_+1;
							GetFolderUnya(local_05->m_int_unk33)->AddFileSize(local_05->m_finddata_.size);
							if (m_int_numberOfBbsUpFile_==100) {
								sprintf(local_32,"BBSファイルが多すぎます(最大 %d)",100);
								ny_addlog(local_32);
							}
						}
					}
				}
			}
		}
		local_05->mf_CWork_0010(false,false);
		return;
	}
	local_15=fopen(local_00.mf_CKey_0230().c_str(),"rb");
	if (local_15==0) {
		local_05->mf_CWork_0010(false,false);
		return;
	}
	fseek(local_15,local_09<<16,0);

	unsigned int	local_25=GetTickCount();
	for (int local_26=0; local_26<5000; local_26++) {
	int		local_27=fread(gbuf20000_hatena1,1,0x00010000,local_15);
		if (local_27>0) {
			MD5update(&local_05->m_md5ctx,gbuf20000_hatena1,local_27);
			local_09=local_09+1;
			local_05->SetCountNow(local_09);
			if (local_09>=local_07) break;
		} else {
			local_05->SetCountNow(local_07);
			break;
		}
		unsigned int tmp=GetTickCount();
		if (tmp-local_25>300) break;
	}
	if (local_15!=0) {
		fclose(local_15);
	}
	m_flgarray_unk[2]=true;

	return;
}


void CMainControl::mf_CMainControl_0460()
{
	int local_00;
	local_00=m_vectorpCWork_.size();
	int local_01;
	for (local_01=0; local_01<local_00; local_01++) {
		if (!(/**/(*GetWorkNP(local_01))->GetWorkType()==WORKTYPE04)&&/**/(*GetWorkNP(local_01))->GetWorkType()!=WORKTYPE07) continue;
		m_vectorpCWork_[local_01]->mf_CWork_0010(false,false);
		/**/(*GetWorkNP(local_01))->SetWorkType(WORKTYPE00);
	}
	return;
}



CKey * CMainControl::mf_CMainControl_0470(struct__finddata_t * arg_0,bool arg_1)
{
	CKey * local_00;
	bool local_01;
	CKey * local_02;
	char local_03[1024];
	char local_04[16];
	if (! (!arg_1||strlen(arg_0->name)<=250) ) {
		sprintf(local_03,"名前の長すぎるファイルがあります(%s)",arg_0->name);
		ny_addlog(local_03);
		return NULLPO;
	}
	if (! (!arg_1||m_int_numberOfBbsUpFile_<100) ) {
		return NULLPO;
	}
	local_00=NULLPO;
	memset(local_04,0,16);
	local_02=mf_CMainControl_0600(false,arg_0->name,strlen(arg_0->name),arg_0->size,NULLPO,(arg_1)?2:1,&local_01,"",0,arg_1,0,0);
	if (local_02==0) {
		return NULLPO;
	}
	local_02->m_bln_unk314=true;
	mf_CMainControl_0580(local_02);
	if (! (!local_02->m_bln_unk308||local_02->m_int_unk203==6) ) {
		local_02->m_int_unk0x=0;
		return NULLPO;
	}
	if (! (!(!local_02->m_bln_unk308&&!local_02->mf_CKey_0140())&&(!(local_02->m_int_unk203<4)&&(!local_02->m_bln_unk308||local_02->m_uint_unk13<0x00100000))) ) {
		if (! (!(local_02->m_int_unk203<4)&&(!(!(local_02->m_bln_unk302||local_02->mf_CKey_0150()>=10)&&!local_02->m_bln_unk308)&&memcmp((unsigned char *)local_02->m_hash_tabun,local_04,16)!=0)) ) {
			if ((int)*arg_0->name==37) {
				_unlink(local_02->mf_CKey_0210().c_str());
			}
			local_02->m_int_unk0x=0;
		} else {
			local_02->m_char_keyType_=KEYTYPE01;
			local_00=local_02;
		}
	} else {
		local_00=local_02;
	}
	return local_00;
}


void CMainControl::mf_CMainControl_0480(xint arg_0,int arg_1,bool arg_2)
{
	unsigned int local_01;
	CFolderSorter local_11;
	char local_12[4096];
	char local_13[1024];

	local_01=(unsigned int)m_vectorCFolder_.size();
	vector<CFolderSorter> local_00;

	unsigned int local_02;
	unsigned int local_03;

	local_03=0;
	try {
		for (local_02=0; local_02<local_01; local_02++) {
			if (!GetFolder(local_02)->Get_flg_unk3()) continue;
			local_11.m_uint_unk1=local_02;
			local_11.m_pCFoler=&m_vectorCFolder_[local_02];
			local_11.m_flag_unk3=arg_2;
			local_11.m_int_unk2=arg_1;
			local_11.m_flag_unk3=arg_2;
			local_00.push_back(local_11);
			local_03=local_03+1;
		}
	}
	catch (std::bad_alloc ex_44) {
		return;
	}
	sort(&local_00[1],local_00.end());
	if (local_03>1000) {
		local_03=1000;
	}

	int	local_04=0;
	unsigned int local_05;
	local_03=(unsigned int)local_00.size();
	local_05=(unsigned int)m_vectorInt_.size();
	for (local_02=0; local_02<local_03; local_02++) {
		*((unsigned int *)(g_nazouintarray[arg_0]+local_02))=local_00[local_02].m_uint_unk1;
		CFolder *		local_06=local_00[local_02].m_pCFoler;
		strcpy(local_12,local_06->m__unknown_000.c_str());
		strcpy(g_listitemarray[arg_0][local_04][0],local_12);
		strcpy(local_12,local_06->m__unknown_001.c_str());
		strcpy(g_listitemarray[arg_0][local_04][1],local_12);
		if (strlen(local_06->m__unknown_003.c_str())>0) {
			sprintf(local_12,"%s  (#%s)",local_06->m__unknown_002.c_str(),local_06->m__unknown_003.c_str());
		} else {
			local_12[0]=0;
		}
		strcpy(g_listitemarray[arg_0][local_04][2],local_12);
		sprintf(local_13,"%u",local_06->m_int_unk2);
		ny_sanketacomma(local_13);
		sprintf(local_12,"%s",local_13);
		strcpy(g_listitemarray[arg_0][local_04][3],local_12);
		sprintf(local_12,"%d",local_06->m_int_unk1);
		strcpy(g_listitemarray[arg_0][local_04][4],local_12);
		local_12[0]=0;
		if (! (local_02!=0||m_int_unk16<0) ) {
			strcpy(local_12,"キャッシュフォルダチェック中");
		} else {
			if (local_06->m_flg_unk4) {
				strcpy(local_12,"ハッシュチェック済み");
			} else {
				if (! (local_02>=local_05
				  ||local_00[local_02].m_uint_unk1>=m_vectorInt_.size()
				  ||m_vectorInt_[local_00[local_02].m_uint_unk1]<0) ) {
					int local_07=m_vectorInt_[local_00[local_02].m_uint_unk1];
					if (! (m_vectorInt_.size()<=local_07||/**/(*GetWorkNP(local_07))->GetWorkType()!=WORKTYPE04) ) {
						if (!/**/(*GetWorkNP(local_07))->IsFinished()) {
							int local_08=/**/(*GetWorkNP(local_07))->Get_int_unk211();
							if (! (local_08<0||/**/(*GetWorkNP(local_08))->GetWorkType()!=WORKTYPE07) ) {
								int local_09=/**/(*GetWorkNP(local_08))->m_finddata_.size;
								int local_10=local_09/0x00010000;
								if (! (!(local_09==0)&&local_09%0x00010000==0) ) {
									local_10=local_10+1;
								}
								int tmp2=(int)((double)((int)/**/(*GetWorkNP(local_08))->GetCountNow())*100.0/(double)local_10);
								sprintf(local_12,"チェック中 %d%% (%s)",tmp2,/**/(*GetWorkNP(local_08))->m_finddata_.name);
							} else {
								strcpy(local_12,"チェック中");
							}
						} else {
							strcpy(local_12,"ハッシュチェック終了");
						}
					}
				}
			}
		}
		strcpy(g_listitemarray[arg_0][local_04][5],local_12);
		local_04=local_04+1;
		if (local_04>=1000) break;
	}
	g_intarray2[arg_0]=local_04;
	return;
}


//ぐちゃぐちゃなので要確認
void CMainControl::mf_CMainControl_0490(xint arg_0,const char * arg_1,const char * arg_2,int arg_3,bool arg_4)
{
	try {
		vector<CKeySorter> local_00;
		local_00.resize(500);
		int local_01;
		int local_02;
		local_02=0;
		char local_19[1024];
		if (strlen(arg_1)>=2) {
			unsigned short local_03=mf_CMainControl_0590(arg_1);
			if (local_03==0||m_KeySearchTable_.count(local_03)!=0) {
				multimap<unsigned short,unsigned int>::iterator local_04;
				if (local_03!=0) {
					local_04=m_KeySearchTable_.find(local_03);
				}
				while (true) {
					if (!(local_03==0)&&local_04==m_KeySearchTable_.end()) break;
					unsigned int local_05=0;
					if (local_03!=0) {
						if (local_04->first!=local_03) break;
						local_05=local_04->second;
					}
					if (local_03==0||m_KeyBuffer_.count(local_05)!=0) {
						multimap<unsigned int,CKey>::iterator local_06;
						if (local_03!=0) {
							local_06=m_KeyBuffer_.find(local_05);
						} else {
							local_06=m_KeyBuffer_.begin();
						}
						for (; local_06!=m_KeyBuffer_.end(); local_06++) {
							CKey * local_07=&local_06->second;
							if (local_07->m_int_unk0x==0) continue;
							if (!(local_03==0)&&*((int *)local_07->m_hash_tabun)!=local_05) break;
							if (m_flg_unk15462) {
								local_07->m_bln_unk303=false;
								local_07->m_bln_unk304=false;
							}
							local_00[local_02].m_int_unk0=local_02;
							if ((
							  (local_07->m_bln_unk308
							   ||!m_optflg_displayUpFile_&&local_07->m_char_keyType_==KEYTYPE02
							   ||!m_optflg_displayCacheFile_&&local_07->m_char_keyType_==KEYTYPE03
							   ||!(!m_optflg_V4CacheNotDown_)&&local_07->m_int_unk203==4
							  )||(!mf_CMainControl_1180(local_07)&&local_07->m_bln_unk302
							  ||!(local_07->m_char_keyType_>0)&&local_07->m_int_unk200<2
							  ||!(local_07->m_int_unk203==4)&&local_07->m_int_unk203!=5))
							  ||!(m_optflg_displayTmpCacheFile_||local_07->m_char_keyType_!=KEYTYPE01)
							  &&!mf_CMainControl_1180(local_07)
							  ) continue;
							local_07->m_bln_unk303=false;
							local_07->m_bln_unk304=false;
							if ( !(local_07->mf_CKey_0040(arg_1,arg_2,false)) ) continue;
							local_19[0]=0;
							strcpy(local_19,local_07->mf_CKey_0260());
							local_19[260]=0;
							if ((unsigned char)local_19[0]=='@'||local_19[0]==0) continue;
							if (m_optflg_searchIgnore_) {
								local_07->m_bln_unk303=false;
								local_07->m_bln_unk304=false;
								unsigned int local_08=0;
								for (local_08=0; m_IgnoreCondition_.size()>local_08; local_08++) {
									CAutoDownList * local_09=&m_IgnoreCondition_[local_08];
									if (!(local_09->m_double_unk9<=0.0)&&(double)local_07->m_uint_unk13*(float)9.5367432e-007>local_09->m_double_unk9||!(local_09->m_double_unk10<=0.0)&&(double)local_07->m_uint_unk13*(float)9.5367432e-007<local_09->m_double_unk10||!(!local_09->m_flag_unk5)&&!local_07->m_bln_unk308||!local_09->m_flag_unk5&&local_07->m_bln_unk308) continue;
									if (local_09->mf_CAutoDownList_0010()) {
										if (memcmp(local_09->m_hash,(unsigned char *)local_07->m_hash_tabun,16)!=0) continue;
										break;
									}
									if (strlen(local_09->m_char256_unk1)<2||!local_07->mf_CKey_0040(local_09->m_char256_unk1,local_09->m_char256_unk2,true)) continue;
									break;
								}
								if (m_IgnoreCondition_.size()>local_08) continue;
							}
							strcpy(local_00[local_02].m_szstr_unk1,local_19);

							local_00[local_02].m_double_unk2=(double)(local_07->m_uint_unk204^0x98765432)*((local_07->m_bln_unk313&&m_unknown_001_70)?-1.0:1.0);

							local_00[local_02].m_pCKey=local_07;
							local_00[local_02].m_int_unk3=arg_3;
							local_00[local_02].m_flag_unk4=arg_4;
							local_02=local_02+1;
							if (local_00.size()<=local_02) {
								local_00.resize(local_02+500);
							}
						}
					}
					if (local_03==0) break;
					local_04++;
				}
			}
		}
		local_00.resize(local_02);
		sort(local_00.begin(),local_00.end());

		int local_10;
		int local_11;
		local_10=0;
		for (local_01=0; local_01<local_02; local_01++) {
			int local_12=5;
			if (local_12>local_02) {
				local_12=local_02;
			}
			for (local_11=0; local_11<local_12; local_11++) {
				if (!(local_01<=local_11)&&local_00[local_01].m_pCKey==local_00[(local_01-local_11)-1].m_pCKey) break;
			}
			if (local_11<local_12) {
				local_00[local_01].m_int_unk0=-1;
				continue;
			}
			local_10=local_10+1;
		}
		m_int_unk17=local_10;
		if (local_10>1000) {
			local_10=1000;
		}
		time_t tmptime;
		int local_13=0;
		for (local_01=0; local_01<local_02; local_01++) {
			if (local_00[local_01].m_int_unk0<0) continue;
			CKey * local_14=local_00[local_01].m_pCKey;
			g_nazouintarray[arg_0][local_13]=local_00[local_01].m_int_unk0;
			g_nazocharbuf[arg_0][local_13]=(char)local_14->m_bln_unk313;
			g_KeyBlocks[arg_0][local_13].m_char_unk1=1;
			g_KeyBlocks[arg_0][local_13].m_char_unk0=local_14->m_char_keyType_;
			g_KeyBlocks[arg_0][local_13].m_int_unk3=local_14->mf_CKey_0150();
			(unsigned int)g_KeyBlocks[arg_0][local_13].m_int_unk2=local_14->mf_CKey_0170();

			char local_20[4096];
			char local_21[1024];
			strcpy(local_20,arg_2);
			if ((unsigned char)g_KeyBlocks[arg_0][local_13].m_char_unk0==1) {
				if (g_KeyBlocks[arg_0][local_13].m_pchar_unk4!=0) {
					free(g_KeyBlocks[arg_0][local_13].m_pchar_unk4);
				}
				int local_15=g_KeyBlocks[arg_0][local_13].m_int_unk2;
				g_KeyBlocks[arg_0][local_13].m_pchar_unk4=(char *)malloc(local_15);
				for (int local_16=0; local_16<local_15; local_16++) {
					*((unsigned char *)(g_KeyBlocks[arg_0][local_13].m_pchar_unk4+local_16))=local_14->mf_CKey_0190(local_16);
				}
			}
			strcpy(local_20,local_00[local_01].m_szstr_unk1);
			strcpy(g_listitemarray[arg_0][local_13][0],local_20);
			strcpy(local_20,local_14->mf_CKey_0000());
			strcpy(g_listitemarray[arg_0][local_13][1],local_20);
			sprintf(local_21,"%u",local_14->m_uint_unk13);
			ny_sanketacomma(local_21);
			sprintf(local_20,"%s",local_21);
			strcpy(g_listitemarray[arg_0][local_13][2],local_20);
			strcpy(g_listitemarray[arg_0][local_13][3],"");
			local_20[0]=0;
			switch (local_14->m_char_keyType_) {
			case KEYTYPE00:
				sprintf(local_20,"仮想ファイル");
				break;
			case KEYTYPE02:
				sprintf(local_20,"UPフォルダ内");
				break;
			case KEYTYPE01:
				if (!mf_CMainControl_1180(local_14)) {
					sprintf(local_20,"部分キャッシュ");
					break;
				}
				sprintf(local_20,"受可キャッシュ");
				break;
			case KEYTYPE03:
				sprintf(local_20,"完全キャッシュ");
			}
			strcpy(g_listitemarray[arg_0][local_13][4],local_20);
			if (local_14->mf_CKey_0170()==0) {
				local_20[0]=0;
			} else {
				sprintf(local_20,"%d",(local_14->m_uint_unk204^0x98765432)>>4);
				ny_sanketacomma(local_20);
			}
			sprintf(g_listitemarray[arg_0][local_13][5],"%c %s",(int)(!(!local_14->m_bln_unk313)?'?':' '),local_20);
			tmptime=local_14->m_time_;
			ny_unknown_0010(local_20,tmptime);
			strcpy(g_listitemarray[arg_0][local_13][6],local_20);
			sprintf(local_20,"%8.3f",(double)local_14->m_float_unk15);
			strcpy(g_listitemarray[arg_0][local_13][7],local_20);
			sprintf(local_20,"%d",local_14->m_int_unk203);
			strcpy(g_listitemarray[arg_0][local_13][8],local_20);
			local_20[0]=0;

			int dummy;
			char local_17[8];
			for (int local_18=0; local_18<16; local_18++) {
				sprintf(local_17,"%02x",(unsigned int)local_14->m_hash_tabun[local_18]);
				strcat(local_20,local_17);
			}
			strcpy(g_listitemarray[arg_0][local_13][9],local_20);
			local_13=local_13+1;
			if (local_13>=1000) break;
		}
		m_flg_unk15462=false;
		g_intarray2[arg_0]=local_13;
	}
	catch (std::bad_alloc ex_8) {
		return;
	}
	return;
}


inline CBoardSorter* getptr_boardsorter(vector<CBoardSorter> &V,unsigned int idx) {
	return (CBoardSorter*) ( (idx*576)+(unsigned int)(V.begin()) );
}


void CMainControl::mf_CMainControl_0500(xint arg_0,const char * arg_1,int arg_2,bool arg_3)
{
	try {
		vector<CBoardSorter> local_00;
		local_00.resize(500);
		int local_01;
		bool local_02;
		local_02=false;
		char local_21[1024];
		char local_22[1024];
		if (memcmp(arg_1,"[BBS_",5)==0) {
			strcpy(local_21,arg_1+5);
		} else {
			strcpy(local_21,arg_1);
			local_02=true;
		}
		int local_03=0;
		unsigned short local_04=mf_CMainControl_0590(local_21);
		if ( (local_04==0 || m_KeySearchTable_.count(local_04)!=0) ) {
			multimap<unsigned short,unsigned int>::iterator local_05;
			if (local_04!=0) {
				local_05=m_KeySearchTable_.find(local_04);
			}
			while (true) {
				if (!(local_04==0)&&local_05==m_KeySearchTable_.end()) break;
				unsigned int local_06=0;
				if (local_04!=0) {
					if (local_05->first!=local_04) break;
					local_06=local_05->second;
				}
				if ( (local_04==0 || m_KeyBuffer_.count(local_06)!=0) ) {
					multimap<unsigned int,CKey>::iterator local_07;
					if (local_04!=0) {
						local_07=m_KeyBuffer_.find(local_06);
					} else {
						local_07=m_KeyBuffer_.begin();
					}
					for (; local_07!=m_KeyBuffer_.end(); local_07++) {
						CKey * local_08=&local_07->second;
						if (local_08->m_int_unk0x==0) continue;
						if (!(local_04==0)&&*((int *)local_08->m_hash_tabun)!=local_06) break;
						if (m_flg_unk15462) {
							local_08->m_bln_unk303=false;
							local_08->m_bln_unk304=false;
						}
						getptr_boardsorter(local_00,local_03)->m_int_unk4=local_03;
						if ( (!local_08->m_bln_unk308 || !m_optflg_displayNonWritableBbs_ && !mf_CMainControl_1190(local_08) || (!mf_CMainControl_1180(local_08)&&local_08->m_bln_unk302 || !(local_08->mf_CKey_0040(arg_1,"",false)))) ) continue;
						local_22[0]=0;
						strcpy(local_22,local_08->mf_CKey_0260());
						if ( !local_02&&memcmp(local_22,arg_1,strlen(arg_1))!=0||((unsigned char)local_22[0]=='@'||local_22[0]==0||strncmp(local_22,"[BBS_",5)!=0) ) continue;
						if (m_optflg_searchIgnore_) {
							local_08->m_bln_unk303=false;
							local_08->m_bln_unk304=false;
							unsigned int local_09=0;
							for (local_09=0; m_IgnoreCondition_.size()>local_09; local_09++) {
								CAutoDownList * local_10=&m_IgnoreCondition_[local_09];
								if (!(local_10->m_double_unk9<=0.0)&&(double)local_08->m_uint_unk13*(float)9.5367432e-007>local_10->m_double_unk9||!(local_10->m_double_unk10<=0.0)&&(double)local_08->m_uint_unk13*(float)9.5367432e-007<local_10->m_double_unk10||!(!local_10->m_flag_unk5)&&!local_08->m_bln_unk308||!local_10->m_flag_unk5&&local_08->m_bln_unk308) continue;
								if (local_10->mf_CAutoDownList_0010()) {
									if (memcmp((unsigned char *)local_10->m_hash,(unsigned char *)local_08->m_hash_tabun,16)!=0) continue;
									break;
								}
								if (strlen(local_10->m_char256_unk1)<2||!local_08->mf_CKey_0040(local_10->m_char256_unk1,local_10->m_char256_unk2,true)) continue;
								break;
							}
							if (m_IgnoreCondition_.size()>local_09) continue;
						}
						char * local_11=local_22+5;
						while (!(*local_11==0)&&(unsigned char)*local_11!=']') {
							if (! (!ny_iskanji(*local_11)||*(local_11+1)==0) ) {
								local_11=local_11+2;
							} else {
								local_11=local_11+1;
							}
						}
						if (*local_11!=0) {
							char * local_12=local_11;
							for (local_11=local_11+1; (unsigned char)*local_11==' '; local_11++) {
							}
							strcpy(getptr_boardsorter(local_00,local_03)->m_szstr_unk1,local_11);
							*local_12=0;
							strcpy(getptr_boardsorter(local_00,local_03)->m_char48_unk6,&local_22[5]);
							getptr_boardsorter(local_00,local_03)->m_double_unk2=(double)(local_08->m_uint_unk204^0x98765432);
							getptr_boardsorter(local_00,local_03)->m_pCKey=local_08;
							getptr_boardsorter(local_00,local_03)->m_int_unk3=5;
							getptr_boardsorter(local_00,local_03)->m_flag_unk4=false;
							local_03=local_03+1;
							if (local_00.size()<=local_03) {
								local_00.resize(local_03+500);
							}
						}
					}
				}
				if (local_04==0) break;
				local_05++;
			}
		}
		local_00.resize(local_03);
		sort(local_00.begin(),local_00.end());

		int local_13=0;
		int local_14;
		for (local_01=0; local_01<local_03; local_01++) {
			int local_15=5;
			if (local_15>local_03) {
				local_15=local_03;
			}
			for (local_14=0; local_14<local_15; local_14++) {
				if (!(local_01<=local_14)&&local_00[local_01].m_pCKey==local_00[(local_01-local_14)-1].m_pCKey) break;
			}
			if (local_14<local_15) {
				local_00[local_01].m_int_unk4=-1;
				continue;
			}
			local_13=local_13+1;
		}
		m_int_unk17=local_13;
		int local_16=1;
		for (local_01=0; local_01<local_03; local_01++) {
			if (local_00[local_01].m_int_unk4>=0) {
				local_00[local_01].m_int_unk5=local_16;
				local_16=local_16+1;
			}
			local_00[local_01].m_int_unk3=arg_2;
			local_00[local_01].m_flag_unk4=arg_3;
		}
		sort(local_00.begin(),local_00.end());
		if (local_13>1000) {
			local_13=1000;
		}

		time_t tmptime;
		int local_17=0;
		for (local_01=0; local_01<local_03; local_01++) {
			if (local_00[local_01].m_int_unk4<0) continue;
			g_nazouintarray[arg_0][local_17]=local_00[local_01].m_int_unk4;
			CKey* local_18=local_00[local_01].m_pCKey;
			g_nazocharbuf[arg_0][local_17]=(char)local_18->m_bln_unk313;
			char local_23[4096];
			char local_24[1024];
			local_23[0]=0;
			switch (local_18->m_char_keyType_) {
			case KEYTYPE00:
				sprintf(local_23," ");
				break;
			case KEYTYPE02:
				sprintf(local_23,"自");
				break;
			case KEYTYPE01:
				if (!mf_CMainControl_1190(local_18)) {
					sprintf(local_23,"読");
					break;
				}
				if (local_18->m_bln_unk301) {
					sprintf(local_23,"新");
					break;
				}
				sprintf(local_23,"書");
				break;
			case KEYTYPE03:
				if (local_18->m_bln_unk302) {
					sprintf(local_23,"自");
					break;
				}
				if (mf_CMainControl_1190(local_18)) {
					if (local_18->m_bln_unk301) {
						sprintf(local_23,"新");
						break;
					}
					sprintf(local_23,"書");
					break;
				}
				sprintf(local_23,"読");
			}
			strcpy(g_listitemarray[arg_0][local_17][0],local_23);
			sprintf(local_23,"%d",local_00[local_01].m_int_unk5);
			sprintf(g_listitemarray[arg_0][local_17][1],local_23);
			strcpy(local_23,local_00[local_01].m_szstr_unk1);
			strcpy(g_listitemarray[arg_0][local_17][2],local_23);
			sprintf(local_23,"%d",local_18->m_uint_unk204^0x98765432);
			sprintf(g_listitemarray[arg_0][local_17][3],local_23);
			strcpy(g_listitemarray[arg_0][local_17][4],local_00[local_01].m_char48_unk6);
			tmptime=local_18->m_time_;
			ny_unknown_0010(local_23,tmptime);
			strcpy(g_listitemarray[arg_0][local_17][5],local_23);
			strcpy(local_23,local_18->mf_CKey_0000());
			strcpy(g_listitemarray[arg_0][local_17][6],local_23);
			sprintf(local_24,"%u",local_18->m_uint_unk13);
			ny_sanketacomma(local_24);
			sprintf(local_23,"%s",local_24);
			strcpy(g_listitemarray[arg_0][local_17][7],local_23);
			local_23[0]=0;
			int notused;
			char local_19[8];
			for (int local_20=0; local_20<16; local_20++) {
				sprintf(local_19,"%02x",(unsigned int)local_18->m_hash_tabun[local_20]);
				strcat(local_23,local_19);
			}
			strcpy(g_listitemarray[arg_0][local_17][8],local_23);
			local_17=local_17+1;
			if (local_17>=1000) break;
		}
		m_flg_unk15462=false;
		g_intarray2[arg_0]=local_17;
	}
	catch (std::bad_alloc ex_8) {
		return;
	}
	return;
}


inline double getpreference2(CMainControl &mc,int idx) {
	return ( mc.m_hostArray[idx].m_int_preference2_positive-(mc.m_hostArray[idx].m_int_preference2_negative<<3) ) /100.0 ;
}
inline double getpreference1(CMainControl &mc,int idx) {
	return (double) mc.m_hostArray[idx].m_int_preference1;
}

void CMainControl::mf_CMainControl_0510(xint arg_0,bool arg_1,int arg_2,bool arg_3)
{
	try {
		unsigned int local_01;
		unsigned int local_02;
		vector<CHostSorter> local_00;
		unsigned int local_03=0;
		for (local_01=1; local_01<600; local_01++) {
			if (!m_hostArray[local_01].m_flgIsValid||m_hostArray[local_01].m_flgUnknown_7F||m_hostArray[local_01].m_flgIsBBSNode_8!=arg_1) continue;
			local_03=local_03+1;
		}
		local_00.resize(local_03);
		local_03=0;
		for (local_01=1; local_01<600; local_01++) {
			if (!m_hostArray[local_01].m_flgIsValid||m_hostArray[local_01].m_flgUnknown_7F||m_hostArray[local_01].m_flgIsBBSNode_8!=arg_1) continue;
			local_00[local_03].m_int_unk00=local_01;
			local_00[local_03].m_int_unk01=m_hostArray[local_01].m_int_connectionTimeInSec;
			local_00[local_03].m_int_unk07=m_hostArray[local_01].m_int_version;
			local_00[local_03].m_int_unk02=m_hostArray[local_01].m_int_nodataTimeInSec;
			if (m_hostArray[local_01].m_flgIsConnected) {
				local_00[local_03].m_int_unk04=(int)(char)m_hostArray[local_01].m_flg_isDownConnection;
			} else {
				local_00[local_03].m_int_unk04=-1;
			}
			if (m_hostArray[local_01].m_field_8E) {
				local_00[local_03].m_int_unk03=3;
			} else {
				if (!m_hostArray[local_01].m_flgIsConnected) {
					local_00[local_03].m_int_unk03=2;
				} else {
					if (m_hostArray[local_01].m_flgIsTransferLink_8) {
						local_00[local_03].m_int_unk03=1;
					} else {
						local_00[local_03].m_int_unk03=0;
					}
				}
			}
			if (m_hostArray[local_01].m_int_lineSpeed>0) {
				if (m_hostArray[local_01].m_field_94) {
					local_00[local_03].m_int_unk05=8;
				} else {
					if (m_hostArray[local_01].m_field_82) {
						local_00[local_03].m_int_unk05=7;
					} else {
						if (m_hostArray[local_01].m_flgIgnoredWarning_8) {
							local_00[local_03].m_int_unk05=6;
						} else {
							if (m_hostArray[local_01].m_flgNetsuzouWarning_8) {
								local_00[local_03].m_int_unk05=5;
							} else {
								if (m_hostArray[local_01].m_flgIsBadPortZero_9) {
									local_00[local_03].m_int_unk05=4;
								} else {
									if (m_hostArray[local_01].m_flgIsPortZero_9) {
										local_00[local_03].m_int_unk05=3;
									} else {
										if ((m_hostArray+local_01)->m_str_DDNSname.Length()!=0) {
											local_00[local_03].m_int_unk05=2;
										} else {
											if (m_hostArray[local_01].m_flgIsNAT) {
												local_00[local_03].m_int_unk05=1;
											} else {
												local_00[local_03].m_int_unk05=0;
											}
										}
									}
								}
							}
						}
					}
				}
			}
			local_00[local_03].m_int_unk06=m_hostArray[local_01].m_int_lineSpeed;
			local_00[local_03].m_CHost_unk2=m_hostArray+local_01;
			local_00[local_03].m_float_unk1=
				getpreference1(*this,local_01)
				+getpreference2(*this,local_01);  //結局微妙に再現できていない。どうやってるんだ？
			local_00[local_03].m_int_unk3=arg_2;
			local_00[local_03].m_bool_unk4=arg_3;
			local_03=local_03+1;
			if (local_00.size()<=local_03) break;
		}
		sort(local_00.begin(),local_00.end());
		if (local_03>1000) {
			local_03=1000;
		}
		int local_04=0;
		char local_08[4096];
		for (local_02=0; local_02<local_03; local_02++) {
			local_01=local_00[local_02].m_int_unk00;
			if (!m_hostArray[local_01].m_flgIsValid) continue;
			g_nazouintarray[arg_0][local_04]=local_01;
			if (m_hostArray[local_01].m_flg_IsBBSPort) {
				sprintf(local_08,"BBS Port");
			} else {
				if (m_hostArray[local_01].m_flgIsBBSConnectionTest) {
					sprintf(local_08,"BBS接続テスト");
				} else {
					if (! (m_hostArray[local_01].m_flgUnknown_80||!m_hostArray[local_01].m_flgIsConnected) ) {
						sprintf(local_08,"接続テスト");
					} else {
						if (m_hostArray[local_01].m_field_8E) {
							sprintf(local_08,"検索中");
						} else {
							if (!m_hostArray[local_01].m_flgIsConnected) {
								sprintf(local_08,"待機");
							} else {
								if (m_hostArray[local_01].m_flgIsTransferLink_8) {
									sprintf(local_08,"転送リンク");
								} else {
									if (arg_1) {
										sprintf(local_08,"BBS検索リンク");
									} else {
										sprintf(local_08,"検索リンク");
									}
								}
							}
						}
					}
				}
			}
			strcpy(g_listitemarray[arg_0][local_04][0],local_08);
			local_08[0]=0;
			if (m_hostArray[local_01].m_flgIsConnected) {
				switch (m_hostArray[local_01].m_flg_isDownConnection) {
				case 0:
					if (! (!m_hostArray[local_01].m_flgIsTransferLink_8||!m_hostArray[local_01].m_flgIsTransferProxy_8) ) {
						sprintf(local_08,"上流 (転送)");
						break;
					}
					sprintf(local_08,"上流");
					break;
				case 1:
					if (! (!m_hostArray[local_01].m_flgIsTransferLink_8||!m_hostArray[local_01].m_flgIsTransferProxy_8) ) {
						sprintf(local_08,"下流 (転送)");
						break;
					}
					sprintf(local_08,"下流");
					break;
				case 3:
					sprintf(local_08,"右側");
					break;
				case 2:
					sprintf(local_08,"左側");
				}
			}
			strcpy(g_listitemarray[arg_0][local_04][1],local_08);
			local_08[0]=0;
			if (m_hostArray[local_01].m_int_lineSpeed>0) {
				sprintf(local_08,"%d",m_hostArray[local_01].m_int_lineSpeed);
			}
			strcpy(g_listitemarray[arg_0][local_04][2],local_08);
			local_08[0]=0;
			if (m_hostArray[local_01].m_int_lineSpeed>0) {
				if (m_hostArray[local_01].m_field_94) {
					sprintf(local_08,"ポート警告");
				} else {
					if (m_hostArray[local_01].m_flgIgnoredWarning_8) {
						sprintf(local_08,"無視ノード警告");
					} else {
						if (m_hostArray[local_01].m_flgNetsuzouWarning_8) {
							sprintf(local_08,"捏造警告");
						} else {
							if (m_hostArray[local_01].m_flgIsBadPortZero_9) {
								sprintf(local_08,"BadPort 0");
							} else {
								if (m_hostArray[local_01].m_flgIsPortZero_9) {
									sprintf(local_08,"Port 0");
								} else {
									if ((m_hostArray+local_01)->m_str_DDNSname.Length()!=0) {
										sprintf(local_08,"DDNS");
									} else {
										if (m_hostArray[local_01].m_flgIsNAT) {
											sprintf(local_08,"NAT");
										} else {
											sprintf(local_08,"Raw");
										}
									}
								}
							}
						}
					}
				}
			}
			strcpy(g_listitemarray[arg_0][local_04][3],local_08);
			local_08[0]=0;
			int local_05=m_hostArray[local_01].m_int_connectionTimeInSec;
			if (m_hostArray[local_01].m_flgIsConnected) {
				sprintf(local_08,"%d:%02d",local_05/60,local_05%60);
			}
			strcpy(g_listitemarray[arg_0][local_04][4],local_08);
			local_08[0]=0;
			if (m_hostArray[local_01].m_flgIsConnected) {
				int local_06=m_hostArray[local_01].m_int_nodataTimeInSec;
				sprintf(local_08,"%d:%02d",local_06/60,local_06%60);
			}
			strcpy(g_listitemarray[arg_0][local_04][5],local_08);
			local_08[0]=0;
			if (m_hostArray[local_01].m_int_version>0) {
				if (m_hostArray[local_01].m_int_version>=20000) {
					sprintf(local_08,"%g",(double)((double)m_hostArray[local_01].m_int_version/10000.0));
				} else {
					sprintf(local_08,"b%g",(double)((double)(m_hostArray[local_01].m_int_version+-12000)/100.0));
				}
			}
			strcpy(g_listitemarray[arg_0][local_04][6],local_08);
			int local_07=m_hostArray[local_01].m_int_preference2_positive-(m_hostArray[local_01].m_int_preference2_negative<<3);
			if (local_07==0) {
				sprintf(local_08,"%d ( 0 )",m_hostArray[local_01].m_int_preference1);
			} else {
				sprintf(local_08,"%d ( %+d )",m_hostArray[local_01].m_int_preference1,local_07);
			}
			strcpy(g_listitemarray[arg_0][local_04][7],local_08);
			local_08[0]=0;
			if (!m_hostArray[local_01].m_flgIsTransferLink_8) {
				sprintf(local_08,"%s %s %s",(m_hostArray+local_01)->m_sz_clusterword[0],(m_hostArray+local_01)->m_sz_clusterword[1],(m_hostArray+local_01)->m_sz_clusterword[2]);
			}
			strcpy(g_listitemarray[arg_0][local_04][8],local_08);
			local_04=local_04+1;
		}
		g_intarray2[arg_0]=local_04;

//!!441b60 ここのvectorのdestructorにあるex sclnが再現できないので、サイズ合わせ
#ifdef EXACTMATCH
	asm nop;
	asm nop;
	asm nop;
	asm nop;
	asm nop;
	asm nop;
#endif

	}
	catch (std::bad_alloc ex_8) {
		return;
	}
	return;
}


void CMainControl::mf_CMainControl_0520(xint arg_0,int arg_1,bool arg_2)
{
	try {
		int local_01;
		int local_02;
		int local_03=m_vectorpCWork_.size();
		vector<CWorkSorter> local_00;
		unsigned int local_04=0;
		local_00.resize(local_03);
		for (local_01=0; local_01<local_03; local_01++) {
			CWork* local_05=m_vectorpCWork_[local_01];
			if (!(local_05->m_worktype_!=WORKTYPE01)&&(local_05->IsValid_hostIdx_mouikko())||!(local_05->m_worktype_!=WORKTYPE03)&&local_05->m_flgkasiraso_3) continue;
			if (! (local_05->m_worktype_<WORKTYPE01||local_05->m_worktype_>WORKTYPE03) ) {
				local_00[local_04].m_int_unk0=local_01;
				local_00[local_04].m_int_unk1=local_05->m_int_unk300;
				local_00[local_04].m_int_unk2=(int)local_05->m_worktype_;
				local_00[local_04].m_pCWork=local_05;
				local_00[local_04].m_int_unk3=arg_1;
				local_00[local_04].m_flag_unk4=arg_2;
				if (! (!local_05->m_flgIsFinished_370||!(local_05->m_worktype_!=WORKTYPE01)&&(!m_flg_unk15509||local_05->m_flgIsSuccessed_371)) ) {
					local_00[local_04].m_int_unk2+=10;
				}
				local_04=local_04+1;
			}
			if (local_00.size()<=local_04) break;
		}
		local_00.resize(local_04);
		sort(local_00.begin(),local_00.end());

		if (local_04>1000) {
			local_04=1000;
		}
		int local_07=0;
		for (unsigned int local_08=0; local_08<local_04; local_08++) {
			int local_09=local_00[local_08].m_int_unk0;
			CWork * local_10=m_vectorpCWork_[local_09];
			int local_11=local_10->m_hostIdx_;
			if (local_10->m_worktype_==WORKTYPE01) {
				CKey* local_12=mf_CMainControl_0180(local_10->m_uint_countMax_,local_10->m_uchar16_unk1);
				if (local_12!=0) {
					if (local_12->m_bln_unk308) continue;
					g_nazocharbuf[arg_0][local_07]=(char)local_12->m_bln_unk313;
				}
			}
			bool local_13=false;
			if (local_10->m_worktype_==WORKTYPE01) {
				for (local_02=0; (int)m_vectorpCWork_.size()>local_02; local_02++) {
					if (local_09==local_02) continue;
					CWork* local_14=m_vectorpCWork_[local_02];
					if (local_14->m_worktype_!=WORKTYPE01||local_14->m_flgIsFinished_370||memcmp(local_10->m_uchar16_unk1,local_14->m_uchar16_unk1,16)!=0) continue;
					local_13=true;
					break;
				}
			}

			char local_16[4096];
			char local_17[4096];
			local_16[0]=0;
			sprintf(local_16,"%s",local_10->m_char256_unk10);
			g_nazouintarray[arg_0][local_07]=local_09;
			strcpy(g_listitemarray[arg_0][local_07][0],local_16);
			if (local_10->m_flgIsFinished_370) {
				if (local_10->m_flgIsSuccessed_371) {
					switch (local_10->m_worktype_) {
					case 5:
						sprintf(local_16,"アップロード失敗");
						break;
					case 1:
						sprintf(local_16,"ダウンロード失敗");
						break;
					case 2:
						sprintf(local_16,"キャッシュに変換失敗");
						break;
					case 3:
						if (local_10->m_flgkasiraso_3) {
							sprintf(local_16,"キャッシュチェック失敗");
							break;
						}
						sprintf(local_16,"キャッシュから変換失敗");
						break;
					}
				} else {
					switch (local_10->m_worktype_) {
					case 5:
						sprintf(local_16,"アップロード済み");
						break;
					case 1:
						sprintf(local_16,"ダウンロード済み");
						break;
					case 2:
						sprintf(local_16,"キャッシュに変換済み");
						break;
					case 3:
						if (local_10->m_flgkasiraso_3) {
							sprintf(local_16,"キャッシュチェック済み");
							break;
						}
						sprintf(local_16,"キャッシュから変換済み");
						break;
					}
				}
			} else {
				if (! (!m_flg_unk15509&&!local_10->m_flgkasiraso_2||local_10->m_flgkasiraso_3||!(local_10->m_worktype_==WORKTYPE02)&&local_10->m_worktype_!=WORKTYPE03) ) {
					sprintf(local_16,"キャッシュ変換保留中");
				} else {
					switch (local_10->m_worktype_) {
					case 5:
						sprintf(local_16,"アップロード中");
						break;
					case 1:
						if (local_13) {
							sprintf(local_16,"多重ダウンロード中");
							break;
						}
						sprintf(local_16,"ダウンロード中");
						break;
					case 2:
						sprintf(local_16,"キャッシュに変換中");
						break;
					case 3:
						if (local_10->m_flgkasiraso_3) {
							sprintf(local_16,"キャッシュチェック中");
							break;
						}
						sprintf(local_16,"キャッシュから変換中");
					}
				}
			}
			strcpy(g_listitemarray[arg_0][local_07][1],local_16);
			local_16[0]=0;
			local_17[0]=0;
			if (local_10->m_flgkasiraso_4) {
				sprintf(local_17,"%u",local_10->m_uint_countNow);
				ny_sanketacomma(local_17);
			}
			if (local_10->m_uint_countMax_>0) {
				sprintf(local_16,"%s / ",local_17);
				sprintf(local_17,"%u",local_10->m_uint_countMax_);
				ny_sanketacomma(local_17);
				strcat(local_16,local_17);
			} else {
				strcpy(local_16,local_17);
			}
			strcpy(g_listitemarray[arg_0][local_07][2],local_16);
			local_16[0]=0;
			if (local_10->m_flg_unk302) {
				sprintf(local_16,"タスク時間切れ");
			} else {
				mf_CMainControl_1580(local_10,local_16);
			}
			if (! (local_16[0]!=0||local_10==0||local_10->m_flgIsFinished_370||local_10->m_uint_countMax_<=0) ) {
				double tmp=(((double)((int)local_10->m_uint_countNow)/(double)local_10->m_uint_countMax_)*10000.0);
				sprintf(local_16," %d",(int)tmp);
			}
			strcpy(g_listitemarray[arg_0][local_07][3],local_16);
			int local_15=(int)local_10->mf_CWork_0060();
			local_16[0]=0;
			if (! (local_10->m_flgIsFinished_370||local_15>= 10000000/*g_listitemarray[0][45][9]+228*/) ) {
				if (local_15<3600) {
					sprintf(local_16,"%d:%02d",local_15/60,local_15%60);
				} else {
					sprintf(local_16,"%d:%02d:%02d",local_15/3600,(local_15%3600)/60,local_15%60);
				}
			}
			strcpy(g_listitemarray[arg_0][local_07][4],local_16);
			local_16[0]=0;
			if (!local_10->m_flgIsFinished_370) {
				if (! (local_11<0||m_hostArray[local_11].m_int_lineSpeed<=0) ) {
					sprintf(local_16,"%7.1f (%dkB/s)",local_10->m_double_unk6,m_hostArray[local_11].m_int_lineSpeed);
				} else {
					sprintf(local_16,"%7.1f",local_10->m_double_unk6);
				}
			}
			strcpy(g_listitemarray[arg_0][local_07][5],local_16);
			local_07=local_07+1;
			if (local_07>=1000) break;
		}
		g_intarray2[arg_0]=local_07;
	}
	catch (std::bad_alloc ex_8) {
		return;
	}
	return;
}


void CMainControl::mf_CMainControl_0530(xint arg_0)
{
	char local_10[4096];
	char local_11[4096];
	int local_00;
	int local_01=0;
	for (local_00=0; m_DownCondition_.size()>local_00; local_00++) {
		if (!GetDownCondition(local_00)->IsValid()) continue;
		local_01=local_01+1;
	}
	if (local_01>1000) {
		local_01=1000;
	}
	int	local_02=0;
	int	local_03=0;
	for (local_00=0; m_DownCondition_.size()>local_00; local_00++) {
		if (!GetDownCondition(local_00)->IsValid()) continue;
		g_nazouintarray[arg_0][local_02]=local_00;
		char local_04=' ';
		if (local_00==m_int_unk18) {
			local_04='-';
		}
		local_10[0]=0;
		if (! (local_03>=3||m_DownCondition_[local_00].mf_CAutoDownList_0010()||strlen(m_DownCondition_[local_00].m_char256_unk1)<=1) ) {
			sprintf(local_10,"%c*%s",(int)local_04,m_DownCondition_[local_00].m_char256_unk1);
			local_03=local_03+1;
		} else {
			int dummy;
			char local_05[8];
			if (GetDownCondition(local_00)->mf_CAutoDownList_0010()) {
				local_11[0]=0;
				for (int local_06=0; local_06<16; local_06++) {
					sprintf(local_05,"%02x",(unsigned int)GetDownCondition(local_00)->GetHash()[local_06]);
					strcat(local_11,local_05);
				}
				sprintf(local_10,"%c%c%s (%s)",(int)local_04,(int)(!(!GetDownCondition(local_00)->Get_flag_unk6())?':':' '),m_DownCondition_[local_00].m_char256_unk1,local_11);
			} else {
				if (strlen(m_DownCondition_[local_00].m_char256_unk1)>1) {
					sprintf(local_10,"%c%c%s",(int)local_04,(int)(!(!GetDownCondition(local_00)->Get_flag_unk6())?':':' '),m_DownCondition_[local_00].m_char256_unk1);
				}
			}
		}
		strcpy(g_listitemarray[arg_0][local_02][0],local_10);
		if (!GetDownCondition(local_00)->Get_flag_unk5()) {
			sprintf(local_10,"%s",m_DownCondition_[local_00].m_char256_unk2);
		} else {
			sprintf(local_10,"BBS");
		}
		strcpy(g_listitemarray[arg_0][local_02][1],local_10);
		sprintf(local_10,"%g - %g",GetDownCondition(local_00)->Get_double_unk10(),GetDownCondition(local_00)->Get_double_unk9());
		strcpy(g_listitemarray[arg_0][local_02][2],local_10);
		sprintf(local_10,"%d",GetDownCondition(local_00)->Get_int_unk20());
		strcpy(g_listitemarray[arg_0][local_02][3],local_10);
		local_10[0]=0;
		int local_07=GetDownCondition(local_00)->Get_int_unk4();
		CKey* local_08=NULLPO;
		if (! (local_07<0||(int)m_vectorpCWork_.size()<=local_07) ) {
			local_08=mf_CMainControl_0180((*GetWorkNP(local_07))->GetCountMax(),(*GetWorkNP(local_07))->Get_uchar16_unk1());
			if (local_08!=0) {
				strcpy(local_10,local_08->mf_CKey_0260());
			}
		} else {
			strcpy(local_10,m_DownCondition_[local_00].m_char256_unk3);
		}
		strcpy(g_listitemarray[arg_0][local_02][4],local_10);
		local_10[0]=0;
		if (local_07>=0) {
			sprintf(local_11,"%u",/**/(*GetWorkNP(local_07))->GetCountNow());
			ny_sanketacomma(local_11);
			if (local_08!=0) {
				sprintf(local_10,"%s / ",local_11);
				sprintf(local_11,"%u",/**/(*GetWorkNP(local_07))->GetCountMax());
				ny_sanketacomma(local_11);
				strcat(local_10,local_11);
			} else {
				strcpy(local_10,local_11);
			}
		} else {
			if (strlen(GetDownCondition(local_00)->m_char256_unk3)>0) {
				sprintf(local_11,"%u",GetDownCondition(local_00)->Get_uint_unk001());
				ny_sanketacomma(local_11);
				sprintf(local_10,"%s / ",local_11);
				sprintf(local_11,"%u",GetDownCondition(local_00)->Get_uint_unk000());
				ny_sanketacomma(local_11);
				strcat(local_10,local_11);
			}
		}
		strcpy(g_listitemarray[arg_0][local_02][5],local_10);
		local_10[0]=0;
		if (local_07<0) {
			if (GetDownCondition(local_00)->Get_int_unk20()!=0) {
				if (! (!(local_08==0)&&local_08->m_int_unk14>=10) ) {
					sprintf(local_10,"ダウン試行待ち");
				} else {
					sprintf(local_10,"連続ダウン制限");
				}
			} else {
				if (GetDownCondition(local_00)->Get_char_unk100_70()!=0) {
					sprintf(local_10,"捏造無視中");
				} else {
					sprintf(local_10,"キー探索中");
				}
			}
		} else {
			if (/**/(*GetWorkNP(local_07))->GetCountMax()>0) {
				double tmp=(((double)((int)/**/(*GetWorkNP(local_07))->GetCountNow())/(double)/**/(*GetWorkNP(local_07))->GetCountMax())*10000.0);
				sprintf(local_10," %d",(int)tmp);
			}
		}
		strcpy(g_listitemarray[arg_0][local_02][6],local_10);
		local_10[0]=0;
		if (local_07>=0) {
			int local_09=(int)m_vectorpCWork_[local_07]->mf_CWork_0060();
			if (local_09<10000000) {
				if (local_09<3600) {
					sprintf(local_10,"%d:%02d",local_09/60,local_09%60);
				} else {
					sprintf(local_10,"%d:%02d:%02d",local_09/3600,(local_09%3600)/60,local_09%60);
				}
			}
		}
		strcpy(g_listitemarray[arg_0][local_02][7],local_10);
		local_10[0]=0;
		if (local_07>=0) {
			sprintf(local_10,"%7.1f",(*GetWorkNP(local_07))->Get_double_unk6());
		}
		strcpy(g_listitemarray[arg_0][local_02][8],local_10);
		local_02=local_02+1;
		if (local_02>=1000) break;
	}
	g_intarray2[arg_0]=local_02;
	return;
}


void CMainControl::mf_CMainControl_0540(xint arg_0)
{
	int local_00;
	int local_01;
	char local_06[4096];
	char local_07[4096];
	local_01=0;
	for (local_00=0; m_IgnoreCondition_.size()>local_00; local_00++) {
		if (!m_IgnoreCondition_[local_00].IsValid()) continue;
		local_01=local_01+1;
	}
	if (local_01>1000) {
		local_01=1000;
	}
	int local_02;
	local_02=0;
	for (local_00=0; m_IgnoreCondition_.size()>local_00; local_00++) {
		if (!m_IgnoreCondition_[local_00].IsValid()) continue;
		g_nazouintarray[arg_0][local_02]=local_00;
		char local_03;
		local_03=' ';
		if (! (local_00!=m_int_unk19||!m_IgnoreCondition_[local_00].Get_flag_unk7()&&!m_IgnoreCondition_[local_00].Get_flag_unk8()) ) {
			local_03='-';
		}
		local_06[0]=0;
		if (m_IgnoreCondition_[local_00].mf_CAutoDownList_0010()) {
			local_07[0]=0;
			int dummy;
			char local_04[8];
			for (int local_05=0; local_05<16; local_05++) {
				sprintf(local_04,"%02x",(unsigned int)m_IgnoreCondition_[local_00].GetHash()[local_05]);
				strcat(local_07,local_04);
			}
			sprintf(local_06,"%c%c%s (%s)",(int)local_03,(int)(!(!m_IgnoreCondition_[local_00].Get_flag_unk6())?':':' '),m_IgnoreCondition_[local_00].m_char256_unk1,local_07);
		} else {
			if (strlen(m_IgnoreCondition_[local_00].m_char256_unk1)>1) {
				sprintf(local_06,"%c%c%s",(int)local_03,(int)(!(!m_IgnoreCondition_[local_00].Get_flag_unk6())?':':' '),m_IgnoreCondition_[local_00].m_char256_unk1);
			}
		}
		strcpy(g_listitemarray[arg_0][local_02][0],local_06);
		if (!m_IgnoreCondition_[local_00].Get_flag_unk5()) {
			sprintf(local_06,"%s",m_IgnoreCondition_[local_00].m_char256_unk2);
		} else {
			sprintf(local_06,"BBS");
		}
		strcpy(g_listitemarray[arg_0][local_02][1],local_06);
		sprintf(local_06,"%g - %g",m_IgnoreCondition_[local_00].Get_double_unk10(),m_IgnoreCondition_[local_00].Get_double_unk9());
		strcpy(g_listitemarray[arg_0][local_02][2],local_06);
		sprintf(local_06,"%d",m_IgnoreCondition_[local_00].Get_int_unk20());
		strcpy(g_listitemarray[arg_0][local_02][3],local_06);
		if (m_IgnoreCondition_[local_00].Get_flag_unk7()) {
			strcpy(local_06,"ON");
		} else {
			strcpy(local_06,"OFF");
		}
		strcpy(g_listitemarray[arg_0][local_02][4],local_06);
		if (m_IgnoreCondition_[local_00].Get_flag_unk8()) {
			strcpy(local_06,"ON");
		} else {
			strcpy(local_06,"OFF");
		}
		strcpy(g_listitemarray[arg_0][local_02][5],local_06);
		local_02=local_02+1;
		if (local_02>=1000) break;
	}
	g_intarray2[arg_0]=local_02;
	return;
}



void CMainControl::mf_CMainControl_0550(xint arg_0)
{
	int local_00;
	int local_01;
	unsigned int local_02;
	char local_12[1024];
	char local_13[1024];

	local_00=0;
	strcpy(g_listitemarray[arg_0][local_00][0],"アップフォルダ個数");
	sprintf(local_12,"%d",m_vectorCFolder_.size());
	strcpy(g_listitemarray[arg_0][local_00++][1],local_12);
	strcpy(g_listitemarray[arg_0][local_00][0],"アップファイル個数");
	sprintf(local_12,"%d",m_int_numberOfUpFile_);
	strcpy(g_listitemarray[arg_0][local_00++][1],local_12);
	strcpy(g_listitemarray[arg_0][local_00][0],"BBSアップファイル個数");
	sprintf(local_12,"%d",m_int_numberOfBbsUpFile_);
	strcpy(g_listitemarray[arg_0][local_00++][1],local_12);
	local_00=local_00+1;
	strcpy(g_listitemarray[arg_0][local_00][0],"キャッシュファイル数");
	sprintf(local_12,"%d",m_int_numberOfCacheFile_);
	strcpy(g_listitemarray[arg_0][local_00++][1],local_12);
	strcpy(g_listitemarray[arg_0][local_00][0],"保持キャッシュサイズ");
	if (m_double_currentCacheSize_<1000.0) {
		sprintf(local_12,"%g Mbyte",m_double_currentCacheSize_);
	} else {
		sprintf(local_12,"%g Gbyte",m_double_currentCacheSize_*(float)0.0009765625);
	}
	strcpy(g_listitemarray[arg_0][local_00++][1],local_12);
	strcpy(g_listitemarray[arg_0][local_00][0],"キャッシュドライブ空き容量");
	sprintf(local_12,"%g Gbyte",(double)m_uint_cacheDriveFreeMByte_*(float)0.0009765625);
	strcpy(g_listitemarray[arg_0][local_00++][1],local_12);
	local_00=local_00+1;
	strcpy(g_listitemarray[arg_0][local_00][0],"ダウンドライブ空き容量");
	sprintf(local_12,"%g Gbyte",(double)m_uint_downDriveFreeMByte_*(float)0.0009765625);
	strcpy(g_listitemarray[arg_0][local_00++][1],local_12);
	local_00=local_00+1;
	strcpy(g_listitemarray[arg_0][local_00][0],"ダウン試行時間");
	sprintf(local_12,"%d:%02d:%02d",m_int_downTrial_TimeInSec_/3600,(m_int_downTrial_TimeInSec_-(m_int_downTrial_TimeInSec_/3600)*3600)/60,m_int_downTrial_TimeInSec_%60);
	strcpy(g_listitemarray[arg_0][local_00++][1],local_12);
	local_00=local_00+1;
	local_01=m_int_downTrial_NumberOfTry_;
	if (local_01<=0) {
		local_01=1;
	}
	sprintf(local_13,"%d",(int)(m_double_totalFileSize_/(double)local_01));
	ny_sanketacomma(local_13);
	strcpy(g_listitemarray[arg_0][local_00][0],"ダウン試行ファイル平均サイズ");
	sprintf(local_12,"%s Mbyte",local_13);
	strcpy(g_listitemarray[arg_0][local_00++][1],local_12);
	sprintf(local_13,"%d",(int)(m_double_totalReferenceSize_*(float)0.0625/(double)local_01));
	ny_sanketacomma(local_13);
	strcpy(g_listitemarray[arg_0][local_00][0],"ダウン試行ファイル平均参照量");
	sprintf(local_12,"%s Mbyte",local_13);
	strcpy(g_listitemarray[arg_0][local_00++][1],local_12);
	local_00=local_00+1;
	strcpy(g_listitemarray[arg_0][local_00][0],"ダウン試行回数");
	sprintf(local_12,"%d",m_int_downTrial_NumberOfTry_);
	strcpy(g_listitemarray[arg_0][local_00++][1],local_12);
	strcpy(g_listitemarray[arg_0][local_00][0],"ダウンコネクション限界回数");
	sprintf(local_12,"%d",m_int_downTrial_LimitTryCount_);
	strcpy(g_listitemarray[arg_0][local_00++][1],local_12);
	local_00=local_00+1;
	local_01=m_int_downTrial_NumberOfTry_-m_int_downTrial_LimitTryCount_;
	if (local_01<=0) {
		local_01=1;
	}
	strcpy(g_listitemarray[arg_0][local_00][0],"ダウン成功回数");
	sprintf(local_12,"%d ( %4.1f%% )",m_int_downTrial_NumberOfSuccessTry_,(double)m_int_downTrial_NumberOfSuccessTry_*(float)100.0/(double)local_01);
	strcpy(g_listitemarray[arg_0][local_00++][1],local_12);
	strcpy(g_listitemarray[arg_0][local_00][0],"ダウンキーロスト切断回数");
	sprintf(local_12,"%d ( %4.1f%% )",m_int_downTrial_NumberOfKeylostDisconnect_,(double)m_int_downTrial_NumberOfKeylostDisconnect_*(float)100.0/(double)local_01);
	strcpy(g_listitemarray[arg_0][local_00++][1],local_12);
	strcpy(g_listitemarray[arg_0][local_00][0],"ダウンタイムアウト回数");
	sprintf(local_12,"%d ( %4.1f%% )",m_int_downTrial_NumberOfTimeout_,(double)m_int_downTrial_NumberOfTimeout_*(float)100.0/(double)local_01);
	strcpy(g_listitemarray[arg_0][local_00++][1],local_12);
	local_00=local_00+1;
	local_01=0;
	for (local_02=0; m_DownCondition_.size()>local_02; local_02++) {
		if (!GetDownCondition(local_02)->IsValid()) continue;
		local_01=local_01+1;
	}
	strcpy(g_listitemarray[arg_0][local_00][0],"ダウン条件個数");
	sprintf(local_12,"%d",local_01);
	strcpy(g_listitemarray[arg_0][local_00++][1],local_12);
	local_01=0;
	for (local_02=0; m_IgnoreCondition_.size()>local_02; local_02++) {
		if (!m_IgnoreCondition_[local_02].IsValid()) continue;
		local_01=local_01+1;
	}
	strcpy(g_listitemarray[arg_0][local_00][0],"無視条件個数");
	sprintf(local_12,"%d",local_01);
	strcpy(g_listitemarray[arg_0][local_00++][1],local_12);
	local_00=local_00+1;
	strcpy(g_listitemarray[arg_0][local_00][0],"Winny本体フォルダ位置");
	sprintf(local_12,"%s",/*(const char *)*/g_AppPath);
	strcpy(g_listitemarray[arg_0][local_00++][1],local_12);
	strcpy(g_listitemarray[arg_0][local_00][0],"キャッシュフォルダ位置");
	sprintf(local_12,"%s",m_sz_CacheFolderPath_);
	strcpy(g_listitemarray[arg_0][local_00++][1],local_12);
	strcpy(g_listitemarray[arg_0][local_00][0],"ダウンフォルダ位置");
	sprintf(local_12,"%s",m_sz_DownFolderPath_);
	strcpy(g_listitemarray[arg_0][local_00++][1],local_12);
	strcpy(g_listitemarray[arg_0][local_00][0],"BBSフォルダ位置");
	sprintf(local_12,"%s",m_sz_BbsFolderPath_);
	strcpy(g_listitemarray[arg_0][local_00++][1],local_12);

	multimap<unsigned int,CKey>::iterator local_03;
	g_intarray2[arg_0]=local_00;
	int	local_04=0;
	int	local_05=0;
	local_01=0;
	int	local_06=0;
	int	local_07=0;
	int	local_08=0;
	int	local_09=0;
	int	local_10=0;
	for (local_03=m_KeyBuffer_.begin(); local_03!=m_KeyBuffer_.end(); local_03++) {
		CKey* local_11=&local_03->second;
		if (local_11->m_int_unk0x==0) continue;
		local_01=local_01+1;
		switch (local_11->m_char_keyType_) {
		case KEYTYPE00:
			if (local_11->m_bln_unk308) {
				if (local_11->m_bln_unk307) {
					local_09=local_09+1;
					break;
				}
				local_10=local_10+1;
				break;
			}
			if (local_11->m_bln_unk307) {
				local_04=local_04+1;
				break;
			}
			local_05=local_05+1;
			break;
		case KEYTYPE01:
			local_06=local_06+1;
			break;
		case KEYTYPE03:
			local_07=local_07+1;
			break;
		case KEYTYPE02:
			local_08=local_08+1;
		}
	}
	local_00=0;
	strcpy(g_listitemarray[arg_0][local_00][2],"BBS専用ノード");
	sprintf(local_12,"%s",!(!m_optflg_UseBbsOnly_)?"ON":"OFF");
	strcpy(g_listitemarray[arg_0][local_00++][3],local_12);
	strcpy(g_listitemarray[arg_0][local_00][2],"BBSクラスタ参加");
	sprintf(local_12,"%s",!(!m_flg_IsJoiningBBSCluster_)?"ON":"OFF");
	strcpy(g_listitemarray[arg_0][local_00++][3],local_12);
	strcpy(g_listitemarray[arg_0][local_00][2],"BBS検索リンク接続");
	sprintf(local_12,"%s",!(!m_flg_IsJoiningBBSCluster_&&!m_flg_IsBBSSearchLinkOn_)?"ON":"OFF");
	strcpy(g_listitemarray[arg_0][local_00++][3],local_12);
	strcpy(g_listitemarray[arg_0][local_00][2],"DDNS名");
	sprintf(local_12,"%s",m_sz_MyDDNSname_);
	strcpy(g_listitemarray[arg_0][local_00++][3],local_12);
	strcpy(g_listitemarray[arg_0][local_00][2],"回線速度");
	sprintf(local_12,"%d Kbyte/s",m_int_linespeed_);
	strcpy(g_listitemarray[arg_0][local_00++][3],local_12);
	strcpy(g_listitemarray[arg_0][local_00][2],"Acceptポート番号");
	sprintf(local_12,"%d",m_port_accept_);
	strcpy(g_listitemarray[arg_0][local_00++][3],local_12);
	strcpy(g_listitemarray[arg_0][local_00][2],"BBS Acceptポート番号");
	sprintf(local_12,"%d",m_port_bbsaccept_);
	strcpy(g_listitemarray[arg_0][local_00++][3],local_12);
	local_00=local_00+1;
	strcpy(g_listitemarray[arg_0][local_00][2],"キーバッファサイズ");
	sprintf(local_12,"%d",m_KeyBuffer_.size());
	strcpy(g_listitemarray[arg_0][local_00++][3],local_12);
	strcpy(g_listitemarray[arg_0][local_00][2],"キー検索テーブルサイズ/GC");
	sprintf(local_12,"%dk / %dk",m_KeySearchTable_.size()/1000,(unsigned int)m_int_virtualKeyMax_*100/1000);
	strcpy(g_listitemarray[arg_0][local_00++][3],local_12);
	strcpy(g_listitemarray[arg_0][local_00][2],"保持キー個数");
	sprintf(local_12,"%d",local_01);
	strcpy(g_listitemarray[arg_0][local_00++][3],local_12);
	strcpy(g_listitemarray[arg_0][local_00][2],"仮想キー個数限界");
	sprintf(local_12,"%d",m_int_virtualKeyMax_);
	strcpy(g_listitemarray[arg_0][local_00++][3],local_12);
	strcpy(g_listitemarray[arg_0][local_00][2],"上流仮想ファイルキー個数");
	sprintf(local_12,"%d",local_04);
	strcpy(g_listitemarray[arg_0][local_00++][3],local_12);
	strcpy(g_listitemarray[arg_0][local_00][2],"下流仮想ファイルキー個数");
	sprintf(local_12,"%d",local_05);
	strcpy(g_listitemarray[arg_0][local_00++][3],local_12);
	strcpy(g_listitemarray[arg_0][local_00][2],"上流仮想BBSキー個数");
	sprintf(local_12,"%d",local_09);
	strcpy(g_listitemarray[arg_0][local_00++][3],local_12);
	strcpy(g_listitemarray[arg_0][local_00][2],"下流仮想BBSキー個数");
	sprintf(local_12,"%d",local_10);
	strcpy(g_listitemarray[arg_0][local_00++][3],local_12);
	strcpy(g_listitemarray[arg_0][local_00][2],"部分キャッシュキー個数");
	sprintf(local_12,"%d",local_06);
	strcpy(g_listitemarray[arg_0][local_00++][3],local_12);
	strcpy(g_listitemarray[arg_0][local_00][2],"完全キャッシュキー個数");
	sprintf(local_12,"%d",local_07);
	strcpy(g_listitemarray[arg_0][local_00++][3],local_12);
	m_int_numberOfCompleteCacheFile_=local_07;
	strcpy(g_listitemarray[arg_0][local_00][2],"アップファイルキー個数");
	sprintf(local_12,"%d",local_08);
	strcpy(g_listitemarray[arg_0][local_00++][3],local_12);
	local_00=local_00+1;
	local_04=local_09=0;
	for (local_02=0; local_02<600; local_02++) {
		if (!m_hostArray[local_02].m_flgIsValid) continue;
		if (m_hostArray[local_02].m_flgIsBBSNode_8) {
			local_09=local_09+1;
			continue;
		}
		local_04=local_04+1;
	}
	strcpy(g_listitemarray[arg_0][local_00][2],"保持ノード数/バッファサイズ");
	sprintf(local_12,"%d / %d",local_04,600);
	strcpy(g_listitemarray[arg_0][local_00++][3],local_12);
	strcpy(g_listitemarray[arg_0][local_00][2],"保持BBSノード数/バッファサイズ");
	sprintf(local_12,"%d / %d",local_09,600);
	strcpy(g_listitemarray[arg_0][local_00++][3],local_12);
	local_01=0;
	for (local_02=0; m_vectorpCWork_.size()>local_02; local_02++) {
		if (/**/(*GetWorkNP(local_02))->GetWorkType()==WORKTYPE00||/**/(*GetWorkNP(local_02))->IsFinished()) continue;
		local_01=local_01+1;
	}
	strcpy(g_listitemarray[arg_0][local_00][2],"タスク個数/バッファサイズ");
	sprintf(local_12,"%d / %d",local_01,m_vectorpCWork_.size());
	strcpy(g_listitemarray[arg_0][local_00++][3],local_12);
	local_01=0;
	for (local_02=0; m_vectorCQuery_.size()>local_02; local_02++) {
		if (!m_vectorCQuery_[local_02].Get_flg_unk04()) continue;
		local_01=local_01+1;
	}
	strcpy(g_listitemarray[arg_0][local_00][2],"クエリ個数/バッファサイズ");
	sprintf(local_12,"%d / %d",local_01,m_vectorCQuery_.size());
	strcpy(g_listitemarray[arg_0][local_00++][3],local_12);
	return;
}


int CMainControl::mf_CMainControl_0560(_in_addr * ipaddr,int port)
{
	int local_00;
	int local_01;
	int local_02;
	_in_addr * local_03;
	CHost * local_04;
	for (local_00=0; local_00<600; local_00++) {
		if (!(m_hostArray[local_00].m_flgIsValid||m_hostArray[local_00].m_flgIsBadPortZero_9)&&!m_hostArray[local_00].m_field_82) break;
	}
	if (local_00>=600) {
		local_01=0;
		local_02=0;
		for (local_00=1; local_00<600; local_00++) {
			if ((!m_hostArray[local_00].m_flgIsValid||m_hostArray[local_00].m_flgIsConnected)||!(m_hostArray[local_00].m_int_unk10<=0||m_hostArray[local_00].m_flgIsPortZero_9||m_hostArray[local_00].m_flgIsBadPortZero_9||!m_hostArray[local_00].m_field_8D)&&m_hostArray[local_00].m_int_unk5<=300) continue;
			if (m_hostArray[local_00].m_flgIsBBSNode_8) {
				local_02=local_02+1;
				if (local_02<100) continue;
			} else {
				local_01=local_01+1;
				if (local_01<100) continue;
			}
			m_hostArray[local_00].mf_CHost_0190(true);
			m_hostArray[local_00].mf_CHost_0000();
			m_hostArray[local_00].m_flgIsValid=false;
		}
		for (local_00=1; local_00<600; local_00++) {
			if (!m_hostArray[local_00].m_flgIsValid) break;
		}
	}
	if (local_00==600) {
		local_00=local_00-1;
		m_hostArray[local_00].mf_CHost_0190(true);
	}
	if (m_hostArray[local_00].m_socket!=0) {
		closesocket(m_hostArray[local_00].m_socket);
		g_int_unk506=g_int_unk506+1;
	}
	m_hostArray[local_00].mf_CHost_0000();
	local_03=ipaddr;
	local_04=m_hostArray+local_00;
	local_04->m_ipaddr3.b1=local_03->b1;
	local_04->m_ipaddr3.b2=local_03->b2;
	local_04->m_ipaddr3.b3=local_03->b3;
	local_04->m_ipaddr3.b4=local_03->b4;
	GetHost(local_00)->SetPort(port);
	GetHost(local_00)->SetWmsgIdx(local_00+1);
	m_hostArray[local_00].m_flgIsConnected=false;
	m_hostArray[local_00].m_socket=0;//INVALID_SOCKET;
	m_hostArray[local_00].m_flg_isDownConnection=true;
	m_hostArray[local_00].m_flgIsValid=true;
	m_hostArray[local_00].m_flgIsPortZero_9=false;
	m_hostArray[local_00].m_flgIsBadPortZero_9=false;
	m_hostArray[local_00].m_field_94=false;
	m_hostArray[local_00].m_field_87=false;
	m_hostArray[local_00].m_field_88=false;
	m_hostArray[local_00].m_int_preference2_negative=0;
	return local_00;
}


void CMainControl::mf_CMainControl_0570()
{
	if (m_int_unk21==0) {
		m_KeySearchTable_.clear();
	}
	multimap<unsigned int,CKey>::iterator local_00;
	for (local_00=m_KeyBuffer_.begin(); local_00!=m_KeyBuffer_.end(); local_00++) {
		CKey* local_01=&local_00->second;
		if (local_01->m_int_unk0x==0||local_01->m_int_unk201%10!=m_int_unk21) continue;
		mf_CMainControl_0580(local_01);
	}
	m_int_unk21=m_int_unk21+1;
	if (m_int_unk21>=10) {
		m_int_unk21=0;
	}
	return;
}


void CMainControl::mf_CMainControl_0580(CKey * arg_0)
{
	char local_08[4096];
	try {
		unsigned short local_00=(short)((unsigned int)arg_0->m_hash_tabun[0]<<8)+(short)((unsigned int)arg_0->m_hash_tabun[1]);
		m_KeySearchTable_.insert(make_pair(local_00,*((unsigned int *)arg_0->m_hash_tabun)));
		local_08[0]=0;
		strcpy(local_08,arg_0->mf_CKey_0260());
		if (! (!(local_08[0]==0)&&(int)local_08[0]!=64) ) {
			return;
		}
		int local_02=0;
		while (*(local_08+local_02)!=0) {
			unsigned short local_03=0;
			if (! ((short)((int)*(local_08+local_02))!=129||(short)((int)*((local_08+1)+local_02))!=64) ) {
				local_02=local_02+2;
			} else {
				if (! (!ny_iskanji(*(local_08+local_02))||*((local_08+1)+local_02)==0) ) {
					unsigned char tmp1=*(local_08+local_02);
					unsigned char tmp2=*((local_08+1)+local_02);
					local_03=(short)((unsigned int)tmp1<<8)+(short)((unsigned int)tmp2);
					local_02=local_02+2;
					m_KeySearchTable_.insert(make_pair(local_03,*((unsigned int *)arg_0->m_hash_tabun)));
				} else {
					if (! (ny_iskanji(*(local_08+local_02))||ny_iskanji(*((local_08+1)+local_02))) ) {
						unsigned char local_05=*(local_08+local_02);
						unsigned char local_06=*((local_08+1)+local_02);
						if (! (local_05<'a'||local_05>'z') ) {
							local_05=local_05+224;
						}
						if (! (local_06<'a'||local_06>'z') ) {
							local_06=local_06+224;
						}
						local_03=(short)((unsigned int)local_05<<8)+(short)((unsigned int)local_06);
						local_02=local_02+1;
						m_KeySearchTable_.insert(make_pair(local_03,*((unsigned int *)arg_0->m_hash_tabun)));
					} else {
						local_02=local_02+1;
					}
				}
			}
		}
	}
	catch (std::bad_alloc ex_8) {
	}
	return;
}


unsigned short CMainControl::mf_CMainControl_0590(const char * arg_0)
{
	int local_00;
	unsigned short local_01;
	unsigned char local_04[16];
	if ((int)*arg_0==37) {
		ny_aschash2binhash(arg_0+1,local_04);
		return (short)((unsigned int)local_04[0]<<8)+(short)((unsigned int)local_04[1]);
	}
	local_00=0;
	while (*(arg_0+local_00)!=0) {
		local_01=0;
		if (! ((short)((int)*(arg_0+local_00))!=129||(short)((int)*((arg_0+1)+local_00))!=64) ) {
			local_00=local_00+2;
		} else {
			if (ny_iskanji(*(arg_0+local_00))) {
				unsigned char tmp1=*(arg_0+local_00);
				unsigned char tmp2=*((arg_0+1)+local_00);
				local_01=(short)((unsigned int)tmp1<<8)+(short)((unsigned int)tmp2);
				return local_01;
			} else {
				if (! (ny_iskanji(*(arg_0+local_00))||ny_iskanji(*((arg_0+1)+local_00))) ) {
					unsigned char local_02=*((char *)(arg_0+local_00));
					unsigned char local_03=*((char *)((arg_0+1)+local_00));
					if (! (local_02<'a'||local_02>'z') ) {
						local_02=local_02+224;
					}
					if (! (local_03<'a'||local_03>'z') ) {
						local_03=local_03+224;
					}
					local_01=(short)((unsigned int)local_02<<8)+(short)((unsigned int)local_03);
					return local_01;
				} else {
					local_00=local_00+1;
				}
			}
		}
	}
	return (unsigned short)0;
}


//arg_5はenumKeyTypeらしい
CKey * CMainControl::mf_CMainControl_0600(bool arg_0,char * arg_1,unsigned int arg_2,unsigned int arg_3,unsigned char * arg_4,char arg_5,bool * arg_6,char * arg_7,int arg_8,bool arg_9,unsigned int arg_10,int arg_11)
{
	CKey local_00;

	local_00.m_fileptr_=NULLPO;
	local_00.mf_CKey_0060();
	local_00.Set_int_unk0x(1);
	local_00.SetKeyType( (enumKeyType)arg_5 );
	local_00.Set_int_unk16(arg_8);
	local_00.mf_CKey_0240(arg_3);
	local_00.Set_char11_nazo2(arg_7);

	if (arg_10>0) {
		local_00.Set_time( (time_t)arg_10 );
	} else {
		time(&local_00.m_time_);
	}
	local_00.mf_CKey_0070(arg_1,arg_2,arg_0);
	local_00.Set_bln_unk308(arg_9);
	try {
		if (arg_4!=0) {
			local_00.Set_hash_tabun(arg_4);
			local_00.m_int_unk0x=1;
		} else {
			if ((unsigned char)arg_5==2) {}
			if (arg_5!=0) {
				local_00.mf_CKey_0100();
				arg_3=local_00.m_uint_unk13;
			}
		}
		*arg_6=false;
		unsigned int local_02=*((unsigned int *)local_00.m_hash_tabun);
		int local_03=m_KeyBuffer_.count(local_02);
		CKey* local_04=NULLPO;
		multimap<unsigned int,CKey>::iterator local_05;
		if (local_03>0) {
			for (local_05=m_KeyBuffer_.find(local_02); local_05!=m_KeyBuffer_.end(); local_05++) {
				CKey * local_06=&local_05->second;
				if (*((int *)local_06->m_hash_tabun)!=local_02) break;
				if (memcmp(local_06->m_hash_tabun,local_00.m_hash_tabun,16)!=0) continue;
				if (local_06->m_bln_unk308) {
					if (! (local_06->m_char_keyType_==KEYTYPE02||local_06->m_int_refcountOfFileptr_!=0||local_06->m_time_+10>=arg_10) ) {
						local_06->mf_CKey_0130();
						local_06->mf_CKey_0240(arg_3);
						local_06->Set_time(arg_10);
						if (arg_11>0) {
							local_06->SetRefs(arg_11);
						}
						if (local_06->m_char_keyType_>=KEYTYPE01) {
							local_06->m_bln_unk301=true;
						}
						if (local_06->m_char_keyType_==KEYTYPE03) {
							local_06->m_char_keyType_=KEYTYPE01;
						}
						if (local_06->m_char_keyType_!=KEYTYPE00) {
							local_06->mf_CKey_0110();
						}
					}
					local_06->Set_uint_unk206(local_06->Get_uint_unk206()+1);
					*arg_6=true;
					return local_06;
				}
				if (local_06->m_uint_unk13!=arg_3) continue;
				local_06->Set_uint_unk206(local_06->Get_uint_unk206()+1);
				if (! (local_06->m_bln_unk314||local_06->m_char_keyType_==KEYTYPE02||*arg_7==0) ) {
					local_06->Set_char11_nazo2(arg_7);
					local_06->mf_CKey_0070(arg_1,arg_2,arg_0);
				}
				if (! (!(local_06->m_char_keyType_>=(enumKeyType)arg_5)&&local_06->m_int_refcountOfFileptr_==0) ) {
					*arg_6=true;
					return local_06;
				}
				local_04=local_06;
				break;
			}
		}
		if (local_04==0) {
			pair<unsigned int,CKey> local_01(local_02,local_00);
			m_KeyBuffer_.insert(local_01);
			local_04=mf_CMainControl_0180(local_02,local_00.m_hash_tabun);
		}
		if (local_04==0) {
			return NULLPO;
		}
		local_04->mf_CKey_0060();
		local_04->m_int_unk0x=1;
		local_04->Set_int_unk203(local_00.m_int_unk203);
		local_04->Set_char11_nazo2(arg_7);
		local_04->SetKeyType( (enumKeyType)arg_5 );
		local_04->mf_CKey_0070(arg_1,arg_2,arg_0);
		local_04->Set_int_unk16(arg_8);
		local_04->mf_CKey_0240(arg_3);
		if (arg_11>0) {
			local_04->SetRefs(arg_11);
		}
		if (arg_10>0) {
			local_04->Set_time( (time_t)arg_10 );
		} else {
			time(&local_04->m_time_);
		}
		local_04->Set_bln_unk308(arg_9);
		local_04->Set_int_unk201(g_int_unk402++);

		memcpy(local_04->m_hash_tabun,local_00.m_hash_tabun,16);
		local_04->m_int_unk0x=1;
		if ((enumKeyType)arg_5==KEYTYPE02) {
			local_04->m_bln_unk302=true;
		}
		if ((enumKeyType)arg_5>=KEYTYPE01) {
			if (local_04->mf_CKey_0100()) {}
		}
		local_04->m_bln_unk313=false;
		if (! (!local_04->m_bln_unk308||(enumKeyType)arg_5!=KEYTYPE02) ) {
			local_04->m_char_keyType_=KEYTYPE02;
		}
		if (local_04->m_bln_unk308) {
			local_04->m_int_unk203=6;
		}
		_in_addr local_08;
		ny_addrcrypter(&local_08,m_hostArray[0].m_ipaddr3);
		memcpy(&local_04->m_ipaddr_0__,&local_08,4);
		local_04->Set_portno_0(m_port_accept_);
		memcpy(&local_04->m_ipaddr_1__,&local_08,4);
		local_04->Set_portno_1(m_port_accept_);
		return local_04;
	}
	catch (std::bad_alloc ex_32) {
		return NULLPO;
	}
}



sl CMainControl::mf_CMainControl_0610()
{
	try {
		int local_00;
		int		local_01=m_vectorpCWork_.size();
		for (local_00=0; local_00<local_01; local_00++) {
			if (/**/(*GetWorkNP(local_00))->GetWorkType()==WORKTYPE00) break;
		}
		if (local_00==local_01) {
			CWork * local_02=new CWork();
			local_02->mf_CWork_0000();
			m_vectorpCWork_.push_back(local_02);
		}
		m_vectorpCWork_[local_00]->mf_CWork_0000();
		return local_00;
	}
	catch (std::bad_alloc ex_8) {
		return 0;
	}
}


void CMainControl::mf_CMainControl_0620()
{
	int local_00;
	int local_01;
	local_01=m_vectorpCWork_.size();
	for (local_00=0; local_00<local_01; local_00++) {
		if (/**/(*GetWorkNP(local_00))->GetWorkType()==WORKTYPE00) continue;
		m_vectorpCWork_[local_00]->mf_CWork_0010(false,true);
	}
	return;
}


void CMainControl::mf_CMainControl_0630()
{
	int local_00;
	int local_01;
	local_01=m_vectorpCWork_.size();
	for (local_00=0; local_00<local_01; local_00++) {
		if (/**/(*GetWorkNP(local_00))->GetWorkType()==WORKTYPE00||!/**/(*GetWorkNP(local_00))->IsFinished()) continue;
		/**/(*GetWorkNP(local_00))->SetWorkType(WORKTYPE00);
	}
	return;
}


void CMainControl::mf_CMainControl_0640(int arg_0)
{
	if (! (/**/(*GetWorkNP(arg_0))->GetWorkType()==WORKTYPE00||/**/(*GetWorkNP(arg_0))->IsFinished()) ) {
		if (/**/(*GetWorkNP(arg_0))->GetHostIdx()>=0) {
			CHost * local_00=m_hostArray+/**/(*GetWorkNP(arg_0))->GetHostIdx();
			if (! (!local_00->m_flgIsValid||!local_00->m_flgIsConnected||!local_00->m_flgIsTransferLink_8) ) {
				local_00->mf_CHost_0190(true);
			}
		}
		m_vectorpCWork_[arg_0]->mf_CWork_0010(false,true);
		(*GetWorkNP(arg_0))->SetErrorcode(2);
	}
	return;
}


void CMainControl::mf_CMainControl_0650(int arg_0)
{
	int local_00;
	if (arg_0>=0) {
		local_00=GetDownCondition(arg_0)->Get_int_unk4();
			if (local_00>=0) {
			mf_CMainControl_0640(local_00);
		}
	}
	return;
}


sl CMainControl::mf_CMainControl_0660()
{
	int local_01;
	try {
		int local_02=m_vectorCQuery_.size();
		for (local_01=0; local_01<local_02; local_01++) {
			if (!m_vectorCQuery_[local_01].Get_flg_unk04()) break;
		}
		if (local_01==local_02) {
			CQuery local_00;
			local_00.mf_CQuery_0000("","",0);
			m_vectorCQuery_.push_back(local_00);
		}
		return local_01;
	}
	catch (std::bad_alloc ex_8) {
		return 0;
	}
}



void CMainControl::mf_CMainControl_0670(int arg_0,int arg_1)
{
	char local_01;
	char * local_02;
	char local_03[8];
	char * local_04;
	char * local_05;
	unsigned char * local_06;
	_in_addr * local_07;
	int local_08;
	int local_09;
	char local_12[1024];
	if (! (!(arg_0<0)&&arg_0<600) ) {
		return;
	}
	if (m_hostArray[arg_0].m_flg_IsBBSPort) {
		return;
	}
	local_01='a';
	mf_CMainControl_0370(arg_0,&local_01,1);
	local_02=local_12+1;
	local_12[0]=0;
	*((int *)local_02)=12710;
	sprintf(local_02+4,"Winny Ver2.0b1    ");
	CRC4 local_00;
	local_00.setupkey("98789asj");
	local_00.crypter(local_12+1,20);
	mf_CMainControl_0370(arg_0,local_12,21);
	local_03[0]=*(m_hostArray+arg_0)->m_cryptseed_send;
	local_03[1]=(m_hostArray+arg_0)->m_cryptseed_send[1]^'9';
	local_03[2]=(m_hostArray+arg_0)->m_cryptseed_send[2]^'9';
	local_03[3]=(m_hostArray+arg_0)->m_cryptseed_send[3]^'9';
	local_03[4]=0;
	m_hostArray[arg_0].mf_CHost_0030(local_03);
	local_04=local_12+1;
	local_12[0]=1;
	*((float *)local_04)=(float)m_int_linespeed_;
	mf_CMainControl_0370(arg_0,local_12,5);
	local_05=local_12+1;
	local_12[0]=2;
	if (!m_hostArray[arg_0].m_flgIsTransferLink_8) {
		*local_05=0;
	} else {
		if (m_hostArray[arg_0].m_flgIsBBSNode_8) {
			*local_05=2;
		} else {
			*local_05=1;
		}
	}
	*(local_05+1)=(char)(!(!m_optflag_notConnected__)?1:0);
	if (! (!m_hostArray[arg_0].m_flgIsBBSNode_8||m_flg_IsJoiningBBSCluster_) ) {
		*(local_05+1)=1;
	}
	*(local_05+2)=(char)(!(!m_hostArray[arg_0].m_flgUnknown_7F)?1:0);
	*(local_05+3)=(char)(!(!m_hostArray[arg_0].m_flgIsBBSNode_8)?1:0);
	mf_CMainControl_0370(arg_0,local_12,5);
	local_06=(unsigned char *)(local_12+1);
	local_12[0]=3;
	*((int *)(local_06+4))=m_port_accept_;
	local_07=&m_hostArray->m_ipaddr3;
	*local_06=local_07->b1;
	*(local_06+1)=local_07->b2;
	*(local_06+2)=local_07->b3;
	*(local_06+3)=local_07->b4;
	local_08=12;
	strcpy(local_06+local_08,m_hostArray->m_str_DDNSname.c_str());
	local_09=strlen(m_hostArray->m_str_DDNSname.c_str());
	*(local_06+8)=*((unsigned char *)(&local_09));
	local_08=local_08+local_09;
	if (m_hostArray[arg_0].m_flgIsBBSNode_8) {
		for (int local_10=0; local_10<3; local_10++) {
			*((local_06+9)+local_10)=0;
		}
	} else {
		for (int local_11=0; local_11<3; local_11++) {
			local_09=strlen(m_hostArray->m_sz_clusterword[local_11]);
			if (local_09>100) {
				local_09=100;
			}
			local_06[local_11+9]=local_09;

			memcpy(local_06+local_08,m_hostArray->m_sz_clusterword[local_11],local_09);
			local_08=local_08+local_09;
		}
	}
	mf_CMainControl_0370(arg_0,local_12,local_08+1);
	return;
}


void CMainControl::mf_CMainControl_0680(int arg_0)
{
	multimap<unsigned int,CKey>::iterator local_00;
	for (local_00=m_KeyBuffer_.begin(); local_00!=m_KeyBuffer_.end(); local_00++) {
		CKey * local_01=&local_00->second;
		_in_addr local_02;
		ny_addrcrypter(&local_02,local_01->m_ipaddr_0__);
		if (local_01->m_int_unk0x==0
		  ||local_01->m_char_keyType_>KEYTYPE00||local_01->m_int_refcountOfFileptr_!=0||arg_0<0||!m_hostArray[arg_0].m_flgIsValid
		  ||m_hostArray[arg_0].m_port1!=local_01->m_portno_0__
		  ||!(m_hostArray[arg_0].IsInternalIpaddr_x2b(local_02))) continue;
		local_01->m_int_unk0x=0;
	}
	return;
}


void CMainControl::mf_CMainControl_0690()
{
	bool local_00;
	local_00=true;
	multimap<unsigned int,CKey>::iterator local_01;
	for (local_01=m_KeyBuffer_.begin(); local_01!=m_KeyBuffer_.end(); local_01++) {
		CKey * local_02=&local_01->second;
		if (local_02->m_int_unk0x==0||local_02->m_int_refcountOfFileptr_==0) continue;
		local_00=false;
		break;
	}
	if (local_00) {
		m_KeyBuffer_.clear();
	}
	return;
}


void CMainControl::mf_CMainControl_0700()
{
	multimap<unsigned int,CKey>::iterator local_00;
	for (local_00=m_KeyBuffer_.begin(); local_00!=m_KeyBuffer_.end(); local_00++) {
		CKey * local_01=&local_00->second;
		if (! (local_01->m_int_unk0x==0||local_01->m_int_refcountOfFileptr_!=0||local_01->m_char_keyType_>KEYTYPE00) ) {
			local_01->m_int_unk0x=0;
		}
		local_01->m_int_unk200=0;
	}
	return;
}


void CMainControl::mf_CMainControl_0710()
{
	m_int_numberOfUpFile_=0;
	m_int_numberOfBbsUpFile_=0;
	multimap<unsigned int,CKey>::iterator local_00;
	for (local_00=m_KeyBuffer_.begin(); local_00!=m_KeyBuffer_.end(); local_00++) {
		CKey * local_01=&local_00->second;
		if (local_01->m_int_unk0x==0||local_01->m_int_refcountOfFileptr_!=0||local_01->m_char_keyType_!=KEYTYPE02) continue;
		local_01->m_int_unk0x=0;
	}
	return;
}


void CMainControl::mf_CMainControl_0720()
{
	time_t local_00;
	int local_01;

	time(&local_00);
	local_01=0;
	multimap<unsigned int,CKey>::iterator local_02;
	_in_addr local_03;
	int local_04;
	local_04=0;
	for (local_02=m_KeyBuffer_.begin(); local_02!=m_KeyBuffer_.end(); local_02++) {
		CKey * local_05=&local_02->second;
		if (local_05->m_int_unk0x==0) continue;
		if (! ((!local_05->m_bln_unk308||local_05->m_bln_unk302)||!(local_05->m_char_keyType_==KEYTYPE01)&&local_05->m_char_keyType_!=KEYTYPE03) ) {
			local_04=local_04+1;
		}
		ny_addrcrypter(&local_03,local_05->m_ipaddr_0__);
		if (local_05->m_char_keyType_==KEYTYPE00) {
			local_01=local_01+1;
		}
		if (! (local_05->m_int_refcountOfFileptr_!=0||local_05->m_char_keyType_>KEYTYPE00||m_port_accept_!=local_05->m_portno_0__||!(m_hostArray[0].IsInternalIpaddr(local_03))) ) {
			local_05->m_int_unk0x=0;
		}
		if (! (local_05->m_int_unk203==4||local_05->m_int_unk203==5||local_05->m_int_unk203==6) ) {
			local_05->m_int_unk0x=0;
		}
		if (! (local_05->m_int_refcountOfFileptr_!=0||!((unsigned int)local_00+300<(unsigned int)local_05->m_time_)&&(unsigned int)local_00-0x05A39A80<=(unsigned int)local_05->m_time_) ) {
			local_05->m_int_unk0x=0;
		}
		int local_06=local_05->m_int_unk200;
		if (! ((local_06>2||local_05->m_int_refcountOfFileptr_!=0)||!(!local_05->m_bln_unk308)&&local_06>=-1000) ) {
			mf_CMainControl_0730(local_05);
		}

		if (strlen(local_05->mf_CKey_0260())>m_int_maxnamelen_70) {
			mf_CMainControl_0730(local_05);
		}

		if (local_06>10000) {
			local_06=1;
		}
		if (!(local_06>0)&&(!local_05->m_bln_unk308||local_05->m_char_keyType_!=KEYTYPE00)) continue;
		local_05->Set_int_unk200(local_06-5);
	}
	if (m_int_virtualKeyMax_<5000) {
		m_int_virtualKeyMax_=5000;
	}
	if (m_int_virtualKeyMax_>50000) {
		m_int_virtualKeyMax_=50000;
	}
	if (m_int_virtualKeyMax_/3<local_04) {
		mf_CMainControl_0750();
	}
	if (local_01>m_int_virtualKeyMax_) {
		multimap<unsigned int,CKey>::iterator local_07;
		for (local_07=m_KeyBuffer_.begin(); local_07!=m_KeyBuffer_.end(); local_07++) {
			CKey * local_08=&local_07->second;
			if (local_08->m_int_unk0x==0||local_08->m_bln_unk308||local_08->m_char_keyType_!=KEYTYPE00||local_08->m_int_refcountOfFileptr_!=0||local_08->m_int_unk14!=0) continue;
			local_08->m_int_unk0x=0;
		}
	}
	multimap<unsigned int,CKey>::iterator local_09;
	local_09=m_KeyBuffer_.begin();
	while (local_09!=m_KeyBuffer_.end()) {
		CKey *tmp=&local_09->second;
		if (tmp->Get_int_unk0x()==0) {
			m_KeyBuffer_.erase(local_09++);
		} else {
			local_09++;
		}
	}
	if (local_01>m_int_virtualKeyMax_) {
		mf_CMainControl_0570();
	}
	return;
}


void CMainControl::mf_CMainControl_7000()
{
	multimap<unsigned int,CKey>::iterator local_00;
	for (local_00=m_KeyBuffer_.begin(); local_00!=m_KeyBuffer_.end(); local_00++) {
		CKey * local_01=&local_00->second;
		if (local_01->m_int_unk0x==0||((unsigned int)strlen(local_01->mf_CKey_0260())<=(unsigned int)m_int_maxnamelen_70)) continue;
		local_01->m_int_unk0x=0;
	}
	return;
}


void CMainControl::mf_CMainControl_0730(CKey * arg_0)
{
	_in_addr local_00;
	if (arg_0->m_char_keyType_==KEYTYPE01) {
		ny_addrcrypter(&local_00,m_hostArray[0].m_ipaddr3);
		memcpy(&arg_0->m_ipaddr_0__,&local_00,4);
		arg_0->Set_portno_0(m_port_accept_);
		if (arg_0->m_bln_unk308) {
			memcpy(&arg_0->m_ipaddr_1__,&local_00,4);
			arg_0->Set_portno_1(m_port_accept_);
			return;
		}
		local_00.b1=0;
		local_00.b2='^';
		local_00.b3='^';
		local_00.b4='^';
		memcpy(&arg_0->m_ipaddr_1__,&local_00,4);
		arg_0->Set_portno_1(0);
	} else {
		if (arg_0->m_char_keyType_<KEYTYPE01) {
			arg_0->m_int_unk0x=0;
		}
	}
	return;
}


void CMainControl::mf_CMainControl_0740()
{
	multimap<unsigned int,CKey>::iterator local_00;
	for (local_00=m_KeyBuffer_.begin(); local_00!=m_KeyBuffer_.end(); local_00++) {
		CKey * local_01=&local_00->second;
		if ((local_01->m_int_unk0x==0||local_01->m_int_refcountOfFileptr_!=0)||!(local_01->m_char_keyType_==KEYTYPE03)&&local_01->m_char_keyType_!=KEYTYPE01||!local_01->m_bln_unk302) continue;
		local_01->m_bln_unk302=false;
		local_01->mf_CKey_0110();
	}
	return;
}


void CMainControl::mf_CMainControl_0750()
{
	multimap<unsigned int,CKey>::iterator local_00;
	for (local_00=m_KeyBuffer_.begin(); local_00!=m_KeyBuffer_.end(); local_00++) {
		CKey * local_01=&local_00->second;
		if (local_01->m_int_unk0x==0||local_01->m_int_refcountOfFileptr_!=0||local_01->m_char_keyType_==KEYTYPE02||local_01->m_char_keyType_<KEYTYPE01||!local_01->m_bln_unk308) continue;
		if (local_01->mf_CKey_0090()>0) {
			_unlink(local_01->mf_CKey_0210().c_str());
		}
		local_01->m_int_unk0x=0;
	}
	return;
}


void CMainControl::mf_CMainControl_0760()
{
	multimap<unsigned int,CKey>::iterator local_00;
	for (local_00=m_KeyBuffer_.begin(); local_00!=m_KeyBuffer_.end(); local_00++) {
		CKey * local_01=&local_00->second;
		if (local_01->m_int_unk0x==0) continue;
		local_01->m_bln_unk312=false;
	}
	return;
}


void CMainControl::mf_CMainControl_0770()
{
	int local_00;
	int local_01;
	if (!m_optflg_showVersionWarning_) {
		local_00=0;
		for (local_01=1; local_01<600; local_01++) {
			if (!m_hostArray[local_01].m_flgIsValid||m_hostArray[local_01].m_int_version<=12710) continue;
			local_00=local_00+1;
		}
		if (local_00>3) {
			m_optflg_showVersionWarning_=true;
		}
	}
	return;
}


struct struct_wk_0780 {
	char code;
	char data[100];	//ﾃｷﾄｳ
};


void CMainControl::mf_CMainControl_0780(int arg_0)
{
	int local_01;
	char local_33[1024];

	if (! (!(arg_0<0)&&arg_0<600) ) {
		return;
	}
	CRC4 local_00;
	for (local_01=0; local_01<5; local_01++) {
		if (!m_hostArray[arg_0].m_flgIsValid||!m_hostArray[arg_0].mf_CHost_0120()) break;
		CHost* local_02=m_hostArray+arg_0;
		int local_03=local_02->mf_CHost_0150(gbuf_recvbuf,0x00020000);
		if (local_03==0) continue;
		unsigned char local_04=gbuf_recvbuf[0];
		if (local_04==0) {
			char *local_05=((struct_wk_0780 *)gbuf_recvbuf)->data;
			local_00.setupkey("98789asj");
			local_00.crypter(gbuf_recvbuf+1,20);
			if ( memcmp(local_05+4,"Winny Ver2.0",12)==0&&(!(*((int *)local_05)<12660)&&*((int *)local_05)<12900||*((int *)local_05)>=20000&&*((int *)local_05)<21000) ) {
				local_02->SetVersion( *((int *)local_05) );
				if (*((int *)local_05)>12710) {
					mf_CMainControl_0770();
				}
				char local_06[8];
				local_02->m_flg_unk303=true;
				local_06[0]=*local_02->m_cryptseed_recv;
				local_06[1]=local_02->m_cryptseed_recv[1]^'9';
				local_06[2]=local_02->m_cryptseed_recv[2]^'9';
				local_06[3]=local_02->m_cryptseed_recv[3]^'9';
				local_06[4]=0;
				local_02->mf_CHost_0060(local_06);
			} else {
				local_02->mf_CHost_0190(true);
				return;
			}
			if (!local_02->m_flg_unk303) {
				local_02->mf_CHost_0190(true);
				return;
			}
			if (! (local_02->m_flgIsBBSNode_8||!m_flg_IsJoiningBBSCluster_) ) {
				char *local_07=((struct_wk_0780 *)gbuf_recvbuf)->data;
				gbuf_recvbuf[0]=5;
				*((int *)local_07)=m_port_bbsaccept_;
				mf_CMainControl_0370(arg_0,gbuf_recvbuf,5);
			}
		}
		if (! (local_04!=1||local_03<4) ) {
			float *tmp=(float *)(((struct_wk_0780 *)gbuf_recvbuf)->data);
			local_02->SetLineSpeed((int)(*tmp));
			continue;
		}
		if (! (local_04!=2||local_03<4) ) {
			unsigned char *local_08=((struct_wk_0780 *)gbuf_recvbuf)->data;
			local_02->SetflgIsPortZero((bool)(*(local_08+1)!=0));
			if (local_02->m_flg_isDownConnection) {
				local_02->SetflgIsBBSNode( (bool)(*(local_08+3)!=0) );
			}
			if (!local_02->m_flgUnknown_7F) {
				local_02->SetflgUnknown7F_( *(local_08+2)!=0 );
			}
			if (!local_02->m_flgIsTransferLink_8) {
				local_02->SetflgIsTransferLink( (bool)(*local_08!=0) );
			}
			if (local_02->m_flgIsPortZero_9) {
				local_02->m_flgUnknown_80=true;
			}
			if (!
				(
				 (
					!local_02->m_flg_isDownConnection
					||local_02->m_flg_IsBBSPort
					||*(local_08+2)!=0
					||*local_08!=1
				 )
				 ||!(m_int_CurrentTransferUpConnectionCount_>=m_int_currentTransferUpConnectionMax_)&&(!local_02->m_flgIsPortZero_9||m_int_CurrentTransferUpToPortzeroConnectionCount_<3))
				) {
char local_09;
				local_09=' ';
				mf_CMainControl_0370(arg_0,&local_09,1);
			}
			if (*local_08==2) {
				local_02->m_flgIsBBSNode_8=true;
				local_02->m_flgUnknown_80=true;
			}
			if (! (!m_optflg_UseBbsOnly_||local_02->m_flgUnknown_7F||local_02->m_flgIsBBSNode_8) ) {
				local_02->mf_CHost_0190(true);
				break;
			}
			if (! ((m_flg_IsJoiningBBSCluster_||local_02->m_flgUnknown_7F||!local_02->m_flgIsBBSNode_8)||!local_02->m_flg_isDownConnection&&!local_02->m_flgIsPortZero_9) ) {
				local_02->mf_CHost_0190(true);
				break;
			}
			continue;
			bool dummy;		//orphan jump 変数領域合わせは詰めていない
		} else {//orphan jump用
			if (! (local_04!=3||local_03<12) ) {
				unsigned char *local_10=((struct_wk_0780 *)gbuf_recvbuf)->data;
				unsigned char local_11;
				unsigned char local_12;
				unsigned char local_13;
				unsigned char local_14;
				local_14=*local_10;
				local_13=*(local_10+1);
				local_12=*(local_10+2);
				local_11=*(local_10+3);
				*((unsigned char *)(&local_02->m_ipaddr1.b1))=local_14;
				*((unsigned char *)(&local_02->m_ipaddr1.b2))=local_13;
				*((unsigned char *)(&local_02->m_ipaddr1.b3))=local_12;
				*((unsigned char *)(&local_02->m_ipaddr1.b4))=local_11;
				//!!44b276 生成が若干異なる
				local_02->SetflgIsNAT( local_02->IsnotInternalIpaddr_x2b( *(_in_addr *)&local_14 ) );
				local_02->SetPort( *((int *)(local_10+4)) );
				local_02->m_field_8D=true;
				unsigned int local_15;
				local_15=12;
				*(local_33+(unsigned int)*(local_10+8))=0;
				memcpy(local_33,local_10+local_15,(unsigned int)*(local_10+8));
				local_02->mf_CHost_0230(local_33);
				local_15+=(unsigned int)*(local_10+8);
				if (local_02->m_flgIsBBSNode_8) {
					for (int local_16=0; local_16<3; local_16++) {
						local_02->mf_CHost_0020(local_16,"");
					}
				} else {
					for (int local_17=0; local_17<3; local_17++) {
						*(local_33+(unsigned int)*((local_10+9)+local_17))=0;
						memcpy(local_33,local_10+local_15,(unsigned int)*((local_10+9)+local_17));
						local_02->mf_CHost_0020(local_17,local_33);
						local_15=local_15+(unsigned int)*((local_10+9)+local_17);
					}
				}
				mf_CMainControl_0790(arg_0);
				continue;
			}
			if (! (local_04!=4||local_03<20) ) {
				this->mf_CMainControl_1010(gbuf_recvbuf+1);
				continue;
			}
			if (! (local_04!=5||local_03<4) ) {
				char * local_18;  //これは直接代入表現にするとexblockが挿入されるのでダメ
				local_18=((struct_wk_0780 *)gbuf_recvbuf)->data;
				local_02->SetBbsPort(*((int *)local_18));
				int local_19;
				local_19=mf_CMainControl_0560(&local_02->m_ipaddr3,local_02->m_port1);
				m_hostArray[local_19].m_flgIsValid=true;
				m_hostArray[local_19].m_flgIsTransferLink_8=false;
				m_hostArray[local_19].m_flg_isDownConnection=true;
				m_hostArray[local_19].m_flgUnknown_80=false;
				m_hostArray[local_19].m_flgIsBBSNode_8=true;
				m_hostArray[local_19].SetPort(local_02->m_port1);
				m_hostArray[local_19].SetBbsPort(*((int *)local_18));
				m_hostArray[local_19].mf_CHost_0190(false);
				continue;
			}
			if (! (local_04!=10||local_03!=1) ) {
				mf_CMainControl_0850(arg_0);
				continue;
			}
			if (! (local_04!=11||local_03<32) ) {
				char * local_20;
				local_20=((struct_wk_0780 *)gbuf_recvbuf)->data;
				this->mf_CMainControl_0900(arg_0,*((int *)local_20),*((int *)(local_20+4)),*((int *)(local_20+8)),local_20+12,*((unsigned int *)(local_20+28)));
				continue;
			}
			if (local_04==12) {
				char * local_21;
				local_21=((struct_wk_0780 *)gbuf_recvbuf)->data;
				this->mf_CMainControl_1110(arg_0,local_21,local_21+256,*((int *)(local_21+272)),false);
				continue;
			}
			if (local_04==15) {
				char * local_22;
				local_22=((struct_wk_0780 *)gbuf_recvbuf)->data;
				this->mf_CMainControl_1110(arg_0,local_22,local_22+256,*((int *)(local_22+272)),true);
				continue;
			}
			if (local_04==13) {
				if (m_int_unk43>=20) continue;
				mf_CMainControl_1100(arg_0,gbuf_recvbuf,local_03,-1);
				continue;
			}
			if (! (local_04!=16||local_03!=1) ) {
				mf_CMainControl_0860(arg_0);
				continue;
			}
			if (! (local_04!=17||local_03<128) ) {
				const char *tmp;
				tmp=((struct_wk_0780 *)gbuf_recvbuf)->data;
				memcpy(gbuf_recvbuf,tmp,local_03);
				*(gbuf_recvbuf+local_03)=0;
				mf_CMainControl_1390(arg_0,gbuf_recvbuf);
				continue;
			}
			if (! (local_04!=21||local_03<9) ) {
				char * local_23;
				local_23=((struct_wk_0780 *)gbuf_recvbuf)->data;
				this->mf_CMainControl_0920(arg_0,*((int *)local_23),*((int *)(local_23+4)),local_23+8,(unsigned int)local_03-9);
				continue;
			}
			if (! (local_04!=22||local_03<8) ) {
				char * local_24;
				local_24=((struct_wk_0780 *)gbuf_recvbuf)->data;
				int local_25;
				local_25=this->mf_CMainControl_0560((_in_addr *)local_24,*((int *)(local_24+4)));
				m_hostArray[local_25].m_flgIsValid=true;
				m_hostArray[local_25].m_flgIsTransferLink_8=true;
				mf_CMainControl_0260(local_25,false);
				m_hostArray[local_25].m_flg_isDownConnection=true;
				m_hostArray[local_25].m_flgUnknown_80=true;
				continue;
			}
			if (! (local_04!=23||local_03<8) ) {
				char * local_26;
				local_26=((struct_wk_0780 *)gbuf_recvbuf)->data;
				char * local_27;
				local_27=local_26;
				*((char *)(&local_02->m_ipaddr2.b1))=*local_27;
				local_02->m_ipaddr2.b2=(unsigned char)*(local_27+1);
				local_02->m_ipaddr2.b3=(unsigned char)*(local_27+2);
				local_02->m_ipaddr2.b4=(unsigned char)*(local_27+3);
				local_02->SetPort3(*((int *)(local_26+4)));
				continue;
			}
			if (! (local_04!=24||local_03<17) ) {
				char * local_28;
				char * local_29;
				local_28=((struct_wk_0780 *)gbuf_recvbuf)->data;
				local_29=((struct_wk_0780 *)gbuf20000_hatena2)->data;
				gbuf20000_hatena2[0]=27;
				memcpy(local_29,local_28,16);
				*((int *)(local_29+16))=!(mf_CMainControl_1520(local_28,local_28+16)==0)?1:0;
				if (local_02->m_flg_IsBBSPort) continue;
				mf_CMainControl_0370(arg_0,gbuf20000_hatena2,21);
				continue;
			}
			if (! (local_04!=25||local_03<25) ) {
				char * local_30;
				local_30=((struct_wk_0780 *)gbuf_recvbuf)->data;
				this->mf_CMainControl_1490(arg_0,*((int *)(local_30+4)),local_30,local_30+8,local_30+24);
				continue;
			}
			if (! (local_04!=26||local_03<20) ) {
				char * local_31;
				local_31=((struct_wk_0780 *)gbuf_recvbuf)->data;
				this->mf_CMainControl_1500(arg_0,local_31,(*((int *)(local_31+16))!=0)?true:false);
				continue;
			}
			if (! (local_04!=27||local_03<20) ) {
				char * local_32;
				local_32=((struct_wk_0780 *)gbuf_recvbuf)->data;
				this->mf_CMainControl_1510(arg_0,local_32,(*((int *)(local_32+16))!=0)?true:false);
				continue;
			}
			if (local_04==' ') {
				local_02->m_field_7E=true;
				local_02->m_field_94=false;
				continue;
			}
			if (local_04=='!') {
				local_02->mf_CHost_0190(true);
				local_02->m_field_94=true;
				continue;
			}
			if (local_04=='"') {
				local_02->mf_CHost_0190(true);
				local_02->m_flgIgnoredWarning_8=true;
				continue;
			}
			if (local_04=='#') {
				local_02->mf_CHost_0190(true);
				local_02->m_field_88=true;
				continue;
			}
			if (local_04=='%') {
				local_02->mf_CHost_0190(true);
				local_02->m_flgNetsuzouWarning_8=true;
				continue;
			}
			if (local_04==0||!(local_04<'`')&&local_04<='c') continue;
			local_02->mf_CHost_0190(true);
		}//orphan jump用
	}
	return;
}


void CMainControl::mf_CMainControl_0790(int arg_0)
{
	if (! (arg_0<0||arg_0>=600||!m_hostArray[arg_0].m_flgIsValid) ) {
		if (! (m_hostArray[arg_0].m_int_lineSpeed!=m_int_linespeed_||m_hostArray[arg_0].m_port1!=m_port_accept_||strcmp((m_hostArray+arg_0)->m_sz_clusterword[0],m_hostArray->m_sz_clusterword[0])!=0||strcmp((m_hostArray+arg_0)->m_sz_clusterword[1],m_hostArray->m_sz_clusterword[1])!=0||strcmp((m_hostArray+arg_0)->m_sz_clusterword[2],m_hostArray->m_sz_clusterword[2])!=0) ) {
			m_hostArray[arg_0].mf_CHost_0190(true);
			m_hostArray[arg_0].m_flgIsValid=false;
		}
		if ((double)m_int_linespeed_<0.1) {
			m_int_linespeed_=1;
		}
		float local_00;
		local_00=(double)m_hostArray[arg_0].m_int_lineSpeed/(double)m_int_linespeed_;
		if (! (m_hostArray[arg_0].m_flgIsTransferLink_8||!(!(local_00<=1.2)&&local_00>19.9)&&(local_00>=1.0/1.2/*0.833333*/||local_00>=1.0/19.9/*0.0502513*/)) ) {
			//!!44bdf1 たぶんインライン
			CWork *tmp;
			tmp=m_vectorpCWork_[mf_CMainControl_0610()];
			tmp->mf_CWork_0130(arg_0,true);
			return;
		}
		if (! (m_hostArray[arg_0].m_flgIsPortZero_9||!(!m_hostArray[arg_0].m_flgIsTransferLink_8)&&m_hostArray[arg_0].m_flgIsBBSNode_8) ) {
			if (! (!m_hostArray[arg_0].m_flg_isDownConnection||m_hostArray[arg_0].m_flgUnknown_7F) ) {
				int local_01;
				_in_addr * local_02;
				CHost * local_03;
				local_01=this->mf_CMainControl_0560(&(m_hostArray+arg_0)->m_ipaddr3,m_hostArray[arg_0].m_port1);
				m_hostArray[local_01].m_flgIsValid=true;
				local_02=&(m_hostArray+arg_0)->m_ipaddr3;
				local_03=m_hostArray+local_01;
				local_03->m_ipaddr3.b1=local_02->b1;
				local_03->m_ipaddr3.b2=local_02->b2;
				local_03->m_ipaddr3.b3=local_02->b3;
				local_03->m_ipaddr3.b4=local_02->b4;
				m_hostArray[local_01].SetPort(m_hostArray[arg_0].m_port1);
				m_hostArray[local_01].m_flgIsTransferLink_8=true;
				m_hostArray[local_01].m_flgUnknown_7F=true;
				mf_CMainControl_0260(local_01,false);
			}
		} else {
			m_hostArray[arg_0].m_flgUnknown_80=true;
		}
		if (! ((m_hostArray[arg_0].m_flgIsPortZero_9||m_optflag_notConnected__||m_hostArray[arg_0].m_flgIsTransferLink_8)||!(local_00>1.5)&&local_00>=2.0/3.0/*0.666667*/) ) {
			bool tmp=(local_00>1.0);
			m_hostArray[arg_0].m_flg_isDownConnection=((tmp!=false)?false:true);
		}
		if (! (m_hostArray[arg_0].m_flgIsTransferLink_8||!m_hostArray[arg_0].m_flgIsPortZero_9) ) {
			m_hostArray[arg_0].m_flg_isDownConnection=true;
		}
		if (! (m_flg_IsJoiningBBSCluster_||!m_hostArray[arg_0].m_flgIsBBSNode_8) ) {
			m_hostArray[arg_0].m_flg_isDownConnection=false;
		}
	}
	return;
}



void CMainControl::mf_CMainControl_0800()
{
	int local_00;
	int local_01;
	int local_02;
	unsigned int local_03;

	m_int_unk20=0;
	local_01=0;
	local_02=-1;
	local_03=0xFFFFFFFF;
	if (!m_flg_unk200) {
		mf_CMainControl_0280();
	}
	if (!m_flg_unk201) {
		mf_CMainControl_0300();
	}
	for (local_00=0; m_vectorpCWork_.size()>local_00; local_00++) {
		if (/**/(*GetWorkNP(local_00))->GetWorkType()!=WORKTYPE00) {
			local_01=local_01+1;
		}
		if (! (/**/(*GetWorkNP(local_00))->GetWorkType()!=WORKTYPE01||/**/(*GetWorkNP(local_00))->IsFinished()||/**/(int)((*GetWorkNPx(local_00))->m_uint_countNow)<=(int)0||/**/(*GetWorkNP(local_00))->Get_flgkasiraso_()) ) {
			m_int_unk20=m_int_unk20+1;
		}
		if (/**/(*GetWorkNP(local_00))->IsFinished()||!(/**/(*GetWorkNP(local_00))->GetWorkType()==WORKTYPE03)&&/**/(*GetWorkNP(local_00))->GetWorkType()!=WORKTYPE02) continue;
		if (/**/(*GetWorkNP(local_00))->GetCountMax()<local_03) {
			local_03=/**/(*GetWorkNP(local_00))->GetCountMax();
			local_02=local_00;
		}
		CWork *tmp;
		tmp=(*GetWorkNP(local_00));
		tmp->m_flgkasiraso_2=true;
	}
	ny_nazo(3.1);
	if (! (m_flg_unk15509||local_02<0) ) {
		/**/(*GetWorkNP(local_02))->Set_flgkasiraso_2(false);
	}
	for (local_00=0; m_vectorpCWork_.size()>local_00; local_00++) {
		if (/**/(*GetWorkNP(local_00))->GetWorkType()==WORKTYPE00) continue;
		if (/**/(*GetWorkNP(local_00))->IsFinished()) {
			if (!(/**/(*GetWorkNP(local_00))->GetWorkType()>WORKTYPE04||local_01>80)&&!/**/(*GetWorkNP(local_00))->Get_flgkasiraso_3()) continue;
			/**/(*GetWorkNP(local_00))->SetWorkType(WORKTYPE00);
			local_01=local_01-1;
			continue;
		}
		if (/**/(*GetWorkNP(local_00))->Get_flgkasiraso_2()||!(!m_flg_unk15509||/**/(*GetWorkNP(local_00))->Get_flgkasiraso_3())&&(/**/(*GetWorkNP(local_00))->GetWorkType()==WORKTYPE02||/**/(*GetWorkNP(local_00))->GetWorkType()==WORKTYPE03)) continue;
		if (/**/(*GetWorkNP(local_00))->Get_int_unk304()>0) {
			CWork * local_04;
			local_04=m_vectorpCWork_[local_00];
			local_04->m_int_unk304=local_04->m_int_unk304-1;
			continue;
		}

		unsigned int local_05;
		CWork *tmp=(*GetWorkNP(local_00));
		local_05=tmp->m_tick_2_=GetTickCount();
		if (! (/**/(*GetWorkNP(local_00))->GetWorkType()==WORKTYPE02||/**/(*GetWorkNP(local_00))->GetWorkType()==WORKTYPE03||/**/(*GetWorkNP(local_00))->GetWorkType()==WORKTYPE07
		  ||local_05-/**/(*GetWorkNP(local_00))->Get_tick_created()<=/**/(*GetWorkNP(local_00))->Get_uint_unk305()) ) {
			int local_06;
			local_06=/**/(*GetWorkNP(local_00))->GetHostIdx();
			if (local_06>=0) {
				CHost * local_07;
				local_07=m_hostArray+local_06;
				if (! (!local_07->m_flgIsValid||local_07->m_flg_IsBBSPort) ) {
					char local_08;
					local_08=31;	//ここ多分バグと過去に判断しているが、詳細未確認
					mf_CMainControl_0370(local_06,&local_08,1);
					local_07->mf_CHost_0190(true);
				}
				m_flgarray_unk[0]=true;
				m_flgarray_unk[4]=true;
				m_flgarray_unk[5]=true;
				m_flgarray_unk[6]=true;
			}
			m_vectorpCWork_[local_00]->mf_CWork_0030();
			CWork * local_09;
			local_09=m_vectorpCWork_[local_00];
			if (local_09->m_pchar_status_!=0) {
				strcpy(local_09->m_pchar_status_,"タイムアウト");
			}
			if (/**/(*GetWorkNP(local_00))->GetWorkType()==WORKTYPE01) {
				CKey * local_10;
				local_10=mf_CMainControl_0180(/**/(*GetWorkNP(local_00))->GetCountMax(),/**/(*GetWorkNP(local_00))->Get_uchar16_unk1());
				if (! (local_10==0||local_10->m_bln_unk308) ) {
					m_int_downTrial_NumberOfTimeout_=m_int_downTrial_NumberOfTimeout_+1;
				}
			}
			if (/**/(*GetWorkNP(local_00))->GetWorkType()!=WORKTYPE08) continue;
			m_vectorpCWork_[local_00]->mf_CWork_0010(true,false);
			continue;
		}
		switch ((int)/**/(*GetWorkNP(local_00))->GetWorkType()) {
		case 1:
			mf_CMainControl_0890(local_00);
			g_int_unk405=g_int_unk405+1;
			break;
		case 5:
			g_int_unk405=g_int_unk405+1;
			mf_CMainControl_0910(local_00);
			break;
		case 2:
			g_int_unk405=g_int_unk405+1;
			mf_CMainControl_0960(local_00);
			break;
		case 3:  
			g_int_unk405=g_int_unk405+1;
			mf_CMainControl_0990(local_00);
			break;
		case 6:  
			mf_CMainControl_1000(local_00);
			break;
		case 4:  
			mf_CMainControl_0440(local_00);
			g_int_unk403=g_int_unk403+1;
			break;
		case 7:  
			mf_CMainControl_0450(local_00);
			break;
		case 8:  
			mf_CMainControl_1460(local_00);
			break;
		case 9:  
			mf_CMainControl_1530(local_00);
			break;
		case 10:  
			mf_CMainControl_1560(local_00);
		}
	}
	ny_nazo(3.2);

	int local_11;
	int local_12;

	local_11=(int)GetTickCount();
	if (g_int_unk407%10==0) {
		mf_CMainControl_1060();
	}
	g_int_unk407=g_int_unk407+1;
	if (g_int_unk407>100) {
		g_int_unk407=0;
	}
	ny_nazo(3.3);
	if ((unsigned int)local_11-(unsigned int)g_int_unk406>1000) {
		m_flgarray_unk[4]=true;
		m_flgarray_unk[5]=true;
		m_flgarray_unk[6]=true;
		m_flgarray_unk[0]=true;
		m_flgarray_unk[1]=true;
		m_flgarray_unk[8]=true;
		mf_CMainControl_0170(0);
		ny_nazo(3.31);
		mf_CMainControl_1140();
		ny_nazo(3.32);
		if (g_int_unk408%20==0) {
			mf_CMainControl_1200();
		}
		ny_nazo(3.33);
		if (g_int_unk408++%5==2) {
			mf_CMainControl_0720();
		}
		ny_nazo(3.34);
		if (g_int_unk408%296==0) {
			mf_CMainControl_0420();
		}
		m_int_unk30=m_int_unk30+1;
		if (! (!m_flg_IsBBSSearchLinkOn_||m_int_unk30<=300||m_flg_IsJoiningBBSCluster_) ) {
			m_flg_IsBBSSearchLinkOn_=false;
			mf_CMainControl_0340();
		}
		if (g_int_unk408%302==0) {
			mf_CMainControl_0430();
		}
		ny_nazo(3.4);
		if (m_optflag_Connect__) {
			m_int_downTrial_TimeInSec_=m_int_downTrial_TimeInSec_+1;
		}
		m_int_uptimeInSec_=m_int_uptimeInSec_+1;
		if (m_int_uptimeInSec_>60000) {
			m_int_uptimeInSec_=0;
		}
		if (m_int_uptimeInSec_%30==0) {
			mf_CMainControl_0830();
		}
		if (m_int_uptimeInSec_%10==0) {
			mf_CMainControl_0840();
		}
		if (m_int_uptimeInSec_%30==15) {
			mf_CMainControl_1160();
		}
		if (! (  !(m_int_virtualKeyMax_*100 < m_KeySearchTable_.size()) && m_int_unk21<=0 ) ) {
			mf_CMainControl_0570();
		}
		ny_nazo(3.5);
		local_12=m_int_linespeed_/80+8;
		if (! (!(m_int_currentTransferUpConnectionMax_>local_12||m_int_related_maxconnection__>local_12||m_int_CurrentTransferUpConnectionCount_>local_12)&&m_int_CurrentTransferDownConnectionCount_<=local_12) ) {
			mf_CMainControl_0350();
		}
		m_flgarray_unk[8]=true;
		if (g_int_unk403>0) {
			m_flgarray_unk[2]=true;
		}
		if (g_int_unk404>0) {
			m_flgarray_unk[9]=true;
			m_flgarray_unk[3]=true;
		}
		if (g_int_unk405>0) {
			m_flgarray_unk[4]=true;
			m_flgarray_unk[5]=true;
			m_flgarray_unk[6]=true;
		}
		g_int_unk403=0;
		g_int_unk404=0;
		g_int_unk405=0;
		int local_13;
		local_13=0;
		for (local_00=0; m_vectorpCWork_.size()>local_00; local_00++) {
			if (/**/(*GetWorkNP(local_00))->IsFinished()) continue;
			if (! (!(/**/(*GetWorkNP(local_00))->GetWorkType()==WORKTYPE01||/**/(*GetWorkNP(local_00))->GetWorkType()==WORKTYPE03)&&/**/(*GetWorkNP(local_00))->GetWorkType()!=WORKTYPE02) ) {
				m_vectorpCWork_[local_00]->mf_CWork_0050();
			}
			if (/**/(*GetWorkNP(local_00))->GetWorkType()!=WORKTYPE03||/**/(*GetWorkNP(local_00))->IsFinished()) continue;
			local_13=local_13+1;
		}
		if (local_13>=10) {
			if (m_flg_unk15509) {
				m_flg_unk15509=false;
			} else {
				m_flg_unk16400=true;
			}
		} else {
			m_flg_unk16400=false;
		}
		if (m_int_uptimeInSec_%600==0) {
			m_double_14424=0.0;
		}
		m_double_upKBytePerSec_=0.0;
		m_double_downKBytePerSec_=0.0;
		if (m_optflag_Connect__) {
			m_arraydouble_unk10[m_int_unk15]=(double)m_int_14416;
			m_arraydouble_unk11[m_int_unk15]=(double)m_int_14420;
			m_int_unk15=m_int_unk15+1;
			double local_14;
			double local_15;
			local_14=0.0;
			local_15=0.0;
			for (local_00=0; local_00<m_uint_unk14; local_00++) {
				local_14=m_arraydouble_unk10[local_00]+local_14;
				local_15=m_arraydouble_unk11[local_00]+local_15;
			}
			m_uint_unk14=m_uint_unk14+1;
			if (m_uint_unk14>=60) {
				m_uint_unk14=60;
			}
			if (m_int_unk15>=60) {
				m_int_unk15=0;
			}
			if (m_uint_unk14!=0) {
				m_double_upKBytePerSec_=(local_14/(double)m_uint_unk14)/1000.0;
				m_double_downKBytePerSec_=(local_15/(double)m_uint_unk14)/1000.0;
			}
		}
		if (m_double_14424<m_double_upKBytePerSec_) {
			m_double_14424=m_double_upKBytePerSec_;
		}
		m_int_currentTransferUpConnectionMax_=(int)(m_double_upKBytePerSec_/80.0);
		m_int_currentTransferUpConnectionMax_=m_int_currentTransferUpConnectionMax_+1;
		m_int_currentTransferUpConnectionMax_=m_int_currentTransferUpConnectionMax_+1;
		if (m_int_currentTransferUpConnectionMax_<2) {
			m_int_currentTransferUpConnectionMax_=2;
		}
		if (m_int_related_maxconnection__+2<m_int_currentTransferUpConnectionMax_) {
			m_int_currentTransferUpConnectionMax_=m_int_related_maxconnection__+2;
		}
		m_int_14416=0;
		m_int_14420=0;
		g_int_unk406=local_11;
		ny_nazo(3.6);
		for (local_00=0; m_vectorpCWork_.size()>local_00; local_00++) {
			if (/**/(*GetWorkNP(local_00))->GetWorkType()==WORKTYPE00
			  ||!/**/(*GetWorkNP(local_00))->IsFinished()) continue;
			if (/**/(*GetWorkNP(local_00))->Get_int_unk34()>0) {
				CWork * local_16;
				local_16=m_vectorpCWork_[local_00];
				local_16->m_int_unk34=local_16->m_int_unk34-1;
			}
			if (/**/(*GetWorkNP(local_00))->Get_flg_unk212()||/**/(*GetWorkNP(local_00))->Get_int_unk34()!=0) continue;
			/**/(*GetWorkNP(local_00))->SetWorkType(WORKTYPE00);
			m_flgarray_unk[4]=true;
			m_flgarray_unk[5]=true;
			m_flgarray_unk[6]=true;
		}
		mf_CMainControl_0400();
		ny_nazo(3.7);
		m_int_unk42=m_int_unk42+1;
		if (m_optflg_autoDisconnect_) {
			if (m_int_unk42>600) {
				mf_CMainControl_0330(false);
			}
		} else {
			if (m_int_unk42>3600) {
				mf_CMainControl_0330(false);
			}
		}
		ny_nazo(3.71);
		if (m_int_uptimeInSec_%30==3) {
			mf_CMainControl_1370();
		}
		ny_nazo(3.8);
		if (m_optflg_downRetryFast_) {
			int local_17;
			for (local_17=0; local_17<2; local_17++) {
				mf_CMainControl_1260();
			}
		} else {
			if (m_int_uptimeInSec_%2==0) {
				mf_CMainControl_1260();
			}
		}
		mf_CMainControl_1270();
		ny_nazo(3.9);
		mf_CMainControl_1290();
		ny_nazo(3.91);
		mf_CMainControl_1150();
		mf_CMainControl_1170();
		ny_nazo(3.92);
		if (g_pproc_SetThreadExecutionState!=0) {
			g_pproc_SetThreadExecutionState(1);
		}
#ifndef _DEBUG
		if (! (m_int_uptimeInSec_%600!=0||!IsDebuggerPresent()) ) {
			exit(0);
		}
#endif
	}
	return;
}


void CMainControl::mf_CMainControl_0810()
{
	int local_00;
	for (local_00=1; local_00<600; local_00++) {
		if (!m_hostArray[local_00].m_flgIsValid||!m_hostArray[local_00].m_flgIsConnected) continue;
		m_hostArray[local_00].mf_CHost_0180();
	}
	return;
}


void CMainControl::mf_CMainControl_0820()
{
	unsigned	int local_00;
	m_int_unk43=0;
	for (local_00=0; m_vectorCQuery_.size()>local_00; local_00++) {
		if (!m_vectorCQuery_[local_00].Get_flg_unk04()) continue;
		m_int_unk43=m_int_unk43+1;
	}
	for (local_00=1; local_00<600; local_00++) {
		CHost * local_01=m_hostArray+local_00;
		if (!local_01->m_flgIsValid||!local_01->m_flgIsConnected||local_01->m_flg_IsBBSPort) continue;
		mf_CMainControl_0780(local_00);
	}
	return;
}


void CMainControl::mf_CMainControl_0830()
{
	int local_00;
	char local_01;
	for (local_00=1; local_00<600; local_00++) {
		if (!m_hostArray[local_00].m_flgIsValid||m_hostArray[local_00].m_flg_IsBBSPort||!m_hostArray[local_00].m_field_8D||!m_hostArray[local_00].m_flgIsConnected||m_hostArray[local_00].m_flgIsTransferLink_8||m_hostArray[local_00].m_int_connectionTimeInSec<=5) continue;
		local_01=10;
		mf_CMainControl_0370(local_00,&local_01,1);
	}
	return;
}


void CMainControl::mf_CMainControl_0840()
{
	int local_00;
	char local_01;
	if (m_flg_IsJoiningBBSCluster_) {
		for (local_00=1; local_00<600; local_00++) {
			if (!m_hostArray[local_00].m_flgIsValid||!m_hostArray[local_00].m_flgIsBBSNode_8||m_hostArray[local_00].m_flgIsPortZero_9||m_hostArray[local_00].m_flg_IsBBSPort||!m_hostArray[local_00].m_field_8D||!m_hostArray[local_00].m_flgIsConnected||m_hostArray[local_00].m_flgIsTransferLink_8||m_hostArray[local_00].m_int_connectionTimeInSec<=5) continue;
			local_01=16;
			mf_CMainControl_0370(local_00,&local_01,1);
		}
	}
	return;
}


void CMainControl::mf_CMainControl_0850(int arg_0)
{
	if (! (arg_0<1||arg_0>=600||!m_hostArray[arg_0].m_flgIsValid||!m_hostArray[arg_0].m_flgIsConnected) ) {
		if (m_hostArray[arg_0].GetflgIsUpConnection()) {
			mf_CMainControl_1110(arg_0,"","",m_int_unk41,false);
			return;
		}
		mf_CMainControl_1120(arg_0,"","",m_int_unk41,false);
	}
	return;
}


void CMainControl::mf_CMainControl_0860(int arg_0)
{
	if (! (!m_flg_IsJoiningBBSCluster_||arg_0<1||arg_0>=600||!m_hostArray[arg_0].m_flgIsValid||!m_hostArray[arg_0].m_flgIsConnected) ) {
		if (m_hostArray[arg_0].GetflgIsUpConnection()) {
			mf_CMainControl_1110(arg_0,"","",m_int_unk41,true);
			return;
		}
		mf_CMainControl_1120(arg_0,"","",m_int_unk41,true);
	}
	return;
}


void CMainControl::mf_CMainControl_0870(const char * arg_0,const char * arg_1)
{
	char * local_00;
	int local_01;
	char local_02[1024];
	local_00=local_02+1;
	local_02[0]=12;
	strcpy(local_00,arg_0);
	strcpy(local_00+256,arg_1);
	*((int *)(local_00+272))=m_int_unk41;
	for (local_01=1; local_01<600; local_01++) {
		if (!m_hostArray[local_01].m_flgIsValid||m_hostArray[local_01].m_flgIsBBSNode_8||!m_hostArray[local_01].m_field_8D||!m_hostArray[local_01].m_flgIsConnected||!m_hostArray[local_01].m_flg_isDownConnection||m_hostArray[local_01].m_flgIsTransferLink_8||m_hostArray[local_01].m_flg_IsBBSPort) continue;
		mf_CMainControl_0370(local_01,local_02,277);
	}
	return;
}


Bb CMainControl::mf_CMainControl_0880(unsigned int arg_0,unsigned char * arg_1,int arg_2,int arg_3,bool * arg_4,int * arg_5,char * arg_6)
{
	bool local_00;
	CKey * local_01;
	char local_16[256];

	local_00=false;
	*arg_4=false;
	*arg_5=-1;
	local_01=this->mf_CMainControl_0180(arg_0,(unsigned char *)arg_1);
	if (! (!(local_01==0)&&local_01->m_int_unk0x!=0) ) {
		if (arg_6!=0) {
			strcpy(arg_6,"キーロスト");
		}
	} else {
		CKey * local_02;
		_in_addr local_03;
		local_02=local_01;
		if (!mf_CMainControl_1180(local_02)) {
			if (arg_6!=0) {
				strcpy(arg_6,"ダウン不可能");
			}
			return false;
		}
		if (! (local_02->m_bln_unk308||m_int_currentTransferUpConnectionMax_+2>=m_int_CurrentTransferDownConnectionCount_) ) {
			return false;
		}
		if (! (local_02->m_bln_unk308||!m_flag_cacheFolderDiskFull_&&!m_flag_downFolderDiskFull_) ) {
			return false;
		}
		local_03.b1=local_02->m_ipaddr_0__.b1;
		local_03.b2=local_02->m_ipaddr_0__.b2^'^';
		local_03.b3=local_02->m_ipaddr_0__.b3^'^';
		local_03.b4=local_02->m_ipaddr_0__.b4^'^';
		if (! (!local_02->m_bln_unk308||local_02->m_portno_0__!=m_port_accept_||!(m_hostArray[0].IsInternalIpaddr_x2b(local_03))) ) {
			local_03.b1=local_02->m_ipaddr_1__.b1;
			local_03.b2=local_02->m_ipaddr_1__.b2^'^';
			local_03.b3=local_02->m_ipaddr_1__.b3^'^';
			local_03.b4=local_02->m_ipaddr_1__.b4^'^';
			local_02->Set_ipaddr_0(local_02->GetIpaddr1());
			local_02->Set_portno_0(local_02->m_portno_1__);
		}
		if (! (!(m_hostArray[0].IsInternalIpaddr_x2b(local_03))||m_port_accept_!=local_02->m_portno_0__) ) {
			if (arg_6!=0) {
				if (local_02->m_char_keyType_==KEYTYPE02) {
					strcpy(arg_6,"自己スレッド");
				} else {
					strcpy(arg_6,"キャッシュ出力");
				}
			}
			return false;
		}
		if (!local_02->m_bln_unk308) {
			if (m_optflg_UseBbsOnly_) {
				return false;
			}
			unsigned int local_04;
			for (local_04=0; m_vectorpCWork_.size()>local_04; local_04++) {
				if (/**/(*GetWorkNP(local_04))->GetWorkType()!=WORKTYPE01||/**/(*GetWorkNP(local_04))->IsFinished()) continue;
				int local_05;
				local_05=/**/(*GetWorkNP(local_04))->GetHostIdx();
				if (local_05<0) continue;
				CHost * local_06;
				local_06=m_hostArray+local_05;
				if (local_06->IsInternalIpaddr_x2b(local_03) && local_06->m_port1==local_02->m_portno_0__) {
					return false;
				}
			}
		} else {
			m_int_unk30=0;
		}
		unsigned int local_07;
		local_07=0;
		for (local_07=0; m_IgnoreCondition_.size()>local_07; local_07++) {
			CAutoDownList * local_08;
			local_08=&m_IgnoreCondition_[local_07];
			if (!(local_08->m_double_unk9<=0.0)&&(double)local_02->m_uint_unk13*(float)9.5367432e-007>local_08->m_double_unk9||!(local_08->m_double_unk10<=0.0)&&(double)local_02->m_uint_unk13*(float)9.5367432e-007<local_08->m_double_unk10||!(!local_08->m_flag_unk5)&&!local_02->m_bln_unk308||!local_08->m_flag_unk5&&local_02->m_bln_unk308) continue;
			if (local_08->mf_CAutoDownList_0010()) {
				if (memcmp(local_08->m_hash,local_02->m_hash_tabun,16)!=0) continue;
				break;
			}
			if (strlen(local_08->m_char256_unk1)<2) continue;
			if (!local_02->mf_CKey_0040(local_08->m_char256_unk1,local_08->m_char256_unk2,true)) continue;
			break;
		}
		if (m_IgnoreCondition_.size()>local_07) {
			if (arg_6!=0) {
				strcpy(arg_6,"無視条件ヒット");
			}
			return false;
		}
		if (local_02->m_char_keyType_==KEYTYPE02) {
			if (arg_6!=0) {
				strcpy(arg_6,"アップファイル");
			}
			return false;
		}
		if (local_02->m_char_keyType_==KEYTYPE03) {
			if (local_02->m_bln_unk308) {
				local_02->mf_CKey_0290();
				if (arg_6!=0) {
					strcpy(arg_6,"キャッシュ更新");
				}
			} else {
				return false;
			}
		}

		bool local_09;
		bool local_10;
		int local_11;
		local_09=false;
		local_10=false;
		local_11=0;
		for (local_07=1; local_07<600; local_07++) {
			if (!m_hostArray[local_07].m_flgIsValid||!m_hostArray[local_07].m_field_8D||!m_hostArray[local_07].m_flgIsPortZero_9||m_hostArray[local_07].m_port1!=local_02->m_portno_0__||!(m_hostArray[local_07].IsInternalIpaddr(local_03))) continue;
			local_10=true;
			if (!m_hostArray[local_07].m_flgIsConnected) continue;
			local_09=true;
			local_11=local_07;
		}
		if (! (!local_10||local_09) ) {
			if (local_02->m_char_keyType_<=KEYTYPE01) {
				mf_CMainControl_0730(local_02);
			}
			return false;
		}
		if (!local_09) {
			local_11=mf_CMainControl_0560(&local_03,local_02->m_portno_0__);
			m_hostArray[local_11].m_flgIsValid=true;
			CHost * local_12;
			local_12=m_hostArray+local_11;
			local_12->m_ipaddr3.b1=local_03.b1;
			local_12->m_ipaddr3.b2=local_03.b2;
			local_12->m_ipaddr3.b3=local_03.b3;
			local_12->m_ipaddr3.b4=local_03.b4;
			m_hostArray[local_11].SetPort(local_02->m_portno_0__);
		} else {
			if (! (arg_2<0||m_hostArray[arg_2].m_flgIsPortZero_9) ) {
				unsigned char * local_13;
				local_13=(unsigned char *)(local_16+1);
				local_16[0]=22;
				*local_13=(m_hostArray+arg_2)->m_ipaddr3.b1;
				*(local_13+1)=(m_hostArray+arg_2)->m_ipaddr3.b2;
				*(local_13+2)=(m_hostArray+arg_2)->m_ipaddr3.b3;
				*(local_13+3)=(m_hostArray+arg_2)->m_ipaddr3.b4;
				*((int *)(local_13+4))=m_hostArray[arg_2].m_port1;
				mf_CMainControl_0370(local_11,local_16,9);
				unsigned char * local_14;
				local_14=(unsigned char *)(local_16+1);
				local_16[0]=23;
				*local_14=(m_hostArray+local_11)->m_ipaddr3.b1;
				*(local_14+1)=(m_hostArray+local_11)->m_ipaddr3.b2;
				*(local_14+2)=(m_hostArray+local_11)->m_ipaddr3.b3;
				*(local_14+3)=(m_hostArray+local_11)->m_ipaddr3.b4;
				*((int *)(local_14+4))=m_hostArray[local_11].m_port1;
				mf_CMainControl_0370(arg_2,local_16,9);
				*arg_4=true;
				return true;
			}
		}
		local_02->mf_CKey_0100();
		local_02->m_bln_unk302=false;
		if (!local_02->m_bln_unk308) {
			m_int_downTrial_NumberOfTry_=m_int_downTrial_NumberOfTry_+1;
			m_double_totalFileSize_+=(double)(local_02->m_uint_unk13>>20);
			m_double_totalReferenceSize_+=(double)(local_02->GetRefs());
		}
		bool local_15;
		local_15=mf_CMainControl_1250(arg_1,arg_0);
		if (! (!local_02->m_bln_unk308&&m_int_related_maxconnection__+2<m_int_currentTransferUpConnectionMax_) ) {
			*arg_5=mf_CMainControl_0610();
			if (!local_09) {
				if (local_02->m_bln_unk308) {
					m_hostArray[local_11].m_flgIsBBSNode_8=true;
				}
				m_hostArray[local_11].m_flgIsTransferLink_8=true;
				mf_CMainControl_0260(local_11,false);
			}
			g_int_unk409=g_int_unk409+1;
			m_vectorpCWork_[*arg_5]->mf_CWork_0090(local_11,arg_0,(unsigned char *)arg_1,g_int_unk409,arg_2);
			/**/(*GetWorkNP(*arg_5))->Set_flgkasiraso_1(local_09);
			local_03.b1=m_hostArray->m_ipaddr3.b1;
			local_03.b2=m_hostArray->m_ipaddr3.b2^'^';
			local_03.b3=m_hostArray->m_ipaddr3.b3^'^';
			local_03.b4=m_hostArray->m_ipaddr3.b4^'^';
			local_02->Set_portno_0(m_port_accept_);
			memcpy(&local_02->m_ipaddr_0__,&local_03,4);
			local_02->m_bln_unk305=false;
			if (local_02->m_bln_unk308) {
				local_02->mf_CKey_0180(local_02->mf_CKey_0170()-1,0);
				if (local_02->m_char_keyType_==KEYTYPE03) {
					local_02->m_char_keyType_=KEYTYPE01;
				}
				local_02->mf_CKey_0110();
			}
			local_02->m_bln_unk314=true;
			if (local_15) {
				/**/(*GetWorkNP(*arg_5))->SetCountNow(0);
			} else {
				/**/(*GetWorkNP(*arg_5))->SetCountNow(arg_3<<16);
				if (arg_6!=0) {
					strcpy(arg_6,"接続中");
				}
				/**/(*GetWorkNP(*arg_5))->Set_pchar_status_(arg_6);
			}
			local_00=true;
		}
	}
	m_flgarray_unk[4]=true;
	m_flgarray_unk[5]=true;
	m_flgarray_unk[6]=true;
	return local_00;
}


void CMainControl::mf_CMainControl_0890(int arg_0)
{
	char local_25[256];

	CWork *	local_00=m_vectorpCWork_[arg_0];
	double	local_01=200.0;
	CKey *	local_02=mf_CMainControl_0180(local_00->GetCountMax(),local_00->m_uchar16_unk1);
	if (local_02==0) return;
	if (local_00->m_flgkasiraso_) {
		bool local_03;
		int local_04;
		local_03=false;
		local_04=local_00->m_hostIdx_;
		if (! (local_04<0||!m_hostArray[local_04].m_flgIsValid) ) {
			if (m_hostArray[local_04].m_flgIsConnected) {
				local_00->m_flgkasiraso_=false;
				local_00->m_int_unk304=1;
				if (! (local_02==0||local_02->m_int_unk0x==0||local_02->mf_CKey_0150()!=0) ) {
					local_02->mf_CKey_0080();
					local_02->m_char_keyType_=KEYTYPE01;
					if (!local_02->m_bln_unk308) {
						local_02->SetRefs(0);
					} else {
						m_flgarray_unk[10]=true;
					}
					if (local_00->m_pchar_status_!=0) {
						strcpy(local_00->m_pchar_status_,"ダウン開始");
					}
				}
			} else {
				if (m_hostArray[local_04].m_field_8C) {
					local_00->m_flgkasiraso_=false;
				} else {
					local_03=true;
				}
			}
		} else {
			local_00->m_flgkasiraso_=false;
		}
		if (local_03) return;
	}

	int local_05;
	char local_06;
	local_05=local_00->m_hostIdx_;
	local_06=0;
	if (! (!(local_05<0||!m_hostArray[local_05].m_flgIsValid||!m_hostArray[local_05].m_flgIsConnected)&&(!(!(local_06==0||local_02==0)&&!local_02->m_bln_unk308)&&(local_02->m_bln_unk308||!m_optflg_UseBbsOnly_))) ) {
		local_00->mf_CWork_0010(false,true);
		if (! (!m_hostArray[local_05].m_flgIsValid||!m_hostArray[local_05].m_field_7E) ) {
			local_00->m_int_errorcode_kamo_=11;
			if (local_00->m_pchar_status_!=0) {
				strcpy(local_00->m_pchar_status_,"接続限界");
			}
			if (!local_02->m_bln_unk308) {
				m_int_downTrial_LimitTryCount_=m_int_downTrial_LimitTryCount_+1;
			} else {
				m_flgarray_unk[10]=true;
			}
		} else {
			if (m_hostArray[local_05].m_field_8C) {
				local_00->m_int_errorcode_kamo_=15;
				if (local_00->m_pchar_status_!=0) {
					strcpy(local_00->m_pchar_status_,"ノードロスト");
				}
			} else {
				local_00->m_int_errorcode_kamo_=4;
				if (local_00->m_pchar_status_!=0) {
					strcpy(local_00->m_pchar_status_,"接続切断");
				}
			}
			if (!local_02->m_bln_unk308) {
				m_int_downTrial_NumberOfKeylostDisconnect_=m_int_downTrial_NumberOfKeylostDisconnect_+1;
			} else {
				m_flgarray_unk[10]=true;
			}
		}
		if (local_02!=0) {
			mf_CMainControl_0730(local_02);
		}
		int local_07;
		local_07=local_00->m_hostIdx_mouikko_;
		if (! (local_07<0||!m_hostArray[local_07].m_flgIsValid||!m_hostArray[local_07].m_flgIsConnected||!m_hostArray[local_07].m_flgIsTransferLink_8) ) {
			char local_08;
			local_08=31;
			if (! (!m_hostArray[local_05].m_flgIsValid||!m_hostArray[local_05].m_field_7E) ) {
				local_08=' ';
			}
			mf_CMainControl_0370(local_07,&local_08,1);
		}
		return;
	}
	if (! (!(!m_hostArray[local_05].m_field_8D||m_hostArray[local_05].m_int_lineSpeed<=0)&&m_hostArray[local_05].m_int_connectionTimeInSec>=2) ) {
		if (local_00->m_pchar_status_!=0) {
			strcpy(local_00->m_pchar_status_,"接続中");
		}
		local_00->m_int_unk30=0;
		local_00->m_int_unk304=1;
		return;
	}
	if (local_00->m_pchar_status_!=0) {
		strcpy(local_00->m_pchar_status_,"受信中");
	}

	_in_addr local_09;
	ny_addrcrypter(&local_09,m_hostArray[local_05].m_ipaddr3);
	if (local_02!=0) {
		memcpy(&local_02->m_ipaddr_2__,&local_09,4);
		local_02->Set_portno_2(m_hostArray[local_05].m_port1);
	}
	if (memcmp(m_hash_exeHash_,g_exesignature_defined,16)!=0&&m_hostArray[local_05].m_int_connectionTimeInSec>=412) {
		char local_10;
		local_10=31;
		mf_CMainControl_0370(local_05,&local_10,1);
		return;
	}
	m_hostArray[local_05].SetflgIsTransferProxy(local_00->m_hostIdx_mouikko_>=0);
	if (m_hostArray[local_05].m_port3>0) {
	int local_11;
		for (local_11=0; local_11<600; local_11++) {
			if (!m_hostArray[local_11].m_flgIsValid
			  ||!m_hostArray[local_11].m_flgIsConnected
			  ||!m_hostArray[local_11].m_flgIsTransferLink_8
			  ||m_hostArray[local_11].m_flgUnknown_7F
			  ||m_hostArray[local_11].m_port1!=m_hostArray[local_05].m_port3
			  ||!(m_hostArray[local_11].IsInternalIpaddr_x2b(m_hostArray[local_05].m_ipaddr2)) ) continue;
			m_hostArray[local_05].m_port3=0;
			local_00->SetHostIdx(local_11);
			m_hostArray[local_05].mf_CHost_0190(true);
			m_hostArray[local_11].m_flg_isDownConnection=false;
			local_00->SetHostIdx(local_11);
			local_00->m_int_unk30=0;
		}
		return;
	}

	bool local_12;
	local_12=false;
	if (m_optflg_useTransferLimit_) {
		if ((double)m_int_linespeed_>m_double_downKBytePerSec_) {
			m_double_unk12+=(float)0.00001;
		} else {
			m_double_unk12-=(float)0.00001;
		}
		if (m_double_unk12>5.0) {
			m_double_unk12=5.0;
		}
		if (m_double_unk12<0.2) {
			m_double_unk12=0.2;
		}
		local_12=true;
		double tmp=(1000.0/(((double)m_int_linespeed_*m_double_unk12)/80.0));
		if ( (double)(GetTickCount()-local_00->m_tick_3_) </**/ (double)m_int_unk20*tmp ) return;
	}
	if (! (local_12||m_int_downTrial_TimeInSec_<=600||m_double_14424*4.0>=/**/(double)m_int_linespeed_) ) {
		local_12=true;
		if (GetTickCount()-local_00->m_tick_3_<m_int_unk20*250) return;
	}
	if (! (!m_optflg_cutSlowTransfer_||m_hostArray[local_05].m_int_connectionTimeInSec<120||local_01/10.0<=local_00->m_double_unk6||m_int_CurrentTransferDownConnectionCount_<m_int_currentTransferUpConnectionMax_) ) {
		char local_13;
		local_13='#';
		mf_CMainControl_0370(local_05,&local_13,1);
		m_hostArray[local_05].m_field_87=true;
		return;
	}
	local_00->m_tick_3_=GetTickCount();
	if (local_02==0) {
		if (local_00->m_pchar_status_!=0) {
			strcpy(local_00->m_pchar_status_,"キーロスト");
		}
		m_flgarray_unk[10]=true;
		return;
	}

	CKey * local_14;
	int local_15;
	int local_16;
	int local_17;
	int local_18;
	int local_19;
	bool local_20;
	local_14=local_02;
	if (! (local_14->m_int_unk0x==0||local_00->m_int_unk30!=0) ) {
		local_14->mf_CKey_0110();
		local_15=local_14->mf_CKey_0170();
		local_16=(int)local_00->m_uint_countNow/0x00010000;
		local_17=mf_CMainControl_0930(local_02,arg_0);
		if (! (!(local_17==0||local_16>=local_15)&&local_14->mf_CKey_0190(local_16)<=0) ) {
			local_18=0;
			local_19=0;
			local_20=false;
			for (local_16=0; local_16<local_15; local_16++) {
				if (local_20) {
					if (local_14->mf_CKey_0190(local_16)>0) {
						local_20=false;
						continue;
					}
					local_19=local_19+1;
					if (local_19>255) break;
					continue;
				}
				if (local_14->mf_CKey_0190(local_16)!=0) continue;
				local_18=local_18+1;
				if (local_18>local_17) break;
				local_20=true;
				local_19=0;
			}
		}
		if (! (!(local_16>=local_15)&&local_14->mf_CKey_0190(local_16)!=1) ) {
			for (local_16=0; local_16<local_15; local_16++) {
				if (local_14->mf_CKey_0190(local_16)==0) break;
			}
		}
		if (local_16<local_15) {
			int local_21;
			xint local_22;
			int * local_23;
			local_21=1;
			local_22=32;
			if (local_12) {
				local_22=1;
			}
			for (local_21=1; local_21<local_22; local_21++) {
				if (local_16+local_21>=local_15||local_14->mf_CKey_0190(local_16+local_21)!=0) break;
			}
			local_23=(int *)(local_25+1);
			local_25[0]=11;
			*local_23=local_00->m_int_unk32;
			*(local_23+1)=local_16;
			*(local_23+2)=local_21;
			*((unsigned int *)(local_23+7))=local_14->m_uint_unk13;
			memcpy((unsigned char *)(local_23+3),local_14->m_hash_tabun,16);
			mf_CMainControl_0370(local_05,local_25,33);
			int local_24;
			int tmp;
			local_24=local_21;
			tmp=local_16;
			local_00->m_int_unk31=tmp;
			local_00->m_int_unk30=local_24;
			local_00->m_int_unk304=1;
			local_00->m_flgkasiraso_4=true;
			return;
		}
		local_00->m_int_unk30=0;
		local_00->m_int_unk304=1;
	}
	return;
}


void CMainControl::mf_CMainControl_0900(int arg_0,int arg_1,int arg_2,int arg_3,char * arg_4,unsigned int arg_5)
{
	bool local_01;
	int local_02;
	bool local_03;
	CKey * local_04;
	unsigned int local_05;
	char local_08[1024];

	local_01=false;
	if (arg_3==0) {
		return;
	}
	local_03=false;
	local_04=this->mf_CMainControl_0180(arg_5,(unsigned char *)arg_4);
	if (! (local_04==0||local_04->m_int_unk0x==0) ) {
		if (! (!local_04->m_bln_unk308||!m_hostArray[arg_0].m_flgIsTransferLink_8) ) {
			m_hostArray[arg_0].m_flgIsBBSNode_8=true;
		}
		if (local_04->m_char_keyType_==KEYTYPE02) {
			if (local_04->m_bln_unk308) {
				CBbsFile local_00;
				local_00.mf_CBbsFile_0080(local_04->mf_CKey_0260());
				local_00.mf_CBbsFile_0010(local_04);
			}
			local_01=true;
		} else {
			if (local_04->m_char_keyType_==KEYTYPE03) {
				local_01=true;
			} else {
				if (local_04->m_bln_unk308) {
					local_01=false;
				} else {
					local_05=0;
					for (local_05=0; m_DownCondition_.size()>local_05; local_05++) {
						CAutoDownList * local_06=GetDownCondition(local_05);
						if (!(local_06->m_double_unk9<=0.0)&&(double)local_04->m_uint_unk13*(float)9.5367432e-007>local_06->m_double_unk9||!(local_06->m_double_unk10<=0.0)&&(double)local_04->m_uint_unk13*(float)9.5367432e-007<local_06->m_double_unk10||!(!local_06->m_flag_unk5)&&!local_04->m_bln_unk308||!local_06->m_flag_unk5&&local_04->m_bln_unk308) continue;
						if (local_06->mf_CAutoDownList_0010()) {
							if (memcmp(local_06->m_hash,local_04->m_hash_tabun,16)!=0) continue;
							break;
						}
						if (strlen(local_06->m_char256_unk1)<2) continue;
						if (!local_04->mf_CKey_0040(local_06->m_char256_unk1,local_06->m_char256_unk2,true)) continue;
						break;
					}
					if (m_DownCondition_.size()==local_05) {
						this->mf_CMainControl_0880(arg_5,(unsigned char *)arg_4,arg_0,arg_2,&local_03,&local_02,NULLPO);
					}
					local_01=true;
				}
			}
		}
	} else {
		if (! (arg_0<0||!m_hostArray[arg_0].m_flgIsValid||!m_hostArray[arg_0].m_flgIsTransferLink_8) ) {
			m_hostArray[arg_0].mf_CHost_0190(true);
		}
	}
	if (! (!local_01||local_03) ) {
		int tmp;
		CWork * local_07;
		tmp=mf_CMainControl_0610();
		local_07=m_vectorpCWork_[tmp];
		local_07->mf_CWork_0100(arg_0,arg_5,arg_4,arg_2,arg_3,arg_1);
		local_04->mf_CKey_0280(local_08,false);
		char *tmp2=local_08;
		strcpy(local_07->m_char256_unk10,tmp2);
		local_07->m_int_unk304=1;
	}
	return;
}


void CMainControl::mf_CMainControl_0910(int arg_0)
{
	CWork * local_00;
	char local_15[256];
	char local_16[256];

	local_00=m_vectorpCWork_[arg_0];
	CKey * local_01;
	local_01=mf_CMainControl_0180(local_00->GetCountMax(),local_00->m_uchar16_unk1);
	if (! (local_01==0||local_01->m_int_unk0x==0) ) {
		CKey * local_02;
		int local_03;
		local_02=local_01;
		local_03=local_00->m_hostIdx_;
		if (! (!(!m_hostArray[local_03].m_flgIsValid||!m_hostArray[local_03].m_flgIsConnected)&&(!m_optflg_UseBbsOnly_||local_02->m_bln_unk308)) ) {
			local_00->mf_CWork_0010(false,true);
			local_00->m_int_errorcode_kamo_=5;
			return;
		}
		CHost * local_04;
		local_04=m_hostArray+local_03;
		if (local_04->m_field_8D) {
			bool local_05;
			local_05=0;
			if (local_02->m_char_keyType_==KEYTYPE02) {
				local_05=1;
			}
			bool local_06;
			local_06=!local_05;
			if ((int)*local_02->mf_CKey_0260()==64) {
				local_06=false;
			}
			FILE * local_07;
			local_07=local_02->m_fileptr_;
			if (local_07!=0) {
				int local_08;
				local_08=1;
				int local_09;
				for (local_09=0; local_09<local_08; local_09++) {
					int local_10;
					int local_11;
					local_10=0;
					local_11=!(local_00->m_int_unk30>0)?-1:local_00->m_int_unk31;
					gbuf20000_hatena3[0]=21;
					char * local_12;
					local_12=((struct_wk_0780 *)gbuf20000_hatena3)->data;
					if (! (local_11<0||local_02->mf_CKey_0170()<=local_11) ) {
						*((int *)local_12)=local_00->m_int_unk20;
						*((int *)(local_12+4))=local_11;
						if (local_05!=0) {
							gbuf20000_hatena4[0]=0;
							if (local_02->m_bln_unk308) {
								fseek(local_07,0,0);
								fflush(local_07);
								fgets(gbuf20000_hatena4,0x00020000,local_07);
							}
							fseek(local_07,strlen(gbuf20000_hatena4)+(local_11<<16),0);
							int local_13;
							local_13=fread(local_12+24,1,0x00010000,local_07);
							if (local_13>0) {
								local_10=local_13+16;
								MD5calc(local_12+24,(unsigned char *)(local_12+8),local_13);
								local_02->mf_CKey_0200(local_11,local_15);
								m_CRC4.setupkey(local_15);
								m_CRC4.crypter(local_12+24,local_13);
							}
						} else {
							if (local_02->mf_CKey_0190(local_11)==1) {
								fseek(local_07,local_02->mf_CKey_0170()+(local_11*0x00010010+320),0);
								local_10=fread(local_12+8,1,0x00010010,local_07);
								if (! (!local_06||local_10<=16) ) {
									memcpy(gbuf20000_hatena4,local_12+8,local_10);
									local_02->mf_CKey_0200(local_11,local_16);
									m_CRC4.setupkey(local_16);
									m_CRC4.crypter(gbuf20000_hatena4+16,local_10+-16);
									MD5calc(&gbuf20000_hatena4[16],(unsigned char *)gbuf20000_hatena4,local_10+-16);
									if (memcmp(local_12+8,gbuf20000_hatena4,16)!=0) {
										local_10=0;
										local_02->mf_CKey_0180(local_11,0);
										local_02->m_char_keyType_=KEYTYPE01;
										local_02->mf_CKey_0110();
									}
								} else {
									if (!local_02->m_bln_unk308) {
										local_02->mf_CKey_0180(local_11,0);
										local_02->m_char_keyType_=KEYTYPE01;
										local_02->mf_CKey_0110();
										g_pCMainControl->m_int_cacheOpenErrorCount_=g_pCMainControl->m_int_cacheOpenErrorCount_+1;
									}
								}
							}
						}
					}
					if (local_10>16) {
						if (!local_01->m_bln_unk308) {
							if (local_02->m_char_keyType_==KEYTYPE02) {
								local_04->Set_int_unk301((local_01->GetRefs())/10);
							} else {
								local_04->Set_int_unk301(local_01->GetRefs());
							}
						}
						local_00->mf_CWork_0040(local_10+-16);
						local_00->SetCountNow( (local_11+1)<<16 );
						if (local_00->m_uint_countNow>local_02->m_uint_unk13) {
							local_00->SetCountNow(local_02->m_uint_unk13);
						}
						if (! (local_02->m_bln_unk308||local_02->mf_CKey_0170()*10000<=(local_02->GetRefs())) ) {
							local_02->IncrementRefs();
						}
						mf_CMainControl_0370(local_03,gbuf20000_hatena3,local_10+9);
						local_00->m_tick_created_kamo_=GetTickCount();
						if (local_00->m_int_unk30<=0) continue;
						local_00->m_int_unk30=local_00->m_int_unk30-1;
						local_00->m_int_unk31=local_00->m_int_unk31+1;
						continue;
					}
					if (local_11>=0) break;
					if (!local_02->m_bln_unk308) {
						time(&local_02->m_time_);
					}
					local_02->mf_CKey_0110();
					local_00->mf_CWork_0010(true,false);
					local_00->m_worktype_=WORKTYPE00;
					break;
				}
			} else {
				if (! (!(local_02->m_char_keyType_==KEYTYPE02||local_02->m_bln_unk302)&&local_02->m_char_keyType_!=KEYTYPE03) ) {
					local_02->m_int_unk0x=0;
				}
			}
		}
	} else {
	int local_14;
		local_14=local_00->m_hostIdx_;
		if (! (local_14<0||!m_hostArray[local_14].m_flgIsValid||!m_hostArray[local_14].m_flgIsTransferLink_8) ) {
			m_hostArray[local_14].mf_CHost_0190(true);
		}
	}
	return;
}


void CMainControl::mf_CMainControl_0920(int arg_0,int arg_1,int arg_2,char * arg_3,int arg_4)
{
	unsigned int local_00;
	char local_11[256];

	local_00=0;
	for (local_00=0; m_vectorpCWork_.size()>local_00; local_00++) {
		if (!(/**/(*GetWorkNP(local_00))->GetWorkType()!=WORKTYPE01
		  ||/**/(*GetWorkNP(local_00))->IsFinished())&&/**/(*GetWorkNP(local_00))->Get_int_unk32()==arg_1) break;
	}

	if (m_vectorpCWork_.size()>local_00) {
		CWork * local_01;
		local_01=m_vectorpCWork_[local_00];
		if (! (!(arg_0<0||!m_hostArray[arg_0].m_flgIsValid)&&m_hostArray[arg_0].m_flgIsConnected) ) {
			if (local_01->m_pchar_status_!=0) {
				strcpy(local_01->m_pchar_status_,"接続切断");
			}
			local_01->mf_CWork_0010(false,true);
			local_01->m_int_errorcode_kamo_=6;
			m_flgarray_unk[10]=true;
			return;
		}
		CKey * local_02;
		local_02=mf_CMainControl_0180(local_01->GetCountMax(),local_01->m_uchar16_unk1);
		if (! (!(local_02==0||local_02->m_int_unk0x==0||arg_2<0)&&local_02->mf_CKey_0170()>arg_2) ) {
			if (local_01->m_pchar_status_!=0) {
				strcpy(local_01->m_pchar_status_,"受信位置エラー");
			}
			m_hostArray[arg_0].mf_CHost_0190(true);
			local_01->mf_CWork_0010(false,true);
			local_01->m_int_errorcode_kamo_=7;
			m_flgarray_unk[10]=true;
			return;
		}
		CKey * local_03;
		local_03=local_02;
		if (! (local_01->m_flgIsFinished_370||local_01->m_flg_unk302) ) {
			local_01->m_tick_created_kamo_=GetTickCount();
			FILE * local_04;
			xint local_05;
			local_04=local_03->m_fileptr_;
			local_05=0;
			if (local_04!=0) {
				if (! (arg_2<=0||arg_2%200!=0||(int)local_03->mf_CKey_0170()<=(int)arg_2+200) ) {
					int local_06;
					local_06=local_03->mf_CKey_0170()+((arg_2+200)*0x00010010+320);
					fseek(local_04,local_06,0);
					char local_07;
					local_07=0;
					fread(&local_07,1,1,local_04);
					fseek(local_04,local_06,0);
					fwrite(&local_07,1,1,local_04);
				}
				memcpy(gbuf20000_hatena5,arg_3,arg_4);
				local_03->mf_CKey_0200(arg_2,local_11);
				m_CRC4.setupkey(local_11);
				m_CRC4.crypter(gbuf20000_hatena5+16,arg_4+-16);
				MD5calc(&gbuf20000_hatena5[16],(unsigned char *)gbuf20000_hatena5,arg_4+-16);
				if (memcmp(arg_3,gbuf20000_hatena5,16)==0) {
					fseek(local_04,local_03->mf_CKey_0170()+(arg_2*0x00010010+320),0);
					if (fwrite(arg_3,arg_4,1,local_04)<=0) {
						m_hostArray[arg_0].mf_CHost_0190(true);
						local_01->mf_CWork_0010(false,true);
						local_01->m_int_errorcode_kamo_=13;
						if (local_01->m_pchar_status_!=0) {
							strcpy(local_01->m_pchar_status_,"書き込みエラー");
						}
						if (local_03->m_bln_unk308) {
							m_flgarray_unk[10]=true;
						}
						mf_CMainControl_0320();
						return;
					}
					local_05=1;
				}
			}
			local_03->mf_CKey_0180(arg_2,*((unsigned char *)(&local_05)));
			if (local_03->mf_CKey_0190(arg_2+1)>0) {
				arg_2=arg_2+1;
				arg_2=arg_2+(256-arg_2%256);
				if (local_03->mf_CKey_0170()<=arg_2) {
					local_01->SetCountNow(0);
				} else {
					local_01->SetCountNow(arg_2<<16);
				}
			} else {
				local_01->SetCountNow((arg_2+1)<<16);
			}
			if (local_01->m_uint_countNow>local_03->m_uint_unk13) {
				local_01->SetCountNow(local_03->m_uint_unk13);
			}
			local_01->m_int_unk30=local_01->m_int_unk30-1;
			local_01->mf_CWork_0040(arg_4);
			local_01->m_flgkasiraso_2=false;
			if (local_03->mf_CKey_0140()) {
				if (local_01->m_pchar_status_!=0) {
					strcpy(local_01->m_pchar_status_,"ダウン完了");
				}
				if (local_03->m_bln_unk308) {
					m_flgarray_unk[10]=true;
				}
				if (!local_03->m_bln_unk308) {
					m_int_downTrial_NumberOfSuccessTry_=m_int_downTrial_NumberOfSuccessTry_+1;
				}
				if (local_01->m_hostIdx_mouikko_<0) {
					int local_08;
					for (local_08=1; local_08<600; local_08++) {
						if (!m_hostArray[local_08].m_flgIsValid||m_hostArray[local_08].m_flgIsBBSNode_8||m_hostArray[local_08].m_flg_IsBBSPort||m_hostArray[local_08].m_port1!=m_hostArray[arg_0].m_port1
						  ||!(m_hostArray[local_08].IsInternalIpaddr_x2b(m_hostArray[arg_0].m_ipaddr3))) continue;
						m_hostArray[local_08].m_int_preference2_positive=m_hostArray[local_08].m_int_preference2_positive+20;
					}
				}

				_in_addr local_09;
				ny_addrcrypter(&local_09,m_hostArray[0].m_ipaddr3);
				memcpy(&local_03->m_ipaddr_0__,&local_09,4);
				local_03->Set_portno_0(m_port_accept_);
				local_03->m_char_keyType_=KEYTYPE03;
				local_01->SetCountNow(local_03->m_uint_unk13);
				if (!local_03->m_bln_unk308) {
					time(&local_03->m_time_);
				} else {
					local_03->m_bln_unk301=false;
				}
				local_03->mf_CKey_0110();
				local_01->mf_CWork_0010(true,false);
				mf_CMainControl_0940(local_03,local_00);
				if (! (!(!local_01->m_flgkasiraso_1)&&!m_hostArray[arg_0].m_flgIsTransferLink_8) ) {
					char local_10;
					local_10=31;
					mf_CMainControl_0370(arg_0,&local_10,1);
					m_hostArray[arg_0].mf_CHost_0190(true);
				}
				if (! (local_03->m_bln_unk308||local_03->m_bln_unk305) ) {
					if (m_optflag_notConvert__) {
						if (local_01->m_hostIdx_mouikko_<0) {
							local_01->m_flg_unk212=true;
							if (m_optflg_makeMarkFile_) {
								mf_CMainControl_0970(local_03->m_uint_unk13,local_03->m_hash_tabun);
							}
							local_03->m_bln_unk312=true;
						}
					} else {
						if ((int)*local_03->mf_CKey_0260()!=64) {
							mf_CMainControl_0980(local_03->m_uint_unk13,local_03->m_hash_tabun,local_01->m_hostIdx_mouikko_>=0);
						}
					}
				}
				m_flgarray_unk[4]=true;
				m_flgarray_unk[5]=true;
				m_flgarray_unk[6]=true;
				if (local_03->m_bln_unk308) {
					m_flgarray_unk[10]=true;
					m_flgarray_unk[9]=true;
				}
			}
		}
	}
	return;
}


int CMainControl::mf_CMainControl_0930(CKey * arg_0,int arg_1)
{
	int local_00;
	local_00=0;
	if (! (!(arg_0==0||arg_1<0)&&m_vectorpCWork_.size()>arg_1) ) {
		return 0;
	}
	CWork * local_01;
	local_01=m_vectorpCWork_[arg_1];
	if (local_01->m_worktype_!=WORKTYPE01) {
		return 0;
	}
	for (int local_02=0; (int)m_vectorpCWork_.size()>local_02; local_02++) {
		if (arg_1==local_02) continue;
CWork *		local_03=m_vectorpCWork_[local_02];
		if (local_03->m_worktype_!=WORKTYPE01||local_03->m_flgIsFinished_370||memcmp(local_01->m_uchar16_unk1,local_03->m_uchar16_unk1,16)!=0||local_03->m_double_unk6<=local_01->m_double_unk6) continue;
		local_00=local_00+1;
	}
	return local_00;
}


void CMainControl::mf_CMainControl_0940(CKey * arg_0,unsigned int arg_1)
{
	int local_00;
	if (arg_0!=0) {
		for (local_00=0; (int)m_vectorpCWork_.size()>local_00; local_00++) {
			if (local_00==arg_1) continue;
CWork *			local_01=m_vectorpCWork_[local_00];
			if (local_01->m_worktype_!=WORKTYPE01||local_01->m_flgIsFinished_370||memcmp(arg_0->m_hash_tabun,local_01->m_uchar16_unk1,16)!=0) continue;
			local_01->mf_CWork_0010(true,true);
		}
	}
	return;
}


Bb CMainControl::mf_CMainControl_0950(unsigned int arg_0,unsigned char * arg_1)
{
	CKey * local_01;
	local_01=mf_CMainControl_0180(arg_0,arg_1);
	if (! (!(local_01==0||local_01->m_int_unk0x==0)&&local_01->m_char_keyType_==KEYTYPE02) ) {
		return false;
	}
	CKey * local_02=local_01;


	for (int local_03x=0; (int)m_vectorpCWork_.size()>local_03x; local_03x++) {
		CWork * local_04x=m_vectorpCWork_[local_03x];
		if (local_04x->m_worktype_!=WORKTYPE02||local_04x->m_flgIsFinished_370||memcmp(local_04x->m_uchar16_unk1,arg_1,16)!=0) continue;
		return false;
	}


	AnsiString local_00;
	if (local_02->m_bln_unk308) {
		local_00=local_02->mf_CKey_0230()+".txt";
	} else {
		local_00=local_02->mf_CKey_0230();
		local_02->m_char_keyType_=KEYTYPE01;
		local_02->mf_CKey_0130();
	}
	local_02->m_bln_unk302=true;
	if (local_02->mf_CKey_0110()>0) {
		int local_03=mf_CMainControl_0610();
		m_vectorpCWork_[local_03]->mf_CWork_0110(arg_0,arg_1,local_00.c_str());
		/**/(*GetWorkNP(local_03))->SetCountNow(0);
		FILE * tmp;
		tmp=fopen(/**/(*GetWorkNP(local_03))->GetFolderName(),"rb");
		FILE * local_04;
		local_04=tmp;
		CWork * local_05;
		local_05=m_vectorpCWork_[local_03];
		if (local_05->m_fileptr!=0) {
			fclose(local_05->m_fileptr);
		}
		local_05->m_fileptr=local_04;
		m_flgarray_unk[4]=true;
		m_flgarray_unk[5]=true;
		m_flgarray_unk[6]=true;
	} else {
		return false;
	}
	return true;
}


void CMainControl::mf_CMainControl_0960(int arg_0)
{
	unsigned char local_10[16];
	char local_11[256];

#ifdef EXACTMATCH
	//これでもまだダメ
	CWork *	local_00;
	unsigned tmp=arg_0;
	local_00=*((CWork **)((unsigned)tmp*4+(unsigned)m_vectorpCWork_.begin()) );
#else
	CWork *	local_00=GetWorkN(arg_0);
#endif
	CKey * local_01;
	local_01=mf_CMainControl_0180(local_00->GetCountMax(),local_00->m_uchar16_unk1);
	if (local_01==0) {
		local_00->mf_CWork_0010(false,false);
		local_00->m_int_errorcode_kamo_=8;
		m_flgarray_unk[4]=true;
		m_flgarray_unk[5]=true;
		m_flgarray_unk[6]=true;
		return;
	}

	CKey * local_02;
	unsigned int local_03;
	int local_04;
	local_02=local_01;
	local_03=GetTickCount();
	for (local_04=0; local_04<500; local_04++) {
		if (local_02->m_int_unk0x==0) {
			local_00->mf_CWork_0010(false,false);
			local_00->m_int_errorcode_kamo_=8;
			m_flgarray_unk[4]=true;
			m_flgarray_unk[5]=true;
			m_flgarray_unk[6]=true;
			break;
		}

		FILE * local_05;
		unsigned	int local_06;
		FILE * local_07;
		int local_08;
		local_05=local_00->m_fileptr;
		if (local_05!=0) {
			fseek(local_05,local_00->m_uint_countNow,0);
			local_06=fread(gbuf20000_hatena6,1,0x00010000,local_05);
			local_07=NULLPO;
			if (local_06>0) {
				MD5calc(gbuf20000_hatena6,local_10,local_06);
				local_07=local_02->m_fileptr_;
				if (local_07!=0) {
					local_08=(int)local_00->m_uint_countNow/0x00010000;
					fseek(local_07,local_02->mf_CKey_0170()+local_08*0x00010010+320,0);
					local_02->mf_CKey_0200(local_08,local_11);
					m_CRC4.setupkey(local_11);
					local_02->mf_CKey_0180(local_08,1);
					m_CRC4.crypter(gbuf20000_hatena6,local_06);
					fwrite(local_10,16,1,local_07);
					if (fwrite(gbuf20000_hatena6,1,local_06,local_07)==local_06) {
						local_00->mf_CWork_0040(local_06);
						local_00->AddCountNow(local_06);
						local_00->m_tick_created_kamo_=GetTickCount();
					} else {
						local_00->m_int_errorcode_kamo_=13;
						local_00->mf_CWork_0010(false,false);
						break;
					}
				}
			}
			if ((int)local_00->m_uint_countNow%5==4) {
				local_02->mf_CKey_0110();
			}
			if (local_02->m_uint_unk13<=local_00->m_uint_countNow) {
				local_00->mf_CWork_0010(true,false);
				local_02->mf_CKey_0120();
				local_02->mf_CKey_0110();
				m_flgarray_unk[4]=true;
				m_flgarray_unk[5]=true;
				m_flgarray_unk[6]=true;
				if (local_02->m_bln_unk308) {
					local_02->m_char_keyType_=KEYTYPE02;
					local_02->mf_CKey_0110();
					mf_CMainControl_0410(local_02->mf_CKey_0260());
				}
			}
		} else {
			local_00->mf_CWork_0010(false,false);
			local_00->m_int_errorcode_kamo_=9;
			m_flgarray_unk[4]=true;
			m_flgarray_unk[5]=true;
			m_flgarray_unk[6]=true;
		}

		unsigned int local_09;
		local_09=GetTickCount();
		if (local_00->m_flgIsFinished_370||local_09-local_03>150) break;
	}
	return;
}


void CMainControl::mf_CMainControl_0970(unsigned int arg_0,unsigned char * arg_1)
{
	CKey * local_00;
	CKey * local_01;
	FILE * local_02;
	char local_03[4096];
	char local_04[256];
	local_00=mf_CMainControl_0180(arg_0,arg_1);
	if (! ((local_00==0||local_00->m_int_unk0x==0)||!(!local_00->m_bln_unk308)&&local_00->m_char_keyType_!=KEYTYPE02||!(local_00->m_bln_unk308||local_00->m_char_keyType_==KEYTYPE03)&&local_00->m_char_keyType_!=KEYTYPE01) ) {
		local_01=local_00;
		local_02=NULLPO;
		ny_binhash2aschash(arg_1,local_04);
		sprintf(local_03,"%s\\_%s_%s",m_sz_DownFolderPath_,local_04,local_01->mf_CKey_0260());
		local_02=fopen(local_03,"wb");
		if (local_02!=0) {
			fclose(local_02);
		}
	}
	return;
}


void CMainControl::mf_CMainControl_0980(unsigned int arg_0,unsigned char * arg_1,bool arg_2)
{
	CKey * local_00;
	CKey * local_01;
	char local_06[4096];

	local_00=mf_CMainControl_0180(arg_0,arg_1);
	if (! ((local_00==0||local_00->m_int_unk0x==0)||!(!local_00->m_bln_unk308)&&local_00->m_char_keyType_!=KEYTYPE02||!(local_00->m_bln_unk308||local_00->m_char_keyType_==KEYTYPE03)&&local_00->m_char_keyType_!=KEYTYPE01) ) {
		local_01=local_00;

		for (unsigned int local_001=0; m_vectorpCWork_.size()>local_001; local_001++) {
			CWork * local_002=m_vectorpCWork_[local_001];
			if (!(local_002->m_worktype_!=WORKTYPE03||local_002->m_flgIsFinished_370)&&memcmp(local_002->m_uchar16_unk1,arg_1,16)==0) return;
		}

		local_01->m_bln_unk305=true;
		if (! (!(!arg_2)&&(int)*local_01->mf_CKey_0260()==64) ) {
			FILE * local_02=NULLPO;
			if (local_01->m_bln_unk308) {
				sprintf(local_06,"%s\\_incomplete_%s.txt",m_sz_BbsFolderPath_,local_01->mf_CKey_0260());
			} else {
				sprintf(local_06,"%s\\_incomplete_%s",m_sz_DownFolderPath_,local_01->mf_CKey_0260());
			}
			if (!arg_2) {
				local_02=fopen(local_06,"wb");
			}
			if (! (!(local_02!=0)&&!arg_2) ) {
				int local_03=mf_CMainControl_0610();
				m_vectorpCWork_[local_03]->mf_CWork_0120(arg_0,arg_1,local_06,arg_2);
				/**/(*GetWorkNP(local_03))->SetCountNow(0);
				FILE * local_04;
				CWork * local_05;
				local_04=local_02;
				local_05=m_vectorpCWork_[local_03];
				if (local_05->m_fileptr!=0) {
					fclose(local_05->m_fileptr);
				}
				local_05->m_fileptr=local_04;
				MD5init(/**/(*GetWorkNP(local_03))->GetMD5ctx());
			}
		}
	}
	return;
}



void CMainControl::mf_CMainControl_0990(int arg_0)
{
	CWork * local_00;
	char local_18[1024];
	unsigned char local_19[16];
	char local_20[256];
	unsigned char local_21[16];
	unsigned char local_22[16];
	local_00=m_vectorpCWork_[arg_0];
	if (!local_00->m_flgIsFinished_370) {
		CKey * local_01;
		local_01=mf_CMainControl_0180(local_00->GetCountMax(),local_00->m_uchar16_unk1);
		if (local_01==0) {
			local_00->mf_CWork_0010(false,false);
			local_00->m_int_errorcode_kamo_=8;
			return;
		}
		CKey * local_02;
		unsigned int local_03;
		local_02=local_01;
		local_03=GetTickCount();
		int local_04;
		for (local_04=0; local_04<500; local_04++) {
			if (! (!(local_02->m_int_unk0x==0)&&(!(!(!local_01->m_bln_unk308)&&local_01->m_char_keyType_!=KEYTYPE02)&&(local_01->m_bln_unk308||local_02->m_char_keyType_==KEYTYPE03||local_02->m_char_keyType_==KEYTYPE01))) ) {
				local_00->mf_CWork_0010(false,false);
				local_00->m_int_errorcode_kamo_=8;
				break;
			}
			if (local_02->m_int_refcountOfFileptr_==0) {
				local_02->mf_CKey_0020();
			}
			FILE * local_05;
			local_05=local_02->m_fileptr_;
			if (local_05==0) {
				local_00->mf_CWork_0010(false,false);
				local_00->m_int_errorcode_kamo_=10;
			} else {
				FILE * local_06;
				local_06=NULLPO;
				if (!local_00->m_flgkasiraso_3) {
					local_06=local_00->m_fileptr;
				}
				if (! (!(local_06!=0)&&!local_00->m_flgkasiraso_3) ) {
					unsigned	int local_07;
					char local_08;
					local_07=(int)local_00->m_uint_countNow/0x00010000;
					fseek(local_05,local_02->mf_CKey_0170()+local_07*0x00010010+320,0);
					if (local_06!=0) {
						if (! ((unsigned int)local_07<=0||(unsigned int)local_07%200!=0||local_02->mf_CKey_0170()<=local_07+200) ) {
							fseek(local_06,local_07+200<<16,0);
							local_08=0;
							fread(&local_08,1,1,local_06);
							fseek(local_06,local_07+200<<16,0);
							fwrite(&local_08,1,1,local_06);
						}
						fseek(local_06,local_00->m_uint_countNow,0);
					}
					local_02->mf_CKey_0200(local_07,local_20);
					m_CRC4.setupkey(local_20);
					int local_09;
					local_09=fread(gbuf20000_hatena7,1,0x00010010,local_05);
					if (local_09>16) {
						m_CRC4.crypter(gbuf20000_hatena7+16,local_09+-16);
						MD5calc(&gbuf20000_hatena7[16],local_19,local_09+-16);
						if (memcmp(gbuf20000_hatena7,local_19,16)==0) {
							unsigned int local_10;
							int local_11;
							local_10=0xFFFFFFFF;
							if (local_06!=0) {
								local_10=fwrite(gbuf20000_hatena7+16,1,local_09+-16,local_06);
							}
							if (local_09+-16==local_10) {
								local_02->mf_CKey_0180(local_07,1);
								if (local_02->m_int_unk203==4) {
									memcpy(local_21,local_00->m_uchar16_unk2,16);
									if (local_00->m_uint_countNow==0) {
										local_21[0]=local_19[0];
										local_21[1]=local_19[1];
									}
									for (local_11=2; local_11<16; local_11++) {
										local_21[local_11]=local_21[local_11]^local_19[local_11];
									}
									memcpy(local_00->m_uchar16_unk2,local_21,16);
								} else {
									MD5update(&local_00->m_md5ctx,&gbuf20000_hatena7[16],local_09+-16);
								}
							} else {
								local_00->mf_CWork_0010(false,false);
								local_00->m_int_errorcode_kamo_=14;
								break;
							}
						} else {
							memset(gbuf20000_hatena7+16,0,local_09+-16);
							unsigned int local_12;
							local_12=0xFFFFFFFF;
							if (local_06!=0) {
								local_12=fwrite(gbuf20000_hatena7+16,1,local_09+-16,local_06);
							}
							if (local_09+-16==local_12) {
								local_02->mf_CKey_0180(local_07,0);
								local_02->m_char_keyType_=KEYTYPE01;
								local_02->mf_CKey_0110();
								local_00->m_int_errorcode_kamo_=1;
							} else {
								local_00->mf_CWork_0010(false,false);
								local_00->m_int_errorcode_kamo_=1;
								break;
							}
						}
						local_00->AddCountNow(local_09+-16);
						local_00->mf_CWork_0040(local_09+-16);
						local_00->m_tick_created_kamo_=GetTickCount();
					} else {
						local_00->mf_CWork_0010(false,false);
						local_00->m_int_errorcode_kamo_=1;
						local_02->mf_CKey_0110();
						m_flgarray_unk[4]=true;
						m_flgarray_unk[5]=true;
						m_flgarray_unk[6]=true;
					}
					if (local_02->m_uint_unk13<=local_00->m_uint_countNow) {
						local_00->mf_CWork_0010(true,false);
						if (local_02->m_int_unk203==4) {
							memcpy(local_22,local_00->m_uchar16_unk2,16);
						} else {
							MD5final(local_22,&local_00->m_md5ctx);
						}
						bool local_13;
						local_13=local_02->mf_CKey_0250();
						if (! (!local_13||memcmp(local_22,local_00->m_uchar16_unk1,16)==0) ) {
							local_02->mf_CKey_0130();
							local_02->m_char_keyType_=KEYTYPE01;
							local_00->m_int_errorcode_kamo_=12;
						} else {
							local_00->SetErrorcode(!(!local_13)?0:1);
							if (! (!local_02->m_bln_unk308&&(!local_13||local_00->m_flgkasiraso_3)) ) {
								if (local_02->m_bln_unk308) {
									sprintf(gbuf20000_hatena7,"%s\\%s.txt",m_sz_BbsFolderPath_,local_02->mf_CKey_0260());
								} else {
									sprintf(gbuf20000_hatena7,"%s\\%s",m_sz_DownFolderPath_,local_02->mf_CKey_0260());
								}
								if (local_02->mf_CKey_0140()) {
									int local_14;
									FILE * local_15;
									char * local_16;
									local_14=2;
									while (true) {
										local_15=fopen(gbuf20000_hatena7,"rb");
										if (local_15==0) break;
										fclose(local_15);
										strcpy(local_18,local_02->mf_CKey_0260());
										for (local_16=strlen(local_18)+local_18; !(local_18>=local_16)&&(int)*local_16!=46; local_16--) {
										}
										if (local_18<local_16) {
											*local_16=0;
										} else {
											local_16=(local_19+15)+strlen(local_18);
										}
										sprintf(gbuf20000_hatena7,"%s\\%s(%d).%s",m_sz_DownFolderPath_,local_18,local_14,local_16+1);
										local_14=local_14+1;
									}
									rename(local_00->GetFolderName(),gbuf20000_hatena7);
									local_02->m_bln_unk312=true;
								}
							}
						}
						local_02->mf_CKey_0110();
						m_flgarray_unk[4]=true;
						m_flgarray_unk[5]=true;
						m_flgarray_unk[6]=true;
					}
				} else {
					local_00->mf_CWork_0010(false,false);
					local_00->m_int_errorcode_kamo_=10;
					m_flgarray_unk[4]=true;
					m_flgarray_unk[5]=true;
					m_flgarray_unk[6]=true;
				}
			}
			unsigned int local_17;
			local_17=GetTickCount();
			if (local_00->m_flgIsFinished_370||local_17-local_03>150) break;
		}
	}
	return;
}



void CMainControl::mf_CMainControl_1000(int arg_0)
{
	CWork * local_00;
	char local_12[1024];

	local_00=m_vectorpCWork_[arg_0];
	int	local_01=local_00->m_hostIdx_;
	if (! (!(local_01<0)&&m_hostArray[local_01].m_flgIsValid) ) {
		local_00->mf_CWork_0010(false,true);
		return;
	}
	mf_CMainControl_0170(local_01);
	int local_02;
	local_02=0;
	local_00->SetCountNow(0);
	unsigned int local_03;
	for (local_03=0; m_vectorCHostSorter_.size()>local_03; local_03++) {
		int local_04;
		local_04=m_vectorCHostSorter_[local_03].m_int_unk00;
		if (local_04==local_01) continue;
		CHost * local_05;
		local_05=m_hostArray+local_04;
		if (!local_05->m_flgIsValid||local_05->m_flg_IsBBSPort||local_05->m_flgIsPortZero_9||local_05->m_port1==0||!local_05->m_field_8D||local_05->m_flgIsBadPortZero_9||local_05->m_field_82) continue;
		_in_addr * local_06;
		char * local_07;
		local_06=&local_05->m_ipaddr3;
		local_07=(char *)(local_12+1);
		local_12[0]=4;
		memcpy(local_07,local_06,4);
		*((int *)(local_07+4))=local_05->m_port1;
		*((int *)(local_07+8))=local_05->m_port2;
		*((int *)(local_07+13))=local_05->m_int_lineSpeed;
		local_07[12]=(unsigned char)(local_05->m_flgIsBBSNode_8?1:0);
		int local_08;
		local_08=20;
		if (local_05->m_flgIsBBSNode_8) {
			int local_09;
			for (local_09=0; local_09<3; local_09++) {
				*(local_07+17+local_09)=0;
			}
		} else {
			int local_10;
			int local_11;
			for (local_10=0; local_10<3; local_10++) {
				local_11=strlen(local_05->m_sz_clusterword[local_10]);
				if (local_11>100) {
					local_11=100;
				}
				*(local_07+17+local_10)=*((unsigned char *)(&local_11));
				memcpy(local_07+local_08,local_05->m_sz_clusterword[local_10],local_11);
				local_08=local_08+local_11;
			}
		}
		mf_CMainControl_0370(local_01,local_12,local_08+1);
		local_02=local_02+1;
		if (local_02>30) break;
	}
	local_00->mf_CWork_0010(true,false);
	if (local_00->m_flgkasiraso_5) {
		local_12[0]=31;
		mf_CMainControl_0370(local_01,local_12,1);
	}
	mf_CMainControl_0170(0);
	return;
}

void CMainControl::mf_CMainControl_1010(unsigned char * arg_0)
{
	_in_addr local_00;
	int local_01;
	int local_02;
	char local_08[1024];

	memcpy(&local_00,arg_0,4);
	local_01=*((int *)(arg_0+4));
	if (! (local_01<=0||local_01>32767) ) {
		local_02=*((int *)(arg_0+8));
		if (! (!(local_02<0)&&local_02<=32767) ) {
			local_02=0;
		}
		if (! (!(!(m_hostArray[0].IsInternalIpaddr(local_00)))&&m_port_accept_==local_01) ) {
			int local_03=mf_CMainControl_0560(&local_00,local_01);
			m_hostArray[local_03].SetPort(local_01);
			m_hostArray[local_03].SetBbsPort(local_02);
			CHost * local_04=m_hostArray+local_03;
			local_04->m_ipaddr3.b1=local_00.b1;
			local_04->m_ipaddr3.b2=local_00.b2;
			local_04->m_ipaddr3.b3=local_00.b3;
			local_04->m_ipaddr3.b4=local_00.b4;
			m_hostArray[local_03].SetflgIsBBSNode((*(arg_0+12)!=0)?true:false);
			m_hostArray[local_03].SetLineSpeed(*((int *)(arg_0+13)));
			m_hostArray[local_03].m_int_unk5=3600;
			if (*(arg_0+12)!=0) {
				for (int local_05=0; local_05<3; local_05++) {
					m_hostArray[local_03].mf_CHost_0020(local_05,"");
				}
				return;
			}
			unsigned int local_06=20;
			for (int local_07=0; local_07<3; local_07++) {
				memcpy(local_08,arg_0+local_06,(unsigned int)(unsigned char)*((arg_0+17)+local_07));
				*(local_08+(unsigned int)*((arg_0+17)+local_07))=0;
				m_hostArray[local_03].mf_CHost_0020(local_07,local_08);
				local_06+=(unsigned int)*((arg_0+17)+local_07);
			}
		}
	}
	return;
}



char CMainControl::mf_CMainControl_1020(int arg_0,int arg_1,bool arg_2,bool arg_3,bool arg_4,int arg_5,char arg_6)
{
	unsigned int local_00;
	unsigned char local_08[16];
	char local_09[1024];
	char local_10[1024];

	if (arg_1<0) {
		return 0;
	}
	local_00=0;
	if (arg_4) {
		if (g_nazouintarray[arg_0][arg_1]<0) {
			return 0;
		}
		CWork * local_01;
		local_01=m_vectorpCWork_[g_nazouintarray[arg_0][arg_1]];
		CKey * local_02;
		local_02=mf_CMainControl_0180(local_01->GetCountMax(),local_01->m_uchar16_unk1);
		if (! (local_02==0||local_01->m_worktype_!=WORKTYPE01||!local_01->m_flgIsFinished_370||local_02->m_char_keyType_!=KEYTYPE03) ) {
			local_00=local_01->GetCountMax();
			memcpy(local_08,local_01->m_uchar16_unk1,16);
		} else {
			if (! (local_02==0||local_01->m_worktype_!=WORKTYPE03||!local_01->m_flgIsFinished_370||local_02->m_char_keyType_!=KEYTYPE03) ) {
				sprintf(local_09,"%s\\%s",m_sz_DownFolderPath_,local_02->mf_CKey_0260());
				sprintf(local_10,"%s を開きますか？",local_09);
				if (MessageBox(m_hwnd_unk32,local_10,"Winny",0x00042024)==6) {
					//ここで宣言するとorphan jumpができる
					SHELLEXECUTEINFO local_11;
					local_11.cbSize=60;
					local_11.hwnd=NULL;
					local_11.fMask=0;
					local_11.lpVerb="open";
					local_11.lpFile=local_09;
					local_11.lpParameters=NULLPO;
					local_11.lpDirectory=NULLPO;
					local_11.nShow=1;
					local_11.lpIDList=NULLPO;
					ShellExecuteEx(&local_11);
				}
			} else {
				if (local_02!=0) {
					MainForm->ViewWorkClick(!(arg_0==0)?MainForm->SubViewWork:MainForm->ViewWork);
				}
			}
			return 0;
		}
	} else {
		if ((unsigned char)arg_6==9) {
			local_00=ny_unknown_0000(g_listitemarray[arg_0][arg_1][6]);
			ny_aschash2binhash(g_listitemarray[arg_0][arg_1][7],local_08);
		} else {
			local_00=ny_unknown_0000(g_listitemarray[arg_0][arg_1][2]);
			ny_aschash2binhash(g_listitemarray[arg_0][arg_1][9],local_08);
		}
	}

	CKey * local_03;
	char local_04;
	CKey * local_05;
	int local_06;
	bool local_07;

	local_03=mf_CMainControl_0180(local_00,local_08);
	if (! (!(local_03==0)&&local_03->m_int_unk0x!=0) ) {
		return 0;
	}
	local_04=6;
	local_05=local_03;
	if (local_05->m_bln_unk308) {
		mf_CMainControl_1040(0,local_05);
		return 0;
	}
	if (! (local_05->m_char_keyType_>KEYTYPE01||!(arg_2||arg_3)&&!mf_CMainControl_1180(local_05)) ) {
		if (! (!arg_2||local_05->m_char_keyType_!=KEYTYPE01) ) {
			mf_CMainControl_0980(local_00,local_08,false);
		} else {
			if (arg_3) {
				mf_CMainControl_0060(local_05->mf_CKey_0260(),!(arg_5!=0)?local_00:0,local_08,"",0.0,0.0,local_05->m_bln_unk308,true,false,false,false);
				local_04=4;
			} else {
				if (m_int_currentTransferUpConnectionMax_+2>m_int_CurrentTransferDownConnectionCount_) {
					mf_CMainControl_0880(local_00,local_08,-1,0,&local_07,&local_06,NULLPO);
				}
			}
		}
	} else {
		if (local_05->m_char_keyType_==KEYTYPE02) {
			mf_CMainControl_0950(local_00,local_08);
		} else {
			if (local_05->m_char_keyType_==KEYTYPE03) {
				mf_CMainControl_0980(local_00,local_08,false);
			}
		}
	}
	return local_04;
}


void CMainControl::mf_CMainControl_1030(int arg_0)
{
	char local_00[4096];
	SHELLEXECUTEINFO local_01;
	if ((int)m_vectorCFolder_.size()>arg_0) {
		if (arg_0>=0) {
			sprintf(local_00,"%s\\",m_vectorCFolder_[arg_0].Get_001_cstr());
		} else {
			sprintf(local_00,"%s\\",m_sz_DownFolderPath_);
		}
		local_01.cbSize=60;
		local_01.hwnd=NULL;
		local_01.fMask=0;
		local_01.lpVerb="open";
		local_01.lpFile=m_str_optFolderBrowser_.c_str();
		local_01.lpParameters=local_00;
		local_01.lpDirectory=NULLPO;
		local_01.nShow=1;
		local_01.lpIDList=NULLPO;
		ShellExecuteEx(&local_01);
	}
	return;
}


void CMainControl::mf_CMainControl_1040(int arg_0,CKey * arg_1)
{
	CHost * local_00;
	_in_addr local_01;
	char local_02[1024];
	char local_03[1024];
	SHELLEXECUTEINFO local_04;
	if (! (!(arg_1==0)&&!arg_1->m_bln_unk308) ) {
		local_00=m_hostArray+arg_0;
		if (arg_0==0) {
			ny_addrset(&local_01,127,0,0,1);
		} else {
			local_01.b1=local_00->m_ipaddr3.b1;
			local_01.b2=local_00->m_ipaddr3.b2;
			local_01.b3=local_00->m_ipaddr3.b3;
			local_01.b4=local_00->m_ipaddr3.b4;
		}
		if (arg_1!=0) {
			ny_binhash2aschash(arg_1->m_hash_tabun,local_03);
			sprintf(local_02,"http://%d.%d.%d.%d:%d/%s",(unsigned int)local_01.b1,(unsigned int)local_01.b2,(unsigned int)local_01.b3,(unsigned int)local_01.b4,local_00->m_port2,local_03);
		} else {
			if (strlen(m_char512_unk1_)!=0) {
				ny_htmlproc_2(m_char512_unk1_,local_03);
				sprintf(local_02,"http://%d.%d.%d.%d:%d/%s/",(unsigned int)local_01.b1,(unsigned int)local_01.b2,(unsigned int)local_01.b3,(unsigned int)local_01.b4,local_00->m_port2,local_03);
			} else {
				sprintf(local_02,"http://%d.%d.%d.%d:%d/",(unsigned int)local_01.b1,(unsigned int)local_01.b2,(unsigned int)local_01.b3,(unsigned int)local_01.b4,local_00->m_port2);
			}
		}
		local_04.cbSize=60;
		local_04.hwnd=NULL;
		local_04.fMask=0;
		local_04.lpVerb="open";
		if (m_str_optBbsBrowser_.Length()>0) {
			local_04.lpFile=m_str_optBbsBrowser_.c_str();
			local_04.lpParameters=local_02;
		} else {
			local_04.lpFile=local_02;
			local_04.lpParameters=NULLPO;
		}
		local_04.lpDirectory=NULLPO;
		local_04.nShow=1;
		local_04.lpIDList=NULLPO;
		ShellExecuteEx(&local_04);
	}
	return;
}


void CMainControl::mf_CMainControl_1050()
{
#ifdef EXACTMATCH
	unsigned int tmp0=mf_CMainControl_0610();
	unsigned int tmp=tmp0;
	( *((CWork **)((unsigned)tmp*4+(unsigned)m_vectorpCWork_.begin()) ) )->mf_CWork_0170();
#else
	m_vectorpCWork_[mf_CMainControl_0610()]->mf_CWork_0170();
#endif
}


void CMainControl::mf_CMainControl_1060()
{
	int local_00;
	CHost * local_01;
	m_int_CurrentTransferUpToPortzeroConnectionCount_=0;
	m_int_CurrentBBSTransferDownConnectionCount_=0;
	m_int_CurrentBBSTransferUpConnectionCount_=0;
	m_int_CurrentBBSDownConnectionCount_=0;
	m_int_CurrentBBSUpConnectionCount_=0;
	m_int_CurrentTransferProxyConnectionCount_=0;
	m_int_CurrentSearchDownConnectionCount_=0;
	m_int_CurrentSearchUpConnectionCount_=0;
	m_int_CurrentTransferDownConnectionCount_=0;
	m_int_CurrentTransferUpConnectionCount_=0;
	for (local_00=1; local_00<600; local_00++) {
		local_01=m_hostArray+local_00;
		if (!local_01->m_flgIsValid||!local_01->m_flgIsConnected||local_01->m_flgUnknown_7F||local_01->m_flg_IsBBSPort) continue;
		if (!local_01->m_flgIsTransferLink_8) {
			if (local_01->m_flgIsBBSNode_8) {
				if (local_01->m_flg_isDownConnection) {
					m_int_CurrentBBSDownConnectionCount_=m_int_CurrentBBSDownConnectionCount_+1;
					continue;
				}
				m_int_CurrentBBSUpConnectionCount_=m_int_CurrentBBSUpConnectionCount_+1;
				continue;
			}
			if (local_01->m_flg_isDownConnection) {
				m_int_CurrentSearchDownConnectionCount_=m_int_CurrentSearchDownConnectionCount_+1;
				continue;
			}
			m_int_CurrentSearchUpConnectionCount_=m_int_CurrentSearchUpConnectionCount_+1;
			continue;
		}
		if (local_01->m_flgIsBBSNode_8) {
			if (local_01->GetflgIsUpConnection()) {
				m_int_CurrentBBSTransferDownConnectionCount_=m_int_CurrentBBSTransferDownConnectionCount_+1;
			} else {
				m_int_CurrentBBSTransferUpConnectionCount_=m_int_CurrentBBSTransferUpConnectionCount_+1;
			}
		} else {
			if (local_01->GetflgIsUpConnection()) {
				m_int_CurrentTransferDownConnectionCount_=m_int_CurrentTransferDownConnectionCount_+1;
			} else {
				if (local_01->m_flgIsPortZero_9) {
					m_int_CurrentTransferUpToPortzeroConnectionCount_=m_int_CurrentTransferUpToPortzeroConnectionCount_+1;
				}
				if (local_01->m_int_connectionTimeInSec>5) {
					m_int_CurrentTransferUpConnectionCount_=m_int_CurrentTransferUpConnectionCount_+1;
				}
			}
		}
		if (!local_01->m_flgIsTransferProxy_8) continue;
		m_int_CurrentTransferProxyConnectionCount_=m_int_CurrentTransferProxyConnectionCount_+1;
	}
	return;
}


void CMainControl::mf_CMainControl_1070(const char * arg_0)
{
	int local_00;
	int local_01;
	local_00=(int)GetTickCount();
	if (local_00-g_int_unk411>=1000) {
		g_int_unk411=local_00;
		if (!m_flg_IsJoiningBBSCluster_) {
			mf_CMainControl_1400(arg_0);
			return;
		}
		m_int_unk41=m_int_unk41+1;
		for (local_01=0; local_01<5; local_01++) {
			if (m_int_CurrentBBSUpConnectionCount_>0) {
				unsigned int tmp=mf_CMainControl_0660();
				CQuery * local_02=GetQuery(tmp);
				local_02->mf_CQuery_0000(arg_0,"",m_int_unk41);
				local_02->m_flg_unk03=false;
				local_02->m_flg_isBbsQuery__=true;
				local_02->SetPort(m_port_accept_);
				local_02->SetIpaddr(&m_hostArray->m_ipaddr3);
			}
			if (m_int_CurrentBBSDownConnectionCount_<=0) continue;
			unsigned int tmp2=mf_CMainControl_0660();
			CQuery * local_03=GetQuery(tmp2);
			local_03->mf_CQuery_0000(arg_0,"",m_int_unk41);
			local_03->m_flg_isBbsQuery__=true;
			local_03->m_flg_unk03=true;
			local_03->SetPort(m_port_accept_);
			local_03->SetIpaddr(&m_hostArray->m_ipaddr3);
		}
	}
	return;
}



void CMainControl::mf_CMainControl_1080(const char * arg_0,char * arg_1,bool arg_2,int arg_3)
{
	int local_00;
	int local_01;
	char local_04[1024];
	if (arg_3<1) {
		arg_3=1;
	}
	local_00=(int)GetTickCount();
	if (local_00-g_int_unk412<arg_3*1000) {
		g_int_unk413=g_int_unk413+1;
		if (g_int_unk413>2) {
			return;
		}
	} else {
		if (arg_3>1) {
			g_int_unk412=local_00;
			g_int_unk413=0;
		}
	}
	m_int_unk41=m_int_unk41+1;
	if ((int)*arg_1==35) {
		ny_htmlproc_5(arg_1+1,local_04);
	} else {
		strcpy(local_04,arg_1);
	}
	if (arg_2) {
		mf_CMainControl_0870(arg_0,local_04);
	}
	for (local_01=0; local_01<arg_3; local_01++) {
		if (m_int_CurrentSearchUpConnectionCount_>0) {
			unsigned int tmp=mf_CMainControl_0660();
			CQuery * local_02=GetQuery(tmp);
			local_02->mf_CQuery_0000(arg_0,local_04,m_int_unk41);
			local_02->m_flg_unk03=false;
			local_02->SetPort(m_port_accept_);
			local_02->SetIpaddr(&m_hostArray->m_ipaddr3);
		}
		if (m_int_CurrentSearchDownConnectionCount_<=0) continue;
		unsigned int tmp2=mf_CMainControl_0660();
		CQuery * local_03=GetQuery(tmp2);
		local_03->mf_CQuery_0000(arg_0,local_04,m_int_unk41);
		local_03->m_flg_unk03=true;
		local_03->SetPort(m_port_accept_);
		local_03->SetIpaddr(&m_hostArray->m_ipaddr3);
	}
	return;
}


void CMainControl::mf_CMainControl_1090()
{
	int local_00;
	local_00=m_vectorCQuery_.size();
	int local_01;
	for (local_01=0; local_01<local_00; local_01++) {
		CQuery * local_02;
		local_02=&m_vectorCQuery_[local_01];
		if (!local_02->m_flg_unk04) continue;
		int local_03=600;
		int local_04=0;
		if (g_int_unk414>=local_03) {
			g_int_unk414=0;
		}
		if (local_02->m_flg_unk02) {
			if ( (int)local_02->m_vectorCHostHeader_.size()>0 ) {
				_in_addr local_05;
				int local_06;
				if ( local_02->mf_CQuery_0020(&local_05,&local_06) ) {
					int local_07;
					CHost * local_08;
					for (local_07=1; local_07<local_03; local_07++) {
						local_08=m_hostArray+local_07;
						if (!local_08->m_flgIsValid||local_08->m_flgIsBBSNode_8!=local_02->m_flg_isBbsQuery__||local_08->m_flg_IsBBSPort||local_08->m_port1!=local_06||!(local_08->IsInternalIpaddr_x(local_05))||local_08->m_flgIsTransferLink_8) continue;
						local_04=local_02->mf_CQuery_0070(gbuf20000_hatena8,m_hostArray,local_08,local_08->m_int_version<10900);
						mf_CMainControl_0370(local_07,gbuf20000_hatena8,local_04);
					}
				}
			}
		} else {
			bool local_09;
			local_09=false;
			if (! (!(!local_02->m_flg_unk01)&&local_02->m_flg_unk03) ) {
				local_02->mf_CQuery_0010(&m_hostArray->m_ipaddr3,m_port_accept_);
				local_09=true;
			}
			if (!local_02->m_flg_unk03) {
				int local_10;
				int local_11;
				CHost * local_12;
				for (local_10=1; local_10<local_03; local_10++) {
					local_11=local_10;
					if (!local_02->m_flg_unk01) {
						local_11=(g_int_unk414+local_10)%local_03;
					}
					if (local_11==0) continue;
					local_12=m_hostArray+local_11;
					if ((!local_12->m_flgIsValid||!local_12->m_flgIsConnected||local_12->m_flgIsBBSNode_8!=local_02->m_flg_isBbsQuery__)||!(!local_02->m_flg_isBbsQuery__)&&local_12->m_flgIsPortZero_9
					  ||(local_12->m_flg_IsBBSPort
					  ||local_12->m_int_connectionTimeInSec<=5
					  ||local_12->m_flgIsTransferLink_8
//!!452e51 ちょっと変。if分離か？
					  ||local_12->GetflgIsDownConnection() )
					  ||!(!local_12->m_flgIsPortZero_9)&&!local_02->m_flg_unk01||!local_09&&local_02->mf_CQuery_0050(&local_12->m_ipaddr3,local_12->m_port1)>=0) continue;
					local_04=local_02->mf_CQuery_0070(gbuf20000_hatena8,m_hostArray,m_hostArray+local_11,local_12->m_int_version<10900);
					mf_CMainControl_0370(local_11,gbuf20000_hatena8,local_04);
					g_int_unk414=local_11;
					if (!local_02->m_flg_unk01) break;
				}
			} else {
				int local_13;
				CHost * local_14;
				local_13=1;
				while (local_13<local_03) {
					local_14=m_hostArray+local_13;
					if (! ((!local_14->m_flgIsValid||local_14->m_flgIsBBSNode_8!=local_02->m_flg_isBbsQuery__)||!(!local_02->m_flg_isBbsQuery__)&&local_14->m_flgIsPortZero_9||(local_14->m_flg_IsBBSPort||!local_14->m_flgIsConnected||local_14->m_int_connectionTimeInSec<=5||local_14->m_flgIsTransferLink_8||!local_14->m_flg_isDownConnection)||!(!local_14->m_flgIsPortZero_9)&&!local_02->m_flg_unk01) ) {
						local_04=local_02->mf_CQuery_0070(gbuf20000_hatena8,m_hostArray,m_hostArray+local_13,local_14->m_int_version<10900);
						mf_CMainControl_0370(local_13,gbuf20000_hatena8,local_04);
					}
					local_13=local_13+1;
				}
			}
		}
		local_02->m_flg_unk04=false;
	}
	g_int_unk414=g_int_unk414+1;
	return;
}


void CMainControl::mf_CMainControl_1100(int arg_0,char * arg_1,int arg_2,int arg_3)
{
	int local_00;
	unsigned int local_01;
	local_00=0;
	for (local_01=0; m_vectorCQuery_.size()>local_01; local_01++) {
		if (!m_vectorCQuery_[local_01].Get_flg_unk04()) continue;
		local_00=local_00+1;
	}
	if (local_00<10) {
		mf_CMainControl_1130(arg_0,"","",arg_1,arg_2,false,arg_3,false);
	}
	return;
}


void CMainControl::mf_CMainControl_1110(int arg_0,const char * arg_1,const char * arg_2,int arg_3,bool arg_4)
{
	int local_00;
	unsigned int local_01;
	local_00=0;
	for (local_01=0; m_vectorCQuery_.size()>local_01; local_01++) {
		if (!m_vectorCQuery_[local_01].Get_flg_unk04()) continue;
		local_00=local_00+1;
	}
	if (local_00<10) {
		mf_CMainControl_1130(arg_0,arg_1,arg_2,NULLPO,0,false,arg_3,arg_4);
	}
	return;
}


void CMainControl::mf_CMainControl_1120(int arg_0,const char * arg_1,const char * arg_2,int arg_3,bool arg_4)
{
	int local_00;
	unsigned int local_01;
	local_00=0;
	for (local_01=0; m_vectorCQuery_.size()>local_01; local_01++) {
		if (!m_vectorCQuery_[local_01].Get_flg_unk04()) continue;
		local_00=local_00+1;
	}
	if (local_00<10) {
		mf_CMainControl_1130(arg_0,arg_1,arg_2,NULLPO,0,true,arg_3,arg_4);
	}
	return;
}



void CMainControl::mf_CMainControl_1130(int arg_0,const char * arg_1,const char * arg_2,char * arg_3,int arg_4,bool arg_5,int arg_6,bool arg_7)
{
	time_t local_00;
	unsigned char local_35[32];
	unsigned char local_36[32];
	char local_37[1024];
	unsigned char local_38[32];
	char local_39[16];
	char local_40[16];
	char local_41[16];

	if (arg_0<0||!m_hostArray[arg_0].m_flgIsConnected) return;
	time(&local_00);
	CHost * local_01;
	local_01=m_hostArray+arg_0;
	int tmp;
	CQuery * local_02;
	tmp=mf_CMainControl_0660();
	local_02=GetQuery(tmp);
	local_02->Set_flg_unk04(true);
	if (arg_4==0) {
		local_02->mf_CQuery_0000(arg_1,arg_2,arg_6);
		local_02->Set_flg_isBbsQuery__(arg_7);
		local_02->SetIpaddr(&m_hostArray->m_ipaddr3);
		local_02->SetPort(m_port_accept_);
		if (!arg_5) {
			local_02->m_flg_unk03=false;
			local_02->m_flg_unk01=true;
		} else {
			local_02->m_flg_unk03=true;
			local_02->m_flg_unk01=true;
		}
	} else {
		local_02->mf_CQuery_0000("","",arg_6);
		local_02->mf_CQuery_0080(arg_3,arg_4,local_01->m_int_version<10900);
		if (local_01->m_flgIsPortZero_9) {
			local_02->m_flg_isFromPortZero__=true;
		}
		local_02->SetIpaddr(&local_01->m_ipaddr3);
		local_02->SetPort(local_01->m_port1);
		if (local_01->m_flgIsNAT) {
			local_02->mf_CQuery_0060(local_01,&local_01->m_ipaddr3,local_01->m_port1);
		}
		if (! (local_02->m_flg_unk02||local_02->m_flg_unk01) ) {
			if (! (!((int)local_02->m_vectorCHostHeader_.size()>6||m_optflag_notConnected__||(int)local_02->m_vectorCKeyHeader_.size()>=30)&&local_02->mf_CQuery_0050(&m_hostArray->m_ipaddr3,m_port_accept_)<0) )  {
				local_02->m_flg_unk02=true;
			} else {
				int local_03;
				local_03=1;
				if (!local_02->m_flg_unk03) {
					if (! (!(!local_02->m_flg_isBbsQuery__&&m_int_CurrentSearchUpConnectionCount_==0)&&(!local_02->m_flg_isBbsQuery__||m_int_CurrentBBSUpConnectionCount_!=0)) ) {
						local_02->m_flg_unk03=true;
						for ( ; local_03<600; local_03++) {
							CHost * local_04=m_hostArray+local_03;
							if (!(!local_04->m_flgIsValid||!local_04->m_flgIsConnected
							  ||local_04->m_flgIsBBSNode_8!=local_02->m_flg_isBbsQuery__
							  ||local_04->m_flgIsTransferLink_8
							  ||!local_04->m_flg_isDownConnection
							  ||local_04->m_int_lineSpeed<=30)&&local_02->mf_CQuery_0050(&local_04->m_ipaddr3,local_04->m_port1)<0) break;
						}
					}
				} else {
					local_02->m_flg_unk03=false;
					for ( ; local_03<600; local_03++) {
						CHost * local_05=m_hostArray+local_03;
						if (!(!local_05->m_flgIsValid
						  ||!local_05->m_flgIsConnected
						  ||local_05->m_flgIsBBSNode_8!=local_02->m_flg_isBbsQuery__
						  ||local_05->m_flgIsTransferLink_8
						  ||local_05->GetflgIsDownConnection() )
						  &&local_02->mf_CQuery_0050(&local_05->m_ipaddr3,local_05->m_port1)<0) break;
					}
				}
				if (local_03==600) {
					local_02->m_flg_unk02=true;
				}
			}
		}
	}

	int local_06;
	int local_07;
	int local_08;
	int local_09;
	int local_10;
	int local_11;
	int local_12;
	unsigned short local_13;
	time_t local_14;

	local_06=m_KeyBuffer_.size();
	if (local_06==0) {
		local_06=1;
	}
	local_07=0;
	local_08=m_KeyBuffer_.size();
	local_09=m_int_linespeed_/40;
	if (local_01->m_int_lineSpeed<m_int_linespeed_) {
		local_09=local_01->m_int_lineSpeed/40;
	}
	if (! (local_02->m_flg_unk03||local_09<1||local_09>=10) ) {
		local_09=10;
	}
	if (local_09<1) {
		local_09=1;
	}
	if (local_09>100) {
		local_09=100;
	}
	if (arg_4==0) {
		if (m_int_uptimeInSec_>0x000186A0) {
			m_int_uptimeInSec_=0;
		}
		if (local_02->m_flg_isBbsQuery__) {
			local_07=(m_int_uptimeInSec_*local_09)*12%local_06;
			local_08=local_09*120+local_07;
		} else {
			local_07=(m_int_uptimeInSec_*local_09)*2%local_06;
			local_08=local_09*60+local_07;
		}
		if (local_08>=local_06) {
			local_08=local_06;
		}
	}
	local_10=0;
	local_11=0;
	local_12=0;
	local_13=0;
	if ( ((!local_02->m_flg_unk01)||arg_4==0) ) {
		time(&local_14);
		local_14=local_14+600;
		if (!local_02->m_flg_unk01) {
			local_13=mf_CMainControl_0590(local_02->m_sz_filename__);
		}
		if ( ( local_13==0 || m_KeySearchTable_.count(local_13)!=0) ) {
			int dummy;
			multimap<unsigned short,unsigned int>::iterator local_15;
			if (local_13!=0) {
				local_15=m_KeySearchTable_.find(local_13);
			}
			while (true) {
				if (!(local_13==0)&&local_15==m_KeySearchTable_.end()) break;
				unsigned int local_16=0;
				if (local_13!=0) {
					if (local_15->first!=local_13) break;
					local_16=local_15->second;
				}
				if ( ( local_13==0 || m_KeyBuffer_.count(local_16)!=0 ) ) {
					multimap<unsigned int,CKey>::iterator local_17;
					if (local_13!=0) {
						local_17=m_KeyBuffer_.find(local_16);
					} else {
						local_17=m_KeyBuffer_.begin();
					}
					for (; local_17!=m_KeyBuffer_.end(); local_17++) {
						CKey * local_18=&local_17->second;
						if (local_18->m_int_unk0x==0) continue;
						if (!(local_13==0)&&*((int *)local_18->m_hash_tabun)!=local_16) break;
						if (local_02->m_flg_isBbsQuery__!=local_18->m_bln_unk308||!(local_18->m_char_keyType_!=KEYTYPE01)&&local_18->m_bln_unk302) continue;
						if ( (!(local_18->m_bln_unk308||local_18->m_char_keyType_<KEYTYPE02)) ) {
							if (m_int_CurrentTransferUpConnectionCount_ >= m_int_related_maxconnection__) {
								if (rand()%20!=0) continue;
							} else {
								if (!(m_int_related_maxconnection__-1!=m_int_CurrentTransferUpConnectionCount_)&&rand()%5!=0) continue;
							}
						}
						if (! (!(local_18->m_char_keyType_!=KEYTYPE00)&&local_18->m_int_unk200<0||!(!local_18->m_bln_unk308)&&(m_optflag_notConnected__||!mf_CMainControl_1190(local_18))||!(!m_optflag_notConnected__)&&local_18->m_char_keyType_==KEYTYPE00) ) {
							local_18->m_bln_unk303=false;
							local_18->m_bln_unk304=false;
							local_10=local_10+1;
							if (! (!local_02->m_flg_unk01&&!local_18->mf_CKey_0040(local_02->m_sz_filename__,(char *)local_02->m_uchar16_unk1,true)) ) {
								bool local_19=false;
								if (! (!(local_18->m_bln_unk308||local_18->m_char_keyType_!=KEYTYPE01)&&(!(local_18->m_int_refcountOfFileptr_!=0)&&!mf_CMainControl_1180(local_18)||local_18->mf_CKey_0150()==0)||!(arg_4!=0)&&(local_18->m_int_unk201%local_06<local_07||local_18->m_int_unk201%local_06>=local_08)) ) {
									bool local_20=false;
									int local_21=25;
									local_21=local_21-(int)(((double)local_18->mf_CKey_0150()/(double)local_18->mf_CKey_0170())*15.0);
									if (local_21<1) {
										local_21=1;
									}
									if (! (!local_02->m_flg_unk03||m_int_currentTransferUpConnectionMax_-1<=m_int_CurrentTransferUpConnectionCount_||rand()%local_21!=0) ) {
										local_20=true;
									}
									if (! (local_18->m_char_keyType_!=KEYTYPE00||(local_18->GetRefs())*local_18->Get_uint_unk206()<=0x00027100) ) {
										local_20=false;
									}
									if (local_18->m_bln_unk308) {
										local_20=(bool)(local_18->m_char_keyType_==KEYTYPE03);
									}
									if (local_18->m_bln_unk308) {
										local_12=local_12+1;
									}
									local_02->mf_CQuery_0030(local_18,m_hostArray,local_20,local_19,!(local_09<=2)?local_09*80:local_09*40);
									local_11=local_11+1;
								}
							}
						}
					}
				}
				if (local_13==0) break;
				local_15++;
			}
		}
	}

	int local_22;
	if (! (arg_4==0||!local_02->m_flg_unk01&&!local_02->m_flg_unk02) ) {
		local_22=local_02->m_vectorCKeyHeader_.size();
		memset(local_39,0,16);
		//このへんの変数は見直しが必要
		int local_23;
		int local_24;
		int local_25;
		bool local_26;
		int local_27;
		unsigned int local_28;
		bool local_29;
		int local_30;
		time_t local_31;
		bool local_32;
		int local_33;

		for (local_33=0; local_33<local_22; local_33++) {
			if ((!local_02->mf_CQuery_0040(local_33,(_in_addr *)local_35,&local_23,(_in_addr *)local_36,&local_24,local_37,&local_28,(unsigned int *)/*nya*/&local_25,local_38,&local_27,&local_30,&local_29,&local_31,local_40,&local_32,local_41)||memcmp(local_38,local_39,16)==0||local_27>=0x000186A0)||!(!local_02->m_flg_isBbsQuery__)&&local_25>0x00100000
			  ||local_25<0
			  ||m_hostArray[0].IsInternalIpaddr_e(local_36[0],local_36[1],local_36[2],local_36[3]) &&m_port_accept_==local_24
			  ||!(!local_02->m_flg_isBbsQuery__)&&local_40[0]==0
			  /*71*/||!(!local_02->m_flg_isBbsQuery__)&&(unsigned int)local_30>1200
			  ||(local_35[0]==127||local_35[0]==192
			  //)
			  /*71*/||!ny_htmlproc_4a(local_40)||(local_28>(unsigned int)m_int_maxnamelen_70))
			  ||!(!(m_hostArray[0].IsInternalIpaddr_e(local_35[0],local_35[1],local_35[2],local_35[3])))&&m_port_accept_==local_23) continue;

			CKey * local_34=this->mf_CMainControl_0600(true,local_37,local_28,local_25,local_38,0,&local_26,local_40,0,local_02->m_flg_isBbsQuery__,(unsigned int)local_31,local_30);
			if (local_34==0||local_34->m_bln_unk311) continue;
			local_34->Set_bln_unk307(local_01->GetflgIsUpConnection());
			strcpy((char *)local_34->m_char16_char11kamo,local_41);
			if (local_34->m_char_keyType_!=KEYTYPE02) {
				if (!local_26) {
					mf_CMainControl_0580(local_34);
				}
				if (! (!(!(local_34->m_int_refcountOfFileptr_!=0)&&(local_34->m_bln_unk308||local_34->m_char_keyType_<KEYTYPE01))&&(local_34->m_char_keyType_!=KEYTYPE01||mf_CMainControl_1240((_in_addr *)local_35,local_23))||!(local_34->m_bln_unk308||local_34->m_portno_0__!=local_34->m_portno_2__)&&memcmp(&local_34->m_ipaddr_0__,&local_34->m_ipaddr_2__,4)==0) ) {
					local_35[1]=local_35[1]^'^';
					local_35[2]=local_35[2]^'^';
					local_35[3]=local_35[3]^'^';
					memcpy(&local_34->m_ipaddr_0__,local_35,4);
					local_34->Set_portno_0(local_23);
					local_36[1]=local_36[1]^'^';
					local_36[2]=local_36[2]^'^';
					local_36[3]=local_36[3]^'^';
					memcpy(&local_34->m_ipaddr_1__,local_36,4);
					local_34->Set_portno_1(local_24);
				}
			}
			if (! (local_34->m_bln_unk308||(local_34->GetRefs())>=local_30||local_34->mf_CKey_0170()*10000<=local_30) ) {
				local_34->SetRefs(local_30);
			}
			if (local_02->m_flg_isFromPortZero__) {
				local_34->m_bln_unk311=true;
			}
			if (! (!((int)*local_34->mf_CKey_0260()==64||*(local_34->mf_CKey_0260()+1)==0)&&(!local_02->m_flg_isBbsQuery__||strncmp(local_34->mf_CKey_0260(),"[BBS_",5)==0)) ) {
				local_34->m_int_unk0x=0;
				continue;
			}
			local_34->Set_bln_unk313(local_29);
			if (local_34->m_bln_unk308) {
				local_34->Set_int_unk203(6);
			} else {
				if (local_34->mf_CKey_0170()>1) {
					local_34->Set_int_unk203((int)((unsigned int)local_32));
				}
			}
			local_34->Set_int_unk200(local_27);
		}
		if (local_02->m_flg_unk01) {
			local_02->m_flg_unk04=false;
		}
	}
	return;
}


void CMainControl::mf_CMainControl_1140()
{
	int local_00;
	int local_01;
	bool local_02;

	m_int_CurrentSearchDownConnectionCount_=0;
	m_int_CurrentSearchUpConnectionCount_=0;
	m_int_CurrentTransferDownConnectionCount_=0;
	m_int_CurrentTransferUpConnectionCount_=0;
	m_int_CurrentTransferUpToPortzeroConnectionCount_=0;
	m_int_CurrentBBSTransferUpConnectionCount_=0;
	m_int_CurrentBBSTransferDownConnectionCount_=0;
	m_int_CurrentBBSUpConnectionCount_=0;
	m_int_CurrentBBSDownConnectionCount_=0;
	m_int_CurrentTransferProxyConnectionCount_=0;
	local_02=(m_uint_cacheDriveFreeMByte_<100||m_uint_downDriveFreeMByte_<100);
	if (!m_optflag_Connect__) {
		for (local_00=1; local_00<600; local_00++) {
			CHost * local_03;
			local_03=m_hostArray+local_00;
			if (local_03->m_flg_IsBBSPort||!local_03->m_flgIsValid
			  ||!local_03->m_flgIsConnected) continue;
			local_03->mf_CHost_0190(true);
		}
	} else {
		m_int_portWarnedCount_=0;
		for (local_00=1; local_00<600; local_00++) {
			CHost * local_04;
			local_04=m_hostArray+local_00;
			if (! (local_04->m_flg_IsBBSPort
			  ||!(local_04->m_ipaddr3.b1==127)&&local_04->m_ipaddr3.b1!=192) ) {
				local_04->mf_CHost_0190(true);
				local_04->m_flgIsValid=false;
				continue;
			}
			if (! (!local_04->m_flgIsValid||local_04->m_flgIsConnected) ) {
				if (local_04->m_field_94) {
					m_int_portWarnedCount_=m_int_portWarnedCount_+1;
				}
				if (local_04->m_flgIsBBSConnectionTest) {
					local_04->m_int_nodataTimeInSec=local_04->m_int_nodataTimeInSec+1;
					continue;
				}
//4544f8 このへん変数アサインが変
				int tmp1=local_04->m_int_unk5;
				if (tmp1>0) {
					local_04->m_int_unk5=local_04->m_int_unk5-1;
					if (! (!(local_04->m_int_unk5<=0)&&local_04->m_int_preference2_negative<25) ) {
						local_04->mf_CHost_0190(true);
						local_04->m_flgIsValid=false;
						continue;
					}
				}
			}
			if (!local_04->m_flgIsValid||!local_04->m_flgIsConnected) continue;
			local_04->m_int_connectionTimeInSec=local_04->m_int_connectionTimeInSec+1;
			local_04->m_int_nodataTimeInSec=local_04->m_int_nodataTimeInSec+1;
			if (local_04->m_int_connectionTimeInSec>1) {
				if (! (memcmp(m_hash_exeHash_,g_exesignature_defined,16)==0||local_04->m_int_connectionTimeInSec<g_int_unk415*35) ) {
					char local_05;
					local_05=31;
					mf_CMainControl_0370(local_00,&local_05,1);
				}
				if (! (local_04->m_port1!=m_port_accept_
				  ||!(local_04->IsInternalIpaddr_x2b(m_hostArray[0].m_ipaddr3) )) ) {
					local_04->mf_CHost_0190(true);
					continue;
				}
				if (! (!(!(local_04->m_int_connectionTimeInSec<=20)&&(local_04->m_port1==0||!local_04->m_field_8D))&&(!local_04->m_flgIsBadPortZero_9&&local_04->m_int_nodataTimeInSec<=300)) ) {
					local_04->mf_CHost_0190(true);
					continue;
				}
				if (! (local_04->m_int_connectionTimeInSec<=120||!local_04->m_flgIsBBSNode_8||!local_04->m_flgIsTransferLink_8) ) {
					local_04->mf_CHost_0190(true);
					continue;
				}
				if (! (local_04->m_flgIsBBSNode_8||local_04->m_int_lineSpeed<m_int_linespeed_||!local_04->m_flgIsPortZero_9||local_04->m_flgIsTransferLink_8) ) {
					local_04->mf_CHost_0190(true);
					continue;
				}
				if (! (!m_optflag_notConnected__||!local_04->m_flgIsPortZero_9) ) {
					local_04->mf_CHost_0190(true);
					continue;
				}
				if (! (!m_optflg_UseBbsOnly_||local_04->m_flgIsBBSNode_8||!local_04->m_field_8D||local_04->m_flg_IsBBSPort||local_04->m_flgUnknown_7F) ) {
					local_04->mf_CHost_0190(true);
					continue;
				}
				if (! ((m_flg_IsJoiningBBSCluster_||!local_04->m_flgIsBBSNode_8||!local_04->m_field_8D)||!local_04->m_flgIsPortZero_9&&(!local_04->m_flg_isDownConnection||local_04->m_flg_IsBBSPort||local_04->m_flgUnknown_7F)) ) {
					local_04->mf_CHost_0190(true);
					continue;
				}
				if ( local_04->m_flgUnknown_7F && local_04->GetflgIsUpConnection()  ) {
					for (local_01=1; local_01<600; local_01++) {
						if (local_00==local_01) continue;
						CHost * local_06;
						local_06=m_hostArray+local_01;
						if (local_06->m_port1!=local_04->m_port1||!((bool)local_06->IsInternalIpaddr_x2b(local_04->m_ipaddr3) )) continue;
						local_06->m_flgUnknown_80=true;
					}
					local_04->mf_CHost_0190(true);
					continue;
				}
				if (memcmp(m_hash_memorySignature_,g_memorysignature_compared,16)!=0&&local_04->m_int_connectionTimeInSec>=g_int_unk415a_70*35) {
					char local_07;
					local_07=31;
					mf_CMainControl_0370(local_00,&local_07,1);
				}
			}
			if (local_04->m_flgIsPortZero_9||!local_04->m_field_8D||local_04->m_int_connectionTimeInSec<=30||local_04->m_flgUnknown_80||local_04->m_flg_IsBBSPort) continue;
			char local_08;
			local_08='!';
			mf_CMainControl_0370(local_00,&local_08,1);
			local_04->m_flgIsBadPortZero_9=true;
		}
	}
	for (local_00=1; local_00<600; local_00++) {
		CHost * local_09;
		bool local_10;
		CHost * local_11;
		local_09=m_hostArray+local_00;
		if (! ((!local_09->m_flgIsValid||local_09->m_flgIsBBSNode_8)||!(!local_09->m_flgIsConnected)&&local_09->m_flgIsTransferLink_8||!(!local_09->m_flgIsConnected)&&local_09->m_int_connectionTimeInSec<10||local_09->m_field_81) ) {
			local_10=false;
			for (local_01=0; local_01<600; local_01++) {
				local_11=m_hostArray+local_01;
				if ((local_00==local_01||!local_11->m_flgIsValid||local_11->m_flgIsBBSNode_8)||!(!local_11->m_flgIsConnected)&&local_11->m_flgIsTransferLink_8||!(!local_11->m_flgIsConnected)&&local_11->m_int_connectionTimeInSec<10||(local_11->m_field_81
				  ||local_09->m_port1!=local_11->m_port1||!(local_09->IsInternalIpaddr_x2b(local_11->m_ipaddr3)))) continue;
				if (! (!local_09->m_flgIsConnected||!m_hostArray[local_01].m_flgIsConnected||local_09->m_int_connectionTimeInSec>=local_11->m_int_connectionTimeInSec) ) {
					local_10=true;
					if (local_09->m_int_preference2_positive<=local_11->m_int_preference2_positive) continue;
					local_11->SetPreference2_positive(local_09->m_int_preference2_positive);
					continue;
				}
				if (local_11->m_flgIsConnected||local_09->m_flgIsConnected) continue;
				local_11->m_flgIsValid=false;
			}
			if (local_10) {
				local_09->mf_CHost_0190(true);
				local_09->m_field_8D=false;
				local_09->m_flgIsValid=false;
			}
		}
	}
	for (local_00=1; local_00<600; local_00++) {
		CHost * local_12;
		bool local_13;
		CHost * local_14;
		local_12=m_hostArray+local_00;
		if ((!local_12->m_flgIsValid||!local_12->m_flgIsBBSNode_8)||!(!local_12->m_flgIsConnected)&&local_12->m_flgIsTransferLink_8||!(!local_12->m_flgIsConnected)&&local_12->m_int_connectionTimeInSec<10||local_12->m_field_81) continue;
		local_13=false;
		for (local_01=0; local_01<600; local_01++) {
			local_14=m_hostArray+local_01;
			if ((local_00==local_01||!local_14->m_flgIsValid||!local_14->m_flgIsBBSNode_8)||!(!local_14->m_flgIsConnected)&&local_14->m_flgIsTransferLink_8||!(!local_14->m_flgIsConnected)&&local_14->m_int_connectionTimeInSec<10||(local_14->m_field_81
			  ||local_12->m_port1!=local_14->m_port1||!(local_12->IsInternalIpaddr_x2b(local_14->m_ipaddr3)))) continue;
			if (! (!local_12->m_flgIsConnected||!m_hostArray[local_01].m_flgIsConnected||local_12->m_int_connectionTimeInSec>=local_14->m_int_connectionTimeInSec) ) {
				local_13=true;
				if (local_12->m_int_preference2_positive<=local_14->m_int_preference2_positive) continue;
				local_14->SetPreference2_positive(local_12->m_int_preference2_positive);
				continue;
			}
			if (local_14->m_flgIsConnected||local_12->m_flgIsConnected) continue;
			local_14->m_flgIsValid=false;
		}
		if (!local_13) continue;
		local_12->mf_CHost_0190(true);
		local_12->m_field_8D=false;
		local_12->m_flgIsValid=false;
	}
	for (local_00=1; local_00<600; local_00++) {
		CHost * local_15;
		bool local_16;
		CHost * local_17;
		local_15=m_hostArray+local_00;
		if ((!local_15->m_flgIsValid||local_15->m_flgIsBBSNode_8)||!(!local_15->m_flgIsConnected)&&!local_15->m_flgIsTransferLink_8||!(!local_15->m_flgIsConnected)&&local_15->m_int_connectionTimeInSec<10||local_15->m_field_81) continue;
		local_16=false;
		for (local_01=0; local_01<600; local_01++) {
			local_17=m_hostArray+local_01;
			if ((local_00==local_01||!local_17->m_flgIsValid||local_17->m_flgIsBBSNode_8)||!(!local_17->m_flgIsConnected)&&!local_17->m_flgIsTransferLink_8||!(!local_17->m_flgIsConnected)&&local_17->m_int_connectionTimeInSec<10
			  ||(local_17->m_field_81||!(local_15->IsInternalIpaddr_x2b(local_17->m_ipaddr3))||!local_15->m_flgIsConnected||!m_hostArray[local_01].m_flgIsConnected
			  ||local_15->GetflgIsUpConnection()!=local_17->GetflgIsUpConnection()
			  ||local_15->m_int_connectionTimeInSec>=local_17->m_int_connectionTimeInSec)) continue;
			local_16=true;
			if (local_15->m_int_preference2_positive<=local_17->m_int_preference2_positive) continue;
			local_17->SetPreference2_positive(local_15->m_int_preference2_positive);
		}
		if (!local_16) continue;
		local_15->mf_CHost_0190(true);
		local_15->m_field_8D=false;
		local_15->m_flgIsValid=false;
	}
	for (local_00=1; local_00<600; local_00++) {
		CHost * local_18;
		bool local_19;
		CHost * local_20;
		local_18=m_hostArray+local_00;
		if ((!local_18->m_flgIsValid||!local_18->m_flgIsBBSNode_8)||!(!local_18->m_flgIsConnected)&&!local_18->m_flgIsTransferLink_8||!(!local_18->m_flgIsConnected)&&local_18->m_int_connectionTimeInSec<10||local_18->m_field_81) continue;
		local_19=false;
		for (local_01=0; local_01<600; local_01++) {
			local_20=m_hostArray+local_01;
			if ((local_00==local_01||!local_20->m_flgIsValid||!local_20->m_flgIsBBSNode_8)||!(!local_20->m_flgIsConnected)&&!local_20->m_flgIsTransferLink_8||!(!local_20->m_flgIsConnected)&&local_20->m_int_connectionTimeInSec<10
			  ||(local_20->m_field_81||!(local_18->IsInternalIpaddr_x2b(local_20->m_ipaddr3))
			  ||!local_18->m_flgIsConnected||!m_hostArray[local_01].m_flgIsConnected
			  ||local_18->GetflgIsUpConnection()!=local_20->GetflgIsUpConnection()
			  ||local_18->m_int_connectionTimeInSec>=local_20->m_int_connectionTimeInSec)) continue;
			local_19=true;
			if (local_18->m_int_preference2_positive<=local_20->m_int_preference2_positive) continue;
			local_20->SetPreference2_positive(local_18->m_int_preference2_positive);
		}
		if (!local_19) continue;
		local_18->mf_CHost_0190(true);
		local_18->m_field_8D=false;
		local_18->m_flgIsValid=false;
	}
	int local_21;
	int local_22;
	local_21=0;
	local_22=0;
	for (local_00=1; local_00<600; local_00++) {
		CHost * local_23;
		local_23=m_hostArray+local_00;
		if (!local_23->m_flgIsValid||!local_23->m_flgIsConnected||local_23->m_flgUnknown_7F||local_23->m_flg_IsBBSPort) continue;
		if (!local_23->m_flgIsTransferLink_8) {
			if (local_23->m_flgIsBBSNode_8) {
				if (local_23->m_flg_isDownConnection) {
					if (local_23->m_flgIsPortZero_9) {
						local_22=local_22+1;
					}
					m_int_CurrentBBSDownConnectionCount_=m_int_CurrentBBSDownConnectionCount_+1;
					continue;
				}
				m_int_CurrentBBSUpConnectionCount_=m_int_CurrentBBSUpConnectionCount_+1;
				continue;
			}
			if (local_23->m_flg_isDownConnection) {
				m_int_CurrentSearchDownConnectionCount_=m_int_CurrentSearchDownConnectionCount_+1;
				if (!local_23->m_flgIsPortZero_9) continue;
				local_21=local_21+1;
				continue;
			}
			m_int_CurrentSearchUpConnectionCount_=m_int_CurrentSearchUpConnectionCount_+1;
			continue;
		}
		if (local_23->m_flgIsBBSNode_8) {
			if (local_23->GetflgIsUpConnection()) {
				m_int_CurrentBBSTransferDownConnectionCount_=m_int_CurrentBBSTransferDownConnectionCount_+1;
			} else {
				m_int_CurrentBBSTransferUpConnectionCount_=m_int_CurrentBBSTransferUpConnectionCount_+1;
			}
		} else {
			if (local_23->GetflgIsUpConnection()) {
				if (local_02) {
					local_23->mf_CHost_0190(true);
				} else {
					m_int_CurrentTransferDownConnectionCount_=m_int_CurrentTransferDownConnectionCount_+1;
				}
			} else {
				if (local_23->m_flgIsPortZero_9) {
					m_int_CurrentTransferUpToPortzeroConnectionCount_=m_int_CurrentTransferUpToPortzeroConnectionCount_+1;
				}
				if (local_23->m_int_connectionTimeInSec>5) {
					m_int_CurrentTransferUpConnectionCount_=m_int_CurrentTransferUpConnectionCount_+1;
				}
			}
		}
		if (!local_23->m_flgIsTransferProxy_8) continue;
		m_int_CurrentTransferProxyConnectionCount_=m_int_CurrentTransferProxyConnectionCount_+1;
	}
	if (! (m_optflg_UseBbsOnly_||m_int_CurrentSearchUpConnectionCount_>=2) ) {
		mf_CMainControl_0240();
	}
	int local_24;
	int local_25;
	local_24=!(!m_flg_IsJoiningBBSCluster_)?3:4;
	if (! (!m_flg_IsJoiningBBSCluster_&&!m_flg_IsBBSSearchLinkOn_||local_24-1<=m_int_CurrentBBSUpConnectionCount_) ) {
		mf_CMainControl_0250();
	}
	for (local_25=0; local_25<20; local_25++) {
		if (local_21>2) {
			int local_26;
			int local_27;
			CHost * local_28;
			local_26=-1;
			local_27=0x0FFFFFFF;
			for (local_00=1; local_00<600; local_00++) {
				local_28=m_hostArray+local_00;
				if (!local_28->m_flgIsValid||local_28->m_flgIsBBSNode_8||!local_28->m_flgIsConnected||!local_28->m_flgIsPortZero_9||local_28->m_flgIsTransferLink_8||!local_28->m_flg_isDownConnection||!local_28->m_field_8D||local_28->m_int_unk10>=local_27) continue;
				local_27=local_28->m_int_unk10;
				local_26=local_00;
			}
//orphan jump再現のための変更
			if (local_26>=0) {
				if (local_21==3) {
					int tmp=mf_CMainControl_0610();
					m_vectorpCWork_[tmp]->mf_CWork_0130(local_26,true);
					break;
				} else {
					m_hostArray[local_26].mf_CHost_0190(true);
					m_int_CurrentSearchDownConnectionCount_=m_int_CurrentSearchDownConnectionCount_-1;
					local_21=local_21-1;
				}
			}
			continue;
		}
		if (m_int_CurrentSearchDownConnectionCount_<=5) break;
		int local_29;
		int local_30;
		CHost * local_31;
		local_29=-1;
		local_30=0x0FFFFFFF;
		for (local_00=1; local_00<600; local_00++) {
			local_31=m_hostArray+local_00;
			if (!local_31->m_flgIsValid||!local_31->m_flgIsConnected||local_31->m_flgIsTransferLink_8||!local_31->m_flg_isDownConnection||!local_31->m_field_8D||local_31->m_int_unk10>=local_30) continue;
			local_30=local_31->m_int_unk10;
			local_29=local_00;
		}
		if (local_29>=0) {
			if (m_int_CurrentSearchDownConnectionCount_==6) {
				int tmp=mf_CMainControl_0610();
				m_vectorpCWork_[tmp]->mf_CWork_0130(local_29,true);
				break;
			} else {
				m_hostArray[local_29].mf_CHost_0190(true);
				m_int_CurrentSearchDownConnectionCount_=m_int_CurrentSearchDownConnectionCount_-1;
			}
		}
	}
	int local_32;
	int local_33;
	int local_34;
	CHost * local_35;
	for (local_32=0; local_32<20; local_32++) {
		if (local_22>5) {
			local_33=-1;
			local_34=0x0FFFFFFF;
			for (local_00=1; local_00<600; local_00++) {
				local_35=m_hostArray+local_00;
				if (!local_35->m_flgIsValid||!local_35->m_flgIsBBSNode_8||!local_35->m_flgIsConnected||!local_35->m_flgIsPortZero_9||local_35->m_flgIsTransferLink_8||!local_35->m_flg_isDownConnection||!local_35->m_field_8D||local_35->m_int_connectionTimeInSec>=local_34) continue;
				local_34=local_35->m_int_connectionTimeInSec;
				local_33=local_00;
			}
			if (local_33>=0) {
				if (local_22==6) {
					int tmp=mf_CMainControl_0610();
					m_vectorpCWork_[tmp]->mf_CWork_0130(local_33,true);
					break;
				} else {
					m_hostArray[local_33].mf_CHost_0190(true);
					m_int_CurrentBBSDownConnectionCount_=m_int_CurrentBBSDownConnectionCount_-1;
					local_22=local_22-1;
				}
			}
			continue;
		}
		if (m_int_CurrentBBSDownConnectionCount_<=9) break;
		int local_36;
		int local_37;
		local_36=-1;
		local_37=0x0FFFFFFF;
		for (local_00=1; local_00<600; local_00++) {
		CHost * local_38;
			local_38=m_hostArray+local_00;
			if (!local_38->m_flgIsValid||!local_38->m_flgIsBBSNode_8||!local_38->m_flgIsConnected||local_38->m_flgIsTransferLink_8||!local_38->m_flg_isDownConnection||!local_38->m_field_8D||local_38->m_int_connectionTimeInSec>=local_37) continue;
			local_37=local_38->m_int_connectionTimeInSec;
			local_36=local_00;
		}
		if (local_36>=0) {
			if (m_int_CurrentBBSDownConnectionCount_==10) {
				int tmp=mf_CMainControl_0610();
				m_vectorpCWork_[tmp]->mf_CWork_0130(local_36,true);
				break;
			} else {
				m_hostArray[local_36].mf_CHost_0190(true);
				m_int_CurrentBBSDownConnectionCount_=m_int_CurrentBBSDownConnectionCount_-1;
			}
		}
	}
	if (m_int_CurrentSearchUpConnectionCount_>3) {
		int local_39;
		int local_40;
		CHost * local_41;
		local_39=-1;
		local_40=0x0FFFFFFF;
		for (local_00=1; local_00<600; local_00++) {
			local_41=m_hostArray+local_00;
			if ((!local_41->m_flgIsValid
			  ||local_41->m_flgIsBBSNode_8
			  ||!local_41->m_flgIsConnected
			  ||local_41->m_flgIsTransferLink_8
			  ||local_41->GetflgIsDownConnection()
			  ||!local_41->m_field_8D)||(!(local_41->m_int_unk10-(unsigned int)local_41->m_flgIsPortZero_9==0)?100:local_40>0)==0) continue;
			local_40=local_41->m_int_unk10;
			local_39=local_00;
		}
		if (local_39>=0) {
			m_hostArray[local_39].mf_CHost_0190(true);
			m_int_CurrentSearchUpConnectionCount_=m_int_CurrentSearchUpConnectionCount_-1;
		}
	}
	if (m_int_CurrentBBSUpConnectionCount_>local_24) {
		int local_42;
		int local_43;
		CHost * local_44;
		local_42=-1;
		local_43=0x0FFFFFFF;
		for (local_00=1; local_00<600; local_00++) {
			local_44=m_hostArray+local_00;
			if (!local_44->m_flgIsValid
			  ||!local_44->m_flgIsBBSNode_8
			  ||!local_44->m_flgIsConnected
			  ||local_44->m_flgIsTransferLink_8
			  ||local_44->GetflgIsDownConnection()
			  ||!local_44->m_field_8D||local_44->m_int_unk10>=local_43) continue;
			local_43=local_44->m_int_unk10;
			local_42=local_00;
		}
		if (local_42>=0) {
			m_hostArray[local_42].mf_CHost_0190(true);
			m_int_CurrentBBSUpConnectionCount_=m_int_CurrentBBSUpConnectionCount_-1;
		}
	}

	bool local_45;
	int local_46;
	int local_47;
	double local_48;
	CHost * local_49;
	double local_50;
	char local_51;
	int local_52;
	double local_53;
	CHost * local_54;
	double local_55;
	double local_56;
	char local_57;

	local_45=true;
	for (local_46=0; local_46<10; local_46++) {
		if (! (!(m_int_CurrentTransferUpToPortzeroConnectionCount_>3)&&m_int_related_maxconnection__+1>=m_int_CurrentTransferUpConnectionCount_) ) {
			local_47=-1;
			local_48=1e+030;
			for (local_00=1; local_00<600; local_00++) {
				local_49=m_hostArray+local_00;
				if (!local_49->m_flgIsValid||!local_49->m_flgIsConnected||!local_49->m_flgIsTransferLink_8||!local_49->m_flgIsPortZero_9||!local_49->m_flg_isDownConnection||!local_49->m_field_8D||local_49->m_flgIsBBSNode_8||local_49->m_flg_IsBBSPort) continue;
				local_50=(double)local_49->m_int_connectionTimeInSec;
				if (local_50>=local_48) continue;
				local_48=local_50;
				local_47=local_00;
			}
			if (local_47>=0) {
				local_51=' ';
				mf_CMainControl_0370(local_47,&local_51,1);
				m_hostArray[local_47].mf_CHost_0190(true);
				m_int_CurrentTransferUpToPortzeroConnectionCount_=m_int_CurrentTransferUpToPortzeroConnectionCount_-1;
				m_int_CurrentTransferUpConnectionCount_=m_int_CurrentTransferUpConnectionCount_-1;
				local_45=false;
			}
		}
		if (m_int_related_maxconnection__+1<m_int_CurrentTransferUpConnectionCount_) {
			local_52=-1;
			local_53=1e+030;
			for (local_00=1; local_00<600; local_00++) {
				local_54=m_hostArray+local_00;
				if (!local_54->m_flgIsValid||!local_54->m_flgIsConnected||!local_54->m_flgIsTransferLink_8||!local_54->m_flg_isDownConnection||!local_54->m_field_8D||local_54->m_flgIsBBSNode_8||local_54->m_flg_IsBBSPort) continue;
				if (local_54->m_int_lineSpeed<m_int_linespeed_) {
					local_55=(double)local_54->m_int_connectionTimeInSec*450.0;
					if (local_55>=local_53) continue;
					local_53=local_55;
					local_52=local_00;
					continue;
				}
				local_56=(double)local_54->m_int_connectionTimeInSec*500.0;
				if (local_56>=local_53) continue;
				local_53=local_56;
				local_52=local_00;
			}
			if (local_52>=0) {
				local_57=' ';
				mf_CMainControl_0370(local_52,&local_57,1);
				m_hostArray[local_52].mf_CHost_0190(true);
				m_int_CurrentTransferUpConnectionCount_=m_int_CurrentTransferUpConnectionCount_-1;
				local_45=false;
			}
		}
		if (local_45) break;
	}
	return;
}


void CMainControl::mf_CMainControl_1150()
{
	int local_00;
	int local_01;
	CHost * local_02;
	char local_08[40];
	local_00=0;
	for (local_01=1; local_01<600; local_01++) {
		local_02=m_hostArray+local_01;
		if (!local_02->m_flgIsValid||!local_02->m_flgIsPortZero_9||!local_02->m_flgIsConnected||local_02->m_flgIsTransferLink_8) continue;
		*((int *)(local_08+local_00*4))=local_01;
		local_00=local_00+1;
		if (local_00>=10) break;
	}
	multimap<unsigned int,CKey>::iterator local_03;
	for (local_03=m_KeyBuffer_.begin(); local_03!=m_KeyBuffer_.end(); local_03++) {
		CKey * local_04=&local_03->second;
		if (local_04->m_int_unk0x==0||local_04->m_int_refcountOfFileptr_!=0||!local_04->m_bln_unk311) continue;
		if (local_04->m_char_keyType_>=KEYTYPE02) {
			local_04->m_bln_unk311=false;
			continue;
		}
		_in_addr local_05;
		int local_06;
		CHost * local_07;
		ny_addrcrypter(&local_05,local_04->m_ipaddr_0__);
		for (local_06=0; local_06<local_00; local_06++) {
			if (*((int *)(local_08+local_06*4))<1||*((int *)(local_08+local_06*4))>=600) continue;
			local_07=m_hostArray+*((int *)(local_08+local_06*4));
			if (!(local_07->m_port1!=local_04->m_portno_0__)&&local_07->IsInternalIpaddr(local_05)) break;
		}
		if (local_06!=local_00) continue;
		mf_CMainControl_0730(local_04);
		local_04->m_bln_unk311=false;
	}
	return;
}


void CMainControl::mf_CMainControl_1160()
{
	_in_addr local_00;
	ny_addrset(&local_00,127,94,94,95);
	multimap<unsigned int,CKey>::iterator local_01;
	for (local_01=m_KeyBuffer_.begin(); local_01!=m_KeyBuffer_.end(); local_01++) {
		CKey * local_02=&local_01->second;
		if (local_02->m_int_unk0x==0) continue;
		memcpy(&local_02->m_ipaddr_2__,&local_00,4);
		local_02->m_portno_2__=0;
	}
	return;
}


void CMainControl::mf_CMainControl_1170()
{
	unsigned int local_00;
	for (local_00=0; m_IgnoreCondition_.size()>local_00; local_00++) {
	CAutoDownList * local_01;
		local_01=&m_IgnoreCondition_[local_00];
		if (!local_01->m_flg_unk0||!local_01->mf_CAutoDownList_0010()||!local_01->m_flag_unk8) continue;
		CKey * local_02=mf_CMainControl_0180(0,local_01->m_hash);
		if (local_02==0) continue;
		local_02->m_bln_unk313=true;
	}
	return;
}


Bb CMainControl::mf_CMainControl_1180(CKey * arg_0)
{
	_in_addr local_00;
	if (arg_0->m_int_unk0x==0) {
		return false;
	}
	if (arg_0->m_char_keyType_>=KEYTYPE02) {
		return true;
	}
	ny_addrcrypter(&local_00,arg_0->m_ipaddr_0__);
	if (! (!arg_0->m_bln_unk308||arg_0->m_portno_0__!=m_port_accept_||!(m_hostArray[0].IsInternalIpaddr(local_00))) ) {
		ny_addrcrypter(&local_00,arg_0->m_ipaddr_1__);
		return (bool)(arg_0->m_portno_1__!=m_port_accept_||!(m_hostArray[0].IsInternalIpaddr(local_00)));
	}
	return (bool)(!(!(arg_0->m_portno_0__!=m_port_accept_)&&m_hostArray[0].IsInternalIpaddr(local_00))&&(arg_0->m_bln_unk308||arg_0->m_int_unk200>1));
}


Bb CMainControl::mf_CMainControl_1190(CKey * arg_0)
{
	_in_addr local_00;
	if (! (!(arg_0->m_int_unk0x==0)&&arg_0->m_bln_unk308) ) {
		return false;
	}
	if (arg_0->m_char_keyType_==KEYTYPE02) {
		return true;
	}
	ny_addrcrypter(&local_00,arg_0->m_ipaddr_1__);
	return (bool)(!(arg_0->m_portno_1__==0)&&(m_port_accept_!=arg_0->m_portno_1__||!(m_hostArray[0].IsInternalIpaddr_x2b(local_00))));
}



void CMainControl::mf_CMainControl_1200()
{
	m_double_currentCacheSize_=0.0;
	m_int_numberOfCacheFile_=0;
	multimap<unsigned int,CKey>::iterator local_00;
	for (local_00=m_KeyBuffer_.begin(); local_00!=m_KeyBuffer_.end(); local_00++) {
		CKey * local_01=&local_00->second;
		unsigned int local_02;
		if (local_01->m_int_unk0x==0||!(local_01->m_char_keyType_==KEYTYPE03)&&local_01->m_char_keyType_!=KEYTYPE01) continue;
		m_int_numberOfCacheFile_=m_int_numberOfCacheFile_+1;
		local_02=local_01->mf_CKey_0160();
		if (local_01->m_char_keyType_==KEYTYPE01) {
			local_02=local_02+100;
		}
		if (local_01->mf_CKey_0170()<local_02) {
			local_02=local_01->mf_CKey_0170();
		}
		m_double_currentCacheSize_+=((double)(local_02+1)*65552.0)*(float)0.0009765625;
	}
	unsigned __int64 local_03;
	unsigned __int64 local_04;
	unsigned __int64 local_05;
	m_double_currentCacheSize_*=(float)0.0009765625;
	::GetDiskFreeSpaceEx(m_sz_CacheFolderPath_,(PULARGE_INTEGER)&local_03,(PULARGE_INTEGER)&local_04,(PULARGE_INTEGER)&local_05);
	m_uint_cacheDriveFreeMByte_=(((unsigned int *)&local_03)[1]<<12)+(((unsigned int *)&local_03)[0]>>20);
	m_flag_cacheFolderDiskFull_=m_uint_cacheDriveFreeMByte_<256;
	::GetDiskFreeSpaceEx(m_sz_DownFolderPath_,(PULARGE_INTEGER)&local_03,(PULARGE_INTEGER)&local_04,(PULARGE_INTEGER)&local_05);
	m_uint_downDriveFreeMByte_=(((unsigned int *)&local_03)[1]<<12)+(((unsigned int *)&local_03)[0]>>20);
	m_flag_downFolderDiskFull_=(bool)(m_uint_downDriveFreeMByte_<256);
	return;
}



void CMainControl::mf_CMainControl_1210(const char * arg_0,bool arg_1)
{
	FILE * local_01;
	char local_08[1024];
	char local_09[1024];

	local_01=fopen(arg_0,"r");
	if (local_01==0) {
		sprintf(local_08,"初期ノードファイル読み込み失敗(%s)",arg_0);
		ny_addlog(local_08);
		m_flgarray_unk[7]=true;
		return;
	}
	CKey local_00;
	local_00.mf_CKey_0060();
	local_00.m_int_unk203=1;
	for (int local_02=0; local_02<100; local_02++) {
		if (feof(local_01)||fgets(local_08,1024,local_01)==0) break;
		if (strlen(local_08)<3) continue;
		int local_03=strlen(local_08);
		if (local_03<4) continue;
		if ((int)local_08[local_03-1]==10) {
			local_08[local_03-1]=0;
		}
		local_03=strlen(local_08);
		if ((int)local_08[local_03-1]==13) {
			local_08[local_03-1]=0;
		}
		if ((int)local_08[local_03-1]==32) {
			local_08[local_03-1]=0;
		}
		if ((int)local_08[0]==64) {
			local_00.mf_CKey_0070(local_08,strlen(local_08),false);
			local_00.mf_CKey_0270("opiewf6ascxlv",local_09);
			if ((int)local_09[0]==64) continue;
			strcpy(local_08,local_09);
		}
		_in_addr local_04;
		int local_05;
		char * local_06;
		local_04.b1=0;
		local_04.b2=0;
		local_04.b3=0;
		local_04.b4=0;
		local_05=0;
		local_06=strchr(local_08,58);
		if (local_06==0) continue;
		local_05=callatol(local_06+1);
		if (local_05==0) continue;
		*local_06=0;
		int local_07;
		local_07=mf_CMainControl_0560(&local_04,local_05);
		m_hostArray[local_07].SetPort(local_05);
		m_hostArray[local_07].mf_CHost_0230(local_08);
		m_hostArray[local_07].m_flg_isDownConnection=false;
		m_hostArray[local_07].mf_CHost_0200();
		m_hostArray[local_07].SetflgIsBBSNode(arg_1);
	}
	fclose(local_01);
	return;
}


void CMainControl::mf_CMainControl_1220(const char * arg_0,bool arg_1,bool arg_2)
{
	int local_01;
	int local_02;
	int local_03;
	CHost * local_04;
	FILE * local_05;
	unsigned int local_06;
	char local_10[1024];
	local_01=600;
	local_03=0;
	for (local_02=1; local_02<local_01; local_02++) {
		local_04=m_hostArray+local_02;
		if (!local_04->m_flgIsValid||local_04->m_flg_IsBBSPort||local_04->m_flgIsBBSNode_8!=arg_1) continue;
		local_03=local_03+1;
	}
	if (local_03==0) {
		return;
	}
	local_05=fopen(arg_0,"wt");
	if (local_05==0) {
		sprintf(local_10,"ノードファイル出力失敗(%s)",arg_0);
		ny_addlog(local_10);
		m_flgarray_unk[7]=true;
		return;
	}
	CKey local_00;
	local_00.mf_CKey_0060();
	local_00.m_int_unk203=1;
	local_03=0;
	for (local_06=0; m_vectorCHostSorter_.size()>local_06; local_06++) {
		int local_07=m_vectorCHostSorter_[local_06].m_int_unk00;
		if (local_07<0) continue;
		CHost * local_08;
		local_08=m_hostArray+local_07;
		if (!local_08->m_flgIsValid||local_08->m_flg_IsBBSPort||local_08->m_int_preference2_negative>50||local_08->m_flgIsBBSNode_8!=arg_1) continue;
		if (local_08->m_str_DDNSname.Length()==0) {
			_in_addr * local_09;
			local_09=&local_08->m_ipaddr3;
			sprintf(local_10,"%d.%d.%d.%d:%d",(unsigned int)local_09->b1,(unsigned int)local_09->b2,(unsigned int)local_09->b3,(unsigned int)local_09->b4,local_08->m_port1);
		} else {
			sprintf(local_10,"%s:%d",/*(const char *)*/local_08->m_str_DDNSname,local_08->m_port1);
		}
		if (arg_2) {
			local_00.mf_CKey_0070(local_10,strlen(local_10),false);
			local_00.mf_CKey_0270("opiewf6ascxlv",local_10);
		}
		strcat(local_10,"\n");
		fputs(local_10,local_05);
		local_03=local_03+1;
		if (local_03>100) break;
	}
	fclose(local_05);
	return;
}



void CMainControl::mf_CMainControl_1230(AnsiString arg_0,bool arg_1)
{
	FILE * local_00;
	char local_01[1024];
	if (g_AppPath.Length()==0) {
		return;
	}
	if (arg_1) {
		sprintf(local_01,"%s%s",/*(const char *)*/g_AppPath,"BbsNoderef.txt");
	} else {
		sprintf(local_01,"%s%s",/*(const char *)*/g_AppPath,"Noderef.txt");
	}
	local_00=fopen(local_01,"at");
	if (local_00==0) {
		sprintf(local_01,"ノードファイル出力失敗(%s)","Noderef.txt");
		ny_addlog(local_01);
		m_flgarray_unk[7]=true;
		return;
	}
	fprintf(local_00,"%s\n",arg_0.c_str());
	fclose(local_00);
	sprintf(local_01,"%s%s",/*(const char *)*/g_AppPath,"Noderef.txt");
	mf_CMainControl_1210(local_01,false);
	sprintf(local_01,"%s%s",/*(const char *)*/g_AppPath,"BbsNoderef.txt");
	mf_CMainControl_1210(local_01,true);
	return;
}


Bb CMainControl::mf_CMainControl_1240(_in_addr * arg_0,int arg_1)
{
	int local_00;
	int local_01;
	local_00=0;
	local_01=m_vectorpCWork_.size();
	for (int local_02=0; local_02<local_01; local_02++) {
		if (/**/(*GetWorkNP(local_02))->GetWorkType()!=WORKTYPE01||/**/(*GetWorkNP(local_02))->IsFinished()) continue;
		int local_03=/**/(*GetWorkNP(local_02))->GetHostIdx();
		if (local_03<0||!m_hostArray[local_03].m_flgIsValid||m_hostArray[local_03].m_port1!=arg_1||!(m_hostArray[local_03].IsInternalIpaddr_x2b(*arg_0))) continue;
		local_00=local_00+1;
		if (local_00>=10) break;
	}
	return (bool)(!(local_00<=0)&&local_00<10);
}


Bb CMainControl::mf_CMainControl_1250(unsigned char * arg_0,unsigned int arg_1)
{
	int local_00;
	local_00=m_vectorpCWork_.size();
	for (int local_01=0; local_01<local_00; local_01++) {
		if (/**/(*GetWorkNP(local_01))->GetWorkType()!=WORKTYPE01
		  ||/**/(*GetWorkNP(local_01))->IsFinished()) continue;
		unsigned char * local_02=/**/(*GetWorkNP(local_01))->Get_uchar16_unk1();
		int tmp=(*GetWorkNP(local_01))->GetCountMax();
		if (/**/tmp!=arg_1||memcmp(local_02,arg_0,16)!=0) continue;
		return true;
	}
	return false;
}



void CMainControl::mf_CMainControl_0060(const char * arg_0,unsigned int arg_1,unsigned char * arg_2,char * arg_3,double arg_4,double arg_5,bool arg_6,bool arg_7,bool arg_8,bool arg_9,bool arg_10)
{
	char local_12[1024];
	try {
		if (! (strlen(arg_0)>=2||arg_2!=0) ) {
			return;
		}
		if (strchr(arg_3,44)!=0) {
			return;
		}
		char * local_01=local_12;
		const char * local_02=arg_0;
		while (*local_02!=0) {
			if ((int)*local_02==44) {
				*local_01=' ';
				local_01=local_01+1;
				local_02=local_02+1;
			} else {
				*local_01=*local_02;
				local_02=local_02+1;
				local_01=local_01+1;
			}
		}
		*local_01=0;
		int 		local_03=m_DownCondition_.size();
		int 		local_04=0;
		if (arg_2!=0) {
			for (local_04=0; local_04<local_03; local_04++) {
				if (! (!m_DownCondition_[local_04].IsValid()||memcmp(m_DownCondition_[local_04].m_hash,arg_2,16)!=0) ) {
					return;
				}
			}
		}
		for (local_04=0; local_04<local_03; local_04++) {
			if (!m_DownCondition_[local_04].IsValid()) break;
		}
		if (local_04==local_03) {
			CAutoDownList local_00;
			m_DownCondition_.push_back(local_00);
		}
		m_DownCondition_[local_04].mf_CAutoDownList_0000();
		if (arg_2!=0) {
			GetDownCondition(local_04)->Set_hash(arg_2);
		}
		GetDownCondition(local_04)->Set_keyword(local_12);
		GetDownCondition(local_04)->Set_Tripstr(arg_3);
		GetDownCondition(local_04)->Set_double_unk9(arg_4);
		GetDownCondition(local_04)->Set_double_unk10(arg_5);
		GetDownCondition(local_04)->Set_flag_Bbs(arg_6);
		GetDownCondition(local_04)->Set_flag_AutoDelete(arg_7);
		GetDownCondition(local_04)->Set_flag_Disconnect(arg_9);
		GetDownCondition(local_04)->Set_flag_Delete(arg_8);
		if (!arg_10) {
			if (g_AppPath.Length()!=0) {
				sprintf(local_12,"%s%s",/*(const char *)*/g_AppPath,"Download.txt");
				mf_CMainControl_0110(local_12);
			}
			if (! (arg_2==0||arg_1<=0) ) {
				CKey * local_08=this->mf_CMainControl_0180(arg_1,(unsigned char *)arg_2);
				int local_09;
				if (! (local_08==0||local_08->m_int_refcountOfFileptr_!=0) ) {
					local_09=local_08->m_int_unk14;
					if (! (local_09>=10||!local_08->m_bln_unk308&&m_int_CurrentTransferDownConnectionCount_>=m_int_currentTransferUpConnectionMax_+2) ) {
						int tmp10=local_09+1;
						local_08->m_int_unk14=tmp10;

						bool local_10;
						int local_11;
						mf_CMainControl_0880(arg_1,arg_2,-1,0,&local_10,&local_11,NULLPO);
						GetDownCondition(local_04)->Set_int_unk4(local_11);
					} else {
						int tmp11=local_09-1;
						local_08->m_int_unk14=tmp11;
					}
				}
			}
		}
	}
	catch (std::bad_alloc ex_8) {
	}
	return;
}





void CMainControl::mf_CMainControl_0070(const char * arg_0,char * arg_1,unsigned char * arg_2,unsigned char * arg_3,double arg_4,double arg_5,bool arg_6,bool arg_7,bool arg_8,bool arg_9)
{
	char local_08[1024];
	try {
		if (! ((strlen(arg_0)>=2)||arg_2!=0) ) {
			return;
		}
		if (strchr((const char *)arg_3,44)!=0) {
			return;
		}
		char *		local_01=local_08;
		const char *		local_02=arg_0;
		while (*local_02!=0) {
			if ((int)(*local_02)==44) {
				*local_01=' ';
				local_01=local_01+1;
				local_02++;
			} else {
				*local_01=*local_02;
				local_02++;
				local_01=local_01+1;
			}
		}
		*local_01=0;
		int		local_03=m_IgnoreCondition_.size();
		int		local_04=0;
		if (arg_2!=0) {
			for (local_04=0; local_04<local_03; local_04++) {
				if (! (!m_IgnoreCondition_[local_04].IsValid()||memcmp(m_IgnoreCondition_[local_04].m_hash,arg_2,16)!=0) ) return;
			}
		}
		for (local_04=0; local_04<local_03; local_04++) {
			if (!m_IgnoreCondition_[local_04].IsValid()) break;
		}
		if (local_04==local_03) {
			CAutoDownList local_00;
			m_IgnoreCondition_.push_back(local_00);
		}
		m_IgnoreCondition_[local_04].mf_CAutoDownList_0000();
		if (arg_2!=0) {
			GetIgnoreCondition(local_04)->Set_hash(arg_2);

		}
		GetIgnoreCondition(local_04)->Set_keyword(local_08);
		GetIgnoreCondition(local_04)->Set_Tripstr(arg_3);
		GetIgnoreCondition(local_04)->Set_double_unk9(arg_4);
		GetIgnoreCondition(local_04)->Set_double_unk10(arg_5);
		GetIgnoreCondition(local_04)->Set_flag_Bbs(arg_6);
		GetIgnoreCondition(local_04)->Set_flag_AutoDelete(arg_7);
		GetIgnoreCondition(local_04)->Set_flag_Disconnect(arg_9);
		GetIgnoreCondition(local_04)->Set_flag_Delete(arg_8);

		if (g_AppPath.Length()!=0) {
			sprintf(local_08,"%s%s",/*(const char *)*/g_AppPath,"Ignore.txt");
			mf_CMainControl_0120(local_08);
		}
	}
	catch (std::bad_alloc ex_8) {
	}
	return;
}


void CMainControl::mf_CMainControl_0080(xint arg_0,int arg_1)
{
	unsigned char local_02[16];
	char local_03[1024];
	if (arg_1>=0) {
		ny_aschash2binhash(g_listitemarray[arg_0][arg_1][9],local_02);
		int local_00=m_DownCondition_.size();
		int local_01=0;
		for (local_01=0; local_01<local_00; local_01++) {
			if (! (!m_DownCondition_[local_01].IsValid()/*m_flg_unk0*/||memcmp(m_DownCondition_[local_01].m_hash,local_02,16)!=0) ) { //continue;
				int tmp=local_01;
				m_DownCondition_.begin()[tmp].m_flg_unk0=false;
				break;
			}
		}
		if (g_AppPath.Length()!=0) {
#ifdef EXACTMATCH
			//文字列定数で変なのがあるので、入れちゃう
			sprintf(local_03,"%s%s",/*(const char *)*/g_AppPath,"Download.txt\x00%s%s\x00Ignore.txt");
#else
			sprintf(local_03,"%s%s",/*(const char *)*/g_AppPath,"Download.txt");
#endif
			mf_CMainControl_0110(local_03);
		}
	}
	return;
}



void CMainControl::mf_CMainControl_0090(const char * arg_0,bool arg_1)
{
	FILE * local_02;
	char local_16[4096];
	char local_17[1024];
	char local_18[1024];
	unsigned char local_19[16];

	local_02=fopen(arg_0,"r");
	try {
		if (local_02==0) {
			if (arg_1) {
				sprintf(local_16,"ダウンロードリスト読み込み失敗(%s)",arg_0);
				ny_addlog(local_16);
				m_flgarray_unk[7]=true;
			}
			return;
		}
		m_DownCondition_.resize(0);
		int		local_03=0;
		while (true) {
			if (feof(local_02)||fgets(local_16,4096,local_02)==0) break;
			if (strlen(local_16)<1) continue;
			int			local_04=strlen(local_16)-1;
			if ((int)*(local_16+local_04)==10) {
				*(local_16+local_04)=0;
			}
			local_04=strlen(local_16);
			if ((int)*(local_16+local_04)==13) {
				*(local_16+local_04)=0;
			}
			local_17[0]=0;
			local_18[0]=0;
			CAutoDownList local_01;
			local_01.mf_CAutoDownList_0000();
			char *			local_05=local_16;
			char *			local_06=local_16;
			for ( ; !(*local_05==0)&&(int)*local_05!=44; local_05++) {
			}
			char *			local_07=local_05;
			if (*local_05!=0) {
				*local_05=0;
				local_07=local_07+1;
				local_05=local_05+1;
			}
			while (!(*local_05==0)&&(int)*local_05!=44) {
				local_05=local_05+1;
			}
			char *			local_08=local_05;
			if (*local_05!=0) {
				*local_05=0;
				local_08=local_08+1;
				local_05=local_05+1;
			}
			while (!(*local_05==0)&&(int)*local_05!=44) {
				local_05=local_05+1;
			}
			char *			local_09=local_05;
			if (*local_05!=0) {
				*local_05=0;
				local_09=local_09+1;
				local_05=local_05+1;
			}
			while (!(*local_05==0)&&(int)*local_05!=44) {
				local_05=local_05+1;
			}
			char *			local_10=local_05;
			if (*local_05!=0) {
				*local_05=0;
				local_10=local_10+1;
				local_05=local_05+1;
			}
			while (!(*local_05==0)&&(int)*local_05!=44) {
				local_05=local_05+1;
			}
			char *			local_11=local_05;
			if (*local_05!=0) {
				*local_05=0;
				local_11=local_11+1;
				local_05=local_05+1;
			}
			while (!(*local_05==0)&&(int)*local_05!=44) {
				local_05=local_05+1;
			}
			char *			local_12=local_05;
			if (*local_05!=0) {
				*local_05=0;
				local_12=local_12+1;
				local_05=local_05+1;
			}
			while (!(*local_05==0)&&(int)*local_05!=44) {
				local_05=local_05+1;
			}
			char *			local_13=local_05;
			if (*local_05!=0) {
				*local_05=0;
				local_13=local_13+1;
				local_05=local_05+1;
			}
			if (strlen(local_06)>250) {
				continue;
			}
			if (local_12==local_13) {
				if (! (local_11==0||callatol(local_11)<=0) ) {
					local_01.m_flag_unk6=true;
				}
			} else {
				if (! (local_11==0||callatol(local_11)<=0) ) {
					local_01.m_flag_unk7=true;
				}
				if (! (local_12==0||callatol(local_12)<=0) ) {
					local_01.m_flag_unk8=true;
				}
				if (! (local_13==0||callatol(local_13)<=0) ) {
					local_01.m_flag_unk6=true;
				}
				if (! (arg_1||!local_01.m_flag_unk7&&!local_01.m_flag_unk8) ) {
					continue;
				}
			}
			if (local_06!=0) {
                                const char *tmp10=local_06;
				strcpy(local_01.m_char256_unk1,tmp10/*local_06*/);
				local_01.m_flg_unk0=true;
			}
			if (local_07!=0) {
				if (strcmp(local_07,"BBS")==0) {
					local_01.m_flag_unk5=true;
				} else {
                                        const char *tmp11=local_07;
					strcpy(local_01.m_char256_unk2,tmp11/*local_07*/);
				}
			}
			if (local_08!=0) {
				double				local_14=atof(local_08);
				local_01.m_double_unk10=local_14;
			}
			if (local_09!=0) {
				double				local_15=atof(local_09);
				local_01.m_double_unk9=local_15;
			}
			if (local_10!=0) {
				int tmp12=strlen(local_10); //本来はなんかのstructなのか？
				if (tmp12>=32) {
					ny_aschash2binhash(local_10,local_19);
					if (local_19!=0) {
						memcpy(local_01.m_hash,local_19,16);
					} else {
						memset(local_01.m_hash,0,16);
					}
					local_01.m_flg_unk0=true;
				}
			}
			m_DownCondition_.push_back(local_01);
			local_03=local_03+1;
		}
		fclose(local_02);
		m_flgarray_unk[4]=true;
		m_flgarray_unk[5]=true;
	}
	catch (std::bad_alloc ex_8) {
		if (local_02!=0) {
			fclose(local_02);
		}
	}
	return;
}



void CMainControl::mf_CMainControl_0100(const char * arg_0,bool arg_1)
{
	FILE * local_02;
	char local_16[1024];
	char local_17[1024];
	char local_18[1024];
	unsigned char local_19[16];
	local_02=fopen(arg_0,"r");
	try {
		if (local_02==0) {
			if (arg_1) {
				sprintf(local_16,"無視リスト読み込み失敗(%s)",arg_0);
				ny_addlog(local_16);
				m_flgarray_unk[7]=true;
			}
			return;
		}
		m_IgnoreCondition_.resize(0);
		int		local_03=0;
		while (true) {
			if (feof(local_02)||fgets(local_16,1024,local_02)==0) break;
			if (strlen(local_16)<1) continue;
			int			local_04=strlen(local_16)-1;
			if ((int)*(local_16+local_04)==10) {
				*(local_16+local_04)=0;
			}
			local_04=strlen(local_16);
			if ((int)*(local_16+local_04)==13) {
				*(local_16+local_04)=0;
			}
			local_17[0]=0;
			local_18[0]=0;
			CAutoDownList local_01;
			local_01.mf_CAutoDownList_0000();
			char *			local_05=local_16;
			char *			local_06=local_16;
			for ( ; !(*local_05==0)&&(int)*local_05!=44; local_05++) {
			}
			char *			local_07=local_05;
			if (*local_05!=0) {
				*local_05=0;
				local_07=local_07+1;
				local_05=local_05+1;
			}
			while (!(*local_05==0)&&(int)*local_05!=44) {
				local_05=local_05+1;
			}
			char *			local_08=local_05;
			if (*local_05!=0) {
				*local_05=0;
				local_08=local_08+1;
				local_05=local_05+1;
			}
			while (!(*local_05==0)&&(int)*local_05!=44) {
				local_05=local_05+1;
			}
			char *			local_09=local_05;
			if (*local_05!=0) {
				*local_05=0;
				local_09=local_09+1;
				local_05=local_05+1;
			}
			while (!(*local_05==0)&&(int)*local_05!=44) {
				local_05=local_05+1;
			}
			char *			local_10=local_05;
			if (*local_05!=0) {
				*local_05=0;
				local_10=local_10+1;
				local_05=local_05+1;
			}
			while (!(*local_05==0)&&(int)*local_05!=44) {
				local_05=local_05+1;
			}
			char *			local_11=local_05;
			if (*local_05!=0) {
				*local_05=0;
				local_11=local_11+1;
				local_05=local_05+1;
			}
			while (!(*local_05==0)&&(int)*local_05!=44) {
				local_05=local_05+1;
			}
			char *			local_12=local_05;
			if (*local_05!=0) {
				*local_05=0;
				local_12=local_12+1;
				local_05=local_05+1;
			}
			while (!(*local_05==0)&&(int)*local_05!=44) {
				local_05=local_05+1;
			}
			char *			local_13=local_05;
			if (*local_05!=0) {
				*local_05=0;
				local_13=local_13+1;
				local_05=local_05+1;
			}
			if (local_12==local_13) {
				if (! (local_11==0||callatol(local_11)<=0) ) {
					local_01.m_flag_unk6=true;
				}
				local_01.m_flag_unk7=true;
				local_01.m_flag_unk8=true;
			} else {
				if (!arg_1) {
					if (! (local_11==0||callatol(local_11)<=0) ) {
						local_01.m_flag_unk7=true;
					}
					if (! (local_12==0||callatol(local_12)<=0) ) {
						local_01.m_flag_unk8=true;
					}
					if (! (local_13==0||callatol(local_13)<=0) ) {
						local_01.m_flag_unk6=true;
					}
					if (! (local_01.m_flag_unk7||local_01.m_flag_unk8) ) {
						continue;
					}
					if (local_01.m_flag_unk7) {
						if (local_01.m_flag_unk8) {
							local_01.m_flag_unk7=true;
							local_01.m_flag_unk8=true;
						} else {
							local_01.m_flag_unk7=true;
							local_01.m_flag_unk8=false;
						}
					} else {
						local_01.m_flag_unk7=false;
						local_01.m_flag_unk8=false;
					}
				} else {
					if (! (local_11==0||callatol(local_11)<=0) ) {
						local_01.m_flag_unk6=true;
					}
					if (! (local_12==0||callatol(local_12)<=0) ) {
						local_01.m_flag_unk7=true;
					}
					if (! (local_13==0||callatol(local_13)<=0) ) {
						local_01.m_flag_unk8=true;
					}
				}
			}
			if (local_06!=0) {
                                const char *tmp10=local_06;
				strcpy(local_01.m_char256_unk1,tmp10/*local_06*/);
				local_01.m_flg_unk0=true;
			}
			if (local_07!=0) {
				if (strcmp(local_07,"BBS")==0) {
					local_01.m_flag_unk5=true;
				} else {
                                        const char *tmp11=local_07;
					strcpy(local_01.m_char256_unk2,tmp11/*local_07*/);
				}
			}
			if (local_08!=0) {
			double				local_14=atof(local_08);
				local_01.m_double_unk10=local_14;
			}
			if (local_09!=0) {
			double				local_15=atof(local_09);
				local_01.m_double_unk9=local_15;
			}
			if (local_10!=0) {
				int tmp12=strlen(local_10); //本来はなんかのstructなのか？
				if (tmp12>=32) {
					ny_aschash2binhash(local_10,local_19);
					if (local_19!=0) {
						memcpy(local_01.m_hash,local_19,16);
					} else {
						memset(local_01.m_hash,0,16);
					}
					local_01.m_flg_unk0=true;
				}
			}
			m_IgnoreCondition_.push_back(local_01);
			local_03=local_03+1;
		}
		fclose(local_02);
		m_flgarray_unk[4]=true;
		m_flgarray_unk[5]=true;
	}
	catch (std::bad_alloc ex_8) {
		if (local_02!=0) {
			fclose(local_02);
		}
	}
	return;
}


void CMainControl::mf_CMainControl_0110(const char * arg_0)
{
	FILE * local_00;
	char local_05[1024];
	char local_06[1000];
	char local_07[256];
	local_00=fopen(arg_0,"w");
	if (local_00==0) {
		sprintf(local_05,"ダウンロードリスト書き込み失敗(%s)",arg_0);
		ny_addlog(local_05);
		m_flgarray_unk[7]=true;
		return;
	}
	int	local_01=m_DownCondition_.size();
	for (int local_02=0; local_02<local_01; local_02++) {
		if (!m_DownCondition_[local_02].IsValid()) continue;
		local_06[0]=0;
		if (m_DownCondition_[local_02].Get_flag_unk5()) {
			strcpy(local_06,"BBS");
		} else {
			strcpy(local_06,m_DownCondition_[local_02].m_char256_unk2);
		}
		if (m_DownCondition_[local_02].mf_CAutoDownList_0010()) {
			local_07[0]=0;
			char local_03[8];
			for (int local_04=0; local_04<16; local_04++) {
				sprintf(local_03,"%02x",(unsigned int)*(((m_DownCondition_[local_02]).GetHash())+local_04));
				strcat(local_07,local_03);
			}
			local_03[0]=0;
			if (m_DownCondition_[local_02].Get_flag_unk5()) {
				strcpy(local_03,"BBS");
			}
			sprintf(local_05,"%s,%s,%g,%g,%s,%d\n",m_DownCondition_[local_02].m_char256_unk1,local_06,GetDownCondition(local_02)->Get_double_unk10(),GetDownCondition(local_02)->Get_double_unk9(),local_07,GetDownCondition(local_02)->Get_flag_unk6()?1:0);
		} else {
			sprintf(local_05,"%s,%s,%g,%g,,%d\n",m_DownCondition_[local_02].m_char256_unk1,local_06,GetDownCondition(local_02)->Get_double_unk10(),GetDownCondition(local_02)->Get_double_unk9(),GetDownCondition(local_02)->Get_flag_unk6()?1:0);
		}
		fputs(local_05,local_00);
	}
	fclose(local_00);
	return;
}


void CMainControl::mf_CMainControl_0120(const char * arg_0)
{
	FILE * local_00;
	char local_05[1024];
	char local_06[1000];
	char local_07[256];
	local_00=fopen(arg_0,"w");
	if (local_00==0) {
		sprintf(local_05,"無視リスト書き込み失敗(%s)",arg_0);
		ny_addlog(local_05);
		m_flgarray_unk[7]=true;
		return;
	}
	int	local_01=m_IgnoreCondition_.size();
	for (int local_02=0; local_02<local_01; local_02++) {
		if (!m_IgnoreCondition_[local_02].IsValid()) continue;
		local_06[0]=0;
		if (m_IgnoreCondition_[local_02].Get_flag_unk5()) {
			strcpy(local_06,"BBS");
		} else {
			strcpy(local_06,m_IgnoreCondition_[local_02].m_char256_unk2);
		}
		if (m_IgnoreCondition_[local_02].mf_CAutoDownList_0010()) {
			local_07[0]=0;
			char local_03[8];
			for (int local_04=0; local_04<16; local_04++) {
				sprintf(local_03,"%02x",(unsigned int)m_IgnoreCondition_[local_02].GetHash()[local_04]);
				strcat(local_07,local_03);
			}
			local_03[0]=0;
			if (m_IgnoreCondition_[local_02].Get_flag_unk5()) {
				strcpy(local_03,"BBS");
			}
			sprintf(local_05,"%s,%s,%g,%g,%s,%d,%d,%d\n",m_IgnoreCondition_[local_02].m_char256_unk1,local_06,GetIgnoreCondition(local_02)->Get_double_unk10(),GetIgnoreCondition(local_02)->Get_double_unk9(),local_07,GetIgnoreCondition(local_02)->Get_flag_unk6()?1:0,GetIgnoreCondition(local_02)->Get_flag_unk7()?1:0,GetIgnoreCondition(local_02)->Get_flag_unk8()?1:0);
		} else {
			sprintf(local_05,"%s,%s,%g,%g,,%d,%d,%d\n",m_IgnoreCondition_[local_02].m_char256_unk1,local_06,GetIgnoreCondition(local_02)->Get_double_unk10(),GetIgnoreCondition(local_02)->Get_double_unk9(),GetIgnoreCondition(local_02)->Get_flag_unk6()?1:0,GetIgnoreCondition(local_02)->Get_flag_unk7()?1:0,GetIgnoreCondition(local_02)->Get_flag_unk8()?1:0);
		}
		fputs(local_05,local_00);
	}
	fclose(local_00);
	return;
}


CAutoDownList * CMainControl::mf_CMainControl_0130(int arg_0)
{
	return &m_DownCondition_[arg_0];
}


CAutoDownList * CMainControl::mf_CMainControl_0140(int arg_0)
{
	return &m_IgnoreCondition_[arg_0];
}


void CMainControl::mf_CMainControl_0150(int arg_0)
{
	if (! (arg_0<0||m_DownCondition_.size()<=(unsigned int)arg_0) ) {
		m_DownCondition_[arg_0].SetValid(false);
	}
	return;
}


void CMainControl::mf_CMainControl_0160(int arg_0)
{
	if (! (arg_0<0||m_IgnoreCondition_.size()<=(unsigned int)arg_0) ) {
		m_IgnoreCondition_[arg_0].SetValid(false);
	}
	return;
}


void CMainControl::mf_CMainControl_1260()
{
	time_t local_00;
	unsigned int local_01;
	int local_02;
	char local_42[1024];
	char local_43[64];

	if (!m_flg_unk16400) {
		time(&local_00);
		local_02=0;
		if (m_DownCondition_.size()!=0) {
			unsigned	int local_03;
			local_03=0;
			m_hostArray[0].mf_CHost_0020(0,"");
			m_hostArray[0].mf_CHost_0020(1,"");
			m_hostArray[0].mf_CHost_0020(2,"");
			for (local_01=0; m_DownCondition_.size()>local_01; local_01++) {
				if (!GetDownCondition(local_01)->IsValid()||strlen(GetDownCondition(local_01)->m_char256_unk1)<2||GetDownCondition(local_01)->mf_CAutoDownList_0010()) continue;
				m_hostArray[0].mf_CHost_0020(local_03,GetDownCondition(local_01)->m_char256_unk1);
				local_03=local_03+1;
				if (local_03>=3) break;
			}
			int local_04;
			unsigned int local_05;
			local_04=0;
			local_05=(unsigned int)m_vectorpCWork_.size();
			for (local_01=0; local_01<local_05; local_01++) {
				if (/**/(*GetWorkNP(local_01))->GetWorkType()!=WORKTYPE01||/**/(*GetWorkNP(local_01))->IsFinished()) continue;
				local_04=local_04+1;
			}
			int local_06;
			local_06=0;
			for (local_01=0; m_DownCondition_.size()>local_01; local_01++) {
				CAutoDownList * local_07;
				local_07=GetDownCondition(local_01);
				if (!local_07->IsValid()) continue;
				local_06=local_06+1;
				bool local_08;
				int local_09;
				local_08=true;
				local_09=local_07->m_int_unk4;
				if (! (!(local_09<0||(int)m_vectorpCWork_.size()<=local_09||/**/(*GetWorkNP(local_09))->IsFinished())&&/**/(*GetWorkNP(local_09))->GetWorkType()==WORKTYPE01) ) {
					local_08=false;
				}
				CKey * local_10;
				local_10=NULLPO;
				if (local_08) {
					local_10=mf_CMainControl_0180(/**/(*GetWorkNP(local_09))->GetCountMax(),/**/(*GetWorkNP(local_09))->Get_uchar16_unk1());
					if (! (!(local_10==0)&&local_10->m_int_unk0x!=0) ) {
						local_08=false;
					}
				}
				if (local_08) {
					if (local_07->mf_CAutoDownList_0010()) {
						if (memcmp(local_07->m_hash,local_10->m_hash_tabun,16)!=0) {
							local_08=false;
						}
					} else {
						if (! (!(strlen(local_07->m_char256_unk1)<2)&&local_10->mf_CKey_0040(local_07->m_char256_unk1,local_07->m_char256_unk2,true)) ) {
							local_08=false;
						}
					}
				}
				if (local_08) continue;
				if (! (local_10==0||local_10->m_int_unk0x==0) ) {
				int local_11;
					local_11=local_10->m_int_unk14;
					if (local_11>10) {
						local_11=10;
					}
					local_10->Set_int_unk14(local_11+10);
				}
				local_07->m_int_unk4=-1;
			}
			unsigned int local_12;
			for (local_12=0; m_DownCondition_.size()>local_12; local_12++) {
				local_02=g_int_unk416%m_DownCondition_.size();
				g_int_unk416=g_int_unk416+1;
				if (GetDownCondition(local_02)->IsValid()) break;
			}
			if (g_int_unk416>0x000186A0) {
				g_int_unk416=0;
			}
			if (! (m_DownCondition_.size()<=local_02||m_DownCondition_.size()<=local_12) ) {
				m_int_unk18=local_02;
				CAutoDownList * local_13;
				local_13=GetDownCondition(local_02);
				if (local_13->IsValid()) {
					local_13->m_char_unk100_70=0;
					local_13->m_int_unk20=0;
					double local_14;
					double local_15;
					CKey * local_16;
					bool local_17;
					unsigned short local_18;
					local_14=1e+010;
					local_15=1e+010;
					local_16=NULLPO;
					local_13->m__unknown_000=0;
					local_13->m__unknown_001=0;
					strcpy(local_13->m_char256_unk3,"");
					memset(local_13->m_hash_kamo,0,16);
					local_13->m_flg_unk0=true;
					local_17=local_13->mf_CAutoDownList_0010();
					local_18=0;
					local_18=mf_CMainControl_0590(local_13->m_char256_unk1);
					if (local_13->mf_CAutoDownList_0010()) {
						local_18=(short)((unsigned int)local_13->m_hash[0]<<8)+(short)((unsigned int)local_13->m_hash[1]);
					}
					if (! ( (local_13->m_double_unk10>=3999.0 || m_KeySearchTable_.count(local_18)==0) ) ) {
						multimap<unsigned short,unsigned int>::iterator local_19;
						for (local_19=m_KeySearchTable_.find(local_18); local_19!=m_KeySearchTable_.end(); local_19++) {
							if (local_13->m_int_unk20>=100) break;
							unsigned int local_20=local_19->second;
							if (local_19->first!=local_18) break;
							if (m_KeyBuffer_.count(local_20)==0) continue;
							multimap<unsigned int,CKey>::iterator local_21;
							for (local_21=m_KeyBuffer_.find(local_20); local_21!=m_KeyBuffer_.end(); local_21++) {
								CKey * local_22=&local_21->second;
								if (local_22->m_int_unk0x==0) continue;
								if (*((int *)local_22->m_hash_tabun)!=local_20) break;
								local_22->mf_CKey_0050(local_00);
								if ((local_22->m_char_keyType_==KEYTYPE02||local_22->m_bln_unk302)||!(!local_13->m_flag_unk5)&&!local_22->m_bln_unk308||!local_13->m_flag_unk5&&local_22->m_bln_unk308||!(local_22->m_bln_unk308||local_22->m_portno_0__!=local_22->m_portno_2__)&&memcmp(&local_22->m_ipaddr_0__,&local_22->m_ipaddr_2__,4)==0) continue;
								if (m_optflg_V4CacheNotDown_&&local_22->m_int_unk203==4) {
									local_13->m_char_unk100_70=0;
									continue;
								}
								local_22->m_bln_unk303=false;
								local_22->m_bln_unk304=false;
								if (local_17) {
									if (memcmp(local_13->m_hash,local_22->m_hash_tabun,16)!=0) continue;
								} else {
									if (strlen(local_13->m_char256_unk1)<2||!local_22->mf_CKey_0040(local_13->m_char256_unk1,local_13->m_char256_unk2,true)) continue;
								}
								if (!(local_13->m_double_unk9<=0.0)&&(double)local_22->m_uint_unk13*(float)9.5367432e-007>local_13->m_double_unk9||!(local_13->m_double_unk10<=0.0)&&(double)local_22->m_uint_unk13*(float)9.5367432e-007<local_13->m_double_unk10) continue;
								for (local_01=0; m_IgnoreCondition_.size()>local_01; local_01++) {
	CAutoDownList * local_23;
									local_23=&m_IgnoreCondition_[local_01];
									if (!(local_23->m_double_unk9<=0.0)&&(double)local_22->m_uint_unk13*(float)9.5367432e-007>local_23->m_double_unk9||!(local_23->m_double_unk10<=0.0)&&(double)local_22->m_uint_unk13*(float)9.5367432e-007<local_23->m_double_unk10||!(!local_23->m_flag_unk5)&&!local_22->m_bln_unk308||!local_23->m_flag_unk5&&local_22->m_bln_unk308) continue;
									if (local_23->mf_CAutoDownList_0010()) {
										if (memcmp(local_23->m_hash,local_22->m_hash_tabun,16)!=0) continue;
										break;
									}
									if (strlen(local_23->m_char256_unk1)<2) continue;
									if (!local_22->mf_CKey_0040(local_23->m_char256_unk1,local_23->m_char256_unk2,true)) continue;
									break;
								}
								if (m_IgnoreCondition_.size()!=local_01) continue;
								if (local_22->m_char_keyType_==KEYTYPE03) {
									if (! (!local_22->m_bln_unk312&&!local_13->m_flag_unk5||(!local_13->m_flag_unk6||local_13->m_flag_unk5!=local_22->m_bln_unk308)) ) {
										local_22->m_bln_unk312=false;
										local_13->m_flg_unk0=false;
										if (g_AppPath.Length()!=0) {
											sprintf(local_42,"%s%s",/*(const char *)*/g_AppPath,"Download.txt");
											mf_CMainControl_0110(local_42);
										}
										return;
									}
									if (! (!local_13->m_flag_unk6||!local_13->mf_CAutoDownList_0010()||local_22->m_bln_unk305||local_22->m_bln_unk312) ) {
										mf_CMainControl_0980(local_22->m_uint_unk13,local_22->m_hash_tabun,false);
									}
									continue;
								}
								if (!m_optflg_useMultiDownload_&&local_22->m_int_refcountOfFileptr_!=0) continue;
								if (mf_CMainControl_1180(local_22)) {

									if (!m_unknown_000_70&&local_22->m_bln_unk313) {
										local_13->Set_unk3(local_22->mf_CKey_0260());
										unsigned char *local_001=local_22->m_hash_tabun;
										if (local_001!=0) {
											memcpy(local_13->m_hash_kamo,local_001,16);
										} else {
											memset(local_13->m_hash_kamo,0,16);
										}
										local_13->m_flg_unk0=true;
										local_13->m_char_unk100_70=1;
										continue;
									}

									double local_24;
									_in_addr local_25;
									local_24=local_22->m_float_unk15*0.1;
									if ((double)local_22->m_int_unk14-local_24<local_14) {
										if (!local_22->m_bln_unk308) {
											ny_addrcrypter(&local_25,local_22->m_ipaddr_0__);
											unsigned int local_26;
											for (local_26=0; m_vectorpCWork_.size()>local_26; local_26++) {
												if (/**/(*GetWorkNP(local_26))->GetWorkType()!=WORKTYPE01||/**/(*GetWorkNP(local_26))->IsFinished()) continue;
												int local_27;
												local_27=/**/(*GetWorkNP(local_26))->GetHostIdx();
												if (local_27<0) continue;
												CHost * local_28;
												local_28=m_hostArray+local_27;
												if ((local_28->IsInternalIpaddr_x2b(local_25))&&local_28->m_port1==local_22->m_portno_0__) break;
											}
											if (m_vectorpCWork_.size()>local_26) continue;
										}
										local_14=(double)local_22->m_int_unk14-local_24;
										local_16=local_22;
									}
									local_13->Set_int_unk20(local_13->Get_int_unk20()+1);
									continue;
								}
								m_flgarray_unk[4]=true;
								m_flgarray_unk[5]=true;
								double local_29;
								local_29=local_22->m_float_unk15*0.1;
								if ((double)local_22->m_int_unk14-local_29<local_15) {
									local_15=(double)local_22->m_int_unk14-local_29;
									local_13->Set__unknown_000(local_22->m_uint_unk13);
									unsigned int local_30;
									local_30=local_22->mf_CKey_0150()<<16;
									if (local_30>local_22->m_uint_unk13) {
										local_30=local_22->m_uint_unk13;
									}
									local_13->Set__unknown_001(local_30);
									local_13->Set_unk3(local_22->mf_CKey_0260());
									unsigned char * local_31;
									local_31=local_22->m_hash_tabun;
									if (local_31!=0) {
										memcpy(local_13->m_hash_kamo,local_31,16);
									} else {
										memset(local_13->m_hash_kamo,0,16);
									}
									local_13->m_flg_unk0=true;
								}
							}
						}
					}
					int local_32;
					if (! (!m_optflg_useMultiDownload_&&local_13->m_int_unk4>=0||!m_optflag_Connect__) ) {
						local_32=(int)(m_double_upKBytePerSec_/80);
						local_32=local_32+1;
						local_32=local_32+1;
						if (local_32<2) {
							local_32=2;
						}
						if (m_int_related_maxconnection__+2<local_32) {
							local_32=m_int_related_maxconnection__+2;
						}
						if (! (m_int_CurrentTransferUpConnectionCount_==0||m_double_upKBytePerSec_<=40.0) ) {
							local_32=local_32+1;
						}
						if (! (m_flag_cacheFolderDiskFull_||m_flag_downFolderDiskFull_) ) {
							if (local_16!=0) {
								local_13->Set__unknown_000(local_16->m_uint_unk13);
								unsigned int local_33;
								local_33=local_16->mf_CKey_0150()<<16;
								if (local_16->m_uint_unk13<local_33) {
									local_33=local_16->m_uint_unk13;
								}
								local_13->Set__unknown_001(local_33);
								local_13->Set_unk3(local_16->mf_CKey_0260());
								unsigned char * local_34;
								local_34=local_16->m_hash_tabun;
								if (local_34!=0) {
									memcpy(local_13->m_hash_kamo,local_34,16);
								} else {
									memset(local_13->m_hash_kamo,0,16);
								}
								local_13->m_flg_unk0=true;
								bool local_35;
								local_35=false;
								if (! (local_16->m_bln_unk308||m_int_CurrentTransferDownConnectionCount_>=local_32||local_04>=local_32) ) {
									local_35=true;
								}
								if (! (!local_16->m_bln_unk308||!(local_16->m_char_keyType_==KEYTYPE00)&&!local_16->m_bln_unk301) ) {
									local_35=true;
								}
								if (local_35) {
									m_flgarray_unk[4]=true;
									m_flgarray_unk[5]=true;
									int local_36;
									local_36=local_16->m_int_unk14;
									if (local_36<10) {
										local_16->Set_int_unk14(local_36+1);
										bool local_37;
										int local_38;
										mf_CMainControl_0880(local_16->m_uint_unk13,local_16->m_hash_tabun,-1,0,&local_37,&local_38,NULLPO);
										local_13->Set_int_unk4(local_38);
										return;
									}
									local_16->Set_int_unk14(local_36-1);
								}
								return;
							}
							if (! (local_13->m_int_unk20>=10||!local_13->mf_CAutoDownList_0010()&&strlen(local_13->m_char256_unk1)<=1||(m_int_CurrentTransferDownConnectionCount_>=local_32||local_04>=local_32)) ) {
								xint local_39;
								local_39=5;
								if (!m_optflg_downRetryFast_) {
									local_39=2;
								}
								if ((unsigned int)local_02<3) {
									local_39=10;
								}
								if (rand()%local_39==0) {
									int local_40;
									unsigned int local_41;
									local_40=0;
									for (local_41=0; m_vectorCQuery_.size()>local_41; local_41++) {
										if (!m_vectorCQuery_[local_41].Get_flg_unk04()) continue;
										local_40=local_40+1;
									}
									if (local_40<2) {
										if (local_13->mf_CAutoDownList_0010()) {
											ny_binhash2aschash(local_13->m_hash,local_43+1);
											local_43[0]='%';
											mf_CMainControl_1080(local_43,local_13->m_char256_unk2,false,1);
											return;
										}
										mf_CMainControl_1080(local_13->m_char256_unk1,local_13->m_char256_unk2,false,1);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return;
}



void CMainControl::mf_CMainControl_1270()
{
	int local_00;
	char local_15[1024];

	local_00=0;
	if (m_IgnoreCondition_.size()!=0) {
	unsigned int local_01;
		for (local_01=0; m_IgnoreCondition_.size()>local_01; local_01++) {
			local_00=g_int_unk417%m_IgnoreCondition_.size();
			g_int_unk417=g_int_unk417+1;
			if (!(!m_IgnoreCondition_[local_00].IsValid())&&(m_IgnoreCondition_[local_00].Get_flag_unk7()||m_IgnoreCondition_[local_00].Get_flag_unk8())) break;
		}
		if (g_int_unk417>0x000186A0) {
			g_int_unk417=0;
		}
		if (! (m_IgnoreCondition_.size()<=local_00||m_IgnoreCondition_.size()<=local_01) ) {
			m_int_unk19=local_00;
			CAutoDownList * local_02;
			local_02=&m_IgnoreCondition_[local_00];
			local_02->m_int_unk20=0;
			if (! (!local_02->m_flag_unk7&&local_02->m_flag_unk8) ) {
				local_02->m__unknown_000=0;
				local_02->m__unknown_001=0;
				strcpy(local_02->m_char256_unk3,"");
				memset(local_02->m_hash_kamo,0,16);
				local_02->m_flg_unk0=true;
				bool local_03;
				unsigned short local_04;
				local_03=local_02->mf_CAutoDownList_0010();
				local_04=0;
				local_04=mf_CMainControl_0590(local_02->m_char256_unk1);
				if (local_02->mf_CAutoDownList_0010()) {
					local_04=(short)((unsigned int)local_02->m_hash[0]<<8)+(short)((unsigned int)local_02->m_hash[1]);
				}
				int local_05;
				local_05=0;
				if (m_KeySearchTable_.count(local_04)!=0) {
					multimap<unsigned short,unsigned int>::iterator local_06;
					for (local_06=m_KeySearchTable_.find(local_04); local_06!=m_KeySearchTable_.end(); local_06++) {
						if (local_05>=50) break;
						unsigned int local_07=local_06->second;
						if (local_06->first!=local_04) break;
						if (m_KeyBuffer_.count(local_07)==0) continue;
						multimap<unsigned int,CKey>::iterator local_08;
						for (local_08=m_KeyBuffer_.find(local_07); local_08!=m_KeyBuffer_.end(); local_08++) {
							CKey * local_09=&local_08->second;
							_in_addr local_10;
							if (local_09->m_int_unk0x==0) continue;
							if (*((int *)local_09->m_hash_tabun)!=local_07) break;
							if ((local_09->m_char_keyType_==KEYTYPE02||local_09->m_bln_unk302)||!(!local_02->m_flag_unk5)&&!local_09->m_bln_unk308||!local_02->m_flag_unk5&&local_09->m_bln_unk308||local_09->m_int_refcountOfFileptr_!=0) continue;
							local_09->m_bln_unk303=false;
							local_09->m_bln_unk304=false;
							if (local_03) {
								if (memcmp(local_02->m_hash,local_09->m_hash_tabun,16)!=0) continue;
							} else {
								if (strlen(local_02->m_char256_unk1)<2||!local_09->mf_CKey_0040(local_02->m_char256_unk1,local_02->m_char256_unk2,true)) continue;
							}
							if (!(local_02->m_double_unk9<=0.0)&&(double)local_09->m_uint_unk13*(float)9.5367432e-007>local_02->m_double_unk9||!(local_02->m_double_unk10<=0.0)&&(double)local_09->m_uint_unk13*(float)9.5367432e-007<local_02->m_double_unk10) continue;
							ny_addrcrypter(&local_10,local_09->m_ipaddr_0__);
							if (m_flg_unk15510||local_09->m_char_keyType_==KEYTYPE02) continue;
							if (local_02->m_flag_unk7) {
								if (! (!local_02->m_flag_unk5||!(m_port_accept_!=local_09->m_portno_0__)&&m_hostArray[0].IsInternalIpaddr_x2b(local_10)) ) {
	multimap<unsigned int,CKey>::iterator local_11;
									for (local_11=m_KeyBuffer_.begin(); local_11!=m_KeyBuffer_.end(); local_11++) {
CKey *										local_12=&local_11->second;
										if (local_12->m_int_unk0x==0||local_12->m_int_refcountOfFileptr_!=0||!local_12->m_bln_unk308||local_12->m_portno_1__!=local_09->m_portno_1__||memcmp(&local_09->m_ipaddr_1__,&local_12->m_ipaddr_1__,4)!=0) continue;
										local_12->mf_CKey_0130();
										if (! (!(local_12->m_char_keyType_==KEYTYPE01)&&local_12->m_char_keyType_!=KEYTYPE03) ) {
											local_12->mf_CKey_0110();
										}
										local_12->m_int_unk0x=0;
									}
								}
								local_09->mf_CKey_0130();
								if (! (!(local_09->m_char_keyType_==KEYTYPE01)&&local_09->m_char_keyType_!=KEYTYPE03) ) {
									local_09->mf_CKey_0110();
									local_05=local_05+1;
								}
								local_09->m_int_unk0x=0;
							}
							if (local_02->m_flag_unk8) {
								if (! (!local_02->m_flag_unk5||!(m_port_accept_!=local_09->m_portno_0__)&&m_hostArray[0].IsInternalIpaddr_x2b(local_10)) ) {
									multimap<unsigned int,CKey>::iterator local_13;
									for (local_13=m_KeyBuffer_.begin(); local_13!=m_KeyBuffer_.end(); local_13++) {
CKey *										local_14=&local_13->second;
										if (local_14->m_int_unk0x==0||local_14->m_int_refcountOfFileptr_!=0||!local_14->m_bln_unk308||local_14->m_portno_1__!=local_09->m_portno_1__||memcmp(&local_09->m_ipaddr_1__,&local_14->m_ipaddr_1__,4)!=0) continue;
										local_14->m_bln_unk310=true;
									}
								}
								local_09->m_bln_unk310=true;
								if (local_02->mf_CAutoDownList_0010()) {
									local_09->m_bln_unk309=true;
								}
							}
							local_02->Set_int_unk20(local_02->Get_int_unk20()+1);
							if (!local_02->m_flag_unk6) continue;
							local_02->m_flg_unk0=false;
							if (g_AppPath.Length()==0) return;
							sprintf(local_15,"%s%s",/*(const char *)*/g_AppPath,"Ignore.txt");
							mf_CMainControl_0120(local_15);
							return;
						}
					}
				}
			}
		}
	}
	return;
}


void CMainControl::mf_CMainControl_1280(int arg_0)
{
	CWork * local_00;
	local_00=m_vectorpCWork_[arg_0];
	CKey * local_01;
	local_01=mf_CMainControl_0180(local_00->GetCountMax(),local_00->m_uchar16_unk1);
	if (! (local_01==0||local_01->m_int_unk0x==0||local_01->m_char_keyType_==KEYTYPE00) ) {
		mf_CMainControl_0980(local_01->m_uint_unk13,local_01->m_hash_tabun,false);
	}
	return;
}


void CMainControl::mf_CMainControl_1290()
{
	int local_00;
	int local_01;
	CHost * local_02;
	CHost * local_03;
	_in_addr local_04;
	int local_05;
	int local_06;
	int local_07;

	for (local_00=0; local_00<1; local_00++) {
		local_01=0;
		for (local_01=0; local_01<100; local_01++) {
			m_int_unk31=m_int_unk31+1;
			if (m_int_unk31>=600) {
				m_int_unk31=1;
			}
			local_02=m_hostArray+m_int_unk31;
			if ( (!local_02->m_flgIsValid||local_02->m_flg_IsBBSPort||!local_02->m_flgIsConnected||local_02->m_flgIsTransferLink_8) ) {
				continue;
			} else {
				break;
			}
		}
		if (local_01>=100) break;
		local_03=m_hostArray+m_int_unk31;
		ny_addrcrypter(&local_04,local_03->m_ipaddr3);
		local_05=3;
		local_06=0;
		local_07=0;
		multimap<unsigned int,CKey>::iterator local_08;
		for (local_08=m_KeyBuffer_.begin(); local_08!=m_KeyBuffer_.end(); local_08++) {
			CKey * local_09=&local_08->second;
			if (local_09->m_portno_0__!=local_03->m_port1||memcmp(&local_04,&local_09->m_ipaddr_0__,4)!=0) continue;
			if (local_09->m_bln_unk309) {
				local_06=local_06+1;
			}
			if (local_09->m_bln_unk310) {
				local_07=local_07+1;
			}
			if (local_06>0||local_07>=3) break;
		}
		char local_10;
		if (!(local_06>0)&&local_07<3) continue;
		mf_CMainControl_0680(m_int_unk31);
		local_10='"';
		if (local_06>0) {
			local_10='%';
		}
		mf_CMainControl_0370(m_int_unk31,&local_10,1);
		local_03->m_field_82=true;
	}
	return;
}


bool CMainControl::mf_CMainControl_1300(int arg_0,unsigned char * arg_1,unsigned int arg_2,char * arg_3,unsigned int arg_4)
{
	char local_04[256];
	char local_05[131056];
	char local_06[16];
	unsigned char local_07[16];

	if (! (arg_1!=0||!(arg_0<0||m_vectorpCWork_.size()<arg_0)&&/**/(*GetWorkNP(arg_0))->GetWorkType()==WORKTYPE01) ) {
		return false;
	}
	CKey * local_00=NULLPO;
	if (arg_1!=0) {
		local_00=this->mf_CMainControl_0180(arg_2,(unsigned char *)arg_1);
	} else {
		local_00=mf_CMainControl_0180(/**/(*GetWorkNP(arg_0))->GetCountMax(),/**/(*GetWorkNP(arg_0))->Get_uchar16_unk1());
	}
	if (local_00==0) {
		return false;
	}
	bool	local_01=false;
	FILE *	local_02=fopen(local_00->mf_CKey_0210().c_str(),"rb");
	if (local_02!=0) {
		fseek(local_02,local_00->mf_CKey_0170()+320,0);
		local_00->mf_CKey_0200(0,local_04);
		m_CRC4.setupkey(local_04);
		memset(local_06,0,0x00020000);
		int local_03=fread(local_06,1,0x00010010,local_02);
		if (local_03>16) {
			m_CRC4.crypter(local_05,local_03+-16);
			MD5calc(local_05,local_07,local_03+-16);
			if (memcmp(local_06,local_07,16)==0) {
				local_01=true;
				memcpy(arg_3,local_05,arg_4);
			}
		}
		fclose(local_02);
	}
	return local_01;
}


char * CMainControl::mf_CMainControl_1310(int arg_0,char * arg_1,int * arg_2,time_t * arg_3)
{
	bool local_00;
	char * local_01;
	int local_02;
	char * local_03;
	char * local_04;
	char * local_05;
	time_t local_06;
	struct_tm * local_07;
	bool local_08;
	char local_09[131072];
	char local_10[131072];
	char local_11[512];
	char local_12[256];
	char local_13[4096];
	char local_14[512];
	char local_15[244];
	char local_16[12];
	char local_17[4096];
	char local_18[256];
	char local_19[1024];
	local_00=false;
	local_01=arg_1;
	*arg_3=(time_t)0;
	local_02=1;
	while (true) {
		local_03=local_09;
		local_04=local_01;
		for ( ; !(*local_01==0||(int)*local_01==10)&&local_03-local_09<0x00020000; local_03++) {
			*local_03=*local_01;
			local_01=local_01+1;
		}
		if ((int)*local_01!=10) {
			local_00=true;
			local_01=local_04;
			break;
		}
		*local_03=0;
		local_03=local_09;
		for (local_05=local_10; !(*local_03==0||(int)*local_03==9)&&local_05-local_10<512; local_05++) {
			*local_05=*local_03;
			local_03=local_03+1;
		}
		*local_05=0;
		strcpy(local_14,local_10);
		ny_htmlproc_1(local_10,local_11,true,false);
		if (*local_03!=0) {
			local_03=local_03+1;
		}
		for (local_05=local_10; !(*local_03==0||(int)*local_03==9)&&local_05-local_10<256; local_05++) {
			*local_05=*local_03;
			local_03=local_03+1;
		}
		*local_05=0;
		strcpy(local_16,local_10);
		if (*local_03!=0) {
			local_03=local_03+1;
		}
		for (local_05=local_12; !(*local_03==0||(int)*local_03==9)&&local_05-local_12<256; local_05++) {
			*local_05=*local_03;
			local_03=local_03+1;
		}
		*local_05=0;
		if (*local_03!=0) {
			local_03=local_03+1;
		}
		for (local_05=local_10; !(*local_03==0||(int)*local_03==9)&&local_05-local_10<4096; local_05++) {
			*local_05=*local_03;
			local_03=local_03+1;
		}
		*local_05=0;
		strcpy(local_17,local_10);
		ny_htmlproc_1(local_10,local_13,true,false);
		local_06=(time_t)callatol(local_12);
		local_07=localtime(&local_06);
		if (! (local_06==0||local_07==0) ) {
			if (stricmp(local_16,"sage")!=0) {
				*arg_3=local_06;
			}
			*arg_2=*arg_2+1;
			sprintf(local_18,"%02d/%02d/%02d %02d:%02d",local_07->tm_year%100,local_07->tm_mon+1,local_07->tm_mday,local_07->tm_hour,local_07->tm_min);
			local_08=mf_CMainControl_1440(local_17,local_14,local_16);
			if (! (strlen(local_16)<=12||(int)local_16[11]!=35) ) {
				strcpy(local_19,local_15);
			} else {
				local_19[0]=0;
			}
			if (local_08) {
				sprintf(local_09,"<br><dt>%d ：<font color=green><b>%s</b><b>◆%s</b></font>：%s</dt><dd>%s</dd><br>\n",*arg_2,local_11,local_19,local_18,local_13);
			} else {
				sprintf(local_09,"<br><dt>%d ：<font color=red><b>%s</b><b>◆認証警告 %s</b></font>：%s</dt><dd>%s</dd><br>\n",*arg_2,local_11,local_19,local_18,local_13);
			}
			int tmp=strlen(local_09);
			m_hostArray[arg_0].mf_CHost_0170(local_09,tmp);
		}
		while ((int)*local_01==10||(int)*local_01==13) {
			local_01=local_01+1;
		}
		if (local_00) break;
		local_02=local_02+1;
	}
	return local_01;
}



char * CMainControl::mf_CMainControl_1320(TRichTextView * arg_0,char * arg_1,time_t * arg_2,time_t * arg_3)
{
	bool local_00;
	float local_01;
	TColor local_02;
	TColor local_03;
	char local_24[131072];
	char local_25[131072];
	char local_26[131072];
	char local_27[512];
	char local_28[256];
	char local_29[4096];
	char local_30[512];
	char local_31[244];
	char local_32[12];
	char local_33[4096];
	char local_34[256];
	char local_35[1024];

	local_00=false;
	local_01=1.0;
	if (MainForm->BbsButton->Down) {
		local_01=(double)(OptionForm->BbsColorTrackBar->Position+1)*0.5;
	} else {
		local_01=(double)(OptionForm->ColorTrackBar->Position+1)*0.5;
	}
	local_02=(TColor)(((unsigned int)((unsigned char)((int)(128.0/local_01)))|(unsigned int)((unsigned short)((unsigned int)((unsigned char)((int)(128.0/local_01)))))<<8)|(unsigned int)((unsigned char)((int)(255.0/local_01)))<<16);
	local_03=(TColor)RGB( 0, 255.0/local_01,0 );
	*((TColor *)arg_0->TextAttrib)=arg_0->Font->Color;
	arg_0->TextAttrib[1].color=local_02;
	(arg_0->TextAttrib+1)->style<<fsUnderline;  //|=4;
	arg_0->TextAttrib[2].color=local_03;
	arg_0->TextAttrib[3].color=(TColor)0x000000FF;

	char * local_04;
	int local_05;
	local_04=arg_1;
	*arg_3=(time_t)0;
	local_05=1;
	while (true) {
		char * local_06;
		char * local_07;
		char * local_08;
		local_06=local_24;
		local_07=local_04;
		for ( ; !(*local_04==0||(int)*local_04==10)&&local_06-local_24<0x00020000; local_06++) {
			*local_06=*local_04;
			local_04=local_04+1;
		}
		if ((int)*local_04!=10) {
			local_00=true;
			local_04=local_07;
			break;
		}
		*local_06=0;
		local_06=local_24;
		for (local_08=local_25; !(*local_06==0||(int)*local_06==9)&&local_08-local_25<512; local_08++) {
			*local_08=*local_06;
			local_06=local_06+1;
		}
		*local_08=0;
		strcpy(local_30,local_25);
		ny_htmlproc_1(local_25,local_26,false,true);
		ny_htmlproc_4(local_26,local_27);
		if (*local_06!=0) {
			local_06=local_06+1;
		}
		for (local_08=local_25; !(*local_06==0||(int)*local_06==9)&&local_08-local_25<256; local_08++) {
			*local_08=*local_06;
			local_06=local_06+1;
		}
		*local_08=0;
		strcpy(local_32,local_25);
		if (*local_06!=0) {
			local_06=local_06+1;
		}
		for (local_08=local_28; !(*local_06==0||(int)*local_06==9)&&local_08-local_28<256; local_08++) {
			*local_08=*local_06;
			local_06=local_06+1;
		}
		*local_08=0;
		if (*local_06!=0) {
			local_06=local_06+1;
		}
		for (local_08=local_25; !(*local_06==0||(int)*local_06==9)&&local_08-local_25<4096; local_08++) {
			*local_08=*local_06;
			local_06=local_06+1;
		}
		*local_08=0;
		strcpy(local_33,local_25);
		ny_htmlproc_1(local_25,local_26,true,true);
		ny_htmlproc_4(local_26,local_29);

		time_t local_09;
		struct_tm * local_10;
		local_09=(time_t)callatol(local_28);
		local_10=localtime(&local_09);
		if ( (!(local_09==0||local_10==0)) ) {
			TRichTVItem * local_11;
			bool local_12;
			local_11=new TRichTVItem(arg_0);
			local_11->OffsetLeft=5;
			if (stricmp(local_32,"sage")!=0) {
				*arg_3=local_09;
			}
			local_12=mf_CMainControl_1440(local_33,local_30,local_32);
			*arg_2=*arg_2+1;
			sprintf(local_34,"%02d/%02d/%02d %02d:%02d",local_10->tm_year%100,local_10->tm_mon+1,local_10->tm_mday,local_10->tm_hour,local_10->tm_min);
			sprintf(local_24,"%d",*arg_2);
			local_11->Add(local_24,strlen(local_24),33);
			sprintf(local_24," 名前：");
			local_11->Add(local_24,strlen(local_24),0);
			if (! (strlen(local_32)<=12||(int)local_32[11]!=35) ) {
				strcpy(local_35,local_31);
			} else {
				local_35[0]=0;
			}
			if (local_12) {
				sprintf(local_24,"%s◆%s",local_27,local_35);
				local_11->Add(local_24,strlen(local_24),2);
			} else {
				sprintf(local_24,"%s◆認証警告 %s",local_27,local_35);
				local_11->Add(local_24,strlen(local_24),3);
			}
			sprintf(local_24," 投稿日：%s\r\n",local_34);
			local_11->Add(local_24,strlen(local_24),0);
			m_vectorInt__1.push_back(arg_0->Strings->Count);
			arg_0->Strings->Add(local_11);

			char * local_13;
			char * local_14;
			bool local_15;
			TRichTVItem * local_16;
			int local_17;
			int local_18;
			int local_19;
			int local_20;
			int local_21;
			int local_22;
			TRichTVItem * local_23;
			local_13=local_29;
			local_14=local_29;
			while (1) {
				while (!(*local_13==0)&&(int)*local_13!=10) {
					local_13=local_13+1;
				}
				local_15=(bool)(*local_13==0);
				*local_13=0;
				local_16=new TRichTVItem(arg_0);
				local_16->OffsetLeft=30;
				local_17=strlen(local_14)-1;
				local_18=0;
				for (local_19=0; local_19<local_17; local_19++) {
					if (! (((int)*(local_14+local_19)!=62||(int)*((local_14+1)+local_19)!=62)||!(!((int)*((local_14+2)+local_19)<48)&&(int)*((local_14+2)+local_19)<=57)&&(int)*((local_14+2)+local_19)!=45) ) {
						for (local_20=2; local_20<13; local_20++) {
							if (*(local_14+(local_19+local_20))==0||!((int)*(local_14+(local_19+local_20))==45)&&((int)*(local_14+(local_19+local_20))<48||(int)*(local_14+(local_19+local_20))>57)) break;
						}
						if (local_18<local_19) {
							local_16->Add(local_14+local_18,local_19-local_18,0);
						}
						local_16->Add(local_14+local_19,local_20,33);
						local_16->Add(" ",1,128);
						local_18=local_19+local_20;
						local_19=local_19+2;
					}
					if (! ((int)*(local_14+local_19)!=62||!(!((int)*((local_14+1)+local_19)<48)&&(int)*((local_14+1)+local_19)<=57)&&(int)*((local_14+1)+local_19)!=45) ) {
						for (local_21=1; local_21<13; local_21++) {
							if (*(local_14+(local_19+local_21))==0||!((int)*(local_14+(local_19+local_21))==45)&&((int)*(local_14+(local_19+local_21))<48||(int)*(local_14+(local_19+local_21))>57)) break;
						}
						if (local_18<local_19) {
							local_16->Add(local_14+local_18,local_19-local_18,0);
						}
						local_16->Add(local_14+local_19,local_21,33);
						local_16->Add(" ",1,128);
						local_18=local_19+local_21;
						local_19=local_19+1;
					}
					if (strncmp(local_14+local_19,"http://",7)!=0) continue;
					local_22=7;
					while (true) {
						if ((unsigned char)*(local_14+(local_19+local_22))=='<'
						  ||(unsigned char)*(local_14+(local_19+local_22))=='>'
						  ||(unsigned char)*(local_14+(local_19+local_22))<'#'
						  ||(unsigned char)*(local_14+(local_19+local_22))>=128) break;
						local_22=local_22+1;
					}
					if (local_18<local_19) {
						local_16->Add(local_14+local_18,local_19-local_18,0);
					}
					local_16->Add(local_14+local_19,local_22,33);
					local_16->Add(" ",1,128);
					local_18=local_19+local_22;
					local_19=local_19+local_22;
				}
				local_16->Add(local_14+local_18,strlen(local_14+local_18),0);
				arg_0->Strings->Add(local_16);
				if (local_15) {
					local_23=new TRichTVItem(arg_0);
					local_23->OffsetLeft=30;
					arg_0->Strings->Add(local_23);
				} else {
				
					local_13=local_13+1;
					local_14=local_13;
					continue;
				}
				break;
			}
		}

		while ((int)*local_04==10||(int)*local_04==13) {
			local_04=local_04+1;
		}

		if (local_00) break;
		local_05=local_05+1;
	}
	return local_04;
}



sl CMainControl::mf_CMainControl_1330(TBbsTab * arg_0,TRichTextView * arg_1,TLabel * arg_2)
{
	CKey * local_00;
	time_t local_01;
	char local_13[131056];
	char local_14[16];
	char local_15[131072];
	char local_16[256];
	unsigned char local_17[16];

	arg_1->Clear();
	local_00=g_pCMainControl->mf_CMainControl_0180(0,arg_0->m_hash);
	if (local_00==0) {
		return 0;
	}
	local_01=local_00->m_time_;
	ny_unknown_0010(local_15,local_01);
	bool tmp=local_00->mf_CKey_0010();
	sprintf(local_14,"  %s%s Mes: %d Time: %s Trip: %s",tmp?"":"(認証警告) ",local_00->mf_CKey_0260(),local_00->GetRefs(),local_15,local_00->mf_CKey_0000());
	arg_2->Caption=local_14;
	g_pCMainControl->m_vectorInt__1.clear();
	int	local_02=local_00->m_int_unk17;
	if (local_00->m_char_keyType_==KEYTYPE02) {
		FILE *		local_03=fopen(local_00->mf_CKey_0230().c_str(),"rt");
		time_t local_04;
		if (local_03!=0) {
			local_04=(time_t)0;
			while (true) {
				time_t local_06;
				if (feof(local_03)) break;
				local_14[0]=0;
				fgets(local_14,0x00020000,local_03);
				local_06=local_01;
				char * local_05=g_pCMainControl->mf_CMainControl_1320(arg_1,local_14,&local_04,&local_06);
				//!!45ada1 ここよくわからん：local_05と06が逆になっちゃう
			}
			fclose(local_03);
		}
	} else {
		int local_07;
		local_07=local_00->mf_CKey_0170();
		strcpy(local_14,local_00->mf_CKey_0210().c_str());
		FILE * local_08=fopen(local_00->mf_CKey_0210().c_str(),"rb");
		if (local_08!=0) {
			time_t local_09;
			int local_10;
			local_09=(time_t)0;
			local_15[0]=0;
			for (local_10=0; local_10<local_07; local_10++) {
				fseek(local_08,local_10*0x00010010+local_07+320,0);
				local_00->mf_CKey_0200(local_10,local_16);
				m_CRC4.setupkey(local_16);
				int local_11=fread(local_14,1,0x00010010,local_08);
				if (local_11<=16) break;
				m_CRC4.crypter(local_13,local_11+-16);
				MD5calc(local_13,local_17,local_11+-16);
				if (memcmp(local_14,local_17,16)!=0) {
					fclose(local_08);
					local_08=NULLPO;
					_unlink(local_00->mf_CKey_0210().c_str());
					local_00->mf_CKey_0130();
					local_00->m_char_keyType_=KEYTYPE01;
					local_00->mf_CKey_0110();
					break;
				}
				*(local_14+local_11)=0;
				time_t local_12=(time_t)0;
				strcat(local_15,local_13);
				char *tmp=g_pCMainControl->mf_CMainControl_1320(arg_1,local_15,&local_09,&local_12);
				strcpy(local_15,tmp);
				
				if (strlen(local_15)>0x00010000) break;
			}
			if (local_08!=0) {
				fclose(local_08);
			}
		}
	}
	return local_02;
}


void CMainControl::mf_CMainControl_1340(int arg_0)
{
	CWork * local_00;
	unsigned char local_12[16];
	char local_13[256];
	char local_14[4096];
	local_00=m_vectorpCWork_[arg_0];
	int	local_01=local_00->m_hostIdx_;
	if (! (local_01<0||m_hostArray[local_01].m_flgIsConnected) ) {
		m_hostArray[local_01].mf_CHost_0190(true);
		local_00->mf_CWork_0010(true,false);
		if (local_00->m_pchar_status_!=0) {
			strcpy(local_00->m_pchar_status_,"接続切断");
		}
		return;
	}

	CKey * local_02;
	local_02=mf_CMainControl_0180(local_00->GetCountMax(),local_00->m_uchar16_unk1);
	if (local_02==0) {
		if (! (local_00->m_int_unk211<0||/**/(*GetWorkNP(local_00->m_int_unk211))->GetWorkType()!=WORKTYPE01||/**/(*GetWorkNP(local_00->m_int_unk211))->IsFinished()) ) {
			m_vectorpCWork_[local_00->m_int_unk211]->mf_CWork_0010(true,false);
		}
		if (local_01>=0) {
			strcpy(gbuf40000_1,"<br><font color=red>BBSキーロストエラー</font><br>\n");
			m_hostArray[local_01].mf_CHost_0170(gbuf40000_1,strlen(gbuf40000_1));
			strcpy(gbuf40000_1,"</body>\n");
			m_hostArray[local_01].mf_CHost_0170(gbuf40000_1,strlen(gbuf40000_1));
			strcpy(gbuf40000_1,"</html>\n\n");
			m_hostArray[local_01].mf_CHost_0170(gbuf40000_1,strlen(gbuf40000_1));
			m_hostArray[local_01].mf_CHost_0190(true);
		} else {
			strcpy(m_szstr_errormsg_,"BBSキーロストエラー");
			if (local_00->m_pchar_status_!=0) {
				strcpy(local_00->m_pchar_status_,"キーロスト");
			}
		}
		local_00->mf_CWork_0010(true,false);
		return;
	}
	_in_addr local_03;
	ny_addrcrypter(&local_03,m_hostArray[0].m_ipaddr3);

	bool local_04;

	local_04=true;
	gbuf40000_1[0]=0;
	if (! (!local_00->m_flg_unk200||local_00->m_flg_unk201) ) {
		return;
	}
	if (local_00->Get_flg_unk302()) {
		if (local_01>=0) {
			strcpy(gbuf40000_1,"<br><font color=red>タイムアウトエラー</font><br>\n");
			m_hostArray[local_01].mf_CHost_0170(gbuf40000_1,strlen(gbuf40000_1));
		} else {
			strcpy(m_szstr_errormsg_,"タイムアウトエラー");
		}
	} else {
		if (! (!(local_00->m_int_unk211<0)&&/**/(*GetWorkNP(local_00->m_int_unk211))->GetWorkType()==WORKTYPE01) ) {
			if (! (local_01<0||mf_CMainControl_1190(local_02)) ) {
				strcpy(gbuf40000_1,"<br><font color=red>ローカルキャッシュ出力</font><br>\n");
				m_hostArray[local_01].mf_CHost_0170(gbuf40000_1,strlen(gbuf40000_1));
			}
			strcpy(m_szstr_errormsg_,"ローカルキャッシュ");
		} else {
			if (/**/(*GetWorkNP(local_00->m_int_unk211))->Get_flg_unk302()) {
				if (local_01>=0) {
					strcpy(gbuf40000_1,"<br><font color=red>タイムアウトエラー</font><br>\n");
					m_hostArray[local_01].mf_CHost_0170(gbuf40000_1,strlen(gbuf40000_1));
				} else {
					strcpy(m_szstr_errormsg_,"タイムアウトエラー");
				}
			} else {
				if (/**/(*GetWorkNP(local_00->m_int_unk211))->GetErrorcode()>0) {
					mf_CMainControl_1580(m_vectorpCWork_[local_00->m_int_unk211],gbuf40000_2);
					if (local_01>=0) {
						sprintf(gbuf40000_1,"<br><font color=red>%s</font><br>\n",gbuf40000_2);
						m_hostArray[local_01].mf_CHost_0170(gbuf40000_1,strlen(gbuf40000_1));
					} else {
						strcpy(m_szstr_errormsg_,gbuf40000_2);
					}
				} else {
					if (/**/(*GetWorkNP(local_00->m_int_unk211))->IsFinished()) {
						if (mf_CMainControl_1580(m_vectorpCWork_[local_00->m_int_unk211],gbuf40000_2)!=0) {
							if (local_01>=0) {
								strcpy(gbuf40000_1,"<br><font color=red>");
								m_hostArray[local_01].mf_CHost_0170(gbuf40000_1,strlen(gbuf40000_1));
								m_hostArray[local_01].mf_CHost_0170(gbuf40000_2,strlen(gbuf40000_2));
								strcpy(gbuf40000_1,"</font><br>\n");
								m_hostArray[local_01].mf_CHost_0170(gbuf40000_1,strlen(gbuf40000_1));
							} else {
								strcpy(m_szstr_errormsg_,gbuf40000_2);
							}
						}
					} else {
						local_04=false;
					}
				}
			}
		}
	}
	if (local_04) {
		int local_05;
		local_05=local_02->mf_CKey_0170();
		if (!local_00->m_flg_unk200) {
			if (local_01>=0) {
				FILE * local_06=fopen(local_02->mf_CKey_0210().c_str(),"rb");
				if (local_06!=0) {
					int local_07;
					int local_08;
					local_07=0;
					strcpy(gbuf40000_1,"<dl>\n");
					m_hostArray[local_01].mf_CHost_0170(gbuf40000_1,strlen(gbuf40000_1));
					gbuf40000_2[0]=0;
					for (local_08=0; local_08<local_05; local_08++) {
						fseek(local_06,local_08*0x00010010+local_05+320,0);
						local_02->mf_CKey_0200(local_08,local_13);
						m_CRC4.setupkey(local_13);
						int local_09=fread(gbuf40000_1,1,0x00010010,local_06);
						if (local_09<=16) break;
						m_CRC4.crypter(gbuf40000_1+16,local_09+-16);
						MD5calc(&gbuf40000_1[16],local_12,local_09+-16);
						if (memcmp(gbuf40000_1,local_12,16)!=0) {
							fclose(local_06);
							local_06=NULLPO;
							_unlink(local_02->mf_CKey_0210().c_str());
							local_02->mf_CKey_0130();
							local_02->m_char_keyType_=KEYTYPE01;
							local_02->mf_CKey_0110();
							strcpy(gbuf40000_1,"キャッシュ破損検出\n");
							m_hostArray[local_01].mf_CHost_0170(gbuf40000_1,strlen(gbuf40000_1));
							break;
						}
						*(gbuf40000_1+local_09)=0;
						time_t local_10=(time_t)0;
						strcat(gbuf40000_2,&gbuf40000_1[16]);
						char * local_11=mf_CMainControl_1310(local_01,gbuf40000_2,&local_07,&local_10);
						local_02->SetRefs(local_07);
						local_09=strlen(local_11);
						memcpy(gbuf40000_2,local_11,local_09);
						*(gbuf40000_2+local_09)=0;
						if (strlen(gbuf40000_2)>0x00010000) break;
					}
					strcpy(gbuf40000_1,"</dl>\n");
					m_hostArray[local_01].mf_CHost_0170(gbuf40000_1,strlen(gbuf40000_1));
					strcpy(gbuf40000_1,"<br><hr>\n");
					m_hostArray[local_01].mf_CHost_0170(gbuf40000_1,strlen(gbuf40000_1));
					if (strlen(local_00->m_char256_unk3)!=0) {
						ny_htmlproc_2(local_00->m_char256_unk3,gbuf40000_2);
						sprintf(gbuf40000_1,"<br><a href=\"/%s/\">%sスレッド一覧</a>\n",gbuf40000_2,local_00->m_char256_unk3);
						m_hostArray[local_01].mf_CHost_0170(gbuf40000_1,strlen(gbuf40000_1));
					}
					if (mf_CMainControl_1190(local_02)) {
						ny_binhash2aschash(local_02->m_hash_tabun,gbuf40000_1);
						mf_CMainControl_1480(local_01,gbuf40000_1);
					}
					if (local_06!=0) {
						fclose(local_06);
					}
				}
			}
		} else {
			if (!local_00->m_flg_unk202) {
				if (local_01>=0) {
					strcpy(gbuf40000_1,"<BR>投稿に失敗しました。\n");
					m_hostArray[local_01].mf_CHost_0170(gbuf40000_1,strlen(gbuf40000_1));
				} else {
					strcpy(m_szstr_errormsg_,"投稿に失敗しました");
				}
			} else {
				if (local_01>=0) {
					strcpy(gbuf40000_1,"<BR>投稿に成功しました。読み込み直してください。<BR><BR>\n");
					m_hostArray[local_01].mf_CHost_0170(gbuf40000_1,strlen(gbuf40000_1));
					ny_binhash2aschash(local_02->m_hash_tabun,gbuf40000_2);
					strcpy(gbuf40000_1,local_02->mf_CKey_0260());
					ny_htmlproc_3(gbuf40000_1,local_14);
					sprintf(gbuf40000_1,"<a href=\"%s\">%s</a><br>\n",gbuf40000_2,local_14);
					m_hostArray[local_01].mf_CHost_0170(gbuf40000_1,strlen(gbuf40000_1));
				} else {
					strcpy(m_szstr_errormsg_,"投稿に成功しました");
				}
				local_02->Set_ipaddr_0(&local_02->m_ipaddr_1__);
				local_02->Set_portno_0(local_02->m_portno_1__);
				local_02->mf_CKey_0290();
			}
		}
		if (local_01>=0) {
			strcpy(gbuf40000_1,"</body>\n");
			m_hostArray[local_01].mf_CHost_0170(gbuf40000_1,strlen(gbuf40000_1));
			strcpy(gbuf40000_1,"</html>\n\n");
			m_hostArray[local_01].mf_CHost_0170(gbuf40000_1,strlen(gbuf40000_1));
			m_hostArray[local_01].mf_CHost_0190(true);
		}
		local_00->mf_CWork_0010(true,false);
		if (! (local_00->m_int_unk211<0||/**/(*GetWorkNP(local_00->m_int_unk211))->GetWorkType()!=WORKTYPE01||/**/(*GetWorkNP(local_00->m_int_unk211))->IsFinished()) ) {
			m_vectorpCWork_[local_00->m_int_unk211]->mf_CWork_0010(true,false);
		}
	}
	return;
}



bool CMainControl::mf_CMainControl_1350(int arg_0,CKey * arg_1,bool arg_2,const char * arg_3,const char * arg_4,const char * arg_5)
{
	int local_01;
	char local_20[4096];
	char local_21[256];
	char local_22[4096];
	local_01=/**/(*GetWorkNP(arg_0))->GetHostIdx();
	if (! (local_01<0||m_hostArray[local_01].m_flgIsConnected) ) {
		m_hostArray[local_01].mf_CHost_0190(true);
		m_vectorpCWork_[arg_0]->mf_CWork_0010(true,false);
		return false;
	}
	if (local_01>=0) {
		CWork *		local_02=m_vectorpCWork_[arg_0];
		bool		local_03=arg_1->mf_CKey_0010();
		ny_unknown_0010(local_21,arg_1->m_time_);
		sprintf(gbuf40000_3,"%s%s  Time: %s Trip: %s",!(!local_03)?"":"(認証警告) ",arg_1->mf_CKey_0260(),local_21,arg_1->mf_CKey_0000());
		ny_htmlproc_3(gbuf40000_3,local_20);
		strcpy(gbuf40000_3,"<head>\n");
		m_hostArray[local_01].mf_CHost_0170(gbuf40000_3,strlen(gbuf40000_3));
		sprintf(gbuf40000_3,"<title>%s</title>\n",local_20);
		m_hostArray[local_01].mf_CHost_0170(gbuf40000_3,strlen(gbuf40000_3));
		strcpy(gbuf40000_3,"</head>\n");
		m_hostArray[local_01].mf_CHost_0170(gbuf40000_3,strlen(gbuf40000_3));
		sprintf(gbuf40000_3,"<body bgcolor=#efefef text=black link=blue alink=red vlink=#660099>\n");
		m_hostArray[local_01].mf_CHost_0170(gbuf40000_3,strlen(gbuf40000_3));
		if (strlen(local_02->m_char256_unk3)!=0) {
			ny_htmlproc_2(local_02->m_char256_unk3,local_21);
			sprintf(gbuf40000_3,"<a href=\"/%s/\">%sスレッド一覧</a>\n",local_21,local_02->m_char256_unk3);
			m_hostArray[local_01].mf_CHost_0170(gbuf40000_3,strlen(gbuf40000_3));
		}
		if (local_03) {
			sprintf(gbuf40000_3,"<p><font size=+1 color=red>%s</font><br>\n",local_20);
		} else {
			sprintf(gbuf40000_3,"<p><font size=+1 color=red><strike>%s</strike></font><br>\n",local_20);
		}
		m_hostArray[local_01].mf_CHost_0170(gbuf40000_3,strlen(gbuf40000_3));
	}
	if (arg_1->m_char_keyType_==KEYTYPE02) {
		CWork * local_04;
		local_04=m_vectorpCWork_[arg_0];
		if (local_01>=0) {
			FILE * local_05=fopen(arg_1->mf_CKey_0230().c_str(),"rb");
			if (local_05==0) {
				sprintf(gbuf40000_3,"<br><font color=red>ファイルオープンエラー</font><br>\n");
				m_hostArray[local_01].mf_CHost_0170(gbuf40000_3,strlen(gbuf40000_3));
				arg_1->m_int_unk0x=0;
				return false;
			}
			fclose(local_05);
		}
		if (!arg_2) {
			FILE * local_06=fopen(arg_1->mf_CKey_0230().c_str(),"rt");
			unsigned int local_07;
			int local_08;
			int local_09;
			local_07=strlen("WinnyBBS 2.0b1 ");
			if (! (!(fread(gbuf40000_3,1,local_07,local_06)!=local_07) && memcmp(gbuf40000_3,"WinnyBBS 2.0b1 ",local_07)==0) ) {
				fclose(local_06);
				arg_1->m_int_unk0x=0;
				return false;
			}
			local_08=0;
			gbuf40000_4[0]=0;
			if (local_06!=0) {
				strcpy(gbuf40000_3,"<dl>\n");
				m_hostArray[local_01].mf_CHost_0170(gbuf40000_3,strlen(gbuf40000_3));
				arg_1->SetRefs(0);
				for (local_09=0; local_09<10; local_09++) {
					int local_10=fread(gbuf40000_3,1,0x00010000,local_06);
					if (local_10<=0) break;
					*(gbuf40000_3+local_10)=0;
					strcat(gbuf40000_4,gbuf40000_3);
					time_t local_11;
					char * local_12;
					time_t local_13;
					local_11=(time_t)0;
					local_13=local_11;
					local_12=mf_CMainControl_1310(local_01,gbuf40000_4,&local_08,&local_13);
					arg_1->SetRefs(local_08);
					if (local_11!=0) {
						arg_1->Set_time(local_11);
					}
					strcpy(gbuf40000_4,local_12);
					if (strlen(gbuf40000_4)>0x00010000) break;
				}
				fclose(local_06);
				strcpy(gbuf40000_3,"</dl>\n");
				m_hostArray[local_01].mf_CHost_0170(gbuf40000_3,strlen(gbuf40000_3));
				strcpy(gbuf40000_3,"<br><hr>\n");
				m_hostArray[local_01].mf_CHost_0170(gbuf40000_3,strlen(gbuf40000_3));
				if (strlen(local_04->m_char256_unk3)!=0) {
					ny_htmlproc_2(local_04->m_char256_unk3,gbuf40000_4);
					sprintf(gbuf40000_3,"<br><a href=\"/%s/\">%sスレッド一覧</a>\n",gbuf40000_4,local_04->m_char256_unk3);
					m_hostArray[local_01].mf_CHost_0170(gbuf40000_3,strlen(gbuf40000_3));
				}
				if (mf_CMainControl_1190(arg_1)) {
					ny_binhash2aschash(arg_1->m_hash_tabun,gbuf40000_3);
					mf_CMainControl_1480(local_01,gbuf40000_3);
				}
			}
		} else {
			bool local_14;
			local_14=true;
			CBbsFile local_00;
			local_00.mf_CBbsFile_0080(arg_1->mf_CKey_0260());
			if (local_00.mf_CBbsFile_0010(arg_1)) {
				local_00.mf_CBbsFile_0040(gbuf40000_3,arg_1,arg_3,arg_4,arg_5);
				bool local_15=local_00.mf_CBbsFile_0060(arg_1->m_uint_unk13,gbuf40000_3);
				if (!local_15) {
					local_00.mf_CBbsFile_0070(arg_1);
					if (! ((arg_1->GetRefs())>=1000||!local_00.mf_CBbsFile_0050(arg_1,gbuf40000_3)) ) {
						local_14=false;
					}
				}
			}
			if (strcmp(arg_4,"sage")!=0) {
				time(&arg_1->m_time_);
			}
			arg_1->mf_CKey_0110();
			if (local_01>=0) {
				if (local_14) {
					strcpy(gbuf40000_3,"<BR>投稿に失敗しました。<BR><BR>\n");
					m_hostArray[local_01].mf_CHost_0170(gbuf40000_3,strlen(gbuf40000_3));
				} else {
					strcpy(gbuf40000_3,"<BR>投稿に成功しました。読み込み直してください。<BR><BR>\n");
					m_hostArray[local_01].mf_CHost_0170(gbuf40000_3,strlen(gbuf40000_3));
					ny_binhash2aschash(arg_1->m_hash_tabun,gbuf40000_4);
					strcpy(gbuf40000_3,arg_1->mf_CKey_0260());
					ny_htmlproc_3(gbuf40000_3,local_22);
					sprintf(gbuf40000_3,"<a href=\"%s\">%s</a><br>\n",gbuf40000_4,local_22);
					m_hostArray[local_01].mf_CHost_0170(gbuf40000_3,strlen(gbuf40000_3));
				}
				m_hostArray[local_01].mf_CHost_0190(true);
			} else {
				if (local_14) {
					strcpy(m_szstr_errormsg_,"投稿に失敗しました");
				} else {
					strcpy(m_szstr_errormsg_,"投稿に成功しました");
				}
			}
		}
	} else {
		time_t local_16;
		time(&local_16);
		if (arg_2) {
			sprintf(gbuf40000_3,"%s\t%s\t%u\t%s\n",arg_3,arg_4,local_16,arg_5);
			mf_CMainControl_1360(arg_1,gbuf40000_3);
			(*GetWorkNP(arg_0))->Set_flg_unk200(true);
		} else {
			if (false && arg_1->mf_CKey_0140()) {
			} else {
				bool local_17;
				int local_18;
				local_18=-1;
				mf_CMainControl_0880(arg_1->m_uint_unk13,arg_1->m_hash_tabun,-1,0,&local_17,&local_18,NULLPO);
				if (local_18>=0) {
					(*GetWorkNP(arg_0))->Set_int_unk211(local_18);
				}
			}
		}
		CWork * local_19;
		local_19=m_vectorpCWork_[arg_0];
		local_19->SetCountNow(1);
		local_19->SetCountMax(arg_1->m_uint_unk13);
		local_19->Set_uchar16_unk1(arg_1->m_hash_tabun);
		return true;
	}
	return false;
}


Bb CMainControl::mf_CMainControl_1360(CKey * arg_0,char * arg_1)
{
	char * local_00;
	_in_addr local_01;
	int local_02;
	int local_03;
	int local_04;
	local_00=((struct_wk_0780 *)gbuf20000_hatena01)->data;
	gbuf20000_hatena01[0]=25;
	*((int *)(local_00+4))=arg_0->m_portno_1__;
	ny_addrcrypter(&local_01,arg_0->m_ipaddr_1__);
	memcpy(local_00,&local_01,4);
	memcpy(local_00+8,arg_0->m_hash_tabun,16);
	strcpy(local_00+24,arg_1);
	local_02=-1;
	local_03=0;
	for (local_04=1; local_04<600; local_04++) {
		CHost * local_05;
		local_05=m_hostArray+local_04;
		if (!local_05->m_flgIsValid||!local_05->m_flgIsConnected||local_05->m_flgIsTransferLink_8||!local_05->m_field_8D||!local_05->m_flgIsBBSNode_8||local_05->m_flg_IsBBSPort||local_05->m_int_nodataTimeInSec>=30||local_05->m_int_connectionTimeInSec<=local_03) continue;
		local_03=local_05->m_int_connectionTimeInSec;
		local_02=local_04;
	}
	if (local_02>=0) {
		mf_CMainControl_0370(local_02,gbuf20000_hatena01,strlen(arg_1)+25);
		return true;
	}
	strcpy(m_szstr_errormsg_,"投稿に失敗しました");
	return false;
}



void CMainControl::mf_CMainControl_1370()
{
	m_mapStringInt_.clear();
	if (BbsMakeForm==0) {
		return;
	}
	int local_04;
	local_04=BbsMakeForm->BoardListCombo->Items->Count;
	int local_05;
	for (local_05=0; local_05<local_04; local_05++) {
		AnsiString local_00=(BbsMakeForm->BoardListCombo->Items->Strings[local_05]);
		if (local_00.Length()==0) {
			continue;
		}
		pair<AnsiString,int> local_01(local_00,0);
		m_mapStringInt_.insert(local_01);
	}
	multimap<unsigned int,CKey>::iterator local_06;
	for (local_06=m_KeyBuffer_.begin(); local_06!=m_KeyBuffer_.end(); local_06++) {
		CKey * local_07=&local_06->second;
		if ((local_07->m_int_unk0x==0||!local_07->m_bln_unk308)||!mf_CMainControl_1190(local_07)) continue;
		strcpy(gbuf40000_hatena02,local_07->mf_CKey_0260());
		if (strncmp(gbuf40000_hatena02,"[BBS_",5)!=0) continue;
		char * local_08=gbuf40000_hatena02+5;
		while (!(*local_08==0||(int)*local_08==93)&&(int)*local_08!=60) {
			if (! (!ny_iskanji(*local_08)||*(local_08+1)==0) ) {
				local_08=local_08+2;
			} else {
				local_08=local_08+1;
			}
		}
		*local_08=0;
		int local_09=strlen(&gbuf40000_hatena02[5]);
		if (local_09<=1||local_09>=17||(int)gbuf40000_hatena02[5]==32||(int)gbuf40000_hatena02[5]==95||strncmp(&gbuf40000_hatena02[5],"　",2)==0
		  ||strstr(&gbuf40000_hatena02[5]," ")!=0) continue;
		AnsiString local_02=&gbuf40000_hatena02[5];
		pair<AnsiString,int> local_03(local_02,1);
		m_mapStringInt_.insert(local_03);
	}
	m_flg_unk16402=true;
	return;
}


void CMainControl::mf_CMainControl_1380(int arg_0)
{
	char local_02[4096];
	strcpy(gbuf40000_hatena03,"<head>\n");
	m_hostArray[arg_0].mf_CHost_0170(gbuf40000_hatena03,strlen(gbuf40000_hatena03));
	sprintf(gbuf40000_hatena03,"<title>Winny 板分類一覧</title>\n");
	m_hostArray[arg_0].mf_CHost_0170(gbuf40000_hatena03,strlen(gbuf40000_hatena03));
	sprintf(gbuf40000_hatena03,"<base target=\"main\">\n");
	m_hostArray[arg_0].mf_CHost_0170(gbuf40000_hatena03,strlen(gbuf40000_hatena03));
	strcpy(gbuf40000_hatena03,"</head>\n");
	m_hostArray[arg_0].mf_CHost_0170(gbuf40000_hatena03,strlen(gbuf40000_hatena03));
	strcpy(gbuf40000_hatena03,"<body bgcolor=#efefef text=black link=blue alink=red vlink=#660099>\n");
	m_hostArray[arg_0].mf_CHost_0170(gbuf40000_hatena03,strlen(gbuf40000_hatena03));
	map<AnsiString,int>::iterator local_00;
	for (local_00=m_mapStringInt_.begin(); local_00!=m_mapStringInt_.end(); local_00++) {
		pair<const AnsiString,int> * local_01;
		local_01=&*local_00;
		ny_htmlproc_2(local_01->first.c_str(),gbuf40000_hatena03);
		sprintf(local_02,"/[BBS_%s]/",gbuf40000_hatena03);
		sprintf(gbuf40000_hatena03,"<a href=\"%s\">%s</a> <br>\n",local_02,local_01->first.c_str());
		m_hostArray[arg_0].mf_CHost_0170(gbuf40000_hatena03,strlen(gbuf40000_hatena03));
	}
	return;
}



void CMainControl::mf_CMainControl_1390(int arg_0,char * arg_1)
{
	char local_03[131072];
	CQuery local_00;
	local_00.mf_CQuery_0000(arg_1,"",0);
	local_00.m_flg_unk04=true;
	local_00.m_flg_unk01=false;
	local_00.m_flg_unk02=true;
	local_00.m_flg_unk03=true;
	local_00.m_flg_isBbsQuery__=true;
	multimap<unsigned int,CKey>::iterator local_01;
	for (local_01=m_KeyBuffer_.begin(); local_01!=m_KeyBuffer_.end(); local_01++) {
		CKey * local_02=&local_01->second;
		if (local_02->m_int_unk0x==0||!local_02->m_bln_unk308) continue;
		local_02->m_bln_unk306=false;
		if (!(!(local_02->mf_CKey_0040(arg_1,"",true))) && !(!mf_CMainControl_1190(local_02))&&!local_00.mf_CQuery_0030(local_02,m_hostArray,false,false,200) ) break;
	}
	int tmp=local_00.mf_CQuery_0070(local_03,m_hostArray,m_hostArray+arg_0,m_hostArray[arg_0].m_int_version<10900);
	this->mf_CMainControl_0370(arg_0,local_03,tmp);
	return;
}


void CMainControl::mf_CMainControl_1400(const char * arg_0)
{
	char * local_00;
	int local_01;
	char local_02[1024];

	local_00=local_02+1;
	local_02[0]=17;
	strcpy(local_00,arg_0);
	for (local_01=1; local_01<600; local_01++) {
		if (m_hostArray[local_01].m_flgIsValid
		  &&m_hostArray[local_01].m_flgIsBBSNode_8
		  &&m_hostArray[local_01].m_field_8D
		  &&m_hostArray[local_01].m_flgIsConnected
		  &&m_hostArray[local_01].GetflgIsUpConnection()
		  &&!m_hostArray[local_01].m_flgIsTransferLink_8
		  &&!m_hostArray[local_01].m_flg_IsBBSPort
		  ) {
			mf_CMainControl_0370(local_01,local_02,129);
		}
	}
	return;
}



void CMainControl::mf_CMainControl_1410(int arg_0,char * arg_1)
{
	time_t local_01;
	try {
		time(&local_01);
		strcpy(gbuf40000_hatena04,"<head>\n");
		m_hostArray[arg_0].mf_CHost_0170(gbuf40000_hatena04,strlen(gbuf40000_hatena04));
		sprintf(gbuf40000_hatena04,"<title>%sスレッド一覧</title>\n",arg_1);
		m_hostArray[arg_0].mf_CHost_0170(gbuf40000_hatena04,strlen(gbuf40000_hatena04));
		strcpy(gbuf40000_hatena04,"</head>\n");
		m_hostArray[arg_0].mf_CHost_0170(gbuf40000_hatena04,strlen(gbuf40000_hatena04));
		strcpy(gbuf40000_hatena04,"<body bgcolor=#efefef text=black link=blue alink=red vlink=#660099>\n");
		m_hostArray[arg_0].mf_CHost_0170(gbuf40000_hatena04,strlen(gbuf40000_hatena04));
		bool local_02=strlen(arg_1)>0;
		if (local_02) {
		}
		char local_12[256];
		int local_03;
		local_03=0;
		vector<CBoardSorter> local_00;
		multimap<unsigned int,CKey>::iterator local_04;
		local_00.resize(m_KeyBuffer_.size());
		CBoardSorter local_13;
		for (local_04=m_KeyBuffer_.begin(); local_04!=m_KeyBuffer_.end(); local_04++) {
			CKey * local_05=&local_04->second;
			if (((local_05->m_int_unk0x==0||!local_05->m_bln_unk308)||!(!local_05->m_bln_unk302)&&local_05->m_char_keyType_!=KEYTYPE02)||!mf_CMainControl_1190(local_05)) continue;
			local_05->m_bln_unk306=false;
			if ( (local_02 && !(local_05->mf_CKey_0040(arg_1,"",true)))||strncmp(local_05->mf_CKey_0260(),"[BBS_",5)!=0) continue;
			local_05->m_bln_unk303=false;
			local_05->m_bln_unk304=false;
			unsigned int local_06;
			local_06=0;
			for (local_06=0; m_IgnoreCondition_.size()>local_06; local_06++) {
				CAutoDownList * local_07=&m_IgnoreCondition_[local_06];
				if (!(local_07->m_double_unk9<=0.0)&&(double)local_05->m_uint_unk13*(float)9.5367432e-007>local_07->m_double_unk9||!(local_07->m_double_unk10<=0.0)&&(double)local_05->m_uint_unk13*(float)9.5367432e-007<local_07->m_double_unk10||!(!local_07->m_flag_unk5)&&!local_05->m_bln_unk308||!local_07->m_flag_unk5&&local_05->m_bln_unk308) continue;
				if (local_07->mf_CAutoDownList_0010()) {
					if (memcmp(local_07->m_hash,local_05->m_hash_tabun,16)!=0) continue;
					break;
				}
				if (strlen(local_07->m_char256_unk1)<2||!local_05->mf_CKey_0040(local_07->m_char256_unk1,local_07->m_char256_unk2,true)) continue;
				break;
			}
			if (m_IgnoreCondition_.size()>local_06) continue;
			local_00.push_back(local_13);
			local_00[local_03].m_int_unk4=local_03;
			local_00[local_03].m_int_unk3=5;
			local_00[local_03].m_flag_unk4=false;
			local_00[local_03].m_pCKey=local_05;
			local_03=local_03+1;
		}
		local_00.resize(local_03);
		sort(local_00.begin(),local_00.end());
		if (local_03>1000) {
			local_03=1000;
		}
		int local_08;
		for (local_08=0; local_08<local_03; local_08++) {
			CKey * local_09=local_00[local_08].m_pCKey;
			if (local_09==0) continue;
			char local_14[256];
			char local_15[4096];
			char local_16[64];
			ny_binhash2aschash(local_09->m_hash_tabun,local_12);
			time_t local_10;
			struct_tm * local_11;
			local_10=local_09->m_time_;
			local_11=localtime(&local_10);
			if (local_11==0||local_01+0x0003F480<local_10||local_01-0x5265C00/*+0xFAD9A400*/>local_10) continue;
			sprintf(local_14,"%02d/%02d/%02d %02d:%02d",local_11->tm_year%100,local_11->tm_mon+1,local_11->tm_mday,local_11->tm_hour,local_11->tm_min);
			strcpy(gbuf40000_hatena04,local_09->mf_CKey_0260());
			if ((int)gbuf40000_hatena04[0]==64) continue;
			ny_htmlproc_3(gbuf40000_hatena04,local_15);
			strcpy(local_16,"black");
			sprintf(gbuf40000_hatena04,"<font color=%s>%s</font> <a href=\"%s\">%s</a> [ %6d ] <br>\n",local_16,local_14,local_12,local_15,local_09->GetRefs());
			m_hostArray[arg_0].mf_CHost_0170(gbuf40000_hatena04,strlen(gbuf40000_hatena04));
		}
	}
	catch (std::bad_alloc ex_8) {
	}
	return;
}



bool CMainControl::mf_CMainControl_1420(int arg_0,bool arg_1,char * arg_2,char * arg_3,char * arg_4,unsigned char * arg_5,bool arg_6)
{
	CWork * local_00;
	char local_08[16];

	local_00=m_vectorpCWork_[arg_0];
	int	local_01=local_00->m_hostIdx_;
	if (! (local_01<0||m_hostArray[local_01].m_flgIsConnected) ) {
		m_hostArray[local_01].mf_CHost_0190(true);
		local_00->mf_CWork_0010(true,false);
		if (local_00->m_pchar_status_!=0) {
			strcpy(local_00->m_pchar_status_,"接続切断");
		}
		return false;
	}
	if (local_01>=0) {
		strcpy(gbuf20000_hatena05,"HTTP/1.0 200 OK\r\n");
		m_hostArray[local_01].mf_CHost_0170(gbuf20000_hatena05,strlen(gbuf20000_hatena05));
		strcpy(gbuf20000_hatena05,"Content-type: text/html\r\n\r\n");
		m_hostArray[local_01].mf_CHost_0170(gbuf20000_hatena05,strlen(gbuf20000_hatena05));
	}
	CKey *	local_02=NULLPO;
	multimap<unsigned int,CKey>::iterator local_03;
	for (local_03=m_KeyBuffer_.begin(); local_03!=m_KeyBuffer_.end(); local_03++) {
	CKey * local_04;
		local_04=&local_03->second;
		if ((local_04->m_int_unk0x==0||!local_04->m_bln_unk308)||!(local_04->m_char_keyType_==KEYTYPE00)&&local_04->m_int_unk203!=6
		  ||local_04->memcmp_hash_tabun(arg_5)!=0 ) continue;
		local_02=local_04;
		break;
	}
	if (local_01>=0) {
		strcpy(gbuf20000_hatena05,"<html>\n");
		m_hostArray[local_01].mf_CHost_0170(gbuf20000_hatena05,strlen(gbuf20000_hatena05));
	}

	int local_05;
	local_05=0;
	if (arg_4!=0) {
		local_05=strlen(arg_4);
	}
	if (!(arg_2==0||strlen(arg_2)<=64)) {
		if (local_01>=0) {
			strcpy(gbuf20000_hatena05,"<head>\n");
			m_hostArray[local_01].mf_CHost_0170(gbuf20000_hatena05,strlen(gbuf20000_hatena05));
			strcpy(gbuf20000_hatena05,"<title>Error</title>\n");
			m_hostArray[local_01].mf_CHost_0170(gbuf20000_hatena05,strlen(gbuf20000_hatena05));
			strcpy(gbuf20000_hatena05,"</head>\n");
			m_hostArray[local_01].mf_CHost_0170(gbuf20000_hatena05,strlen(gbuf20000_hatena05));
			strcpy(gbuf20000_hatena05,"<body bgcolor=#efefef text=black link=blue alink=red vlink=#660099>\n");
			m_hostArray[local_01].mf_CHost_0170(gbuf20000_hatena05,strlen(gbuf20000_hatena05));
			strcpy(gbuf20000_hatena05,"<br>名前が長すぎます<br>\n");
			m_hostArray[local_01].mf_CHost_0170(gbuf20000_hatena05,strlen(gbuf20000_hatena05));
		} else {
			strcpy(m_szstr_errormsg_,"名前が長すぎます");
		}
	} else if (!(arg_3==0||strlen(arg_3)<=64)) {
		if (local_01>=0) {
			strcpy(gbuf20000_hatena05,"<head>\n");
			m_hostArray[local_01].mf_CHost_0170(gbuf20000_hatena05,strlen(gbuf20000_hatena05));
			strcpy(gbuf20000_hatena05,"<title>Error</title>\n");
			m_hostArray[local_01].mf_CHost_0170(gbuf20000_hatena05,strlen(gbuf20000_hatena05));
			strcpy(gbuf20000_hatena05,"</head>\n");
			m_hostArray[local_01].mf_CHost_0170(gbuf20000_hatena05,strlen(gbuf20000_hatena05));
			strcpy(gbuf20000_hatena05,"<body bgcolor=#efefef text=black link=blue alink=red vlink=#660099>\n");
			m_hostArray[local_01].mf_CHost_0170(gbuf20000_hatena05,strlen(gbuf20000_hatena05));
			strcpy(gbuf20000_hatena05,"<br>メール欄が長すぎます<br>\n");
			m_hostArray[local_01].mf_CHost_0170(gbuf20000_hatena05,strlen(gbuf20000_hatena05));
		} else {
			strcpy(m_szstr_errormsg_,"メール欄が長すぎます");
		}
	} else if (!(arg_4==0||local_05<=3000)) {
		if (local_01>=0) {
			strcpy(gbuf20000_hatena05,"<head>\n");
			m_hostArray[local_01].mf_CHost_0170(gbuf20000_hatena05,strlen(gbuf20000_hatena05));
			strcpy(gbuf20000_hatena05,"<title>Error</title>\n");
			m_hostArray[local_01].mf_CHost_0170(gbuf20000_hatena05,strlen(gbuf20000_hatena05));
			strcpy(gbuf20000_hatena05,"</head>\n");
			m_hostArray[local_01].mf_CHost_0170(gbuf20000_hatena05,strlen(gbuf20000_hatena05));
			strcpy(gbuf20000_hatena05,"<body bgcolor=#efefef text=black link=blue alink=red vlink=#660099>\n");
			m_hostArray[local_01].mf_CHost_0170(gbuf20000_hatena05,strlen(gbuf20000_hatena05));
			strcpy(gbuf20000_hatena05,"<br>本文が長すぎます<br>\n");
			m_hostArray[local_01].mf_CHost_0170(gbuf20000_hatena05,strlen(gbuf20000_hatena05));
		} else {
			strcpy(m_szstr_errormsg_,"本文が長すぎます");
		}
	} else if (!(arg_4==0||local_05!=0)) {
		if (local_01>=0) {
			strcpy(gbuf20000_hatena05,"<head>\n");
			m_hostArray[local_01].mf_CHost_0170(gbuf20000_hatena05,strlen(gbuf20000_hatena05));
			strcpy(gbuf20000_hatena05,"<title>Error</title>\n");
			m_hostArray[local_01].mf_CHost_0170(gbuf20000_hatena05,strlen(gbuf20000_hatena05));
			strcpy(gbuf20000_hatena05,"</head>\n");
			m_hostArray[local_01].mf_CHost_0170(gbuf20000_hatena05,strlen(gbuf20000_hatena05));
			strcpy(gbuf20000_hatena05,"<body bgcolor=#efefef text=black link=blue alink=red vlink=#660099>\n");
			m_hostArray[local_01].mf_CHost_0170(gbuf20000_hatena05,strlen(gbuf20000_hatena05));
			strcpy(gbuf20000_hatena05,"<br>本文がありません<br>\n");
			m_hostArray[local_01].mf_CHost_0170(gbuf20000_hatena05,strlen(gbuf20000_hatena05));
		} else {
			strcpy(m_szstr_errormsg_,"本文がありません");
		}
	} else {
		int local_06;
		int local_07;
		local_06=0;
		if (arg_4!=0) {
			for (local_07=0; local_05+-3>local_07; local_07++) {
				if (strnicmp(arg_4+local_07,"%0D",3)!=0) continue;
				local_06=local_06+1;
			}
		}
		if (local_06>50) {
			if (local_01>=0) {
				strcpy(gbuf20000_hatena05,"<head>\n");
				m_hostArray[local_01].mf_CHost_0170(gbuf20000_hatena05,strlen(gbuf20000_hatena05));
				strcpy(gbuf20000_hatena05,"<title>Error</title>\n");
				m_hostArray[local_01].mf_CHost_0170(gbuf20000_hatena05,strlen(gbuf20000_hatena05));
				strcpy(gbuf20000_hatena05,"</head>\n");
				m_hostArray[local_01].mf_CHost_0170(gbuf20000_hatena05,strlen(gbuf20000_hatena05));
				strcpy(gbuf20000_hatena05,"<body bgcolor=#efefef text=black link=blue alink=red vlink=#660099>\n");
				m_hostArray[local_01].mf_CHost_0170(gbuf20000_hatena05,strlen(gbuf20000_hatena05));
				strcpy(gbuf20000_hatena05,"<br>改行が多すぎます<br>\n");
				m_hostArray[local_01].mf_CHost_0170(gbuf20000_hatena05,strlen(gbuf20000_hatena05));
			} else {
				strcpy(m_szstr_errormsg_,"改行が多すぎます");
			}
		} else {
			if ( (!(local_02==0||local_02->m_int_unk0x==0)) ) {
				if (mf_CMainControl_1350(arg_0,local_02,arg_1,arg_2,arg_3,arg_4)) {
					return true;
				}
			} else {
				if (local_01>=0) {
					memset(local_08,0,16);
					if (memcmp(arg_5,local_08,16)==0) {
						if (arg_6) {
							mf_CMainControl_1380(local_01);
						} else {
							if (*local_00->m_char256_unk3==0) {
								mf_CMainControl_1540(local_01);
							} else {
								mf_CMainControl_1070(local_00->m_char256_unk3);
								mf_CMainControl_1410(local_01,local_00->m_char256_unk3);
							}
						}
					} else {
						strcpy(gbuf20000_hatena05,"<br>該当するハッシュキーが見つかりません<br>\n");
						m_hostArray[local_01].mf_CHost_0170(gbuf20000_hatena05,strlen(gbuf20000_hatena05));
					}
				} else {
					strcpy(m_szstr_errormsg_,"該当するハッシュキーが見つかりません");
				}
			}
		}
	}
	if (local_01>=0) {
		strcpy(gbuf20000_hatena05,"</body>\n");
		m_hostArray[local_01].mf_CHost_0170(gbuf20000_hatena05,strlen(gbuf20000_hatena05));
		strcpy(gbuf20000_hatena05,"</html>\n\n");
		m_hostArray[local_01].mf_CHost_0170(gbuf20000_hatena05,strlen(gbuf20000_hatena05));
	}
	return false;
}


bool CMainControl::mf_CMainControl_1430(const char * arg_0,char * arg_1,char * arg_2,char * arg_3,unsigned char * arg_4)
{
	bool local_01;
	const char * local_02;
	char * local_03;
	const char * local_04;
	char * local_05;
	const char * local_06;
	char * local_07;
	const char * local_08;
	char dummy[131040];
	char local_09[32];
	unsigned char local_10[16];

	local_01=true;
	memset(arg_4,0,16);
	local_02=strstr(arg_0,"FROM=");
	*arg_1=0;
	local_01=true;
	if (local_02!=0) {
		local_02=local_02+5;
		for (local_03=local_09; !(*local_02==0||(int)*local_02==38)&&local_03-local_09<0x00020000; local_03++) {
			*local_03=*local_02;
			local_02=local_02+1;
		}
		*local_03=0;
		ny_htmlproc_1(local_09,arg_1,false,false);
		if (strlen(arg_1)==0) {
			strcpy(arg_1,"名無しさん");
		}
	} else {
		local_01=false;
	}
	*arg_2=0;
	local_04=strstr(arg_0,"mail=");
	if (local_04!=0) {
		local_04=local_04+5;
		for (local_05=local_09; !(*local_04==0||(int)*local_04==38)&&local_05-local_09<0x00020000; local_05++) {
			*local_05=*local_04;
			local_04=local_04+1;
		}
		*local_05=0;
		ny_htmlproc_1(local_09,arg_2,false,false);
	} else {
		local_01=false;
	}
	*arg_3=0;
	local_06=strstr(arg_0,"MESSAGE=");
	if (local_06!=0) {
		local_06=local_06+8;
		for (local_07=local_09; !(*local_06==0||(int)*local_06==38)&&local_07-local_09<0x00020000; local_07++) {
			*local_07=*local_06;
			local_06=local_06+1;
		}
		*local_07=0;
		ny_htmlproc_1(local_09,arg_3,false,false);
	} else {
		local_01=false;
	}
	local_08=strstr(arg_0,"key=");
	if (local_08!=0) {
		ny_aschash2binhash(local_08+4,arg_4);
	} else {
		local_01=false;
	}
	sprintf(local_09,"%s#%s",arg_1,arg_3);
	MD5calc(local_09,local_10,strlen(local_09));
	local_10[3]=local_10[3]&127;
	if (*arg_2!=0) {
		RSA local_00;
		local_00.mf_RSA_0000(arg_2);
		int tmp=*((int *)local_10);
		CLongInt local_11=_CLongInt_letint(tmp);
		local_00.mf_RSA_0050(local_00.mf_RSA_0030(&local_11),local_09);

		sprintf(arg_2,"%11s#%11s",local_09,local_00.m_szstr);
	}
	return local_01;
}


bool CMainControl::mf_CMainControl_1440(char * arg_0,char * arg_1,char * arg_2)
{
	char * local_01;
	char * local_02;
	int local_03;
	char local_04[65536];
	char local_05[1024];
	char local_06[1024];
	char local_07[65536];
	unsigned char local_08[16];
	char local_09[244];
	char local_10[12];
	local_01=local_04;
	for (local_02=arg_0; *local_02!=0; local_02++) {
		if ((int)*local_02==13) continue;
		*local_01=*local_02;
		local_01=local_01+1;
	}
	*local_01=0;
	local_01=local_06;
	for (local_02=arg_1; *local_02!=0; local_02++) {
		if ((int)*local_02==13) continue;
		*local_01=*local_02;
		local_01=local_01+1;
	}
	*local_01=0;
	local_01=local_05;
	for (local_02=arg_2; *local_02!=0; local_02++) {
		if ((int)*local_02==13) continue;
		*local_01=*local_02;
		local_01=local_01+1;
	}
	*local_01=0;
	RSA local_00;
	if (*arg_2==0) {
		return true;
	}
	if (strlen(arg_2)!=23) {
		return false;
	}
	sprintf(local_07,"%s#%s",arg_1,local_04);
	MD5calc(local_07,local_08,strlen(local_07));
	local_08[3]=local_08[3]&127;
	local_03=*((int *)local_08);
	strcpy(local_10,arg_2);
	local_10[11]=0;
	strcpy(local_00.m_szstr,local_09);
	local_00.mf_RSA_0070();
	CLongInt local_11;
	CLongInt local_12;
	local_00.str2LongInt(local_10,&local_11);
	local_12=_CLongInt_letint(local_03);
	return local_00.mf_RSA_0040(&local_11,&local_12);
}


sl CMainControl::mf_CMainControl_1450(char * arg_0,const char * arg_1,char * arg_2,unsigned char * arg_3)
{
	CKey * local_01;
	char local_03[4096];
	char local_04[4096];
	char local_05[65536];
	unsigned char local_06[16];

	local_01=mf_CMainControl_0180(0,arg_3);
	if (local_01==0) {
		strcpy(m_szstr_errormsg_,"キーが見つかりません");
		return -1;
	}
	if (!mf_CMainControl_1190(local_01)) {
		strcpy(m_szstr_errormsg_,"書き込めないキーです");
		return -1;
	}
	if (*arg_0==0) {
		strcpy(local_03,"名無しさん");
	} else {
		strcpy(local_03,arg_0);
	}
	if (*arg_1!=0) {
		sprintf(local_05,"%s#%s",local_03,arg_2);
		MD5calc(local_05,local_06,strlen(local_05));
		local_06[3]=local_06[3]&127;
		RSA local_00;
		local_00.mf_RSA_0000(arg_1);
		int tmp=*((int *)local_06);
		CLongInt local_07=_CLongInt_letint(tmp);
		local_00.mf_RSA_0050(local_00.mf_RSA_0030(&local_07),local_05);
		sprintf(local_04,"%11s#%11s",local_05,local_00.m_szstr);
	} else {
		local_04[0]=0;
	}
	int	local_02=mf_CMainControl_0610();
	m_vectorpCWork_[local_02]->mf_CWork_0160(-1);
	mf_CMainControl_1420(local_02,true,local_03,local_04,arg_2,arg_3,false);
	return local_02;
}



void CMainControl::mf_CMainControl_1460(int arg_0)
{
	char local_07[131075];
	unsigned char local_08[16];
	char local_09[512];
	char local_10[512];
	char local_11[65536];
	char local_12[65536];
	char local_13[65536];

	CWork *	local_00=m_vectorpCWork_[arg_0];
	if (local_00->m_flgIsFinished_370) return;
	if ((int)local_00->m_uint_countNow>0) {
		mf_CMainControl_1340(arg_0);
		return;
	}

	int	local_01=local_00->m_hostIdx_;
	if (local_01<0||local_01>=600) return;
	local_07[0]=0;
	if (!m_hostArray[local_01].mf_CHost_0140()) return;

	int local_02;
	int local_03;
	bool local_04;
	char * local_05;

	local_02=m_hostArray[local_01].mf_CHost_0130(local_07,0x0001FFFF);
	memset(local_08,0,16);
	if (memcmp(local_07,"GET /",5)==0) {
		if (local_02>5) {
			for (local_03=5; local_03<local_02; local_03++) {
				if ((int)*(local_07+local_03)!=32) continue;
				*(local_07+local_03)=0;
				break;
			}
		}
		local_09[0]=0;
		local_04=false;
		for (local_05=local_07+5; !(*local_05==0)&&(int)*local_05!=47; local_05++) {
		}
		if (*local_05!=0) {
			if (local_05-local_07<256) {
				memcpy(local_09,local_07+5,(local_05-local_07)+-5);
				*((local_10+507)+(local_05-local_07))=0;
			}
			ny_aschash2binhash(local_05+1,local_08);
		} else {
			if (strcmp(&local_07[5],"board.html")==0) {
				local_04=true;
			} else {
				ny_aschash2binhash(&local_07[5],local_08);
			}
		}
		ny_htmlproc_1(local_09,local_10,true,false);
		if (strstr(local_10,"<")!=0) {
			local_10[0]=0;
		}
		strcpy(local_00->m_char256_unk3,local_10);
		if (mf_CMainControl_1420(arg_0,false,NULLPO,NULLPO,NULLPO,local_08,local_04)) return;
	}
	if (memcmp(local_07,"POST /",6)==0) {
		bool local_06;
		local_06=mf_CMainControl_1430(local_07,local_11,local_12,local_13,local_08);
		if (strlen(local_13)!=0) {
			mf_CMainControl_1420(arg_0,local_06,local_11,local_12,local_13,local_08,false);
			return;
		}
		strcpy(local_07,"<br>本文がありません<br>\n");
		m_hostArray[local_01].mf_CHost_0170(local_07,strlen(local_07));
	}
	Sleep(1);
	m_hostArray[local_01].mf_CHost_0190(true);
	local_00->mf_CWork_0010(true,false);
	return;
}


int CMainControl::mf_CMainControl_1470()
{
	int local_00;
	local_00=0;
	multimap<unsigned int,CKey>::iterator local_01;
	for (local_01=m_KeyBuffer_.begin(); local_01!=m_KeyBuffer_.end(); local_01++) {
		CKey * local_02=&local_01->second;
		if (local_02->m_int_unk0x==0||local_02->m_char_keyType_!=KEYTYPE02||!local_02->m_bln_unk308) continue;
		local_00=local_00+1;
	}
	return local_00;
}


void CMainControl::mf_CMainControl_1480(int arg_0,char * arg_1)
{
	char local_00[256];
	sprintf(local_00,"<form method=POST action=\"/\">");
	m_hostArray[arg_0].mf_CHost_0170(local_00,strlen(local_00));
	sprintf(local_00,"<input type=submit value=\"書き込む\" name=submit>");
	m_hostArray[arg_0].mf_CHost_0170(local_00,strlen(local_00));
	sprintf(local_00," 名前<font size=1> (省略可) </font>： <input name=FROM size=19> トリップ<font size=1> (省略可) </font>");
	m_hostArray[arg_0].mf_CHost_0170(local_00,strlen(local_00));
	sprintf(local_00,"： <input name=mail size=19><br><textarea rows=5 cols=80 wrap=off name=MESSAGE></textarea>");
	m_hostArray[arg_0].mf_CHost_0170(local_00,strlen(local_00));
	sprintf(local_00,"<input type=hidden name=key value=%s>",arg_1);
	m_hostArray[arg_0].mf_CHost_0170(local_00,strlen(local_00));
	sprintf(local_00,"</form>");
	m_hostArray[arg_0].mf_CHost_0170(local_00,strlen(local_00));
	return;
}


void CMainControl::mf_CMainControl_1490(int arg_0,int arg_1,char * arg_2,char * arg_3,char * arg_4)
{
	CKey * local_00;
	char * local_01;
	int local_02;
	char * local_03;
	CHost * local_04;
	char local_06[256];

	local_00=this->mf_CMainControl_0180(0,(unsigned char *)arg_3);
	if (! (local_00==0||local_00->m_char_keyType_!=KEYTYPE02) ) {
		local_01=local_06+1;
		local_06[0]=26;
		memcpy(local_01,arg_3,16);
		*((int *)(local_01+16))=!(mf_CMainControl_1520(arg_3,arg_4)==0)?1:0;
		mf_CMainControl_0370(arg_0,local_06,21);
		return;
	}
	local_02=0;
	local_02=this->mf_CMainControl_0560((_in_addr *)arg_2,arg_1);
	m_hostArray[local_02].m_flgIsValid=true;
	local_03=arg_2;
	local_04=m_hostArray+local_02;
	*((char *)(&local_04->m_ipaddr3.b1))=*local_03;
	*((char *)(&local_04->m_ipaddr3.b2))=*(local_03+1);
	*((char *)(&local_04->m_ipaddr3.b3))=*(local_03+2);
	*((char *)(&local_04->m_ipaddr3.b4))=*(local_03+3);
	m_hostArray[local_02].SetPort(arg_1);
	int	local_05=mf_CMainControl_0610();
	m_hostArray[local_02].m_flgIsBBSNode_8=true;
	m_hostArray[local_02].m_flgIsTransferLink_8=true;
	mf_CMainControl_0260(local_02,false);
	m_vectorpCWork_[local_05]->mf_CWork_0080(local_02,arg_0,arg_3,arg_4);
	return;
}


void CMainControl::mf_CMainControl_1500(int arg_0,char * arg_1,bool arg_2)
{
	int local_00;
	local_00=m_vectorpCWork_.size();
	for (int local_01=0; local_01<local_00; local_01++) {
		if (/**/(*GetWorkNP(local_01))->GetWorkType()!=WORKTYPE08
		  ||memcmp(/**/(*GetWorkNP(local_01))->Get_uchar16_unk1(),arg_1,16)!=0) continue;
		/**/(*GetWorkNP(local_01))->Set_flg_unk201(true);
		/**/(*GetWorkNP(local_01))->Set_flg_unk202(arg_2);
	}
	return;
}


void CMainControl::mf_CMainControl_1510(int arg_0,char * arg_1,bool arg_2)
{
	int local_00;
	char local_03[256];

	local_00=m_vectorpCWork_.size();
	for (int local_01=0; local_01<local_00; local_01++) {
		if (/**/(*GetWorkNP(local_01))->GetWorkType()!=WORKTYPE09
		  ||memcmp(/**/(*GetWorkNP(local_01))->Get_uchar16_unk1(),arg_1,16)!=0) continue;
		char * local_02=local_03+1;
		local_03[0]=26;
		memcpy(local_02,arg_1,16);
		*((int *)(local_02+16))=(unsigned int)arg_2;
		mf_CMainControl_0370(/**/(*GetWorkNP(local_01))->Get_hostIdx_mouikko_(),local_03,21);
		if (/**/(*GetWorkNP(local_01))->GetHostIdx()>=0) {
			m_hostArray[/**/(*GetWorkNP(local_01))->GetHostIdx()].mf_CHost_0190(true);
		}
		/**/(*GetWorkNP(local_01))->Set_flg_unk201(true);
		/**/(*GetWorkNP(local_01))->Set_flg_unk202(arg_2);
		break;
	}
	return;
}


char CMainControl::mf_CMainControl_1520(char * arg_0,char * arg_1)
{
	bool local_01;
	CKey * local_02;
	local_01=false;
	local_02=NULLPO;
	multimap<unsigned int,CKey>::iterator local_03;

	for (local_03=m_KeyBuffer_.begin(); (char)(local_03!=m_KeyBuffer_.end())!=0; local_03++) {
		CKey * local_04=&local_03->second;
		if ((local_04->m_int_unk0x==0||!local_04->m_bln_unk308)
		  ||local_04->memcmp_hash_tabun(arg_0)!=0) continue;
		local_02=local_04;
		break;
	}
	if (! ((local_02==0||!local_02->m_bln_unk308)||strlen(arg_1)+local_02->m_uint_unk13>=0x00100000||local_02->m_char_keyType_!=KEYTYPE02) ) {
		CBbsFile local_00;
		local_00.mf_CBbsFile_0080(local_02->mf_CKey_0260());
		if (!local_00.mf_CBbsFile_0010(local_02)) {
			return 0;
		}
		bool local_05=local_00.mf_CBbsFile_0060(local_02->m_uint_unk13,arg_1);
		if (local_05) {
			return 0;
		}
		local_00.mf_CBbsFile_0070(local_02);
		if ((local_02->GetRefs())>=1000) {
			return 0;
		}
		if (!local_00.mf_CBbsFile_0050(local_02,arg_1)) {
			return 0;
		}
		char * local_06;
		for (local_06=arg_1; !(*local_06==0)&&(int)*local_06!=9; local_06++) {
		}
		if (! (!(*local_06==0)&&strncmp(local_06+1,"sage\t",5)==0) ) {
			time(&local_02->m_time_);
		}
		local_01=true;
		local_00.mf_CBbsFile_0070(local_02);
		local_02->mf_CKey_0110();
	}
	return local_01;
}


void CMainControl::mf_CMainControl_1530(int arg_0)
{
	char local_06[256];
	CWork *	local_00=m_vectorpCWork_[arg_0];
	int	local_01=local_00->m_hostIdx_mouikko_;
	if (! (!(local_01<0||!m_hostArray[local_01].m_flgIsValid)&&m_hostArray[local_01].m_flgIsConnected) ) {
		local_00->mf_CWork_0010(true,false);
		return;
	}
	if (local_00->m_flgkasiraso_) {
	int local_02=local_00->m_hostIdx_;
		if (! (local_02<0||!m_hostArray[local_02].m_flgIsValid||!m_hostArray[local_02].m_flgIsConnected) ) {
			local_00->m_flgkasiraso_=false;
			local_00->m_int_unk304=1;
		}
		return;
	}
	if (!local_00->m_flg_unk201) {
		int local_03=local_00->m_hostIdx_;
		if (! (!(local_03<0||!m_hostArray[local_03].m_flgIsValid)&&m_hostArray[local_03].m_flgIsConnected) ) {
			local_00->mf_CWork_0010(false,true);
			if (! (!m_hostArray[local_03].m_flgIsValid||!m_hostArray[local_03].m_field_7E) ) {
				local_00->m_int_errorcode_kamo_=11;
				return;
			}
			if (m_hostArray[local_03].m_field_8C) {
				local_00->m_int_errorcode_kamo_=15;
				return;
			}
			local_00->m_int_errorcode_kamo_=4;
		} else {
			if (m_hostArray[local_03].m_flgUnknown_80) {
				char * local_04;
				local_04=((struct_wk_0780 *)gbuf20000_hatena06)->data;
				gbuf20000_hatena06[0]=24;
				memcpy(local_04,local_00->m_uchar16_unk1,16);
				strcpy(local_04+16,local_00->m_pchar_unk);
				mf_CMainControl_0370(local_03,gbuf20000_hatena06,strlen(local_00->m_pchar_unk)+17);
				local_00->m_flg_unk201=true;
				local_00->m_flg_unk202=true;
			}
		}
		return;
	}

	unsigned char * local_05;
	local_05=(unsigned char *)(local_06+1);
	local_06[0]=26;
	memcpy(local_05,local_00->m_uchar16_unk1,16);
	*((int *)(local_05+16))=(unsigned int)local_00->m_flg_unk202;
	mf_CMainControl_0370(local_00->m_hostIdx_mouikko_,local_06,21);
	return;
}


void CMainControl::mf_CMainControl_1540(int arg_0)
{
	char local_00[4096];
	sprintf(local_00,"<html>\n");
	m_hostArray[arg_0].mf_CHost_0170(local_00,strlen(local_00));
	sprintf(local_00,"<head>\n");
	m_hostArray[arg_0].mf_CHost_0170(local_00,strlen(local_00));
	sprintf(local_00,"<title>Winny BBS</title>\n");
	m_hostArray[arg_0].mf_CHost_0170(local_00,strlen(local_00));
	sprintf(local_00,"</head>\n");
	m_hostArray[arg_0].mf_CHost_0170(local_00,strlen(local_00));
	sprintf(local_00,"<frameset cols=\"150,*\">\n");
	m_hostArray[arg_0].mf_CHost_0170(local_00,strlen(local_00));
	sprintf(local_00,"<frame name=\"board\" target=\"main\" src=\"board.html\">\n");
	m_hostArray[arg_0].mf_CHost_0170(local_00,strlen(local_00));
	sprintf(local_00,"<frame name=\"main\" src=\"\">\n");
	m_hostArray[arg_0].mf_CHost_0170(local_00,strlen(local_00));
	sprintf(local_00,"</frameset>\n");
	m_hostArray[arg_0].mf_CHost_0170(local_00,strlen(local_00));
	sprintf(local_00,"</html>\n");
	m_hostArray[arg_0].mf_CHost_0170(local_00,strlen(local_00));
	return;
}


void CMainControl::mf_CMainControl_1560(int arg_0)
{
	CWork * local_00;
	local_00=m_vectorpCWork_[arg_0];
	if (local_00->m_flgIsFinished_370||local_00->m_worktype_!=WORKTYPE10) return;
	int	local_01=local_00->m_hostIdx_;
	if (local_01>=0) {
		CHost * local_02=m_hostArray+local_01;
		if (! (!local_02->m_flgIsBBSConnectionTest||local_02->m_int_nodataTimeInSec<=3) ) {
			local_02->mf_CHost_0190(true);
			m_flgarray_unk[0]=true;
		} else {
			if (!(!local_02->m_flgIsBBSConnectionTest)&&!local_02->m_flgIsConnected) return;
		}
		m_flgarray_unk[0]=true;
		if (! (!local_02->m_flgIsBBSConnectionTest||!local_02->m_flgIsConnected) ) {
			local_02->mf_CHost_0190(true);
			local_00->mf_CWork_0010(true,false);
			m_flgarray_unk[0]=true;
			mf_CMainControl_1040(local_01,NULLPO);
			return;
		}
	}
	if (m_vectorCHostSorter_.size()<=local_00->m_uint_countNow) {
		local_00->mf_CWork_0010(true,false);
		return;
	}
	local_01=-1;
	while (true) {
		local_01=m_vectorCHostSorter_[local_00->m_uint_countNow].m_int_unk00;
		if (! (!(m_vectorCHostSorter_.size()<=local_00->m_uint_countNow)&&(int)local_00->m_uint_countNow<=50) ) {
			local_00->mf_CWork_0010(true,false);
			return;
		}
		if (!(!m_hostArray[local_01].m_flgIsValid||!m_hostArray[local_01].m_flgIsBBSConnectionTest&&m_hostArray[local_01].m_port2==0)&&(!(m_hostArray[local_01].m_flgIsConnected||m_hostArray[local_01].m_flgIsPortZero_9)&&!m_hostArray[local_01].m_flgIsBadPortZero_9)) break;
		local_00->m_uint_countNow=local_00->m_uint_countNow+1;
	}
	local_00->m_tick_created_kamo_=GetTickCount();
	local_00->SetHostIdx(local_01);
	m_hostArray[local_01].m_int_preference2_negative=m_hostArray[local_01].m_int_preference2_negative+1;
	mf_CMainControl_0260(local_01,true);
	return;
}


void CMainControl::mf_CMainControl_1570()
{
	int local_02;
	xint local_03;
	char local_04[4096];
	struct__finddata_t local_05;
	AnsiString local_00;
	AnsiString local_01;

	sprintf(local_04,"%s\\*.*",m_sz_CacheFolderPath_);
	local_03=0;
	if ( (local_02=_findfirst(local_04,&local_05)) >=0) {
		_findclose(local_02);
		local_03=1;
	}
	if (local_03==0) {
		sprintf(local_04,"指定されたキャッシュフォルダ(%s)が見当たりません。生成しますか？",m_sz_CacheFolderPath_);
		if (! (MessageBox(m_hwnd_unk32,local_04,"Winny",0x00042024)!=6||mkdir(m_sz_CacheFolderPath_)!=0) ) {
			local_03=1;
		}
	}
	if (local_03==0) {
		MessageBox(m_hwnd_unk32,"キャッシュフォルダの生成に失敗しました","Winny",0x00042030);
	}
	sprintf(local_04,"%s\\*.*",m_sz_DownFolderPath_);
	local_03=0;
	if ((local_02=_findfirst(local_04,&local_05))>=0) {
		_findclose(local_02);
		local_03=1;
	}
	if (local_03==0) {
		sprintf(local_04,"指定されたダウンフォルダ(%s)が見当たりません。生成しますか？",m_sz_DownFolderPath_);
		if (! (MessageBox(m_hwnd_unk32,local_04,"Winny",0x00042024)!=6||mkdir(m_sz_DownFolderPath_)!=0) ) {
			local_03=1;
		}
	}
	if (local_03==0) {
		MessageBox(m_hwnd_unk32,"ダウンフォルダの生成に失敗しました","Winny",0x00042030);
	}
	sprintf(local_04,"%s\\*.*",m_sz_BbsFolderPath_);
	local_03=0;
	if ((local_02=_findfirst(local_04,&local_05))>=0) {
		_findclose(local_02);
		local_03=1;
	}
	if (local_03==0) {
		sprintf(local_04,"指定されたBBSフォルダ(%s)が見当たりません。生成しますか？",m_sz_BbsFolderPath_);
		if (! (MessageBox(m_hwnd_unk32,local_04,"Winny",0x00042024)!=6||mkdir(m_sz_BbsFolderPath_)!=0) ) {
			local_03=1;
		}
	}
	if (local_03==0) {
		MessageBox(m_hwnd_unk32,"BBSフォルダの生成に失敗しました","Winny",0x00042030);
	}
	return;
}


bool CMainControl::mf_CMainControl_1580(CWork * arg_0,char * arg_1)
{
	bool local_00;
	local_00=true;
	*arg_1=0;
	if (arg_0->m_int_errorcode_kamo_==0) {
		if (arg_0->m_flgkasiraso_3) {
			sprintf(arg_1,"ファイルチェック正常終了");
		} else {
			sprintf(arg_1,"ファイル変換正常終了");
		}
	} else {
		if (arg_0->m_int_errorcode_kamo_==1) {
			sprintf(arg_1,"ファイル破損エラー検出");
		} else {
			if (arg_0->m_int_errorcode_kamo_==2) {
				sprintf(arg_1,"ユーザキャンセル");
			} else {
				if (arg_0->m_int_errorcode_kamo_==3) {
					sprintf(arg_1,"接続タイムアウトエラー");
				} else {
					if (arg_0->m_int_errorcode_kamo_==4) {
						sprintf(arg_1,"キーロストによる切断エラー");
					} else {
						if (arg_0->m_int_errorcode_kamo_==5) {
							sprintf(arg_1,"アップ中接続断エラー");
						} else {
							if (arg_0->m_int_errorcode_kamo_==6) {
								sprintf(arg_1,"ブロック受信中接続断エラー");
							} else {
								if (arg_0->m_int_errorcode_kamo_==7) {
									sprintf(arg_1,"不正ブロック位置受信エラー");
								} else {
									if (arg_0->m_int_errorcode_kamo_==8) {
										sprintf(arg_1,"不正キーエラー");
									} else {
										if (arg_0->m_int_errorcode_kamo_==9) {
											sprintf(arg_1,"アップファイルオープンエラー");
										} else {
											if (arg_0->m_int_errorcode_kamo_==10) {
												sprintf(arg_1,"キャッシュファイルオープンエラー");
											} else {
												if (arg_0->m_int_errorcode_kamo_==11) {
													sprintf(arg_1,"コネクション数限界エラー");
												} else {
													if (arg_0->m_int_errorcode_kamo_==12) {
														sprintf(arg_1,"全体ハッシュ不整合エラー");
													} else {
														if (arg_0->m_int_errorcode_kamo_==13) {
															sprintf(arg_1,"キャッシュファイル書き込みエラー");
														} else {
															if (arg_0->m_int_errorcode_kamo_==14) {
																sprintf(arg_1,"ダウンファイル書き込みエラー");
															} else {
																if (arg_0->m_int_errorcode_kamo_==15) {
																	sprintf(arg_1,"接続ノードロストエラー");
																} else {
																	local_00=false;
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
						}
					}
				}
			}
		}
	}
	return local_00;
}


void CMainControl::mf_CMainControl_1590(int arg_0)
{
	char local_00[256];
	switch (arg_0) {
	case 10093:  
		ny_addlog("WSANOTINITIALISED: A successful WSAStartup call must occur before using this function. ");
		break;
	case 10036:  
		ny_addlog("WSAEINPROGRESS: A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. ");
		break;
	case 10038:  
		ny_addlog("WSAENOTSOCK: The descriptor is not a socket. ");
		break;
	case 10047:  
		ny_addlog("WSAEAFNOSUPPORT: Addresses in the specified family cannot be used with this socket.");
		break;
	case 10061:  
		ny_addlog("WSAECONNREFUSED: The attempt to connect was forcefully rejected. ");
		break;
	case 10051:  
		ny_addlog("WSAENETUNREACH: The network cannot be reached from this host at this time. ");
		break;
	case 10014:  
		ny_addlog("WSAEFAULT: The namelen parameter is incorrect. ");
		break;
	case 10022:  
		ny_addlog("WSAEINVAL: The socket is already bound to an address. ");
		break;
	case 10056:  
		ny_addlog("WSAEISCONN: The socket is already connected. ");
		break;
	case 10024:  
		ny_addlog("WSAEMFILE: No more file descriptors are available. ");
		break;
	case 10055:  
		ny_addlog("WSAENOBUFS: No buffer space is available. The socket cannot be connected. ");
		break;
	case 10057:  
		ny_addlog("WSAENOTCONN: The socket is not connected. ");
		break;
	case 10060:  
		ny_addlog("WSAETIMEDOUT: Attempt to connect timed out without establishing a connection. ");
		break;
	case 10050:  
		ny_addlog("WSAENETDOWN: The network subsystem has failed. ");
		break;
	default:
		sprintf(local_00,"errno: %d",arg_0);
		ny_addlog(local_00);
	}
	return;
}


void CMainControl::mf_CMainControl_1600(int arg_0)
{
	char local_00[256];
	switch (arg_0) {
	case 10093:  
		ny_addlog("WSANOTINITIALISED: A successful WSAStartup call must occur before using this function. ");
		break;
	case 10050:  
		ny_addlog("WSAENETDOWN: The network subsystem has failed. ");
		break;
	case 10048:  
		ny_addlog("WSAEADDRINUSE: The socket's local address is already in use and the socket was not marked to allow address reuse with SO_REUSEADDR. This error usually occurs when executing bind, but could be delayed until this function if the bind was to a partially wildcard address (involving ADDR_ANY) and if a specific address needs to be committed at the time of this function. ");
		break;
	case 10004:  
		ny_addlog("WSAEINTR: The blocking Windows Socket 1.1 call was canceled through WSACancelBlockingCall. ");
		break;
	case 10036:  
		ny_addlog("WSAEINPROGRESS: A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. ");
		break;
	case 10037:  
		ny_addlog("WSAEALREADY: A nonblocking connect call is in progress on the specified socket. ");
		break;
	case 10049:  
		ny_addlog("WSAEADDRNOTAVAIL: The remote address is not a valid address (such as ADDR_ANY). ");
		break;
	case 10047:  
		ny_addlog("WSAEAFNOSUPPORT: Addresses in the specified family cannot be used with this socket. ");
		break;
	case 10061:  
		ny_addlog("WSAECONNREFUSED: The attempt to connect was forcefully rejected. ");
		break;
	case 10014:  
		ny_addlog("WSAEFAULT: The name or the namelen parameter is not a valid part of the user address space, the namelen parameter is too small, or the name parameter contains incorrect address format for the associated address family. ");
		break;
	case 10022:  
		ny_addlog("WSAEINVAL: The parameter s is a listening socket. ");
		break;
	case 10056:  
		ny_addlog("WSAEISCONN: The socket is already connected (connection-oriented sockets only). ");
		break;
	case 10051:  
		ny_addlog("WSAENETUNREACH: The network cannot be reached from this host at this time. ");
		break;
	case 10055:  
		ny_addlog("WSAENOBUFS: No buffer space is available. The socket cannot be connected. ");
		break;
	case 10038:  
		ny_addlog("WSAENOTSOCK: The descriptor is not a socket. ");
		break;
	case 10060:  
		ny_addlog("WSAETIMEDOUT: Attempt to connect timed out without establishing a connection. ");
		break;
	case 10035:  
		ny_addlog("WSAEWOULDBLOCK: The socket is marked as nonblocking and the connection cannot be completed immediately. ");
		break;
	case 10013:  
		ny_addlog("WSAEACCES: Attempt to connect datagram socket to broadcast address failed because setsockopt option SO_BROADCAST is not enabled. ");
		break;
	default:
		sprintf(local_00,"errno: %d",arg_0);
		ny_addlog(local_00);
	}
	return;
}


void CMainControl::mf_CMainControl_1610(int arg_0)
{
	char local_00[256];
	switch (arg_0) {
	case 10093:  
		ny_addlog("WSANOTINITIALISED: A successful WSAStartup call must occur before using this function.");
		break;
	case 10050:  
		ny_addlog("WSAENETDOWN: The network subsystem has failed. ");
		break;
	case 10014:  
		ny_addlog("WSAEFAULT: The addrlen parameter is too small or addr is not a valid part of the user address space. ");
		break;
	case 10004:  
		ny_addlog("WSAEINTR: A blocking Windows Sockets 1.1 call was canceled through WSACancelBlockingCall. ");
		break;
	case 10036:  
		ny_addlog("WSAEINPROGRESS: A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. ");
		break;
	case 10022:  
		ny_addlog("WSAEINVAL: The listen function was not invoked prior to accept. ");
		break;
	case 10024:  
		ny_addlog("WSAEMFILE: The queue is nonempty upon entry to accept and there are no descriptors available. ");
		break;
	case 10055:  
		ny_addlog("WSAENOBUFS: No buffer space is available. ");
		break;
	case 10038:  
		ny_addlog("WSAENOTSOCK: The descriptor is not a socket. ");
		break;
	case 10045:  
		ny_addlog("WSAEOPNOTSUPP: The referenced socket is not a type that supports connection-oriented service. ");
		break;
	case 10035:  
		ny_addlog("WSAEWOULDBLOCK: The socket is marked as nonblocking and no connections are present to be accepted. ");
		break;
	default:
		sprintf(local_00,"errno: %d",arg_0);
		ny_addlog(local_00);
	}
	return;
}


void CMainControl::mf_CMainControl_1620(int arg_0)
{
	char local_00[256];
	switch (arg_0) {
	case 10093:  
		ny_addlog("WSANOTINITIALISED: A successful WSAStartup call must occur before using this function. ");
		break;
	case 10050:  
		ny_addlog("WSAENETDOWN: The network subsystem has failed. ");
		break;
	case 10048:  
		ny_addlog("WSAEADDRINUSE: A process on the machine is already bound to the same fully-qualified address and the socket has not been marked to allow address reuse with SO_REUSEADDR. For example, the IP address and port are bound in the af_inet case). (See the SO_REUSEADDR socket option under setsockopt.) ");
		break;
	case 10049:  
		ny_addlog("WSAEADDRNOTAVAIL: The specified address is not a valid address for this machine. ");
		break;
	case 10014:  
		ny_addlog("WSAEFAULT: The name or namelen parameter is not a valid part of the user address space, the namelen parameter is too small, the name parameter contains an incorrect address format for the associated address family, or the first two bytes of the memory block specified by name does not match the address family associated with the socket descriptor s. ");
		break;
	case 10036:  
		ny_addlog("WSAEINPROGRESS: A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. ");
		break;
	case 10022:  
		ny_addlog("WSAEINVAL: The socket is already bound to an address. ");
		break;
	case 10055:  
		ny_addlog("WSAENOBUFS: Not enough buffers available, too many connections. ");
		break;
	case 10038:  
		ny_addlog("WSAENOTSOCK: The descriptor is not a socket. ");
		break;
	default:
		sprintf(local_00,"errno: %d",arg_0);
		ny_addlog(local_00);
	}
	return;
}


void CMainControl::mf_CMainControl_1630(int arg_0)
{
	char local_00[256];
	switch (arg_0) {
	case 10093:  
		ny_addlog("WSANOTINITIALISED: A successful WSAStartup call must occur before using this function. ");
		break;
	case 10050:  
		ny_addlog("WSAENETDOWN: The network subsystem has failed. ");
		break;
	case 10048:  
		ny_addlog("WSAEADDRINUSE: The socket's local address is already in use and the socket was not marked to allow address reuse with SO_REUSEADDR. This error usually occurs during execution of the bind function, but could be delayed until this function if the bind was to a partially wildcard address (involving ADDR_ANY) and if a specific address needs to be committed at the time of this function. ");
		break;
	case 10036:  
		ny_addlog("WSAEINPROGRESS: A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. ");
		break;
	case 10022:  
		ny_addlog("WSAEINVAL: The socket has not been bound with bind. ");
		break;
	case 10056:  
		ny_addlog("WSAEISCONN: The socket is already connected. ");
		break;
	case 10024:  
		ny_addlog("WSAEMFILE: No more socket descriptors are available. ");
		break;
	case 10055:  
		ny_addlog("WSAENOBUFS: No buffer space is available. ");
		break;
	case 10038:  
		ny_addlog("WSAENOTSOCK: The descriptor is not a socket. ");
		break;
	case 10045:  
		ny_addlog("WSAEOPNOTSUPP: The referenced socket is not of a type that supports the listen operation. ");
		break;
	default:
		sprintf(local_00,"errno: %d",arg_0);
		ny_addlog(local_00);
	}
	return;
}


void CMainControl::mf_CMainControl_1640(int arg_0)
{
	char local_00[256];
	switch (arg_0) {
	case 10093:  
		ny_addlog("WSANOTINITIALISED: A successful WSAStartup call must occur before using this function. ");
		break;
	case 10050:  
		ny_addlog("WSAENETDOWN: The network subsystem has failed. ");
		break;
	case 10014:  
		ny_addlog("WSAEFAULT: The buf parameter is not completely contained in a valid part of the user address space. ");
		break;
	case 10057:  
		ny_addlog("WSAENOTCONN: The socket is not connected. ");
		break;
	case 10004:  
		ny_addlog("WSAEINTR: The (blocking) call was canceled through WSACancelBlockingCall. ");
		break;
	case 10036:  
		ny_addlog("WSAEINPROGRESS: A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. ");
		break;
	case 10052:  
		ny_addlog("WSAENETRESET: The connection has been broken due to the keep-alive activity detecting a failure while the operation was in progress. ");
		break;
	case 10038:  
		ny_addlog("WSAENOTSOCK: The descriptor is not a socket. ");
		break;
	case 10045:  
		ny_addlog("WSAEOPNOTSUPP: MSG_OOB was specified, but the socket is not stream-style such as type SOCK_STREAM, OOB data is not supported in the communication domain associated with this socket, or the socket is unidirectional and supports only send operations. ");
		break;
	case 10058:  
		ny_addlog("WSAESHUTDOWN: The socket has been shut down; it is not possible to receive on a socket after shutdown has been invoked with how set to SD_RECEIVE or SD_BOTH. ");
		break;
	case 10035:  
		ny_addlog("WSAEWOULDBLOCK: The socket is marked as nonblocking and the receive operation would block. ");
		break;
	case 10040:  
		ny_addlog("WSAEMSGSIZE: The message was too large to fit into the specified buffer and was truncated. ");
		break;
	case 10022:  
		ny_addlog("WSAEINVAL: The socket has not been bound with bind, or an unknown flag was specified, or MSG_OOB was specified for a socket with SO_OOBINLINE enabled or (for byte stream sockets only) len was zero or negative. ");
		break;
	case 10053:  
		ny_addlog("WSAECONNABORTED: The virtual circuit was terminated due to a time-out or other failure. The application should close the socket as it is no longer usable. ");
		break;
	case 10060:  
		ny_addlog("WSAETIMEDOUT: The connection has been dropped because of a network failure or because the peer system failed to respond. ");
		break;
	case 10054:  
		ny_addlog("WSAECONNRESET: The virtual circuit was reset by the remote side executing a hard or abortive close. The application should close the socket as it is no longer usable. On a UPD-datagram socket this error would indicate that a previous send operation resulted in an ICMP Port Unreachable message. ");
		break;
	default:
		sprintf(local_00,"errno: %d",arg_0);
		ny_addlog(local_00);
	}
	return;
}


void CMainControl::mf_CMainControl_1650(int arg_0)
{
	char local_00[256];
	switch (arg_0) {
	case 10093:  
		ny_addlog("WSANOTINITIALISED: A successful WSAStartup call must occur before using this function. ");
		break;
	case 10050:  
		ny_addlog("WSAENETDOWN: The network subsystem has failed. ");
		break;
	case 10013:  
		ny_addlog("WSAEACCES: The requested address is a broadcast address, but the appropriate flag was not set. Call setsockopt with the SO_BROADCAST parameter to allow the use of the broadcast address. ");
		break;
	case 10004:  
		ny_addlog("WSAEINTR: A blocking Windows Sockets 1.1 call was canceled through WSACancelBlockingCall. ");
		break;
	case 10036:  
		ny_addlog("WSAEINPROGRESS: A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. ");
		break;
	case 10014:  
		ny_addlog("WSAEFAULT: The buf parameter is not completely contained in a valid part of the user address space. ");
		break;
	case 10052:  
		ny_addlog("WSAENETRESET: The connection has been broken due to the keep-alive activity detecting a failure while the operation was in progress. ");
		break;
	case 10055:  
		ny_addlog("WSAENOBUFS: No buffer space is available. ");
		break;
	case 10057:  
		ny_addlog("WSAENOTCONN: The socket is not connected. ");
		break;
	case 10038:  
		ny_addlog("WSAENOTSOCK: The descriptor is not a socket. ");
		break;
	case 10045:  
		ny_addlog("WSAEOPNOTSUPP: MSG_OOB was specified, but the socket is not stream-style such as type SOCK_STREAM, OOB data is not supported in the communication domain associated with this socket, or the socket is unidirectional and supports only receive operations. ");
		break;
	case 10058:  
		ny_addlog("WSAESHUTDOWN: The socket has been shut down; it is not possible to send on a socket after shutdown has been invoked with how set to SD_SEND or SD_BOTH. ");
		break;
	case 10035:  
		ny_addlog("WSAEWOULDBLOCK: The socket is marked as nonblocking and the requested operation would block. ");
		break;
	case 10040:  
		ny_addlog("WSAEMSGSIZE: The socket is message oriented, and the message is larger than the maximum supported by the underlying transport. ");
		break;
	case 10065:  
		ny_addlog("WSAEHOSTUNREACH: The remote host cannot be reached from this host at this time. ");
		break;
	case 10022:  
		ny_addlog("WSAEINVAL: The socket has not been bound with bind, or an unknown flag was specified, or MSG_OOB was specified for a socket with SO_OOBINLINE enabled. ");
		break;
	case 10053:  
		ny_addlog("WSAECONNABORTED: The virtual circuit was terminated due to a time-out or other failure. The application should close the socket as it is no longer usable. ");
		break;
	case 10054:  
		ny_addlog("WSAECONNRESET: The virtual circuit was reset by the remote side executing a hard or abortive close. For UPD sockets, the remote host was unable to deliver a previously sent UDP datagram and responded with a Port Unreachable ICMP packet. The application should close the socket as it is no longer usable. ");
		break;
	case 10060:  
		ny_addlog("WSAETIMEDOUT: The connection has been dropped, because of a network failure or because the system on the other end went down without notice. ");
		break;
	default:
		sprintf(local_00,"errno: %d",arg_0);
		ny_addlog(local_00);
	}
	return;
}


void CMainControl::mf_CMainControl_1660(int arg_0)
{
	char local_00[256];
	switch (arg_0) {
	case 10093:  
		ny_addlog("WSANOTINITIALISED: A successful WSAStartup call must occur before using this function. ");
		break;
	case 10050:  
		ny_addlog("WSAENETDOWN: The network subsystem or the associated service provider has failed. ");
		break;
	case 10047:  
		ny_addlog("WSAEAFNOSUPPORT: The specified address family is not supported. ");
		break;
	case 10036:  
		ny_addlog("WSAEINPROGRESS: A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. ");
		break;
	case 10024:  
		ny_addlog("WSAEMFILE: No more socket descriptors are available. ");
		break;
	case 10055:  
		ny_addlog("WSAENOBUFS: No buffer space is available. The socket cannot be created. ");
		break;
	case 10043:  
		ny_addlog("WSAEPROTONOSUPPORT: The specified protocol is not supported. ");
		break;
	case 10041:  
		ny_addlog("WSAEPROTOTYPE: The specified protocol is the wrong type for this socket. ");
		break;
	case 10044:  
		ny_addlog("WSAESOCKTNOSUPPORT: The specified socket type is not supported in this address family. ");
		break;
	default:
		sprintf(local_00,"errno: %d",arg_0);
		ny_addlog(local_00);
	}
	return;
}



