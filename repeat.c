#include<stdio.h>
#include<string.h>

int main()
{
    char str[105]={};
    int i=0,len,c=1,paren=0,ic=1;
    scanf("%s",str);
    len=strlen(str);
    while(str[i]!='a') i++; paren=i;
    for(i=paren+1;i<=len;i++)
    {
        if(i==len) c*=ic;
        else if(str[i]==')') {c*=ic; ic=1;}
        else if(str[i]=='i') ic++;
    }
    printf("%d",c);
    return 0;
}
