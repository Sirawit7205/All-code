#include<stdio.h>
#include<string.h>

int definePriority(char ch)
{
    int priority;
    if(ch=='+'||ch=='-')
        priority=1;
    else if(ch=='*'||ch=='/')
        priority=2;
    return priority;
}

int main()
{
    char stack[15]={0},input[30]={0};
    int i,j,len,top=0,priority,priority2,parenpos=-1,probe;
    scanf("%s",input);
    len=strlen(input);
    for(i=0;i<len;i++)
    {
        if(input[i]=='('||input[i]==')'||input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='/')
        {
            if(top==0)
            {stack[top]=input[i]; top++;}
            else if(input[i]=='(')
            {stack[top]=input[i]; top++; parenpos=top-1;}
            else if(input[i]==')')
            {
                for(j=top-1;j>parenpos;j--)
                {
                    if(stack[j]!='(')
                    {printf("%c",stack[j]);}
                }
                top=top-(top-parenpos);
                parenpos=-1;
            }
            else
            {
                if(parenpos!=-1)
                    {stack[top]=input[i]; top++;}
                else
                {
                    priority=definePriority(input[i]);
                    priority2=definePriority(stack[top-1]);
                    if(priority>priority2)
                        {stack[top]=input[i]; top++;}
                    else
                       {
                        j=0;
                        printf("%c",stack[top-1]); top--;
                        probe=top;
                        while(probe!=-1)
                        {
                            j++;
                            priority2=definePriority(stack[top-j]);
                            if(priority>priority2||top==0||stack[top]=='(')
                            {stack[top]=input[i]; top++; probe=-1;}
                            else
                            {
                                if(stack[top-j]!='(')
                                {printf("%c",stack[top-j]); top--;}
                            }

                        }
                        }
                }
            }
        }
        else
            printf("%c",input[i]);
    }
    for(i=top-1;i>=0;i--)
    {
        if(stack[i]!='(')
        {printf("%c",stack[i]);}
    }
    return 0;
}
