#include<iostream>
#include<cstdio>
#include<stack>

using namespace std;

typedef struct a{
	int n,l;
	a(int nn,int ll) {n=nn; l=ll;}
}aa;

stack<a> q;
int conn[100005][4]={};

int main()
{
	int i,j,an,p=0,tn,tl,px[5]={};
	scanf("%d",&an);
	for(i=1;i<=an;i++)
	{
		scanf("%d %d",&conn[i][1],&conn[i][2]);
	}
	q.push(a(1,1));
	while(!q.empty())
	{
		tn=q.top().n; tl=q.top().l; q.pop(); conn[tn][0]=tl;
		if(conn[tn][1]==-1||conn[tn][2]==-1) {for(i=0;i<p;i++) if(px[i]==tl) break; else if(px[i]==0){px[i]=tl; p++;}}
		if(p>2) {printf("-1"); return 0;}
		if(conn[tn][1]!=-1) q.push(a(conn[tn][1],tl+1));
		if(conn[tn][2]!=-1) q.push(a(conn[tn][2],tl+1));
	}
	if(p==1) {printf("0"); return 0;}
	//for(i=1;i<=an;i++) printf("%d %d %d %d\n",i,conn[i][0],conn[i][1],conn[i][2]);
	return 0;
}