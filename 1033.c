#include<stdio.h>

char cmd[6][1005]={}, brd[105][105]={};

int wsp,cpos[6][3]={},scr[6]={0,1,1,1,1},s;

void mov(int id,int rnd)
{
	char com=cmd[id][rnd];
	int x=cpos[id][0],y=cpos[id][1];
	if(com=='N') {if(brd[x-1][y]<=52&&x!=1) {scr[id]++; if(brd[x-1][y]==NULL) wsp--; else scr[brd[x-1][y]-48]--; brd[x][y]=id+48; brd[x-1][y]=id+52; cpos[id][0]--;}}
	else if(com=='W') {if(brd[x][y-1]<=52&&y!=1) {scr[id]++; if(brd[x][y-1]==NULL) wsp--; else scr[brd[x][y-1]-48]--; brd[x][y]=id+48; brd[x][y-1]=id+52; cpos[id][1]--;}}
	else if(com=='E') {if(brd[x][y+1]<=52&&y!=s) {scr[id]++; if(brd[x][y+1]==NULL) wsp--; else scr[brd[x][y+1]-48]--; brd[x][y]=id+48; brd[x][y+1]=id+52; cpos[id][1]++;}}
	else {if(brd[x+1][y]<=52&&x!=s) {scr[id]++; if(brd[x+1][y]==NULL) wsp--; else scr[brd[x+1][y]-48]--; brd[x][y]=id+48; brd[x+1][y]=id+52; cpos[id][0]++;}}
}

int main()
{
	int a,i,j,m=0,mc=0;
	scanf("%d %d",&s,&a);
	wsp=(s*s)-4;
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=a;j++) scanf(" %c",&cmd[i][j]);
	}
	brd[1][1]='8'; brd[1][s]='5'; brd[s][1]='7'; brd[s][s]='6';
	cpos[1][0]=1; cpos[1][1]=s; cpos[2][0]=s; cpos[2][1]=s;
	cpos[3][0]=s; cpos[3][1]=1; cpos[4][0]=1; cpos[4][1]=1;
	for(i=1;i<=a;i++)
	{
		mov(1,i); mov(2,i); mov(3,i); mov(4,i);
	}
	if(wsp!=0) printf("No");
	else
	{
		for(i=1;i<=4;i++) if(scr[i]>m) {m=scr[i]; mc=1;} else if(scr[i]==m) mc++;
		printf("%d %d\n",mc,m);
		for(i=1;i<=4;i++) if(scr[i]==m) printf("%d\n",i);
	}
	return 0;
}
