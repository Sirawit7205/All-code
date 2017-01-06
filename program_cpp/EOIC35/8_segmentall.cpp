#include<iostream>
#include<cstdio>

using namespace std;

int dat[100005][3]={};

int main()
{
	int i,j,n,rc=1,ta,tb;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&ta,&tb);
		for(j=1;j<=rc;j++)
		{
			if(ta<dat[j][0]&&tb<dat[j][1]) {dat[j][0]=ta; break;}
			else if(tb>dat[j][0]&&tb>dat[j][1]) {dat[j][1]=tb; break;}
			else if(j==rc)
			{
				rc++;
				dat[j+1][0]=ta; dat[j+1][1]=tb;
				break;
			}
		}
	}
	printf("%d",rc);
	return 0;
}