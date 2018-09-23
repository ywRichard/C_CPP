#include <stdio.h>
#include "13_search_callback.h"

Node *search_list(Node *node, void const *value,
                  int (*compare)(void const *, void const *))
{
    while (node != NULL)
    {
        if (compare(&node->value, value) == 0)
        {
            break;
        }
        node = node->link;
    }
    return node;
}

