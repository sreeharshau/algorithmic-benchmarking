#include "selection_sort.h"

uint32_t selection_sort(uint32_t *sort_array){
    /*
        Selection sort function. Takes an array as input and sorts it. The array to be sorted is passed as a pointer.

        @param: sort_array: Array of <uint32_t> to be sorted
        @return: total_passes: Number of selection sort passes required to sort the array. 
            Usually returns sort_size.
    */

   uint32_t temp_storage = 0;

   // Core selection sort flow
   for(uint32_t i = 0; i < sort_size; i++){
       uint32_t min_idx = i;
       uint32_t min_elem = sort_array[i];
       
       // Find minimum element in unsorted piece of array
       for(uint32_t j = i; j < sort_size; j++){
           if(sort_array[j] < min_elem){
               min_idx = j;
               min_elem = sort_array[j];
           }
       }

       // Swap minimum element with sort_array[i]
       temp_storage = sort_array[i];
       sort_array[i] = min_elem;
       sort_array[min_idx] = temp_storage;        
   }

   // Selection sort always takes <sort_size> passes to sort array
   return sort_size;
}