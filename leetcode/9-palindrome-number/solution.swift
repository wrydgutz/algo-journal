// Problem:
// https://leetcode.com/problems/palindrome-number/
//
// Approach:
//
// Reverse the input number and compare it with the original.
// If both are equal, then the number is a palindrome.
//
// Time Complexity: O(n)
// Since each digit is processed once while reversing the number.
//
// Space Complexity: O(1)
// Since constant memory is used throughout the algorithm.
//
class Solution {
    func isPalindrome(_ x: Int) -> Bool {

        // Skip negative numbers.
        // The presence of the negative sign will always mismatch the first digit.
        // e.g. -343: '-' is not equal to '3' (at the right end)
        guard x >= 0 else { return false }

        // Reverse the number x.
        var revNum = 0

        // Reverse by starting from x and dividing it by 10 every iteration.
        var num = x

        while num > 0 {

            // Extract the rightmost digit using modulo.
            //
            // Example: 1234 % 10 = 4
            //
            // Then append it to the reversed number.
            //
            // Example:
            // rev_num = 123
            // digit = 4
            //
            // 123 * 10 + 4 = 1234
            revNum = revNum * 10 + num % 10
            num = num / 10
        }

        // It is a palindrome if the reversed number is equal to the original.
        return revNum == x
    }
}