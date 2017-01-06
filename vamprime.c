#include<stdio.h>

int precomp[1000001]={},pcc=1,n;

void findnext(int x)
{
    int i,f=0;
    for(i=0;i<pcc;i++) if(precomp[i]>x) break; else {if(x%precomp[i]==0) {f=1; break;}}
    if(f==0) {precomp[pcc]=x; pcc++;}
    if(x>n&&f==0) return; else findnext(x+1);
}

int main()
{
    scanf("%d",&n);
    if(n<0) n=n*-1;
    if(n==0||n==1) {printf("Mr.Nonz 2"); return 0;}
    else if(n==2) {printf("Mr.Nonz 3"); return 0;}
    else
    {
        precomp[0]=2;
        findnext(3);
        if(precomp[pcc-2]==n) printf("%d %d",precomp[pcc-3],precomp[pcc-1]);
        else printf("%d %d",precomp[pcc-2],precomp[pcc-1]);
    }
    return 0;
}
