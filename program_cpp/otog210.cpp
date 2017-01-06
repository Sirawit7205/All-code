#include<cstdio>

int n,c[50][500]={},sup[50][500]={},use[50][500]={},s[1000]={},x,y=0,z,ans=1;

int path(int nd)
{
    int i,m;
    if(nd==z&&x==0) return -1;
    else if(nd==z&&x!=0&&use[nd][0]==c[nd][0]) return 1;
    for(i=1;i<=c[nd][0];i++)
    {
        if(use[nd][i]==0)
        {
            s[ans]=c[nd][i]; use[nd][i]=1; use[nd][0]++; use[c[nd][i]][0]++; use[c[nd][i]][sup[nd][i]]=1; ans++; x--;
            m=path(c[nd][i]);
            if(m==-1) return -1;
            else {use[nd][i]=0; use[nd][0]--; use[c[nd][i]][0]--; use[c[nd][i]][sup[nd][i]]=0;  x++; ans--;}
        }
    }
    return 1;
}

int main()
{
    int i;
    char a,b;
    scanf("%d",&n); x=n;
    for(i=0;i<n;i++) {scanf(" %c%c",&a,&b); c[a-64][0]++; c[a-64][c[a-64][0]]=b-64; c[b-64][0]++; c[b-64][c[b-64][0]]=a-64; sup[a-64][c[a-64][0]]=c[b-64][0]; sup[b-64][c[b-64][0]]=c[a-64][0];}
    for(i=1;i<=26;i++) if(c[i][0]%2!=0) {if(y==0) y=i; else z=i;}
    if(y==0) {y=a-64; z=a-64;}
    s[0]=y; y=path(y);
    for(i=0;i<ans;i++) printf("%c ",s[i]+64);
    return 0;
}
