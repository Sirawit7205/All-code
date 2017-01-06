#include<stdio.h>
#include<string.h>

char name[500][100]={},src[2000]={},dest[2000]={},scrp[2000]={},t[100]={};

int srcn(int a);

int main()
{
    int num,i;
    printf("System file expanding script helper\nWARNING: Paths cannot contain spaces and must ended with \\ !!!\n");
    printf("\nAmount of files to be extract: ");scanf("%d",&num); getchar();
    printf("\nEnter filename to be expand. (Include extension, one per line)\n");
    for(i=0;i<num;i++)
    {
       gets(name[i]);
    }
    printf("\nEnter i386 source directory: ");
    gets(src);
    printf("Enter destination directory: ");
    gets(dest);
    printf("Enter script file saving path: ");
    gets(scrp);
    printf("\n");

    FILE *fp; //Script file open header
    fp=fopen(scrp,"w+");

    fputs("@echo off\n",fp); //Batch header
    for(i=0;i<num;i++)
        {
            srcn(i);
            fprintf(fp,"expand %s%s %s%s\n",src,t,dest,name[i]);
            printf("Added expanding command for %s.\n",name[i]);
        }
    fclose(fp);
    printf("\nScript file closed. Finalized script file saved at %s.\n",scrp);
    return 0;
}

int srcn(int a)
{
    char b[2]={'_'};
    int i;
    for(i=0;i<100;i++) t[i]='\0';
    int len=strlen(name[a]);
    strncpy(t,name[a],len-1);
    strcat(t,b);
    return 0;
}
