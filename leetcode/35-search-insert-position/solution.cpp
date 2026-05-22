// Problem:
// https://leetcode.com/problems/search-insert-position
//
// Approach:
//
// Do a binary search for the target.
//
// Time Complexity: O(log(n))
// Since half of the remaining search range is discarded every iteration.
//
// Space Complexity: O(1)
// Since constant memory is used throughout the algorithm.
//
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

    	// Skip if empty.
        if (nums.empty()) return 0;

        // Simplify if there's just one.
        if (nums.size() == 1) return target > nums[0] ? 1 : 0;

        // Left boundary of the current search range.
        int left = 0;

        // Right boundary of the current search range.
        // Note: Initialized to nums.size(), not nums.size() - 1.
        // 		 Allows insertion at the very end of the array.
        int right = nums.size();

        // Continue while there is still a valid search range.
        // Example: left = 0 (inclusive), right = 4 (exclusive)
        while (left < right) {

            // Find the middle index of the current range.
            int mid = left + (right - left) / 2;

            // If the target is greater than nums[mid], then the 
            // insertion position must be to the right of mid.
            // Example:
            //    nums = [1,3,5,6]
            //    target = 5
            //    mid points to 3
            //
            // Since 5 > 3, discard the left half including mid.
            if (target > nums[mid]) {

                // Move left boundary after mid.
                left = mid + 1;
            } else { // target <= nums[mid]

                // Shrink the range from the right.
                right = mid;
            }
        }

        // At this point: left == right
        // This is the correct insertion index.
        // It is also the target's index if the target exists.
        return left;
    }
};