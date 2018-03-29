#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct data_str {
	unsigned long long int num;
	char textA[70];
	char textB[70];
} data;

int readData(data *ptr);
int cmp_num(const void *a, const void *b);
int cmp_txt(const void *a, const void *b);

int main()
{
	int amt,i;
	data *dataIn, *dataSrt;
	clock_t start[5]={}, end[5]={};

	dataIn = (data *) malloc(100000 * sizeof(data));
	amt=readData(dataIn);
	//dataIn = (data *) realloc(dataIn,amt);
	dataSrt = (data *) malloc(amt * sizeof(data));

	printf("Test 1: stdlib qsort by number.\n");

	memcpy(dataSrt,dataIn,amt*sizeof(data));

	printf("Running...\n");
	start[1]=clock();
	qsort(dataSrt,amt,sizeof(data),cmp_num);
	end[1]=clock();
	printf("Ended, time used %lf seconds.\n",(double)(end[1]-start[1])/CLOCKS_PER_SEC);

	for(i=0;i<10;i++) printf("%llu %s %s\n",dataIn[i].num,dataIn[i].textA,dataIn[i].textB);
	printf("\n");
	for(i=0;i<10;i++) printf("%llu %s %s\n",dataSrt[i].num,dataSrt[i].textA,dataSrt[i].textB);

	return 0;
}

int readData(data *ptr)
{
	FILE *fp;
	int amt=0;

	fp = fopen("test.csv","r");
	while(fscanf(fp,"%llu,%[^,],%s",&ptr[amt].num,&ptr[amt].textA,&ptr[amt].textB)==3)
		amt++;
	fclose(fp);
	return amt;
}

int cmp_num(const void *a, const void *b)
{
	const data *aa = (data *)a;
	const data *bb = (data *)b;
	//printf("%llu %llu\n",aa->num,bb->num);
	if(aa->num < bb->num) return -1;
	else if(aa->num > bb->num) return 1;
	else return 0;
}

int cmp_txt(const void *a, const void *b)
{
	const data *aa = (data *)a;
	const data *bb = (data *)b;
	return (strcmp(aa->textB,bb->textB));
}
