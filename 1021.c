#include<stdio.h>

int dat[300005]={},chk=1;

void down(int chk1)
{
    int temp;
    if(dat[chk1]==-1) return;
    if(dat[chk1*2]>dat[(chk1*2)+1]&&dat[chk1]<dat[chk1*2])
    {
        temp=dat[chk1];
        dat[chk1]=dat[chk1*2];
        dat[chk1*2]=temp;
        down(chk1*2);
    }
    else if(dat[chk1*2]<=dat[(chk1*2)+1]&&dat[chk1]<dat[(chk1*2)+1])
    {
        temp=dat[chk1];
        dat[chk1]=dat[(chk1*2)+1];
        dat[(chk1*2)+1]=temp;
        down((chk1*2)+1);
    }
    else return;
}

void up(int chk1)
{
    int temp;
    if(chk1!=1)
        {
            if(dat[chk1]>dat[chk1/2])
            {
                temp=dat[chk1];
                dat[chk1]=dat[chk1/2];
                dat[chk1/2]=temp;
                up(chk1/2);
            }
        }
    else return;
}

int main()
{
    int i,amt,t;
    char key,drp;
    dat[1]=-1;
    scanf("%d%c",&amt,&drp);
    for(i=0;i<amt;i++)
    {
        key=getchar();
        if(key=='P')
        {
            scanf("%d%c",&t,&drp);
            dat[chk]=t;
            up(chk);
            chk++;
        }
        else
        {
            drp=getchar();
            if(dat[1]==-1) printf("-1\n");
            else
            {
                printf("%d\n",dat[1]);
                dat[1]=dat[chk-1];
                dat[chk-1]=-1;
                down(1);
                chk--;
            }
        }
    }
    return 0;
}
