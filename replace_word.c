#include<stdio.h>

char replaceStr(char str,char c1,char c2)
{
    if(str==c1)
    {str=c2;}
    return str;
}

int main()
{
    char c1,c2,str[100],res[100];
    int i,len;
    printf("Enter string: "); gets(str);
    printf("Search for: "); c1=getchar();
    getchar();
    printf("Replace with: "); c2=getchar();
    for(len=0;str[len]!='\0';len++);
    for(i=0;i<len;i++)
    {res[i]=replaceStr(str[i],c1,c2);}
    for(i=0;i<len;i++)
    {printf("%c",res[i]);}
    return 0;
}
