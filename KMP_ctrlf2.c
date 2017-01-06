#include<stdio.h>

char a[1000005]={},b[1000005]={};
int pi[1000005]={};

int main()
{
    int n,f,i,k=0,q=0,ans=0;
    scanf("%d",&n);
    scanf("%d",&f);
    for(i=1;i<=n;i++) scanf(" %c",&a[i]);
    for(i=1;i<=f;i++) scanf(" %c",&b[i]);
    pi[1]=0;
    for(i=2;i<=f;i++)
    {
        while(k>0&&b[i]!=b[k+1])
            k=pi[k];
        if(b[i]==b[k+1]) k++;
        pi[i]=k;
    }
    for(i=1;i<=n;i++)
    {
        while(q>0&&a[i]!=b[q+1])
            q=pi[q];
        if(a[i]==b[q+1]) q++;
        if(q==f) ans++;
    }
    printf("%d",ans);
    return 0;
}
