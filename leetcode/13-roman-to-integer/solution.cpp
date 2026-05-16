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
public:
    int romanToInt(string s) {
        
        // Skip if empty. Simply zero.
        if (s.empty()) return 0;

        // Skip if just one character. Simply get the value.
        if (s.size() == 1) return value_of_symbol(s[0]);

        // Use the last character as the previous and starting value.
        int previousValue = value_of_symbol(s.back());
        int num = previousValue;

        // Iterate from the previous to the beginning.
        for (int i = s.size() - 2; i >= 0; i--) {

        	// Get the current character's value.
            const int currentValue = value_of_symbol(s[i]);

            // If the current is less than the previous,
            // then it is simply a special case Roman numeral.
            //
            // Example:
            //    previous = 'V', current = 'I'
            //    Means we detected "IV".
            //    previous 'V'(5) - current 'I'(1) = "IV"(4)
            if (currentValue < previousValue) {
                num -= currentValue;
            } else {
            	// Simply keep adding the current value.
            	// Remember, as per Roman numerals except the special cases
            	// values from left to right simply add up.
            	num += currentValue;
            }
            
            // Update the previous value.
            previousValue = currentValue;
        }

        return num;
    }

    inline int value_of_symbol(char symbol) {
	    // For a relatively small and predetermined lookup table
	    // save the trouble and costs of using a hash table by simply
	    // using a switch.
        switch (symbol) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default:  return 0;
        }

        return 0;
    }
};