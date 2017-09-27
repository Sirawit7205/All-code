#include<stdio.h>
#include<string.h>

int main()
{
    int n, i, len;
    char text[10][1005]={}, temp;

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",text[i]);
        len = strlen(text[i]);
        temp = text[i][len-1];

        if((len==1&&text[i][0]=='2')||temp%2==1)
            printf("T\n");
        else
            printf("F\n");
    }
    return 0;
}
