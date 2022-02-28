#include "sort_common.h"
#include "bubble_sort.h"

#include <iostream>
#include <string>


int main(int argc, std::string argv[]){
    /*
        Primary driver function for all sort functions
        @param: None
        @return: None
    */

    // Create the base array for sorting
    setup_sort_base();

    // Call relevant sort driver
    bubble_driver();

    // Cleanup memory allocated for base array
    cleanup_sort_base();

    return 0;
}