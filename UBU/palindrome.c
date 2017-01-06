#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char da[505]={},db[505]={};

int main()
{
    int n,i=0,j=0,k=0,l,c;
    scanf("%d ",&n);
    for(i=0;i<n;i++)
    {
        memset(db,0,k); k=0; c=0;
        gets(da);
        l=strlen(da);
        for(j=0;j<l;j++)
        {
            if(da[j]>=65&&da[j]<=90) {db[k]=da[j]+32; k++;}
            else if(da[j]>=97&&da[j]<=122) {db[k]=da[j]; k++;}
        }
        for(j=0;j<=(k/2)-1;j++)
        {
            if(db[j]!=db[k-j-1]) {c=1; break;}
        }
        if(c==0) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
