#ifndef _UTIL_H_INCLUDED
#define _UTIL_H_INCLUDED


bool ny_iskanji(char ch);
void ny_addlog(AnsiString logstr);
void ny_logclear();
void ny_sanketacomma(char * s);
unsigned int ny_unknown_0000(const char * src);
void ny_aschash2binhash(const char * src_aschash,unsigned char * dest_binhash);
void ny_binhash2aschash(unsigned char * src_binhash,char * dest_aschash);
void ny_htmlproc_1(char * src,char * dest,bool f1,bool f2);
void ny_htmlproc_2(const char * src,char * dest);
void ny_htmlproc_3(char * src,char * dest);
void ny_htmlproc_4(char * src,char * dest);
bool ny_htmlproc_4a(char * arg_0);
void ny_htmlproc_5(const char * src,char * dest);
void ny_decryptstring(const char * src,char * dest);
void ny_unknown_0010(char * arg_0,time_t arg_1);
void ny_unknown_0020(const unsigned char * arg_0,char * arg_1);
int ny_colordiff(TColor color1,TColor color2);
void ny_nazo(double fd);

inline void ny_unknown_0010call(char * arg_0,time_t arg_1) { ny_unknown_0010(arg_0,arg_1); }

#endif// _UTIL_H_INCLUDED
