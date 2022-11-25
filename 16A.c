/*Write a 'C' program which accept the string and reverse each word of the string using Static implementation of stack.
Example: Input - This is an input string
   Output - sihTsinatupnignirts
   
   Output problem - When srting is entered goes in infinite loop*/

#include<stdio.h>
#include<conio.h>
#define MAX 50
char a[MAX];
int top=-1;
void push(char c)
{
top++;
a[top]=c;
}
char pop()
{
char c;
c=a[top];
top--;
return c;
}
void main()
{
int i;
printf("\n\nENTER THE STRING");
gets(a);
for(i=0;a[i]!=" ' "; i++)
{
if(a[i]==' ')
{
while(top!=-1)
{
printf("%c",pop());
}
printf(" ");
}
else
{
if(top==MAX-1)
{
printf("\n\nSTACK IS FULL");
}
else
{
push(a[i]);
}
}
}
while(top!=-1)
{
printf("%c",pop());
}
}
