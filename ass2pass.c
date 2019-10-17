#include<stdio.h>
#include<stdlib.h>

void main()
{
	char label[10],opcode[10],operand[10];
	file *f1,*f2,*f3,*f4;
	f1 = fopen("input.txt");
	f2 = fopen("optab.txt");
	f2 = fopen("symtab.txt");
	f3 = fopen("output.txt");
	fscan(f1,"%s%s%s",label,opcode,operand);
	if(
	


