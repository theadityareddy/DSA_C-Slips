#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
    int data;
    struct queue* next;
}queue;

queue* add(queue* Q, int x)
{
    queue* temp;

    temp = (queue*)malloc(sizeof(queue));
    temp->data = x;
    temp->next = NULL;

    if(Q == NULL)
        temp->next = temp;
    else
        {
            temp->next = Q->next;
            Q->next = temp; 
        }
    Q = temp;

    return Q;
}

int isempty(queue* Q)
{
    if(Q == NULL)
        return 1;
    else
        return 0;
}

queue* delet(queue* Q)
{
    queue* front;
    int x;

    if(!isempty(Q))
        {
            front = Q->next;
            x = front->data;
            printf("The deleted element is %d", x);
            
            if(front != Q)
                {
                    Q->next = front->next;
                    front->next = NULL;
                    free(front);
                }
            else
                {
                    Q = NULL;
                    front->next = NULL;
                    free(front);
                }
        }
    else
        printf("The queue is empty");

    return Q;
}

void display(queue* Q)
{
    queue* p;

    if(!isempty(Q))
        {
            p = Q->next;
            do
            {
                printf("%d ", p->data);
                p = p->next;
            }while(p != Q->next);
        }
    else
        printf("Queue is empty");
}

int peek(queue* Q)
{
    int x = -1;

    if(!isempty(Q))
        x = (Q->next)->data;
    else
        printf("Queue is empty");

    return x;
}

queue* init(queue* Q)
{
    return NULL;
}