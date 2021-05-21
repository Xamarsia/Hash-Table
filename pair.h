#ifndef __PAIR_H__
#define __PAIR_H__

#include <iostream>

struct Pair
{
    std::string p_key;
    std::string p_value;
    Pair();

    Pair(std::string key, std::string value);
};

#endif