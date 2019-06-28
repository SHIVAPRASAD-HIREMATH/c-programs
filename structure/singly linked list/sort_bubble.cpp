	#include<stdio.h>
	#include<stdlib.h>

	
	typedef struct node_block 
	{
		int data;
		struct node_block *addr;
	} node;
	
	node* Head = NULL;
	int count=0;
	
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
	
	void swap(int x,int y)
	{
	  node *prvx=NULL,*curx=Head;
	  while(curx && (curx->data != x ))
	  {
	  	prvx=curx;
	  	curx=curx->addr;
	  }
	  
	  node *prvy=NULL,*cury=Head;
	  while(cury && (cury->data != y) )
	  {
	  	prvy=cury;
	  	cury=cury->addr;
	  }
	  
	  if(prvx != NULL)
	  {
	  	prvx->addr=cury;
	  }
	  else
	  {
	  	Head=cury;
	  }
	  
	  if(prvy != NULL)
	  {
	  	prvy->addr = curx;
	  } 
	 // else
	  {
	 // 	Head=curx;
	  }
	  node *temp;
	  temp=cury->addr;
	  cury->addr=curx->addr;
	  curx->addr=temp;
	}
	
	
	void sort(void)
	{
		node* first;
		node* last;
		for(int i=0;i<count-1;i++)
		{
			printf("first loop\n");
			for(int k=0;k<count-i-1;k++)
			{
				printf("second loop\n");
				first=PositionTraverse(k);
				last=first->addr;
				printf("first=%d last=%d\n  ",first->data,last->data);
				if(first->data > last->data)
				{
					printf("swap\n");
				   	swap(first->data,last->data);
				   	printf("after swaping\n");
				   	printlist();
				}	
			}
		}
	}
	


	
	int main()
	{
		add(1000);
		add(10);
		add(70);
		add(300);
		add(15);
		printlist();
	//	printf("\n%d",count);
		sort();
		printlist();
		
		return 0;
	}
	
