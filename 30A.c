//Implement dynamic implementation of circular queue of integers with following operation:
// - Initialize(),insert(), delete(), isempty(), isfull(), display()
#include<stdio.h>
#include "30A.h"
int main()
{
    queue* Q;
    int x, choice;

    Q = init(Q);
    do
    {
        printf("\n\n1: Insert");
        printf("\n2: Delete");
        printf("\n3: Display");
        printf("\n4: Quit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
            {
                case 1: printf("Enter element to be inserted: ");
                        scanf("%d", &x);
                        Q = add(Q, x);
                        break;

                case 2: Q = delet(Q);
                        break;

                case 3: display(Q);
                        break;
            }
    }while(choice != 4);

    return 0;
}
