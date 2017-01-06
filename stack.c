#include<stdio.h>

int q[1000]={},top=0;

void AddFunc()
{
    if(top==1000)
    {printf("Stack full.\n\n");}
    else
    {
    printf("Add: ");
    scanf("%d",&q[top]);
    printf("%d added.\n\n",q[top]);
    top++;
    }
}

void DelFunc()
{
    if(top==0)
    {printf("No data in stack.\n\n");}
    else
    {
    printf("%d deleted.\n\n",q[top-1]);
    top--;
    }
}

void ShowFunc()
{
    int i;
    printf("Current stack:\n");
    for(i=top-1;i>=0;i--)
    {printf("%d\n",q[i]);}
    printf("\n");
}

int main()
{
    char m;
    printf("Select function [A]dd/[D]elete/[S]how/[E]xit: ");
    scanf("\n%c",&m);
    if(m=='A')
    {
        AddFunc();
        main();
    }
    else if(m=='D')
    {
        DelFunc();
        main();
    }
    else if(m=='S')
    {
        ShowFunc();
        main();
    }
    else if(m=='E')
    {
        printf("Goodbye\n");
        goto stop;
    }
    else
    {
        printf("Invalid Function\n\n");
        main();
    }
    stop:;
    return 0;
}

