#include<stdio.h>

int f[10][10]={},c=0;

void play(int x,int y,int p,int s)
{
	if(f[x][y]==p) {c=1; return;}
	if((s==1||s==0)&&f[x-1][y-1]!=0) {c=0; play(x-1,y-1,p,1); if(c==1) f[x-1][y-1]=p;}
	if((s==2||s==0)&&f[x-1][y]!=0) {c=0; play(x-1,y,p,2); if(c==1) f[x-1][y]=p;}
	if((s==3||s==0)&&f[x-1][y+1]!=0) {c=0; play(x-1,y+1,p,3); if(c==1) f[x-1][y+1]=p;}
	if((s==4||s==0)&&f[x][y+1]!=0) {c=0; play(x,y+1,p,4); if(c==1) f[x][y+1]=p;}
	if((s==5||s==0)&&f[x+1][y+1]!=0) {c=0; play(x+1,y+1,p,5); if(c==1) f[x+1][y+1]=p;}
	if((s==6||s==0)&&f[x+1][y]!=0) {c=0; play(x+1,y,p,6); if(c==1) f[x+1][y]=p;}
	if((s==7||s==0)&&f[x+1][y-1]!=0) {c=0; play(x+1,y-1,p,7); if(c==1) f[x+1][y-1]=p;}
	if((s==8||s==0)&&f[x][y-1]!=0) {c=0; play(x,y-1,p,8); if(c==1) f[x][y-1]=p;}
}

int main()
{
	int i,j,amt,x,y,t=1;
	char temp;
	f[4][4]=2; f[5][5]=2; f[4][5]=1; f[5][4]=1;
	scanf("%d",&amt);
	for(i=1;i<=amt;i++)
	{
		scanf(" %c %d",&temp,&x);
		y=temp-96;
		play(x,y,t,0);
		f[x][y]=t;
		if(t==1) t=2; else t=1;
	}
	for(i=1;i<=8;i++)
	{
		for(j=1;j<=8;j++)
		{
			if(f[i][j]==0) printf("%c",'.');
			else if(f[i][j]==1) printf("%c",'X');
			else printf("%c",'O');
		}
		printf("\n");
	}
	return 0;
}