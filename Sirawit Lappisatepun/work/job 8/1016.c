#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    char dat[3100]={},num[4]={};
    int len,i,mode=0;
    double con,x=0,y=0,t,ans;
    gets(dat);
    len=strlen(dat);
    for(i=0;i<len;i++)
    {
        if(dat[i]=='*') break;

        if(dat[i]>=48&&dat[i]<=57)
        {
            if(dat[i+1]>=48&&dat[i+1]<=57&&i<len)
            {
                if(dat[i+2]>=48&&dat[i+2]<=57&&i<len)
                {
                    num[0]=dat[i]; num[1]=dat[i+1]; num[2]=dat[i+2]; i+=3;
                }
                else
                {
                    num[0]=dat[i]; num[1]=dat[i+1]; i+=2;
                }
            }
            else
            {
                num[0]=dat[i]; i+=1;
            }
            con=atof(num);
            num[0]=0; num[1]=0; num[2]=0;
        }
        if(dat[i]=='N'&&dat[i+1]==' '&&i<len) mode=1;
        else if(dat[i]=='N'&&dat[i+1]=='E'&&i<len) mode=2;
        else if(dat[i]=='E'&&dat[i+1]==' '&&i<len) mode=3;
        else if(dat[i]=='S'&&dat[i+1]=='E'&&i<len) mode=4;
        else if(dat[i]=='S'&&dat[i+1]==' '&&i<len) mode=5;
        else if(dat[i]=='S'&&dat[i+1]=='W'&&i<len) mode=6;
        else if(dat[i]=='W'&&dat[i+1]==' '&&i<len) mode=7;
        else if(dat[i]=='N'&&dat[i+1]=='W'&&i<len) mode=8;
        if(mode%2==0) i+=2;
        else if(mode%2!=0) i++;

        if(mode==1) y+=con;
        else if(mode==3) x+=con;
        else if(mode==5) y-=con;
        else if(mode==7) x-=con;
        else
        {
            t=con*(sqrt(2)/2);
            //printf("%.3f\n",t);
            if(mode==2) {x+=t; y+=t;}
            else if(mode==4) {x+=t; y-=t;}
            else if(mode==6) {x-=t; y-=t;}
            else if(mode==8) {x-=t; y+=t;}
        }
    }
    ans=sqrt(pow(0-x,2)+pow(0-y,2));
    printf("%.3f %.3f\n",x,y);
    printf("%.3f",ans);
    return 0;
}
