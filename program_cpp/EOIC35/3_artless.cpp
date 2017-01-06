#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int num[105]={};

int main()
{
    int n,m,i,j,k,csum=0;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++) scanf("%d",&num[i]);
    sort(num,num+n);
    for(i=n-1;i>=0;i--)
    {
        if(num[i]>m) continue; else csum+=num[i];
        for(j=i-1;j>=0;j--)
        {
            if(csum+num[0]>m) break;
            if(num[j]>m||csum+num[j]>m) continue; else csum+=num[j];
            for(k=j-1;k>=0;k--)
            {
                if(csum+num[0]>m) break;
                if(num[k]>m||csum+num[k]>m) continue; else {csum+=num[k]; printf("%d",csum); return 0;}
            }
            csum-=num[j];
        }
        csum-=num[i];
    }
    return 0;
}
