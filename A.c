#include<stdio.h>
#include<string.h>
int main()
{
    int num,i,c=0,top=0,ans[10001]={},len;
    char test[5];
    while(num!=-1)
    {
        scanf("%d",&num);
        if(num==-1) break;
        sprintf(test,"%d",num);
        len=strlen(test);
        if(len==1) {ans[top]=num; top++; continue;} //1 digit
        if(len==2)
        {if(test[0]==test[1]) {ans[top]=num; top++; continue;}} //All same
        if(len>2)
        {
        for(i=0;i<len-1;i++) //1234
        {if(test[i+1]-1!=test[i]-0) c=1;}
        if(c==1) {c=0;}
        else if(c==0) {ans[top]=num; top++; continue;}
        for(i=0;i<len-1;i++) //4321
        {if(test[i+1]+1!=test[i]-0) c=1;}
        if(c==1) {c=0;}
        else if(c==0) {ans[top]=num; top++; continue;}
        }
        if(num%100==0) {ans[top]=num; top++; continue;} //Mod 100 = 0
        for(i=0;i<len/2;i++) //Palindrome
        {if(test[i]!=test[len-i-1]) c=1;}
        if(c==1) {c=0;}
        else if(c==0) {ans[top]=num; top++; continue;}
        if(len==4) //match two pair
        {if(test[0]==test[2]&&test[1]==test[3]) {ans[top]=num; top++; continue;}}
    }
    for(i=0;i<top;i++)
    {printf("%d\n",ans[i]);}
    return 0;
}
