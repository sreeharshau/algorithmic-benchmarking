#include "insertion_sort.h"

uint32_t insertion_sort(uint32_t *sort_array){
 /*
        Insertion sort function. Takes an array as input and sorts it. The array to be sorted is passed as a pointer.

        @param: sort_array: Array of <uint32_t> to be sorted
        @return: total_passes: Number of insertion sort passes required to sort the array. Always equal to <sort_size>.
*/

    uint32_t temp_storage = 0;
    uint32_t chosen_element = 0;

    // Core insertion sort flow
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
    
    // Insertion sort always makes <sort_size> passes
    return sort_size;
}

