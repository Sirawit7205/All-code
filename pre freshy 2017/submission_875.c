#include<stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));   // should only be called once
    int r = rand()%100;
    int i,num;
	r++;
    printf("This is guessing number game. In 7 rounds, player has to guess the number from 1 to 100.\n");
    for(i=1;i<=7;i++){
        printf("Round %d, enter your number: ",i);
        scanf("%d",&num);
        if(num < r)printf("Incorrect,your guessing is too low\n");
        else if(num > r)printf("Incorrect,your guessing is too high\n");
        else if(num == r)
		{
			printf("Congratulation! your win this game.");
			return 0;
		}
    }
    printf("You lose. The correct number is %d",r);
	return 0;
}

