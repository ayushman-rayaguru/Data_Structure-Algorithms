#include<stdio.h>
 #include<stdlib.h>


struct poly
 {
	 int coeff;
	 int expo;
 };


 struct poly p1[10],p2[10],p3[10];

 int Read_Poly(struct poly []);
 int Add_Poly(struct poly [],struct poly [],int ,int ,struct poly []);
 int Sub_Poly(struct poly [],struct poly [],int ,int ,struct poly []);
 int Multi_Poly(struct poly[],struct poly[],int ,int ,struct poly []);
 void Display_Poly( struct poly [],int terms);

 int main()
 {
 	
 	printf("**** DSA PRACTICAL 11(POLYNOMIAL ADDITION,SUBTRACTION,MULTIPLICATION IN C) **** \n\n");
	printf("MY ROLL NO IS 22206\n\n");
	printf("OOOOOOOOOOOOOOOOOOOOOOO    POLYNOMIAL OPERATIONS  OOOOOOOOOOOOOOOOOOOOOOO \n\n");
	int t1,t2,t3;
 
	int ch;

	while(1){


	t1=Read_Poly(p1);
	printf(" \n FIRST POLYNOMIAL : ");
	Display_Poly(p1,t1);

	t2=Read_Poly(p2);
	printf(" \n SECOND POLYNOMIAL : ");
	Display_Poly(p2,t2);

    printf("\n------------------------------------\n");
	printf(" 1.  ADDITION OF POLYNOMIALS          \n");
	printf(" 2.  SUBTRACTION OF POLYNOMIALS       \n");
	printf(" 3.  MULTIPLICATION OF POLYNOMIALS    \n");
	printf(" 4.  EXIT                             \n");
	printf("------------------------------------\n");

	scanf("%d",&ch);

	switch(ch)
	{


        case 1:{
                t3=Add_Poly(p1,p2,t1,t2,p3);
                printf(" \n\n RESULT OF ADDITION POLYNOMIAL : ");
                Display_Poly(p3,t3);
                break;
                }
        case 2:{
                t3=Sub_Poly(p1,p2,t1,t2,p3);
                printf(" \n\n RESULT OF SUBTRACTION POLYNOMIAL : ");
                Display_Poly(p3,t3);
                break;
                }

        case 3:{
        		t3=Multi_Poly(p1,p2,t1,t2,p3);
                printf(" \n\n RESULT OF MULTIPLIED POLYNOMIAL : ");
                Display_Poly(p3,t3);
                break;
        		
                

                }
                
        case 4:{
				exit(0);
                
				break;
				}
        
        default:{
                printf("\n PLEASE ENTER VALID CHOICE");
                }


	}


	}


	printf("\n");

	return 0;
 }

 int Read_Poly(struct poly p[10])
 {
	int t1,i;

	printf("\n\n ENTER THE TOTAL NO OF TERMS IN POLYNOMIAL :");
	scanf("%d",&t1);

	printf("\n ENTER THE COEFFICIENT AND EXPONENT IN DESCENDING ORDER\n");
	for(i=0;i<t1;i++)
	{
		printf("   ENTER THE COEFFICIENT(%d): ",i+1);
		scanf("%d",&p[i].coeff);
		printf("   ENTER THE EXPONENT   (%d): ",i+1);
		scanf("%d",&p[i].expo);
	}
	return(t1);
 }

 int Add_Poly(struct poly p1[10],struct poly p2[10],int t1,int t2,struct poly p3[10])
 {
	int i,j,k;


	i=0;
	j=0;
	k=0;

	while(i<t1 && j<t2)
	{
		if(p1[i].expo==p2[j].expo)
		{
			p3[k].coeff=p1[i].coeff + p2[j].coeff;
			p3[k].expo=p1[i].expo;

			i++;
			j++;
			k++;
		}
		else if(p1[i].expo>p2[j].expo)
		{
			p3[k].coeff=p1[i].coeff;
			p3[k].expo=p1[i].expo;
			i++;
			k++;
		}
		else
		{
			p3[k].coeff=p2[j].coeff;
			p3[k].expo=p2[j].expo;
			j++;
			k++;
		}
	}


	while(i<t1)
	{
		p3[k].coeff=p1[i].coeff;
		p3[k].expo=p1[i].expo;
		i++;
		k++;
	}

	while(j<t2)
	{
		p3[k].coeff=p2[j].coeff;
		p3[k].expo=p2[j].expo;
		j++;
		k++;
	}

	return(k);
 }


 int Sub_Poly(struct poly p1[10],struct poly p2[10],int t1,int t2,struct poly p3[10])
 {
	int i,j,k;


	i=0;
	j=0;
	k=0;

	while(i<t1 && j<t2)
	{
		if(p1[i].expo==p2[j].expo)
		{
			p3[k].coeff=p1[i].coeff - p2[j].coeff;
			p3[k].expo=p1[i].expo;

			i++;
			j++;
			k++;
		}
		else if(p1[i].expo>p2[j].expo)
		{
			p3[k].coeff=p1[i].coeff;
			p3[k].expo=p1[i].expo;
			i++;
			k++;
		}
		else
		{
			p3[k].coeff=p2[j].coeff;
			p3[k].expo=p2[j].expo;
			j++;
			k++;
		}
	}

	while(i<t1)
	{
		p3[k].coeff=p1[i].coeff;
		p3[k].expo=p1[i].expo;
		i++;
		k++;
	}

	while(j<t2)
	{
		p3[k].coeff=p2[j].coeff;
		p3[k].expo=p2[j].expo;
		j++;
		k++;
	}

	return(k);
 }


 void Display_Poly(struct poly p[10],int term)
 {
	int k;

	for(k=0;k<term-1;k++)
	printf("%d(x^%d)+",p[k].coeff,p[k].expo);
	printf("%d(x^%d)",p[term-1].coeff,p[term-1].expo);
}



 int Multi_Poly(struct poly p1[10],struct poly p2[10],int t1,int t2,struct poly p3[10])
 {
	int i,j,k,l,m,tempc,tempp;


	i=0;
	j=t2-1;
	k=0;
	l=t1-1;
	m=0;
	
	for(i=0;i<10;i++)
	{
		p3[i].coeff=0;
		p3[i].expo=i;
	}
	
	
	while(l>0)
	{
	
	while(j>0)
	{
			tempc=p1[l].coeff * p2[j].coeff;
			tempp=	p2[l].expo+p1[j].expo;

			p3[tempp].coeff+=tempc;

		k=tempp;

		
		
		j--;
			
	}
		l--;
	}
	
	
	printf("%d",k);
	

	return(k);
 }


