#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct a
{
    int cn,co;
}tmp;

vector<a> arr[100000];
priority_queue<a> sht[1000000];
set<int> chk;
set<int>::iterator it;
int main()
{
    int i,n,m,ta,tb,tc,x=0,j;
    cin >> n >> m;
    for(i=0;i<m;i++)
    {
        cin >> ta >> tb >> tc;
        tmp.cn=tb; tmp.co=tc;
        arr[ta].push_back(tmp);
    }
    chk.insert(1); ta=1;
    for(i=0;i<n-1;i++)
    {
        x=(arr[ta].size());
        for(j=0;j<x;j++) {it=chk.find(arr[ta].tmp.cn);}
    }
    return 0;
}
