#include<iostream>
#include<cstdio>

int dat[100001]={},c,cache[100001][2]={};

/*void chk(int a)
{
    if(a<c)
    {
        for(int i=2;i<c;i++)
        {
            if(a+i>c) return;
            if(a+i<=c) sum+=dat[a+i];
            if(sum>ma) ma=sum;
            chk(a+i+1);
            sum-=dat[a+i];
        }
    }
    else return;
}*/

int chk(int a)
{
    //int b,c;
    if(a<2) return 0;
    else
    {
        if(cache[a][1]==1) return cache[a][0];
        else
        {
           // b=chk(a-1); c=chk(a-3)+dat[a];
            //if(b>=c) {cache[a][0]=b; cache[a][1]=1; return b;}
            //else {cache[a][0]=c; cache[a][1]=1; return c;}
            cache[a][1]=1;
            return cache[a][0]=std::max(chk(a-1), chk(a-3)+dat[a]);
        }
    }
}

int main()
{
    int i,x;
    scanf("%d",&c);
    for(i=0;i<c;i++) scanf("%d",&dat[i]);
    x=chk(c-1);
    printf("%d",x);
    return 0;
}
