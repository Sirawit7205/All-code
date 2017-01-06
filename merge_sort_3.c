#include<stdio.h>

int dat[10000]={},temp[10000]={},len;

//FILE * file;

void swp(int s, int e) {int t; t=dat[s]; dat[s]=dat[e]; dat[e]=t;}

void merge(int s, int e,int l)
{
	int i,m,ca,cb,a,b,pt,c;
	if(s>=e||l==1) return;
	else if(e-s==1) {if(dat[s]>dat[e]) swp(s,e); return;}
	else
	{
		if(l%2!=0) c=1; else c=0;
		merge(s,s+(l/2)-1+c,(l/2)+c); merge(s+(l/2)+c,e,l/2);
		ca=s; cb=s+(l/2)+c; a=0; b=0; pt=0;
		for(i=0;i<l;i++)
		{
			if(dat[ca]<=dat[cb]&&a<(l/2)+c||b>=l/2) {temp[pt]=dat[ca]; ca++; a++; pt++;}
			else if(dat[cb]<dat[ca]&&b<l/2||a>=(l/2)+c) {temp[pt]=dat[cb]; cb++; b++; pt++;}
		}
		for(i=0;i<l;i++) dat[s+i]=temp[i];
	}
}

int main()
{
	int i;
	scanf("%d",&len);
	for(i=0;i<len;i++) scanf("%d",&dat[i]);
	//file = fopen("input.txt","r");
	//for(i=0;i<len;i++) fscanf(file,"%d\n",&dat[i]);
	merge(0,len-1,len);
	for(i=0;i<len;i++) printf("%d ",dat[i]);
	return 0;
}