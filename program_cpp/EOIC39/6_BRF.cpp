#include<cstdio>
#include<cstring>

char sta[1005][1005]={};

int main()
{
    int i,j,n,l,ta,tb,cnt=0,r=0;
    scanf("%d",&n);
    scanf("%s",sta[0]);
    l=strlen(sta[0]);
    for(i=1;i<=l;i++)
    {
        ta=0; tb=l-1;
        for(j=0;j<l;j+=2)
        {
            sta[i][j]=sta[i-1][ta];
            if(j+1<l) sta[i][j+1]=sta[i-1][tb];
            if(j+2<l) {sta[i][j+2]=sta[i-1][ta+1]; if(r==0) cnt++;}
            ta++; tb--;
        }
        r=1;
        if(strcmp(sta[0],sta[i])==0) break;
    }
    n=n%i;
    for(i=1;i<=n;i++)
    {
        ta=0; tb=l-1;
        for(j=1;j<=cnt*2;j+=2)
        {
            sta[i][tb]=sta[i-1][j];
            sta[i-1][j]='0'; tb--;
        }
        for(j=0;j<l;j++)
        {
            if(sta[i-1][j]!='0') {sta[i][ta]=sta[i-1][j]; ta++;}
        }
    }
    printf("%s",sta[i-1]);
    return 0;
}
