#include<stdio.h>
#include<string.h>

int main()
{
    char roman[20];
    int i,len,ans=0;
    gets(roman);
    len=strlen(roman);
    for(i=len-1;i>=0;i--)
    {
        if(roman[i]=='V'&&roman[i-1]=='I') {ans+=4; i--;}
        else if(roman[i]=='X'&&roman[i-1]=='I') {ans+=9; i--;}
        else if(roman[i]=='I') {ans+=1;}
        else if(roman[i]=='V') {ans+=5;}
        else if(roman[i]=='X') {ans+=10;}
        else if(roman[i]=='L'&&roman[i-1]=='X') {ans+=40; i--;}
        else if(roman[i]=='C'&&roman[i-1]=='X') {ans+=90; i--;}
        else if(roman[i]=='L') {ans+=50;}
        else if(roman[i]=='C') {ans+=100;}
        else if(roman[i]=='D'&&roman[i-1]=='C') {ans+=400; i--;}
        else if(roman[i]=='M'&&roman[i-1]=='C') {ans+=900; i--;}
        else if(roman[i]=='D') {ans+=500;}
        else if(roman[i]=='M') {ans+=1000;}
    }
    printf("%d",ans);
    getchar();
    return 0;
}
