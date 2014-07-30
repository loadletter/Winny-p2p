//utility
//---------------------------------------------------------------------------
#include "hdrs.h"

#include <vcl.h>
#pragma hdrstop

#include "def.h"

#include "util.h"
#include "md5.h"
#include "CRC4.h"
#include "def2.h"

extern bool                           g_bool_unk100          ;				//fr 0053F438 00000001 


#include <IniFiles.hpp>
#include "CRC4.h"

#include "CMainControl.h"
#include "globals.h"


char                    gbuf10000_211[65536]          ;				//fr 00556490 00010000 
char                    gbuf10010_210[65552]          ;				//fr 00566490 00010010 
char                     gbuf400_001[1024]            ;				//fr 005764A0 00000400 
char                     gbuf400_002[1024]            ;				//fr 005768A0 00000400 
unsigned char                     gbuf400_003[1024]            ;				//fr 00576CA0 00000400
unsigned char                    gbuf7800_200[30720]           ;				//fr 005770A0 00007800
char                     gbuf400_004[1024]            ;				//fr 0057E8A0 00000400 
char                   gbuf20000_201[131072]          ;				//fr 0057ECA0 00020000 
unsigned char                   gbuf20000_202[131072]          ;				//fr 0059ECA0 00020000
char                   gbuf_131072_unk1[131072]       ;				//fr 005BECA0 00020000 
char                     gbuf_1024_unk3 [1024]        ;				//fr 005DECA0 00000400 
char                     gbuf_8192_unk2 [8192]        ;				//fr 005DF0A0 00002000 
unsigned char              g_exesignature_defined[16]   ;				//fr 005E10A0 00000010 
unsigned char              g_memorysignature_compared[16]   ;				//fr 005E10B0 00000010 
char                 gbuf20000_r1        [131072]     ;				//fr 005E10C0 00020000 
char                 gbuf_sendbuf        [131072]     ;				//fr 006010C0 00020000 
char                 gbuf1000_memsigwork [4096]       ;				//fr 006210C0 00001000 
char                 gbuf20000_hatena1   [131072]     ;				//fr 006220C0 00020000 
char                 gbuf_recvbuf        [131072]     ;				//fr 006420C0 00020000 
char                 gbuf20000_hatena2   [131072]     ;				//fr 006620C0 00020000 
char                 gbuf20000_hatena3   [131072]     ;				//fr 006820C0 00020000 
char                 gbuf20000_hatena4   [131072]     ;				//fr 006A20C0 00020000 
char                 gbuf20000_hatena5   [131072]     ;				//fr 006C20C0 00020000
char                 gbuf20000_hatena6   [131072]     ;				//fr 006E20C0 00020000 
char                 gbuf20000_hatena7   [131072]     ;				//fr 007020C0 00020000 
char                 gbuf20000_hatena8   [131072]     ;				//fr 007220C0 00020000 
char                 gbuf40000_1         [262144]     ;				//fr 007420C0 00040000 
char                 gbuf40000_2         [262144]     ;				//fr 007820C0 00040000 
char                 gbuf40000_3         [262144]     ;				//fr 007C20C0 00040000 
char                 gbuf40000_4         [262144]     ;				//fr 008020C0 00040000 
char                 gbuf20000_hatena01  [131072]     ;				//fr 008420C0 00020000 
char                 gbuf40000_hatena02  [262144]     ;				//fr 008620C0 00040000 
char                 gbuf40000_hatena03  [262144]     ;				//fr 008A20C0 00040000 
char                 gbuf40000_hatena04  [262144]     ;				//fr 008E20C0 00040000 
char                 gbuf20000_hatena05  [131072]     ;				//fr 009220C0 00020000 
char                 gbuf20000_hatena06  [131072]     ;				//fr 009420C0 00020000 
MD5CTX                         g_MD5CTX_1             ;				//fr 009620C0 00000058 
MD5CTX                         g_MD5CTX_2             ;				//fr 00962118 00000058 
_STL::vector<AnsiString>             g_Log                  ;				//fr 00962170 00000018 
AnsiString                     g_AppPath              ;				//fr 00962188 00000004 
char                 g_szstr_Version     [256]        ;				//fr 0096218C 00000100 


CKeyBlock             g_KeyBlocks[2][1000]         ;				//fr 0096228C 00007D00


int                         g_intarray2[2]            ;				//fr 00969F8C 00000008
char         g_listitemarray[2][1010][10][280]        ;				//fr 00969F94 00564DC0
int                   g_nazouintarray [2][1010]       ;				//fr 00ECED54 00001F90 

char                  g_nazocharbuf   [2][2000]       ;				//fr 00ED0CE4 000007D0

TIniFile *                     g_pTIniFile=NULL            ;				//fr 00549134 00000004 

int padding0002=0x14;
int padding0003=0x14;
int padding0004=0x19;

int                            g_opt_longFontSpace=15    ;				//fr 00549144 00000004 




bool ny_iskanji(char ch)
{
	return !((unsigned char)ch<129)&&(unsigned char)ch<=159||(unsigned char)ch>=224;
}



void ny_addlog(AnsiString logstr)
{
	char local_00[128];
	char local_01[128];
	char local_02[256];
	
	if (g_bool_unk100) {
		return;
	}
	if (g_Log.size()>500) {
		g_Log.clear();
	}
	_tzset();
	_strtime(local_00);
	_strdate(local_01);
	local_01[5]=0;
	if ((int)*((char *)logstr.c_str())==32) {
		sprintf(local_02,"  %s %s %s",local_01,local_00,logstr.c_str()+1);
	} else {
		sprintf(local_02,"* %s %s %s",local_01,local_00,/*(const char *)*/logstr);
	}
	g_Log.push_back(local_02);
	return;
}


void ny_logclear()
{
	g_Log.clear();
	ny_addlog(" ƒƒOÁ‹Ž");
	return;
}


void ny_sanketacomma(char * s)
{
	int local_00;
	int local_01;
	int local_02;
	char * local_03;
	char local_04[16];
	memset(local_04,32,14);
	local_04[14]=0;
	local_00=strlen(s)-1;
	local_01=13;
	local_02=0;
	while (local_00>=0) {
		*(local_04+local_01)=*(s+local_00);
		local_00=local_00-1;
		local_01=local_01-1;
		local_02=local_02+1;
		if (! (local_00<0||local_02%3!=0) ) {
			*(local_04+local_01)=',';
			local_01=local_01-1;
		}
	}
	for (local_03=local_04; (int)*local_03==32; local_03++) {
	}
	strcpy(s,local_03);
	return;
}



unsigned int ny_unknown_0000(const char * src)
{
	const char * local_00;
	char * local_01;
	int local_02;
	unsigned int local_03;
	char local_04[256];
	local_00=src;
	local_01=local_04;
	
	for (local_02=0; local_02<250; local_02++) {
		while ((int)*local_00==44) {
			local_00=local_00+1;
		}
		*local_01=*local_00;
		local_00=local_00+1;
		local_01=local_01+1;
		if (*local_00==0) break;
	}
	*local_01=0;
	sscanf(local_04,"%u",&local_03);
	return local_03;
}


void ny_aschash2binhash(const char * src_aschash,unsigned char * dest_binhash)
{
	int local_00;
	unsigned int local_01;
	for (local_00=0; local_00<16; local_00++) {
		if (sscanf(src_aschash+local_00*2,"%2x",&local_01)<=0) break;
		dest_binhash[local_00]=(unsigned char)local_01;
	}
	return;
}


void ny_binhash2aschash(unsigned char * src_binhash,char * dest_aschash)
{
	char local_00[4];
	int local_01;
	*dest_aschash=0;
	for (local_01=0; local_01<16; local_01++) {
		sprintf(local_00,"%02x",(unsigned int)src_binhash[local_01]);
		strcat(dest_aschash,local_00);
	}
	return;
}


void ny_htmlproc_1(char * src,char * dest,bool f1,bool f2)
{
	int local_00;
	int local_01;
	char local_02;
	char local_03;
	while (true) {
		if (*src==0) break;
		if ((int)*src==37) {
			if (*(src+1)==0||*(src+2)==0) break;
			local_00=0;
			sscanf(src+1,"%02x",&local_00);
			src=src+3;
			if (! (local_00!=60||f2) ) {
				strcpy(dest,"&lt;");
				dest=dest+4;
				continue;
			}
			if (! (local_00!=62||f2) ) {
				strcpy(dest,"&gt;");
				dest=dest+4;
				continue;
			}
			if (! (local_00!=38||f2) ) {
				strcpy(dest,"&amp;");
				dest=dest+5;
				continue;
			}
			if (! (local_00!=34||f2) ) {
				strcpy(dest,"&quot;");
				dest=dest+6;
				continue;
			}
			if (local_00==13) {
				if (f2) {
					strcpy(dest,"\n");
					dest=dest+1;
					continue;
				}
				if (f1) {
					strcpy(dest,"<br>");
					dest=dest+4;
					continue;
				}
				strcpy(dest,"%0D");
				dest=dest+3;
				continue;
			}
			if (ny_iskanji(*((char *)(&local_00)))) {
				local_01=0;
				if (! ((int)*src!=37||*(src+1)==0||*(src+2)==0) ) {
					sscanf(src+1,"%02x",&local_01);
					src=src+3;
				} else {
					local_01=(int)*src;
					src=src+1;
				}
				if (local_01<32) break;
				*dest=*((char *)(&local_00));
				dest=dest+1;
				*dest=*((char *)(&local_01));
				dest=dest+1;
				continue;
			}
			if (f1) {
				*dest=*((char *)(&local_00));
				dest=dest+1;
				continue;
			}
			if (local_00<32) continue;
			if (! (!f2||local_00<128) ) {
				*dest=*((char *)(&local_00));
				dest=dest+1;
				continue;
			}
			sprintf(dest,"%%%02X",local_00);
			dest=dest+3;
			continue;
		}
		if ((int)*src==43) {
			*dest=' ';
			dest=dest+1;
			src=src+1;
			continue;
		}
		local_02=*src;
		src=src+1;
		if (ny_iskanji(local_02)) {
			local_03=*src;
			src=src+1;
			if ((unsigned char)local_03<' ') continue;
			*dest=local_02;
			dest=dest+1;
			*dest=local_03;
			dest=dest+1;
			continue;
		}
		if (isprint((unsigned int)(unsigned char)local_02)==0) continue;
		*dest=local_02;
		dest=dest+1;
	}
	*dest=0;
	return;
}


void ny_htmlproc_2(const char * src,char * dest)
{
	unsigned char local_00;
	while (true) {
		if (*src==0) break;
		local_00=*src;
		if (ny_iskanji(local_00)) {
			sprintf(dest,"%%%02x",(unsigned int)local_00);
			dest=dest+3;
			src=src+1;
			local_00=*src;
			if (local_00==0) continue;
			sprintf(dest,"%%%02x",(unsigned int)local_00);
			dest=dest+3;
			src=src+1;
			continue;
		}
		*dest=*((char *)src);
		src=src+1;
		dest=dest+1;
	}
	*dest=0;
	return;
}


void ny_htmlproc_3(char * src,char * dest)
{
	while (true) {
		if (*src==0) break;
		if ((int)*src==60) {
			strcpy(dest,"&lt;");
			dest=dest+4;
			src=src+1;
			continue;
		}
		if ((int)*src==62) {
			strcpy(dest,"&gt;");
			dest=dest+4;
			src=src+1;
			continue;
		}
		if ((int)*src==34) {
			strcpy(dest,"&quot;");
			dest=dest+6;
			src=src+1;
			continue;
		}
		if ((int)*src==38) {
			strcpy(dest,"&amp;");
			dest=dest+5;
			src=src+1;
			continue;
		}
		*dest=*src;
		src=src+1;
		dest=dest+1;
	}
	*dest=0;
	return;
}


void ny_htmlproc_4(char * src,char * dest)
{
	while (true) {
		if (*src==0) break;
		if (strncmp(src,"&lt;",4)==0) {
			strcpy(dest,"<");
			dest=dest+1;
			src=src+4;
			continue;
		}
		if (strncmp(src,"&gt;",4)==0) {
			strcpy(dest,">");
			dest=dest+1;
			src=src+4;
			continue;
		}
		if (strncmp(src,"&quot;",6)==0) {
			strcpy(dest,"\"");
			dest=dest+1;
			src=src+6;
			continue;
		}
		if (strncmp(src,"&amp;",5)==0) {
			strcpy(dest,"&");
			dest=dest+1;
			src=src+5;
			continue;
		}
		*dest=*src;
		src=src+1;
		dest=dest+1;
	}
	*dest=0;
	return;
}


void ny_htmlproc_5(const char * src,char * dest)
{
	const char * local_00;
	int local_01;
	int local_02;
	unsigned char local_03[16];
	MD5calc(src,local_03,strlen(src));
	local_00="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	local_01=strlen(local_00);
	for (local_02=0; local_02<10; local_02++) {
		*dest=*((char *)(local_00+(int)(unsigned char)local_03[local_02]%local_01));
		dest=dest+1;
	}
	*dest=0;
	return;
}


void ny_decryptstring(const char * src,char * dest)
{
	int local_00;
	int local_01;
	local_01=strlen(src)/3;
	for (local_00=0; local_00<local_01; local_00++) {
		*(dest+local_00)=*(src+(local_00*3+1))-1;
	}
	*(dest+local_00)=0;
	return;
}


void ny_unknown_0010(char * arg_0,time_t arg_1)
{
	struct tm * local_00;
	int local_01;
	int local_02;
	*arg_0=0;
	for (local_01=0; local_01<5; local_01++) {
		local_00=localtime(&arg_1);
		if (local_00==0) continue;
		local_02=local_00->tm_year+-100;
		if (local_02<0) {
			local_02=local_00->tm_year;
		}
		sprintf(arg_0,"%02d/%02d/%02d %02d:%02d",local_02,local_00->tm_mon+1,local_00->tm_mday,local_00->tm_hour,local_00->tm_min);
		return;
	}
	return;
}


void ny_unknown_0020(const unsigned char * arg_0,char * arg_1)
{
	bool local_00;
	local_00=false;
	while (*arg_0!=0) {
		if (local_00) {
			*arg_1=*arg_0;
			arg_0=arg_0+1;
			arg_1=arg_1+1;
			local_00=false;
		} else {
			if (ny_iskanji(*arg_0)) {
				local_00=true;
				*arg_1=*arg_0;
				arg_0=arg_0+1;
				arg_1=arg_1+1;
			} else {
				if (*arg_0=='%') {
					strcpy(arg_1,"%25");
					arg_1=arg_1+3;
					arg_0=arg_0+1;
				} else {
					if (*arg_0=='+') {
						strcpy(arg_1,"%2B");
						arg_1=arg_1+3;
						arg_0=arg_0+1;
					} else {
						if (*arg_0==10) {
							strcpy(arg_1,"%0D");
							arg_1=arg_1+3;
							arg_0=arg_0+1;
						} else {
							if (! (*arg_0<' '||(unsigned char)*arg_0>=128) ) {
								*arg_1=*arg_0;
								arg_0=arg_0+1;
								arg_1=arg_1+1;
							} else {
								if (*arg_0>=' ') {
									sprintf(arg_1,"%%%02X",(unsigned int)*arg_0);
									arg_1=arg_1+3;
								}
								arg_0=arg_0+1;
							}
						}
					}
				}
			}
		}
	}
	*arg_1=0;
	return;
}


int ny_colordiff(TColor color1,TColor color2)
{
	int c1r=(unsigned int)((unsigned char)((unsigned int)color1>>16));
	int c2r=(unsigned int)((unsigned char)((unsigned int)color2>>16));
	int c1g=(unsigned int)((unsigned char)((int)*((unsigned short *)(&color1))>>8));
	int c2g=(unsigned int)((unsigned char)((int)*((unsigned short *)(&color2))>>8));
	int c1b=(unsigned int)*((unsigned char *)(&color1));
	int c2b=(unsigned int)*((unsigned char *)(&color2));

	return (int) (
		fabs((double)(c1r-c2r))
		+fabs((double)(c1g-c2g))
		+fabs((double)(c1b-c2b))
		);
}


void ny_nazo(double fd)
{
	return;
}



