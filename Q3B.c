#include<stdio.h>
#include<stdlib.h>
struct n
{
int data;
struct n *link;
};
typedef struct n NODE;
NODE *getnode(int);
NODE *findlast(NODE *);
void display(NODE *[],int);
void main()
{
NODE *ptr,*temp,*h[10];
int n,a[10][10],i,j;
printf("\n Enter total number of vertices :");
scanf("%d",&n);
printf("\n Enter entries of an adjacency matrix :\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf("\n Enter a[%d][%d] : ",i+1,j+1);
scanf("%d",&a[i][j]);
}
}
printf("\n Entered Adjacency matrix is … \n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf("\t %d ",a[i][j]);
}
printf("\n");
}
for(i=0;i<n;i++)
h[i]=NULL;
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(a[i][j]==1)
{
temp=getnode(j+1);
if(h[i]==NULL)
h[i]=temp;
else
{
ptr=findlast(h[i]);
ptr->link=temp;
}
}
}
}
printf("\n The Adjacency list looks like … \n");
display(h,n);
}
NODE *getnode(int j)
{
NODE * temp;
temp=(NODE *)malloc(sizeof(NODE));
temp->data=j;
temp->link=NULL;
return(temp);
}
NODE *findlast(NODE *h)
{
NODE *ptr;
for(ptr=h;ptr->link!=NULL;ptr=ptr->link);
return(ptr);
}
void display(NODE *h[10],int n)
{
NODE *ptr;
int i;
for(i=0;i<n;i++)
{
printf("\n V%d ",i+1);
ptr=h[i];
if(ptr==NULL)
printf("NULL");
while(ptr!=NULL)
{
printf(" ->V%d",ptr->data);
ptr=ptr->link;
}
printf("\n");
}
}
