#include<stdio.h>

char stk[100001]={};

int main()
{
    char t='a',a;
    int i,q,top=0;
    scanf("%d%c",&q,&a);
    for(i=0;i<q;i++)
    {
        t='a';
        while(t!='\n')
        {
            scanf("%c",&t);
            if(t=='\n')
            {
                if(top==0) printf("yes\n");
                else {printf("no\n"); top=0;}
                break;
            }
            else
            {
                if(t=='('||t=='{'||t=='[') {stk[top]=t; top++;}
                else if((stk[top-1]=='('&&t==')')||(stk[top-1]=='{'&&t=='}')||(stk[top-1]=='['&&t==']')) top--;
                else {printf("no\n"); top=0; scanf("%*[^\n]%1*[\n]"); break;}
            }
        }
    }
    return 0;
}
