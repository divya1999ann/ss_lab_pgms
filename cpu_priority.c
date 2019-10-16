#include<stdio.h>
#include<time.h>
#include<stdlib.h>
struct Proc
{
int pid,burst,waiting,ta,priority;
}P[10];

void sort(struct Proc *P1,struct Proc *P2)
{
    struct Proc temp=*P1;
    *P1=*P2;
    *P2=temp;
}
void main()
{
	int i,n,sum_wait=0,sum_ta = 0,sum=0,j,t=0;
	float avg_wait,avg_ta;
 	srand(time(0));
 	n=rand()%10+1;
 	for(i=0;i<n;i++)
 	{
  		P[i].pid=i+1;
  		P[i].priority=rand()%10+1;
  		P[i].burst=rand()%10+1;
 	}
 	printf("No of processes %d ",n);
  	for(i=0;i<n;i++)
  	{
   		printf("\nP%d\t%d\t%d",P[i].pid,P[i].priority,P[i].burst);
  	}
  	printf("\n");
 	for(i=0;i<n-1;i++)
  	for(j=0;j<n-i-1;j++)
   	if(P[j].priority>P[j+1].priority)
   	{ 
    	sort(&P[j],&P[j+1]);
   	} 
   	
   	P[0].waiting = 0;
   	P[0].ta = P[0].burst;
   	for(i=1;i<n;i++)
   	{
   		sum=sum+P[i-1].burst;
   		P[i].waiting = sum;
   		P[i].ta = P[i].waiting+P[i].burst;
   	}
   	
   	for(i=0;i<n;i++)
  	{
  		sum_wait+=P[i].waiting;
  		P[i].ta=P[i].waiting+P[i].burst;
  		sum_ta+=P[i].ta;
  	}
  	
   	avg_wait=(float)sum_wait/n;
  	avg_ta = (float)sum_ta/n;
  	printf("Process\t\t\tBurst time\t\tWaiting time\t\tTurnaround time\n");
  	for(i=0;i<n;i++)
  	{
   		printf("\nP%d\t\t\t%d\t\t\t%d\t\t\t%d",P[i].pid,P[i].burst,P[i].waiting,P[i].ta);
  	}
  	printf("\n");  
  	printf("\nAverage waiting and turnaround time are %f %f",avg_wait,avg_ta);
  	printf("\n");

}
