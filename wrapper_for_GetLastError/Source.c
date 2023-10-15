#define _CRT_SECURE_NOWARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>


/*
Hata nedenine iliþkin "last_error" kodunu anlamak zordur. Bunun yerine ilgili hata mesajýna iliþkin hata yazýsý
 rapor edilebilir. FormatMessage API fonksiyonu "last_error" deðerini alarak bize o hata koduna iliþkin hata 
 yazýsýný verir. Aþaðýda bu iþ için bir wrapper function yazýlmýþtýr.
*/

void ExitSys(LPCSTR lpszMsg);

int main()
{
	HANDLE hFile;

	if ((hFile = CreateFile("test.xxx", GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL)) == INVALID_HANDLE_VALUE)
		ExitSys("CreateFile");

	printf("ok\n");
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