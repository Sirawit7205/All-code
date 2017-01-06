#include<stdio.h>
#include<string.h>

char enc[500]={},t[20]={},drp,prt[31]={};
int c=0;

int conv()
{
    return (t[0]*1)+(t[1]*2)+(t[2]*4)+(t[3]*8)+(t[4]*16)+(t[5]*32)+(t[6]*64)+(t[7]*128);
}

int rev(int pos,int mode,int set)
{
    int ans;
    if(set==8) {ans=conv(); prt[c]=ans; c++; return mode;}
    if(mode==1)
    {
        t[set]=0;
        if(enc[pos-1]=='0'&&enc[pos]=='0') rev(pos-2,1,set+1);
        else rev(pos-2,3,set+1);
    }
    else if(mode==3)
    {
        t[set]=0;
        if(enc[pos-1]=='0'&&enc[pos]=='1') rev(pos-2,4,set+1);
        else rev(pos-2,2,set+1);
    }
    else if(mode==2)
    {
        t[set]=1;
        if(enc[pos-1]=='0'&&enc[pos]=='0') rev(pos-2,3,set+1);
        else rev(pos-2,1,set+1);
    }
    else
    {
        t[set]=1;
        if(enc[pos-1]=='0'&&enc[pos]=='1') rev(pos-2,2,set+1);
        else rev(pos-2,4,set+1);
    }
}

int main()
{
    int i,n,len,end,pos;
    scanf("%d%c",&n,&drp);
    for(i=0;i<n;i++)
    {
        scanf("%s",t);
        strcat(enc,t);
    }
    len=strlen(enc); i=0;
    if(enc[len-4]=='1'&&enc[len-3]=='0'&&enc[len-2]=='1'&&enc[len-1]=='1'&&len%16==4) {end=2; pos=len-5;}
    else if(enc[len-4]=='0'&&enc[len-3]=='1'&&enc[len-2]=='1'&&enc[len-1]=='1'&&len%16==4) {end=4; pos=len-5;}
    else if(enc[len-2]=='1'&&enc[len-1]=='1'&&len%16==2) {end=3; pos=len-3;}
    else {end=1; pos=len-1;}
    for(i=0;i<len/16;i++)
    {
        end=rev(pos-(i*16),end,0);
    }
    for(i=c-1;i>=0;i--) printf("%c",prt[i]);
    return 0;
}
