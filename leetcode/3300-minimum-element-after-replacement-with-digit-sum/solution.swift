// Problem:
// https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum
//
// Approach:
//
// Traverse nums, and in each iteration, 
// convert each element to the sum of its digits 
// and update the lowest sum.
//
// Time Complexity: O(n * d)
// Since each element is processed once, and d is the number of digits.
//
// Space Complexity: O(1)
// Since constant memory is used throughout the algorithm.
//
class Solution {
    func minElement(_ nums: [Int]) -> Int {

        // Skip if empty.
        guard !nums.isEmpty else { return 0 }

        // Traverse nums.
        var lowest = Int.max
        for i in 0..<nums.count {

            // If it's just one digit, 
            // only update the lowest.
            if nums[i] < 10 {
                lowest = min(lowest, nums[i])
                continue
            }

            // Get the sum of each digits
            // and update the lowest.
            lowest = min(lowest, sumOfDigits(nums[i]))
        }

        return lowest
    }

    func sumOfDigits(_ n: Int) -> Int {
        var result = 0
        var n = n
        while n != 0 {
            result += n % 10
            n /= 10
        }
        return result
    }
}