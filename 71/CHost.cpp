//---------------------------------------------------------------------------
#include "hdrs.h"

#include <vcl.h>
#pragma hdrstop

#include "def.h"

#include "CKey.h"

#include "def2.h"
#include "globals.h"



CHost::CHost()
{
	mf_CHost_0000();
}


void CHost::mf_CHost_0000()
{
	m_int_wmsgIdx=0;
	m_ipaddr3.b1=0;
	m_ipaddr3.b2=0;
	m_ipaddr3.b3=0;
	m_ipaddr3.b4=0;
	m_ipaddr1.b1=0;
	m_ipaddr1.b2=0;
	m_ipaddr1.b3=0;
	m_ipaddr1.b4=0;
	m_port1=0;
	m_port2=0;
	m_int_lineSpeed=-1;
	m_str_DDNSname="";
	m_str_unk9="";
	m_field_8D=false;
	m_flgIsValid=false;
	m_flgIsPortZero_9=false;
	m_field_8D=false;
	m_flgIsNAT=false;
	m_int_unk5=3600;
	m_socket=0;     //INVALID_SOCKET;
	m_flgIsBadPortZero_9=false;
	m_field_94=false;
	m_field_7E=false;
	m_field_82=false;
	m_flgIgnoredWarning_8=false;
	m_flgNetsuzouWarning_8=false;
	m_field_87=false;
	m_field_88=false;
	m_int_version=0;
	m_int_preference2_negative=0;
	m_int_preference2_positive=0;
	m_int_preference1=0;
	m_flgIsBBSNode_8=false;
	*m_sz_clusterword[0]=0;
	*m_sz_clusterword[1]=0;
	*m_sz_clusterword[2]=0;
	m_int_unk10=0;
	mf_CHost_0010();
	return;
}


void CHost::mf_CHost_0010()
{
	if (m_socket!=0) {
		closesocket(m_socket);
		m_socket=0;     //INVALID_SOCKET;
		g_int_unk506=g_int_unk506+1;
	}
	m_ipaddr2.b1=0;
	m_ipaddr2.b2=0;
	m_ipaddr2.b3=0;
	m_ipaddr2.b4=0;
	m_port3=0;
	m_flg_isDownConnection=false;
	m_flgIsTransferProxy_8=false;
	m_field_81=false;
	m_field_8E=false;
	m_pRecvbuf=NULLPO;
	m_pSendbuf=NULLPO;
	m_flgIsConnected=false;
	m_field_8C=false;
	m_flgIsTransferLink_8=false;
	m_buflen_recvbuf=0;
	m_allocsize_recvbuf=0;
	m_pRecvbuf=NULLPO;
	m_buflen_sendbuf=0;
	m_allocsize_sendbuf=0;
	m_pSendbuf=NULLPO;
	m_field_7C=false;
	m_int_nodataTimeInSec=0;
	m_flgSendKeyok_9=false;
	m_flgRecvKeyok_9=false;
	m_flg_unk303=false;
	m_int_unk300=-1;
	m_int_connectionTimeInSec=0;
	m_flgUnknown_7F=false;
	m_flgUnknown_80=false;
	m_flg_IsBBSPort=false;
	m_flgIsBBSConnectionTest=false;
	m_int_unk301=0;
	*m_cryptseed_send=(char)(rand()%256);
	m_cryptseed_send[1]=(char)(rand()%256);
	m_cryptseed_send[2]=(char)(rand()%256);
	m_cryptseed_send[3]=(char)(rand()%256);
	m_char_unk302=0;
	*m_cryptseed_recv=0;
	return;
}



CHost::~CHost()
{
}


void CHost::mf_CHost_0020(int idx,const char * keyword)
{
	char * local_00;
	strcpy(m_sz_clusterword[idx],keyword);
	for (local_00=m_sz_clusterword[idx]; !(*local_00==0)&&(int)*local_00!=32; local_00++) {
	}
	*local_00=0;
}


void CHost::mf_CHost_0030(char * arg_0)
{
	int local_00;
	int local_01;
	int local_02;
	char local_03[256];
	local_00=strlen(arg_0);
	local_01=0;
	for (local_02=0; local_02<256; local_02++) {
		m_sendtable_[local_02]=*((unsigned char *)(&local_02));
		*(local_03+local_02)=*(arg_0+local_01);
		local_01=local_01+1;
		if (local_01<local_00) continue;
		local_01=0;
	}
	m_sendtablewk1_=local_02=0;
	for ( ; local_02<256; local_02++) {
		m_sendtablewk1_+=*(local_03+local_02)+m_sendtable_[local_02];
		m_sendtablewk2_=m_sendtable_[local_02];
		m_sendtable_[local_02]=m_sendtable_[m_sendtablewk1_];
		m_sendtable_[m_sendtablewk1_]=m_sendtablewk2_;
	}
	m_sendtableptr_=m_sendtablewk1_=0;
	return;
}


char CHost::mf_CHost_0040()
{
	m_sendtableptr_=m_sendtableptr_+1;
	m_sendtablewk1_+=m_sendtable_[m_sendtableptr_];
	m_sendtablewk2_=m_sendtable_[m_sendtableptr_];
	m_sendtable_[m_sendtableptr_]=m_sendtable_[m_sendtablewk1_];
	m_sendtable_[m_sendtablewk1_]=m_sendtablewk2_;
	m_sendtablewk2_=m_sendtable_[m_sendtableptr_]+m_sendtable_[m_sendtablewk1_];
	return *((char *)(m_sendtable_+m_sendtablewk2_));
}


void CHost::mf_CHost_0050(char * arg_0,char * arg_1,int arg_2)
{
	int local_00;
	for (local_00=0; local_00<arg_2; local_00++) {
		*arg_0=mf_CHost_0040()^arg_1[0];
		arg_1=(char *)(arg_1+1);
		arg_0=arg_0+1;
	}
	return;
}


void CHost::mf_CHost_0060(char * arg_0)
{
	int local_00;
	int local_01;
	int local_02;
	char local_03[256];
	local_00=strlen(arg_0);
	local_01=0;
	for (local_02=0; local_02<256; local_02++) {
		m_recvtable_[local_02]=*((unsigned char *)(&local_02));
		*(local_03+local_02)=*(arg_0+local_01);
		local_01=local_01+1;
		if (local_01<local_00) continue;
		local_01=0;
	}

	m_recvtablewk1_=local_02=0;
	for ( ; local_02<256; local_02++) {
		m_recvtablewk1_+=*(local_03+local_02)+m_recvtable_[local_02];
		m_recvtablewk2_=m_recvtable_[local_02];
		m_recvtable_[local_02]=m_recvtable_[m_recvtablewk1_];
		m_recvtable_[m_recvtablewk1_]=m_recvtablewk2_;
	}

	m_recvtableptr_=m_recvtablewk1_=0;
	m_flgRecvKeyok_9=true;
	return;
}


char CHost::mf_CHost_0070()
{
	m_recvtableptr_=m_recvtableptr_+1;
	m_recvtablewk1_+=m_recvtable_[m_recvtableptr_];
	m_recvtablewk2_=m_recvtable_[m_recvtableptr_];
	m_recvtable_[m_recvtableptr_]=m_recvtable_[m_recvtablewk1_];
	m_recvtable_[m_recvtablewk1_]=m_recvtablewk2_;
	m_recvtablewk2_=m_recvtable_[m_recvtableptr_]+m_recvtable_[m_recvtablewk1_];
	return *((char *)(m_recvtable_+m_recvtablewk2_));
}


void CHost::mf_CHost_0080(char * dest,char * src,int len)
{
	int local_00;
	for (local_00=0; local_00<len; local_00++) {
		*dest=mf_CHost_0070()^*src;
		src=src+1;
		dest=dest+1;
	}
	return;
}


void CHost::mf_CHost_0090(char * dest,char * src,int len)
{
	int local_00;
	unsigned char local_01;
	unsigned char local_02;
	unsigned char local_03;
	char local_04[512];
	local_01=m_recvtableptr_;
	local_02=m_recvtablewk1_;
	local_03=m_recvtablewk2_;
	for (local_00=0; local_00<256; local_00++) {
		*(local_04+local_00)=m_recvtable_[local_00];
	}
	for (local_00=0; local_00<len; local_00++) {
		local_01=local_01+1;
		local_02=local_02+*(local_04+(unsigned int)local_01);
		local_03=*(local_04+(unsigned int)local_01);
		*(local_04+(unsigned int)local_01)=*(local_04+(unsigned int)local_02);
		*(local_04+(unsigned int)local_02)=local_03;
		local_03=*(local_04+(unsigned int)local_01)+*(local_04+(unsigned int)local_02);
		*dest=*src^*(local_04+(unsigned int)local_03);
		src=src+1;
		dest=dest+1;
	}
	return;
}


void CHost::mf_CHost_0100(char * arg_0,int arg_1)
{
	if ((int)m_buflen_recvbuf+arg_1>=(int)m_allocsize_recvbuf) {
		m_allocsize_recvbuf=m_buflen_recvbuf+arg_1+0x00020000;
		m_pRecvbuf=(char *)realloc(m_pRecvbuf,m_allocsize_recvbuf);
	}
	if (! (!(m_pRecvbuf==0)&&(int)m_allocsize_recvbuf<=0x00400000) ) {
		ny_addlog("通信受信バッファが溢れたためリンクを切断しました");
		mf_CHost_0190(true);
		m_flgIsValid=false;
		return;
	}
	memcpy(m_pRecvbuf+m_buflen_recvbuf,arg_0,arg_1);
	m_buflen_recvbuf=m_buflen_recvbuf+arg_1;
	return;
}


void CHost::mf_CHost_0110(char * arg_0,int arg_1)
{
	if ((int)m_buflen_recvbuf+arg_1>=(int)m_allocsize_recvbuf) {
		m_allocsize_recvbuf=m_buflen_recvbuf+arg_1+0x00020000;
		m_pRecvbuf=(char *)realloc(m_pRecvbuf,m_allocsize_recvbuf);
	}
	if (! (!(m_pRecvbuf==0)&&(int)m_allocsize_recvbuf<=0x00400000) ) {
		ny_addlog("通信受信バッファが溢れたためリンクを切断しました");
		mf_CHost_0190(true);
		m_flgIsValid=false;
		return;
	}
	memcpy(m_pRecvbuf+m_buflen_recvbuf,arg_0,arg_1);
	m_buflen_recvbuf=m_buflen_recvbuf+arg_1;
	return;
}


Bb CHost::mf_CHost_0120()
{
	char local_00[16];
	if (! (!(m_pRecvbuf==0)&&(int)m_buflen_recvbuf>=4) ) {
		return false;
	}
	this->mf_CHost_0090(local_00,m_pRecvbuf,4);
	int len=(*(int *)local_00);
	if (len+4<=(int)m_buflen_recvbuf) {
		return true;
	}
	return false;
}


unsigned int CHost::mf_CHost_0130(char * arg_0,int arg_1)
{
	unsigned int local_00;
	local_00=m_buflen_recvbuf;
	if (arg_1-1<=(int)local_00) {
		return 0;
	}
	memcpy(arg_0,m_pRecvbuf,local_00);
	*(arg_0+local_00)=0;
	m_buflen_recvbuf=0;
	return local_00;
}


Bb CHost::mf_CHost_0140()
{
	int local_00;
	int local_01;
	local_00=0;
	for (local_01=0; local_01<(int)m_buflen_recvbuf; local_01++) {
		if (local_00%2!=0) {
			if (*(unsigned char *)(m_pRecvbuf+local_01)==10) {
				local_00=local_00+1;
			}
		} else {
			if (*(unsigned char *)(m_pRecvbuf+local_01)==13) {
				local_00=local_00+1;
			}
		}
		if (! (*(unsigned char *)(m_pRecvbuf+local_01)==10||*(unsigned char *)(m_pRecvbuf+local_01)==13) ) {
			local_00=0;
		}
		if (local_00!=4) continue;
		return true;
	}
	return false;
}


sl CHost::mf_CHost_0150(char * arg_0,int arg_1)
{
	char local_00[4];
	int local_01;
	this->mf_CHost_0080(local_00,m_pRecvbuf,4);
	local_01=*(int *)local_00;
	if (! (!(local_01>=arg_1||local_01<0)&&(int)m_buflen_recvbuf>=local_01) ) {
		mf_CHost_0190(true);
		m_field_94=true;
		return 0;
	}
	mf_CHost_0080(arg_0,m_pRecvbuf+4,local_01);
	memcpy(m_pRecvbuf,(m_pRecvbuf+4)+local_01,m_buflen_recvbuf-local_01);
	*(arg_0+local_01)=0;
	m_buflen_recvbuf-=local_01+4;
	if (m_buflen_recvbuf>0x00100000) {
		m_field_7C=true;
	} else {
		m_field_7C=false;
	}
	return local_01;
}


void CHost::mf_CHost_0160(char * arg_0,int arg_1)
{
	if (! (!(!m_flgIsConnected)&&m_buflen_sendbuf>=0) ) {
		return;
	}
	if (m_buflen_sendbuf+arg_1>=m_allocsize_sendbuf) {
		m_allocsize_sendbuf=m_buflen_sendbuf+arg_1+0x00020000;
		m_pSendbuf=(char *)realloc(m_pSendbuf,m_allocsize_sendbuf);
	}
	if (! (!(m_pSendbuf==0)&&m_allocsize_sendbuf<=0x00400000) ) {
		ny_addlog("通信書込みバッファが溢れたためリンクを切断しました");
		mf_CHost_0190(true);
		m_flgIsValid=false;
		return;
	}
	if (!m_flgSendKeyok_9) {
		mf_CHost_0030(m_cryptseed_send);
		*(m_pSendbuf+m_buflen_sendbuf++)=(char)(rand()%256);
		*(m_pSendbuf+m_buflen_sendbuf++)=(char)(rand()%256);
		memcpy(m_pSendbuf+m_buflen_sendbuf,m_cryptseed_send,4);
		m_flgSendKeyok_9=true;
		m_buflen_sendbuf=m_buflen_sendbuf+4;
	}
	mf_CHost_0050(m_pSendbuf+m_buflen_sendbuf,arg_0,arg_1);
	m_buflen_sendbuf=m_buflen_sendbuf+arg_1;
	return;
}


void CHost::mf_CHost_0170(char * buf,unsigned int len)
{
	if (! (!(!m_flgIsConnected)&&m_buflen_sendbuf>=0) ) {
		return;
	}
	if (m_buflen_sendbuf+(int)len>=m_allocsize_sendbuf) {
		m_allocsize_sendbuf=m_buflen_sendbuf+len+0x00020000;
		m_pSendbuf=(char *)realloc(m_pSendbuf,m_allocsize_sendbuf);
	}
	if (! (!(m_pSendbuf==0)&&m_allocsize_sendbuf<=0x00400000) ) {
		ny_addlog("通信書込みバッファが溢れたためリンクを切断しました");
		mf_CHost_0190(true);
		m_flgIsValid=false;
		return;
	}
	memcpy(m_pSendbuf+m_buflen_sendbuf,buf,len);
	m_buflen_sendbuf+=(int)len;
	return;
}


void CHost::mf_CHost_0180()
{
	unsigned int local_00;
	int local_01;
	unsigned int local_02;
	int local_03;
	int local_04;
	if (! (!(m_buflen_sendbuf==0)&&m_socket!=0) ) {
		return;
	}
	local_00=m_buflen_sendbuf;
	if (! (!(!m_flgIsBBSNode_8)&&m_flgIsTransferLink_8||(m_flg_IsBBSPort||!g_pCMainControl->m_optflg_useTransferLimit_)) ) {
		if ((double)g_pCMainControl->m_int_linespeed_>g_pCMainControl->m_double_upKBytePerSec_) {
			g_pCMainControl->m_double_unk13+=(float)0.0001;
		} else {
			g_pCMainControl->m_double_unk13-=(float)0.0001;
		}
		if (g_pCMainControl->m_double_unk13>5.0) {
			g_pCMainControl->m_double_unk13=5.0;
		}
		if (g_pCMainControl->m_double_unk13<0.2) {
			g_pCMainControl->m_double_unk13=0.2;
		}
		local_01=g_pCMainControl->m_int_CurrentTransferUpConnectionCount_;
		if (local_01<1) {
			local_01=1;
		}
		local_02=(unsigned int)((int)(((double)g_pCMainControl->m_int_linespeed_*g_pCMainControl->m_double_unk13)*30.0/(double)local_01));
		if ((int)local_00>(int)local_02) {
			local_00=local_02;
		}
	}
	m_int_nodataTimeInSec=0;
	local_03=send(m_socket,m_pSendbuf,local_00,0);
	if (local_03!=0) {
		if (local_03==-1) {
			local_04=WSAGetLastError();
			if (local_04!=10035) {
				if (! (local_04==10054||local_04==10053||local_04==10057) ) {
					ny_addlog("send() 失敗");
					g_pCMainControl->mf_CMainControl_1650(local_04);
				}
				mf_CHost_0190(false);
			}
		} else {
			if (local_03>0) {
				if ((int)m_buflen_sendbuf-local_03>0) {
					memcpy(m_pSendbuf,m_pSendbuf+local_03,m_buflen_sendbuf-local_03);
				}
				m_buflen_sendbuf-=local_03;
				if (m_buflen_sendbuf<0) {
					m_buflen_sendbuf=0;
				}
				g_pCMainControl->m_int_14416=g_pCMainControl->m_int_14416+local_03;
			}
		}
	}
	return;
}


void CHost::mf_CHost_0190(bool arg_0)
{
	if (arg_0) {
		mf_CHost_0180();
	}
	if (! (m_socket==0||!m_flgIsConnected) ) {
		shutdown(m_socket,1);
		closesocket(m_socket);
		g_int_unk506=g_int_unk506+1;
		m_socket=0;//INVALID_SOCKET;
		m_flgIsConnected=false;
		m_int_unk5=3600;
		if (! (!m_field_8D||m_field_94||m_flgIsBadPortZero_9) ) {
			m_int_unk5*=10;
		}
	}
	if (m_socket!=0) {
		closesocket(m_socket);
		m_socket=0;     //INVALID_SOCKET;
		g_int_unk506=g_int_unk506+1;
	}
	if (m_int_unk300>=0) {
		g_pCMainControl->GetWork(m_int_unk300)->mf_CWork_0010(false,false);
	}
	m_socket=0;//INVALID_SOCKET;
	m_buflen_sendbuf=0;
	m_allocsize_sendbuf=0;
	if (m_pSendbuf!=0) {
		free(m_pSendbuf);
	}
	m_pSendbuf=NULLPO;
	m_buflen_recvbuf=0;
	m_allocsize_recvbuf=0;
	if (m_pRecvbuf!=0) {
		free(m_pRecvbuf);
	}
	m_pRecvbuf=NULLPO;
	mf_CHost_0010();
	return;
}


void CHost::mf_CHost_0200()
{
	if (g_pCMainControl!=0) {
		WSAAsyncGetHostByName(g_pCMainControl->m_hwnd_unk32,GetWmsgOfs_gethostbyname()+1024,m_str_DDNSname.c_str(),/*(HOSTENT *)*/gbuf400_001,1024);
	}
	return;
}


void CHost::mf_CHost_0210(int arg_0,int arg_1)
{
	HOSTENT * local_00;
	if ((unsigned short)((unsigned int)arg_1>>16)!=0) {
		if (m_flgIsConnected) {
			mf_CHost_0190(true);
		}
		m_flgIsValid=false;
		return;
	}
	local_00=gethostbyname(m_str_DDNSname.c_str());
	if (local_00!=0) {
		char *tmp=*local_00->h_addr_list;
		char *local_01=tmp;
		m_ipaddr3.b1=local_01[0];
		m_ipaddr3.b2=local_01[1];
		m_ipaddr3.b3=local_01[2];
		m_ipaddr3.b4=local_01[3];
	}
	m_field_8E=false;
	return;
}


struct temprastruct {
        char    d1[64];
        char    d2[448];
};

int CHost::mf_CHost_0220(CHost * arg_0)
{
	int local_00;
	int local_01;
	int local_02;
	int local_03;
	char * local_04;
	char * local_05;
	int local_06;
	int local_07;

	//13と19で２つに分かれているかも
	char local_08[448];     //structの配列っぽいので書き直しが吉かも ちなみにいまの表現はﾀﾞﾒなので注意
	char local_09[64];
	char local_10[448];
	char local_11[64];
	char local_12[448];
	char local_13[64];

	char local_14[448];
	char local_15[64];
	char local_16[448];
	char local_17[64];
	char local_18[448];
	char local_19[64];

	if (!m_flgIsValid) {
		return -1;
	}

	*(((temprastruct *)&local_13)->d1)=*(((temprastruct *)&local_11)->d1)=*(((temprastruct *)&local_09)->d1)=0;
	*(((temprastruct *)&local_19)->d1)=*(((temprastruct *)&local_17)->d1)=*(((temprastruct *)&local_15)->d1)=0;

	local_00=1;
	strcpy(local_13,arg_0->m_sz_clusterword[0]);
	if (_mbsstr(arg_0->m_sz_clusterword[1],local_13)==0) {
		strcpy(local_13+local_00*512,arg_0->m_sz_clusterword[1]);
		local_00=local_00+1;
	}
	if (! (_mbsstr(arg_0->m_sz_clusterword[2],local_13)!=0||_mbsstr(arg_0->m_sz_clusterword[2],local_11)!=0) ) {
		strcpy(local_13+local_00*512,arg_0->m_sz_clusterword[2]);
	}
	local_00=1;
	strcpy(local_19,m_sz_clusterword[0]);
	if (_mbsstr(m_sz_clusterword[1],local_19)==0) {
		strcpy(local_19+local_00*512,m_sz_clusterword[1]);
		local_00=local_00+1;
	}
	if (! (_mbsstr(m_sz_clusterword[2],local_19)!=0||_mbsstr(m_sz_clusterword[2],local_17)!=0) ) {
		strcpy(local_19+local_00*512,m_sz_clusterword[2]);
	}

	local_12[0]=local_10[0]=local_08[0]=0;
	local_18[0]=local_16[0]=local_14[0]=0;
	local_03=0;
	for (local_02=0; local_02<3; local_02++) {
		local_04=local_19+local_02*512;
		if (strlen(local_04)<2) continue;
		for (local_01=0; local_01<3; local_01++) {
			local_05=local_13+local_01*512;
			if (strlen(local_05)<2||!(_mbsstr(local_05,local_04)!=0)&&_mbsstr(local_04,local_05)==0) continue;
			local_06=strlen(local_05);
			if (local_06<1) {
				local_06=1;
			}
			local_07=strlen(local_04);
			if (local_07<1) {
				local_07=1;
			}
			local_03=local_03+(!(local_06>=local_07)?local_06:local_07);
		}
	}
	return local_03;
}


