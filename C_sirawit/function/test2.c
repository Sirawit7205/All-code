#include<stdio.h>

int main()
{
    int i,A[11]={},B[11]={},C[21]={},a=0,b=0;
    for(i=0;i<10;i++) scanf("%d",&A[i]);
    for(i=0;i<10;i++) scanf("%d",&B[i]);
    for(i=0;i<20;i++)
    {
        if(A[a]==0&&i==19) C[i]=B[b];
        else if(B[b]==0&&i==19) C[i]=A[a];
        else if(A[a]<B[b]) {C[i]=A[a]; a++;}
        else {C[i]=B[b]; b++;}
    }
    for(i=0;i<20;i++) printf("%d ",C[i]);
    return 0;
}
