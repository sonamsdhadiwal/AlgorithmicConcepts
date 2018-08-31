
#include<iostream>
#include "BinarySearchTree.h"
using namespace std;

int main()
{
	int operation;
	cout<<"What operation you want to do?"<<endl;
	cout<<"1.Create"<<endl<<"2.Insert"<<endl<<"3.Find"<<endl<<"4.Delete"<<endl;
	cin>>operation;
	BinarySearchTree<int> bst;
	switch(operation)
	{
	case 1:	
	   bst.insert(40);
	   bst.insert(30);
	   bst.insert(50);
	   bst.insert(20);
	   bst.insert(10);
	   bst.display();

	   break;
	}
}