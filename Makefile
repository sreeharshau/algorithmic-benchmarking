INCLUDE_DIR=./include/

CC=g++
CFLAGS=-I$(INCLUDE_DIR)

sort_driver: sort_driver.cpp sort_common.cpp $(INCLUDE_DIR)/sort_common.h $(INCLUDE_DIR)/constants.h
	$(CC) sort_driver.cpp sort_common.cpp bubble_sort.cpp insertion_sort.cpp selection_sort.cpp -I$(INCLUDE_DIR) -o sort_driver.exe

clean: 
	rm -f *.o *.exe
