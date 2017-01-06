#include<cstdio>
#include<algorithm>

struct a{
    int xa,xb,ya,yb;
    bool operator < (const a&T)const{
        return xa+xb < T.xa+T.xb;
    }
};

struct b{
    int x,y;
};

int n,tax,tay,c=0;
b fa[1505]={},fb[1505]={},fc[1505]={},fd[1505]={};
a sa[2250005]={},sb[2250005]={};

int chk(int a,int b)
{
    if(sa[a].ya+sa[a].yb+sb[b].ya+sb[b].yb==tay)
    {
        printf("%d %d\n%d %d\n%d %d\n%d %d",sa[a].xa,sa[a].ya,sa[a].xb,sa[a].yb,
               sb[b].xa,sb[b].ya,sb[b].xb,sb[b].yb);
        return 1;
    }
    else return 0;
}

int main()
{
    int i,j,mid,l,r,k,tx=0;
    scanf("%d %d %d",&tax,&tay,&n);
    for(i=0;i<n;i++) {scanf("%d %d",&fa[i].x,&fa[i].y);}
    for(i=0;i<n;i++) {scanf("%d %d",&fb[i].x,&fb[i].y);}
    for(i=0;i<n;i++) {scanf("%d %d",&fc[i].x,&fc[i].y);}
    for(i=0;i<n;i++) {scanf("%d %d",&fd[i].x,&fd[i].y);}
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            sa[c].xa=fa[i].x; sa[c].xb=fb[j].x;
            sa[c].ya=fa[i].y; sa[c].yb=fb[j].y;
            sb[c].xa=fc[i].x; sb[c].xb=fd[j].x;
            sb[c].ya=fc[i].y; sb[c].yb=fd[j].y;
            c++;
        }
    }
    std::sort(sb,sb+c);
    for(i=0;i<c;i++)
    {
        k=tax-sa[i].xa-sa[i].xb;
        l=0; r=c-1; mid=(l+r)/2;
        while(l<=r)
        {
            if(sb[mid].xa+sb[mid].xb==k) {tx=chk(i,mid); break;}
            else if(sb[mid].xa+sb[mid].xb<k) l=mid+1;
            else r=mid-1;
            mid=(l+r)/2;
        }
        if(tx==1) break;
    }
    return 0;
}
