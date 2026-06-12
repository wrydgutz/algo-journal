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
    func isValid(_ s: String) -> Bool {

        // Skip empty strings.
        guard !s.isEmpty else { return false }

        // Skip odd-sized strings. They will always have invalid pairs.
        // e.g. "[(]", "({})[", "()]"
        guard s.count % 2 == 0 else { return false }
        
        // Use a stack to track the innermost enclosures.
        var enclosures: [Character] = []
        
        // Traverse all characters.
        for c in s {
        	
            // If an opening is detected, then push to the stack.
            if c == "(" || c == "{" || c == "[" {
                enclosures.append(c)
                continue
            }
            
            // If the stack is prematurely empty here, then it's invalid.
            // e.g. "())" = more endings than openings result in more pops.
            guard !enclosures.isEmpty else { return false }
            
            // Check each ending. If they don't match the top, then it's invalid.
            if c == ")" && enclosures.last! != "(" { return false }
            else if c == "}" && enclosures.last! != "{" { return false }
            else if c == "]" && enclosures.last! != "[" { return false }
            
            // Reaching here means the pair was valid.
            // Pop the top to proceed checking the next outer enclosure.
            enclosures.removeLast()
        }
        
        // Stack being empty here means the string is valid.
        return enclosures.isEmpty
    }
}