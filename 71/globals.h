//initialized

#include <IniFiles.hpp>

#include "CRC4.h"


extern const char * g_tagnames[];
extern int                            g_int_unk000           ;				//fr 005351C0 00000004 
extern int                            g_int_unk001           ;				//fr 005351C4 00000004 
extern int                            g_int_flag_logged_newversion   ;				//fr 005351C8 00000004 
extern int                            g_int_flag_logged_downfolderdisk   ;				//fr 005351CC 00000004 
extern int                            g_int_flag_logged_cachefolderdisk   ;				//fr 005351D0 00000004 


//--


extern bool                           gi_flag_unk300         ;				//fr 0053D930 00000001 


//--


extern int                            g_int_1                ;				//fr 0053E574 00000004 

//--

//extern int                            g_int                  ;				//fr 0053E5A0 00000004 

//--

//initialized??
extern CRC4                           g_CRC4                 ;				//fr 0053ED38 00000303 

extern bool                           g_bln_unk500           ;				//fr 0053F03C 00000001 


//--


extern int                            g_int_unk500          ;				//fr 0053F414 00000004 
extern int                            g_int_unk501           ;				//fr 0053F418 00000004 
extern int                            g_int_unk502           ;				//fr 0053F41C 00000004 
extern int                            g_int_unk503           ;				//fr 0053F420 00000004 
extern int                            g_int_unk504           ;				//fr 0053F424 00000004 
extern int                            g_int_unk505           ;				//fr 0053F428 00000004 
extern int                            g_int_unk506           ;				//fr 0053F42C 00000004 
extern float                          g_float_unk101         ;				//fr 0053F430 00000004 
extern float                          g_float_unk102         ;				//fr 0053F434 00000004 
extern bool                           g_bool_unk100          ;				//fr 0053F438 00000001 


typedef __stdcall BOOL (*t_pfn_ReadProcessMemory)(
  HANDLE hProcess,  // handle to the process whose memory is read
  LPCVOID lpBaseAddress,
                    // address to start reading
  LPVOID lpBuffer,  // address of buffer to place read data
  DWORD nSize,      // number of bytes to read
  LPDWORD lpNumberOfBytesRead
                    // address of number of bytes read
);

typedef __stdcall EXECUTION_STATE (*t_pfn_SetThreadExecutionState)(
  EXECUTION_STATE esFlags  // execution requirements
);




extern HMODULE                        g_hmodule_unk          ;				//fr 0053F444 00000004
extern t_pfn_SetThreadExecutionState  g_pproc_SetThreadExecutionState   ;				//fr 0053F448 00000004
extern HANDLE                         g_handle_uxthemeDll    ;				//fr 0053F44C 00000004
extern PPROC                          g_pproc_EnableThemeNantoka   ;				//fr 0053F450 00000004
extern t_pfn_ReadProcessMemory        g_pproc_ReadProcessMemory   ;				//fr 0053F454 00000004


extern int                            g_int_unk400           ;				//fr 0053F45C 00000004 
extern int                            g_int_unk401           ;				//fr 0053F460 00000004 
extern int                            g_int_unk402           ;				//fr 0053F464 00000004 
extern int                            g_int_unk403           ;				//fr 0053F468 00000004 
extern int                            g_int_unk404           ;				//fr 0053F46C 00000004 
extern int                            g_int_unk405           ;				//fr 0053F470 00000004 
extern int                            g_int_unk406           ;				//fr 0053F474 00000004 
extern int                            g_int_unk407           ;				//fr 0053F478 00000004 
extern int                            g_int_unk408           ;				//fr 0053F47C 00000004 
extern int                            g_int_unk409           ;				//fr 0053F480 00000004 
extern int                            g_int_unk410           ;				//fr 0053F484 00000004 
extern int                            g_int_unk411           ;				//fr 0053F488 00000004 
extern int                            g_int_unk412           ;				//fr 0053F48C 00000004 
extern int                            g_int_unk413           ;				//fr 0053F490 00000004 
extern int                            g_int_unk414           ;				//fr 0053F494 00000004 
extern int                            g_int_unk415           ;				//fr 0053F498 00000004 
extern int                            g_int_unk416           ;				//fr 0053F49C 00000004 
extern int                            g_int_unk417           ;				//fr 0053F4A0 00000004 


//--

extern TIniFile *                     g_pTIniFile            ;				//fr 00549134 00000004 

extern int                            g_opt_longFontSpace    ;				//fr 00549144 00000004 


//--


