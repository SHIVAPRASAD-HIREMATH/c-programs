	#include<stdio.h>
	#include<stdlib.h>
	
	typedef struct node
	{
		int data;
		struct node* adrr;
	}frame;
	
	frame* head=NULL;
	
	int count=0;
	
	void push(int data)
	{		
		frame* temp;
		temp=(frame*)malloc(sizeof(frame));
		temp->data=data;
		temp->adrr=head;
		head=temp;
		count++;
	}
	
	void pop(void)
	{
		frame* temp=NULL;
		temp=head;
		head = head ->addr;
		free(temp);
		count--;
	}
	
	void top(void)
	{
		printf("top frame value = %d\n",head->data);
	}
	
	void IsEmpty()
	{
		if(0 == count)
		{
			printf("stack is empty\n");	
		}
		else
		{
			printf("stack is not empty\n");
		}
	}
	 
	 void DisplayStack()
	 {
	 	frame* Display;
	 	Display=head;
	 	while(NULL != Display)
		{
		  	printf("%d ",Display->data);
		  	Display=Display->adrr;
		}
		printf("\n");
	 }
	 
	int main()
	{
		push(2);
		push(4);
		push(4);
		push(4);
		push(42);
		push(5);
		push(4);
		top();
		pop();
		top();
		DisplayStack();
		IsEmpty();
		return 0;
	}
