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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minDist = INT_MAX;
        int maxDist = 0;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int index = 1;
        int firstCritical = -1;
        int lastCritical = -1;

        while (curr->next != NULL) {
            int l = prev->val;
            int m = curr->val;
            int r = curr->next->val;

            if ((m > l && m > r) || (m < l && m < r)) {

                if (lastCritical != -1) {
                    int dist = index - lastCritical;

                    minDist = min(minDist, dist);
                    maxDist = index - firstCritical;
                } 
                else {
                    firstCritical = index;
                }

                lastCritical = index;
            }

            prev = curr;
            curr = curr->next;
            index++;
        }

        // fewer than 2
        if (firstCritical == -1 || firstCritical == lastCritical) {
            return {-1, -1};
        }

        return {minDist, maxDist};
    }
};