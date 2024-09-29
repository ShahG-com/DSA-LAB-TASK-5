#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
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

    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int data) 
    {
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

    void insertAfter(Node* prevNode, int data) 
    {
        if (prevNode == nullptr) {
            cout << "Previous node cannot be null." << endl;
            return;
        }

        Node* newNode = new Node(data);
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }

    void deleteNode(int key) 
    {
        Node* temp = head;
        Node* prev = nullptr;

        if (head != nullptr && head->data == key) 
        {
            head = head->next;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->data != key) 
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) 
        {
            cout << "Key not found." << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
    }

    void search(int key) {
        Node* temp = head;
        int position = 1;

        while (temp != nullptr) {
            if (temp->data == key) 
            {
                cout << "Key " << key << " found at position " << position << endl;
                return;
            }
            temp = temp->next;
            position++;
        }

        cout << "Key " << key << " not found." << endl;
    }

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

    int data;
    cout << "Enter 5 elements for the linked list: ";
    for (int i = 0; i < 5; i++) 
    {
        cin >> data;
        linkedList.insertAtEnd(data);
    }

    linkedList.display();

    // Perform operations (insert, delete, search)
    linkedList.insertAtBeginning(10);
    linkedList.display();

    linkedList.insertAfter(linkedList.head->next, 20);
    linkedList.display();

    linkedList.deleteNode(10);
    linkedList.display();

    linkedList.search(20);

    return 0;
}