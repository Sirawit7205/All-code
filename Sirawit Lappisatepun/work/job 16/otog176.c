#include<stdio.h>
#include<math.h>

char d[35]={};

int t(int b)
{
    int i=0,len=0,ten=0;
    while(d[i]!='\0') {len++; i++;}
    for(i=0;i<len;i++)
        ten+=(d[i]-48)*pow(b,len-i-1);
    return ten;
}

int tbase(int ten,int b)
{
    int i=0,j,dat[35]={};
    while(ten>=b)
    {
        dat[i]=ten%b;
        ten=ten/b;
        i++;
    }
    printf("%d",ten);
    for(j=0;j<i;j++) printf("%d",dat[i-j-1]);
    return 0;
}

int main()
{
    int i,b1,b2,ten;
    scanf("%d %d",&b1,&b2); getchar();
    gets(d);
    if(b1!=10) ten=t(b1);
    else sscanf(d,"%d",&ten);
    tbase(ten,b2);
    return 0;
}
