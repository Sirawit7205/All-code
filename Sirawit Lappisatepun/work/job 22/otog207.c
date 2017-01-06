#include<stdio.h>

int data[1100]={};

int chk(int a,int b)
{
    int ans=0,i;
    for(i=a;i<=b;i++) ans+=data[i-1];
    return ans;
}

int main()
{
    int i,j,n,q,ab[1100][3]={};
    scanf("%d %d",&n,&q);
    for(i=0;i<n;i++) scanf("%d",&data[i]);
    for(i=0;i<q;i++) scanf("%d %d",&ab[i][0],&ab[i][1]);
    for(i=0;i<q;i++) printf("%d\n",chk(ab[i][0],ab[i][1]));
    return 0;
}
