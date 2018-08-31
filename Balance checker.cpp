#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

int main()
{
	int len,temp=0,temp1=0,temp2=0,temp3=0;
	string parenthesis;
	cout<<"**Program of balanced parenthesis**"<<endl;
	cout<<"Enter required parenthesis expression"<<endl;
	cin>>parenthesis;
	len=parenthesis.length();
	for(int k=0;k<=len-1;k++)
	{
		if(parenthesis[k]=='(')
			temp++;
		else if(parenthesis[k]=='[')
			temp1++;
		else if(parenthesis[k]=='{')
			temp2++;
		else if((parenthesis[k]=='/') && (parenthesis[k+1]=='*'))
		{
			temp3++;
			temp3++;
			k++;
		}
		else if(parenthesis[k]==')')
			temp--;
		else if(parenthesis[k]==']')
			temp1--;
		else if(parenthesis[k]=='}')
			temp2--;
		else if((parenthesis[k]=='*') && (parenthesis[k+1]='/'))
		{
			temp3--;
			temp3--;
			k++;
		}
		
	}
	//<<"value of temp3 is"<<temp3<<endl;
	if(!(temp==0))
		cout<<"Problem with ( or )parenthesis"<<endl;
	else if(!(temp1==0))
		cout<<"Problem with [ or ]parenthesis"<<endl;
	else if(!(temp2==0))
		cout<<"Problem with { or }parenthesis"<<endl;
	else if(!(temp3==0))
		{
			
	cout<<"Problem with /* or */parenthesis"<<endl;
	}
	else 
		cout<<"Parenthesis is balanced"<<endl;
	int ch;
	cin>>ch;
	return 0;
}
	
	