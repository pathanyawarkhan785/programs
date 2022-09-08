#include <stdio.h>
#include <stdlib.h>

int val;
struct node
{
    int teleNum;
    char name[20];
    struct node *next;
};

void display(struct node *head)
{
    struct node *dummy = head;
    if (dummy == NULL)
    {
        printf("linkedlist is empty.");
        return;
    }
    while (dummy != NULL)
    {
        printf("(Name : %s , Telephone : %d)", dummy->name, dummy->teleNum);
        if (dummy->next != NULL)
        {
            printf("->");
        }
        dummy = dummy->next;
    }
}

struct node *insertBegin(struct node *head)
{
    int teleNum;
    char name[20];
    struct node *dummy = head;
    struct node *first = malloc(sizeof(struct node));

    printf("Enter name : ");
    scanf("%s", first->name);

    printf("Enter telephone : ");
    scanf("%d", &first->teleNum);

    first->next = dummy;

    return first;
}

void insertBetween(struct node *head)
{
    int val1, val2, val3;
    struct node *dummy = head;
    printf("After which telephone number you want to insert : ");
    scanf("%d", &val1);
    while (dummy->teleNum != val1)
    {
        dummy = dummy->next;
    }
    struct node *between = malloc(sizeof(struct node));

    printf("Telephone : ");
    scanf("%d", &between->teleNum);

    printf("Name : ");
    scanf("%s", between->name);

    between->next = dummy->next;
    dummy->next = between;
    // printf("Telephone number = %d and Name = %s inserted.\n", between->teleNum, between->name);
}

void insertLast(struct node *head)
{
    struct node *dummy = head;
    while (dummy->next != NULL)
    {
        dummy = dummy->next;
    }
    struct node *last = malloc(sizeof(struct node));
    printf("Telephone : ");
    scanf("%d", &last->teleNum);
    printf("Name : ");
    scanf("%s", last->name);
    last->next = NULL;
    dummy->next = last;
    printf("%d inserted successfully.\n", last->teleNum);
}

struct node *updateTele(struct node *head)
{
    struct node *dummy = head;
    int upd;

    printf("Which telephone number do you want to update : ");
    scanf("%d", &upd);

    while (dummy->teleNum != upd)
    {
        dummy = dummy->next;
    }

    printf("New telephone number : ");
    scanf("%d", &dummy->teleNum);

    return dummy;
}

// struct node *updateName(struct node *head, char oldName)
// {
//     struct node *dummy = head;
//     char newName[20];

//     while (dummy->name != oldName)
//     {
//         printf("%s", dummy->name);
//         dummy = dummy->next;
//     }

//     printf("New Name : ");
//     scanf("%s", &newName);

//     return dummy;
// }

struct node *search(struct node *head, int val)
{
    int count = 1;
    struct node *dummy = head;
    while (dummy != NULL)
    {
        if (dummy->teleNum == val)
        {
            printf("telephone number exists at position no. : %d", count);
            break;
        }
        else if (dummy->next == NULL)
        {
            printf("telephone number not exists.");
        }
        else
        {
            count++;
        }
        dummy = dummy->next;
    }
    return dummy;
}

void deleteExceptFirst(struct node *head)
{
    struct node *dummy, *p;
    int delVal;

    dummy = head;

    printf("enter telephone number you want to delete : ");
    scanf("%d", &delVal);

    while (dummy->next->teleNum != delVal)
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

int main()
{
    struct node *head = malloc(sizeof(struct node));
    struct node *temp;
    head = NULL;
    int option;

    do
    {
        printf("\n1. Display\n");
        printf("2. Insert from begin\n");
        printf("3. Insert from between\n");
        printf("4. Insert from last\n");
        printf("5. Update Telephone\n");
        printf("6. Delete except first\n");
        printf("7. Delete first\n");
        printf("8. Search\n");
        printf("enter operation you want to perform : ");
        scanf("%d", &option);
        switch (option)
        {

        case 1:
            display(head);
            break;

        case 2:

            head = insertBegin(head);
            display(head);
            break;

        case 3:
            insertBetween(head);
            display(head);
            break;

        case 4:
            insertLast(head);
            display(head);
            break;

        case 5:
            head = updateTele(head);
            display(head);
            break;

            // case 6:
            // char oldName[20];
            // printf("enter which name you want to update : ");
            // scanf("%s", &oldName);
            // head = updateName(head, oldName);
            // display(head);
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
            printf("enter telephone number you want to search : ");
            scanf("%d", &val);
            search(head, val);
            break;
        }
    } while (option >= 1);

    return 0;
}