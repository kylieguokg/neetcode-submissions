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
    vector<int> rightSideView(TreeNode* root) {
        if (!root){
            return {};
        }
        vector<int> rightSideView;

        queue<TreeNode*> nextLevel;
        nextLevel.push(root);
        
        while (!nextLevel.empty()){
            int levelSize = nextLevel.size();
            vector<int> curLevel;

            for (int i = 0; i < levelSize; i++){
                TreeNode* node = nextLevel.front();
                nextLevel.pop();

                curLevel.push_back(node->val);

                if (node->left){
                    nextLevel.push(node->left);
                }

                if (node->right){
                    nextLevel.push(node->right);
                }
            }

            rightSideView.push_back(curLevel[levelSize - 1]);
        }
        return rightSideView;

        
    }
};
