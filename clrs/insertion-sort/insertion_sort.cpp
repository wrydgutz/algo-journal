#include "insertion_sort.h"

#include <vector>

// Based on the INSERTION-SORT algorithm from
// Introduction to Algorithms (CLRS),
// Chapter 2.1: Insertion Sort.
void insertion_sort(std::vector<int>& nums) {

    // Traverse nums but starting from the 2nd number.
    // The 1st element is already considered sorted by itself.
    for (int i = 1; i < nums.size(); i++) {

        // Keep track of the current number.
        const int key = nums[i];

        // Traverse backwards from the current element's previous index,
        // shifting larger elements one position to the right
        // until the correct insertion position for key is found.
        int j = i - 1;
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j--;
        }

        // Insert the key into its correct sorted position.
        nums[j + 1] = key;
    }
}
