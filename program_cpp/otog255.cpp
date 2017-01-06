#include<cstdio>
#include<vector>
#include<queue>

std::queue<int> q;
std::vector<int> v[100005]={};
int amt[100005]={},n,m;
long long int s[100005]={};

int main()
{
    int i,ta,tb,t;
    scanf("%d %d",&n,&m);
    for(i=1;i<n;i++)
    {
        scanf("%d %d",&ta,&tb);
        v[tb].push_back(ta); amt[tb]++;
    }
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&ta,&tb);
        s[ta]+=tb;
    }
    q.push(1);
    while(!q.empty())
    {
        t=q.front(); q.pop();
        for(i=0;i<amt[t];i++)
        {
            s[v[t][i]]+=s[t];
            q.push(v[t][i]);
        }
    }
    for(i=1;i<=n;i++) printf("%lld\n",s[i]);
    return 0;
}
