#ifndef _CFOLDER_H_INCLUDED
#define _CFOLDER_H_INCLUDED


class CFolder
{
public:
	AnsiString                     m__unknown_000                ;   //fr      0      4
	AnsiString                     m__unknown_001                ;   //fr      4      4
	AnsiString                     m__unknown_002                ;   //fr      8      4
	AnsiString                     m__unknown_003                ;   //fr     12      4
public:
	int                            m_int_unk1                    ;   //fr     16      4
		//ファイルのカウント
	int                            m_int_unk2                    ;   //fr     20      4
		//ファイルのサイズ(kbyte)
	bool                             m_flg_unk3                    ;   //fr     24      1
	bool                             m_flg_unk4                    ;   //fr     25      1

	CFolder();
	~CFolder();
	void mf_CFolder_0000();
	void mf_CFolder_0010(AnsiString arg_0);

	void mf_CFolder_0020(AnsiString arg_0)
	{
		m__unknown_000=arg_0;
	}

	void mf_CFolder_0030(AnsiString arg_0)
	{
		m__unknown_001=arg_0;
	}

	inline void Set_int_unk1(_CONST int s) { m_int_unk1=s; }
	inline void Set_int_unk2(int s) { m_int_unk2=s; }
	inline void Set_flg_unk3(bool s) { m_flg_unk3=s; }
	inline void Set_flg_unk4(bool s) { m_flg_unk4=s; }
	inline int Get_int_unk1() { return m_int_unk1; }
	inline int Get_int_unk2() { return m_int_unk2; }
	inline bool Get_flg_unk3() { return m_flg_unk3; }
	inline bool Get_flg_unk4() { return m_flg_unk4; }
	inline const char * Get_000_cstr() { return m__unknown_000.c_str(); }
	inline const char * Get_001_cstr() { return m__unknown_001.c_str(); }
	inline const char * Get_002_cstr() { return m__unknown_002.c_str(); }
	inline const char * Get_003_cstr() { return m__unknown_003.c_str(); }

	inline void AddFileSize(unsigned int sz) {
		m_int_unk1++;
		m_int_unk2+=(sz>>10);
	}
};


class CFolderSorter
{
public:
	unsigned int                   m_uint_unk1                   ;   //fr      0      4
	CFolder *                      m_pCFoler                     ;   //fr      4      4
	int                            m_int_unk2                    ;   //fr      8      4
	bool                             m_flag_unk3                   ;   //fr     12      1

    inline unsigned int Get_uint_unk1() { return m_uint_unk1; }

	bool operator < (const CFolderSorter & arg_0) const
	{
		if (m_flag_unk3) {
			switch (m_int_unk2) {
			case 0:
				return (bool)(strcmp(m_pCFoler->m__unknown_000.c_str(),arg_0.m_pCFoler->m__unknown_000.c_str())>0);
			case 1:
				return (bool)(strcmp(m_pCFoler->m__unknown_001.c_str(),arg_0.m_pCFoler->m__unknown_001.c_str())>0);
			case 2:
				return (bool)(strcmp(m_pCFoler->m__unknown_002.c_str(),arg_0.m_pCFoler->m__unknown_002.c_str())>0);
			case 3:
				return (bool)(m_pCFoler->m_int_unk2<arg_0.m_pCFoler->m_int_unk2);
			case 4:
				return (bool)(m_pCFoler->m_int_unk1<arg_0.m_pCFoler->m_int_unk1);
			}
			return (bool)(strcmp(m_pCFoler->m__unknown_001.c_str(),arg_0.m_pCFoler->m__unknown_001.c_str())>0);
		}
		switch (m_int_unk2) {
		case 0:
			return (bool)(strcmp(m_pCFoler->m__unknown_000.c_str(),arg_0.m_pCFoler->m__unknown_000.c_str())<0);
		case 1:
			return (bool)(strcmp(m_pCFoler->m__unknown_001.c_str(),arg_0.m_pCFoler->m__unknown_001.c_str())<0);
		case 2:
			return (bool)(strcmp(m_pCFoler->m__unknown_002.c_str(),arg_0.m_pCFoler->m__unknown_002.c_str())<0);
		case 3:
			return (bool)(m_pCFoler->m_int_unk2>arg_0.m_pCFoler->m_int_unk2);
		case 4:
			return (bool)(m_pCFoler->m_int_unk1>arg_0.m_pCFoler->m_int_unk1);
		}
		return (bool)(strcmp(m_pCFoler->m__unknown_001.c_str(),arg_0.m_pCFoler->m__unknown_001.c_str())<0);
	}

};


#endif// _CFOLDER_H_INCLUDED
