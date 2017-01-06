#include<cstdio>

int np[1000]={},nc=2;

int main()
{
    int i,j,k,n,m,c=0;
    np[1]=2; np[2]=3;
    scanf("%d %d",&n,&m);
    printf("YES\n");
    for(i=3;i<=m;i++)
    {
        j=np[nc]; c=0;
        while(1)
        {
            j+=2; c=0;
            for(k=1;k<=nc;k++)
            {
                if(j%np[k]==0) {c=1; break;}
            }
            if(c!=1) {np[nc+1]=j; nc++; break;}
        }
    }
    for(i=1;i<=m;i++) printf("%d ",np[i]);
    return 0;
}
