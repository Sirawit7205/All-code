#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char dat[1001][31]={};

int cmp(const void *a, const void *b)
{
    char *A=(char *)a;
    char *B=(char *)b;
    return strcmp(A,B);
}

int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%s",dat[i]);
    qsort(dat,n,sizeof(dat[0]),cmp);
    for(i=0;i<n;i++)
    {
        if(i==0) printf("%s\n",dat[i]);
        else if(strcmp(dat[i],dat[i-1])==0) continue;
        else printf("%s\n",dat[i]);
    }
    return 0;
}
