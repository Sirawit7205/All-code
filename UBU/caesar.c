#include<stdio.h>
#include<string.h>

int main()
{
    int i,l;
    char dat[255]={};
    gets(dat);
    l=strlen(dat);
    for(i=0;i<l;i++)
    {
        if(dat[i]==' ') printf(" ");
        else if(dat[i]>=65&&dat[i]<=90)
        {
            if(dat[i]=='X') printf("A");
            else if(dat[i]=='Y') printf("B");
            else if(dat[i]=='Z') printf("C");
            else printf("%c",dat[i]+3);
        }
    }
    return 0;
}
