#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

typedef struct linkedlist {
	char command[50];
	struct linkedlist *next;
} lnkdlist;

typedef struct double_stack {
	double num;
	struct double_stack *next;
} dstack;

void displayHelp();
int separateString(char cmd[], char sprCmd[][50]);
void addStringDelim(char cmd[]);
void convertSignOperator(char sprCmd[][50], int cmdCount);
int syntaxCheck(char sprCmd[][50], int cmdCount);
int getSyntaxType(char cmd[]);
int isFunction(char cmd[]);
int isVariable(char cmd[]);
int isConstant(char cmd[]);
int calculate(char sprCmd[][50], int cmdCount, double *lastAns, double var[]);
void convertPostfix(char cmd[][50], int cmdCount, double lastAns, lnkdlist **qFirst, lnkdlist **qLast);
int calculatePostfix(double *lastAns, double var[], lnkdlist **qFirst, lnkdlist **qLast);
void insertConstant(lnkdlist **ptr, double lastAns);
int priorityCheck(char cmd[]);
lnkdlist *createNode(char cmd[]);
void insertQueue(lnkdlist **first, lnkdlist **last, lnkdlist *ptr);
void insertStack(lnkdlist **first, lnkdlist **last, lnkdlist *ptr);
lnkdlist *popData(lnkdlist **first, lnkdlist **last);

int main()
{
	int i,cmdCount,res;
	char cmd[5000]={}, sprCmd[100][50]={};
	double lastAns=0, var[11]={};

	do {
		printf("\nexpression> ");
		gets(cmd);

		for(i=0;i<strlen(cmd);i++)				//for all characters
			cmd[i]=tolower(cmd[i]);				//convert all to lowercase
		addStringDelim(cmd);					//add separation spaces
		cmdCount=separateString(cmd,sprCmd);	//split string with spaces
		convertSignOperator(sprCmd,cmdCount);
		res=syntaxCheck(sprCmd,cmdCount);

		if(res==-1)
			printf("Syntax check> ERROR\n");
		else
        {
            printf("Syntax check> OK\n");

            if(strcmp(sprCmd[1],"help")==0)
                displayHelp();
            else if(strcmp(sprCmd[1],"end")==0)
                printf("End program.\n");
            else
            {
                res=calculate(sprCmd,cmdCount,&lastAns,var);
                if(res==-1)
                    printf("Answer> ERROR\n");
                else
                    printf("Answer> %g\n",lastAns);
            }
        }
		//for(i=1;i<=cmdCount;i++)
		//	printf("%s\n",sprCmd[i]);

	} while(strcmp(sprCmd[1],"end")!=0);

	printf("Program written by 60070501064 Sirawit Lappisatepun\n");
	return 0;
}

void displayHelp()
{
	printf("\n===Help===\n");
	printf("-> Enter problems in infix form.\n");
	printf("-> All angles in degrees.\n");
	printf("-> Supported operations: + - * / ^\n");
	printf("-> Supported functions: sin cos tan asin acos atan sqrt log exp abs\n");
	printf("-> Supported constants: pi e c g ans(zero init)\n");
	printf("-> Supported variables (assign with =, zero init): x1-x10\n");
}

void addStringDelim(char cmd[])
{
	int i;
	char buff[5000]={},last[5000]={};

	for(i=0;i<strlen(cmd);i++)
	{
		if(strchr("+-*/^()=",cmd[i])!=NULL)
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
		strcpy(sprCmd[count+1],ptr);
		ptr = strtok(NULL," ");
		count++;
	}

	return count;
}

void convertSignOperator(char sprCmd[][50], int cmdCount)
{
	int i;

	if(strcmp(sprCmd[1],"-")==0)
		strcpy(sprCmd[1],"!");

	for(i=2;i<=cmdCount;i++)
	{
		if(strcmp(sprCmd[i+1],"-")==0 && strstr("+-*/^(",sprCmd[i]))
			strcpy(sprCmd[i+1],"!");
	}
}

int syntaxCheck(char sprCmd[][50], int cmdCount)
{
	int res=0,i,parenCount=0,curType=0,nextType=0;

	for(i=1;i<=cmdCount&&res==0;i++)
	{
		//0=start 1=num/const 2=op 3=sign 4=fn 5=( 6=) 7=var 8== 9=help 10=end
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

		if((curType==0)&&!(nextType==1||nextType==3||nextType==4||nextType==5||nextType==7||nextType==9||nextType==10))
			res=-1;
		else if((curType==1)&&!(nextType==2||nextType==6||nextType==10))
			res=-1;
		else if((curType==2)&&!(nextType==1||nextType==3||nextType==4||nextType==5||nextType==7))
			res=-1;
		else if((curType==3)&&!(nextType==1||nextType==4||nextType==5||nextType==7))
			res=-1;
		else if((curType==4)&&!(nextType==5))
			res=-1;
		else if((curType==5)&&!(nextType==1||nextType==3||nextType==4||nextType==5||nextType==7))
			res=-1;
		else if((curType==6)&&!(nextType==2||nextType==6||nextType==10))
			res=-1;
		else if((curType==7)&&!(nextType==2||nextType==3||nextType==6||nextType==8||nextType==10))
			res=-1;
		else if((curType==8)&&!(nextType==1||nextType==3||nextType==4||nextType==5||nextType==7))
			res=-1;
	}

	if(!(nextType==1||nextType==6||nextType==7||nextType==9||nextType==10))
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
	else if(isConstant(cmd)!=-1)
		return 1;
	else if(strchr("+-*/^",cmd[0])!=NULL)
		return 2;
	else if(strcmp(cmd,"!")==0)
		return 3;
	else if(isFunction(cmd)!=-1)
		return 4;
	else if(strcmp(cmd,"(")==0)
		return 5;
	else if(strcmp(cmd,")")==0)
		return 6;
	else if(isVariable(cmd)!=-1)
		return 7;
	else if(strcmp(cmd,"=")==0)
		return 8;
	else if(strcmp(cmd,"help")==0)
		return 9;
	else if(strcmp(cmd,"end")==0)
		return 10;
	else
		return -1;
}

int isFunction(char cmd[])
{
	int i,res=-1;
	char funcName[10][5]={"sin","cos","tan","asin","acos","atan","sqrt","log","exp","abs"};

	for(i=0;i<10;i++)
		if(strcmp(cmd,funcName[i])==0)
			res=i;

	return res;
}

int isVariable(char cmd[])
{
	int i,res=-1;
	char varName[10][5]={"x1","x2","x3","x4","x5","x6","x7","x8","x9","x10"};

	for(i=0;i<10;i++)
		if(strcmp(cmd,varName[i])==0)
			res=i;

	return res;
}

int isConstant(char cmd[])
{
	int i,res=-1;
	char constName[5][5]={"pi","e","c","g","ans"};

	for(i=0;i<5;i++)
	if(strcmp(cmd,constName[i])==0)
		res=i;

	return res;
}

int calculate(char cmd[][50], int cmdCount, double *lastAns, double var[])
{
	int res;
	lnkdlist *qFirst=NULL, *qLast=NULL, *temp;

	convertPostfix(cmd,cmdCount,*lastAns,&qFirst,&qLast);
	res=calculatePostfix(lastAns,var,&qFirst,&qLast);

	/*temp=qFirst;
	while(temp!=NULL)
	{
		printf("%s ",temp->command);
		temp = temp -> next;
	}
	printf("\n");*/

	return res;
}

void convertPostfix(char cmd[][50], int cmdCount, double lastAns, lnkdlist **qFirst, lnkdlist **qLast)
{
	int i,type,chkA,chkB;
	lnkdlist *sFirst=NULL, *sLast=NULL, *ptr, *temp;

	strcpy(cmd[0],"(");
	strcpy(cmd[cmdCount+1],")");
	cmdCount+=2;

	for(i=0;i<cmdCount;i++)
	{
		ptr=createNode(cmd[i]);
		type=getSyntaxType(cmd[i]);

		if(type==1)
		{
			insertConstant(&ptr,lastAns);
			insertQueue(qFirst,qLast,ptr);
		}
		else if(type==7)
			insertQueue(qFirst,qLast,ptr);
		else if((type>=2&&type<=4)||type==8)
		{
			chkA=priorityCheck(ptr->command);

			do {
				chkB=priorityCheck(sFirst->command);
				if(chkB>=chkA)
				{
					temp=popData(&sFirst,&sLast);
					insertQueue(qFirst,qLast,temp);
				}
			} while(chkB>=chkA&&sFirst!=NULL);

			insertStack(&sFirst,&sLast,ptr);
		}
		else if(type==5)
			insertStack(&sFirst,&sLast,ptr);
		else if(type==6)
		{
			while(strcmp(sFirst->command,"(")!=0)
			{
				temp=popData(&sFirst,&sLast);
				insertQueue(qFirst,qLast,temp);
			}
			temp=popData(&sFirst,&sLast);
		}
	}
}

int calculatePostfix(double *lastAns, double var[], lnkdlist **qFirst, lnkdlist **qLast)
{
	int type, fType, varA, varB;
	double numA, numB, ans;
	char *temp;
	lnkdlist *sFirst=NULL, *sLast=NULL;
	lnkdlist *ptr, *ptrA, *ptrB, *new;

	ptr=popData(qFirst,qLast);
	while(ptr!=NULL)
	{
		type=getSyntaxType(ptr->command);
		if(type==1||type==7)
			insertStack(&sFirst,&sLast,ptr);
		else if(type==2||type==8)
		{
			ptrB=popData(&sFirst,&sLast);
			ptrA=popData(&sFirst,&sLast);
			varB=isVariable(ptrB->command);
			varA=isVariable(ptrA->command);

			if(varB!=-1) numB=var[varB];
			else numB=strtod(ptrB->command,&temp);
			if(varA!=-1) numA=var[varA];
			else numA=strtod(ptrA->command,&temp);

			if(strcmp(ptr->command,"+")==0)
				ans=numA+numB;
			else if(strcmp(ptr->command,"-")==0)
				ans=numA-numB;
			else if(strcmp(ptr->command,"*")==0)
				ans=numA*numB;
			else if(strcmp(ptr->command,"/")==0)
			{
				if(numB!=0) ans=numA/numB;
				else return -1;
			}
			else if(strcmp(ptr->command,"^")==0)
				ans=pow(numA,numB);
			else if(strcmp(ptr->command,"=")==0)
				ans=var[varA]=numB;

			sprintf(temp,"%g",ans);
			new=createNode(temp);
			insertStack(&sFirst,&sLast,new);
			free(ptrB);
			free(ptrA);
			free(ptr);
		}
		else if(type==3||type==4)
		{
			ptrA=popData(&sFirst,&sLast);
			varA=isVariable(ptrA->command);

			if(varA!=-1) numA=var[varA];
			else numA=strtod(ptrA->command,&temp);

			fType=isFunction(ptr->command);
			if(fType>=0&&fType<=2) numA=(numA*M_PI)/180;

			if(strcmp(ptr->command,"!")==0)
				ans=numA*-1;
			else if(fType==0)
				ans=sin(numA);
			else if(fType==1)
				ans=cos(numA);
			else if(fType==2)
				ans=tan(numA);
			else if(fType==3)
				ans=asin(numA);
			else if(fType==4)
				ans=acos(numA);
			else if(fType==5)
				ans=atan(numA);
			else if(fType==6)
			{
				if(numA>=0) ans=sqrt(numA);
				else return -1;
			}
			else if(fType==7)
				ans=log(numA);
			else if(fType==8)
				ans=exp(numA);
			else if(fType==9)
				ans=abs(numA);

            if(fType>=3&&fType<=5) ans=(ans*180)/M_PI;
			sprintf(temp,"%g",ans);
			new=createNode(temp);
			insertStack(&sFirst,&sLast,new);
			free(ptrA);
			free(ptr);
		}
		ptr = popData(qFirst,qLast);
	}

	ptr=popData(&sFirst,&sLast);
	(*lastAns)=strtod(ptr->command,&temp);
	return 0;
}

void insertConstant(lnkdlist **ptr, double lastAns)
{
	int type=isConstant((*ptr)->command);
	char temp[50]={};

	if(type==0)
		strcpy((*ptr)->command,"3.14159265358979323846");	//pi
	else if(type==1)
		strcpy((*ptr)->command,"2.71828182845904523536");	//e
	else if(type==2)
		strcpy((*ptr)->command,"299792458");				//c
	else if(type==3)
		strcpy((*ptr)->command,"9.80665");					//g
	else if(type==4)
	{
		sprintf(temp,"%g",lastAns);
		strcpy((*ptr)->command,temp);						//ans
	}
}

int priorityCheck(char cmd[])
{
	if(strcmp(cmd,"=")==0)
		return 1;
	else if(strcmp(cmd,"+")==0||strcmp(cmd,"-")==0)
		return 2;
	else if(strcmp(cmd,"*")==0||strcmp(cmd,"/")==0)
		return 3;
	else if(strcmp(cmd,"^")==0)
		return 4;
	else if(strcmp(cmd,"!")==0)
		return 5;
	else if(isFunction(cmd)!=-1)
		return 6;
	else
		return 0;
}

lnkdlist *createNode(char cmd[])
{
	lnkdlist *ptr;

	ptr = (lnkdlist *) malloc(sizeof(lnkdlist));
	strcpy(ptr->command,cmd);
	ptr -> next = NULL;

	return ptr;
}

void insertQueue(lnkdlist **first, lnkdlist **last, lnkdlist *ptr)
{
    ptr -> next = NULL;

	if((*first)==NULL)
		(*first)=(*last)=ptr;
	else
	{
		(*last) -> next = ptr;
		(*last) = ptr;
	}
}

void insertStack(lnkdlist **first, lnkdlist **last, lnkdlist *ptr)
{
    ptr -> next = NULL;

	if((*first)==NULL)
		(*first)=(*last)=ptr;
	else
	{
		ptr -> next = (*first);
		(*first) = ptr;
	}
}

/*void insertNumberStack(dstack **first, dstack **last, dstack *ptr)
{
    ptr -> next = NULL;

	if((*first)==NULL)
		(*first)=(*last)=ptr;
	else
	{
		ptr -> next = (*first);
		(*first) = ptr;
	}
}*/

lnkdlist *popData(lnkdlist **first, lnkdlist **last)
{
	lnkdlist *temp;

	if((*first)==NULL)
		return NULL;
    else if((*first)==(*last))
    {
        temp=(*first);
        (*first)=(*last)=NULL;
        return temp;
    }
	else
	{
		temp=(*first);
		(*first) = (*first) -> next;
		return temp;
	}
}
