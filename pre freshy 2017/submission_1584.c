#include<stdio.h>
#include<math.h>

double calcMean(int scr[])
{
	int i;
	double sum=0;
	for(i=0;i<10;i++)
	{
		sum+=scr[i];
	}
	return sum/10;
}

double calcSD(int scr[], double mean)
{
	int i;
	double sig=0;
	for(i=0;i<10;i++)
	{
		sig+=pow(scr[i]-mean,2);
	}
	return sqrt(sig/9);
}

void calcRank(double rank[][2],double mean,double sd)
{
	rank[0][0]=mean+sd; 
	rank[0][1]=100;
	rank[1][0]=mean+(0.5*sd); 
	rank[1][1]=mean+sd;
	rank[2][0]=mean-sd; 
	rank[2][1]=mean+(0.5*sd);
	rank[3][0]=mean-(2*sd); 
	rank[3][1]=mean-sd;
	rank[4][0]=0; 
	rank[4][1]=mean-(2*sd);
	printf("Grading Criteria\n");
	printf("A = %.2lf - %.2lf\n",rank[0][0],rank[0][1]);
	printf("B = %.2lf - %.2lf\n",rank[1][0],rank[1][1]);
	printf("C = %.2lf - %.2lf\n",rank[2][0],rank[2][1]);
	printf("D = %.2lf - %.2lf\n",rank[3][0],rank[3][1]);
	printf("F = %.2lf - %.2lf\n",rank[4][0],rank[4][1]);
}

int main()
{
	int i,score[15]={};
	double mean,sd,rank[5][2]={};
	char name[20][20]={};
	for(i=0;i<10;i++)
	{
		printf("Enter name and score of student %d : ",i+1);
		scanf("%s %d",name[i],&score[i]);
	}
	mean=calcMean(score);
	sd=calcSD(score,mean);
	calcRank(rank,mean,sd);
	for(i=0;i<10;i++)
	{
		printf("%s (%d points) : ",name[i],score[i]);
		if(score[i]>=rank[0][0]) 
			printf("A\n");
		else if(score[i]>=rank[1][0]) 
			printf("B\n");
		else if(score[i]>=rank[2][0]) 
			printf("C\n");
		else if(score[i]>=rank[3][0]) 
			printf("D\n");
		else 
			printf("F\n");
	}
	return 0;
}