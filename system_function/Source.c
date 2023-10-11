#include<stdio.h>
#include<stdlib.h>


/*
system fonksiyonu ilgili sistemdeki "komut yorumlayýcý(command interpretter)" programýný
çalýþtýran ve ona bizim fonksiyona argüman olarak verdiðimiz komutu iþlettiren standart bir C
fonksiyonudur. Fonksiyon prototipi:

#include<stdlib.h>

int system(const char *string)

Fonksiyonun geri dönüþ deðeri derleyiciye göre deðiþebilir. Ancak Windows, macOS, UNIX/Linux
sistemlerinde baþarý durumunda 0, baþarýsýzlýk durumunda sýfýr dýþý bir deðer geri döndürülür.

C derleyicisinin olduðu  bir sistemde komut yorumlayýcýsý olmak zorunda deðildir. Örneðin 
iþletim sistemi olmayan bir mikrodenetleyici sisteminde komut yorumlayýcýsý da olmayacaktýr.
Ýþte programcý ilgili iþletim sisteminde komut yorumlayýcýsý olup olmadýðýný anlayabilmek için
fonksiyonu NULL adres ile çaðýrabilir. Bu durumda fonksiyon 0 dýþý herhangi bir deðer dönüyorsa
sistemde bir kpmut yorumlayýsýcý vardýr. Sýfrý deðeri geri dönerse ilgili sistemde komut yorumlayýsýcý
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