#include<stdio.h>

int chk=0,cur=0,cur2=0,min=0;

int func(int n)
{
    if(cur2<0) return 0;
    cur=n-cur2;
    sine(1);
    if(n-min==1) return 0;
    else if(n-min>=0) printf("+%d)",n-min);
    else printf("%d)",n-min);
    min++; cur2--;
    func(n);

}

int sine(int n)
{
    int i;
    if(n==0) return 0;
    printf("sin(%d",n);
    if(n==cur) {for(i=0;i<n;i++) printf(")"); chk=0; cur=n-1; return 0;}
    else if(chk==0) {printf("-"); chk=1; sine(n+1);}
    else if(chk==1) {printf("+"); chk=0; sine(n+1);}
}

int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n-1;i++) printf("(");
    cur=n-1; cur2=n-1;
    func(n);
    printf("+1");
    return 0;
}
