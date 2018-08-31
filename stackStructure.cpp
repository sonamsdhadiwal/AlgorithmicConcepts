
//stack using structure
#include<stdio.h>
#include<conio.h>
#include<iostream>
#define MaxSize 100

struct stac
{
	int top;
	int stk[MaxSize];
} s;

void push()
{
	int num;
	if(s.top==(MaxSize-1))
	{
		printf("\nStack overflow");
		return;
	}
	else
	{
		printf("\nEnter the number");
		scanf("%d",&num);
		s.stk[++s.top]=num;
	}
}

void pop()
{
	if(s.top==-1)
	{
		printf("\nstack empty");
		return;
	}
	else
	{

		s.top--;
	}
}


void display()
{
	for(int i=0;i<=s.top;i++)
		printf("%d",s.stk[i]);
	printf("\n");
}

void main()
{
	s.top=-1;
	push();
	display();
	push();
	display();
push();
	display();
pop();
display();
getch();
}