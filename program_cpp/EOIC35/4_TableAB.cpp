#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int u,v,x,y,i,j,mi=1,mo=1;
	scanf("%d %d %d %d",&u,&v,&x,&y);
	for(i=1;i<=u*x;i++)
	{
	    mo=1;
		for(j=1;j<=v*y;j++)
		{
			if(mi==1) {if(mo==1) printf("A"); else printf("B");} else {if(mo==1) printf("B"); else printf("A");}
			if(j%y==0) {if(mo==1) mo=2; else mo=1;}
		}
		if(i%x==0) {if(mi==1) mi=2; else mi=1;}
		printf("\n");
	}
	return 0;
}
