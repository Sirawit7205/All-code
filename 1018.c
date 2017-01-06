#include<stdio.h>

int main()
{
    int i,amt,len,d[5]={0,0,0,1},x=0,y=0;
    char cmd[3]={};
    scanf("%d",&amt);
    for(i=0;i<amt;i++)
    {
        scanf(" %s %d",cmd,&len);
        if(cmd[0]=='R'&&cmd[1]=='T')
        {
            if(d[0]==1) {d[0]=0; d[3]=1;}
            else if(d[1]==1) {d[1]=0; d[2]=1;}
            else if(d[2]==1) {d[2]=0; d[0]=1;}
            else if(d[3]==1) {d[3]=0; d[1]=1;}
        }
        else if(cmd[0]=='L'&&cmd[1]=='T')
        {
            if(d[0]==1) {d[0]=0; d[2]=1;}
            else if(d[1]==1) {d[1]=0; d[3]=1;}
            else if(d[2]==1) {d[2]=0; d[1]=1;}
            else if(d[3]==1) {d[3]=0; d[0]=1;}
        }
        else if(cmd[0]=='B'&&cmd[1]=='W')
        {
            if(d[0]==1) {d[0]=0; d[1]=1;}
            else if(d[1]==1) {d[1]=0; d[0]=1;}
            else if(d[2]==1) {d[2]=0; d[3]=1;}
            else if(d[3]==1) {d[3]=0; d[2]=1;}
        }
        if(d[0]==1) y+=len;
        else if(d[1]==1) y-=len;
        else if(d[2]==1) x-=len;
        else if(d[3]==1) x+=len;
      if(x<=-50000||x>=50000||y<=-50000||y>=50000)
      {
        printf("DEAD");
        return 0;
      }
    }
    printf("%d %d\n",x,y);
    if(d[0]==1) printf("N");
    else if(d[1]==1) printf("S");
    else if(d[2]==1) printf("W");
    else if(d[3]==1) printf("E");
    return 0;
}
