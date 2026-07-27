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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = lists.size();
        
        if (n == 0) {
            return NULL;
        }
        if (n == 1) {
            return lists[0];
        }
        for (int i = 0; i < n; i++) {
            ListNode *first = lists[i];
            while (first != NULL) {
                pq.push(first->val);
                first = first->next;
            }

        }
        ListNode* head = new ListNode(-1);
        ListNode* dummy = head;
        //then pop out the elements.
        while (!pq.empty()) {
            int el = pq.top();
            ListNode *temp = new ListNode(el);
            dummy->next = temp;
            dummy = dummy->next;
            pq.pop();
        }
        return head->next;
    }
};