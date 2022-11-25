/*Write menu driven program using 'C' for Dynamic implementation of Stack. The menu includes following operations:
-	Push
-	Pop
-	Display
-	Exit
Output problem - When display is clicked goes in infinite loop*/
#include<stdio.h>
#include<process.h>
#include<stdlib.h>

struct node
{
	int num;
	struct node *next;
}*top,*new;

void push()
{
	int item;
	new = (struct node *)malloc(sizeof(struct node));
	printf("Enter item to push : ");
	scanf("%d",&item);
	new->num=item;
	if(top==NULL)
	{
		top=new;
	}
	else
	{
		new->next=top;
		top=new;
	}
}
void pop()
{
	int item;
	struct node *temp;
	if(top==NULL)
	{
		printf("Underflow");
	}
	else
	{
		item=top->num;
		temp=top;
		top=top->next;
		free(temp);
		printf("Item popped");
	}
}
void display()
{
	struct node *temp = top;
	if(top==NULL)
	{
		printf("Stack is empty");
	}
	else
	{
		while(temp->next!=NULL)
		{
			printf("%d--->",temp->num);
			temp=temp->next;
		}
	}
	printf("%d--->NULL",temp->num);
}
void main()
{
	int ch;
	while (1)
	{
		printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;	
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				 printf("Invalid choice");		
		}
		
	}
}
