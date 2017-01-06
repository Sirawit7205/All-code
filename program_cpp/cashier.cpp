#include<iostream>
#include<cstdio>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

vector<int> q[20]={};

int main()
{
	int n,qu,t,i,j,tb,mi=INT_MAX,x,b;
	scanf("%d %d",&n,&qu);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&tb);
		for(j=0;j<tb;j++) {scanf("%d",&t); q[i].push_back(t);}
	}
	for(i=0;i<qu;i++)
	{
		scanf("%d %d",&t,&tb);
		if(t==0)
		{
			q[tb].erase(q[tb].begin());
		}
		else
		{
			x=n; mi=INT_MAX;
			for(j=1;j<=n;j++)
			{
				b=lower_bound(q[j].begin(),q[j].end(),tb)-q[j].begin();
				//printf("B: %d\n",b);
				if(b<mi) {x=j; mi=b; /*printf("X: %d %d\n",x,mi);*/}
			}
			printf("%d\n",x);
			q[x].push_back(tb);
			sort(q[x].begin(),q[x].end());
		}
	}
	return 0;
}