#include<stdio.h>
#include<string.h>

int vote[10]={};

int datain()
{
    char dat[10001]={};
    int i,len;
    gets(dat);
    len=strlen(dat);
    if(dat[0]=='!') return 1;
    for(i=0;i<len;i++)
    {
        if(dat[i]=='A') vote[0]++;
        else if(dat[i]=='B') vote[1]++;
        else if(dat[i]=='C') vote[2]++;
        else if(dat[i]=='D') vote[3]++;
        else if(dat[i]=='E') vote[4]++;
        else if(dat[i]=='F') vote[5]++;
        else if(dat[i]=='G') vote[6]++;
    }
    return 0;
}

int main()
{

    int i,j=0,rem[10]={},c=0,min=30001,cnt=0,left=7,max=-1;
    do
    {
        c=datain();
        if(c==1) break;
        for(i=0;i<7;i++)
        {
            if(rem[i]==1) continue;
            if(vote[i]<min) {min=vote[i]; cnt=i;}
            else if(vote[i]==min) {cnt=-1;}
        }
        if(left==1||cnt==-1) {cnt=0; min=30001; continue;}
        else
        {
            left--;
            rem[cnt]=1;
        }
        cnt=0; min=30001;
    }
    while(c==0);
    printf("%d\n",left);
    /*for(i=0;i<7;i++) printf("%d ",vote[i]);
    printf("\n");
    for(i=0;i<7;i++) printf("%d ",rem[i]);
    printf("\n");*/
    for(i=0;i<left;i++)
    {
        for(j=0;j<7;j++)
        {
            if(rem[j]==1) {continue;}
            else if(vote[j]>max) {max=vote[j]; cnt=j;}
        }
        printf("%c %d\n",cnt+65,vote[cnt]);
        rem[cnt]=1; max=-1; cnt=0;
    }
    return 0;
}
