#include<stdio.h>
#include<math.h>

int main()
{
    int i,n,mode,lvl=0;
    double r,time=0,t;
    scanf("%d %lf",&n,&r);
    for(i=0;i<n;i++)
    {
        scanf("%d %lf",&mode,&t);
        if(mode==0)
        {
            lvl++;
            time+=t/(pow(r,lvl));
        }
        else
        {
            lvl--;
            time+=t/(pow(r,lvl));
        }
    }
    printf("%f",time);
    return 0;
}
