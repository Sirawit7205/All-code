/* Dijkstra*/

#include <stdio.h>

#define MAX 7
#define INFINITE 998

int allselected(int *selected)
{
  int i;
  for(i=0;i<MAX;i++)
    if(selected[i]==0)
      return 0; //return not check
  return 1; //return all check
}

void shortpath(int cost[][MAX],int *preced,int *distance)
{
  int selected[MAX]={0};
  int current=0,i,k,dc,smalldist,newdist;
  for(i=0;i<MAX;i++)
    distance[i]=INFINITE; //set possible max internode
  selected[current]=1;
  distance[0]=0;
  current=0;
  while(!allselected(selected))
  {
    smalldist=INFINITE; //set possible max
    dc=distance[current]; //set current distance from start
    for(i=0;i<MAX;i++)
    {
      if(selected[i]==0) //find not pass
      {
        newdist=dc+cost[current][i]; //find internode dist
        if(newdist<distance[i]) //check infinite
        {
          distance[i]=newdist;
          preced[i]=current; //set passed dist
        }
        if(distance[i]<smalldist) //check shortest
        {
          smalldist=distance[i]; //set shortest dist
          k=i; //set node number
        }
      }
    }
    current=k; //set passed node
    selected[current]=1; //set checked
   }
}

int main()
{
  int cost[MAX][MAX]=
     {{INFINITE,2,4,7,INFINITE,5,INFINITE},
      {2,INFINITE,INFINITE,6,3,INFINITE,8},
      {4,INFINITE,INFINITE,INFINITE,INFINITE,6,INFINITE},
      {7,6,INFINITE,INFINITE,INFINITE,1,6},
      {INFINITE,3,INFINITE,INFINITE,INFINITE,INFINITE,7},
      {5,INFINITE,6,1,INFINITE,INFINITE,6},
      {INFINITE,8,INFINITE,6,7,6,INFINITE}};

  int i,preced[MAX]={0},distance[MAX];
  shortpath(cost,preced,distance);
  for(i=0;i<MAX;i++)
    printf("%d\n",distance[i]);
  return 0;
}
