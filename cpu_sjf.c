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
   	if(P[j].burst>P[j+1].burst)
   	{ 
    	sort(&P[j],&P[j+1]);
   	} 
   	
   	
}
