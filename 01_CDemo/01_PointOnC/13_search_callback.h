typedef struct NODE{
    struct NODE     *link;
    int             value;
} Node;

Node *search_list(Node *node, void const *value,
                  int (*compare)(void const *, void const *));