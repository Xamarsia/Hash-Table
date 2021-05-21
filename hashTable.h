#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__
#include "pair.h"
#include <iostream>

class HashTable
{
private:
    int m_capacity; // длина массива;
    int m_count;    // Количество занятих элементов:
    Pair *array;
    unsigned int hash(const std::string &strKey);

public:
    HashTable();

    unsigned int index(const std::string &strKey);

    void addPair(std::string key, std::string value); //A[key]=data, здесь key – ключ, data – некоторые данные

    int print();

    std::string &operator[](std::string key);

    void deletePair(const std::string &key);

    void resize();
};

#endif