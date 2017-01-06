#include<stdio.h>

char stk[20]={}, tem[20]={};

int main()
{
    char t='a',a;
    int i,q=0,top=0,ans=0,ca,cb,cc;
    scanf("%d %d %d",&ca,&cb,&cc);
	for(i=0;i<ca;i++) {tem[q]='('; tem[q+1]=')'; q+=2;}
	for(i=0;i<cb;i++) {tem[q]='{'; tem[q+1]='}'; q+=2;}
	for(i=0;i<cc;i++) {tem[q]='['; tem[q+1]=']'; q+=2;}
	for(i=0;i<q;i++) printf("%c",tem[i]);
    /* for(i=0;i<q;i++)
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
    } */
    return 0;
}
