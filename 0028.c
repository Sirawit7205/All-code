#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int n,scr,con,ab;
}data;

data a[5];

int cmp(const void *a,const void *b)
{
    const data *aa=(data *)a;
    const data *bb=(data *)b;
    if(aa->scr < bb->scr) return 1;
    else if(aa->scr == bb->scr && aa->con < bb->con) return 1;
    else if(aa-> scr == bb->scr && aa->con == bb->con && aa->ab < bb->ab) return 1;
    else return -1;
}

int main()
{
    char name[5][30]={};
    int i,j,t[5][5]={};
    for(i=1;i<=4;i++) scanf("%s",name[i]);
    for(i=1;i<=4;i++)
    {
        for(j=1;j<=4;j++)
        {
            scanf("%d",&t[i][j]);
        }
    }
    for(i=1;i<=4;i++)
    {
        a[i-1].n=i;
        for(j=1;j<=4;j++)
        {
            if(i==j) continue;
            else
            {
                a[i-1].ab+=t[i][j];
                a[i-1].con+=t[i][j]-t[j][i];
                if(t[i][j]>t[j][i]) a[i-1].scr+=3;
                else if(t[i][j]==t[j][i]) a[i-1].scr+=1;
            }
        }
    }
    qsort(a,4,sizeof(data),cmp);
    for(i=0;i<4;i++) printf("%s %d\n",name[a[i].n],a[i].scr);
    return 0;
}
