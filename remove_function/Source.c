#include<stdio.h>
#include<stdlib.h>


/*
remove standart bir C fonksiyonudur. Prototipi stdio.h k�t�phanesine bulunmaktad�r. Dosya silmek i�in
kullan�l�r. Dosyan�n yol ifadesini al�r. Bir dosyan�n silinememesi i�in pek �ok sebep bulunabilir.
�rne�in:
-Dosya yoktur ve bu sebeple silinemez.
-Dosya mevcuttur fakat i�lemin dosyay� silebilme yetkisi yoktur.
Byu sebeplerle fonksiyonun ba�ar�s� programc� taraf�ndan kontrol edilmelidir.

int remove(const char *filename);

fonksiyonun geri d�n�� de�eri dosyan�n ba�ar�l� bir �ekilde silinip silinmedi�ini belirtir.
E�er i�lem ba�ar�l� bir �ekilde ger�ekle�irse fonksiyon 0 de�erini d�nd�r�rken ba�ar�s�z ger�ekle�en i�lemlerde
s�f�r olmayan bir de�er d�nd�r�l�r.
Bir dosya remove fonksiyonu ile silindi�inde, dosya geri d�n���m kutusunsa saklanmaz. Geri d�n���m
kutusu y�ksek sevyeli bir shell organizasyonudur. Geri d�n���m kutusuyla i�letim sisteminin kernal�n�n
bir ilgisi yoktur.

*/





int main()
{
	if (remove("test.csv"))
	{
		fprintf(stderr, "cannot remove file!..\n");
		exit(EXIT_FAILURE);
	}

	printf("file removed\n");


	return 0;
}



/*
rename isimli standart C fonksiyonu bir dosyan�n ismini de�i�tirmek i�in kullan�l�r. Bir dosyan�n 
ismi ba�ka bir dizininde de de�i�tirilebilir. Bu da ta��ma etkisi yaratmaktad�r. Rename fonksiyonun
prototipi:
#include<stdio.h>

int  rename(const char *old, const char *new);

Fonksiyonun birinci parametresi ismi de�i�tirilecek dosyan�n yol ifadesini, ikinci parametresi ise
 yeni isimli yol ifadesini almaktad�r. Yukar�da belirtti�imiz gibi bir dosyan�n ismi ba�ka bir dizindeki 
 dosya ismi olarak de�i�tirebiliriz. Bu zaten bir ta��ma i�levi g�recektir. Tabi rename i�lemi s�ras�nda 
 dosyan�bn disk �zerindeki i�eri�i ta��nmamaktad�r.

Rename ba�ar� durumunda 0 deperini ba�ar�s�zl�k durumunda -1 de�erini d�nd�rmektedir.  
*/