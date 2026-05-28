// Problem:
// https://leetcode.com/problems/median-of-two-sorted-arrays/
//
// Approach:
//
// Merge the second array with the first, sort, then get the median.
//
// Time Complexity: O((n + m) log(n + m))
// Since we merge both arrays into one array, then sort all n + m elements.
//
// Space Complexity: O(n + m)
// Since allNums grows to hold both arrays.
//
class Solution {
    func findMedianSortedArrays(_ nums1: [Int], _ nums2: [Int]) -> Double {

        // Merge both nums1 and nums2 then sort.
        let allNums = nums1 + nums2
        let sorted = allNums.sorted()
        
        if sorted.count.isMultiple(of: 2) {
            // On even-sized arrays, get the median by averaging the two middle numbers.
            let middle = sorted.count / 2
            return (Double(sorted[middle - 1]) + Double(sorted[middle])) / 2.0
        } else {
            // On odd arrays, simply get the middle number.
            return Double(sorted[sorted.count / 2])
        }
    }
}