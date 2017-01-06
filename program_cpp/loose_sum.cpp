#include<iostream>
#include<cstdio>

using namespace std;

long long int m[2005][2005]={};

int main()
{
	 int i,j,k,q,t;
	 for(i=1;i<=2000;i++)
	 {
	 for(j=1;j<i;j++) 
	 {
		 if(j-1<i-j) m[i][j]=m[i-j][j-1]; else m[i][j]=m[i-j][i-j];
		 m[i][j]+=m[i][j-1];
		 m[i][j]%=1000003;
	 }
	 m[i][i]++;
	 m[i][i]+=m[i][i-1];
	 m[i][i]%=1000003;
	 }
	 scanf("%d",&q);
	 for(i=0;i<q;i++) {scanf("%d",&t); printf("%lld\n",m[t][t]%1000003);}
	 return 0;
}