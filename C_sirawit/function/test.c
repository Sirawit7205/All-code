#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int len;
    char A[100]={},t[100]={};
    scanf("%s",A);
    len=strlen(A);
    itoa(len,t,10);
    strcat(t,A);
    strcpy(A,t);
    printf("%s",A);
    return 0;
}
