#include <chrono>
#include <vector>
#include <iostream>
#include <fstream>

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

void bubble_driver(){
    /*
        Driver function for bubble sort. Runs multiple sort runs, verifies array sort status and calculates time averages.
        @param: None
        @return: None
    */

    std::vector<uint32_t> pass_vector;
    std::vector<double> time_vector;

    unsigned int failed_sorts = 0;

    for (int i = 0; i < NUM_SORT_RUNS; i++){

        std::cout << "\tRunning bubble sort iteration: " << i << std::endl;

        // Setup copy of base array to sort
        uint32_t *sort_array_copy = setup_sort_array_copy();
        
        auto start = std::chrono::high_resolution_clock::now();

        // Sort the array
        uint32_t total_passes = bubble_sort(sort_array_copy);

        auto end = std::chrono::high_resolution_clock::now();

        // Verify that the array was sorted correctly
        bool array_sorted = verify_sort(sort_array_copy);

        if(array_sorted == false){
            std::cout << "Array sorting failed for bubble sort on iteration " << i << std::endl;
            failed_sorts++;
        }
        else{
            std::chrono::duration<double> elapsed = end - start;
            time_vector.push_back(elapsed.count());

            pass_vector.push_back(total_passes);
        }

        // std::cout << "Sorting Passes: " << total_passes << std::endl;

        // Clean up array copy
        cleanup_sort_copy(sort_array_copy);
    }

    std::ofstream bubble_sort_file;
    bubble_sort_file.open("results/bubble_sort.csv");

    bubble_sort_file << "Iteration,Time,Passes" << std::endl;
    
    for(std::size_t i = 0; i < time_vector.size(); ++i) {
        bubble_sort_file << i << "," << time_vector[i] << "," << pass_vector[i] << std::endl;
    }
    
    bubble_sort_file.close();   
}

