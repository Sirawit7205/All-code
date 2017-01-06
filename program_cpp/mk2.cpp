#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int p[1000010][2]={},d[1000010][2]={};

int cmp (const void *a,const void *b)
{
    int *aa=(int *)a;
    int *bb=(int *)b;
    if(aa[0]>bb[0]) return 1; else return -1;
}

int main()
{
    int i,n,x,y,z,ta,tb,sa=0,sb=0,sum,m=0;
    scanf("%d %d %d %d",&n,&x,&y,&z);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&ta,&tb);
        p[sa][0]=ta; p[sa][1]=y-x; sa++;
        d[sb][0]=tb+1; d[sb][1]=z-y; sb++;
    }
    qsort(p,sa,sizeof(p[0]),cmp);
    qsort(d,sb,sizeof(d[0]),cmp);
    sum=x*n; ta=0; tb=0;
    while(1)
    {
        if(ta>sa&&tb>sb) break;
        if((p[ta][0]<d[tb][0]&&ta<=sa)||tb>sb)
        {sum+=p[ta][1]; ta++;
        while(p[ta][0]==p[ta-1][0]&&ta<=sa) {sum+=p[ta][1]; ta++;}}
        else if((p[ta][0]>d[tb][0]&&tb<=sb)||ta>sa)
        {sum+=d[tb][1]; tb++;
        while(d[tb][0]==d[tb-1][0]&&tb<=sb) {sum+=d[tb][1]; tb++;}}
        else
        {
            sum+=p[ta][1]; ta++;
            while(p[ta][0]==p[ta-1][0]&&ta<=sa) {sum+=p[ta][1]; ta++;}
            sum+=d[tb][1]; tb++;
            while(d[tb][0]==d[tb-1][0]&&tb<=sb) {sum+=d[tb][1]; tb++;}
        }
        if(sum>m) m=sum;
    }
    sum-=z*n; if(sum>m) m=sum;
    printf("%d",m);
    return 0;
}
