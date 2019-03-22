//Binary Search tree

#include<iostream>
using namespace std;

//Class Node

class Node
{
    public:
    //data of integer typr
    int data;
    //pointer to left and right child
    Node *left;
    Node *right;
    
    //Default constructor
    Node(int value)
    {
        data=value;
        left=NULL;
        right=NULL;
    }
};


//Class BST

class BST
{
    public:
    
    //root pointer 
    Node *root;
    
    //Default Constructor
    BST()
    {
        root=NULL;
    }
    
    //Insert Function
    void Insert(int value)
    {
        InsertHelper(root,value);
    }
    //InsertHelper function that actually inserts
    void InsertHelper(Node *current, int value)
    {
        //If current is NULL, insert here only
        if(current==NULL)
        {
            current=new Node(value);
            //If root is NULL, make current point to root
            
            //return;
            
            if(root==NULL)
            {
                root=current;
            }
            return;
        }
        else if(value<(current->data))
        {
            //if the present node is the last node,insert there else call insert helper
            if(current->left==NULL)
            {
                current->left=new Node(value);
            }
            else
            {
                InsertHelper(current->left,value);
            }
            
            
        }
        else
        {
             if(current->right==NULL)
            {
                current->right=new Node(value);
            }
            else
            {
                InsertHelper(current->right,value);
            }
            
            
            
        }
    }
    //Display Function
    void Display()
    {
        DisplayHelper(root);
    }
    //Function Display helper that actually displays
    void DisplayHelper(Node*current)
    {
        if(current==NULL)
        {
            return;
        }
        else
        {
            //cout<<current->data;
            DisplayHelper(current->left);
            cout<<current->data;
            DisplayHelper(current->right);
            
            //cout<<current->data;
        }
    
    }
    //Search function
    
		Node* Search(int value){
			Search2(root,value);
		}
		
		Node* Search2(Node*current,int value){
			//comparing values to check if it is on right or left of current
			if(value<current->data){
				Search2(current->left,value);
			}
			else if(value==current->data){
				return current;
			}
			else if(value>current->data){
				Search2(current->right,value);
			}	
		}
    
    
};

//Main function
int main()
{
    BST t1;
    t1.Insert(3);
    t1.Insert(4);
    t1.Insert(1);
    t1.Insert(0);
    t1.Insert(5);
    
    t1.Display();
    
    return 0;
}
    
    
    
