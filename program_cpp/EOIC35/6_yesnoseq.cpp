#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int chkt[2555][5]={};
char namea[2555][15]={},nameb[2555][15]={};

int main()
{
	int i,j,n,cntcr=0,cnttt=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
    {
        scanf("%s",namea[i]);
    }
    for(i=0;i<n;i++)
    {
        scanf("%s",nameb[i]);
    }
    for(i=0;i<n;i++)
    {
        chkt[i][0]=i;
        for(j=0;j<n;j++)
        {
            if(strcmp(namea[i],nameb[j])==0) {chkt[j][1]=i; break;}
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(chkt[i][1]<chkt[j][1]) cntcr++;
            cnttt++;
        }
    }
    printf("%d/%d",cntcr,cnttt);
	return 0;
}
