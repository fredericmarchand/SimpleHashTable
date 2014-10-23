#include <cstdlib>
#include <iostream>
#include <string>

#include "Hash.h"

using namespace std;

Hash::Hash() 
{
    for (int i = 0; i < tableSize; ++i)
    {
        hashTable[i] = new item;
        hashTable[i]->name = "";
        hashTable[i]->phone = "";
        hashTable[i]->next = NULL;
    }
}

Hash::~Hash()
{
    item *temp = NULL;

    for (int i = 0; i < tableSize; ++i)
    {
        item *ptr = hashTable[i];
        while (ptr->next != NULL)
        {
            temp = ptr;
            ptr = ptr->next;
            delete temp;
        }
    }
}

void Hash::addItem(string name, string phone)
{
    int key = hash(name);
    if (hashTable[key]->name == "")
    {
        hashTable[key]->name = name;
        hashTable[key]->phone = phone;
        hashTable[key]->next = NULL;
    }
    else
    {
        item *temp = hashTable[key];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new item;
        temp->next->name = name;
        temp->next->phone = phone;
        temp->next->next = NULL;
    }
}

int Hash::hash(string key)
{
    int hashIndex;

    for (int i = 0; i < key.length(); ++i)
    {
        hashIndex += (int)key[i];
        hashIndex *= 17;
    }

    return hashIndex % tableSize;
}
 
int Hash::itemCountAtIndex(int index)
{
    int count = 0;
    item *ptr = hashTable[index];
    if (hashTable[index]->name == "")
    {
        return 0;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ++count;
            ptr = ptr->next;
        }
    }
    return count;
}
