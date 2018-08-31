
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string>
using namespace std;
char stac[50];
int top = -1;


struct stack1
{
   string data;
   struct stack1 *next;
};

class stack
{
   struct stack1 *top;
   public:
   stack()
   {
      top = 0;
   }
   void push(string data);
   string pop();
};

void stack::push(string data)
{
   struct stack1 *temp;
   temp = new stack1();
   temp->data = data;
   temp->next = (top != 0) ? top : 0;
   top = temp;
}

string stack::pop()
{
   struct stack1 *temp;
   if (top == 0)
	   cout<<"Stack is empty or the expression is same as given or invalid operation"<<endl;
   else
   {
   temp = top;
   string result = temp->data; 
   top = top->next;
   delete temp;
   return result;
   }
}

//Infix to postfix methods and functions
void push(char ch)
{
    stac[++top] = ch;
}

char pop()
{
        if(top == -1)
                return -1;
        else
        	return stac[top--];
}

int priority(char ch)
{
	if(ch == '(')
		return 0;
	if(ch == '+' || ch == '-')
		return 1;
	if(ch == '*' || ch == '/')
		return 2;
	if(ch == '^')
		return 3;
}



int main()
{
        char exp[20];
        char *ptr, ch;
		int ch1,ch2,count=0,count1=0;
		
   string postfix, infix, operand1, operand2, expr;
		do{
			cout<<"Which operation you want to perform?"<<endl;
			cout<<"1.Infix to postfix"<<endl<<"2.Postfix to infix"<<endl;
			cin>>ch1;
			switch(ch1)
			{
			case 1:
               cout<<"Enter the arithmatic expression :: "<<endl;
               cin>>exp;
               ptr = exp;
               
			   while(*ptr != '\0')
               {
                     if(isalnum(*ptr))
					 {
                        cout<<*ptr;
						count++;
					 }
                     else if(*ptr == '(')
			            push(*ptr);
		             else if(*ptr == ')')
                      {
                          while((ch = pop()) != '(')
				          cout<< ch;
                       }
		              else
		               {
			               while(priority(stac[top]) >= priority(*ptr))
				           cout<<pop();
			               push(*ptr);
						   count1++;
		               }
                   ptr++;
               }
	           while(top != -1)
	           {
		            cout<<pop();
	           }
			   count--;
			   if(!(count==count1))
			   { 
				   cout<<endl;
				   cout<<"Expression is not correct"<<endl<<"Please check your expression"<<endl;
			   }
			   break;
			case 2:
				stack s;
                cout << "Enter postfix expression" << endl;
                cin >> postfix;
                for(int i = 0; i < postfix.length(); i++)
                {
                    string c = postfix.substr(i, 1);
                     if (c == "^" || c == "+" || c == "-" || c == "*" || c == "/")
                    {
                        operand2 = s.pop();
                        operand1 = s.pop();
                        expr = "(" + operand1 + c + operand2 + ")";
                        s.push(expr);
                    } 
                    else 
                   {
                       s.push(c);
                   }
          }
          infix = s.pop();
          cout << "The infix expression is" << endl << infix << endl;
    		break;
			}
			cout<<"Do you want to continue"<<endl;
			cin>>ch2;
		}while(ch2==1);
	return 0;
}
