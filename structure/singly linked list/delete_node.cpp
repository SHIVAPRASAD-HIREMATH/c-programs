	#include<stdio.h>
	#include<stdlib.h>
	int count = 0;
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
		count++;
	}
	void printlist()
	{
		node *temp;
		temp=head;
		while(temp != NULL)
		{
			printf("%d ",temp->data);
			temp=temp->addr;
		}
		printf("\n");
	}
	
	void Delete(int pos)
	{
		node* prv,*cur;
		node* temp = head;
		prv=head;
		
		for(int i=1;i<=pos;i++)
		{	
			if(i == pos-1)
			{
				prv=temp;
			}
			else if(i == pos)
			{
				cur=temp;
			}
			temp=temp->addr;
		}
		if(pos == 1)
		{
			head = cur->addr;
		}
		else 
		{
			prv->addr = cur->addr;
		}
	
			free(cur);
			count--;
	}
	
	int main()
	{
		insert(4);
		insert(5);
		insert(6);
		insert(8);
		insert(5);
		printlist();
	    printf("count=%d\n",count);
	    Delete(5);
		printlist();
		printf("count=%d\n",count);
			
	}

