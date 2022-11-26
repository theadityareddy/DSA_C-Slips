//Write a ‘C’ program to create a Binary Search tree and implements following functions
// -	Create Binary Search Tree						
// -	Search a node in binary search tree					
// -      Display a binary search tree	 (Post order Traversal)
#include<stdio.h>
#include<stdlib.h>
typedef struct BSTnode
{
    struct BSTnode* left;
    int data;
    struct BSTnode* right;
}BSTnode;

BSTnode* create();
BSTnode* insert(BSTnode*, int);
void display(BSTnode*);
void display(BSTnode*);
int search(BSTnode*, int);

int main()
{
    BSTnode* root = NULL;
    int i, x, cnt, choice;

    root = create();
    do
    {
        printf("\n\n1: Search");
        printf("\n2: Display");
        printf("\n3: Quit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
            {
                case 1: printf("Enter the data to be searched: ");
                        scanf("%d", &x);
                        if(search(root, x))
                            printf("%d found", x);
                        else
                            printf("%d not found", x);
                        break;

                case 2: display(root);
                        break;
            }
    }while(choice != 3);
    
    return 0;
}

BSTnode* insert(BSTnode* T, int x)
{
    BSTnode* node;

    if(T == NULL)
        {
            node = (BSTnode*)malloc(sizeof(BSTnode)); //create node
            node->data = x;
            node->left = NULL;
            node->right = NULL;
            return node;
        }
    else if(x >= T->data)
        T->right = insert(T->right, x);   //create node on right side
    else
        T->left = insert(T->left, x);       //create node on left side

    return T;
}
void display(BSTnode* T)
{
    if(T != NULL)
        {
            display(T->left);
            display(T->right);
            printf("%d ", T->data); 
        }
}
BSTnode* create()
{
    BSTnode* root = NULL;
    int i, n, x;

    printf("Enter how many nodes: ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
        {
            printf("Enter node value: ");
            scanf("%d", &x);
            root = insert(root, x);
        }
    
    return root;
}
int search(BSTnode* T, int x)
{
    int flag = 0;

    while(T != NULL)
        {
            if(x == T->data)
                {
                    flag = 1;
                    break;
                }
            else if(x > T->data)
                T = T->right;
            else
                T = T->left;
        }

    return flag;
}