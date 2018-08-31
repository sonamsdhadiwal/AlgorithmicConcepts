#include<iostream>
#include<stdlib.h>
using namespace std;

struct list
{
    int info;
    struct list *ptr;
}*top,*top1,*temp,*temp1;
 
 
int main()
{
    int data, ch,count=0;
 
    cout<<"1 :: Create"<<endl<<"2 :: Push"<<endl<<"3 :: Pop"<<endl<<" 4 :: Top element"<<endl<<" 5 :: check Is stack Empty"<<endl;
	cout<<"6 :: Dipslay"<<endl<<"7 :: Stack Count"<<endl<<" 8 :: Destroy stack"<<endl<<"9.Exit"<<endl;
    //Assigning top as null so that new element can be created and stack doesnt overflow
	top = NULL;
    while (1)
    {
        cout<<" Enter choice : ";
        cin>>ch;
        switch (ch)
        {
		case 1:
			//create
			top = NULL;
        case 2:
			//Push
            cout<<"Enter data : "<<endl;
            cin>>data;
			 if (top == NULL)
             {
                  top =(struct list *)malloc(1*sizeof(struct list));
                  top->ptr = NULL;
                  top->info = data;
             }
			else
			{
				temp =(struct list *)malloc(1*sizeof(struct list));
				temp->ptr = top;
				temp->info = data;
				top = temp;
			}
			count++;
            break;
        case 3:
            //POP
			top1 = top;
           if (top1 == NULL)
              cout<<"Stack is empty...Please try another option"<<endl;
           else
		   {
              top1 = top1->ptr;
              cout<<"Poped Element is"<<top->info<<endl;
              free(top);
              top = top1;
              count--;
		   }
            break;
        case 4:
			//Top Element
            if (top == NULL)
                cout<<"No elements in stack"<<endl;
            else
           		cout<<"Top element is"<<top->info<<endl;
            break;
        case 5:
            //Check stack empty
			if(top==NULL)
				cout<<"Stack empty"<<endl;
			else
				cout<<"stack is not empty"<<endl;
            break;
        
        case 6:
            //display
			top1 = top;
            if (top1 == NULL)
                  cout<<"Stack is empty"<<endl;
            while (top1 != NULL)
            {
                cout<<top1->info<<" "<<endl;
                 top1 = top1->ptr;
            }
            break;
        case 7:
			//Get number of elements in stack
			cout<<"Number of elements in the stack is"<<count<<endl;
            break;
        case 8:
			//Destroy stack
			top1 = top; 
            while (top1 != NULL)
            {
				top1 = top->ptr;
			    free(top);
                top = top1;
                top1 = top1->ptr;
            }
            free(top1);
            top = NULL;
 
          cout<<"All stack elements destroyed"<<endl;
          count = 0;
            break;
			case 9:
            exit(0);
        default :
            cout<<" Wrong choice, Please enter correct choice  "<<endl;
            break;
        }
    }
	return 0;
}
 
