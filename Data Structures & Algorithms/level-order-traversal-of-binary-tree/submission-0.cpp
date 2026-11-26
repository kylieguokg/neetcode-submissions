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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels = {};
        getLevels(root, levels, 0);
        return levels;
    }

    void getLevels(TreeNode* root, vector<vector<int>>& levels, int level){
        if (!root){
            return;
        }
        if (level >= levels.size()){
            levels.push_back({});
        }
        levels[level].push_back(root-> val);
        getLevels(root->left, levels, level + 1);
        getLevels(root->right, levels, level + 1);
    }
};
