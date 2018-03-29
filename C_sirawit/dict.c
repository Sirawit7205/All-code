#include<stdio.h>
#include<string.h>

typedef struct {
	char vocab[15];
	char mean[35];
	char type[5];
} dict_type;

dict_type dict[100000];
int dcount=0;

int Vocab_search(dict_type dict[], int first, int last, char *key);
void insertion_sort(dict_type dict[], int count);
void quickSort(dict_type data[], int first, int last);
void swap(dict_type *a, dict_type *b);

int main()
{
	char dataA[15]={}, dataB[35]={}, dataC[5]={}, find[10]={};
	int mode,i;
	
	while(1)
	{
		printf("mode 1:add 2:sort 3:search> ");
		scanf("%d",&mode);
		
		if(mode==1)
		{
			scanf("%s %s %s",dataA,dataB,dataC);
			strcpy(dict[dcount].vocab,dataA);
			strcpy(dict[dcount].mean,dataB);
			strcpy(dict[dcount].type,dataC);
			dcount++;
		}
		else if(mode==2)
		{			
			//insertion_sort(dict,dcount);
			quickSort(dict,0,dcount-1);
		}
		else if(mode==3)
		{
			scanf("%s",find);
			printf("found at %d\n",Vocab_search(dict,0,dcount-1,find));
		}
		
		for(i=0;i<dcount;i++)
			printf("\t%s %s %s\n",dict[i].vocab,dict[i].mean,dict[i].type);
	}
	return 0;	
}

int Vocab_search(dict_type dict[], int first, int last, char *key)
{
	int mid;
	
	mid=(first+last)/2;
	
	if(first>last)
		return -1;
	else if(strcmp(dict[mid].vocab,key)==0)
		return mid;
	else if(strcmp(dict[mid].vocab,key)<0)
		return Vocab_search(dict,mid+1,last,key);
	else
		return Vocab_search(dict,first,mid-1,key);
}

void insertion_sort(dict_type dict[], int count)
{
	int i,j,k;
	dict_type temp;
	
	for(i=0;i<dcount;i++)
	{
		j=0;
		while(strcmp(dict[j].vocab,dict[i].vocab)<0)
			j++;
		
		temp=dict[i];
		for(k=i;k>j;k--)
			dict[k]=dict[k-1];
		dict[j]=temp;
	}
}

void quickSort(dict_type data[], int first, int last)
{
	int l,r;
	
	if(first<last)
	{
		l=first;
		r=last;
		
		while(l!=r)
		{
			while(strcmp(data[l].vocab,data[r].vocab)<0) l++;
			swap(&data[l],&data[r]);
			while(strcmp(data[l].vocab,data[r].vocab)<0) r--;
			swap(&data[l],&data[r]);
		}
		if(l!=first) quickSort(data,first,l-1);
		if(r!=last) quickSort(data,r+1,last);
	}
}

void swap(dict_type *a, dict_type *b)
{
	dict_type c;
	c=*a;
	*a=*b;
	*b=c;
}
