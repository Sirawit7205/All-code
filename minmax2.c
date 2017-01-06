#include<stdio.h>
#define ARRAY_SIZE(array) (sizeof(array)/sizeof(array[0]))
int tempmax,tempmin;

int getmax(int first,int second)
{
    return first > second ? first : second;
}

int getmin(int first,int second)
{
    return first < second ? first : second;
}

int *maxmin(const int list[],const int low,const int high,int max,int min)
{
    int mid,max1,min1;
    static int maxandmin[2];
    if(low==high)
    {
        max=list[low];
        min=list[low];
    }
    else if(low==high-1)
    {
        if(list[low]<list[high]){
            tempmax=getmax(tempmax,list[high]);
            tempmin=getmin(tempmin,list[low]);}
        else{
            tempmax=getmax(tempmax,list[high]);
            tempmin=getmin(tempmin,list[low]);}
    }
    else
    {
        mid=(low+high)/2;
        max1=list[mid+1];
        min1=list[mid+1];
        maxmin(list,low,mid,max,min);
        maxmin(list,mid+1,high,max1,min1);
        tempmax=getmax(tempmax,max1);
        tempmin=getmin(tempmin,min1);
    }
    maxandmin[0]=tempmax;
    maxandmin[1]=tempmin;
    return maxandmin;
}

int main(void)
{
    int list[]={100,123};
    int *value;
    int size=ARRAY_SIZE(list);
    tempmax=tempmin=list[0];
    value=maxmin(list,0,size-1,list[0],list[0]);
    printf("The maximum value is %2d\n",*value);
    printf("The minimum value is %2d\n",*(value+1));
    return 0;
}
