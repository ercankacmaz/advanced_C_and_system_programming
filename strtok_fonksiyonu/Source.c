#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>


/*
strtok fonksiyonu  stringleri tokenlara ayırmak için kuyllanılır. <string.h> kütüphanesinde bulunur.
Prototipi  char *strtok(char *str, const char *delin)
*str tokenlarına ayrılacak olan dizinin adresini argüman olarak alır, *delin ise stringteki ayırmaları yapacak karakteri argüman olarak alır. 
Bir döngü ile kullanılır. Eğer fonksiyon sadece bir kez çağırılırsa sadece ilk ayrılan kısım yazdırılabilir. 
*/


int main()
{
	char s[] = "ali,veli,hakan";
	char* str;

	for (str = strtok(s, ","); str != NULL; str = strtok(NULL, ","))
	{
		puts(str);
	}
	return 0;

}