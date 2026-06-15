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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *start = head, *temp = head;
        int cnt = 0;
        if (head->next == NULL) {
            head = NULL;
            return head;
        }
        while(start != NULL) {
            cnt++;
            start = start->next;
        }
        int cnt1 = 0;
        start = temp;
        
        while (start != NULL) {
            if (cnt1 == (cnt/ 2)) {
                break;
                // cout << start->val << endl;
            }
            temp = start;
            cnt1++;
            start = start->next;
        }
        if (start->next != NULL) {
            temp->next = start->next;
            // free(start);
        } else {
            temp->next = NULL;
            // free(start);
        }
        return head;
    }
};