// Problem:
// https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum
//
// Approach:
//
// Traverse nums, and in each iteration, 
// convert each element to the sum of its digits 
// and also get the lowest sum.
//
// Time Complexity: O(n * d)
// Since each element is processed once, and d is the number of digits.
//
// Space Complexity: O(1)
// Since constant memory is used throughout the algorithm.
//

class Solution {
public:
    int minElement(vector<int>& nums) {
        
        // Track the lowest sum.
        int lowest = INT_MAX;

        // Traverse nums.
        for (int i = 0; i < nums.size(); i++) {

            // If it's just one digit, 
            // only update the lowest.
            if (nums[i] < 10) {
                lowest = min(lowest, nums[i]);
                continue;
            }

            // Get the sum of each digits
            // and update the current 
            // element as well as lowest.
            nums[i] = sumOfDigits(nums[i]);
            lowest = min(lowest, nums[i]);
        }

        return lowest;
    }

    int sumOfDigits(int n) {

        int result = 0;

        while (n != 0) {
            result += n % 10;
            n /= 10;
        }

        return result;
    }
};