#include<stdio.h>

int prevWireFunc(int curWire,int wires);
void recurPrevWires(int remain,int curWire,int wires,char colorSeq[]);
char queryCol[5]={};

int main()
{
	int i=0,wires,battCnt,startWire,isReverse,firstSNNum,curWire,prevWire,temp=0,resCnt=0;
	int rawCon[20]={},wiresLink[20]={},result[20]={},wiresList[20]={};
	char litCLR,hasRJ,curSNChar,firstSNChar;
	char serialNo[10]={},colorSeq[20]={};

	printf("KTaNE Follow The Leader solver [v1.0]\nCreated by SL7205.\n");
	printf("\n-----Global Info-----\n");
	printf("Serial number: ");
	scanf("%s",serialNo);
	printf("Battery count: ");
	scanf("%d",&battCnt);
	printf("Lit CLR? / RJ-45? (T/F) (T/F): ");
	scanf(" %c %c",&litCLR,&hasRJ);
	printf("\nReady!\n");

	//find S/N first char/num;
	do{
		firstSNChar = serialNo[i];
		i++;
	}while(serialNo[i-1]>='0'&&serialNo[i-1]<='9');
	i=0;
	do{
		firstSNNum = serialNo[i] - '0';
		i++;
	}while(serialNo[i-1]>='A'&&serialNo[i-1]<='Z');

	while(1)
	{
		//init blank
		for(i=1;i<=12;i++)
        {
            wiresLink[i]=-1;
            wiresList[i]=-1;
        }
		resCnt=1;
		wires=1;
		curSNChar=firstSNChar;

		//input route/color
		printf("Enter connection route and color, from lowest:\n");
		do{
			printf("No. %d: ",wires);
			scanf("%d%c",&rawCon[wires],&colorSeq[wires]);
			wires++;
		}while(rawCon[1]!=rawCon[wires-1]||wires==2);
		wires-=2;

		//make wires link
		for(i=1;i<=wires;i++)
		{
			wiresLink[i]=rawCon[i+1];
			wiresList[rawCon[i]]=rawCon[i+1];
		}

		//check start wire
		printf("\n--Answer--\n\n");
		if(hasRJ == 'T' && wiresList[4] == 5)
			startWire = 4;
		else if(wiresList[battCnt] != -1)
			startWire = battCnt;
		else if(wiresList[firstSNNum] != -1)
			startWire = firstSNNum;
		else if(litCLR == 'T')
		{
			printf("\nCut all from highest.\n");
			continue;
		}
		else
			startWire = rawCon[1];

		//pointer
		for(i=1;i<=wires;i++)
		{
			if(rawCon[i] == startWire)
			{
				curWire = i;
				break;
			}
		}

		//reverse
		if(colorSeq[curWire] == 'R' || colorSeq[curWire] == 'G' || colorSeq[curWire] == 'W')
			isReverse = 1;
        else isReverse = 0;

		//first wire is always cut
		result[0]=rawCon[curWire];
		curWire++;
		if(curWire>wires)
            curWire=1;

		//rules checking
		for(i=1;i<wires;i++)
		{
			temp=0;

			if(curSNChar=='A'||curSNChar=='N')
			{
				prevWire=prevWireFunc(curWire,wires);
				if(colorSeq[prevWire]!='Y'&&colorSeq[prevWire]!='B'&&colorSeq[prevWire]!='G')
				{
					result[resCnt]=rawCon[curWire];
					resCnt++;
				}
			}
			else if(curSNChar=='B'||curSNChar=='O')
			{
				prevWire=prevWireFunc(curWire,wires);
				if(wiresLink[prevWire]%2==0)
				{
					result[resCnt]=rawCon[curWire];
					resCnt++;
				}
			}
			else if(curSNChar=='C'||curSNChar=='P')
			{
				prevWire=prevWireFunc(curWire,wires);
				if(result[resCnt-1]==rawCon[prevWire])
				{
					result[resCnt]=rawCon[curWire];
					resCnt++;
				}
			}
			else if(curSNChar=='D'||curSNChar=='Q')
			{
				prevWire=prevWireFunc(curWire,wires);
				if(colorSeq[prevWire]=='R'||colorSeq[prevWire]=='B'||colorSeq[prevWire]=='K')
				{
					result[resCnt]=rawCon[curWire];
					resCnt++;
				}
			}
			else if(curSNChar=='E'||curSNChar=='R')
			{
				recurPrevWires(3,curWire,wires,colorSeq);
				if(queryCol[1]==queryCol[2]&&queryCol[1]!=queryCol[3])
				{
					result[resCnt]=rawCon[curWire];
					resCnt++;
				}
				if(queryCol[1]==queryCol[3]&&queryCol[1]!=queryCol[2])
				{
					result[resCnt]=rawCon[curWire];
					resCnt++;
				}
				if(queryCol[2]==queryCol[3]&&queryCol[2]!=queryCol[1])
				{
					result[resCnt]=rawCon[curWire];
					resCnt++;
				}
			}
			else if(curSNChar=='F'||curSNChar=='S')
			{
				recurPrevWires(2,curWire,wires,colorSeq);
				if(queryCol[1]==colorSeq[curWire]&&queryCol[2]!=colorSeq[curWire])
				{
					result[resCnt]=rawCon[curWire];
					resCnt++;
				}
				else if(queryCol[1]!=colorSeq[curWire]&&queryCol[2]==colorSeq[curWire])
				{
					result[resCnt]=rawCon[curWire];
					resCnt++;
				}
			}
			else if(curSNChar=='G'||curSNChar=='T')
			{
				prevWire=prevWireFunc(curWire,wires);
				if(colorSeq[prevWire]=='Y'||colorSeq[prevWire]=='W'||colorSeq[prevWire]=='G')
				{
					result[resCnt]=rawCon[curWire];
					resCnt++;
				}
			}
			else if(curSNChar=='H'||curSNChar=='U')
			{
				prevWire=prevWireFunc(curWire,wires);
				if(result[resCnt-1]!=rawCon[prevWire])
				{
					result[resCnt]=rawCon[curWire];
					resCnt++;
				}
			}
			else if(curSNChar=='I'||curSNChar=='V')
			{
				prevWire=prevWireFunc(curWire,wires);
				if(wiresLink[prevWire]-rawCon[prevWire]!=1&&wiresLink[prevWire]-rawCon[prevWire]!=-11)
				{
					result[resCnt]=rawCon[curWire];
					resCnt++;
				}
			}
			else if(curSNChar=='J'||curSNChar=='W')
			{
				prevWire=prevWireFunc(curWire,wires);
				if(colorSeq[prevWire]!='W'&&colorSeq[prevWire]!='K'&&colorSeq[prevWire]!='R')
				{
					result[resCnt]=rawCon[curWire];
					resCnt++;
				}
			}
			else if(curSNChar=='K'||curSNChar=='X')
			{
				recurPrevWires(2,curWire,wires,colorSeq);
				if(queryCol[1]!=queryCol[2])
				{
					result[resCnt]=rawCon[curWire];
					resCnt++;
				}
			}
			else if(curSNChar=='L'||curSNChar=='Y')
			{
				prevWire=prevWireFunc(curWire,wires);
				if(wiresLink[prevWire]>6)
				{
					result[resCnt]=rawCon[curWire];
					resCnt++;
				}
			}
			else
			{
				recurPrevWires(2,curWire,wires,colorSeq);
				if(queryCol[1]=='K'||queryCol[1]=='W')
					temp++;
				if(queryCol[2]=='K'||queryCol[2]=='W')
					temp++;
				if(temp<=1)
				{
					result[resCnt]=rawCon[curWire];
					resCnt++;
				}
			}

			//loop
			curWire++;
			if(curWire>wires)
				curWire=1;

			//letter incre/decremental
			if(isReverse==1)
				curSNChar--;
			else
				curSNChar++;

			//wrapping around
			if(curSNChar<'A')
				curSNChar='Z';
			else if(curSNChar>'Z')
				curSNChar='A';
		}

		//result
		printf("Cut in order: ");
		for(i=0;i<resCnt;i++)
			printf("%d ",result[i]);
		printf("\n\n");
	}
}

//aux function for wrapping around
int prevWireFunc(int curWire,int wires)
{
	if(curWire==1)
		return wires;
	else
		return curWire-1;
}

//recursive for case E/R
void recurPrevWires(int remain,int curWire,int wires,char colorSeq[])
{
	int prevWire;

	if(remain==0)
		return;

	prevWire=prevWireFunc(curWire,wires);
	queryCol[remain]=colorSeq[prevWire];
	recurPrevWires(remain-1,prevWire,wires,colorSeq);
}
