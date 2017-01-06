#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int p[100005]={};

int main()
{
    int i,n=0,k,c,l,t=0,ma=1,j=1;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++) scanf("%d",&p[i]);
    sort(p,p+n);
    for(i=p[0];i<=p[n-1];i++)
    {
        l=p[0]; t=0;
        while(1)
        {
            l+=j;
            c=upper_bound(p,p+n,l)-p;
            if(p[c-1]==l||p[c]>l) {t++;}
            if(t==k-1) {if(ma<j) ma=j; break;}
            if(c==n) {printf("%d",ma); return 0;}
        }
        j++;
    }
    //for(i=0;i<n;i++) printf("%d ",p[i]);
    return 0;
}
