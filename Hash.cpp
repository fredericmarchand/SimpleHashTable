#include <cstdlib>
#include <iostream>
#include <string>

#include "Hash.h"

using namespace std;

Hash::Hash() 
{
    size = 0;

    for (int i = 0; i < tableSize; ++i)
    {
        hashTable[i] = new item;
        hashTable[i]->key = "";
        hashTable[i]->value = "";
        hashTable[i]->next = NULL;
    }
}

Hash::~Hash()
{
    item *temp = NULL;
    size = 0;
    for (int i = 0; i < tableSize; ++i)
    {
        item *ptr = hashTable[i];
        while (ptr->next != NULL)
        {
            temp = ptr;
            ptr = ptr->next;
            delete temp;
        }
        delete ptr;
    }
}

void Hash::addItem(string key, string value)
{
    int hashIndex = hash(key);
    if (hashTable[hashIndex]->key == "")
    {
        ++size;
        hashTable[hashIndex]->key = key;
        hashTable[hashIndex]->value = value;
        hashTable[hashIndex]->next = NULL;
    }
    else
    {
        item *temp = hashTable[hashIndex];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new item;
        temp->next->key = key;
        temp->next->value = value;
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
    if (hashTable[index]->key == "")
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

void Hash::clear()
{
    size = 0;
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
        delete ptr;
    }

    for (int i = 0; i < tableSize; ++i)
    {
        hashTable[i] = new item;
        hashTable[i]->key = "";
        hashTable[i]->value = "";
        hashTable[i]->next = NULL;
    }
}

bool Hash::containsValue(string value)
{

}

bool Hash::containsKey(string key)
{

}

string Hash::getValue(string key)
{
    int index = hash(key);

    if (hashTable[index]->key == "")
    {
        cerr << "Item does not exist" << endl;
        return "";
    }
    else
    {
        item *ptr = hashTable[index];
        while (ptr->next != NULL)
        {
            if (ptr->key == key)
            {
                return ptr->value;
            }
            ptr = ptr->next;
        }
    }
}

int Hash::getSize()
{
    return size;
}

