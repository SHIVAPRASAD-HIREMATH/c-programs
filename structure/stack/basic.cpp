	#include<stdio.h>
	#include<stdlib.h>
	
	int list[10];
	int count = 0;
	
	void push(int data)
	{
		list[count++]=data;
	}
	
	int pop(void)
	{
		return(list[--count]);
	}
	
	int top(void)
	{
		return(list[count-1]);
	}
	
	int IsEmpty(void)
	{
		return((count == 10 )? 1 : 0);
		#if 0
		if(count == 0)
		{
			return (1);
		}
		else
		{
			return (0);
		}
		#endif
	}
	
	int IsFull(void)
	{
		if(count == 10)
		{
			return (1);
		}
		else
		{
			return (0);
		}
	}
	
	void DisplayStack()
	{
		for(int i=0;i<count;i++)
		{
			printf("%d ",list[i]);
		}
		printf("\n");
	}
	
	int main()
	{
		push(10);
		push(5);
		push(3);
		push(9);
		push(17);
		push(10);
		push(5);
		push(3);
		push(9);
		push(17);	
		DisplayStack();	 
		printf("%d  ",IsFull());
		printf("%d  ",count);
		DisplayStack();	 
		 return 0;
	}
