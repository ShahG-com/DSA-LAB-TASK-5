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

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void insertAfter(Node* prevNode, int data) {
        if (prevNode == nullptr) {
            cout << "Previous node cannot be null." << endl;
            return;
        }

        Node* newNode = new Node(data);
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }

    void deleteNode(int key) {
        Node* temp = head;
        Node* prev = nullptr;

        if (head != nullptr && head->data == key) {
            head = head->next;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
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
            if (temp->data == key) {
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
        while (temp != nullptr) {
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

    linkedList.display();

    int choice;
    cout << "Choose an operation:\n";
    cout << "1. Insert at beginning\n";
    cout << "2. Insert at end\n";
    cout << "3. Insert after a node\n";
    cout << "4. Delete a node\n";
    cout << "5. Search for a node\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    while (choice != 6) {
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to insert at beginning: ";
                cin >> data;
                linkedList.insertAtBeginning(data);
                break;
            }
            case 2: {
                int data;
                cout << "Enter data to insert at end: ";
                cin >> data;
                linkedList.insertAtEnd(data);
                break;
            }
            case 3: {
                int data, position;
                cout << "Enter data to insert: ";
                cin >> data;
                cout << "Enter position after which to insert: ";
                cin >> position;
                Node* prevNode = linkedList.head;
                for (int i = 0; i < position - 1; i++) {
                    prevNode = prevNode->next;
                }
                linkedList.insertAfter(prevNode, data);
                break;
            }
            case 4: {
                int key;
                cout << "Enter key to delete: ";
                cin >> key;
                linkedList.deleteNode(key);
                break;
            }
            case 5: {
                int key;
                cout << "Enter key to search: ";
                cin >> key;
                linkedList.search(key);
                break;
            }
            default:
                cout << "Invalid choice." << endl;
        }

        linkedList.display();

        cout << "\nChoose an operation:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after a node\n";
        cout << "4. Delete a node\n";
        cout << "5. Search for a node\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
    }

    return 0;
}