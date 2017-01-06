#include<stdio.h>
#include<string.h>

char dat[1000001]={};

void flip(int a, int b)
{
    int i;
    char t;
    for(i=a;i<=a+((b-a)/2);i++) {t=dat[i]; dat[i]=dat[b-i+a]; dat[b-i+a]=t;}
}

void encode(int a,int b)
{
	int mid=(a+b)/2;
	if(a==b) return;
	else if(a-b==1||a-b==-1) {flip(a,b); return;}
	else {encode(a,mid); encode(mid+1,b); flip(a,b);}
}

int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",dat);
    encode(0,n-1);
    printf("%s",dat);
    return 0;
}

