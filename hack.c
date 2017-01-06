#include<stdio.h>
#include<string.h>

int n,k,t,c=0,ca=0,p[10]={},use[50]={};
char l[50]={},tc,ans[5000][7]={};

void chk()
{
    char tstr[7]={};
    int i;
    for(i=0;i<n;i++) tstr[i]=l[p[i+1]-1];
    if(ca==0) {strcpy(ans[ca],tstr); ca++;}
    else
    {
        for(i=0;i<ca;i++)
        {
            if(strcmp(ans[i],tstr)==0) return;
        }
        {strcpy(ans[ca],tstr); ca++;}
    }
}

void permu(int a)
{
    int i;
    if(a>n) /*{int i; for(i=1;i<=c;i++) printf("%d ",p[i]); printf("\n");}*/ {chk(); return;}
    else
    {
        for(i=1;i<=c;i++)
        {
            if(use[i]==0)
            {
                p[a]=i;
                use[i]=1;
                //printf("Doing %d\n",i);
                permu(a+1);
                use[i]=0;
            }
        }
    }
}

int main()
{
    int i,j;
    scanf("%d %d",&n,&k);
    for(i=0;i<k;i++)
    {
        scanf(" %c %d",&tc,&t);
        for(j=0;j<t;j++) l[c+j]=tc;
        c+=t;
    }
    permu(1);
    printf("%d\n",ca);
    for(i=0;i<ca;i++) printf("%s\n",ans[i]);
    return 0;
}
