#include<stdio.h>

int main()
{
    int i=0,len=0;
    char a[5100]={};
    gets(a);
    while(a[i]!='\0') {i++; len++;}
    for(i=0;i<len;i++)
    {
        if(a[i]>=65&&a[i]<=90) a[i]+=32;
        else a[i]-=32;
    }
    puts(a);
    return 0;
}
