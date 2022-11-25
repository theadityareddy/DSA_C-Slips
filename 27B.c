/*3 Write a ‘C’ program to create Doubly Link list and display it.*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node * preptr;
    struct node * nextptr;
}*stnode, *endnode;
void DlListcreation(int n);
void displayDlList();

int main()
{
    int n;
    stnode = NULL;
    endnode = NULL;
	printf("\n\n Doubly Linked List : Create and display a doubly linked list :\n");
    printf(" Input the number of nodes : ");
    scanf("%d", &n);
 
    DlListcreation(n); 
    displayDlList();
    return 0;
}
void DlListcreation(int n)
{
    int i, num;
    struct node *fnNode;
 
    if(n >= 1)
    {
        stnode = (struct node *)malloc(sizeof(struct node));
 
        if(stnode != NULL)
        {
            printf(" Input data for node 1 : "); // assigning data in the first node
            scanf("%d", &num);
            stnode->num = num;
            stnode->preptr = NULL;
            stnode->nextptr = NULL;
            endnode = stnode;
// putting data for rest of the nodes
            for(i=2; i<=n; i++)
            {
                fnNode = (struct node *)malloc(sizeof(struct node));
                if(fnNode != NULL)
                {
                    printf(" Input data for node %d : ", i);
                    scanf("%d", &num);
                    fnNode->num = num;
                    fnNode->preptr = endnode;    // new node is linking with the previous node
                    fnNode->nextptr = NULL;
 
                    endnode->nextptr = fnNode;   // previous node is linking with the new node
                    endnode = fnNode;            // assign new node as last node
                }
                else
                {
                    printf(" Memory can not be allocated.");
                    break;
                }
            }
        }
        else
        {
            printf(" Memory can not be allocated.");
        }
    }
}
void displayDlList()
{
    struct node * tmp;
    int n = 1;
    if(stnode == NULL)
    {
        printf(" No data found in the List yet.");
    }
    else
    {
        tmp = stnode;
        printf("\n\n Data entered on the list are :\n");
 
        while(tmp != NULL)
        {
            printf(" node %d : %d\n", n, tmp->num);
            n++;
            tmp = tmp->nextptr; // current pointer moves to the next node
        }
    }
}
