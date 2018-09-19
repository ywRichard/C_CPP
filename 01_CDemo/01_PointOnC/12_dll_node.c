#include <stdlib.h>
#include <stdio.h>
#include "12_dll_node.h"

int dll_insert(Node *rootp, int value)
{
    Node *this;
    Node *next;
    Node *newnode;

    for (this = rootp; (next = this->fwd) != NULL; this = next)
    {
        //return if the value exits
        if (next->value == value)
            return 0;

        if (next->value > value)
            break;
    }
    newnode = (Node *)malloc(sizeof(Node));
    if (newnode == NULL)
        return -1;
    newnode->value = value;

    //insert newnode into linked list
    if (next != NULL) //1,2 -> not the end of list
    {

        if (this != rootp) //1.not the begin of list
        {
            newnode->fwd = next;
            this->fwd = newnode;
            newnode->bwd = this;
            next->bwd = newnode;
        }
        else //2.begin of list
        {
            newnode->fwd = next;
            rootp->fwd = newnode;
            newnode->bwd = NULL;
            next->bwd = newnode;
        }
    }
    else //3,4 -> append to the end of list
    {
        if (this->bwd != rootp) //append to list end
        {
            newnode->fwd = NULL;
            this->fwd = newnode;
            newnode->bwd = this;
            rootp->bwd = newnode;
        }
        else //insert to a empty list
        {
            newnode->fwd=NULL;
            rootp->fwd=newnode;
            newnode->bwd=NULL;
            rootp->bwd=newnode;
        }
    }
}