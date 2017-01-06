#include<stdio.h>

int main()
{
    int amt,i=0,j=1,count=0,count2=0;
    char str1[100],str2[100];
    printf("String 1: "); scanf("%s",str1);
    printf("String 2: "); scanf("%s",str2);
    printf("Amount: "); scanf("%d",&amt);
    while(j>0)
    {
        if(str1[i]!='\0')
        {count++; i++;}
        else
        {j=0;}
    }
    i=0; j=1;
    while(j>0)
    {
        if(str2[i]!='\0')
        {count2++; i++;}
        else
        {j=0;}
    }
    if(amt>count2)
    {printf("String is too short");}
    else if(count+count2>100)
    {printf("Not enough space");}
    else
    {
        for(i=0;i<amt;i++)
        {str1[count+i]=str2[i];}
        for(i=0;i<amt+count;i++)
        {printf("%c",str1[i]);}
    }
    return 0;
}
