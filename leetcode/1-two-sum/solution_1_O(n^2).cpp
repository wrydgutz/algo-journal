// Problem:
// https://leetcode.com/problems/two-sum/
//
// Approach:
// Brute Force O(n^2)
//
// Compare every number with every other number
// until a pair that matches the target sum is found.
//
// Time Complexity: O(n^2)
// Space Complexity: O(1)
//
//
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // Go through every possible pair
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size() && j != i; j++) {
                
                // Check if the pair adds up to the target
                if (nums[i] + nums[j] == target) {
                    return { i, j };
                }
            }
        }

        return {};
    }
};