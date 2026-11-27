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
        if (!root){
            return -1;
        }   

        return getOrder(root)[k - 1];
    }

    vector<int> getOrder(TreeNode* root){
        if (!root){
            return {};
        }
        vector<int> order = { root->val };
        vector<int> leftNodes = getOrder(root->left);
        order.insert(order.begin(), leftNodes.begin(), leftNodes.end());
        
        vector<int> rightNodes = getOrder(root->right);
        order.insert(order.end(), rightNodes.begin(), rightNodes.end());

        return order;
    }
};
