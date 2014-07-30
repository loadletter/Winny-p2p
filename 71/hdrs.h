//バイナリ一致を目指す場合にdefineする
#define EXACTMATCH


//const定義
#ifdef EXACTMATCH
#define _CONST
#else
#define _CONST const
#endif


#include <map>
#include <vector>
#include <algorithm>

#ifdef EXACTMATCH
//こう表現すると、tpdscのポインタも_STL::が付く模様
//でもデバッグ情報を付加しようとするとコンパイラ内部エラーでコンパイルできない
using std::vector;
using std::map;
using std::multimap;
using std::sort;
using std::pair;
using std::make_pair;
#else
using namespace std;
#endif

/*
#define PAD_0001 asm nop;
#define PAD_0002 asm nop; asm nop;
#define PAD_0003 asm nop; asm nop; asm nop;
#define PAD_0004 asm nop; asm nop; asm nop; asm nop;
#define PAD_0005 PAD_0004 asm nop;
#define PAD_0006 PAD_0004 asm nop; asm nop;
#define PAD_0007 PAD_0004 asm nop; asm nop; asm nop;
#define PAD_0008 PAD_0004 asm nop; asm nop; asm nop; asm nop;
#define PAD_0009 PAD_0008 asm nop;
#define PAD_000a PAD_0008 asm nop; asm nop;
#define PAD_000b PAD_0008 asm nop; asm nop; asm nop;
#define PAD_000c PAD_0008 asm nop; asm nop; asm nop; asm nop;
#define PAD_000d PAD_000c asm nop;
#define PAD_000e PAD_000c asm nop; asm nop;
#define PAD_000f PAD_000c asm nop; asm nop; asm nop;
#define PAD_0010 PAD_000c asm nop; asm nop; asm nop; asm nop;
#define PAD_0020 PAD_0010 PAD_0010
#define PAD_0030 PAD_0010 PAD_0010 PAD_0010
#define PAD_0040 PAD_0010 PAD_0010 PAD_0010 PAD_0010
#define PAD_0050 PAD_0040 PAD_0010
#define PAD_0060 PAD_0040 PAD_0010 PAD_0010
#define PAD_0070 PAD_0040 PAD_0010 PAD_0010 PAD_0010
#define PAD_0080 PAD_0040 PAD_0010 PAD_0010 PAD_0010 PAD_0010
#define PAD_0090 PAD_0080 PAD_0010
#define PAD_00a0 PAD_0080 PAD_0010 PAD_0010
#define PAD_00b0 PAD_0080 PAD_0010 PAD_0010 PAD_0010
#define PAD_00c0 PAD_0080 PAD_0010 PAD_0010 PAD_0010 PAD_0010
#define PAD_00d0 PAD_00c0 PAD_0010
#define PAD_00e0 PAD_00c0 PAD_0010 PAD_0010
#define PAD_00f0 PAD_00c0 PAD_0010 PAD_0010 PAD_0010
#define PAD_0100 PAD_00c0 PAD_0010 PAD_0010 PAD_0010 PAD_0010

*/



