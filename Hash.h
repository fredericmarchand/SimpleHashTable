#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

class Hash {

public:
    Hash();
    ~Hash();
    void addItem(string key, string value);
    int hash(string key);
    int itemCountAtIndex(int index);
    void clear();
    bool containsValue(string value);
    bool containsKey(string key);
    string getValue(string key);
    int getSize();
    void remove(string key);

private:
    static const int tableSize = 1024;
    int size;

    struct item {
        string key;
        string value;
        item *next;
    };

    item *hashTable[tableSize];

};

#endif
