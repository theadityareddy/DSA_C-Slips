#include<stdio.h>
#include<stdlib.h>

struct node
{
        struct node *lchild;
        int info;
        struct node *rchild;
};

struct node *insert(struct node *ptr, int ikey);

void display(struct node *ptr,int level);

int main( )
{
        struct node *root=NULL,*ptr;
        int choice,k;

        while(1)
        {
                printf("\n");
                printf("1.Insert\n");
                printf("2.Display\n");
                printf("3.Quit\n");
                printf("\nEnter your choice : ");
                scanf("%d",&choice);

                switch(choice)
                {
                case 1:
                        printf("\nEnter the key to be inserted : ");
                        scanf("%d",&k);
                        root = insert(root, k);
                        break;

        case 2:
            printf("\n");
            display(root,0);
            printf("\n");
            break;
			case 3:
            exit(1);
			default:
            printf("\nWrong choice\n");
                }/*End of switch */
        }/*End of while */

        return 0;

}/*End of main( )*/


struct node *insert(struct node *ptr, int ikey )
{
        if(ptr==NULL)
        {
                ptr = (struct node *) malloc(sizeof(struct node));
                ptr->info = ikey;
                ptr->lchild = NULL;
                ptr->rchild = NULL;
        }
        else if(ikey < ptr->info) /*Insertion in left subtree*/
                ptr->lchild = insert(ptr->lchild, ikey);
        else if(ikey > ptr->info) /*Insertion in right subtree */
                ptr->rchild = insert(ptr->rchild, ikey);
        else
                printf("\nDuplicate key\n");
        return ptr;
}/*End of insert( )*/

void display(struct node *ptr,int level)
{
        int i;
        if(ptr == NULL )/*Base Case*/
                return;
        else
    {
                display(ptr->rchild, level+1);
                printf("\n");
                for (i=0; i<level; i++)
                        printf("    ");
                printf("%d", ptr->info);
                display(ptr->lchild, level+1);
        }
}
