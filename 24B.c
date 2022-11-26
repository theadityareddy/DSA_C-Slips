// Write a ‘C’ program to remove last node of the singly linked list and insert it at the beginning of list.
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}node;

int x;

node* create(int);
void print(node*);
node* insert(node*, int);
node* deleteLast(node*);

int main()
{
    node* head = NULL;
    int n;

    printf("Enter how many nodes: ");
    scanf("%d", &n);
    head = create(n);

    deleteLast(head);
    head = insert(head, x);
    print(head);
    
    return 0;
}

node* deleteLast(node* head)
{
    node* q, *p;

    if(head == NULL)
        printf("Nothing to delete");
    else if(head->next == NULL)
        {   
            q = head;
            x = head->data;
            head = NULL;
            free(q);
        }
    else
        {
            p = head;
            q = p->next;
            while(q->next != NULL)
                {
                    p = p->next;
                    q = q->next;
                }
            x = q->data;
            p->next = NULL;
            free(q);
        }
    return head;
}
node* insert(node* head, int x)
{
    node* temp;

    temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->next = NULL;

    if(head == NULL)
        head = temp;
    else
        {
            temp->next = head;
            head = temp;
        }
        
    return head;
}
node* create(int n)
{
    node* head, *p, *temp;
    int i;

    head = (node*)malloc(sizeof(node));
    printf("Enter data for head node: ");
    scanf("%d", &head->data);
    head->next = NULL;

    p = head; 
    for(i = 1; i < n; i++)
        {
            temp = (node*)malloc(sizeof(node));
            printf("Enter data: ");
            scanf("%d", &temp->data);
            temp->next = NULL;
            p->next = temp;
            p = p->next;
        }
    return head;
}
void print(node* head)
{
    node* p;

    for(p = head; p != NULL; p=p->next)
        printf("%d->", p->data);
    printf("NULL");
}