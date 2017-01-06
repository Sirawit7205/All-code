#include<stdio.h>

int q[1000]={},top=0,bot=0;

void AddFunc()
{
    if(top==1000)
    {printf("Queue full.\n\n");}
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
    if(bot==top)
    {printf("No data in queue.\n\n");}
    else
    {
    printf("%d deleted.\n\n",q[bot]);
    bot++;
    }
}

void ShowFunc()
{
    int i;
    printf("Current queue:\n");
    for(i=bot;i<top;i++)
    {printf("%d ",q[i]);}
    printf("\n\n");
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
