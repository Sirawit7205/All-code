#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

struct inser
{
    long long int ind,a,b,c,d;
    bool operator < (const inser&T) const
    {
        return ind < T.ind;
    }
}dat[400005];

int fi=0;

void inst(long long int a,long long int b,long long int c)
{
    if(a==2||a==4||a==6||a==8||a==10) {dat[fi].a++; dat[fi+1].a--;} if(a==4) {dat[fi].a++; dat[fi+1].a--;} if(a==8) {dat[fi].a+=2; dat[fi+1].a-=2;}
    if(a==3||a==6||a==9) {dat[fi].b++; dat[fi+1].b--;} if(a==9) {dat[fi].b++; dat[fi+1].b--;}
    if(a==5||a==10) {dat[fi].c++; dat[fi+1].c--;}
    if(a==7) {dat[fi].d++; dat[fi+1].d--;}
    dat[fi].ind=b; dat[fi+1].ind=c+1;
    fi+=2;
}

int main()
{
    long long int t,comp[5]={},i,m,n,ta,tb,tc,prev=0,ma=0,coun=0;
    scanf("%lld %lld",&m,&n);
    dat[fi+1].ind=n+1; fi+=2;
    for(i=0;i<m;i++)
    {
        scanf("%lld %lld %lld",&ta,&tb,&tc);
        inst(ta,tb,tc);
    }
    sort(dat,dat+fi);
    //for(i=0;i<fi;i++) printf("%d %d %d %d %d\n",dat[i].ind,dat[i].a,dat[i].b,dat[i].c,dat[i].d);
    for(i=0;i<fi;i++)
    {
        if(prev==dat[i].ind) {comp[0]+=dat[i].a; comp[1]+=dat[i].b; comp[2]+=dat[i].c; comp[3]+=dat[i].d;}
        if(prev!=dat[i].ind)
        {
            t=(comp[0]+1)*(comp[1]+1)*(comp[2]+1)*(comp[3]+1);
            if(t>ma) {ma=t; coun=dat[i].ind-prev;}
            else if(t==ma) coun+=dat[i].ind-prev;
            comp[0]+=dat[i].a; comp[1]+=dat[i].b; comp[2]+=dat[i].c; comp[3]+=dat[i].d;
            //reach+=dat[i].ind-prev;
            prev=dat[i].ind;
        }
        //printf("%d %d %d %d %d\n",i,comp[0],comp[1],comp[2],comp[3]);
    }
    printf("%lld %lld",ma,coun);
    return 0;
}
