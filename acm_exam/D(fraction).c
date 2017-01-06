#include<stdio.h>
#include<string.h>

int main()
{
    char maze[5][10]={ {'i','u','w','e','t','h','e','y','h','e'} , {'i','l','o','v','e','y','o','u','o','k'} , {'s','t','r','o','n','g','p','l','a','y'} , {'c','o','f','f','e','e','b','l','u','e'} , {'p','a','p','e','r','s','t','u','d','y'} };
    int i,j,k,l,a,n,len;
    char q[10];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",q);
        for(j=0;j<5;j++)
        {
            for(k=0;k<10;k++)
            {
                if(q[0]==maze[j][k])
                {
                    a=1;
                    for(l=k;l<10;l++)
                    {
                        if(q[a]==maze[j][l])
                            a++;
                        if(a==len)
                    }
                }
    }
    return 0;
}
