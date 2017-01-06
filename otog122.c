#include<stdio.h>

int t[400005]={}, pnd[400005]={};

int build(int n,int nl,int nr,int l, int r, int v)
{
	int mid=(nl+nr)/2,lft=0,rgh=0,tx;
	if(nl==nr) {t[n]+=v; return v;}
	if(nl==l&&nr==r) {t[n]+=(nr-nl+1)*v; pnd[n]+=v; return (nr-nl+1)*v;}
	if(l<=mid) {if(r<=mid) tx=r; else tx=mid; lft=build(n*2,nl,mid,l,tx,v);}
	if(r>mid) {if(l>mid) tx=l; else tx=mid+1; rgh=build((n*2)+1,mid+1,nr,tx,r,v);}
	t[n]+=lft+rgh;
	return lft+rgh;
}

int query(int n,int nl,int nr,int v)
{
	int mid=(nl+nr)/2;
	if(nl==nr) {if(pnd[n]!=0) {t[n]+=pnd[n]; pnd[n]=0;} return t[n];}
	if(pnd[n]!=0) {pnd[n*2]+=pnd[n]; pnd[(n*2)+1]+=pnd[n]; pnd[n]=0;}
	if(v<=mid) return query(n*2,nl,mid,v);
	else return query((n*2)+1,mid+1,nr,v);
}

int main()
{
	int n,m,i,mode,ta,tb,tc;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&mode);
		if(mode==1)
		{
			scanf("%d %d %d",&ta,&tb,&tc); if(tb>n) tb=n;
			ta=build(1,1,n,ta,tb,tc);
		}
		else
		{
			scanf("%d",&ta);
			ta=query(1,1,n,ta);
			printf("%d\n",ta);
		}
	}
	return 0;
}
