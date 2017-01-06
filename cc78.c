#include<stdio.h>

int main()
{
	int sum=0,tar,a[10]={},i,x=0;
	scanf("%d",&tar);
	for(i=0;i<5;i++) {scanf("%d",&a[i]); sum+=a[i];}
	if(sum<tar) {printf("-1"); return 0;}
	else if(sum>tar)
	{
		for(i=0;i<5;i++)
		{
			if(a[i]==sum-tar) {a[i]=0; x=1; break;}
		}
	}
	else x=1;
	if(x==0) printf("-1");
	else for(i=0;i<5;i++) printf("%d ",a[i]);
	return 0;
}