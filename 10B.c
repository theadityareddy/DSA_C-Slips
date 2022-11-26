// Write a ‘C’ program to sort randomly generated array elements using Insertion sort method. (Use Random Function)
#include<stdio.h>
#include<stdlib.h>
void readArray(int[], int);
void printArray(int[], int);
void insertionSort(int[], int);

int main()
{
    int a[50], n;

    printf("Enter how many numbers: ");
    scanf("%d", &n);

    readArray(a, n);
    printf("\nBefore sorting\n");
    printArray(a, n);

    insertionSort(a, n);
    printf("\nAfter sorting\n");
    printArray(a, n);
    
    return 0;
}

void readArray(int a[], int n)
{
    int i;

    for(i = 0; i < n; i++)
        {
            a[i] = rand()%100;
        }
}
void printArray(int a[], int n)
{
    int i;

    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
}
void insertionSort(int a[], int n)
{
    int i, j, cmpcnt = 0, t;

    for(i = 1; i < n; i++)
        {
            t = a[i];
            for(j = i-1; j >= 0; j--)
                {
                    if(a[j] > t)
                        a[j+1] = a[j];
                    else
                        break;
                }
            a[j+1] = t;
        }
}