#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) { data = v; next = NULL; }
};

bool hasLoop(Node* head) {
    const int TABLE_SIZE = 100;
    Node* hashTable[TABLE_SIZE];

    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = NULL;

    Node* current = head;

    while (current != NULL) {
        int key = (long long)current % TABLE_SIZE;
        if (key < 0) key += TABLE_SIZE;

        while (hashTable[key] != NULL) {
            if (hashTable[key] == current)
                return true;

            key = (key + 1) % TABLE_SIZE;
        }

        hashTable[key] = current;
        current = current->next;
    }

    return false;
}

int main() {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;

    if (hasLoop(n1))
        cout << "true";
    else
        cout << "false";

    return 0;
}
