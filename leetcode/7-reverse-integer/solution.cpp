// Problem:
// https://leetcode.com/problems/reverse-integer
//
// Approach:
//
// Reverse the number digit-by-digit.
// Before appending each digit, check whether multiplying the
// current reversed number by 10 would overflow a 32-bit integer.
//
// Time Complexity: O(n)
// Since each digit is processed once.
//
// Space Complexity: O(1)
// Since constant memory is used throughout the algorithm.
//
class Solution {
public:
    int reverse(int x) {
        
        // Store the reversed number.
        int reverse = 0;

        // Cache the largest and smallest safe values
        // before multiplying by 10.
        //
        // Example:
        // 214748364 * 10 = 2147483640 (still safe)
        // 214748365 * 10 = overflow
        constexpr int maxBeforeMultiplyBy10 = INT_MAX / 10;
        constexpr int minBeforeMultiplyBy10 = INT_MIN / 10;

        // Process all digits until the number becomes 0.
        while (x != 0) {

            // Extract the rightmost digit.
            //
            // Example:
            // 123 % 10 = 3
            // -123 % 10 = -3
            const int digit = x % 10;

            // Skip if multiplying by 10 and appending the digit would overflow INT_MAX.
            //
            // INT_MAX = 2147483647
            //
            // If reverse is already larger than 214748364, multiplying by 10 will definitely overflow.
            // If reverse is exactly 214748364, only digits up to 7 are safe.
            if (reverse > maxBeforeMultiplyBy10 || 
                (reverse == maxBeforeMultiplyBy10 && digit > 7)) return 0;

            // Skip if multiplying by 10 and appending the digit would overflow INT_MIN.
            //
            // INT_MIN = -2147483648
            //
            // If reverse is already smaller than -214748364, multiplying by 10 will definitely overflow.
            // If reverse is exactly -214748364, only digits down to -8 are safe.
            if (reverse < minBeforeMultiplyBy10 || 
                (reverse == minBeforeMultiplyBy10 && digit < -8)) return 0;

            // Append the digit to the reversed number.
            //
            // Example:
            // reverse = 123
            // digit = 4
            //
            // 123 * 10 + 4 = 1234
            reverse = reverse * 10 + digit;

            // Remove the rightmost digit.
            // Example: 123 / 10 = 12
            x /= 10;
        }

        return reverse;
    }
};