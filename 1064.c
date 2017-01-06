#include<stdio.h>

int qtree[65][65]={},qtp[65][65]={},q[4500][2]={},pchk[4500]={},n,m,pcnt=1,rnd=2;
char tmp[65][65]={};

void bfs(int a,int b)
{
	int h=0,t=1;
	q[h][0]=a; q[h][1]=b; qtp[a][b]=pcnt;
	while(h<=t)
	{
		a=q[h][0]; b=q[h][1]; h++;
		if(qtp[a-1][b]==-1&&a-1>0) {q[t][0]=a-1; q[t][1]=b; t++; qtp[a-1][b]=pcnt;}
		if(qtp[a+1][b]==-1&&a+1<=n) {q[t][0]=a+1; q[t][1]=b; t++; qtp[a+1][b]=pcnt;}
		if(qtp[a][b-1]==-1&&b-1>0) {q[t][0]=a; q[t][1]=b-1; t++; qtp[a][b-1]=pcnt;}
		if(qtp[a][b+1]==-1&&b+1<=m) {q[t][0]=a; q[t][1]=b+1; t++; qtp[a][b+1]=pcnt;}
	}
	pcnt++;
}

int fnd(int a,int b,int k)
{
	int i,j,c=0;
	for(i=a-k;i<=a;i++)
	{
		for(j=b-k;j<=b;j++)
		{
			if(qtp[i][j]!=0&&pchk[qtp[i][j]]!=rnd) {c++; pchk[qtp[i][j]]=rnd;}
		}
	}
	return c;
}

int main()
{
	int i,j,k,mx,ansa=0,ansb=99999,f=0,x;
	scanf("%d %d",&m,&n);
	if(m>n) mx=n; else mx=m;
	for(i=0;i<n;i++) scanf("%s",tmp[i]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(tmp[i][j]=='T') qtree[i+1][j+1]=qtree[i][j+1]+qtree[i+1][j]-qtree[i][j]+1;
			else qtree[i+1][j+1]=qtree[i][j+1]+qtree[i+1][j]-qtree[i][j];
			if(tmp[i][j]=='P') qtp[i+1][j+1]=-1;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++) if(qtp[i][j]==-1) bfs(i,j);
	}
	for(k=mx;k>0;k--)
	{
		for(i=k;i<=n;i++)
		{
			for(j=k;j<=m;j++)
			{
				if(qtree[i][j]-qtree[i-k][j]-qtree[i][j-k]+qtree[i-k][j-k]==0)
				{
					f=1; ansa=k; rnd++;
					x=fnd(i,j,k-1); if(x<ansb) ansb=x;
					if(ansb==0) f=2;
				}
				if(f==2) break;
			}
			if(f==2) break;
		}
		if(f!=0) break;
	}
	if(ansa==0) ansb=0;
	printf("%d %d",ansa*ansa,ansb);
	return 0;
}