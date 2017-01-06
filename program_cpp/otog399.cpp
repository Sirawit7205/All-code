#include<cstdio>

int str[1000005][2]={},cnt=0;

int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        if(n-(i*5)>0)
        {
            if((n-(i*5))%2==0)
            {
                str[cnt][0]=i;
                str[cnt][1]=(n-(i*5))/2;
                cnt++;
            }
        }
        else break;
    }
    printf("%d\n",cnt);
    for(i=0;i<cnt;i++) printf("%d %d\n",str[i][0],str[i][1]);
    return 0;
}
