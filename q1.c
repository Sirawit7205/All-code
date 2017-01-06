#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void *a, const void *b)
{
    int *A=(int *)a;
    int *B=(int *)b;
    if(*A<*B) return 1;
    else return -1;
}

int main()
{
    int i,j,k,len,c=0,t=0,a=1;
    char dat[2001]={},temp[2001]={};
    scanf("%s",dat);
    len=strlen(dat);
    for(i=len-1;i>=0;i--)
    {
        if(dat[i]!='0')
        {
            for(j=i-1;j>=0;j--)
            {
                if(dat[j]!='9')
                {
                    dat[j]++;
                    dat[i]--;
                    for(k=j+1;k<=len-1;k++) temp[c++]=dat[k];
                    qsort(temp,c,sizeof(char),cmp);
                    for(k=j+1;k<=len-1;k++) {dat[k]=temp[c-a]; a++;}
                    t=1;
                    break;
                }
            }
            if(t==1) break;
        }
    }
    if(t==0) printf("-1");
    else printf("%s",dat);
    return 0;
}
