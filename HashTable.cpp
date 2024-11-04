#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
   Written by Rayan Bellahsni
   Language:  Apple Clang (14.0.3) 64-bit g++ compiler
              Xcode 14 C++ 98
   December 2023
*/


class HashTable {
private:
    vector<string> table;
    int size;

public:

    // This is a constructor to initialize the hash table with a given size
    HashTable(int size) : size(size) {
        table.resize(size);
    }

    //This is a hash function to calculate the index for a given word

    int hashFunction(const string& word) {
        return ((word.front() * 2) + (word.back() - 1)) % size;
    }

    void insert(const string& word) {
        int hashValue = hashFunction(word);

        while (!table[hashValue].empty()) {
            // when collision occurs, this will try the next position
            hashValue = (hashValue + 1) % size;
        }

        table[hashValue] = word;
    }
    
    //This will print the contents of each position in the hash table
    
    void printTable() {
        for (int i = 0; i < size; ++i) {
            cout << "Position " << i << ": ";
            if (!table[i].empty()) {
                cout << table[i];
            } else {
                cout << " ";
            }
            cout << endl;
        }
    }

    bool search(const string& target) {
        int hashValue = hashFunction(target);

        while (!table[hashValue].empty()) {
            if (table[hashValue] == target) {
                return true;
            }

            //When Collision occurs, this will try the next position
            hashValue = (hashValue + 1) % size;
        }

        return false;
    }
};

/*
   Written by Rayan Bellahsni
   Language:  Apple Clang (14.0.3) 64-bit g++ compiler
              Xcode 14 C++ 98
   December 2023
*/ 
  

int main() {
    HashTable hashTable(15);

    // This query user for ten words and store them
    for (int i = 0; i < 10; ++i) {
        string word;
        cout << "Enter word " << i + 1 << ": ";
        cin >> word;
        hashTable.insert(word);
    }

    // This prints the contents of each position
    hashTable.printTable();

    // This queries the user for target words and search for them
    while (true) {
        string target;
        cout << "Enter a target word or 'stop' to exit: ";
        cin >> target;
  
 	
        if (target == "stop") {
            break;
        }

        if (hashTable.search(target)) {
            cout << "Word found in the hash table." << endl;
        } else {
            cout << "Word not found in the hash table." << endl;
        }
    }

    return 0;
}

