#include <iostream>
using namespace std;

void findCommon(int A[], int n1, int B[], int n2) {
    const int TABLE_SIZE = 100;
    int hashTable[TABLE_SIZE];

    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = -1;

    for (int i = 0; i < n1; i++) {
        int value = A[i];
        int index = value % TABLE_SIZE;
        if (index < 0) index += TABLE_SIZE;

        while (hashTable[index] != -1) {
            index = (index + 1) % TABLE_SIZE;
        }
        hashTable[index] = value;
    }

    cout << "Common elements: ";

    for (int i = 0; i < n2; i++) {
        int value = B[i];
        int index = value % TABLE_SIZE;
        if (index < 0) index += TABLE_SIZE;

        while (hashTable[index] != -1) {
            if (hashTable[index] == value) {
                cout << value << " ";
                break;
            }
            index = (index + 1) % TABLE_SIZE;
        }
    }
}

int main() {
    int A[] = {1, 2, 3, 4};
    int B[] = {3, 4, 5, 6};

    int n1 = 4, n2 = 4;

    findCommon(A, n1, B, n2);

    return 0;
}
