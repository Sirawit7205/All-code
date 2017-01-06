#include<stdio.h>
#include<string.h>

char a[10100]={}, b[10100]={};
int main()
{
    int i,lena,lenb,ca[27]={},cb[27]={};
    gets(a);//scanf("%s",a);
    gets(b);//scanf("%s",b);
    lena=strlen(a); lenb=strlen(b);
    for(i=0;i<lena;i++) if(a[i]>=97&&a[i]<=122) a[i]-=32;
    for(i=0;i<lenb;i++) if(b[i]>=97&&b[i]<=122) b[i]-=32;
    for(i=0;i<lena;i++) if(a[i]!=32) ca[a[i]-65]++;
    for(i=0;i<lenb;i++) if(b[i]!=32) cb[b[i]-65]++;
    for(i=0;i<26;i++)

        if(ca[i]!=cb[i]) {printf("No"); return 0;}
    printf("Yes");
    return 0;
}
