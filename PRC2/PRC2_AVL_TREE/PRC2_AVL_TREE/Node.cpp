#include "Node.h"

#include <iostream>
#include <algorithm>

using namespace std;

int Node::Height() {
    return height;
}

int Node::getBalance() {
    if (left == nullptr && right == nullptr)
        return 0;
    else if (left == nullptr)
        return -right->Height();
    else
        return left->Height();
    return left->Height() - right->Height();
}

Node* Node::rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;


    nullptrFix(y);
    nullptrFix(x);

    return x;
}

Node* Node::leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    nullptrFix(x);
    nullptrFix(y);

    return y;
}

Node* Node::nullptrFix(Node* node) {
    if (node->left == nullptr && node->right == nullptr)
        node->height = 1;
    else if (node->left == nullptr)
        node->height = 1 + node->right->Height();
    else if (node->right == nullptr)
        node->height = 1 + node->left->Height();
    else
        node->height = 1 + max(node->left->Height(), node->right->Height());
    return node;
}

Node* Node::insert(Node* node, int key) {
    if (node == nullptr)
        return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    nullptrFix(node);

    int balance = node->getBalance();

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* Node::minValueNode(Node* node) {
    Node* current = node;

    while (current->left != nullptr)
        current = current->left;

    return current;
}

Node* Node::deleteNode(Node* root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == nullptr || root->right == nullptr) {
            Node* temp = root->left ? root->left : root->right;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            }
            else
                *root = *temp;

            delete temp;
        }
        else {
            Node* temp = minValueNode(root->right);

            root->key = temp->key;

            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == nullptr)
        return root;

    root->height = 1 + max(root->left->Height(), root->right->Height());

    int balance = root->getBalance();

    if (balance > 1 && root->left->getBalance() >= 0)
        return rightRotate(root);

    if (balance > 1 && root->left->getBalance() < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && root->right->getBalance() <= 0)
        return leftRotate(root);

    if (balance < -1 && root->right->getBalance() > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node* Node::search(Node* root, int key) {
    if (root == nullptr || root->key == key)
        return root;

    if (key < root->key)
        return search(root->left, key);

    return search(root->right, key);
}

void Node::printSpaces(int count) {
    for (int i = 0; i < count; i++)
        cout << " ";
}

void Node::printLevel(Node* root, int level, int indentSpace, int levelSpace) {
    if (root == nullptr) {
        printSpaces(levelSpace);
        return;
    }

    if (level == 1) {
        printSpaces(indentSpace);
        cout << root->key;
        printSpaces(levelSpace - indentSpace);
    }
    else if (level > 1) {
        printLevel(root->left, level - 1, indentSpace, levelSpace / 2);
        printLevel(root->right, level - 1, indentSpace, levelSpace / 2);
    }
}

void Node::print2D(Node* root) {
    int h = root->Height();
    int levelSpace = pow(2, h) * 2 - 1;

    for (int i = 1; i <= h; i++) {
        printLevel(root, i, levelSpace / pow(2, i), levelSpace);
        cout << endl;
    }
}

void Node::printInorder(Node* root) {
    if (root != nullptr) {
        printInorder(root->left);
        cout << root->key << " ";
        printInorder(root->right);
    }
}

void Node::printPostorder(Node* root) {
    if (root != nullptr) {
        printPostorder(root->left);
        printPostorder(root->right);
        cout << root->key << " ";
    }
}

void Node::printGivenLevel(Node* root, int level) {
    if (root == nullptr)
        return;
    if (level == 1)
        cout << root->key << " ";
    else if (level > 1) {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

