#include<stdio.h>
#include<string.h>

int len,amt;
char str[100][10],tmp[10];

void sort(int a)
{
    int i,j;
    if(a==len) return;
    for(i=0;i<amt-1;i++)
    {
        for(j=0;j<len;j++)
        {
            if(str[i][j]>str[i+1][j])
            {
                strcpy(tmp,str[i]);
                strcpy(str[i],str[i+1]);
                strcpy(str[i+1],tmp);
                break;
            }
        }
    }
    sort(a+1);
}

int main()
{
    int i;
    scanf("%d",&amt);
    getchar();
    for(i=0;i<amt;i++) gets(str[i]);
    printf("\n");
    for(len=0;str[0][len]!='\0';len++);
    sort(0);
    for(i=0;i<amt;i++)
    {
        puts(str[i]);
    }
    return 0;
}
