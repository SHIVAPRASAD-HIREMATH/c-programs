	#include<stdio.h>
	#include<stdlib.h>
	#define N 10
	int arr[N],front=-1,rear=-1;
	
	int IsEmpty(void)
	{
		if(front == -1 && rear == -1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	
	int IsFull()
	{
		if((rear+1)%N == front)
		{
			return 1;
		}
		else
		{
			return 0;
		}	
	}
	
	void Enqueue(int data)
	{
		if(IsFull())
		{
			printf("queue is full\n");
		}
		else
		{
			
			if(IsEmpty())
			{
				front = 0; rear = 0;
			}
			else
			{
				rear = (rear+1)%N;
			}
			arr[rear]=data;
		}
	}
	
	void Dequeue(void)
	{
		if(IsEmpty())
		{
			printf("queue is empty\n");
		}
		else if(front == rear)
		{
			printf("queue is empty\n");
			front = -1 ; rear = -1;
		}
		else
		{
			front = (front+1)%N;
		}
	}
	
	void Display(void)
	{
		int i;
		for( i=front;i!=rear;i++)
		{
			printf("%d ",arr[i]);
		}
		printf("%d ",arr[i]);
		printf("\n");
	}
	
	int main()
	{
		Enqueue(10);
		Enqueue(400);
		Enqueue(130);
		Dequeue();
		Display();
	}
