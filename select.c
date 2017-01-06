#include<stdio.h>

int res[100000][15]={},dat[7]={},tmp[11]={},total=0,m_round=0,no;

void permu(int n)
{
    int i,j,all=0;
    if(n>m_round)
        {
            for(j=1;j<n;j++) all+=tmp[j];
            if(all==no)
            {
                res[total][0]=n-1;
                for(j=1;j<=n-1;j++) res[total][j]=tmp[j];
                total++;
            }
            return;
        }
    for(i=0;i<6;i++)
    {
        //if(use[i]==0||i==tmp[n-i])
        //{
        //    use[i]=1;
            tmp[n]=dat[i];
            permu(n+1);
        //    use[i]=0;
        //}
    }
}

int main()
{
    int i,j,m;
    scanf("%d %d",&no,&m);
    for(i=0;i<6;i++) scanf("%d",&dat[i]);
    for(i=1;i<=m;i++)
    {
        m_round=i;
        permu(1);
    }
    printf("%d\nE\n",total);
    for(i=0;i<total;i++)
    {
        printf("%d ",res[i][0]);
        for(j=1;j<=res[i][0];j++) printf("%d ",res[i][j]);
        printf("\nE\n");
    }
    return 0;
}
