#include<stdio.h>
#include<stdlib.h>

typedef struct node_block
{
	int data;
	struct node_block *addr;
} node;

node* head = NULL;
node* temp1= NULL;

void insert(int data)
{
	node* temp;
	temp=(node*)malloc(sizeof(node));
	if(head == NULL)
	{
		head = temp;
		temp->data = data;
		temp->addr = NULL; 
		temp1 = temp;
	}
	else
	{
		temp->data=data;
		temp->addr=NULL;
		temp1->addr=temp;
		temp1=temp;
	}
}
int printlist(node *temp)
{
	if(temp == NULL)
	{
		return (temp->data);
	}
	printf("%d",return (printlist(temp->addr)));
}

int main()
{
	insert(4);
	insert(5);
	insert(6);
	printlist(head);
	
}

