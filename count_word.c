#include<stdio.h>

int main()
{
    int i=0,j=1,len=0,count=0;
    char str[100]={};
    gets(str);
    while(j>0)
    {
        if(str[i]!='\0')
        {len++; i++;}
        else
        {j=0;}
    }
    for(i=0;i<len;i++)
    {
        if(str[i]!=' '&&str[i-1]==' '||str[i]!=' '&&i==0)
        {count++;}
    }
    printf("%d",count);
    return 0;
}
