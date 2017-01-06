#include<stdio.h>

int field[20][18]={0};

void bomb(int x, int y,int p)
{
    if(p>=1&&x>=0&&x<20&&y>=0&&y<18)
    {
        field[x][y]+=p;
        bomb(x-1,y,p-1);
        bomb(x+1,y,p-1);
        bomb(x,y-1,p-1);
        bomb(x,y+1,p-1);
    }
    else return;
}

int main()
{
    int x,y,p;
    int i,j;
    scanf("%d %d %d",&y,&x,&p);
    bomb(x,y,p);
    for(i=0;i<20;i++)
    {
        for(j=0;j<18;j++)
        {
            printf("%03X ",field[i][j]);
        }
        printf("\n");
    }
    return 0;
}
