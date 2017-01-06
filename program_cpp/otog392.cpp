#include<cstdio>
#include<queue>

using namespace std;

struct a{
    int nd,w;
    bool operator<(const a&T) const {return w>T.w;}
}aa;

priority_queue<a> q;
int con[30][30][2]={},st[30]={},fr,to;

int main()
{
    int i,t,ta,tb;
    char ca,cb,cc,cd;
    scanf(" %c %c %d",&ca,&cb,&t);
    for(i=0;i<26;i++) st[i]=-1;
    for(i=0;i<t;i++)
    {
        scanf(" %c %d %c %d",&cc,&ta,&cd,&tb);
        if(tb==1) continue;
        con[cc-65][con[cc-65][0][0]+1][0]=cd-65; con[cc-65][con[cc-65][0][0]+1][1]=ta; con[cc-65][0][0]++;
        con[cd-65][con[cd-65][0][0]+1][0]=cc-65; con[cd-65][con[cd-65][0][0]+1][1]=ta; con[cd-65][0][0]++;
    }
    aa.nd=ca-65; aa.w=0; q.push(aa); st[ca-65]=0;
    while(!q.empty())
    {
        aa=q.top(); q.pop(); ta=aa.nd; tb=aa.w;
        for(i=1;i<=con[ta][0][0];i++)
        {
            if(st[con[ta][i][0]]==-1||st[con[ta][i][0]]>tb+con[ta][i][1])
            {
                st[con[ta][i][0]]=tb+con[ta][i][1];
                aa.nd=con[ta][i][0]; aa.w=st[con[ta][i][0]]; q.push(aa);
            }
        }
    }
    printf("%d",st[cb-65]);
    return 0;
}
