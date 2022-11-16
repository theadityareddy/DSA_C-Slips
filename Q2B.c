#include<stdio.h>  
#include<stdlib.h>  
struct node  
{  
    struct node *prev;  
    struct node *next;  
    int data;  
};  
struct node *head;  
void insertion_beginning();  
  
void display();  
 
void main ()  
{  
int choice =0;  
    while(choice != 9)  
    {   
        printf("\nChoose one option from the following list ...\n");   
        printf("\n1.Insert in Beginning\n2.Show\n3.Exit\n");  
        printf("\nEnter your choice?\n");  
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            insertion_beginning();  
            break;  
            
            case 2:  
            display();  
            break;  
            case 3:  
            exit(0);  
            break;  
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
}  
void insertion_beginning()  
{  
   struct node *ptr,*temp;   
   int item;  
   ptr = (struct node *)malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else  
   {  
    printf("\nEnter Item value");  
    scanf("%d",&item);  
    ptr->data=item;  
   if(head==NULL)  
   {  
      head = ptr;  
      ptr -> next = head;   
      ptr -> prev = head;   
   }  
   else   
   {  
       temp = head;   
    while(temp -> next != head)  
    {  
        temp = temp -> next;   
    }  
    temp -> next = ptr;  
    ptr -> prev = temp;  
    head -> prev = ptr;  
    ptr -> next = head;  
    head = ptr;  
   }  
   printf("\nNode inserted\n");  
}  
     
}  
void display()  
{  
    struct node *ptr;  
    ptr=head;  
    if(head == NULL)  
    {  
        printf("\nnothing to print");  
    }     
    else  
    {  
        printf("\n printing values ... \n");  
          
        while(ptr -> next != head)  
        {  
          
            printf("%d\n", ptr -> data);  
            ptr = ptr -> next;  
        }  
        printf("%d\n", ptr -> data);  
    }  
              
}  
  
