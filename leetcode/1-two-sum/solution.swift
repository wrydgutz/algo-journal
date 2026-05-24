// Problem:
// https://leetcode.com/problems/two-sum/
//
// Approach:
// Use a dictionary to keep track of indices.
//
// Time Complexity: O(n)
// Since each element is processed at most once.
//
// Space Complexity: O(n)
// Since the dictionary may store up to nums.count elements.
//
class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {

        // Use a dictionary (hash table). O(1) degrading to O(n) only during collisions.
        var map = [Int: Int]()

        // In one pass, go through each array value.
        for (i, num) in nums.enumerated() {

            // Check if the map contains the number.
            // If it does, then return the value and index as the pair.
            if let value = map[num] {
                return [value, i]
            }

            // Store the current index using the 
            // complement (target - num) as the key.
            map[target - num] = i
        }

        return [];
    }
}