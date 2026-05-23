// Problem:
// https://leetcode.com/problems/string-to-integer-atoi
//
// Approach:
//
// Traverse the string, looking for the number
// as per the described rules. Then, process
// each digit to build the number.
//
// Time Complexity: O(n)
// Since each character is processed once.
//
// Space Complexity: O(1)
// Since constant memory is used throughout the algorithm.
//
class Solution {
public:
    int myAtoi(string s) {
        
        // Skip if empty.
        if (s.empty()) return 0;

        // Traverse the string and look for the
        // start and end indices covering the number.
        int sign = 0;
        int startIndex = -1;
        int endIndex = -1;
        bool leadingZeroes = false;
        bool skippingWhitespaces = true;
        for (int i = 0; i < s.size(); i++) {

        	// Skip whitespaces.
            if (skippingWhitespaces) {
                if (s[i] == ' ') continue; 
                else skippingWhitespaces = false;
            }

            // Check if the first digit hasn't been found yet.
            if (startIndex == -1) {
            	// If a negative sign is found, keep track of it.
                if (sign == 0 && s[i] == '-') {
                    sign = -1;
                } else if (sign == 0 && s[i] == '+') { // Likewise, keep track of the positive sign.
                    sign = 1;
                } else if (isDigit(s[i])) {
                	// If a digit has been found but no sign was parsed,
                	// then assume the number is positive.
                    if (sign == 0) sign = 1;

                    // If the first digit found is a zero,
                    // it could just be leading zeroes, in which
                    // case should be ignored. But, if it's all
                    // zeroes until the end of the string 
                    // or until another non-digit, then it's zero.
                    if (s[i] == '0') leadingZeroes = true;

                    // Keep track of the start of the number.
                    startIndex = i;
                    endIndex = i;
                } else return 0; // Reaching this means a non-digit has been found after the sign, which is zero as per the rules.
            } else if (isDigit(s[i])) { // At this point, the number is being processed.
            	// Skip all leading zeroes. 
            	// If a non-zero is found, then update the startIndex.
                if (leadingZeroes && s[i] - '0' > 0) {
                    startIndex = i;
                    leadingZeroes = false;
                }

                // Update the index of the last digit.
                endIndex = i;
            } else break; // Reached the end of the number if a non-digit is found.
        }

        // Return zero if no valid number was found,
		// or if the parsed number contains only zeroes.
        if (skippingWhitespaces || leadingZeroes || startIndex == -1) return 0;

        // Traverse from the first to the last digit,
        // processing each for conversion.
        int num = 0;
        constexpr int maxBeforeMultiplyBy10 = INT_MAX / 10;
        constexpr int minBeforeMultiplyBy10 = INT_MIN / 10;
        for (int i = startIndex; i <= endIndex; i++) {
            const int digit = (int)(s[i] - '0') * sign;
        
            if (num > maxBeforeMultiplyBy10 || 
                (num == maxBeforeMultiplyBy10 && digit > 7)) return INT_MAX;

            if (num < minBeforeMultiplyBy10 || 
                (num == minBeforeMultiplyBy10 && digit < -8)) return INT_MIN;

            num = num * 10 + digit;
        }
        
        return num;
    }

    inline bool isDigit(char c) {
        return c - '0' >= 0 && c - '0' <= 9;
    }
};