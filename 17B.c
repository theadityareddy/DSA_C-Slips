#include<stdio.h>
#include<string.h>
typedef struct city
{
    int id;
    char name[20];
}city;
void read(city[], int);
int search(city[], int, char[]);

int main()
{
    city c[10];
    int n, loc;
    char cname[20];

    printf("Enter the no of cities: ");
    scanf("%d", &n);

    read(c, n);
    printf("Enter the name you want to search: ");
    scanf("%s", cname);

    loc = search(c, n, cname);
    if(loc == -1)
        printf("\n%s not found", cname);
    else
        {
            printf("\n%s found", cname);
            printf("\nCity id = %d", c[loc].id);
            printf("\nCity name = %s", c[loc].name);
        }

    return 0;
}

void read(city c[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        {
            printf("\nEnter id: ");
            scanf("%d", &c[i].id);

            printf("\nEnter name: ");
            scanf("%s", c[i].name);
        }
}
int search(city c[], int n, char cname[])
{
    int i, loc = -1, cnt = 0;

    for(i = 0; i < n; i++)
        {
            cnt++;
            if(strcmp(c[i].name, cname) == 0)
                {
                    loc = i;
                    break;
                }
        }
    printf("Total no of comparisons = %d", cnt);
    return loc;
}
