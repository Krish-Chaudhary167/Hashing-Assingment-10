#include <iostream>
using namespace std;

bool containsDuplicate(int nums[], int n) {
    const int TABLE_SIZE = 100; 
    int hashTable[TABLE_SIZE];

    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = -1;

    for (int i = 0; i < n; i++) {
        int value = nums[i];
        int hashIndex = value % TABLE_SIZE;

        if (hashIndex < 0)
            hashIndex += TABLE_SIZE;

        while (hashTable[hashIndex] != -1) {
            if (hashTable[hashIndex] == value)
                return true;
            hashIndex = (hashIndex + 1) % TABLE_SIZE;
        }

        hashTable[hashIndex] = value;
    }

    return false;
}

int main() {
    int nums[] = {1, 2, 3, 1};
    int n = 4;

    if (containsDuplicate(nums, n))
        cout << "true";
    else
        cout << "false";

    return 0;
}
