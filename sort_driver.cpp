#include "sort_common.h"
#include "bubble_sort.h"
#include "insertion_sort.h"
#include "selection_sort.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>


void sort_driver_common(std::string outfile_name, uint32_t (*sort_func)(uint32_t *)){
    /*
        Driver function for all sorts. Runs multiple sort runs, verifies array sort status and calculates time averages.
        @param: outfile_name: Name of the output file to store run results to within the directory "./results/"
        @param: sort_func: 
            Function pointer to a function which takes a uint32_t * array as a parameter and returns a uint32_t value
            Note: The driver assumes all implemented sorts follow this format.
        @return: None
    */

    // Setup vectors to store pass counts and times for each run
    std::vector<uint32_t> pass_vector;
    std::vector<double> time_vector;

    unsigned int failed_sorts = 0;

    std::cout << "Running sort with output file: " << outfile_name << std::endl;

    // Run sort for NUM_SORT_RUNS times
    for (int i = 0; i < NUM_SORT_RUNS; i++){

        std::cout << "\tRunning sort iteration: " << i << std::endl;

        // Setup copy of base array to sort
        uint32_t *sort_array_copy = setup_sort_array_copy();
        
        auto start = std::chrono::high_resolution_clock::now();

        // Sort the array
        uint32_t total_passes = sort_func(sort_array_copy);

        auto end = std::chrono::high_resolution_clock::now();

        // Verify that the array was sorted correctly
        bool array_sorted = verify_sort(sort_array_copy);

        if(array_sorted == false){
            // Handle sort failures by alerting user, excluding run results from averages
            std::cout << "Array sorting failed for insertion sort on iteration " << i << std::endl;
            failed_sorts++;
        }
        else{
            // Push run results to vectors
            std::chrono::duration<double> elapsed = end - start;
            time_vector.push_back(elapsed.count());

            pass_vector.push_back(total_passes);
        }

        // std::cout << "Sorting Passes: " << total_passes << std::endl;

        // Clean up array copy
        cleanup_sort_copy(sort_array_copy);
    }

    // Write results to output file
    std::ofstream sort_out_file;
    sort_out_file.open(std::string("results/").append(outfile_name));

    sort_out_file << "Iteration,Time,Passes" << std::endl;
    
    for(std::size_t i = 0; i < time_vector.size(); ++i) {
        sort_out_file << i << "," << time_vector[i] << "," << pass_vector[i] << std::endl;
    }
    
    sort_out_file.close();   
}

int main(int argc, std::string argv[]){
    /*
        Primary function for benchmarking framework
        @param: None
        @return: None
    */

    // Create the base array for sorting
    setup_sort_base();

    

    // Call relevant sort drivers
    // sort_driver_common("bubble_sort.csv", bubble_sort);

    // sort_driver_common("insertion_sort.csv", insertion_sort);

    sort_driver_common("selection_sort.csv", selection_sort);

    // Cleanup memory allocated for base array
    cleanup_sort_base();

    return 0;
}