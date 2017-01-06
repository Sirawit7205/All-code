#include<stdio.h>
#include<limits.h>

char str[SHRT_MAX]={};

void rev(int n)
{
    if(n<0) return;
    printf("%c",str[n-1]);
    rev(n-1);
}

int main()
{
    int n=0;
    scanf("%s",str);
    while(str[n]!='\0') n++;
    rev(n);
    return 0;
}
