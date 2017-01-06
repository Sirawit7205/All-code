#include<stdio.h>

char dat[100001]={};

int main()
{
    char t1='-',t2='-',drp;
    int i=0,n,c=0;
    scanf("%d%c",&n,&drp);
    while(i<=n)
    {
        if(t1=='-'&&t2=='-')
            {
                if(n==1) {scanf("%c%c",&t1,&drp); break;}
                else
                {
                    scanf("%c%c",&t1,&drp);
                    scanf("%c%c",&t2,&drp);
                }
            }
        else
        {
            scanf("%c%c",&t2,&drp);
        }
        if(t1==t2)
            {
                n-=2; t1='-'; t2='-';
                continue;
            }
        else
        {
            dat[i]=t1;
            i++; c++; n--;
            t1=t2;
            if(dat[i-1]==dat[i-2]) {dat[i-1]='-'; dat[i-2]='|'; i-=2; c-=2;}

        }
    }
    if(t1!='-'&&t1!=dat[i-1]) {c++; dat[i]=t1;}
    else if(t1!='-'&&t1==dat[i-1]) c--;
    printf("%d\n",c);
    if(c==0) printf("empty");
    else
    {
        for(i=c-1;i>=0;i--) printf("%c",dat[i]);
    }
    return 0;
}
