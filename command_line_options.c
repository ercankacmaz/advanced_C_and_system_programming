#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>

#define DEFAULT_LINE_CHAR   16

/*
dispfile <dosya ismi>

-t --> text (default)
-x --> hex 
-o --> octal
-n --> bir satırda kaç hex digit

*/

/*
Ayrıştırma işlemi sırasında bir hata oluştuğunda programın devam
etmemesini isteriz. Ancak tüm hataların rapor edilmesi de gerekmektedir.
Bunun için bir flag değişkeninden faydalanılabilir. O flag değişkeni
hata durumunda set edilir. Çıkışta kontrol edilip duruma göre program
sonlandırılır.
*/

int check_number(const char *str);
bool disp_text(FILE *f);
bool disp_hex(FILE *f, int n_arg);
bool disp_octal(FILE *f, int n_arg);



int main(int argc, char *argv[])
{
int result;
int t_flag, o_flag, x_flag, n_flag, err_flag;
int n_arg;
FILE *f;


t_flag = o_flag = x_flag = n_flag = err_flag = 0;
n_arg = DEFAULT_LINE_CHAR;
opterr = 0;

while((result = getopt(argc, argv, "toxn:")) != -1)
{
    switch (result)
    {
        case 't':
           t_flag = 1;
           n_arg = 0;
           break;

        case 'o':
            o_flag = 1;
            break;
        case 'x':
            x_flag = 1;
            break;
        case 'n':
            n_flag = 1;
            if((n_arg = check_number(optarg)) < 0)
            {
                fprintf(stderr, "-n arguement is invalid!..\n");
                err_flag = 1;
            }
            break;
        case '?':
            if(optopt == 'n')
              fprintf(stderr, "-%c option given without  arguemenet!..\n", optopt);
            else 
            
              fprintf(stderr, "invalid option: -%c\n", optopt);
            err_flag = 1;
            
            break;    

    }
}

if(err_flag)
{
   exit(EXIT_FAILURE);
}

if(t_flag + o_flag + x_flag > 1)
{
    fprintf(stderr, "Only one of -[tox] option may be specified!..\n");
    exit(EXIT_FAILURE);
}
if(t_flag + o_flag + x_flag == 0)
{
    t_flag = 1;
    n_arg = 0;
}

if(t_flag && n_arg)
{
    fprintf(stderr, "-n option cannot used with -t option!..\n");
    exit(EXIT_FAILURE);
}


/*if(t_flag)
{
    printf("-t given..\n");
}

if(o_flag)
{
    printf("-o given..\n");
}

if(x_flag)
{
    printf("-x given..\n");
}

if(n_flag)if(t_flag)
{
    printf("-t given..\n");
}

if(o_flag)
{
    printf("-o given..\n");
}

if(x_flag)
{
    printf("-x given..\n");
}

if(n_flag)
{
    printf("-n given with arguement \"%d\"...\n", n_arg);
}
if(argc -optind == 0)
{
    fprintf(stderr, "file must be specified!..\n");
    exit(EXIT_FAILURE);
}

if(argc -optind > 1)
{
    fprintf(stderr, "too many files specified!..\n");
    exit(EXIT_FAILURE);
}

printf("OK\n");

/*for(int i = optind; i < argc; ++i)
{
    puts(argv[i]);
}

printf("n value: %d\n", n_arg);*/

if((f = fopen(argv[optind], t_flag ? "r" : "rb")) == NULL)
{
    fprintf(stderr, "cannot open file %s!..\n", argv[optind]);
    exit(EXIT_FAILURE);
}

if(t_flag)
{
    result = disp_text(f);
}

else if(x_flag)
{
    result =disp_hex(f, n_arg);
}

else if(o_flag)
{
    result = disp_octal(f, n_arg);
}
if(!result)
{
    fprintf(stderr, "cannot read file: %s\n", argv[optind]);
    exit(EXIT_FAILURE);
}



fclose(f);

    return 0;
}

bool disp_text(FILE *f)
{
    int ch;

    while((ch = fgetc(f)) != EOF)
    {
        putchar(ch);
    }

    return feof(f);
}

bool disp_hex(FILE *f, int n_arg)
{
    size_t i;
    int ch;

    for(i = 0; (ch = fgetc(f)) != EOF; ++i)
    {
        if(i % n_arg == 0)
        {
            printf("%08zX ", i);
        }
        ch = fgetc(f);
        
        printf("%02X ", ch);
        if(i % n_arg == n_arg-1)
        {
            putchar('\n');
        }
    }
    putchar('\n');

    return feof(f);
}

bool disp_octal(FILE *f, int n_arg)
{
    size_t i;
    int ch;

    for(i = 0; (ch = fgetc(f)) != EOF; ++i)
    {
        if(i % n_arg == 0)
        {
            printf("%08zo ", i);
        }
        ch = fgetc(f);
        
        printf("%03o ", ch);
        if(i % n_arg == n_arg-1)
        {
            putchar('\n');
        }
    }
    putchar('\n');

    return feof(f);
}

int check_number(const char *str)
{
    const char *temp;
    int result;

    while(isspace(*str))
    {
        ++str;
    }
    temp = str;

    while(isdigit(*str))
    {
        ++str;
    }

    if(*str != '\0')
    {
        return -1;
    }
   
    result = atoi(temp);
    if(!result)
    {
        return -1;
    }

    return result;
}