#ifndef _CHOST_H_INCLUDED
#define _CHOST_H_INCLUDED

class CHost
{
public:
	_in_addr                       m_ipaddr1                     ;   //fr      0      4
	_in_addr                       m_ipaddr2                     ;   //fr      4      4
	_in_addr                       m_ipaddr3                     ;   //fr      8      4
	int                            m_port1                       ;   //fr     12      4
	int                            m_port2                       ;   //fr     16      4
	int                            m_port3                       ;   //fr     20      4
	int                            m_int_wmsgIdx                 ;   //fr     24      4
	int                            m_int_lineSpeed               ;   //fr     28      4
	int                            m_int_unk5                    ;   //fr     32      4
	int                            m_int_connectionTimeInSec     ;   //fr     36      4
	int                            m_int_nodataTimeInSec         ;   //fr     40      4
	Bb                             m_flg_unk303                  ;   //fr     44      1
	char *                         m_pRecvbuf                    ;   //fr     48      4
	int                   m_allocsize_recvbuf           ;   //fr     52      4
	int                   m_buflen_recvbuf              ;   //fr     56      4
	char *                         m_pSendbuf                    ;   //fr     60      4
	int                   m_allocsize_sendbuf           ;   //fr     64      4
	int                   m_buflen_sendbuf              ;   //fr     68      4
	bool                             m_flg_isDownConnection        ;   //fr     72      1
		//boolじゃなくてcharかenumと思われる。本来はdirectionか？影響が大きいので、そのままになってるので注意
	int                            m_int_unk300                  ;   //fr     76      4
	int                            m_int_version                 ;   //fr     80      4
	AnsiString                     m_str_unk9                    ;   //fr     84      4
	int                            m_int_unk10                   ;   //fr     88      4
	int                            m_int_preference2_negative    ;   //fr     92      4
	int                            m_int_preference2_positive    ;   //fr     96      4
	int                            m_int_preference1             ;   //fr    100      4
	int                            m_int_unk301                  ;   //fr    104      4
	char                        m_cryptseed_send[4]              ;   //fr    108      4
	char                           m_char_unk302                 ;   //fr    112      1
	char pad0[3];	//fr    113      3 <unknown>
	char                        m_cryptseed_recv[4]              ;   //fr    116      4
	int pad1;	//fr    120      4 <unknown>
	Bb                             m_field_7C                    ;   //fr    124      1
	Bb                             m_flgIsNAT;   //fr    125      1
	Bb                             m_field_7E                    ;   //fr    126      1
	Bb                             m_flgUnknown_7F               ;   //fr    127      1
	Bb                             m_flgUnknown_80               ;   //fr    128      1
	Bb                             m_field_81                    ;   //fr    129      1
	Bb                             m_field_82                    ;   //fr    130      1
	Bb                             m_flgIgnoredWarning_8         ;   //fr    131      1
	Bb                             m_flgNetsuzouWarning_8        ;   //fr    132      1
	Bb                             m_flgIsBBSNode_8              ;   //fr    133      1
	Bb                             m_flg_IsBBSPort               ;   //fr    134      1
	Bb                             m_field_87                    ;   //fr    135      1
	Bb                             m_field_88                    ;   //fr    136      1
	Bb                             m_flgIsTransferProxy_8        ;   //fr    137      1
	Bb                             m_flgIsValid;   //fr    138      1
	Bb                             m_flgIsConnected;   //fr    139      1
	Bb                             m_field_8C                    ;   //fr    140      1
	Bb                             m_field_8D                    ;   //fr    141      1
	Bb                             m_field_8E                    ;   //fr    142      1
	Bb                             m_flgIsTransferLink_8         ;   //fr    143      1
	Bb                             m_flgSendKeyok_9              ;   //fr    144      1
	Bb                             m_flgRecvKeyok_9              ;   //fr    145      1
	Bb                             m_flgIsPortZero_9             ;   //fr    146      1
	Bb                             m_flgIsBadPortZero_9          ;   //fr    147      1
	Bb                             m_field_94                    ;   //fr    148      1
	Bb                             m_flgIsBBSConnectionTest      ;   //fr    149      1
	//fr    150      2 <unknown>
	AnsiString                     m_str_DDNSname                ;   //fr    152      4
	SOCKET                         m_socket                      ;   //fr    156      4
	char                      m_sz_clusterword[3][128]            ;   //fr    160    128
	unsigned char             m_sendtable_[256]                  ;   //fr    544    256
	unsigned char                  m_sendtableptr_               ;   //fr    800      1
	unsigned char                  m_sendtablewk1_               ;   //fr    801      1
	unsigned char                  m_sendtablewk2_               ;   //fr    802      1
	unsigned char             m_recvtable_[256]                  ;   //fr    803    256
	unsigned char                  m_recvtableptr_               ;   //fr   1059      1
	unsigned char                  m_recvtablewk1_               ;   //fr   1060      1
	unsigned char                  m_recvtablewk2_               ;   //fr   1061      1


	CHost();
	void mf_CHost_0000();
	void mf_CHost_0010();
	~CHost();
	void mf_CHost_0020(int idx,const char * keyword);
	void mf_CHost_0030(char * arg_0);
	char mf_CHost_0040();
	void mf_CHost_0050(char * arg_0,char * arg_1,int arg_2);
	void mf_CHost_0060(char * arg_0);
	char mf_CHost_0070();
	void mf_CHost_0080(char * dest,char * src,int len);
	void mf_CHost_0090(char * dest,char * src,int len);
	void mf_CHost_0100(char * arg_0,int arg_1);
	void mf_CHost_0110(char * arg_0,int arg_1);
	Bb mf_CHost_0120();
	unsigned int mf_CHost_0130(char * arg_0,int arg_1);
	Bb mf_CHost_0140();
	sl mf_CHost_0150(char * arg_0,int arg_1);
	void mf_CHost_0160(char * arg_0,int arg_1);
	void mf_CHost_0170(char * buf,unsigned int len);
	void mf_CHost_0180();
	void mf_CHost_0190(bool arg_0);
	void mf_CHost_0200();
	void mf_CHost_0210(int arg_0,int arg_1);
	int mf_CHost_0220(CHost * arg_0);

	void CHost::mf_CHost_0230(AnsiString arg_0)
	{
		m_str_DDNSname=arg_0;
		return;
	}


	unsigned int GetWmsgOfs_crw() {
		return (!(m_flg_IsBBSPort==0))?(m_int_wmsgIdx*3+1000):(m_int_wmsgIdx*3);
	}
	unsigned int GetWmsgOfs_connect() {
		return (!(m_flg_IsBBSPort==0))?(m_int_wmsgIdx*3+1001):(m_int_wmsgIdx*3+1);
	}
	unsigned int GetWmsgOfs_gethostbyname() {
		return (!(m_flg_IsBBSPort==0))?(m_int_wmsgIdx*3+1002):(m_int_wmsgIdx*3+2);
	}
	inline void SetWmsgIdx(_CONST int s) {
		m_int_wmsgIdx=s;
		mf_CHost_0010();
	}

	inline void SetPort(_CONST int p) { m_port1=p; }
	inline void SetBbsPort(_CONST int p) { m_port2=p; }
	inline void SetPort3(_CONST int p) { m_port3=p; }
	inline void SetSocket(SOCKET s) { m_socket=s; }

	inline bool IsInternalIpaddr(const _in_addr &s) const { return s.b1==m_ipaddr3.b1 && s.b2==m_ipaddr3.b2 && s.b3==m_ipaddr3.b3 && s.b4==m_ipaddr3.b4; }
	int IsInternalIpaddr_x(const _in_addr &s) const { return s.b1==m_ipaddr3.b1 && s.b2==m_ipaddr3.b2 && s.b3==m_ipaddr3.b3 && s.b4==m_ipaddr3.b4; }
	bool IsInternalIpaddr_x2b(const _in_addr &s) const { return m_ipaddr3.b1==s.b1 && m_ipaddr3.b2==s.b2 && m_ipaddr3.b3==s.b3 && m_ipaddr3.b4==s.b4; }
	inline bool IsnotInternalIpaddr_x2b(const _in_addr &s) const { return m_ipaddr3.b1!=s.b1 || m_ipaddr3.b2!=s.b2 || m_ipaddr3.b3!=s.b3 || m_ipaddr3.b4!=s.b4; }
	inline bool IsInternalIpaddr_e(const unsigned char b1,const unsigned char b2,const unsigned char b3,const unsigned char b4) const { return m_ipaddr3.b1==b1 && m_ipaddr3.b2==b2 && m_ipaddr3.b3==b3 && m_ipaddr3.b4==b4; }

	inline void SetVersion(int s) { m_int_version=s; }
	inline void SetLineSpeed(_CONST int s) { m_int_lineSpeed=s; }
	inline void SetflgIsPortZero(_CONST bool s) { m_flgIsPortZero_9=s; }
	inline void SetflgIsBBSNode(_CONST bool s) { m_flgIsBBSNode_8=s; }
	inline void SetflgIsTransferLink(_CONST bool s) { m_flgIsTransferLink_8=s; }
	inline void SetflgIsTransferProxy(_CONST bool s) { m_flgIsTransferProxy_8=s; }
	inline void SetflgUnknown7F_(_CONST bool s) { m_flgUnknown_7F=s; }
	inline void SetflgIsNAT(_CONST bool s) { m_flgIsNAT=s; }
	inline void Set_int_unk301(_CONST int s) { m_int_unk301=s; }
	inline void SetPreference2_positive(_CONST int s) { m_int_preference2_positive=s; }

	bool GetflgIsDownConnection() _CONST { return ((char)m_flg_isDownConnection)!=0; }
	bool GetflgIsUpConnection() _CONST { return !GetflgIsDownConnection(); }
	bool GetflgIsUpConnection_x() _CONST { return ((char)m_flg_isDownConnection)==0; }
};





class CHostSorter
{
public:
	int                            m_int_unk00                   ;   //fr      0      4 
	int                            m_int_unk01                   ;   //fr      4      4 
	int                            m_int_unk02                   ;   //fr      8      4 
	int                            m_int_unk03                   ;   //fr     12      4 
	int                            m_int_unk04                   ;   //fr     16      4
	int                            m_int_unk05                   ;   //fr     20      4 
	int                            m_int_unk06                   ;   //fr     24      4 
	float                          m_float_unk1                  ;   //fr     28      4 
	int                            m_int_unk07                   ;   //fr     32      4 
	CHost *                        m_CHost_unk2                  ;   //fr     36      4 
	int                            m_int_unk3                    ;   //fr     40      4 
	Bb                             m_bool_unk4                   ;   //fr     44      1 

	bool operator < (const CHostSorter & arg_0) const
	{
		if (m_bool_unk4) {
			switch (m_int_unk3) {
			case 0:
				return (bool)(m_int_unk03<arg_0.m_int_unk03);
			case 1:
				return (bool)(m_int_unk04<arg_0.m_int_unk04);
			case 2:
				return (bool)(m_int_unk06<arg_0.m_int_unk06);
			case 3:
				return (bool)(m_int_unk05<arg_0.m_int_unk05);
			case 4:
				return (bool)(m_int_unk01<arg_0.m_int_unk01);
			case 5:
				return (bool)(m_int_unk02<arg_0.m_int_unk02);
			case 6:
				return (bool)(m_int_unk07<arg_0.m_int_unk07);
			case 7:
				return (bool)(m_float_unk1<arg_0.m_float_unk1);
			}
			return (bool)(m_int_unk03<arg_0.m_int_unk03);
		}
		switch (m_int_unk3) {
		case 0:
			return (bool)(m_int_unk03>arg_0.m_int_unk03);
		case 1:
			return (bool)(m_int_unk04>arg_0.m_int_unk04);
		case 2:
			return (bool)(m_int_unk06>arg_0.m_int_unk06);
		case 3:
			return (bool)(m_int_unk05>arg_0.m_int_unk05);
		case 4:
			return (bool)(m_int_unk01>arg_0.m_int_unk01);
		case 5:
			return (bool)(m_int_unk02>arg_0.m_int_unk02);
		case 6:
			return (bool)(m_int_unk07>arg_0.m_int_unk07);
		case 7:
			return (bool)(m_float_unk1>arg_0.m_float_unk1);
		}
		return (bool)(m_int_unk03>arg_0.m_int_unk03);
	}


};

class CHostHeader
{
public:
	_in_addr                       m_ipaddr1                     ;   //fr      0      4
	int                            m__unknown_000                ;   //fr      4      4
	CHostHeader(){}
	int IsIpaddr_Host_x(const CHost &s) const { return s.m_ipaddr3.b1==m_ipaddr1.b1 && s.m_ipaddr3.b2==m_ipaddr1.b2 && s.m_ipaddr3.b3==m_ipaddr1.b3 && s.m_ipaddr3.b4==m_ipaddr1.b4; }
};


#endif// _CHOST_H_INCLUDED
