#include "pair.h"
#include <iostream>

Pair::Pair() : p_key(""), p_value("") {}

Pair::Pair(std::string key, std::string value) : p_key(key), p_value(value) {}