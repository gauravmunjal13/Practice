#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct node
{
    int data;
    struct node* next;
    struct node* arbitrary;
};

/* Function to push a node */
void push_with_next(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));

    /* put in the data  */
    new_node->data  = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

void push_with_arbitrary(struct node ** head_ref)
{
    struct node *temp = *head_ref;

    temp->arbitrary = temp->next->next;
    temp = temp->next;
    temp->arbitrary = *head_ref;
    temp = temp->next;
    temp->arbitrary = temp->next->next;
    temp = temp->next;
    temp->arbitrary = (*head_ref)->next->next;
    temp = temp->next;
    temp->arbitrary = (*head_ref)->next;

    return;
}

/* Function to print linked list */
void printList(struct node *head)
{
    struct node *temp = head;
    while(temp->next != NULL)
    {
        printf("data: %d \t next: %d \t arbitrary: %d \n ", temp->data,temp->next->data,temp->arbitrary->data);
        temp = temp->next;
    }
    if( temp != NULL )
    {
        printf("data: %d \t arbitrary: %d \n ", temp->data,temp->arbitrary->data);
    }
}

struct node * clone(struct node **head)
{

}
/* Driver program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;

     push_with_next(&head, 5);
     push_with_next(&head, 4);
     push_with_next(&head, 3);
     push_with_next(&head, 2);
     push_with_next(&head, 1);

     push_with_arbitrary(&head);
     printList(head);

     getchar();
     return 0;
}

