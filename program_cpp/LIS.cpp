#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int a[100001]={},ma[100001]={},s=0;

/*int bins(int a,int b,int c)
{
    int mid=(a+b)/2;
    if(a==b) return a;
    //if(ma[mid-1]<c&&ma[mid+1]>=c) return mid+1;
    if(ma[mid]==c) return mid;
    if(ma[mid]<c) bins(mid+1,b,c);
    else bins(a,mid-1,c);
}*/

int main()
{
    int i,n,m;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        if(s==0) {m=s; s++;}
        else if(ma[s-1]==a[i]) continue;
        else if(ma[s-1]<a[i]) {m=s; s++;}
        else
        {
            /*x=0,b=s-1;
            while(1)
            {
                if(x>=b) {m=b+1; break;}
                mid=(x+b)/2;
                if(ma[mid-1]<a[i]&&ma[mid+1]>=a[i]) {m=mid; break;}
                if(ma[mid]==a[i]) {m=mid; break;}
                if(ma[mid]<a[i]) {x=mid+1;} else b=mid-1;
            }*/
            m=upper_bound(ma,ma+s,a[i])-ma;
        }
        if(ma[m-1]==a[i]) continue;
        ma[m]=a[i];
    }
    printf("%d",s);
    return 0;
}
