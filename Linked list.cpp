#include <iostream>
#include <string>

class Node {
public:
    std::string data;
    Node* next;

    Node(const std::string& data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    // Menambahkan nama tempat ke akhir linked list
    void append(const std::string& data) {
        Node* new_node = new Node(data);
        if (head == nullptr) {
            head = new_node;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_node;
    }

    // Menampilkan isi linked list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "Berhenti" << std::endl;
    }
};

int main() {
    // Membuat objek LinkedList
    LinkedList myLinkedList;

    // Menambahkan nama tempat ke dalam linked list
    myLinkedList.append("Jakarta");
    myLinkedList.append("Bandung");
    myLinkedList.append("Surabaya");
    myLinkedList.append("Yogyakarta");

    // Menampilkan isi linked list
    myLinkedList.display();

    return 0;
}
