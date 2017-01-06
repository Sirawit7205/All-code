#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

queue<int> a;

int main()
{
    int n,m,i,t;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++) a.push(i);
    while(not a.empty())
    {
        for(i=1;i<m;i++)
        {
            t=a.front(); a.pop(); a.push(t);
        }
        printf("%d ",a.front()); a.pop();
    }
    return 0;
}
