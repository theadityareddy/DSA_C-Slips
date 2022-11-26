// Write a ‘C’ program to create a Binary tree, traverse it using recursive operations like  inorder, preorder and postorder and display the result of each one separately.
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
void preorder(BSTnode*);
void inorder(BSTnode*);
void postorder(BSTnode*);

int main()
{
    BSTnode* root = NULL;
    int choice;

    root = create();
    do
    {
        printf("\n\n1: preorder");
        printf("\n2: Inorder");
        printf("\n3: Postorder");
        printf("\n4: Quit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
            {
                case 1: preorder(root);
                        break;

                case 2: inorder(root);
                        break;

                case 3: postorder(root);
                        break;
            }

    }while(choice != 4);

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
void preorder(BSTnode* T)
{
    if(T != NULL)
        {
            printf("%d ", T->data); 
            display(T->left);
            display(T->right);
        }
}
void inorder(BSTnode* T)
{
    if(T != NULL)
        {
            inorder(T->left);
            printf("%d ", T->data); 
            inorder(T->right);
        }
}
void postorder(BSTnode* T)
{
    if(T != NULL)
        {
            postorder(T->left);
            postorder(T->right);
            printf("%d ", T->data); 
        }
}