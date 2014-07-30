//---------------------------------------------------------------------------
#include "hdrs.h"

//#include <vcl.h>
#pragma hdrstop

#include <system.hpp>

#include "def0.h"
#include <stdio.h>


#include "RSA.h"

#include "CRC4.h"



RSA::RSA()
{
}


RSA::~RSA()
{
}


void RSA::mf_RSA_0000(const char * arg_0)
{
	CLongInt local_00;
	CLongInt local_01;
	unsigned char local_02[16];

	MD5calc(arg_0,local_02,strlen(arg_0));
	mf_RSA_0020(local_02,&local_00,&local_01);
	mf_RSA_0010(&local_00,&local_01);
	return;
}



void RSA::mf_RSA_0010(CLongInt * arg_0,CLongInt * arg_1)
{
	int local_00;
	CLongInt local_01;
	CLongInt local_02;
	CLongInt local_03;
	CLongInt local_04;
	CLongInt local_05;
	CLongInt local_06;
	CLongInt local_07;
	CLongInt local_08;
	CLongInt local_09;
	local_09=_CLongInt_letint(100);
	local_08=_CLongInt_letint(1);
	local_01=_CLongInt_letint(0x00010001);
	local_02=*arg_0;
	local_03=*arg_1;

	for (local_00=0; local_00<100; local_00++) {
		while (_CLongInt__isprime(local_02)==0) {
			local_02.addchunk(1);
		}
		local_06=_CLongInt__subint(local_02,1);
		while (_CLongInt__isprime(local_03)==0) {
			local_03.addchunk(1);
		}
		local_07=_CLongInt__subint(local_03,1);
		m__unknown_000=_CLongInt__mult(local_02,local_03);
		local_04=_CLongInt__lcm(local_06,local_07);
		if (_CLongInt__abscompare(_CLongInt__mult(local_01,local_04),_CLongInt__lcm(local_01,local_04))!=0) {
			local_02.addchunk(1);
		} else {
			m__unknown_001=_CLongInt__modinv(local_01,local_04);
			if (_CLongInt__abscompare(_CLongInt__divremain(_CLongInt__mult(m__unknown_001,local_01),local_04),local_08)==0) {
				local_05=_CLongInt__powermod(local_09,m__unknown_001,m__unknown_000);
				if (_CLongInt__abscompare(_CLongInt__powermod(local_05,local_01,m__unknown_000),local_09)==0) break;
				local_02.addchunk(1);
			}
		}
	}
	mf_RSA_0060();
	return;
}


void RSA::mf_RSA_0020(unsigned char * arg_0,CLongInt * arg_1,CLongInt * arg_2)
{
	int local_00;
	int local_01;
	char local_02[64];
	local_00=*((int *)arg_0);
	local_00=local_00&0x7FFFFFFF;
	sprintf(local_02,"%u",local_00+0x3B9ACA00);
	*arg_1=_CLongInt__loadstr(local_02);
	local_01=*((int *)(arg_0+8));
	local_01=local_01&0x7FFFFFFF;
	sprintf(local_02,"%u",local_01+0x3B9ACA00);
	*arg_2=_CLongInt__loadstr(local_02);
	return;
}


CLongInt RSA::mf_RSA_0030(CLongInt * arg_0)
{
	CLongInt tmp=_CLongInt__powermod(*arg_0,m__unknown_001,m__unknown_000);
	return tmp;
}


Bb RSA::mf_RSA_0040(CLongInt * arg_0,CLongInt * arg_1)
{
	CLongInt tmp0=_CLongInt_letint(0x00010001);
	CLongInt tmp1=_CLongInt__powermod(*arg_0,tmp0,m__unknown_000);
	return (bool)(_CLongInt__abscompare(tmp1,*arg_1)==0);
}


void RSA::mf_RSA_0050(CLongInt arg_0,char * arg_1)
{
	CLongInt local_04=_CLongInt_letint(64);
	CLongInt local_05;
	CLongInt local_06;
	char local_07[64];
	const char *local_01="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+!";

	int local_02;
	char * local_03;

	local_03=local_07;
	for (local_02=0; local_02<4; local_02++) {
		local_06=_CLongInt__div(arg_0,local_04,&local_05);
		*local_03=*(local_01+_CLongInt__toint(local_05));
		arg_0=local_06;
		local_03=local_03+1;
	}
	*local_03=0;
	CRC4 local_00;
	local_00.setupkey(local_07);
	memcpy(arg_1,local_07,4);
	local_03=arg_1+4;
	for (local_02=4; local_02<11; local_02++) {
		local_06=_CLongInt__div(arg_0,local_04,&local_05);
		*local_03=(char)_CLongInt__toint(local_05);
		arg_0=local_06;
		local_03=local_03+1;
	}
	for (local_02=10; local_02>=4; local_02--) {
		*(arg_1+local_02)=*(local_01+((int)local_00.mf_CRC4_0000()+(int)*(arg_1+local_02))%64);
	}
	*local_03=0;
	return;
}


void RSA::mf_RSA_0060()
{
	mf_RSA_0050(m__unknown_000,m_szstr);
	return;
}


void RSA::str2LongInt(const char * src,CLongInt * result)
{
	char local_06[64];
	*result=_CLongInt_letint(0);
	CLongInt local_07=_CLongInt_letint(64);
	CLongInt local_08;
	CLongInt local_09;

	int local_01;
	int local_02;
	const char *local_03="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+!";
	const unsigned char * local_04;

	memcpy(local_06,src,4);
	local_06[4]=0;
	CRC4 local_00;
	local_00.setupkey(local_06);
	local_04=src+11;
	local_01=10;
	while (1) {
		local_04=local_04+-1;
		*result=_CLongInt__mult(*result,local_07);
		for (local_02=0; local_02<64; local_02++) {
			if ((unsigned int)*local_04!=(unsigned int)local_03[local_02]) continue;
			int local_05=local_02;
			if (local_01>3) {
				local_05=(local_02+320-(local_00.mf_CRC4_0000()))%64;
			}
			result->_CLongInt_addint(local_05);
			break;
		}
		if (local_04<=src) break;
		local_01=local_01-1;
	}
	return;
}


void RSA::mf_RSA_0070()
{
	str2LongInt(m_szstr,&m__unknown_000);
	return;
}



