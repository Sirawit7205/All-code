#include<stdio.h>

main(){
    int a[6],sum[8]={},i,j;

    for(i=0;i<8;i++)
    {
        scanf("%d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4]);
        for(j=0;j<5;j++)
        {
            if(a[j]>0) sum[i]+=a[j];
        }
    }
    for(i=0;i<8;i++) printf("%d\n",sum[i]);
    return 0;
}
