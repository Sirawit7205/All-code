#include<stdio.h>

int main(){
int num1,num2;
printf("Enter the first number: ");
scanf("%d",&num1);
printf("Enter the second number: ");
scanf("%d",&num2);

if(num1 > num2){
        printf("The maxinum valus is %d\n",num1);
        printf("The mininum valus is %d",num2);
}
else
{
        printf("The maxinum valus is %d\n",num2);
        printf("The mininum valus is %d",num1);
}
}
