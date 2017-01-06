#include<iostream>
#include<cstdio>

#define hashs 500009;
#define hashsize 1<<19;

using namespace std;

int hashtable[1<<19], code[1<<17];
bool chk[100005]={};

void inhash(int a,int ind)
{
	int now=a%hashs;
	int next=1;
	while(hashtable[now]!=0)
	{
		now+=next;
		next<<=1;
		now%=hashsize;
	}
	hashtable[now]=ind;
	code[ind]=a;
}

int findhash(int a)
{
	int now=a%hashs;
	int next=1;
	while(hashtable[now]!=0)
	{
		if(code[hashtable[now]]==a) break;
		now+=next;
		next<<=1;
		now%=hashsize;
	}
	return hashtable[now];
}

int main()
{
	int k,m,i,j,pow,q,l,a,ret,c=0;
	char t[35]={},dat[1000005]={};
	scanf("%d %d",&k,&m);
	for(i=1;i<=k;i++)
	{
		scanf("%s",t);
		pow=1; a=0;
		for(j=1;j<=m;j++)
		{
			a+=(t[m-j]-48)*pow;
			pow*=2;
		}
		inhash(a,i);
	}
	scanf("%d",&q);
	for(i=0;i<q;i++)
	{
		scanf("%d",&l); scanf("%s",dat);
		pow=1; a=0;
		for(j=1;j<=m;j++)
		{
			a+=(dat[m-j]-48)*pow;
			pow*=2;
		}
		for(j=m;j<=l;j++)
		{
			ret=findhash(a);
			if(ret!=0) chk[ret]=true;
			a=(a<<1)&((1<<m)-1);
			if(dat[j]=='1') a++;
		}
		for(j=1;j<=k;j++) if(chk[j]==true) {printf("%d ",j); chk[j]=false; c=1;}
		if(c==0) printf("OK"); else c=0;
		printf("\n");
	}
	return 0;
}