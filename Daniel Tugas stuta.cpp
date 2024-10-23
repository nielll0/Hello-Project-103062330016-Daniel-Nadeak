#include <iostream>
using namespace std;

// Node structure for Double Linked List
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a new node at a specific position
void insertAtPosition(Node*& head, int data, int position) {
    Node* newNode = createNode(data);
    
    // If inserting at the head
    if (position == 1) {
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position is out of range." << endl;
        return;
    }

    newNode->next = temp->next;
    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }
    newNode->prev = temp;
    temp->next = newNode;
}

// Function to display the Double Linked List
void displayList(Node* node) {
    int count = 1;
    while (node != nullptr) {
        cout << "node " << count << ": " << node->data << endl;
        node = node->next;
        count++;
    }
}

int main() {
    Node* head = nullptr;
    int n, data, position;

    cout << "Masukkan jumlah node (3 atau lebih): ";
    cin >> n;

    // Inserting initial nodes
    for (int i = 1; i <= n; i++) {
        cout << "Input data untuk node " << i << ": ";
        cin >> data;
        insertAtPosition(head, data, i);
    }

    cout << "\nData yang dimasukkan ke dalam daftar adalah:" << endl;
    displayList(head);

    // Inserting a new node at a specific position
    cout << "\nMasukkan posisi (2 hingga " << n << ") untuk memasukkan node baru: ";
    cin >> position;
    cout << "Input data untuk posisi " << position << ": ";
    cin >> data;

    insertAtPosition(head, data, position);

    cout << "\nSetelah penyisipan, daftar baru adalah:" << endl;
    displayList(head);

    return 0;
}

