//
//  linear.cpp
//  hashing
//
//  Created by Jingchen Cao on 5/19/19.
//  Copyright © 2019 cjc. All rights reserved.
//

#include "linear.hpp"

int linearHash::cHash(char *key)
{
    int tmp = 0;
    for (char *i = key; *i; i++)
    {
        tmp = (tmp * 53 % BIGINT + (int)*i) % BIGINT;
    }
    return tmp % size;
}

void linearHash::set(char *key)
{
    int idx = cHash(key);
    while (hashTable[idx] != nullptr)
    {
        idx = (idx + 1) % size;
    }
    
    hashTable[idx] = new char[strlen(key)];
    strcpy(hashTable[idx], key);
    used += 1;
}

bool linearHash::get(char *key)
{
    int idx = cHash(key);
    while (1)
    {
        if (hashTable[idx] == nullptr)
        {
            return false;
        }
        if (strcmp(hashTable[idx], key) == 0)
        {
            return true;
        }
        idx = (idx + 1) % size;
    }
}

void linearHash::del(char *key)
{
    int idx = cHash(key);
    while (1)
    {
        if (hashTable[idx] == nullptr)
        {
            throw "Not Existed Error!";
        }
        if (strcmp(hashTable[idx], key) == 0)
        {
            delete hashTable[idx];
            hashTable[idx] = nullptr;
            used -= 1;
            return;
        }
        idx = (idx + 1) % size;
    }
}

void linearHash::show()
{
    cout << "Used : " << used << endl;
    cout << "-------------------------" << endl;
    for (int i = 0; i < size; i++)
    {
        if (hashTable[i] != nullptr)
        {
            cout << i << " : " << hashTable[i] << endl;
        }
    }
}
