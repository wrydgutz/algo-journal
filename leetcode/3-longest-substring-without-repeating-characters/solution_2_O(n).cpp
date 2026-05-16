// Problem:
// https://leetcode.com/problems/longest-substring-without-repeating-characters
//
// Approach:
//
// Use the sliding window technique combined with a vector of flags
// to check the characters and compute the longest substring.
//
// Reference: https://www.geeksforgeeks.org/dsa/window-sliding-technique/
//
//
// Time Complexity: O(n)
// Since each character enters and leaves the sliding window at most once.
//
// Space Complexity: O(1)
// Since the flags remain constant size throughout the algorithm.
//
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

    	// Skip if the string's empty.
    	// Also, skip if the string's just one character.
        if (s.empty() || s.size() <= 1) return s.size();
        
        // First, allocate a vector of 256 flags.
		// Each index represents one ASCII character.
		// Since char values map to ints, chars can be used as indices.
		// 256 covers the full unsigned char byte range.
        vector<bool> seen(256, false);

		// Using the sliding window technique, use a left and right cursor to compare.
        int left = 0, longest = 0;
        for (int right = 0; right < s.size(); right++) {

	        // Keep shrinking the window from the left while the
			// current character already exists in the window.
            while (seen[s[right]]) {
                seen[s[left]] = false;
                left++;
            }

			// Mark this char as seen.
            seen[s[right]] = true;
            longest = max(longest, right - left + 1);
        }

        return longest;
    }
};