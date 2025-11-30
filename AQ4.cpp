#include <iostream>
using namespace std;

struct Pair {
    int key;
    int freq;
};

int firstNonRepeating(int nums[], int n) {
    const int TABLE_SIZE = 100;
    Pair hashTable[TABLE_SIZE];

    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].key = -1;
        hashTable[i].freq = 0;
    }

    for (int i = 0; i < n; i++) {
        int value = nums[i];
        int index = value % TABLE_SIZE;
        if (index < 0) index += TABLE_SIZE;

        while (hashTable[index].key != -1 && hashTable[index].key != value) {
            index = (index + 1) % TABLE_SIZE;
        }

        if (hashTable[index].key == -1) {
            hashTable[index].key = value;
            hashTable[index].freq = 1;
        } else {
            hashTable[index].freq++;
        }
    }

    for (int i = 0; i < n; i++) {
        int value = nums[i];
        int index = value % TABLE_SIZE;
        if (index < 0) index += TABLE_SIZE;

        while (hashTable[index].key != -1) {
            if (hashTable[index].key == value && hashTable[index].freq == 1)
                return value;

            index = (index + 1) % TABLE_SIZE;
        }
    }

    return -1;
}

int main() {
    int nums[] = {4, 5, 1, 2, 0, 4};
    int n = 6;

    int result = firstNonRepeating(nums, n);

    if (result != -1)
        cout << result;
    else
        cout << "No non-repeating element";

    return 0;
}
