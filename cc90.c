#include<stdio.h>

char f[85][85]={};
int n,m;

void recur(int x, int y, int mode)
{
	int i;
	if(mode==1) 
		for(i=x;i>=0;i--) 
		{
			if(f[i][y]!='.'&&f[i][y]!='-') return;
			else {if(f[i][y]=='-') f[i][y]='+'; else f[i][y]='|';}
		}
	else if(mode==2)
		for(i=y;i>=0;i--)
		{
			if(f[x][i]!='.'&&f[x][i]!='|') return;
			else {if(f[x][i]=='|') f[x][i]='+'; else f[x][i]='-';}
		}
	else if(mode==3)
		for(i=y;i<m;i++)
		{
			if(f[x][i]!='.'&&f[x][i]!='|') return;
			else {if(f[x][i]=='|') f[x][i]='+'; else f[x][i]='-';}
		}
	else
		for(i=x;i<n;i++)
		{
			if(f[i][y]!='.'&&f[i][y]!='-') return;
			else {if(f[i][y]=='-') f[i][y]='+'; else f[i][y]='|';}
		}
}

int main()
{
	int i,j;
	scanf("%d %d",&m,&n);
	for(i=0;i<n;i++) scanf("%s",&f[i]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(f[i][j]=='^') recur(i-1,j,1);
			else if(f[i][j]=='<') recur(i,j-1,2);
			else if(f[i][j]=='>') recur(i,j+1,3);
			else if(f[i][j]=='V') recur(i+1,j,4);
			else if(f[i][j]=='B') f[i][j]='*';
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++) printf("%c",f[i][j]);
		printf("\n");
	}
	return 0;
}