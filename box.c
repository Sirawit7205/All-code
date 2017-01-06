#include<stdio.h>

char f[35][35]={};
int sa,sb,a=0;

void recur(int x,int y,int d)
{
	//printf("%d %d %d\n",x,y,d);
	f[x][y]='#';
	if(x==0) {a=1; return;}
	if(d!=3&&f[x-1][y]=='.'&&f[x-1][y+1]=='.'&&x-1>=0&&y+1<sb&&a==0) recur(x-1,y,1);
	if(d!=2&&f[x][y-1]=='.'&&f[x+1][y-1]=='.'&&x+1<=sa&&y-1>=0&&a==0) recur(x,y-1,4);
	if(d!=1&&f[x+2][y]=='.'&&f[x+2][y+1]=='.'&&x+2<=sa&&y+1<=sb&&a==0) recur(x+1,y,3);
	if(d!=4&&f[x][y+2]=='.'&&f[x+1][y+2]=='.'&&x+1<=sa&&y+2<=sb&&a==0) recur(x,y+1,2);
}

int main()
{
	int i;
	scanf("%d %d",&sa,&sb);
	for(i=0;i<sa;i++) scanf("%s",f[i]);
	for(i=0;i<sb;i++) if(a==0&&f[sa-2][i]=='.'&&f[sa-2][i+1]=='.'&&f[sa-1][i]=='.'&&f[sa-1][i+1]=='.'&&sa-2>=0&&i+1<sb) recur(sa-2,i,1);
	if(a==1) printf("yes"); else printf("no");
	return 0;
}
