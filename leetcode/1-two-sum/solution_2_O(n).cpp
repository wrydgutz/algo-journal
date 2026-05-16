// Problem:
// https://leetcode.com/problems/two-sum/
//
// Approach:
// Use a hash table to keep track of indices.
//
// Time Complexity: O(n)
// Space Complexity: O(n)
//
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // Use a hash table. O(1) degrading to O(n) only during collisions.
        // Key: Value of nums at index
        // Value: Index of nums
        unordered_map<int, int> umap;
        
        // In one pass, go through each array value.
        for (int i = 0; i < nums.size(); i++) {

            // Find the complement.
            const int complement = target - nums[i];

            // Check in the table. If the complement is in there, then return the pair of indices.
            if (umap.find(complement) != umap.end() && umap[complement] != i) {
                return { umap[complement], i };
            }

            // If the complement was not in there, store the index.
            umap[nums[i]] = i;
        }

        return {};
    }
};