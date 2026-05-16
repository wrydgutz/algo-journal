// Problem:
// https://leetcode.com/problems/longest-substring-without-repeating-characters
//
// Approach:
// Brute Force O(n^2)
//
// Compare every character with every other character in the string
// and keep track of the longest substring using a set.
//
// Time Complexity: O(n^2)
// Since the string is iterated again for every iteration.
//
// Space Complexity: O(n)
// Since the set can grow as long as the string itself.
//
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // Skip if the string's empty.
        if (s.empty()) return 0;
        
        // Create one set for every possible starting index.
        //
        // Each set stores the characters currently seen for that substring window.
        unordered_set<char> usets[s.size()];
        
        // Tracks the leftmost valid substring start.
        //
        // Example:
        // "abcabcbb"
        //        ^
        //
        // If a duplicate is found, move the start forward.
        int longestIndex = 0;

        // Iterate through every character in the string.
        for (int i = 0; i < s.size(); i++) {

            // Check every active substring window.
            for (int j = longestIndex; j <= i; j++ ) {

                // If the character already exists in the set,
                // then the substring is no longer valid.
                if (usets[j].contains(s[i])) {
                    longestIndex++;
                    continue;
                }

                // Otherwise add the character to the substring.
                usets[j].insert(s[i]);
            }
        }

        // Find the largest substring size among all sets.
        int longest = 0;
        for (int i = 0; i < s.size(); i++) {

            // Keep track of the maximum substring length found.
            if (usets[i].size() > longest) longest = usets[i].size();
        }

        return longest;
    }
};