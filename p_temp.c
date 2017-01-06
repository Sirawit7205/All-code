#include<stdio.h>
int d[100005]={};
#include<stdlib.h>

int cmp(const void *a, const void *b) {return (*(int*)a-*(int*)b);}
int main()
{
    int c=0,j,i,a,b,x,y;
    scanf("%d %d",&a,&b);
    for(i=0;i<a;i++) scanf("%d",&d[i]);
    qsort(d,a,sizeof(int),cmp);
    for(i=0;i<b;i++)
    {
        c=0;
        scanf("%d %d",&x,&y);
        for(j=0;j<a;j++)
        {
            if(d[j]>=x&&d[j]<=y) c++;
            if(d[j]>y) break;
        }
        printf("%d\n",c);
    }
    return 0;
}
