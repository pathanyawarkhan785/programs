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

void main()
{
    int val;
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

    // preOrder(root);
    // postOrder(root);
    // inOrder(root);

    // insertNode(root);

    // printf("enter value you want to search : ");
    // scanf("%d", &val);
    // struct node *temp = isExist(root, val);
    // if (temp == NULL)
    // {
    //     printf("element not found.");
    // }
    // else
    // {
    //     printf("element found : %d", temp);
    // }

    // printf("enter value you want to insert : ");
    // scanf("%d", &val);

    // insertNode(root, val);
    // struct node *temp = isExist(root, val);
    // if (temp == NULL)
    // {
    //     printf("element not found.");
    // }
    // else
    // {
    //     printf("element found : %d", temp->data);
    // }
}