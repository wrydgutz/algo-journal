// Problem:
// https://leetcode.com/problems/roman-to-integer
//
// Approach:
//
// Traverse the input backwards and keep adding up
// the values, except for special cases where they must
// instead be subtracted. Use a lookup table (switch in this case)
// to determine the value of each Roman numeral.
//
// Time Complexity: O(n)
// Since each character is processed once traversing the input.
//
// Space Complexity: O(1)
// Since constant memory is used throughout the algorithm.
//
class Solution {
    func romanToInt(_ s: String) -> Int {

        // Skip empty input. Simply zero.
        guard !s.isEmpty else { return 0 }

        // If there's only one symbol,
        // simply return its value.
        guard s.count != 1 else { return valueOfSymbol(s.first!) }

        // Use the last symbol as the starting value
        // and the initial previous value.
        var previousValue = valueOfSymbol(s.last!)
        var num = previousValue

        // Iterate from the second-to-last symbol
        // back to the beginning.
        for c in s.dropLast().reversed() {

            // Get the current symbol's value.
            let currentValue = valueOfSymbol(c)

            // If the current value is less than the previous value,
            // then we've encountered a subtractive Roman numeral.
            //
            // Example:
            //     previous = 'V', current = 'I'
            //     Means we detected "IV".
            //     5 - 1 = 4.
            num = num + (currentValue < previousValue ? -currentValue : currentValue)

            // Update the previous value.
            previousValue = currentValue
        }

        return num
    }

    // Small fixed lookup table implemented with a switch.
    func valueOfSymbol(_ symbol: Character) -> Int {
        switch symbol {
            case "I": return 1
            case "V": return 5
            case "X": return 10
            case "L": return 50
            case "C": return 100
            case "D": return 500
            case "M": return 1000
            default: return 0
        }
    }
}