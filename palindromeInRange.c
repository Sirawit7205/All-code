#include<stdio.h>
#include<string.h>

int min,max;
char str[5];

void chk(int m)
{
    int i,len,check;
    if(m>max) return;
    sprintf(str, "%d", m);
    len=strlen(str);
    check=0;
    for(i=0;i<len/2;i++)
    {
        if(str[i]!=str[len-i-1])
        {check=0; break;}
        else
        {check=1;}
    }
    if(check==1||len==1)
    {printf("%d ",m);}
    chk(m+1);
}

int main()
{
    scanf("%d",&min);
    scanf("%d",&max);
    chk(min);
    return 0;
}
