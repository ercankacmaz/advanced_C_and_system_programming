#include<stdio.h>



/*
Bir programý komut satýrýndan çalýþtýrýrken program isminin yanýna yazýlan yazýlara "komut satýrý
argümanlar (command line arguments)" denilmektedir. Örbeðin:

prog ali veli selami

Burada çalýþtýrýlmak istenen program "prog" isimli programdýr. "prog", "ali", "veli", "selami" yazýlarý ise programýn
komut satýrý argümanlarýný oluþturmaktadýr. Komut satýrý argümanlarýnýn amacý programý çalýþtýrýrken 
yapacaðý iþler konusunda etkili olmaktýr.

C'de programýn komut satýrý argümanlarý main fonksiyonundan alýnmaktadýr. Yani programýn komut satýrý argümanalrý
tipik olarak kabuk(shell) programý tarafýndan komut satýrýndan alýnýr ve manin fonksiyonuna argüman
olarak geçilir. C standaertlarýna göre main fonksiyonunun parametrik yapýsý iki biçimdedir:

int main(void)
int main(int argc, char *argv[])

Tabii burada argc ve argv isimleri gelenekseldir. Bu isimlerin kullanýlmasý zorunlu deðildir. 
C standartlarýnda main fonksiyonun geri dönüþ deðerinin int türünden omasý zorunludur. Fonksiyonlardaki
köþeli parantezler "gösterici(pointer)" anlamýna gelmektedir. Bu durumda main fonksiyonu þu
þekilde de yazýlabilr:

int main(int argc, char **argv)

Buradaki argc satýrýndaki argümanlarýn program ismi dahil olmak üzere toplam sayýsýný belirtmektedir.
argv ise programýn ismi dahil olmka üzere komut satýrý argüman yazýlarýnýn baþlangýç adreslerini tutan
gösterici dizisini göstermektedir. standartlar bu dizinin son elemanunda NULL adersin olacaðýný (yani
argv(argc) deðerinin NULL olacaðýný) garanti etmektedir.
*/





int main(int argc, char* argv[])
{
	for (int i; i < argc; i++)
		puts(argv[i]);




	return 0;
}


/*
Komut satýrý argümanlarýnda "seçenek (option)" denilen bir kavram vardýr. Programýn yaptýðý iþ
üzerinde bazý belirlemeleri oluþturmak için seçenbek argümanlardan faydalanmaktadýr. Yani seçenekeler 
bir iþin çeþitli varyasyonlarýný belirtmek için kullanlan komut satýrý argümanlarýdýr. Seçenek belirme
iþlemi UNIX/Linux dünyasýnda "-" karakteri ile Windows dünyasýnda "/" karakteri ile yapýlmkatadýr. 
Örneðin:

gcc -c sample.c
cl /c sample.c

Burada UNIX/Linux sistemlerindeki gcc derleyicisinin -c seçeneði "derle fakat link etme" anlamýna
gelmektedir. Benzer biçinde Windows sistemlerinde Microsoft C derleyicilerindeki /c seçeneði de ayný
anlama gelmektedir.
*/