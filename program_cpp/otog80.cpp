#include<cstdio>
#include<queue>

using namespace std;

struct a
{
    int date,price,name;
    bool operator < (const a&T)const{
        if(date==T.date) return price < T.price;
        else return date < T.date;
    }
}aa;

struct b
{
    int date,price,name;
    bool operator < (const b&T)const{
        return price < T.price;
    }
}bb;

priority_queue<a> q;
priority_queue<b> qq;
int s[100005]={},x[100005]={};

int main()
{
    int n,i,ta,tb,c=0,mx;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&ta,&tb);
        aa.date=ta; aa.price=tb; aa.name=i; q.push(aa);
    }
    mx=q.top().date;
    while(1)
    {
        if(mx<=0) break;
        if(!q.empty()) while(q.top().date>mx) {bb.date=q.top().date; bb.name=q.top().name; bb.price=q.top().price; qq.push(bb); q.pop(); if(q.empty()) break;}
        if(q.empty()&&!qq.empty()) {c++; s[c]=qq.top().name; qq.pop();}
        else if(!q.empty())
        {
            if(!qq.empty())
            {
                if(q.top().date<mx) {c++; s[c]=qq.top().name; qq.pop();}
                else if(qq.top().price>q.top().price) {c++; s[c]=qq.top().name; qq.pop();}
                else {c++; s[c]=q.top().name; q.pop();}
            }
            else if(q.top().date>=mx) {c++; s[c]=q.top().name; q.pop();}
        }
        else break;
        mx--;
    }
    printf("%d\n",c);
    for(i=c;i>=1;i--) printf("%d\n",s[i]);
    return 0;
}
