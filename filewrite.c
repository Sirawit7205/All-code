#include<stdio.h>
#include<string.h>
#include<conio.h>

int main()
{
	int i,j,k,count=0;
	char name[15]={};
	FILE *fp;
	
	fp=fopen("D:/All-code/output.txt","w+");
	
	for(i=97;i<123;i++)
	{
		for(j=97;j<123;j++)
		{
			for(k=97;k<123;k++)
			{
				strcat(name,"www.rb");
				name[6]=i;
				name[7]=j;
				name[8]=k;
				strcat(name,".com\n");

				fputs(name,fp);
				count++;
				memset(name,0,sizeof name);
				
				if(count==100)
				{
					fclose(fp);
					count=0;
					
					printf("100 addresses reached, press any key to continue.\n");
					getch();
					fp=fopen("D:/All-code/output.txt","w+");
				}
			}
		}
	}
	
	fclose(fp);
}