#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b) {return (*(int*)a-*(int*)b);}

int dat[500005]={};

int main()
{
	int i,a,b,p=0,x=0;
	scanf("%d",&a);
	for(i=0;i<a;i++) scanf("%d",&dat[i]);
	qsort(dat,a,sizeof(int),cmp);
	b=a-1;
	while(1)
	{
		if(dat[p]>=b) {printf("%d",b+x); break;}
		else if(dat[p]==b-1) {printf("%d",dat[p]+x); break;}
		else {b-=dat[p]+1; x+=dat[p]; p++;}
	}
	return 0;
}