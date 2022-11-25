/*Write a 'C' program to count all non-zero elements, odd numbers and even numbers in the singly linked list.*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
int info;
struct node *link;
}
NODE;
NODE * get_node()
{
NODE *p;
p = (NODE*)malloc(sizeof(NODE));
printf("Enter info:");
scanf("%d",&p->info);
p->link = NULL;
return p;
}
NODE * create_sll()
{
NODE *first=NULL,*last,*t;
int i,n;
printf("Enter no.of nodes:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
t = get_node();
if(first==NULL)
first = t;
else
last->link = t;
last = t;
}
return first;
}
void display(NODE *h)
{
int nz=0,odd=0,even=0;
while(h!=NULL)
{
if(h->info!=0) nz++;
if(h->info%2==0) even++;
if(h->info%2==1) odd++;
h=h->link;
}
printf("No.of non zeroes = %d\n",nz);
printf("No.of evens = %d\n",even);
printf("No.of odds = %d\n",odd);
}
void main()
{
NODE *start;
start = create_sll();
display(start);

}
