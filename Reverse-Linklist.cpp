#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) 
    {
        this->data = data;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }
    
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) 
        {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) 
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    // Reverse the Node
    void reverse() 
    {
        Node* prev = nullptr;
        Node* current = head;
        Node* next;

        while (current != nullptr) 
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }
    // To Display
    void display() {
        Node* temp = head;
        while (temp != nullptr) 
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList linkedList;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        linkedList.insertAtEnd(data);
    }
    cout << "Original linked list: ";
    linkedList.display();
    linkedList.reverse();
    cout << "Reversed linked list: ";
    linkedList.display();

    return 0;
}