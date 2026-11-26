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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root){
            return nullptr;
        }

        if (p->val < q->val){
            return getLCA(root, p, q);
        } 
        return getLCA(root, q, p);
        
    }

/**
a < b
**/
    TreeNode* getLCA(TreeNode* root, TreeNode* a, TreeNode* b){
        if (!root){
            return nullptr;
        }

        if (a->val <= root->val){
            if (b->val < root->val){
                return getLCA(root->left, a, b);
            } else {
                return root;
            }
        } else {
            return getLCA(root->right, a, b);
        }
    }
};
