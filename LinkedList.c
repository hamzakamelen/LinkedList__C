#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
// Traverse
void TraverseLinkedList(struct Node *variable)
{
    while (variable != NULL)
    {
        printf("Element is: %d \n", variable->data);
        variable = variable->next;
    }
}
// Insertion
//  Case 1:
//  Insert At Beginning
struct Node *insertatBeginning(struct Node *head, int USERdata)
{
    struct Node *newElement;
    newElement = (struct Node *)malloc(sizeof(struct Node));

    newElement->next = head;
    newElement->data = USERdata;
    return newElement;
}
// Case 2:
// Insert After Node
struct Node *InsertAfter(struct Node *head, struct Node *prevNode, int USERdata)
{
    struct Node *newElement;
    newElement = (struct Node *)malloc(sizeof(struct Node));
    newElement->data = USERdata;

    newElement->next = prevNode->next;
    prevNode->next = newElement;
    return head;
}
// Case 3:
// Insert at Index
struct Node *InsertAtindex(struct Node *head, int index, int USERdata)
{
    struct Node *newElement;
    newElement = (struct Node *)malloc(sizeof(struct Node));
    newElement->data = USERdata;
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    newElement->next = p->next;
    p->next = newElement;
    return head;
}
// Case 4:
// Insert at End
struct Node *InsertAtEnd(struct Node *head, int USERdata)
{
    struct Node *newElement;
    newElement = (struct Node *)malloc(sizeof(struct Node));
    newElement->data = USERdata;
    struct Node *p = head;
    newElement->next = NULL;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = newElement;
    newElement->data = USERdata;

    return head;
}
//------------------------------------------------
// Deletion
// Case 1:
// Delete From beginning
struct Node *deletefromBeginning(struct Node *head)
{
    struct Node *delete = head;
    head = head->next;
    free(delete);
    return head;
}
// Case 2:
// Delete At Index
struct Node *DeleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    struct Node *delete = p->next;
    p->next = delete->next;
    free(delete);
    return head;
}
// Case 3:
// Delete At End
struct Node *deleteAtEnd(struct Node *head)
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
// Case 4:
// Delete At Given value
struct Node *deletefromGivenValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->data !=value){
        p= p->next;
        q= q->next;
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
    // Creating Nodes
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;

    // Memory Allocate
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));
    // Data Store
    // -> (For targeting Structure Elements)
    //-----------------------------------------

    // Linked List 1:
    head->data = 228000;
    head->next = second;

    // Linked List 2:
    second->data = 2000;
    second->next = third;

    // Linked List 3
    third->data = 20;
    third->next = fourth;

    // Linked List 4
    fourth->data = 1;
    fourth->next = fifth;

    fifth->data = 53641;
    fifth->next = NULL;
    printf("Before\n");
    TraverseLinkedList(head);
    // ----------------Insert-----------------------
    printf("After Insert at Beginning\n");
        head = insertatBeginning(head,52);
        TraverseLinkedList(head);

    printf("After Insert After nODE\n");
    head=InsertAfter(head,second,59);
    TraverseLinkedList(head);

    printf("After Insert At Index\n");
    head=InsertAtindex(head,2,509);
    TraverseLinkedList(head);

    printf("After Insert At End\n");
    head=InsertAtEnd(head,80);
    TraverseLinkedList(head);

    // ------------------ Delete-*-------------------------
    printf("After Delete from Beginning \n");
    head=deletefromBeginning(head);
    TraverseLinkedList(head);

    printf("After Delete from Index \n");
    head=DeleteAtIndex(head,2);
    TraverseLinkedList(head);

    printf("After Delete from End \n");
    head=deleteAtEnd(head);
    TraverseLinkedList(head);

    printf("After Delete from Given Value \n");
    head = deletefromGivenValue(head,1);
    TraverseLinkedList(head);
    return 0;
}