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

// Case 1: Deleting From Beginning
struct Node *DeleteFromBeginning(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
//-------------------------------------------------

// Case 2: Deleting at index
struct Node *DeletingAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    struct Node *q = p->next;
    p->next = q->next;
    free(q);
    return head;
}
//-------------------------------------------------

// Case 3: Deleting At End
struct Node *DeletingAtEnd(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    free(q);
    p->next = NULL;
    return head;
}
//-------------------------------------------------

// Case 4: Deleting At Given Value
struct Node *DeletingAtGivenValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data != value)
    {
        p = p->next;
        q = q->next;
    }
    if(q->data == value){
    p->next = q->next;
    free(q);
    }else{
        printf("Given Value Not Found");
    }
    return head;
}
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
    head->data = 70;
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
    TraversalLinkedList(head);
    printf("---------------------------");
    // 1. Delete From Beginning

    //  head =  DeleteFromBeginning(head);
    //   TraversalLinkedList(head);
    printf("---------------------------");
    // 2. Deleting At Index

    // head = DeletingAtIndex(head, 2);
    // TraversalLinkedList(head);
    printf("---------------------------");
    // 3. Deleting At End

    // head = DeletingAtEnd(head);
    // TraversalLinkedList(head);
    printf("---------------------------");
    // 4. Deleting At Given Value

    head = DeletingAtGivenValue(head,125);
    TraversalLinkedList(head);
    return 0;
}
