// Problem:
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string
//
// Approach:
//
// Traverse the haystack but only up to the last index
// that can contain the needle. Check for the needle's
// first and last character against the haystack, and if
// matching proceed to check the rest of the needle's contents.
//
// Time Complexity: O(nm)
// Since haystack characters are traversed once, and all chacters of
// the needle are also traversed once in case of a match or close match.
//
// Space Complexity: O(1)
// Since constant memory is used throughout the algorithm.
//
class Solution {
public:
    int strStr(string haystack, string needle) {

    	// Empty needle is considered found at index 0.
		if (needle.empty()) return 0;

		// Empty haystack cannot contain a non-empty needle.
		if (haystack.empty()) return -1;

        // Skip if the needle is longer than the haystack.
        // e.g. haystack = "leet", needle = "leetcode"
      	//		haystack doesn't fit the needle.
        const int needleSize = needle.size();
        const int haystackSize = haystack.size();
        if (needleSize > haystackSize) return -1;

        // Traverse the haystack only up to the last
        // index that can be checked with the needle's first index.
        for (int i = 0; i <= haystackSize - needleSize ; i++) {
        	// Skip if current haystack character doesn't match the needle's first character.
            if (haystack[i] != needle[0]) continue;

            // Skip if the needle's last character doesn't match the haystack's corresponding character.
            if (haystack[i + needleSize - 1] != needle[needleSize - 1]) continue;

            // Reaching here means the first and last characters of the needle matched.
            // Now just check if all characters within the range match.
            bool contains = true;
            for (int j = 1; j < needleSize - 1; j++) {
                if (haystack[i + j] != needle[j]) {
                    contains = false;
                    break;
                }
            }

            // If it does contain the needle, then return the first index in the haystack
            // where it matched.
            if (contains) return i; 
        }

        // Otherwise, the needle wasn't found.
        return -1;
    }
};