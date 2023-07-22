#include <stdio.h>
#include <stdlib.h>
// Declaring Node
struct Node
{
    int data;
    struct Node *next;
};

// Linked List Traversal
void TraversalLinkedList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// 1.Insert at Beginning
struct Node *insertatBeginning(struct Node *head, int data){
    struct Node *newAdd = (struct Node *)malloc(sizeof(struct Node));
    newAdd->next = head;
    newAdd->data = data;
    return newAdd;
};

// 2. Insert in Between
int main()
{
    // Initialize Nodes
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for each Node
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Linked First & Second Node
    head->data = 7;
    head->next = second;

    // Linked Second & Third Node
    second->data = 6;
    second->next = third;

    // Linked Third & fourth Node
    third->data = 66;
    third->next = fourth;

    // Terminate fourth Node
    fourth->data = 125;
    fourth->next = NULL;

    // Print All Elements
    TraversalLinkedList(head);
    printf("------------------------------------------");

    // Insert Element at Beginning
    head = insertatBeginning(head, 54);
    // Print All Elements After Modification
    TraversalLinkedList(head);
    printf("------------------------------------------");
    return 0;
}