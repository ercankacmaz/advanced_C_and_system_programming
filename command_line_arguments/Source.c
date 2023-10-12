#include<stdio.h>



/*
Bir program� komut sat�r�ndan �al��t�r�rken program isminin yan�na yaz�lan yaz�lara "komut sat�r�
arg�manlar (command line arguments)" denilmektedir. �rbe�in:

prog ali veli selami

Burada �al��t�r�lmak istenen program "prog" isimli programd�r. "prog", "ali", "veli", "selami" yaz�lar� ise program�n
komut sat�r� arg�manlar�n� olu�turmaktad�r. Komut sat�r� arg�manlar�n�n amac� program� �al��t�r�rken 
yapaca�� i�ler konusunda etkili olmakt�r.

C'de program�n komut sat�r� arg�manlar� main fonksiyonundan al�nmaktad�r. Yani program�n komut sat�r� arg�manalr�
tipik olarak kabuk(shell) program� taraf�ndan komut sat�r�ndan al�n�r ve manin fonksiyonuna arg�man
olarak ge�ilir. C standaertlar�na g�re main fonksiyonunun parametrik yap�s� iki bi�imdedir:

int main(void)
int main(int argc, char *argv[])

Tabii burada argc ve argv isimleri gelenekseldir. Bu isimlerin kullan�lmas� zorunlu de�ildir. 
C standartlar�nda main fonksiyonun geri d�n�� de�erinin int t�r�nden omas� zorunludur. Fonksiyonlardaki
k��eli parantezler "g�sterici(pointer)" anlam�na gelmektedir. Bu durumda main fonksiyonu �u
�ekilde de yaz�labilr:

int main(int argc, char **argv)

Buradaki argc sat�r�ndaki arg�manlar�n program ismi dahil olmak �zere toplam say�s�n� belirtmektedir.
argv ise program�n ismi dahil olmka �zere komut sat�r� arg�man yaz�lar�n�n ba�lang�� adreslerini tutan
g�sterici dizisini g�stermektedir. standartlar bu dizinin son elemanunda NULL adersin olaca��n� (yani
argv(argc) de�erinin NULL olaca��n�) garanti etmektedir.
*/





int main(int argc, char* argv[])
{
	for (int i; i < argc; i++)
		puts(argv[i]);




	return 0;
}


/*
Komut sat�r� arg�manlar�nda "se�enek (option)" denilen bir kavram vard�r. Program�n yapt��� i�
�zerinde baz� belirlemeleri olu�turmak i�in se�enbek arg�manlardan faydalanmaktad�r. Yani se�enekeler 
bir i�in �e�itli varyasyonlar�n� belirtmek i�in kullanlan komut sat�r� arg�manlar�d�r. Se�enek belirme
i�lemi UNIX/Linux d�nyas�nda "-" karakteri ile Windows d�nyas�nda "/" karakteri ile yap�lmkatad�r. 
�rne�in:

gcc -c sample.c
cl /c sample.c

Burada UNIX/Linux sistemlerindeki gcc derleyicisinin -c se�ene�i "derle fakat link etme" anlam�na
gelmektedir. Benzer bi�inde Windows sistemlerinde Microsoft C derleyicilerindeki /c se�ene�i de ayn�
anlama gelmektedir.
*/