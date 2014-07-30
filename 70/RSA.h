#include "CLongInt.h"
#include "md5.h"


class RSA 
{
public:
	CLongInt                       m__unknown_000                ;   //fr      0     92 
	CLongInt                       m__unknown_001                ;   //fr     92     92 
	char                           m_szstr[32]                   ;   //fr    184     32 
	
	RSA();
	~RSA();
	void mf_RSA_0000(const char * arg_0);
	void mf_RSA_0010(CLongInt * arg_0,CLongInt * arg_1);
	void mf_RSA_0020(unsigned char * arg_0,CLongInt * arg_1,CLongInt * arg_2);
	CLongInt mf_RSA_0030(CLongInt * arg_0);
	Bb mf_RSA_0040(CLongInt * arg_0,CLongInt * arg_1);
	void mf_RSA_0050(CLongInt arg_0,char * arg_1);
	void mf_RSA_0060();
	void str2LongInt(const char * src,CLongInt * result);
	void mf_RSA_0070();
};

