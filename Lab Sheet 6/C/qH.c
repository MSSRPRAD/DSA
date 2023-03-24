#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

struct Node_t
{
    int data;
    struct Node_t *next;
    struct Node_t *prev;
};

typedef struct Node_t Node;

Node *createNode(int val)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = val;
    temp->next = NULL;
    temp->next = NULL;
    return temp;
}

Node *pop(Node *head)
{
    if (head->next == head)
    {
        return NULL;
    }
    head->prev->next = head->next;
    head->next->prev = head->prev;
    Node *temp = head->next;
    free(head);
    return temp;
}

Node *push(Node *head, int val)
{
    Node *temp = createNode(val);
    temp->next = head->next;
    temp->prev = head;
    head->next->prev = temp;
    head->next = temp;
    return head;
}

Node *createQueue(int n)
{
    Node *head = createNode(1);
    head->next = head;
    head->prev = head;
    Node *temp = head;
    for (int i = 2; i <= n; i++)
    {
        push(temp, i);
        temp = temp->next;
    }
    return head;
}

int main(void)
{
    int n, k;
    scanf("%d %d", &n, &k);
    Node *head = createQueue(n);
    for (int i = 1; i < n; i++)
    {
        for (int i = 1; i < k; i++)
        {
            head = head->next;
        }
        head = pop(head);
    }
    printf("%d ", head->data);

    return 0;
}