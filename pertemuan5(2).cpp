#include <iostream>
using namespace std;

// Definisikan struct untuk Node linked list
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

// Fungsi untuk menambah node di akhir linked list
void tambahNode(Node** head, int data) {
    Node* nodeBaru = new Node(data);
    
    if (*head == nullptr) {
        *head = nodeBaru;
    } else {
        Node* temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = nodeBaru;
    }
}

// Fungsi untuk mengonversi representasi biner dari linked list menjadi desimal
int binerKeDesimal(Node* head) {
    int hasil = 0;
    
    while (head != nullptr) {
        hasil = (hasil << 1) | head->data;  // Geser hasil ke kiri dan tambahkan bit saat ini
        head = head->next;
    }
    
    return hasil;
}

int main() {
    Node* head = nullptr;
    int n, nilai;
    
    // Input jumlah node pada linked list
    cout << "Masukkan jumlah elemen linked list: ";
    cin >> n;

    // Input elemen-elemen linked list (0 atau 1)
    cout << "Masukkan elemen-elemen (0 atau 1): ";
    for (int i = 0; i < n; ++i) {
        cin >> nilai;
        tambahNode(&head, nilai);
    }
    
    // Mengonversi biner ke desimal
    int hasil = binerKeDesimal(head);
    cout << "Nilai desimal dari linked list: " << hasil << endl;
    
    return 0;
}

