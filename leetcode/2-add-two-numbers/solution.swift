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
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init() { self.val = 0; self.next = nil; }
 *     public init(_ val: Int) { self.val = val; self.next = nil; }
 *     public init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next; }
 * }
 */
class Solution {
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {

        // Declare the arg as local vars, allowing node traversal
        var l1 = l1
        var l2 = l2

        var ret: ListNode?      // Head of the resulting linked list.
        var itret: ListNode?    // Iterator used to append nodes to the result.

        // Stores overflow from previous addition.
        // Example:
        // 8 + 7 = 15
        // digit = 5
        // carry = 1
        var carry = 0

        // Continue while:
        // - l1 still has digits
        // - l2 still has digits
        // - or there is leftover carry
        while l1 != nil || l2 != nil || carry > 0 {

            // Use current digit if node exists.
            // Otherwise use 0 if one list is shorter.
            let digit1 = l1?.val ?? 0
            let digit2 = l2?.val ?? 0

            // Add digits together with carry.
            let sum = carry + digit1 + digit2

            // Extract carry for next iteration.
            // Example: 18 / 10 = 1
            carry = sum / 10

            // Create node using only the current digit.
            // Example: 18 % 10 = 8
            let node = ListNode(sum % 10)

            // First node becomes the head.
            if ret == nil {
                ret = node
                itret = node
            } else { // Otherwise append to the tail.
                itret?.next = node
                itret = node
            }

            // Advance input list iterators if possible.
            l1 = l1?.next
            l2 = l2?.next
        }

        return ret
    }
}