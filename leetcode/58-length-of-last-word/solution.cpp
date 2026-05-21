// Problem:
// https://leetcode.com/problems/length-of-last-word/
//
// Approach:
//
// Traverse from the last character, skipping spaces
// and only counting non-space characters, up until
// the next space is found.
//
// Time Complexity: O(n)
// Since all characters may be traversed in the worst case.
//
// Space Complexity: O(1)
// Since constant memory is used throughout the algorithm.
//
class Solution {
public:
    int lengthOfLastWord(string s) {

    	// Skip if empty.
        if (s.empty()) return 0;

        // Track the length of the last word.
        // length > 0 signals the last word has been found.
        int length = 0;
        
        // Traverse from the last character.
        for (int i = s.size() - 1; i >= 0; i--) {

        	// Check for space character.
            if (s[i] == ' ') {
            	// If the word was already found, and another
            	// space is reached, return the length.
                if (length > 0) return length;

                // Continue skipping the last spaces.
                continue;
            }
            
            // Keep incrementing as each non-space character is found.
            length++;
        }

        return length;
    }
};