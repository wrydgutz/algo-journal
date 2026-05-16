// Problem:
// https://leetcode.com/problems/palindrome-number/
//
// Approach:
//
// Convert the input to a string, and then use a shrinking window 
// to compare both character ends to find a mismatch, in which 
// case determines that it's not a palindrome.
//
// Time Complexity: O(n)
// Since the string is iterated until the center only.
//
// Space Complexity: O(n)
// Since converting the integer to a string allocates memory
// proportional to the number of digits.
//
class Solution {
public:
    bool isPalindrome(int x) {

    	// Convert x to a string.
        string s = to_string(x);

        // Use two indices to represent a shrinking window
        // with left pointing to the current left character
        // and the right to the corresponding right character.
        int left = 0;
        int right = s.size() - 1;

        // Iterate until the center character is reached.
        while (left < right) {

        	// If there's a mismatch, then it's not a palindrome.
            if (s[left] != s[right]) return false;

            // Shrink the window.
            left++;
            right--;
        }

        // Reaching here means every character matched.
        // Hence, x is a palindrome.
        return true;
    }
};