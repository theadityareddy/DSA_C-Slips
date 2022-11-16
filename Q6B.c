#include<stdio.h>
int main()
{
	int arr[10],n,i,j,temp;
	printf("enter size of array:\n");
	scanf("%d",&n);
	printf("enter elements in array:\n");
	for(i=0;i<n;i++)
	{
		arr[i]=0;
		scanf("%d",&arr[i]);
	}
	printf("sorting with bubble sort");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("sorted array \n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",arr[i]);
	}
}
