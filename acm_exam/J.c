#include<stdio.h>

int main()
{
    int i,num,t[11]={};
    for(i=0;i<10;i++)
    {
        scanf("%d",&num);
        if(num==0) t[i]=0;
        else if(num>0)
        {
            if(num%2==0)
                t[i]=1;
            else
                t[i]=2;
        }
        else
        {
            if(num%2==0)
                t[i]=3;
            else
                t[i]=4;
        }
    }
    for(i=0;i<10;i++)
    {
        if(t[i]==0) printf("zero\n");
        else if(t[i]==1) printf("positive even\n");
        else if(t[i]==2) printf("positive odd\n");
        else if(t[i]==3) printf("negative even\n");
        else if(t[i]==4) printf("negative odd\n");
    }
}
