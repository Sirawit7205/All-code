#include<stdio.h>
#include<math.h>

int main()
{
    int i;
    float r,ans,a[11];
    for(i=0;i<10;i++)
    {
     scanf("%f",&r);
    ans=(M_PI*r*r)-(r*2*r*2/2);
    a[i]=ans;
    }
    for(i=0;i<10;i++)
    {
        printf("%.2f\n",a[i]);
    }
    return 0;
}
