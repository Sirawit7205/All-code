#include<iostream>
#include<cstdio>

using namespace std;

int sta[1005]={},cnt[1005]={},str[1005]={},n;

int chk(int n,long long int ct)
{
	if(sta[n]==1)
	{
		sta[n]=0;
		if(str[n]!=0) return ct+=str[n]/1000000007;
		else return str[n]=chk(cnt[n],ct);
	}		
}

int main()
{
    int i;
	long long int c=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&cnt[i]);
	for(i=1;i<=n;i++)
	{
		if(i==1) {cnt[1]=1; c+=2;}
		else
		{
			if(str[cnt[i]]!=0) c+=str[cnt[i]]/1000000007; 
			else c+=chk(cnt[i],0)/1000000007;
		}
	}
	return 0;
}
