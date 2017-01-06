#include<stdio.h>

int use[1000]={},res[1000]={},n,c=0;

int permut(int a)
{
    FILE * fp;
    fp=fopen("output.txt","a+");
    int i;
    if(a>n)
    {
        for(i=1;i<=n;i++) fprintf(fp,"%d ",res[i]);//printf("%d ",res[i]);
        fprintf(fp,"\n"); //printf("\n");
        printf("OK %d\n",c); c++;
        return 0;
    }
    else
    {
        for(i=1;i<=n;i++)
        {
            if(use[i]==0)
            {
            res[a]=i;
            use[i]=1;
            permut(a+1);
            use[i]=0;
            }
        }
    }
    fclose(fp);
}

int main()
{
    scanf("%d",&n);
    permut(1);
    return 0;
}
