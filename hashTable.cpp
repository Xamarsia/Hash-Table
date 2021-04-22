#include <iostream>
#include <string>

struct Pair
{
    std::string p_key;
    std::string p_value;
    Pair() : p_key(""), p_value("") {}

    Pair(std::string key, std::string value) : p_key(key), p_value(value) {}
};

class HashTable
{
private:
    int m_capacity; // длина массива;
    int m_count;    // Количество занятих элементов:
    Pair *array;
    unsigned int hash(const std::string &strKey)
    {
        unsigned int hash = 5381;
        int num;

        for (const auto &num : strKey)
        {
            hash = ((hash << 5) + hash) + num; /* hash * 33 + num */
        }

        return hash; // 274241819
    }

public:
    HashTable() : m_capacity(3), m_count(0)
    {
        array = new Pair[m_capacity];
    }

    unsigned int index(const std::string &strKey)
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

    void addPair(std::string key, std::string value) //A[key]=data, здесь key – ключ, data – некоторые данные
    {
        (*this)[key] = value;
    }

    int print()
    {
        for (int i = 0; i < m_capacity; ++i)
        {
            std::cout << array[i].p_key << " : " << array[i].p_value << std::endl;
        }
        return 0;
    }

    std::string &operator[](std::string key)
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

    void deletePair(const std::string &key)
    {
        if (array[index(key)].p_key == key)
        {
            array[index(key)] = Pair("", "");
            --m_count;
        }
    }

    void resize()
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
};

int main()
{
    std::cout << "**************************************************" << std::endl;
    HashTable test;
    test.print();
    std::cout << ".............................................." << std::endl;
    test.addPair("Фрукт", "Груша");
    std::cout << test["Фрукт"];
    test.print();
    test["Фрукт"] = "Яблоко";
    test.addPair("c", "c1");
    test.print();
    std::cout << ".............................................." << std::endl;
    test.print();
    std::cout << ".............................................." << std::endl;
    test.addPair("d", "d1");
    test.addPair("Фрукт", "Груша");
    test["a"] = "1a";
    std::cout << ".............................................." << std::endl;
    test.print();
}