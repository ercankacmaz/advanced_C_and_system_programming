#include<stdio.h>




/*
tmpfile fpnksiyonu ile a��lm�� bir ge�ici bir dosya elde ederiz. Ancak ge�ici dosyan�n ismini bilmeyiz.
Oysa baz� uygulamalarda programc� bir isim ile ge�ici dosya olu�turmak ister. �rne�in bir text
dosyas�ndaki t�m "ankara" yaz�lar�n� "istanbul" yapmak isteyebiliriz. B�yle bir i�lemi dosya �st�nde yapmak
hem yava�l��a hem de kar���kl��a yol a�ar. Bunun kolasy bir yolu ge�ici dosyaya yazmak ve i�lem bitince de 
as�l dosyay� silip ge�ici dosyan�n ismini de�i�tirmek. ��te bunun i�in ge�ici dosyan�n ismini bilmemiz gerekir.

tmpnam isimli standart C fonksiyonu g e�ici dosyay� a�maz, bize ge�ici dosyaya ili�kin yol ifadesi verir.
Bu yol ifadesi belirtilen dosyay� a�mak programc�n�n yapaca�� bir i�tir. Prototipi:

#include<stdio.h>

char *tmpnam(char *s);

Fonksiyonun parametresi ge�ici dosya isminin yerle�tirilece�i dizinin adresini almaktad�r. Ancak fonksiyon
�a��r�l�rken arg�man olarak NULL adres de ge�ilebilir. Bu durumda fonkisyon ge�ici dosya ismini static 
yerel bir dizinin i�erisine yerle�tirir ve o dizinin adresiyle geri d�ner. E�er arg�man olarak NULL 
adres ge�ilmezse fonksiyonun arg�man olrak ge�ilmi� adresin ayn�s�yla geri d�ner. Fonksiyonun en az 
TMP_MAX (<stdio.h> i�erisinde define edilmi�tir.) kadar dosya ismi �retebilece�i garanti edilmi�tir.
Ancak makul bir limit a��ld���nda fonksiyon ba�ar�s�z olabilir. Bu durumda NULL adrese geri d�ner.


*/








int main(void)
{






	return 0;
}