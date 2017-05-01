#include<stdio.h>

void printFunc(int score)
{
	printf("Your total score is %d\n",score);
	if(score<30) printf("You get F");
	else if(score<40) printf("You get D");
	else if(score<50) printf("You get D+");
	else if(score<60) printf("You get C");
	else if(score<70) printf("You get C+");
	else if(score<80) printf("You get B");
	else if(score<90) printf("You get B+");
	else printf("You get A");
}

int main()
{
	int a,b,c;
	printf("Enter the score of assignments (0-30) : ");
	scanf("%d",&a);
	printf("Enter the score of midterm exam (0-30) : ");
	scanf("%d",&b);
	printf("Enter the score of final exam (0-30) : ");
	scanf("%d",&c);
	a+=b+c;
	printFunc(a);
	return 0;
}