#ifndef _CMAINCONTROL_H_INCLUDED
#define _CMAINCONTROL_H_INCLUDED

#include "CQuery.h"
#include "CRC4.h"
#include "CWork.h"
#include "CKey.h"
#include "CAutoDownList.h"
#include "CBbsFile.h"
#include "CFolder.h"
#include "CHost.h"
#include "miscclass.h"

#include "RichTextView.hpp"

class CMainControl
{
public:
	_STL::vector<CHostSorter>            m_vectorCHostSorter_          ;   //fr      0     24
	_STL::map<AnsiString,int>            m_mapStringInt_               ;   //fr     24     32
	_STL::vector<CQuery>                 m_vectorCQuery_               ;   //fr     56     24
	_STL::vector<CWork *>                m_vectorpCWork_               ;   //fr     80     24
	_STL::vector<CUpfileInfo>            m_vectorCUpfileInfo_          ;   //fr    104     24
	_STL::vector<CAutoDownList>          m_DownCondition_              ;   //fr    128     24
	_STL::vector<CAutoDownList>          m_IgnoreCondition_            ;   //fr    152     24
	_STL::multimap<unsigned int,CKey>    m_KeyBuffer_                  ;   //fr    176     32
	_STL::multimap<unsigned short,unsigned int> m_KeySearchTable_             ;   //fr    208     32
	_STL::vector<CFolder>                m_vectorCFolder_              ;   //fr    240     24
	_STL::vector<int>                    m_vectorInt_                  ;   //fr    264     24
	char                     m_szstr_errormsg_[1024]             ;   //fr    288   1024 
	int                            m_port_accept_                ;   //fr   1312      4 
	int                            m_port_bbsaccept_             ;   //fr   1316      4 
	char                     m_sz_DownFolderPath_ [4096]         ;   //fr   1320   4096 
	char                     m_sz_CacheFolderPath_[4096]         ;   //fr   5416   4096 
	char                     m_sz_BbsFolderPath_  [4096]         ;   //fr   9512   4096 
	char                     m_sz_MyDDNSname_     [256]          ;   //fr  13608    256 
	char                     m_char512_unk1_      [512]          ;   //fr  13864    512 
	int                            m_int_linespeed_              ;   //fr  14376      4 
	int pad1;	//fr  14380      4 <unknown>
	double                         m_double_currentCacheSize_    ;   //fr  14384      8
	Bb                             m_flag_cacheFolderDiskFull_   ;   //fr  14392      1
	Bb                             m_flag_downFolderDiskFull_    ;   //fr  14393      1
	int                            m_int_numberOfUpFile_         ;   //fr  14396      4
	int                            m_int_numberOfBbsUpFile_      ;   //fr  14400      4
	int                            m_int_numberOfCacheFile_      ;   //fr  14404      4
	int                            m_int_numberOfCompleteCacheFile_;   //fr  14408      4
	Bb                             m_optflag_notConnected__      ;   //fr  14412      1
	Bb                             m_optflag_notConvert__        ;   //fr  14413      1
	Bb                             m_optflag_Connect__           ;   //fr  14414      1
	int                            m_int_14416                   ;   //fr  14416      4
	int                            m_int_14420                   ;   //fr  14420      4
	double                         m_double_14424                ;   //fr  14424      8
	double                         m_double_upKBytePerSec_       ;   //fr  14432      8
	double                         m_double_downKBytePerSec_     ;   //fr  14440      8
	double                     m_arraydouble_unk10[60]           ;   //fr  14448    480
	double                     m_arraydouble_unk11[60]           ;   //fr  14928    480
	double                         m_double_unk12                ;   //fr  15408      8
	double                         m_double_unk13                ;   //fr  15416      8
	unsigned int                   m_uint_unk14                  ;   //fr  15424      4
	int                            m_int_unk15                   ;   //fr  15428      4
	int                            m_int_related_maxconnection__ ;   //fr  15432      4
	int                            m_int_currentTransferUpConnectionMax_;   //fr  15436      4
	int                            m_int_unk16                   ;   //fr  15440      4
	int                            m_int_unk17                   ;   //fr  15444      4
	int                            m_int_unk18                   ;   //fr  15448      4
	int                            m_int_unk19                   ;   //fr  15452      4
	Bb                             m_optflg_autoDisconnect_      ;   //fr  15456      1
	Bb                             m_optflg_displayUpFile_       ;   //fr  15457      1
	Bb                             m_optflg_displayCacheFile_    ;   //fr  15458      1
	Bb                             m_optflg_displayTmpCacheFile_ ;   //fr  15459      1
	Bb                             m_optflg_useMultiDownload_    ;   //fr  15460      1
	Bb                             m_optflg_useTransferLimit_    ;   //fr  15461      1
	Bb                             m_flg_unk15462                ;   //fr  15462      1
	bool pad2;	//fr  15463      1 <unknown>
	Bb                             m_optflg_displayNonWritableBbs_;   //fr  15464      1
	Bb                             m_optflg_downRetryFast_       ;   //fr  15465      1
	Bb                             m_optflg_searchIgnore_        ;   //fr  15466      1
	Bb                             m_optflg_autoTabChange_       ;   //fr  15467      1
	Bb                             m_optflg_displayNewCache_     ;   //fr  15468      1
	Bb                             m_flg_unk15469                ;   //fr  15469      1
	Bb                             m_flg_unk15470                ;   //fr  15470      1
	unsigned int                   m_uint_cacheDriveFreeMByte_   ;   //fr  15472      4
	unsigned int                   m_uint_downDriveFreeMByte_    ;   //fr  15476      4
	int                            m_int_unk20                   ;   //fr  15480      4
	int                            m_int_portWarnedCount_        ;   //fr  15484      4
	int                            m_int_virtualKeyMax_          ;   //fr  15488      4
	AnsiString                     m_str_optBbsBrowser_          ;   //fr  15492      4
	AnsiString                     m_str_optUrlBrowser_          ;   //fr  15496      4
	AnsiString                     m_str_optFolderBrowser_       ;   //fr  15500      4
	AnsiString                     m_str_optDownlistEditor_      ;   //fr  15504      4
	Bb                             m_optflg_showVersionWarning_  ;   //fr  15508      1
	Bb                             m_flg_unk15509                ;   //fr  15509      1
	Bb                             m_flg_unk15510                ;   //fr  15510      1
	Bb                             m_flg_unk15511                ;   //fr  15511      1
	Bb                             m_optflg_cutSlowTransfer_     ;   //fr  15512      1
	Bb                             m_optflg_V4CacheNotDown_      ;   //fr  15513      1
	CRC4                           m_CRC4                        ;   //fr  15514    771
	double                         m_double_optDownParamSize_    ;   //fr  16288      8
	double                         m_double_optDownParamTime_    ;   //fr  16296      8
	double                         m_double_optDownParamBlock_   ;   //fr  16304      8
	double                         m_double_optDownParamRef_     ;   //fr  16312      8
	Bb                             m_flag_exeSignatureIsOkay_    ;   //fr  16320      1
	Bb                             m_optflg_useTipPopup_         ;   //fr  16321      1
	unsigned char              m_hash_exeHash_[16]               ;   //fr  16322     16
	int                            m_int_unk21                   ;   //fr  16340      4
	AnsiString                     m_str_fontName_               ;   //fr  16344      4
	int pad4;	//fr  16348      4 <unknown>
	double                         m_double_fontSize_            ;   //fr  16352      8
	int                            m_int_downTrial_TimeInSec_    ;   //fr  16360      4
	int                            m_int_downTrial_NumberOfTry_  ;   //fr  16364      4
	int                            m_int_downTrial_NumberOfSuccessTry_;   //fr  16368      4
	int                            m_int_downTrial_NumberOfKeylostDisconnect_;   //fr  16372      4
	int                            m_int_downTrial_NumberOfTimeout_;   //fr  16376      4
	int                            m_int_downTrial_LimitTryCount_;   //fr  16380      4
	double                         m_double_totalFileSize_       ;   //fr  16384      8
	double                         m_double_totalReferenceSize_  ;   //fr  16392      8
	Bb                             m_flg_unk16400                ;   //fr  16400      1
	Bb                             m_optflg_makeMarkFile_        ;   //fr  16401      1
	Bb                             m_flg_unk16402                ;   //fr  16402      1
	Bb                             m_optflg_UseBlackColor_       ;   //fr  16403      1
	Bb                             m_optflg_UseBbsBlackColor_    ;   //fr  16404      1
	Bb                             m_flg_IsJoiningBBSCluster_    ;   //fr  16405      1
	Bb                             m_flg_IsBBSSearchLinkOn_      ;   //fr  16406      1
	Bb                             m_optflg_UseBbsOnly_          ;   //fr  16407      1
	Bb                             m_flg_unk16408                ;   //fr  16408      1
	int                            m_int_unk30                   ;   //fr  16412      4
	int                            m_int_unk31                   ;   //fr  16416      4
	unsigned char              m_hash_memorySignature_[16]       ;   //fr  16420     16
	int                            m_int_cacheOpenErrorCount_    ;   //fr  16436      4
	int                            m_int_maxnamelen_70                ;   //fr  16440      1
	bool m_unknown_000_70;
	bool m_unknown_001_70;
	bool m_flg_notused_;
	_STL::vector<int>                    m_vectorInt__1                ;   //fr  16448     24
	HWND                           m_hwnd_unk32                  ;   //fr  16472      4
	WSADATA                        m_wsadata_                    ;   //fr  16476     14
	SOCKET                         m_socket_accepting__          ;   //fr  16876      4
	SOCKET                         m_socket_unk33                ;   //fr  16880      4
	CHost                     m_hostArray[610]                   ;   //fr  16884 649040
	Bb                             m_flg_unk200                  ;   //fr 665924      1
	Bb                             m_flg_unk201                  ;   //fr 665925      1
	bool                       m_flgarray_unk[20]                ;   //fr 665926     20
	Bb                             m_flg_unk202                  ;   //fr 665946      1
	int                            m_int_CurrentSearchUpConnectionCount_;   //fr 665948      4
	int                            m_int_CurrentSearchDownConnectionCount_;   //fr 665952      4
	int                            m_int_CurrentTransferUpConnectionCount_;   //fr 665956      4
	int                            m_int_CurrentTransferDownConnectionCount_;   //fr 665960      4
	int                            m_int_CurrentTransferUpToPortzeroConnectionCount_;   //fr 665964      4
	int                            m_int_CurrentBBSTransferUpConnectionCount_;   //fr 665968      4
	int                            m_int_CurrentBBSTransferDownConnectionCount_;   //fr 665972      4
	int                            m_int_CurrentBBSUpConnectionCount_;   //fr 665976      4
	int                            m_int_CurrentBBSDownConnectionCount_;   //fr 665980      4
	int                            m_int_CurrentTransferProxyConnectionCount_;   //fr 665984      4
	Bb                             m_flg_unk203                  ;   //fr 665988      1
	int                            m_int_unk40                   ;   //fr 665992      4
	int                            m_int_unk41                   ;   //fr 665996      4
	int                            m_int_uptimeInSec_            ;   //fr 666000      4
	int                            m_int_unk42                   ;   //fr 666004      4
	int                            m_int_unk43                   ;   //fr 666008      4
	int pad7;	//fr 666012      4 <unknown>


	CMainControl();

	void CMainControl::mf_CMainControl_0000()
	{
		int local_00;
		for (local_00=0; local_00<20; local_00++) {
			m_flgarray_unk[local_00]=false;
		}
	}

	~CMainControl();
	void mf_CMainControl_0010(const AnsiString & arg_0,const AnsiString & arg_1,const AnsiString & arg_2,int arg_3);
	void mf_CMainControl_0020(const AnsiString & arg_0,const AnsiString & arg_1,const AnsiString & arg_2);
	void mf_CMainControl_0030();
	void mf_CMainControl_0040(const char * arg_0);
	void mf_CMainControl_0050(const char * arg_0);
	void mf_CMainControl_0060(const char * arg_0,unsigned int arg_1,unsigned char * arg_2,char * arg_3,double arg_4,double arg_5,bool arg_6,bool arg_7,bool arg_8,bool arg_9,bool arg_10);
	void mf_CMainControl_0070(const char * arg_0,char * arg_1,unsigned char * arg_2,unsigned char * arg_3,double arg_4,double arg_5,bool arg_6,bool arg_7,bool arg_8,bool arg_9);
	void mf_CMainControl_0080(xint arg_0,int arg_1);
	void mf_CMainControl_0090(const char * arg_0,bool arg_1);
	void mf_CMainControl_0100(const char * arg_0,bool arg_1);
	void mf_CMainControl_0110(const char * arg_0);
	void mf_CMainControl_0120(const char * arg_0);
	CAutoDownList * mf_CMainControl_0130(int arg_0);
	CAutoDownList * mf_CMainControl_0140(int arg_0);
	void mf_CMainControl_0150(int arg_0);
	void mf_CMainControl_0160(int arg_0);
	void mf_CMainControl_0170(int arg_0);
	CKey * mf_CMainControl_0180(unsigned int n,unsigned char * hash);
	void mf_CMainControl_0190();
	void mf_CMainControl_0200();
	void mf_CMainControl_0210();
	void mf_CMainControl_0220();
	void mf_CMainControl_0230(unsigned int arg_0,int arg_1,int arg_2);
	void mf_CMainControl_0240();
	void mf_CMainControl_0250();
	void mf_CMainControl_0260(int arg_0,bool arg_1);
	void mf_CMainControl_0270(int arg_0,int arg_1,int arg_2);
	void mf_CMainControl_0280();
	void mf_CMainControl_0290(int arg_0,int arg_1);
	void mf_CMainControl_0300();
	void mf_CMainControl_0310(int arg_0,int arg_1);
	void mf_CMainControl_0320();
	void mf_CMainControl_0330(bool arg_0);
	void mf_CMainControl_0340();
	void mf_CMainControl_0350();
	void mf_CMainControl_0360(int arg_0,int arg_1);
	void mf_CMainControl_0370(int hostidx,char * buf,int len);
	void mf_CMainControl_0380();
	void mf_CMainControl_0390();
	void mf_CMainControl_0400();
	void mf_CMainControl_0410(const char * arg_0);
	void mf_CMainControl_0420();
	void mf_CMainControl_0430();
	void mf_CMainControl_0440(int arg_0);
	void mf_CMainControl_0450(int arg_0);
	void mf_CMainControl_0460();
	CKey * mf_CMainControl_0470(struct__finddata_t * arg_0,bool arg_1);
	void mf_CMainControl_0480(xint arg_0,int arg_1,bool arg_2);
	void mf_CMainControl_0490(xint arg_0,const char * arg_1,const char * arg_2,int arg_3,bool arg_4);
	void mf_CMainControl_0500(xint arg_0,const char * arg_1,int arg_2,bool arg_3);
	void mf_CMainControl_0510(xint arg_0,bool arg_1,int arg_2,bool arg_3);
	void mf_CMainControl_0520(xint arg_0,int arg_1,bool arg_2);
	void mf_CMainControl_0530(xint arg_0);
	void mf_CMainControl_0540(xint arg_0);
	void mf_CMainControl_0550(xint arg_0);
	int mf_CMainControl_0560(_in_addr * ipaddr,int port);
	void mf_CMainControl_0570();
	void mf_CMainControl_0580(CKey * arg_0);
	unsigned short mf_CMainControl_0590(const char * arg_0);
	CKey * mf_CMainControl_0600(bool arg_0,char * arg_1,unsigned int arg_2,unsigned int arg_3,unsigned char * arg_4,char arg_5,bool * arg_6,char * arg_7,int arg_8,bool arg_9,unsigned int arg_10,int arg_11);
	sl mf_CMainControl_0610();
	void mf_CMainControl_0620();
	void mf_CMainControl_0630();
	void mf_CMainControl_0640(int arg_0);
	void mf_CMainControl_0650(int arg_0);
	sl mf_CMainControl_0660();
	void mf_CMainControl_0670(int arg_0,int arg_1);
	void mf_CMainControl_0680(int arg_0);
	void mf_CMainControl_0690();
	void mf_CMainControl_0700();
	void mf_CMainControl_0710();
	void mf_CMainControl_0720();
	void mf_CMainControl_7000();
	void mf_CMainControl_0730(CKey * arg_0);
	void mf_CMainControl_0740();
	void mf_CMainControl_0750();
	void mf_CMainControl_0760();
	void mf_CMainControl_0770();
	void mf_CMainControl_0780(int arg_0);
	void mf_CMainControl_0790(int arg_0);
	void mf_CMainControl_0800();
	void mf_CMainControl_0810();
	void mf_CMainControl_0820();
	void mf_CMainControl_0830();
	void mf_CMainControl_0840();
	void mf_CMainControl_0850(int arg_0);
	void mf_CMainControl_0860(int arg_0);
	void mf_CMainControl_0870(const char * arg_0,const char * arg_1);
	Bb mf_CMainControl_0880(unsigned int arg_0,unsigned char * arg_1,int arg_2,int arg_3,bool * arg_4,int * arg_5,char * arg_6);
	void mf_CMainControl_0890(int arg_0);
	void mf_CMainControl_0900(int arg_0,int arg_1,int arg_2,int arg_3,char * arg_4,unsigned int arg_5);
	void mf_CMainControl_0910(int arg_0);
	void mf_CMainControl_0920(int arg_0,int arg_1,int arg_2,char * arg_3,int arg_4);
	int mf_CMainControl_0930(CKey * arg_0,int arg_1);
	void mf_CMainControl_0940(CKey * arg_0,unsigned int arg_1);
	Bb mf_CMainControl_0950(unsigned int arg_0,unsigned char * arg_1);
	void mf_CMainControl_0960(int arg_0);
	void mf_CMainControl_0970(unsigned int arg_0,unsigned char * arg_1);
	void mf_CMainControl_0980(unsigned int arg_0,unsigned char * arg_1,bool arg_2);
	void mf_CMainControl_0990(int arg_0);
	void mf_CMainControl_1000(int arg_0);
	void mf_CMainControl_1010(unsigned char * arg_0);
	char mf_CMainControl_1020(int arg_0,int arg_1,bool arg_2,bool arg_3,bool arg_4,int arg_5,char arg_6);
	void mf_CMainControl_1030(int arg_0);
	void mf_CMainControl_1040(int arg_0,CKey * arg_1);
	void mf_CMainControl_1050();
	void mf_CMainControl_1060();
	void mf_CMainControl_1070(const char * arg_0);
	void mf_CMainControl_1080(const char * arg_0,char * arg_1,bool arg_2,int arg_3);
	void mf_CMainControl_1090();
	void mf_CMainControl_1100(int arg_0,char * arg_1,int arg_2,int arg_3);
	void mf_CMainControl_1110(int arg_0,const char * arg_1,const char * arg_2,int arg_3,bool arg_4);
	void mf_CMainControl_1120(int arg_0,const char * arg_1,const char * arg_2,int arg_3,bool arg_4);
	void mf_CMainControl_1130(int arg_0,const char * arg_1,const char * arg_2,char * arg_3,int arg_4,bool arg_5,int arg_6,bool arg_7);
	void mf_CMainControl_1140();
	void mf_CMainControl_1150();
	void mf_CMainControl_1160();
	void mf_CMainControl_1170();
	Bb mf_CMainControl_1180(CKey * arg_0);
	Bb mf_CMainControl_1190(CKey * arg_0);
	void mf_CMainControl_1200();
	void mf_CMainControl_1210(const char * arg_0,bool arg_1);
	void mf_CMainControl_1220(const char * arg_0,bool arg_1,bool arg_2);
	void mf_CMainControl_1230(AnsiString arg_0,bool arg_1);
	Bb mf_CMainControl_1240(_in_addr * arg_0,int arg_1);
	Bb mf_CMainControl_1250(unsigned char * arg_0,unsigned int arg_1);
	void mf_CMainControl_1260();
	void mf_CMainControl_1270();
	void mf_CMainControl_1280(int arg_0);
	void mf_CMainControl_1290();
	bool mf_CMainControl_1300(int arg_0,unsigned char * arg_1,unsigned int arg_2,char * arg_3,unsigned int arg_4);
	char * mf_CMainControl_1310(int arg_0,char * arg_1,int * arg_2,time_t * arg_3);
	char * mf_CMainControl_1320(TRichTextView * arg_0,char * arg_1,time_t * arg_2,time_t * arg_3);
	sl mf_CMainControl_1330(TBbsTab * arg_0,TRichTextView * arg_1,TLabel * arg_2);
	void mf_CMainControl_1340(int arg_0);
	bool mf_CMainControl_1350(int arg_0,CKey * arg_1,bool arg_2,const char * arg_3,const char * arg_4,const char * arg_5);
	Bb mf_CMainControl_1360(CKey * arg_0,char * arg_1);
	void mf_CMainControl_1370();
	void mf_CMainControl_1380(int arg_0);
	void mf_CMainControl_1390(int arg_0,char * arg_1);
	void mf_CMainControl_1400(const char * arg_0);
	void mf_CMainControl_1410(int arg_0,char * arg_1);
	bool mf_CMainControl_1420(int arg_0,bool arg_1,char * arg_2,char * arg_3,char * arg_4,unsigned char * arg_5,bool arg_6);
	bool mf_CMainControl_1430(const char * arg_0,char * arg_1,char * arg_2,char * arg_3,unsigned char * arg_4);
	bool mf_CMainControl_1440(char * arg_0,char * arg_1,char * arg_2);
	sl mf_CMainControl_1450(char * arg_0,const char * arg_1,char * arg_2,unsigned char * arg_3);
	void mf_CMainControl_1460(int arg_0);
	int mf_CMainControl_1470();
	void mf_CMainControl_1480(int arg_0,char * arg_1);
	void mf_CMainControl_1490(int arg_0,int arg_1,char * arg_2,char * arg_3,char * arg_4);
	void mf_CMainControl_1500(int arg_0,char * arg_1,bool arg_2);
	void mf_CMainControl_1510(int arg_0,char * arg_1,bool arg_2);
	char mf_CMainControl_1520(char * arg_0,char * arg_1);
	void mf_CMainControl_1530(int arg_0);
	void mf_CMainControl_1540(int arg_0);
	void mf_CMainControl_1550();
	void mf_CMainControl_1560(int arg_0);
	void mf_CMainControl_1570();
	bool mf_CMainControl_1580(CWork * arg_0,char * arg_1);
	void mf_CMainControl_1590(int arg_0);
	void mf_CMainControl_1600(int arg_0);
	void mf_CMainControl_1610(int arg_0);
	void mf_CMainControl_1620(int arg_0);
	void mf_CMainControl_1630(int arg_0);
	void mf_CMainControl_1640(int arg_0);
	void mf_CMainControl_1650(int arg_0);
	void mf_CMainControl_1660(int arg_0);


	inline CWork *GetWork(int idx) {        //チェックあり
		if ( (int)idx<0 || idx>=(int)m_vectorpCWork_.size() ) return NULLPO;
		return m_vectorpCWork_[idx];
	}
	inline CWork **GetWorkArray() {       //beginを返す
			return m_vectorpCWork_.begin();
	}
	inline CWork *GetWorkNC(unsigned int idx) {       //チェックなし
			return m_vectorpCWork_[idx];
	}

	inline CWork **GetWorkNP(unsigned int idx) {       //チェックなし,begin形式  shlにするにはこれを使うと良い
			return GetWorkArray()+idx;
	}
	inline CWork **GetWorkNPx(unsigned int idx) {       //チェックなし,begin形式  shlにするにはこれを使うと良い
			CWork **tmp=GetWorkArray()+idx;
			return tmp;
	}
	inline CWork *GetWorkUnya(unsigned int idx) {
		return *(CWork**) ( (idx*sizeof(CWork*))+((unsigned int)m_vectorpCWork_.begin()) );
	}

	inline CQuery *GetQuery(unsigned int idx) {
		return m_vectorCQuery_.begin()+idx;
	}

	inline CFolder *GetFolder(unsigned int idx) {
			return m_vectorCFolder_.begin()+idx;
	}
	inline CFolder &GetFolderR(unsigned int idx) {
			return m_vectorCFolder_.begin()[idx];
	}
	inline CFolder *GetFolderUnya(int idx) {
		return (CFolder*) ( (unsigned int)(idx*sizeof(CFolder))+((unsigned int)m_vectorCFolder_.begin()) );
	}

	inline CAutoDownList * GetDownCondition(int idx) {
		return &m_DownCondition_[idx];
	}
	inline CAutoDownList * GetIgnoreCondition(int idx) {
		return &m_IgnoreCondition_[idx];
	}

	inline CHost *GetHost(int idx) {
		return &m_hostArray[idx];
	}

};



#endif// _CMAINCONTROL_H_INCLUDED
