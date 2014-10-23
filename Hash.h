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
    void addItem(string name, string phone);
    int hash(string key);
    int itemCountAtIndex(int index);

private:
    static const int tableSize = 1024;

    struct item {
        string name;
        string phone;
        item *next;
    };

    item *hashTable[tableSize];

};

#endif
