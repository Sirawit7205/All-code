#include<stdio.h>
#include<stdlib.h>

long long int a,b;

int main()
{
	long long int l,r,mid,ta,tb,tmp;
	scanf("%lld %lld",&a,&b);
	l=1; r=a/2; mid=(l+r)/2;
	while(l<=r)
	{
		ta=mid; tb=a-mid;
		if(b%ta==0&&b%tb==0) {printf("%lld %lld",ta,tb); return 0;}
        tmp=b/ta; tmp/=tb;
        if(tmp==0) r=mid-1;
        else l=mid+1;
        /*if((ta*tb)/tb!=ta) r=mid-1;
        else
        {
            if(ta*tb==b) {printf("%lld %lld",ta,tb); return 0;}
            else if(ta*tb<b) l=mid+1;
            else if(ta*tb>b) r=mid-1;
        }*/
        mid=(l+r)/2;
	}
	printf("Goodbye T-T");
	return 0;
}
