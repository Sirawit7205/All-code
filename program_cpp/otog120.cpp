#include<cstdio>
#include<algorithm>

using namespace std;

int d[60]={},n,str[100][100]={};

int chk(int l,int r)
{
	int ta,tb,tc,td;
	if(l==r-1) return max(d[l],d[r]);
	else
	{
		if(str[l+1][r-1]!=0) ta=str[l+1][r-1]; else ta=chk(l+1,r-1);
		if(str[l+2][r]!=0) tb=str[l+2][r]; else tb=chk(l+2,r);
		if(str[l][r-2]!=0) tc=str[l][r-2]; else tc=chk(l,r-2);
		str[l][r]=max(d[l]+max(ta,tb),d[r]+max(ta,tc));
		return str[l][r];
	}
	//else return max(d[l]+max(chk(l+1,r-1),chk(l+2,r)),d[r]+max(chk(l,r-2),chk(l+1,r-1)));
}

int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n*2;i++) scanf("%d",&d[i]);
	printf("%d",chk(1,n*2));
	return 0;
}