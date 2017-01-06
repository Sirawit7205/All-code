#include<stdio.h>
int list[10001];

int main()
{
    //FILE *fp; //file input
    //fp=fopen("testSearch.txt","r"); //file input
    int len,low=0,mid,high,i,key;
    scanf("%d",&key);
    scanf("%d",&len);
    for(i=0;i<len;i++) scanf("%d",&list[i]); //std input
    //for(i=0;i<len;i++) fscanf(fp,"%d", &list[i]); //file input
    high=len-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(list[mid]==key)
        {
            printf("Target found at %d",mid);
            return 0;
        }
        if(key<list[mid])
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    printf("Target not found");
    return 0;
}
