//
// Created by MoNasr on 1/18/2023.
//
#include <iostream>

#include "../random_generator_lib.h"

int main()
{
    std::vector<int>vector_test= random_vector( 10 , 1 , 100 );
    for(auto child:vector_test)
        std::cout<<child<<' ';

    return 0;
}