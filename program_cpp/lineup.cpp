#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

struct a
{
		int id,h;
}str[1005];

bool cmp(a A,a B)
{
	if(A.h==B.h) return A.id < B.id;
	else return A.h > B.h;
}

int main()
{
	int i,n,q,c,ta,j;
	scanf("%d %d %d",&n,&q,&c);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&str[i].h);
		str[i].id=i;
	}
	sort(&str[1],&str[n+1],cmp);
	for(i=1;i<=q;i++)
	{
		scanf("%d",&ta);
		for(j=1;j<=n;j++)
		{
			if(str[j].id==ta)
			{
				if(j%c!=0) printf("%d ",(j/c)+1); else printf("%d ",j/c);
				if(j%c==0) printf("%d\n",c); else printf("%d\n",j%c);
				break;
			}
		}
	}
	return 0;
}