#include<cstdio>
#include<cstring>

char num[10005]={};
int len,m,tmp=0;

int main()
{
    int i;
    scanf("%s %d",num,&m);
    len=strlen(num);
    for(i=0;i<len;i++)
    {
        tmp*=10; tmp+=num[i]-48;
        if(tmp>=m) tmp-=(tmp/m)*m;
    }
    printf("%d",tmp);
    return 0;
}
