#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int cn[1000005]={},f[1005][2]={};

int main()
{
    int n,m,k,l,i,j,cnt,pt,t,tb,c;
    scanf("%d %d %d %d",&n,&m,&k,&l);
    for(i=0;i<n;i++) scanf("%d",&cn[i]);
    for(i=0;i<k;i++)
    {
        cnt=0; pt=0; c=0;
        for(j=0;j<m;j++)
        {
            scanf("%d",&t);
            if(pt==0||t-l>f[pt-1][1]) {f[pt][0]=t-l; f[pt][1]=t+l; pt++;}
            else f[pt-1][1]=t+l;
        }
        //for(j=0;j<pt;j++) printf("%d %d\n",f[j][0],f[j][1]);
        for(j=0;j<pt;j++)
        {
            t=lower_bound(cn+c,cn+n,f[j][0])-cn;
            tb=upper_bound(cn+c,cn+n,f[j][1])-cn;
            cnt+=tb-t; c+=tb-t;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
