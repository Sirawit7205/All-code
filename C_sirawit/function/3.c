#include<stdio.h>
#include<string.h>

int chk(char num[100])
{
    char ans;
    int len;
    len=strlen(num);
    ans=num[len-1];
    return ans;
}

int main()
{
    char num[100]={};
    printf("Enter number: "); gets(num);
    printf("The first digit is %c",chk(num));
    return 0;
}
