# Random-genererator

It is a library written in `c++` provides some functions generate random numbers, strings, trees, ... and some useful tools see all [provided functions](#provided-functions).

-   [How to use](#How-to-use)
-   [Provided functions](#provided-functions)
    -   [random seed](#1-random-seed)
    -   [random number (int)](#2-random-number-int)
    -   [random number (long long)](#3-random-number-long-long)
    -   [random huge number](#4-random-huge-number)
    -   [random string](#5-random-string)
    -   [pick random item form vector](#6-pick-random-item-form-vector)
    -   [pick random item form vector and remove it](#7-pick-random-item-form-vector-and-remove-it)
    -   [random_tree](#8-random_tree)
    -   [random_permutation](#9-random-permutation)
    -   [random_binary_string](#10-random-binary-string)
    -   [random_flag](#11-random-flag)
    -   [random_vowel](#12-Random-Vowel)
-   [Contribute](#contribute)

## How to use

1- download the library besides your `cpp` file.

-   `git clone git@github.com:Omar622/Random-generator.git`

2 - include the header file of the library `random_generator_lib.h` in the cpp file you are working on.

-   `#include "random_generator_lib.h"`

see the [include example.](https://github.com/Omar622/Random-generator/blob/main/examples/include/include.cpp)

## provided functions

Here are the docs of all functions.

### 1. random seed

-   author: [Omar Abdelghani](https://www.linkedin.com/in/omar-abdelghani-596062191/)

-   brief
    -   It is a random number generator (RNG) `mt19937`. [see more about mt19937](https://cplusplus.com/reference/random/mt19937/)
-   function name
    -   `random_seed`
-   params
    -   no parameters
-   return data type
    -   `(unsigned int)` 32-bit unsigned integer
-   complexity
    -   `O(1)`
-   see [random_seed example](https://github.com/Omar622/Random-generator/blob/main/examples/random_seed.cpp)

### 2. random number (int)

-   author: [Omar Abdelghani](https://www.linkedin.com/in/omar-abdelghani-596062191/)
-   updated by: [ALi Ibrahim](https://github.com/Ali-Ibrahim137)

-   brief
    -   return random integer number in given range [low, high].
    -   the chosen number is uniformly distributed.
    -   using [random seed](#1-random-seed).
    -   if the given low greater than the given high, function will throw error `(random32 parameters is invalid)`.
-   function name
    -   `random32`
-   params
    -   low `(int)`
    -   high `(int)`
-   return data type
    -   `(int)`
-   complexity
    -   `O(1)`
-   see [random32 example](https://github.com/Omar622/Random-generator/blob/main/examples/random32.cpp)

### 3. random number (long long)

-   author: [Omar Abdelghani](https://www.linkedin.com/in/omar-abdelghani-596062191/)
-   updated by: [ALi Ibrahim](https://github.com/Ali-Ibrahim137)

-   brief
    -   return random long long number in given range [low, high].
    -   the chosen number is uniformly distributed.
    -   using [random seed](#1-random-seed).
    -   if the given low greater than the given high, function will throw error `(random64 parameters is invalid)`.
-   function name
    -   `random64`
-   params
    -   low `(long long)`
    -   high `(long long)`
-   return data type
    -   `(long long)`
-   complexity
    -   `O(1)`
-   see [random64 example](https://github.com/Omar622/Random-generator/blob/main/examples/random64.cpp)

### 4. random huge number

-   author: [Omar Abdelghani](https://www.linkedin.com/in/omar-abdelghani-596062191/)

-   brief
    -   return very big valid random number as string.
    -   every chosen digit is uniformly distributed using [random seed](#1-random-seed).
-   function name
    -   `random_huge_number`
-   params
    -   length `(int)`
-   return data type
    -   `(string)`
-   complexity
    -   `O(1)`
-   see [random_huge_number example](https://github.com/Omar622/Random-generator/blob/main/examples/random_huge_number.cpp)

### 5. random string

-   author: [Omar Abdelghani](https://www.linkedin.com/in/omar-abdelghani-596062191/)

-   brief
    -   return random string consists of only lower case letters.
    -   every chosen character is uniformly distributed using [random seed](#1-random-seed).
-   function name
    -   `random_string`
-   params
    -   length `(int)`
-   return data type
    -   `(string)`
-   complexity
    -   `O(length)`
-   see [random_string example](https://github.com/Omar622/Random-generator/blob/main/examples/random_string.cpp)

### 6. pick random item form vector

-   author: [Omar Abdelghani](https://www.linkedin.com/in/omar-abdelghani-596062191/)

-   brief
    -   return random item from the given vector.
    -   using [random seed](#1-random-seed).
-   function name
    -   `pick_random`
-   params
    -   `vector` of any data type
-   return data type
    -   same as vector data type
-   complexity
    -   `O(1)`
-   see [pick_random example](https://github.com/Omar622/Random-generator/blob/main/examples/pick_random/)

### 7. pick random item form vector and remove it

-   author: [Omar Abdelghani](https://www.linkedin.com/in/omar-abdelghani-596062191/)

-   brief
    -   return random item from the given vector then remove the chosen item.
    -   using [random seed](#1-random-seed).
    -   the order of the given vector will be changed after using this function.
-   function name
    -   `pick_random_and_remove`
-   params
    -   `vector` of any data type
-   return data type
    -   same as vector data type
-   complexity
    -   `O(1)`
-   see [pick_random_and_remove example](https://github.com/Omar622/Random-generator/blob/main/examples/pick_random_and_remove/)

### 8. random_tree

-   author: [Omar Abdelghani](https://www.linkedin.com/in/omar-abdelghani-596062191/)
-   updated by: [Eddard](https://www.linkedin.com/in/eddard/)

-   brief
    -   return random tree given number of nodes, root and height.
    -   every node will have a unique id from 1 to number of nodes.
    -   in case not given any parameter they will be chosen randomly.
    -   in case given not valid root or height, the function will choose the nearest valid root and height.
-   function name
    -   `random_tree`
-   params
    -   number of nodes `(int)`.
        -   in case not given it will be chosen randomly in range [1, 100000] using [random number (int)](#2-random-number-int).
    -   root id `(int)`.
        -   expected an integer in range [1, number of nodes parameter].
        -   in case not given it will be chosen randomly in range [1, number of nodes] using [random number (int)](#2-random-number-int).
        -   in case given not valid root, the function will choose the nearest valid root id.
    -   height `(int)`.
        -   expected an integer in range [0, number of nodes parameter - 1].
        -   in case not given it will be chosen randomly in range [0, number of nodes parameter - 1] using [random number (int)](#2-random-number-int).
        -   in case given not valid height, the function will choose the nearest valid height.
-   return data type
    -   `vector<pair<int, int>>`
        -   the size of the vector will be equal to (number of nodes - 1).
        -   each pair in the vector represents a directed edge in the tree. `(pair.first -> pair.second)`
-   complexity
    -   `O(number of nodes)`
-   see [random_tree example](https://github.com/Omar622/Random-generator/blob/main/examples/random_tree/)

### 9. Random Permutation

-   author: [Khaled Hegazy](https://www.linkedin.com/in/khaled-hegazy-61b49a1a9/)

-   brief
    -   return random permutation consists of unique positive integers.
-   function name
    -   `random_permutation`
-   params
    -   length `(int)`
-   return data type
    -   `vector<int>`
-   Complexity
    -   `O(length)`
-   see [random_permutation example](https://github.com/Omar622/Random-generator/blob/main/examples/random_permutation.cpp)

### 10. Random Binary String

-   author: [Khaled Hegazy](https://www.linkedin.com/in/khaled-hegazy-61b49a1a9/)

-   brief
    -   return random binary string conists of binary digits `0`,`1`.
-   function name
    -   `random_binary_string`
-   params
    -   length `(int)`
-   return data type
    -   `string`
-   Complexity
    -   `O(length)`
-   see [random_binary_string example](https://github.com/Omar622/Random-generator/blob/main/examples/random_binary_string.cpp)

### 11. Random Flag

-   author: [Khaled Hegazy](https://www.linkedin.com/in/khaled-hegazy-61b49a1a9/)

-   brief
    -   return random boolean flag with value `True`,`False`.
-   function name
    -   `random_flag`
-   params
    -   `none`
-   return data type
    -   `bool`
-   Complexity
    -   `O(1)`
-   see [random_flag example](https://github.com/Omar622/Random-generator/blob/main/examples/random_flag.cpp) 

### 12. Random Vowel  

-  author: [Sree Sayi Hrudai](https://www.linkedin.com/in/sayihrudai/) 

-  breif 
   -  returns random vowel with values ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'].
-  function name 
   - `random_vowel_lower`
   - `random_vowel_upper`
- params 
   - `none` 
- return data type 
   - `char` 
- Complexity 
   - `O(1)` 
- see [random_vowel example](https://github.com/hrudai2002/Random-generator/blob/main/examples/random_vowel.cpp)

## Contribute

If you want to contribute 🤝 to this library, you're always welcome!
you can contribute by implementing random function generating something doesn't exist in the library and this function is almost needed.

### Rules of contribution

1. your function
    - works correctly.
    - add comments in your code and the brief comment above your function.
    - the brief comment must be in the same format as other briefs.
    - the function is almost needed.
2. add examples of using function in the [examples](https://github.com/Omar622/Random-generator/tree/main/examples) directory.
3. add docs about this function in [README](https://github.com/Omar622/Random-generator#readme) file in the same format. (do not forget to add your name and linkedin or github link 😀)
