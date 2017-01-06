#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

struct two
{
    int w,v,t,d;
    bool operator<(const two&T) const {return w>T.w;}
}insto;

struct three
{
    int cw,v,t,p;
    bool operator<(const three&T) const {return t>T.t;}
}instt;

priority_queue<two> qo;
priority_queue<three> qt;
int var[100001]={};

int main()
{
    int i,m,n,mode,place=0,a,b,c,f=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n+m;i++)
    {
        f=0;
        scanf("%d",&mode);
        if(mode==1)
        {
            scanf("%d",&mode);
            if(mode==1)
            {
                scanf("%d %d",&insto.w,&insto.v); insto.t=-1; insto.d=-1;
                qo.push(insto);
            }
            else if(mode==2)
            {
                scanf("%d %d %d",&insto.w,&insto.v,&insto.t); insto.d=-1;
                qo.push(insto);
            }
            else
            {
                scanf("%d %d %d %d",&insto.w,&a,&b,&c);
                insto.v=a; insto.t=b; insto.d=place; instt.cw=c; instt.v=a; instt.t=b; instt.p=place;
                qo.push(insto); qt.push(instt); place++;
            }
        }
        else
        {
            while(not qo.empty())
            {
                insto=qo.top(); qo.pop();
                if(insto.t!=-1&&insto.d==-1&&insto.t<i) continue;
                else if(insto.d!=-1&&var[insto.d]==1) continue;
                else {printf("%d\n",insto.v); if(insto.d!=-1) var[insto.d]=2; f=1; break;}
            }
            if(qo.empty()&&f==0) {printf("0\n"); continue;}
        }
        while(not qt.empty())
        {
            instt=qt.top();
            if(instt.t==i)
            {
                qt.pop();
                if(var[instt.p]!=2)
                {
                    var[instt.p]=1;
                    insto.w=instt.cw; insto.v=instt.v; insto.t=-1; insto.d=-1;
                    qo.push(insto);
                }
            }
            else break;
        }
    }
    return 0;
}
