#include  <stdio.h>

typedef struct
{
    int id;
    char name[10];
    char surname[10];
    int assign;
    int midterm;
    int final;
    int total;
}stds;
 
void menu1(stds student[],int i)
{
    int j;
    if(i==0)
        printf("There is no student in the program. Please go to menu 2.\n");
    else
    {
        printf("ID Name          Assign Midterm Final Total\n");
        for(j=0;j<i;j++)
        {
        printf("%-3d%-7s%-7s%-7d%-8d%-6d%-5d\n",student[j].id,student[j].name,student[j].surname,student[j].assign,student[j].midterm,student[j].final,student[j].total);
        }
    }
}
 
void menu2(stds student[],int i)
{
    /*Enter the student ID: 1
    Enter the name:  Souma
    Enter the surname: Yukihira
    Enter the assignment score: 20
    Enter the midterm exam score: 30
    Enter the final exam score: 28
    */
    char buffer[128];
	int j;
    printf("Enter the student ID: ");
    fgets(buffer,sizeof(buffer),stdin);
    sscanf(buffer,"%d",&student[i].id);
	for(j=0;j<i;j++)
	{
		if(student[i].id==student[j].id)
		{
			printf("Enter new ID ;");
			fgets(buffer,sizeof(buffer),stdin);
			sscanf(buffer,"%d",&student[i].id);
			j=-1;
		}
	}
        
    printf("Enter the name: ");
    fgets(buffer,sizeof(buffer),stdin);
    sscanf(buffer,"%s",student[i].name);
    
    printf("Enter the surname: ");
    fgets(buffer,sizeof(buffer),stdin);
    sscanf(buffer,"%s",student[i].surname);
    
    printf("Enter the student assign: ");
    fgets(buffer,sizeof(buffer),stdin);
    sscanf(buffer,"%d",&student[i].assign);
     
    printf("Enter the student midterm: ");
    fgets(buffer,sizeof(buffer),stdin);
    sscanf(buffer,"%d",&student[i].midterm);
    
    printf("Enter the student final: ");
    fgets(buffer,sizeof(buffer),stdin);
    sscanf(buffer,"%d",&student[i].final);
    
    student[i].total=student[i].assign+student[i].midterm+student[i].final;
} 
    
int menu3(stds student[],int i)
{
    char buffer[128],yn;
    int j,k,isPresent=0;
    printf("What student ID you want to delete? : ");
    fgets(buffer,sizeof(buffer),stdin);
    sscanf(buffer,"%d",&j);
    for(k=0;k<i;k++)
    {
        if(j==student[k].id)
        {
            j=k;
			isPresent=1;
            printf("ID Name          Assign Midterm Final Total\n");
            printf("%-3d%-7s%-7s%-7d%-8d%-6d%-5d\n",student[j].id,student[j].name,student[j].surname,student[j].assign,student[j].midterm,student[j].final,student[j].total);
            printf("Do you want to delete %s %s? (y/n): ",student[j].name,student[j].surname);
            fgets(buffer,sizeof(buffer),stdin);
            sscanf(buffer,"%c",&yn);
            if(yn=='y')
            {
                for(j;j<i;j++)
                {
                    student[j]=student[j+1];
                }  
				i--;
            }
			break;
		}      
    }
	if(isPresent==0) 
		printf("Sorry, there is no matching student ID in the program. Please try again.\n");
    return i;  
}  

void menu4(stds student[],int i)
/*Enter the min score: 72
Enter the max score: 100*/
{
    char buffer[128];
    int min,max,j;
    printf("Enter the min score: ");
    fgets(buffer,sizeof(buffer),stdin);
    sscanf(buffer,"%d",&min);
    printf("Enter the max score: ");
    fgets(buffer,sizeof(buffer),stdin);
    sscanf(buffer,"%d",&max);
    printf("ID Name          Assign Midterm Final Total\n");
    
    for(j=0;j<i;j++)
    {
        if(student[j].total>=min && student[j].total<=max)
            printf("%-3d%-7s%-7s%-7d%-8d%-6d%-5d\n",student[j].id,student[j].name,student[j].surname,student[j].assign,student[j].midterm,student[j].final,student[j].total);
    }
}
    

int main()
{
    stds student[50];
    int i=0;
    char buffer[128];
    int menu;
    
    while(menu!=5)
    {
        printf("Menu List\n");
        printf("1) Show all students\n");
        printf("2) Add new student\n");
        printf("3) Delete student\n");
        printf("4) Filter students by the total score\n");
        printf("5) Exit the program\n");
     
        printf ("Select the menu number: ");
        fgets(buffer,sizeof(buffer),stdin);
	    sscanf(buffer,"%d",&menu);
	
	    if(menu==1)
	        menu1(student,i);
	    else if(menu==2) 
	    {
	        menu2(student,i);
	        i++;
	    }
	    else if(menu==3) 
	    {
	        i=menu3(student,i);
	    }
	    else if(menu==4) 
	    {
	        menu4(student,i);
	    }
	}
	return 0;
}
