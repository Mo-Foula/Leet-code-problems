/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> q_original,q_cloned;
        q_original.push(original);
        q_cloned.push(cloned);
        while(q_original.size()){
            auto oriNode = q_original.front();
            auto cloNode = q_cloned.front();
            q_original.pop(); q_cloned.pop();
            if(oriNode == target){
                cloned = cloNode;
                break;
            }
            if(oriNode->left != NULL){
                q_original.push(oriNode->left);
                q_cloned.push(cloNode->left);
            }
            if(oriNode->right != NULL){
                q_original.push(oriNode->right);
                q_cloned.push(cloNode->right);
            }
            
        }
        return cloned;
    }
};