#include<stdio.h>
#include<stdlib.h>

int temp[100005]={},dat[100005][3]={};

int cmp(const void *a, const void *b) {return (*(int *)a-*(int *)b);}

int main()
{
    int n,m,j=0,pa,pb,mid,ta,tb,x,y,i,k,sum;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++) scanf("%d",&temp[i]);
    qsort(temp,n,sizeof(int),cmp);
    for(i=0;i<n;i++) {if(dat[j][0]!=temp[i]) {j++; dat[j][0]=temp[i]; dat[j][1]++;} else dat[j][1]++;}
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&pa,&pb); ta=1; tb=j; x=0;
        mid=(ta+tb)/2;
        while(ta<=tb)
        {
            if(dat[mid][0]==pa) {x=mid; break;}
            else if(dat[mid][0]>pa) tb=mid-1;
            else if(dat[mid][0]<pa) ta=mid+1;
            mid=(ta+tb)/2;
        }
        if(x==0) x=mid; if(dat[x][0]<pa) x++; if(dat[j][0]<x) x=j+1;
        mid=(ta+tb)/2; ta=1; tb=j; y=0;
        while(ta<=tb)
        {
            if(dat[mid][0]==pb) {y=mid; break;}
            else if(dat[mid][0]>pb) tb=mid-1;
            else if(dat[mid][0]<pb) ta=mid+1;
            mid=(ta+tb)/2;
        }
        if(y==0) y=mid; sum=0;
        //printf("%d %d\n",x,y);
        for(k=x;k<=y;k++) sum+=dat[k][1];
        printf("%d\n",sum);
    }
    return 0;
}
