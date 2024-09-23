#include <stdio.h>
#include <stdlib.h>

typedef struct    Node {
    int    data;
    struct    Node    *next;
}    Node;

Node    *create(int n)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = n;
    new_node->next = NULL;
    return (new_node);
}

void    delete(int n, Node *new_node)
{
    Node *copy;
    Node *temp;
    copy = new_node;
    while (copy && copy->next)
    {
        if(copy->next->data == n)
        {
            temp = copy->next;
            copy->next = copy->next->next;
            free(temp);
        }
        copy = copy->next;
    }
}

int    main(void)
{
    Node *new_node;// *new_node2;

    new_node = create(10);
    new_node->next = create(20);
    new_node->next->next = create(30);
    new_node->next->next->next = create(40);
    new_node->next->next->next->next = create(60);
    //new_node2 = new_node;
    delete(30, new_node);
    while (new_node)
    {
        printf("A.%d\n", new_node->data);
        new_node = new_node->next;
    }
    //new_node = new_node2;
    //printf("FIM = %d\n\n", new_node->data);
    return (0);
}
