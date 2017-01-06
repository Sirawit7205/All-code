#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

struct m{
	int pos,col;
}mm;

queue<m> q;
int dat[105][105]={},sta[105]={};

int main()
{
	int c,i,tt,x,y;
	scanf("%d",&c);
	for(i=1;i<=c;i++)
	{
		while(1) {scanf("%d",&tt); if(tt!=0) {dat[i][dat[i][0]+1]=tt; dat[i][0]++;} else break;}
	}
	mm.pos=1; mm.col=1; q.push(mm); tt=0; sta[1]=1;
	while(!q.empty())
	{
		mm=q.front(); x=mm.pos; y=mm.col; q.pop();
		//printf("COMPARE %d to %d -> %d available\n",x,y,dat[x][0]);
		for(i=1;i<=dat[x][0];i++)
		{
			if(y==1&&sta[dat[x][i]]==0) {sta[dat[x][i]]=2; mm.pos=dat[x][i]; mm.col=2; q.push(mm);}
			else if(y==2&&sta[dat[x][i]]==0) {sta[dat[x][i]]=1; mm.pos=dat[x][i]; mm.col=1; q.push(mm);}
			else if(y==1&&sta[dat[x][i]]==1) {tt=1; break;}
			else if(y==2&&sta[dat[x][i]]==2) {tt=1; break;}
		}
		if(tt==1) break;
	}
	if(tt==0) printf("yes"); else printf("no");
	return 0;
}