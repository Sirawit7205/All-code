#include<stdio.h>

int main(){
    int n,i,j,k[12],mx,cn=0,sum=0,l,ans[11][3]={};
    for(l=0;l<10;l++){
    mx=5000;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&k[i]);
        k[i]=k[i]-2;
        if(k[i]<mx) mx=k[i];
    }
    for(i=mx;i>0;i--)
    {
        cn=0;
        for(j=0;j<n;j++)
        {
            if(k[j]%i==0)
                cn++;
        }
        if(cn==n) break;
    }
    for(j=0;j<n;j++)
    {
        sum+=k[j]/i;
    }
    ans[l][0]=i;
    ans[l][1]=sum;
    sum=0;
    }
    for(i=0;i<10;i++){
    printf("%d %d\n",ans[i][0],ans[i][1]);}
    return 0;
}
