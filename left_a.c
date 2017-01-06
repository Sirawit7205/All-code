#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b) {return (*(int*)a-*(int*)b);}

int dat[100005]={};

int main()
{
	int i,pa,pb,a;
	long long int sum=0;
	scanf("%d",&a);
	for(i=0;i<a;i++) scanf("%d",&dat[i]);
	qsort(dat,a,sizeof(int),cmp);
	pa=0; pb=a-1;
	while(1)
	{
		if(a>=4)
		{
			sum+=dat[pb]+dat[pa]+dat[pa+1]; pa+=2; pb-=2; a-=4;
		}
		else {for(i=0;i<a;i++) sum+=dat[pa+i]; break;}
	}
	printf("%lld",sum);
	return 0;
}