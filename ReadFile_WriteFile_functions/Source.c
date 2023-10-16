#define _CRT_SECURE_NO_WARNINGS




#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define BUFFER_SIZE    512
#define SOURCE_FILE_PATH   "test.txt"
#define DEST_FILE_PATH     "mest.txt"

void ExitSys(LPCSTR lpszMsg);

int main()
{
	HANDLE hFileSource, hFileDest;
	char buf[BUFFER_SIZE];
	DWORD dwRead, dwWrite;
	BOOL bResult;


	if ((hFileSource = CreateFile(SOURCE_FILE_PATH, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL)) == INVALID_HANDLE_VALUE)
	{
		ExitSys("CreateFile");
	}

	if ((hFileDest = CreateFile(DEST_FILE_PATH, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL)) == INVALID_HANDLE_VALUE)
	{
		ExitSys("CreateFile");
	}

	while ((bResult = ReadFile(hFileSource, buf, BUFFER_SIZE, &dwRead, NULL)) != 0 && dwRead > 0) {
		if (!WriteFile(hFileDest, buf, dwRead, &dwWrite, NULL))
			ExitSys("WriteFile");
		if (dwRead != dwWrite)
		{
			fprintf(stderr, "Partial write Error..!\n");
			exit(EXIT_FAILURE);
		}
	}

	if (!bResult)
		ExitSys("ReadFile");

	CloseHandle(hFileDest);
	CloseHandle(hFileSource);
}


void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();

	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL))
	{
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}