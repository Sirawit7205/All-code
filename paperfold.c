#include<stdio.h>
#include<math.h>

int main()
{
    int i,x;
    double s=0,base=1;
    scanf("%d",&x);
    for(i=0;i<x;i++) {s+=base; base*=2;}
    printf("%.0f",s);
    return 0;
}
