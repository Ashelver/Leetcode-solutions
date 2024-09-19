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
        ListNode* dummyHead = new ListNode(0); // Used as an anchor for the return
        ListNode* current_pointer = dummyHead;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry == 1){
            int sum = carry;
            if (l1 != nullptr){
                sum += l1->val;
                l1 = l1->next;
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

            current_pointer->next = new ListNode(sum % 10);
            current_pointer = current_pointer->next;
        }

        return dummyHead->next;
    }
};