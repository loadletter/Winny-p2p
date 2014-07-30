//md5

#ifndef _MD5_H_INCLUDED
#define _MD5_H_INCLUDED



typedef struct tagMD5CTX 
{
	unsigned int                state[4]                         ;   //fr      0     16 
	unsigned int                count[2]                         ;   //fr     16      8 
	unsigned char               buffer[64]                        ;   //fr     24     64 
} MD5CTX;


void MD5sub(unsigned char * buf,unsigned int d2);
ul MD5step(unsigned int d1,unsigned int d2,unsigned int d3,unsigned int d4,unsigned int d5);
void MD5init(MD5CTX * context);
void MD5update(MD5CTX * context,const char * buf,unsigned int len);
void MD5final(unsigned char * digest,MD5CTX * context);
void MD5transform(unsigned int * state,unsigned char * block);
void MD5trans1(unsigned int * d1,unsigned int * d2,unsigned int * d3,unsigned int * d4,unsigned char * block);
void MD5trans2(unsigned int * d1,unsigned int * d2,unsigned int * d3,unsigned int * d4,unsigned char * block);
void MD5trans3(unsigned int * d1,unsigned int * d2,unsigned int * d3,unsigned int * d4,unsigned char * block);
void MD5trans4(unsigned int * d1,unsigned int * d2,unsigned int * d3,unsigned int * d4,unsigned char * block);
Bb MD5_exechecksub(const char * filename,unsigned char * digest);
void MD5calc(const char * buf,unsigned char * digest,int len);


#endif // _MD5_H_INCLUDED
