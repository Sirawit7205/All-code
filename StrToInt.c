#include<stdio.h>
#include<string.h>
#include<math.h>

char str[100];
int in=0,len;

void s2n(char str[100],int len2)
{
    if(len2==0) return;
    else
    {in+=(str[len2-1]-48)*pow(10,len-len2);}
    return s2n(str,len2-1);
}

int main()
{
    scanf("%s",str);
    len=strlen(str);
    s2n(str,len);
    printf("%d",in);
    return 0;
}
