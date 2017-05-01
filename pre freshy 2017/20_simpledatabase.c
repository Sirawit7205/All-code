#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int id;
	int scr[5];
	char name[55];
	char surname[55];
	int isUsing;
}DB;

DB db[55];
int stdcnt=0;

int cmp(const void *a, const void *b)
{
	DB *dbA = (DB *)a;
	DB *dbB = (DB *)b;
	if(dbA->isUsing == dbB->isUsing)
	{
		return(dbA->id - dbB->id);
	}
	else return(dbB->isUsing - dbA->isUsing);
}

void displayData(int idFirst, int idLast, int minScr, int maxScr)
{
	int i;
	printf("ID\tName\t\tAssign\tMidterm\tFinal\tTotal\n");
	for(i=idFirst;i<=idLast;i++)
	{
		if((minScr==-1&&maxScr==-1)||(db[i].scr[3]>=minScr&&db[i].scr[3]<=maxScr))
		{
			printf("%d\t%s %s\t%d\t%d\t%d\t%d\n",db[i].id,db[i].name,db[i].surname,db[i].scr[0],db[i].scr[1],db[i].scr[2],db[i].scr[3]);
		}
	}
}

void showAll()
{
	if(stdcnt == 0) printf("There is no student in the program. Please go to menu 2.\n");
	else displayData(0,stdcnt-1,-1,-1);
}

void addStd()
{
	int i,tmp,repeat;
	printf("Adding a new student\n");
	while(1)
	{
		repeat=0;
		printf("Enter the student ID: ");
		scanf("%d",&tmp);
		for(i=0;i<stdcnt;i++)
		{
			if(db[i].id == tmp) 
				repeat=1;
		}
		if(repeat==1) 
			printf("ID repeated, please try again.\n");
		else break;
	}
	db[stdcnt].id=tmp;
	printf("Enter the name: ");
	scanf("%s",db[stdcnt].name);
	printf("Enter the surname: ");
	scanf("%s",db[stdcnt].surname);
	printf("Enter the assignment score: ");
	scanf("%d",&db[stdcnt].scr[0]);
	printf("Enter the midterm exam score: ");
	scanf("%d",&db[stdcnt].scr[1]);
	printf("Enter the final exam score: ");
	scanf("%d",&db[stdcnt].scr[2]);
	db[stdcnt].scr[3]=db[stdcnt].scr[0]+db[stdcnt].scr[1]+db[stdcnt].scr[2];
	db[stdcnt].isUsing=1;
	stdcnt++;
	qsort(db,stdcnt,sizeof(DB),cmp);
}

void remStd()
{
	int i,tmp,repeat;
	char temp;
	printf("What student ID you want to delete?: ");
	scanf("%d",&tmp);
	repeat=0;
	for(i=0;i<stdcnt;i++)
	{
		if(tmp == db[i].id) 
			{
				repeat=1; 
				break;
			}
	}
	if(repeat==0) 
		printf("Sorry, there is no matching student ID in the program. Please try again.\n");
	else
	{
		displayData(i,i,-1,-1);
		printf("Do you want to delete %s %s? (y/n): ",db[i].name,db[i].surname);
		scanf(" %c",&temp);
		if(temp == 'y')
		{
			db[i].isUsing=0;
			qsort(db,stdcnt,sizeof(DB),cmp);
			stdcnt--;
			printf("Student deleted.\n");
		}
	}
}

void showInRange()
{
	int minScr,maxScr;
	printf("Enter the min score: ");
	scanf("%d",&minScr);
	printf("Enter the max score: ");
	scanf("%d",&maxScr);
	displayData(0,stdcnt-1,minScr,maxScr);
}

int main()
{
	int menu;
	do
	{
		printf("Menu List\n1) Show all students\n2) Add new student\n3) Delete student\n4) Filter students by the total score\n5) Exit the program\nSelect the menu number: ");
		scanf("%d",&menu);
		if(menu == 1) //Show all
		{
			showAll();
		}
		else if(menu == 2) //Add
		{
			addStd();
		}
		else if(menu == 3) //Delete
		{
			remStd();
		}
		else if(menu == 4) //List with range
		{
			showInRange();
		}
		printf("\n");
	}
	while(menu!=5);
	printf("Program is terminated");
	return 0;
}