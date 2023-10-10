#include<stdio.h>
#include<stdlib.h> 



/*
Program�n �al��mas� s�ras�nda belli  ir ama�la yarat�lan o ama� ger�ekle�tirildikten sonra silinen 
k�sa �m�rl� dosyalara "ge�ici dosyalar(temporary files) denir. Ge�ici dosyalar� olu�tururken �nemli
bir sorun bu dosyalar�n verilecek isimlerin tesad�fen var olan dosyalarla �ak��mas�d�r.

tmpfile isimli standart C fonksiyonu olmayan bir dosyay� "wb+" modunda yarat�r ve dosyaya ili�kin 
dosya bilgi g�stericisiyle geri d�ner. B�yle dosyalar kapat�ld���nda diskteki dosya da otomatik olarak 
silinecektir. tmpfile fonksiyonu da �e�itli sebeplerden �t�r� ba�ar�s�z olabilir. Fonksiyon ba�ar�s�zl�k
durumunda NULL adrese geri d�nmektedir. Programc� fonksiyonun ba�ar�s�n� kontrol etmelidir.
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