#include<stdio.h>
#include<string.h>

char dat[260]={},temp[5]={};
int cst1,cst3,key[5]={};

void enc(int i, int t)
{
    int c;
    c=key[0]+t;
    if(c<=10) t=c-1; else t=c-10;
    c=key[1]+t;
    if(c<=10) t=c-1; else t=c-10;
    c=key[2]+t;
    if(c<=10) t=c-1; else t=c-10;
    dat[i]=t;
    key[0]+=cst1; key[1]--; key[2]+=cst3;
    if(key[0]>9) key[0]-=9;
    if(key[1]==0) key[1]=9;
    if(key[2]>9) key[2]-=9;
    //printf("%d %d %d\n",key[0],key[1],key[2]);
    return;
}

int main()
{
    int i,len,t;
    scanf(" %s",temp);
    scanf(" %s",dat);
    len=strlen(dat);
    cst1=temp[0]-48; cst3=temp[2]-48;
    key[0]=temp[0]-48; key[1]=temp[1]-48; key[2]=temp[2]-48;
    for(i=0;i<len;i++)
    {
        t=dat[i]-48;
        enc(i,t);
    }
    for(i=0;i<len;i++) printf("%d",dat[i]);
    return 0;
}
