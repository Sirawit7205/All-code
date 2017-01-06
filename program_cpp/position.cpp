#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

struct a
{
	int x,y,fr,cnt;
}b;

queue<a> q;
char ma[305][305][10]={};

int main()
{
	int m,n,c,i,j,spx,spy,t[5]={},init=0,ta,tb,mi,az=0;
	scanf("%d %d %d",&m,&n,&c);
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf(" %c",&ma[i][j][0]);
			if(ma[i][j][0]=='J') {spx=i; spy=j;}
		}
	}
	b.x=spx; b.y=spy; b.fr=0; b.cnt=1; q.push(b);
	//printf("%d %d %d %d\n",b.x,b.y,b.fr,b.cnt);
	for(i=1;i<=8;i++) ma[spx][spy][i]=-1;
	while(not q.empty())
	{
		b=q.front(); q.pop();
		t[0]=b.x; t[1]=b.y; t[2]=b.fr; t[3]=b.cnt;
		//printf("%d %d %d %d\n",t[0],t[1],t[2],t[3]);
		if(b.fr==0&&init==0)
		{
			//printf("INIT\n");
			init=1;
			if(t[0]-1>0&&t[1]-1>0&&ma[t[0]-1][t[1]-1][0]!='#') {b.x=t[0]-1; b.y=t[1]-1; b.fr=1; b.cnt=1; q.push(b);}
			if(t[0]-1>0&&ma[t[0]-1][t[1]][0]!='#') {b.x=t[0]-1; b.y=t[1]; b.fr=2; b.cnt=1; q.push(b);}
			if(t[0]-1>0&&t[1]+1<=n&&ma[t[0]-1][t[1]+1][0]!='#') {b.x=t[0]-1; b.y=t[1]+1; b.fr=3; b.cnt=1; q.push(b);}
			if(t[1]-1>0&&ma[t[0]][t[1]-1][0]!='#') {b.x=t[0]; b.y=t[1]-1; b.fr=4; b.cnt=1; q.push(b);}
			if(t[1]+1<=n&&ma[t[0]][t[1]+1][0]!='#') {b.x=t[0]; b.y=t[1]+1; b.fr=5; b.cnt=1; q.push(b);}
			if(t[0]+1<=m&&t[1]-1>0&&ma[t[0]+1][t[1]-1][0]!='#') {b.x=t[0]+1; b.y=t[1]-1; b.fr=6; b.cnt=1; q.push(b);}
			if(t[0]+1<=m&&ma[t[0]+1][t[1]][0]!='#') {b.x=t[0]+1; b.y=t[1]; b.fr=7; b.cnt=1; q.push(b);}
			if(t[0]+1<=m&&t[1]+1<=n&&ma[t[0]+1][t[1]+1][0]!='#') {b.x=t[0]+1; b.y=t[1]+1; b.fr=8; b.cnt=1; q.push(b);}
		}
		else if(b.fr==1)
		{
			//printf("1: %d %d\n",t[0],t[1]);
			ma[t[0]][t[1]][1]=t[3];
			if(t[0]-1>0&&t[1]-1>0&&(ma[t[0]-1][t[1]-1][1]==0||ma[t[0]-1][t[1]-1][1]>=t[3])&&ma[t[0]-1][t[1]-1][0]!='#') {b.x=t[0]-1; b.y=t[1]-1; b.fr=1; b.cnt=t[3]; q.push(b);}
			if(t[0]+1<=m&&t[1]-1>0&&(ma[t[0]+1][t[1]-1][6]==0||ma[t[0]+1][t[1]-1][6]>=t[3]+1)&&ma[t[0]+1][t[1]-1][0]!='#') {b.x=t[0]+1; b.y=t[1]-1; b.fr=6; b.cnt=t[3]+1; q.push(b);}
		}
		else if(b.fr==2)
		{
			//printf("2: %d %d\n",t[0],t[1]);
			ma[t[0]][t[1]][2]=t[3];
			if(t[0]-1>0&&(ma[t[0]-1][t[1]][2]==0||ma[t[0]-1][t[1]][2]>=t[3])&&ma[t[0]-1][t[1]][0]!='#') {b.x=t[0]-1; b.y=t[1]; b.fr=2; b.cnt=t[3]; q.push(b);}
			if(t[1]-1>0&&(ma[t[0]][t[1]-1][4]==0||ma[t[0]][t[1]-1][4]>=t[3]+1)&&ma[t[0]][t[1]-1][0]!='#') {b.x=t[0]; b.y=t[1]-1; b.fr=4; b.cnt=t[3]+1; q.push(b);}
			if(t[1]+1<=n&&(ma[t[0]][t[1]+1][5]==0||ma[t[0]][t[1]+1][5]>=t[3]+1)&&ma[t[0]][t[1]+1][0]!='#') {b.x=t[0]; b.y=t[1]+1; b.fr=5; b.cnt=t[3]+1; q.push(b);}
		}
		else if(b.fr==3)
		{
			//printf("3: %d %d\n",t[0],t[1]);
			ma[t[0]][t[1]][3]=t[3];
			if(t[0]-1>0&&t[1]+1<=n&&(ma[t[0]-1][t[1]+1][3]==0||ma[t[0]-1][t[1]+1][3]>=t[3])&&ma[t[0]-1][t[1]+1][0]!='#') {b.x=t[0]-1; b.y=t[1]+1; b.fr=3; b.cnt=t[3]; q.push(b);}
			if(t[0]+1<=m&&t[1]+1<=n&&(ma[t[0]+1][t[1]+1][8]==0||ma[t[0]+1][t[1]+1][8]>=t[3]+1)&&ma[t[0]+1][t[1]+1][0]!='#') {b.x=t[0]+1; b.y=t[1]+1; b.fr=8; b.cnt=t[3]+1; q.push(b);}
		}
		else if(b.fr==4)
		{
			//printf("4: %d %d\n",t[0],t[1]);
			ma[t[0]][t[1]][4]=t[3];
			if(t[1]-1>0&&(ma[t[0]][t[1]-1][4]==0||ma[t[0]][t[1]-1][4]>=t[3])&&ma[t[0]][t[1]-1][0]!='#') {b.x=t[0]; b.y=t[1]-1; b.fr=4; b.cnt=t[3]; q.push(b);}
			if(t[0]-1>0&&(ma[t[0]-1][t[1]][2]==0||ma[t[0]-1][t[1]][2]>=t[3]+1)&&ma[t[0]-1][t[1]][0]!='#') {b.x=t[0]-1; b.y=t[1]; b.fr=2; b.cnt=t[3]+1; q.push(b);}
			if(t[0]+1<=m&&(ma[t[0]+1][t[1]][7]==0||ma[t[0]+1][t[1]][7]>=t[3]+1)&&ma[t[0]+1][t[1]][0]!='#') {b.x=t[0]+1; b.y=t[1]; b.fr=7; b.cnt=t[3]+1; q.push(b);}
		}
		else if(b.fr==5)
		{
			//printf("5: %d %d\n",t[0],t[1]);
			ma[t[0]][t[1]][5]=t[3];
			if(t[1]+1<=n&&(ma[t[0]][t[1]+1][5]==0||ma[t[0]][t[1]+1][5]>=t[3])&&ma[t[0]][t[1]+1][0]!='#') {b.x=t[0]; b.y=t[1]+1; b.fr=5; b.cnt=t[3]; q.push(b);}
			if(t[0]-1>0&&(ma[t[0]-1][t[1]][2]==0||ma[t[0]-1][t[1]][2]>=t[3]+1)&&ma[t[0]-1][t[1]][0]!='#') {b.x=t[0]-1; b.y=t[1]; b.fr=2; b.cnt=t[3]+1; q.push(b);}
			if(t[0]+1<=m&&(ma[t[0]+1][t[1]][7]==0||ma[t[0]+1][t[1]][7]>=t[3]+1)&&ma[t[0]+1][t[1]][0]!='#') {b.x=t[0]+1; b.y=t[1]; b.fr=7; b.cnt=t[3]+1; q.push(b);}
		}
		else if(b.fr==6)
		{
			//printf("6: %d %d\n",t[0],t[1]);
			ma[t[0]][t[1]][6]=t[3];
			if(t[0]+1<=m&&t[1]-1>0&&(ma[t[0]+1][t[1]-1][6]==0||ma[t[0]+1][t[1]-1][6]>=t[3])&&ma[t[0]+1][t[1]-1][0]!='#') {b.x=t[0]+1; b.y=t[1]-1; b.fr=6; b.cnt=t[3]; q.push(b);}
			if(t[0]-1>0&&t[1]-1>0&&(ma[t[0]-1][t[1]-1][1]==0||ma[t[0]-1][t[1]-1][1]>=t[3]+1)&&ma[t[0]-1][t[1]-1][0]!='#') {b.x=t[0]-1; b.y=t[1]-1; b.fr=1; b.cnt=t[3]+1; q.push(b);}
		}
		else if(b.fr==7)
		{
			//printf("7: %d %d\n",t[0],t[1]);
			ma[t[0]][t[1]][7]=t[3];
			if(t[0]+1<=m&&(ma[t[0]+1][t[1]][7]==0||ma[t[0]+1][t[1]][7]>=t[3])&&ma[t[0]+1][t[1]][0]!='#') {b.x=t[0]+1; b.y=t[1]; b.fr=7; b.cnt=t[3]; q.push(b);}
			if(t[1]-1>0&&(ma[t[0]][t[1]-1][4]==0||ma[t[0]][t[1]-1][4]>=t[3]+1)&&ma[t[0]][t[1]-1][0]!='#') {b.x=t[0]; b.y=t[1]-1; b.fr=4; b.cnt=t[3]+1; q.push(b);}
			if(t[1]+1<=n&&(ma[t[0]][t[1]+1][5]==0||ma[t[0]][t[1]+1][5]>=t[3]+1)&&ma[t[0]][t[1]+1][0]!='#') {b.x=t[0]; b.y=t[1]+1; b.fr=5; b.cnt=t[3]+1; q.push(b);}
		}
		else if(b.fr==8)
		{
			//printf("8: %d %d\n",t[0],t[1]);
			ma[t[0]][t[1]][8]=t[3];
			if(t[0]+1<=m&&t[1]+1<=n&&(ma[t[0]+1][t[1]+1][8]==0||ma[t[0]+1][t[1]+1][8]>=t[3])&&ma[t[0]+1][t[1]+1][0]!='#') {b.x=t[0]+1; b.y=t[1]+1; b.fr=8; b.cnt=t[3]; q.push(b);}
			if(t[0]-1>0&&t[1]+1<=n&&(ma[t[0]-1][t[1]+1][3]==0||ma[t[0]-1][t[1]+1][3]>=t[3]+1)&&ma[t[0]-1][t[1]+1][0]!='#') {b.x=t[0]-1; b.y=t[1]+1; b.fr=3; b.cnt=t[3]+1; q.push(b);}
		}
		//getch();
	}
	for(i=0;i<c;i++)
	{
		mi=1000000;
		scanf("%d %d",&ta,&tb);
		for(j=1;j<=8;j++) {/* printf("%d ",ma[ta][tb][j]); */ if(ma[ta][tb][j]<mi&&ma[ta][tb][j]!=0) {mi=ma[ta][tb][j]; az=1;}}
		if(az==1) {printf("%d\n",mi-1); az=0;} else printf("-1\n");
	}
	return 0;
}