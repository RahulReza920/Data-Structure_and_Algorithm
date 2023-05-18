#include <iostream>

struct Node {
    int data;
    Node* next;
};

bool hasLoop(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

int main() {
    // Create a sample linked list with a loop: 1 -> 2 -> 3 -> 4 -> 5 -> 3
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
    
    // Create the loop
    fifth->next = third;

    // Detect loop
    bool loopExists = hasLoop(head);
    if (loopExists) {
        std::cout << "The linked list contains a loop." << std::endl;
    } else {
        std::cout << "The linked list does not contain a loop." << std::endl;
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
