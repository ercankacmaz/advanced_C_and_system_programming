#include<stdio.h>
#include<stdlib.h>


/*
remove standart bir C fonksiyonudur. Prototipi stdio.h kütüphanesine bulunmaktadýr. Dosya silmek için
kullanýlýr. Dosyanýn yol ifadesini alýr. Bir dosyanýn silinememesi için pek çok sebep bulunabilir.
Örneðin:
-Dosya yoktur ve bu sebeple silinemez.
-Dosya mevcuttur fakat iþlemin dosyayý silebilme yetkisi yoktur.
Byu sebeplerle fonksiyonun baþarýsý programcý tarafýndan kontrol edilmelidir.

int remove(const char *filename);

fonksiyonun geri dönüþ deðeri dosyanýn baþarýlý bir þekilde silinip silinmediðini belirtir.
Eðer iþlem baþarýlý bir þekilde gerçekleþirse fonksiyon 0 deðerini döndürürken baþarýsýz gerçekleþen iþlemlerde
sýfýr olmayan bir deðer döndürülür.
Bir dosya remove fonksiyonu ile silindiðinde, dosya geri dönüþüm kutusunsa saklanmaz. Geri dönüþüm
kutusu yüksek sevyeli bir shell organizasyonudur. Geri dönüþüm kutusuyla iþletim sisteminin kernalýnýn
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
rename isimli standart C fonksiyonu bir dosyanýn ismini deðiþtirmek için kullanýlýr. Bir dosyanýn 
ismi baþka bir dizininde de deðiþtirilebilir. Bu da taþýma etkisi yaratmaktadýr. Rename fonksiyonun
prototipi:
#include<stdio.h>

int  rename(const char *old, const char *new);

Fonksiyonun birinci parametresi ismi deðiþtirilecek dosyanýn yol ifadesini, ikinci parametresi ise
 yeni isimli yol ifadesini almaktadýr. Yukarýda belirttiðimiz gibi bir dosyanýn ismi baþka bir dizindeki 
 dosya ismi olarak deðiþtirebiliriz. Bu zaten bir taþýma iþlevi görecektir. Tabi rename iþlemi sýrasýnda 
 dosyanýbn disk üzerindeki içeriði taþýnmamaktadýr.

Rename baþarý durumunda 0 deperini baþarýsýzlýk durumunda -1 deðerini döndürmektedir.  
*/