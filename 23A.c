/*Write a menu driven program using 'C' for singly linked list-
-	To create linked list.
-	To display linked list
-	To insert node at last position of linked list.
(Above repeated in 11A)
-	To delete node from specific position of linked list.*/

void deletePosition()
{
    struct node *temp, *position;
    int i = 1, pos;
  
    // If LL is empty
    if (start == NULL)
        printf("\nList is empty\n");
  
    // Otherwise
    else {
        printf("\nEnter index : ");
  
        // Position to be deleted
        scanf("%d", &pos);
        position = malloc(sizeof(struct node));
        temp = start;
  
        // Traverse till position
        while (i < pos - 1) {
            temp = temp->link;
            i++;
        }
  
        // Change Links
        position = temp->link;
        temp->link = position->link;
  
        // Free memory
        free(position);
    }
}
  
