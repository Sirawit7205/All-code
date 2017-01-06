#include<stdio.h>

int main()
{
    int amt,i,j,tmp,tmp2,pos[101][101]={},con[101]={},col[101]={};
    scanf("%d",&amt);
    for(i=1;i<=amt;i++)
    {
        scanf("%d",&tmp);
        if(tmp==0&&tmp2==0) break;
        if(tmp==0) {tmp2=tmp; continue;}
        pos[i][con[i]]=tmp; con[i]++;
        pos[tmp][con[tmp]]=i; con[tmp]++;
        tmp2=1; i--;
    }
    for(i=1;i<=amt;i++)
    {
        if(i==1) col[i]=1;
        for(j=0;j<con[i];j++)
        {
            if(col[pos[i][j]]!=0)
            {
                if(col[pos[i][j]]==col[i])
                {printf("no"); return 0;}
            }
            else
            {
                if(col[i]==1) col[pos[i][j]]=2;
                else if(col[i]==2) col[pos[i][j]]=1;
            }
        }
    }
    printf("yes");
    return 0;
}
