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
    // ListNode* helper()
    ListNode* rotateRight(ListNode* head, int k) {
        int i = 1;
        ListNode* temp = head;
        if (head == NULL || head->next == NULL)
            return head;
        while (temp->next != NULL) {
            temp = temp->next;
            i++;
        }
        // cout << i << endl;
        ListNode* last = temp;
        temp = head;
        k = k % i;
        if (k == 0 || k == i)
            return head;

        int b = i - k;

        // k--;
        ListNode* pre = NULL;
        while (b--) {
            pre = temp;
            temp = temp->next;
        }
        ListNode* newHead = temp;
        last->next = head;
        pre->next = NULL;

        return newHead;
    }
};