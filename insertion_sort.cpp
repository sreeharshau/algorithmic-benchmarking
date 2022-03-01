#include <chrono>
#include <vector>
#include <iostream>
#include <fstream>

#include "insertion_sort.h"

uint32_t insertion_sort(uint32_t *sort_array){

    uint32_t temp_storage = 0;
    uint32_t chosen_element = 0;

    for(int i = 1; i < sort_size; i++){
        chosen_element = sort_array[i];

        for(int j = i-1; j >= 0; j--)
            if(sort_array[j] >= chosen_element)
                sort_array[j+1] = sort_array[j];
            else{
                sort_array[j+1] = chosen_element;
                break;
            }
    }

    return sort_size;
}

