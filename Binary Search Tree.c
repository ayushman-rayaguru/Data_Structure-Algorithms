# include <stdio.h>
# include <conio.h>
# include <stdlib.h>
 
typedef struct BST {
   int data;
   struct BST *left, *right;
} node;
 
void insert(node *, node *);
void inorder(node *);
void preorder(node *);
void postorder(node *);
node *find(node *, int, node **);
 
void main() 

{
	printf("\n*************** DSA PRACTICAL 8(BST OPERATIONS IN C) *************** \n\n");
	printf("MY ROLL NO IS 22206\n\n");
	printf("OOOOOOOOOOOOOO    BINARY SEARCH TREE OPERATIONS  OOOOOOOOOOOOOO\n\n");
   int choice;
   char ans = 'N';
   int key;
   node *new_node, *root, *tmp, *p;
   node *get_node();
   root = NULL;
   
   do {
   	  printf("\n---------------------------------------------------\n");
      printf("1.CREATE 2.SEARCH 3.RECURSIVE TRAVERSALS 4.EXIT \n");
      printf("\n---------------------------------------------------\n");
      printf("\nENTER YOUR CHOICE :");
      scanf("%d", &choice);
 
      switch (choice) {
      case 1:
         do {
            new_node = get_node();
            printf("\nENTER THE ELEMENT\n ");
            scanf("%d", &new_node->data);
 
            if (root == NULL) // TREE CANT EXIST
               root = new_node;
            else
               insert(root, new_node);
 
            printf("MORE ELEMENTS ?(y/n)\n ");
            ans = getch();
         } while (ans == 'y');
         break;
 
      case 2:
         printf("WHICH ELEMENT IS TO BE SEARCHED ?\n  ");
         scanf("%d", &key);
 
         tmp = find(root, key, &p);
         printf("\n PARENT OF NODE %d is %d", tmp->data, p->data);
         break;
 
      case 3:
         if (root == NULL)
            printf("TREE CANT EXIST");
         else {
            printf("\n INORDER FORMAT : ");
            inorder(root);
            printf("\n PREORDER FORMAT : ");
            preorder(root);
            printf("\n POSTORDER FORMAT : ");
            postorder(root);
         }
         break;
      }
   } while (choice != 4);
}

 //Get new Node

node *get_node() {
   node *temp;
   temp = (node *) malloc(sizeof(node));
   temp->left = NULL;
   temp->right = NULL;
   return temp;
}

//creating a binary find tree

void insert(node *root, node *new_node) {
   if (new_node->data < root->data) {
      if (root->left == NULL)
         root->left = new_node;
      else
         insert(root->left, new_node);
   }
 
   if (new_node->data > root->data) {
      if (root->right == NULL)
         root->right = new_node;
      else
         insert(root->right, new_node);
   }
}

 //This function binary find Tree

node *find(node *root, int key, node **p) {
   node *temp;
   temp = root;
   while (temp != NULL) {
      if (temp->data == key) {
         printf("\nTHE %d ELEMENT IS  PRESENT AT", temp->data);
         return temp;
      }
      *p = temp;
 
      if (temp->data > key)
         temp = temp->left;
      else
         temp = temp->right;
   }
   return NULL;
}

//displays the tree in inorder FORMAT

void inorder(node *temp) {
   if (temp != NULL) {
      inorder(temp->left);
      printf("%d  ", temp->data);
      inorder(temp->right);
   }
}

// displays the tree in preorder FORMAT

void preorder(node *temp) {
   if (temp != NULL) {
      printf("%d  ", temp->data);
      preorder(temp->left);
      preorder(temp->right);
   }
}
 

//displays the tree in postorder FORMAT

void postorder(node *temp) {
   if (temp != NULL) {
      postorder(temp->left);
      postorder(temp->right);
      printf("%d  ", temp->data);
   }
}
