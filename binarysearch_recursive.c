#include<stdio.h>
int list[10001]={};

int sort(int n)
{
    int i,j=0,tmp,c=1;
    while(c==1)
    {
        c=0;
        j++;
        for(i=0;i<n-j;i++)
        {
            if(list[i]>list[i+1])
            {
                tmp=list[i];
                list[i]=list[i+1];
                list[i+1]=tmp;
                c=1;
            }
        }
    }
    return 0;
}

int bin(int key,int low,int high)
{
    int mid;
    if(low<=high)
    {
        mid=(low+high)/2;
        if(list[mid]==key) return mid;
        else if(key<list[mid]) return bin(key,low,mid-1);
        else return bin(key,mid+1,high);
    }
    else return -1;
}

int main()
{
    int i,key,len,res;
    printf("Array size: "); scanf("%d",&len);
    printf("Search for: "); scanf("%d",&key);
    printf("Enter data: ");
    for(i=0;i<len;i++) scanf("%d",&list[i]);
    sort(len);
    printf("Sorted: ");
    for(i=0;i<len;i++) printf("%d ",list[i]);
    res=bin(key,0,len-1);
    if(res!=-1) printf("\nFound at %d",res);
    else printf("\nNot found");
    return 0;
}
