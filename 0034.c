#include<stdio.h>

int main()
{
	int i,j,a,b,c,na,nb,nc,nd,ch=0,t;
	scanf("%d %d %d",&a,&b,&c);
	if(c<0) c*=-1;
	for(i=1;i<=a;i++)
	{
		if(a%i!=0) continue;
		else
		{
			if(c==0&&b==0) {na=i; nb=0; nc=a/i; nd=0; ch=1; break;}
			for(j=c;j>=1;j--)
			{
				if(c%j!=0) continue;
				else
				{
					//printf("%d %d\n",i,j);
					if((i*j)+((a/i)*(c/j))==b)
					{
						na=i; nb=c/j; nc=a/i; nd=j; ch=1; break;
					}
					else if((i*j)+((a/i)*(c/j)*-1)==b)
					{
						na=i; nb=(c/j)*-1; nc=a/i; nd=j; ch=1; break;
					}
					else if((i*j*-1)+((a/i)*(c/j))==b)
					{
						na=i; nb=c/j; nc=a/i; nd=j*-1; ch=1; break;
					}
					else if((i*j*-1)+((a/i)*(c/j)*-1)==b)
					{
						na=i; nb=(c/j)*-1; nc=a/i; nd=j*-1; ch=1; break;
					}
				}
			}
		}
		if(ch==1) break;
	}
	if(nc<na)
	{
		t=na;
		na=nc;
		nc=t;
	}
	else if(na==nc)
	{
		if(nd<nb)
		{
			t=nb;
			nb=nd;
			nd=t;
		}
	}
	if(ch==1) printf("%d %d %d %d",na,nb,nc,nd); else printf("No Solution");
	return 0;
}