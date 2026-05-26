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
    func lengthOfLongestSubstring(_ s: String) -> Int {
        
        // Skip if the string's empty.
        // Also, skip if the string's just one character.
        guard s.count > 1 else { return s.count }

        // First, allocate a vector of 256 flags.
        // Each index represents one ASCII character.
        // Since char values map to ints, chars can be used as indices.
        // 256 covers the full unsigned char byte range.
        var seen = [Bool](repeating: false, count: 256)

        // Swift String does not support indexing. Forcing it
        // with s.index() is also slow. Instead, convert
        // to array first and use that instead.
        let chars = Array(s)

        // Using the sliding window technique, use a left and right cursor to compare.
        var left = 0
        var longest = 0
        for right in 0..<chars.count {
            
            // Keep shrinking the window from the left while the
            // current character already exists in the window.
            let rightChar = chars[right]
            let rightAscii = Int(rightChar.asciiValue!)
            while seen[rightAscii] {
                let leftChar = chars[left]
                seen[Int(leftChar.asciiValue!)] = false
                left += 1
            }

            // Mark this char as seen.
            seen[rightAscii] = true
            longest = max(longest, right - left + 1)
        }

        return longest
    }
}