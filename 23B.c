/*Write a 'C' program to create a random array of n integers. Accept a value x from user and use Binary search algorithm to check whether the number is present in array or not.
 (Students can accept sorted array or can use any sorting method to sort the array)*/

#include<stdio.h>
void main()
{
	int arr[20],n,i,j,key,mid,end,beg,temp;
	printf("Enter size of array:");
	scanf("%d",&n);
	printf("Enter elements of array:\n");
	for(i=0;i<n;i++)
	{
		printf("\nElement [%d] : ",i);
		scanf("%d",&arr[i]);
	}
	printf("Sorting array....\n");
	for(i=0;i<(n-1);i++)
	{
		for(j=0;j<(n-i-1);j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("\nSorted array\n");
	for(i=0;i<n;i++)
	{
		printf("\nElement [%d] : %d",i,arr[i]);
	}
	printf("\n\nEnter element to find : \n");
	scanf("%d",&key);
	beg=0;
	end=n-1;
	mid=(beg+end)/2;
	while(beg<=end)
	{
		if(arr[mid]<key)
		{
			beg=mid+1;
		}
		else if(arr[mid]==key)
		{
			printf("\nElement is found at position %d",mid+1);
			break;
		}
		else if(arr[i]!=key)
	    {
		printf("\nElement not found\n");
		break;
	    }
		else
		{
			end=mid+1;
		}
		mid=(beg+end)/2;
	}
	
	
}
