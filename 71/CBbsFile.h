#ifndef _CBBSFILE_H_INCLUDED
#define _CBBSFILE_H_INCLUDED

#include "CKey.h"


class CBbsFile
{
public:
	AnsiString                     m__unknown_000                ;   //fr      0      4
	AnsiString                     m__unknown_001                ;   //fr      4      4
	TMemoryStream *                m_pTMemoryStream              ;   //fr      8      4

	CBbsFile();
	~CBbsFile();
	bool mf_CBbsFile_0000(CKey * arg_0);
	bool mf_CBbsFile_0010(CKey * arg_0);
	bool mf_CBbsFile_0020(CKey * arg_0);
	AnsiString mf_CBbsFile_0030();
	void mf_CBbsFile_0040(char * arg_0,CKey * arg_1,const char * arg_2,const char * arg_3,const char * arg_4);
	bool mf_CBbsFile_0050(CKey * arg_0,char * arg_1);
	bool mf_CBbsFile_0060(unsigned int arg_0,char * arg_1);
	void mf_CBbsFile_0070(CKey * arg_0);

	void CBbsFile::mf_CBbsFile_0080(AnsiString arg_0)
	{
		m__unknown_000=arg_0;
		return;
	}

};


#endif //_CBBSFILE_H_INCLUDED
