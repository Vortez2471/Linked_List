#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

class Node
{
	public:
		int data;
		Node* link;
};
Node* root=NULL,*head=NULL;

void insert_at_beginning_root()
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


void insert_at_beginning_head()
{
	Node*temp= new Node();
    cin>>temp->data;
    temp->link=NULL;

	if(head==NULL)
		head=temp;

	else
	{
		temp->link=head;
		head=temp;
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

int length(Node* root)
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

void intersection_by_loops()
{
	Node* temp=root,*flag=head;

	while(temp!=NULL)
	{
		while(flag!=NULL)
		{
			if(temp==flag)
			{
				cout<<"Intersection point found"<<endl;
				return;
			}
			flag=flag->link;
		}
		flag=head;
		temp=temp->link;
	}
	cout<<"Intersection point not found"<<endl;
}

void intersection_by_set()
{
	Node* temp=root;
	unordered_set<Node*>s;
	while(temp!=NULL)
	{
		s.insert(temp);
		temp=temp->link;
	}
	temp=head;
	while(temp!=NULL)
	{
		if(s.find(temp)!=s.end())
		{
			cout<<"Intersection point found"<<endl;
			return;
		}
		temp=temp->link;
	}
	cout<<"Intersection point not found"<<endl;
}

void intersection_by_best()
{
	int len1=length(root);
	int len2=length(head);
	int max,min;
	
	if(len1>len2)
	{
		max=len1;
		min=len2;
	}
	else
	{
		max=len2;
		min=len1;
	}
	
	Node* temp=root,*flag=head;

	for(int i=1;i<=max-min;i++)
	{
		if(max==len1)
		{
			temp=temp->link;
		}
		else
		{
			flag=flag->link;
		}
	}

	while(temp!=NULL)
	{
		if(temp==flag)
		{
			cout<<"Intersection point found"<<endl;
			return;
		}
		temp=temp->link;
		flag=flag->link;
	}
	cout<<"Intersection point not found"<<endl;
}

int main()
{
	insert_at_beginning_root();
	print_ll(root);
	insert_at_beginning_root();
	print_ll(root);
	insert_at_beginning_root();
	print_ll(root);
	insert_at_beginning_root();
	print_ll(root);
	insert_at_beginning_root();
	print_ll(root);
	insert_at_beginning_root();
	print_ll(root);
	insert_at_beginning_root();
	print_ll(root);
	insert_at_beginning_root();
	print_ll(root);
	insert_at_beginning_root();
	print_ll(root);
	insert_at_beginning_root();
	print_ll(root);
	insert_at_beginning_head();
	print_ll(head);
	insert_at_beginning_head();
	print_ll(head);
	head->link->link=root->link->link->link->link;
	print_ll(head);
	print_ll(root);
	intersection_by_loops();
	intersection_by_set();
	intersection_by_best();

}