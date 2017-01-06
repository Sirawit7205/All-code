#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int a,b,c,cnt=0,t;
	scanf("%d %d %d",&a,&b,&c);
	while(not (a==1&&b==1&&c==1) )
	{
		cnt++;
		t=max(a,max(b,c));
		if(a==t) a/=2;
		else if(b==t) b/=2;
		else if(c==t) c/=2;
	}
	printf("%d",cnt);
	return 0;
}