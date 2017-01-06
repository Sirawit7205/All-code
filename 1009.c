#include<stdio.h>
#include<string.h>

unsigned int res=0,temp=0;
char num1[50]={},num2[50]={},num3[50]={},t;

int cal(int len1)
{
    int i,j;
    for(i=0;i<len1;i++)
    {
        if(num1[0+(i*3)+i]==' '&&num1[1+(i*3)+i]==' '&&num1[2+(i*3)+i]==' '&&num2[0+(i*3)+i]==' '&&num2[1+(i*3)+i]==' '&&num2[2+(i*3)+i]=='|'&&num3[0+(i*3)+i]==' '&&num3[1+(i*3)+i]==' '&&num3[2+(i*3)+i]=='|') temp=1;
        else if(num1[0+(i*3)+i]==' '&&num1[1+(i*3)+i]=='_'&&num1[2+(i*3)+i]==' '&&num2[0+(i*3)+i]==' '&&num2[1+(i*3)+i]=='_'&&num2[2+(i*3)+i]=='|'&&num3[0+(i*3)+i]=='|'&&num3[1+(i*3)+i]=='_'&&num3[2+(i*3)+i]==' ') temp=2;
        else if(num1[0+(i*3)+i]==' '&&num1[1+(i*3)+i]=='_'&&num1[2+(i*3)+i]==' '&&num2[0+(i*3)+i]==' '&&num2[1+(i*3)+i]=='_'&&num2[2+(i*3)+i]=='|'&&num3[0+(i*3)+i]==' '&&num3[1+(i*3)+i]=='_'&&num3[2+(i*3)+i]=='|') temp=3;
        else if(num1[0+(i*3)+i]==' '&&num1[1+(i*3)+i]==' '&&num1[2+(i*3)+i]==' '&&num2[0+(i*3)+i]=='|'&&num2[1+(i*3)+i]=='_'&&num2[2+(i*3)+i]=='|'&&num3[0+(i*3)+i]==' '&&num3[1+(i*3)+i]==' '&&num3[2+(i*3)+i]=='|') temp=4;
        else if(num1[0+(i*3)+i]==' '&&num1[1+(i*3)+i]=='_'&&num1[2+(i*3)+i]==' '&&num2[0+(i*3)+i]=='|'&&num2[1+(i*3)+i]=='_'&&num2[2+(i*3)+i]==' '&&num3[0+(i*3)+i]==' '&&num3[1+(i*3)+i]=='_'&&num3[2+(i*3)+i]=='|') temp=5;
        else if(num1[0+(i*3)+i]==' '&&num1[1+(i*3)+i]=='_'&&num1[2+(i*3)+i]==' '&&num2[0+(i*3)+i]=='|'&&num2[1+(i*3)+i]=='_'&&num2[2+(i*3)+i]==' '&&num3[0+(i*3)+i]=='|'&&num3[1+(i*3)+i]=='_'&&num3[2+(i*3)+i]=='|') temp=6;
        else if(num1[0+(i*3)+i]==' '&&num1[1+(i*3)+i]=='_'&&num1[2+(i*3)+i]==' '&&num2[0+(i*3)+i]==' '&&num2[1+(i*3)+i]==' '&&num2[2+(i*3)+i]=='|'&&num3[0+(i*3)+i]==' '&&num3[1+(i*3)+i]==' '&&num3[2+(i*3)+i]=='|') temp=7;
        else if(num1[0+(i*3)+i]==' '&&num1[1+(i*3)+i]=='_'&&num1[2+(i*3)+i]==' '&&num2[0+(i*3)+i]=='|'&&num2[1+(i*3)+i]=='_'&&num2[2+(i*3)+i]=='|'&&num3[0+(i*3)+i]=='|'&&num3[1+(i*3)+i]=='_'&&num3[2+(i*3)+i]=='|') temp=8;
        else if(num1[0+(i*3)+i]==' '&&num1[1+(i*3)+i]=='_'&&num1[2+(i*3)+i]==' '&&num2[0+(i*3)+i]=='|'&&num2[1+(i*3)+i]=='_'&&num2[2+(i*3)+i]=='|'&&num3[0+(i*3)+i]==' '&&num3[1+(i*3)+i]=='_'&&num3[2+(i*3)+i]=='|') temp=9;
        else continue;
        for(j=0;j<len1-i-1;j++) temp*=10;
        res+=temp;
    }
    return 0;
}

int main()
{
    int len1,len2;
    scanf("%d %d%c",&len1,&len2,&t);
    gets(num1); gets(num2); gets(num3);
    cal(len1);
    gets(num1); gets(num2); gets(num3);
    cal(len2);
    printf("%u",res);
    return 0;
}
