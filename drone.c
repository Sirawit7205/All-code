#include<stdio.h>

int main()
{
    int n,m,i,k,cur=1,mov=0,drp;
    char t,d;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%c%c %c %d",&drp,&t,&d,&k);
        mov=k%n;
        if(t=='M'&&d=='A')
        {
            if(cur+mov>n) cur=cur+mov-n;
            else cur+=mov;
        }
        else if(t=='M'&&d=='B')
        {
            if(cur-mov<1) cur=cur-mov+n;
            else cur-=mov;
        }
        else if(t=='Q'&&d=='A')
        {
            if(cur+mov>n) printf("%d\n",cur+mov-n);
            else printf("%d\n",cur+mov);
        }
        else
        {
            if(cur-mov<1) printf("%d\n",cur-mov+n);
            else printf("%d\n",cur-mov);
        }
    }
    return 0;
}
