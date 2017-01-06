#include<stdio.h>
#include<string.h>

int a[1005][1005]={};

void chk()
{
    int i,j,lena,lenb,y;
    char stra[1005]={},strb[1005]={};
    scanf("%s %s",stra,strb); lena=strlen(stra); lenb=strlen(strb);
    for(i=0;i<=lena;i++) a[i][0]=i; for(i=0;i<=lenb;i++) a[0][i]=i;
    for(i=1;i<=lena;i++)
    {
        for(j=1;j<=lenb;j++)
        {
            if(a[i-1][j]+1>=a[i][j-1]+1) y=a[i][j-1]+1; else y=a[i-1][j]+1;
            if(stra[i-1]==strb[j-1]) {if(a[i-1][j-1]<y) y=a[i-1][j-1];}
            else {if(a[i-1][j-1]+1<y) y=a[i-1][j-1]+1;}
            a[i][j]=y;
        }
    }
    printf("%d\n",a[lena][lenb]);
    for(i=0;i<=lena;i++)
    {
        for(j=0;j<=lenb;j++) a[i][j]=0;
    }
    return;
}

int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {
            chk();
        }
    return 0;
}
