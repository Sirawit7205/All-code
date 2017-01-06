#include<stdio.h>

int main()
{
    int i=0,j=1,count1=0,count2=0,match=0;
    char str1[100],str2[100];
    printf("String 1: "); scanf("%s",str1);
    printf("String 2: "); scanf("%s",str2);
    while(j>0)
    {
        if(str1[i]!='\0')
        {count1++; i++;}
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
    if(count1!=count2)
        {printf("Not match");}
    else
    {
        for(i=0;i<count1;i++)
        {
            if(str1[i]!=str2[i])
            {printf("Not match"); break;}
            else
            {match++;}
        }
    }
    if(match==count1)
    {printf("Match");}
    return 0;
}
