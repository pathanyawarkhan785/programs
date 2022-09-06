#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *insert(int val)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *preOrder(struct node *root)
{
    struct node *dummy = root;
    if (dummy != NULL)
    {
        printf("%d ", dummy->data);
        preOrder(dummy->left);
        preOrder(dummy->right);
    }
    return dummy;
}

struct node *inOrder(struct node *root)
{
    struct node *dummy = root;
    if (dummy != NULL)
    {
        inOrder(dummy->left);
        printf("%d ", dummy->data);
        inOrder(dummy->right);
    }
    return dummy;
}

struct node *postOrder(struct node *root)
{
    struct node *dummy = root;
    if (dummy != NULL)
    {
        postOrder(dummy->left);
        postOrder(dummy->right);
        printf("%d ", dummy->data);
    }
    return dummy;
}

struct node *insertNode(struct node *root, int val)
{
    struct node *dummy = root;
    while (1)
    {
        if (dummy->data > val)
        {
            if (dummy->left == NULL)
            {
                struct node *temp = malloc(sizeof(struct node));
                dummy->left = temp;
                temp->data = val;
                temp->left = NULL;
                temp->right = NULL;
                break;
            }
            dummy = dummy->left;
        }
        else
        {
            if (dummy->right == NULL)
            {
                struct node *temp = malloc(sizeof(struct node));
                dummy->right = temp;
                temp->data = val;
                temp->left = NULL;
                temp->right = NULL;
                break;
            }
            dummy = dummy->right;
        }
    }
}

struct node *isExist(struct node *root, int val)
{
    struct node *dummy = root;
    while (dummy != NULL)
    {
        if (dummy->data == val)
        {
            return dummy;
        }
        else if (dummy->data < val)
        {
            dummy = dummy->right;
        }
        else
        {
            dummy = dummy->left;
        }
    }
    return NULL;
}

struct node *updateNode(struct node *root, int val, int newVal)
{
    struct node *dummy = root;

    while (dummy != NULL)
    {
        if (dummy->data == val)
        {

            dummy->data = newVal;
            break;
        }
        else if (dummy->data < val)
        {
            dummy = dummy->right;
        }
        else
        {
            dummy = dummy->left;
        }
    }
    return NULL;
}

struct node *deleteLeafNode(struct node *root, int val)
{
    struct node *dummy = root;
    while (dummy != NULL)
    {
        if (dummy->data = val)
        {
            free(dummy);
            break;
        }
        else if (dummy->data < val)
        {
            dummy = dummy->right;
        }
        else
        {
            dummy = dummy->left;
        }
    }
    return NULL;
}

void main()
{
    int val, newVal;
    struct node *root = insert(27);
    struct node *val1 = insert(13);
    struct node *val2 = insert(73);
    struct node *val3 = insert(10);
    struct node *val4 = insert(20);
    struct node *val5 = insert(50);
    struct node *val6 = insert(100);

    root->left = val1;
    root->right = val2;
    val1->left = val3;
    val1->right = val4;
    val2->left = val5;
    val2->right = val6;

    int option;

    do
    {
        printf("\n1. Sorted Array\n");
        printf("2. Value exist or not\n");
        printf("3. Insert\n");
        printf("4. Update\n");
        printf("5. Delete\n");
        printf("enter operation you want to perform : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            inOrder(root);
            // preOrder(root);
            // postOrder(root);
            break;

        case 2:
            printf("enter value you want to search : ");
            scanf("%d", &val);
            struct node *temp2 = isExist(root, val);
            if (temp2 == NULL)
            {
                printf("element not found.");
                break;
            }
            else
            {
                printf("element found : %d", temp2->data);
                break;
            }
        case 3:
            printf("enter value you want to insert : ");
            scanf("%d", &val);

            insertNode(root, val);
            struct node *temp = isExist(root, val);
            if (temp == NULL)
            {
                printf("element not found.");
                break;
            }
            else
            {
                printf("element found : %d", temp->data);
                break;
            }
        case 4:
            printf("enter value you want to update : ");
            scanf("%d", &val);
            printf("enter new value : ");
            scanf("%d", &newVal);
            struct node *temp3 = isExist(root, newVal);
            updateNode(root, val, newVal);
            if (temp3 == NULL)
            {
                printf("element not found.");
                break;
            }
            else
            {
                printf("element found : %d", temp3->data);
                break;
            }
        case 5:
            printf("enter value you want to delete : ");
            scanf("%d", &val);
            deleteLeafNode(root, val);

            struct node *temp4 = isExist(root, val);
            if (temp4 == NULL)
            {
                printf("element not found.");
            }
            else
            {
                printf("element found : %d", temp4->data);
            }
        }
    } while (option >= 1 && option <= 9);
}