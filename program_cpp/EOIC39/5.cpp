#include<cstdio>

int dat[10]={},use[10]={},ans[10]={},k;

void chk()
{
    int i,s,sym=0;
    printf("%d",ans[0]); s=ans[0];
    for(i=1;i<k;i++)
    {
        if(sym==0) {printf("+"); s+=ans[i]; sym=1;} else {printf("-"); s-=ans[i]; sym=0;}
        printf("%d",ans[i]);
    }
    printf("=%d\n",s);
    return;
}

void perm(int c,int lim)
{
    int i;
    if(c==lim) {chk(); return;}
    for(i=0;i<k;i++)
    {
        if(use[i]==0) {use[i]=1; ans[c]=dat[i]; perm(c+1,lim); use[i]=0;}
    }
}

int main()
{
    int i;
    scanf("%d",&k);
    for(i=0;i<k;i++) scanf("%d",&dat[i]);
    perm(0,k);
    return 0;
}
