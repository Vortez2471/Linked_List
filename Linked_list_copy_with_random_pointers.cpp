#include<bits/stdc++.h>
using namespace std;

class Node
{
	public:
		int data;
		Node* link;
		Node*random_link;
};
Node* root=NULL,*head=NULL;

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

void print_ll(Node* root)
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

void copy_with_random_pointer()
{
	Node* temp=root;

	while(temp!=NULL)
	{
		Node *flag= new Node();
		flag->data=temp->data;
		flag->link=temp->link;
		temp->link=flag;
		temp=flag->link;
	}
	temp=root;
	while(temp->link->link!=NULL)
	{
		temp->link->random_link=temp->random_link->link;
		temp=temp->link->link;
	}
	print_ll(root);
	temp=root;
	head=temp->link;
	Node* flag=head;
	while(flag!=NULL)
	{
		temp->link=temp->link->link;
		if(flag->link==NULL)
		{
			flag=flag->link;
			continue;
		}
		flag->link=flag->link->link;
		temp=temp->link;
		flag=flag->link;
	}
}

int main()
{
	insert_at_beginning();
	print_ll(root);
	insert_at_beginning();
	print_ll(root);
	insert_at_beginning();
	print_ll(root);
	insert_at_beginning();
	print_ll(root);
	insert_at_beginning();
	print_ll(root);
	insert_at_beginning();
	print_ll(root);
	root->random_link=root->link->link->link;
	root->link->random_link=root->link;
	root->link->link->random_link=root->link->link->link->link;
	root->link->link->link->random_link=root->link->link;
	root->link->link->link->link->random_link=root->link->link->link->link->link;
	root->link->link->link->link->link->random_link=root->link;
	copy_with_random_pointer();
	print_ll(root);
	print_ll(head);
}