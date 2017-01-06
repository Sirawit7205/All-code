#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

char str[100001]={},w[21][2]={};

int main()
{
    int i,j,len,x,ma=0,c[100001]={};
    scanf("%s",str);
    len=strlen(str);
    scanf("%d",&x);
    for(i=0;i<x;i++) scanf("%s",w[i]);
    for(i=0;i<len-1;i++)
    {
        for(j=0;j<x;j++)
        {
            if((str[i]==w[j][0]&&str[i+1]==w[j][1])||(str[i]==w[j][1]&&str[i+1]==w[j][0])) {c[i]++; c[i+1]++; break;}
        }
    }
    for(i=0;i<len;i++) if(c[i]>ma) ma=c[i];
    printf("%d",ma);
    return 0;
}
