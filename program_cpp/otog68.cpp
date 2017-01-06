#include<cstdio>

long long int pattn[5]={},ans=0;

int main()
{
    int i,j,n,a,b,bwa,bwb,ca,cb;
    scanf("%d %d %d",&n,&a,&b);
    for(i=1;i<=4;i++)
    {
        ca=0; cb=0;
        if(i==1) {bwa=1; bwb=1;}
        else if(i==2) {bwa=1; bwb=0;}
        else if(i==3) {bwa=0; bwb=1;}
        else {bwa=0; bwb=0;}
        for(j=1;j<=n;j++)
        {
            if(bwa==1||bwb==1) pattn[i]++;
            ca++; cb++;
            if(ca==a) {if(bwa==1) bwa=0; else bwa=1; ca=0;}
            if(cb==b) {if(bwb==1) bwb=0; else bwb=1; cb=0;}
        }
    }
    ca=0; cb=0; bwa=1; bwb=1;
    for(i=1;i<=n;i++)
    {
        if(bwa==1&&bwb==1) ans+=pattn[1];
        else if(bwa==1&&bwb==0) ans+=pattn[2];
        else if(bwa==0&&bwb==1) ans+=pattn[3];
        else ans+=pattn[4];
        ca++; cb++;
        if(ca==a) {if(bwa==1) bwa=0; else bwa=1; ca=0;}
        if(cb==b) {if(bwb==1) bwb=0; else bwb=1; cb=0;}
    }
    printf("%lld",ans);
    return 0;
}
