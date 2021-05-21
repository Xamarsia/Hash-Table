#include "pair.h"
#include "hashTable.h"
#include <iostream>

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