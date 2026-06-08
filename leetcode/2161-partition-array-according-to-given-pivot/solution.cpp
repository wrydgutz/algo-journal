// Problem:
// https://leetcode.com/problems/partition-array-according-to-given-pivot/
//
// Approach:
//
// Store elements smaller than the pivot and greater than the pivot
// in separate vectors, while counting elements equal to the pivot.
// Then combine smaller elements, pivot elements, and greater elements.
//
// Time Complexity: O(n)
// Since each element is processed once.
//
// Space Complexity: O(n)
// Since the extra vectors may store up to n elements.
//
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        vector<int> lower;
        vector<int> greater;
        int pivotCount = 0;

        for (const int n: nums) {
            if (n < pivot) {
                lower.push_back(n);
            } else if (n > pivot) {
                greater.push_back(n);
            } else {
                pivotCount++;
            }
        }
        
        lower.insert(lower.end(), pivotCount, pivot);
        lower.insert(lower.end(), greater.begin(), greater.end());
        return lower;
    }
};