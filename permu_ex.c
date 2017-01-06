#include <stdio.h>
#include <stdlib.h>
int ch[20]={0},ponlup[20]={0},max;

void permue(int n)
{
	int X=1;
	if(n==max+1)
	{
		for(X=1;X<=max;X++)
		{
			printf("%d ",ponlup[X]);
		}
		printf("\n");
		return ;
	}
	for(X=1;X<=max;X++)
	{
	if(ch[X]==0)
		{
			ponlup[n]=X;
			ch[X]=1;
			permue(n+1);
			ch[X]=0;
			//ponlup[n]=0;
		}
	}
}

int main()
{
	scanf("%d",&max);
	permue(1);
	return 0;
}
