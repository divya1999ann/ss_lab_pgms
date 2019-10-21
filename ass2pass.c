#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	char label[10],opcode[10],operand[10],ch,pseudo_opcode[10][10]={"START","LDA","STA","LDCH","STCH","END"};
	int locctr,i=0,error,start_add,length;
	FILE *f1,*f2,*f3;
	f1 = fopen("input.txt","r");
	f2 = fopen("symtab.txt","w");
	f3 = fopen("output.txt","w");
	fscanf(f1,"%s%s%s",label,opcode,operand);
	if(opcode == "START")
	{
		locctr = atoi(operand);
		start_add = locctr;
		fprintf(f3,"%s\t%s\t%s\n",label,opcode,operand);
		fscanf(f1,"%s%s%s",label,opcode,operand);
	}
	else
	{
		locctr=0;
		start_add=0;
	}
	while(strcmp(opcode,"END")!=0)
	{   fprintf(f3,"%d",locctr);
		if(label != "**")
		{
			fprintf(f2,"%s\t%d\n",label,locctr);
		}
		
		while(pseudo_opcode[i] != "END")
    	{
     		if(strcmp(opcode,pseudo_opcode[i])==0)
     		{
      			locctr+=3;
      			break;
     		}
     		i++;
    	}
		if(opcode == "WORD")
			locctr= locctr+3;
		else if(opcode == "BYTE")
			{
			if(operand[0] == 'C')
				locctr = locctr+strlen(operand)-3;
			else
				locctr = locctr + (strlen(operand)-3)/2;
			}
		else if(opcode == "RESW")
			locctr = locctr + atoi(operand)*3;
		else if(opcode == "RESB")
			locctr = locctr+atoi(operand);
		
	}
	fprintf(f3,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
	length = locctr - start_add;
	printf("\nLength of the program is %d",length);
	fcloseall();
	printf("\n\nInput file :\n\n");
    f1=fopen("input.txt","r");
    ch=fgetc(f1);
    while(ch!=EOF)
    {
    	printf("%c",ch);
    	ch=fgetc(f1);
   	}
  	printf("\nTemporary file :\n\n\t");
    f3=fopen("output.txt","r");
    ch=fgetc(f3);
    while(ch!=EOF)
    {
    	printf("%c",ch);
    	ch=fgetc(f3);
    }
  	printf("\nSymbol Table(Symtab) :\n\n");
    f2=fopen("symtab.txt","r");
    ch=fgetc(f2);
  	while(ch!=EOF)
   	{
    	printf("%c",ch);
    	ch=fgetc(f2);
    }
  fcloseall();
}
	


