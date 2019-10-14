#include<stdio.h>
#include<time.h>
#include<stdlib.h>
struct Proc
{
int id,arrival,burst,waiting,ta;
}P[10];

void sort(struct Proc *P1,struct Proc *P2)
{
    struct Proc temp=*P1;
    *P1=*P2;
    *P2=temp;
}
void main()
{
	int i,n,sum_wait=0,sum_ta = 0,sum=0,avg_wait,avg_ta,j,t=0;
 	srand(time(0));
 	n=rand()%10+1;
 	for(i=0;i<n;i++)
 	{
  		P[i].id=i+1;
  		P[i].arrival=rand()%10+1;
  		P[i].burst=rand()%10+1;
 	}
 	printf("No of processes %d ",n);
  	for(i=0;i<n;i++)
  	{
   		printf("\nP%d\t%d\t%d",P[i].id,P[i].arrival,P[i].burst);
  	}
  	printf("\n");
 	for(i=0;i<n-1;i++)
  	for(j=0;j<n-i-1;j++)
   	if(P[j].arrival>P[j+1].arrival)
   	{ 
    	sort(&P[j],&P[j+1]);
   	} 
 	P[0].waiting=0;
 	for(i=1;i<n;i++)
 	{
 		t=t+P[i-1].burst;
 		P[i].waiting = t-P[i].arrival;
 	}
 
 	for(i=0;i<n;i++)
  	{
  		sum_wait+=P[i].waiting;
  		P[i].ta=P[i].waiting+P[i].burst;
  		sum_ta+=P[i].ta;
  	}
  	avg_wait=sum_wait/n;
  	avg_ta = sum_ta/n;
  	printf("Process\t\t\tArrival time\t\tBurst time\t\tWaiting time\t\tTurnaround time\n");
  	for(i=0;i<n;i++)
  	{
   		printf("\nP%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d",P[i].id,P[i].arrival,P[i].burst,P[i].waiting,P[i].ta);
  	}
  	printf("\n");
  	printf("\nAverage waiting and turnaround time are %d %d ",avg_wait,avg_ta);
  	printf("\n");
}
 
 
 
 
  
