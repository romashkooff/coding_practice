class Node
{
private:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int key) : key(key), left(nullptr), right(nullptr), height(1) {}

    static Node* rightRotate(Node* y);
    static Node* leftRotate(Node* x);
public:
    int Height();
    int getBalance();

    static Node* nullptrFix(Node* node);
    static Node* insert(Node* node, int key);
    static Node* minValueNode(Node* node);
    static Node* deleteNode(Node* root, int key);
    static Node* search(Node* root, int key);
    static void printSpaces(int count);
    static void printLevel(Node* root, int level, int indentSpace, int levelSpace);
    static void print2D(Node* root);
    static void printInorder(Node* root);
    static void printPostorder(Node* root);
    static void printGivenLevel(Node* root, int level);
};