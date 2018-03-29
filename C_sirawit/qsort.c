#include<stdio.h>

typedef struct {
	long int id;
	char name[30];
	float score;
	char email[50];
} st_type;

st_type student[3000];
int max_student=0;

void swap(st_type *a, st_type *b);
void sort_student_by_id(st_type student[], int left, int right);
int binary_search(int first,int last,int key);

int main()
{
	int mode,i,res;
	st_type input;
	
	while(1)
	{
		printf("mode 1:add 2:sort 3:search> ");
		scanf("%d",&mode);
		
		if(mode==1)
		{
			scanf("%ld %s %f %s",&input.id,input.name,&input.score,input.email);
			student[max_student]=input;
			max_student++;
		}
		else if(mode==2)
		{
			sort_student_by_id(student,0,max_student-1);
			for(i=0;i<max_student;i++)
				printf("%ld %s %f %s\n",student[i].id,student[i].name,student[i].score,student[i].email);
			
		}
		else
		{
			scanf("%d",&res);
			res=binary_search(0,max_student-1,res);
			printf("found> %d\n",res);
		}
	}
	return 0;
}

void swap(st_type *a, st_type *b)
{
	st_type c;
	c = *a;
	*a = *b;
	*b = c;
}

void sort_student_by_id(st_type student[], int left, int right)
{
	int l,r;
	
	l=left;
	r=right;
	
	if(l<r)
	{
		while(l!=r)
		{
			while(student[l].id<student[r].id) l++;
			swap(&student[l],&student[r]);
			while(student[l].id<student[r].id) r--;
			swap(&student[l],&student[r]);
		}
		if(l!=left) sort_student_by_id(student,left,l-1);
		if(r!=right) sort_student_by_id(student,r+1,right);
	}
}

int binary_search(int first,int last,int key)
{
	int mid;
	
	mid=(first+last)/2;
	
	if(first>last)
		return -1;
	else if(student[mid].id==key)
		return mid;
	else if(student[mid].id<key)
		binary_search(mid+1,last,key);
	else
		binary_search(first,mid-1,key);
}