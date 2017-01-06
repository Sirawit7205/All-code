#include<stdio.h>
int w[100];
int sol[100];
void recur(int level,int lim ,int _l)
{
    int i;
	if( level == _l ){
		for(i=0;i<level;i++)
			printf("%d",w[i]);
		printf("\n");
	} else {
		for(i=1;i<=lim;i++){
			if( sol[i] == 0 ){
				sol[i] = 1 ;
				w[level] = i ;
				recur( level+1,lim,_l);
				sol[i] = 0 ;
			}
		}
	}
}
int main(){
	recur(0,10,1);
	return 0;
}
