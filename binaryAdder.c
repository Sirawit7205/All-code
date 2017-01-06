#include<stdio.h>
#include<string.h>

int main()
{
    char ans[100],in1[100],in2[100];
    int i,j,k=0,len1,len2,chk=0;
    gets(in1); gets(in2);
    len1=strlen(in1);
    len2=strlen(in2);
    for(i=0;i<len2;i++)
    {
        chk=0;
        for(j=0;j<len1;j++)
        {
            if(in2[i]==in1[j]) {chk=1; break;}
        }
        if(chk==0)
        {ans[k]=in2[i]; k++;}
    }
    for(i=0;i<k;i++) printf("%c",ans[i]);
    return 0;
}
