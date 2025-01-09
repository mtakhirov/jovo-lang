#ifndef __JOVO__BASE_H_
#define __JOVO__BASE_H_

#include <functional>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

template <typename T> using vector = std::vector<T>;

using str = std::string;
using str_vie = std::string_view;

// umap
template <typename Key, typename Value, typename Hash = std::hash<Key>>
using umap = std::unordered_map<Key, Value, Hash>;

// uset
template <typename Key, typename Hash = std::hash<Key>> using uset = std::unordered_set<Key, Hash>;

using std::pair;
using std::stack;

#endif // __JOVO__BASE_H_