	#include<stdio.h>
	#include<stdlib.h>

	
	typedef struct node_block 
	{
		struct node_block *prv;
		int data;
		struct node_block *next;
	} node;
	
	node* Head = NULL;
	int count=0;
	
	void  Count(void)
	{
		printf("\t%d\n",count);
	}
	
	void PrintReverse(void)
	{
		node* temp;
		temp = Head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		while(temp != NULL)
		{
			printf("%d ",temp->data);
			temp = temp->prv;
		}
		printf("\n");
	}
	
	
	int insert(int data,int pos)
	{
		if(pos > count)
		{
			printf("position should be less then count\n");
			return 0;
			
		}
		else
		{
			node* temp1;
			node* temp;
			temp1=Head;
			temp=(node*)malloc(sizeof(node));
			temp->data=data;
			if(pos == 1)
			{
				temp->prv=NULL;
				temp->next=Head;
				Head=temp;
			}
			else
			{
				for(int i=1;i<pos-1;i++)
				{
					temp1=temp1->next;
				}
			
				temp->next=temp1->next;
				temp->prv=temp1;
				temp1->next->prv=temp;
				temp1->next=temp;
			}
			count++;
		}
	}
	
	
	void add(int data)
	{
		node *temp;
		temp=(node*)malloc(sizeof(node));
		temp->data = data;
		temp->prv=NULL;
		if(Head == NULL)
		{
			temp->next=NULL;
		}
		else
		{
			temp->next = Head;
			Head->prv  = temp;
		}
		Head=temp;
		count++;
	}
	
	void printlist(void)
	{
		node *temp1;
		temp1=Head;
		
		while(temp1 != NULL)
		{
			printf("%d  ",temp1->data);
			temp1=temp1->next;
		}
		printf("\n");
	}
	 
	void IsEmpty(void)
	{
		if(Head==NULL)
		{
			printf("EMPTY\n");
		}
		else
		{
			printf("NOT EMPTY\n");
		}
	}
	
	int main(void)
	{
		int choice;
		int data,pos;
		while(1)
		{
			printf(" enter 1 to add node \n enter 2 to insert \n enter 3 for count value \n enter 4 to display elements \n enter 5 to check empty\n enter 6 to reverse print\n enter 7 to reverse list\n enter 8 to exit\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:printf("enter data to add node\n");
						scanf("%d",&data);
						add(data);
						break;
				case 2: printf("enter data and position\n");
						scanf("%d %d",&data,&pos);
						insert(data,pos);
						break;
				case 3: Count();
						break;
				case 4: printlist();
						break;
				case 5: IsEmpty();
						break;
				case 6:PrintReverse();
						break;
		
				case 8:return 0;
			}
		}
		
	}
