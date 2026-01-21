#include <iostream>
#include <queue>
using namespace std;

// **************************** Linked List Implementation ************************** //

// [ 1 | adrs1 ] -> [ 2 | adrs2 ] -> [ 3 | nullptr ]
//   ^              #adrs1           #adrs2         
//   | #head


// Singly linked Node creation
struct Node {
    int data;
    Node* link;
};

// Doubly linked Node creation
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

Node* head = nullptr;           // global

// int main () {
// Node *ptr = new Node();              // Create new node using new, return the adreess into the pointer ptr
// ptr->data = 10;
// ptr->link = nullptr;                 // As it's the only node, link part will point to null
// head = ptr;                         // Make head point to this node
//}

// Insertion at end
void insertAtEnd(int value) {
    Node* ptr = new Node();              // Create new node using new
    ptr->data = value;
    ptr->link = nullptr;
    if (!isEmpty()) {                        // If list is empty
        head = ptr;
    } else {                                // If list is not empty
        Node* temp = head;
        while (temp->link != nullptr) {      // Traverse to the last node
            temp = temp->link;
        }
        temp->link = ptr;
    }
}

// Deletion from start
void deleteFromStart() {
    if (head == nullptr) {
        cout << "List is empty, nothing to delete" << endl;
        return;
    }
    Node* temp = head;                                       // Store current head
    head = head->link;                                    // Move head to next node
    delete temp;                                            // Free memory
}

// Deletion from end
void deleteFromEnd() {
    if (head == nullptr) {
        cout << "List is empty, nothing to delete" << endl;
        return;
    }
    if (head->link == nullptr) {                            // If there's only one node
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->link->link != nullptr) {                  // Traverse to the second last node
        temp = temp->link;
    }
    delete temp->link;                                     // Free memory of last node
    temp->link = nullptr;                                  // Update second last node's link to null
}

// Delete note given only access to that node
void deleteNode(Node* node) {
    if (node == nullptr || node->link == nullptr) {
        cout << "Cannot delete the given node." << endl;
        return;
    }
    Node* temp = node->link;          // Store next node
    node->data = temp->data;         // Copy data from next node to current node
    node->link = temp->link;         // Link current node to the next of next node
    delete temp;                     // Free memory of next node
}

// Finding middle element
void findMiddle() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->link != nullptr) {
        slow = slow->link;               // Move slow by one
        fast = fast->link->link;        // Move fast by two
    }
    cout << "Middle element is: " << slow->data << endl;
}

// reversing the linked list
void reverseList() {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while (current != nullptr) {
        next = current->link;      // Store next node
        current->link = prev;      // Reverse current node's link
        prev = current;            // Move prev to current node
        current = next;            // Move to next node
    }
    head = prev;                   // Update head to new first node
}

// find/detect loop in linked list using Floyd’s Cycle-Finding Algorithm
bool detectLoop() { 
    Node *slow = head, *fast = head; 
    while (slow && fast && fast->link) { 
        slow = slow->link; 
        fast = fast->link->link; 
        if (slow == fast) { 
            return true; 
        } 
    } 
    return false; 
}

// ************************************** Stack using Linked List ****************************** //

// Node structure
struct StackNode {
    int data;
    StackNode* link;
};
StackNode* top = nullptr;


// empty check => indicates T/F wether the stack is empty or not. [condition: top == nullptr]
bool isEmpty() {
    return top == nullptr ? true : false;
}

// Insert at start (PUSH)
void PUSH(int value) {
    StackNode *ptr = new StackNode();              // Create new node using new, return the adreess into the pointer ptr
    ptr->data = value;                   // Insert the value into the data part of the node
    ptr->link = top;                   // Make the link part of the new node point to the current top (top of the stack)
    top = ptr;                         // Update top to point to the new node
}

// Delete from start (POP)
void POP() {
    if (top == nullptr) {
        cout << "Stack Underflow/Stack is empty" << endl;
        return;
    }
    StackNode* temp = top;                  // Store current top
    top = top->link;                  // Move top to next node
    delete temp;                        // Free memory
}

// Peek operation => returns the top element of the stack without removing it
void PEEk() {
    if (top == nullptr) {
        cout << "Stack is empty" << endl;  
    }
    cout << "Top element is: ";
    cout << top->data << endl;                  // Return the data of the top node
}

int main() {
    PUSH(10);
    PUSH(20);
    PUSH(30);
    PEEk();             // Output: 30
    POP();
    PEEk();             // Output: 20
    POP();
    POP();
    POP();              // Output: Stack Underflow/Stack is empty
    return 0;
}

// ************************************** Queue using Linked List ****************************** //


struct QueueNode {
    int data;
    QueueNode* link;
};

QueueNode *front = nullptr;
QueueNode *rear = nullptr;

// add element at rear end (ENQUEUE)
void ENQUEUE(int value) {
    QueueNode* ptr = new QueueNode();
    ptr->data = value;
    ptr->link = nullptr;
    if (rear == nullptr) {               // If queue is empty
        front = rear = ptr;
        return;
    }
    rear->link = ptr;                   // Link new node at the end of the queue
    rear = ptr;                         // Update rear to new node
}

// delete element from front end (DEQUEUE)
void DEQUEUE() {
    if (front == nullptr) {
        cout << "Queue Underflow/Queue is empty" << endl;
        return;
    }
    QueueNode* temp = front;            // Store current front
    front = front->link;                // Move front to next node
    if (front == nullptr) {             // If queue becomes empty
        rear = nullptr;
    }
    delete temp;                        // Free memory
}

// Peek front and rear elements
void ShowFront() {
    if (front == nullptr) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Front element is: " << front->data << endl;
}

// Peek rear element
void ShowRear() {
    if (rear == nullptr) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Rear element is: " << rear->data << endl;
}

//  Check if queue is empty
void IsEmptyQueue() {
    if (front == nullptr) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }
}

// ************************************** STL QUEUE *************************************** //



// queue <TYPE> queue_name;  // syntax for STL queue
// 
queue<int> q;  // creates a queue named q of integers

q.push(10);  // adds 10 to the rear of the queue

cout << q.front() << " " << q.back() << endl;   // return a reference to the element at front
  // return a reference to the element at rear