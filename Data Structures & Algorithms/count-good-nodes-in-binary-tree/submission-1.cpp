/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
   private:
    int goodNodesDfs(TreeNode* root, int maxValue) {
        if (!root) {
            return 0;
        }

        int goodNodes = root->val >= maxValue ? 1 : 0;

        maxValue = max(root->val, maxValue);
        goodNodes += goodNodesDfs(root->left, maxValue);
        goodNodes += goodNodesDfs(root->right, maxValue);
        return goodNodes;
    }

   public:
    int goodNodes(TreeNode* root) { return goodNodesDfs(root, INT_MIN); }
};
