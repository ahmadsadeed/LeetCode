// struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL|| k == 1) return head;
        int counter = 0;
        ListNode *newHead = new ListNode(0);
        newHead->next = head;

        ListNode *curr = newHead, *next, *prev = newHead;
        while ((curr = curr->next)) // no error with =, extra () to silence the warning
            counter++;

        while (counter >= k) {
            curr = prev->next;
            next = curr->next;
            for (int i = 1; i < k; ++i) {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }
            prev = curr;
            counter -= k;
        }

        return newHead->next;
    }
};
