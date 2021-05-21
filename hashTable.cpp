#include <iostream>
#include "pair.h"
#include "hashTable.h"

unsigned int HashTable::hash(const std::string &strKey)
{
    unsigned int hash = 5381;
    int num;

    for (const auto &num : strKey)
    {
        hash = ((hash << 5) + hash) + num;
    }
    return hash;
}

HashTable::HashTable() : m_capacity(3), m_count(0)
{
    array = new Pair[m_capacity];
}

unsigned int HashTable::index(const std::string &strKey)
{
    int i = hash(strKey) % m_capacity; // i = index
    if (array[i].p_key == "" || array[i].p_key == strKey)
    {
        return i;
    }
    else
    {
        unsigned int newIndex = i;
        int counter = 0;
        while (array[newIndex].p_key != "" && array[i].p_key != strKey)
        {
            ++newIndex;
            if (newIndex == m_capacity)
            {
                newIndex = 0;
            }
            if (counter == m_capacity)
            {
                return -1;
            }
            ++counter;
        }
        return newIndex;
    }
}

void HashTable::addPair(std::string key, std::string value) //A[key]=data, здесь key – ключ, data – некоторые данные
{
    (*this)[key] = value;
}

int HashTable::print()
{
    for (int i = 0; i < m_capacity; ++i)
    {
        std::cout << array[i].p_key << " : " << array[i].p_value << std::endl;
    }
    return 0;
}

std::string &HashTable::operator[](std::string key)
{
    if ((m_count * 100.0) / m_capacity > 40.0)
    {
        resize();
    }

    auto i = index(key);

    if (array[i].p_key == "")
    {
        array[i].p_key = key;
        ++m_count;
        return array[i].p_value;
    }
    return array[i].p_value; // if (array[index(key)].p_key == key)
}

void HashTable::deletePair(const std::string &key)
{
    if (array[index(key)].p_key == key)
    {
        array[index(key)] = Pair("", "");
        --m_count;
    }
}

void HashTable::resize()
{
    int oldCapacity = m_capacity;
    m_capacity = m_capacity * 2;
    Pair *newArray;
    newArray = new Pair[m_capacity];
    for (int i = 0; i < oldCapacity; ++i)
    {
        newArray[index(array[i].p_key)] = Pair(array[i].p_key, array[i].p_value);
    }
    delete[] array;
    array = newArray;
}
