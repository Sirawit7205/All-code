#include<stdio.h>
#include<string.h>
#include<stdbool.h>

unsigned long long int str[2000000]={},n,temp;
bool ver[2000000]={};
char ovf[25]={'1','8','4','4','6','7','4','4','0','7','3','7','0','9','5','5','1','6','1','6'},t[25]={};

void upd(int nd,int l,int r,int k,unsigned long long int v)
{
	int mid=(l+r)/2;
	if(l==r) {str[nd]=v; if(v==0) ver[nd]=true; return;}
	else if(k<=mid) upd(nd*2,l,mid,k,v);
	else upd((nd*2)+1,mid+1,r,k,v);
	if(v==0&&str[nd]<1) {ver[nd]=true; str[nd]=v;} else if(str[nd]<v) {ver[nd]=false; str[nd]=v;}
}

unsigned long long int query(int nd,int l,int r,int tl,int tr)
{
	int mid=(l+r)/2,x,p=0,q=0;
	unsigned long long int ta,tb;
	if(l==tl&&r==tr) {if(str[nd]==0&&ver[nd]==true) temp=1; return str[nd];}
	if(tr>mid) {if(tl>mid) x=tl; else x=mid+1; ta=query((nd*2)+1,mid+1,r,x,tr); if(ta==0&&temp==1) {p=1; temp=0;}} else ta=0;
	if(tl<=mid) {if(tr<=mid) x=tr; else x=mid; tb=query(nd*2,l,mid,tl,x); if(tb==0&&temp==1) {q=1; temp=0;}} else tb=0;
    if(p==1) ta=1; if(q==1) tb=1;
	if(ta>=tb)
    {
        if(ta==1&&p==1) {temp=1; return 0;} else return ta;
    }
    else {if(tb==1&&q==1) {temp=1; return 0;} else return tb;}
}

int main()
{
	int m,i,j,ta;
	unsigned long long int tb,x;
	char mode;
	scanf("%llu %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf(" %c",&mode);
		if(mode=='B')
		{
			scanf("%d %s",&ta,t);
			tb=strcmp(ovf,t);
			if(tb==0) tb=18446744073709551615; else {tb=0; x=1; for(j=strlen(t)-1;j>=0;j--) {tb+=(t[j]-48)*x; x*=10;} tb--;}
			//if(tb!=0) upd(1,1,n,ta,tb,0); else upd(1,1,n,ta,tb,1);
			upd(1,1,n,ta,tb);
		}
		else
		{
			scanf("%d",&ta);
			tb=query(1,1,n,1,ta);
			if(tb==18446744073709551615) {for(j=0;j<20;j++) printf("%c",ovf[j]); printf("\n");}
			else if(tb==0&&temp==0) printf("%llu\n",tb); else printf("%llu\n",tb+1);
		}
	}
	return 0;
}
