#include<iostream>
#include<cstdio>

using namespace std;

char sta[30005][35]={};
int r,c;

void upd(int t, int u)
{
	if(t==r-1) {sta[t][u]='O'; return;}
	else if(sta[t+1][u]=='.') upd(t+1,u);
	else if(sta[t+1][u]=='X') {sta[t][u]='O'; return;}
	else if(sta[t+1][u]=='O')
	{
		if(sta[t][u-1]=='.'&&sta[t+1][u-1]=='.'&&u-1>=0&&t+1<r) upd(t,u-1);
		else if(sta[t][u+1]=='.'&&sta[t+1][u+1]=='.'&&u+1<c&&t+1<r) upd(t,u+1);
		else {sta[t][u]='O'; return;}
	}
}

int main()
{
	int n,t,i;
	scanf("%d %d",&r,&c);
	for(i=0;i<r;i++) scanf("%s",sta[i]);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		upd(0,t-1);
	}
	for(i=0l;i<r;i++) printf("%s\n",sta[i]);
	return 0;
}