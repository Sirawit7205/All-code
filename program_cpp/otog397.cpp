#include<cstdio>

int left[10005]={},cnt=0;

void srch(int a)
{
    int i;
    for(i=0;i<cnt;i++)
    {
        if(left[i]==a) return;
    }
    left[cnt]=a;
    cnt++;
}

int main()
{
    int i,n,t,d;
    scanf("%d %d",&n,&d);
    for(i=0;i<n;i++)
    {
        scanf("%d",&t);
        srch(t%d);
    }
    printf("%d",cnt);
    return 0;
}
