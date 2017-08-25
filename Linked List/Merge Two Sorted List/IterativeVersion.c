
/*Program to alternatively split a linked list into two halves */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

/* Link list node */
struct node
{
    int data;
    struct node* next;
};

/* Takes two lists sorted in increasing order, and splices their nodes together to make one big sorted list which is returned.  */
struct node* SortedMerge(struct node* a, struct node* b)
{
   struct node dummy;
   struct node *result = &dummy;

   while(1)
   {
      if(a == NULL)
      {
         /* if either list runs out, use the other list */
         result->next = b;
         break;
      }
      else if (b == NULL)
      {
         result->next = a;
         break;
      }
      if (a->data <= b->data)
      {
         result->next = a;
         a = a->next;
      }
      else
     {
        result->next = b;
        b = b->next;
     }
     result = result->next;
  }
  return(dummy.next);
}

/* Function to insert a node at the beginging of the linked list */
void push(struct node** head_ref, int new_data)
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

/* Function to print nodes in a given linked list */
void printList(struct node *node)
{
  while(node!=NULL)
  {
   printf("%d ", node->data);
   node = node->next;
  }
}

/* Drier program to test above functions*/
int main()
{
  /* Start with the empty list */
  struct node* res = NULL;
  struct node* a = NULL;
  struct node* b = NULL;

  /* Let us create two sorted linked lists to test the functions
   Created lists shall be a: 5->10->15,  b: 2->3->20 */
  push(&a, 15);
  push(&a, 10);
  push(&a, 5);

  push(&b, 20);
  push(&b, 3);
  push(&b, 2);

  /* Remove duplicates from linked list */
  res = SortedMerge(a, b);

  printf("\n Merged Linked List is: \n");
  printList(res);

  getchar();
  return 0;
}
