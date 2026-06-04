// Problem:
// https://leetcode.com/problems/count-the-number-of-special-characters-i
//
// Approach:
//
// Traverse the string while storing previously seen characters
// in a hash set. Whenever a character's opposite case has already
// been seen and the current character has not yet been counted,
// increment the special character count.
//
// Time Complexity: O(n)
// Since each character is processed once.
//
// Space Complexity: O(1)
// Since the hash set stores at most 52 English alphabet characters.
//
class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        unordered_set<char> uset;
        int specials = 0;
        
        for (const char c: word) {
            
            // Count the character only once.
            // A character is special when both its lowercase
            // and uppercase forms appear in the string.
            if (uset.find(c) == uset.end() && 
                uset.find(complement(c)) != uset.end()) {
                specials++;
            }
            
            // Mark the current character as seen.
            uset.insert(c);
        }

        return specials;
    }

    // Return the opposite case of the character.
    inline char complement(const char c) {
        return c + (isUppercase(c) ? 32 : -32);
    }

    // Check whether the character is uppercase.
    inline bool isUppercase(const char c) {
        return c >= 65 && c <= 90;
    }
};