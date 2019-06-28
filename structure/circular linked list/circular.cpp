	#include<stdio.h>
	#include<stdlib.h>

	
	typedef struct node_block 
	{
		int data;
		struct node_block *addr;
	} node;
	
	node *Head = NULL,*Tail = NULL;
	int count=0;
	
	void add(int data)
	{
		node *temp;
		temp=(node*)malloc(sizeof(node));
		temp->data = data;
		temp->addr=Head;
		if(Head == NULL)
		{
		  Tail=temp;	
		}
	    Tail->addr=temp;
		Head=temp;
		count++;
	}
	
	void printlist(void)
	{
		node *temp1;
		temp1=Head;
		
		do
		{
			printf("%d  ",temp1->data);
			temp1=temp1->addr;
		}
		while(temp1 != Head);
		printf("\n");
	}
	
	int main()
	{
		add(1000);
		add(10);
		add(70);
		add(300);
		add(15);
		printlist();
	//	sort();
		printlist();
		return 0;
		
	}
