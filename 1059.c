#include<stdio.h>

char typed[81],top=0;

void resolve(int btt,int amt)
{
    if(btt==1)
    {
        if(top<amt)
        {top=0;}
        else
        {top-=amt;}
    }
    else if(btt==2)
    {
        if(amt%3==1)
        {typed[top]='A';}
        else if(amt%3==2)
        {typed[top]='B';}
        else
        {typed[top]='C';}
        top++;
    }
    else if(btt==3)
    {
        if(amt%3==1)
        {typed[top]='D';}
        else if(amt%3==2)
        {typed[top]='E';}
        else
        {typed[top]='F';}
        top++;
    }
    else if(btt==4)
    {
        if(amt%3==1)
        {typed[top]='G';}
        else if(amt%3==2)
        {typed[top]='H';}
        else
        {typed[top]='I';}
        top++;
    }
    else if(btt==5)
    {
        if(amt%3==1)
        {typed[top]='J';}
        else if(amt%3==2)
        {typed[top]='K';}
        else
        {typed[top]='L';}
        top++;
    }
    else if(btt==6)
    {
        if(amt%3==1)
        {typed[top]='M';}
        else if(amt%3==2)
        {typed[top]='N';}
        else
        {typed[top]='O';}
        top++;
    }
    else if(btt==7)
    {
        if(amt%4==1)
        {typed[top]='P';}
        else if(amt%4==2)
        {typed[top]='Q';}
        else if(amt%4==3)
        {typed[top]='R';}
        else
        {typed[top]='S';}
        top++;
    }
    else if(btt==8)
    {
        if(amt%3==1)
        {typed[top]='T';}
        else if(amt%3==2)
        {typed[top]='U';}
        else
        {typed[top]='V';}
        top++;
    }
    else if(btt==9)
    {
        if(amt%4==1)
        {typed[top]='W';}
        else if(amt%4==2)
        {typed[top]='X';}
        else if(amt%4==3)
        {typed[top]='Y';}
        else
        {typed[top]='Z';}
        top++;
    }
}

int main()
{
    int i,amt,thumb[81][4],f[3],tmp;
    scanf("%d",&amt);
    scanf("%d %d",&f[0],&f[1]);
    for(i=0;i<amt-1;i++)
    {scanf("%d %d %d",&thumb[i][0],&thumb[i][1],&thumb[i][2]);}
    resolve(f[0],f[1]);
    for(i=0;i<amt-1;i++)
    {
        tmp=f[0]+thumb[i][0]+(thumb[i][1]*3);
        resolve(tmp,thumb[i][2]);
        f[0]=tmp;
    }
    if(top==0)
    {printf("null");}
    else
    {
        for(i=0;i<top;i++)
        {printf("%c",typed[i]);}
    }
    return 0;
}
