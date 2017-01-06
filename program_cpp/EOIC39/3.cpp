#include<cstdio>
#include<cstring>

char dat[500]={};

int main()
{
    int i,j,l,q,up,lw,scr;
    scanf("%d ",&q);
    for(i=0;i<q;i++)
    {
        gets(dat);
        l=strlen(dat);
        up=0; lw=0; scr=0;
        for(j=0;j<=l;j++)
        {
            if(dat[j]>='A'&&dat[j]<='Z') up=1;
            else if(dat[j]>='a'&&dat[j]<='z') lw=1;
            else if(dat[j]==' '&&dat[j+1]==' ') continue;
            else
            {
                if(up==1&&lw==0) scr+=1;
                else if(up==0&&lw==1) scr+=2;
                else if(up==1&&lw==1) scr+=3;
                up=0; lw=0;
            }
        }
        printf("%d\n",scr);
    }
    return 0;
}
