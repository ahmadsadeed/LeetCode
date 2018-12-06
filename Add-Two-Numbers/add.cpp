/*
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
*/
static const auto x=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *node = new ListNode(0);
        ListNode *listOne = l1, *listTwo = l2, *current = node;

        int carry = 0;
        while (listOne || listTwo) {
            //
            int x = (listOne) ? listOne->val : 0;
            int y = (listTwo) ? listTwo->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;

            if (listOne) {
                listOne = listOne->next;
            }
            if (listTwo) {
                listTwo = listTwo->next;
            }
        }
        if (carry > 0) {
            current->next = new ListNode(carry);
        }

        return node->next;
    }
};


/*
int main(){
    
    ListNode * listOne = new ListNode(0);
    ListNode * onePtr = listOne;
    ListNode * listTwo = new ListNode(0);
    ListNode * twoPtr = listTwo;

    listOne->next = new ListNode(2);
    listOne = listOne->next;
    listOne->next = new ListNode(4);
    listOne = listOne->next;
    listOne->next = new ListNode(3);

    listTwo->next = new ListNode(5);
    listTwo = listTwo->next;
    listTwo->next = new ListNode(6);
    listTwo = listTwo->next;
    listTwo->next = new ListNode(4);

    Solution sol;
    ListNode * result = sol.addTwoNumbers(onePtr, twoPtr);


    result = result->next;
    cout << "==> " << result->val << endl;
    result = result->next;
    cout << "==> " << result->val << endl;
    result = result->next;
    cout << "==> " << result->val << endl;


    return 0;
}
*/


