#include<stdio.h>

int findRuleset(int battCnt,int mcuSec,int mcuLst,char serialNo[],char litSIGRJ);

int main()
{
	int pinConfig[4][3][10] = {
		{
			{1,0,4,2,3,5,0,0,0,0},
			{1,3,5,2,0,5,4,5,0,0},
			{5,5,5,5,1,2,5,0,4,3}	
		},
		{
			{3,4,0,2,1,5,0,0,0,0},
			{3,2,0,5,1,5,4,5,0,0},
			{3,1,2,5,5,5,5,4,0,5}
		},
		{
			{5,1,3,0,2,4,0,0,0,0},
			{3,5,5,0,1,5,2,4,0,0},
			{3,2,1,5,5,0,5,5,4,5}
		},
		{
			{3,0,4,1,2,5,0,0,0,0},
			{1,5,4,5,0,5,2,3,0,0},
			{4,2,0,5,5,5,1,5,3,5}
		}
	};
	char colorName[5][6][10] = {
		{"Yellow","Magenta","Green","Blue","Red","White"},
		{"Yellow","Red","Magenta","Green","Blue","White"},
		{"Red","Magenta","Green","Blue","Yellow","White"},
		{"Red","Blue","Yellow","Green","Magenta","White"},
		{"Green","Red","Yellow","Blue","Magenta","White"}
	};
	int battCnt,mcuSec,mcuLst,mcuDIP,orient,ruleset,mcuSel,i;
	char serialNo[10]={},litSIGRJ,mcuTyp;
	
	printf("KTaNE Microcontroller solver [v1.0]\nCreated by SL7205.\n");
	printf("\n-----Global Info-----\n");
	printf("Serial number: ");
	scanf("%s",serialNo);
	printf("Battery count: ");
	scanf("%d",&battCnt);
	printf("Lit SIG/RJ-45? (T/F): ");
	scanf(" %c",&litSIGRJ);
	printf("\nReady!\n");
	
	while(1)
	{
		printf("Enter type/DIP package: ");
		scanf(" %c %d",&mcuTyp,&mcuDIP);
		printf("Enter second/last digit of MCU's S/N no: ");
		scanf("%d %d",&mcuSec,&mcuLst);
		printf("Enter orientation of 1st pin (1=ul/2=ur/3=ll/4=lr): ");
		scanf("%d",&orient);
		
		printf("\n--Answer--\n\n");
		ruleset=findRuleset(battCnt,mcuSec,mcuLst,serialNo,litSIGRJ);
		if(mcuTyp == 'S')
			mcuSel = 0;
		else if(mcuTyp == 'L')
			mcuSel = 1;
		else if(mcuTyp == 'C')
			mcuSel = 2;
		else
			mcuSel = 3;
		
		if(orient == 1)
		{
			for(i=0;i<mcuDIP/2;i++) 
				printf("%s ",colorName[ruleset][pinConfig[mcuSel][(mcuDIP/2)-3][i]]);
			printf("\n");
			for(i=mcuDIP-1;i>=mcuDIP/2;i--)
				printf("%s ",colorName[ruleset][pinConfig[mcuSel][(mcuDIP/2)-3][i]]);
			printf("\n");
		}
		else if(orient == 2)
		{
			for(i=(mcuDIP/2)-1;i>=0;i--) 
				printf("%s ",colorName[ruleset][pinConfig[mcuSel][(mcuDIP/2)-3][i]]);
			printf("\n");
			for(i=mcuDIP/2;i<mcuDIP;i++)
				printf("%s ",colorName[ruleset][pinConfig[mcuSel][(mcuDIP/2)-3][i]]);
			printf("\n");
		}
		else if(orient == 3)
		{
			for(i=mcuDIP-1;i>=mcuDIP/2;i--) 
				printf("%s ",colorName[ruleset][pinConfig[mcuSel][(mcuDIP/2)-3][i]]);
			printf("\n");
			for(i=0;i<mcuDIP/2;i++) 
				printf("%s ",colorName[ruleset][pinConfig[mcuSel][(mcuDIP/2)-3][i]]);
			printf("\n");
		}
		else
		{
			for(i=mcuDIP/2;i<mcuDIP;i++)
				printf("%s ",colorName[ruleset][pinConfig[mcuSel][(mcuDIP/2)-3][i]]);
			printf("\n");
			for(i=(mcuDIP/2)-1;i>=0;i--) 
				printf("%s ",colorName[ruleset][pinConfig[mcuSel][(mcuDIP/2)-3][i]]);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}

int findRuleset(int battCnt,int mcuSec,int mcuLst,char serialNo[],char litSIGRJ)
{
	int i,findTarget=0;
	for(i=0;i<6;i++)
	{
		if(serialNo[i] == 'C' || serialNo[i] == 'L' || serialNo[i] == 'R' || serialNo[i] == 'X' || serialNo[i] == '1' || serialNo[i] == '8')
		{
			findTarget=1;
			break;
		}
	}
	
	if(mcuLst == 1 || mcuLst == 4)
		return 0;
	else if(litSIGRJ == 'T')
		return 1;
	else if(findTarget == 1)
		return 2;
	else if(mcuSec == battCnt)
		return 3;
	else
		return 4;
}