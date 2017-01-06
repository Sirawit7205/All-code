#include<cstdio>
#include<algorithm>

using namespace std;

int x[5005]={},y[5005]={};
float ans=0,two=2,ta=0,tb=0;

int main()
{
	int n,m,i;
	float tta,ttb;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&x[i],&y[i]);
	}
	x[i]=0; x[i+1]=n; y[i]=0; y[i+1]=n;
	sort(x,x+i+1); sort(y,y+i+1);
	for(i=0;i<=m;i++)
	{
		tta=(x[i+1]-x[i])/two; ttb=(y[i+1]-y[i])/two;
		//printf("%d: %.3f %.3f\n",i,tta,ttb);
		if(tta>ta) ta=tta; if(ttb>tb) tb=ttb;
	}
	if(ta<=tb) ans=ta; else ans=tb; 
	printf("%.3f",ans);
	return 0;
}