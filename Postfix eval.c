// C program to evaluate value of a postfix Expression
#include <stdio.h> 
#include <string.h> 
#include <ctype.h> // FOR IDENTIFYING CHARACTERS LIKE + - * / IN expression
#include <stdlib.h> 
  
// Stack STRUCTURE
struct Stack 
{ 
    int top; 
    int limit; 
    int* data; 
}; 
  
// Stack Operations 
struct Stack* createStack(int limit ) 
{ 
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)); 
  
    if (!stack) return NULL; 
  
    stack->top = -1; 
    stack->limit = limit; 
    stack->data = (int*) malloc(stack->limit * sizeof(int)); 
  
    if (!stack->data) return NULL; 
  
    return stack; 
} 
  
int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1 ; 
} 
  
char peek(struct Stack* stack) 
{ 
    return stack->data[stack->top]; 
} 
  
char pop(struct Stack* stack) 
{ 
    if (!isEmpty(stack)) 
        return stack->data[stack->top--] ; 
    return '!'; 
} 
  
void push(struct Stack* stack, char op) 
{ 
    stack->data[++stack->top] = op; 
} 
  
  
// The main function that returns value of a given postfix Expression
int Postfix_Eval(char* Expression) 
{ 
    // CREATE a stack of limit equal to Expression size 
    struct Stack* stack = createStack(strlen(Expression)); 
    int i; 
  
    // CHECK stack was created successfully 
    if (!stack) 
	return -1; 
  
    // Scan all characters one by one 
    for (i = 0; Expression[i]; ++i) 
    { 
        // If the scanned character is an operand (number here), 
        // push it to the stack. 
        if (isdigit(Expression[i])) 
            push(stack, Expression[i] - '0'); 
  
     
        else
        { 
            int op1 = pop(stack); 
            int op2 = pop(stack); 
            switch (Expression[i]) 
            { 
            case '+': push(stack, op2 + op1); 
			        break; 
            case '-': push(stack, op2 - op1); 
					break; 
            case '*': push(stack, op2 * op1); 
					break; 
            case '/': push(stack, op2/op1); 
					break; 
            } 
        } 
    } 
    return pop(stack); 
} 
  

int main() 
{ 	

	printf("\n*************** DSA PRACTICAL 10(POSTFIX EVALUATION IN C) *************** \n\n");
	printf("MY ROLL NO IS 22206\n");
	printf("OOOOOOOOOOOOOO    IMPLEMENTING POSTFIX USING STACK   OOOOOOOOOOOOOO\n\n");
    char Expression[10];
    printf("ENTER THE EXPRESSION IN POSTFIX ORDER : ");
	gets(Expression);
    printf ("POSTFIX EVALUATION: %d", Postfix_Eval(Expression)); 
    return 0; 
} 
