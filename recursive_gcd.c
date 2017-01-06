#include<stdio.h>

int num1,num2,ans=1,i=2;

int gcd(int a,int b)
{
    if(a==1||b==1||a<i||b<i) return ans;
    if(a%i==0&&b%i==0) {a=a/i; b=b/i; ans*=i; i++; gcd(a,b);}
    else {i++; gcd(a,b);}
}

int main()
{
    scanf("%d %d",&num1,&num2);
    ans=gcd(num1,num2);
    printf("%d",ans);
    return 0;
}
