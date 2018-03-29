#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

int separateString(char cmd[], char sprCmd[][50]);
void addStringDelim(char cmd[]);
void convertSignOperator(char sprCmd[][50], int cmdCount);
int syntaxCheck(char sprCmd[][50], int cmdCount);
int getSyntaxType(char cmd[]);
int functionCheck(char cmd[]);

int main()
{
	int i,cmdCount,res;
	char cmd[5000]={}, sprCmd[100][50]={};

	do {
		printf("\nexpression> ");
		gets(cmd);

		for(i=0;i<strlen(cmd);i++)				//for all characters
			cmd[i]=tolower(cmd[i]);				//convert all to lowercase
		addStringDelim(cmd);					//add separation spaces
		cmdCount=separateString(cmd,sprCmd);	//split string with spaces
		convertSignOperator(sprCmd,cmdCount);
		res=syntaxCheck(sprCmd,cmdCount);

		//for(i=0;i<cmdCount;i++)
		//	printf("%s\n",sprCmd[i]);

		if(res==-1)
			printf("answer> error\n");
		else
			printf("answer> OK\n");
	} while(strcmp(sprCmd[0],"stop")!=0);
	return 0;
}

void addStringDelim(char cmd[])
{
	int i;
	char buff[5000]={},last[5000]={};

	for(i=0;i<strlen(cmd);i++)
	{
		if(strchr("+-*/^()",cmd[i])!=NULL)
			sprintf(buff,"%s %c ",last,cmd[i]);
		else
			sprintf(buff,"%s%c",last,cmd[i]);
		strcpy(last,buff);
	}
	strcpy(cmd,buff);
}

int separateString(char cmd[], char sprCmd[][50])
{
	int count=0;
	char *ptr;

	ptr = strtok(cmd," ");
	while(ptr!=NULL)
	{
		strcpy(sprCmd[count],ptr);
		ptr = strtok(NULL," ");
		count++;
	}

	return count;
}

void convertSignOperator(char sprCmd[][50], int cmdCount)
{
	int i;

	if(strcmp(sprCmd[0],"-")==0)
		strcpy(sprCmd[0],"!");

	for(i=1;i<cmdCount;i++)
	{
		if(strcmp(sprCmd[i+1],"-")==0 && strstr("+-*/^(",sprCmd[i]))
			strcpy(sprCmd[i+1],"!");
	}
}

int syntaxCheck(char sprCmd[][50], int cmdCount)
{
	int res=0,i,parenCount=0,curType=0,nextType=0;

	for(i=0;i<cmdCount&&res==0;i++)
	{
		//0=start 1=num 2=op 3=sign 4=fn 5=( 6=) 7=stop
		curType=nextType;
		nextType=getSyntaxType(sprCmd[i]);

		if(nextType==-1)
			res=-1;

		if(nextType==5)
			parenCount++;
		if(nextType==6&&parenCount==0)
			res=-1;
		else if(nextType==6)
            parenCount--;

		if((curType==0)&&!(nextType==1||nextType==3||nextType==4||nextType==5))
			res=-1;
		else if((curType==1)&&!(nextType==2||nextType==6||nextType==7))
			res=-1;
		else if((curType==2)&&!(nextType==1||nextType==4||nextType==5))
			res=-1;
		else if((curType==3)&&!(nextType==1||nextType==4||nextType==5))
			res=-1;
		else if((curType==4)&&!(nextType==5))
			res=-1;
		else if((curType==5)&&!(nextType==1||nextType==3|nextType==4||nextType==5))
			res=-1;
		else if((curType==6)&&!(nextType==2||nextType==6||nextType==7))
			res=-1;
	}

	if(!(nextType==1||nextType==6))
		res=-1;
	if(parenCount!=0)
		res=-1;

	return res;
}

int getSyntaxType(char cmd[])
{
	double temp;
	char *endptr;

	temp=strtod(cmd,&endptr);

	if((*endptr)==0)
		return 1;
	else if(strchr("+-*/^",cmd[0])!=NULL)
		return 2;
	else if(strcmp(cmd,"!")==0)
		return 3;
	else if(functionCheck(cmd)==0)
		return 4;
	else if(strcmp(cmd,"(")==0)
		return 5;
	else if(strcmp(cmd,")")==0)
		return 6;
	else
		return -1;
}

int functionCheck(char cmd[])
{
	int i,res=-1;
	char funcName[10][5]={"sin","cos","tan","asin","acos","atan","sqrt","log","exp","abs"};

	for(i=0;i<10;i++)
		if(strcmp(cmd,funcName[i])==0)
			res=0;

	return res;
}
