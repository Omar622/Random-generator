#include "random_generator_lib.h"

/**
 * @brief generate random integer(int)
 *
 * @param left, right the generated number will be in range [left, right] inclusive
 * @return int
 */
int random32(int left=INT_MIN, int right=INT_MAX)
{
    if (left > right)
        throw std::invalid_argument("random32 parameters is invalid");
    std::uniform_int_distribution<int> dist(left, right);
    return dist(random_seed);
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
        throw std::invalid_argument("random64 parameters is invalid");

    std::uniform_int_distribution<long long> dist(left, right);
    return dist(random_seed);
}

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
 * @param capital
 * @return std::string
 */
std::string random_string(int length , bool capital=false )
{
    if(capital)
    {
        std::string str(length, ' ');
        for (int i = 0; i < length; ++i)
            str[i] = 'A' + random32(0, 25);

        return str;
    }
    else
    {
        std::string str(length, ' ');
        for (int i = 0; i < length; ++i)
            str[i] = 'a' + random32(0, 25);

        return str;
    }
}

/**
 * @brief pick random item from vector of items
 *
 * @tparam T the data type of vector
 * @param vec the container
 * @return T the data type of vector is same as the returned data type
 */
template <typename T>
T pick_random(std::vector<T> &vec)
{
    if (vec.empty())
        throw std::invalid_argument("can not pick from empty vector");

    int index = random32(0, vec.size() - 1);
    return vec[index];
}

/**
 * @brief pick random item from vector of items then remove it from the vector
 *
 * @tparam T the data type of vector
 * @param vec the container
 * @return T the data type of vector is same as the returned data type
 */
template <typename T>
T pick_random_and_remove(std::vector<T> &vec)
{
    if (vec.empty())
        throw std::invalid_argument("can not pick from empty vector");

    int index = random32(0, vec.size() - 1);
    std::swap(vec[index], vec.back());
    T value = vec.back();
    vec.pop_back();

    return value;
}

/**
 * @brief generates random tree in O(number_of_nodes)
 *
 * @param number_of_nodes
 * @param root optional paramater. if it is not given the root will be random node
 * @param height optional paramater. if it is not given it will be random
 * and if it was incorrect it will be set to the nearest valid height
 * @return std::vector<std::pair<int, int>>. every pair represents an edge in the tree means that
 * pair.first have direct edge to pair.second. the vector will have size = number of nodes - 1
 */
std::vector<std::pair<int, int>> random_tree(int number_of_nodes = -1, int root = -1, int height = -1)
{
    if (!~number_of_nodes)
        number_of_nodes = random32(1, 100000);

    if (number_of_nodes <= 1)
        return {};

    // pick random root if not given or given and not valid
    if (root > number_of_nodes or root < 1)
        root = random32(1, number_of_nodes);

    // pick random height if not given
    if (!~height)
        height = random32(1, number_of_nodes - 1);
    // if height is too small set it to 1
    if (height < 1)
        height = 1;
    // if height is too tall set it to max
    if (height > number_of_nodes - 1)
        height = number_of_nodes - 1;

    std::vector<std::pair<int, int>> edges;
    int depth[number_of_nodes];
    std::vector<int> nodes_to_connect, disconnected_nodes(number_of_nodes);
    iota(disconnected_nodes.begin(), disconnected_nodes.end(), 1);

    depth[root-1] = 0;
    nodes_to_connect.emplace_back(root);
    for (int h = 1; h <= height; ++h)
    {
        int random_disconnected_node = pick_random_and_remove(disconnected_nodes);
        if (random_disconnected_node == root)
        {
            --h;
            continue;
        }

        if (edges.empty())
        {
            depth[random_disconnected_node-1] = 1 + depth[root-1];
            edges.push_back({root, random_disconnected_node});
        }
        else
        {
            depth[random_disconnected_node-1] = 1 + depth[edges.back().second-1];
            edges.push_back({edges.back().second, random_disconnected_node});
        }

        if (depth[random_disconnected_node-1] != height)
            nodes_to_connect.emplace_back(random_disconnected_node);
    }

    while (!disconnected_nodes.empty())
    {
        int random_disconnected_node = pick_random_and_remove(disconnected_nodes);
        if (random_disconnected_node == root)
            continue;
        int random_connected_node = pick_random(nodes_to_connect);

        depth[random_disconnected_node-1] = 1 + depth[random_connected_node-1];
        edges.push_back({random_connected_node, random_disconnected_node});

        if (depth[random_disconnected_node-1] != height)
            nodes_to_connect.emplace_back(random_disconnected_node);
    }

    std::shuffle(edges.begin(), edges.end(), random_seed);

    return edges;
}
/**
 * @brief generates a random edges of graph in O(length)
 *
 * @param number_of_edges
 * @param start
 * @param end
 * @param wighted
 *
 * @return std::vector<int>
 */
std::vector<std::vector<int>> random_edges(int number_of_edges, int start = 1, int end =1e9,bool wighted=false) {
    std::vector <std::vector<int>> result;
    while (number_of_edges--)
    {
        int first_node= random32(start,end);
        int second_node= random32(start,end);

        while (first_node==second_node)
        {
            second_node= random32(start,end);
        }
        if(wighted)
        {
            result.push_back({first_node,second_node, random32() });
        }
        else
        {
            result.push_back({ first_node ,second_node });
        }
    }
    return result;
}
/**
 * @brief generates a random permutation in O(length)
 *
 * @param length
 * @return std::vector<int>
 */
std::vector<int> random_permutation(int length)
{
    if (length < 0)
        throw std::invalid_argument("can not generate negative size for permutation");

    std::vector<int> vec(length);
    std::iota(vec.begin(), vec.end(), 1);

    std::vector<int> randomized_vec;
    while (length--)
        randomized_vec.push_back(pick_random_and_remove(vec));

    return randomized_vec;
}

/**
 * @brief generates a random binary string in O(length)
 *
 * @param length
 * @return std::string
 */
std::string random_binary_string(int length)
{
    if (length < 0)
        throw std::invalid_argument("can not generate negative size for string");

    std::string str;
    while (length--)
        str.push_back('0' + random32(0, 1));

    return str;
}
/*
 * @brief generates a random vector in O(length)
 *
 * @param length of vector
 * @param minimum value
 * @param maximum value
 *
 * @return vector
 */
std::vector<T> random_vector(T length,T minimum=INT_MIN,T maximum=INT_MAX)
{
    std::vector<T>result;
    while (length--)
    {
        result.push_back(random32(minimum,maximum));
    }
    return result;
}
