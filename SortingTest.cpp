/*
 Author: Kasey Harvey
 Course: CSCI-235
 Assignment: SortingTest.cpp, Project 4
 compliedwith = g++ -Wall -Wpedantic -Werror -g SortingTest.cpp -o Sort -std=c++11
 */

#include "SortingTest.hpp"
#include <algorithm>
using namespace std;

/*****************************************************************/
/********************* SORTING FUNCTIONS *************************/
/*****************************************************************/

/**
 @post Sorts an array in ascending order using the selection sort algorithm.
 @param a the array to sort
 @param size the number of elements in a
 */
void selectionSort(int a[], size_t size){

    for (int i = 0; i < size-1; i++) {
        int min = i;
        for (int j = i+1 ; j < size; j++) {
            if (a[j] < a[min]) min = j;

        }
        if (min != i) {
            swap(a[i],a[min]);
        }
    }
    
}

/**
 @post Sorts an array in ascending order using insertion sort.
 @param a the array to sort
 @param size of the array
 */
void insertionSort(int a[], size_t size){

    for ( int i = 0; i<size ; i++){
        int index = i;
        int value = a[i];
//        if (a[i] < a[i-1]) {
//            swap(a[i], a[0]);
//        }
        while (index > -1 && a[index-1] > value) {
            a[index]= index-1;
            index = index-1;
        }
    }
}

///**
// @post Sorts the elements in a range of a array.
// @param a the array with the elements to sort
// @param from the first position in the range to sort
// @param to the last position in the range to sort (included)
// */
//void mergeSort(int a[], int from, int to);
//
//
//
/*********************************************************************/
/****************** ARRAY POPULATING FUNCTIONS ***********************/
/*********************************************************************/


/**
 @post Populates values with randomly generated numbers in range size
 @param values the array to populate
 @param size of the array to be populated
 */
void generateRandomArray(int values[], size_t size){
    for (int i = 0; i < size ; i++) {
        values[i] = rand() % size;
    }
}

/**
 @post Populates values with integers in ascending order
 @param values the array to populate
 @param size of the array to be populated
 */
void generateAscendingArray(int values[], size_t size){
    generateRandomArray(values, size);
    selectionSort(values,size);
}

/**
 @post Populates values with integers in descending order
 @param values the array to populate
 @param size of the array to be populated
 */
void generateDescendingArray(int values[], size_t size){
    generateRandomArray(values, size);
    
    // swap the list from start to end
    for (int i = 0; i < size-1; i++) {
        int max = i;
        for (int j = i+1 ; j < size; j++) {
            if (values[j] > values[max]) max = j;
            
        }
        if (max != i) {
            std::swap(values[i],values[max]);
        }
    }
}

/**
 @post Populates values with integers in ascending order except for the last 10 that are randomly generated
 @param values the array to populate
 @param size of the array to be populated
 */
void generateLastTenRandomArray(int values[], size_t size){
    generateRandomArray(values, size);
    selectionSort(values,size - 10);
}

/**
 @post Populates values with integers in randomly generated in range size/10
 @param values the array to populate
 @param size of the array to be populated
 */
void generateFewRandomArray(int values[], size_t size){
     generateRandomArray(values, size/10);
 }



/*****************************************************************/
/****************** RUNTIME TEST FUNCTIONS ***********************/
/*****************************************************************/


/**
 @post Sorts values in ascending order and averages its runtime over 10 runs
 @param sortingFunction the function used to sort the array
 @param values the array to sort
 @param size of the array to sort
 @return the average runtime in microseconds
 */
double sortTest(void (*sortingFunction)(int a[], size_t size), int values[], size_t size){
    double runtime_sum= 0;
    for (int i = 0; i < 10; i++) {
        auto start_time = high_resolution_clock().now();
        sortingFunction(values, size);
        auto end_time = high_resolution_clock().now();
        
        duration<float, std::micro> runt_time = duration_cast<microseconds>(end_time - start_time);
        
        runtime_sum += runt_time.count();
    }
    
    return runtime_sum/10;
}

///**
// @post Sorts values in ascending order using mergeSort and averages its runtime over 10 runs
// @param values the array to sort
// @param size of the array to sort
// @return the average runtime in microseconds
// */
//double mergeSortTest(int values[], size_t size);
//
//
//#endif /* SortingTests_hpp */
