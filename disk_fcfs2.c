#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//calculate total head movements 
int total (int head, int n, int *seek)
	{
	 	int total = 0;
	 	for(int i=0; i<n; i++)
		{ total += abs(seek[i]-head) ;
		  head = seek[i]; }
		return total;
		} 

// configure gnuplot
void plot(int *s, int head, int n, char str[])
	{
    	char * commandsForGnuplot[] = {"set xlabel 'BURST TIME' ", "set ylabel 'Time'", "set style data line", "plot [0:250][0:10] 'data.temp' , '' with labels "};
    	FILE * temp = fopen("data.temp", "w");
    	FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
    	fprintf(temp, "%d 0 \n", head);
    	for (int i=0; i < n; i++)
        	fprintf(temp, "%d %d %d \n", s[i], i+1,s[i]);
    
    	fprintf(gnuplotPipe, "set title \"%s\" \n", str);

    	for (int i=0; i < 4; i++)
        	fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]);
	} 
	 
void main()
{
	srand(time(0));
	printf("FCFS");
	//generate number of requests, seek position, current head position
	
	int n = rand()%10;
	int *seek_pos = (int *)malloc(sizeof(int *)*n);
	int head = rand()%250;
	for(int i=0; i<n; i++)
		 seek_pos[i] = rand()%250;  
	
	printf("Disk Request Queue \n");
	for(int i=0; i<n; i++)
		printf(" %d ",seek_pos[i]); 
	 
	//print schedule
	
	printf("\n head position = %d \n",head);
	printf("Scheduled order \n");
	for(int i=0; i<n; i++)
		printf(" %d ",seek_pos[i]); 
	int total_movement = total(head,n,seek_pos);
	printf("\n Total head movements = %d \n",total_movement );
	
	//seek time calculation
        int move_time = rand()%10 + 1;
	float avg_seek_time = (float)(move_time * total_movement)/n;        
	printf("\n Move time = %d ms\n seek time = %0.3f \n",move_time,avg_seek_time);
	
	//gnuplot
	char str[] = "FCFS";
        plot(seek_pos,head,n,str);                                                      
	 
 }
	
	
