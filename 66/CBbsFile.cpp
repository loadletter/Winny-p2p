//---------------------------------------------------------------------------
#include "hdrs.h"

#include <vcl.h>
#pragma hdrstop

#include "def.h"

#include "CBbsFile.h"

#include "def2.h"



CBbsFile::CBbsFile()
{
	char local_00[512];
	sprintf(local_00,"%s%d","WinnyBBS 2.0b1 ",rand());
	m__unknown_001=local_00;
	m_pTMemoryStream=new TMemoryStream();
}


CBbsFile::~CBbsFile()
{
	if (m_pTMemoryStream!=0) {
		delete m_pTMemoryStream;
	}
}


bool CBbsFile::mf_CBbsFile_0000(CKey * arg_0)
{
	char local_05[131044];
	char local_06[12];
	char local_07[16];
	unsigned char local_08[16];
	char local_09[256];
	FILE *	local_01=fopen(mf_CBbsFile_0030().c_str(),"rb");
	if (local_01==0) {
		return false;
	}
	if (! (!(arg_0->mf_CKey_0090()==0||!arg_0->m_bln_unk308)&&arg_0->m_int_unk203==6) ) {
		fclose(local_01);
		return false;
	}
	arg_0->mf_CKey_0100();
	unsigned int	local_02=0;
	CRC4 local_00;
	for (int local_03=0; local_03<100; local_03++) {
		fseek(local_01,arg_0->mf_CKey_0170()+(local_03*0x00010010+320),0);
		arg_0->mf_CKey_0200(local_03,local_09);
		local_00.setupkey(local_09);
		int	local_04=fread(local_07,1,0x00010010,local_01);
		if (local_04<=16) break;
		local_00.crypter(local_06,local_04+-16);
		MD5calc(local_06,local_08,local_04+-16);
		if (memcmp(local_07,local_08,16)==0) {
			if (local_03==0) {
				m_pTMemoryStream->Write(local_05,local_04+-28);
				local_02+=(local_04-28);
				continue;
			}
			m_pTMemoryStream->Write(local_06,local_04+-16);
			local_02+=(local_04-16);
			continue;
		}
		fclose(local_01);
		return false;
	}
	fclose(local_01);
	arg_0->mf_CKey_0240(local_02);
	return true;
}



bool CBbsFile::mf_CBbsFile_0010(CKey * arg_0)
{
	int local_00;
	struct__finddata_t local_06;
	unsigned char local_07[65536];
	arg_0->m_uint_unk204=0x98765432;
	arg_0->mf_CKey_0240(0);
	if ((local_00=_findfirst(mf_CBbsFile_0030().c_str(),&local_06))>=0) {
                time_t tmptime=local_06.time_write;
		arg_0->m_time_=tmptime;
	}
	_findclose(local_00);
	FILE *	local_01=fopen(mf_CBbsFile_0030().c_str(),"rt");
	if (local_01==0) {
		return false;
	}
	m_pTMemoryStream->Clear();
	int	local_02=0;
	unsigned int local_03=0;
	fgets(local_07,0x00010000,local_01);
	if (strncmp(local_07,"WinnyBBS 2.0b1 ",strlen("WinnyBBS 2.0b1 "))!=0) {
		fclose(local_01);
		return false;
	}
	m__unknown_001=(char *)local_07;
	while (1) {
		int local_04=fread(local_07,1,0x0000FFFF,local_01);
		if (local_04==0) break;
		*(local_07+local_04)=0;
		for (unsigned char * local_05=local_07; *local_05!=0; local_05++) {
			if (! (*local_05==9||*local_05==10||*local_05>=' ') ) {
				fclose(local_01);
				return false;
			}
			if (*local_05!=10) continue;
			local_02=local_02+1;
		}
		local_03=local_03+local_04;
		m_pTMemoryStream->Write(local_07,local_04);
		if (m_pTMemoryStream->Size>=0x00100000) break;
	}
	fclose(local_01);
	arg_0->mf_CKey_0240(local_03);
	arg_0->SetRefs(local_02);
	return true;
}


bool CBbsFile::mf_CBbsFile_0020(CKey * arg_0)
{
	char local_02[65536];
	FILE *	local_00=fopen(mf_CBbsFile_0030().c_str(),"wt");
	if (local_00==0) {
		return false;
	}
	fputs(m__unknown_001.c_str(),local_00);
	m_pTMemoryStream->Seek(0,(unsigned short)0);
	while (true) {
	int	local_01=m_pTMemoryStream->Read(local_02,0x0000FFFF);
		if (local_01==0) break;
		fwrite(local_02,1,local_01,local_00);
	}
	fclose(local_00);
	mf_CBbsFile_0070(arg_0);
	return true;
}


AnsiString CBbsFile::mf_CBbsFile_0030()
{
	AnsiString local_00;
	local_00.sprintf("%s\\%s",g_pCMainControl->m_sz_BbsFolderPath_,m__unknown_000.c_str());
	return local_00;
}


void CBbsFile::mf_CBbsFile_0040(char * arg_0,CKey * arg_1,const char * arg_2,const char * arg_3,const char * arg_4)
{
	time_t local_00;
	time(&local_00);
	sprintf(arg_0,"%s\t%s\t%u\t%s\n",arg_2,arg_3,local_00,arg_4);
	return;
}


bool CBbsFile::mf_CBbsFile_0050(CKey * arg_0,char * arg_1)
{
	unsigned int local_00;
	unsigned char local_05[65536];
	local_00=arg_0->m_uint_unk13;
	if (strlen(arg_1)>=0x00010000) {
		return false;
	}
	unsigned char *	local_01=arg_1;
	unsigned char *	local_02=local_05;
	for ( ; *local_01!=0; local_01++) {
		if (! (!(*local_01>=' '||*local_01==10)&&*local_01!=9) ) {
			*local_02=*local_01;
			local_02=local_02+1;
		}
	}
	*local_02=0;
	int	local_03=strlen(local_05);
	FILE *	local_04=fopen(mf_CBbsFile_0030().c_str(),"at");
	if (local_04==0) {
		return false;
	}
	fputs(local_05,local_04);
	fclose(local_04);
	arg_0->mf_CKey_0240(local_00+local_03);
	time(&arg_0->m_time_);
	arg_0->SetRefs(arg_0->GetRefs()+1);
	return true;
}


bool CBbsFile::mf_CBbsFile_0060(unsigned int arg_0,char * arg_1)
{
	int local_00;
	int local_01;
	int local_02;
	char * local_03;
	char * local_04;
	local_00=arg_0+-4096;
	if (local_00<0) {
		local_00=0;
	}
	m_pTMemoryStream->Seek(local_00,(unsigned short)0);
	if (m_pTMemoryStream->Size==0) {
		return false;
	}
	gbuf10000_211[0]=0;
	local_01=m_pTMemoryStream->Read(gbuf10000_211,0x0000FFFF);
	local_02=strlen(arg_1);
	if (local_01>1) {
		for (local_03=arg_1+local_02-1; !(local_03<=arg_1)&&(int)*local_03!=9; local_03--) {
		}
		for (local_04=gbuf10000_211+local_01-1; !(gbuf10000_211>=local_04)&&(int)*local_04!=9; local_04--) {
		}
		if (strcmp(local_04+1,local_03+1)==0) {
			return true;
		}
	}
	return false;
}


void CBbsFile::mf_CBbsFile_0070(CKey * arg_0)
{
	int local_00;
	int local_01;
	int local_02;
	if (! (arg_0->m_int_unk0x==0||!arg_0->m_bln_unk308||arg_0->m_char_keyType_!=KEYTYPE02) ) {
		m_pTMemoryStream->Seek(0,(unsigned short)0);
		local_00=0;
		while (true) {
			local_01=m_pTMemoryStream->Read(gbuf10010_210,0x00010000);
			if (local_01<=0) break;
			for (local_02=0; local_02<local_01; local_02++) {
				if ((int)*(gbuf10010_210+local_02)!=10) continue;
				local_00=local_00+1;
			}
		}
		if (local_00>0) {
			arg_0->SetRefs(local_00);
		}
	}
	return;
}




