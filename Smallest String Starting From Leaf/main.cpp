

class Solution {
public:
    vector<string> vStrings;

    void createStr(vector<char> const &vChars) {
        const string alphabet = "abcdefghijklmnopqrstuvwxyz";
        string s;
        for (int i = (int) vChars.size() - 1; i > 0; i--)
            s += alphabet[vChars.at(i)];
        s += alphabet[vChars.at(0)];
        vStrings.push_back(s);
    }

    void findLastLeaf(TreeNode* node, vector<char> &vChars) {
        if (node == nullptr) return;
        vChars.push_back(node->val);

        // if last leaf add str to vec
        if (node->left == nullptr && node->right == nullptr) createStr(vChars);

        findLastLeaf(node->left, vChars);
        findLastLeaf(node->right, vChars);
        vChars.pop_back();
    }

    string smallestFromLeaf(TreeNode* root) {
        if (root == NULL) return "";
        vector<char> vChars;
        findLastLeaf(root, vChars);

        sort(vStrings.begin(), vStrings.end());
        return vStrings[0];
    }
};
