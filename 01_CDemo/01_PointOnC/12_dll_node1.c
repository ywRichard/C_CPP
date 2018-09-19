#include <stdlib.h>
#include <stdio.h>
#include "12_dll_node.h"

int dll_insert(register Node *rootp, int value)
{
    register Node *this;
    register Node *next;
    register Node *newnode;

    for (this = rootp; (next = this->fwd) != NULL; this = next)
    {
        if (next->value == value)
            return 0;

        if (next->value > value)
            break;
    }

    newnode = (Node *)malloc(sizeof(Node));
    if (newnode == NULL)
        return -1;
    newnode->value = value;

    newnode->fwd=next;
    this->fwd=newnode;

    if(this !=rootp)
        newnode->bwd=this;
    else
        newnode->bwd=NULL;

    if(next!=NULL)
        next->bwd=newnode;
    else
        rootp->bwd=newnode;

    return 1;
}