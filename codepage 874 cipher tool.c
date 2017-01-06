#include <stdio.h>
#include <wchar.h>
#include <time.h>

int main()
{
    FILE *fp;
    FILE *fp2;
    wchar_t dat[100000]= {};
    char fname[100]= {}, fname2[100]= {}, index[4]={};
    int len=0,i;
    time_t cur=time(NULL);
    printf("Please enter source file: ");
    gets(fname);
    printf("Please enter destination file: ");
    gets(fname2);
    fp=fopen(fname,"r");
    fgetws(dat, 100000, fp);
    fclose(fp);
    fp2=fopen(fname2,"a");
    len=wcslen(dat);
    printf("Complete report:\n\n");
    printf("Cipher with: ISO/IEC 8859-11 codepage standard.\n");
    printf("Return values: 2 digits HEX from codepage's index.\n");
    printf("Message length: %d\n",len);
    printf("Create time: %s\n",ctime(&cur));
    printf("----------Begin data block----------\n\n");
    for(i=1; i<=len; i++)
    {
        if(i%27==0)
        {
            printf("%X",dat[i-1]);
        }
        else
        {
            printf("%X ",dat[i-1]);
        }
        sprintf(index,"%X ",dat[i-1]);
        fputs(index,fp2);
    }
    printf("\n\n-----------End data block-----------\n\n");
    printf("Report ended.\nEOF\n");
    fclose(fp2);
    return 0;
}

