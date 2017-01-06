#include<stdio.h>
#include<string.h>
char dat[128]={},func[128]={};
int a,b,len;

void parse(int str,int end,int pnt)
{
	int lws=5,expc=0,l=str,r=end,i,paren=0;
	char t='\0';
	for(i=str;i<=end;i++)
	{
		if(dat[i]=='(') {paren++; if(lws>4) {lws=4; t=')'; }}
		else if(dat[i]==')') {paren--;}
		else if(dat[i]=='^'&&lws>3&&paren==0) {lws=3; t='^';}
		else if(dat[i]=='*'&&lws>2&&paren==0) {lws=2; t='*';}
		else if(dat[i]=='+'&&lws>1&&paren==0) {lws=1; t='+';}
	}
	paren=0;
	for(i=str;i<=end;i++)
	{
		if(dat[i]=='(') paren++; else if(dat[i]==')') paren--;
		if((dat[i]==t&&paren==0)||i==end) 
		{
			r=i-1; expc++; if(i==end&&t!=')') r++; if(t==')') l++;
			if(expc==func[pnt]-48) 
			{
				if(pnt<len) {parse(l,r,pnt+2); return;} else {a=l; b=r; return;}
			}
			else l=i+1;
			if(l>end) {a=-1; b=-1; return;}
		}
	}
}

void opt(int l)
{
	if(l<0) return;
	printf("op(%c,",func[l]);
	if(l==0) printf("p");
	opt(l-2);
	printf(")");
}

int main()
{
	int amt,i,j,k;
	scanf("%s",dat);
	scanf("%d",&amt);
	for(i=0;i<amt;i++)
	{
		scanf("\n%[^\n]%*c",func);
		len=strlen(func)-3; a=0; b=0;
		parse(0,strlen(dat)-1,0); opt(len); printf("=");
		if(a==-1&&b==-1) printf("null"); else for(k=a;k<=b;k++) printf("%c",dat[k]);
		printf("\n");
	}
	return 0;
}