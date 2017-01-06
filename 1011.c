#include<stdio.h>

int n,m,scr=0;
char mp[6][6]={};

void  upd()
{
	int i,j,b=9999;
	for(i=1;i<=m;i++)
	{
		for(j=n;j>0;j--)
        {
            if(mp[j][i]=='-'&&b==9999) b=j;
            else if(mp[j][i]=='#') b=9999;
            else if(mp[j][i]>=65&&mp[j][i]<=90&&b!=9999) {mp[b][i]=mp[j][i]; mp[j][i]='-'; b--;}
        }
	}
}

void calc()
{
	int i,j,a;
	upd();
	for(i=1;i<n;i++)
	{
		for(j=1;j<=m;j++)
		{
		    a=0;
			if(mp[i][j]==mp[i-1][j]&&mp[i][j]>=65&&mp[i][j]<=90) {scr+=5; mp[i-1][j]='-'; a=1;}
			if(mp[i][j]==mp[i+1][j]&&mp[i][j]>=65&&mp[i][j]<=90) {scr+=5; mp[i+1][j]='-'; a=1;}
			if(mp[i][j]==mp[i][j-1]&&mp[i][j]>=65&&mp[i][j]<=90) {scr+=5; mp[i][j-1]='-'; a=1;}
			if(mp[i][j]==mp[i][j+1]&&mp[i][j]>=65&&mp[i][j]<=90) {scr+=5; mp[i][j+1]='-'; a=1;}
			if(a==1) {scr+=5; mp[i][j]='-'; break;}
		}
	}
	upd();
	if(a==0) return;
	else calc();
}

int main()
{
	int i,j,c,ta,tb,tc;
	char x,tcc;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++) {scanf("%c",&x); if((x>=65&&x<=90)||x=='#'||x=='-') mp[i][j]=x; else j--;}
	}
	scanf("%d",&c);
	for(i=0;i<c;i++)
	{
		scanf("%d %d %c",&ta,&tb,&tcc); ta++; tb++; if(tcc=='L') tc=1; else tc=2;
		if(mp[ta][tb]=='-'||mp[ta][tb]=='#'||(tc==1&&mp[ta][tb-1]!='-')||(tc==2&&mp[ta][tb+1]!='-')) {scr-=5; continue;}
		else {if(tc==1) mp[ta][tb-1]=mp[ta][tb]; else mp[ta][tb+1]=mp[ta][tb]; mp[ta][tb]='-'; calc();}
	}
	printf("%d\n",scr);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++) printf("%c ",mp[i][j]);
		printf("\n");
	}
	return 0;
}
