#include<stdio.h>
#include<stdlib.h>


/*
system fonksiyonu ilgili sistemdeki "komut yorumlay�c�(command interpretter)" program�n�
�al��t�ran ve ona bizim fonksiyona arg�man olarak verdi�imiz komutu i�lettiren standart bir C
fonksiyonudur. Fonksiyon prototipi:

#include<stdlib.h>

int system(const char *string)

Fonksiyonun geri d�n�� de�eri derleyiciye g�re de�i�ebilir. Ancak Windows, macOS, UNIX/Linux
sistemlerinde ba�ar� durumunda 0, ba�ar�s�zl�k durumunda s�f�r d��� bir de�er geri d�nd�r�l�r.

C derleyicisinin oldu�u  bir sistemde komut yorumlay�c�s� olmak zorunda de�ildir. �rne�in 
i�letim sistemi olmayan bir mikrodenetleyici sisteminde komut yorumlay�c�s� da olmayacakt�r.
��te programc� ilgili i�letim sisteminde komut yorumlay�c�s� olup olmad���n� anlayabilmek i�in
fonksiyonu NULL adres ile �a��rabilir. Bu durumda fonksiyon 0 d��� herhangi bir de�er d�n�yorsa
sistemde bir kpmut yorumlay�s�c� vard�r. S�fr� de�eri geri d�nerse ilgili sistemde komut yorumlay�s�c�
yok demektir.



*/




int main(void)
{
	for (int i = 0; i < 10; i++)
		printf("%d\n", i);

	printf("Press ENTER to continue...\n");
	getchar();

	system("cls");

	getchar();

	return 0;
}