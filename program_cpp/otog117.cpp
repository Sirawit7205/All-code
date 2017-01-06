#include<cstdio>
#include<queue>
#include<climits>

using namespace std;

struct a{
	int nd,l;
	bool operator<(const a&T)const{
		return l > T.l;
	}
}aa;

int c[60][10005]={},ln[60][10005]={},d[60]={},out[60]={},ans;
priority_queue<a> q;

int main()
{
	int n,i,tc,nd,l,m=INT_MAX;
	char ta,tb;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf(" %c %c %d",&ta,&tb,&tc);
		d[ta-65]=-1; d[tb-65]=-1; c[ta-65][0]++; c[tb-65][0]++;
		c[ta-65][c[ta-65][0]]=tb-65; c[tb-65][c[tb-65][0]]=ta-65;
		ln[ta-65][c[ta-65][0]]=tc; ln[tb-65][c[tb-65][0]]=tc;
	}
	aa.nd=25; aa.l=0; q.push(aa);
	while(!q.empty())
	{
		aa=q.top(); q.pop(); nd=aa.nd; l=aa.l; out[nd]=1;
		if(d[nd]==-1)
		{
			for(i=1;i<=c[nd][0];i++)
				{
					if(l+ln[nd][i]<d[c[nd][i]]||d[c[nd][i]]==-1) {aa.nd=c[nd][i]; aa.l=l+ln[nd][i]; q.push(aa);}
				}
			d[nd]=l;
		}
	}
	for(i=0;i<25;i++) if(d[i]<m&&d[i]>0) {m=d[i]; ans=i;}
	printf("%c %d",ans+65,m);
	return 0;
}