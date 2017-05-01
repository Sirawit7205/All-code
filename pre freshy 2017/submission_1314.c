#include<stdio.h>

float calculateDiscount(int isMember,double price){
    float total;
    if(isMember == 1){total = price - price/5;}
    else if(isMember == 0){total = price - price/10;}
    return total;
}



int main(){
    float num;
    int member;
    int yn;
    char yesno;
    printf("How much does the meal cost? : ");
    scanf("%f",&num);

    if (num>=1000){
        printf("Does customer have member card? (y/n)");
        scanf(" %c",&yesno);
        if(yesno == 'y')yn=1;
        else if(yesno == 'n')yn=0;
        printf("Sub total (bath): %.2f\n",num);
        printf("Discount (bath):  %.2f\n",num/5);
        printf("Total (bath):     %.2f\n",calculateDiscount(yn,num));

    }
    else{
      printf("There is no discount for this promotion\n");
      printf("total (bath):  %.2f\n",num);
    }


    return 0;
}
