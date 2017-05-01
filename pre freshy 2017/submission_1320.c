#include<stdio.h>
int total;
int grade(int score){
     if(score < 30) {printf("Your get F");}
else if(score < 40) {printf("Your get D");}
else if(score < 50) {printf("Your get D+");}
else if(score < 60) {printf("Your get C");}
else if(score < 70) {printf("Your get C+");}
else if(score < 80) {printf("Your get B");}
else if(score < 90) {printf("Your get B+");}
else if(score < 100){printf("Your get A");}
}


int main(){
    int score1,score2,score3;
printf("Enter the score of assignments (0-30):");
scanf("%d",&score1);
printf("Enter the score of assignments (0-35):");
scanf("%d",&score2);
printf("Enter the score of assignments (0-35):");
scanf("%d",&score3);
total = score1+score2+score3;
printf("Your total score is %d \n",total);
grade(total);

}
