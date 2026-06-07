// Problem:
// https://leetcode.com/problems/plus-one/
//
// Approach:
//
// Start from the last digit and add 1.
// If a digit becomes 10, set it to 0 and carry 1 to the next digit.
// If no carry remains, stop early.
// If carry still remains after the loop, insert 1 at the front.
//
// Time Complexity: O(n)
// Since each digit is processed at most once.
//
// Space Complexity: O(1)
// Since the input array is modified in place.
//
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int carry = 1;
        int i = digits.size() - 1;
        while (i >= 0) {
            digits[i] += carry;
            if (digits[i] > 9) {
                digits[i] = 0;
                i--;
            } else {
                carry = 0;
                break;
            }
        }

        if (carry > 0) digits.insert(digits.begin(), carry);
        return digits;
    }
};