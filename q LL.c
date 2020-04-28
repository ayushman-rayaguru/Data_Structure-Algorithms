
#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int info;
    struct node *ptr;
}*front,*rear,*temp,*front1;
 
int frontcheck();
void enque(int data);
void deque();
void empty();
void display();
void create();
void queuesize();
 
int count = 0;
 
void main()
{
    int no, choice, e;
    printf("*************** DSA PRACTICAL 7B(QUEUE USING LINKED LIST) *************** \n\n");
	printf("MY ROLL NO IS 22206 \n\n");
	printf("OOOOOOOOOOOO    IMPLEMENTING QUEUE USING LINKED LIST    OOOOOOOOOOOO\n\n");
    printf("\n-----------------------------------------------------------------------\n");
    printf("\n 1)ENQUE 2)DEQUE 3)FRONT STATUS 4)EMPTY 5)EXIT 6)DISPLAY 7)QUEUE SIZE\n");
    printf("\n-----------------------------------------------------------------------\n");
 
    create();
    while (1)
    {
        printf("\nENTER CHOICE : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("ENTER DATA : ");
            scanf("%d", &no);
            enque(no);
            break;
        case 2:
            deque();
            break;
        case 3:
            e = frontcheck();
            if (e != 0)
                printf("FRONT ELEMENT : %d", e);
            else
                printf("\nNO FRONT ELEMENT IN QUEUE !");
            break;
        case 4:
            empty();
            break;
        case 5:
            exit(0);
        case 6:
            display();
            break;
        case 7:
            queuesize();
            break;
        default:
            printf("INVALID CHOICE,ENTER VALID CHOICE!! ");
            break;
        }
    }
}
 
/* Create an empty queue */
void create()
{
    front = rear = NULL;
}
 
/* Returns queue size */
void queuesize()
{
    printf("\nQUEUE SIZE : %d", count);
}
 
/* Enqueing the queue */
void enque(int data)
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(1*sizeof(struct node));
        rear->ptr = NULL;
        rear->info = data;
        front = rear;
    }
    else
    {
        temp=(struct node *)malloc(1*sizeof(struct node));
        rear->ptr = temp;
        temp->info = data;
        temp->ptr = NULL;
 
        rear = temp;
    }
    count++;
}
 
/* Displaying the queue elements */
void display()
{
    front1 = front;
 
    if ((front1 == NULL) && (rear == NULL))
    {
        printf("Queue is empty");
        return;
    }
    while (front1 != rear)
    {
        printf("%d ", front1->info);
        front1 = front1->ptr;
    }
    if (front1 == rear)
        printf("%d", front1->info);
}
 
/* Dequeing the queue */
void deque()
{
    front1 = front;
 
    if (front1 == NULL)
    {
        printf("\nCAN'T DISPLAY FROM EMPTY QUEUE");
        return;
    }
    else
        if (front1->ptr != NULL)
        {
            front1 = front1->ptr;
            printf("\nDEQUED VALUE : %d", front->info);
            free(front);
            front = front1;
        }
        else
        {
            printf("\nDEQUED VALUE : %d", front->info);
            free(front);
            front = NULL;
            rear = NULL;
        }
        count--;
}
 
/* Returns the front element of queue */
int frontcheck()
{
    if ((front != NULL) && (rear != NULL))
        return(front->info);
    else
        return 0;
}
 
/* Display if queue is empty or not */
void empty()
{
     if ((front == NULL) && (rear == NULL))
        printf("\nQUEUE EMPTY!");
    else
       printf("QUEUE NOT EMPTY!\n");
}


