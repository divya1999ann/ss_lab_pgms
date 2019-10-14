#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
void main()
{
  	srand(time(0));
  	int i,n,init,seektime[10],request[10], total=0,j,p,temp1[10],temp,pos,last;
  	bool flag[10];
	n=rand()%5+1;
	printf("Number of requests : %d\n",n);
	printf("Requests arriving \n");
	for(i=0;i<n;i++)
	{ 
		flag[i]=false;
		request[i]=rand()%5;
		temp1[i]=request[i];
		printf("%d ",request[i]);
	}
	init=rand()%5;
	printf("\nHead is initially at %d\n",init);
	for(i=0;i<n;i++)
	{
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(temp1[j]<temp1[pos])
			pos=j;
		}
		temp=temp1[i];
		temp1[i]=temp1[pos];
		temp1[pos]=temp;
	}
//for(i=0;i<n;i++){printf("%d",temp1[i]);}
//last = temp1[n-1];
	for( i=0;i<n;i++)
	{
	if(temp1[i]>init)
	{
    	pos=i;
    	break;
	}
	}
if(i==n){
seektime[0]=abs(init-temp1[n-1]);
pos=n-1;
}else{
seektime[0]=abs(init-temp1[pos]);
flag[pos]=true;
}
j=1;
for(i=pos+1;i<n;i++){
seektime[j++]=abs(temp1[i-1]-temp1[i]);
flag[i]=true;
}
seektime[j]=abs(temp1[n-1]-4);
for(i=n-1;i>=0;i--){
if(flag[i] == false)
pos=i;                                                                              

}
seektime[j+1]=abs(4-temp1[pos]);

for(i=pos-1;i>=0;i++){
seektime[j++] = abs(temp1[i-1]-temp1[i]);
}
for(i=0;i<n;i++){
total+=seektime[i];
}

printf("\nTotal time is %d",total);
printf("\n");


}

