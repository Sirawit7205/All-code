#include<stdio.h>

int main()
{
    int a,c,t,i;
    float b,to=0;
    scanf("%d %f %d",&a,&b,&c);
    to=to+(a*2500)+(b*300)+(c*1000);
    for(i=0;i<c;i++)
    {
        scanf("%d",&t);
        if(t>10) to+=(t-10)*100;
    }
    if(to>10000) to-=to/10;
    printf("%.2f",to);
    return 0;
}
