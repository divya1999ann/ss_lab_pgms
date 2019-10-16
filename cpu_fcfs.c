#include<stdio.h>
#include<time.h>
#include<stdlib.h>
struct Proc
{
int pid,arrival,burst,waiting,ta;
}P[10];

void sort(struct Proc *P1,struct Proc *P2)
{
    struct Proc temp=*P1;
    *P1=*P2;
    *P2=temp;
}
void main()
{
	float avg_wait=0,avg_ta=0;
	int i,n,sum_wait=0,sum_ta = 0,sum=0,j,t=0;
	
 	srand(time(0));
 	n=rand()%10+1;
 	for(i=0;i<n;i++)
 	{
  		P[i].pid=i+1;
  		P[i].arrival=rand()%10+1;
  		P[i].burst=rand()%10+1;
 	}
 	printf("No of processes %d ",n);
  	for(i=0;i<n;i++)
  	{
   		printf("\nP%d\t%d\t%d",P[i].pid,P[i].arrival,P[i].burst);
  	}
  	printf("\n");
 	for(i=0;i<n-1;i++)
  	for(j=0;j<n-i-1;j++)
   	if(P[j].arrival>P[j+1].arrival)
   	{ 
    	sort(&P[j],&P[j+1]);
   	} 
 	P[0].waiting=0;
 	t=P[0].arrival;
 	for(i=1;i<n;i++)
 	{
 		t=t+P[i-1].burst;
 		P[i].waiting = t-P[i].arrival;
 		if(P[i].waiting<0)
 		{   
 			t=t+abs(P[i].waiting);
 			P[i].waiting=0;
 			
 		}
 	}
 
 	for(i=0;i<n;i++)
  	{
  		sum_wait+=P[i].waiting;
  		P[i].ta=P[i].waiting+P[i].burst;
  		sum_ta+=P[i].ta;
  	}
  	avg_wait=(float)sum_wait/n;
  	avg_ta = (float)sum_ta/n;
  	printf("Process\t\t\tArrival time\t\tBurst time\t\tWaiting time\t\tTurnaround time\n");
  	for(i=0;i<n;i++)
  	{
   		printf("\nP%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d",P[i].pid,P[i].arrival,P[i].burst,P[i].waiting,P[i].ta);
  	}
  	printf("\n");  
  	printf("\nAverage waiting and turnaround time are %f %f",avg_wait,avg_ta);
  	printf("\n");
}
 
 
 
 
  
