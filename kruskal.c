#include<stdio.h>
#include<stdlib.h>

struct an{
	int x,y,w;
};

struct an dat[1000];
int chk[1000]={};

int cmp(const void *a,const void *b)
{
	an *aa =(an*)a;
	an *bb =(an*)b;
	return (aa->w - bb->w);
}

void join(int x, int y,int n)
{
	int i;
	for(i=1;i<=n;i++) if(chk[i]==y) chk[i]=x;
}

int main()
{
	int n,m,i,j,cr=1;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++) chk[i]=i;
	for(i=1;i<=m;i++) scanf("%d %d %d",&dat[i].x,&dat[i].y,&dat[i].w);
	qsort(dat+1,m,sizeof(an),cmp);
	for(i=1;i<=m;i++)
	{
		if(chk[dat[i].x]!=chk[dat[i].y]) 
			{
				join(dat[i].x,dat[i].y,n); cr++;
				printf("%d %d %d\n",dat[i].x,dat[i].y,dat[i].w);
			}
		if(cr==n) break;
	}
	return 0;
}