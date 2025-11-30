#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) { data = v; left = right = NULL; }
};

bool insertHash(int value, int hashTable[], int size) {
    int index = value % size;
    if (index < 0) index += size;

    while (hashTable[index] != -1) {
        if (hashTable[index] == value)
            return false; // duplicate found
        index = (index + 1) % size;
    }

    hashTable[index] = value;
    return true;
}

bool checkDuplicates(Node* root, int hashTable[], int size) {
    if (root == NULL) return false;

    if (!insertHash(root->data, hashTable, size))
        return true;

    return checkDuplicates(root->left, hashTable, size) ||
           checkDuplicates(root->right, hashTable, size);
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(10);

    const int TABLE_SIZE = 100;
    int hashTable[TABLE_SIZE];

    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = -1;

    if (checkDuplicates(root, hashTable, TABLE_SIZE))
        cout << "Duplicates Found";
    else
        cout << "No Duplicates";

    return 0;
}
