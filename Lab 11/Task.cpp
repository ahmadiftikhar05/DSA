#include <iostream>
#include <queue>
#include <limits> 

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int key) {
        data = key;
        left = right = nullptr;
    }
};


void BFS(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty. Nothing to traverse.\n";
        return;
    }
    queue<Node*> q;
    q.push(root);
    cout << "BFS Traversal of the Tree: ";
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        cout << node->data << " ";
        if (node->left != nullptr) {
            q.push(node->left);
        }
        if (node->right != nullptr) {
            q.push(node->right);
        }
    }
    cout << endl;
}

// Free Memory for Tree
void freeTree(Node* root) {
    if (root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

// Safe Input Function
int safeInput() {
    int value;
    while (!(cin >> value)) {
        cout << "Invalid input. Please enter an integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return value;
}

// Build Tree from User Input
Node* buildTree() {
    cout << "Enter root node value (-1 for NULL): ";
    int data = safeInput();

    if (data == -1) {
        cout << "Empty tree created.\n";
        return nullptr;
    }

    Node* root = new Node(data);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << "Enter left child of " << current->data << " (-1 for NULL): ";
        data = safeInput();
        if (data != -1) {
            current->left = new Node(data);
            q.push(current->left);
        }

        cout << "Enter right child of " << current->data << " (-1 for NULL): ";
        data = safeInput();
        if (data != -1) {
            current->right = new Node(data);
            q.push(current->right);
        }
    }

    return root;
}

int main() {
    Node* root = buildTree();

    BFS(root);

    // Free the dynamically allocated memory
    freeTree(root);

    return 0;
}
