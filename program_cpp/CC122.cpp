#include<cstdio>
#include<queue>

using namespace std;

struct a{
	int x,y,n,cn;
}aa;

queue<a> q;
char f[505][505]={};
int b[505][505]={};

int main()
{
	int n,m,i,j,c[5]={},d[5]={},ta,tb,tc,td;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++) scanf("%s",f[i]);
	for(i=0;i<n;i++) for(j=0;j<m;j++) if(f[i][j]=='S') {aa.x=i; aa.y=j; break;}
	aa.n=0; aa.cn=1; q.push(aa); c[1]=1000000; c[2]=1000000; c[3]=1000000; b[aa.x][aa.y]=1;
	while(!q.empty())
	{
		aa=q.front(); q.pop(); b[aa.x][aa.y]=1; ta=aa.x; tb=aa.y; tc=aa.n; td=aa.cn;
		if((f[ta][tb]=='J'&&c[1]==1000000&&tc==1)||(f[ta][tb]=='S'&&c[2]==1000000&&tc==1)||(f[ta][tb]=='B'&&c[3]==1000000&&tc==1)) continue;
		if(f[ta][tb]=='j') c[1]=td; else if(f[ta][tb]=='s') c[2]=td; else if(f[ta][tb]=='b') c[3]=td;
		if(ta>0&&f[ta-1][tb]!='#') {aa.x=ta-1; aa.y=tb; aa.n=0; aa.cn=td+1; q.push(aa);}
		if(ta<n&&f[ta+1][tb]!='#') {aa.x=ta+1; aa.y=tb; aa.n=0; aa.cn=td+1; q.push(aa);}
		if(tb>0&&f[ta][tb]!='#') {aa.x=ta; aa.y=tb-1; aa.n=0; aa.cn=td+1; q.push(aa);}
		if(tb<m&&f[ta][tb]!='#') {aa.x=ta; aa.y=tb+1; aa.n=0; aa.cn=td+1; q.push(aa);}		
	}
	return 0;
}