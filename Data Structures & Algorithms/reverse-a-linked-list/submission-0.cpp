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
    ListNode* reverseList(ListNode* head) {
        ListNode* tail = head;
        ListNode* temp = nullptr;

        while (tail != nullptr) {
            ListNode* next = tail->next;
            tail->next = temp;
            temp = tail;
            tail = next;
        }

        return temp;
    }
};