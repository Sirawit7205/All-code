#include<iostream>
#include<cstdio>

using namespace std;

int p[200005]={};

int main()
{
    int i,n,m,mode,a,c,suma,sumb;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d",&mode);
        if(mode==1)
        {
            scanf("%d %d",&c,&a);
            p[a]+=c;
            while(a<=n)
            {
                a+=(a&-a);
                if(a>n) break;
                p[a]+=c;
            }
        }
        else
        {
            scanf("%d %d",&a,&c);
            suma=0; a--;
            while(a)
            {
                suma+=p[a];
                a-=(a&-a);
            }
            sumb=0;
            while(c)
            {
                sumb+=p[c];
                c-=(c&-c);
            }
            printf("%d\n",sumb-suma);
        }
    }
    return 0;
}
