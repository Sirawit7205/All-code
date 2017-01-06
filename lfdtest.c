#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int cmp(const void *a, const void *b) {return (*(int*)a-*(int*)b);}

long long int p[100005]={},c,t,m,a,b,mid,cnt=0;

/*void find(long long int s,long long int tt)
{
	//printf("%d %d ",s,tt);
	int mid=(s+tt)/2,x=0,i;
	long long int cnt=0;
	if(s>tt) return;
	for(i=0;i<c;i++) {cnt+=mid/p[i]; if(cnt>m) {x=1; break;}}
	if(cnt>=t||x==1) {if(mid<m) m=mid; find(s,mid-1);}
	else if(cnt<t) find(mid+1,tt);
}*/

int main()
{
	int i,j;
	scanf("%lld %lld",&c,&t);
	for(i=0;i<c;i++) scanf("%lld",&p[i]);
	qsort(p,c,sizeof(long long int),cmp);
	a=0; b=p[c-1]*t; m=LLONG_MAX;
	mid=(a+b)/2; cnt=0;
	while(a!=mid)
	{
	    for(i=0;i<c;i++) cnt+=mid/p[i];
	    if(cnt>=t) {if(mid<m) m=mid; b=mid;}
	    else a=mid;
	    mid=(a+b)/2; cnt=0;
	}
	printf("%lld",m);
	return 0;
}
