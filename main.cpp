#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node*next;
	struct node*prev;
};
struct node*add_at_empty(struct node*head,int data)
{
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	temp->prev=NULL;
	return temp;
}
struct node*add_to_last(struct node*head,int data)
{
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	head->next=temp;
	temp->prev=head;
	temp->next=NULL;
	return temp;
}
int main()
{
	#ifndef OUTLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	struct node*head=NULL;
	head=add_at_empty(head,54);
	struct node*temp=head;
	temp=add_to_last(temp,32);
	temp=add_to_last(temp,78);
	temp=add_to_last(temp,23);
	temp=add_to_last(temp,61);
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	return 0;
}