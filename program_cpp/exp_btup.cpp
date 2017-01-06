#include<iostream>
#include<cstdio>

using namespace std;

int tab[1005][1005][2]={},a[1005]={},b[1005]={},m,k;

void gent()
{
    int i,j,c,d,e,f;
    c=0; d=1;
    for(i=1;i<=k;i++)
    {
        c+=a[i];
        if(c>m) {d++; c=a[i]; tab[0][i][0]=d; tab[0][i][1]=a[i];} else {tab[0][i][0]=d; tab[0][i][1]=c;}
    }
    c=0; d=1;
    for(i=1;i<=k;i++)
    {
        c+=b[i];
        if(c>m) {d++; c=b[i]; tab[i][0][0]=d; tab[i][0][1]=b[i];} else {tab[i][0][0]=d; tab[i][0][1]=c;}
    }
    for(i=1;i<=k;i++)
    {
        for(j=1;j<=k;j++)
        {
            c=tab[i][j-1][1]; d=tab[i][j-1][0]; e=tab[i-1][j][1]; f=tab[i-1][j][0];
            c+=a[j]; if(c>m) {d++; c=a[j];}
            e+=b[i]; if(e>m) {f++; e=b[i];}
            if(c==e&&d==f) {tab[i][j][1]=c; tab[i][j][0]=d;}
            else if(d<f) {tab[i][j][1]=c; tab[i][j][0]=d;}
            else if(f<d) {tab[i][j][1]=e; tab[i][j][0]=f;}
            else if(f==d)
            {
                if(c<e) {tab[i][j][1]=c; tab[i][j][0]=d;}
                else {tab[i][j][1]=e; tab[i][j][0]=f;}
            }
        }
    }
}

int main()
{
    int i;
    scanf("%d %d",&m,&k);
    for(i=1;i<=k;i++) scanf("%d",&a[i]);
    for(i=1;i<=k;i++) scanf("%d",&b[i]);
    tab[0][0][0]=1;
    gent();
    /*for(i=0;i<=k;i++)
    {
        for(j=0;j<=k;j++) printf("%d/%d ",tab[i][j][0],tab[i][j][1]);
        printf("\n");
    }*/
    printf("%d\n%d",tab[k][k][0],tab[k][k][1]);
    return 0;
}
