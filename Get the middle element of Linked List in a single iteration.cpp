#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* getMiddleElement(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node();
    head->data = 1;

    Node* second = new Node();
    second->data = 2;
    head->next = second;

    Node* third = new Node();
    third->data = 3;
    second->next = third;

    Node* fourth = new Node();
    fourth->data = 4;
    third->next = fourth;

    Node* fifth = new Node();
    fifth->data = 5;
    fourth->next = fifth;
    fifth->next = nullptr;

    // Get the middle element
    Node* middle = getMiddleElement(head);
    if (middle != nullptr) {
        std::cout << "Middle element: " << middle->data << std::endl;
    } else {
        std::cout << "The list is empty." << std::endl;
    }

    // Clean up memory (delete all nodes)
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
