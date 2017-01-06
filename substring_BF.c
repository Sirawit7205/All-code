#include<stdio.h>
#include<string.h>

char a[300005]={};
int diff[30]={};

void chk(int len)
{
    int i,j,k,td[30]={},t=0;
    for(i=1;i<=len;i++)
    {
        for(j=0;j<=len-i;j++)
        {
            t=0;
            for(k=j;k<j+i;k++) td[a[k]-97]=1;
            for(k=0;k<30;k++) if(td[k]==1) {t++; td[k]=0;}
            diff[t]++;
        }
    }
}

int main()
{
    int i,len,td[30]={},c=0;
    scanf("%s",a);
    len=strlen(a);
    for(i=0;i<len;i++) td[a[i]-97]=1;
    for(i=0;i<30;i++) if(td[i]==1) c++;
    printf("%d\n",c);
    chk(len);
    for(i=1;i<=c;i++) printf("%d\n",diff[i]);
    return 0;
}
