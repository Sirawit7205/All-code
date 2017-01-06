#include<stdio.h>

int main()
{
    int i,j,a,b,c=0,f;
    char stra[1005]={},strb[1005]={};
    scanf("%d %d",&a,&b);
    scanf("%s",stra); scanf("%s",strb);
    for(i=0;i<=a-b;i++)
    {
        f=0;
        for(j=0;j<b;j++)
        {
            if(stra[i+j]!=strb[j]) {f=1; break;}
        }
        if(f==0) c++;
    }
    printf("%d",c);
    return 0;
}
