#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int rev(int num)
{
    int a;
    char n[10]={};
    sprintf(n,"%d",num);
    strrev(n);
    a=atoi(n);
    return a;
}

int chkp(int num)
{
    int len,i;
    char n[10]={};
    sprintf(n,"%d",num);
    len=strlen(n);
    for(i=0;i<len/2;i++)
    {
        if(n[i]!=n[len-i-1]) return 1;
    }
    return 0;
}

int main()
{
    int i,c=0,j,in,chk=0,ans[1000]={},pal[1000]={};
    do
    {
        scanf("%d",&in);
        if(in==0) break;
        c++;
        chk=chkp(in);
        if(chk==0)  {pal[c-1]=in; continue;}
        else
        {
            for(j=0;j<10;j++)
            {
                in=in+rev(in);
                chk=chkp(in);
                if(chk==0) break;
            }
            if(j!=10) ans[c-1]=j+1;
            else ans[c-1]=10;
        }
        pal[c-1]=in;
    } while(in!=0);
    for(i=0;i<c;i++)
    {
        if(ans[i]==10) printf("Ohgodwhy!\n");
        else printf("%d %d\n",ans[i],pal[i]);
    }
    return 0;
}

