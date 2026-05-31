// Problem:
// https://leetcode.com/problems/add-binary/
//
// Approach:
//
// Like binary addition downwards, sum of each digit from 
// the right side of both strings, appending to the result
// and reversing the result string.
//
// Time Complexity: O(n)
// Since each element is processed once.
//
// Space Complexity: O(n)
// Since the resulting string grows as long as the longest input.
//
class Solution {
public:
    string addBinary(string a, string b) {
        
        // The sum stored in reverse.
        // Reversed before returning.
        string sumInReverse;

        // Traverse both strings simultaneously,
        // starting from their ends.
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry > 0) {

            // Determine the current sum.
            int digitSum = carry;
            if (i >= 0) digitSum += a[i--] - '0';
            if (j >= 0) digitSum += b[j--] - '0';

            // Carry happens when there's 1+1 or 1+1+1.
            carry = digitSum / 2;

            // Append the current binary digit.
            sumInReverse += '0' + (digitSum % 2);
        }

        reverse(sumInReverse.begin(), sumInReverse.end());
        return sumInReverse;
    }
};