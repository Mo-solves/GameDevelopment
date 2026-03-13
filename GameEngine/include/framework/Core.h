#pragma once
#include <stdio.h>
#include <memory>
#include <map>
#include <unordered_map>

namespace gdev {
// Renaming data types
template<typename T>
using unique = std::unique_ptr<T>;

template<typename T>
using shared = std::shared_ptr<T>;

template<typename T>
using weak = std::weak_ptr<T>;

template<typename T>
using List = std::vector<T>;

// this is orders map based on keys using std::less with Pr
template<typename keyType, typename valType, typename Pr = std::less<keyType>>
using Map = std::map<keyType, valType, Pr>;

// this is unordered map
template<typename keyType, typename valType, typename hasher = std::hash<keyType>>
using Dictionary = std::unordered_map<keyType, valType, hasher>;

// Macro
#define LOG(M, ...) printf(M "\n", ##__VA_ARGS__)

}