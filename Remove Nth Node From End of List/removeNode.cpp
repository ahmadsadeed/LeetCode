#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <string>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
static const auto x=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL) return head;

        ListNode *headCopy1 = head;
        ListNode *headCopy2 = head;
        
        // send the first pointer ahead by n
        for (int i = 0; i < n; i++)
            headCopy1 = headCopy1->next;

        // if n=length(node)
        if (headCopy1 == NULL)  return head->next;

        while (headCopy1->next) {
            headCopy1 = headCopy1->next;
            headCopy2 = headCopy2->next;
        }
        headCopy2->next = headCopy2->next->next;

        return head;
    }
};

int main(){
    ListNode *list = new ListNode(1);
    ListNode *listPtr = list;

    list->next = new ListNode(2);
    list = list->next;
    list->next = new ListNode(3);
    list = list->next;
    list->next = new ListNode(4);
    list = list->next;
    list->next = new ListNode(5);

    Solution sol;
    ListNode *node = sol.removeNthFromEnd(listPtr, 5);

    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
    return 0;
}

