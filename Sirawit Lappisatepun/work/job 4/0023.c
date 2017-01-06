#include<stdio.h>

int main()
{
    int d,m,cal;
    scanf("%d %d",&d,&m);
    if(m==1) cal=d;
    else if(m==2) cal=d+31;
    else if(m==3) cal=d+59;
    else if(m==4) cal=d+90;
    else if(m==5) cal=d+120;
    else if(m==6) cal=d+151;
    else if(m==7) cal=d+181;
    else if(m==8) cal=d+212;
    else if(m==9) cal=d+243;
    else if(m==10) cal=d+273;
    else if(m==11) cal=d+304;
    else cal=d+334;
    cal=cal%7;
    if(cal==1) printf("Thursday");
    else if(cal==2) printf("Friday");
    else if(cal==3) printf("Saturday");
    else if(cal==4) printf("Sunday");
    else if(cal==5) printf("Monday");
    else if(cal==6) printf("Tuesday");
    else printf("Wednesday");
    return 0;
}
