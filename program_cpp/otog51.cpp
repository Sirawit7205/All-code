#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

priority_queue<int> q;

int main()
{
	int n,l,h,x,y,a,t,i,j,ans=0,dl,cr;
	scanf("%d %d %d",&n,&l,&h);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a);
		for(j=0;j<a;j++)
		{
			scanf("%d",&t);
			q.push(t); ans++;
		}
		scanf("%d %d",&x,&y);
		if(x==0) dl=l; else dl=l-((-1*h*x)/y);
		while(1)
		{
			if(q.empty()) {printf("0\n"); break;}
			cr=q.top();
			if(cr>=dl) {q.pop(); ans--;}
			else break;
		}
		printf("%d\n",ans);
	}
	return 0;
}