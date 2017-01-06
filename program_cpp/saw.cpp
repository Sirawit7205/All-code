#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

int mdat[1000005][2]={};

struct a
{
    int n,lp,chk;
    bool operator<(const a&T) const
    {
        if(lp == T.lp) return n < T.n ;
        else return lp < T.lp;
    }
}inst;

priority_queue<a> q;

int main()
{
    int i,n,m,ta,tb,tc,mode;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++) {scanf("%d",&ta); mdat[i][0]=ta; inst.n=i; inst.lp=ta; inst.chk=0; q.push(inst);}
    //for(i=1;i<=n;i++) {inst=q.top(); q.pop(); printf("%d %d\n",inst.n,inst.lp);}
    for(i=1;i<=m;i++)
    {
        scanf("%d",&mode);
        if(mode==1)
        {
            scanf("%d %d %d",&ta,&tb,&tc);
            if(mdat[ta][1]!=-1&&mdat[tb][1]!=-1&&mdat[ta][0]-i>0&&mdat[tb][0]-i>0)
            {
                if(tc>=mdat[tb][0]-i)
                {
                    mdat[ta][0]+=mdat[tb][0]-(i*2);
                    mdat[ta][1]=i; mdat[tb][1]=-1;
                    inst.n=ta; inst.lp=mdat[ta][0]; inst.chk=mdat[ta][1]; q.push(inst);
                }
                else
                    {
                        mdat[ta][0]+=tc-(i-mdat[ta][1]); mdat[tb][0]-=tc-(i-mdat[ta][1]);
                        mdat[ta][1]=i; mdat[tb][1]=i;
                        inst.n=ta; inst.lp=mdat[ta][0]; inst.chk=mdat[ta][1]; q.push(inst);
                        inst.n=tb; inst.lp=mdat[tb][0]; inst.chk=mdat[tb][1]; q.push(inst);
                    }
            }
            else if(mdat[ta][0]-i<=0) mdat[ta][1]=-1;
            else if(mdat[tb][0]-i<=0) mdat[tb][1]=-1;
        }
        else if(mode==2)
        {
            scanf("%d %d",&ta,&tb);
            if(mdat[ta][1]!=-1&&mdat[ta][0]-i>0)
            {
                mdat[ta][1]++; mdat[ta][0]+=tb-i-1;
                inst.n=ta; inst.lp=mdat[ta][0]; inst.chk=mdat[ta][1]; q.push(inst);
            }
            else if(mdat[ta][0]-i<=0) mdat[ta][1]=-1;
        }
        else
        {
            if(not q.empty())
            {
                while(1)
                {
                    inst=q.top(); q.pop();
                    if(mdat[inst.n][0]-i<0||mdat[inst.n][1]==-1) {mdat[inst.n][1]=-1; continue;}
                    else if(mdat[inst.n][1]!=inst.chk) continue;
                    else if(inst.chk==0&&i==1) {printf("%d %d\n",inst.n,inst.lp-1); inst.chk=i; mdat[inst.n][1]=i; q.push(inst); break;}
                    else if(inst.chk==0) {printf("%d %d\n",inst.n,inst.lp-i); inst.chk=i; mdat[inst.n][1]=i; q.push(inst); break;}
                    else if(inst.chk!=0) {printf("%d %d\n",inst.n,inst.lp); break;}
                }
            }
            else printf("-1\n");

        }
    }
    return 0;
}
