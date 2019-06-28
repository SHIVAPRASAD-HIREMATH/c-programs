	#include<stdio.h>
	#include<stdlib.h>

	
	typedef struct node_block 
	{
		int data;
		struct node_block *addr;
	} node;
	
	node* Head = NULL;
	int count=0;	
	
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
	
	void add(int data)
	{
		node *temp;
		temp=(node*)malloc(sizeof(node));
		temp->data = data;
		temp->addr=Head;
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
			temp1=temp1->addr;
		}
		printf("\n");
	}
	
	void  Count(void)
	{
		printf("\t%d\n",count);
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
			if(pos == 1)
			{
				temp->data=data;
				temp->addr=Head;
				Head=temp;
			}
			else
			{
				for(int i=1;i<pos-1;i++)
				{
					temp1=temp1->addr;
				}
				
				temp->data=data;
				temp->addr=temp1->addr;
				temp1->addr=temp;
			}
			count++;
		}
	}
	
	void PrintReverse(void)
	{
		node* temp;
		temp = Head;
		for(int i=0;i<count;i++)
		{
			temp = Head;
			for(int k=1;k<count-i;k++)
			{
				temp = temp->addr;
			}
			printf("%d ",temp->data);
		}
		printf("\n");
	}
	
	node* PositionTraverse(int pos)
	{
		node* temp;
		temp = Head;
		for(int k=0;k<pos;k++)
		{
			temp = temp->addr;
		}
		return temp;
	}
	
	
	void ReverseList()
	{
		node* last;
		node* first;
		node* temp;
		for(int i=1;i<count;i++)
		{
		  first=PositionTraverse(count-1-i);
          last=first->addr;
          
          if(i==1)
          {
          	temp=last;
		  }
		  if(i == count-1)
		  {
		  	first->addr=NULL;
		  }
          last->addr=first;
		}
		Head = temp;
		printlist();
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
				case 7:ReverseList();
						break;
				case 8:return 0;
			}
		}
	}

