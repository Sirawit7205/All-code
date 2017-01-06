#include<iostream>
#include<cstdio>

using namespace std;

int cn[1000005]={},f[1005]={};

int main()
{
	int i,j,n,m,k,l,t,pta,ptb,cnt;
	scanf("%d %d %d %d",&n,&m,&k,&l);
	for(i=0;i<n;i++) scanf("%d",&cn[i]);
	for(i=0;i<k;i++)
	{
		for(j=0;j<m;j++) {scanf("%d",&t); f[j]=t-l;}
		cnt=0; pta=0; ptb=0;
		while(pta<n&&ptb<m)
		{
			if(cn[pta]<=f[ptb]+(l*2)&&f[ptb]<=cn[pta]) {cnt++;/*   printf("%d %d: %d\n",pta,ptb,cnt); */ pta++; }
			else if(cn[pta]<f[ptb]) {pta++;/*  printf("A: %d\n",pta); */}
			else {ptb++; /* printf("B: %d\n",ptb); */}
		}
		printf("%d\n",cnt);
	}
return 0;
}