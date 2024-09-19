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
        // Simply use `carry` to pass the '1' to next node
        // Use a pionter to track the l1--improved.v1
        ListNode* pointer = l1;
        int carry = 0;
        while (pointer != nullptr || l2 != nullptr){
            int sum = carry;
            if (pointer != nullptr){
                sum += pointer->val;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
        
            // updated the `carry`
            if (sum > 9){
                carry = 1;
            } else {
                carry = 0;
            }
            
            pointer->val = sum % 10;

            // Process edge problems
            if (pointer->next == nullptr){
                if (l2 != nullptr || carry == 1){
                    pointer->next = new ListNode(carry);
                    carry = 0;
                }
                

            }

            pointer = pointer->next;
        }

        return l1;
    }
};