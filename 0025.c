#include<stdio.h>
#include<string.h>

int main()
{
    char m,a[101]={},b[101]={};
    int i,la,lb,lm,lmt;
    scanf("%s",a); la=strlen(a);
    scanf("%s",&m);
    scanf("%s",b); lb=strlen(b);
    if(la>lb||la==lb) {lm=la; lmt=lb;} else if(la<lb) {lm=lb; lmt=la;}
    if(m=='*')
    {
        printf("1");
        for(i=0;i<la+lb-2;i++) printf("0");
    }
    else
    {
        if(la==lb) printf("2"); else printf("1");
        for(i=lm-1;i>0;i--)
        {
            if(i==lmt) printf("1"); else printf("0");
        }
    }
    return 0;
}
