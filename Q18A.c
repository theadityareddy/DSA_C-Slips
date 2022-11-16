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
  
