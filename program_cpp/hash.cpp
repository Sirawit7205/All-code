#include<iostream>
#include<cstdio>

using namespace std;

bool dat[100000000]={false};

int main()
{
    int a,b,n,m,scn,cnt=0,tt;
    unsigned long long t,i,j;
    scanf("%d %d %d %d",&a,&b,&n,&m);
    for(i=0;i<a;i++)
    {
        scanf("%d",&scn);
        for(j=0;j<b;j++)
        {
            t=((scn+(j*j))%99999989)%99999989;
            //printf("%lld ",t);
            //t=t%99999989;
            tt=t;
            dat[tt]=true;
        }
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&scn);
        for(j=0;j<m;j++)
        {
            t=((scn+(j*j*j))%99999989)%99999989;
            //printf("%lld ",t);
            //t=t%99999989;
            tt=t;
            if(dat[tt]==true) cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}
