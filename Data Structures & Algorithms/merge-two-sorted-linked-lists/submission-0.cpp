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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Dummy node to simplify edge cases
        ListNode dummy(0);
        ListNode* current = &dummy;

        // Compare nodes from both lists and link the smaller one
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                current->next = list1;   // Link list1's node
                list1 = list1->next;     // Advance list1
            } else {
                current->next = list2;   // Link list2's node
                list2 = list2->next;     // Advance list2
            }
            current = current->next;     // Advance current
        }

        // Attach whichever list still has remaining nodes
        if (list1 != nullptr) current->next = list1;
        if (list2 != nullptr) current->next = list2;

        return dummy.next; // Head of merged list
    }
};
 
