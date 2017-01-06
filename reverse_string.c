#include<stdio.h>

int main()
{
    char str[100];
    int i,len;
    gets(str);
    for(len=0;str[len]!='\0';len++);
    for(i=len-1;i>=0;i--)
    {printf("%c",str[i]);}
    return 0;
}
