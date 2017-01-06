#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b) {return (*(int*)a-*(int*)b);}

int p[100005]={},n,a,b;

int src(int l,int r,int k,int m)
{
	int mid=(l+r)/2,i;
	if(l>=r)
	{
	    if(a==b) return -1;
	    /*if(mid<0) mid=0;
        if(p[mid]<k&&m==1) {for(i=mid;i<n-1;i++) if(p[i+1]<k) mid++; else break;}
        else if(p[mid]>k&&m==1) {for(i=mid;i>0;i--) if(p[i-1]>k) mid--; else break;}
        else if(p[mid]<k&&m==2) {for(i=mid;i>0;i--) if(p[i-1]>k) mid--; else break;}
        else if(p[mid]>k&&m==2) {for(i=mid;i<n-1;i++) if(p[i+1]==k) mid++; else break;}
        if(mid>n-1) mid=n-1;
        if(p[mid]<k&&p[mid+1]>k&&a!=b) mid++;*/
        return mid;
	}
	if(k==p[mid]&&m==1) {for(i=mid;i>0;i--) if(p[i-1]==k) mid--; else break; return mid;}
	else if(k==p[mid]&&m==2) {for(i=mid;i<n-1;i++) if(p[i+1]==k) mid++; else break; return mid;}
	else if(k>p[mid]) src(mid+1,r,k,m);
	else if(k<p[mid]) src(l,mid-1,k,m);
}

int main()
{
	int m,i,j,x,y;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++) scanf("%d",&p[i]);
	qsort(p,n,sizeof(int),cmp);
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&a,&b);
		if(a<p[0]&&b<p[0]||a>p[n-1]&&b>p[n-1]) {x=-1; y=-1;} else {
		if(a<p[0]) x=0; else x=src(0,n,a,1);


		if(b>p[n-1]) y=n-1; else y=src(0,n,b,2);}
		//printf("%d %d\n",x,y);
		//if(p[x]<a) x++; if(y>n-1) y=n-1;
		//for(j=x;j>=0;j--) if(p[j-1]==p[j]&&j-1>=0) x--; else break;
		//for(j=y;j<n;j++) if(p[j+1]==p[j]&&j+1<n) y++; else break;
		if(x==-1&&y==-1||(p[x]<a&&p[x+1]>a&&p[y]<b&&p[y+1]>b)||(p[x-1]<a&&p[x]>a&&p[y-1]<b&&p[y]>b&&x-1>=0)) printf("0\n");
		else {if(p[x]<a) x++; if(p[y]>b) y--; printf("%d\n",y-x+1);}
	}
	return 0;
}
