#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	struct node *prev;
	int info;
	struct node *next;
} node_type;

node_type *first, *last, *ptr;

void addnode(int data);
node_type *pop();

int main()
{
	int mode,data;
	node_type *cur;
	
	first=last=NULL;
	
	while(1)
	{
		printf("mode 1:add 2:pop> ");
		scanf("%d",&mode);
		
		if(mode==1)
		{
			scanf("%d",&data);
			addnode(data);
		}
		else if(mode==2)
		{			
			ptr=pop();
			printf("%d\n",ptr->info);
		}
		
		printf("DATA> ");
		cur=first;
		while(cur!=NULL)
		{
			printf("%d ",cur->info);
			cur=cur->next;
		}
		printf("\n");
	}
	return 0;
}

void addnode(int data)
{
	node_type *newdata;
	
	newdata = (node_type *) malloc(sizeof(node_type));
	newdata->info = data;
	
	if(first==NULL)
	{
		newdata->prev = newdata->next = NULL;
		first = last = newdata;
	}	
	else
	{
		last->next = newdata;
		newdata->prev = last;
		newdata->next = NULL;
		last = newdata;
	}
}

node_type *pop()
{
	if(first==NULL)
		return NULL;
	else if(first==last)
	{
		ptr=first;
		first = last = NULL;
	}
	else
	{
		ptr=first;
		first = ptr->next;
		first->prev = NULL;
	}
	return ptr;
}