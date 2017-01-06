#include<iostream>
#include<cstdio>

using namespace std;

long long pass[1000]={},exit_total[1000]={},cnt[1000]={};

int main()
{
    int n;
    long long tt,tc;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&pass[i]);
    for(i=1;i<=n+1;i++)
    {
        cnt[i]++;
        if(cnt%2!=0)
        {
            if(cnt[pass[i]]!=0) tt+=cnt[pass[i]];
            else
            {
                while(1)
                {

                }
            }
        }

    }
}
