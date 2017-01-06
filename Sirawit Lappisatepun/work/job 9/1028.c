#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>

int assig(int i); //function prototype
int disp(int i);
int cal(char annt,int i);

char dat[SHRT_MAX][10]={}; //command line data
int var[27]={}; //TOI language's variables

int main()
{
    int len=0,i;
    do{
    gets(dat[len]);
    len++;
    if(dat[len-1][0]=='!') break;
    }while(1);
    for(i=0;i<len;i++)
    {
        if(dat[i][0]=='=') assig(i);
        else if(dat[i][0]=='#') disp(i);
        else if(dat[i][0]=='!') { printf("!"); break;}
        else cal(dat[i][0],i);
    }
    return 0;
}

int assig(int i)
{
    char temp[6]={};
    int t,j;
    for(j=4;j<=9;j++) if(dat[i][j]!='\0') temp[j-4]=dat[i][j];
    t=atoi(temp);
    if(dat[i][4]!='\0')var[dat[i][2]-65]=t;
    return 0;
}

int disp(int i)
{
    printf("%d\n",var[dat[i][2]-65]);
    return 0;
}

int cal(char annt,int i)
{
    if(annt=='+') var[dat[i][2]-65]+=var[dat[i][4]-65];
    else if(annt=='-') var[dat[i][2]-65]-=var[dat[i][4]-65];
    else if(annt=='*') var[dat[i][2]-65]*=var[dat[i][4]-65];
    else if(annt=='/') var[dat[i][2]-65]/=var[dat[i][4]-65];
    return 0;
}
