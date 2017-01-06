#include<stdio.h>

long long int curin=0, ctotal=1, rem[10]={}, add[10]={}, remtotal=0, addtotal=0, ans;

int main()
{
	int n,x,y,c,i=1,lim[5]={},sect[5]={};
	scanf("%d %d %d %d",&n,&x,&y,&c);
	if(c==1) {printf("0"); return 0;}
	lim[1]=y-1; lim[2]=x-1; lim[3]=n-x; lim[4]=n-y;
	sect[1]=x+y; sect[2]=n-x+1+y; sect[3]=x+n-y+1; sect[4]=n-x+1+n-y+1;
	while(1)
	{
		curin+=4; ctotal+=curin; ans=ctotal; remtotal=0; addtotal=0;
		//printf("R%d: %lld ",i,ctotal);
		if(i>lim[1]) {rem[1]+=1+(rem[2]*2); rem[2]++; remtotal+=rem[1];}
		if(i>lim[2]) {rem[3]+=1+(rem[4]*2); rem[4]++; remtotal+=rem[3];}
		if(i>lim[3]) {rem[5]+=1+(rem[6]*2); rem[6]++; remtotal+=rem[5];}
		if(i>lim[4]) {rem[7]+=1+(rem[8]*2); rem[8]++; remtotal+=rem[7];}
		ans-=remtotal;
		if(i>=sect[1]) {add[1]+=add[2]+1; add[2]++; addtotal+=add[1];}
		if(i>=sect[2]) {add[3]+=add[4]+1; add[4]++; addtotal+=add[3];}
		if(i>=sect[3]) {add[5]+=add[6]+1; add[6]++; addtotal+=add[5];}
		if(i>=sect[4]) {add[7]+=add[8]+1; add[8]++; addtotal+=add[7];}
		ans+=addtotal;
		//printf("%lld %lld %lld\n",remtotal,addtotal,ans);
		if(ans>=c) {printf("%d",i); break;}
		else i++;
	}
	return 0;
}
