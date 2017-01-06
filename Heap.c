#include<stdio.h>
int heap[400001]={},h=0;
void up(int pos)
    {
        if(pos<=0)return ;
        int t;
        if(heap[pos]>heap[(pos-1)/2])
        {
            t=heap[pos];
            heap[pos]=heap[(pos-1)/2];
            heap[(pos-1)/2]=t;
            up((pos-1)/2);

        }
    }

void down(int pos)
    {
        if(2*pos+1>h)return ;
        int t;
        if(heap[2*pos+1]>heap[2*pos+2]&&heap[2*pos+1]>heap[pos])
        {
            t=heap[pos];
            heap[pos]=heap[2*pos+1];
            heap[2*pos+1]=t;
            down(2*pos+1);
        }
        else if(heap[2*pos+2]>=heap[2*pos+1]&&heap[2*pos+2]>heap[pos])
        {
            t=heap[pos];
            heap[pos]=heap[2*pos+2];
            heap[2*pos+2]=t;
            down(2*pos+2);
        }
        else return ;

    }

int main()
{
char key;
int n,x,i;
scanf(" %d",&n);
for(i=0;i<n;i++)
    {
    scanf(" %c",&key);
    if(key=='P')
        {
        scanf(" %d",&x);
        heap[h++]=x;
        up(h-1);
        }
    else
        {
        if(h==0)printf("-1\n");
        else
            {
            printf("%d\n",heap[0]);
            heap[0]=heap[--h];
	    heap[0]=-1;
            down(0);
            }
        }
    }
return 0;
}
