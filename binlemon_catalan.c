#include<stdio.h>
#include<math.h>

float fcatalan(float n)
{
    if(n==0) return 1;
    else return fmod(((2*((2*n)-1))/(n+1))*fcatalan(n-1),909091);
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%.0f",fmod(fcatalan(n),909091));
    return 0;
}
