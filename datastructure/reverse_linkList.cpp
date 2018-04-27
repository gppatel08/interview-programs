#include <iostream>
#include <stdlib.h>

using namespace std;

/* 1. Iterative Method 

 1. Initialize three pointers prev as NULL, curr as head and next as NULL.
 2. Iterate through the linklist as below:
    //before changing the next of current store next node
    next = curr->next

    //This is where actual reversing happens
    curr->next = prev

    //move prev and curr one step forward
    prev = curr
    curr = next
*/


typedef struct Node {
  int data;
  Node *next;
}Node;

void addListBegin(Node **head_ref, int data) {
  //allocate memory for new node
  Node *new_node = (Node*)malloc(sizeof(Node));
  new_node->data = data;
  
  new_node->next = *head_ref;
  *head_ref = new_node;
}

/*  Iterative Method: Time Complexity: O(n), Space Complexity: O(1)
 1. Initialize three pointers prev as NULL, curr as head and next as NULL.
 2. Iterate through the linklist as below:
    //before changing the next of current store next node
    next = curr->next

    //This is where actual reversing happens
    curr->next = prev

    //move prev and curr one step forward
    prev = curr
    curr = next
*/

void reverseListIterative(Node **head_ref) {
  Node *prev = NULL, *current = *head_ref, *next = NULL;

  while(current != NULL) {
    next = current->next;

    current->next = prev;

    prev = current;
    current = next;
  }
  *head_ref = prev;
}

/* 2. Recursive Method: Time Complexity: O(n), Space Complexity: O(1)
   1) Divide the list in two parts - first node and rest of the linked list.
   2) Call reverse for the rest of the linked list.
   3) Link rest to first.
   4) Fix head pointer */

void recursiveReverse(struct Node** head_ref) {
    struct Node* first;
    struct Node* rest;
      
    /* empty list */
    if (*head_ref == NULL)
       return;   
 
    /* suppose first = {1, 2, 3}, rest = {2, 3} */
    first = *head_ref;  
    rest  = first->next;
 
    /* List has only one node */
    if (rest == NULL)
       return;   
 
    /* reverse the rest list and put the first element at the end */
    recursiveReverse(&rest);
    first->next->next  = first;  
     
    /* tricky step -- see the diagram */
    first->next  = NULL;          
 
    /* fix the head pointer */
    *head_ref = rest;              
}


/* 3. A Simpler and Tail Recursive Method */
/* A simple and tail recursive function to reverse a linked list.  prev is passed as NULL initially.*/
void reverseUtil(Node *curr, Node *prev, Node **head) {
    /* If last node mark it head*/
    if (!curr->next) {
        *head = curr;
 
        curr->next = prev; /* Update next to prev node */
        return;
    }
 
    Node *next = curr->next; /* Save curr->next node for recursive call */
 
    curr->next = prev; /* and update next */
 
    reverseUtil(next, curr, head);
}

/* This function mainly calls reverseUtil() with prev as NULL */
void reverseListRecursive(Node **head) {
    if (!head)
        return;
    reverseUtil(*head, NULL, head);
}

void printList(Node *head) {
  Node *temp = head;
  while(temp != NULL) {
    cout << " " << temp->data;
    temp = temp->next;
  } 
  cout << endl;
}

int main() {
  Node *head = NULL;

  addListBegin(&head, 20);
  addListBegin(&head, 30);
  addListBegin(&head, 40);
  addListBegin(&head, 50);
  addListBegin(&head, 60);

  printList(head);

  //reverseListIterative(&head);
  //reverseListRecursive(&head);
  recursiveReverse(&head);

  printList(head);
  return 0;
}
