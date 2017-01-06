#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

struct rice
{
  double absp,left,price;
  bool operator<(const rice&T) const {return absp>T.absp;}
}r;

priority_queue<rice> dat;

int main()
{
    int i,k,m,req;
    double prc=0;
    scanf("%d",&k);
    for(i=0;i<k;i++)
    {
        scanf("%lf %lf",&r.price,&r.left); r.absp=r.price/r.left;
        dat.push(r);
    }
    r.left=0;
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%d",&req); prc=0;
        while(req!=0)
        {
            if(r.left==0) {r=dat.top(); dat.pop();}
            if(r.left>=req) {prc+=req*r.absp; r.left-=req; break;}
            else {prc+=r.left*r.absp; req-=r.left; r.left=0;}
        }
        printf("%.3f\n",prc);
    }
    return 0;
}
