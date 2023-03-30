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
struct compare {
    bool operator()(const ListNode* l1, const ListNode* l2) {
        return l1->val > l2->val;
    }
};

class Solution {
public:
    // HCI RESEARCH
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        // Initialize the priority queue
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for (ListNode* list : lists) {
            if (list != NULL) {
                pq.push(list);
            }
        }
        
        // Initialize the merged list
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        
        // Merge the lists using the priority queue
        while (!pq.empty()) {
            ListNode* curr = pq.top();
            pq.pop();
            tail->next = curr;
            tail = tail->next;
            if (curr->next != NULL) {
                pq.push(curr->next);
            }
        }
        
        return dummy->next;
        
    }
};