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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> order;
        getOrder(root, order);
        return order[k - 1];
    }

    void getOrder(TreeNode* root, vector<int>& order){
        if (!root){
            return;
        }
        getOrder(root->left, order);
        order.push_back(root->val);
        getOrder(root->right, order);
    }
};
