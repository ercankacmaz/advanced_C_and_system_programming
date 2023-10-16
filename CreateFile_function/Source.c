#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>





int main()
{
	HANDLE hFile;


	if ((hFile = CreateFile("text.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL)) == INVALID_HANDLE_VALUE)
	{
		fprintf(stderr, "CreateFile : %lu", GetLastError());
		exit(EXIT_FAILURE);
	}


	printf("Succes!\n");


	CloseHandle(hFile);


}