#include <vector>
#include <cassert>
#include <iostream>

#include "insertion_sort.h"
#include "../helpers.h"

void test_unsorted_array() {

    std::vector<int> nums = {5, 2, 4, 6, 1, 3};
    insertion_sort(nums);
    assert((nums == std::vector<int>{1 ,2, 3, 4, 5, 6}));
}

void test_unsorted_array_2() {

    // Introduction to Algorithm
    // Exercise 2.1-1
    std::vector<int> nums = {31, 41, 59, 26, 41, 58};
    insertion_sort(nums);
    assert((nums == std::vector<int>{26 ,31, 41, 41, 58, 59}));
}

void test_unsorted_array_descending() {

    // Introduction to Algorithm
    // Exercise 2.1-3
    std::vector<int> nums = {5, 2, 4, 6, 1, 3};
    insertion_sort(nums, false);
    assert((nums == std::vector<int>{6, 5, 4, 3, 2, 1}));
}

void test_empty_array() {

    std::vector<int> nums = {};
    insertion_sort(nums);
    assert(nums.empty());
}

void test_single_element() {

    std::vector<int> nums = {1};
    insertion_sort(nums);
    assert((nums == std::vector<int>{1}));
}

void run_tests() {

    test_unsorted_array();
    test_unsorted_array_2();
    test_empty_array();
    test_single_element();

    std::cout << "All tests passed.\n";
}
