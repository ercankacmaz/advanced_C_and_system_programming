#include<stdio.h>




/*
tmpfile fpnksiyonu ile açýlmýþ bir geçici bir dosya elde ederiz. Ancak geçici dosyanýn ismini bilmeyiz.
Oysa bazý uygulamalarda programcý bir isim ile geçici dosya oluþturmak ister. Örneðin bir text
dosyasýndaki tüm "ankara" yazýlarýný "istanbul" yapmak isteyebiliriz. Böyle bir iþlemi dosya üstünde yapmak
hem yavaþlýða hem de karýþýklýða yol açar. Bunun kolasy bir yolu geçici dosyaya yazmak ve iþlem bitince de 
asýl dosyayý silip geçici dosyanýn ismini deðiþtirmek. Ýþte bunun için geçici dosyanýn ismini bilmemiz gerekir.

tmpnam isimli standart C fonksiyonu g eçici dosyayý açmaz, bize geçici dosyaya iliþkin yol ifadesi verir.
Bu yol ifadesi belirtilen dosyayý açmak programcýnýn yapacaðý bir iþtir. Prototipi:

#include<stdio.h>

char *tmpnam(char *s);

Fonksiyonun parametresi geçici dosya isminin yerleþtirileceði dizinin adresini almaktadýr. Ancak fonksiyon
çaðýrýlýrken argüman olarak NULL adres de geçilebilir. Bu durumda fonkisyon geçici dosya ismini static 
yerel bir dizinin içerisine yerleþtirir ve o dizinin adresiyle geri döner. Eðer argüman olarak NULL 
adres geçilmezse fonksiyonun argüman olrak geçilmiþ adresin aynýsýyla geri döner. Fonksiyonun en az 
TMP_MAX (<stdio.h> içerisinde define edilmiþtir.) kadar dosya ismi üretebileceði garanti edilmiþtir.
Ancak makul bir limit aþýldýðýnda fonksiyon baþarýsýz olabilir. Bu durumda NULL adrese geri döner.


*/








int main(void)
{






	return 0;
}