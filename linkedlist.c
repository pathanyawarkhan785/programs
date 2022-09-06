#include <stdio.h>
#include <stdlib.h>

int val;
struct node
{
    int data;
    struct node *next;
};

void display(struct node *head)
{
    if (head == NULL)
    {
        printf("----Linkedlist is empty----");
    }
    while (head != NULL)
    {
        printf(" %d ", head->data);
        if (head->next != NULL)
        {
            printf("->");
        }
        head = head->next;
    }
}

struct node *search(struct node *head, int val)
{
    int count = 1;
    struct node *dummy = head;
    while (dummy != NULL)
    {
        if (dummy->data == val)
        {
            printf("value exists at position no. : %d", count);
            break;
        }
        else if (dummy->next == NULL)
        {
            printf("value not exists.");
        }
        else
        {
            count++;
        }
        dummy = dummy->next;
    }
    return dummy;
}

void insertLast(struct node *head)
{
    int val;
    struct node *dummy;
    dummy = head;
    printf("enter value you want to insert from last : ");
    scanf("%d", &val);
    while (dummy->next != NULL)
    {
        dummy = dummy->next;
    }
    struct node *last = malloc(sizeof(struct node));
    last->data = val;
    last->next = NULL;
    dummy->next = last;
    printf("%d inserted successfully.\n", last->data);
}

void insertBetween(struct node *head)
{
    int val1, val2;
    struct node *dummy = head;
    printf("After which value you want to insert : ");
    scanf("%d", &val1);
    while (dummy->data != val1)
    {
        dummy = dummy->next;
    }
    printf("The value you would like to insert : ");
    scanf("%d", &val2);

    struct node *between = malloc(sizeof(struct node));

    between->data = val2;
    between->next = dummy->next;
    dummy->next = between;
    printf("%d inserted after %d.\n", val2, val1);
}

struct node *insertBegin(struct node *head)
{
    int val;
    struct node *dummy = head;
    struct node *first = malloc(sizeof(struct node));

    printf("enter val : ");
    scanf("%d", &val);

    first->next = dummy;
    first->data = val;

    return first;
}

struct node *update(struct node *head)
{
    struct node *dummy;
    int upd, newupd;
    dummy = head;

    printf("Which value do you want to update : ");
    scanf("%d", &upd);

    printf("The value you would like to update : ");
    scanf("%d", &newupd);

    dummy->next->data = newupd;

    return dummy;
}

void deleteExceptFirst(struct node *head)
{
    struct node *dummy, *p;
    int delVal;

    dummy = head;

    printf("enter value to delete : ");
    scanf("%d", &delVal);

    while (dummy->next->data != delVal)
    {
        dummy = dummy->next;
    }

    p = dummy->next;
    dummy->next = dummy->next->next;

    free(p);
}

struct node *deleteFirst(struct node *head)
{
    struct node *p;
    p = head;
    head = head->next;
    free(p);
    return head;
}

struct node *insert(struct node *head)
{
    // printf("inside next %d\n", head->data);
    if (head->data == '\0')
    {
        printf("Insert value you want : ");
        scanf("%d", &val);
        head->data = val;
        head->next = NULL;
        printf("Inserted value : %d", head->data);
        return head;
    }
}

int main()
{
    struct node *head = malloc(sizeof(struct node));
    struct node *temp;
    head->data = '\0';
    head->next = NULL;
    int option;

    do
    {
        printf("\n1. Display\n");
        printf("2. Insert from last\n");
        printf("3. Insert in between\n");
        printf("4. Insert in begin\n");
        printf("5. Update\n");
        printf("6. Delete except first\n");
        printf("7. Delete first\n");
        printf("8. Search\n");
        printf("9. Insert linkedlist emptye\n");
        printf("enter operation you want to perform : ");
        scanf("%d", &option);
        switch (option)
        {

        case 1:
            display(temp);
            break;

        case 2:
            insertLast(head);
            display(head);
            break;

        case 3:
            insertBetween(head);
            display(head);
            break;

        case 4:
            head = insertBegin(head);
            // display(head);
            break;

        case 5:
            head = update(head);
            display(head);
            break;

        case 6:
            deleteExceptFirst(head);
            display(head);
            break;

        case 7:
            head = deleteFirst(head);
            display(head);
            break;

        case 8:
            printf("enter value you want to search : ");
            scanf("%d", &val);
            search(head, val);
            break;

        case 9:
            // ***insert***

            temp = insert(head);
            break;
        }
    } while (option >= 1 && option <= 9);

    return 0;
}