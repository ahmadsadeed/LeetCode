// #include <iostream>
// #include <vector>
// #include <cstdlib>
// #include <algorithm>
// #include <string>

// using namespace std;


// // Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode* next;
//     ListNode(int x) : val(x), next(NULL) {}
// };


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode listPtr(0);
        ListNode* list = &listPtr;

        if (l1 == NULL && l2 != NULL) return l2;
        else if (l2 == NULL && l1 != NULL) return l1;

        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                list->next = l1;
                l1 = l1->next;
            } else {
                list->next = l2;
                l2 = l2->next;
            }
            list = list->next;
        }
        list->next = ( (l1) ? l1 : l2 );
        return listPtr.next;
    }
};

// int main(){
//     ListNode* list1 = new ListNode(1);
//     ListNode* list1Ptr = list1;
//     list1->next = new ListNode(2);
//     list1 = list1->next;
//     list1->next = new ListNode(6);

//     ListNode* list2 = new ListNode(1);
//     ListNode* list2Ptr = list2;
//     list2->next = new ListNode(4);
//     list2 = list2->next;
//     list2->next = new ListNode(5);


//     Solution sol;
//     ListNode* node = sol.mergeTwoLists(list1Ptr, list2Ptr);

//     while (node != NULL) {
//         cout << node->val << " ";
//         node = node->next;
//     }
//     cout << endl;
//     return 0;
// }
