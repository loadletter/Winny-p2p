#ifndef _CKEYBLOCK_H_INCLUDED
#define _CKEYBLOCK_H_INCLUDED


#include "OptionUnit.h"

class CKeyBlock
{
public:
	char                           m_char_unk0                   ;   //fr      0      1
	char                           m_char_unk1                   ;   //fr      1      1
	int                            m_int_unk2                    ;   //fr      4      4
	int                            m_int_unk3                    ;   //fr      8      4
	char *                         m_pchar_unk4                  ;   //fr     12      4

	//Ç±Ç±Ç…èëÇ≠ÇÃÇ™ê≥âÇ»ñÕól
	CKeyBlock()
	{
		m_pchar_unk4=NULLPO;
		m_char_unk1=0;
		m_int_unk2=0;
	}


	~CKeyBlock()
	{
		if (m_pchar_unk4!=0) {
			free(m_pchar_unk4);
		}
	}

	void mf_CKeyBlock_0000(TCanvas * arg_0,TRect * arg_1);	//CKey

};



//extern CKeyBlock             g_KeyBlocks[2][1000]           ;				//fr 0096228C 00007D00


#endif// _CKEYBLOCK_H_INCLUDED
