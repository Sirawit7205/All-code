#include<cstdio>
#include<queue>
#include<climits>

struct a{
	int nd,l;
	bool operator<(const a&T)const{
		return l > T.l;
	}
}aa;

std::priority_queue<a> q;
int c[60][60]={},d[60]={};

int main()
{
	int i,n,tc,td,ans,min=INT_MAX;
	char ta,tb;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf(" %c %c %d",&ta,&tb,&tc);
		if(ta>=65&&ta<=91) ta-=65; else ta-=71;
		if(tb>=65&&tb<=91) tb-=65; else tb-=71;
		d[ta]=-1; d[tb]=-1;
		if(c[ta][tb]==0||(c[ta][tb]!=0&&c[ta][tb]>tc)) {c[ta][tb]=tc; c[tb][ta]=tc;}
	}
	aa.nd=25; aa.l=0; q.push(aa);
	while(!q.empty())
	{
		aa=q.top(); q.pop(); tc=aa.nd; td=aa.l;
		if(d[tc]==-1)
		{
			for(i=0;i<52;i++)
			{
				if(c[tc][i]!=0) {aa.nd=i; aa.l=td+c[tc][i]; q.push(aa);}
			}
			d[tc]=td;
		}
	}
	for(i=0;i<25;i++) if(d[i]<min&&d[i]>0) {min=d[i]; ans=i;}
	printf("%c %d",ans+65,min);
	return 0;
}
