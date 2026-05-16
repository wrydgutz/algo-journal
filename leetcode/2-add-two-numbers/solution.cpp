// Problem:
// https://leetcode.com/problems/add-two-numbers/
//
// Approach:
// Add the two numbers by adding their digits downwards and carrying, like elementary math.
//
// For example:
//
//                 1         11         11
//     123   ->   123   ->   123   ->   123
//	 + 789      + 789      + 789      + 789
//	 -----      -----      -----      -----
//                  2         12        912
//
// Digits are added one-by-one with carry:
// 3 + 9 = 12  -> write 2, carry 1
// 2 + 8 + 1 = 11 -> write 1, carry 1
// 1 + 7 + 1 = 9
//
// Time complexity: O(max(n, m))
// Since the list can have different lengths.
//
// Space complexity: O(n)
// Since the resulting list grows as the digits are filled.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* ret = nullptr; 	// Head of the resulting linked list.
        ListNode* itret = nullptr;	// Iterator used to append nodes to the result.
        
        // Stores overflow from previous addition.
        // Example:
        // 8 + 7 = 15
        // digit = 5
        // carry = 1
        int carry = 0;

        // Continue while:
        // - l1 still has digits
        // - l2 still has digits
        // - or there is leftover carry
        while(l1 != nullptr || l2 != nullptr || carry > 0) {
            
        	// Use current digit if node exists.
            // Otherwise use 0 if one list is shorter.
            const int digit1 = (l1 != nullptr) ? l1->val : 0;
            const int digit2 = (l2 != nullptr) ? l2->val : 0;
            
            // Add digits together with carry.
            const int sum = carry + digit1 + digit2;
            
            // Extract carry for next iteration.
            // Example: 18 / 10 = 1
            carry = sum / 10;

			// Create node using only the current digit.
            // Example: 18 % 10 = 8
            ListNode* node = new ListNode(sum % 10);

            // First node becomes the head.
            if (ret == nullptr) {
                ret = node;
                itret = node;
            } else { // Otherwise append to the tail.
                itret->next = node;
                itret = node;
            }

            // Advance input list iterators if possible.
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        return ret;
    }
};