#include <iostream>
#include <algorithm> // for max()
using namespace std;

// Node structure for BST
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Binary Search Tree class
class BST {
private:
    Node* root;

    // Helper function for insertion
    Node* insert(Node* node, int val) {
        if (node == nullptr)
            return new Node(val);

        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        else
            cout << "Duplicate value not allowed.\n";

        return node;
    }

    // Helper function for inorder display
    void inorder(Node* node) {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Helper function to find height (longest path)
    int height(Node* node) {
        if (node == nullptr)
            return 0;
        return 1 + max(height(node->left), height(node->right));
    }

    // Helper function to find minimum value
    Node* findMin(Node* node) {
        while (node && node->left != nullptr)
            node = node->left;
        return node;
    }

    // Helper function to mirror the tree
    void mirror(Node* node) {
        if (node == nullptr)
            return;

        mirror(node->left);
        mirror(node->right);
        swap(node->left, node->right);
    }

    // Helper function to search value
    bool search(Node* node, int val) {
        if (node == nullptr)
            return false;
        if (node->data == val)
            return true;
        else if (val < node->data)
            return search(node->left, val);
        else
            return search(node->right, val);
    }

    // Helper function to delete node
    Node* deleteNode(Node* node, int val) {
        if (node == nullptr)
            return node;

        if (val < node->data)
            node->left = deleteNode(node->left, val);
        else if (val > node->data)
            node->right = deleteNode(node->right, val);
        else {
            // Node found
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            else if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            // Node with two children
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

public:
    BST() { root = nullptr; }

    void insert(int val) { root = insert(root, val); }

    void display() {
        if (root == nullptr)
            cout << "Tree is empty.\n";
        else {
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << endl;
        }
    }

    void longestPath() {
        cout << "Number of nodes in the longest path: " << height(root) << endl;
    }

    void minimumValue() {
        if (root == nullptr)
            cout << "Tree is empty.\n";
        else
            cout << "Minimum value in the tree: " << findMin(root)->data << endl;
    }

    void mirrorTree() {
        mirror(root);
        cout << "Tree has been mirrored (left and right pointers swapped).\n";
    }

    void searchValue(int val) {
        if (search(root, val))
            cout << "Value " << val << " found in the tree.\n";
        else
            cout << "Value " << val << " not found in the tree.\n";
    }

    void deleteValue(int val) {
        if (root == nullptr) {
            cout << "Tree is empty.\n";
            return;
        }
        root = deleteNode(root, val);
        cout << "If present, value " << val << " has been deleted.\n";
    }
};

// Main function
int main() {
    BST tree;
    int choice, val;

    do {
        cout << "\n--- Binary Search Tree Menu ---\n";
        cout << "1. Insert Node\n";
        cout << "2. Display Tree (Inorder)\n";
        cout << "3. Find Number of Nodes in Longest Path\n";
        cout << "4. Find Minimum Value\n";
        cout << "5. Mirror the Tree\n";
        cout << "6. Search a Value\n";
        cout << "7. Delete a Value\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            tree.insert(val);
            break;

        case 2:
            tree.display();
            break;

        case 3:
            tree.longestPath();
            break;

        case 4:
            tree.minimumValue();
            break;

        case 5:
            tree.mirrorTree();
            break;

        case 6:
            cout << "Enter value to search: ";
            cin >> val;
            tree.searchValue(val);
            break;

        case 7:
            cout << "Enter value to delete: ";
            cin >> val;
            tree.deleteValue(val);
            break;

        case 8:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 8);

    return 0;
}
