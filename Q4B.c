#include<stdio.h>
#include<conio.h>
void main()
{ 
int a[10],b[10],c[10],i,m;

printf("Enter the highest order of two polynomials : ");
scanf("%d",&m);
printf("Enter first polynomial coefficients :\n");
for(i=m;i>=0;i--)
{
printf("\nEnter the Co-efficient x^%d : ",i);
scanf("%d",&a[i]);
}
printf("Enter second polynomial coefficients :\n");
for(i=m;i>=0;i--)
{
printf("\nEnter the Co-efficient x^%d : ",i);
scanf("%d",&b[i]);
}
printf("\nExpression 1: ");
for(i=m;i>=0;i--)
{
	printf("%dx^%d+ ",a[i],i);
}

printf("\n\nExpression 2: ");
for(i=m;i>=0;i--)
{
	printf("%dx^%d+ ",b[i],i);
}
for(i=m;i>=0;i--)
{
	c[i]=a[i]+b[i];
}
printf("\n\nAdded expression: ");
for(i=m;i>=0;i--)
{
	printf("%dx^%d+ ",c[i],i);
}
}

