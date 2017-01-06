#include<iostream>
#include<cstdio>
#include<stack>

using namespace std;

struct m{
	int x,y,c;
}mm;

stack<m> q;
int m=0,f[255][255]={},v[255][255]={};

int main()
{
	int sa,sb,i,j,tx,ty,tc;
	scanf("%d %d",&sa,&sb);
	for(i=1;i<=sa;i++)
	{
		for(j=1;j<=sb;j++) scanf("%d",&f[i][j]);
	}
	mm.x=1; mm.y=1; mm.c=0; q.push(mm);
	while(!q.empty())
	{
		mm=q.top(); q.pop(); tx=mm.x; ty=mm.y; tc=mm.c+f[tx][ty];
		if(v[tx][ty]<tc) v[tx][ty]=tc;
		if(ty!=sb&&v[tx][ty+1]<tc+f[tx][ty+1]) {mm.x=tx; mm.y=ty+1; mm.c=tc; q.push(mm);}
		if(tx!=sa&&v[tx+1][ty]<tc+f[tx+1][ty]) {mm.x=tx+1; mm.y=ty; mm.c=tc; q.push(mm);}
		if(tx==sa&&ty==sb) {if(m<tc) m=tc;}
	}
	printf("%d",m);
	return 0;
}
