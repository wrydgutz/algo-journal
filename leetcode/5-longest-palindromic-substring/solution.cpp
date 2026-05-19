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
public:

    string longestPalindrome(string s) {

        // Skip if empty.
        if (s.empty()) return "";

        const int size = s.size();

        // Skip if just one character.
        if (size == 1) return s;

        // Simplify the check for two characters.
        if (size == 2) return s[0] == s[1] ? s : s.substr(0, 1);

        // Track the longest palindrome's start and end index.
        int bestLeft = 0, bestRight = 0;

        // Traverse the entire string.
        for (int i = 0; i < size; i++) {

            // Treat as center of an odd palindrome.
            expand(s, size, i, i, bestLeft, bestRight);

            // Treat as center of an even palindrome.
            expand(s, size, i, i + 1, bestLeft, bestRight);
        }

        // Return the substring of the longest palindrome.
        return s.substr(bestLeft, bestRight - bestLeft + 1);
    }

    void expand(const string& s, const int size, int left, int right, int& bestLeft, int& bestRight) {

        // Keep expanding while the palindrome is valid.
        while (left >= 0 && right < size && s[left] == s[right]) {

            // Update the longest palindrome's start and end index if applicable.
            if (right - left > bestRight - bestLeft) {
                bestLeft = left;
                bestRight = right;
            }

            left--;
            right++;
        }
    }
};