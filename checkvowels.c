#include<stdio.h>

int main()
{
    int i=0,v=0,len=0,spc=0;
    char str[100];
    gets(str);
    for(len=0;str[len]!='\0';len++);
    for(i=0;i<len;i++)
    {
        if(str[i]=='a'||str[i]=='A'||str[i]=='e'||str[i]=='E'||str[i]=='i'||str[i]=='I'||str[i]=='o'||str[i]=='O'||str[i]=='u'||str[i]=='U')
        {v++;}
        else
        if(str[i]==' ')
        {spc++;}
    }
    printf("Consonants: %d\n",len-v-spc);
    printf("Vowels: %d\n",v);
    printf("Spaces: %d",spc);
    getchar();
    return 0;
}
