#include<stdio.h>

typedef struct node_tag{
	long int info;
	struct node_tag *next;
} node_type;

typedef struct linked_tag{
	node_type *first, *last;
} linked_list;

linked_list list1,list2,list3;

node_type *getlink(linked_list list);
void addlink(linked_list list, node_type *ptr);

int main()
{
	node_type *ptr;
}

node_type *getlink(linked_list list)
{
	
}

void addlink(linked_list list, node_type *ptr)
{
	
}

void merge_linked_list(linked_list list1, linked_list list2, linked_list list3)
{
	node_type *ptr1, *ptr2;
	
	ptr1=getlink(list1);
	ptr2=getlink(list2);
	while(ptr1!=NULL||ptr2!=NULL)
	{
		if(ptr1==NULL)
			while(ptr2!=NULL)
			{
				addlink(list3,ptr2);
				ptr2=getlink(list2);
			}
		else if(ptr2==NULL)
			while(ptr1!=NULL)
			{
				addlink(list3,ptr1);
				ptr1=getlink(list1);
			}
		else
		{
			if(ptr1->info <= ptr2->info)
			{
				addlink(list3,ptr1);
				ptr1=getlink(list1);
			}
			else
			{
				addlink(list3,ptr2);
				ptr2=getlink(list2);
			}
		}
	}
}