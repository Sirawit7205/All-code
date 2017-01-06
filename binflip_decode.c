#include<stdio.h>
#include<string.h>

char dat[1000001]={};

void flip(int a, int b)
{
    int i;
    char t;
    for(i=a;i<=a+((b-a)/2);i++) {t=dat[i]; dat[i]=dat[b-i+a]; dat[b-i+a]=t;}
}

void decode(int a, int b)
{
    int mid=(a+b)/2;
    if(a==b) return;
    flip(a,b);
    decode(a,mid);
    decode(mid+1,b);
}

int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",dat);
    decode(0,n-1);
    printf("%s",dat);
    return 0;
}
