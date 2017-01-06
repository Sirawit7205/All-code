#include<stdio.h>
#include<string.h>
#include<ctype.h>

char stra[1000005]={},strb[1000005]={};
int key[1000005]={};

int main()
{
    int i,lena,lenb,err=0,t;
    scanf("%s",stra); lena=strlen(stra);
    scanf("%s",strb); lenb=strlen(strb);
    for(i=0;i<lena;i++) {stra[i]=toupper(stra[i]); strb[i]=toupper(strb[i]);}
    if(lena!=lenb) {printf("R.I.P."); return 0;}
    for(i=0;i<lena;i++)
    {
        if(stra[i]==strb[i]) continue;
        else if(stra[i]<strb[i])
        {
            if(strb[i]+9>90) t=strb[i]-16; else t=strb[i]+9;
            if(t>=stra[i]) key[i]=(stra[i]+26)-strb[i]; else {err=1; break;}
        }
        else
        {
            if(strb[i]+9>90) t=90; else t=strb[i]+9;
            if(t>=stra[i]) key[i]=stra[i]-strb[i]; else {err=1; break;}
        }
    }
    if(err==1) printf("R.I.P.");
    else for(i=0;i<lena;i++) printf("%d",key[i]);
    return 0;
}
