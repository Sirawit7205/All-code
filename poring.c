#include<stdio.h>

int main()
{
    int i,n;
    long long int cur=1,repl=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        cur+=(repl*3)-1;
        repl=(repl*3)-1;
    }
    printf("%lld",cur);
    return 0;
}
