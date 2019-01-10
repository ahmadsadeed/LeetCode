// #include <iostream>
// #include <string>
// #include <vector>
// #include <set>

// using namespace std;


// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };


class Solution {
public:
    vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage) {
        set<int> result;
        int index = 0;
        if(!findFlips(root, voyage, result, index)){
            result.clear();
            result.insert(-1);
        }

        vector<int> v{result.begin(), result.end()};
        return v;
    }
private:
    bool findFlips(TreeNode * node, vector<int> &voyageRef, set<int> &resultRef, int &index) {
        if (node->val == voyageRef[index]) {
            ++index;

            if (node->left == NULL) {
                if (node->right == NULL) {
                    return true;
                } else return findFlips(node->right, voyageRef, resultRef, index);
            } else if (node->right == NULL) {
                return findFlips(node->left, voyageRef, resultRef, index);
            } else {
                // both have values
                if (node->left->val == voyageRef[index]) {
                    if (findFlips(node->left, voyageRef, resultRef, index)) {
                        return findFlips(node->right, voyageRef, resultRef, index);
                    }
                } else if (node->right->val == voyageRef[index]) {
                    resultRef.insert(node->val);
                    if (findFlips(node->right, voyageRef, resultRef, index)) {
                        return findFlips(node->left, voyageRef, resultRef, index);
                    }
                }
            }

        } else return false;
        return false;
    }
};
/*
 [1,2,null,3]
 [1,3,2]

 */

// int main(){

//     return 0;
// }

