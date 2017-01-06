#include<stdio.h>

int a=1,dat[300005]={};

void chk(int m, int b)
{
    int t,f=0;
    if(m==1)
    {
        if(b==1) return;
        if(dat[b]>dat[b/2])
        {
            t=dat[b];
            dat[b]=dat[b/2];
            dat[b/2]=t;
            chk(1,b/2);
        }
        else return;
    }
    else
    {
        if(b*2>=a) return;
        if((b*2)+1>=a) f=1;
        if(f==0){
        if(dat[b]>dat[b*2]&&dat[b]>dat[(b*2)+1]) return;
        else if(dat[b]<dat[b*2]&&dat[b]<dat[(b*2)+1])
        {
            if(dat[b*2]>=dat[(b*2)+1])
            {
                t=dat[b];
                dat[b]=dat[b*2];
                dat[b*2]=t;
                chk(2,b*2);
            }
            else
            {
                t=dat[b];
                dat[b]=dat[(b*2)+1];
                dat[(b*2)+1]=t;
                chk(2,(b*2)+1);
            }
        }
        else if(dat[b]<dat[b*2]&&dat[b]>=dat[(b*2)+1])
        {
            t=dat[b];
            dat[b]=dat[b*2];
            dat[b*2]=t;
            chk(2,b*2);
        }
        else if(dat[b]>=dat[b*2]&&dat[b]<dat[(b*2)+1])
        {
            t=dat[b];
            dat[b]=dat[(b*2)+1];
            dat[(b*2)+1]=t;
            chk(2,(b*2)+1);
        }
    }
    else
    {
        if(dat[b]<dat[b*2])
        {
            t=dat[b];
            dat[b]=dat[b*2];
            dat[b*2]=t;
        }
    }
    }
}

void add(int b)
{
    dat[a]=b;
    if(a!=1) chk(1,a);
    a++;
}

int rem()
{
    int t;
    if(a==1) return -1;
    else
    {
        t=dat[1];
        dat[1]=dat[a-1];
        a--;
        chk(2,1);
        return t;
    }
}

int main()
{
    int i,n,b;
    char mode,drp;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%c%c",&drp,&mode);
        if(mode=='P')
        {
            scanf("%d",&b);
            add(b);
        }
        else printf("%d\n",rem());
    }
    return 0;
}
