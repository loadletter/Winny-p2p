//md5
//---------------------------------------------------------------------------
#include "hdrs.h"

#include <vcl.h>
#pragma hdrstop

#include "def.h"


#include "md5.h"

extern MD5CTX g_MD5CTX_1;
extern MD5CTX g_MD5CTX_2;


//ÇÊÇ≠ÇÌÇ©ÇÁÇÒÇ™ÅAstatic dataÇ™Ç†ÇÈñÕól

const char *notused_001="";
const int notused_002[]={  0x0D98C1DD4, 0x4B2008F, 0x980980E9, 0x7E42F8EC };
const char *notused_003="a";
const char notused_004[]={ 0x0C,0xC1,0x75,0xB9,0xC0,0xF1,0xB6,0xA8,0x31,0xC3,0x99,0xE2,0x69,0x77,0x26,0x61 };
const char *notused_005="abc";
const char notused_006[]={ 0x90,0x01,0x50,0x98,0x3C,0xD2,0x4F,0xB0,0xD6,0x96,0x3F,0x7D,0x28,0xE1,0x7F,0x72 };
const char *notused_007="message digest";
const char notused_008[]={ 0xF9,0x6B,0x69,0x7D,0x7C,0xB7,0x93,0x8D,0x52,0x5A,0x2F,0x31,0xAA,0xF1,0x61,0xD0 };
const char *notused_009="abcdefghijklmnopqrstuvwxyz";
const char notused_010[]={ 0xC3,0xFC,0xD3,0xD7,0x61,0x92,0xE4,0x00,0x7D,0xFB,0x49,0x6C,0xCA,0x67,0xE1,0x3B };
const char *notused_011="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
const char notused_012[]={ 0xD1,0x74,0xAB,0x98,0xD2,0x77,0xD9,0xF5,0xA5,0x61,0x1C,0x2C,0x9F,0x41,0x9D,0x9F };
const char *notused_013="12345678901234567890123456789012345678901234567890123456789012345678901234567890";
const char notused_014[]={ 0x57,0xED,0xF4,0xA2,0x2B,0xE3,0xC9,0x55,0xAC,0x49,0xDA,0x2E,0x21,0x07,0xB6,0x7A };
const int notused_015[]={ 0,0,0,0 };




void MD5sub(unsigned char * buf,unsigned int d2)
{
	do {
#ifdef EXACTMATCH
		int tmp=((unsigned int)*(buf+1)<<8|(unsigned int)*buf)|((unsigned int)*(buf+3)<<8|(unsigned int)*(buf+2))<<16;
		*((int *)buf)=tmp;
#else
		*((int *)buf)=((unsigned int)*(buf+1)<<8|(unsigned int)*buf)|((unsigned int)*(buf+3)<<8|(unsigned int)*(buf+2))<<16;
#endif
		buf=buf+4;
	} while (--d2!=0);
	return;
}


ul MD5step(unsigned int d1,unsigned int d2,unsigned int d3,unsigned int d4,unsigned int d5)
{
	d2+=d1+d4;
	d2=(d2<<d5)|(d2>>32-d5);
	d2=d2+d3;
	return d2;
}


void MD5init(MD5CTX * context)
{
	context->state[0]=0x67452301;
	context->state[1]=0xEFCDAB89;
	context->state[2]=0x98BADCFE;
	context->state[3]=0x10325476;
	context->count[0]=0;
	context->count[1]=0;
	return;
}


void MD5update(MD5CTX * context,const char * buf,unsigned int len)
{
	unsigned int local_00;
	unsigned char * local_01;

	local_00=context->count[0];
	if ((context->count[0]=(len<<3)+local_00)<(unsigned int)local_00) {
		context->count[1]=context->count[1]+1;
	}
	context->count[1]=context->count[1]+(len>>29);
	local_00=local_00>>3&63;
	if (local_00!=0) {
		local_01=context->buffer+local_00;
		local_00=64-local_00;
		if ((unsigned int)len<local_00) {
			memcpy(local_01,buf,len);
			return;
		}
		memcpy(local_01,buf,local_00);
		MD5sub(context->buffer,16);
		MD5transform(context->state,context->buffer);
		buf=buf+local_00;
		len-=local_00;
	}
	while (len>=64) {
		memcpy(context->buffer,buf,64);
		MD5sub(context->buffer,16);
		MD5transform(context->state,context->buffer);
		buf=buf+64;
		len-=64;
	}
	memcpy(context->buffer,buf,len);
	return;
}


void MD5final(unsigned char * digest,MD5CTX * context)
{
	unsigned int local_00;
	unsigned char * local_01;
	local_00=context->count[0]>>3&63;
	local_01=context->buffer+local_00;
	*local_01=128;
	local_01=local_01+1;
	local_00=63-local_00;
	if (local_00<8) {
		memset(local_01,0,local_00);
		MD5sub(context->buffer,16);
		MD5transform(context->state,context->buffer);
		memset(context->buffer,0,56);
	} else {
		memset(local_01,0,local_00-8);
	}
	MD5sub(context->buffer,14);
	*((unsigned int *)(context->buffer+56))=context->count[0];
	*((unsigned int *)(context->buffer+60))=context->count[1];
	MD5transform(context->state,context->buffer);
	MD5sub((unsigned char *)context,4);
	memcpy(digest,context,16);
	memset(context,0,4);
	return;
}


void MD5transform(unsigned int * state,unsigned char * block)
{
	unsigned int local_00;
	unsigned int local_01;
	unsigned int local_02;
	unsigned int local_03;
	local_00=state[0];
	local_01=state[1];
	local_02=state[2];
	local_03=state[3];
	MD5trans1(&local_00,&local_01,&local_02,&local_03,block);
	MD5trans2(&local_00,&local_01,&local_02,&local_03,block);
	MD5trans3(&local_00,&local_01,&local_02,&local_03,block);
	MD5trans4(&local_00,&local_01,&local_02,&local_03,block);
	state[0]=state[0]+local_00;
	state[1]=state[1]+local_01;
	state[2]=state[2]+local_02;
	state[3]=state[3]+local_03;
	return;
}


void MD5trans1(unsigned int * d1,unsigned int * d2,unsigned int * d3,unsigned int * d4,unsigned char * block)
{
	*d1=MD5step(((*d3^*d4)&*d2)^*d4,*d1,*d2,*((unsigned int *)block)+0xD76AA478,7);
	*d4=MD5step(*d3^((*d3^*d2)&*d1),*d4,*d1,*((unsigned int *)(block+4))+0xE8C7B756,12);
	*d3=MD5step((*d4&(*d1^*d2))^*d2,*d3,*d4,*((unsigned int *)(block+8))+0x242070DB,17);
	*d2=MD5step((*d3&(*d4^*d1))^*d1,*d2,*d3,*((unsigned int *)(block+12))+0xC1BDCEEE,22);
	*d1=MD5step(((*d3^*d4)&*d2)^*d4,*d1,*d2,*((unsigned int *)(block+16))+0xF57C0FAF,7);
	*d4=MD5step(*d3^((*d3^*d2)&*d1),*d4,*d1,*((unsigned int *)(block+20))+0x4787C62A,12);
	*d3=MD5step((*d4&(*d1^*d2))^*d2,*d3,*d4,*((unsigned int *)(block+24))+0xA8304613,17);
	*d2=MD5step((*d3&(*d4^*d1))^*d1,*d2,*d3,*((unsigned int *)(block+28))+0xFD469501,22);
	*d1=MD5step(((*d3^*d4)&*d2)^*d4,*d1,*d2,*((unsigned int *)(block+32))+0x698098D8,7);
	*d4=MD5step(*d3^((*d3^*d2)&*d1),*d4,*d1,*((unsigned int *)(block+36))+0x8B44F7AF,12);
	*d3=MD5step((*d4&(*d1^*d2))^*d2,*d3,*d4,*((unsigned int *)(block+40))+0xffff5bb1/*-42063*/,17);
	*d2=MD5step((*d3&(*d4^*d1))^*d1,*d2,*d3,*((unsigned int *)(block+44))+0x895CD7BE,22);
	*d1=MD5step(((*d3^*d4)&*d2)^*d4,*d1,*d2,*((unsigned int *)(block+48))+0x6B901122,7);
	*d4=MD5step(*d3^((*d3^*d2)&*d1),*d4,*d1,*((unsigned int *)(block+52))+0xFD987193,12);
	*d3=MD5step((*d4&(*d1^*d2))^*d2,*d3,*d4,*((unsigned int *)(block+56))+0xA679438E,17);
	*d2=MD5step((*d3&(*d4^*d1))^*d1,*d2,*d3,*((unsigned int *)(block+60))+0x49B40821,22);
	return;
}


void MD5trans2(unsigned int * d1,unsigned int * d2,unsigned int * d3,unsigned int * d4,unsigned char * block)
{
	*d1=MD5step((*d4&(*d3^*d2))^*d3,*d1,*d2,*((unsigned int *)(block+4))+0xF61E2562,5);
	*d4=MD5step((*d3&(*d1^*d2))^*d2,*d4,*d1,*((unsigned int *)(block+24))+0xC040B340,9);
	*d3=MD5step(((*d4^*d1)&*d2)^*d1,*d3,*d4,*((unsigned int *)(block+44))+0x265E5A51,14);
	*d2=MD5step(((*d3^*d4)&*d1)^*d4,*d2,*d3,*((unsigned int *)block)+0xE9B6C7AA,20);
	*d1=MD5step((*d4&(*d3^*d2))^*d3,*d1,*d2,*((unsigned int *)(block+20))+0xD62F105D,5);
	*d4=MD5step((*d3&(*d1^*d2))^*d2,*d4,*d1,*((unsigned int *)(block+40))+0x02441453,9);
	*d3=MD5step(((*d4^*d1)&*d2)^*d1,*d3,*d4,*((unsigned int *)(block+60))+0xD8A1E681,14);
	*d2=MD5step(((*d3^*d4)&*d1)^*d4,*d2,*d3,*((unsigned int *)(block+16))+0xE7D3FBC8,20);
	*d1=MD5step((*d4&(*d3^*d2))^*d3,*d1,*d2,*((unsigned int *)(block+36))+0x21E1CDE6,5);
	*d4=MD5step((*d3&(*d1^*d2))^*d2,*d4,*d1,*((unsigned int *)(block+56))+0xC33707D6,9);
	*d3=MD5step(((*d4^*d1)&*d2)^*d1,*d3,*d4,*((unsigned int *)(block+12))+0xF4D50D87,14);
	*d2=MD5step(((*d3^*d4)&*d1)^*d4,*d2,*d3,*((unsigned int *)(block+32))+0x455A14ED,20);
	*d1=MD5step((*d4&(*d3^*d2))^*d3,*d1,*d2,*((unsigned int *)(block+52))+0xA9E3E905,5);
	*d4=MD5step((*d3&(*d1^*d2))^*d2,*d4,*d1,*((unsigned int *)(block+8))+0xFCEFA3F8,9);
	*d3=MD5step(((*d4^*d1)&*d2)^*d1,*d3,*d4,*((unsigned int *)(block+28))+0x676F02D9,14);
	*d2=MD5step(((*d3^*d4)&*d1)^*d4,*d2,*d3,*((unsigned int *)(block+48))+0x8D2A4C8A,20);
	return;
}


void MD5trans3(unsigned int * d1,unsigned int * d2,unsigned int * d3,unsigned int * d4,unsigned char * block)
{
	*d1=MD5step((*d3^*d2)^*d4,*d1,*d2,*((unsigned int *)(block+20))+0xFFFA3942,4);
	*d4=MD5step((*d1^*d2)^*d3,*d4,*d1,*((unsigned int *)(block+32))+0x8771F681,11);
	*d3=MD5step((*d4^*d1)^*d2,*d3,*d4,*((unsigned int *)(block+44))+0x6D9D6122,16);
	*d2=MD5step((*d3^*d4)^*d1,*d2,*d3,*((unsigned int *)(block+56))+0xFDE5380C,23);
	*d1=MD5step((*d3^*d2)^*d4,*d1,*d2,*((unsigned int *)(block+4))+0xA4BEEA44,4);
	*d4=MD5step((*d1^*d2)^*d3,*d4,*d1,*((unsigned int *)(block+16))+0x4BDECFA9,11);
	*d3=MD5step((*d4^*d1)^*d2,*d3,*d4,*((unsigned int *)(block+28))+0xF6BB4B60,16);
	*d2=MD5step((*d3^*d4)^*d1,*d2,*d3,*((unsigned int *)(block+40))+0xBEBFBC70,23);
	*d1=MD5step((*d3^*d2)^*d4,*d1,*d2,*((unsigned int *)(block+52))+0x289B7EC6,4);
	*d4=MD5step((*d1^*d2)^*d3,*d4,*d1,*((unsigned int *)block)+0xEAA127FA,11);
	*d3=MD5step((*d4^*d1)^*d2,*d3,*d4,*((unsigned int *)(block+12))+0xD4EF3085,16);
	*d2=MD5step((*d3^*d4)^*d1,*d2,*d3,*((unsigned int *)(block+24))+0x04881D05,23);
	*d1=MD5step((*d3^*d2)^*d4,*d1,*d2,*((unsigned int *)(block+36))+0xD9D4D039,4);
	*d4=MD5step((*d1^*d2)^*d3,*d4,*d1,*((unsigned int *)(block+48))+0xE6DB99E5,11);
	*d3=MD5step((*d4^*d1)^*d2,*d3,*d4,*((unsigned int *)(block+60))+0x1FA27CF8,16);
	*d2=MD5step((*d3^*d4)^*d1,*d2,*d3,*((unsigned int *)(block+8))+0xC4AC5665,23);
	return;
}


void MD5trans4(unsigned int * d1,unsigned int * d2,unsigned int * d3,unsigned int * d4,unsigned char * block)
{
	*d1=MD5step(*d3^(~*d4|*d2),*d1,*d2,*((unsigned int *)block)+0xF4292244,6);
	*d4=MD5step((~*d3|*d1)^*d2,*d4,*d1,*((unsigned int *)(block+28))+0x432AFF97,10);
	*d3=MD5step((*d4|~*d2)^*d1,*d3,*d4,*((unsigned int *)(block+56))+0xAB9423A7,15);
	*d2=MD5step((*d3|~*d1)^*d4,*d2,*d3,*((unsigned int *)(block+20))+0xFC93A039,21);
	*d1=MD5step(*d3^(~*d4|*d2),*d1,*d2,*((unsigned int *)(block+48))+0x655B59C3,6);
	*d4=MD5step((~*d3|*d1)^*d2,*d4,*d1,*((unsigned int *)(block+12))+0x8F0CCC92,10);
	*d3=MD5step((*d4|~*d2)^*d1,*d3,*d4,*((unsigned int *)(block+40))+0xFFEFF47D,15);
	*d2=MD5step((*d3|~*d1)^*d4,*d2,*d3,*((unsigned int *)(block+4))+0x85845DD1,21);
	*d1=MD5step(*d3^(~*d4|*d2),*d1,*d2,*((unsigned int *)(block+32))+0x6FA87E4F,6);
	*d4=MD5step((~*d3|*d1)^*d2,*d4,*d1,*((unsigned int *)(block+60))+0xFE2CE6E0,10);
	*d3=MD5step((*d4|~*d2)^*d1,*d3,*d4,*((unsigned int *)(block+24))+0xA3014314,15);
	*d2=MD5step((*d3|~*d1)^*d4,*d2,*d3,*((unsigned int *)(block+52))+0x4E0811A1,21);
	*d1=MD5step(*d3^(~*d4|*d2),*d1,*d2,*((unsigned int *)(block+16))+0xF7537E82,6);
	*d4=MD5step((~*d3|*d1)^*d2,*d4,*d1,*((unsigned int *)(block+44))+0xBD3AF235,10);
	*d3=MD5step((*d4|~*d2)^*d1,*d3,*d4,*((unsigned int *)(block+8))+0x2AD7D2BB,15);
	*d2=MD5step((*d3|~*d1)^*d4,*d2,*d3,*((unsigned int *)(block+36))+0xEB86D391,21);
	return;
}


Bb MD5_exechecksub(const char * filename,unsigned char * digest)
{
	FILE * local_00;
	int local_01;
	char local_02[131072];
	local_00=fopen(filename,"rb");
	if (local_00==0) {
		return false;
	}
	if (fseek(local_00,1536,0)!=0) {
		fclose(local_00);
		return false;
	}
	MD5init(&g_MD5CTX_1);
	while (true) {
		local_01=fread(local_02,1,0x00010000,local_00);
		if (local_01<=0) break;
		MD5update(&g_MD5CTX_1,local_02,local_01);
	}
	MD5final(digest,&g_MD5CTX_1);
	fclose(local_00);
	return true;
}


void MD5calc(const char * buf,unsigned char * digest,int len)
{
	MD5init(&g_MD5CTX_2);
	MD5update(&g_MD5CTX_2,buf,len);
	MD5final(digest,&g_MD5CTX_2);
	return;
}


