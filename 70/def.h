#ifndef _DEF_H_INCLUDED
#define _DEF_H_INCLUDED


#include <stdio.h>
#include <string.h>
#include <mbstring.h>
#include <ctype.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <math.h>
#include <io.h>
#include <dir.h>
#include <winsock2.h>


#include "def0.h"

#define NULLPO ((void *)0)

typedef void * PPROC;

class _in_addr
{
public:
	unsigned char b1;
	unsigned char b2;
	unsigned char b3;
	unsigned char b4;

	bool operator == (const _in_addr &rhs) const {
		return b1==rhs.b1 && b2==rhs.b2 && b3==rhs.b3 && b4==rhs.b4;
	}
	bool isaddr(const unsigned char _b1,const unsigned char _b2,const unsigned char _b3,const unsigned char _b4) const {
//		return (b1==_b1 && b2==_b2 && b3==_b3 && b4==_b4);
		return !(b1!=_b1 || b2!=_b2 || b3!=_b3 || b4!=_b4);
	}
};


#define ny_addrset(pa,d1,d2,d3,d4) (pa)->b1=d1; (pa)->b2=d2; (pa)->b3=d3; (pa)->b4=d4; 
#define ny_addrcrypter(dest,src) (dest)->b1=(src).b1; (dest)->b2=(src).b2^94; (dest)->b3=(src).b3^94; (dest)->b4=(src).b4^94;


class CGlobalLock {
public:
	static int g_globallock;
		char d;
	CGlobalLock() {
		g_globallock=1;
	}
	~CGlobalLock() {
		g_globallock=0;
	}

};


extern AnsiString                     g_AppPath              ;				//fr 00962188 00000004


#define ny_pv_at(vv,idx) ( ((int)idx<0||idx>=(int)(vv)->size())?(CWork*)NULLPO:(*(vv))[idx] )


#ifdef EXACTMATCH
inline long callatol(const char *s) { return atol(s); }
#else
#define callatol(s) atol(s)
#endif


#endif
