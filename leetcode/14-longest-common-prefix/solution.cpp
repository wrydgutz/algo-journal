// Problem:
// https://leetcode.com/problems/longest-common-prefix
//
// Approach:
//
// Brute-force using an index starting from the left
// and comparing each character from each string at
// the corresponding index until a mismatch is found.
//
// Time Complexity: O(n * m)
// n = number of strings
// m = length of the shortest string / common prefix length
//
// Space Complexity: O(1) auxiliary space
// excluding the returned string, which is O(m).
//
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        // Skip empty input.
        if (strs.empty()) return "";

        // If there's just one string,
        // then it's already the prefix itself.
        if (strs.size() == 1) return strs[0];

        // Index of the current column for all strings during comparison.
        int i = 0;

        // The current character being compared.
        char c = 0;

        // The resulting prefix where each common character is added.
        string prefix;

        // Flag to track if all characters in a column match.
        bool common = true;

        // Traverse each column.
        do {
            // Reset to null character.
            c = 0;

            // Traverse each string.
            for (const string& s : strs) {

                // If the end of one string is reached
                // then there's no match on this column.
                if (i >= s.size()) {
                    common = false;
                    break;
                }

                // Track the current character if not yet so.
                if (c == 0) c = s[i];

                // If there's a mismatch, then end checking.
                else if (c != s[i]) {
                    common = false;
                    break;
                }
            }

            // Append the current character to the prefix.
            if (common) prefix += c;

            // Proceed to the next column.
            i++;

        } while (common);

        return prefix;
    }
};