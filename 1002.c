#include<stdio.h>

int main()
{
	int i=0,v=0,x=0,l=0,c=0,a,b,t;
	scanf("%d",&b);
	for(a=1;a<=b;a++)
	{
		t=a/100;
		if(t!=0)
		{
			if(t==1||t==4) c++;
			else if(t==2) c+=2;
			else if(t==3) c+=3;
		}
		a-=(a/100)*100; t=a/10;
		if(t!=0)
		{
			if(t==1) x++;
			else if(t==2) x+=2;
			else if(t==3) x+=3;
			else if(t==4||t==6) {x++; l++;}
			else if(t==5) l++;
			else if(t==7) {l++; x+=2;}
			else if(t==8) {l++; x+=3;}
			else if(t==9) {x++; c++;}
		}
		a-=(a/10)*10; t=a;
		if(t!=0)
		{
			if(t==1) i++;
			else if(t==2) i+=2;
			else if(t==3) i+=3;
			else if(t==4||t==6) {i++; v++;}
			else if(t==5) v++;
			else if(t==7) {v++; i+=2;}
			else if(t==8) {v++; i+=3;}
			else if(t==9) {i++; x++;}
		}
	}
	printf("%d %d %d %d %d",i,v,x,l,c);
	return 0;
}