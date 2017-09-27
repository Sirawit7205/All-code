#include<stdio.h>

#define const_odd 0.1339745

int main()
{
    double ans;
    int in;

    scanf("%d",&in);
    if(in%2==0)
        ans=in;
    else if(in==1)
        ans=2;
    else if(in==3)
        ans=(in+1)-(const_odd*2);
    else
        ans=(in+1)-(const_odd*4);

    printf("%.6lf",ans);
    return 0;
}
