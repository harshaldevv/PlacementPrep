/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // Find the middle of the list
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        ListNode *prev = nullptr, *curr = slow->next;
        slow->next = nullptr;
        while (curr) {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // Merge the first half of the list with the reversed second half of the list
        ListNode *p1 = head, *p2 = prev;
        while (p2) {
            ListNode *temp1 = p1->next;
            ListNode *temp2 = p2->next;
            p1->next = p2;
            p2->next = temp1;
            p1 = temp1;
            p2 = temp2;
        }
    }
};
