#include <iostream>
#include <random>
#include <algorithm>

#include "random_generator_lib.h"

int rnd(int a, int b)
{
    if (a > b)
    {
        std::cerr << "Exception: rnd parameters is invalid\n";
        throw;
    }
    return mt() % (b - a + 1) + a;
}

long long rndll(long long a, long long b)
{
    if (a > b)
    {
        std::cerr << "Exception: rndll parameters is invalid\n";
        throw;
    }
    return (1ll * mt() * mt()) % (b - a + 1) + a;
}

void shuffle_rnd(int *arr, int n, int lft = -1, int rht = -1)
{
    if (!~lft)
        lft = 0;
    if (!~rht)
        rht = n;
    std::shuffle(arr + lft, arr + rht, mt);
}
void shuffle_rnd(long long *arr, int n, int lft = -1, int rht = -1)
{
    if (!~lft)
        lft = 0;
    if (!~rht)
        rht = n;
    std::shuffle(arr + lft, arr + rht, mt);
}
void shuffle_rnd(std::vector<int> &vec, int lft = -1, int rht = -1)
{
    if (!~lft)
        lft = 0;
    if (!~rht)
        rht = vec.size();
    std::shuffle(vec.begin() + lft, vec.begin() + rht, mt);
}
void shuffle_rnd(std::vector<long long> &vec, int lft = -1, int rht = -1)
{
    if (!~lft)
        lft = 0;
    if (!~rht)
        rht = vec.size();
    std::shuffle(vec.begin() + lft, vec.begin() + rht, mt);
}

// random number of n digit as string in O(n)
std::string random_huge_number(int n)
{
    std::string str(n, ' ');
    for (int i = 0; i < n; ++i)
        str[i] = '0' + rnd(0, 9);

    return str;
}

// random string of n digit in O(n)
std::string random_string(int n)
{
    std::string str(n, ' ');
    for (int i = 0; i < n; ++i)
        str[i] = 'a' + rnd(0, 26);

    return str;
}

// return 1-based random tree rooted at r (as n-1 edge in vector) in O(n)
std::vector<std::pair<int, int>> random_tree(int n, int r)
{
    std::vector<std::pair<int, int>> edges;
    std::vector<int> nodes = {r};
    int u = 1;
    while (u <= n)
    {
        if (u != r)
        {
            int v = nodes[rnd(0, nodes.size())];
            edges.push_back({u, v});
            nodes.emplace_back(u);
        }
        ++u;
    }
    return edges;
}