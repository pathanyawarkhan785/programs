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

void main()
{
    struct node *root = insert(27);
    struct node *val1 = insert(13);
    struct node *val2 = insert(73);

    root->left = val1;
    root->right = val2;
}