#include <iostream>
#include <random>
#include <algorithm>

#include "random_generator_lib.h"

/**
 * @brief generate random integer(int)
 *
 * @param left, right the generated number will be in range [left, right] inclusive
 * @return int
 */
int random32(int left, int right)
{
    if (left > right)
    {
        std::cerr << "Exception: random32 parameters is invalid\n";
        throw;
    }
    return rnd_gen() % (right - left + 1) + left;
}

/**
 * @brief generate random integer(long long)
 *
 * @param left, right the generated number will be in range [left, right] inclusive
 * @return long long
 */
long long random64(long long left, long long right)
{
    if (left > right)
    {
        std::cerr << "Exception: random64 parameters is invalid\n";
        throw;
    }
    return (1ll * rnd_gen() * rnd_gen()) % (right - left + 1) + left;
}

/**
 * @brief the next four functions shuffle array or vector of int or long long in O(size)
 *
 * @param arr, vec the given container of data type int or long long
 * @param size size of container
 * @param left, right optional parameters if given will shuffle the range [left:rigth] (0-indexed)
 *                    otherwise will shuffle the whole container
 */
void shuffle_rnd(int *arr, int size, int left = -1, int right = -1)
{
    if (!~left)
        left = 0;
    if (!~right)
        right = size;
    std::shuffle(arr + left, arr + right, rnd_gen);
}
void shuffle_rnd(long long *arr, int size, int left = -1, int right = -1)
{
    if (!~left)
        left = 0;
    if (!~right)
        right = size;
    std::shuffle(arr + left, arr + right, rnd_gen);
}
void shuffle_rnd(std::vector<int> &vec, int left = -1, int right = -1)
{
    if (!~left)
        left = 0;
    if (!~right)
        right = vec.size();
    std::shuffle(vec.begin() + left, vec.begin() + right, rnd_gen);
}
void shuffle_rnd(std::vector<long long> &vec, int left = -1, int right = -1)
{
    if (!~left)
        left = 0;
    if (!~right)
        right = vec.size();
    std::shuffle(vec.begin() + left, vec.begin() + right, rnd_gen);
}

// random number of n digit as string in O(n)
/**
 * @brief generate random number of (length) digit in O(length)
 *
 * @param length
 * @return std::string
 */
std::string random_huge_number(int length)
{
    std::string str(length, ' ');
    for (int i = 0; i < length; ++i)
        str[i] = '0' + random32(!i, 9);

    return str;
}

/**
 * @brief generate random string or lower case characters in O(length)
 *
 * @param length
 * @return std::string
 */
std::string random_string(int length)
{
    std::string str(length, ' ');
    for (int i = 0; i < length; ++i)
        str[i] = 'a' + random32(0, 26);

    return str;
}

/**
 * @brief generate random tree in O(number_of_nodes)
 *
 * @param number_of_nodes
 * @param root optoinal paramater. if it is not given the root will be random
 * @return std::vector<std::pair<int, int>>. (number_of_nodes-1) edge
 */
std::vector<std::pair<int, int>> random_tree(int number_of_nodes, int root = -1)
{
    if (!~root)
        root = random32(1, number_of_nodes);

    std::vector<std::pair<int, int>> edges;
    std::vector<int> nodes = {root};
    for (int node = 1; node <= number_of_nodes; ++node)
        if (node != root)
        {
            int random_node = nodes[random32(0, nodes.size() - 1)];
            edges.push_back({random_node, node});
            nodes.emplace_back(node);
        }

    return edges;
}