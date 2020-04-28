
#include <stdio.h>
 
#define MAX 50
 
struct que
 {
 	int data[MAX];
 	int rear;
 	int front;
 } q;
 
 

void initalize();
void enque();
void deque();
void display();
int isfull();
int isempty();

/*int queue_array[MAX];
int rear = - 1;
int front = - 1;*/
main()
{   
     printf("************************ DSA PRACTICAL 7A(QUEUE) ************************ \n\n");
	 printf("MY ROLL NO IS 22206\n");
	 printf("OOOOOOOOOOOOOOOOOOOOOOO    IMPLEMENTING QUEUE    OOOOOOOOOOOOOOOOOOOOOOO\n\n");
	initalize();
    int choice;
    while (1)
    {
      
        printf("--------------------------------------\n");
        printf("1.ENQUE  2.DEQUE  3.DISPLAY 4.EXIT \n");
        printf("--------------------------------------\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            enque();
            break;
            case 2:
            deque();
            break;
            case 3:
            display();
            break;
            case 4:
            return;
            default:
            printf("Wrong choice \n");
        } /* End of switch */
    } /* End of while */
} /* End of main() */

 void initalize()
{
	q.front=q.rear=-1;
}

int isfull()
{
	if(q.rear==MAX-1)
	{
		printf("Queue Overflow \n");
	}
	return(-1);
	
}

int isempty()
{
	if(q.rear== -1)
	{
        printf("Queue Underflow \n");
        return ;
    }
	return(-1);

}


void enque()
{
    int additem;	
    isfull();
    
		
        if (q.front == - 1)
        q.front = 0;
        printf("Inset the element in queue : ");
        scanf("%d", &additem);
        q.rear = q.rear  + 1;
        q.data[q.rear] = additem;
    
} /* End of insert() */
 
void deque()
{
    /*if (queue->front == - 1 || queue->front > rear)*/
    isempty();
    
    
        printf("Element deleted from queue is : %d\n", q.data[q.front]);
        q.front = q.front + 1;
    
} /* End of delete() */
 
void display()
{
    int i;
    if (q.front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = q.front; i <= q.rear; i++)
            printf("%d ", q.data[i]);
        printf("\n");
    }
} /* End of display() */







