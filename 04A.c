/*Write menu driven program using 'C' for Binary Search Tree. The menu includes
-	Create a Binary Search Tree
-	Traverse it by using Inorder and Postorder traversing technique*/



#include <stdio.h>
#include <stdlib.h>


struct btnode
{
    int value;
    struct btnode *l;
    struct btnode *r;
}*root = NULL, *temp = NULL, *t2, *t1;


// Function declaration
void create();
void search(struct btnode *t);
void inorder(struct btnode *t);
void postorder(struct btnode *t);

 
int flag = 1;


void main() {
    int ch;
 
    printf("\nOPERATIONS ---");
    printf("\n1 - Insert an element into tree\n");
    printf("2 - Inorder Traversal\n");
    printf("3 - Postorder Traversal\n");
    printf("4 - Exit\n");
    while(1) {
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:    
            create();
            break;
        case 2:    
            inorder(root);
            break;
        case 3:    
            postorder(root);
            break;
        case 4:    
            exit(0);
        default :     
            printf("Invalid Input!");
            break;    
        }
    }
}
  

void create() {
    int data;
 
    printf("Enter data of node to be inserted : ");
    scanf("%d", &data);
    temp = (struct btnode *)malloc(1*sizeof(struct btnode));
    temp->value = data;
    temp->l = temp->r = NULL;
    if (root == NULL) 
        root = temp;
    else    
        search(root);    
}
 
// find the right position in the tree to insert the data
void search(struct btnode *t) {
    if ((temp->value > t->value) && (t->r != NULL)) {
	    /* value more than root node value insert at right */
        search(t->r);
	}
	else if ((temp->value > t->value) && (t->r == NULL)) {
		t->r = temp;
	}        
    else if ((temp->value < t->value) && (t->l != NULL)) {
	   /* value less than root node value insert at left */
        search(t->l);
    }
    else if ((temp->value < t->value) && (t->l == NULL)) {
    	t->l = temp;
	}       
}
 
void inorder(struct btnode *t) {
    if (root == NULL) {
        printf("No elements in a tree to display");
        return;
    }
    
    if (t->l != NULL) {
    	inorder(t->l);
	} 
        
    printf("%d -> ", t->value);
    
	if (t->r != NULL) {
		inorder(t->r);
	}  
}


void postorder(struct btnode *t) {
    if (root == NULL) {
        printf("No elements in a tree to display ");
        return;
    }
    
	if (t->l != NULL) {
    	postorder(t->l);
	}
        
    if (t->r != NULL) {
    	postorder(t->r);
	}
        
    printf("%d -> ", t->value);
}



