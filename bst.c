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

    printf("enter value you want to insert : ");
    scanf("%d", &temp->data);

    // temp->data = val;
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
        printf("%d -> ", dummy->data);
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

    if (dummy->left == NULL && dummy->right == NULL && dummy->data == '\0')
    {
        dummy->data = val;
        dummy->left = NULL;
        dummy->right = NULL;
        return dummy;
    }

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

struct node *search(struct node *root, int val)
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
            printf("value updated successully.");
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
    if (dummy == NULL)
        return dummy;

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
    struct node *root;
    root->left = root->right = NULL;

    int option;

    do
    {
        printf("\n1. Insert\n");
        printf("2. preorder\n");
        printf("3. inorder\n");
        printf("4. postorder\n");
        printf("5. Search\n");
        printf("6. Update\n");
        printf("7. Delete\n");
        printf("8. Exit\n");
        printf("enter operation you want to perform : ");
        scanf("%d", &option);
        if (option == 8)
        {
            break;
        }
        switch (option)

        {

        case 1:

            printf("enter value you want to insert : ");
            scanf("%d", &val);

            insertNode(root, val);
            struct node *temp = search(root, val);
            if (temp == NULL)
            {
                printf("element %d not found.", val);
                break;
            }
            else
            {
                printf("element found : %d", temp->data);
                break;
            }

        case 2:
            preOrder(root);
            break;

        case 3:

            inOrder(root);
            break;

        case 4:
            postOrder(root);
            break;

        case 5:

            printf("enter value you want to search : ");
            scanf("%d", &val);
            struct node *temp2 = search(root, val);
            if (temp2 == NULL)
            {
                printf("element %d not found.", val);
                break;
            }
            else
            {
                printf("element found : %d", temp2->data);
                break;
            }

        case 6:

            printf("enter value you want to update : ");
            scanf("%d", &val);
            printf("enter new value : ");
            scanf("%d", &newVal);
            struct node *temp3 = search(root, newVal);
            updateNode(root, val, newVal);
            break;

        case 7:

            printf("enter value you want to delete : ");
            scanf("%d", &val);
            deleteLeafNode(root, val);
        }
    } while (option >= 1);
}