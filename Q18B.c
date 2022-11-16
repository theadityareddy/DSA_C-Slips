#include<stdio.h>
void main()
{
	int arr[20],n,i,j,key,mid,end,beg,temp;
	printf("Enter size of array:");
	scanf("%d",&n);
	printf("Enter elements of array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Sorting array\n");
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
	printf("Sorted array");
	for(i=0;i<n;i++)
	{
		printf("%d\n",arr[i]);
	}
	printf("Enter element to be found\n");
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
			printf("Element is found at position %d",mid+1);
			break;
		}
		else
		{
			end=mid+1;
		}
		mid=(beg+end)/2;
	}
	if(beg>mid)
	{
		printf("Element not found");
	}
	
}
