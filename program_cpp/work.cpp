#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

vector<int> v[51]={};
int chk[55][55]={},stk[2510][3]={},nrc[55]={},b=1;

void recur(int a,int d)
{
	//printf("%d\n",d);
	if (chk[a][d]!=0) return;
	//printf("%d %d\n",a,d);
	chk[a][d]=b;
	chk[d][a]=b;
	b++;
	if(nrc[d]==1) return; else nrc[d]=1;
	while(not v[d].empty())
	{
		//printf("c");
		recur(d,v[d].front());
		v[d].erase(v[d].begin());
	}
	//printf("d%d\n",d);
	return;
}

int main()
{
	int i,j,n,m,ta,tb;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&ta,&tb);
		v[ta].push_back(tb); v[tb].push_back(ta);
		stk[i][0]=ta; stk[i][1]=tb;
	}
	recur(1,v[1].front());
	/*for(i=0;i<m;i++)
	{
		for(j=0;j<=m;j++) printf("%d ",chk[i][j]);
		printf("\n");
	} */
	printf("YES\n");
	for(i=0;i<m;i++) printf("%d ",chk[stk[i][0]][stk[i][1]]);
	return 0;
}