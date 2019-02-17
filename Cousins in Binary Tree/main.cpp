using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    unordered_map<int, int> parent;
    unordered_map<int, int> depth;
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, nullptr);

        return (depth[x] == depth[y] && parent[x] != parent[y]);
    }

    void dfs(TreeNode * node, TreeNode * par) {
        if (node) {
            depth.insert(make_pair(node->val, par != nullptr ? 1 + depth[par->val] : 0));
            parent.insert(make_pair(node->val, par != nullptr ? par->val : -1));
            dfs(node->left, node);
            dfs(node->right, node);

        }
    }
};
