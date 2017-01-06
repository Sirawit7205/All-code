#include<stdio.h>
#include<string.h>

int main()
{
    FILE *fp;
    FILE *fp2;
    int l,i,amt;
    char t[1005]={},a;
    fp=fopen("temp.txt","w");
    fp2=fopen("in.txt","r");
    scanf("%d %d",&amt,&l);
    for(i=1;i<amt;i++)
    {
        fgets(t,l+1,fp2);
        a=fgetc(fp2);
        printf("%c\n",a);
        fprintf(fp,t);
        fprintf(fp,"\n");
    }
    return 0;
}
