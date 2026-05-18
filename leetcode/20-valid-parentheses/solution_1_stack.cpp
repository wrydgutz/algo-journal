// Problem:
// https://leetcode.com/problems/valid-parentheses
//
// Approach:
//
// Use a stack to keep track of the innermost enclosures.
// For every ending, check if the stack's top is the corresponding opening.
// If it's not, then it's invalid.
//
// Time Complexity: O(n)
// Since we traverse the entire string once. 
// The stack operations used are all O(1).
//
// Space Complexity: O(n)
// For a valid string, the stack will grow at most half the input. O(n/2)
// Worst case: an invalid string containing only openings (e.g. "(([[{{") will make the stack grow as much as the input.
//
class Solution {
public:
    bool isValid(string s) {

        // Skip empty strings.
        if (s.empty()) return false;

        // Skip odd-sized strings. They will always have invalid pairs.
        // e.g. "[(]", "({})[", "()]"
        if (s.size() % 2 != 0) return false;
        
        // Use a stack to track the innermost enclosures.
        stack<char> enclosures;

        // Traverse all characters.
        for (auto c : s) {
            // If an opening is detected, then push to the stack.
            if (c == '(' || c == '{' || c == '[') {
                enclosures.push(c);
                continue;
            }
            
            // If the stack is prematurely empty here, then it's invalid.
            // e.g. "())" = more endings than openings result in more pops.
            if (enclosures.empty()) return false;
            
            // Check each ending. If they don't match the top, then it's invalid.
            if (c == ')' && enclosures.top() != '(') return false;
            else if (c == '}' && enclosures.top() != '{') return false;
            else if (c == ']' && enclosures.top() != '[') return false;

            // Reaching here means the pair was valid.
            // Pop the top to proceed checking the next outer enclosure.
            enclosures.pop();
        }

        // Stack being empty here means the string is valid.
        return enclosures.empty();
    }
};