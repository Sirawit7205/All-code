#include<stdio.h>

int main()
{
    char str[100];
    int i,len,chk=0;
    gets(str);
    for(len=0;str[len]!='\0';len++);
    for(i=0;i<len/2;i++)
    {
        if(str[i]!=str[len-i-1])
        {printf("Not Palindrome"); break;}
        else
        {chk=1;}
    }
    if(chk==1||len==1)
    {printf("Palindrome");}
    return 0;
}
