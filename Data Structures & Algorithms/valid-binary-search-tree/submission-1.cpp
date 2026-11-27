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
    bool isValidBST(TreeNode* root, int minValue, int maxValue){
        if (!root){
            return true;
        }

        // cout << root->val << " min: " << minValue << " max: " << maxValue << "\n";

        if (root->val <= minValue || root->val >= maxValue){
            return false;
        }

        if (root->left){
            if (!isValidBST(root->left, minValue, min(maxValue, root->val))){
                return false;
            }
        }

        if (root->right){
            return isValidBST(root->right, max(minValue, root->val), maxValue);
        }

        return true;
    }

public:
    bool isValidBST(TreeNode* root) {
       return isValidBST(root, INT_MIN, INT_MAX);
    }
};
