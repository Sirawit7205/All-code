#include<iostream>
#include<cstdio>

using namespace std;

int dat[100001]={},n,pth[100001][2]={},c=0;

/*void fx(int f,int t)
{
    int i;
    for(i=1;i<=n;i++) if(dat[i]==f) dat[i]=t;
}*/

int main()
{
    int i,Q,m,ta,tb,a=1,tc;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&ta,&tb);
        if(dat[ta]==0&&dat[tb]==0) {dat[ta]=a; dat[tb]=a; a++;}
        else if(dat[ta]==0&&dat[tb]!=0) {dat[ta]=dat[tb];}
        else if(dat[tb]==0&&dat[ta]!=0) {dat[tb]=dat[ta];}
        else if(dat[tb]!=0&&dat[ta]!=0&&dat[ta]!=dat[tb]) {pth[c][0]=dat[ta]; pth[c][1]=dat[tb]; c++;}
    }
    scanf("%d",&Q);
    for(i=0;i<Q;i++)
    {
        scanf("%d %d",&ta,&tb);
        if(dat[ta]==dat[tb]) printf("YES\n");
        else
        {
            tc=0;
            for(i=0;i<c;i++) if((pth[i][0]==dat[ta]&&pth[i][1]==dat[tb])||(pth[i][0]==dat[tb]&&pth[i][1]==dat[ta])) {printf("YES\n"); tc=1; break;}
            if(tc==0) printf("NO\n");
        }
    }
    //for(i=1;i<=n;i++) printf("%d ",dat[i]);
    return 0;
}
