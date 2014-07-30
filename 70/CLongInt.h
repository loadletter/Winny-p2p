#ifndef _CLONGINT_H_INCLUDED
#define _CLONGINT_H_INCLUDED


class CLongInt
{
public:
	int                            m_int1                        ;   //fr      0      4
	int                            m_int2                        ;   //fr      4      4
	int                            m_intarray[21]                ;   //fr      8     84

	CLongInt()
	{
		int local_00;
		for (local_00=0; local_00<20; local_00++) {
			m_intarray[local_00]=0;
		}
		m_int1=1;
		m_int2=0;
	}

	void subchunk(int n);
	void addchunk(int n);
	void _CLongInt_subint(int arg_0);
	void divbase(int arg1);
	void _CLongInt_addint(int arg_0);
	void multbase(int arg1);
	void divintself(int arg,int * remain);
	void _CLongInt_multint(int arg_0);

};


CLongInt _CLongInt__satsub(CLongInt arg_0,CLongInt arg_1);
CLongInt _CLongInt__add_sub(CLongInt arg_0,CLongInt arg_1);
int _CLongInt__toint(CLongInt arg1);
CLongInt _CLongInt__add(CLongInt arg_0,CLongInt arg_1);
int _CLongInt__abscompare(CLongInt arg1,CLongInt arg2);
CLongInt _CLongInt__div(CLongInt arg_0,CLongInt arg_1,CLongInt * arg_2);
CLongInt _CLongInt__gcd(CLongInt arg_0,CLongInt arg_1);
CLongInt _CLongInt__modinv(CLongInt arg_0,CLongInt arg_1);
CLongInt _CLongInt__lcm(CLongInt arg_0,CLongInt arg_1);
CLongInt _CLongInt__divremain(CLongInt arg_0,CLongInt arg_1);
CLongInt _CLongInt__mult(CLongInt arg1,CLongInt arg2);
CLongInt _CLongInt__mult_sub(CLongInt arg1,CLongInt arg2);
int _CLongInt__isprime(CLongInt arg);
CLongInt _CLongInt__powermod(CLongInt arg_0,CLongInt arg_1,CLongInt arg_2);
CLongInt _CLongInt__loadstr(char * arg_0);
CLongInt _CLongInt_letint(int src);
CLongInt _CLongInt__sub(CLongInt arg_0,CLongInt arg_1);
CLongInt _CLongInt__divint(CLongInt arg1,int arg2,int * remain);
CLongInt _CLongInt__multint(CLongInt arg1,int arg2);
CLongInt _CLongInt__subint(CLongInt arg_0,int arg_1);



#endif //_CLONGINT_H_INCLUDED

