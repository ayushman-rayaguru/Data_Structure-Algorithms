#include <stdio.h>
#include <stdlib.h>
int array[100],n, c, d,i,a,b,choice,step,min_idx;
void bubble_sort(int array[], int n);
void selection_sort(int array[], int n);
void insertion_sort(int array[], int n);
void read(int array[],int n);
void display(int array[],int n); 
int swap(int*x,int*y);

int main()
{
	printf("\t ******** DSA PRACTICAL 2 (SORTING TECHNIQUE)********\n\n");
	
	printf("MY ROLL NO IS :22206\n \n");
    
    printf("MENU FOR SORTING ELEMENTS(BUBBLE/INSERTION/SELECTION) SORT\n\n");
    
    printf("ENTER THE SIZE OF THE ARRAY:");

    scanf("%d",&n);

   /* printf("ENTER THE ELEMENTS OF THE ARRAY:\n\n");*/
    
	printf("___________________\n");

    printf("1.BUBBLE SORT\n");
	printf("2.SELECTION SORT\n");
    printf("3.INSERTION SORT\n");
    
    printf("___________________\n");

    printf("ENTER YOUR CHOICE:");

    scanf("%d",&choice);

	switch(choice)     //USER MENU FOR WHICH TYPE OF SORT
    {

    case 1:
        read(array,n);
        bubble_sort(array,n);
        printf("The Sorted Array is:\n");
       /* display(array,n);*/
        break;

    case 2:
        read(array,n);
        selection_sort(array,n);
        display(array,n);
        
        break;
        
 	case 3:
        read(array,n);
        insertion_sort(array,n);
        display(array,n);
        break;

	default:

        printf("Please Try again\nEnter Valid Choice!!!");

}
	

  /*printf("Enter number of elements\n");
  scanf("%d", &n);
 
  printf("Enter %d Numbers\n", n);
 
  for (c = 0; c < n; c++)
    scanf("%d", &array[c]);*/
 
   
 
 /* printf("Sorted list in ascending order:\n");
 
  for ( c = 0 ; c < n ; c++ )
     printf("%d\n", array[c]);*/
 
  return 0;
}
 
void bubble_sort(int list[], int n)
{
  long c, d, t;
 
  for (c = 0 ; c < ( n - 1 ); c++)    //d=comparison  and c = pass
  {
  printf(" \n========================================\n pass %d : ", c+1 );
  
    for (d = 0 ; d < n - c - 1; d++)
    {
     printf(" \n No of Comparison %d : ", d );
     
      if (list[d] > list[d+1])
      {
      	
        swap(&list[d],&list[d+1]);
        
		/* Swapping 
        
        t         = list[d];
        list[d]   = list[d+1];
        list[d+1] = t;*/
      }
      display(array,n);
    }
  }
}

 void insertion_sort(int array[], int n)
{
  for(step=1; step<n; step++)
  {
  int key = array[step];
  int j=step-1;
  while(key<array[j] && j>=0)
  {
    // For descending order, change key<array[j] to key>array[j].
    array[j+1] = array[j];
    --j;
  }
  array[j+1]=key;
  }
}
 
 
 
 void selection_sort(int array[], int n)
{
  for (step = 0; step < n - 1; step++)
  {
    min_idx = step;
    for (i = step + 1; i < n; i++)
    {
      if (array[i] < array[min_idx])
        min_idx = i;
    }
   
   swap(&array[min_idx],&array[step]);
  }
}


	
	
	int swap(int*x,int*y)
	{
		int temp;
		temp = *x;
		*x = *y;
		*y = temp;
	}





/*Read Function*/
void read(int array[],int n)
{ 

 	printf("Enter number of elements\n");
  	scanf("%d", &n);
 	printf("Enter %d Numbers: \t", n);
	 
	 for(i=0;i<n;i++)
    {

        scanf("%d",&array[i]);
	
    }
}



void display(int array[],int n)
{

    
    for(i=0;i<n;i++)
    	{   
    	
			printf("%d   ",array[i]);
    	
		}		
}
