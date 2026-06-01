// Problem:
// https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount
//
// Approach:
//
// Sort the input, then traverse in steps of three from the end,
// adding up the last two numbers and skipping the third.
//
// Time Complexity: O(n log n)
// Since we sort the array.
//
// Space Complexity: O(1)
// Since constant memory is used throughout the algorithm.
//
class Solution {
public:
    int minimumCost(vector<int>& cost) {

    	// Simplify for low sizes.
        const int size = cost.size();
        if (size == 0) return 0;
        else if (size == 1) return cost[0];
        else if (size == 2) return cost[0] + cost[1];

        // Sort the input.
        sort(cost.begin(), cost.end());

        // Traverse in steps of three.
        // Adding up the last two numbers and skipping the third.
        int total = 0;
        for(int i = size - 1; i >= 0; i -= 3) {
            if (i - 1 >= 0) total += cost[i] + cost[i - 1];
            else total += cost[i];
        }

        return total;
    }
};