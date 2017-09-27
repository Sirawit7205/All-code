#include<stdio.h>

int lnklist[3][100005]={};

int main()
{
    int amt,i,cnt,chk=1,cur;

    scanf("%d",&amt);
    cnt=amt;
    for(i=1;i<=amt;i++)
    {
        scanf(" %c",&lnklist[0][i]);
        lnklist[1][i]=i+1;
        lnklist[2][i]=i-1;
    }

    lnklist[1][0]=1;
    lnklist[2][amt+1]=amt;
    cur=lnklist[1][0];

    while(chk==1)
    {
        chk=0;

        while(cur<amt&&cnt!=0)
        {
            if(lnklist[0][cur]==lnklist[0][lnklist[1][cur]])
            {
                chk=1;
                cnt-=2;
                lnklist[1][lnklist[2][cur]]=lnklist[1][lnklist[1][cur]];
                lnklist[2][lnklist[1][lnklist[1][cur]]]=lnklist[2][cur];
                cur=lnklist[2][cur];
                break;
            }
            else
            {
                cur=lnklist[1][cur];
            }
        }
    }
    printf("%d\n",cnt);
    if(cnt==0)
        printf("empty");
    else
    {
        cur=lnklist[2][amt+1];
        while(cur>0)
        {
            printf("%c",lnklist[0][cur]);
            cur=lnklist[2][cur];
        }
    }
    return 0;
}
