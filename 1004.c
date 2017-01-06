#include<stdio.h>

int cls[10005]={},chk[15]={},q[1005]={};

int main()
{
	int n,m,ta,tb,i,j,qh=0,qt=0;
	char c[10];
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&ta,&tb);
		cls[tb]=ta;
	}
	while(1)
	{
		scanf("%s",c);
		if(c[0]=='X') break;
		else if(c[0]=='E')
		{
			scanf("%d",&ta);
			if(chk[cls[ta]]==0) {q[qt]=ta; qt++; chk[cls[ta]]++;}
			else
			{
				for(i=qh;i<=qt;i++)
                    if(cls[q[i]]==cls[ta])
                    {
                        while(1) {if(cls[q[i]]==cls[ta]) i++; else break;}
                        qt++; chk[cls[ta]]++;
                        for(j=i;j<=qt;j++)
                        {
                            tb=q[j]; q[j]=ta; ta=tb;
                        }
                        break;
                    }
			}
		}
		else
		{
			if(qh==qt) printf("empty\n");
			else {printf("%d\n",q[qh]); chk[cls[q[qh]]]--; qh++;}
		}
	}
	printf("0");
	return 0;
}
