#include<cstdio>

int d[2505]={},m=-1,mts=0;

int main()
{
    int i,n,pa=0,pb,ma,mb;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&d[i]);
    for(i=0;i<n;i++)
    {
        if(d[i]+mts>0) {if(pa==-1) pa=i; mts+=d[i]; if(mts>m) {m=mts; pb=i; ma=pa; mb=pb;}}
        else if(d[i]+mts<=0) {mts=0; pa=-1;}
    }
    if(m==-1) printf("Empty sequence");
    else
    {
        for(i=ma;i<=mb;i++) printf("%d ",d[i]);
        printf("\n%d",m);
    }
    return 0;
}
