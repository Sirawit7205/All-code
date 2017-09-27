#include<stdio.h>

int lnklist[2][100005]={};
char ans[100005]={};

int main()
{
    int amt,i,cnt,chk=1,last,cur;

    scanf("%d",&amt);
    cnt=amt;
    for(i=1;i<=amt;i++)
    {
        scanf(" %c",&lnklist[0][i]);
        lnklist[1][i]=i+1;
    }

    lnklist[1][0]=1;
    while(chk==1)
    {
        chk=0;
        last=0;
        cur=lnklist[1][0];
        while(cur<amt)
        {
            if(lnklist[0][cur]==lnklist[0][lnklist[1][cur]])
            {
                chk=1;
                cnt-=2;
                lnklist[1][last]=lnklist[1][lnklist[1][cur]];
                break;
            }
            else
            {
                last=cur;
                cur=lnklist[1][cur];
            }
        }
    }
    printf("%d\n",cnt);
    if(cnt==0)
        printf("empty");
    else
    {
        i=0;
        cur=lnklist[1][0];
        while(cur<=amt)
        {
            ans[i]=lnklist[0][cur];
            i++;
            cur=lnklist[1][cur];
        }
        for(i=cnt-1;i>=0;i--)
            printf("%c",ans[i]);
    }
    return 0;
}
