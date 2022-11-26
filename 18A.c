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
int count(BSTnode*);
void degree(BSTnode*);
int countleaf(BSTnode*);

int main()
{
    BSTnode* root = NULL;
    int i, x, cnt, choice;

    root = create();
    do
    {
        printf("\n\n1: Display");
        printf("\n2: Count nodes");
        printf("\n3: Degree of nodes");
        printf("\n4: Leaf nodes");
        printf("\n5: Quit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
            {
                case 1: display(root);
                        break;

                case 2: cnt = count(root);
                        printf("Total nodes = %d", cnt);
                        break;

                case 3: degree(root);
                        break;

                case 4: cnt = countleaf(root);
                        printf("Total no of leaf nodes = %d", cnt);
            }
    }while(choice != 5);
    
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
            printf("%d ", T->data); 
            display(T->left);
            display(T->right);
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
int count(BSTnode* T)
{
    int cnt = 0;

    if(T != NULL)
        {
            cnt++;
            cnt = cnt + count(T->left);
            cnt = cnt + count(T->right);
        }

    return cnt;
}
int countleaf(BSTnode* T)
{
    int cnt = 0;

    if(T != NULL)
        {
            if(T->left==NULL && T->right==NULL)
                {
                    cnt++;
                    printf("%d ", T->data);
                }
            cnt = cnt + countleaf(T->left);
            cnt = cnt + countleaf(T->right);    
        }

    return cnt;
}
void degree(BSTnode* T)
{
    if(T != NULL)
        {
            if(T->left!=NULL && T->right!= NULL)
                printf("\nDegree of %d is 2", T->data);
            else if((T->left==NULL && T->right!=NULL) || (T->left!=NULL && T->right==NULL))
                printf("\nDegree of %d is 1", T->data);
            else
                printf("\nDegree of %d is 0", T->data);

            degree(T->left);
            degree(T->right);
        }
}