#include <vector>
#include <cassert>
#include <iostream>

#include "insertion_sort.h"

void test_unsorted_array() {

    std::vector<int> nums = {5, 2, 4, 6, 1, 3};
    insertion_sort(nums);
    assert((nums == std::vector<int>{1 ,2, 3, 4, 5, 6}));
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
    test_empty_array();
    test_single_element();

    std::cout << "All tests passed.\n";
}
