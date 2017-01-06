#include<stdio.h>

int num[605]={};

int chk(int a,int b)
{
    if(b<=a) return 1;
    if(num[a-1]<num[b-1]) return 1;
    else if(num[a-1]>num[b-1]) return -1;
    else chk(a-1,b-1);
}

int main()
{
    int i,j,n,a,b,c;
    long long int ans=0,tmp=0;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&num[i]);
    a=0; b=n-1;
    for(i=0;i<n-1;i++)
    {
        if(num[a]<num[b])
        {
            alb:;
            ans+=(num[a]*2);
            for(j=a+1;j<=b;j++) tmp+=num[j];
            ans+=tmp; tmp=0; a++;
        }
        else if(num[a]>num[b])
        {
            bla:;
            ans+=(num[b]*2);
            for(j=a;j<b;j++) tmp+=num[j];
            ans+=tmp; tmp=0; b--;
        }
        else
        {
            c=chk(a,b);
            if(c==1) goto alb; else goto bla;
        }
    }
    printf("%lld",ans);
    return 0;
}
