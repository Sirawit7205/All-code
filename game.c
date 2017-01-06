#include<stdio.h>

int main()
{
    char table[10][11]={{B,L,J,D,U,C,K,F,X,J},
                        {E,U,K,Y,E,Y,A,Z,T,H},
                        {E,L,T,H,F,K,F,T,U,C},
                        {C,Y,E,T,K,C,X,F,R,D},
                        {Y,H,J,P,E,Y,Z,E,T,O},
                        {F,F,I,S,H,R,H,Y,L,G},
                        {H,C,X,J,K,A,F,Z,E,X},
                        {J,Y,H,A,F,J,N,L,H,E},
                        {O,W,L,Z,J,K,C,T,Y,H}},search[10];
    int i,j,k,len,chk=0;
    gets(search);
    for(len=0;search[len]!='\0';len++);
    for(i=0;i<9;i++)
    {
        for(j=0;j<10;j++)
        {
            for(k=0;k<len&&k+len<10;k++)
            {
                if(search[k]!=table[i][j+k])
                {break;}
            }
            for(k=0;k<len&&k+len<9;k++)
            {
                if(search[k]!=table[i+k][j])
                {break;}
            }
            for(k=0;k<len&&k+len<)
            if(chk==len)
            {
                printf("Match found at %d %d",i,j);
                break;
            }
        }
        if(chk==len)
        {break;}
    }


}
