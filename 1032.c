#include<stdio.h>

int f[10][10]={},hsum[10]={},vsum[10]={},tmpl[10][10]={};

void chkin(int num)
{
	int i,j,k,l,sum;
	for(i=0;i<9;i+=3) for(j=0;j<9;j+=3)
	{
		sum=0;
		for(k=i;k<i+3;k++) for(l=j;l<j+3;l++)
		{sum+=f[k][l];}
		if(sum!=45) return;
	}
	printf("%d\n",num);
}

int main()
{
	int a,i,j,k,x;
	scanf("%d",&a);
	for(i=0;i<9;i++) for(j=0;j<9;j++) scanf("%d",&tmpl[i][j]);
	for(i=1;i<=a;i++)
	{
		x=0;
		for(j=0;j<9;j++)
		{
			for(k=0;k<9;k++)
			{
				scanf("%d",&f[j][k]);
				if(f[j][k]!=tmpl[j][k]&&tmpl[j][k]!=0) x=1;
				hsum[j]+=f[j][k];
				vsum[k]+=f[j][k];
			}
		}		
		for(j=0;j<9;j++) {if(hsum[j]!=45||vsum[j]!=45) x=1; hsum[j]=0; vsum[j]=0;}
		if(x==1) continue;
		else {chkin(i);}
	}
	printf("END");
	return 0;
}