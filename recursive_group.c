#include<stdio.h>
#include<string.h>

char str[7],sto[7]={};
int len,amt;

void grp(int g)
{
    int i;
    if(g==amt)
    {
        printf("%s\n",sto);
        return;
    }
    else
    {
        for(i=0;i<len;i++)
        {
            sto[g]=str[i]; grp(g+1);
        }
    }
}

int main()
{
    scanf("%s",str);
    scanf("%d",&amt);
    len=strlen(str);
    grp(0);
    return 0;
}
