#include<stdio.h>

char findCreature(int locNo, int ruleNo);
void printSteps(char creature);

int main()
{
	int bhCount, ppCount, litCount, unlitCount, dCount, aaCount, dupBool;
	int ruleNo, typeNo=0, pos, eleNo;
	char creature, initial;
	int location[4][4]= {
		{2,	1,	4,	3},
		{1,	2,	3,	4},
		{3,	4,	2,	1},
		{4,	3,	1,	2}
	};
	
	printf("KTaNE Creation solver [v1.0]\nCreated by SL7205.\n");
	printf("\n-----Global Info-----\n");
	printf("Battery Holder count: ");
	scanf("%d",&bhCount);
	printf("Lit and Unlit indicator count: ");
	scanf("%d %d",&litCount,&unlitCount);
	if(bhCount > 2)
	{
		printf("D and AA battery count: ");
		scanf("%d %d",&dCount,&aaCount);
	}
	else
	{
		printf("Port Plates count: ");
		scanf("%d",&ppCount);
		printf("Duplicate ports? (1/0): ");
		scanf("%d",&dupBool);
	}
	printf("\nReady!\n");
	
	if(bhCount > 2)
	{
		if(litCount>0&&aaCount>0&&dCount==0) ruleNo=0;
		else if(litCount>0) ruleNo=1;
		else if(unlitCount>0&&aaCount==0&&dCount>0) ruleNo=2;
		else if(unlitCount>0) ruleNo=3;
		else ruleNo=4;
	}
	else
	{
		if(ppCount>bhCount) ruleNo=5;
		else if(dupBool==1) ruleNo=6;
		else if(unlitCount>litCount) ruleNo=7;
		else ruleNo=8;
	}
	printf("Remember to use weather rules where applicable!\n");
	
	printf("\nHow to create Life (will be displayed once):\n");
	printf("Fire + Air\nEarth + Water\nEnergy + Swamp\n");
	
	creature=findCreature(typeNo,ruleNo);
	printf("\nCreation steps for initial clear weather:\n");
	printSteps(creature);
	
	while(1)
	{
		printf("\nEnter initial (w,a,f,e) and position:");
		scanf(" %c %d",&initial,&pos);
		
		if(initial=='w') eleNo=0;
		else if(initial=='a') eleNo=1;
		else if(initial=='f') eleNo=2;
		else eleNo=3;
		typeNo=location[eleNo][pos-1];
		creature=findCreature(typeNo,ruleNo);
		printf("\nAnswer:\n");
		printSteps(creature);
	}
}

char findCreature(int locNo, int ruleNo)
{
	char lifeformA[5][5]= {
		{'b','d','t','l','w'},
		{'d','t','l','w','b'},
		{'t','l','w','b','d'},
		{'l','w','b','d','t'},
		{'w','b','d','t','l'}
	};
	char lifeformB[4][5]= {
		{'g','p','s','m','g'},
		{'p','s','m','g','p'},
		{'s','m','g','p','s'},
		{'m','g','p','s','m'}
	};
	
	if(ruleNo<5)
		return lifeformA[ruleNo][locNo];
	else
	{
		ruleNo-=5;
		return lifeformB[ruleNo][locNo];
	}
}

void printSteps(char creature)
{
	if(creature=='b')
	{
		printf("Creating Bird:\n");
		printf("Life + Earth\nEgg + Air\n");
	}
	else if(creature=='d')
	{
		printf("Creating Dinosaur:\n");
		printf("Life + Earth\nEgg + Earth\n");
	}
	else if(creature=='t')
	{
		printf("Creating Turtle:\n");
		printf("Life + Earth\nEgg + Water\n");
	}
	else if(creature=='l')
	{
		printf("Creating Lizard:\n");
		printf("Life + Earth\nEgg + Swamp\n");
	}
	else if(creature=='w')
	{
		printf("Creating Worm:\n");
		printf("Life + Swamp\nBacteria + Swamp\n");
	}
	else if(creature=='g')
	{
		printf("Creating Ghost:\n");
		printf("Energy + Fire\nLife + Plasma\n");
	}
	else if(creature=='p')
	{
		printf("Creating Plankton:\n");
		printf("Life + Swamp\nBacteria + Water\n");
	}
	else if(creature=='s')
	{
		printf("Creating Seed:\n");
		printf("Life + Earth\nLife + Water\nEgg + Weeds\n");
	}
	else if(creature=='m')
	{
		printf("Creating Mushroom:\n");
		printf("Life + Water\nWeeds + Earth\n");
	}
}
