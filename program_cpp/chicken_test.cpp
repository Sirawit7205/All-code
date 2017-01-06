#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

struct m{
	int x,y,c;
}mm;

queue<m> q;
int f[1005][1005]={};
char ff[1005][1005]={};

int main()
{
	int sa,sb,pa,pb,da,db,i,j,tx,ty,tc,n=0;
	scanf("%d %d",&sa,&sb);
	for(i=1;i<=sa;i++) scanf("%s",ff[i]);
	scanf("%d %d %d %d",&pa,&pb,&da,&db);
	mm.x=pa; mm.y=pb; mm.c=1; q.push(mm);
	f[tx][ty]=1;
	while(!q.empty())
	{
		mm=q.front(); q.pop(); tx=mm.x; ty=mm.y; tc=mm.c;
		if(tx==da&&ty==db) {n=1; break;}
		if(tx-2>0&&ty-1>0&&(f[tx-2][ty-1]==0||f[tx-2][ty-1]>tc+1)&&ff[tx-2][ty-2]!='X') {f[tx-2][ty-1]=tc+1; mm.x=tx-2; mm.y=ty-1; mm.c=tc+1; q.push(mm);}
		if(tx-1>0&&ty-2>0&&(f[tx-1][ty-2]==0||f[tx-1][ty-2]>tc+1)&&ff[tx-1][ty-3]!='X') {f[tx-1][ty-2]=tc+1; mm.x=tx-1; mm.y=ty-2; mm.c=tc+1; q.push(mm);}
		if(tx-2>0&&ty+1<=sb&&(f[tx-2][ty+1]==0||f[tx-2][ty+1]>tc+1)&&ff[tx-2][ty]!='X') {f[tx-2][ty+1]=tc+1; mm.x=tx-2; mm.y=ty+1; mm.c=tc+1; q.push(mm);}
		if(tx-1>0&&ty+2<=sb&&(f[tx-1][ty+2]==0||f[tx-1][ty+2]>tc+1)&&ff[tx-1][ty+1]!='X') {f[tx-1][ty+2]=tc+1; mm.x=tx-1; mm.y=ty+2; mm.c=tc+1; q.push(mm);}
		if(tx+2<=sa&&ty-1>0&&(f[tx+2][ty-1]==0||f[tx+2][ty-1]>tc+1)&&ff[tx+2][ty-2]!='X') {f[tx+2][ty-1]=tc+1; mm.x=tx+2; mm.y=ty-1; mm.c=tc+1; q.push(mm);}
		if(tx+1<=sa&&ty-2>0&&(f[tx+1][ty-2]==0||f[tx+1][ty-2]>tc+1)&&ff[tx+1][ty-3]!='X') {f[tx+1][ty-2]=tc+1; mm.x=tx+1; mm.y=ty-2; mm.c=tc+1; q.push(mm);}
		if(tx+2<=sa&&ty+1<=sb&&(f[tx+2][ty+1]==0||f[tx+2][ty+1]>tc+1)&&ff[tx+2][ty]!='X') {f[tx+2][ty+1]=tc+1; mm.x=tx+2; mm.y=ty+1; mm.c=tc+1; q.push(mm);}
		if(tx+1<=sa&&ty+2<=sb&&(f[tx+1][ty+2]==0||f[tx+1][ty+2]>tc+1)&&ff[tx+1][ty+1]!='X') {f[tx+1][ty+2]=tc+1; mm.x=tx+1; mm.y=ty+2; mm.c=tc+1; q.push(mm);}
	}
	if(n==0) printf("-1"); else printf("%d",tc-1);
	return 0;
}