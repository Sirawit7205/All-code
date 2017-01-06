#include<stdio.h>
#include<math.h>
int main()
{
    int c=1,l,A[6][6],B[6][6],C[6][6];
    double b=0,p=0,m=0;
    scanf("%d",&l);
    while(c<=pow(l,2)*2)
    {
        scanf("%lf %lf %lf",&b,&p,&m);
        b=fmod(b,m);
        l=fmod(pow(b,p),m);
        printf("%d",l);
    }

}
