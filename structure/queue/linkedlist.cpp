	#include<stdio.h>
	#include<stdlib.h>
	
	typedef struct node_block
	{
		int data;
		struct node_block* addr;
	}node;
	
	node *rear = NULL,*front = NULL;
	
	void Enqueue(int data)
	{
		node *temp;
		temp=(node*)malloc(sizeof(node));
		if(rear == NULL && front == NULL)
		{
			rear=temp; front=temp;
		}
		temp->data=data;
		rear->addr=temp;
		temp->addr=NULL;
		rear=temp;
	}
	
	void Dequeue(void)
	{
		node *temp;
		temp=front->addr;
		free(front);
		front=temp;
	}
	
	void Display(void)
	{
		node *temp;
		temp=front;
		while(temp != NULL)
		{
			printf("%d ",temp->data);
			temp=temp->addr;
		}
		printf("\n");
	}
	
	int main()
	{
		Enqueue(10);
		Enqueue(40);
		Enqueue(12);
		Display();
		Enqueue(10);
		Enqueue(40);
		Enqueue(12);
		Display();
		
	}
