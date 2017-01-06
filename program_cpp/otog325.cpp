#include<cstdio>

int dp[20][260][260][3]={};
char dat[260]={};

int main()
{
    int i,j,k,l,len,pa,pb,pc,pd;
    for(i=0;i<20;i++)
    {
        scanf("%d",&len);
        scanf("%s",dat);
        for(j=1;j<=len;j++)
        {
            dp[i][j][j][dat[j-1]-48]=1;
        }
        for(j=2;j<=len;j++)
        {
            for(k=1;k<=len-j+1;k++)
            {
                pa=k; pb=k; pc=k+1; pd=j+k-1;
                for(l=pb;l<j+k-1;l++)
                {
                    if(dp[i][pa][pb][0]!=0&&dp[i][pc][pd][0]!=0) dp[i][k][j+k-1][2]=1;
                    if(dp[i][pa][pb][0]!=0&&dp[i][pc][pd][1]!=0) dp[i][k][j+k-1][1]=1;
                    if(dp[i][pa][pb][0]!=0&&dp[i][pc][pd][2]!=0) dp[i][k][j+k-1][0]=1;
                    if(dp[i][pa][pb][1]!=0&&dp[i][pc][pd][0]!=0) dp[i][k][j+k-1][2]=1;
                    if(dp[i][pa][pb][1]!=0&&dp[i][pc][pd][1]!=0) dp[i][k][j+k-1][1]=1;
                    if(dp[i][pa][pb][1]!=0&&dp[i][pc][pd][2]!=0) dp[i][k][j+k-1][1]=1;
                    if(dp[i][pa][pb][2]!=0&&dp[i][pc][pd][0]!=0) dp[i][k][j+k-1][1]=1;
                    if(dp[i][pa][pb][2]!=0&&dp[i][pc][pd][1]!=0) dp[i][k][j+k-1][2]=1;
                    if(dp[i][pa][pb][2]!=0&&dp[i][pc][pd][2]!=0) dp[i][k][j+k-1][1]=1;
                    pb++; pc++;
                }
            }
        }
        if(dp[i][1][len][0]==1) printf("yes\n"); else printf("no\n");
    }
    return 0;
}
