//---------------------------------------------------------------------------
#include "hdrs.h"

#include <vcl.h>

//#pragma hdrstop

#include <IniFiles.hpp>

#include "def.h"

#include "MainUnit.h"

extern TIniFile *                     g_pTIniFile;



//---------------------------------------------------------------------------
USEFORM("MainUnit.cpp", MainForm);
USEFORM("ControlUnit.cpp", ControlForm);
USEFORM("AboutUnit.cpp", AboutForm);
USEFORM("AutoDownUnit.cpp", AutoDownForm);
USEFORM("NodeAddUnit.cpp", NodeAddForm);
USEFORM("FolderAddUnit.cpp", FolderAddForm);
USEFORM("DownParamUnit.cpp", DownParamForm);
USEFORM("IpConvUnit.cpp", IpConvForm);
USEFORM("OptionUnit.cpp", OptionForm);
USEFORM("ViewUnit.cpp", ViewForm);
USEFORM("BbsMakeUnit.cpp", BbsMakeForm);
USEFORM("BbsWriteUnit.cpp", BbsWriteForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	HANDLE local_01;
	int local_02;
#ifndef _DEBUG
	if (IsDebuggerPresent()) {
		exit(0);
	}
#endif
	for (local_02=0; local_02<5; local_02++) {
		local_01=OpenMutex(0x001F0001,false,"Winny");
		if (local_01==0) break;
		CloseHandle(local_01);
		Sleep(1000);
	}
	if (local_02==5) {
		return 0;
	}
	local_01=CreateMutex(NULL,false,"Winny");
	try {
		Application->Initialize();
		Application->ShowMainForm=false;
		Application->CreateForm(__classid(TControlForm), &ControlForm);
		Application->CreateForm(__classid(TMainForm), &MainForm);
		if (g_pTIniFile->ReadInteger("Frame","Minimize",0)==0) {
			MainForm->Show();
		}
		Application->CreateForm(__classid(TAutoDownForm), &AutoDownForm);
		Application->CreateForm(__classid(TOptionForm), &OptionForm);
		Application->CreateForm(__classid(TViewForm), &ViewForm);
		Application->CreateForm(__classid(TBbsMakeForm), &BbsMakeForm);
		Application->CreateForm(__classid(TBbsWriteForm), &BbsWriteForm);
		Application->Run();
	}
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception1)
                 {
						 Application->ShowException(&exception1);
                 }
        }
	ReleaseMutex(local_01);
	return 0;
}
//---------------------------------------------------------------------------
