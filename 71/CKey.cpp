//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "hdrs.h"

#include <stdio.h>
#include <mbstring.h>
#include <time.h>
#include <io.h>
#include <dir.h>

#include <winsock2.h>

#include "def0.h"


#define NULLPO ((void *)0)
typedef void * PPROC;

class _in_addr
{
public:
	unsigned char b1;
	unsigned char b2;
	unsigned char b3;
	unsigned char b4;

	bool operator == (const _in_addr &rhs) const {
		return b1==rhs.b1 && b2==rhs.b2 && b3==rhs.b3 && b4==rhs.b4;
	}
};

struct struct_charptrd {
		char    d1[64];
		char    d2[448];
};

#include "CKey.h"
#include "CKeyBlock.h"


#include "RSA.h"


extern int                            g_TControlForm_inifincount   ;				//fr 0055648C 00000004 
extern char                   gbuf10000_211    [65536]       ;				//fr 00556490 00010000 
extern char                   gbuf10010_210    [65552]       ;				//fr 00566490 00010010 
extern char                   gbuf400_001      [1024]        ;				//fr 005764A0 00000400 
extern char                   gbuf400_002      [1024]        ;				//fr 005768A0 00000400 
extern unsigned char                   gbuf400_003      [1024]        ;				//fr 00576CA0 00000400
extern unsigned char                   gbuf7800_200     [30720]       ;				//fr 005770A0 00007800 
extern char                   gbuf400_004      [1024]        ;				//fr 0057E8A0 00000400 
extern char                   gbuf20000_201    [131072]      ;				//fr 0057ECA0 00020000 
extern unsigned char                   gbuf20000_202    [131072]      ;				//fr 0059ECA0 00020000

extern char                   gbuf_131072_unk1 [131072]      ;				//fr 005BECA0 00020000
extern char                   gbuf_1024_unk3   [1024]        ;				//fr 005DECA0 00000400 
extern char                   gbuf_8192_unk2   [8192]        ;				//fr 005DF0A0 00002000 
extern unsigned char              g_exesignature_defined     [16];				//fr 005E10A0 00000010 
extern unsigned char              g_memorysignature_compared [16]  ;				//fr 005E10B0 00000010 
extern char                   gbuf20000_r1          [131072] ;				//fr 005E10C0 00020000 
extern char                   gbuf_sendbuf          [131072] ;				//fr 006010C0 00020000 
extern char                   gbuf1000_memsigwork   [4096]   ;				//fr 006210C0 00001000 
extern char                   gbuf20000_hatena1     [131072] ;				//fr 006220C0 00020000 
extern char                   gbuf_recvbuf          [131072] ;				//fr 006420C0 00020000 
extern char                   gbuf20000_hatena2     [131072] ;				//fr 006620C0 00020000 
extern char                   gbuf20000_hatena3     [131072] ;				//fr 006820C0 00020000 
extern char                   gbuf20000_hatena4     [131072] ;				//fr 006A20C0 00020000 
extern char                   gbuf20000_hatena5     [131072] ;				//fr 006C20C0 00020000 
extern char                   gbuf20000_hatena6     [131072] ;				//fr 006E20C0 00020000 
extern char                   gbuf20000_hatena7     [131072] ;				//fr 007020C0 00020000 
extern char                   gbuf20000_hatena8     [131072] ;				//fr 007220C0 00020000 
extern char                   gbuf40000_1           [262144] ;				//fr 007420C0 00040000 
extern char                   gbuf40000_2           [262144] ;				//fr 007820C0 00040000 
extern char                   gbuf40000_3           [262144] ;				//fr 007C20C0 00040000 
extern char                   gbuf40000_4           [262144] ;				//fr 008020C0 00040000 
extern char                   gbuf20000_hatena01    [131072] ;				//fr 008420C0 00020000 
extern char                   gbuf40000_hatena02    [262144] ;				//fr 008620C0 00040000 
extern char                   gbuf40000_hatena03    [262144] ;				//fr 008A20C0 00040000 
extern char                   gbuf40000_hatena04    [262144] ;				//fr 008E20C0 00040000 
extern char                   gbuf20000_hatena05    [131072] ;				//fr 009220C0 00020000 
extern char                   gbuf20000_hatena06    [131072] ;				//fr 009420C0 00020000 

#include "util.h"

#include "CMainControl.h"
extern CMainControl *g_pCMainControl;

#include "globals.h"


const char *cryptkey="CHeader";

CRC4                           CKey::g_CRC4                 ;				//fr 0053ED38 00000303



CKey::CKey() : m_vectorUchar_()
{
	m_fileptr_=NULLPO;
	mf_CKey_0060();
}


CKey::~CKey()
{
	if (m_fileptr_!=0) {
		fclose(m_fileptr_);
	}
}


char * CKey::mf_CKey_0000()
{
	return m_char11_nazo2;
}


Bb CKey::mf_CKey_0010()
{
	char local_02[1024];
	unsigned char local_03[16];
	RSA local_00;
	char *src=m_char11_nazo2;
	strcpy(local_00.m_szstr,src);
	local_00.mf_RSA_0070();
	sprintf(local_02,"%11s#%s",m_char11_nazo2,mf_CKey_0260());
	MD5calc(local_02,local_03,strlen(local_02));
	local_03[3]=local_03[3]&127;
	int	local_01=*((int *)local_03);
	CLongInt local_04;
	CLongInt local_05;
	local_00.str2LongInt((const char *)m_char16_char11kamo,&local_04);
	local_05=_CLongInt_letint(local_01);
	return local_00.mf_RSA_0040(&local_04,&local_05);
}


int CKey::mf_CKey_0020()
{
	if (m_int_refcountOfFileptr_==0) {
		if (m_char_keyType_!=KEYTYPE02) {
			m_fileptr_=fopen(mf_CKey_0230().c_str(),"rb+");
			if (m_fileptr_!=0) goto ret;
			if (! (m_bln_unk308||m_char_keyType_==KEYTYPE00) ) {
				g_pCMainControl->m_int_cacheOpenErrorCount_=g_pCMainControl->m_int_cacheOpenErrorCount_+100;
			}
			mf_CKey_0130();
			m_fileptr_=fopen(mf_CKey_0230().c_str(),"wb");
			
			if (m_fileptr_!=0) {
				fclose(m_fileptr_);
				m_fileptr_=fopen(mf_CKey_0230().c_str(),"rb+");
				goto ret;
			}
			return 0;
		}
		if (m_bln_unk308) {
			m_fileptr_=fopen(mf_CKey_0230().c_str(),"rb+");
		} else {
			m_fileptr_=fopen(mf_CKey_0230().c_str(),"rb");
		}
	
	}
ret:
	m_int_refcountOfFileptr_=m_int_refcountOfFileptr_+1;
	return m_int_refcountOfFileptr_;
}


void CKey::mf_CKey_0030()
{
	if (m_int_refcountOfFileptr_>0) {
		m_int_refcountOfFileptr_=m_int_refcountOfFileptr_-1;
	}
	if (! (m_int_refcountOfFileptr_>0||m_fileptr_==0) ) {
		fclose(m_fileptr_);
		m_fileptr_=NULLPO;
	}
	return;
}


bool CKey::mf_CKey_0040(const char * arg_0,const char * arg_1,bool arg_2)
{
	int local_00;
	int local_01;
	int local_02;
	int local_03;
	bool local_04;
	unsigned char local_05[16];
	char local_06[120];

	if (! (arg_2||!m_bln_unk304) ) {
		return m_bln_unk303;
	}
	if (!arg_2) {
		m_bln_unk304=true;
	}

	local_00=strlen(arg_0);
	if (local_00==0) {
		if (!arg_2) {
			m_bln_unk303=true;
		}
		return true;
	}
	if (! (m_bln_unk308||local_00>=2) ) {
		return false;
	}
	m_bln_unk303=false;
	if (! ((int)*arg_0!='%'||local_00!=33) ) {
		ny_aschash2binhash(arg_0+1,local_05);
		if (memcmp((unsigned char *)m_hash_tabun,local_05,16)==0) {
			m_bln_unk303=true;
			return true;
		}
		return false;
	}

	if (*arg_1!=0) {
		if ((int)*arg_1=='#') {
			ny_htmlproc_5(arg_1+1,gbuf400_004);
			if (strcmp(m_char11_nazo2,gbuf400_004)!=0) {
				return false;
			}
			bool dummy;	//orphan jumpの再現用。これをしなくても、制御構造を変えれば出ると思われ
		} else {
			if (strcmp(m_char11_nazo2,arg_1)!=0) {
				return false;
			}
		}
	}

	strcpy(gbuf400_002,mf_CKey_0260());
	if ((unsigned char)gbuf400_002[0]=='@') {
		return false;
	}
	strcpy(gbuf400_003,arg_0);
	local_02=0;
	local_03=0;
	_mbslwr(gbuf400_002);
	_mbslwr(gbuf400_003);
	for (local_01=0; local_01<30; local_01++) {
		gbuf7800_200[local_01*1024]=0;
		*((int *)(local_06+local_01*4))=0;
	}
	local_04=false;
	for (local_01=0; local_01<local_00; local_01++) {
		if (! ((*(gbuf400_003+local_01)==0||(unsigned char)*(gbuf400_003+local_01)==' ')||!((unsigned char)*(gbuf400_003+local_01)!=129)&&(unsigned char)*((gbuf400_003+1)+local_01)=='@') ) {
			*((gbuf7800_200+local_02*1024)+local_03)=*(gbuf400_003+local_01);
			local_03=local_03+1;
			continue;
		}
		if (local_03<2) {
			local_03=0;
		}
		*((int *)(local_06+local_02*4))=local_03;
		*((gbuf7800_200+local_02*1024)+local_03)=0;
		if (local_03>=2) {
			if (*(gbuf7800_200+local_02*1024)!='-') {
				local_04=true;
			}
			if (local_02>=29) break;
			local_02=local_02+1;
		}
		local_03=0;
		if (*(gbuf400_003+local_01)==' ') continue;
		local_01=local_01+1;
	}
	if (! (!(!(local_02!=0)&&(local_03<2||(unsigned char)*(((struct_charptrd *)gbuf7800_200)->d1)=='-'))&&(local_02<=0||local_04)) ) {
		return false;
	}
	if (local_03<2) {
		local_03=0;
	}
	*((int *)(local_06+local_02*4))=local_03;
	*((gbuf7800_200+local_02*1024)+local_03)=0;
	for (local_03=0; local_03<=local_02; local_03++) {
		if (*(gbuf7800_200+local_03*1024)==0||!(gbuf7800_200[local_03*1024]!='-')&&*(gbuf7800_200+local_03*1024+1)==0) continue;
		if (gbuf7800_200[local_03*1024]=='-') {
			if (_mbsstr(gbuf400_002,&gbuf7800_200[local_03*1024+1])==0) continue;
			return false;
		}
		if (_mbsstr(gbuf400_002,&gbuf7800_200[local_03*1024])!=0) continue;
		return false;
	}
	if (!arg_2) {
		m_bln_unk303=true;
	}
	return true;

}



void CKey::mf_CKey_0050(time_t arg_0)
{
	double local_00;
	double local_01;
	double local_02;
	local_00=(double)(GetRefs())/10000000.0;
	if (local_00<0.0) {
		local_00=0.0;
	}
	local_01=(double)(int)((unsigned int)m_time_-((unsigned int)arg_0-0x000D2F00))/864000.0;
	if ((unsigned int)arg_0+0x00015180<(unsigned int)m_time_) {
		local_01=0.0;
	}
	local_02=(double)mf_CKey_0150()/(double)mf_CKey_0170();
	if (! (!(m_char_keyType_>=KEYTYPE02)&&!m_bln_unk308) ) {
		local_02=0.0;
	}
	double tmp=(double)m_uint_unk13/1000000000.0;
	m_float_unk15=
		local_00*g_pCMainControl->m_double_optDownParamRef_
		+local_01*g_pCMainControl->m_double_optDownParamTime_
		+local_02*g_pCMainControl->m_double_optDownParamBlock_
		+tmp*g_pCMainControl->m_double_optDownParamSize_;
	return;
}


float CKey::mf_CKey_0055()
{
	if (m_char_keyType_==KEYTYPE02) {
		return 1.0;
	}
	return (double)mf_CKey_0150()/(double)mf_CKey_0170();
}


void CKey::mf_CKey_0060()
{
	m_int_unk0x=0;
	m_uint_unk13=0;
	memset((unsigned char *)m_hash_tabun,0,16);
	m_vectorUchar_.clear();
	memset(m_sz_originalFilename_maybe__,0,258);
	memset(m_char258_unk1,0,258);
	memset(m_sz_filename_,0,36);
	m_bln_unk306=false;
	*m_char11_nazo2=0;
	m_char16_char11kamo[0]=0;
	m_int_unk16=0;
	m_ipaddr_0__.b1=127;
	m_ipaddr_0__.b2='^';
	m_ipaddr_0__.b3='^';
	m_ipaddr_0__.b4='_';
	m_portno_0__=0;
	m_ipaddr_1__.b1=127;
	m_ipaddr_1__.b2='^';
	m_ipaddr_1__.b3='^';
	m_ipaddr_1__.b4='_';
	m_portno_1__=0;
	m_ipaddr_2__.b1=127;
	m_ipaddr_2__.b2='^';
	m_ipaddr_2__.b3='^';
	m_ipaddr_2__.b4='_';
	m_portno_2__=0;
	m_uint_unk204=0x98765432;
	m_int_refcountOfFileptr_=0;
	m_int_unk200=0;
	m_int_unk205=0;
	m_int_unk14=0;
	m_bln_unk303=false;
	m_bln_unk304=false;
	m_bln_unk302=false;
	m_int_unk203=5;
	m_int_lenOriginalFilename_=0;
	m_bln_unk305=false;
	m_bln_unk307=false;
	m_bln_unk309=false;
	m_bln_unk310=false;
	m_bln_unk308=false;
	m_bln_unk301=false;
	m_bln_unk312=false;
	m_bln_unk311=false;
	m_bln_unk313=false;
	m_float_unk15=(float)0;
	m_uint_unk206=0;
	m_int_unk202=-1;
	m_bln_unk314=false;
	m_int_unk17=0;
	if (m_fileptr_!=0) {
		fclose(m_fileptr_);
	}
	m_fileptr_=NULLPO;
	return;
}


void CKey::mf_CKey_0070(char * arg_0,unsigned int arg_1,bool arg_2)
{
	char local_00[1024];
	m_int_lenOriginalFilename_=(int)arg_1;
	if (m_int_unk203==1) {
		strcpy(m_sz_originalFilename_maybe__,arg_0);
	} else {
		if (arg_2) {
			memcpy(m_sz_originalFilename_maybe__,arg_0,arg_1+2);
			*(m_sz_originalFilename_maybe__+arg_1+2)=0;
		} else {
			memcpy(m_sz_originalFilename_maybe__+2,arg_0,arg_1);
			*(m_sz_originalFilename_maybe__+arg_1+2)=0;
			*m_sz_originalFilename_maybe__=0;
			*(m_sz_originalFilename_maybe__+1)=0;
			if (m_char_keyType_==KEYTYPE02) {
				mf_CKey_0280(local_00,true);
				memcpy(m_sz_originalFilename_maybe__,local_00,arg_1+2);
			}
		}
	}
	m_bln_unk306=false;
	m_int_unk0x=1;
	return;
}


void CKey::mf_CKey_0080()
{
	if (! (m_int_unk0x==0||mf_CKey_0100()>0) ) {
		mf_CKey_0110();
	}
	return;
}


int CKey::mf_CKey_0090()
{
	FILE * local_00;
	int local_01;
	int local_02;
	mf_CKey_0020();
	local_00=m_fileptr_;
	if (m_char_keyType_==KEYTYPE02) {
		local_00=fopen(mf_CKey_0210().c_str(),"rb");
	}
	if (local_00==0) {
		mf_CKey_0030();
		return 0;
	}
	fseek(local_00,0,0);
	local_01=0;
	if (fread(gbuf20000_201,64,1,local_00)<1) {
		if (m_char_keyType_==KEYTYPE02) {
			fclose(local_00);
		}
		mf_CKey_0030();
		return 0;
	}
	g_CRC4.setupkey("header");
	g_CRC4.crypter(gbuf20000_201+16,48);
	local_01=local_01+64;
	local_02=*((int *)(gbuf20000_201+16));
	if (! (local_02==0x47470104||local_02==0x47470105||local_02==0x47470106) ) {
		if (m_char_keyType_==KEYTYPE02) {
			fclose(local_00);
		}
		mf_CKey_0030();
		return 0;
	}
	*m_char11_nazo2=0;
	m_bln_unk308=(bool)(((unsigned char)gbuf20000_201[61]>0)?true:false);
	memcpy(m_char11_nazo2,gbuf20000_201+48,11);
	*(m_char11_nazo2+(!(m_int_unk203<=5)?11:10))=0;
	if (local_02==0x47470104) {
		m_int_unk203=4;
	} else {
		if (local_02==0x47470105) {
			m_int_unk203=5;
		} else {
			m_int_unk203=6;
		}
	}
	if (m_char_keyType_==KEYTYPE02) {
		fclose(local_00);
	}
	mf_CKey_0030();
	return 1;
}



int CKey::mf_CKey_0100()
{
	FILE * local_00;
	int local_01;
	int local_02;
	unsigned	int local_03;
	bool local_04;
	int local_05;
	unsigned	int local_06;
	int local_07;
	unsigned char local_08[16];
	char local_09[32];

	mf_CKey_0020();
	local_00=m_fileptr_;
	if (m_char_keyType_==KEYTYPE02) {
		local_00=fopen(mf_CKey_0210().c_str(),"rb");
	}
	if (local_00==0) {
		mf_CKey_0030();
		return -1;
	}
	fseek(local_00,0,0);
	local_01=0;
	if (fread(gbuf20000_202,64,1,local_00)<1) {
		if (m_char_keyType_==KEYTYPE02) {
			fclose(local_00);
		}
		mf_CKey_0030();
		return 0;
	}
	g_CRC4.setupkey("header");
	g_CRC4.crypter(gbuf20000_202+16,4);
	local_01=local_01+4;
	local_02=*((int *)(gbuf20000_202+16));
	if (! (local_02==0x47470104||local_02==0x47470105||local_02==0x47470106) ) {
		if (m_char_keyType_==KEYTYPE02) {
			fclose(local_00);
		}
		mf_CKey_0030();
		return 0;
	}
	if (local_02==0x47470104) {
		g_CRC4.crypter(gbuf20000_202+20,44);
		local_01=local_01+60;
		m_int_unk203=4;
	} else {
		if (local_02==0x47470105) {
			g_CRC4.setupkey("adsfu6");
			g_CRC4.crypter(gbuf20000_202+20,44);
			local_01=local_01+60;
			m_int_unk203=5;
		} else {
			if (local_02==0x47470106) {
				g_CRC4.setupkey("adsfu6");
				g_CRC4.crypter(gbuf20000_202+20,44);
				local_01=local_01+60;
				m_int_unk203=6;
				memcpy(local_09,gbuf20000_202+20,12);
				local_09[12]=0;
				g_CRC4.setupkey(local_09);
			}
		}
	}
	*m_char11_nazo2=0;
	m_bln_unk308=(bool)(((unsigned char)gbuf20000_202[61]>0)?true:false);
	memcpy(m_char11_nazo2,gbuf20000_202+48,11);
	*(m_char11_nazo2+(!(m_int_unk203<=5)?11:10))=0;
	if (! (!m_bln_unk308||!(m_int_unk203!=6)&&*m_char11_nazo2!=0) ) {
		return 0;
	}
	m_int_lenOriginalFilename_=(int)((unsigned int)(unsigned char)gbuf20000_202[62]);
	if (! (!m_bln_unk308||m_int_lenOriginalFilename_<=240) ) {
		m_int_lenOriginalFilename_=240;
	}
	memcpy((unsigned char *)m_hash_tabun,gbuf20000_202+32,16);
	m_bln_unk302=(bool)(!(gbuf20000_202[63]<=0)?true:false);
	m_uint_unk13=*((unsigned int *)(gbuf20000_202+20));
	local_03=m_uint_unk13>>16;
	if (! (!(m_uint_unk13==0)&&(m_uint_unk13&0x0000FFFF)==0) ) {
		local_03=local_03+1;
	}
	local_04=false;
	m_uint_unk204=*((unsigned int *)(gbuf20000_202+24));
	if ((m_uint_unk204^0x98765432)>local_03*10000) {
		m_uint_unk204=0x98765432;
		local_04=true;
	}
	m_time_=*((time_t *)(gbuf20000_202+28));
	local_05=64;
	if (fread(gbuf20000_202+64,256,1,local_00)<1) {
		if (m_char_keyType_==KEYTYPE02) {
			fclose(local_00);
		}
		mf_CKey_0030();
		return 0;
	}
	g_CRC4.crypter(gbuf20000_202+local_05,256);
	if (m_bln_unk308) {
		memcpy(m_sz_originalFilename_maybe__,gbuf20000_202+64,m_int_lenOriginalFilename_+2);
		*(m_sz_originalFilename_maybe__+m_int_lenOriginalFilename_+2)=0;
		memcpy(m_char16_char11kamo,gbuf20000_202+305,11);
		m_char16_char11kamo[12]=0;
		m_int_unk17=*((int *)(gbuf20000_202+316));
	} else {
		memcpy(m_sz_originalFilename_maybe__,gbuf20000_202+64,m_int_lenOriginalFilename_+2);
		*(m_sz_originalFilename_maybe__+m_int_lenOriginalFilename_+2)=0;
	}
	local_05=local_05+256;
	local_01=local_01+256;
	if (! (*m_sz_originalFilename_maybe__!=0||m_sz_originalFilename_maybe__[1]!=0) ) {
		if (m_char_keyType_==KEYTYPE02) {
			fclose(local_00);
		}
		mf_CKey_0030();
		return 0;
	}
	if (fread(gbuf20000_202+local_05,local_03,1,local_00)<1) {
		if (m_char_keyType_==KEYTYPE02) {
			fclose(local_00);
		}
		mf_CKey_0030();
		return 0;
	}
	g_CRC4.crypter(gbuf20000_202+local_05,local_03);
	MD5calc(&gbuf20000_202[16],local_08,local_05+local_03-16);
	if (memcmp(gbuf20000_202,local_08,16)!=0) {
		if (m_char_keyType_==KEYTYPE02) {
			fclose(local_00);
		}
		mf_CKey_0030();
		return 0;
	}
	mf_CKey_0240(m_uint_unk13);
	local_01=(local_01+local_03);
	if (!local_04) {
		local_07=-1;
		for (local_06=0; local_06<local_03; local_06++) {
			if (gbuf20000_202[local_06+local_05]==0) continue;
			local_07=local_06;
		}
		m_vectorUchar_.resize(local_07+1);
		for (local_06=0; local_06<local_03; local_06++) {
			mf_CKey_0180(local_06,*(local_06+local_05+gbuf20000_202));
		}
	} else {
		for (local_06=0; local_06<local_03; local_06++) {
			mf_CKey_0180(local_06,0);
		}
	}
	local_01=local_01+16;
	if (m_char_keyType_==KEYTYPE02) {
		fclose(local_00);
	}
	mf_CKey_0030();
	if (!mf_CKey_0140()) {
		m_char_keyType_=KEYTYPE01;
	} else {
		m_char_keyType_=KEYTYPE03;
	}
	return local_01;
}


int CKey::mf_CKey_0110()
{
	FILE * local_00;
	int local_01;
	int local_02;
	int local_03;
	char local_04[20];
	char local_05[12];

	mf_CKey_0020();
	local_00=m_fileptr_;
	if (m_char_keyType_==KEYTYPE02) {
		if (m_bln_unk308) {
			mf_CKey_0030();
			return 0;
		}
		local_00=fopen(mf_CKey_0210().c_str(),"rb+");
		if (local_00==0) {
			mf_CKey_0130();
			local_00=fopen(mf_CKey_0210().c_str(),"wb");
		}
	}
	if (local_00==0) {
		mf_CKey_0030();
		mf_CKey_0060();
		return 0;
	}
	fseek(local_00,0,0);
	local_02=m_uint_unk13>>16;
	if (! (!(m_uint_unk13==0)&&(m_uint_unk13&0x0000FFFF)==0) ) {
		local_02=local_02+1;
	}
	if (local_02==1) {
		if (m_bln_unk308) {
			m_int_unk203=6;
		} else {
			m_int_unk203=5;
		}
	}
	for (local_01=0; local_01<64; local_01++) {
		*(gbuf_131072_unk1+local_01)=(char)(rand()%256);
	}
	if (m_int_unk203==4) {
		memcpy(gbuf_131072_unk1+16,&g_int_unk500,4);
	} else {
		if (m_int_unk203==5) {
			memcpy(gbuf_131072_unk1+16,&g_int_unk501,4);
		} else {
			memcpy(gbuf_131072_unk1+16,&g_int_unk502,4);
		}
	}
	memcpy(gbuf_131072_unk1+32,(unsigned char *)m_hash_tabun,16);
	memcpy(gbuf_131072_unk1+48,m_char11_nazo2,11);
	gbuf_131072_unk1[63]=(char)(m_bln_unk302?(char)1:(char)0);
	gbuf_131072_unk1[62]=*((char *)(&m_int_lenOriginalFilename_));
	gbuf_131072_unk1[61]=(char)(m_bln_unk308?(char)1:(char)0);
	memcpy(gbuf_131072_unk1+20,&m_uint_unk13,4);
	memcpy(gbuf_131072_unk1+24,&m_uint_unk204,4);
	memcpy(gbuf_131072_unk1+28,&m_time_,4);
	local_03=64;
	if (m_bln_unk308) {
		memcpy(gbuf_131072_unk1+local_03,m_sz_originalFilename_maybe__,241);
		memcpy((gbuf_131072_unk1+241)+local_03,m_char16_char11kamo,11);
		*((int *)((gbuf_131072_unk1+252)+local_03))=m_int_unk17;
	} else {
		memcpy(gbuf_131072_unk1+local_03,m_sz_originalFilename_maybe__,256);
	}
	local_03=local_03+256;
	for (local_01=0; local_01<local_02; local_01++) {
		*(local_01+local_03+gbuf_131072_unk1)=mf_CKey_0190(local_01);
	}
	MD5calc(&gbuf_131072_unk1[16],(unsigned char *)gbuf_131072_unk1,local_03+local_02+-16);
	if (m_int_unk203==4) {
		g_CRC4.setupkey("header");
		g_CRC4.crypter(gbuf_131072_unk1+16,local_03+local_02+-16);
	} else {
		if (m_int_unk203==5) {
			g_CRC4.setupkey("header");
			g_CRC4.crypter(gbuf_131072_unk1+16,4);
			g_CRC4.setupkey("adsfu6");
			g_CRC4.crypter(gbuf_131072_unk1+20,local_03+local_02+-20);
		} else {
			memcpy(local_05,gbuf_131072_unk1+20,12);
			local_04[0]=0;
			g_CRC4.setupkey("header");
			g_CRC4.crypter(gbuf_131072_unk1+16,4);
			g_CRC4.setupkey("adsfu6");
			g_CRC4.crypter(gbuf_131072_unk1+20,44);
			g_CRC4.setupkey(local_05);
			g_CRC4.crypter(gbuf_131072_unk1+64,local_03+local_02+-64);
		}
	}
	fwrite(gbuf_131072_unk1,local_03+local_02,1,local_00);
	if (m_char_keyType_==KEYTYPE02) {
		fclose(local_00);
	}
	mf_CKey_0030();
	return local_03+local_02;
}


void CKey::mf_CKey_0120()
{
	try {
		int local_00=m_uint_unk13>>16;
		if (! (!(m_uint_unk13==0)&&(m_uint_unk13&0x0000FFFF)==0) ) {
			local_00=local_00+1;
		}
		m_vectorUchar_.resize(0,0);
		m_int_unk202=local_00;
		if (m_char_keyType_==KEYTYPE01) {
			m_char_keyType_=KEYTYPE03;
		}
	}
	catch (std::bad_alloc ex_8) {
		m_int_unk0x=0;
	}
	return;
}


void CKey::mf_CKey_0130()
{
	try {
		m_vectorUchar_.resize(0,0);
		m_int_unk202=0;
		if (m_char_keyType_==KEYTYPE03) {
			m_char_keyType_=KEYTYPE01;
		}
	}
	catch (std::bad_alloc ex_8) {
		m_int_unk0x=0;
	}
	return;
}


Bb CKey::mf_CKey_0140()
{
	int local_00;
	local_00=m_uint_unk13>>16;
	if (! (!(m_uint_unk13==0)&&(m_uint_unk13&0x0000FFFF)==0) ) {
		local_00=local_00+1;
	}
	m_int_unk202=-1;
	return (bool)(mf_CKey_0150()==local_00);
}


sl CKey::mf_CKey_0150()
{
	int local_00;
	unsigned int local_01;
	int local_02;
	local_00=m_uint_unk13>>16;
	if (! (!(m_uint_unk13==0)&&(m_uint_unk13&0x0000FFFF)==0) ) {
		local_00=local_00+1;
	}
	if (m_int_unk202>=0) {
		return m_int_unk202;
	}
	local_02=0;
	for (local_01=0; m_vectorUchar_.size()>local_01; local_01++) {
		if (m_vectorUchar_[local_01]!=1) continue;
		local_02=local_02+1;
	}
	m_int_unk202=local_02;
	return local_02;
}


int CKey::mf_CKey_0160()
{
	int local_00;
	int local_01;
	int local_02;
	local_00=m_uint_unk13>>16;
	if (! (!(m_uint_unk13==0)&&(m_uint_unk13&0x0000FFFF)==0) ) {
		local_00=local_00+1;
	}
	local_02=0;
	for (local_01=m_vectorUchar_.size()-1; local_01>=0; local_01--) {
		if (m_vectorUchar_[local_01]!=1) continue;
		local_02=local_01+1;
		break;
	}
	return local_02;
}


unsigned int CKey::mf_CKey_0170()
{
	if (! (m_uint_unk13==0||(m_uint_unk13&0x0000FFFF)!=0) ) {
		return m_uint_unk13>>16;
	}
	return (m_uint_unk13>>16)+1;
}


void CKey::mf_CKey_0180(unsigned int arg_0,unsigned char arg_1)
{
	if (! (m_char_keyType_!=KEYTYPE03||arg_1!=0) ) {
		m_vectorUchar_.resize(mf_CKey_0170());
		for (unsigned int local_00=0; m_vectorUchar_.size()>local_00; local_00++) {
			m_vectorUchar_[local_00]=1;
		}
	}
	unsigned int local_01=(unsigned int)m_vectorUchar_.size();
	if ((unsigned int)arg_0>=local_01) {
		if (arg_1!=0) {
			m_vectorUchar_.resize(arg_0+1);
			//このへんインライン展開かも
			unsigned int local_02=local_01;
			if (local_02<(unsigned int)arg_0) {
				do {
					m_vectorUchar_[local_02]=0;
					local_02++;
				} while (local_02<(unsigned int)arg_0);
			}
			m_vectorUchar_[arg_0]=arg_1;
			m_int_unk202=-1;
		}
	} else {
		m_vectorUchar_[arg_0]=arg_1;
		m_int_unk202=-1;
	}
	return;
}


unsigned char CKey::mf_CKey_0190(int arg_0)
{
	if (m_char_keyType_==KEYTYPE03) {
		return 1;
	}
	if (m_vectorUchar_.size()>(unsigned int)arg_0) {
		return m_vectorUchar_[arg_0];
	}
	return 0;
}


void CKey::mf_CKey_0200(int arg_0,char * arg_1)
{
	char local_00[256];
	if (arg_0==0) {
		strcpy(arg_1,"header");
		return;
	}
	if (m_int_unk203==4) {
		*arg_1=0;
		return;
	}
	ny_binhash2aschash(m_hash_tabun,local_00);
	sprintf(arg_1,"%d %s",arg_0,local_00);
	return;
}


AnsiString CKey::mf_CKey_0210()
{
	if (! (m_char_keyType_!=KEYTYPE02||!m_bln_unk308) ) {
		return mf_CKey_0230();
	}
	mf_CKey_0220();
	sprintf(gbuf_1024_unk3,"%s\\%s",g_pCMainControl->m_sz_CacheFolderPath_,m_sz_filename_);
	return gbuf_1024_unk3;
}


void CKey::mf_CKey_0220()
{
	int local_00;
	char local_01[8];
	unsigned char local_02[16];
	for (local_00=0; local_00<16; local_00++) {
		if (m_hash_tabun[local_00]!=0) break;
	}
	if (local_00==16) {
		strcpy(m_sz_filename_,&m_sz_originalFilename_maybe__[2]);
		return;
	}
	g_CRC4.setupkey(cryptkey);
	memcpy(local_02,(unsigned char *)m_hash_tabun,16);
	g_CRC4.crypter((char *)local_02,16);
	strcpy(m_sz_filename_,"%");
	for (local_00=0; local_00<16; local_00++) {
		sprintf(local_01,"%02x",(unsigned int)local_02[local_00]);
		strcat(m_sz_filename_,local_01);
	}
	return;
}


AnsiString CKey::mf_CKey_0230()
{
	AnsiString local_00=("");
	if (m_char_keyType_==KEYTYPE02) {
		sprintf(gbuf_8192_unk2,"%s\\%s",g_pCMainControl->GetFolder(m_int_unk16)->Get_001_cstr(),mf_CKey_0260());
		local_00=gbuf_8192_unk2;
	} else {
		mf_CKey_0220();
		//参照されない文字定数をこれで作っちゃう
#ifdef EXACTMATCH
		sprintf(gbuf_8192_unk2,"%s\\%s\x00\x00%s\\%s\x00\x00%s\\%s",g_pCMainControl->m_sz_CacheFolderPath_,m_sz_filename_);
#else
		sprintf(gbuf_8192_unk2,"%s\\%s",g_pCMainControl->m_sz_CacheFolderPath_,m_sz_filename_);
#endif
		local_00=gbuf_8192_unk2;
	}
	return local_00;
}


//arg1はrectだと思ったが、int *扱いな模様。rect扱いのままでキャスト対応
void CKeyBlock::mf_CKeyBlock_0000(TCanvas * arg_0,TRect * arg_1)
{
	float local_00;
	TColor local_01;
	TColor local_02;
	int local_03;
	int local_04;
	TColor local_05;

	if (m_char_unk1!=0) {
		local_00=(double)(OptionForm->ColorTrackBar->Position+9)/10.0;
		local_01=(TColor)(((unsigned int)((unsigned char)((int)(255.0/local_00)))|(unsigned int)((unsigned short)((unsigned int)((unsigned char)((int)(255.0/local_00)))))<<8)|(unsigned int)((unsigned char)((int)(128.0/local_00)))<<16);
		local_02=(TColor)(((unsigned int)((unsigned char)((int)(128.0/local_00)))|(unsigned int)((unsigned short)((unsigned int)((unsigned char)((int)(128.0/local_00)))))<<8)|(unsigned int)((unsigned char)((int)(255.0/local_00)))<<16);
		local_03=(arg_1->Bottom-arg_1->Top)/10;
		((int *)arg_1)[1]/*->Top*/+=(local_03+1);
		((int *)arg_1)[3]/*->Bottom*/-=local_03;
		local_04=arg_1->Right-arg_1->Left;
		local_05=arg_0->Brush->Color;
		if (! (!((unsigned char)m_char_unk0==3)&&(unsigned char)m_char_unk0!=2) ) {
			arg_0->Brush->Color=local_01;
			TRect * local_06=arg_1;
			TRect local_12;
			local_12.Left=local_06->Left;
			local_12.Top=local_06->Top;
			local_12.Right=local_06->Right;
			local_12.Bottom=local_06->Bottom;
			arg_0->FillRect(local_12);
		} else {
			if (! (!(m_char_unk0<=0||m_int_unk3==0)&&m_int_unk2>=m_int_unk3) ) {
				arg_0->Brush->Color=local_02;
				TRect * local_07=arg_1;
				TRect local_13;
				local_13.Left=local_07->Left;
				local_13.Top=local_07->Top;
				local_13.Right=local_07->Right;
				local_13.Bottom=local_07->Bottom;
				arg_0->FillRect(local_13);
			} else {
				if (local_04<1) {
					local_04=1;
				}
				int local_08=m_int_unk2/local_04;
				if (local_08<1) {
					local_08=1;
				}
				if (m_int_unk2>0) {
					int local_09=0;
					while (local_09<m_int_unk2) {
												int local_10,local_11;
						if (local_04/4<m_int_unk2) {
							local_10=local_04*local_09/m_int_unk2;
							local_11=local_10+4;
							if (local_11>local_04) {
								local_11=local_04;
							}
						} else {
							local_10=local_04*local_09/m_int_unk2;
							local_11=(local_09+1)*local_04/m_int_unk2;
						}
						if (! (local_09>=m_int_unk2||(unsigned char)*(m_pchar_unk4+local_09)!=1) ) {
							arg_0->Brush->Color=local_01;
						} else {
							arg_0->Brush->Color=local_02;
						}
						TRect local_14x,local_18;
						local_14x.Left=arg_1->Left+local_10;
						local_14x.Top=arg_1->Top;
						local_14x.Right=arg_1->Left+local_11;
						local_14x.Bottom=arg_1->Bottom;
						local_18.Left=local_14x.Left;
						local_18.Top=local_14x.Top;
						local_18.Right=local_14x.Right;
						local_18.Bottom=local_14x.Bottom;

						arg_0->FillRect(local_18);
						local_09=local_09+local_08;
					}
				}
			}
		}
		arg_0->Brush->Color=local_05;
	}
	return;
}


void CKey::mf_CKey_0240(unsigned int arg_0)
{
	m_uint_unk13=arg_0;
	m_int_unk202=-1;
	return;
}


Bb CKey::mf_CKey_0250()
{
	if (m_int_unk0x==0) {
		return false;
	}
	if (! (m_char_keyType_==KEYTYPE03||m_char_keyType_==KEYTYPE01) ) {
		return false;
	}
	if (mf_CKey_0100()<=0) {
		return false;
	}
	if (!mf_CKey_0140()) {
		m_char_keyType_=KEYTYPE01;
		return false;
	}
	m_char_keyType_=KEYTYPE03;
	return true;
}


char * CKey::mf_CKey_0260()
{
	if (!m_bln_unk306) {
		mf_CKey_0280(m_char258_unk1,true);
		m_bln_unk306=true;
	}
	if (! (!(*m_char258_unk1!=0)&&m_char258_unk1[1]==0) ) {
		strcpy(m_char258_unk1+2,"@");
	}
	return m_char258_unk1+2;
}


void CKey::mf_CKey_0270(const char * arg_0,char * arg_1)
{
	int local_00;
	int local_01;
	bool local_02;
	int local_03;
	unsigned int local_04;
	char local_05[12];
	unsigned char local_06[2048];
	unsigned char local_07[2048];
	local_01=strlen(m_sz_originalFilename_maybe__);
	strcpy(local_06,m_sz_originalFilename_maybe__);
	local_02=false;
	if (local_06[0]=='@') {
		for (local_00=0; local_01/2>local_00; local_00++) {
			sscanf(local_06+1+local_00*2,"%2x",&local_03);
			*(local_06+local_00)=*((char *)(&local_03));
		}
		*(local_06+local_00)=0;
		local_02=true;
		local_01/=2;
	}
	local_04=0;
	local_05[11]=0;
	if (!local_02) {
		for (local_00=0; local_00<local_01; local_00++) {
			local_04+=(unsigned int)*(local_06+local_00);
		}
		local_04=local_04&255;
		local_07[1]=0;
		strcpy(local_07,arg_0);
		if (strlen(arg_0)!=1) {
			local_07[0]=*((char *)(&local_04));
		}
		g_CRC4.setupkey(local_07);
		g_CRC4.crypter(local_06,local_01);
		strcpy(local_07,"@");
		if (local_05[11]==0) {
			sprintf(local_05,"%02x",local_04);
			strcat(local_07,local_05);
			for (local_00=0; local_00<local_01; local_00++) {
				sprintf(local_05,"%02x",(unsigned int)*(local_06+local_00));
				strcat(local_07,local_05);
			}
		}
		strcpy(arg_1,local_07);
		return;
	}
	local_07[1]=0;
	strcpy(local_07,arg_0);
	if (strlen(arg_0)!=1) {
		local_07[0]=local_06[0];
	}
	g_CRC4.setupkey(local_07);
	g_CRC4.crypter(local_06+1,local_01-1);
	for (local_00=1; local_00<local_01; local_00++) {
		local_04+=(unsigned int)*(local_06+local_00);
		if (*(local_06+local_00)>=' ') continue;
		local_05[11]=1;
		break;
	}
	if (((unsigned int)*((unsigned char *)(&local_04))&255)==(unsigned int)local_06[0]) {
		strcpy(arg_1,&local_06[1]);
		return;
	}
	strcpy(arg_1,"@");
	return;
}


void CKey::mf_CKey_0280(char * arg_0,bool arg_1)
{
	int local_00;
	unsigned int local_01;
	unsigned char local_02[2048];
	char local_03[2048];
	local_01=0;
	memcpy(local_02,m_sz_originalFilename_maybe__,m_int_lenOriginalFilename_+2);
	if (! (local_02[0]!=0||local_02[1]!=0) ) {
		for (local_00=0; local_00<m_int_lenOriginalFilename_; local_00++) {
			local_01+=(unsigned int)*((local_02+2)+local_00);
		}
		local_03[1]=0;
		local_03[0]=*((char *)(&local_01))&255;
		g_CRC4.setupkey(local_03);
		g_CRC4.crypter(local_02+2,m_int_lenOriginalFilename_);
		*((unsigned short *)local_02)=local_01&0xffff;
		*((local_02+2)+m_int_lenOriginalFilename_)=0;
		if (arg_1) {
			memcpy(arg_0,local_02,m_int_lenOriginalFilename_+3);
			return;
		}
		memcpy(arg_0,local_02+2,m_int_lenOriginalFilename_+1);
		return;
	}
	local_03[1]=0;
	local_03[0]=local_02[0];
	g_CRC4.setupkey(local_03);
	g_CRC4.crypter(local_02+2,m_int_lenOriginalFilename_);
	for (local_00=0; local_00<m_int_lenOriginalFilename_; local_00++) {
		local_01=local_01+(unsigned int)*((local_02+2)+local_00);
	}
	if ((local_01&0x0000FFFF)==(unsigned int)*((unsigned short *)local_02)) {
		*((local_02+2)+m_int_lenOriginalFilename_)=0;
		local_02[0]=0;
		local_02[1]=0;
	} else {
		local_02[0]='@';
		local_02[1]=0;
		local_02[2]='@';
		local_02[3]=0;
	}
	if (arg_1) {
		memcpy(arg_0,local_02,m_int_lenOriginalFilename_+3);
		return;
	}
	memcpy(arg_0,local_02+2,m_int_lenOriginalFilename_+1);
	return;
}


void CKey::mf_CKey_0290()
{
	int local_00;
	local_00=m_vectorUchar_.size();
	if (local_00>=1) {
		m_vectorUchar_[local_00-1]=0;
		if (m_char_keyType_==KEYTYPE03) {
			m_char_keyType_=KEYTYPE01;
		}
		m_int_unk202=-1;
	}
	return;
}


