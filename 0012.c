#include<stdio.h>

char raw[16]={};

void l_one(int len)
{
    int i,c=1;
    for(i=0;i<(len*2)+1;i++)
    {
        if(i%2==0) if(i==0||i==len*2) printf(".."); else printf("...");
        else {if(c%3==0) printf("*"); else printf("#"); c++;}
    }
    c=1; printf("\n");
}

void l_two(int len)
{
    int i;
    for(i=1;i<=len;i++) if(i%3==0) printf(".*.*"); else printf(".#.#");
    printf(".\n");
}

int main()
{
    int i,len=0;
    scanf("%s",raw);
    while(raw[len]!='\0') len++;
    l_one(len);
    l_two(len);
    for(i=1;i<=len;i++)
    {
        if(i%3==0||(i%3==1&&i!=1)) printf("*.%c.",raw[i-1]); else printf("#.%c.",raw[i-1]);
    }
    if((i-1)%3==0) printf("*\n"); else printf("#\n");
    l_two(len);
    l_one(len);
    return 0;
}
