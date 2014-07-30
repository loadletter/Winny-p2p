#ifndef _CRC4_H_INCLUDED
#define _CRC4_H_INCLUDED

class CRC4
{
public:
	unsigned char             m_tbl_1[256]                  ;   //fr      0    256 
	unsigned char             m_uchar_1                     ;   //fr    256      1 
	unsigned char             m_uchar_2                     ;   //fr    257      1 
	unsigned char             m_uchar_3                     ;   //fr    258      1 
	unsigned char             m_tbl_2[256]                  ;   //fr    259    256 
	unsigned char             m_tbl_3[256]                  ;   //fr    515    256 

	CRC4();
	~CRC4();
	void setupkey(const char * key);
	unsigned char mf_CRC4_0000();
	void crypter(char * buf,int len);
};

#endif // _CRC4_H_INCLUDED

