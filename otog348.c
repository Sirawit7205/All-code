#include<stdio.h>
#include<string.h>
#include<stdbool.h>

unsigned long long int str[3000000]={},n,chk=0;
bool ver[3000000]={};
char ovf[25]={'1','8','4','4','6','7','4','4','0','7','3','7','0','9','5','5','1','6','1','6'},t[25]={};

void upd(int nd,int l,int r,int k,unsigned long long int v)
{
	int mid=(l+r)/2;
	if(l==r) {str[nd]=v; if(v==0) ver[nd]=true; return;}
	else if(k<=mid) upd(nd*2,l,mid,k,v);
	else upd((nd*2)+1,mid+1,r,k,v);
	if(v==0) {ver[nd]=true; str[nd]=0;} else {if(str[nd]<v&&ver[nd]==false) str[nd]=v;}
}

unsigned long long int query(int nd,int l,int r,int tl,int tr)
{
	int mid=(l+r)/2,x;
	unsigned long long int ta,tb;
	if(l==tl&&r==tr) {if(ver[nd]==true) chk=-1; return str[nd];}
	if(tr>mid) {if(tl>mid) x=tl; else x=mid+1; ta=query((nd*2)+1,mid+1,r,x,tr);} else ta=0;
	if(tl<=mid) {if(tr<=mid) x=tr; else x=mid; tb=query(nd*2,l,mid,tl,x);} else tb=0;
	if((ta==0||tb==0)&&ver[nd]==true&&chk==-1) {chk=1; return 0;}
	if(ta>=tb) return ta; else return tb;
}

int main()
{
	int m,i,j,ta;
	unsigned long long int tb,x=1;
	char mode;
	scanf("%llu",&n); scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf(" %c",&mode);
		if(mode=='B')
		{
			scanf("%d %s",&ta,t);
			tb=strcmp(ovf,t);
			if(tb==0) tb=0; else {tb=0; x=1; for(j=strlen(t)-1;j>=0;j--) {tb+=(t[j]-48)*x; x*=10;}}
			upd(1,1,n,ta,tb);
		}
		else
		{
			scanf("%d",&ta); chk=0;
			tb=query(1,1,n,1,ta);
			if(tb==0&&(chk==1||chk==-1)) {for(j=0;j<20;j++) printf("%c",ovf[j]); printf("\n");} else printf("%llu\n",tb);
		}
	}
	return 0;
}
