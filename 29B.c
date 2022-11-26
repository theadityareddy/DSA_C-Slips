//Write a ‘C’ program to create Circular Singly Link list and display it.
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}node;
node* create(int);
void display(node*);

int main()
{
    node* rear = NULL;
    int n;

    printf("Enter how many nodes: ");
    scanf("%d", &n);
    rear = create(n);

    display(rear);
    
    return 0;
}

node* create(int n)
{
    node* rear = NULL, *temp;
    int i;

    for(i = 1; i <= n; i++)
        {
            temp = malloc(sizeof(node));
            printf("Enter data: ");
            scanf("%d", &temp->data);
            temp->next = NULL;

            if(rear == NULL)
                {
                    rear = temp;
                    rear->next = rear;
                }
            else
                {
                    temp->next = rear->next;
                    rear->next = temp;
                    rear = temp;
                }
        }

    return rear;
}
void display(node* rear)
{
    node* p;

    p = rear->next;
    do
    {
        printf("%d->", p->data);
        p = p->next;
    }while(p != rear->next);
}