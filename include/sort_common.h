#ifndef SORT_COMMON_
#define SORT_COMMON_

#include <cstdint>

#include "constants.h"

// Sort utility functions

void setup_sort_base();
uint32_t *setup_sort_array_copy();

bool verify_sort(uint32_t *sort_array_copy);
void print_array(uint32_t *array_copy);


void cleanup_sort_copy(uint32_t *sort_array_copy);
void cleanup_sort_base();


// Sort global variables

extern uint32_t *sort_array_base;
extern uint32_t sort_size;

#endif
