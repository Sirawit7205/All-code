#include<stdio.h>
#include<string.h>

int n,k,l,c=1,use[12]={},ans[12]={},e=0;

void permu(int a)
{
    int i,j;
    if(e==1) return;
    if(a==k+1)
    {
        if(c==l)
        {
            for(i=1;i<=k;i++) printf("%d ",ans[i]);
            //printf("\n");
            e=1;
            return;
        }
        //memset(ans,0,sizeof(ans));
        c++;
        return;
    }
    for(j=1;j<=n;j++)
    {
        if(use[j]==0)
        {
            ans[a]=j;
            use[j]=1;
            permu(a+1);
            use[j]=0;
        }
    }
}

int main()
{
    scanf("%d %d %d",&n,&k,&l);
    permu(1);
    return 0;
}
