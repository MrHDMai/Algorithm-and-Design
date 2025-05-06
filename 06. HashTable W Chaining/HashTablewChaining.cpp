#include <iostream>
#include <list>
#include <vector>

using namespace std;

int tableSize;  // Size of the hash table
vector<list<int>> hashTable;  // Hash table using chaining

// Hash function to compute index
int hashFunction(int key) {
    return key % tableSize;
}

// Insert key into hash table
void insertKey(int key) {
    int index = hashFunction(key);
    hashTable[index].push_front(key);
}

// Delete key from hash table
void deleteKey(int key) {
    int index = hashFunction(key);
    auto& chain = hashTable[index];

    for (auto it = chain.begin(); it != chain.end(); ++it) {
        if (*it == key) {
            chain.erase(it);
            cout << key << ":DELETED;\n";
            return;
        }
    }
    cout << key << ":DELETE_FAILED;\n";
}

// Search for a key in the hash table
void searchKey(int key) {
    int index = hashFunction(key);
    const auto& chain = hashTable[index];
    int position = 0;

    for (auto it = chain.begin(); it != chain.end(); ++it, ++position) {
        if (*it == key) {
            cout << key << ":FOUND_AT" << index << "," << position << ";\n";
            return;
        }
    }
    cout << key << ":NOT_FOUND;\n";
}

// Print the entire hash table
void printHashTable() {
    for (int i = 0; i < tableSize; ++i) {
        cout << i << ":";
        for (int key : hashTable[i]) {
            cout << key << "->";
        }
        cout << ";\n";
    }
}

int main() {
    cin >> tableSize;
    hashTable.resize(tableSize);

    char command;
    int key;

    while (true) {
        cin >> command;

        if (command == 'e') break;  // Exit loop on 'e'

        switch (command) {
            case 'i':  // Insert
                cin >> key;
                insertKey(key);
                break;

            case 'd':  // Delete
                cin >> key;
                deleteKey(key);
                break;

            case 's':  // Search
                cin >> key;
                searchKey(key);
                break;

            case 'o':  // Output
                printHashTable();
                break;

            default:
                cerr << "Invalid command!\n";
        }
    }

    return 0;
}
