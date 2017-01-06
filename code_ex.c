#include<stdio.h>
#include<stdlib.h>
int code[1000005]={},mov[1000005]={};

int cmp(const void *a,const void *b)
{
    int *A=(int *)a;
    int *B=(int *)b;
    return *A-*B;
}

int main()
{
    int i,n,t,max=0,num=0,cur=-2,ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&t);
        code[t]=i;
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&t);
        if(code[t]!=0)
        {
            if(code[t]==i) mov[t]=-3;
            else if(code[t]>i) mov[t]=n-(code[t]-i);
            else mov[t]=i-code[t];
        }
        else mov[t]=-1;
    }
    mov[0]=-1;
    qsort(mov,n,sizeof(int),cmp);
    for(i=1;i<=n;i++)
    {
        if(mov[i]==-1||mov[i]==0) continue;
        if(mov[i]!=cur) {ans=mov[i]; if(num>max) {max=num; ans=cur;} num=0; cur=mov[i];}
        num++;
    }
    if(ans==-3) ans=0;
    printf("%d",ans);
    return 0;
}
