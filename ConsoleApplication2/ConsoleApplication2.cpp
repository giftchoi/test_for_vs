// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ConsoleApplication2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;
void findfile(CString filename);

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// initialize MFC and print and error on failure
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: change error code to suit your needs
			_tprintf(_T("Fatal Error: MFC initialization failed\n"));
			nRetCode = 1;
		}
		else
		{
			findfile(_T("*.*"));
			
		}
	}
	else
	{
		// TODO: change error code to suit your needs
		_tprintf(_T("Fatal Error: GetModuleHandle failed\n"));
		nRetCode = 1;
	}

	return nRetCode;
}

void findfile(CString filename){
	CFileFind finder;
	BOOL bWorking = finder.FindFile(filename);
	while (bWorking){
		bWorking = finder.FindNextFileW();
		if (finder.IsDirectory()){
			filename = finder.GetFilePath() + _T("\\*");
			findfile(filename);
		}
		else wcout << (LPCTSTR)finder.GetFileName() << endl;
	}
}
