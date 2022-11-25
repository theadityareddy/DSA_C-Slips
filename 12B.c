/*Write a 'C' program to accept and sort n elements in ascending order using Selection sort method*/
#include<stdio.h> 
void main()
{
int arr[20],i,j,temp,min,n;
printf("Enter size of array:"); 
scanf("%d",&n); 
printf("Enter elements of array:\n");
for(i=0;i<n;i++)
{
	scanf("%d",&arr[i]);
}

for (i=0;i<n;i++)
{
	min=i;
	for(j=i+1;j<n;j++)
	{
		if(arr[min]>arr[j])
		{
			min=j;
		}
	}
	if(min!=i)
	{
		temp=arr[i];
		arr[i]=arr[min];
		arr[min]=temp;
	}
}
printf("Sorted array:\n");

for(i=0;i<n;i++)
{
	printf("%d\n",arr[i]);
}
}
