/*Write a 'C' program Accept n elements from user store it in an array. Accept a value from the user 
and use linear/Sequential search method to check whether the value is present in array or not. Display proper message.*/
#include<stdio.h>
void main()
{
	int arr[20],n,i,key;
	printf("Enter size of array:");
	scanf("%d",&n);
	printf("Enter elements of array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter element to be found");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
		if(key==arr[i])
		{
			printf("Element %d is found at position %d",key,i+1);
			break;
	   }
   }
}
