#include<iostream>
#include<cstdio>

using namespace std;

int nc[10005]={},na[10005]={};

void findh(int p,int c)
{
	if(nc[p]==p) {if(nc[c]!=c) findh(p,nc[c]); nc[c]=p; return;}
	else findh(nc[p],c);
}

int main()
{
	int n,m,t,i,j,c,nu=0,p;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++) nc[i]=i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		if(t==0) nu++;
		for(j=0;j<t;j++)
		{
			scanf("%d",&c);
			na[c]++;
			if(j==0) p=c;
			else findh(p,c);
		}	
	}
	//for(i=1;i<=m;i++) printf("%d ",nc[i]); printf("\n");
	for(i=1;i<=m;i++) if(nc[i]==i&&na[i]!=0) nu++;
	printf("%d",nu-1);
	return 0;
}