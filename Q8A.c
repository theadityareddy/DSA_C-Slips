#include <stdio.h>
#include <stdlib.h>
 
struct TreeNode {
    int data;
    struct TreeNode *leftChildNode;
    struct TreeNode *rightChildNode;
};
 
typedef struct TreeNode node;
node *rootNode = NULL;
 
/*  Function to insert a node in a Binary search tree  */
void insertNode(int i, node **n) {
    if (*n == NULL) {
        (*n) = (node*)malloc(sizeof(node));
        (*n)->leftChildNode = NULL;
        (*n)->rightChildNode = NULL;
        (*n)->data = i;
    }
    else if ((*n)->data == i)
        printf("\nThis value already exists in the tree!");
    else if (i > (*n)->data)
        insertNode(i, &((*n)->rightChildNode));
    else
        insertNode(i, &((*n)->leftChildNode));
}
/* End of insertNode() */
 
/*  Function to search an element in a Binary search tree  */
void searchNode(int i, node **n) {
    if (*n == NULL)
        printf("\nValue does not exist in tree!\n");
    else if((*n)->data == i)
        printf("\nValue found!\n");
    else if(i > (*n)->data)
        searchNode(i, &((*n)->rightChildNode));
    else
        searchNode(i, &((*n)->leftChildNode));
}
/* End of serachNode() */

void display(struct TreeNode *n)
{
	if(rootNode==NULL)
	{
		printf("No elements");
	}
	printf("%d->",n->data);
	if(n->leftChildNode!=NULL)
	{
		display(n->leftChildNode);
	}
	if(n->rightChildNode!=NULL)
	{
		display(n->rightChildNode);
	}
	
 } 
/* The main() program begins */
int main()
{
    int ch, num;
    while(1) {
        printf("\n1.Insert\n2.Search\n3.Display\n4.Exit\n");
        printf("\nChoice: ");
        scanf("%d", &ch);
        switch(ch) {
        case 1: 
            printf("\nEnter an element: ");
            scanf("%d", &num);
            insertNode(num, &rootNode);
            break;
        case 2: 
            printf("\nEnter the element to be searched for: ");
            scanf("%d", &num);
            searchNode(num, &rootNode);
            break;
        case 3:
        	display(rootNode);
        	break;
        default: 
           exit(0);
        }
    }
    return 0;
}





