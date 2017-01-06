#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void * a, const void * b)
{
    int *A=(int *)a;
    int *B=(int *)b;
    if(*A<*B) return 1;
    else return -1;
}

int chkmax()
{
    char dat[501]={};
    int t=0,i,l,c[27]={};
    scanf("%s",dat); l=strlen(dat);
    for(i=0;i<l;i++)
    {
        if(dat[i]>=65&&dat[i]<=90) c[dat[i]-65]++;
        else c[dat[i]-97]++;
    }
    qsort(c,26,sizeof(int),cmp);
    for(i=0;i<26;i++)
    {
        if(c[i]==0) break;
        else t+=(26-i)*c[i];
    }
    return t;
}

int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++) printf("%d\n",chkmax());
    return 0;
}
