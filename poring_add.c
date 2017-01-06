#include<stdio.h>

int target,ans=0,use[10]={},dat[10]={};

void perm(int r)
{
    int i,t;
    if(r>9) {for(i=0;i<10;i++) t+=dat[i]; if(t==target) ans++; return;}
    for(i=0;i<9;i++) {if(use[i]==0) {use[i]=1; dat[r]=i; perm(r);}}
}

int main()
{
    scanf("%d",&target);
    perm(0); if(target==1) ans++;
    printf("%d",ans);
    return 0;
}
