#ifndef _CAUTODOWNLIST_H_INCLUDED
#define _CAUTODOWNLIST_H_INCLUDED



class CAutoDownList
{
public:
	bool                      m_flg_unk0                    ;   //fr      0      1
	char                      m_char256_unk1[256]           ;   //fr      1    256
	char                      m_char256_unk2[256]           ;   //fr    257    256
	char                      m_char256_unk3[256]           ;   //fr    513    256
	int                       m_int_unk4                    ;   //fr    772      4
	bool                      m_flag_unk5                   ;   //fr    776      1
	bool                      m_flag_unk6                   ;   //fr    777      1
	bool                      m_flag_unk7                   ;   //fr    778      1
	bool                      m_flag_unk8                   ;   //fr    779      1
	char                      m_char_unk100_70;
		//boolかも
		
	double                    m_double_unk9                 ;   //fr    784      8
	double                    m_double_unk10                ;   //fr    792      8
	unsigned int              m__unknown_000                ;   //fr    800      4
	unsigned int              m__unknown_001                ;   //fr    804      4
	int                       m_int_unk20                   ;   //fr    808      4
	unsigned char             m_hash[16]                    ;   //fr    812     16
	unsigned char             m_hash_kamo[16]               ;   //fr    828     16
	int                       m_int_unk21                   ;   //fr    844      4

private:
	static int                            g_int             ;				//fr 0053E5A0 00000004


public:

	CAutoDownList();
	~CAutoDownList();
	void mf_CAutoDownList_0000();
	Bb mf_CAutoDownList_0010();
	Bb mf_CAutoDownList_0020();

	bool IsValid() { return m_flg_unk0; }  //このフラグがvalidかは確認してないけど、多分validということで
	void SetValid(_CONST bool s) { m_flg_unk0=s; }  //このフラグがvalidかは確認してないけど、多分validということで

	bool Get_flag_unk5() { return m_flag_unk5; }
	bool Get_flag_unk6() { return m_flag_unk6; }
	bool Get_flag_unk7() { return m_flag_unk7; }
	bool Get_flag_unk8() { return m_flag_unk8; }
	double Get_double_unk9() { return m_double_unk9; }
	double Get_double_unk10() { return m_double_unk10; }
	unsigned char *GetHash() { return m_hash; }

	int Get_int_unk4() { return m_int_unk4; }
	void Set_int_unk4(_CONST int s) { m_int_unk4=s; }
	int Get_int_unk20() _CONST { return m_int_unk20; }
	void Set_int_unk20(_CONST int s) { m_int_unk20=s; }
	int Get_int_unk21() _CONST { return m_int_unk21; }
	unsigned int Get_uint_unk000() { return m__unknown_000; }
	unsigned int Get_uint_unk001() { return m__unknown_001; }
	char Get_char_unk100_70() { return m_char_unk100_70; }

	void Set__unknown_000(_CONST unsigned int s) { m__unknown_000=s; }
	void Set__unknown_001(_CONST unsigned int s) { m__unknown_001=s; }

	void Set_Tripstr(_CONST char *s) { strcpy(m_char256_unk2,s); }
	void Set_unk3(_CONST char *s) { strcpy(m_char256_unk3,s); }
	void Set_UpperSizeLimit(_CONST double s) { m_double_unk9=s; }
	void Set_LowerSizeLimit(_CONST double s) { m_double_unk10=s; }

	void Set_flag_Bbs(_CONST bool s) { m_flag_unk5=s; }
	void Set_flag_AutoDelete(_CONST bool s) { m_flag_unk6=s; }
	void Set_flag_Delete(_CONST bool s) { m_flag_unk7=s; }
	void Set_flag_Disconnect(_CONST bool s) { m_flag_unk8=s; }
	void Set_double_unk9(_CONST double s) { m_double_unk9=s; }
	void Set_double_unk10(_CONST double s) { m_double_unk10=s; }

	void Set_hash(_CONST unsigned char *s) {
		if (s!=0) {
			memcpy(m_hash,s,16);
		} else {
			memset(m_hash,0,16);
		}
		m_flg_unk0=true;
	}

	void Set_keyword(_CONST char *s) {
		strcpy(m_char256_unk1,s);
		m_flg_unk0=true;
	}

};


#endif// _CAUTODOWNLIST_H_INCLUDED
