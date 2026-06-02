// Problem:
// https://leetcode.com/problems/zigzag-conversion/
//
// Approach:
//
// Append characters to each row of strings
// downwards then upwards, then combining
// the resulting rows into one string.
//
// Time Complexity: O(n)
// Since each character is processed once.
//
// Space Complexity: O(n)
// Since the total stored characters correspond to the string's size.
//
class Solution {
    func convert(_ s: String, _ numRows: Int) -> String {

        // Skip if there's just one row.
        // Also, skip if there are more rows than the string length.
        // Both will result in the same string.
        guard numRows > 1 && numRows < s.count else { return s }

        // Track each row's string.
        var rows = [String](repeating: "", count: numRows)

        // Direction to the next row.
        var direction = 1

        // Current row where character is added.
        var row = 0

        // Traverse each character.
        for c in s {
            
            // Add this character to the current row.
            rows[row] += String(c)

            // Switch direction at the first or last row.
            if row == numRows - 1 { direction = -1 }
            else if row == 0 { direction = 1 }

            // Traverse by direction.
            row += direction
        }
        
        // Combine all rows into one and return.
        let result = rows.joined()
        return result
    }
}