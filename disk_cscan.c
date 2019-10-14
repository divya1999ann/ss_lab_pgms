#include<stdio.h>
#include<stdlib.h>
#include<time.h>



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

//calculate total head movements 
int total (int head, int n, int *seek_pos , char ch)
	{	int *s = (int *)malloc(sizeof(int *)*n);
		int j=0,real_head=head;
	 	int total = 0; int pos ,flag = 0;
		
	   //find pivot position 
	   for(int i=0;i<n;i++)
	    {if(head<seek_pos[i])
	    	{ pos = i; flag = 1;break;}
	    }
	    if(flag ==0)
	    pos = n - 1;
	    
	    //printf(" ch = %c",ch);
	    
	    printf(" \n Scheduled queue is \n");
	    if(ch == 'l')
	    	{ for(int i=pos-1;i>=0;i--)
	    		{ s[j++]=seek_pos[i];
			  printf(" %d ",seek_pos[i]); 
	    		  total += abs(head - seek_pos[i]);
	    		  head = seek_pos[i]; }
	    	  for(int i=n-1;i>=pos;i--)
	    		{ s[j++]=seek_pos[i];
			  printf(" %d",seek_pos[i]); 
	    		  total += abs(head - seek_pos[i]);
	    		  head = seek_pos[i];
	    		   }
	        }
	    
	    else
	    	{ for(int i=pos;i<n;i++)
	    		{ s[j++]=seek_pos[i];
			  printf(" %d",seek_pos[i]); 
	    		  total += abs(head - seek_pos[i]);
	    		  head = seek_pos[i]; }
	    		  s[j++] = 250;
	    		  s[j++] = 0;
	    	  for(int i=0;i<pos;i++)
	    		{ s[j++]=seek_pos[i];
			  printf(" %d",seek_pos[i]); 
	    		  total += abs(head - seek_pos[i]);
	    		  head = seek_pos[i]; }
	     	 }
	     	 
	     	 
		  //gnuplot
	          char str[] = "SCAN";
    		  plot(s,real_head,n,str);
	     return total;
	     }
	
void sort(int *seek_pos, int n)
	{   int temp;
    	for(int i=0;i<n-1;i++)
        	for(int j=0;j<n-i-1;j++)
            	if(seek_pos[j]>seek_pos[j+1])
            	{
            		 temp = seek_pos[j];
            		 seek_pos[j]=seek_pos[j+1];
            		 seek_pos[j+1]=temp;
            	}
           
	}


// configure gnuplot

	 
void main()
{	printf("CSCAN");
	srand(time(0));
	
	//generate number of requests, seek position, current head position
	
	int n = rand()%10;
	int *seek_pos = (int *)malloc(sizeof(int *)*n);
	int head = rand()%250;
	for(int i=0; i<n; i++)
		 seek_pos[i] = rand()%250;  
	
	//print schedule
	
	printf("head position = %d \n",head);
	printf("Disk Request queue  \n");
	for(int i=0; i<n; i++)
		printf(" %d ",seek_pos[i]); 
	sort(seek_pos,n);
	char option[2] = {'l','r'};
	int total_movement = total(head,n,seek_pos,(char)option[rand()%2 + 1]);
	printf("\n Total head movements = %d \n",total_movement );	
	//seek time calculation
        int move_time = rand()%10 + 1;
	float avg_seek_time = (float)(move_time * total_movement)/n;        
	printf("\n Move time = %d ms\n seek time = %0.3f \n",move_time,avg_seek_time);
	                                                      
	 
 }
	
	
	
	
