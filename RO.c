#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int a[1000005]={};

typedef struct
{
    long long int val,ind;
}s;

s b[1000005]={};

int cmp(const void* a,const void* b)
{
    s *aa=(s *)a;
    s *bb=(s *)b;
    if(aa->val < bb->val) return 1;
    else if(aa->val == bb->val&& aa->ind > bb->ind ) return 1;
    else return -1;
}

int main()
{
    int n,i;
    long long int dmax=0,dtemp=0,tm=INT_MAX,ta=INT_MIN,cur,k;
    char t;
    scanf("%d %lld",&n,&k);
    for(i=1;i<=n;i++) {scanf(" %c",&t); if(t=='R') a[i]=1; else a[i]=2;}
    for(i=1;i<=n;i++)
    {
        if(a[i]==1) b[i].val=b[i-1].val-k;
        else b[i].val=b[i-1].val+1;
        b[i].ind=i;
    }
    //for(i=1;i<=n;i++) printf("%d: %d %d\n",i,b[i].val,b[i].ind); printf("\n");
    qsort(b,n+1,sizeof(s),cmp);
    //for(i=1;i<=n;i++) printf("%d: %lld %lld\n",i,b[i].val,b[i].ind);
    for(i=1;i<=n;i++)
    {
        if(i==1) {cur=b[i].val; if(b[i].ind<tm) tm=b[i].ind; if(b[i].ind>ta) ta=b[i].ind; dtemp=ta-tm; continue;}
        if(b[i].val!=cur) {cur=b[i].val; if(dmax<dtemp) dmax=dtemp; tm=INT_MAX; ta=INT_MIN; dtemp=0; if(b[i].ind<tm) tm=b[i].ind; if(b[i].ind>ta) ta=b[i].ind; dtemp=ta-tm;}
        else if(b[i].val==cur) {if(b[i].ind<tm) tm=b[i].ind; if(b[i].ind>ta) ta=b[i].ind; dtemp=ta-tm;}
    }
    printf("%lld",dmax);
    return 0;
}
