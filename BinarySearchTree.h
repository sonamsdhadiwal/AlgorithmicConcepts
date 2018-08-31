#include<iostream>
using namespace std;

template <class T>
class BinarySearchTree
{
public:
	struct node
	{
		T element;
		node *left;
		node *right;
	};
	node* root;
public:
	void insert(T key);
	node* find(int key);
//	void create(T ele);
	void display();
	void inorder(node*);
	BinarySearchTree()
	{
		root=NULL;
	}
};

template <class T>
void BinarySearchTree <T> ::insert(T key)
{    
	node *newNode= new node();
	newNode->element=key;
	newNode->left=NULL;
	newNode->right=NULL;
	//,*rootnode;
	node *temp;
	//First take the element
	cout<<"Enter the element you want to insert in Binary Search tree"<<endl;
	cin>>key;
	temp=root;
	if(root==NULL)
	{
		newNode=root;

	}

while(temp!=NULL)
{
	if(temp->element>key)
		{
			//insert left
			//need to repeatedly check the condition
			if(temp->left==NULL)
			{
				temp->left=newNode;
				break;
			}
			else
			{
			temp=temp->left;
//			goto label;
			}
		}
		else if(temp->element<key)
		{
			//insert right
			//similarly need to check repeated condition
		    if(temp->right==NULL)
			{
				temp->right=newNode;
				break;
			}
			else
			{
			temp->right=newNode;
		//	goto label;
			}	
	}
		if(temp->element==key)
		{
			cout<<"Element already present"<<endl;
		}
}
}

template<class T>
void BinarySearchTree<T>::display()
{
	inorder(root);
}

template<class T>
void BinarySearchTree<T>::inorder(node *temp1)
{
	if(temp1!=NULL)
	{
		inorder(temp1->left);
	     cout<<temp1->element;
		 inorder(temp1->right);
	}
}