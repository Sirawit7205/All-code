#include<stdio.h>
#include<conio.h>

int nums[10001]={}, b=0;

int sort_num(cur,max)
{
    int i,j,p,temp,min=max;
    for(i=0;i<cur;i++)
    {
        for(j=i;j<cur;j++)
        {
            if(nums[j]<min) {min=nums[j]; p=j;}
        }
        temp=nums[p];
        nums[p]=nums[i];
        nums[i]=temp;
        min=max;
    }

}

int main()

{
    int next=0,max=0,i;
    do {
        scanf("%d",&next);
        if(next!=0)
        {nums[b]=next;
        b++;
        if(next>max) {max=next;}
        }
        }
    while (next!=0);
    sort_num(b,max);
    for(i=0;i<b;i++)
    {
        printf("%d\n",nums[i]);
    }
    return 0;
}
