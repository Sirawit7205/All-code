#include<stdio.h>

long long int qword[1000001]={};
int raw[1000001]={},n;

void qsum(int str)
{
    if(str>n) return;
    if(str==0) qword[0]=0;
    else
    {
        qword[str]=qword[str-1]+raw[str-1];
    }
    qsum(str+1);
}

int main()
{
    int i,q,f,t;
    scanf("%d %d",&n,&q);
    for(i=0;i<n;i++) scanf("%d",&raw[i]);
    qsum(0);
    for(i=0;i<q;i++)
    {
        scanf("%d %d",&f,&t);
        printf("%lld\n",qword[t]-qword[f-1]);
    }
    //for(i=0;i<=n;i++) printf("%lld\n",qword[i]);
    return 0;
}
