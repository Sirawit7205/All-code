#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int s,ap;
}an;

an dat[100]={};

int cmp(const void *a, const void *b)
{
    an *aa=(an*)a;
    an *bb=(an*)b;
    return(aa->s - bb->s);
}

int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d %d",&dat[i].s,&dat[i].ap);
    qsort(dat,n,sizeof(an),cmp);
    for(i=0;i<n;i++) printf("%d %d\n",dat[i].s,dat[i].ap);
    return 0;
}
