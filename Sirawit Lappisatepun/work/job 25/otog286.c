#include<stdio.h>
#include<string.h>
int main()
{
    int i,len,cnt=0,r;
    char a[11000]={};
    gets(a);
    scanf("%d",&r);
    len=strlen(a);
    for(i=0;i<len-1;i++)
    {
        if((a[i]=='c'||a[i]=='C')&&(a[i+1]=='c'||a[i+1]=='C')) cnt++;
    }
    if(cnt==r) printf("#OCOMisfun");
    else if(cnt>r) {printf("#OCOMisfun"); for(i=0;i<cnt-r;i++) printf(" fun");}
    else printf("OCOM is not fun");
    return 0;
}
