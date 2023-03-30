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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //hci researhc
        ListNode* fast = head;
        ListNode* slow = head;

        // Move the fast pointer n nodes ahead of the slow pointer
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // If fast pointer becomes null, remove the first node
        if (!fast) {
            return head->next;
        }

        // Move both pointers until fast pointer reaches the end
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove the nth node from the end
        slow->next = slow->next->next;

        return head;
    }
};
