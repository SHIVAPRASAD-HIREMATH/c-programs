//program for circular queue.

#include<stdio.h>               //including header file for std i.p o/p operations
#include<stdlib.h>
#define SIZE 5                  //defining the macros.
int arr[SIZE],front=-1,rear=-1;      //defining array and initializing queue indices globally.      


void display()                                       //function for displaying the queue.
{
   if(front==-1 && rear==-1)
      printf("queue is empty\n");
      
   else if((rear+1)%SIZE==front)
      printf("queue is full\n");
   else
   {
      int i;
      for(i=front;i!=rear;i=(i+1)%SIZE)
      {
         printf("%d\n",arr[i]);
      }
      printf("%d\n",arr[i]);
   }
   printf("\n");
}

void enq(int data)                  //function for entering element onto the queue.
{
   if((rear+1)%SIZE==front)
   {
      display();                     //check whether queue is full or not.
   }
   else
   {
      if(front==-1 && rear==-1)
      {
         rear=0;
         front=0;
         arr[rear]=data;
      }   
      else if((rear=rear+1)%SIZE!=front)
      {
         arr[rear]=data;   
      }
      
      //arr[rear]=data;
   }
}
void dq(void)                                 //function to delete element from the queue.
{
   
   if(front==-1 && rear==-1)
   {
      display();               // to check no elements in queue 
   }
   else if(front==rear)
   {
      arr[front]=0;
      front=-1;
      rear=-1;
   }
   else
   {
      front=(front+1)%SIZE;
      arr[front-1]=0;
   }
}


int main()                                       //main program starts from here.
{
   printf("***********QUEUE PROGRAM***********\n\n");
   enq(9);
   enq(15);   
   enq(12);
   enq(111);
   display();
   dq();
   display();      

return 0;

}    
