#include <iostream>
using namespace std;

struct Pair {
    int key;
    int freq;
};

void countFrequency(int nums[], int n) {
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

    cout << "Frequency count:\n";
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i].key != -1) {
            cout << hashTable[i].key << " : " << hashTable[i].freq << " times\n";
        }
    }
}

int main() {
    int nums[] = {2, 3, 2, 4, 3, 2};
    int n = 6;

    countFrequency(nums, n);

    return 0;
}
