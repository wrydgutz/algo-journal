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
// Space Complexity: O(S)
// S = total number of characters in all strings
//
class Solution {
    func longestCommonPrefix(_ strs: [String]) -> String {

        // Skip empty input.
        guard !strs.isEmpty else { return "" }

        // If there's just one string,
        // then it's already the prefix itself.
        guard strs.count != 1 else { return strs[0] }

        // Index of the current column for all strings during comparison.
        var i = 0

        // The current character being compared.
        var c: Character?

        // The resulting prefix where each common character is added.
        var prfx = ""

        // Flag to track if all characters in a column match.
        var common = true

        // Cache strings to an [[Character]] for index access.
        let arr = strs.map { Array($0) }

        // Traverse each column while all characters are common.
        while common {

            // Reset to nil.
            c = nil

            // Traverse each string.
            for str in arr {

                // If the end of one string is reached
                // then there's no match on this column.
                if i >= str.count {
                    common = false
                    break
                }

                // Track the current character if not yet so.
                if c == nil {
                    c = str[i]
                } 

                // If there's a mismatch, then end checking.
                else if c != str[i] {
                    common = false
                    break
                }
            }

            // If one of the character mismatched in the column, 
            // then end the entire check.
            guard common else { break }
            
            // Append the current character to the prefix.
            if let c = c {
                prfx += String(c)
            }

            // Proceed to the next column.
            i += 1
        }

        return prfx
    }
}