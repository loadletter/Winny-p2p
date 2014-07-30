//CLongInt

//---------------------------------------------------------------------------
#include "hdrs.h"

#include <vcl.h>
#pragma hdrstop

#include "def.h"

#include "CLongInt.h"



void CLongInt::subchunk(int n)
{
	int local_00;
	int * local_01;
	if (! (n<0||n>=100||n==0) ) {
		if (m_int1==0) {
			*this=_CLongInt_letint(-n);
			return;
		}
		local_01=m_intarray+1;
		*local_01=*local_01-n;
		for (local_00=0; m_int1-1>local_00; local_00++) {
			if (*local_01>=0) return;
			*local_01=(*local_01+100)%100;
			local_01=local_01+1;
			*local_01=*local_01-1;
		}
		if (*local_01==0) {
			m_int1=m_int1-1;
		}
	}
	return;
}


void CLongInt::addchunk(int n)
{
	int local_00;
	int * local_01;
	if (! (n<0||n>=100||n==0) ) {
		if (m_int1==0) {
			*this=_CLongInt_letint(n);
			return;
		}
		local_01=m_intarray+1;
		*local_01=*local_01+n;
		for (local_00=0; m_int1+1>local_00; local_00++) {
			if (*local_01<100) break;
			*local_01=*local_01%100;
			local_01=local_01+1;
			*local_01=*local_01+1;
		}
		if (m_int1==local_00) {
			m_int1=m_int1+1;
		}
	}
	return;
}


CLongInt _CLongInt__satsub(CLongInt arg_0,CLongInt arg_1)
{
	int local_00;
	int local_01;
	CLongInt local_02;

	local_02.m_int1=local_02.m_int2=0;
        
	local_01=_CLongInt__abscompare(arg_0,arg_1);
	if (local_01<0) {
		return local_02;
	}
	if (local_01==0) {
		return local_02;
	}
	local_01=0;
	for (local_00=1; local_00<=arg_1.m_int1; local_00++) {
		local_01=(arg_0.m_intarray[local_00]-arg_1.m_intarray[local_00])-local_01;
		if (local_01>=0) {
			local_02.m_intarray[local_00]=local_01;
			local_01=0;
			continue;
		}
		local_02.m_intarray[local_00]=local_01+100;
		local_01=1;
	}
	while (local_00<=arg_0.m_int1 && local_01!=0) {
		local_01=arg_0.m_intarray[local_00]-local_01;
		if (local_01>=0) {
			local_02.m_intarray[local_00]=local_01;
			local_01=0;
		} else {
			local_02.m_intarray[local_00]=local_01+100;
			local_01=1;
		}
		local_00=local_00+1;
	}
	while (local_00<=arg_0.m_int1) {
		local_02.m_intarray[local_00]=arg_0.m_intarray[local_00];
		local_00=local_00+1;
	}
	for (local_02.m_int1=arg_0.m_int1; local_02.m_intarray[local_02.m_int1]==0; local_02.m_int1--) {
	}
	return local_02;
}


CLongInt _CLongInt__add_sub(CLongInt arg_0,CLongInt arg_1)
{
	int local_00;
	int local_01;
	CLongInt local_02;

	arg_0.m_int2=arg_1.m_int2=0;

	local_02.m_int1=local_02.m_int2=0;
	if (_CLongInt__abscompare(arg_0,arg_1)<0) {
		return local_02;
	}
	local_01=0;
	for (local_00=1; local_00<=arg_1.m_int1; local_00++) {
		local_01+=arg_0.m_intarray[local_00]+arg_1.m_intarray[local_00];
		if (local_01<100) {
			local_02.m_intarray[local_00]=local_01;
			local_01=0;
			continue;
		}
		local_02.m_intarray[local_00]=local_01+-100;
		local_01=1;
	}
	while (local_00<=arg_0.m_int1 && local_01!=0) {
		local_01=local_01+arg_0.m_intarray[local_00];
		if (local_01<100) {
			local_02.m_intarray[local_00]=local_01;
			local_01=0;
		} else {
			local_02.m_intarray[local_00]=local_01+-100;
			local_01=1;
		}
		local_00=local_00+1;
	}
	while (local_00<=arg_0.m_int1) {
		local_02.m_intarray[local_00]=arg_0.m_intarray[local_00];
		local_00=local_00+1;
	}
	if (local_01==0) {
		local_02.m_int1=arg_0.m_int1;
	} else {
		if (arg_0.m_int1<=20) {
			local_02.m_int1=arg_0.m_int1+1;
			local_02.m_intarray[local_00]=1;
		}
	}
	return local_02;
}


int _CLongInt__toint(CLongInt arg1)
{
	int local_00;
	if (arg1.m_int1==0) {
		return 0;
	}
	if (arg1.m_int1==1) {
		if (arg1.m_int2==0) {
			return arg1.m_intarray[1];
		}
		return -arg1.m_intarray[1];
	}
	if (arg1.m_int1==2) {
		local_00=arg1.m_intarray[2]*100+arg1.m_intarray[1];
		if (arg1.m_int2==0) {
			return local_00;
		}
		return -local_00;
	}
	if (arg1.m_int1==3) {
		local_00=(arg1.m_intarray[3]*100+arg1.m_intarray[2])*100+arg1.m_intarray[1];
		if (arg1.m_int2==0) {
			return local_00;
		}
		return -local_00;
	}
	return 0;
}


CLongInt _CLongInt__add(CLongInt arg_0,CLongInt arg_1)
{
	int local_00;
	CLongInt local_01;
	if (arg_0.m_int1==0) {
		return arg_1;
	}
	if (arg_1.m_int1==0) {
		return arg_0;
	}
	local_00=_CLongInt__abscompare(arg_0,arg_1)>=0;
	if (arg_0.m_int2==arg_1.m_int2) {
		if (local_00!=0) {
			local_01=_CLongInt__add_sub(arg_0,arg_1);
		} else {
			local_01=_CLongInt__add_sub(arg_1,arg_0);
		}
		local_01.m_int2=arg_0.m_int2;
	} else {
		if (local_00!=0) {
			local_01=_CLongInt__satsub(arg_0,arg_1);
			local_01.m_int2=arg_0.m_int2;
		} else {
			local_01=_CLongInt__satsub(arg_1,arg_0);
			local_01.m_int2=!(arg_0.m_int2!=-1)?0:-1;
		}
	}
	return local_01;
}


int _CLongInt__abscompare(CLongInt arg1,CLongInt arg2)
{
	int local_00;
	if (arg1.m_int1>arg2.m_int1) {
		return 1;
	}
	if (arg2.m_int1>arg1.m_int1) {
		return -1;
	}
	local_00=arg1.m_int1;
	arg1.m_intarray[0]=0;
	arg2.m_intarray[0]=1;
	for ( ; arg1.m_intarray[local_00]==arg2.m_intarray[local_00]; local_00--) {
	}
	if (local_00==0) {
		return 0;
	}
	if (arg1.m_intarray[local_00]>arg2.m_intarray[local_00]) {
		return 1;
	}
	return -1;
}


void CLongInt::_CLongInt_subint(int arg_0)
{
	if (! (arg_0==0||arg_0<=-100||arg_0>=100) ) {
		if (m_int1==0) {
			*this=_CLongInt_letint(-arg_0);
			return;
		}
		if (m_int2==0) {
			if (arg_0>0) {
				subchunk(arg_0);
				return;
			}
			addchunk(-arg_0);
		} else {
			if (arg_0>0) {
				addchunk(arg_0);
				return;
			}
			m_int2=0;
			subchunk(-arg_0);
			m_int2=!(m_int2!=0)?-1:0;
		}
	}
	return;
}


//LINT ldivide(LINT a, LINT b, LINT *r){
CLongInt _CLongInt__div(CLongInt arg_0,CLongInt arg_1,CLongInt * arg_2)
{
	int local_00;
	int local_01;
	int * local_02;
	int local_03;
	int local_04;
	CLongInt local_05;
	CLongInt local_06;
	CLongInt local_07;
	CLongInt local_08;

	local_07.m_int1=local_07.m_int2=0;
	arg_2->m_int1=arg_2->m_int2=0;
	if ( (!(arg_0.m_int1==0||arg_1.m_int1==0)) ) {
		if (arg_1.m_int1==1) {
			if (arg_1.m_int2==0) {
				local_07=_CLongInt__divint(arg_0,arg_1.m_intarray[1],&local_01);
			} else {
				local_07=_CLongInt__divint(arg_0,-arg_1.m_intarray[1],&local_01);
			}
			*arg_2=_CLongInt_letint(local_01);
		} else {
			switch (_CLongInt__abscompare(arg_0,arg_1)) {
			case 0:  
				local_07.m_int2=!(arg_0.m_int2!=arg_1.m_int2)?0:-1;
				local_07.m_int1=1;
				local_07.m_intarray[1]=1;
				break;
			case -1:  
//微妙に違うコードが出る。CLongIntはclassじゃなくてstructが本来かも
//42831d
				*arg_2=arg_0;
				break;
			default:
				if (arg_0.m_int1==20) break;
				local_07.m_int2=!(arg_0.m_int2!=arg_1.m_int2)?0:-1;
//微妙に違うコードが出る。CLongIntはclassじゃなくてstructが本来かも
				arg_2->m_int2=arg_0.m_int2;
				local_01=100/(arg_1.m_intarray[arg_1.m_int1]+1);
				local_05=arg_0;
				local_06=arg_1;
				if (local_01!=1) {
					local_05._CLongInt_multint(local_01);
					local_06._CLongInt_multint(local_01);
				}
				local_07.m_int1=(local_05.m_int1-local_06.m_int1)+1;
				if ((local_04=local_05.m_intarray[local_05.m_int1]/local_06.m_intarray[local_06.m_int1])==0) {
					local_07.m_int1=local_07.m_int1-1;
					local_04=(local_05.m_intarray[local_05.m_int1]*100+*(&local_05.m_int2+local_05.m_int1))/local_06.m_intarray[local_06.m_int1];
				}
				local_05.m_int2=local_06.m_int2;
				local_08.m_int1=0;
				local_00=1;
				local_02=local_07.m_intarray+1;
				for ( ; local_00<=local_07.m_int1; local_00++) {
					*local_02=0;
					local_02=local_02+1;
				}
				local_03=local_07.m_int1;
				while (true) {
					local_08=_CLongInt__multint(local_06,local_04);
					local_08.multbase(local_03-1);
					if (_CLongInt__abscompare(local_08,local_05)>0) {
						local_04=local_04-1;
						continue;
					}
					local_07.m_intarray[local_03]=local_04;
					local_03=local_03-1;
					local_05=_CLongInt__sub(local_05,local_08);
					if (local_05.m_int1==0||local_03==0) break;
					local_04=(local_05.m_intarray[local_05.m_int1]*100+*(&local_05.m_int2+local_05.m_int1))/local_06.m_intarray[local_06.m_int1];
				}
				if (local_07.m_intarray[local_07.m_int1]==0) {
					local_07.m_int1=local_07.m_int1-1;
				}
				if (local_05.m_int1<=0) break;
				*arg_2=_CLongInt__divint(local_05,local_01,&local_04);
				if (arg_2->m_int2==arg_0.m_int2) break;
				if (arg_0.m_int2==0) {
					local_07.subchunk(1);
				} else {
					local_07.addchunk(1);
				}
				if (arg_2->m_int2==0) {
					*arg_2=_CLongInt__sub(*arg_2,arg_1);
				} else {
					*arg_2=_CLongInt__add(*arg_2,arg_1);
				}
			}
		}
	}
	return local_07;
}

//void ldown(LINT *a, int n)
void CLongInt::divbase(int arg1)
{
	int local_00;
	if (! (m_int1==0||arg1==0) ) {
		if (arg1<0) {
			multbase(arg1);
		} else if (m_int1<=arg1) {
			m_int1=m_int2=0;
		} else {
			m_int1=m_int1-arg1;
			for (local_00=1; local_00<=m_int1; local_00++) {
				m_intarray[local_00]=m_intarray[local_00+arg1];
			}
		}
	}
	return;
}


//LINT lgcd(LINT a, LINT b)
CLongInt _CLongInt__gcd(CLongInt arg_0,CLongInt arg_1)
{
	CLongInt local_00;

	local_00.m_int1=local_00.m_int2=0;
	if (! (!(arg_0.m_int2==-1)&&arg_1.m_int2!=-1) ) {
		return local_00;
	}
	do {
		_CLongInt__div(arg_0,arg_1,&local_00);
		arg_0=arg_1;
		arg_1=local_00;
	} while (arg_1.m_int1>0);
	return arg_0;
}


void CLongInt::_CLongInt_addint(int arg_0)
{
	if (! (arg_0==0||arg_0<=-100||arg_0>=100) ) {
		if (m_int1==0) {
			*this=_CLongInt_letint(arg_0);
			return;
		}
		if (m_int2==0) {
			if (arg_0>0) {
				addchunk(arg_0);
				return;
			}
			subchunk(-arg_0);
		} else {
			if (arg_0<=0) {
				addchunk(-arg_0);
				return;
			}
			m_int2=0;
			subchunk(arg_0);
			m_int2=!(m_int2!=0)?-1:0;
		}
	}
	return;
}


CLongInt _CLongInt__modinv(CLongInt arg_0,CLongInt arg_1)
{
	CLongInt local_00;
	CLongInt local_01;
	CLongInt local_02;
	CLongInt local_03;
	CLongInt local_04;
	local_01=arg_1;
	local_02=_CLongInt_letint(1);
	local_03.m_int1=0;
	while (arg_0.m_int1>0) {
		local_00=_CLongInt__div(local_01,arg_0,&local_04);
		local_01=arg_0;
		arg_0=local_04;
		local_04=_CLongInt__mult(local_00,local_02);
		local_04=_CLongInt__sub(local_03,local_04);
		local_03=local_02;
		local_02=local_04;
	}
	if (local_03.m_int2==-1) {
		local_03=_CLongInt__add(local_03,arg_1);
	}
	return local_03;
}


CLongInt _CLongInt__lcm(CLongInt arg_0,CLongInt arg_1)
{
	CLongInt local_00;
	CLongInt local_01;
	local_00.m_int1=0;
	if (! (arg_0.m_int2<0||arg_1.m_int2<0||arg_0.m_int1==0||arg_1.m_int1==0) ) {
		local_00=_CLongInt__div(_CLongInt__mult(arg_0,arg_1),_CLongInt__gcd(arg_0,arg_1),&local_01);
	}
	return local_00;
}


CLongInt _CLongInt__divremain(CLongInt arg_0,CLongInt arg_1)
{
	CLongInt local_00;
	_CLongInt__div(arg_0,arg_1,&local_00);
	return local_00;
}


CLongInt _CLongInt__mult(CLongInt arg1,CLongInt arg2)
{
	CLongInt local_00;
	local_00=_CLongInt__mult_sub(arg1,arg2);
	if (! (!(local_00.m_int1==0)&&arg1.m_int2!=arg2.m_int2) ) {
		return local_00;
	}
	local_00.m_int2=-1;
	return local_00;
}


//LINT lmulp(LINT a, LINT b)
CLongInt _CLongInt__mult_sub(CLongInt arg1,CLongInt arg2)
{
	int * local_00;
	int * local_01;
	int * local_02;
	int local_03;
	int local_04;
	int local_05;
	int local_06;
	int local_07;
	int local_08;
	int local_09;
	CLongInt local_10;

	local_10.m_int1=local_10.m_int2=0;

	if ( ((local_03=arg1.m_int1)==0)||((local_04=arg2.m_int1)==0) ) {
		return local_10;
	}

	local_00=arg1.m_intarray+1;
	if (local_03==1) {
		return _CLongInt__multint(arg2,*local_00);
	}
	if (local_04==1) {
		return _CLongInt__multint(arg1,arg2.m_intarray[1]);
	}
	if ((local_05=local_03+local_04)>20) {
		return local_10;
	}
	local_01=local_10.m_intarray+1;
	local_06=local_05;
	for ( ; local_06--!=0; local_01++) {
		*local_01=0;
	}
	for (local_07=1; local_07<=local_04; local_07++) {

		if ((local_09=arg2.m_intarray[local_07])==0) continue;
		local_08=0;
		local_02=local_00;
		local_01=local_10.m_intarray+local_07;
		local_06=local_03;
		for ( ; local_06--!=0; local_01++) {
			*local_01=(local_08+=*(local_02++)*local_09+*local_01)%100;
			local_08/=100;
		}
		*local_01+=local_08;
	}
	local_01=local_10.m_intarray+local_05;
	while (*local_01==0) {
		local_01--;
	}
	local_10.m_int1=local_01-local_10.m_intarray;
	return local_10;
}


int _CLongInt__isprime(CLongInt arg)
{
	CLongInt local_00;
	CLongInt local_01;
	CLongInt local_02;
	if (! (!(arg.m_int1==0)&&arg.m_int2!=-1) ) {
		return 0;
	}
	if (! (arg.m_int1!=1||arg.m_intarray[1]>=4) ) {
		return 1;
	}
	if (arg.m_intarray[1]%2==0) {
		return 0;
	}
	local_00.m_int1=1;
	local_00.m_int2=0;
	local_00.m_intarray[1]=3;
	while (true) {
		local_02=_CLongInt__div(arg,local_00,&local_01);
		if (local_01.m_int1==0) {
			return 0;
		}
		if (_CLongInt__abscompare(local_00,local_02)>=0) {
			return 1;
		}
		local_00.addchunk(2);
	}
}


CLongInt _CLongInt__powermod(CLongInt arg_0,CLongInt arg_1,CLongInt arg_2)
{
	int local_00;
	CLongInt local_01;
	CLongInt local_02;
	CLongInt local_03;
	CLongInt local_04;
	CLongInt local_05;
	local_05=_CLongInt_letint(1);
	local_01=arg_1;
	local_02=arg_0;
	while (true) {
		if (!(local_01.m_int1>1)&&local_01.m_intarray[1]==0) break;
		local_01.divintself(2,&local_00);
		if (local_00!=0) {
			local_03=_CLongInt__mult(local_05,local_02);
			_CLongInt__div(local_03,arg_2,&local_05);
		}
		local_03=_CLongInt__mult(local_02,local_02);
		_CLongInt__div(local_03,arg_2,&local_02);
	}
	return local_05;
}


CLongInt _CLongInt__loadstr(char * arg_0)
{
	char * local_00;
	int local_01;
	int local_02;
	int local_03;
	char local_04[100];
	CLongInt local_05;
	local_05.m_intarray[0]=0;
	local_05.m_int2=0;
	local_02=0;
	for ( ; !(*arg_0==0)&&(int)*arg_0==32; arg_0++) {
	}
	local_03=strlen(arg_0);
	if (local_03==0) {
		local_05.m_intarray[1]=0;
		local_05.m_int1=0;
		local_05.m_int2=0;
		return local_05;
	}
	if ((int)*arg_0==45) {
		local_05.m_int2=-1;
		local_02=local_02+1;
	}
	if ((int)*arg_0==43) {
		local_02=local_02+1;
	}
	strcpy(local_04,arg_0+local_02);
	local_00=local_04;
	local_00=strrev(local_00);
	local_03=local_03-local_02;
	for (local_01=0; local_01<local_03; local_01++) {
		if (isdigit((int)*(local_00+local_01))==0) break;
		*(local_00+local_01)-='0';
	}
	local_03=local_01;
	local_02=1;
	local_01=0;
	while (local_01<local_03) {
		local_05.m_intarray[local_02]=(int)*(local_00+local_01)+(int)*((local_00+1)+local_01)*10;
		local_02=local_02+1;
		local_01=local_01+2;
	}
	local_05.m_int1=local_02-1;
	return local_05;
}

//LINT lset(long n){
CLongInt _CLongInt_letint(int src)
{
	int local_00;
	CLongInt local_01;

	local_01.m_int1=local_01.m_int2=0;
	if (src==0) {
		return local_01;
	}
	if (src<0) {
		local_01.m_int2=-1;
		src=-src;
	}
	local_00=1;
	do {
		local_01.m_intarray[local_00]=src%100;
		local_00=local_00+1;
		src/=100;
	} while (src>0);
	local_01.m_int1=local_00-1;
	return local_01;
}


CLongInt _CLongInt__sub(CLongInt arg_0,CLongInt arg_1)
{
	int local_00;
	CLongInt local_01;

	local_01.m_int1=local_01.m_int2=0;
	local_00=_CLongInt__abscompare(arg_0,arg_1);
	if (! (local_00!=0||arg_0.m_int2!=arg_1.m_int2) ) {
		return local_01;
	}
	if (arg_0.m_int1==0) {
		arg_1.m_int2=!(arg_1.m_int2!=0)?-1:0;
		return arg_1;
	}
	if (arg_1.m_int1==0) {
		return arg_0;
	}
	local_00=local_00>=0;
	if (arg_0.m_int2==arg_1.m_int2) {
		if (local_00!=0) {
			local_01=_CLongInt__satsub(arg_0,arg_1);
			local_01.m_int2=arg_0.m_int2;
		} else {
			local_01=_CLongInt__satsub(arg_1,arg_0);
			local_01.m_int2=!(arg_0.m_int2!=-1)?0:-1;
		}
	} else {
		if (local_00!=0) {
			local_01=_CLongInt__add_sub(arg_0,arg_1);
		} else {
			local_01=_CLongInt__add_sub(arg_1,arg_0);
		}
		local_01.m_int2=arg_0.m_int2;
	}
	return local_01;
}


void CLongInt::multbase(int arg1)
{
	int local_00;
	int * local_01;
	if (! (m_int1==0||arg1==0) ) {
		if (arg1<0) {
			divbase(arg1);
			return;
		}
		local_00=m_int1;
		local_01=m_intarray+m_int1+arg1;
		while (local_00>=1) {
			*local_01=*(local_01-arg1);
			local_00=local_00-1;
			local_01--;
		}
		for (local_00=arg1; local_00>=1; local_00--) {
			*local_01=0;
			local_01--;
		}
		m_int1=m_int1+arg1;
	}
	return;
}


void CLongInt::divintself(int arg,int * remain)
{
	int local_00;
	int local_01;
	CLongInt local_02;
	CLongInt local_03;
	*remain=0;
	if (! (m_int1==0||arg==0) ) {
		if (abs(arg)>=100) {
			local_02=_CLongInt_letint(arg);
			*this=_CLongInt__div(*this,local_02,&local_03);
			*remain=_CLongInt__toint(local_03);
			return;
		}
		if (arg<0) {
			m_int2=!(m_int2!=-1)?0:-1;
			arg=-arg;
		}
		local_01=0;
		for (local_00=m_int1; local_00>=1; local_00--) {
//微妙に違うコードが出る
			local_01=local_01*100+m_intarray[local_00];
			m_intarray[local_00]=local_01/arg;
			local_01%=arg;
		}
		*remain=!(m_int2!=0)?local_01:-local_01;
		if (m_intarray[m_int1]==0) {
			m_int1=m_int1-1;
		}
	}
	return;
}


CLongInt _CLongInt__divint(CLongInt arg1,int arg2,int * remain)
{
	int local_00;
	int local_01;
	CLongInt local_02;
	CLongInt local_03;
	CLongInt local_04;
	local_04.m_int1=local_04.m_int2=*remain=0;
	if (arg1.m_int1==0) {
		return local_04;
	}
	if (arg2==0) {
		return local_04;
	}
	if (abs(arg2)>=100) {
		local_02=_CLongInt_letint(arg2);
		local_04=_CLongInt__div(arg1,local_02,&local_03);
		*remain=_CLongInt__toint(local_03);
		return local_04;
	}
	if (! (!(!(arg1.m_int2!=0)&&arg2<0)&&(arg1.m_int2!=-1||arg2<=0)) ) {
		local_04.m_int2=-1;
	}
	if (arg2<0) {
		arg2=-arg2;
	}
	local_01=0;
	for (local_00=arg1.m_int1; local_00>=1; local_00--) {
		local_01=local_01*100+arg1.m_intarray[local_00];
		local_04.m_intarray[local_00]=local_01/arg2;
		local_01%=arg2;
	}
	*remain=!(arg1.m_int2!=0)?local_01:-local_01;
	local_04.m_int1=arg1.m_int1;
	if (local_04.m_intarray[arg1.m_int1]==0) {
		local_04.m_int1=local_04.m_int1-1;
	}
	return local_04;
}


void CLongInt::_CLongInt_multint(int arg_0)
{
	int local_00;
	int local_01;
	CLongInt local_02;
	if (m_int1!=0) {
		if (arg_0==0) {
			m_int1=m_int2=0;
			return;
		}
		if (abs(arg_0)>=100) {
			local_02=_CLongInt_letint(arg_0);
			*this=_CLongInt__mult(*this,local_02);
			return;
		}
		if (arg_0<0) {
			m_int2=!(m_int2!=-1)?0:-1;
			arg_0=-arg_0;
		}
		local_01=0;
		for (local_00=1; local_00<=m_int1; local_00++) {
			local_01=local_01+m_intarray[local_00]*arg_0;
			m_intarray[local_00]=local_01%100;
			local_01/=100;
		}
		while (local_01!=0) {
			m_int1=m_int1+1;
			if (m_int1>20) {
				m_int1=m_int1-1;
				return;
			}
			m_intarray[m_int1]=local_01%100;
			local_01/=100;
		}
	}
	return;
}

//LINT smul(LINT a, int n)
CLongInt _CLongInt__multint(CLongInt arg1,int arg2)
{
	int local_00;
	int local_01;
	CLongInt local_02;
	CLongInt local_03;

	local_03.m_int1=local_03.m_int2=0;
	if (! (!(arg1.m_int1==0)&&arg2!=0) ) {
		return local_03;
	}
	if (abs(arg2)>=100) {
		local_02=_CLongInt_letint(arg2);
		return _CLongInt__mult(arg1,local_02);
	}
	if (! (!(!(arg1.m_int2!=0)&&arg2<0)&&(arg1.m_int2!=-1||arg2<0)) ) {
		local_03.m_int2=-1;
	}
	if (arg2<0) {
		arg2=-arg2;
	}
	local_01=0;
	for (local_00=1; local_00<=arg1.m_int1; local_00++) {
		local_01+=arg1.m_intarray[local_00]*arg2;
		local_03.m_intarray[local_00]=local_01%100;
		local_01/=100;
	}
	local_03.m_int1=arg1.m_int1;
	while (local_01!=0) {
		local_03.m_int1=local_03.m_int1+1;
		if (local_03.m_int1>20) {
			local_03.m_int1=local_03.m_int1-1;
			return local_03;
		}
		local_03.m_intarray[local_03.m_int1]=local_01%100;
		local_01/=100;
	}
	return local_03;
}


CLongInt _CLongInt__subint(CLongInt arg_0,int arg_1)
{
	arg_0._CLongInt_subint(arg_1);
	return arg_0;
}



