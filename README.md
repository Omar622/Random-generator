# Random-genererator
prewritten functions generate random numbers, arrays, trees, ...

## Intro
There is some helpful pre written functions:
  1. Random number in range.
  2. Shuffle array or vector.
  3. Large random number as string.
  4. Random string.
  5. Random tree.

Below you will see how to use them.

## Details
  1. Random number in range.
     * Return type: integer
     * Function name: `rnd`
     * Parameters: left (integer), right (integer)
  2. Shuffle array or vector.
     * shuffle array
         * Return type: void
         * Function name: `shuffle_rnd`
         * Parameters: array pointer, size (int), left (int)(optional=0), right (int)(optional=size)
     * shuffle vector
         * Return type: void
         * Function name: `shuffle_rnd`
         * Parameters: array pointer, left (int)(optional=0), right (int)(optional=size)
  3. Random number in range.
     * Return type: long long
     * Function name: `rndll`
     * Parameters: left (long long), right (long long)
  4. Large random number as string.
     * Return type: string
     * Function name: `random_huge_number`
     * Parameters: lenght (integer)
  5. Random string.
     * Return type: string
     * Function name: `random_string`
     * Parameters: lenght (integer)
  6. Random tree.
     * Return type: vector<pair<int, int>>
     * Function name: `random_tree`
     * Parameters: number of nodes (integer), root (integer)
     * More details:
       * Nodes are numbered 1, 2, 3, ... .
       * Return (number of nodes - 1) edges.
       * Edge between u, v is represented as a pair(u, v)
