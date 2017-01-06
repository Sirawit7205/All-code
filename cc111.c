#include<stdio.h>

int main()
{
	int a,b,c,mmx=0,mx=0,d;
	scanf("%d %d %d",&a,&b,&c);
	if(a+b+c!=100) {printf("BUG"); return 0;}
	if(a>mx) {mx=a; d=1;} if(b>mx) {mx=b; d=2;} if(c>mx) {mx=c; d=3;}
	if(a==mx) mmx++; if(b==mx) mmx++; if(c==mx) mmx++;
	if(mmx>1) {printf("I DON'T KNOW"); return 0;}
	if(d==1) printf("PAPER"); else if(d==2) printf("SCISSORS"); else printf("ROCK");
	return 0;
}