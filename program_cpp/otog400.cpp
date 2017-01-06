#include<cstdio>

int main()
{
    int i,n,ta,tb,cn;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&ta,&tb);
        tb+=15;
        if(tb>=60) {ta++; tb-=60;}
        if(ta>=21) printf("0 0\n");
        else
        {
            cn=0; cn+=60-tb; cn+=(21-ta-1)*60;
            if(cn%2==0) printf("%d %d\n",cn,cn/2);
            else printf("%d %d\n",cn,cn/2+1);
        }
    }
    return 0;
}
