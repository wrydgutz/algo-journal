// Problem:
// https://leetcode.com/problems/median-of-two-sorted-arrays/
//
// Approach:
//
// Use a multiset (set that allows duplicate keys) to merge
// the contents of two vectors but ordered, then get the median.
//
// Time Complexity: O((n + m) log(n + m))
// Since each multiset insert costs O(log(n + m)),
// and we insert all n + m elements.
// std::advance is also O(n + m).
//
// Space Complexity: O(n+m)
// Since the set grows to the size of both vectors combined.
//
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        // Use a multiset, which allows duplicate keys
        // and orders upon insertion.
        multiset<int> uset;

        for (auto i:nums1) {
            uset.insert(i);
        }

        for (auto i:nums2) {
            uset.insert(i);
        }

        const bool isEven = uset.size() % 2 == 0;
        auto it = uset.begin();

        if (isEven) {
            // On even-sized arrays, get the median by averaging the two middle numbers.
            const int advanceBy = (uset.size() / 2) - 1;
            advance(it, advanceBy);
            const int left = *it;
            advance(it, 1);
            return (double)(left + *it) / 2.0;
        } else {
            // On odd sets, simply get the middle number.
            advance(it, uset.size() / 2);
            return *it;
        }
    }
};