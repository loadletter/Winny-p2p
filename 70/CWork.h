#ifndef _CWORK_H_INCLUDED
#define _CWORK_H_INCLUDED


#include "md5.h"


enum enumWorkType {
        WORKTYPE00,WORKTYPE01,WORKTYPE02,WORKTYPE03,WORKTYPE04,
        WORKTYPE05,WORKTYPE06,WORKTYPE07,WORKTYPE08,WORKTYPE09,
		WORKTYPE10
};


class CWork
{
public:
	int                            m_ffresult__                  ;   //fr      0      4
	struct _finddata_t             m_finddata_                   ;   //fr      4    280
	int                            m_int_unk300                  ;   //fr    284      4
	enumWorkType                         m_worktype_                   ;   //fr    288      1
	int                            m_hostIdx_                    ;   //fr    292      4
	unsigned char              m_uchar16_unk1[16]                ;   //fr    296     16
	unsigned char              m_uchar16_unk2[16]                ;   //fr    312     16
	unsigned int                   m_uint_countMax_              ;   //fr    328      4
		//intàµÇ¢Ç»Ç∆Ç±ÇÎÇ∆uintàµÇ¢Ç»Ç∆Ç±ÇÎÇ™ç¨ç›ÇµÇƒÇ¢ÇÈ

	int pad1;	//fr    332      4 <unknown>
	int                            m_int_unk20                   ;   //fr    336      4
	char                      m_char256_unk10[256]               ;   //fr    340    256
	int pad2;	//fr    596      4 <unknown>
	char                      m_char256_unk3[256]                ;   //fr    600    256
	char                       m_char16_unk301[16]               ;   //fr    856     16
	char *                         m_pchar_status_               ;   //fr    872      4
	unsigned int                   m_uint_countNow               ;   //fr    876      4
		//intàµÇ¢Ç»Ç∆Ç±ÇÎÇ∆uintàµÇ¢Ç»Ç∆Ç±ÇÎÇ™ç¨ç›ÇµÇƒÇ¢ÇÈ

	Bb                             m_flgIsFinished_370           ;   //fr    880      1
	Bb                             m_flgIsSuccessed_371          ;   //fr    881      1
	Bb                             m_flg_unk302                  ;   //fr    882      1
	Bb                             m_flg_unk303                  ;   //fr    883      1
	int                            m_int_unk304                  ;   //fr    884      4
	unsigned int                   m_uint_unk305                 ;   //fr    888      4
	char                     m_sz_foldername_kamo_[1024]         ;   //fr    892   1024
	unsigned int                   m_tick_created_kamo_          ;   //fr   1916      4
	unsigned int                   m_tick_2_                     ;   //fr   1920      4
	unsigned int                   m_tick_3_                     ;   //fr   1924      4
	int                            m_int_unk220_                 ;   //fr   1928      4
	int                        m_intarray60_unk306[60]           ;   //fr   1932    240
	int pad3;	//fr   2172      4 <unknown>
	double                         m_double_unk6                 ;   //fr   2176      8
	unsigned int                   m_uint_unk210                 ;   //fr   2184      4
	Bb                             m_flgkasiraso_                ;   //fr   2188      1
	int                            m_hostIdx_mouikko_            ;   //fr   2192      4
	Bb                             m_flgkasiraso_1               ;   //fr   2196      1
	Bb                             m_flgkasiraso_2               ;   //fr   2197      1
	Bb                             m_flgkasiraso_3               ;   //fr   2198      1
	Bb                             m_flgkasiraso_4               ;   //fr   2199      1
	Bb                             m_flgkasiraso_5               ;   //fr   2200      1
	int                            m_int_unk30                   ;   //fr   2204      4
	int                            m_int_unk31                   ;   //fr   2208      4
	int                            m_int_unk32                   ;   //fr   2212      4
	int                            m_int_unk33                   ;   //fr   2216      4
	int                            m_int_unk34                   ;   //fr   2220      4
	int                            m_int_errorcode_kamo_         ;   //fr   2224      4
	SOCKET                         m_socket_unk5                 ;   //fr   2228      4
	int                            m_int_unk211                  ;   //fr   2232      4
	Bb                             m_flg_unk212                  ;   //fr   2236      1
	char *                         m_pchar_unk                   ;   //fr   2240      4
	Bb                             m_flg_unk200                  ;   //fr   2244      1
	Bb                             m_flg_unk201                  ;   //fr   2245      1
	Bb                             m_flg_unk202                  ;   //fr   2246      1
	MD5CTX                         m_md5ctx                      ;   //fr   2248     88
	FILE *                         m_fileptr                     ;   //fr   2336      4
	int pad4;	//fr   2340      4 <unknown>


	CWork();
	~CWork();
	void mf_CWork_0000();
	void mf_CWork_0010(bool arg_0,bool arg_1);
	void mf_CWork_0020();
	void mf_CWork_0030();
	void mf_CWork_0040(int arg_0);
	void mf_CWork_0050();
	double mf_CWork_0060();
	void mf_CWork_0070(char * arg_0,int arg_1);
	void mf_CWork_0080(int arg_0,int arg_1,char * arg_2,char * arg_3);
	void mf_CWork_0090(int arg1,unsigned int arg2,unsigned char * arg3,int arg4,int arg5);
	void mf_CWork_0100(int arg1,unsigned int arg2,char * arg3,int arg4,int arg5,int arg6);
	void mf_CWork_0110(unsigned int arg_0,unsigned char * arg_1,const char * arg_2);
	void mf_CWork_0120(unsigned int arg_0,unsigned char * arg_1,const char * arg_2,bool arg_3);
	void mf_CWork_0130(int arg_0,bool arg_1);
	void mf_CWork_0140(const char * arg_0,const char * arg_1,int arg_2);
	void mf_CWork_0150(char * arg_0,int arg_1);
	void mf_CWork_0160(int arg_0);
	void mf_CWork_0170();

	inline enumWorkType GetWorkType() const { return m_worktype_; }
	inline void SetWorkType(enumWorkType s) { m_worktype_=s; }
	inline bool IsFinished() const { return m_flgIsFinished_370; }
	inline int Get_int_unk211() { return m_int_unk211; }
	inline void Set_int_unk211(int s) { m_int_unk211=s; }
	inline int Get_int_unk32() { return m_int_unk32; }
	inline int Get_int_unk33() { return m_int_unk33; }
	inline int Get_int_unk34() { return m_int_unk34; }
	inline int Get_int_unk304() { return m_int_unk304; }
	inline unsigned int Get_uint_unk305() { return m_uint_unk305; }

	inline unsigned int GetCountNow() { return m_uint_countNow; }
	inline void SetCountNow(_CONST unsigned int s) { m_uint_countNow=s; }
	inline void AddCountNow(_CONST unsigned int s) { m_uint_countNow+=s; }
	inline unsigned int GetCountMax() { return m_uint_countMax_; }
	inline void SetCountMax(_CONST unsigned int s) { m_uint_countMax_=s; }
	inline char *GetFolderName() { return m_sz_foldername_kamo_; }
	inline char *Get_char16_unk301() { return m_char16_unk301; }
	inline char *Get_uchar16_unk1() { return m_uchar16_unk1; }
	inline double Get_double_unk6() { return m_double_unk6; }
	inline void SetHostIdx(_CONST int s) { m_hostIdx_=s; }
	inline int GetHostIdx() { return m_hostIdx_; }
	inline int Get_hostIdx_mouikko_() { return m_hostIdx_mouikko_; }
    inline bool IsValid_hostIdx_mouikko() { return m_hostIdx_mouikko_>=0; }

	inline void SetErrorcode(_CONST int s) { m_int_errorcode_kamo_=s; }
	inline int GetErrorcode() _CONST { return m_int_errorcode_kamo_; }

	inline bool Get_flg_unk212() _CONST { return m_flg_unk212; }
	inline bool Get_flg_unk302() _CONST { return m_flg_unk302; }

	inline struct _finddata_t *GetFinddata() { return &m_finddata_; }
	inline int GetFinddata_size() { return m_finddata_.size; }
	inline char * GetFinddata_name() { return m_finddata_.name; }
	inline MD5CTX * GetMD5ctx() { return &m_md5ctx; }

	inline bool Get_flgkasiraso_() { return m_flgkasiraso_; }
	inline void Set_flgkasiraso_1(_CONST bool s) { m_flgkasiraso_1=s; }
	inline bool Get_flgkasiraso_2() _CONST { return m_flgkasiraso_2; }
	inline void Set_flgkasiraso_2(_CONST bool s) { m_flgkasiraso_2=s; }
	inline bool Get_flgkasiraso_3() _CONST { return m_flgkasiraso_3; }

	inline void Set_flg_unk200(_CONST bool s) { m_flg_unk200=s; }
	inline void Set_flg_unk201(_CONST bool s) { m_flg_unk201=s; }
	inline void Set_flg_unk202(_CONST bool s) { m_flg_unk202=s; }

	inline unsigned int Get_tick_created() _CONST { return m_tick_created_kamo_; }
	inline unsigned int Set_tick_2_(_CONST unsigned int s) { return m_tick_2_=s; }

	inline void Set_pchar_status_(_CONST char * s) { m_pchar_status_=s; }
	void Set_char256_unk10(_CONST char * s) { strcpy(m_char256_unk10,s); }
	void Set_uchar16_unk1(_CONST unsigned char * s) { memcpy(m_uchar16_unk1,s,16); }
};




class CWorkSorter
{
public:
	int                            m_int_unk0                    ;   //fr      0      4 
	int                            m_int_unk1                    ;   //fr      4      4 
	int                            m_int_unk2                    ;   //fr      8      4 
	CWork *                        m_pCWork                      ;   //fr     12      4 
	int                            m_int_unk3                    ;   //fr     16      4 
	Bb                             m_flag_unk4                   ;   //fr     20      1 

	bool operator < (const CWorkSorter & arg_0) const
	{
		if (m_int_unk2<arg_0.m_int_unk2) {
			return false;
		}
		if (m_int_unk2>arg_0.m_int_unk2) {
			return true;
		}
		if (m_flag_unk4) {
			switch (m_int_unk3) {
			case 0:  
				return (bool)(strcmp(m_pCWork->m_char256_unk10,arg_0.m_pCWork->m_char256_unk10)<0);
			case 2:  
				if (m_pCWork->m_uint_countMax_==arg_0.m_pCWork->m_uint_countMax_) {
					return (bool)(m_pCWork->m_double_unk6<arg_0.m_pCWork->m_double_unk6);
				}
				return (bool)(m_pCWork->m_uint_countMax_<arg_0.m_pCWork->m_uint_countMax_);
			case 3:  
				if (! (!(m_int_unk2>=10||arg_0.m_int_unk2>=10||m_pCWork->m_uint_countMax_==0)&&arg_0.m_pCWork->m_uint_countMax_!=0) ) {
					return (bool)(m_int_unk1<arg_0.m_int_unk1);
				}
				return (bool)((double)*((int *)(&m_pCWork->m_uint_countNow))/(double)m_pCWork->m_uint_countMax_<(double)*((int *)(&arg_0.m_pCWork->m_uint_countNow))/(double)arg_0.m_pCWork->m_uint_countMax_);
			case 4:
				if (! (!(m_int_unk2>=10)&&arg_0.m_int_unk2<10) ) {
					return (bool)(m_int_unk1<arg_0.m_int_unk1);
				}
				return (bool)(m_pCWork->mf_CWork_0060()<arg_0.m_pCWork->mf_CWork_0060());
			case 5:
				if (! (!(m_int_unk2>=10)&&arg_0.m_int_unk2<10) ) {
					return (bool)(m_int_unk1<arg_0.m_int_unk1);
				}
				return (bool)(m_pCWork->m_double_unk6<arg_0.m_pCWork->m_double_unk6);
			}
			return (bool)(m_int_unk1<arg_0.m_int_unk1);
		}
		switch (m_int_unk3) {
		case 0:
			return (bool)(strcmp(m_pCWork->m_char256_unk10,arg_0.m_pCWork->m_char256_unk10)>0);
		case 2:
			if (m_pCWork->m_uint_countMax_==arg_0.m_pCWork->m_uint_countMax_) {
				return (bool)(m_pCWork->m_double_unk6>arg_0.m_pCWork->m_double_unk6);
			}
			return (bool)(m_pCWork->m_uint_countMax_>arg_0.m_pCWork->m_uint_countMax_);
		case 3:
			if (! (!(m_int_unk2>=10||arg_0.m_int_unk2>=10||m_pCWork->m_uint_countMax_==0)&&arg_0.m_pCWork->m_uint_countMax_!=0) ) {
				return (bool)(m_int_unk1<arg_0.m_int_unk1);
			}
			return (bool)((double)*((int *)(&m_pCWork->m_uint_countNow))/(double)m_pCWork->m_uint_countMax_>(double)*((int *)(&arg_0.m_pCWork->m_uint_countNow))/(double)arg_0.m_pCWork->m_uint_countMax_);
		case 4:
			if (! (!(m_int_unk2>=10)&&arg_0.m_int_unk2<10) ) {
				return (bool)(m_int_unk1<arg_0.m_int_unk1);
			}
			return (bool)(m_pCWork->mf_CWork_0060()>arg_0.m_pCWork->mf_CWork_0060());
		case 5:
			if (! (!(m_int_unk2>=10)&&arg_0.m_int_unk2<10) ) {
				return (bool)(m_int_unk1<arg_0.m_int_unk1);
			}
			return (bool)(m_pCWork->m_double_unk6>arg_0.m_pCWork->m_double_unk6);
		}
		return (bool)(m_int_unk1<arg_0.m_int_unk1);
	}

};



#endif// _CWORK_H_INCLUDED
