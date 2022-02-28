#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cstdlib>

#include "sort_common.h"

// Global variables useful for all sort functions
uint32_t *sort_array_base;
uint32_t sort_size = SORT_ARRAY_SIZE;

void setup_sort_base(){
    /*
        Creates a base array of size SORT_ARRAY_SIZE and fills it with random numbers from 0 to MAX_SORT_VALUE. 
        Assigns this array to the global sort_array_base pointer.

        @param: None
        @return: None
    */
    
    // Seed random generator
    srand(time(0));

    sort_array_base = new uint32_t[sort_size];

    // Fill array with random values
    for(int i = 0; i < sort_size; i++){
        sort_array_base[i] = (rand() % MAX_SORT_VALUE) + 1;
    }

    // std::cout << "Array Base:" << std::endl;
    // print_array(sort_array_base);
}

uint32_t *setup_sort_array_copy(){
    /*
        Creates a copy of the base array for use in sorting. 
        
        @param: None
        @return: sort_array_copy: A uint32_t array copy of sort_array_base
    */
    
    // Create a new array and copy over contents of base array
    uint32_t *sort_array_copy = new uint32_t[sort_size];

    for (int i = 0; i < sort_size; i++){
        sort_array_copy[i] = sort_array_base[i];
    }

    // std::cout << "Array Copy:" << std::endl;
    // print_array(sort_array_copy);

    return sort_array_copy;
}

bool verify_sort(uint32_t *sort_array_copy){
    /*
        Verifies if the contents of the provided array are sorted

        @param: sort_array_copy: Array to verify
        @return: bool: 
            true if the array has been sorted
            false otherwise
    */
    

    bool array_sorted = true;
    for(int i = 0; i < sort_size - 1; i++)
        if(sort_array_copy[i] > sort_array_copy[i+1])
            array_sorted = false;
    
    return array_sorted;
}

void cleanup_sort_copy(uint32_t *sort_array_copy){
    /*
        Cleanup array provided as a parameter. Useful for deleting copies of base array.
        
        @param: sort_array_copy: Array to free / delete.
        @return: None
    */
    
    delete sort_array_copy;
}

void cleanup_sort_base(){
    /*
        Cleanup memory allocated for base array
        
        @param: None
        @return: None
    */
    
    delete sort_array_base;
}

void print_array(uint32_t *array_copy){
    /*
        Print function useful for debugging. Prints the contents of the array on a single line with elements separated by spaces.

        @param: array_copy: Array to print passed as a pointer
        @return: None
    */

    for(int i = 0; i < sort_size; i++)
        std::cout << array_copy[i] << " ";
    
    std::cout << std::endl;
}