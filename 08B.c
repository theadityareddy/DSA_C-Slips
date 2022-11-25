/*Write a 'C' program to accept and sort n elements in ascending order by using insertion sort.*/

#include<stdio.h> 
void main()
{
int arr[20],i,j,temp,n;
printf("Enter size of array:"); 
scanf("%d",&n); 
printf("Enter elements of array:");
for(i=0;i<n;i++)
{
	scanf("%d",&arr[i]);
}

for (i=1;i<n;i++)
{
	temp=arr[i];
	j=i-1;
	while(j>=0&&arr[j]>temp)
	{
		arr[j+1]=arr[j];
		j=j-1;
	}
	arr[j+1]=temp;
}
printf("Sorted array:\n");

for(i=0;i<n;i++)
{
	printf("%d\n",arr[i]);
}
}
