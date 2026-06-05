// Problem:
// https://leetcode.com/problems/string-to-integer-atoi
//
// Approach:
//
// Traverse the string, looking for the number
// as per the described rules. Then, process
// each digit to build the number.
//
// Time Complexity: O(n)
// Since each character is processed once.
//
// Space Complexity: O(1)
// Since constant memory is used throughout the algorithm.
//
class Solution {
    func myAtoi(_ s: String) -> Int {

        // Skip if empty.
        guard !s.isEmpty else { return 0 }
        
        // Traverse the string and look for the
        // start and end indices covering the number.
        var arr = Array(s)
        var sign = 0
        var startIndex = -1
        var endIndex = -1
        var leadingZeroes = false
        var skippingWhitespaces = true

        for i in 0..<s.count {
            
        	// Skip whitespaces.
            if skippingWhitespaces {
                if arr[i] == " " { continue }
                else { skippingWhitespaces = false }
            }
            
            // Check if the first digit hasn't been found yet.
            if startIndex == -1 {
            	// If a negative sign is found, keep track of it.
                if sign == 0 && arr[i] == "-" {
                    sign = -1
                } else if sign == 0 && arr[i] == "+" {  // Likewise, keep track of the positive sign.
                    sign = 1
                } else if isDigit(arr[i]) {
                	// If a digit has been found but no sign was parsed,
                	// then assume the number is positive.
                    if (sign == 0) { sign = 1 }

                    // If the first digit found is a zero,
                    // it could just be leading zeroes, in which
                    // case should be ignored. But, if it's all
                    // zeroes until the end of the string 
                    // or until another non-digit, then it's zero.
                    if (arr[i] == "0") { leadingZeroes = true }

                    // Keep track of the start of the number.
                    startIndex = i;
                    endIndex = i;
                } else {
                	 // Reaching this means a non-digit has been found after the sign, which is zero as per the rules.
                    return 0
                }
            } else if (isDigit(arr[i])) { // At this point, the number is being processed.
            	// Skip all leading zeroes. 
            	// If a non-zero is found, then update the startIndex.
                if leadingZeroes && arr[i] > "0" {
                    startIndex = i
                    leadingZeroes = false
                }

                // Update the index of the last digit.
                endIndex = i
            } else {
            	// Reached the end of the number if a non-digit is found.
                break
            }
        }
        
        // Return zero if no valid number was found,
		// or if the parsed number contains only zeroes.
        if skippingWhitespaces || leadingZeroes || startIndex == -1 {
            return 0
        }
        
        // Traverse from the first to the last digit,
        // processing each for conversion.
        var num = 0
        let maxBeforeMultiplyBy10 = Int32.max / 10
        let minBeforeMultiplyBy10 = Int32.min / 10
        for i in startIndex...endIndex {

            let digit = arr[i].wholeNumberValue! * sign
            
            if num > maxBeforeMultiplyBy10 || (num == maxBeforeMultiplyBy10 && digit > 7) {
                return Int(Int32.max);
            }
            
            if num < minBeforeMultiplyBy10 || (num == minBeforeMultiplyBy10 && digit < -8) {
                return Int(Int32.min);
            }
            
            num = num * 10 + digit;
        }
        
        return num;
        
    }
    
    func isDigit(_ c: Character) -> Bool {
        return c >= "0" && c <= "9"
    }
}

