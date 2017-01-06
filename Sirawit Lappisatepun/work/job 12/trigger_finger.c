#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char str[1000000];
    int len=0,i,upper=0;
    scanf("%s",str);
    len=strlen(str);
    for(i=1;i<=len;i++){
        if(isupper(str[i-1]))
            if(isupper(str[i])){
               upper=upper+2;

               point1:; while(isupper(str[i-1]))
               {i++;}
                if(isupper(str[i]))
                    {upper++;
                     i++;
                    goto point1;
                    }}
            else
                {upper++;}
    }
    if(isupper(str[len-1])&&isupper(str[len-2]))
    {upper--;}
    printf("%d",upper);
}
