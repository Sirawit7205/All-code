#include<stdio.h>

int main()
{
    char names[10][150]={},mid;
    int i,j,k,spc=0,amt,len,spc_p[5]={};
    scanf("%d",&amt);
    getchar();
    for(i=0;i<amt;i++)
    {gets(names[i]);}
    for(j=0;j<amt;j++)
    {
        spc=0;
        for(len=0;names[j][len]!='\0';len++);
        for(i=0;i<len;i++)
        {
            if(names[j][i]==' ')
            {spc_p[spc]=i; spc++;}
        }
        for(k=spc_p[spc-1]+1;k<len;k++)
            printf("%c",names[j][k]); printf(", ");
        for(k=0;k<spc_p[0];k++)
            printf("%c",names[j][k]); printf(" ");
        if(spc>1)
            for(k=0;k<spc-1;k++)
            printf("%c.",names[j][spc_p[k]+1]);
        printf("\n");
    }
    return 0;
}
