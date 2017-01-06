#include<stdio.h>

long long int qword[100003]={};
int n;

void qsum(int a)
{
    int i;
    if(a>n) return;
    scanf("%d",&i);
    qword[a]=qword[a-1]+i;
    qsum(a+1);
}

int main()
{
    int i,j,a=0,b=0,c=0;
    scanf("%d",&n);
    qsum(1);
    for(i=1;i<n;i++)
    {
        if(qword[i]==qword[n]-qword[i]) {printf("%d",i); return 0;}
        else
        {
            if(c==0) for(j=n-1;j>i;j--) if(qword[i]+(qword[n]-qword[j])==qword[j]-qword[i]) {a=i; b=j; c=1; break;}
        }
    }
    if(c==1) {printf("%d %d",a,b);}
    else printf("NO");
    return 0;
}
