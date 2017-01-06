#include<stdio.h>

int rule[10]={};
char cell[100]={},temp[100]={},t[1]={};

int main()
{
    int i,j,n,len=0;
    scanf("%d",&n);
    if(n<0||n>255) {printf("Unknown rule."); return 0;}
    for(i=0;i<8;i++)
    {
        rule[i]=n%2;
        n=n/2;
    }
    scanf("%s",cell);
    while(cell[len]!='\0') len++;
    if(len>80) {printf("Input Exceeded limits."); return 0;}
    for(i=0;i<60;i++)
    {
        temp[0]=cell[0]; temp[len-1]=cell[len-1];
        for(j=1;j<=len-2;j++)
        {
            if(cell[j-1]=='0'&&cell[j]=='0'&&cell[j+1]=='0') sprintf(t,"%d",rule[0]);
            else if(cell[j-1]=='0'&&cell[j]=='0'&&cell[j+1]=='1') sprintf(t,"%d",rule[1]);
            else if(cell[j-1]=='0'&&cell[j]=='1'&&cell[j+1]=='0') sprintf(t,"%d",rule[2]);
            else if(cell[j-1]=='0'&&cell[j]=='1'&&cell[j+1]=='1') sprintf(t,"%d",rule[3]);
            else if(cell[j-1]=='1'&&cell[j]=='0'&&cell[j+1]=='0') sprintf(t,"%d",rule[4]);
            else if(cell[j-1]=='1'&&cell[j]=='0'&&cell[j+1]=='1') sprintf(t,"%d",rule[5]);
            else if(cell[j-1]=='1'&&cell[j]=='1'&&cell[j+1]=='0') sprintf(t,"%d",rule[6]);
            else sprintf(t,"%d",rule[7]);
            temp[j]=t[0];
        }
        for(j=0;j<len;j++) {cell[j]=temp[j]; if(cell[j]=='1') printf("%c",254); else printf("%c",32);}
        printf("\n");
    }
    return 0;
}
