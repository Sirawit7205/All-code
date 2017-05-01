#include<stdio.h>

int main(){
    int k;
    for(;;){
        int i;
        printf("enter the number k:");
        scanf("%d",&k);
        if(k>=1 && k<=25){
            for(i=1;i<=12;i++){
                printf(" %d x 1 = %d\n",k,k*i);
            }
        }
        else {  printf("error\n");

        }
    }
}//end

