#include<cstdio>
#include<queue>
#include<cstdlib>

using namespace std;

struct inst{
	int nd,len;
	bool operator<(const inst&A) const{
		return len > A.len;
	}
}instt;

int n,m,k,ln[2005][2010]={},cnt=3,dist[2005]={},o[2005]={},ans=0;
char tmp[10005]={};
priority_queue<inst> q;

int main()
{
	int i,j,ta,tb,cur;
	scanf("%d %d %d",&n,&m,&k);
	dist[2]=-1;
	for(i=0;i<n;i++)
	{
		scanf("%s",tmp);
		for(j=0;j<m;j++) if(tmp[j]!='.')
		{
			if(tmp[j]=='A') {ln[1][0]=i; ln[1][1]=j;}
			else if(tmp[j]=='B') {ln[2][0]=i; ln[2][1]=j;}
			else {ln[cnt][0]=i; ln[cnt][1]=j; dist[cnt]=-1; cnt++;}
		}
	}
	for(i=1;i<cnt;i++)
	{
		for(j=1;j<cnt;j++)
		{
			if(i==j) continue;
			else if(abs(ln[i][0]-ln[j][0])+abs(ln[i][1]-ln[j][1])<=k) {ln[i][2]++; ln[i][ln[i][2]+2]=j;}
		}
	}
	instt.nd=1; instt.len=0; q.push(instt);
	while(!q.empty())
	{
		instt=q.top(); q.pop(); ta=instt.nd; tb=instt.len; o[ta]=1;
		if(ta==2) {ans=tb; break;}
		for(i=3;i<=ln[ta][2]+2;i++)
		{
			cur=abs(ln[ta][0]-ln[ln[ta][i]][0])+abs(ln[ta][1]-ln[ln[ta][i]][1])+tb;
			if((dist[ln[ta][i]]==-1||dist[ln[ta][i]]>cur)&&o[ln[ta][i]]==0)
			{
				dist[ln[ta][i]]=cur;
				instt.nd=ln[ta][i]; instt.len=dist[ln[ta][i]]; q.push(instt);
			}
		}
	}
	if(ans==0) printf("-1"); else printf("%d",ans);
	return 0;
}
