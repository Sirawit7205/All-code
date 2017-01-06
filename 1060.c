#include<stdio.h>

char mnt[15][100]={};

void inst(int str,int h,int sth)
{
	int i,j;
	for(i=1;i<=h;i++)
	{
		if(mnt[i+sth][str-i]=='\\') mnt[i+sth][str-i]='v'; else if(mnt[i+sth][str-i]!='X') mnt[i+sth][str-i]='/';
		for(j=1;j<=(i-1)*2;j++) mnt[i+sth][str+j-i]='X';
		if(mnt[i+sth][str+j-i]=='/') mnt[i+sth][str+j-i]='v'; else if(mnt[i+sth][str+j-i]!='X') mnt[i+sth][str+j-i]='\\';
	}
}

int main()
{
	int i,j,amt,ta,tb,mxa=0,mxb=0,temp[25][3]={};
	scanf("%d",&amt);
	for(i=0;i<amt;i++)
	{
		scanf("%d %d",&ta,&tb);
		if(tb>mxb) mxb=tb;
		if(ta+(tb*2)-1>mxa) mxa=ta+(tb*2)-1;
		temp[i][0]=ta; temp[i][1]=tb;
	}
	for(i=0;i<amt;i++)
	{
		inst(temp[i][0]+temp[i][1],temp[i][1],mxb-temp[i][1]);
	}
	for(i=1;i<=mxb;i++)
	{
		for(j=1;j<=mxa;j++) if(mnt[i][j]==NULL) printf("."); else printf("%c",mnt[i][j]);
		printf("\n");
	}
	return 0;
}