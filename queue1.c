#include<stdio.h>

int queue[11],front,rear,i;

int addQ(int front,int rear,int queue[11])
{
    char mode;
    if(rear==10)
    {printf("Queue full, cannot add\n"); return 0;}
    printf("Enter number: "); scanf("%d",&queue[rear]);
    rear++;
    printf("Continue? (Y/N): "); scanf("\n%c",&mode);
    if(mode=='Y')
    {addQ(front, rear, queue);}
    return rear;
}

int removeQ(int front,int rear,int queue[11])
{
    char mode;
    int idx,i;
    if(rear==0)
    {printf("Queue empty, cannot delete\n"); return 0;}
    printf("Enter index: "); scanf("%d",&idx);
    rear--;
    for(i=0;i<rear-idx;i++)
    {queue[i]=queue[i+1];}
    queue[rear]=0;
    printf("Continue? (Y/N): "); scanf("\n%c",&mode);
    if(mode=='Y')
    {removeQ(front, rear, queue);}
    return front, rear, queue;
}

int main()
{
    char mode;
    while(i>-1)
    {
    printf("Enter mode: "); scanf("\n%c",&mode);
    if(mode=='A')
    {addQ(front,rear,queue);}
    else if(mode=='D')
    {removeQ(front, rear, queue);}
    for(i=0;i<10;i++)
    {printf("%d ",queue[i]);}
    }
    /*else if(mode=='E')
    {emptyQ();}
    else
    {printfQ();}*/
}
