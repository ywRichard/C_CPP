#include <stdlib.h>
#include <stdio.h>
#include "12_sll_node.h"

int sll_insert1(Node **rootp, int new_value)
{
    Node *current;
    Node *previous;
    Node *new;

    //point to list root
    current = *rootp;
    previous = NULL;

    while (current != NULL && current->value < new_value)
    {
        previous = current;
        current = current->link;
    }

    //malloc memory for new Node
    new = (Node *)malloc(sizeof(Node));
    if (new = NULL)
        return FALSE;
    new->value = new_value;
    new->link = current;

    if (previous == NULL)
        *rootp = new;
    else
        previous->link = new;

    return TRUE;
}

int sll_insert2(register Node **linkp, int new_value)
{
    register Node *current;
    register Node *new;

    while ((current = *linkp) != NULL && current->value < new_value)
    {
        linkp = &current->link;
    }

    //malloc memory for new Node
    new = (Node *)malloc(sizeof(Node));
    if (new = NULL)
        return FALSE;
    new->value = new_value;
    new->link = current;

    return TRUE;
}
