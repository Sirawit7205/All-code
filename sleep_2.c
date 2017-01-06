#include<stdio.h>

int t[1000005]={};

int main()
{
    int a,b,i,j,ta,tb,c=0,ch=0;
    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        c=0; ch=0;
        scanf("%d",&b);
        for(j=0;j<b;j++) {scanf("%d %d",&ta,&tb); t[ta]++; t[tb+1]--;}
        for(j=1;j<=1000000;j++)
        {c+=t[j]; t[j]=0; if(c==b) {ch=1; break;}}
        if(ch==1) printf("no\n"); else printf("yes\n");
    }
    return 0;
}
