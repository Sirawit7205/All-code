#include<stdio.h>

long long int str[300000]={},n;

void upd(int nd,int l,int r,int k,long long int v)
{
	int mid=(l+r)/2;
	if(l==r) {str[nd]=v; return;}
	else if(k<=mid) upd(nd*2,l,mid,k,v);
	else upd((nd*2)+1,mid+1,r,k,v);
	if(str[nd]<v) str[nd]=v;
}

long long int query(int nd,int l,int r,int tl,int tr)
{
	int mid=(l+r)/2,x;
	long long int ta,tb;
	if(l==tl&&r==tr) return str[nd];
	if(tr>mid) {if(tl>mid) x=tl; else x=mid+1; ta=query((nd*2)+1,mid+1,r,x,tr);} else ta=0;
	if(tl<=mid) {if(tr<=mid) x=tr; else x=mid; tb=query(nd*2,l,mid,tl,x);} else tb=0;
	if(ta>=tb) return ta; else return tb;
}

int main()
{
	int m,i,ta;
	long long int tb;
	char mode;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf(" %c",&mode);
		if(mode=='B')
		{
			scanf("%d %lld",&ta,&tb);
			upd(1,1,n,ta,tb);
		}
		else
		{
			scanf("%d",&ta);
			tb=query(1,1,n,1,ta);
			printf("%lld\n",tb);
		}
	}
	return 0;
}
