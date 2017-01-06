#include<stdio.h>
#include<string.h>

char t[205]={},a[205]={},b[205]={};
int la,lb,qa[205]={},qb[205]={};

int main()
{
	int i,j,k,l,x,y;
	scanf("%s",a); scanf("%s",b);
	la=strlen(a); lb=strlen(b);
	if(la<lb) y=la; else y=lb;
	for(i=1;i<=la;i++) qa[i]=qa[i-1]+a[i-1]; for(i=1;i<=lb;i++) qb[i]=qb[i-1]+b[i-1];
	for(i=y;i>0;i--)
	{
		for(j=1;j<=la-i+1;j++)
		{
			for(k=1;k<=lb-i+1;k++)
			{
				x=0;
				if(qa[j+i-1]-qa[j-1]==qb[k+i-1]-qb[k-1])
				{
					//printf("FOUND %d %d %d\n",i,j,k);
					for(l=0;l<i;l++) if(a[j+l-1]!=b[k+l-1]) {x=1; break;}
					if(x==0) {for(l=0;l<i;l++) printf("%c",a[j+l-1]); return 0;}
				}
			}
		}
	}
	return 0;
}
