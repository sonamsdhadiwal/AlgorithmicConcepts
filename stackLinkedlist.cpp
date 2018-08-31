
//stack using linked list
#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<stdlib.h>

struct node
{
	int data;
	struct node *ptr;
}*top,*top1,*temp;

void push(int num)
{
	if(top==NULL)
	{
		top=(struct node *)malloc(1*sizeof(struct node));
		top->data=num;
		top->ptr=NULL;
	}
	else
	{
		temp=(struct node *)malloc(1*sizeof(struct node));
		temp->data=num;
		temp->ptr=top;
		top=temp;
	}
}


void pop()
{
	top1=top;
	if(top1==NULL)
	{
		printf("\nNo element in stack");
		return;
	}
	else
	{
		top1= top1->ptr;
		printf("\nPopped value",top->data);
		free(top);
		top=top1;
	}
}

void display()
{
	top1=top;
	if(top==NULL)
	{
		printf("\nNo element in stack");
		return;
	}
	while(top1!=NULL)
	{
		printf("%d",top1->data);
		top1=top1->ptr;
	}
}

void main()
{
	push(4);
	printf("\nFirst display::");
	display();
	
	push(6);
	printf("\nSecond display::");
	display();

	push(7);
	printf("\nThird display::");
	display();

	pop();
	printf("\nFourth display::");
	display();

	push(8);
	printf("\nFifth display::");
	display();
	getch();
}

