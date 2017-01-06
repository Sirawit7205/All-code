#include<stdio.h>

int x,y,z,a[20]={},ans=0,use[20]={},st[20]={},h=0;

void perm(int c,int l)
{
	int i;
	if(c>l) {ans++; return;}
	for(i=1;i<=l;i++)
	{
		if(use[i]==0)
		{
		    if(h==0&&(a[i]==41||a[i]==93||a[i]==125)) continue;
			else if((a[i]==41&&st[h-1]!=41)||(a[i]==93&&st[h-1]!=93)||(a[i]==125&&st[h-1]!=125)) continue;
			else
			{
				use[i]=1;
				if(a[i]==40) {st[h]=41; h++;} else if(a[i]==91) {st[h]=93; h++;} else if(a[i]==123) {st[h]=125; h++;}
				else h--;
				perm(c+1,l);
				if(a[i]==41) {st[h]=41; h++;} else if(a[i]==93) {st[h]=93; h++;} else if(a[i]==125) {st[h]=125; h++;}
				else h--;
				use[i]=0;
			}
		}
	}
}

int main()
{
	int i,div=1;
	scanf("%d %d %d",&x,&y,&z);
	for(i=1;i<=x*2;i+=2) {a[i]=40; a[i+1]=41;}
	for(i=i;i<=(x*2)+(y*2);i+=2) {a[i]=91; a[i+1]=93;}
	for(i=i;i<=(x*2)+(y*2)+(z*2);i+=2) {a[i]=123; a[i+1]=125;}
	perm(1,(x+y+z)*2);
	if(x!=0) div*=x*x; if(y!=0) div*=y*y; if(z!=0) div*=z*z;
	if(x==3) div*=4; if(y==3) div*=4; if(z==3) div*=4;
	printf("%d",ans/div);
	return 0;
}
