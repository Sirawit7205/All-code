#include  <stdio.h>
#include  <math.h>

void input(char buffer[],int i,char name[][10],float score[])
{
    for (i=0;i<10;i++)
    {
	    printf ("Enter name and score of student %d :",i+1);
	    fgets(buffer,sizeof(buffer),stdin);
	    sscanf(buffer,"%s %f",name[i],&score[i]);   
    }
}

float findmean(float score[],int i)
{
    float mean=0;
    for (i=0;i<10;i++)
    {
        mean=(mean+score[i]);
    }
    mean=mean/10;
    return mean;
}

float findsd(float score[],float mean,int i)
{
    float sd=0,sum=0;
    for (i=0;i<10;i++)
    {
        sd=(score[i]-mean);
        sd=sd*sd;
        sum=sum+sd;
    }
    sum=sum/9;
    sd=sqrt(sum);
    return sd;
}

void findgrade(float mean,float sd,int i,float grade[])
{
    grade[0]=mean-(2*sd);
    grade[1]=mean-sd;
    grade[2]=mean+(0.5*sd);
    grade[3]=mean+sd;
}

void printgrade(float grade[])
{
    printf("Grading Criteria\n");
    printf("A = %.2f - 100.00\n",grade[3]);
    printf("B = %.2f - %.2f\n",grade[2],grade[3]);
    printf("C = %.2f - %.2f\n",grade[1],grade[2]);
    printf("D = %.2f - %.2f\n",grade[0],grade[1]);
    printf("F = 0.00 - %.2f\n",grade[0]);
}

void cutgrade(char name[][10],float score[],float grade[],int i)
{
    for (i=0;i<10;i++)
    {
        if (score[i]>grade[3])
            printf("%s (%.2f points) : A\n",name[i],score[i]);
        else if (score[i]>grade[2])
            printf("%s (%.2f points) : B\n",name[i],score[i]);
        else if (score[i]>grade[1])
            printf("%s (%.2f points) : C\n",name[i],score[i]);
        else if (score[i]>grade[0])
            printf("%s (%.2f points) : D\n",name[i],score[i]);
        else
            printf("%s (%.2f points) : F\n",name[i],score[i]);
    }
}

int main()
{	
    float score[10],mean,sd,grade[3];
    int i ;
    char name[10][10],buffer[100];
    input(buffer,0,name,score);
    mean=findmean(score,0);
    sd=findsd(score,mean,0);
	findgrade(mean,sd,0,grade);
	printgrade(grade);
	cutgrade(name,score,grade,0);
	return 0;
}
