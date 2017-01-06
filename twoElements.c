#include<stdio.h>
#include<math.h>

int len,min[100]={},num[100]={},no;

int plus(int a,int sum)
{
    int i,j,k,l,tmp;
    if(a>5) return;
    for(k=0;k<len;k++)
    {
        for(i=0;i<len-a;i++)
        {
            tmp=abs(num[i]);
            for(j=0;j<a;j++)
            {
                if(j+1==i) {break;}
                else {tmp+=abs(num[j+1]);}
            }
            if(abs(tmp)<sum)
            {
                sum=tmp;
                for(l=0;l<=a;l++) {min[l]=num[i+l];}
                no=a+1;
            }
        }
    }
    plus(a+1,sum);
}

int main()
{
    int i,ans;
    scanf("%d",&len);
    for(i=0;i<len;i++) scanf("%d",&num[i]);
    ans=plus(1,9999);
    for(i=0;i<no;i++) {printf("%d ",min[i]);}
    return 0;
}
