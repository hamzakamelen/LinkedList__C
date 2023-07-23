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
// ---------------------------------------


// 1.Insert At Beginning
struct Node *insertatBeginning(struct Node *head, int data)
{
    struct Node *newAdd = (struct Node *)malloc(sizeof(struct Node));
    newAdd->next = head;
    newAdd->data = data;
    return newAdd;
};
// ---------------------------------------

// 2. Insert At Index
struct Node *InsertAtIndex(struct Node *head, int data, int index)
{
    struct Node *newAdd = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    newAdd->data = data;
    newAdd->next = p->next;
    p->next = newAdd;
    return head;
}
// ---------------------------------------

// 3. Insert At Index
struct Node *InsertAtEnd(struct Node *head, int data)
{
    struct Node *newAdd = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    newAdd->next = head;
    while (p->next!=NULL)
    {
        p = p->next;
    }
    p->next = newAdd;
    newAdd->data = data;
    newAdd->next = NULL;
    return head;
}
// ---------------------------------------

// 4. Insert After Node
struct Node *InsertAfterNode(struct Node *head,struct Node *prevNode, int data)
{
    struct Node *newAdd = (struct Node *)malloc(sizeof(struct Node));
    newAdd->data = data;

    newAdd->next=prevNode->next;
    prevNode->next =newAdd;
    return head;
}
// ---------------------------------------

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
    head->data = 87;
    head->next = second;

    // Linked Second & Third Node
    second->data = 16;
    second->next = third;

    // Linked Third & fourth Node
    third->data = 66;
    third->next = fourth;

    // Terminate fourth Node
    fourth->data = 15;
    fourth->next = NULL;

    // Print All Elements
    TraversalLinkedList(head);
    printf("------------------------------------------");

    // 1. Insert Element at Beginning
    
    head = insertatBeginning(head, 54);
    // Print All Elements After Modification
    TraversalLinkedList(head);
    printf("------------------------------------------");
    
    // 2.Insert at Index
    
    head = InsertAtIndex(head, 54,1);
    TraversalLinkedList(head);
    printf("------------------------------------------");
        
    // 3.Insert at End
    
    head = InsertAtEnd(head,520);
    TraversalLinkedList(head);
    printf("------------------------------------------");
    // 4. Insert After a Node
    
    head = InsertAfterNode(head,second,4000);
    TraversalLinkedList(head);
    printf("------------------------------------------");
    return 0;
}