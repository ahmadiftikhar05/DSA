#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int runs;
    Node* prev = NULL;
    Node* next = NULL ;
};

class DoublyList {
private:
    Node* head;
    Node* tail;

public:
    DoublyList() : head(nullptr), tail(nullptr) {}

    void addRunsAtStart(int runs) {
        Node* newNode = new Node();
        newNode->runs = runs;
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void addRunsAtEnd(int runs) {
        Node* newNode = new Node();
        newNode->runs = runs;
        if (!tail) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deleteAllOccurrences(int score) {
        if (!head) {
            cout << "No matches recorded yet.\n";
            return;
        }
        Node* current = head;
        bool found = false;
        while (current) {
            if (current->runs == score) {
                found = true;
                Node* toDelete = current;
                if (current->prev) current->prev->next = current->next;
                if (current->next) current->next->prev = current->prev;
                if (current == head) head = current->next;
                if (current == tail) tail = current->prev;
                current = current->next;
                delete toDelete;
            }
            else {
                current = current->next;
            }
        }
        if (!found)
            cout << "Score not found in any match." << endl;
        else
            cout << "Score Removed successfully" << endl;
    }

    void displayScores() {
        if (!head) {
            cout << "No matches recorded yet.\n";
            return;
        }
        Node* current = head;
        while (current) {
            cout << current->runs << " ";
            current = current->next;
        }
        cout << "\n";
    }

    void displayScoresReverse() {
        if (!tail) {
            cout << "No matches recorded yet.\n";
            return;
        }
        Node* current = tail;
        while (current) {
            cout << current->runs << " ";
            current = current->prev;
        }
        cout << "\n";
    }

    void findHighestAndLowestScores() {
        if (!head) {
            cout << "No matches recorded yet.\n";
            return;
        }
        int highest = INT_MIN, lowest = INT_MAX;
        Node* current = head;
        while (current) {
            if (current->runs > highest) highest = current->runs;
            if (current->runs < lowest) lowest = current->runs;
            current = current->next;
        }
        cout << "Highest Score: " << highest << "\n";
        cout << "Lowest Score: " << lowest << "\n";
    }
};

int main() {
    DoublyList team;
    int choice, runs;

    do {
        cout << "\n1. Add Runs at Start\n2. Add Runs at End\n3. Delete All Occurrences of a Score\n";
        cout << "4. Display Scores in Sequence\n5. Display Scores in Reverse Sequence\n6. Find Highest and Lowest Scores\n7. Exit\n";
        cout << "Enter your choice: ";
        while (true) {
            cin >> choice;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Invalid input. Please enter a valid integer: ";
            }
            else {
                break;
            }
        }

        if (choice == 1) {
            cout << "Enter runs to add at start: ";
            cin >> runs;
            team.addRunsAtStart(runs);
        }
        else if (choice == 2) {
            cout << "Enter runs to add at end: ";
            cin >> runs;
            team.addRunsAtEnd(runs);
        }
        else if (choice == 3) {
            cout << "Enter score to delete: ";
            cin >> runs;
            team.deleteAllOccurrences(runs);
        }
        else if (choice == 4) {
            team.displayScores();
        }
        else if (choice == 5) {
            team.displayScoresReverse();
        }
        else if (choice == 6) {
            team.findHighestAndLowestScores();
        }
        else if (choice == 7) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
        cout << "\n";
        system("pause");
        system("CLS");
    } while (choice != 7);

    return 0;
}
