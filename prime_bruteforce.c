#include<stdio.h>
#define c 2

int main()
{
    int prime=100000,m=2,i,a;
    while(m<=prime) //min to max limits
    {
        a=0; //a=0 is prime
        for(i=2;i<=(m-c)/2;i++) //divide first half only
        {
            if(m%i==0) {a=1; break;} //if divide OK then break with a=1
            if(i>2) i++; //skip all even number except 2
        }
        if(a==0||m==2) printf("%d ",m);  //if a=0 or 2 print out
        m++; //check next

    }
    return 0;
}
