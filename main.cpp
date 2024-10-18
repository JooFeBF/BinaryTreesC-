#include <iostream>

using namespace std;

struct node {
    int data;
    node *left;
    node *right;
};

node *createNode(int data) {
    node *newNode = new node;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void addNode(node **root, int data) {
    node *newNode = createNode(data);
    node *current = *root;
    if (*root == nullptr) {
        cout << "Root is empty. Adding node to root." << endl;
        *root = newNode;
        return;
    }
    while (true) {
        std::cout << "Add node to the left or right subtree? (l/r): ";
        char choice;
        std::cin >> choice;
        if (choice == 'l') {
            if (current->left == nullptr) {
                current->left = newNode;
                break;
            } else {
                current = current->left;
            }
        } else if (choice == 'r') {
            if (current->right == nullptr) {
                current->right = newNode;
                break;
            } else {
                current = current->right;
            }
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}

void inOrderTraversal(node *root) {
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->left);
    std::cout << root->data << " ";
    inOrderTraversal(root->right);
}

void printBinaryTree(string prefix, node *root, bool isLeft) {
    if (root != nullptr) {
        cout << prefix;
        cout << (isLeft ? "├──" : "└──");
        cout << root->data << endl;
        printBinaryTree(prefix + (isLeft ? "│   " : "    "), root->left, true);
        printBinaryTree(prefix + (isLeft ? "│   " : "    "), root->right, false);
    }
}

void visualizeTree(node *root) {
    printBinaryTree("", root, false);
}

void printOptions() {
    std::cout << "1. Add Node" << std::endl;
    std::cout << "2. In-Order Traversal" << std::endl;
    std::cout << "3. Visualize Tree" << std::endl;
    std::cout << "4. Exit" << std::endl;
}

int getUserChoice() {
    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    return choice;
}

int getUserInput() {
    int data;
    std::cout << "Enter data: ";
    std::cin >> data;
    return data;
}

int main() {
    node *root = nullptr;
    while (true) {
        printOptions();
        int choice = getUserChoice();
        switch (choice) {
            case 1:
                addNode(&root, getUserInput());
                break;
            case 2:
                inOrderTraversal(root);
                std::cout << std::endl;
                break;
            case 3:
                visualizeTree(root);
                break;
            case 4:
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}
