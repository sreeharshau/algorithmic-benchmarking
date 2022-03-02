#include "bubble_sort.h"

uint32_t bubble_sort(uint32_t *sort_array){
    /*
        Bubble sort function. Takes an array as input and sorts it. The array to be sorted is passed as a pointer.

        @param: sort_array: Array of <uint32_t> to be sorted
        @return: total_passes: Number of bubble sort passes required to sort the array
    */

    uint32_t temp_storage = 0;

    uint32_t total_passes = 0;

    // Core bubble sort flow
    for (total_passes; total_passes < sort_size; total_passes++){
        bool swapped_any = false;
    
        for(int j = 0; j < sort_size - total_passes - 1; j++){

            // Check for misaligned elements and swap them if found
            if(sort_array[j] > sort_array[j+1]){
                temp_storage = sort_array[j];
                sort_array[j] = sort_array[j+1];
                sort_array[j+1] = temp_storage;

                swapped_any = true;
            }
        }

        // If no swaps in this pass, the array is already sorted
        if(swapped_any == false)
            break;

        // std::cout << "Array after pass: " << total_passes << std::endl;
        // print_array(sort_array);
    }
    
    return total_passes;
}