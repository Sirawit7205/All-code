#include<stdio.h>
#include<stdlib.h>

int dat[1000005]={},n;

int cmp(const void *a,const void *b)
{
    int *A=(int *)a;
    int *B=(int *)b;
    return *A>*B;
}

int f_p(int a,int lim)
{
    int i,t=0;
    for(i=lim;i<n;i++) t+=dat[i]/a;
    return t;
}

int main()
{
    int i,p,j,c,f,pr=-1;
    scanf("%d %d",&n,&p);
    for(i=0;i<n;i++) scanf("%d",&dat[i]);
    qsort(dat,n,sizeof(int),cmp);
    for(i=n-1;i>=0;i--)
    {
        c=f_p(dat[i],i);
        if(c==p) {printf("YES\n%d",dat[i]); return 0;}
        else if(c>p)
        {
            for(j=dat[i+1]-1;j>i;j--)
            {
                f=f_p(j,i); if(pr==-1) pr=j;
                if(f==p) {printf("YES\n%d",j); return 0;}
                if(f>p) {printf("NO\n%d",pr); return 0;}
                pr=f;
            }
        }
    }
    for(j=dat[0]-1;j>0;j--)
        {
            f=f_p(j,0);
            if(f==p) {printf("YES\n%d",j); return 0;}
            else if(f>p) {printf("NO\n%d",j); return 0;}
        }
        printf("NO\n%d",1);
    //for(i=0;i<n;i++) printf("%d ",dat[i]);
    return 0;
}
