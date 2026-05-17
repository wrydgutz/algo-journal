// Problem:
// https://leetcode.com/problems/median-of-two-sorted-arrays/
//
// Approach:
//
// Merge the second vector with the first, sort, then get the median.
//
// NOTE: On production code, it's less ideal to mutate the arg unless intentional.
//
// Time Complexity: O((n + m) log(n + m))
// Since we merge both arrays into one vector, then sort all n + m elements.
//
// Space Complexity: O(n + m)
// Since nums1 grows to hold both arrays.
//
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        // Insert the contents of nums2 to nums1.
        nums1.insert(nums1.begin(), nums2.begin(), nums2.end());

        // Sort nums1.
        sort(nums1.begin(), nums1.end());

        const int size = nums1.size();
        if (size % 2 == 0) {
            // On even-sized arrays, get the median by averaging the two middle numbers.
            const int middle = size / 2;
            return (double)(nums1[middle - 1] + nums1[middle]) / 2.0;
        } else {
            // On odd sets, simply get the middle number.
            return nums1[size / 2];
        }
    }
};