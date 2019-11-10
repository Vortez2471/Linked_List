#include<bits/stdc++.h>
using namespace std;

class Node
{
	public:
		int data;
		Node* link;
};
Node* root=NULL;

void insert_at_beginning()
{
	Node*temp= new Node();
    cin>>temp->data;
    temp->link=NULL;

	if(root==NULL)
		root=temp;

	else
	{
		temp->link=root;
		root=temp;
	}
}

void insert_at_end()
{
	Node*temp= new Node();
    cin>>temp->data;
    temp->link=NULL;

    if(root==NULL)
    	root=temp;

    else
    {
    	Node*flag=root;

    	while(flag->link!=NULL)
    	{
    		flag=flag->link;
    	}

    	flag->link=temp;
    }
}

void insert_at_position(int pos)
{
	Node*temp= new Node();
    cin>>temp->data;
    temp->link=NULL;

	if(root==NULL)
		cout<<"List is empty"<<endl;

	else
	{
		Node*flag=root;
		int i=1;
		while(i<pos-1)
		{
			flag=flag->link;
			i++;
		}

		temp->link=flag->link;
		flag->link=temp;
	}
}

void print_ll()
{
	Node* temp=root;

	if(root==NULL)
		cout<<"List is empty"<<endl;

	else
	{
		while(temp)
		{
			cout<<temp->data<<"->";
			temp=temp->link;
		}
		cout<<endl;
	}
}

int length()
{
	Node* temp=root;
	int i=0;
	if(root==NULL)
		cout<<"List is empty"<<endl;
	else
	{
		while(temp!=NULL)
		{
			temp=temp->link;
			i++;
		}
	}
	return i;
}

void search(int key)
{
	Node* temp=root;
	int flag=0;
	if(root==NULL)
		cout<<"List is empty"<<endl;
	else
	{
		while(temp!=NULL)
		{
			if(temp->data==key)
				flag=1;
            temp=temp->link;
		}
	}

	if(flag)
		cout<<"Key found"<<endl;
	else
		cout<<"Key not found"<<endl;
}

void nth_from_beginning(int n)
{
	if(root==NULL)
		cout<<"List is empty"<<endl;
	else
	{
		Node* temp=root;
		int i=1;
		while(i<n)
		{
			temp=temp->link;
			i++;
		}
		cout<<"Nth node from beginning is "<<temp->data<<endl;
	}
}

void nth_from_end(int n)
{
	if(root==NULL)
		cout<<"list is empty"<<endl;
	else
	{
		Node* temp=root;
		n=length()-n+1;
		int i=1;

		while(i<n)
		{
			temp=temp->link;
			i++;
		}
		cout<<"Nth node from end is "<<temp->data<<endl;
	}
}

void nth_from_end_with_two_pointers(int n)
{
	if(root==NULL)
		cout<<"List is empty"<<endl;
	else
	{
		Node* temp,*flag;
		temp=root;
		flag=root;
        int i=1;
		while(i<=n)
		{
			temp=temp->link;
			i++;
		}
		while(temp!=NULL)
		{
			flag=flag->link;
			temp=temp->link;
		}
		cout<<"Nth node from end is "<<flag->data<<endl;
	}
}

void delete_at_beginning()
{
	Node* temp=root;

	if(root==NULL)
		cout<<"List is empty"<<endl;
	else
	{
		root=temp->link;
		delete temp;
	}
}

void delete_at_end()
{
	Node* temp=root;

	if(root==NULL)
		cout<<"List is empty"<<endl;

	else if(root->link==NULL)
		delete root;
	else
	{
		while(temp->link->link!=NULL)
		{
			temp=temp->link;
		}
		delete temp->link;
		temp->link=NULL;
	}
}

void delete_at_position(int pos)
{
	Node* temp=root;
	int i=1;

	if(root==NULL)
		cout<<"List is empty"<<endl;
	else
	{
		while(i<pos-1)
		{
			temp=temp->link;
			i++;
		}
		Node*flag=temp->link->link;
		delete temp->link;
		temp->link=flag;
	}
}

void mid_element_two_pointers()
{
	Node *temp,*flag;
	temp=root;
	flag=root;

	while(temp->link!=NULL)
	{
		temp=temp->link->link;
		flag=flag->link;
	}
	cout<<"The mid element is "<<flag->data<<endl;
}

void mid_element()
{
	int i=length()/2,j=1;
	Node* temp=root;
	while(j<=i)
	{
		temp=temp->link;
		j++;
	}
	cout<<"The mid element is "<<temp->data<<endl;
}

void reverse()
{
	if(root==NULL)
		cout<<"List is empty"<<endl;
	else
	{
		Node *prev=NULL,*next=NULL,*temp=root;

		while(temp!=NULL)
		{
			next=temp->link;
			temp->link=prev;
			prev=temp;
			temp=next;
		}
		root=prev;
	}
}

int main()
{
	insert_at_beginning();
	print_ll();
	insert_at_beginning();
	print_ll();
	insert_at_beginning();
	print_ll();
	insert_at_end();
	print_ll();
	insert_at_end();
	print_ll();
	insert_at_end();
	print_ll();
	insert_at_position(3);
	print_ll();
	insert_at_position(4);
	print_ll();
    delete_at_beginning();
    print_ll();
    delete_at_end();
    print_ll();
    delete_at_position(3);
    print_ll();
    cout<<"The length of the list is "<<length()<<endl;
    search(50);
    nth_from_beginning(4);
    nth_from_end(2);
    nth_from_end_with_two_pointers(2);
    mid_element_two_pointers();
    mid_element();
    reverse();
    print_ll();
}