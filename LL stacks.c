
//C Program to Implement a Stack using Linked List
 
#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int info;
    struct node *ptr;
}*top,*top1,*temp;
 
int topelement();
void push(int data);
void pop();
void empty();
void display();
void free_stack();
void stack_count();
void create();
 
int count = 0;
 
void main()
{
	printf("************************ DSA PRACTICAL 6A ************************ \n\n");
	printf("MY ROLL NO IS 22206\n");
	printf("OOOOOOOOOOOOOO  IMPLEMENTING STACK USING LINKED LIST  OOOOOOOOOOOOOO\n\n");
	
    int no, choice, e;
 printf("--------------------------------------------\n");
 printf("1.PUSH  2.POP     3.TOP   4.EMPTY  \n");
 printf("5.EXIT  6.DISPLAY 7.COUNT 8.FREE STACK \n");
 printf("--------------------------------------------\n");

    create();
 
    while (1)
    {
        printf("\nENTER CHOICE: ");
        scanf("%d", &choice);
 
        switch (choice)
        {
        case 1:
            printf(" ENTER DATA \n : ");
            scanf("%d", &no);
            push(no);
            break;
        case 2:
            pop();
            break;
        case 3:
            if (top == NULL)
                printf("No ELEMENTS IN STACK \n");
            else
            {
                e = topelement();
                printf("\n TOP ELEMENT IS: %d", e);
            }
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
            stack_count();
            break;
        case 8:
            free_stack();
            break;
        default :
            printf(" WRONG CHOICE ! ENTER VALID CHOICE \n ");
            break;
        }
    }
}
 
/* Create empty stack */
void create()
{
    top = NULL;
}
 
/* Count stack elements */
void stack_count()
{
    printf("\n NO OF ELEMENTS IN STACK: %d", count);
}
 
/* Push data into stack */
void push(int data)
{
    if (top == NULL)
    {
        top =(struct node *)malloc(1*sizeof(struct node));
        top->ptr = NULL;
        top->info = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = top;
        temp->info = data;
        top = temp;
    }
    count++;
}
 
/* Display stack elements */
void display()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("STACK IS EMPTY \n ");
        return;
    }
 
    while (top1 != NULL)
    {
        printf("%d ", top1->info);
        top1 = top1->ptr;
    }
 }
 
/* Pop Operation on stack */
void pop()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("\n NO POP FROM EMPTY STACK ");
        return;
    }
    else
        top1 = top1->ptr;
    printf("\n POPPED VALUE : %d", top->info);
    free(top);
    top = top1;
    count--;
}
 
/* Return top element */
int topelement()
{
    return(top->info);
}
 
/* Check if stack is empty or not */
void empty()
{
    if (top == NULL)
        printf("\n STACK IS EMPTY");
    else
        printf("\n STACK IS WITH %d elements", count);
}
 
/* Destroy entire stack */
void free_stack()
{
    top1 = top;
 
    while (top1 != NULL)
    {
        top1 = top->ptr;
        free(top);
        top = top1;
        top1 = top1->ptr;
    }
    free(top1);
    top = NULL;
 
    printf("\n STACK WAS DEALLOCATED ! \n");
    count = 0;
}
