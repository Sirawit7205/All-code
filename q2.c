#include<stdio.h>

int main()
{
    int i,j,k,t,n,m,c=0,f[101][101]={};
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int rmax[101]={},cmax[101]={};
        scanf("%d %d",&n,&m);
        for(j=0;j<n;j++)
        {
            for(k=0;k<m;k++)
            {
                scanf("%d",&f[j][k]); if(rmax[k]<f[j][k]) rmax[k]=f[j][k]; if(cmax[j]<f[j][k]) cmax[j]=f[j][k];
            }
        }
        for(j=0;j<n;j++)
        {
            for(k=0;k<m;k++)
            {
                if(f[j][k]<cmax[k]&&f[j][k]<rmax[j]) {c=1; break;}
            }
            if(c==1) break;
        }
        if(c==1) printf("NO\n");
        else printf("YES\n");
        c=0;
    }
    return 0;
}
