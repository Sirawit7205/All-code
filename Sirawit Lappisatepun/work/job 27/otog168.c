#include<stdio.h>
#include<string.h>

char dat[1000010]={};
int alpha[30]={}, beta[26][27]={};

int main()
{
    int alp=0,bet=0;
    int i,j,len;
    scanf("%s",dat);
    len=strlen(dat);
    //printf("%s",dat);
    //printf("%d\n",len);
    for(i=0;i<len;i++)
    {
        if(dat[i+1]>=97)
            {
                beta[dat[i]-65][dat[i+1]-97]++;
                if(beta[dat[i]-65][dat[i+1]-97]==1) bet++;
                i++;
            }
        else
        {
            alpha[dat[i]-65]++;
            if(alpha[dat[i]-65]==1) alp++;
        }
    }
    printf("%d\n",alp);
    if(alp!=0)
    {
        for(i=0;i<26;i++)
        {
            if(alpha[i]!=0) printf("%c %d\n",65+i,alpha[i]);
        }
    }
    printf("%d\n",bet);
    if(bet!=0)
    {
        for(i=0;i<26;i++)
        {
            for(j=0;j<26;j++)
            {
                if(beta[i][j]!=0) printf("%c%c %d\n",65+i,97+j,beta[i][j]);
            }
        }
    }
    return 0;
}
