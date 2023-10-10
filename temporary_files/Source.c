#include<stdio.h>
#include<stdlib.h> 



/*
Programýn çalýþmasý sýrasýnda belli  ir amaçla yaratýlan o amaç gerçekleþtirildikten sonra silinen 
kýsa ömürlü dosyalara "geçici dosyalar(temporary files) denir. Geçici dosyalarý oluþtururken önemli
bir sorun bu dosyalarýn verilecek isimlerin tesadüfen var olan dosyalarla çakýþmasýdýr.

tmpfile isimli standart C fonksiyonu olmayan bir dosyayý "wb+" modunda yaratýr ve dosyaya iliþkin 
dosya bilgi göstericisiyle geri döner. Böyle dosyalar kapatýldýðýnda diskteki dosya da otomatik olarak 
silinecektir. tmpfile fonksiyonu da çeþitli sebeplerden ötürü baþarýsýz olabilir. Fonksiyon baþarýsýzlýk
durumunda NULL adrese geri dönmektedir. Programcý fonksiyonun baþarýsýný kontrol etmelidir.
*/









int main(void)
{

	FILE* f;
	int i;
	int val;

	if ((f = tmpfile()) == NULL)
	{
		fprintf(stderr, "cannot create temporary file!..\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < 1000000; i++)
	{
		if (fwrite(&i, sizeof(int), 1, f) != 1)
		{
			fprintf(stderr, "cannot write file!..\n");
			exit(EXIT_FAILURE);
		}
	}
	
	while (fread(&val, sizeof(int), 1, f) == 1)
		printf("%d\n", val);

	if (ferror(f))
	{
		fprintf(stderr, "cannot read file!..\n");
		exit(EXIT_FAILURE);
	}

	fclose(f);

	return 0;
}