#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display(struct node *head)
{
    while (head != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
}

void search(struct node *head)
{
    int val, count = 1;
    printf("enter value you want to search : ");
    scanf("%d", &val);
    while (head != NULL)
    {
        if (head->data == val)
        {
            printf("value exists at position no. %d", count);
            break;
        }
        else if (head->next == NULL)
        {
            printf("value not exists.");
        }
        else
        {
            count++;
        }
        head = head->next;
    }
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
    printf("kai value pachhi insert krvu 6e e value : ");
    scanf("%d", &val1);
    while (dummy->data != val1)
    {
        dummy = dummy->next;
    }
    printf("kai value insert krvi 6e e : ");
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

    printf("kai value update krvi 6e e : ");
    scanf("%d", &upd);

    while (dummy->data != upd)
    {
        dummy = dummy->next;
    }

    printf("navi value : ");
    scanf("%d", &newupd);

    dummy->data = newupd;

    return dummy;
}

void deleteExceptLast(struct node *head)
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

int main()
{
    struct node *head = malloc(sizeof(struct node));
    struct node *second = malloc(sizeof(struct node));
    struct node *third = malloc(sizeof(struct node));
    struct node *temp;

    head->data = 13;
    head->next = second;

    second->data = 27;
    second->next = third;

    third->data = 73;
    third->next = NULL;

    display(head);

    // search(head);

    // insertLast(head);
    // display(head);

    // insertBetween(head);
    // display(head);

    // head = insertBegin(head);
    // display(head);

    // head = update(head);
    // display(head);

    // deleteExceptLast(head);
    // display(head);

    // head = deleteFirst(head);
    // display(head);

    return 0;
}