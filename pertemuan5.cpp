#include <iostream>
using namespace std;

// Definisikan struct untuk Node linked list
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambah node baru ke linked list
void tambahNode(Node** head, int data) {
    Node* nodeBaru = new Node();
    nodeBaru->data = data;
    nodeBaru->next = *head;
    *head = nodeBaru;
}

// Fungsi rekursif untuk memeriksa apakah linked list adalah palindrome
bool cekPalindrome(Node** left, Node* right) {
    // Jika sudah mencapai akhir linked list
    if (right == nullptr) 
        return true;
    
    // Rekursi untuk ke node berikutnya
    bool hasil = cekPalindrome(left, right->next);
    
    if (!hasil)
        return false;

    // Membandingkan nilai dari node kiri dan kanan
    bool cekSekarang = ((*left)->data == right->data);
    
    // Geser pointer kiri ke depan
    *left = (*left)->next;
    
    return cekSekarang;
}

// Fungsi utama untuk memeriksa apakah linked list adalah palindrome
bool isPalindrome(Node* head) {
    return cekPalindrome(&head, head);
}

int main() {
    Node* head = nullptr;
    int n, nilai;

    // Input jumlah elemen linked list
    cout << "Masukkan jumlah elemen linked list: ";
    cin >> n;

    // Input elemen-elemen linked list dari pengguna
    cout << "Masukkan elemen-elemen linked list: ";
    for (int i = 0; i < n; ++i) {
        cin >> nilai;
        tambahNode(&head, nilai);
    }

    // Cek apakah palindrome
    if (isPalindrome(head)) {
        cout << "Linked list adalah palindrome bubub." << endl;
    } else {
        cout << "Linked list bukan palindrome bubub." << endl;
    }

    return 0;
}

