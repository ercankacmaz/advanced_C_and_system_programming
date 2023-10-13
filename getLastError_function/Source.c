#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>


/*
if (!SomeAPIFunc(...)
	{
		fprintf(stderr, "SomeAPIFunc failed: %lu\n", GetLastError());
		exit(EXIT_FAILURE);
	}
*/



int main()
{
	HANDLE hFile;

	if ((hFile = CreateFile("test.xxx", GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL)) == INVALID_HANDLE_VALUE)
	{
		fprintf(stderr, "CreateFile failed: %lu\n", GetLastError());
		exit(EXIT_FAILURE);
	}

	printf("Ok\n");
}