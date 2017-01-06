#include<stdio.h>

int main()
{
    int num,p,i,ans[8][3];
    for(i=0;i<7;i++){
    scanf("%d %d",&p,&num);
    ans[i][0]=num/p; ans[i][1]=num-((num/p)*p);
}
for(i=0;i<7;i++)
    printf("%d %d\n",ans[i][0],ans[i][1]);
    return 0;
}
