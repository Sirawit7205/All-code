#include<stdio.h>

double calculateDiscount(int isMember, double price)
{
	double disc;
	if(isMember == 1) disc = price * 0.2; else disc = price * 0.1;
	return disc;
}

int main()
{
	double price, disc = 0;
	int mem;
	char text;
	printf("How much does the meal cost? : ");
	scanf("%lf",&price);
	if(price < 1000) printf("There is no discount for this promotion\n");
	else
	{
		printf("Does customer have member card? (y/n) : ");
		scanf(" %c",&text);
		if(text == 'y') mem = 1; else mem = 0;
		disc = calculateDiscount(mem, price);
		printf("Sub Total (Baht): %.2f\nDiscount (Baht): %.2f\n",price,disc);
	}
	printf("Total (Baht): %.2f",price-disc);
	return 0;
}