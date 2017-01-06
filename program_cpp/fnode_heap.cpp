#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

struct a
{
    int val,chk;
    bool operator<(const a&T) const {
        if(val!=T.val) return val<T.val;
        else return chk<T.chk;
    }
}b;
priority_queue<a> q;

int vald[1000005]={};

int main()
{
    int i,n,l,r,ta,tb;
    char t;
    scanf("%d %d %d",&n,&l,&r);
    for(i=1;i<=n;i++) {b.val=0; b.chk=i; q.push(b);}
    for(i=0;i<l+r;i++)
    {
         scanf(" %c",&t);
         if(t=='L')
         {
            scanf("%d %d",&ta,&tb);
            b.val=vald[tb]+1; b.chk=tb; q.push(b); vald[tb]+=1;
         }
         else if(t=='C')
         {
            scanf("%d %d",&ta,&tb);
            b.val=vald[tb]+3; b.chk=tb; q.push(b); vald[tb]+=3;
         }
         else if(t=='R'||t=='D')
         {
             while(not q.empty())
             {
                 b=q.top();
                 if(b.val!=vald[b.chk]) {q.pop(); continue;}
                 else
                 {
                     if(t=='D') q.pop();
                     else printf("%d\n",b.chk);
                 }
                 break;
             }
         }
    }
    return 0;
}
