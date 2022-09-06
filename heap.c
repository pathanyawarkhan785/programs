#include <stdio.h>
#include <stdlib.h>

void main()
{
    int option;

    printf("enter value : ");
    scanf("%d", &option);

    do
    {
        printf("1.\n");
        printf("2.\n");
        printf("3.\n");
        printf("4.\n");
        printf("5.\n");
        printf("enter operation you want to perform : ");
        scanf("%d", &option);
    } while (option >= 1 && option <= 9);
}
