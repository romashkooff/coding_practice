#include "Node.h"
#include <iostream>

using namespace std;

void interactiveMenu() {
    Node* root = nullptr;
    int choice, key;

    while (true) {
        cout << "AVL Tree Operations Menu\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Print 2D\n";
        cout << "5. Print Inorder\n";
        cout << "6. Print Postorder\n";
        cout << "7. Print Given Level\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            root = Node::insert(root, key);
            break;
        case 2:
            cout << "Enter key to delete: ";
            cin >> key;
            root = Node::deleteNode(root, key);
            break;
        case 3:
            cout << "Enter key to search: ";
            cin >> key;
            if (Node::search(root, key))
                cout << "Key " << key << " found in the AVL tree.\n";
            else
                cout << "Key " << key << " not found in the AVL tree.\n";
            break;
        case 4:
            cout << "2D visualization of the AVL tree:\n";
            Node::print2D(root);
            cout << endl;
            break;
        case 5:
            cout << "Inorder traversal of the AVL tree:\n";
            Node::printInorder(root);
            cout << endl;
            break;
        case 6:
            cout << "Postorder traversal of the AVL tree:\n";
            Node::printPostorder(root);
            cout << endl;
            break;
        case 7:
            cout << "Enter level to print: ";
            cin >> key;
            cout << "Nodes at level " << key << ":\n";
            Node::printGivenLevel(root, key);
            cout << endl;
            break;
        case 8:
            return;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    }
}

int main() {
    interactiveMenu();

    return 0;
}
