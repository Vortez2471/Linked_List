#include<bits/stdc++.h>
#include<unordered_set>
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

void detect_loop_by_set()
{
	unordered_set<Node*> s;
	Node* temp=root;
	int i=0;

	while(temp!=NULL)
	{
		if(s.find(temp)!=s.end())
		{
			i=1;
			break;
		}
		s.insert(temp);
		temp=temp->link;
	}
	if(i==1)
	{
		cout<<"Loop detected"<<endl;
	}
	else
		cout<<"Loop not detected"<<endl;
	
}

void detect_loop_by_two_pointers()
{
	Node* temp=root,*flag=root;
	int i=0;
	while(flag!=NULL)
	{
		temp=temp->link;
		flag=flag->link->link;

		if(flag==temp)
		{
			i=1;
			break;	
		}
	}
	if(i==1)
		cout<<"Loop detected"<<endl;
	else
		cout<<"Loop not detected"<<endl;
}

void length_of_the_loop()
{
	unordered_set<Node*> s;
	Node* temp=root,*flag=NULL;

	while(temp!=NULL)
	{
		if(s.find(temp)!=s.end())
		{
			flag=temp;
			break;
		}
		s.insert(temp);
		temp=temp->link;
	}
	int count=1;
	temp=flag->link;
	while(temp!=flag)
	{
		count++;
		temp=temp->link;
	}
	cout<<"Length of the loop is "<<count<<endl;
}

int main()
{
	insert_at_beginning();
	print_ll();
	insert_at_beginning();
	print_ll();
	insert_at_beginning();
	print_ll();
	insert_at_beginning();
	print_ll();
	insert_at_beginning();
	print_ll();
	insert_at_beginning();
	print_ll();
	root->link->link->link=root;
	detect_loop_by_set();
	detect_loop_by_two_pointers();
	length_of_the_loop();
}