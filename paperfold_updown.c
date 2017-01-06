#include<stdio.h>

char ans[5]={};
int c=0,rttf;

void asg(int mode,int flc)
{
	if(mode==0) if(flc%2==0) ans[c]='D'; else ans[c]='U';
	else if(flc%2==0) ans[c]='U'; else ans[c]='D';
	c++;
}

void flip(int lvl, int pnt, int flc)
{
	rttf/=2;
	int mid=rttf/2;
	if(pnt==mid) {asg(0,flc); return;}
	else if(lvl==2&&pnt==1) {asg(0,flc); return;}
	else if(lvl==2&&pnt==3) {asg(1,flc); return;}
	else if(pnt<mid) flip(lvl-1,pnt,flc);
	else if(pnt>mid) {flc++; flip(lvl-1,rttf-pnt,flc);}
}

int main()
{
	int amt,cnt,i,cns=1;
	scanf("%d %d",&amt,&cnt);
	for(i=0;i<=amt;i++) cns*=2;
	rttf=cns; flip(amt,cnt,0);
	rttf=cns; flip(amt,cnt+1,0);
	rttf=cns; flip(amt,cnt+2,0);
	printf("%c%c%c",ans[0],ans[1],ans[2]);
}