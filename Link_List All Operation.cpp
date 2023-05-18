#include <iostream>
#include <stdlib.h>

using namespace std;

// Creating a node
struct Node {
  int data;
  struct Node* next;
};


void insertAtBeginning(struct Node** head, int new_data) {
  // Allocate memory for a node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

  // Insert the data
  new_node->data = new_data;
  new_node->next = *head;

  // Update the head pointer
  *head = new_node;
}



void insertAtend(struct Node** head, int new_data) {
  // Allocate memory for a node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

  // Insert the data
  new_node->data = new_data;
  new_node->next = NULL;  // Set the next pointer of the new node to NULL

  if (*head == NULL) {
    // If the linked list is empty, make the new node the head
    *head = new_node;
  } else {
    struct Node* temp = *head;

    while (temp->next != NULL) {
      temp = temp->next;
    }

    // Append the new node to the end of the linked list
    temp->next = new_node;
  }
}




void insertAfter(struct Node* prev_node, int new_data) {
  // Check if the given previous node is NULL
  if (prev_node == NULL) {
    cout << "The given previous node cannot be NULL";
    return;
  }

  // Allocate memory for a new node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

  // Insert the data into the new node
  new_node->data = new_data;

  // Link the new node to the next node after the previous node
  new_node->next = prev_node->next;

  // Link the previous node to the new node
  prev_node->next = new_node;
}


//delete a Node
void deleteNode(struct Node** head_ref, int key) {
  struct Node *temp = *head_ref, *prev;

  // if (temp != NULL && temp->data == key) {
  // *head_ref = temp->next;
  // free(temp);
  // return;
  // }
  // Find the key to be deleted
  while (temp != NULL && temp->data != key) {
  prev = temp;
  temp = temp->next;
  }

  // If the key is not present
  if (temp == NULL) return;

  // Remove the node
  prev->next = temp->next;

  free(temp);
}

// Traverse a linked list
void printlist(struct Node* head) {
  struct Node* current = head;

  while (current != NULL) {
    cout << current->data << " ";
    current = current->next;
  }
}

int main() {
  Node* head = NULL;
  Node* one = NULL;
  Node* two = NULL;
  Node* three = NULL;

  // Allocate 3 node memory
  one = new Node();
  two = new Node();
  three = new Node();

  // Assign values
  head = one;
  one->data = 1;
  one->next = two;
  two->data = 2;
  two->next = three;
  three->data = 3;
  three->next = NULL;

  // Update the head pointer with the new node inserted at the beginning
  insertAtBeginning(&head, 6);
  insertAtend(&head,10);
  
  insertAfter(head->next->next,9);
  // Print the linked list values
  printlist(head);

  cout<<endl;

  deleteNode(&head,9);

  printlist(head);

  return 0;
}
