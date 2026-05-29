// Problem:
// https://leetcode.com/problems/longest-palindromic-substring
//
// Approach:
//
// Treat each character as a possible center and expand
// both sides checking, looking for the longest palindrome.
//
// Time Complexity: O(n^2)
// Since the entire string is traversed and for each character
// expansions are done repetitively to check for palindromes.
// 
// Space Complexity: O(1)
// Since constant memory is used throughout the algorithm.
//
class Solution {
    func longestPalindrome(_ s: String) -> String {

        // Skip if empty.
        guard !s.isEmpty else { return "" }

        // Skip if just one character.
        let count = s.count
        guard count != 1 else { return s }
        
        // Simplify the check for two characters.
        let a = Array(s)
        guard count != 2 else { return a[0] == a[1] ? s : String(a[0]) }

        // Track the longest palindrome's start and end index.
        var bestLeft = 0
        var bestRight = 0

        // Traverse the entire string.
        for i in 0..<count - 1 {

            // Treat as center of an odd palindrome.
            expand(a: a, count: count, left: i, right: i, bestLeft: &bestLeft, bestRight: &bestRight)

            // Treat as center of an even palindrome.
            expand(a: a, count: count, left: i, right: i + 1, bestLeft: &bestLeft, bestRight: &bestRight)
        }

        // Return the substring of the longest palindrome.
        return String(a[bestLeft...bestRight])
    }

    func expand(a: [Character], count: Int, left: Int, right: Int, bestLeft: inout Int, bestRight: inout Int) {

        // Keep expanding while the palindrome is valid.
        var left = left
        var right = right
        while left >= 0 && right < count && a[left] == a[right] {

            // Update the longest palindrome's start and end index if applicable.
            if right - left > bestRight - bestLeft {
                bestLeft = left
                bestRight = right
            }
            
            left -= 1
            right += 1
        }
    }
}