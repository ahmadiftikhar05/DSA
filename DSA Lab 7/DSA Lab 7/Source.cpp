#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;

public:
    LinkedList() : head(NULL) {}

    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (!head) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void insertAtPosition(int value, int position) {
        if (position < 1) {
            cout << "Position should be >= 1." << endl;
            return;
        }

        if (position == 1) {
            insertAtBeginning(value);
            return;
        }

        Node* newNode = new Node();
        newNode->data = value;

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp; ++i) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Position out of range." << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteFromBeginning(int &value) {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        temp->data = value;
        delete temp;
    }

    void deleteFromEnd(int &value) {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        if (!head->next) {
            head->data = value;
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }
        temp->next->data = value;
        delete temp->next;
        temp->next = NULL;
    }

    void deleteFromPosition(int position,int &value) {
        if (position < 1) {
            cout << "Position should be >= 1." << endl;
            return;
        }

        if (position == 1) {
            deleteFromBeginning(value);
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp; ++i) {
            temp = temp->next;
        }

        if (!temp || !temp->next) {
            cout << "Position out of range." << endl;
            return;
        }
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        nodeToDelete->data = value;
        delete nodeToDelete;
    }

    void display() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    LinkedList List;
    string choice;
    while (choice != "8") {
        cout << "\nLinked List Implementation" << endl
            << "1) Insert at Beginning" << endl
            << "2) Insert at End" << endl
            << "3) Insert at Middle" << endl
            << "4) Delete from Begining" << endl
            << "5) Delete from End" << endl
            << "6) Delete from Middle" << endl
            << "7) Display" << endl
            << "8) Exit" << endl << "\nEnter your Choice: ";
        cin >> choice;
        if (choice == "1") {
            int value;
            cout << "\nEnter the value: ";
            cin >> value;
            List.insertAtBeginning(value);
        }
        else if (choice == "2") {
            int value;
            cout << "\nEnter the value: ";
            cin >> value;
            List.insertAtEnd(value);
        }
        else if (choice == "3") {
            int value, position;
            cout << "\nEnter the value: ";
            cin >> value;
            cout << "\nEnter the position: ";
            cin >> position;
            List.insertAtPosition(value, position);
        }
        else if (choice == "4") {
            int val;
            List.deleteFromBeginning(val);
            cout << val << "hase been removed from list" << endl;
        }
        else if (choice == "5") {
            int val;
            List.deleteFromEnd(val);
            cout << val << "hase been removed from list" << endl;
        }
        else if (choice == "6") {
            int position, val;
            cout << "\nEnter the position from where you want to delete: ";
            cin >> position;
            List.deleteFromPosition(position, val);
            cout <<"\n" << val << "hase been removed from list" << endl;
        }
        else if (choice == "7") {
            List.display();
        }
        else if (choice == "8") {
            exit;
        }
        else
        {
            cout << "\ninvalid input!\n" << endl;
        }
    }

}