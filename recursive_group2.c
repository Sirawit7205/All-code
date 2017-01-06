#include<stdio.h>
#include<string.h>

char str[10],sto[10];
int amt,len;

void grp(int g,int pt)
{
    int i;
    if(g==amt)
    {
        printf("%s\n",sto);
        return;
    }
    else
    {
         for(i=pt;i<len;i++)
        {
            sto[g]=str[i]; grp(g+1,i+1);
        }
    }
}

int main()
{
    scanf("%s",str);
    scanf("%d",&amt);
    len=strlen(str);
    grp(0,0);
    return 0;
}
